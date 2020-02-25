/***************************************************************************//**
* @file     Application_impl.cpp
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

#include "../include/Application_impl.h"
#include "SADParser.h"
#include "PRFParser.h"
#include "utils.h"
#include "ConfigParser.h"
#include "Boost_utils.h"

#ifdef __SDS_OS_VXWORKS__
extern SEM_ID semAppsMutex;
#endif

/*
 * The Application class provides the interface for the control, configuration,
 * and status of an instantiated application in the domain.
 * The Application interface inherits the IDL interface of Resource. A created
 * application instance may contain Resource components and/or non-CORBA
 * components.
 * The Application interface releaseObject operation provides the interface to
 * release the computing resources allocated during the instantiation of the
 * application, and de-allocate the devices associated with Application instance.
 *
 * An instance of an Application is returned by the create operation of an
 * instance of the ApplicationFactory class.
 */
// 函数作用：构造函数
Application_impl::Application_impl(
    const char * appId,
    const char * appName,
    const char * appNameWithInstanceNum,
    const char * profile,
    CF::DeviceAssignmentSequence * devSeq,
    CF::Application::ComponentElementSequence * implSeq,
    CF::Application::ComponentElementSequence * namingCtxSeq,
    CF::Application::ComponentProcessIdSequence * procIdSeq,
    std::vector <UsesConnectionInfo *> connectionsData,
    CF::Resource_ptr assemblyController,
    CF::DomainManager::ApplicationSequence * appseq) :
	// 对父类进行初始化
	Resource_impl( appId ) {

	DEBUG(1, Application, "In Application constructor.")

	m_identifier = appId;
	m_name = appName;
	m_appNameWithInstanceNum = appNameWithInstanceNum;
	m_sadProfile = profile;
	m_assemblyController = assemblyController;
	m_appseq = appseq;

	// 应用组件对应的设备分配序列
	// 存放了组件的ID和每个组件分配的设备ID
	m_appCompDevices = new CF::DeviceAssignmentSequence();
	if ( devSeq != NULL ) {
		m_appCompDevices->length( devSeq->length() );

		for (unsigned int i = 0; i < devSeq->length(); i++) {
			(*m_appCompDevices)[i] =  (*devSeq)[i];
			DEBUG(7, App_impl, "appCompdevices componentId: " <<
			      (*m_appCompDevices)[i].componentId)
			DEBUG(7, App_impl, "appCompdevices deviceId: " <<
			      (*m_appCompDevices)[i].assignedDeviceId)
		}
	} else {
		m_appCompDevices->length( 0 );
		DEBUG(2, Applicaton_impl, "In constructor devSeq is nil")

		exit(EXIT_FAILURE);
	}

	// 应用组件对应的实现序列
	// 存放的是组件ID和组件实现的ID
	m_appCompImpls = new CF::Application::ComponentElementSequence();
	if ( implSeq != NULL) {
		m_appCompImpls->length( implSeq->length() );

		for (unsigned int i = 0; i < implSeq->length(); i++)
			(*m_appCompImpls)[i] =  ( *implSeq )[i];
	} else {
		m_appCompImpls->length( 0 );
		DEBUG(2, Applicaton_impl, "In constructor implSeq is nil")

		exit(EXIT_FAILURE);
	}

	// 应用组件对应的命名服务序列
	// 存放的是组件ID和组件对应的命名服务
	m_appCompNamingCtxs = new CF::Application::ComponentElementSequence();
	if ( namingCtxSeq != NULL) {
		m_appCompNamingCtxs->length( namingCtxSeq->length() );

		for (unsigned int i = 0; i < namingCtxSeq->length(); i++)
			(*m_appCompNamingCtxs)[i] =  (*namingCtxSeq)[i];
	} else {
		m_appCompNamingCtxs->length( 0 );
		DEBUG(2, Applicaton_impl, "In constructor namingCtxSeq is nil")

		exit(EXIT_FAILURE);
	}

	// 应用组件对应的进程序列
	// 存放的是进程ID和组件ID
	m_appCompProcIds = new CF::Application::ComponentProcessIdSequence();
	if ( procIdSeq != NULL) {
		m_appCompProcIds->length( procIdSeq->length() );

		for (unsigned int i = 0; i < procIdSeq->length(); i++)
			(*m_appCompProcIds)[i] =  (*procIdSeq)[i];
	} else {
		m_appCompProcIds->length( 0 );
		DEBUG(2, Applicaton_impl, "In constructor procIdSeq is nil")

		exit(EXIT_FAILURE);
	}

	// 连接信息
	for (unsigned int i = 0; i < connectionsData.size(); i++) {
		UsesConnectionInfo* conntInfo =
		    new UsesConnectionInfo(connectionsData[i]->getPort(),
		                           connectionsData[i]->getID());

		m_connectsData.push_back(conntInfo);
	}

	postConstructor();

	DEBUG(2, Application, "Leaving Applcaiton constructor.")
}

Application_impl::~Application_impl() {
	delete m_appCompDevices;
	m_appCompDevices = NULL;

	delete m_appCompImpls;
	m_appCompImpls = NULL;

	delete m_appCompNamingCtxs;
	m_appCompNamingCtxs = NULL;

	delete m_appCompProcIds;
	m_appCompProcIds = NULL;

	for (unsigned int i = 0; i < m_connectsData.size(); i++)
		delete m_connectsData[i];
	m_connectsData.clear();

	delete m_sadParser;

	DEBUG(2, Application, "leaving Applicaiton deconstructor.")
}

