/***************************************************************************//**
* @file     LaunchNode.pp
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

#ifdef __SDS_OS_VXWORKS__
#include <loadLib.h>
#include <unldLib.h>
#include <ioLib.h>
#include <taskLib.h>
#include <symLib.h>
#endif

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

#include <iostream>
#include <vector>
#include <cstring>

#include "../include/LaunchNode.h"
#include "../include/debug.h"
#include "ConfigParser.h"

/**
 * @brief	Constructor of the LaunchNode class.
 * @param[in] fsRoot	Root path of the file system.
 * @param[in] sdrRoot	Path of the platform relative to file system.
 */
 // 定义一种操作，操作名为LaunchNode
 // 输入是fsRoot和sdrRoot
 // 将fsRoot赋值给m_fsRoot，将sdrRoot赋值给m_sdrRoot
LaunchNode::LaunchNode(
	std::string fsRoot,
	std::string sdrRoot) {
	m_fsRoot = fsRoot;
	m_sdrRoot = sdrRoot;
}

// 析构函数名也应与类名相同，只是在函数名前面加一个位取反符~
// 当对象脱离其作用域时,系统自动执行析构函数
LaunchNode::~LaunchNode() {

}

/*
 * @brief	Get file's reference by input file path.
 *
 * @param[in] fileSys	 File system where finding the specific file by input 
 * 						file path.
 * @param[in] filePath	Path of the file user wants to find.
 *
 * @return  The specific file's reference.
 */

 // 返回的是CF命名空间中的一个变量File_var
 // CF是一个命名空间，定义在E:\SCA程序\openSCA-master\frameworks\CF_Interface\include\CFC.h
 // 为什么函数的返回是一个CF::File_var类型，而在函数程序内部定义的却是CF::File_ptr类型？
CF::File_var
LaunchNode::getFileRef(
    CF::FileSystem_ptr fileSys,
    std::string filePath) {
	// 在filePath中从第3个位置往后找到第一个“/”对应的位置
	size_t pos = filePath.find_first_of("/", 3);

	// 找到/后，往后挪一位，然后取出这之后filepath的所有字符
	std::string relativeFilePath = filePath.substr(pos + 1);
	CF::File_ptr filePtr;

	// 从filesys中打开relativeFilePath对应字符的文件
	try {
		filePtr = fileSys->open(relativeFilePath.c_str(), true);
	} catch (CF::InvalidFileName& e) {
		//如果出现文件名无效
		DEBUG(5, LaunchNode,
		      "[launch_opensca] when opening" << 
		      filePath << "with invalid name")
		exit(EXIT_FAILURE);
	} catch (CF::FileException& e) {
		//如果出现FileException的情况
		DEBUG(5, LaunchNode,
		      "[launch_opensca] when opening " << 
		      filePath << "File exception occur")
		exit(EXIT_FAILURE);
	} catch (...) {
		//拦截住所有try里没有被前面捕获的错误，但是你不知道是什么错误
		DEBUG(5, LaunchNode,
		      "[launch_opensca] when opening " << 
		      filePath << "Unkown exception occur")
		exit(EXIT_FAILURE);
	}

	// is_nil是CORBA类中的一个操作
	if (CORBA::is_nil(filePtr)) {
		DEBUG(5, getFileRef, "file's reference is nil. " << filePath)
		exit(EXIT_FAILURE);
	}

	return filePtr;
}

/*
 * @brief Get params which naming service task needs.
 *
 * @param[in] spdParser	The parser of spd file.
 *
 * @return TaskParams	@see TaskParams
 */
 // 提取命名服务需要的任务参数
 // 出现了两个类，一个是TaskParamsType，另一个是SPDParser
