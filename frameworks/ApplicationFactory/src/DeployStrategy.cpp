/***************************************************************************//**
* @file     DelpoyStrategy.cpp
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

#include "../include/DeployStrategy.h"
#include "../include/debug.h"
#include "SADParser.h"
#include "PRFParser.h"
#include "SCDParser.h"
#include "SPDParser.h"
#include "prop_helpers.h"
#include "utils.h"
#include "ConfigParser.h"
#include "DCDParser.h"

class DeployStrategy;
class BaseDeployStrategy;

DeployStrategy::DeployStrategy(
    std::vector<CF::Device_ptr> regedDevs,
    std::vector<SADComponentPlacement*> * sadCompPlacs) {
	DEBUG(7, DeployStrategy, "In DeployStrategy constructor.")

}

DeployStrategy::DeployStrategy( ) {
	DEBUG(7, DeployStrategy, "In default constructor.")
}

DeployStrategy::~DeployStrategy() {

}

/**
 * This class provides two kind of deploy Strategy. The first strategy is
 * implemented by createDepoyInfo function without device assignment, it consider
 * of OS and processor and allocation properties. Well the second strategy is
 * implemented by ceateDeployInfo with device assignement parameter, it consider of
 * os and processor simply.
 * 
 // 该类提供了两类部署策略。第一种策略是通过没有设备分配的createDepoyInfo函数实现的，它考虑了OS和处理器
 // 以及分配特性。第二种策略通过有设备分配参数的ceateDeployInfo函数实现的，它简单地考虑了OS和处理器
 *
 * it mainly verify device capacity is suitable for component deploy dependences.
 */
// BaseDeployStrategy的构造函数
BaseDeployStrategy::BaseDeployStrategy(
    std::vector<CF::Device_ptr> regedDevs,
    SADParser * sadPar,
    CF::FileManager_ptr fileMgr,
    std::vector<SADComponentPlacement *> *sadCompPlacs) {
	DEBUG(2, BaseDeployStrategy, "In constructor.")

	// 注册设备的指针赋值给m_registeredDevices
	m_registeredDevices = regedDevs;
	// 根据SAD解析出来的组件位置赋值给m_sadCompPlaces
	m_sadCompPlaces = sadPar->getComponents();
	// 文件管理器的指针赋值给m_fileMgr
	m_fileMgr = fileMgr;
	// SAD解析器的指针赋值给m_sadPar
	m_sadPar = sadPar;

    
	char openScaPath[64];
    getConfigFilePathFromSHM(openScaPath, sizeof(openScaPath));
  	ConfigParser configParser(openScaPath);
	// 找到SDR根路径，赋值给m_sdrRoot
	m_sdrRoot = configParser.getValueById(CONSTANT::SDRROOT);
	DEBUG(2, BaseDeployStrategy, "finish constructor.")
}

// for循环里面的步骤是不是没写？
BaseDeployStrategy::~BaseDeployStrategy() {
	for (unsigned int numComp = 0; numComp < m_allCompsInfo.size(); numComp++) {
		//delete m_allCompsInfo[numComp];
	}
}

BaseDeployStrategy::BaseDeployStrategy() {

}

// 不带参数的创建部署信息函数
// 给每个组件分配一个设备
std::vector<openscaSupport::ComponentInfo*>
BaseDeployStrategy::createDeployInfo() {
	DEBUG(2, ApplicationFactory,
	    "In createDeployInfo() with matching component num: " << 
	    m_sadCompPlaces->size())

	//loop to get every component info then match deploying device
	// 采用一个循环获得所有组件的信息，并给每个组件部署一个设备
	// m_sadCompPlaces->size()表示组件的个数
	for (unsigned int numComp = 0; 
		numComp < m_sadCompPlaces->size(); numComp++) {
		DEBUG(7, DaseDeployStrategy, "In createDeployInfo round: " << numComp)

		// m_allCompsInfo只在h文件里面定义了一下，并没有初始化
		// 所以刚开始m_allCompsInfo是个空指针吗？m_allCompsInfo.size()的大小为0
		// 判断这个组件的ID是否已经存在
		bool hasAssigned = false;
		for ( unsigned int i = 0; i < m_allCompsInfo.size(); ++i) {
			if ( 0 == strcmp(m_allCompsInfo[i]->getIdentifier(),
			                 (*((*m_sadCompPlaces)[numComp]->
			                 getSADInstantiations()))[0]->getID()) ) {
				hasAssigned = true;
				break;
			}
		}

		if (hasAssigned)
			continue;

		openscaSupport::ComponentInfo * compInfo = 
						new openscaSupport::ComponentInfo;
		std::vector<PRFProperty * > matchingProps;

		// 组件的路径为“”吗？不是，“”只是初始化
		std::string spdPath = "";
		SPDParser * spdParser = NULL;
		// 获得第numComp个组件的SPD解析器
		// 具体函数实现在下面
		spdParser = getSpdParser((*m_sadCompPlaces)[numComp], spdPath);
		// 获得第numComp个组件的信息，并将信息写入到compInfo中
		getCompInfo(compInfo, (*m_sadCompPlaces)[numComp], spdPath, spdParser);

		PRFParser * prfParser = NULL;
		// 根据compInfo获得PRF解析器
		// 具体函数实现在下面
		prfParser = getPrfParser(compInfo);

		// 从prf解析器中获得组件参数信息，
		// 将工厂参数、执行参数、配置参数、容量特征写入到compInfo中
		// 将匹配特征写入到matchingProps中
		getPropertyFromPRF(compInfo, matchingProps, prfParser);

		//getCompInfo(compInfo, matchingProps, (*m_sadCompPlaces)[num_comp]);
		// 将组件的类同组件赋值给affinityComponents
		std::vector<std::string> affinityComponents = 
							compInfo->getAffinityComponents();

		//begin to assign component to candidate devices. The first thing is that
		//match operating system, then match processor, at last match matching properties.
		// 开始将组件部署到潜在的设备上，首先是匹配操作系统，接着匹配处理器，最后匹配匹配特征

		//loop to match device in registered devices
		bool foundDevToDeploy = false;
		for (unsigned int numDev = 0; 
			numDev < m_registeredDevices.size(); numDev++) {

			// 遍历所有的设备，直到找到和组件匹配的设备，且匹配的设备是第numDev个
			if ( !matchSpecificCompWithDev(compInfo, 
					m_registeredDevices[numDev], matchingProps) ) {
				continue;
			}

			// 如果组件没有类同组件，则直接将设备的ID号写入
			if (0 == affinityComponents.size()) {
				// 将第numDev对应的注册设备的ID赋值给m_assignedDeviceId
				compInfo->setAssignedDeviceId( 
					m_registeredDevices[numDev]->identifier() );

				// 将组件信息写入m_allCompsInfo
				m_allCompsInfo.push_back(compInfo);

				// 将foundDevToDeploy置为真
				foundDevToDeploy = true;

				// 找到和组件匹配的设备以后就跳出循环
				break;
			} 

			// execute here, indicate affinityComponents > 0
			// 如果组件有类同组件，需要将类同组件也部署在该设备上，只有部署成功，才会将设备的ID写入
			if (deployAffinityComponents(
					affinityComponents, m_registeredDevices[numDev])) {
				compInfo->setAssignedDeviceId( 
					m_registeredDevices[numDev]->identifier() );

				m_allCompsInfo.push_back(compInfo);
				foundDevToDeploy = true;
				break;
			}
		}	//for (unsigned int numDev=0; numDev<m_registeredDevices.size(); numDev++)

		if ( !foundDevToDeploy ) {
			DEBUG(7, DaseDeployStrategy,
			    "[BaseDeployStrategy::createDeployInfo]Component:" <<
			    compInfo->getUsageName() << "don't found device to deploy.")

			throw CF::ApplicationFactory::CreateApplicationError();
		}

		DEBUG(7, BaseDeployStrategy, "found device to deploy succ")

		DEBUG(2, BaseDeployStrategy, "Component:" << 
			compInfo->getUsageName() << " has found device to deploy.")

		if (spdParser != NULL) {
			delete spdParser;
		}
		if (prfParser != NULL) {
			delete prfParser;
		}

	}//for (unsigned int numComp=0; numComp<m_sadCompPlaces->size(); numComp++)

	DEBUG(2, BaseDeployStrategy, "Leaving createDeployInfo().")
	// 返回的是所有组件的信息
	return m_allCompsInfo;
}