void 
Application_impl::postConstructor()
{
	DEBUG(5, Application_impl::postConstructor, "enter in...")
	//instantiate ORB_Wrap in order to resolve domain manager ref
#ifdef __SDS_OS_VXWORKS__
	m_orbWrap = new openscaSupport::ORB_Wrap::ORB_Wrap();
#elif defined __SDS_OS_LINUX__
	m_orbWrap = new openscaSupport::ORB_Wrap();
#endif
	if ( !m_orbWrap ) {
		DEBUG(5, App_impl,
		      "[ApplicationFactory_impl] instantiate ORB_Wrap failed.")
		exit(EXIT_FAILURE);
	}

	// 获得域管理器对象
	CORBA::Object_var dmnObj = CORBA::Object::_nil();
	try {
		dmnObj = m_orbWrap->get_object_from_string(
		             "OpenSCA_Domain/Domain_Manager");
	} catch (...) {
		DEBUG(5, App_impl,
		      "[ApplicationFactory_impl] m_orbWrap->get_object_from_string \
			failed with Unknown Exception.")
		exit(EXIT_FAILURE);
	}

	// 获得域管理器
	try {
		m_dmnMgr = CF::DomainManager::_narrow(dmnObj.in());
	} catch (...) {
		DEBUG(5, App_impl, "[ApplicationFactory_impl] \
			CF::DomainManager::_narrow failed with Unknown Exception.")
		exit(EXIT_FAILURE);
	}

	// parser SAD.xml for this application
	if (CORBA::is_nil(m_dmnMgr)) {
		DEBUG(5, App_impl,
		      "[Application_impl::releaseAllResources] m_dmnMgr is nil;")
		return;
	}

	// 获得文件管理器
	m_fileMgr = m_dmnMgr->fileMgr();
	if (CORBA::is_nil(m_fileMgr)) {
		DEBUG(5, App_impl, "[Application_impl::releaseAllResources] \
			m_dmnMgr->fileMgr failed with m_fileMgr is nil.")
		return;
	}

	CF::File_ptr sadfl = CF::File::_nil();
	try {
		// 打开SAD文件
		sadfl = m_fileMgr->open(m_sadProfile.c_str(), true);
	} catch (CF::InvalidFileName & e) {
		DEBUG(5, App_impl,
		      "[Application_impl::releaseAllResources] \
		    m_fileMgr->open failed with invalid file name.")
		return;
	} catch (...) {
		DEBUG(5, App_impl,
		      "[Application_impl::releaseAllResources] \
			m_fileMgr->open failed with Unknown Exception")
	}

	if (!CORBA::is_nil(sadfl)) {
		// 获得SAD解析器
		m_sadParser = new SADParser(sadfl);
	}

	try {
		sadfl->close();
	} catch (...) {
		DEBUG(5, App_impl, "[Application_impl::releaseAllResources] \
			sadfl->close failed with Unknown Exception.")
		return;
	}

	DEBUG(5, Application_impl::postConstructor, "leave...")
}

// 获得应用组件对应的设备
CF::DeviceAssignmentSequence *
Application_impl::componentDevices() {
	//DEBUG(5, Application, "In componentDevices.")
	CF::DeviceAssignmentSequence_var devAssigSeq;
	try {
		devAssigSeq = new CF::DeviceAssignmentSequence(*m_appCompDevices);
	} catch (...) {
		DEBUG(5, App_impl, "[Application_impl::componentDevices] Unknown Exception.")
		throw;
	}

	return  devAssigSeq._retn();
}

// 获得组件的实现
CF::Application::ComponentElementSequence *
Application_impl::componentImplementations() {
	//DEBUG(5, Application, "In componentImplementations.")

	CF::Application::ComponentElementSequence_var cmpImplsSeq;
	try {
		cmpImplsSeq = 
			new CF::Application::ComponentElementSequence(*m_appCompImpls);
		DEBUG(5, App_impl, "[Application_impl::componentImplementations] leaving....")
	} catch (...) {
		DEBUG(5, App_impl,
		    "[Application_impl::componentImplementations] Unknown Exception.")
		throw;
	}

	return  cmpImplsSeq._retn();
}

// 获得组件的命名内容
CF::Application::ComponentElementSequence *
Application_impl::componentNamingContexts() {
	DEBUG(5, Application, "In componentNamingContexts.")
	CF::Application::ComponentElementSequence_var cmpNmCtxSeq;
	try {
		cmpNmCtxSeq = new CF::Application::ComponentElementSequence(
		    *m_appCompNamingCtxs);
	} catch (...) {
		DEBUG(5, App_impl,
		    "[Application_impl::componentNamingContexts]Unknown Exception.")
		throw;
	}

	return  cmpNmCtxSeq._retn();
}

// 获得组件进程的ID
CF::Application::ComponentProcessIdSequence *
Application_impl::componentProcessIds() {
	DEBUG(5, Application, "In componentProcessIds.")
	CF::Application::ComponentProcessIdSequence_var cmpProcIdsSeq;
	try {
		cmpProcIdsSeq = new CF::Application::ComponentProcessIdSequence(
		    *m_appCompProcIds);
	} catch (...) {
		DEBUG(5, App_impl, "[Application_impl::componentProcessIds] Unknown Exception.")
		throw;
	}

	return cmpProcIdsSeq._retn();
}

/**
 * The configure operation allows id/value pair configuration properties to be
 * assigned to application implementing this interface.
 */
// 配置
void
Application_impl::configure(
    const CF::Properties & cofigProperties)
throw (
    CF::PropertySet::PartialConfiguration,
    CF::PropertySet::InvalidConfiguration,
    CORBA::SystemException) {
	DEBUG(5, Application, "In configure.")

	try {
		m_assemblyController->configure( cofigProperties );
	} catch (CF::PropertySet::PartialConfiguration & e) {
		DEBUG(5, App_impl,
		    "[Application_impl::configure] assemblyController-> \
		    configure failed with CF::PropertySet::PartialConfiguration \
		    Exception.")
		throw e;
	} catch (CF::PropertySet::InvalidConfiguration & e) {
		DEBUG(5, App_impl,
		    "[Application_impl::configure] assemblyController->configure \
		    failed with CF::PropertySet::InvalidConfiguration Exception.")
		throw e;
	} catch (CORBA::SystemException & e) {
		DEBUG(5, App_impl,
		    "[Application_impl::configure] assemblyController->configure \
		    failed with CORBA::SystemException.")
		throw;
	} catch (...) {
		DEBUG(5, App_impl,
		    "[Application_impl::configure] assemblyController->configure \
		    failed with Unknown Exception.")
		throw;
	}
}

/**
 * The getPort operation returns object references for port names that are in the
 * application SAD externalports element.
 * The getPort operation shall return object references only for input port names
 * that match the port names that are in the application SAD externalports element.
 */
// 根据id获得端口对象
CORBA::Object_ptr
Application_impl::getPort(
    const char * id)