TaskParamsType
LaunchNode::getTaskParamsFromSPD(
    SPDParser& spdParser) {
	DEBUG(5, LaunchNode::getTaskParamsFromSPD, "enter in...")

	TaskParamsType taskParams;
	std::vector<SPDImplementation*>* implVec = spdParser.getImplementations();

	// 将spdParser中的任务参数赋值给taskParams
	taskParams.stackSize = (*implVec)[0]->getStackSize();
	taskParams.priority = (*implVec)[0]->getPriority();
	taskParams.entryPoint = new char[strlen((*implVec)[0]->getEntryPoint())];
	strcpy(taskParams.entryPoint, (*implVec)[0]->getEntryPoint());

	DEBUG(5, LaunchNode::getTaskParamsFromSPD, "leave...")

	return taskParams;
}

/**
 * @brief  Get execute params.
 *
 * @param[in] fileSys Filesystem of the platform.
 * @param[in] spdParser Parser of spd file.
 * @param[in] spdflPath The path of spd file.
 *
 * @return	execute params
 */
 // 提取执行参数
ExecParamsType
LaunchNode::getExecParamsFromPRF(
    FileSystem_impl* fileSys,
    SPDParser& spdParser,
    const std::string& spdflPath) {
	DEBUG(5, LaunchNode::getExecParamsFromPRF, "enter in...")

	// 从spdParser中提取PRF文件名
	std::string prfFileName = const_cast<char*>(spdParser.getPRFFile());

	// 将PRF文件名加到spd路径名之后
	size_t pos = spdflPath.find_last_of("/");
	std::string prfFilePath = spdflPath.substr(0, pos + 1) + prfFileName;

	// 如果系统中不存在该PRF文件，则报错
	if (!isFileExists(fileSys, m_sdrRoot + "/" + prfFilePath)) {
		exit(EXIT_FAILURE);
	}

	// PRF文件的完整路径
	std::string prfFileFullPath =
	    m_fsRoot + "/" + m_sdrRoot + "/" + prfFilePath;
	
	// 根据PRF路径创建一个PRF解析器对象
	PRFParser prfParser(prfFileFullPath);

	// 从PRF解析对象中提取执行参数
	ExecParamsType execParams = prfParser.getExecParams();

	DEBUG(5, LaunchNode::getExecParamsFromPRF, "leave...")
	return execParams;
}

/**
 * @brief  Change execParams' format from ExecParamsType to char**.
 *
 * @param[in] argv	 		destination params.
 * @param[in] execParams	executable params of process.
 */
 // 将执行参数的格式从ExecParamsType转化为字符类型
 // iter里面有两个部分吗？为什么要分成两段读
 // 感觉好像是前一个部分存的是名字，后一部分存的是值
 // char **表示指向字符型指针的指针
void
LaunchNode::changeExecParamsFormat(
    char ** argv,
    ExecParamsType execParams) {
#ifdef __SDS_OS_VXWORKS__
	int index = 0;
	for (ExecParamsType::iterator iter = execParams.begin();
	        iter != execParams.end(); iter++) {
		// 将执行参数的名字写入argv中
		// 这里为什么要加1呢，也就是为什么要在名字后面加0呢？
		std::string name = iter->first;
		argv[index] = new char[name.size() + 1];
		bzero(argv[index], name.size() + 1);
		strcpy(argv[index], name.c_str());

		// 将执行参数的值写入argv中
		std::string value = iter->second;
		argv[++index] = new char[value.size() + 1];
		bzero(argv[index], value.size() + 1);
		strcpy(argv[index], value.c_str());

		++index;
	}

	// 在argv最后写了一个空字符
	strcpy(argv[index], NULL);
#endif
}

/**
 * @brief  Change execParams and taskParams' format from ExecParamsType to char**.
 *
 * @param[in] argv	 		destination params.
 * @param[in] execParams	executable params of process.
 * @param[in] taskParams	task params of process.
 */
 // 将执行参数和任务参数的格式变为字符
