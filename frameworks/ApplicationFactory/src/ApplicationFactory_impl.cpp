/***************************************************************************//**
* @file     ApplicationFactory_impl.cpp
* @author   open Team
* @version  9
* @date     2017-03-18
* @brief
* @Remark : <Description>
* @verbatim
* ==============================================================================
* <Date>     | <Version> | <Author>       | <Description>
* ==============================================================================
*  2015-05-23 | 1       | open Team       | Create file
* ==============================================================================
* @endverbatim
* ******************************************************************************
* <h2><center>&copy; Copyright(c)2015-2025 JFounder Info Tech Co.,Ltd</center></h2>
* All rights reserved. The right to copy, distribute, modify or otherwise make use
* of this software may be licensed only pursuant to the terms of an applicable
* JFounder license agreement. Company website: www.onetek.net
*//****************************************************************************/

// 头文件
#include <iostream>
#include <sstream>
#include "../include/ApplicationFactory_impl.h"
#include "../include/debug.h"
#include "port_helpers.h"
#include "utils.h"
#include "Boost_utils.h"
#include "TimeDelay.h"
#include "ConfigParser.h"

// 条件编译
// 判断某个宏是否被定义，若定义，执行随后的语句
#ifdef __SDS_OS_VXWORKS__
#include "taskLib.h"

// extern是计算机语言中的一个关键字，可置于变量或者函数前，以表示变量或者函数的定义在别的文件中。
// 提示编译器遇到此变量或函数时，在其它模块中寻找其定义
extern SEM_ID semAppsMutex;
#endif

// 宏定义命令 ,它用来将一个标识符定义为一个字符串 , 该标识符被称为宏名, 被定义的字符串称为替换文本
// #表示预处理命令
// 宏命令的作用域为宏定义起到源程序结束
#define APP_NUMS_UPPER 16

// 定义变量并初始化， bool为数据类型，isTimeout为变量名，=false为初始化
bool isTimeout = false;

// 函数，void为函数返回值类型，handler为函数名
void handler() {
	isTimeout = true;
}

// 构造函数
// 构造函数的作用是初始化类对象的数据成员，无论何时只要类的对象被创建，就会执行构造函数
// m_instanceNum(0)是将m_instanceNum初始化为0
// 当我们在类的外部定义类的成员函数时，必须指明该函数是哪个类的成员
ApplicationFactory_impl::ApplicationFactory_impl(
    const char * sftwpfl,
    CF::DomainManager::ApplicationSequence * appSeqPtr)
	: m_instanceNum(0) {
		
	DEBUG(1, ApplicationFactory, "In ApplicationFactory constructor.")
	// 将sftwpfl拷贝给m_softwareProfile，对m_softwareProfile初始化
	m_softwareProfile = sftwpfl;

	// 将appSeqPtr拷贝给m_appSeqPtr，对m_appSeqPtr初始化
	m_appSeqPtr = appSeqPtr;

	// 对类的其他一些数据成员进行初始化
	postConstructor();

	//get registered devices and component palcement from sad.xml
	// 找到域中所有注册的设备，并将其拷贝给m_registeredDevices
	getRegisteredDevices();

	DEBUG(5, ApplicationFactory_impl, "m_factoryName is " << m_factoryName)
	DEBUG(5, ApplicationFactory_impl, "m_identifier is " << m_identifier)
	DEBUG(5, ApplicationFactory, "Leaving ApplicationFactory constructor.")
}

// 根据软件描述文件找到应用的一些重要参数
void 
ApplicationFactory_impl::postConstructor()
{
	/*
	 * instantiate ORB_Wrap in order to resolve domain manager ref and
	 * file manager ref.
	 */
// 实例化一个ORB_Wrap类
// openscaSupport是一个命名空间
// ORB_Wrap是openscaSupport命名空间中的一个类
#ifdef __SDS_OS_VXWORKS__
	m_orbWrap = new openscaSupport::ORB_Wrap::ORB_Wrap();
#elif defined __SDS_OS_LINUX__
	m_orbWrap = new openscaSupport::ORB_Wrap();
#endif

	// 如果实例化失败，则报错
	if ( !m_orbWrap ) {
		DEBUG(1, ApplicationFactory,
		    "[ApplicationFactory_impl] instantiate ORB_Wrap failed.")
		exit(EXIT_FAILURE);
	}

	// 从ORB_Wrap里面找到域管理器对应的参考
	// 定义并初始化一个corba对象指针
	CORBA::Object_ptr dmnObj = CORBA::Object::_nil();
	// 跟在try之后的是一个或多个catch子句。catch内表示异常声明，当选中了某个catch子句处理异常之后，执行对应的块。
	try {
		// 获得域管理器对象（CORBA对象）
		// 函数的定义在E:\SCA程序\openSCA-master\include\runtime_env\openscaSupport.h
		// 具体的实现没有给出
		dmnObj = m_orbWrap->get_object_from_string(
			"OpenSCA_Domain/Domain_Manager");
	} catch (...) {
		DEBUG(1, ApplicationFactory,
		    "[ApplicationFactory_impl] m_orbWrap-> \
		    get_object_from_string failed with Unknown Exception.")
		// 无条件地关闭程序
		exit(EXIT_FAILURE);
	}

	try {
		// 返回域管理器指针（CF中域管理器对象）
		m_dmnMgr = CF::DomainManager::_narrow(dmnObj);
	} catch (...) {
		DEBUG(1, ApplicationFactory,
		    "[ApplicationFactory_impl] CF::DomainManager::_narrow \
		    failed with Unknown Exception.")
		exit(EXIT_FAILURE);
	}

	try {
		// 返回文件管理器指针
		m_fileMgr = m_dmnMgr->fileMgr();
	} catch (...) {
		DEBUG(1, ApplicationFactory,
		    "[ApplicationFactory_impl] m_dmnMgr->fileMgr \
		    failed with Unknown Exception.")
		exit(EXIT_FAILURE);
	}

	//open sad.xml and parser it
	CF::File_var fl;
	try {
		// 从文件管理器中返回软件配置文件的指针
		fl = m_fileMgr->open(m_softwareProfile.c_str(), true);
	} catch (CF::InvalidFileName & e) {
		DEBUG(1, ApplicationFactory,
		    "[ApplicationFactory_impl] m_fileMgr->open \
		    failed with Invalid file name.")
		exit(EXIT_FAILURE);

	} catch (CF::File::IOException & e) {
		DEBUG(1, ApplicationFactory,
		    "[ApplicationFactory_impl] m_fileMgr->open \
		    failed with CF::File::IOException.")
		exit(EXIT_FAILURE);
	} catch (CF::FileException & e) {
		DEBUG(1, ApplicationFactory,
		    "[ApplicationFactory_impl] m_fileMgr->open \
		    failed with CF::FileException.")
		exit(EXIT_FAILURE);
	} catch (...) {
		DEBUG(1, ApplicationFactory,
		    "[ApplicationFactory_impl] m_fileMgr->open \
		    failed with Unknown Exception.")
		exit(EXIT_FAILURE);
	}

	// 根据软件配置文件实例化SAD解析器
	// SAD解析器是一个类，里面定义了很多解析SAD文件的操作
	// SADParser的输入是CF::File_ptr
	m_sadParser = new SADParser( fl );

	try {
		// 关闭f1
		fl->close();
	} catch (CF::InvalidFileName & e) {
		DEBUG(1, ApplicationFactory,
		    "[ApplicationFactory_impl] m_fileMgr->open \
		    failed with Invalid file name.")
		exit(EXIT_FAILURE);
	} catch (CF::File::IOException & e) {
		DEBUG(1, ApplicationFactory,
		    "[ApplicationFactory_impl] m_fileMgr->open\
		    failed with CF::File::IOException.")
		exit(EXIT_FAILURE);
	} catch (CF::FileException & e) {
		DEBUG(1, ApplicationFactory,
		    "[ApplicationFactory_impl] m_fileMgr->open\
		    failed with CF::FileException.")
		exit(EXIT_FAILURE);
	} catch (...) {
		DEBUG(1, ApplicationFactory,
		    "[ApplicationFactory_impl] m_fileMgr->open \
		    failed with Unknown Exception.")
		exit(EXIT_FAILURE);
	}

	if (m_sadParser) {
		DEBUG(5, ApplicationFactory_impl, "new SADParser...")
	}

	//initialize name and identifier of application
	// 根据SAD解析器的内容找到应用的名字和识别号
	m_factoryName = m_sadParser->getName();
	m_identifier = m_sadParser->getID();
}

// 析构函数的定义
ApplicationFactory_impl::~ApplicationFactory_impl() {
	DEBUG(3, ApplicationFactory, "In AapplicationFactory destrutor.")
	// delete表示释放new分配的对象指针指向的内存
	delete m_sadParser;
}