throw (
    CORBA::SystemException,
    CF::PortSupplier::UnknownPort) {
	DEBUG(5, Application, "In getPort with pordid: " << id)

	if (CORBA::is_nil(m_assemblyController)) {
		DEBUG(5, App_impl, "[Application_impl::getPort] assembleyController is nil;")
		return NULL;
	}

	//modify by maketure 20171026
	std::string targetPortName;

	// 获得连接信息
	std::vector<Connection* > * connects = m_sadParser->getConnections();

	// 获得外部端口
	std::vector <ExternalPort* > * externalPorts = 
									m_sadParser->getExternalPorts();

	DEBUG(5, Application_impl::getPort,
	    "externalPorts size is = " << externalPorts->size())

	for (int i = 0; i < externalPorts->size(); i++) 
	{
		// 从外部端口中获得组件实例化的参考ID
		std::string compInstantId =
		    (*externalPorts)[i]->getComponentInstantiationRefId();

		DEBUG(5, Application_impl,
		    "in getPort external refid is " << compInstantId.c_str())

		std::string externalPortName = m_name + "/";
		// 如果外部端口是提供者
		if ( (*externalPorts)[i]->isProvidesIdentifier() ) {
			// 获得外部端口的名字
			externalPortName += (*externalPorts)[i]->getProvidesIdentifier();
			// 如果外部端口的名字和输入的ID名字一致
			if ( strcmp(id, externalPortName.c_str()) == 0 ) 
			{
				// 获得外部提供者端口的名字
				getExternalProvidesPortName(externalPortName.c_str(),
					compInstantId.c_str(), connects, targetPortName);
			}
		} 
		// 如果外部端口是使用者
		else if ( (*externalPorts)[i]->isUsesIdentifier() ) {
			// 获得外部端口的名字
			externalPortName += (*externalPorts)[i]->getUsesIdentifier();
			DEBUG(5, Application_impl,
			      "getPorts external Provides -> externalPortName :" << externalPortName.c_str())
			// 如果外部端口的名字和输入的ID名字一致
			if ( strcmp(id, externalPortName.c_str()) == 0) {
				// 获得外部使用者端口的名字
				getExternalUsesPortName(externalPortName.c_str(),
					compInstantId.c_str(), connects, targetPortName);
			}
		} else {
			DEBUG(1, Application, " fail to get external indentifier " )
			throw;
		}
	}

	DEBUG(5, Application_impl, "going to call getPort")

	try {
		DEBUG(5, Application, 
			"leaving getPort with targetPortName.c_str() = " << targetPortName.c_str())

		// 从端口名字获得端口的目标参考
		return m_assemblyController->getPort( targetPortName.c_str() );
	} catch (CF::PortSupplier::UnknownPort & e) {
		DEBUG(5, App_impl,
		    "[Application_impl::getPort] assemblyController->getPort failed \
			with UnknownPort Exception.")
		throw e;
	} catch (CORBA::SystemException & e) {
		DEBUG(5, App_impl,
		    "[Application_impl::getPort] assemblyController->getPort failed \
			with CORBA::SystemException.")
		throw;
	} catch (...) {
		DEBUG(5, App_impl,
		    "[Application_impl::getPort] assemblyController->getPort failed \
			with Unknown Exception.")
		throw;
	}
}

// 获得外部提供者端口名字
bool
Application_impl::getExternalProvidesPortName(
	const char * externalPortName,
	const char * compInstantId,
	const std::vector<Connection * > * connects,
	std::string & targetPortName)
{
	DEBUG(5, Application_impl,
		"getPorts external Provides -> externalPortName :" << externalPortName)

	//find the target port connectted to this external port
	for (int i = 0; i < connects->size(); i++) {
		// 从连接中获得两个外部提供者端口
		std::vector<ProvidesPort*> twoExternalProvidePorts =
							(*connects)[i]->getExternalProvidePorts();

		if (twoExternalProvidePorts.size() != 2) {
			DEBUG(5, Application, "this is not external provide connections")
			continue;
		}
		std::string firstFindByName = "";
		std::string secondFindByName = "";

		if (twoExternalProvidePorts[0]->getFindBy() &&
			twoExternalProvidePorts[1]->getFindBy()) 
		{
			// 获得端口的名字
			firstFindByName += twoExternalProvidePorts[0]->getFindBy()->
				getFindByNamingServiceName();
			secondFindByName += twoExternalProvidePorts[1]->getFindBy()->
				getFindByNamingServiceName();
		} else {
			DEBUG(5, Application,
				"In getPort maybe  Exterernal provideport elment have \
				not FindBy childelement " )
			return false;
		}

		// 获得跟端口连接的组件的实例化ID
		std::string firstCompInsId = 
			twoExternalProvidePorts[0]->getComponentInstantiationRefID();
		std::string secondCompInsId = 
			twoExternalProvidePorts[1]->getComponentInstantiationRefID();
		// 组件的实例化ID和第二个端口连接的组件的实例化ID一致
		// 外部端口的名字和第一个端口的名字一致
		// 这一块没太搞懂
		// 外部端口是提供者，组件是使用者
		if ((strcmp(compInstantId, secondCompInsId.c_str()) == 0) &&
			(strcmp(externalPortName, firstFindByName.c_str()) == 0)) {
			targetPortName = secondFindByName;
			return true; 
		} else if ((strcmp(compInstantId, firstCompInsId.c_str()) == 0) &&
			(strcmp(externalPortName, secondFindByName.c_str()) == 0)) {
			targetPortName = firstFindByName;
			return true;
		} else {
			DEBUG(5, Application, "external connection is invalid")
			return false;
		}
	}	// for (int j=0; j<connects->size(); j++)

	return false;
}

// 获得外部使用者端口名字
bool
Application_impl::getExternalUsesPortName(
	const char * externalPortName,
	const char * compInstantId,
	const std::vector<Connection * > * connects,
	std::string & targetPortName)
{
	DEBUG(5, Application_impl::getExternalUsesPortName, "enter in...")
	//find the target port connectted to this external port
	for (int j = 0; j < connects->size(); j++) {
		std::vector<UsesPort* > twoExternalUsesPorts =
						(*connects)[j]->getExternalUsesPorts();

		DEBUG(5, Application_impl,
			"twoExternalUsesPorts size = " << twoExternalUsesPorts.size())

		if (twoExternalUsesPorts.size() != 2) {
			DEBUG(5, Application_impl,
				"this is not external uses connections[ " << j << "]")
			continue;
		}

		//check if external connection have FindBy
		std::string firstFindByName = "";
		std::string secondFindByName = "";

		if (twoExternalUsesPorts[0]->getFindBy() &&
			twoExternalUsesPorts[1]->getFindBy()) {
			firstFindByName +=
				twoExternalUsesPorts[0]->getFindBy()->
				getFindByNamingServiceName();
			secondFindByName +=
				twoExternalUsesPorts[1]->getFindBy()->
				getFindByNamingServiceName();
		} else {
			DEBUG(5, Application,
				"In getPort maybe  Exterernal provideport elment have not FindBy childelement " )
			return false;
		}

		DEBUG(5, Application_impl, "firstFindByName : " << firstFindByName << " \
			secondFindByName: " << secondFindByName)

		DEBUG(5, Application_impl, "externalPortName is " << externalPortName)

		std::string firstCompInsId = 
			twoExternalUsesPorts[0]->getComponentInstantiationRefID();
		std::string secondCompInsId = 
			twoExternalUsesPorts[1]->getComponentInstantiationRefID();

		DEBUG(5, Application_impl, "twoExternalUsesPorts[0] id " << firstCompInsId)

		DEBUG(5, Application_impl, "twoExternalUsesPorts[1] id " << secondCompInsId)

		if ((strcmp(compInstantId, secondCompInsId.c_str()) == 0) &&
			(strcmp(externalPortName, firstFindByName.c_str()) == 0)) {
			targetPortName = secondFindByName;
			return true;
		} else if ((strcmp(compInstantId, firstCompInsId.c_str()) == 0) &&
			(strcmp(externalPortName, secondFindByName.c_str()) == 0)) {
			targetPortName = firstFindByName;
			return true;
		} else {
			DEBUG(5, Application, "external connection is invalid")
			return false;
		}
	}	// for (int j=0; j<connects->size(); j++)

	DEBUG(5, Application_impl::getExternalUsesPortName, "leave...")
	return false;
}