void
LaunchNode::changeParamsFormat(
    char** argv,
    ExecParamsType execParams,
    TaskParamsType taskParams) {
	int index = 0;
	for (ExecParamsType::iterator execIter = execParams.begin();
	        execIter != execParams.end(); execIter++) {
		std::string name = execIter->first;
		argv[index] = new char[name.size() + 1];
		bzero(argv[index], name.size() + 1);
		strcpy(argv[index], name.c_str());

		std::string value = execIter->second;
		argv[++index] = new char[value.size() + 1];
		bzero(argv[index], value.size() + 1);
		strcpy(argv[index], value.c_str());

		++index;
	}

	// 加上"-STACK_SIZE"
	argv[index] = new char[strlen("-STACK_SIZE") + 1];
	bzero(argv[index], strlen("-STACK_SIZE") + 1);
	strcpy(argv[index], "-STACK_SIZE");
	++index;

	// ULONG_MAX_SIZE是一个全局变量吗？
	// ULONG_MAX_SIZE是taskParams.stackSize的大小
	// sprinf是将taskParams.stackSize输出到argv[index]字符串中
	// %d表示按有符号的十进制整数打印成字符串
	argv[index] = new char[ULONG_MAX_SIZE + 1];
	bzero(argv[index], ULONG_MAX_SIZE + 1);
	sprintf(argv[index], "%d",
	        taskParams.stackSize); //todo converted to DEC string format
	++index;

	// 加上"-PRIORITY"
	argv[index] = new char[strlen("-PRIORITY") + 1];
	bzero(argv[index], strlen("-PRIORITY") + 1);
	strcpy(argv[index], "-PRIORITY");
	++index;

	// 将taskParams.priority转化成字符串加入
	argv[index] = new char[ULONG_MAX_SIZE + 1];
	bzero(argv[index], ULONG_MAX_SIZE + 1);
	sprintf(argv[index], "%d",
	        taskParams.priority); //todo converted to DEC string format
	++index;

	// 加上"-ENTRY_POINT"
	argv[index] = new char[strlen("-ENTRY_POINT") + 1];
	bzero(argv[index], strlen("-ENTRY_POINT") + 1);
	strcpy(argv[index], "-ENTRY_POINT");
	++index;

	// 将taskParams.entryPoint转化成字符串加入
	argv[index] = new char[strlen(taskParams.entryPoint) + 1];
	bzero(argv[index], strlen(taskParams.entryPoint) + 1);
	strcpy(argv[index], taskParams.entryPoint);
	++index;

	argv[index] = NULL;
}

/**
 * @brief	The operation shall start a new process by input parameters.
 * @param[in] fileSys		File system of the platform.
 * @param[in] spdParser		Parser of the spd.xml file.
 * @param[in] spdflPath		Path of the psd.xml file.
 * @param[in] argv			Parameters passed to process's entrypoint.
 * @param[in] taskParams	Task parameters of the process.
 */
 // 
void
LaunchNode::execute(
    FileSystem_impl* fileSys,
    SPDParser& spdParser,
    const std::string& spdflPath,
    char* argv[],
    TaskParamsType taskParams) {
#ifdef __SDS_OS_LINUX__
	// 提取代码文件名称
	std::string codeFileName = getBinaryFileNameFromSPD(spdParser, spdflPath);
	DEBUG(5, launchNode,
	      "[LaunchNode::execute] codeFileName is " << codeFileName)

	// 判断文件是否存在
	if (!isFileExists(fileSys, m_sdrRoot + "/" + codeFileName)) {
		DEBUG(5, launchNode, "[LaunchNode::execute] codeFileName is invalid.")
		exit(EXIT_FAILURE);
	}

	// 文件的完整路径
	std::string fileFullPath = m_fsRoot + "/" + m_sdrRoot + "/" + codeFileName;
	DEBUG(5, launchNode,
	      "[LaunchNode::execute] fileFullPath is " << fileFullPath)

	// fork函数是什么？
	pid_t pid = fork();
	if (pid == -1) {
		DEBUG(5, launchNode, "[LaunchNode::execute] fork() failed.")
		return;
	}

	if (pid == 0) {
		m_pidMap.insert(
		    std::pair<std::string, pid_t>(taskParams.entryPoint, getpid()));

		execv(fileFullPath.c_str(), argv);
		DEBUG(5, launchNode, "[LaunchNode::execute] child process end.")
		exit(0);
	}
#endif
}