/**
 * The create operation is used to create an application within the system domain.
 *
 * The create operation provides a client interface to request the creation of an
 * application on client requested device(s) and/or the creation of an application
 * in which the application factory determines the necessary device(s) required
 * for instantiation of the application.
 * The following steps demonstrate one scenario of the behavior of an application
 * factory for the creation of an application:
 * // 接下来的步骤描述了一个应用工厂创建一个应用的行为的场景
 *  1. Client invokes the create operation.
 * // 1. 用户提出创建的操作
 *  2. Evaluate the Domain Profile for available devices that meet the application's
 *  memory and processor requirements, available dependent applications, and dependent
 *  libraries needed by the application. Create an instance of an Application, if the
 *  requested application can be created. Update the memory and processor utilization
 *  of the devices.
 * // 评估满足应用内存和处理器要求的可用设备，可用的独立应用以及应用需要的独立库。如果被需求的应用
 * // 能够被创立，则创建一个应用的实例。更新设备的内存和处理器的使用情况
 *  3. Allocate the device(s) memory and processor utilization.
 * // 分配设备内存和处理器的使用
 *  4. Load the application software modules on the devices using the appropriate
 *  Device(s) interface provided the application software modules haven't already
 *  been loaded.
 * // 如果应用软件组件没有被加载，则采用合适的设备接口将应用软件组件加载到设备之上
 *  5. Execute the application software modules on the devices using the appropriate
 *  Device interface as indicated by the application's software profile.
 * // 根据应用软件配置所指示的那样，采用合适的设备接口在设备上开启应用软件组件
 *  6. Obtain the object reference (Resource or ResourceFactory) as described by the SAD.
 * // 根据SAD所描述的那样，获得对象的参考（资源或资源工厂）
 *  7. If the component obtained from the CORBA Naming Service is a resource factory as
 *  indicated by the SAD, then narrow the object reference to be a ResourceFactory component.
 * // 如果根据SAD所指示的，从CORBA命名服务获得的组件是资源工厂，那么将对象的参考缩小为资源工厂组件
 *  8. If the component is a ResourceFactory, then create a resource using the
 *  ResourceFactory interface.
 * // 如果组件是资源工厂，采用资源工厂接口创建一个资源
 *  9. If the components obtained from the Naming Services is a resource supporting the
 *  Resource interface as indicated by the SCDs, then narrow the components reference to Resource
 *  components.
 * // 如果根据SCD所指示的，从命名服务中获得的组件是一个用来支撑资源接口的资源，那么将组件的参考缩小为资源组件
 *  10. Initialize the resource.
 * // 初始化资源
 *  11. Get Port object references for the resources.
 * // 获得资源的端口对象参考
 *  12. Connect the ports that interconnect the resources' ports together.
 * // 将相互联系的资源端口连接在一起
 *  13. Configure the assemblycontroller component using the Resource interface.
 * // 采用资源接口配置装配控制器组件
 *  14. Return the Application object reference and log message.
 * // 返回应用对象的参考以及日志信息
 *  15. Generate an event to indicate the application has been added to the domain.
 * // 产生一个事件用来表明应用已经被加载到域中
 */

// 如果一个标明throw()的函数内部发生了throw：
// 1，如果内部直接throw something，编译器会发现并指出；
// 2. 如果是内部调用了一个可能throw something的函数，编译器无法发现，运行时一旦这个内部的函数throw，程序会abort。
// void fun() throw();      //表示fun函数不允许抛出任何异常，即fun函数是异常安全的。
// void fun() throw(...);    //表示fun函数可以抛出任何形式的异常。
// void fun() throw(exceptionType);    // 表示fun函数只能抛出exceptionType类型的异常。
CF::Application_ptr
ApplicationFactory_impl::create(
    const char * name,
    const CF::Properties & initConfiguration,
    const CF::DeviceAssignmentSequence & deviceAssignments)
throw (
    CF::ApplicationFactory::InvalidInitConfiguration,
    CF::ApplicationFactory::CreateApplicationRequestError,
    CF::ApplicationFactory::CreateApplicationError,
    CORBA::SystemException) {

	DEBUG(1, ApplicationFactory, "In create.")

	// 该函数的实现在下面
	// 具体实现的功能还没搞清楚，貌似是锁住什么？
	// 下面有对应的解锁函数
	lock();

	// 定义并初始化了一个变量，名为appVar，数据类型为CF::Application_var
	CF::Application_var appVar = CF::Application::_nil();

	// 将name拷贝给m_appName
	m_appName = name;

	// increment applicaton instance number
	// 在APP_NUMS_UPPER + 1范围内选择最小的且没有用过的整数给应用进行一个编号，并赋值给m_instanceNum
	// 函数的调用
	updateInstanceNum();
	DEBUG(5, ApplicationFactory_impl::create, "update instance number finished")
	
	// 定义一个含有5个char的数组instanceNum
	char instanceNum[5];

	// 将整数m_instanceNum打印成一个字符串保存在instanceNum中
	sprintf(instanceNum, "%d", (int)m_instanceNum);

	// 将应用名和编号一起拷贝给m_appNameWithInstanceNum
	m_appNameWithInstanceNum = m_appName + ":" + instanceNum;

	DEBUG(5, ApplicationFactory_impl::create, 
		"m_appNameWithInstanceNum: " << m_appNameWithInstanceNum)

	// 根据SAD解析器找到所有的组件
	// 定义并初始化
	std::vector <SADComponentPlacement*> * sadComplaces =
	    m_sadParser->getComponents();

	DEBUG(5, ApplicationFactory_impl::create, 
		"start create deploy strategy")
	//generate components deployment info in term of deviceAssignments.
	// 关于这个函数，有个问题，既然sadComplaces可以通过m_sadParser得到，为什么还要作为一个单独的输入
	// 经过检查程序，发现这个参数在实现中并没有用到
	// 实例化一个类
	DeployStrategy * deployStg = new BaseDeployStrategy (
	    m_registeredDevices,
	    m_sadParser,
	    m_fileMgr,
	    sadComplaces);

	// 生成配置信息
	bool result = 
		generateDeployInformation(deployStg, sadComplaces, deviceAssignments);
	delete deployStg; //delete deploy strategy

	if (!result)
	{
		unlock();
		return appVar._retn();
	}

	try {
		//create application context
		// 创建应用的命名
		// 只有应用中的组件能够被布置到设备上时，才会在命名服务中注册
		createAppNamingCtx();

	} catch (...) {
		unlock();
		return appVar._retn();
	}

	//load and execute all components according to m_deployCompsInfo
	// 实例化一个ComponentProcessIdSequence类，名字为m_appCompProcIds，且最多包含20个对象
	m_appCompProcIds = new CF::Application::ComponentProcessIdSequence (20);
	// 初始化长度为0
	m_appCompProcIds->length (0);
	try {
		// 加载和执行组件
		loadAndExecuteComps( m_appCompProcIds);
	} catch (...) {

		DEBUG(3, ApplicationFactory_impl,
		      "In Create. loadAndExecuteComps occur exception....")
		unlock();
		exit(-1);
	}

	sleep(1);

	//configure and initialize every resource component
	// 初始化和配置每个资源组件
	if ( !initializeAndConfigureRsrcComps(initConfiguration) ) {
		unlock();
		return appVar._retn();
	}

	//create all connections in term of SAD.xml
	// 创建组件之间的连接
	if (!createConnections()) {
		DEBUG(0, ApplicationFactory::create, "create connection failed")
		unlock();
		return appVar._retn();
	} else {
		DEBUG(5, ApplicationFactory::create, "create connection successfully")
	}


		//extract appNamingCtx and m_appCompImpls from componentInfo sequence
	m_appCompImpls = new CF::Application::ComponentElementSequence(20);
	m_appNamingCtxs = new CF::Application::ComponentElementSequence(20);

	m_appNamingCtxs->length(m_deployCompsInfo.size());
	m_appCompImpls->length(m_deployCompsInfo.size());
	for (unsigned int numComp = 0; 
		numComp < m_deployCompsInfo.size(); numComp++) {

		(*m_appNamingCtxs)[numComp].componentId = CORBA::string_dup(
			m_deployCompsInfo[numComp]->getIdentifier());

		if (m_deployCompsInfo[numComp]->isNamingService()) {
			(*m_appNamingCtxs)[numComp].elementId = CORBA::string_dup(
				m_deployCompsInfo[numComp]->getNamingServiceName());
		}

		(*m_appCompImpls)[numComp].componentId = CORBA::string_dup(
			m_deployCompsInfo[numComp]->getIdentifier());

		(*m_appCompImpls)[numComp].elementId = CORBA::string_dup(
			m_deployCompsInfo[numComp]->getImplId());
	}

	/*
	 * Allocate space for device assignment
	 * TODO (assume maximum length of 10 - will make dynamic in later version)
	 */
	// 实例化应用
	if (!instantiateApplication(deviceAssignments, appVar))
	{
		unlock();
		throw CF::ApplicationFactory::CreateApplicationError();
	}

	unlock();

	DEBUG(5, ApplicationFactory, "finish create application")
	return appVar._retn();
}