// 初始化
void
Application_impl::initialize()
throw (
    CF::LifeCycle::InitializeError,
    CORBA::SystemException) {
	DEBUG(5, Application, "In initialize.")

	try {
		return m_assemblyController->initialize();
	} catch (CF::LifeCycle::InitializeError & e) {
		DEBUG(5, App_impl,
		    "[Application_impl::initialize] assemblyController-> \
		    initialize failed with InitializeError Exception.")
		throw e;
	} catch (CORBA::SystemException & e) {
		DEBUG(5, App_impl,
		    "[Application_impl::initialize] assemblyController-> \
		    initialize failed with CORBA::SystemException.")
		throw;
	} catch (...) {
		DEBUG(5, App_impl,
		    "[Application_impl::initialize] assemblyController-> \
		    initialize failed with Unknown Exception.")
		throw;
	}
}

// 返回应用的名字
char *
Application_impl::name() {
	return CORBA::string_dup( m_name.c_str());
}

// 返回SAD描述文件
char *
Application_impl::profile() {
	return  CORBA::string_dup(m_sadProfile.c_str());
}

/**
 * The query operation allows a application to be queried to retrieve its
 * properties.
 */
// 从装配控制器中获得配置特性
void
Application_impl::query(
    CF::Properties & configProperties)
throw (
    CF::UnknownProperties,
    CORBA::SystemException) {
	DEBUG(5, Application, "In query.")

	try {
		m_assemblyController->query( configProperties );
	} catch (CF::UnknownProperties & e) {
		DEBUG(5, App_impl,
		      "[Application_impl::query]\"assemblyController->query\"failed \
					 with CF::PropertySet::PartialConfiguration Exception.")
		throw e;
	} catch (CORBA::SystemException & e) {
		DEBUG(5, App_impl,
		      "[Application_impl::query]\"assemblyController->query\"failed \
					 with CORBA::SystemException.")
		throw;
	} catch (...) {
		DEBUG(5, App_impl,
		      "[Application_impl::query]\"assemblyController->query\"failed \
					 with Unknown Exception.")
		throw;
	}
}

/**
 * The releaseObject operation terminates execution of the application, returns
 * all allocated computing resources, and de-allocates the resources' capacities
 * in use by the devices associated with the application. Before terminating, the
 * application removes the message connectivity with its associated applications
 * (e.g., ports, resources, and logs) in the domain.
 */
void
Application_impl::releaseObject()
throw (
    CF::LifeCycle::ReleaseError,
    CORBA::SystemException) 
{
	DEBUG(2, Application, "In releaseObject.")
#ifdef __SDS_OS_VXWORKS__
	m_orbWrap = new openscaSupport::ORB_Wrap::ORB_Wrap();
#elif defined __SDS_OS_LINUX__
	m_orbWrap = new openscaSupport::ORB_Wrap();
#endif

	// 获得域管理器目标
	CORBA::Object_ptr obj = CORBA::Object::_nil();
	obj = m_orbWrap->get_object_from_string("OpenSCA_Domain/Domain_Manager");
	if ( CORBA::is_nil(obj) ) {
		DEBUG(5, App_impl,
		    "[ApApp_impl,plication_impl::releaseObject]m_orbWrap-> \
		    get_object_from_string failed with unknown exception.")
		return;
	}

	// 获得域管理器指针
	CF::DomainManager_var dmnMgr = CF::DomainManager::_nil();
	try {
		dmnMgr = CF::DomainManager::_narrow( obj );
	} catch (...) {
		DEBUG(5, App_impl,
		    "[Application_impl::releaseObject]CF::DomainManager::_narrow \
		    failed with unknown exception.")
		return;
	}

	//disconnect all ports for this application
	// 断开应用中所有端口的连接
	if ( !disconnetAllPorts() ) {
		DEBUG(5, App_impl,
		    "[Application_impl::releaseObject] disconnect all ports failed.")
		throw CF::LifeCycle::ReleaseError();
	}


	DEBUG(3, Application, "unbind application component from naming Service")
	//destory all component resources for this application in domain
	// 释放域中所有该应用的组件源
	if ( !releaseAllResources( dmnMgr ) ) {
		DEBUG(5, App_impl,
		    "[Application_impl::releaseObject] release all resources failed.")
		throw CF::LifeCycle::ReleaseError();
	}

	//if there are process running in device, terminate it. Then unload
	//component from system. at last deallocate all capacities allcoate
	//for the component in application.
	// 如果设备上还有进程在运行，则终止进程，然后从系统中卸载组件，最后解除分配给应用组件的所有资源
	if ( !unloadAndDeallocatCaps( dmnMgr ) ) {
		DEBUG(5, App_impl, "[Application_impl::releaseObject] unld and dealloc failed.")
		throw CF::LifeCycle::ReleaseError();
	}

	//unbind application components from Naming Service.
	std::string appsContext("OpenSCA_Domain/Applications");
	CORBA::Object_var appsCtxObj = m_orbWrap->get_object_from_string(
	                                   appsContext.c_str());
	CosNaming::NamingContext_var appsCtx = CosNaming::NamingContext::_nil();

	try {
		appsCtx = CosNaming::NamingContext::_narrow( appsCtxObj );
	} catch (...) {
		DEBUG(5, App_impl,
		    "[Application::releaseObject] |CosNaming::NamingContext::_narrow( \
		    appsCtxObj ) failed withUnknown Exception")
		return;
	}

	// 从命名服务中解开应用组件
	m_orbWrap->unbind_string(appsCtx, m_appNameWithInstanceNum.c_str());

	std::string portContext("OpenSCA_Domain/" + m_appNameWithInstanceNum);
	CORBA::Object_var portCtxObj = 
		m_orbWrap->get_object_from_string(portContext.c_str());
	CosNaming::NamingContext_var portCtx = CosNaming::NamingContext::_nil();
	try {
		portCtx = CosNaming::NamingContext::_narrow( portCtxObj );
	} catch (...) {
		DEBUG(5, App_impl,
		    "[Application::releaseObject] |CosNaming::NamingContext::_narrow( \
		    portCtxObj ) failed withUnknown Exception")
		return;
	}
	// 从端口中松开应用组件
	m_orbWrap->unbind_string(portContext.c_str());
	portCtx->destroy();

	//remove reference for this application from Domain
	// 从应用序列中删除该应用
	if ( !removeRefFromDomain(dmnMgr) ) {
		DEBUG(5, App_impl,
		    "[Application_impl::releaseObject] remove app ref from domain failed.")
		throw CF::LifeCycle::ReleaseError();
	}

	DEBUG(5, Application, "leaving releaseObject")
}