/**
 * @brief	This function used to execute NamingService.
 *
 * @param[in] fileSys File system used to find file by input file path.
 * @param[in] spdflPath Naming service's spd file's path, relative to SDRROOT.
 */
 // 启动命名服务
void
LaunchNode::executeNamingService(
    FileSystem_impl* fileSys,
    const std::string& spdflPath) {
	DEBUG(5, launchNode, "[LaunchNode::executeNamingService] entering...")

	// 找到路径，并根据路径建立一个SPDParser对象
	std::string spdflFullPath = m_fsRoot + "/" + m_sdrRoot + "/" + spdflPath;
	SPDParser spdParser(spdflFullPath);

// 如果是__SDS_OS_VXWORKS__，则执行loadFile程序
#ifdef __SDS_OS_VXWORKS__
	loadFile(fileSys, spdParser, spdflPath);
#endif

	// 提取任务参数
	TaskParamsType taskParams = getTaskParamsFromSPD(spdParser);

	// 提取执行参数
	ExecParamsType execParams =
	    getExecParamsFromPRF(fileSys, spdParser, spdflPath);

// 如果是__SDS_OS_VXWORKS__
#ifdef __SDS_OS_VXWORKS__
	// 将execParams转化为字符串，写到argv中
	// 这里的加2是什么意思？是为了后面多写入两个字符
	int argc = execParams.size() * 2 + 2 + 1;
	char** argv = new char*[argc];
	bzero(argv, argc);
	changeExecParamsFormat(argv, execParams);

    // 从SHM中提取文件路径，并根据该路径设置ConfigParser对象configParser
	char openScaPath[64];
    getConfigFilePathFromSHM(openScaPath, sizeof(openScaPath));
  	ConfigParser configParser(openScaPath);

	// 从openScaPath中找NAMING_SERVICE_ENDPOINTS的路径
	// 倒数第三个字符写为“-ORBListenEndpoints”
  	std::string namingServiceEndpoints = 
  		checkConfigInfo(&configParser, CONSTANT::NAMING_SERVICE_ENDPOINTS);
  	argv[argc - 3] = new char[strlen("-ORBListenEndpoints") + 1];
	
	// memset是内存赋值函数，0是要填充的值，strlen("-ORBListenEndpoints") + 1是要填充的字节数
	// 为什么要先用memset再用strcpy，不可以直接用strcpy吗？
  	memset(argv[argc - 3], 0, strlen("-ORBListenEndpoints") + 1);
  	strcpy(argv[argc - 3], "-ORBListenEndpoints");

  	// 倒数第二个字符写namingServiceEndpoints对应的字符
	argv[argc -2] = new char[namingServiceEndpoints.size() + 1];
  	memset(argv[argc - 2], 0, namingServiceEndpoints.size() + 1);
  	strcpy(argv[argc - 2], namingServiceEndpoints.c_str());

	pid_type pid = 0;
	// spawn new task for DmnMgr

	// 执行spawnProcess
	if (!spawnProcess(argc, argv, taskParams.entryPoint, taskParams.stackSize,
	                  taskParams.priority, pid)) {
		DEBUG(5, launchNode,
		      "[LaunchNode::executeNamingService] spawnprocess failed")
		exit(EXIT_FAILURE);
	}
// 如果是defined __SDS_OS_LINUX__
#elif defined __SDS_OS_LINUX__
	//TASK_PARAMS_COUNT也是一个全局变量？
	int argc = execParams.size() * 2 + TASK_PARAMS_COUNT + 2 + 1;
	char** argv = new char*[argc];
	bzero(argv, argc);

	// -ORB parameters should be neighbouring, otherwise will parse failed
	// 这里为什么要+2？因为要在0和1的位置写字符
	// 将执行参数和任务参数转化为字符串
	changeParamsFormat(argv + 2, execParams, taskParams);

    char openScaPath[64];
    getConfigFilePathFromSHM(openScaPath, sizeof(openScaPath));
  	ConfigParser configParser(openScaPath);

	//  这里为什么要用getValueById这个操作，而不是上面checkConfigInfo操作
	//  getValueById是根据ID名获得名字
	// LINUX系统中NAMING_SERVICE_ENDPOINTS是ID名，而VXWORKS系统中是函数名吗？
  	std::string namingServiceEndpoints = 
  	configParser.getValueById(CONSTANT::NAMING_SERVICE_ENDPOINTS);
	
	// 第一位写"-ORBListenEndpoints"
  	argv[0] = new char[strlen("-ORBListenEndpoints") + 1];
  	memset(argv[0], 0, strlen("-ORBListenEndpoints") + 1);
  	strcpy(argv[0], "-ORBListenEndpoints");

  	// 第二位写namingServiceEndpoints对应的字符
	argv[1] = new char[namingServiceEndpoints.size() + 1];
  	memset(argv[1], 0, namingServiceEndpoints.size() + 1);
  	strcpy(argv[1], namingServiceEndpoints.c_str());

	// 执行服务
	execute(fileSys, spdParser, spdflPath, argv, taskParams);
#endif

	// 休眠10毫秒
	sMsSleep(10);

	// 释放动态二维数组
	delete2DArray(argc, argv);

	DEBUG(5, launchNode, "[LaunchNode::executeNamingService] execute NamingSvr succ")
}