// 找到组件对应的SPD解析器
SPDParser *
BaseDeployStrategy::getSpdParser(
    SADComponentPlacement *sadCompPlace,
    std::string & spdPath) {
	if (!sadCompPlace) {
		return NULL;
	}

	//parsing spd.xml
	CF::File_var spdfl;

	// 根据sadCompPlace获得组件文件的参考ID
	std::string spdrefid = sadCompPlace->getFileRefId();

	// 根据参考ID获得SPD的路径
	spdPath.append(m_sdrRoot);
	spdPath.append("/");
	spdPath.append(m_sadPar->getSPDById(spdrefid.c_str()));

	DEBUG(7, BaseDeployStrategy::getCompInfo, "spdPath is: " << spdPath)
	try {
		// 从文件管理器中打开spd
		spdfl = m_fileMgr->open(spdPath.c_str(), true);
	} catch (CF::InvalidFileName & e) {
		DEBUG(7, BaseDeployStrategy::getCompInfo,
		      "[BaseDeployStrategy::createDeployInfo] m_fileMgr->open " <<
		      "failed with invalid file name:" << e.msg)
		CF::ApplicationFactory::CreateApplicationError();
	} catch (CF::FileException & e) {
		DEBUG(7, BaseDeployStrategy::getCompInfo,
		      "[BaseDeployStrategy::createDeployInfo] m_fileMgr->open "
		      "failed with CF::FileException.")
		CF::ApplicationFactory::CreateApplicationError();
	} catch (...) {
		DEBUG(7, BaseDeployStrategy::getCompInfo,
		      "[BaseDeployStrategy::createDeployInfo] m_fileMgr->open "
		      "failed with Unknown Exception.")
		CF::ApplicationFactory::CreateApplicationError();
	}

	//parsing component spd.xml
	// 根据spdfl找到对应的SPD解析器
	SPDParser * spdParser = new SPDParser(spdfl);
	try {
		spdfl->close();
	} catch (CF::FileException & e) {
		DEBUG(7, BaseDeployStrategy::getCompInfo,
		      "[BaseDeployStrategy::createDeployInfo]\"spdfl->close(\" \
		failed with CF::FileException.")
		CF::ApplicationFactory::CreateApplicationError();
	} catch (...) {
		DEBUG(7, BaseDeployStrategy::getCompInfo,
		      "[BaseDeployStrategy::createDeployInfo]\"spdfl->close(\" \
		failed with Unknown Exception.")
		CF::ApplicationFactory::CreateApplicationError();
	}

	return spdParser;
}

// 找到组件对应的prf解析器
PRFParser *
BaseDeployStrategy::getPrfParser(
    openscaSupport::ComponentInfo * compInfo) {

	// 根据compInfo获得prf文件的路径
	std::string prfPath = compInfo->getImplPRFFile();

	//parsering spd.xml
	CF::File_var prffl;
	try {
		// 从文件管理器中打开prffl
		prffl = m_fileMgr->open(prfPath.c_str(), true);
	} catch (CF::InvalidFileName & e) {
		DEBUG(7, BaseDeployStrategy::getCompInfo,
		      "[BaseDeployStrategy::getCompInfoFromPRF] \"m_fileMgr->open\" \
				failed with invalid file name:" << e.msg)
		CF::ApplicationFactory::CreateApplicationError();
	} catch (CF::FileException & e) {
		DEBUG(7, BaseDeployStrategy::getCompInfo,
		      "[BaseDeployStrategy::getCompInfoFromPRF]\"m_fileMgr->open\" \
		failed with CF::FileException.")
		CF::ApplicationFactory::CreateApplicationError();
	} catch (...) {
		DEBUG(7, BaseDeployStrategy::getCompInfo,
		      "[BaseDeployStrategy::getCompInfoFromPRF]\"m_fileMgr->open\" \
		failed with Unknown Exception.")
		CF::ApplicationFactory::CreateApplicationError();
	}

	DEBUG(7, BaseDeployStrategy::getCompInfo,
	      "In getCompInfoFromPRF parsing prf.xml")

	//parsering component spd.xml
	// 根据prffl获得prf解析器
	PRFParser * prfParser = new PRFParser(prffl);

	try {
		prffl->close();
	} catch (CF::FileException & e) {
		DEBUG(7, BaseDeployStrategy::getCompInfo,
		      "[BaseDeployStrategy::createDeployInfo]\"prffl->close(\" \
		failed with CF::FileException.")
		CF::ApplicationFactory::CreateApplicationError();
	} catch (...) {
		DEBUG(7, BaseDeployStrategy::getCompInfo,
		      "[BaseDeployStrategy::createDeployInfo]\"prffl->close(\" \
		failed with Unknown Exception.")
		CF::ApplicationFactory::CreateApplicationError();
	}

	return prfParser;

}