/**
* remove reference for this application from DomainManager
*/
// 从应用序列中删除该应用
bool
Application_impl::removeRefFromDomain(
    CF::DomainManager_ptr domainMgr) {
	DEBUG(5, Application, "In removeRefFromDomain.")

#ifdef __SDS_OS_VXWORKS__
	semTake(semAppsMutex, WAIT_FOREVER);
#elif defined __SDS_OS_LINUX__
	sds_lock(BOOST_CONSTANT::APP_MUTEX_CND);
#endif

	bool appFound = false;
	int oldAppIdx = -1;

	if (m_appseq->length() <= 0) {
		DEBUG(7, Application_impl, "App Sequence is null")
		return false;
	}

	for (unsigned int i = 0; i < m_appseq->length(); i++) {
		// 在应用序列中找到该应用
		if (strcmp((*m_appseq)[i]->identifier(), this->identifier()) == 0 ) {
			
			appFound = true;
			oldAppIdx = i;
			break;
		}
	}

	if ( !appFound ) {
		DEBUG(7, Application_impl, "don't found App in Domain")
		return false;
	}

	//remove ref for this application from ApplicationSequence in DomainMgr
	// 从应用序列中删除该应用
	for (unsigned int j = oldAppIdx; j < m_appseq->length() - 1; j++) {
		(*m_appseq)[j] = (*m_appseq)[j + 1];
	}

	m_appseq->length( m_appseq->length() - 1 );

	DEBUG(5, Application, "leaving removeRefFromDomain.")

#ifdef __SDS_OS_VXWORKS__
	semGive(semAppsMutex);
#elif defined __SDS_OS_LINUX__
	sds_unlock(BOOST_CONSTANT::APP_MUTEX_CND);
#endif

	return true;
}

/**
* disconnect all connections for this application in domain
*/
// 从域中断开应用的所有连接
bool
Application_impl::disconnetAllPorts() {
	DEBUG(5, Application, "disconnectAllPorts.")

	DEBUG(5, App_impl, "[Application]m_connectsData size is:" << m_connectsData.size())

	CF::PPort_var portObj = CF::PPort::_nil();
	for (unsigned int i = 0; i < m_connectsData.size(); i++) {
		DEBUG(5, App_impl, "[Application_impl::disconnetAllPorts] \
			loop at: " << i)
		if (CORBA::is_nil( m_connectsData[i] )) {
			std::cerr << "[Application::disconnectAllPorts] \
				m_connectsData:" << i << "invlid." << std::endl;
			return false;
		}

		DEBUG(5, Application_impl::disconnetAllPorts, "start get connection info")

		// 获得端口目标
		portObj = m_connectsData[i]->getPort();
		// 获得连接ID
		std::string connectId = m_connectsData[i]->getID();

		DEBUG(5, Application_impl::disconnetAllPorts, "finish get connection info")

		if (CORBA::is_nil(portObj)) {
			DEBUG(5, App_impl, 
				"[Application_impl::disconnetAllPorts]portObj is nil.")
			continue;
		}

		if (portObj->_non_existent()) {
			DEBUG(0, App_impl, 
				"[Application_impl::disconnetAllPorts]portObj is not exist.")
		} else {
			DEBUG(0, App_impl, 
				"[Application_impl::disconnetAllPorts]portObj is exist.")
		}

		try {
			DEBUG(5, Application_impl::disconnetAllPorts, "start disconnect port")
			// 断开端口的连接
			portObj->disconnectPort(connectId.c_str());
			DEBUG(5, Application_impl::disconnetAllPorts, "finish disconnect port")
		} catch (...) {
			DEBUG(5, App_impl,
			    "[Application_impl::disconnetAllPorts]portObj-> \
			    disconnectPort failed.")
			return false;
		}
	}

	return true;
}