/**
 * @brief	This function is used to execute device manager.
 *
 * @param[in] fileSys 	FileSystem used to find file by input file path.
 * @param[in] spdflPath DeviceManager's dcd file's path, relative to SDRROOT.
 */
 // 启动设备管理器
void
LaunchNode::executeDevMgr(
    FileSystem_impl* fileSys,
    const std::string& dcdflPath) {
	DEBUG(5, launchNode, "[LaunchNode::executeDevMgr] entering...")

	// 找到dcd文件的路径
	std::string dcdflFullPath = m_fsRoot + "/" + m_sdrRoot + "/" + dcdflPath;

	// 根据dcd文件的路径创建DCDParser对象
	DCDParser dcdParser(dcdflFullPath);

	//get spd file
	// 找到spd文件的名字
	std::string spdflName = dcdParser.getDeviceManagerSoftPkg();
	size_t pos = dcdflFullPath.find_last_of("/");

	// 在dcd文件的名字后面加上spd文件的名字，从而构成spd文件的路径
	std::string spdflFullPath = dcdflFullPath.substr(0, pos + 1) + spdflName;

	// 根据spd文件的路径创建SPDParser对象
	SPDParser spdParser(spdflFullPath);

	//load binary file
	// 相对路径，没有m_fsRoot + "/" + m_sdrRoot + "/"
	std::string spdflRelativePath =
	    dcdflPath.substr(0, dcdflPath.find_last_of("/") + 1) + spdflName;

// 如果是__SDS_OS_VXWORKS__，需要加载文件
#ifdef __SDS_OS_VXWORKS__
	loadFile(fileSys, spdParser, spdflRelativePath);
#endif

	// 找到任务参数和执行参数
	TaskParamsType taskParams = getTaskParamsFromSPD(spdParser);
	ExecParamsType execParams =
	    getExecParamsFromPRF(fileSys, spdParser, spdflRelativePath);

// 如果是__SDS_OS_VXWORKS__
#ifdef __SDS_OS_VXWORKS__
	int argc = execParams.size() * 2 + 1;
	char** argv = new char*[argc];
	bzero(argv, argc);

	changeExecParamsFormat(argv, execParams);

	pid_type pid = 0;
	// spawn new task for Devmgr
	// 执行spawn过程
	if (!spawnProcess(argc, argv, taskParams.entryPoint, taskParams.stackSize,
	                  taskParams.priority, pid)) {
		DEBUG(5, launchNode, "[LaunchNode::executeDevMgr] spawnprocess failed")
		exit(EXIT_FAILURE);
	}
// 如果是defined __SDS_OS_LINUX__
#elif defined __SDS_OS_LINUX__
	int argc = execParams.size() * 2 + TASK_PARAMS_COUNT + 1;
	char** argv = new char*[argc];
	bzero(argv, argc);

	changeParamsFormat(argv, execParams, taskParams);

	execute(fileSys, spdParser, spdflRelativePath, argv, taskParams);
#endif

	sMsSleep(10);
	delete2DArray(argc, argv);

	DEBUG(5, launchNode, "[LaunchNode::executeDevMgr] execute DevMgr succ")
}