// 获得组件信息
bool
BaseDeployStrategy::getCompInfo(
    openscaSupport::ComponentInfo * compInfo,
    SADComponentPlacement * sadCompPlace,
    std::string & spdPath,
    SPDParser * spdParser) {

	DEBUG(5, BaseDeployStrategy::getCompInfo, "enter in ...")

	if ((!compInfo) || (!sadCompPlace)) {
		return false;
	}

	//parsing spd.xml
	// 将spdPath赋值给m_implSPD
	compInfo->setImplSPDFile(spdPath.c_str());

	DEBUG(7, BaseDeployStrategy::getCompInfo, "spdPath is: " << spdPath)

	// 将m_implementations赋值给spdImpls
	std::vector<SPDImplementation *> * spdImpls = 
							spdParser->getImplementations();
	//bool foundSpdImpl = false;
	SPDImplementation * spdImp = NULL;
	if (spdImpls->size() > 0) {
		// 将spdImpls的第一位赋值给spdImp
		spdImp = (*spdImpls)[0];
	} else {
		DEBUG(8, BaseDeployStrategy::getCompInfo,
		      " in CreateDeployInfo no implementation SPD.xml")
		CF::ApplicationFactory::CreateApplicationError();
	}

	// 将sadComp赋值给sadCompInsts（实例化）
	std::vector<SADComponentInstantiation *> * sadCompInsts =
		sadCompPlace->getSADInstantiations();
	SADComponentInstantiation * sadCompInst = NULL;
	if (sadCompInsts->size() > 0) {
		// 将sadCompInsts的第一位赋值给sadCompInst
		sadCompInst = (*sadCompInsts)[0];
	} else {
		DEBUG(8, BaseDeployStrategy::getCompInfo,
		    " in CreateDeployInfo no SADComponentInstantiation")
		CF::ApplicationFactory::CreateApplicationError();	
	}

	//get absloute path for local code file
	size_t pos = spdPath.find_last_of("/");
	// 根据spdImp的路径获得文件名
	std::string absLocalFile = 
		replaceFileNameofPath(spdPath.c_str(), spdImp->getCodeFile());
	
	//将文件名赋值给m_localFileName
	compInfo->setLocalFileName(absLocalFile.c_str());

	// 判断是否和SCA兼容，并将结果赋值给m_scaComplicant
	compInfo->setScaComplicant(sadCompPlace->isScaCompliant());

	//get component Info for os/processor/implprf and so on
	if (spdImp && sadCompInst) {
		//assume that every component placement have one instantiation
		// 配置组件信息
		setComponentInfo(compInfo, (*sadCompInsts)[0], spdImp);
	} else {
		DEBUG(7, BaseDeployStrategy::getCompInfo,
		    "[BaseDeployStrategy::createDeployInfo] don't found " \
		    "implementation in spd.xml.")
		CF::ApplicationFactory::CreateApplicationError();
	}

	// 获得装配控制器的参考ID
	std::string assemblyCtrlRefId = m_sadPar->getAssemblyControllerRefId();

	// 判断装配控制器的参考ID和组件信息中的ID是否一致，并将结果赋值给m_isAssemblyController
	if (strcmp(compInfo->getIdentifier(), assemblyCtrlRefId.c_str()) == 0) {
		compInfo->setIsAssemblyController( true );
		DEBUG(7, BaseDeployStrategy::getCompInfo,
		      "[BaseDeployStrategy::createDeployInfo]" << 
		      compInfo->getIdentifier() << " is setIsAssemblyController")
	} else {
		compInfo->setIsAssemblyController(false);
		DEBUG(7, BaseDeployStrategy::getCompInfo, compInfo->getIdentifier() <<
		    " isn't setIsAssemblyController")
	}

	DEBUG(7, DeployStrategy, "obtain info from scd.xml")
	//get component info for resource type in scd.xml
	// 获得SCD文件的路径名
	std::string scdPath = replaceFileNameofPath(
							spdPath.c_str(), spdParser->getSCDFile());

	DEBUG(7, DeployStrategy, "obtain info from scd.xml")
	// 从SCD中获得组件信息
	getCompInfoFromSCD(scdPath.c_str(), compInfo);

	// 获得PRF文件的路径名
	std::string prfPath = replaceFileNameofPath(
							spdPath.c_str(), spdParser->getPRFFile());
	//get component info about properties in prf.xml
	// 将prf路径名赋值给m_implPRF
	compInfo->setImplPRFFile(prfPath.c_str());

	//parsering spd.xml
	// 从文件管理器中打开PRF配置文件，并将指针赋值给prffl
	// 如果打开出错，则返回false
	CF::File_var prffl;
	if (!openProfileFile(m_fileMgr.in(), prfPath.c_str(), prffl)) 
		return false;

	DEBUG(7, BaseDeployStrategy::getCompInfo,
		"In getCompInfoFromPRF parsing prf.xml")
	//parsering component spd.xml
	// 根据prffl获得对应的解析器prfParser
	// 获得prfParser之后并没有使用，这两句是不是可以不用？
	// 此外prf的解析器有专门的程序getPrfParser
	PRFParser * prfParser = new PRFParser(prffl);
	closeProfileFile(prffl.in());

	DEBUG(5, BaseDeployStrategy::getCompInfo, "leave ...")
	return true;
}

// 将特定的组件和设备进行匹配，如果匹配成功，返回true
bool
BaseDeployStrategy::matchSpecificCompWithDev(
    openscaSupport::ComponentInfo * compInfo,
    CF::Device_ptr dev,
    std::vector<PRFProperty*> & matchingProps) {
	DEBUG(5, BaseDeployStrategy::matchSpecificCompWithDev, "enter in ...")

	// 根据dev找到可加载设备的指针loadDev
	CF::LoadableDevice_ptr loadDev = CF::LoadableDevice::_narrow(dev);
	// 如果可加载设备不存在，则返回false
	if (CORBA::is_nil(loadDev)) {
		return false;
	}

	// 如果设备状态是忙，则返回false
	if (loadDev->usageState() == CF::Device::BUSY)
		return false;
	// 如果设备的可操作性状态是不可操作，则返回false
	if (loadDev->operationalState() == CF::Device::DISABLED)
		return false;
	// 如果设备的管理状态是上锁，则返回false
	if (loadDev->adminState() == CF::Device::LOCKED)
		return false;

	//check device's health state
	// 检查设备的健康状态，如果设备不健康，则返回false
	CF::Properties prop;
	prop.length(1);
	std::string propId = CONSTANT::HEALTH_PROP_ID;
	prop[0].id = CORBA::string_dup(propId.c_str());
	loadDev->query(prop);
	CORBA::Boolean bVal;
	prop[0].value >>= CORBA::Any::to_boolean(bVal);
	if ( !bVal )
		return false;

	DEBUG(7, BaseDeployStrategy, "component info-OS:" << 
		compInfo->getOSName())
	// 从组件信息中获得操作系统的名字
	std::string osName(compInfo->getOSName());
	//compare os name
	// 如果操作系统的名字不为空
	if ( osName.empty() == false) {
		DEBUG(7, BaseDeployStrategy, "component os name not nil" )
		// 根据loadDev获得可执行设备的指针exeDev
		CF::ExecutableDevice_ptr exeDev =
		    CF::ExecutableDevice::_narrow (loadDev);
		// 如果可执行设备的指针不为空
		if (!CORBA::is_nil( exeDev )) {
			// 将可执行设备和组件的操作系统匹配，如果匹配不成功，返回false
			if (!matchOSToDevice(exeDev, compInfo)) {
				DEBUG(7, BaseDeployStrategy, "match os to device failed")
				return false;
			}

			DEBUG(7, BaseDeployStrategy, "match os to device succ")
		}
	}

	DEBUG(7, BaseDeployStrategy,
	      "component proceessors size:" << compInfo->getProcessors().size())

	//compare processor type
	// 将可加载设备和组件的处理器匹配，如果匹配不成功，返回false
	if (!matchProcessorToDevice(loadDev, compInfo)) {
		DEBUG(7, BaseDeployStrategy, "match processor to device failed")
		return false;
	}

	DEBUG(7, BaseDeployStrategy, "match processor to device successfully")

	//compare matching other properties to device except for os and processor
	// 将可加载设备和组件的其他特征匹配，如果匹配不成功，返回false
	if (matchingProps.size() > 0) {
		if ( !matchOtherPropsToDevice(loadDev, &matchingProps)) {
			return false;
		}
	}

	DEBUG(7, BaseDeployStrategy, "match otherprops to device successfully")
	DEBUG(7, DeployStrategy,
	    "In createDeployInfo assigned device id: " << loadDev->identifier())
	DEBUG(5, BaseDeployStrategy::matchSpecificCompWithDev, "leave ...")

	// 如果都匹配成功，返回true
	return true;
}