// 在APP_NUMS_UPPER + 1范围内选择最小的且没有被使用过的整数给应用进行一个编号，并赋值给m_instanceNum
void
ApplicationFactory_impl::updateInstanceNum() {
	DEBUG(5, ApplicationFactory_impl::updateInstanceNum, "enter in...")

	std::vector<std::string> ids;
	std::vector<unsigned char> insNumsUsed;
	// m_appSeqPtr是应用顺序指针，在构造函数里面进行了赋值	
	for (CORBA::ULong i = 0; i < m_appSeqPtr->length(); i++) {
		std::string id;
		// m_appName是应用的名字，在create函数里面进行了赋值
		// strcmp()是比较两个字符的函数，如果str1>str2，返回值>0；两串相等，返回0；如果str1<str2，返回值<0；
		// 按照m_appSeqPtr中的顺序依次检查是否有m_appName对应的名字，有就取出对应的ID，并写入到ids之中
		// 应用顺序中可能有多次该应用的名字，因此ids的大小可能大于1
		if ( 0 == strcmp(m_appName.c_str(), (*m_appSeqPtr)[i]->name() ) ) {
			// 将ID值赋给id
			id = (*m_appSeqPtr)[i]->identifier();
			// 将ID写入ids
			// push_back表示向vector中添加元素
			ids.push_back(id);
		}
	}

	// ids.size()指m_appSeqPtr中与m_appName对应的应用的个数
	// 将ids中的内容按顺序从十六进制转化为十进制，然后写入到insNum中
	// id最后的编号是用十六进制编
	for (int i = 0; i < ids.size(); i++) {
		// insStr最开始的两个字符是"0x"
		std::string insStr = "0x";
		// 将ids中的内容按顺序依次写入到insStr中
		int pos = ids[i].find_last_of(":");
		// substr表示对原始字符的一部分或全部的拷贝，substr（pos,n），从pos开始的n个字符的拷贝
		insStr.append( ids[i].substr(pos + 1, ids[i].size()) );
		unsigned short insNum = 0;

		// hexConvertToDec表示将十六进制转化为十进制，且返回值写入insNum中
		if (hexConvertToDec(insStr.c_str(), insNum)) {
			// 将insNum按顺序写入到insNumsUsed之中
			// 而且是转化为无符号的字符形式写入的
			// insNumsUsed表示已经使用过的实例的编号
			insNumsUsed.push_back((unsigned char)insNum);
		}
	}

	// 对于所有的小于APP_NUMS_UPPER + 1的整数，检查是否有应用的ID和它一致
	// 如果没有，在APP_NUMS_UPPER + 1范围内选择最小的整数给应用进行一个编号，并赋值给m_instanceNum
	for (int i = 1; i < APP_NUMS_UPPER + 1; ++i) {
		bool hasUsed = false;
		// 检查是否有应用的ID和i一致，一旦有，则将hasUsed置为true，并跳出程序
		for (int j = 0; j < insNumsUsed.size(); j++) {
			if ( (unsigned char)i == insNumsUsed[j] ) {
				hasUsed = true;
				break;
			}
		}

		if (hasUsed) {
			continue;
		} else {
			// 将i赋值给m_instanceNum
			m_instanceNum = (unsigned char)i;
			DEBUG(5, ApplicationFactory_impl::updateInstanceNum, "leave...")
			return;
		}
	}

	DEBUG(5, ApplicationFactory_impl::updateInstanceNum, "leave...")
}

// 获得每个组件的设备配置信息，如果获得成功，则返回true
bool 
ApplicationFactory_impl::generateDeployInformation(
	DeployStrategy* deployStg,
	std::vector <SADComponentPlacement*> * sadComplaces,
	const CF::DeviceAssignmentSequence & deviceAssignments)
{
	// 如果每个组件都分配了设备
	if (deviceAssignments.length() == sadComplaces->size()) {

		try {
			// 根据deviceAssignments获得配置信息m_deployCompsInfo
			m_deployCompsInfo = 
				deployStg->createDeployInfo(deviceAssignments);
		} catch (CF::ApplicationFactory::CreateApplicationError & e) {
			DEBUG(1, ApplicationFactory,
			    "[ApplicationFactory_impl::create] \
			    deployStg->createDeployInfo(deviceAssignements) \
				failed with CF::ApplicationFactory::CreateApplicationError.")
			return false;
		} catch (CF::ApplicationFactory::CreateApplicationRequestError & e) {
			DEBUG(1, ApplicationFactory,
			    "[ApplicationFactory_impl::create] \
			    deployStg->createDeployInfo(deviceAssignements) failed with \
			    CF::ApplicationFactory::CreateApplicationRequestError.")
			return false;
		} catch (...) {
			DEBUG(1, ApplicationFactory,
			    "[ApplicationFactory_impl::create] \
			    deployStg->createDeployInfo(deviceAssignements) \
				failed with Unknown Exception.")
			return false;
		}

	} else if (deviceAssignments.length() == 0) {
		// 如果所有组件都没有分配设备
		try {
			m_deployCompsInfo = deployStg->createDeployInfo();
			DEBUG(1, ApplicationFactory,
			    "[ApplicationFactory_impl::create] " << "m_deployCompsInfo \
			    length is " << m_deployCompsInfo.size())
		} catch (CF::ApplicationFactory::CreateApplicationError & e) {
			DEBUG(1, ApplicationFactory,
			    "[ApplicationFactory_impl::create] \
			    deployStg->createDeployInfo failed with \
			    CF::ApplicationFactory::CreateApplicationError.")
			return false;

		} catch (...) {
			DEBUG(1, ApplicationFactory,
			    "[ApplicationFactory_impl::create] \
			    deployStg->createDeployInfo failed with Unknown Exception.")
			return false;
		}

	} else {
		DEBUG(1, ApplicationFactory,
		    "[ApplicationFactory_impl::create]The length of deviceassignments \
		    is wrong. its not zero but not num of all components.")
		return false;
	}

	return true;
}

// 实例化应用
bool 
ApplicationFactory_impl::instantiateApplication(
	const CF::DeviceAssignmentSequence & deviceAssignments,
	CF::Application_var & appVar)
{
	CF::DeviceAssignmentSequence * assignedDevs = NULL;
		//default deployment strategy
	// 如果设备的分配顺序不存在，即没有指定组件对应的设备
	if (deviceAssignments.length() == 0) {
		// m_deployCompsInfo中分配了设备的组件大小
		CORBA::ULong deployCompsInfoSize = m_deployCompsInfo.size();

		// 创建一个DeviceAssignmentSequence类
		assignedDevs = new CF::DeviceAssignmentSequence(deployCompsInfoSize);
		assignedDevs->length(deployCompsInfoSize);

		DEBUG(7, ApplicationFactory,
			"deviceAssignedmentSequence length is: " << assignedDevs->length())

		for (unsigned int i = 0; i < deployCompsInfoSize; i++) {

			// 第i个设备的组件ID是第i个组件的ID
			(*assignedDevs)[i].componentId = CORBA::string_dup(
				m_deployCompsInfo[i]->getIdentifier());
			DEBUG(7, ApplicationFactory,
				"deviceAssignedmentSequence compId is: " << (*assignedDevs)[i].componentId)

			// 第i个设备的ID是第i个组件对应的设备ID
			(*assignedDevs)[i].assignedDeviceId = CORBA::string_dup(
				m_deployCompsInfo[i]->getAssignedDeviceId());
			DEBUG(7, ApplicationFactory,
				"deviceAssignedmentSequence deviceId is: " << (*assignedDevs)[i].assignedDeviceId)
		}
	} else {
			// external deployment strategy
			// 如果已经有设备的分配顺序，则将分配顺序拷贝给assignedDevs
		assignedDevs = new CF::DeviceAssignmentSequence(deviceAssignments);
	}

	if (m_assemblyController == NULL) {
		DEBUG(1, ApplicationFactory,
			"[ApplicationFactory_impl::create] Can't found assemblyController.")
		return false;
	}

	Application_impl * application = NULL;
	try {
		// 获得带实例化参数的ID
		std::string appId = getIdentifierWithInstanceNum(m_identifier);
		// 实例化一次应用
		application = new Application_impl (
		    appId.c_str(),
		    m_appName.c_str(),
		    m_appNameWithInstanceNum.c_str(),
		    m_softwareProfile.c_str(),
		    assignedDevs,
		    m_appCompImpls,
		    m_appNamingCtxs,
		    m_appCompProcIds,
		    m_connectionsInfo,
		    CF::Resource::_duplicate (m_assemblyController),
		    m_appSeqPtr);
	} catch (...) {

		DEBUG(1, ApplicationFactory_impl::create,
		      "exception occur when create application")
		return false;
	}

	// Add a reference to the new application to the ApplicationSequence 
	// in DomainManager
	// 在域管理器中将新的应用的参考加入应用顺序
	try {
		// 获得应用的指针
		appVar = CF::Application::_duplicate(application->_this());
		int oldLength = m_appSeqPtr->length();
		m_appSeqPtr->length(oldLength + 1);

		// 将应用加入应用顺序m_appSeqPtr
		(*m_appSeqPtr)[oldLength] = 
			CF::Application::_duplicate(application->_this());

	} catch (...) {
		return false;
	}

	return true;
}