/*
 * @brief	This function is used to execute domain manager.
 *
 * @param[in] fileSys 		file system used to find file by input file path.
 * @param[in] dmdflPath		domainManager's dmd file's path, relative to SDRROOT.
 */
 // 启动域管理器
void
LaunchNode::executeDmnMgr(
    FileSystem_impl* fileSys,
    const std::string& dmdflPath) {
	DEBUG(5, launchNode, "[LaunchNode::executeDmnMgr] entering...")

	// 找到dmd文件的路径
	std::string dmdflFullPath = m_fsRoot + "/" + m_sdrRoot + "/" + dmdflPath;

	// 根据dmd文件的路径创建DMDParser对象
	DMDParser dmdParser(dmdflFullPath);

	//get spd file
	// 将spf文件名加到dmd文件名之后，构成spf文件的路径，并创立SPDParser对象
	std::string spdflName = dmdParser.getDomainManagerSoftPkg();
	size_t pos = dmdflFullPath.find_last_of("/");
	std::string spdflFullPath = dmdflFullPath.substr(0, pos + 1) + spdflName;
	SPDParser spdParser(spdflFullPath);

	//load binary file
	// 相对路径，没有m_fsRoot + "/" + m_sdrRoot + "/"
	std::string spdflRelativePath =
	    dmdflPath.substr(0, dmdflPath.find_last_of("/") + 1) + spdflName;

#ifdef __SDS_OS_VXWORKS__
	loadFile(fileSys, spdParser, spdflRelativePath);
#endif

	// 提取任务参数和执行参数
	TaskParamsType taskParams = getTaskParamsFromSPD(spdParser);
	ExecParamsType execParams =
	    getExecParamsFromPRF(fileSys, spdParser, spdflRelativePath);

#ifdef __SDS_OS_VXWORKS__
	
	int argc = execParams.size() * 2 + 1;
	char** argv = new char*[argc];
	bzero(argv, argc);

	// 将执行参数转化为字符
	changeExecParamsFormat(argv, execParams);

	pid_type pid = 0;
	// spawn new task for DmnMgr
	// 执行域管理器的spawn过程
	if (!spawnProcess(argc, argv, taskParams.entryPoint, taskParams.stackSize,
	                  taskParams.priority, pid)) {
		DEBUG(5, launchNode, "[LaunchNode::executeDmnMgr] spawnprocess failed")
		exit(EXIT_FAILURE);
	}
#elif defined __SDS_OS_LINUX__
	int argc = execParams.size() * 2 + TASK_PARAMS_COUNT + 1;
	char** argv = new char*[argc];
	bzero(argv, argc);

	// 将执行参数和任务参数转化为字符
	changeParamsFormat(argv, execParams, taskParams);

	// 执行域管理器的启动
	execute(fileSys, spdParser, spdflRelativePath, argv, taskParams);
#endif

	sMsSleep(10);
	delete2DArray(argc, argv);

	DEBUG(5, launchNode, "[LaunchNode::executeDmnMgr] execute DmnMgr succ")
}