/**
 * @brief The operation shall be called when a component is deployed successfully, 
 *        and the component has a affinity component, they should be deployed on 
 *        same deviceor one device's affinity device.
 // 该操作只有在组件被成功地部署且组件有一个类同组件的情况下才会被调用
 *
 * @param[in] affinityComponents Affinity components need deployed.
 * @param[in] dev				 Device on which the component deployed.
 *
 * @return Result of deploying the affinity component.
 * @retval true		Deploy successfully.
 * @retval false 	Deploy failed.
 */
// 将类同组件部署在设备上，如果部署成功，返回true
bool
BaseDeployStrategy::deployAffinityComponents(
    const std::vector<std::string> & affinityComponents,
    CF::Device_ptr dev) {
	DEBUG(5, BaseDeployStrategy::deployAffinityComponents, "enter in ...")

	openscaSupport::ComponentInfo * compInfo = 
					new openscaSupport::ComponentInfo;
	std::vector<PRFProperty*> matchingProps;

	bool findComp = false;
	std::vector <SADComponentInstantiation*> sadIns;
	sadIns.clear();

	// 对于SAD中每一个组件，循环执行
	// 目的是找到和类同组件字符一致的SAD组件
	for (unsigned int i = 0; i < m_sadCompPlaces->size(); i++) {
		// 获得SAD实例化的指针
		sadIns = *((*m_sadCompPlaces)[i]->getSADInstantiations());
		if (sadIns.size() < 1) {
			continue;
		}

		// 如果类同组件的字符和SAD实例化的设备名字一致
		if ( 0 == strcmp(affinityComponents[0].c_str(), 
						sadIns[0]->getUsageName()) ) {

			std::string spdPath = "";
			SPDParser * spdParser = NULL;
			// 获得SPD解析器的指针spdParser和路径spdPath
			spdParser = getSpdParser((*m_sadCompPlaces)[i], spdPath);

			// 获得组件信息
			getCompInfo(compInfo, (*m_sadCompPlaces)[i], spdPath, spdParser);

			PRFParser * prfParser = NULL;
			// 获得PRF解析器的指针prfParser
			prfParser = getPrfParser(compInfo);
			// 从PRF中获得特性
			getPropertyFromPRF(compInfo, matchingProps, prfParser);

			//getCompInfo(compInfo, matchingProps, (*m_sadCompPlaces)[i]);
			findComp = true;
			break;
		}
	}

	if (!findComp) {
		//delete compInfo;
		return false;
	}

	//Firstly, match current device
	// 如果组件和设备匹配成功，则将信息写入到m_allCompsInfo中，返回true
	if ( matchSpecificCompWithDev(compInfo, dev, matchingProps) ) {
		compInfo->setAssignedDeviceId( dev->identifier() );
		m_allCompsInfo.push_back(compInfo);

		DEBUG(5, BaseDeployStrategy::deployAffinityComponents, "leave ...")

		return true;
	}

	// 如果组件和设备没有匹配成功，找到设备中软件配置文件的SPD路径
	std::string spdPath = dev->softwareProfile();
	CF::File_var spdfl;
	// 从文件管理器中找到SPD路径对应的SPD解析器指针spdfl
	if(!openProfileFile(m_fileMgr.in(), spdPath.c_str(), spdfl))
		return false;

	//parsing component spd.xml
	// 根据spdfl找到SPD解析器
	SPDParser spdParser( spdfl );
	closeProfileFile(spdfl);

	// 获得SPD解析器中的PRF文件名
	std::string prfPath = replaceFileNameofPath(
							spdPath.c_str(), spdParser.getPRFFile());
	CF::File_var prffl;
	// 从文件管理器中找到PRF文件对应的指针prffl
	if(!openProfileFile(m_fileMgr.in(), prfPath.c_str(), prffl))
		return false;

	// 根据prffl找到PRF解析器
	PRFParser prfParser(prffl);
	closeProfileFile(prffl);

	// 从PRF解析器中获得配置特性
	std::vector <PRFProperty *> configProps = 
	        *(prfParser.getConfigureProperties());
	std::string affinityDevName = "";
	for (int i = 0; i < configProps.size(); ++i) {
		// 查找配置特性中是否有"affinity_component"字符
		if ( 0 == strcmp("affinity_component", configProps[i]->getName()) ) {
			// 如果有，就将值写到affinityDevName之中
			affinityDevName = (configProps[i]->getValue())[0];
			break;
		}
	}

	// 如果affinityDevName为空字符，返回false
	if ("" == affinityDevName) {
		//delete compInfo;
		return false;
	}

	bool findDev = false;
	CF::Device_ptr affinityDev;

	for (unsigned int i = 0; i < m_registeredDevices.size(); i++) {
		if (CORBA::is_nil(m_registeredDevices[i])) {
			continue;
		}

		// 如果affinityDevName和第i个注册设备的标志一致
		if ( 0 == strcmp(affinityDevName.c_str(), 
						m_registeredDevices[i]->label()) ) {
			// 将m_registeredDevices[i]赋值给affinityDev
			affinityDev = m_registeredDevices[i];
			findDev = true;
			break;
		}
	}

	if (!findDev) {
		DEBUG(5, BaseDeployStrategy::deployAffinityComponents,
		      "match affinity component failed.")
		//delete compInfo;
		return false;
	}

	/**
	 * if component can't match current device and the current device has affinity device,
	 * then try to match affinity device.
	 */
	// 如果组件不能匹配当前的设备，但是当前的设备具有类同设备，尝试去匹配类同设备

	if ( matchSpecificCompWithDev(compInfo, affinityDev, matchingProps) ) {
			compInfo->setAssignedDeviceId( affinityDev->identifier() );
		m_allCompsInfo.push_back(compInfo);

		DEBUG(5, BaseDeployStrategy::deployAffinityComponents, "leave ...")

		return true;
	} else {
		//delete compInfo;
		return false;
	}
}