/*
 * @brief	Convert UUID(DCE::233f-324lfs-32wefe:1) to id with instance num. 
 *        	The last num is instance num
 * @return  id with instance num
 */
// 获得带实例化编号的ID
std::string
ApplicationFactory_impl::getIdentifierWithInstanceNum(
    const std::string & scaid) {
	std::string id = scaid;
	//check if scaid is valid
	// 检查scaid是否有效
	if (isValidOfSCAId(scaid) == false) {
		DEBUG(3, ApplicationFactory_impl,
		    "In getIdentifierWithInstanceNum application id is invalid.")
		return id;
	}

	size_t pos = scaid.find_last_of(':');
	std::string str = scaid.substr(0, pos + 1);

	char temp[64];
	// 将实例化编号转化为十六进制写入temp
	sprintf(temp, "%x", (int) m_instanceNum);
	str.append(temp);
	return str;
}

// 判断SCA ID是否有效
bool
ApplicationFactory_impl::isValidOfSCAId(
    const std::string & scaid) {
	std::string id = scaid;
	unsigned int len = scaid.size();

	size_t pos = scaid.find_last_of(':');
	std::string str = scaid.substr(pos + 1, scaid.size() - pos);
	// atoi函数是将字符转化给整型输出
	int num = atoi(str.c_str());

	if ((num >= 0) && (len >= 42))
		return true;
	else
		return false;
}

// 初始化和配置组件
// 只有资源组件才可以初始化和配置
bool
ApplicationFactory_impl::initializeAndConfigureRsrcComps(
    const CF::Properties & initConfigurations) {
	DEBUG(3, ApplicationFactory_impl, "In initializeAndConfigureRsrcComps.")

	m_assemblyController = CF::Resource::_nil();

	//loop to initialize and configure every component
	// 循环初始化和配置每个组件
	for (unsigned int numComp = 0; 
		numComp < m_deployCompsInfo.size(); numComp++) {
		// 判断组件是否和SCA相容
		if (!(m_deployCompsInfo[numComp]->isScaComplicant()))
			continue;

		std::string compNamingName = "";
		DEBUG(1, ApplicationFactory,
		      "[ApplicationFactory_impl::initializeAndConfigureRsrcComps] \
		      in loop" << "deployCompsInfor size is:" << m_deployCompsInfo.size())
		//check if this component is type of Resource, if not bypass it
		// 判断组件是否是资源
		if (!m_deployCompsInfo[numComp]->isResource())
			continue;

		compNamingName = m_deployCompsInfo[numComp]->getUsageName();

		DEBUG(7, ApplicationFactory,
		    "In initializeAndConfigureRsrcComps with compNamingName: " << compNamingName)
		std::string cosName = "OpenSCA_Domain/Applications";
		cosName.append("/");
		cosName.append(m_appNameWithInstanceNum);
		cosName.append("/");
		cosName.append(compNamingName);

		CORBA::Object_ptr obj = CORBA::Object::_nil();
		
		// 根据组件的名字获得组件对象的引用
		if (!getObjectRefFromNamingService(cosName.c_str(), obj))
			return false;

		CF::Resource_ptr src = CF::Resource::_nil();
		try {
			// 从对象获得资源
			src = CF::Resource::_narrow(obj);

		} catch (...) {
			DEBUG(1, ApplicationFactory::initializeAndConfigureRsrcComps,
			    "CF::Resource::_narrow failed with Unknown Exception.")
			return false;
		}

		//store the pointer to this resource into component Info
		// 将资源指针存入组件信息
		m_deployCompsInfo[numComp]->setResourcePtr(src);

		DEBUG(1, ApplicationFactory::initializeAndConfigureRsrcComps,
		    "begin to check AssCon")
		// 判断组件是否是装配控制器
		if (m_deployCompsInfo[numComp]->isAssemblyController()) {
			//modefied by victor 20161107
			// 将资源拷贝给m_assemblyController
			m_assemblyController = CF::Resource::_duplicate(src);

			DEBUG(1, ApplicationFactory::initializeAndConfigureRsrcComps,
			    "has setted AssCon")
			try {
				// 初始化
				m_assemblyController->initialize();
			} catch (...) {
				DEBUG(1, ApplicationFactory::initializeAndConfigureRsrcComps,
				    "m_assemblyController->initialize failed with Unknown Exception.")
			}

			try {
				// 配置
				m_assemblyController->configure(initConfigurations);
			} catch (...) {
				DEBUG(1, ApplicationFactory::initializeAndConfigureRsrcComps,
				    "m_assemblyController->configure failed with Unknown Exception.")
				throw CF::ApplicationFactory::InvalidInitConfiguration();
			}

		} else {/*if(m_deployCompsInfo[numComp]->isConfigurable())*/
			try {
				// 初始化
				src->initialize();
			} catch (...) {
				DEBUG(1, ApplicationFactory::initializeAndConfigureRsrcComps,
				    "m_assemblyController->initialize failed with Unknown Exception.")
			}

			try {
				// 配置
				src->configure(initConfigurations);
			} catch (...) {
				DEBUG(1, ApplicationFactory::initializeAndConfigureRsrcComps,
				    "m_assemblyController->configure failed with Unknown Exception.")
				throw CF::ApplicationFactory::InvalidInitConfiguration();
			}
		}
	}	//for (unsigned int numComp=0; numComp<m_deployCompsInfo.size(); numComp++)

	return true;
}

// 从命名服务中获得对象的引用
// 之所以说是从命名服务中获得，是因为cosName是绑定在命名服务中
bool 
ApplicationFactory_impl::getObjectRefFromNamingService(
	const char * cosName,
	CORBA::Object_ptr & obj)
{
	sMsSleep(SDS_SLEEP);
	int count = 10;
	while (count) {
		try {
			// 从orbwarp中根据对象的名字获得对象
			obj = m_orbWrap->get_object_from_string(cosName);
		} catch (...) {
			DEBUG(1, ApplicationFactory_impl::getObjectRefFromNamingService,
				"m_orbWrap->get_object_from_string failed with Unknown Exception.")
			sMsSleep(SDS_SLEEP);
			count--;
			continue;
		}
		// 这是为了给找对象留有足够的时间
		if (CORBA::is_nil(obj)) {
			sMsSleep(SDS_SLEEP);
			count--;
		} else {
			break;
		}
	}

	if (0 == count) {
		DEBUG(5, ApplicationFactory_impl::getObjectRefFromNamingService,
			"get object failed with name: " << cosName)
		return false;
	}

	return true;
}

// 创建应用的命名服务
void
ApplicationFactory_impl::createAppNamingCtx() {
	// create naming context for this application
	CORBA::Object_var objAppsCtx;
	try {
		// 从orbwrap中找到应用对象
		objAppsCtx = m_orbWrap->get_object_from_string(
		                 "OpenSCA_Domain/Applications");

	} catch (CORBA::SystemException & ex) {
		DEBUG(1, ApplicationFactory::createAppNamingCtx,
		    "[ApplicationFactory::create] get_object_from_string " \
		    " threw CORBA::SystemException")
		exit(EXIT_FAILURE);
	} catch (...) {
		DEBUG(1, ApplicationFactory::createAppNamingCtx,
		      "[ApplicationFactory::create] get_object_from_string" \
		      " threw Unknown Exception")
		exit(EXIT_FAILURE);
	}

	CosNaming::NamingContext_var AppsContext = 
						CosNaming::NamingContext::_nil();
	try {
		// 从应用对象中获得命名服务中的应用内容
		AppsContext = CosNaming::NamingContext::_narrow(objAppsCtx);
	} catch (...) {
		DEBUG(1, ApplicationFactory::createAppNamingCtx,
		    "[ApplicationFactory::create] \
		    CosNaming::NamingContext::_narrow threw Unknown Exception")
		exit(EXIT_FAILURE);
	}

	unsigned short appCount = 0;
	std::string appContextName("");
	CORBA::Object_var objAppContext;

	bool foundEmpty = false;

	// do{}while()语句是先执行循环体，再判断，当判断为假时，退出循环，判断为真时，继续循环
	do {
		appContextName = "";
		appContextName.append(m_appNameWithInstanceNum.c_str());

		std::string tempAppContext("OpenSCA_Domain/Applications/");
		tempAppContext.append(appContextName.c_str());

		// 获得cosname
		CosNaming::Name_var cosName = m_orbWrap->string_to_CosName(
		                                  tempAppContext.c_str());

		DEBUG(7, ApplicationFactory::createAppNamingCtx,
		      "In createAppNamingCtx will call to bind_new_context_with_string")

		// 在命名服务中捆绑该应用
		m_orbWrap->bind_new_context_with_string(tempAppContext.c_str());

		// resolve的目的是什么？
		try {
			objAppContext = m_orbWrap->naming_cntx->resolve(cosName);
		} catch (const CosNaming::NamingContext::NotFound &) {
			foundEmpty = true;
			sMsSleep(5);
		}
	} while (foundEmpty);

	//create component port naming context by call bind_new_context_with_string
	// 创建组件端口命名内容
	// 当一个新的对象需要和命名服务捆绑在一起时，需要调用bind_new_context_with_string
	// 为什么要创建两次命名服务？一个是加了应用，一个是没加应用？
	std::string appNaming = "OpenSCA_Domain/" + m_appNameWithInstanceNum;
	if (false == m_orbWrap->bind_new_context_with_string(appNaming.c_str())) {
		throw CF::LifeCycle::InitializeError();
	}

	DEBUG(7, ApplicationFactory, "leaving createAppNamingCtx ")
}