/**
 * @brief Terminate a specific process by process id.
 * @param[in] pid	Identifier of the process. 
 * @return	Result of killing the process.
 * @retval true		Kill the process successfully.
 * @retval false	Kill the process failed.
 */
// 终止一个特定的过程
bool
LaunchNode::killProcess(
    pid_type pid) {
	DEBUG(5, launchNode, "[LaunchNode::killProcess pid_type] entering...")

#ifdef __SDS_OS_VXWORKS__
	// 如果删除任务出错
	if (taskDelete(pid) == ERROR) {
		DEBUG(2, ExecutableDevice, "In killProcess pid_type delete task failed")
		return false;
	}
#elif defined __SDS_OS_LINUX__
	// kill函数应该是返回是否终止成功的标记
	int retval = kill(pid, SIGKILL);

	// 如果没有成功，则报错
	if (retval) {
		DEBUG(2, ExecutableDevice, "In killProcess pid_t delete task failed")
		return false;
	}
#endif

	return true;
}

/**
 * @brief		Get binary file's name by parsering spd file.
 * @param[in]	spdParser	parser of the spd.xml file.
 * @param[in]	spdflPath   spd file's path.
 * @return 		binary file's name
 */
 // 获得文件的名字
 // spd路径名加上spdParser的名字
std::string
LaunchNode::getBinaryFileNameFromSPD(
    SPDParser& spdParser,
    const std::string& spdflPath) {
	std::string codeFileName =
	    const_cast<char*>((
	    	*(spdParser.getImplementations()))[0]->getCodeFile());
	size_t pos = spdflPath.find_last_of("/");
	return spdflPath.substr(0, pos + 1) + codeFileName;
}

/**
 * @brief		Load binary file into memory
 * @param[in]   fileSys  	file system used to find binary file
 * @param[in]	spdParser	parser of the spd.xml file.
 * @param[in]	spdflPath	spd file's path, relative to SDRROOT
 */
 // 将文件加载到内存之中
void
LaunchNode::loadFile(
    FileSystem_impl* fileSys,
    SPDParser& spdParser,
    const std::string& spdflPath) {
#ifdef __SDS_OS_VXWORKS__
	// 获得代码的名字
	std::string codeFileName = getBinaryFileNameFromSPD(spdParser, spdflPath);
	if (!isFileExists(fileSys, m_sdrRoot + "/" + codeFileName)) {
		exit(EXIT_FAILURE);
	}

	DEBUG(5, launchNode, "[LaunchNode::loadFile] entering...")

	// 获得代码的完整名字
	std::string codeFileFullName =
	    m_fsRoot + "/" + m_sdrRoot + "/" + codeFileName;

	//open file with open call
	// 打开文件
	int fdx = ::open(codeFileFullName.c_str(), O_RDONLY, 0);

	// 如果打开文件出错，则报错
	if (fdx == ERROR) {
		DEBUG(5, launchNode,
		      "[LaunchNode::loadFile]open file:" << 
		      codeFileFullName << " failed")
		exit(EXIT_FAILURE);
	}

	// 将文件加载到模块之中，且模块的id为mid
	// LOAD_ALL_SYMBOLS这个应该也是全局变量
	MODULE_ID mid = loadModule(fdx, LOAD_ALL_SYMBOLS);

	// 将文件关闭
	::close(fdx);

	// 如果模块的id是0，则报错
	if (mid == 0) {
		std::cerr << "Failed to load file: " << codeFileFullName << std::endl;
		exit(EXIT_FAILURE);
	}

	//store info into filemap
	// 将文件的名字以及模块名存到loadFileInfo之中
	LoadFileInfo loadFileInfo;
	loadFileInfo.localFile = codeFileFullName;
	loadFileInfo.loadType = "executable";
	loadFileInfo.refcnt = 1;
	loadFileInfo.moduleID = mid;

	// m_loadFileMap是一个LoadFileMap对象，其声明在LaunchNode.h文件中
	// 除了这两个地方，其他地方没有用到，那这一行语句是干嘛用的？
	m_loadFileMap[codeFileFullName] = loadFileInfo;

	DEBUG(5, launchNode, "leaving LaunchNode::loadfile...")
#endif

}