/**
 * @brief The operation shall match all properties component need with properties
 *        the device can provides, if match successfully, then the component can 
 *        deploy on this device, otherwise can not.
 *
 * @param[in] registeredDevice	Device need matched with the component.
 * @parma[in] matchProps		Properties the component needs.
 *
 * @return Result of matching properties.
 * @retval Match successfully.
 * @retval Match failed.
 */
// 将组件的特性和设备能提供的特性进行匹配，如果匹配成功，返回true
bool 
BaseDeployStrategy::matchOtherPropsToDevice(
    const CF::Device_ptr registeredDevice,
    const std::vector<PRFProperty*> * matchProps) {
	DEBUG(4, BaseDeployStrategy,
	    "In matchOtherPropsToDevice with properties length: " << 
	    matchProps->size())

	for (unsigned int numProp = 0; numProp < matchProps->size(); numProp++) {

		// 这三段赋值在这个函数里面没有用到，难道是全局变量吗？
		CF::DataType * dataType = (*matchProps)[numProp]->getDataType();
		std::string action = (*matchProps)[numProp]->getAction();
		std::string propId = (*matchProps)[numProp]->getID();
		CF::Properties queryProps;
		queryProps.length(1);

		queryProps[0].id = CORBA::string_dup((*matchProps)[numProp]->getID());
		try {
			DEBUG(5, matchOtherPropsToDevice, "query start...")
			if (registeredDevice) {
				// 获得设备能提供的特性
				registeredDevice->query(queryProps);
			}

			DEBUG(5, matchOtherPropsToDevice, "query no exception")
		} catch (CF::UnknownProperties & e) {
			DEBUG(7, DaseDeployStrategy::matchOtherPropsToDevice, 
			      "registeredDevice->query failed with unknown properties.")
			return false;
		} catch (CORBA::SystemException & e) {
			DEBUG(7, DaseDeployStrategy::matchOtherPropsToDevice,
			      "registeredDevice->query failed with SystemException.")
			return false;
		} catch (...) {
			DEBUG(7, DaseDeployStrategy::matchOtherPropsToDevice,
			      "registeredDevice->query failed with unknown exception.")
			return false;
		}

		//get value from query props
		// 将特性值赋值给devPropValAny
		CORBA::Any devPropValAny = queryProps[0].value;
		// 判断该特性是否能匹配成功，如果匹配失败，则返回false
		if (matchSinglePropToDevice((*matchProps)[numProp], devPropValAny))
			continue;
		else
			return false;
		
	}	//for (unsigned int numProp=0; numProp<matchProps->size(), numProp++)

	DEBUG(5, BaseDeployStrategy, "Leaving matchOtherPropsToDevice.")
	return true;
}

// 对单个特性进行匹配，如果匹配成功，返回true，否则返回false
bool 
BaseDeployStrategy::matchSinglePropToDevice(
	PRFProperty * prop,
	CORBA::Any devPropValAny)
{
	// 如果特性是double类型
	if (prop->isDouble()) {	// the type of value is Double
		// 将组件的特性值赋值给doubleVal
		CORBA::Double doubleVal = openscaSupport::strings_to_double(
			prop->getValue());
		
		// devPropVal是设备的特性值吗？这里应该是声明，赋值在哪里？暂时没有找到
		CORBA::Double devPropVal;
	
		// 如果devPropValAny的值小于devPropVal，则返回false
		// devPropValAny是什么？为什么要和这个值作比较，是设备能提供的特性值，应该是能力的一种上界？
		if ( !(devPropValAny >>= devPropVal) ) {
			DEBUG(7, DaseDeployStrategy::matchSinglePropToDevice],
				"matchVal >>= devPropVal any to double failed.")
			return false;
		}

		// 判断特性是否匹配成功
		if (isPropMatched(devPropVal, doubleVal, prop))
			return true;
		else
			return false;
	} else if (prop->isFloat()) {	// the type of value is Float
		CORBA::Float floatVal = openscaSupport::strings_to_float(
			prop->getValue());
		CORBA::Float devPropVal;
		if ( !(devPropValAny >>= devPropVal) ) {
			DEBUG(7, DaseDeployStrategy::matchSinglePropToDevice,
				"matchVal >>= devPropVal any to float failed.")
			return false;
		}

		if (isPropMatched(devPropVal, floatVal, prop))
			return true;
		else
			return false;
	} else if (prop->isULong()) {	// the type of value is ULong
		CORBA::ULong ulongVal = openscaSupport::strings_to_unsigned_long(
			prop->getValue());
		CORBA::ULong devPropVal;
		if ( !(devPropValAny >>= devPropVal) ) {
			DEBUG(7, DaseDeployStrategy::matchSinglePropToDevice,
				"matchVal >>= devPropVal any to ULong failed.")
			return false;
		}

		if (isPropMatched(devPropVal, ulongVal, prop))
			return true;
		else
			return false;
	} else if (prop->isLong()) { // the type of value is Long
		CORBA::Long longVal = openscaSupport::strings_to_long(
			prop->getValue());
		CORBA::Long devPropVal;
		if (!(devPropValAny >>= devPropVal)) {
			DEBUG(7, DaseDeployStrategy::matchSinglePropToDevice,
				"matchVal >>= devPropVal any to ULong failed.")
			return false;
		}

		if (isPropMatched(devPropVal, longVal, prop))
			return true;
		else
			return false;
	} else if (prop->isUShort()) {	// the type of value is UShort
		CORBA::UShort ushortVal =
		openscaSupport::strings_to_unsigned_short(
			prop->getValue());
		CORBA::UShort devPropVal;
		if (!(devPropValAny >>= devPropVal)) {
			DEBUG(7, DaseDeployStrategy::matchSinglePropToDevice,
				"matchVal >>= devPropVal any to UShort failed.")
			return false;
		}

		if (isPropMatched(devPropVal, ushortVal, prop))
			return true;
		else
			return false;
	} else if (prop->isShort()) { // the type of value is Short
		CORBA::Short shortVal = openscaSupport::strings_to_short(
			prop->getValue());
		CORBA::Short devPropVal;
		if (!(devPropValAny >>= devPropVal)) {
			DEBUG(7, DaseDeployStrategy::matchSinglePropToDevice,
				"matchVal >>= devPropVal any to Short failed.")
			return false;
		}

		if (isPropMatched(devPropVal, shortVal, prop))
			return true;
		else
			return false;
	} else if (prop->isString()) {	//Type for String
		CORBA::String_var stringVal = openscaSupport::strings_to_string(
			prop->getValue());
		const char* devPropVal;
		if (!(devPropValAny >>= devPropVal)) {
			DEBUG(7, DaseDeployStrategy::matchSinglePropToDevice,
				"matchVal >>= devPropVal any to String failed.")
			return false;
		}

		if (prop->isEqual()) {
			if (strcmp(devPropVal, stringVal.in()) == 0) {
				return true;
			} else {
				DEBUG(7, DaseDeployStrategy::matchSinglePropToDevice,
					"Property with vaule =" << devPropVal << 
					" failed to match with:" << stringVal.in())
				return false;
			}
		} else {
			DEBUG(7, DaseDeployStrategy::matchSinglePropToDevice, "Property with \
				id=" << prop->getID() << "and type=String: has \
				unknown value type.")
			return false;
		}
	} else {
		DEBUG(7, DaseDeployStrategy::matchSinglePropToDevice,
			"Property with id=" << prop->getID() << " has unknown Data Type")
		return false;
	}	
}