// 创建端口的连接
bool
ApplicationFactory_impl::createConnections() {
	DEBUG(3, ApplicationFactory_impl, "In createConnections.")

	//clear old connection info from local variable: connectionsinfo
	// 清除旧的连接信息
	m_connectionsInfo.clear();

	std::vector <Connection *> * connections = NULL;

	if (m_sadParser) {
		DEBUG(5, ApplicationFactory_impl, "m_sadParser -> getConnections")

		// 从SAD解析器中获得连接关系
		connections = m_sadParser->getConnections();

		if (!connections) {
			DEBUG(5, ApplicationFactory_impl,"connections from sad.xml is null")
			return false;
		}
	} else {
		DEBUG(5, ApplicationFactory_impl, "m_sadParser is null exception")
		return false;
	}

	DEBUG(5, ApplicationFactory_impl,
	    "total connections is " << connections->size())

	//loop to establish connections
	// 循环来建立连接
	for (unsigned int numCont = 0; numCont < connections->size();
	        numCont++) {

		// 选取第numCont个连接
		Connection * connect = (*connections)[numCont];

		// 获得连接的ID
		std::string connectId = connect->getID();

		DEBUG(5, ApplicationFactory_impl,
		    "Creating connection start: " << connectId)

		// 判断连接的端口数目是不是大于2
		if ((connect->getExternalUsesPorts()).size() >= 2 || 
			(connect->getExternalProvidePorts()).size() >= 2) {
			continue;
		}

		//get provides port info for id and ref
		std::string providName = "";

		//CF::PPort_ptr providPort = CF::PPort::_nil();
		CORBA::Object_var providesObjRef = CORBA::Object::_nil();

		try {
			// 根据连接信息获得提供者的信息
			getProvidesPort(providName, providesObjRef, connect);
		} catch (...) {
			DEBUG(5, ApplicationFactory_impl,
			    "call getProvidesPort occur unknow exception...")
			return false;
		}

		//get uses port info for id and ref
		std::string usesName = "";
		CF::PPort_var usesPort = CF::PPort::_nil();

		try {
			// 根据连接信息获得使用者的信息
			getUsesPort(usesName, usesPort, connect);
		} catch (...) {
			DEBUG(5, ApplicationFactory_impl,
			    "call getUsesPort occur unknow exception...")
			return false;
		}

		// Create connection
		try {
			if (CORBA::is_nil(usesPort)) {
				DEBUG(5, ApplicationFactory_impl::createConnections,
				    "uses port null: " << usesName)
				continue;
			}

			if (CORBA::is_nil(providesObjRef)) {
				DEBUG(5, ApplicationFactory_impl::createConnections,
				    "provides port null: " << providName)
				continue;
			}
			DEBUG(5, ApplicationFactory_impl,
			    "usesport connect providesport start")
			// 连接端口
			usesPort->connectPort(providesObjRef, connect->getID());
			DEBUG(5, ApplicationFactory_impl,
			    "usesport connect providesport finished")
		} catch (...) {
			DEBUG(1, ApplicationFactory,
			    "[ApplicationFactory::createConnections] usesPort->connectPort \
				failed with Unknown Exception for connection ID " << connect->getID())
			return false;
		}

		DEBUG(5, ApplicationFactory_impl,
		      "Creating connection finisged: " << connectId)
		//modfied by victor at 20170819
		// 将连接信息存入m_connectionsInfo
		m_connectionsInfo.push_back(
		    new UsesConnectionInfo(usesPort, connect->getID()));
	}//for (unsigned int numCont=0; numCont<connections->size(); numCont++)

	return true;
}

// 获得提供者的端口
void
ApplicationFactory_impl::getProvidesPort(
    std::string & providName,
    CORBA::Object_var & providesport,
    const Connection * connect) {
	DEBUG(3, ApplicationFactory_impl, "In getProvidesPort.")

	if (!connect) {
		DEBUG(3, ApplicationFactory_impl, "connect is nil")
		return;
	}

	// 获得连接的提供者端口
	ProvidesPort * providPort = connect->getProvidesPort();

	if (providPort == NULL) {
		DEBUG(3, ApplicationFactory_impl,
		      "while create connection: failed to get provides port.")

		//mask occure exception in VX6.9
		throw CF::ApplicationFactory::CreateApplicationError();
	}

	CF::Resource_var providComp = CF::Resource::_nil();
	CORBA::Object_var provideObj = CORBA::Object::_nil();

	// 如果能找到命名服务中存在的组件端口
	if (providPort->isFindBy()) {
		// 获得提供者端口的名字
		providName = providPort->getFindBy()->getFindByNamingServiceName();
		DEBUG(3, ApplicationFactory_impl, " has got providName.")
		// 判断是不是MAL端口
		if (isMhalDevProvidesPort(providName)) {
			// 获得端口的指针
			getMhalDevProvidesPort(provideObj, connect, providName);
			if (!CORBA::is_nil(provideObj)) {
				providesport = provideObj;
			} else {
				DEBUG(5, ApplicationFactory_impl::getProvidesPort,
					"get provides port failed.")
			}
			return;
		}

		//get full port name in NamingService
		// 如果不是MAL端口，获得端口名字的全名称
		std::string compPortFindbyName = "";
		compPortFindbyName.append("OpenSCA_Domain/");
		compPortFindbyName.append(m_appNameWithInstanceNum);
		compPortFindbyName.append("/");
		compPortFindbyName.append(providName);

		DEBUG(3, ApplicationFactory_impl, "begin to resovle port naming")

		// 获得提供者对象引用
		bool result = getObjectRefFromNamingService(
						compPortFindbyName.c_str(), provideObj);
		if (result)
			providesport = provideObj;

	} else if (providPort->isComponentInstantiationRef()) {
		// 如果命名服务中找不到该组件端口，判断提供者端口是不是组件的实例化引用，如果是，执行下列步骤

		// 获得组件实例化的参考ID
		std::string compId = providPort->getComponentInstantiationRefID();

		// 获得提供者端口的ID
		providName = providPort->getID();

		bool foundComp = false;

		for (unsigned int i = 0; i < m_deployCompsInfo.size(); i++) {
			// 从部署的组件信息中找到对应的组件
			if (0 == strcmp(compId.c_str(), 
					m_deployCompsInfo[i]->getIdentifier())) {
				foundComp = true;
				// 获得组件对应的资源
				providComp = CF::Resource::_duplicate(
								m_deployCompsInfo[i]->getResourcePtr());
				break;
			}
		}
		if (!foundComp) {
			DEBUG(1, ApplicationFactory,
			    "[ApplicationFactory_impl::getProvidesPort]" << "Can't found \
			    component by ComponentInstantiationRef")
			return;
		}

		try {
			// 从资源组件中获得提供者端口
			provideObj = providComp->getPort(providName.c_str());
		} catch (...) {
			DEBUG(1, ApplicationFactory::getProvidesPort,
			    "providComp->getPort" << " in connection: " << providPort->getID())
		}
		if (!CORBA::is_nil(provideObj)) {
			providesport = provideObj;
		} else {
			DEBUG(1, ApplicationFactory::getProvidesPort, "narrow port failed.")
		}
	} else {
		DEBUG(1, ApplicationFactory::getProvidesPort,
		    "Can't found provides port in connection: " << providPort->getID())

		throw CF::ApplicationFactory::CreateApplicationError();
	}

	DEBUG(3, ApplicationFactory_impl, "leave getProvidesPort.")
}