/**
* destory all component resources for this application in domain
*/
// 释放所有的资源
bool
Application_impl::releaseAllResources(
    CF::DomainManager_ptr dmnMgr) {
	DEBUG(5, Application, "In realeaseAllResources.")

	// 获得CORBA组件
	// 为什么是CORBA组件而不是组件？因为非CORBA组件没有资源？
	std::vector <SADComponentPlacement*> * sadCompPlts =
	    m_sadParser->getCorbaComponents();

	//loop to search for resource component to release. 
	//if component is DSP or FPGA
	// 循环寻找源组件来释放
	for (unsigned int numCompPlts = 0; numCompPlts < sadCompPlts->size();
	        numCompPlts++) {
		// 获得SAD实例化
		std::vector<SADComponentInstantiation*> * sadCompInsts =
		    (*sadCompPlts)[numCompPlts]->getSADInstantiations();

		// 组件ID和命名
		std::string compId = (*sadCompInsts)[0]->getID();
		std::string compCosNaming = 
			(*sadCompInsts)[0]->getFindByNamingServiceName();

		DEBUG(7, Application_impl, "In releaseAllResources ")

		bool comp_found = false;
		// 判断组件是否在命名服务中存在
		for (unsigned int i = 0; i < m_appCompNamingCtxs->length(); i++) {
			DEBUG(7, Application_impl,
			      "In releaseAllResources \
			      appCompnamingCtxs " << (*m_appCompNamingCtxs)[i].componentId)
			DEBUG(7, Application_impl,
			      "In releaseAllResources \
			      appCompnamingCtxs " << (*m_appCompNamingCtxs)[i].elementId)
			// 组件的ID和应用组件命名内容中的组件ID一致
			// 组件的命名和应用组件命名内容中的元素ID一致
			// 组件的命名不为空字符
			if ( !strcmp(compId.c_str(), 
				(*m_appCompNamingCtxs)[i].componentId) &&
			    !strcmp(compCosNaming.c_str(), 
			    (*m_appCompNamingCtxs)[i].elementId) &&
			    strcmp(compCosNaming.c_str(), "")) {
				
				comp_found = true;
				break;
			}
		}

		if ( !comp_found ) {	//don't found component in domain
			DEBUG(5, App_impl, "[Application_impl::releaseAllResources] \
				Couldn't find " << compCosNaming << "in domain.")
			continue;
		}

		// 获得组件的完整命名
		std::string fullCompCosName = "OpenSCA_Domain/Applications";
		fullCompCosName.append("/");
		fullCompCosName.append( m_appNameWithInstanceNum );
		fullCompCosName.append("/");
		fullCompCosName.append( compCosNaming );

		// 从命名服务中获得组件的参考
		CORBA::Object_ptr obj = CORBA::Object::_nil();
		if (!getObjectRefFromNamingService(fullCompCosName.c_str(), obj))		
			continue;

		CF::Resource_ptr rsc = CF::Resource::_nil();
		try {
			// 根据参考获得资源
			rsc = CF::Resource::_narrow(obj);
		} catch (...) {
			DEBUG(5, App_impl,
			    "[Application_impl::releaseAllResources] \
			    CF::Resource::_narrow failed, ")
			break;
		}

		if (CORBA::is_nil(rsc)) {
			DEBUG(5, App_impl, "[Application_impl::releaseAllResources] rsc is nil")
			return false;
		}

		try {
			// 释放目标
			rsc->releaseObject();
		} catch (...) {
			DEBUG(5, App_impl,
			    "[Application_impl::releaseAllResources] rsc->releaseObject \
				failed with Unknown Exception.")
			return false;
		}

		DEBUG(3, Application, 
			"finished release resource component:" << fullCompCosName)

	}	//for (unsigned int numCompPlts=0; numCompPlts< sadCompPlts->size(); numCompPlts++)

	DEBUG(4, Application,
	    "[Application_impl::releaseAllResources] finished all resource components.")

	return true;
}

// 从命名服务中获得目标的参考
bool 
Application_impl::getObjectRefFromNamingService(
	const char * objectName,
	CORBA::Object_ptr & obj)
{
	DEBUG(5, Application_impl::getObjectRefFromNamingService, "enter in...")

	int count = 0;
	while (count < 5) {
		try {
			obj = m_orbWrap->get_object_from_string(objectName);
		} catch (...) {
			DEBUG(5, App_impl,
				"[Application_impl::releaseAllResources] m_orbWrap-> \
				get_object_from_string failed, it may be DSP or \
				FPGA component.")
			++count;
			continue;
		}

		try {
			if (CORBA::is_nil(obj)) {
				DEBUG(5, App_impl::releaseAllResources, "don't get object")
				std::cout << "please check network!!!" << std::endl;
			} else {
				break;
			}
		} catch (...) {
			DEBUG(5, App_impl::releaseAllResources, 
				"exception occur when get object")
			std::cout << "please check network!!!" << std::endl;
		}
		sleep(1);
		++count;
	}

	DEBUG(5, Application_impl::getObjectRefFromNamingService, "leave...")

	return true;
}

/**
* if there are process running in device, terminate it. Then unload
* component from system. at last deallocate all capacities allcoate
* for the component in application.
*/
// 如果设备上还有进程在运行，则终止进程，然后从系统中卸载组件，最后解除分配给应用组件的所有资源
bool
Application_impl::unloadAndDeallocatCaps(
	CF::DomainManager_ptr dmnMgr) {
	DEBUG(4, Application, "In unloadAndDeallcoatCaps.")

	//\TODO devMgrSeq maybe CF::DeviceManagerSequence*
	// 从域管理器中获得设备管理器序列
	CF::DomainManager::DeviceManagerSequence_var devMgrSeq =
	    dmnMgr->deviceManagers();
	//\TODO regedDevSeq maybe std::vector<CF::Device_ptr>
	std::vector<CF::Device_ptr> regedDevSeq;
	CF::DeviceSequence_var devSeq;
	unsigned int dev_len = 0;
	for (unsigned int num_dev_mgr = 0; num_dev_mgr < devMgrSeq->length();
	        num_dev_mgr++) {
		//loop to copy all device from all device managers
		// 第num_dev_mgr个设备管理器的所有注册设备
		devSeq = devMgrSeq[num_dev_mgr]->registeredDevices();
		for (unsigned int num_dev = 0; 
			num_dev < devSeq->length(); num_dev++) {
			// 所有的设备
			regedDevSeq.push_back((*devSeq)[num_dev]);
		}
	}

	// 组件的位置
	std::vector<SADComponentPlacement*> * sadCompPlts =
	    m_sadParser->getComponents();
	for (unsigned int numCompId = 0; numCompId < sadCompPlts->size();
	        numCompId++) {
		// 组件的实例化
		std::vector<SADComponentInstantiation*> * sadInts =
		    (*sadCompPlts)[numCompId]->getSADInstantiations();

		// 组件ID
		std::string compId = (*sadInts)[0]->getID();

		//find device in deviceassignments by compid
		std::string devid;
		bool foundCompDev = false;
		for (unsigned int i = 0; i < m_appCompDevices->length(); i++) {
			DEBUG(7, App_impl, "In  unloadAndDeallocatCaps \
				appCompDevices " << (*m_appCompDevices)[i].componentId)
			DEBUG(7, App_impl, "In  unloadAndDeallocatCaps \
				appCompDevices " << (*m_appCompDevices)[i].assignedDeviceId)
			// 找到组件对应的设备ID
			if (strcmp(compId.c_str(), 
				(*m_appCompDevices)[i].componentId) == 0) {

				devid = (*m_appCompDevices)[i].assignedDeviceId;
				foundCompDev = true;
				break;
			}
		}
		if ( !foundCompDev ) {	//don't found comp in devassign
			DEBUG(5, App_impl,
			    "[Application_impl::unloadAndDeallocatCaps] \
			    don't find component:" << compId << " in deviceassignmentseq.")
			return false;
		}

		//find Device ref by Device id
		CORBA::Object_ptr devObject = CORBA::Object::_nil();
		bool foundRegDev = false;
		// 从所有的设备中找到组件对应的设备
		for (unsigned int j = 0; j < regedDevSeq.size(); j++) {
			if ( strcmp(devid.c_str(), regedDevSeq[j]->identifier()) == 0 ) {
				devObject = CORBA::Object::_duplicate(regedDevSeq[j]);
				foundRegDev = true;
				break;
			}
		}
		if (CORBA::is_nil(devObject) || !foundRegDev) {
			DEBUG(5, App_impl,
			    "[Application_impl::unloadAndDeallocatCaps] \
			    haven't found in regedDevSeq.")
			return false;
		}

		// 终止组件的运行
		terminateComponentProcess(devObject, compId.c_str());

		//parser code file from spd.xml
		//extract platform root form sad profile
		// 提取SPD路径
	    char openScaPath[64];
	    getConfigFilePathFromSHM(openScaPath, sizeof(openScaPath));
	  	ConfigParser configParser(openScaPath);
		std::string platformRoot = 
			configParser.getValueById(CONSTANT::SDRROOT);
		platformRoot.append("/");
		std::string spdPath(platformRoot);
		spdPath.append(m_sadParser->getSPDById( (
		        *sadCompPlts)[numCompId]->getFileRefId()) );
		CF::File_var spdf = CF::File::_nil();
		
		// 从文件管理器中打开SPD文件，并将指针赋值给spdf
		if (!openProfileFile(m_fileMgr, spdPath.c_str(), spdf))
			continue;

		// 找到对应的SPD解析器
		SPDParser spdPar( spdf );
		closeProfileFile(spdf);		

		// 卸载组件的码文件
		unloadComponentCodeFile(devObject, &spdPar, compId.c_str(), spdPath.c_str());

		//deallocate all capacities for device
		std::string prfPath = 
			replaceFileNameofPath(spdPath.c_str(), spdPar.getPRFFile());
		// 解除分配给应用组件的所有资源
		deallocateDeviceCapacity(devObject, prfPath.c_str());

	}	//for (unsigned int numCompId=0; numCompId<sadCompPlts->size(); numCompId++)

	DEBUG(2, Application, "leaving unloadAndDeallocatCaps...")

	return true;
}