// 判断特性是否匹配，如果匹配，返回true
// 特性的判断只有大小关系，所谓的特性到底是指什么？
template <class T>
bool
BaseDeployStrategy::isPropMatched(
	T devProp, 
	T compProp, 
	PRFProperty* prop)
{
	// 如果需要判断你的特性是是否相等，则设备的特性和组件的特性相等时返回true
	if (prop->isEqual()) {
		if (compProp == devProp) {
			return true;
		} else {
			DEBUG(7, DaseDeployStrategy::isPropMatched,
				"match Property: " << prop->getID() << "failed.")
			return false;
		}
	} else if (prop->isGreaterThanOrEqual()) {
		if (devProp >= compProp) {
			return true;
		} else {
			DEBUG(7, DaseDeployStrategy::isPropMatched,
				"match Property: " << prop->getID() << "failed.")
			return false;
		}
	} else if (prop->isGreaterThan()) {
		if (devProp > compProp) {
			return true;
		} else {
			DEBUG(7, DaseDeployStrategy::isPropMatched,
				"match Property: " << prop->getID() << "failed.")
			return false;
		}
	} else if (prop->isLessThanOrEqual()) {
		if (devProp <= compProp) {
			return true;
		} else {
			DEBUG(7, DaseDeployStrategy::isPropMatched,
				"match Property: " << prop->getID() << "failed.")
			return false;
		}
	} else if (prop->isLessThan()) {
		if (devProp < compProp) {
			return true;
		} else {
			DEBUG(7, DaseDeployStrategy::isPropMatched,
				"match Property: " << prop->getID() << "failed.")
			return false;
		}
	} else if (prop->isNotEqual()) {
		if (devProp != compProp) {
			return true;
		} else {
			DEBUG(7, DaseDeployStrategy::isPropMatched,
				"match Property: " << prop->getID() << "failed.")
			return false;
		}
	} else {
		DEBUG(7, DaseDeployStrategy::isPropMatched,
			"Property with id=" << prop->getID() << 
			"and type=double: has a wrong action.")
		return false;
	}
}

// 将设备和组件的操作系统进行匹配，如果匹配成功，返回true
bool
BaseDeployStrategy::matchOSToDevice(
    const CF::Device_ptr registeredDevice,
    openscaSupport::ComponentInfo * compInfo) {
	DEBUG(4, BaseDeployStrategy, "In matchOSToDevice.")

	CF::Properties props;
	props.length(1);
	props[0].id = CORBA::string_dup("DCE:os_name:1");

	try {
		if (registeredDevice != NULL) {
			DEBUG(5, BaseDeployStrategy::matchOSToDevice, 
				"registeredDevice query start...")

			// 获得设备的操作系统名字
			registeredDevice->query(props);

			DEBUG(5, BaseDeployStrategy::matchOSToDevice, 
				"registeredDevice query end...")
		}
	} catch (CF::UnknownProperties & ex) {
		DEBUG(3, BaseDeployStrategy::matchOSToDevice,
		    "In matchOSToDeivice occure UnknownProperties excetpion")
		return false;
	} catch (...) {
		DEBUG(3, BaseDeployStrategy::matchOSToDevice, 
			"In matchOSToDeivice occure Unknown excetpion")
		return false;
	}

	DEBUG(7, BaseDeployStrategy::matchOSToDevice, 
		"In matchOSToDevice begin to extract osName")

	std::string str = "any ok";

	CORBA::Any aany;
	aany <<= str.c_str();
	const char* msg;
	aany >>= msg;
	DEBUG(7, DaseDeployStrategy, "msg is: " << msg)
	DEBUG(7, DaseDeployStrategy, "begin to extract osName")
	const char* osName = NULL;
	//CORBA::String_var osName;
	try {
		// 将设备的操作系统的名字赋值给osName
		props[0].value >>= osName;
	} catch (...) {
		DEBUG(7, BaseDeployStrategy, "extract string failed")
		return false;
	}

	DEBUG(7, BaseDeployStrategy::matchOSToDevice,
	    "compInfo->getOSName() is :" << compInfo->getOSName() << 
	    "  osName is :" << osName)

	// 如果设备的操作系统的名字和组件的操作系统的名字一致，则返回true
	if ( strcmp(osName, compInfo->getOSName()) == 0) {
		DEBUG(7, BaseDeployStrategy::matchOSToDevice, 
			"In matchOSToDevice return true")
		return true;
	} else {
		DEBUG(7, BaseDeployStrategy::matchOSToDevice, 
			"In matchOSToDevice return false")
		return false;
	}
}

// 将设备和组件的处理器进行匹配，如果匹配成功，返回true
// 设备的处理器只有一个，而组件的处理器有多个，只要有一个匹配成功就算匹配成功
bool
BaseDeployStrategy::matchProcessorToDevice(
    const CF::Device_ptr registeredDevice,
    openscaSupport::ComponentInfo * compInfo) {
	DEBUG(5, BaseDeployStrategy, "In matchProcessorToDevice.")

	CF::Properties props;
	props.length(1);
	props[0].id = CORBA::string_dup("DCE:processor_name:1");

	try {
		// 获得设备的处理器名字
		registeredDevice->query(props);
	} catch (CF::UnknownProperties & ex) {
		DEBUG(3, BaseDeployStrategy::matchProcessorToDevice,
		    "In matchProcessorToDevice occure UnknownProperties excetpion")
		return false;
	} catch (...) {
		DEBUG(3, BaseDeployStrategy::matchProcessorToDevice,
		    "In matchProcessorToDevice occure Unknown excetpion")
		return false;
	}

	const char * processorName;
	// 将设备的处理器的名字赋值给processorName
	props[0].value >>= processorName;
	bool foundProcessor = false;

	// 组件的处理器可能有多个，个数为size
	// 对每个组件处理器，判断其名字是否和设备的处理器名字一致，如果有一致的，则将foundProcessor置为true
	int size = compInfo->getProcessors().size();
	for (unsigned int i = 0; i < size; i++) {
		DEBUG(7, BaseDeployStrategy::matchProcessorToDevice,
		    "comInfo processor is: " << compInfo->getProcessors()[i])
		if (0 == strcmp(processorName, 
				compInfo->getProcessors()[i].c_str())) {
			foundProcessor = true;
			break;
		}
	}

	// 如果组件的处理器中有和设备的处理器一致的，就返回true
	if (foundProcessor) {
		return true;
	} else {
		DEBUG(2, BaseDeployStrategy, "don't find processor: " << processorName)
		return false;
	}

}

