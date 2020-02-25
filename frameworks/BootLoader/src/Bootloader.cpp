/***************************************************************************//**
* @file     Bootloader.cpp
* @author   open Team
* @version  9
* @date     2017-03-16
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

#include <string.h>
#include <stdio.h>
#include <sys/time.h>
#include <dirent.h>

#ifdef __SDS_OS_VXWORKS__
#include <taskLib.h>
#endif

#include <iostream>
#include <istream>

#include "../include/LaunchNode.h"
#include "../include/debug.h"
#include "utils.h"
#include "cf_utils.h"
#include "SPDParser.h"
#include "DCDParser.h"
#include "FileSystem_impl.h"
#include "CFS.h"
#include "ConfigParser.h"
#include "Boost_utils.h"

// checkConfigInfo函数的声明（具体的函数在下面）
const std::string
checkConfigInfo(
    ConfigParser * configParser,
    const char * item);

// splitString函数的声明
void
splitString(
    const std::string & context,
    std::vector<std::string> & subStrs,
    const std::string & splitStr);

// 使用ifdef可以区隔一些与特定头文件、程序库和其他文件版本有关的代码
// 如果定义的是__SDS_OS_VXWORKS__，则函数的文件名叫launch_opensca
// 被extern “C”修饰的函数或者变量是按照C语言方式编译和链接的
#ifdef __SDS_OS_VXWORKS__
extern "C"
int launch_opensca(int argc, char* argv[])

// 如果定义的是defined __SDS_OS_LINUX__，则函数的文件名叫main
#elif defined __SDS_OS_LINUX__
int main(int argc, char * argv[])
#endif
{
	// SCA_SHM和SCA_SHM_SIZE定义在Boost_utils.h文件中
	// 创建一个共享内存，名字为"sca_shm"（SCA_SHM）， 大小为1024（SCA_SHM_SIZE）	
	// 该函数的定义在E:\SCA程序\openSCA-master\runtime_env\rte_utils\include\Boost_utils.h中
	// 该函数的具体操作没找到
	createSharedMemory(SCA_SHM, SCA_SHM_SIZE);

	// 该函数的定义在E:\SCA程序\openSCA-master\frameworks\libCF_Utils\include\debug.h中
	// 函数的具体操作在E:\SCA程序\openSCA-master\frameworks\libCF_Utils\src\debug.cpp中
	// 函数中调用了一个setDebugLevel函数
	// setDebugLevel函数的具体操作没找到
	set_debug_level(0);

	// 该函数的定义在E:\SCA程序\openSCA-master\include\runtime_env\rte_debug.h中
	// 具体操作没找到
	set_rte_debug_level(0);

	// DEBUG的具体操作没找到
	DEBUG(5, Bootloader_main, "start...")

	// 该函数在E:\SCA程序\openSCA-master\frameworks\libCF_Utils\src\cf_utils.cpp中
	// 读取exe的路径
	// exe名字为"/proc/self/exe"，还要加上"opensca.conf"
    std::string exePath = getConfigFilePathByExecutablePath();

	// 函数没找到，猜测是将配置文件路径写到SHM之中
	// exePath.c_str()返回指向exePath的指针
    setConfigFilePathToSHM(exePath.c_str());
	
    char openScaPath[64];
	//函数没找到，猜测是从SHM之中读取配置文件路径
    getConfigFilePathFromSHM(openScaPath, sizeof(openScaPath));

	// 定义一个ConfigParser对象，名字为configParser
	// 根据openScaPath的文件名确定configParser
  	ConfigParser configParser(openScaPath);

	DEBUG(5, Bootloader_main, "Test BootLoader configParser end...")

	// 从openScaPath中找FSROOT的路径
	std::string fsRoot = checkConfigInfo(&configParser, CONSTANT::FSROOT);
	// 如果fsRoot为空字符
	if ("" == fsRoot) {
		DEBUG(0, Bootloader_main, "Test BootLoader first checkConfigInfo...")
		return -1;
	}

	DEBUG(5, Bootloader_main, "Test BootLoader first checkConfigInfo end...")

	// 从openScaPath中找SDRROOT的路径
	std::string sdrRoot = checkConfigInfo(&configParser, CONSTANT::SDRROOT);
	if ("" == sdrRoot) {
		DEBUG(0, Bootloader_main, "Test BootLoader second checkConfigInfo...")
		return -1;
	}

	DEBUG(5, Bootloader_main, "Test BootLoader second checkConfigInfo end...")

	// 定义一个字符变量snFile
	std::string snFile = const_cast<char*>(CONSTANT::SNFILE);

	// 定义一个FileSystem_impl对象，名字为fileSystemImpl
	FileSystem_impl* fileSystemImpl = new FileSystem_impl(fsRoot.c_str());

	// 定义snPath
	std::string snPath = "/" + sdrRoot + "/" + snFile;

	// 定义snFilePath
	// snFilePath只在这里定义了，但是没有用到
	std::string snFilePath = fsRoot + snPath;

#ifdef __SDS_OS_VXWORKS__
	// semBCreate的具体操作没有找到
	domainMgrMtx = semBCreate(SEM_Q_PRIORITY, SEM_EMPTY);
	devMgrMtx = semBCreate(SEM_Q_PRIORITY, SEM_EMPTY);
	sysMgrMtx = semBCreate(SEM_Q_PRIORITY, SEM_EMPTY);
#endif

	// 从openScaPath中找NAMING_SERVICE_SPDPATH的路径
	std::string namingServiceSPDPath =
	    checkConfigInfo(&configParser, CONSTANT::NAMING_SERVICE_SPDPATH);
	if ("" == namingServiceSPDPath) {
		return -1;
	}

	// 从openScaPath中找MAINDCDPATH的路径
	std::string mainDCDPath = checkConfigInfo(
								&configParser, CONSTANT::MAINDCDPATH);
	DEBUG(7, Bootloader, "mainDCDPath: " << mainDCDPath)
	if ("" == mainDCDPath) {
		return -1;
	}

	// 从openScaPath中找DMDPATH的路径
	std::string DMDPath = checkConfigInfo(&configParser, CONSTANT::DMDPATH);
	if ("" == DMDPath) {
		return -1;
	}

	// 定义一个节点对象，名字为launchNode
	LaunchNode* launchNode = new LaunchNode(fsRoot, sdrRoot);
	DEBUG(0, Bootloader_main, "BootLoader launch namingservice start...")
	DEBUG(5, launch_opensca, "execute namingservice")

	// 启动命名服务
	launchNode->executeNamingService(fileSystemImpl, namingServiceSPDPath);

	///< load binary file: DomainMgr.out
	DEBUG(0, Bootloader_main, "BootLoader launch Domain_Manager start...")
	DEBUG(5, launch_opensca, "load binary file: Domain_Manager.out")
	// 启动域管理器服务
	launchNode->executeDmnMgr(fileSystemImpl, DMDPath);

	///< load binary file: DevMgr.out
	DEBUG(5, launch_opensca, "load binary file: Device_Manager.out")
	// 启动设备管理器服务
	launchNode->executeDevMgr(fileSystemImpl, mainDCDPath);

#ifdef __SDS_OS_VXWORKS__
	semTake(sysMgrMtx, WAIT_FOREVER);
#elif defined __SDS_OS_LINUX__
	waitSemaphore(BOOST_CONSTANT::SYSTEM_MANAGER_CND);
#endif

	DEBUG(5, launch_opensca, "launch opensca platform finish.")

	delete fileSystemImpl;
	delete launchNode;

	wait(NULL);
	///< destroy sca_shm shared memory.
	removeSharedMemory(SCA_SHM);

	DEBUG(0, Bootloader_main, "leaving...")
	return 0;
}

// 函数checkConfigInfo
// 输入有两个，一个是ConfigParser对象，对象名为configParser，是一个指针
// 另一个是一个常数字符，名字为item，也是一个指针
// 输出是item对应的名字
// ->是指向结构体成员运算符，用处是使用一个指向结构体或对象的指针访问其内成员。
// ConfigParser是一个类，位置在E:\SCA程序\openSCA-master\include\runtime_env\ConfigParser.h
// ConfigParser类里面声明了getValueById这个操作，但是操作的具体过程没找到，操作的目的是根据ID获得名字
// 函数的作用，根据item这个ID找对应的名字，如果能找到，则返回名字，如果找不到，则显示不能找到
const std::string
checkConfigInfo(
    ConfigParser* configParser,
    const char* item) {
	if (!configParser->getValueById(item)) {
		DEBUG(5, checkConfigInfo, "can't find " << item)
		return "";
	}

	return configParser->getValueById(item);
}

// 函数splitString
// 输入有三个，第一个是常数字符，名字为context
// 第二个是一个vector数组，名字为subStrs
// 第三个也是一个常数字符，名字为splitStr
// 函数的作用是从context中抠除所有的splitStr字符，然后加到subStrs后面
// 如果context中没有splitStr字符，则把context整个加到subStrs后面
// 该函数在这个程序里面定义了，但是并没有用到
void
splitString(
    const std::string & context,
    std::vector<std::string> & subStrs,
    const std::string & splitStr) {
	// 函数里面定义了两个量 pos1 和 pos2
	// std::string::size_type是尺寸单位类型
	// string::find函数返回的类型就是std::string::size_type
	std::string::size_type pos1;
	std::string::size_type pos2;

	// 初始化
	// string::find 返回值是字母在母串中的位置，如果没有找到，会返回一个特别的标记npos
	// pos2是splitStr在context中的位置
	pos2 = context.find(splitStr);
	pos1 = 0;

    // 这一部分的目的是从context中抠除所有的splitStr字符，然后加到subStrs后面
	while (string::npos != pos2) {
		// s.substr(p,n)返回值是一个string，包含字符串s中从p开始的n个字符的拷贝
		// subStrs.push_back表示在subStrs尾部加入一个数据
		subStrs.push_back(context.substr(pos1, pos2 - pos1));

		// string::size()返回的是一个无符号的整数
		// splitStr.size()返回的是splitStr中字符的个数
		pos1 = pos2 + splitStr.size();

		// 从pos1位置之后从context中查找splitStr的位置
		pos2 = context.find(splitStr, pos1);
	}


	// 该语句有两个作用，如果context中没有splitStr字符，则把context的内容整个加到subStrs后面
	// 如果context中有splitStr字符，执行完上面的while语句之后，把最后一段内容加到subStrs后面
	if (pos1 != context.length())
		subStrs.push_back(context.substr(pos1));
}