// 判断提供者端口是不是MHAL设备端口，如果是，返回true
// 这里是in
bool
ApplicationFactory_impl::isMhalDevProvidesPort(
    const std::string & portName) {
	DEBUG(5, ApplicationFactory_impl::isMhalDevProvidesPort, "enter in ...")

	// 和MHAL设备名字做比较，如果名字一致，则返回true
	if ((strcmp(portName.c_str(), "MHAL_Device/mhal_srio_data_in") == 0) || 
		(strcmp(portName.c_str(), "MHAL_Device/mhal_eth_data_in") == 0) || 
		(strcmp(portName.c_str(), "MHAL_Device/mhal_axi_data_in") == 0)) {
		DEBUG(5, ApplicationFactory_impl::isMhalDevProvidesPort,
		      " this port is mhal port, leave ...")
		return true;
	} else {
		DEBUG(5, ApplicationFactory_impl::isMhalDevProvidesPort,
		      "this port isn't mhal port, leave ...")
		return false;
	}
}

// 判断用户端口是不是MHAL设备端口，如果是，返回true
// 这里是out
bool
ApplicationFactory_impl::isMhalDevUsesPort(
    const std::string & portName) {
	DEBUG(5, ApplicationFactory_impl::isMhalDevUsesPort, "enter in ...")

	if ((strcmp(portName.c_str(), "MHAL_Device/mhal_srio_data_out") == 0) || 
		(strcmp(portName.c_str(), "MHAL_Device/mhal_eth_data_out") == 0) || 
		(strcmp(portName.c_str(), "MHAL_Device/mhal_axi_data_out") == 0)) {
		DEBUG(5, ApplicationFactory_impl::isMhalDevUsesPort,
		    " this port is mhal port, leave ...")
		return true;
	} else {
		DEBUG(5, ApplicationFactory_impl::isMhalDevUsesPort,
		    "this port isn't mhal port, leave ...")
		return false;
	}
}

// 获得提供者MHAL设备的端口
void
ApplicationFactory_impl::getMhalDevProvidesPort(
    CORBA::Object_var & provideObj,
    const Connection * connect,
    const std::string & portNameId) {
	DEBUG(5, ApplicationFactory_impl::getMhalDevProvidesPort, "enter in ...")
	
	// 获得连接中使用者的端口
	UsesPort* usesPort = connect->getUsesPort();
	// 获得组件的实例化参考ID
	std::string compId = usesPort->getComponentInstantiationRefID();
	bool foundComp = false;
	std::string assignedDevId = "";
	for(unsigned int i = 0; i < m_deployCompsInfo.size(); ++i)
	{
		// 从部署的组件信息中找到组件对应的设备
		if( 0 == strcmp(compId.c_str(), m_deployCompsInfo[i]->getIdentifier()) )
		{
			foundComp = true;
			assignedDevId = m_deployCompsInfo[i]->getAssignedDeviceId();
			break;
		}
	}
	
	if(!foundComp)
	{
		DEBUG(5, ApplicationFactory_impl::getMhalDevProvidesPort,
			"don't find the component, id is: " << compId)
		return;
	}
	
	bool findAssignedDev = false;
	CF::AggregateDevice_var aggrDev = CF::AggregateDevice::_nil();
	
	for(int i = 0; i < m_registeredDevices.size(); ++i)
	{
		// 根据设备ID从注册的设备中找到该设备
		if( 0 == strcmp(m_registeredDevices[i]->identifier(), 
						assignedDevId.c_str()) )
		{
			findAssignedDev = true;
			// 找到该设备对应的聚合设备？
			aggrDev = CF::AggregateDevice::_duplicate(
						m_registeredDevices[i]->compositeDevice());
			DEBUG(5, ApplicationFactory_impl::getMhalDevProvidesPort, 
					"parent dev id: " << m_registeredDevices[i]->identifier())
			break;
		}
	}
	
	if((!findAssignedDev) || (CORBA::is_nil(aggrDev)))
		return;

	CF::DeviceSequence_var deviceSeq;
	deviceSeq = aggrDev->devices();

	for(CORBA::ULong i = 0; i < deviceSeq->length(); i++)
	{
		// 如果设备是MHAL设备
		if( 0 == strcmp("MHAL_Device", (*deviceSeq)[i]->label()) )
		{
			// 获得设备的端口
			provideObj = (*deviceSeq)[i]->getPort(portNameId.c_str());
		}
	}
	
	DEBUG(5, ApplicationFactory_impl::getMhalDevProvidesPort, "leave ...")
}

// 获得使用者的端口
// 和获得提供者的端口流程基本一致
void
ApplicationFactory_impl::getUsesPort(
    std::string & usesPortName,
    CF::PPort_var & usesPortObj,
    const Connection * connect) {

	DEBUG(3, ApplicationFactory_impl, "In getUsesPort.")

	// 获得连接的使用者端口
	UsesPort * usesPort = connect->getUsesPort();
	if (usesPort == NULL) {
		DEBUG(3, ApplicationFactory_impl,
		      "while create connection: failed to get uses port.")

		//mask occure exception in VX6.9
		throw CF::ApplicationFactory::CreateApplicationError();
	}

	CF::Resource_var usesPortComp = CF::Resource::_nil();
	CORBA::Object_var obj = CORBA::Object::_nil();

	int count = 0;
	if (usesPort->isFindBy()) {
		usesPortName = usesPort->getFindBy()->getFindByNamingServiceName();
		if (isMhalDevUsesPort(usesPortName)) {
			std::string usesPortNameId = usesPort->getID();
			getMhalDevUsesPort(obj, connect, usesPortName);
			if (!CORBA::is_nil(obj)) {
				usesPortObj = CF::PPort::_narrow(obj);
			} else {
				DEBUG(5, ApplicationFactory_impl::getUsesPort,
					"get uses port failed.")
			}
			return;
		}

		//assume that component findby is 
		//"DomainName1/appname/componentname" in naming service
		std::string compFindbyName = "";
		compFindbyName.append("OpenSCA_Domain/");
		compFindbyName.append(m_appNameWithInstanceNum);
		compFindbyName.append("/");
		compFindbyName.append(usesPortName);

		bool result = 
			getObjectRefFromNamingService(compFindbyName.c_str(), obj);
		if (!result)
			return;

		try {
			usesPortObj = CF::PPort::_narrow(obj);
		} catch (...) {
			DEBUG(1, ApplicationFactory,
			      "[ApplicationFactory_impl::getUsesPort]" << "CF::Resource::_narrow \
			      failed with Unknown Exception.")
			exit(EXIT_FAILURE);
		}

	} else if (usesPort->isComponentInstantiationRef()) {
		std::string compId = usesPort->getComponentInstantiationRefID();
		usesPortName = usesPort->getID();
		bool foundComp = false;
		for (unsigned int i = 0; i < m_deployCompsInfo.size(); i++) {
			if (0 == strcmp(compId.c_str(), 
					m_deployCompsInfo[i]->getIdentifier())) {
				foundComp = true;
				usesPortComp = CF::Resource::_duplicate(
								m_deployCompsInfo[i]->getResourcePtr());
				break;
			}
		}
		if (!foundComp) {
			DEBUG(1, ApplicationFactory::getUsesPort,
			    "Can't found uses port: " << usesPortName << "by ComponentInstantiationRef")
			return;
		}

		try {
			obj = usesPortComp->getPort(usesPortName.c_str());
		} catch (...) {
			DEBUG(1, ApplicationFactory::getUsesPort,
			    "providComp->getPort " << usesPortName)
		}

		if (!CORBA::is_nil(obj)) {
			usesPortObj = CF::PPort::_narrow(obj);
		} else {
			DEBUG(1, ApplicationFactory::getUsesPort, "narrow port failed.")
		}
	} else {
		DEBUG(1, ApplicationFactory::getUsesPort,
		    "Can't found uses port: " << usesPortName)

		throw CF::ApplicationFactory::CreateApplicationError();
	}

	DEBUG(3, ApplicationFactory_impl, "leave getUsesPort.")
}

/**
 * @brief This function used to get MHAL_Device's uses port. Through Connection,
 * 		  can get the aggregate device which component is deployed on, and MHAL_Device will
 * 		  be a child device of the aggregate device.
 */