// 从DPD解析器中获得设备能力
// 这个函数的实现没有写，有用到这个函数吗？没有
void
BaseDeployStrategy::getDevCapsFromDPD(
    const char * dpdprfl,
    std::vector<PRFProperty*> * capacityProps) {
	DEBUG(4, BaseDeployStrategy, "In getDevCapsFromDPD.")
}

//get component info such as resource type in scd.xml
// 从SCD解析器中获得组件信息，如源类型
void
BaseDeployStrategy::getCompInfoFromSCD(
    const char * scdflPath,
    openscaSupport::ComponentInfo * compinfo) {
	DEBUG(4, BaseDeployStrategy::getCompInfoFromSCD,
	      "In getCompInfoFromSCD with SCD path: " << scdflPath)

	CF::File_var scdfl;
	// 从文件管理器中获得SCD解析器文件的指针
	scdfl = m_fileMgr->open( scdflPath, true );
	//parsering scd.xml
	// 如果文件打开失败，则跳出
	if (!openProfileFile(m_fileMgr.in(), scdflPath, scdfl))
		return;

	//parsering component scd.xml
	// 根据scdfl获得SCD解析器
	SCDParser scdParser( scdfl );
	closeProfileFile(scdfl);

	// 将SCD解析器中源类型赋值给m_isResource
	compinfo->setIsResource( scdParser.isResource() );

	DEBUG(4, BaseDeployStrategy::getCompInfoFromSCD,
	    "In getCompInfoFromSCD component isResource " << scdParser.isResource())
}

//get component info about properties in prf.xml or implpri.xml
// 从prf.xml或者implpri.xml文件里面获得组件特征信息（包括工厂参数、执行参数、配置参数、容量特征、匹配特征）
// 将工厂参数、执行参数、配置参数、容量特征信息写入到compinfo中，将匹配特征写入matchingProps
void
BaseDeployStrategy::getPropertyFromPRF(
    openscaSupport::ComponentInfo * compinfo,
    std::vector<PRFProperty *> & matchingProps,
    PRFParser * prfParser) {
	DEBUG(7, BaseDeployStrategy::getPropertyFromPRF, "In getPropertyFromPRF.")

	//extract properties from prf.xml
	DEBUG(8, BaseDeployStrategy::getPropertyFromPRF,
	    "In getPropertyFromPRF storing factory parameters in componentinfo")
	
	// 从prf解析器中获得工厂参数特征
	std::vector<PRFProperty *> * factoryProp = 
				prfParser->getFactoryParamProperties();
	// 工厂特征的大小
	unsigned int factoryPropSize = factoryProp->size();
	for (unsigned int i = 0; i < factoryPropSize; i++) {
		DEBUG(8, BaseDeployStrategy::getPropertyFromPRF,
		    "adding factory parameter: " << (*factoryProp)[i]->getName());
		// 将工厂特征写入compinfo中
		// getDataType返回的是m_dataType，是一个结构体或者类，里面包含value和id
		compinfo->addFactoryParameter((*factoryProp)[i]->getDataType());
	}

	DEBUG(8, BaseDeployStrategy::getPropertyFromPRF,
	    "In getPropertyFromPRF storing exec parameters in componentinfo")
	
	// 从prf解析器中获得执行参数特征
	std::vector<PRFProperty *> * execProp = prfParser->getExecParamProperties();
	unsigned int execPropSize = execProp->size();
	for (unsigned int i = 0; i < execPropSize; i++) {
		DEBUG(8, BaseDeployStrategy::getPropertyFromPRF, 
			"adding exec parameter: " << (*execProp)[i]->getName() );
		// 将执行参数写入compinfo中
		compinfo->addExecParameter((*execProp)[i]->getDataType());
	}

	DEBUG(8, BaseDeployStrategy::getPropertyFromPRF,
	    "In getPropertyFromPRF storing configure parameters in componentinfo")
	
	// 从prf解析器中获得配置特征
	std::vector<PRFProperty *> * configProp = 
					prfParser->getConfigureProperties();
	unsigned int configPropSize = configProp->size();
	for (unsigned int i = 0; i < configPropSize; i++) {
		DEBUG(8, BaseDeployStrategy::getPropertyFromPRF,
		    "adding configure property: " << (*configProp)[i]->getName() );

		// 将配置特征写入compinfo中
		compinfo->addConfigureProperty((*configProp)[i]->getDataType());
		// 如果配置特征的名字为"affinity_component"，则将值写到compinfo中
		if (0 == strcmp((*configProp)[i]->getName(), "affinity_component")) {
			compinfo->addAffinityCompinents((*configProp)[i]->getValue());
		}
	}

	DEBUG(8, BaseDeployStrategy::getPropertyFromPRF,
	    "In getPropertyFromPRF storing capacity parameters in componentinfo")
	
	// 从prf解析器中获得容量特征
	std::vector<PRFProperty *> * capacityProp = 
					prfParser->getCapacityProperties();
	unsigned int capacityPropSize = capacityProp->size();
	for (unsigned int i = 0; i < capacityPropSize; i++) {
		DEBUG(8, BaseDeployStrategy::getPropertyFromPRF,
		    "adding allocation property: " << (*capacityProp)[i]->getName() );
		// 将容量特征写入compinfo中
		compinfo->addAllocationCapacity((*capacityProp)[i]->getDataType());
	}

	//get matching props intend to match device deploying on
	// 从prf解析器中获得匹配特征，并将匹配特征写入matchingProps
	matchingProps = *(prfParser->getMatchingProperties());
	if (matchingProps.size() > 0) {
		DEBUG(8, BaseDeployStrategy::getPropertyFromPRF,
		    "In getPropertyFromPRF matchingProps size is: " << 
		    matchingProps.size())
	} else {
		DEBUG(8, BaseDeployStrategy::getPropertyFromPRF,
		    "In getPropertyFromPRF matchingProps size is zero ")
	}
}

/**
 * this function is designed to create component deployment relations with devices
 * according to Device Assignment Sequence.
 // 该函数用来根据设备分配顺序来创建组件和设备的部署关系 
 */