// 终止组件的运行
bool 
Application_impl::terminateComponentProcess(
	CORBA::Object_ptr obj,
	const char * compId)
{
	DEBUG(5, Application_impl::terminateComponentProcess, "enter in...")

	//found process which is running, and terminate it
	bool foundCompProc = false;
	unsigned long procId = 0;
	// 从应用组件运行ID中找到组件ID对应的运行ID
	for (unsigned int i = 0; i < m_appCompProcIds->length(); i++) {
		DEBUG(7, App_impl, "In unldAndDeallCaps \
			m_appCompProcIds: " << (*m_appCompProcIds)[i].componentId)
		DEBUG(7, App_impl, "In unldAndDeallCaps \
			m_appCompProcIds: " << (*m_appCompProcIds)[i].processId)
		if (strcmp(compId, (*m_appCompProcIds)[i].componentId) == 0) {
			foundCompProc = true;
			procId = (*m_appCompProcIds)[i].processId;
			break;
		}
	}

	if (!foundCompProc)
		return false;

	CF::ExecutableDevice_var exeDevice = CF::ExecutableDevice::_nil();
	try {
		// 找到可执行设备
		exeDevice = CF::ExecutableDevice::_narrow(obj);
	} catch (...) {
		DEBUG(5, App_impl,
			"[Application_impl::unloadAndDeallocatCaps] \
			CF::ExecutableDevice::_narrow failed with Unknown Exception.")
		return false;
	}
	try {
		// 从可执行设备中终止进程
		if (!CORBA::is_nil(exeDevice)) {
			exeDevice->terminate(procId);
		}
	} catch (...) {
		DEBUG(5, App_impl,
			"[Application_impl::unloadAndDeallocatCaps] \
			exeDevice->terminate failed with Unknown Exception.")
		return false;
	}

	DEBUG(5, Application_impl::terminateComponentProcess, "leave...")
	return true;
}

// 卸载组件的码文件
bool
Application_impl::unloadComponentCodeFile(
	CORBA::Object_ptr obj,
	SPDParser * compSPDParser,
	const char * compId,
	const char * spdPath)
{
	DEBUG(5, Application_impl::unloadComponentCodeFile, "enter in...")

	// 找到组件的实现
	std::vector<SPDImplementation*> * spdImpls = 
						compSPDParser->getImplementations();
	//find implement for this component
	bool foundCompImpl = false;
	std::string codefile, impId;
	for (unsigned int i = 0; i < m_appCompImpls->length(); i++) {
		// 比较组件的ID和应用组件实现中的组件ID，从而获得组件的实现ID
		if (strcmp(compId, 
			(*m_appCompImpls)[i].componentId) == 0) {

			impId = (*m_appCompImpls)[i].elementId;
		foundCompImpl = true;
		break;
		}
	}
	if ( !foundCompImpl ) {
		DEBUG(5, App_impl,
			"[Application_impl::unloadComponentCodeFile]Cann't found \
			componentid in m_appCompImpls.")
		return false;
	}

	DEBUG(7, App_impl, "In unloadComponentCodeFile impId is: " << impId)

	bool foundSpdImpl = false;
	for (unsigned int i = 0; i < spdImpls->size(); i++) {
		DEBUG(7, App_impl, "In unloadComponentCodeFile spdImpls \
			id: " << (*spdImpls)[i]->getID())
		// 找到码文件
		if (strcmp(impId.c_str(), (*spdImpls)[i]->getID()) == 0) {
			foundSpdImpl = true;
			codefile = (*spdImpls)[i]->getCodeFile();
		}
	}
	if (!foundSpdImpl) {
		DEBUG(5, App_impl,
			"[Application_impl::unloadComponentCodeFile] Cann't found implid in \
			spdImpls.")
		return false;
	}

	DEBUG(7, App_impl, "In unldAndDeallCaps codefile is: " << codefile)

	//\TODO codefile is just only code file name, so it isn't absoulte path
	std::string fullCodeFile = 
	replaceFileNameofPath(spdPath, codefile.c_str());
	DEBUG(7, App_impl, "In unldAndDeallCaps fullCodeFile: " << fullCodeFile)

	//unload code file from loadabledevice
	CF::LoadableDevice_ptr loadDev;
	try {
		// 找到可加载设备
		loadDev = CF::LoadableDevice::_narrow( obj );
	} catch (...) {
		DEBUG(5, App_impl,
			"[Application_impl::unloadComponentCodeFile] \
			CF::LoadableDevice::_narrow failed with Unknown Exception.")
		return false;
	}

	try {
		// 卸载码文件
		loadDev->unload( fullCodeFile.c_str() );
	} catch (...) {
		DEBUG(5, App_impl,
			"[Application_impl::unloadAndDeallocatCaps] loadDev->unload \
			with Unknown Exception.")
		return false;
	}

	DEBUG(5, Application_impl::unloadComponentCodeFile, "leave...")

	return true;
}