// 获得使用者MAL设备端口
void
ApplicationFactory_impl::getMhalDevUsesPort(
    CORBA::Object_var & usesObj,
    const Connection * connect,
    const std::string & portNameId) {
	
	DEBUG(5, ApplicationFactory_impl::getMhalDevUsesPort, "enter in ...")
	
	// 获得连接的提供者的端口
	ProvidesPort* providesPort = connect->getProvidesPort();
	// 获得组件实例化的参考ID
	std::string compId = providesPort->getComponentInstantiationRefID();
	bool foundComp = false;
	std::string assignedDevId = "";
	CORBA::ULong deployCompsInfoSize = m_deployCompsInfo.size();
	for(unsigned int i = 0; i < deployCompsInfoSize; i++)
	{
		if( 0 == strcmp(compId.c_str(), 
			m_deployCompsInfo[i]->getIdentifier()) )
		{
			foundComp = true;
			assignedDevId = m_deployCompsInfo[i]->getAssignedDeviceId();
		}
	}
	
	if(!foundComp)
		return;
	
	bool findAssignedDev = false;
	CF::AggregateDevice_var aggrDev = CF::AggregateDevice::_nil();
	CORBA::ULong registeredDevSize = m_registeredDevices.size();
	for(int j = 0; j < registeredDevSize; j++)
	{
		if( 0 == strcmp(m_registeredDevices[j]->identifier(), 
					assignedDevId.c_str()) )
		{
			findAssignedDev = true;
			aggrDev = CF::AggregateDevice::_duplicate(
						m_registeredDevices[j]->compositeDevice());
			break;
		}
	}
	
	if((!findAssignedDev) || (CORBA::is_nil(aggrDev)))
		return;
	
	CF::DeviceSequence_var deviceSeq;
	deviceSeq = aggrDev->devices();
	for(CORBA::ULong i = 0; i < deviceSeq->length(); i++)
	{
		if( 0 == strcmp("MHAL_Device", (*deviceSeq)[i]->label()) )
		{
			usesObj = (*deviceSeq)[i]->getPort(portNameId.c_str());

			return;
		}
	}
	
	DEBUG(5, ApplicationFactory_impl::getMhalDevUsesPort, "leave ...")
}

// 找到域中所有注册的设备，并将其赋值给m_registeredDevices
void
ApplicationFactory_impl::getRegisteredDevices() {
	DEBUG(3, ApplicationFactory, "In getRegisteredDevices.")

	CF::DomainManager::DeviceManagerSequence_var devMgrs;
	try {
		// 从域管理器中返回设备管理器的指针
		devMgrs = m_dmnMgr->deviceManagers();
	} catch (CORBA::SystemException & e) {
		DEBUG(1, ApplicationFactory::getRegisteredDevices,
			"m_dmnMgr->deviceManagers failed with CORBA::SystemException.")
	} catch (...) {
		DEBUG(1, ApplicationFactory::getRegisteredDevices,
			"m_dmnMgr->deviceManagers failed with Unknown Exception.")
		exit(EXIT_FAILURE);
	}

	// 找出域中所有注册的设备，赋值给m_registeredDevices
	// 一个域中可能有多个设备管理器，而每个设备管理器可能管理多个设备
	// 多个设备管理器是为了管理分立的多个系统上的设备
	for (unsigned int numDevMgr = 0; numDevMgr < devMgrs->length();
	        numDevMgr++) {
		// 找到所有在第numDevMgr个设备管理器注册的设备
		CF::DeviceSequence_var devSeq =
		    devMgrs[numDevMgr]->registeredDevices();

		// 将注册的设备赋值给m_registeredDevices
		for (unsigned int numDev = 0; numDev < devSeq->length(); numDev++) {
			m_registeredDevices.push_back(
			    CF::Device::_duplicate(devSeq[numDev]));

			DEBUG(5, ApplicationFactory::getRegisteredDevices,
			    "In getRegisteredDevices numDev: " << numDev)
			DEBUG(5, ApplicationFactory::getRegisteredDevices,
			    "In getRegisteredDevices identifier: " << devSeq[numDev]->identifier())
		}
	}

	DEBUG(5, ApplicationFactory, "Leaving getRegisteredDevices.")
}

// 加载和执行组件
void
ApplicationFactory_impl::loadAndExecuteComps(
    CF::Application::ComponentProcessIdSequence * pids) {
	DEBUG(3, ApplicationFactory, "In loadAndExecuteComps.")
	DEBUG(3, ApplicationFactory_impl,
	    "m_deployCompsInfo size:" << m_deployCompsInfo.size())

    char openScaPath[64];
    getConfigFilePathFromSHM(openScaPath, sizeof(openScaPath));
  	ConfigParser configParser(openScaPath);
	std::string fsroot = configParser.getValueById(CONSTANT::FSROOT);

	for (unsigned int numComp = 0; numComp < m_deployCompsInfo.size();
	        numComp++) {
		openscaSupport::ComponentInfo * component = m_deployCompsInfo[numComp];

		DEBUG(1, ApplicationFactory_impl,
		    "Component: " << component->getUsageName() << 
		    "Assigned device: " << component->getAssignedDeviceId())

		CF::Device_ptr device;
		try {
			// 根据组件对应的设备ID找到设备接口
			device = find_device_from_id(component->getAssignedDeviceId());
		} catch (...) {
			DEBUG(1, ApplicationFactory::loadAndExecuteComps,
			    "find_device_from_id failed with Unknown Exception")
			throw CF::ApplicationFactory::CreateApplicationError();
		}

		DEBUG(1, ApplicationFactory_impl,
		    "Host is " << device->label () << " Local file name \
		    is: " << component->getLocalFileName())

		// Now we have a pointer to the required device
		// Get allocation properties
		try {
			// 根据组件的分配能力需要对设备进行分配
			device->allocateCapacity(component->getAllocationCapacities());
		} catch (...) {
			DEBUG(1, ApplicationFactory::loadAndExecuteComps,
			    "device->allocateCapacity failed with Unknown Exception")
			throw CF::ApplicationFactory::CreateApplicationError();
		}

		// now that capacity has been allocated, need to execute the component.
		// check devices until an executable device has been found, set up
		// the pointer to the device, and then execute. this assumes that
		// only a single GPP is being used.

		/// \TODO Validate that the intended device supports the LoadableDevice interface

		CF::FileManager::MountSequence_var mts;
		try {
			// 从文件管理器中找到mounts
			mts = m_fileMgr->getMounts();
		} catch (...) {
			DEBUG(1, ApplicationFactory,
				"[ApplicationFactory::loadAndExecuteComponents] \
				fileMgr->getMounts failed with Unknown Exception")
			throw CF::ApplicationFactory::CreateApplicationError();
		}
		
		// 从组件中找到代码文件的名字
		std::string compLocalFile = component->getLocalFileName();
		DEBUG(1, ApplicationFactory_impl, "loading " << compLocalFile)

		// 根据文件名找到文件所在的文件管理器指针
		unsigned int mtsIdx = getFileSystemIndex(mts, compLocalFile.c_str());
		if (-1 == mtsIdx)
			return;

		// binaryFileName和compLocalFile是一样的
		std::string binaryFileName = component->getLocalFileName();
		CF::LoadableDevice::LoadType loadType = component->getCodeType();
		
		// 加载组件的程序文件
		// mts[mtsIdx].fs是第mtsIdx个文件系统
		bool result = loadComponentCodeFile(mts[mtsIdx].fs, device, 
					binaryFileName.c_str(), loadType);
		if (!result)
			return;

		DEBUG(7, ApplicationFactory,
		      "In loadAndExecuteComponents will call excute")
		// Execute when necessary
		// 执行条件
		if ((loadType == CF::LoadableDevice::EXECUTABLE) || 
			(loadType == CF::LoadableDevice::SHARED_LIBRARY) &&
			(0 != strcmp(component->getEntryPoint(), ""))) {
			/// \TODO: Validate that the intended device supports 
			/// the LoadableDevice interface

			DEBUG(1, ApplicationFactory_impl, "executing: " << binaryFileName)

			//parse options such as stack size / priority / entry point
			CF::Properties options;
			// 获得组件的执行选项
			getComponentExecOptions(component, options);

			//parse input parameters such as -APP_NAME / -ID / -DEBUG / -LABEL
			CF::Properties parameters;
			// 获得组件的执行参数
			getComponentExecParameters(component, parameters, fsroot.c_str());

			CF::ExecutableDevice::ProcessID_Type tempPid;
			// 开启组件的执行过程，并获得执行id
			// 组件的执行过程具体是指什么？
			tempPid = executeComponentProcess(device, binaryFileName.c_str(), options, parameters);

			if (tempPid < 0) {
				DEBUG(1, ApplicationFactory::loadAndExecuteComps,
					"tempPid is less than zero.")
				throw CF::ApplicationFactory::CreateApplicationError();
			} else {
				// 如果执行成功，将执行id和组件ID信息写入pids
				pids->length(pids->length() + 1);
				(*pids)[pids->length() - 1].processId = tempPid;
				(*pids)[pids->length() - 1].componentId = CORBA::string_dup(
					component->getIdentifier());
			}
		}
	}//for (unsigned int numComp=0; numComp<m_deployCompsInfo.size (); numComp++)
}