/**
 * @brief	The operation shall start a new process by input parameters.
 * @param[in] argc			Counts of parameters passed to the entrypoint 
 * 							of the process.
 * @param[in] argv			Parameters passed to process's entrypoint.
 * @param[in] ulStackSize	Size of the stack the process needs.
 * @param[in] ulPriority	Priority of the process.
 * @param[inout] pid		Id of the process.
 */
// spawn过程
// 如果任务启动，返回true，否则返回false
bool
LaunchNode::spawnProcess(
    int argc,
    char* argv[],
    char* entryPoint,
    unsigned long ulStackSize,
    unsigned long ulPriority,
    pid_type& pid) {
// 如果是__SDS_OS_VXWORKS__
#ifdef __SDS_OS_VXWORKS__
	DEBUG(5, launchNode, "[LaunchNode::spawnProcess] entering...")

	// 定义任务名的长度
	int taskNameLen = strlen(entryPoint) + 2;
	char* taskName = new char[taskNameLen];
	taskName[0] = 't';
	taskName[1] = '\0';

	//strcat() 函数把 entryPoint 所指向的字符串追加到 taskName 所指向的字符串的结尾
	// taskName 末尾的\0会被覆盖，entryPoint 末尾的\0会一起被复制过去
	// 返回值：指向 taskName 的指针
	strcat(taskName, entryPoint);
	DEBUG(5, launchNode, "[LaunchNode::spawnProcess] taskName is " << taskName)

	// extern可以置于变量或者函数前，以标示变量或者函数的定义在别的文件中
	extern SYMTAB_ID sysSymTbl;
	char* address;
	SYM_TYPE type;
	// 根据输入的entryPoint判断是否能找到名字，如果找不到则报错
	if (symFindByName(sysSymTbl, entryPoint, &address, &type) == ERROR) {
		std::cerr << "ERROR: Could not find symbol: " << 
			std::string(entryPoint) << std::endl;
		return false;
	}

	// 确定pid
	// taskSpawn是VXworks中的一个函数吗？没有找到函数的声明和具体过程
	pid = taskSpawn(
	          taskName,					///< task name
	          ulPriority,				///< task priority
	          VX_FP_TASK | VX_SPE_TASK,	///< task options
	          ulStackSize,				///< task stack size
	          (FUNCPTR) address,		///< task entry point
	          argc, (int) (argv), 0, 0, 0, 0, 0, 0, 0, 0);

	delete[] taskName;

	// 如果pid是错误，则报错
	if (pid == ERROR) {
		std::cerr << "ERROR: Failed to spawn task: " << std::string(argv[0])
		          << std::endl;
		return false;
	}
	return true;

#endif
}

/*
 * @brief Check the input file is existed in the iinput fileSystem.
 *
 * @param[in] fileSys	pointet to FileSystem.
 * @param[in] filePath  the checked file's path.
 *
 * @return result of file's existing.
 * @retval true		file exists in file system
 * @retval false	file dosen't exist in file system.
 */
 // 判断文件是否存在
bool
LaunchNode::isFileExists(
    FileSystem_impl* fileSys,
    const std::string& filePath) {
	assert(fileSys);
	if (!(fileSys->exists(filePath.c_str()))) {
		DEBUG(5, isFileExists, "do not exist in file system." << filePath)
		return false;
	}
	return true;
}