// 带参数的创建配置信息函数
std::vector<openscaSupport::ComponentInfo*>
BaseDeployStrategy::createDeployInfo(
    CF::DeviceAssignmentSequence devAssigSeq) {

	DEBUG(2, BaseDeployStrategy, "In createDeployInfo(devAssigSeq).")

	//loop to get every component info thru match deploying device
	// 根据组件的个数循环获得每个组件的信息
	for (unsigned int numComp = 0; numComp < m_sadCompPlaces->size(); numComp++) 
	{
		openscaSupport::ComponentInfo * compInfo = 
					new openscaSupport::ComponentInfo;

		// 获得每个组件的SAD实例化指针sadCompInsts
		std::vector<SADComponentInstantiation*> * sadCompInsts =
		    (*m_sadCompPlaces)[numComp]->getSADInstantiations();

		// 根据SAD解析器获得装配控制器的参考IDassemblyCtrlRefId
		std::string assemblyCtrlRefId = m_sadPar->getAssemblyControllerRefId();
		// 如果组件的ID和装配控制器的ID一致
		if (strcmp(compInfo->getIdentifier(), assemblyCtrlRefId.c_str()) == 0) {
			// 将装配控制器的标志m_isAssemblyController设置为true
			compInfo->setIsAssemblyController( true );
			DEBUG(7, BaseDeployStrategy::createDeployInfo,
			    compInfo->getIdentifier() << " is setIsAssemblyController")
		} else {
			compInfo->setIsAssemblyController( false );
			DEBUG(7, BaseDeployStrategy::createDeployInfo,
			    compInfo->getIdentifier() << " isn't setIsAssemblyController")
		}

		//parsering spd.xml
		// 获得组件的文件参考IDspdrefid
		std::string spdrefid = (*m_sadCompPlaces)[numComp]->getFileRefId();
		// 得到SPD的路径名
		std::string spdPath = 
			m_sdrRoot + "/" + m_sadPar->getSPDById( spdrefid.c_str());
		DEBUG(7, DeployStrategy, "spdPath is: " << spdPath)

		CF::File_var spdfl;
		// 从文件管理器中打开spd文件，并将指针赋值给spdfl
		// 如果打开文件失败，不是进入debug模式，而是直接返回m_allCompsInfo
		if (!openProfileFile(m_fileMgr.in(), spdPath.c_str(), spdfl))
			return m_allCompsInfo;

		//parsering component spd.xml
		// 根据spdfl获得SPD解析器
		SPDParser spdParser( spdfl );
		closeProfileFile(spdfl.in());

		// 根据spd解析器获得实现的指针spdImpls
		std::vector <SPDImplementation*> * spdImpls =
		    spdParser.getImplementations();

		//get absloute path for local code file
		// 获得代码文件的绝对路径
		size_t pos = spdPath.find_last_of("/");
		std::string absLocalFile = 
			replaceFileNameofPath(spdPath.c_str(), (*spdImpls)[0]->getCodeFile());
		compInfo->setLocalFileName(absLocalFile.c_str());

		compInfo->setScaComplicant((*m_sadCompPlaces)[numComp]->isScaCompliant());

		//get component Info for os/processor/implprf and so on
		if ( ((*spdImpls)[0]) && ((*sadCompInsts)[0])) {
			//assume that every component placement have one instantiation
			// 获得组件的信息
			setComponentInfo(compInfo, (*sadCompInsts)[0], (*spdImpls)[0]);
		} else {
			DEBUG(7, BaseDeployStrategy,
			    "[BaseDeployStrategy::createDeployInfo] don't found \
				implementation in spd.xml.")
			exit(1);
		}

		//get component info for resource type in scd.xml
		//extract common path from full SPD path
		DEBUG(7, DeployStrategy, "obtain info from scd.xml")
		//get component info for resource type in scd.xml
		// 获得SCD文件的路径
		std::string scdPath = 
			replaceFileNameofPath(spdPath.c_str(), spdParser.getSCDFile());
		// 从SCD中获得组件信息
		getCompInfoFromSCD(scdPath.c_str(), compInfo);

		//get component info about properties in prf.xml
		// 获得PRF文件的路径
		std::string prfPath = spdParser.getPRFFile();

		//in order to store the identifier of devices assigned
		std::vector <std::string> assignedDevices;

		//extract the matching relation between component and device from
		//input parameter devAssigSeq into compinfo
		// 从devAssigSeq中提取组件和设备之间的匹配关系
		// devAssigSeq中有两个重要信息，一是组件的ID，二是为该组件分配的设备ID
		bool foundCompDev = false;
		for (unsigned int numCompDev = 0; numCompDev < devAssigSeq.length();
		        numCompDev++) {
			// 如果组件的ID和devAssigSeq中的组件ID一致
			if (strcmp(compInfo->getIdentifier(),
			           devAssigSeq[numCompDev].componentId) == 0) {
				// 将设备的ID写到compInfo
				compInfo->setAssignedDeviceId(
					devAssigSeq[numCompDev].assignedDeviceId);
				foundCompDev =  true;
				break;
			}
		}
		if (!foundCompDev) {
			DEBUG(7, BaseDeployStrategy::createDeployInfo,
			    "can't find component: " <<
			    compInfo->getIdentifier() << " in deviceAssignments.")

			throw CF::ApplicationFactory::CreateApplicationRequestError();
		}

		// 将compInfo写入m_allCompsInfo
		m_allCompsInfo.push_back(compInfo);

		DEBUG(2, BaseDeployStrategy, "Component:" << 
			compInfo->getUsageName() << "has found device to deploy.")

	}	//for (unsigned int numComp=0; numComp<m_sadCompPlaces->size(); numComp++)

	DEBUG(2, BaseDeployStrategy, "Leaving createDeployInfo().")

	return m_allCompsInfo;
}

// 配置组件信息
// 根据组件实例化配置的信息（ID,usagename，是否有命名服务，命名服务名称）
// 根据组件实现配置的信息（代码类型，实现ID，进入点，操作系统，处理器，堆栈大小和优先级）
void 
BaseDeployStrategy::setComponentInfo(
	openscaSupport::ComponentInfo * compInfo,
	SADComponentInstantiation * sadCompInst,
	SPDImplementation * spdImp)
{
	if ((!compInfo) || (!sadCompInst) || (!spdImp))
	{
		DEBUG(1, BaseDeployStrategy::setComponentInfo,
			"invalid input parameter")
		return;
	}

	// 根据组件实例化配置的信息（ID,usagename，是否有命名服务，命名服务名称）
	compInfo->setIdentifier( sadCompInst->getID());
	compInfo->setUsageName( sadCompInst->getUsageName());
	compInfo->setNamingService( sadCompInst->isNamingService());
	compInfo->setNamingServiceName(sadCompInst->getFindByNamingServiceName());

	// 根据组件实现配置的信息（代码类型，实现ID，进入点，操作系统，处理器，堆栈大小和优先级）
	compInfo->setCodeType(spdImp->getCodeType());
	compInfo->setImplId(spdImp->getID());
	compInfo->setEntryPoint(spdImp->getEntryPoint());
			//intend to match device deploying on
	compInfo->setOperatingSystem(spdImp->getOperatingSystem().getOSName());
	compInfo->setProcessors(spdImp->getProcessors());
	compInfo->setStackSize( spdImp->getStackSize() );
	compInfo->setPriority( spdImp->getPriority() );
}