// 根据文件名找到文件所在的文件系统
unsigned int 
ApplicationFactory_impl::getFileSystemIndex(
	CF::FileManager::MountSequence_var mts,
	const char * fileName)
{
	unsigned int index = -1;

	for (unsigned int i = 0; i < mts->length(); i++) {
		try {
			// 根据文件名找到文件所在的文件系统
			if (mts[i].fs->exists(fileName))
				index = i;
				break;
		} catch (CF::InvalidFileName & _ex) {
			DEBUG(1, ApplicationFactory::getFileSystemIndex,
				"when searching for FileSys \
				containing " << fileName << " occure \
				InvalidFileName exception")
		} catch (CF::FileException & _ex) {
			DEBUG(1, ApplicationFactory::getFileSystemIndex,
				"Searching for FileSys \
				containing " << fileName << " occure \
				FileExcetpion")
		} catch (...) {
			DEBUG(1, ApplicationFactory::getFileSystemIndex,
				"Searching for FileSys \
				containing" << fileName << " Unknown Exception")
		}
	}

	return index;
}

// 加载组件的程序文件，加载成功返回true
bool 
ApplicationFactory_impl::loadComponentCodeFile(
	CF::FileSystem_ptr fs,
	CF::Device_ptr device,
	const char * binaryFileName,
	CF::LoadableDevice::LoadType loadType)
{
	CF::LoadableDevice_var loadabledev;
	try {
		// 从设备中找到可加载设备
		loadabledev = CF::LoadableDevice::_narrow(device);
	} catch (...) {
		DEBUG(1, ApplicationFactory::loadComponentCodeFile,
			"CF::LoadableDevice::_narrow failed with Unknown Exception")
		return false;
	}

	if (CORBA::is_nil(loadabledev)) {
		DEBUG(1, ApplicationFactory::loadComponentCodeFile,
			"loadabledev is nil.")
		return false;
	}

	try {
		// 将文件加载到可加载设备上
		loadabledev->load(fs, binaryFileName, loadType);
	} catch (CF::InvalidFileName & _ex) {
		DEBUG(1, ApplicationFactory::loadComponentCodeFile,
			"While loading binaryfile with exception: " << _ex.msg)
		return false;
	} catch (CF::Device::InvalidState & _ex) {
		DEBUG(1, ApplicationFactory::loadComponentCodeFile,
			"While loading binaryfile with exception: " << _ex.msg)
		return false;
	} catch (...) {
		DEBUG(1, ApplicationFactory::loadComponentCodeFile,
			"While loading binaryfile with  Unknown Exception")
		return false;
	}

	return true;
}

// 获得组件的执行选项
void 
ApplicationFactory_impl::getComponentExecOptions(
	openscaSupport::ComponentInfo * component,
	CF::Properties & options)
{
	options.length(3);

	// 堆栈的大小
	CF::DataType stkSizeDt;
	stkSizeDt.id = CORBA::string_dup("STACK_SIZE_ID");
	CORBA::ULong stkSize = component->getStackSize();
	// 这里的<<=感觉应该是赋值，应该属于类里面对运算符的重新定义，但具体定义在哪里没找到
	stkSizeDt.value <<= stkSize;
	options[0] = stkSizeDt;
	DEBUG(1, ApplicationFactory_impl::getComponentExecOptions,
		"In loadAndExecuteComp stack size: " << stkSize)

	// 优先级
	CF::DataType prioDt;
	prioDt.id = CORBA::string_dup("PRIORITY_ID");
	CORBA::ULong prio = component->getPriority();
	prioDt.value <<= prio;
	options[1] = prioDt;
	DEBUG(1, ApplicationFactory_impl::getComponentExecOptions,
		"In loadAndExecuteComp priority: " << prio)

	// 进入点
	CF::DataType entryPointDt;
	entryPointDt.id = CORBA::string_dup("ENTRY_POINT");
	std::string entryPoint = component->getEntryPoint();
	entryPointDt.value <<= entryPoint.c_str();
	options[2] = entryPointDt;
	DEBUG(1, ApplicationFactory_impl::getComponentExecOptions,
		"In loadAndExecuteComp netry_point: " << entryPoint)
}

// 获得组件的执行参数
void
ApplicationFactory_impl::getComponentExecParameters(
	openscaSupport::ComponentInfo * component,
	CF::Properties & parameters,
	const char * fsroot)
{
	parameters.length(6);

	// 应用名字
	CF::DataType appNameDt;
	appNameDt.id = CORBA::string_dup("-APP_NAME");
	appNameDt.value <<= m_appNameWithInstanceNum.c_str();
	parameters[0] = appNameDt;

	// debug信息
	CF::DataType debugDt;
	debugDt.id = CORBA::string_dup("-DEBUG");
	debugDt.value <<= "8";
	parameters[1] = debugDt;

	// ID
	CF::DataType idDt;
	idDt.id = CORBA::string_dup("-ID");
	idDt.value <<= component->getIdentifier();
	parameters[2] = idDt;
	DEBUG(1, ApplicationFactory_impl::getComponentExecParameters,
		"In loadAndExecuteComp comp id: " << component->getIdentifier())

	// cos名字
	CF::DataType cosNamingDt;
	cosNamingDt.id = CORBA::string_dup("-COS_NAMING");
	cosNamingDt.value <<= component->getNamingServiceName();
	parameters[3] = cosNamingDt;
	DEBUG(1, ApplicationFactory_impl::getComponentExecParameters,
		"In loadAndExecuteComp comp name: " << component->getNamingServiceName())

	// SPD文件路径
	CF::DataType spdFileDt;
	spdFileDt.id = CORBA::string_dup("-SFTFL");
	spdFileDt.value <<= component->getImplSPDFile();
	parameters[4] = spdFileDt;

	//ConfigParser configParser("opensca.conf");
	//std::string fsroot = configParser.getValueById(CONSTANT::FSROOT);
	// 文件系统的根路径
	CF::DataType fsrootDt;
	fsrootDt.id = CORBA::string_dup("-FSROOT");
	fsrootDt.value <<= fsroot;
	parameters[5] = fsrootDt;
}

// 执行组件过程
CF::ExecutableDevice::ProcessID_Type
ApplicationFactory_impl::executeComponentProcess(
	CF::Device_ptr device,
	const char * binaryFileName,
	const CF::Properties & options,
	const CF::Properties & parameters)
{
	CF::ExecutableDevice::ProcessID_Type pid = -1;
	CF::ExecutableDevice_var execdev;
	try {
		// 从设备中找到可执行设备
		execdev = CF::ExecutableDevice::_narrow(device);
	} catch (...) {
		DEBUG(1, ApplicationFactory,
			"[ApplicationFactory::loadAndExecuteComponents] \
			CF::ExecutableDevice::_narrow failed with Unknown Exception")
		return pid;
	}

	if (CORBA::is_nil(execdev)) {
		DEBUG(7, ApplicationFactory_impl,
			"component is assigned to device that is only Loadable")
		return pid;
	}

	try {
		// 按照执行选项和执行参数执行程序
		pid = execdev->execute(binaryFileName, options, parameters);
	} catch (CF::InvalidFileName & _ex) {
		DEBUG(1, ApplicationFactory,
			"[ApplicationFactory::create] CF::InvalidFileName when calling \
			'execute' on a device: " << _ex.msg)
		return pid;
	} catch (CF::Device::InvalidState & _ex) {
		DEBUG(1, ApplicationFactory,
			"[ApplicationFactory::create] CF::InvalidState when \
			calling 'execute' on a device: " << _ex.msg)
		return pid;
	} catch (...) {
		DEBUG(1, ApplicationFactory,
			"[ApplicationFactory::create] Unknown Exception when \
			calling 'execute' on a device: Unknown Exception")
		return pid;
	}

	return pid;
	// NOTE: The PID returned by execute is not handled
	// An exception shall be thrown when PID = -1
}

// 根据ID找到设备
CF::Device_ptr
ApplicationFactory_impl::find_device_from_id(
    const char * deviceId) {
	DEBUG(5, ApplicationFactory_impl::find_device_from_id, "enter in ...")

	for (unsigned int i = 0; i < m_registeredDevices.size(); i++) {
		// 将设备的ID和所有注册过的设备的ID做比较
		if (strcmp(m_registeredDevices[i]->identifier(), deviceId) == 0) {
			DEBUG(5, ApplicationFactory_impl::find_device_from_id,
			      "leaving ...")
			// NOTE: This is DANGEROUS!!
			return CF::Device::_duplicate(m_registeredDevices[i]); 
		}
	}

	std::cerr << "Device not found, this should never happen." << std::endl;
	exit(EXIT_FAILURE);
}

void 
ApplicationFactory_impl::lock()
{
#ifdef __SDS_OS_VXWORKS__
	semTake(semAppsMutex, WAIT_FOREVER);
#elif defined __SDS_OS_LINUX__
	sds_lock(BOOST_CONSTANT::APP_MUTEX_CND);
#endif
}

void
ApplicationFactory_impl::unlock()
{
#ifdef __SDS_OS_VXWORKS__
	semGive(semAppsMutex);
#elif defined __SDS_OS_LINUX__
	sds_unlock(BOOST_CONSTANT::APP_MUTEX_CND);
#endif
}