// 解除分配给应用组件的所有资源
bool 
Application_impl::deallocateDeviceCapacity(
	CORBA::Object_ptr obj,
	const char* compPrfPath)
{
	DEBUG(5, Application_impl::deallocateDeviceCapacity, "enter in...")

	// 获得prf路径
	std::string prfPath(compPrfPath);

	CF::File_var prf;
	try {
		// 从文件管理器中打开prf文件
		prf = m_fileMgr->open( prfPath.c_str(), true );
	} catch ( CF::InvalidFileName & e ) {
		DEBUG(5, App_impl,
			"[Application::unloadAndDeallocatCaps] \
			fileMgr->open failed with InvalidFileName.")
		return false;
	} catch ( CF::FileException & e ) {
		DEBUG(5, App_impl,
			"[Application::unloadAndDeallocatCaps] \
			fileMgr->open failed with CF::FileException.")
		return false;
	} catch ( ... ) {
		DEBUG(5, App_impl,
			"[Application::unloadAndDeallocatCaps] \
			fileMgr->open failed with InvalidFileName.")
		return false;
	}

	// 找到prf解析器
	PRFParser PRFFile ( prf );
	try {
		prf->close();
	} catch ( CORBA::SystemException & se ) {
		DEBUG(5, App_impl, "[Application::unloadAndDeallocatCaps] \
			prf->close failed with CORBA::SystemException.")
		return false;
	} catch ( ... ) {
		DEBUG(5, App_impl, "[Application::unloadAndDeallocatCaps] \
			prf->close failed with Unknown Exception.")
		return false;
	}

	// 从prf中获得匹配特性
	std::vector <PRFProperty *> *prfSimpleProp = 
			PRFFile.getMatchingProperties ();
	CF::Properties deallocCaps (10);	//max length is 10, not length.
	// 将匹配特性中的ID和值赋值给deallocCaps
	deallocCaps.length ( prfSimpleProp->size ());
	for (unsigned int propIndex = 0; propIndex < prfSimpleProp->size ();
			propIndex++) {
		CF::DataType *dt = (*prfSimpleProp)[propIndex]->getDataType ();
		deallocCaps[propIndex].id = CORBA::string_dup (dt->id);
		deallocCaps[propIndex].value = dt->value;
	}

	CF::Device_ptr dev;
	try {
		dev = CF::Device::_narrow(obj);
	} catch ( ... ) {
		DEBUG(5, App_impl,
			"[Application_impl::unloadAndDeallocatCaps] \
			CF::Device::_narrow failed with Unknown Exception")
	}

	if (prfSimpleProp->size() > 0) {
		try {
			// 解除分配
			dev->deallocateCapacity (deallocCaps);
		} catch (...) {
			DEBUG(5, App_impl,
				"[Application::unloadAndDeallocatCaps] \
				dev->deallocateCapacity failed with Unknown Exception.")
			return false;
		}
	}

	DEBUG(5, Application_impl::deallocateDeviceCapacity, "leave...")

	return true;
}

// 测试
void
Application_impl::runTest(
    CORBA::ULong testid,
    CF::Properties & testValues)
throw (
    CORBA::SystemException,
    CF::UnknownProperties,
    CF::TestableObject::UnknownTest) {
	DEBUG(5, Application, "In runTest.")

	try {
		return m_assemblyController->runTest(testid, testValues);
	} catch (CF::UnknownProperties & e) {
		DEBUG(5, App_impl,
		    "[Application_impl::runTest] assemblyController->runTest \
		    failed with InitializeError Exception.")
		throw e;
	} catch (CF::TestableObject::UnknownTest & e) {
		DEBUG(5, App_impl,
		    "[Application_impl::runTest] assemblyController->runTest failed \
			with CF::TestableObject::UnknownTest Exception.")
		throw e;
	} catch (CORBA::SystemException & e) {
		DEBUG(5, App_impl,
		    "[Application_impl::runTest] assemblyController->runTest failed \
			with CORBA::SystemException.")
		throw;
	} catch (...) {
		DEBUG(5, App_impl,
		    "[Application_impl::runTest] assemblyController->runTest failed \
			with Unknown Exception.")
		throw;
	}
}

/**
 * The stop operation is provided to command the application implementing this
 * interface to start internal processing.
 */
// 开启
void
Application_impl::start()
throw (
    CF::Resource::StartError,
    CORBA::SystemException) {
	DEBUG(5, Application, "In start.")

	try {
		return m_assemblyController->start( );
	} catch (CF::UnknownProperties & e) {
		DEBUG(5, App_impl,
		    "[Application_impl::start] assemblyController->start failed \
			with CF::Resource::StartError Exception.")
		throw e;
	} catch (CORBA::SystemException & e) {
		DEBUG(5, App_impl,
		    "[Application_impl::start] assemblyController->start failed \
			with CORBA::SystemException.")
		throw;
	} catch (...) {
		DEBUG(5, App_impl,
		    "[Application_impl::start] assemblyController->start failed \
			with Unknown Exception.")
		throw;
	}
}

/**
 * The stop operation is provided to command the application implementing this
 * interface to stop internal processing.
 */
// 结束
void
Application_impl::stop()
throw (
    CF::Resource::StopError,
    CORBA::SystemException) {
	DEBUG(5, Application, "In stop.")

	try {
		m_assemblyController->stop();
	} catch (CF::Resource::StopError & e) {
		DEBUG(5, App_impl, "[Application_impl::stop] \
			assemblyController->stop failed \
			with CF::Resource::StopError Exception.")
		throw e;
	} catch (CORBA::SystemException & e) {
		DEBUG(5, App_impl, "[Application_impl::stop] \
			assemblyController->stop failed \
			with CORBA::SystemException.")
		throw;
	} catch (...) {
		DEBUG(5, App_impl, "[Application_impl::stop] \
			assemblyController->stop failed \
			with Unknown Exception.")
		throw;
	}
}
