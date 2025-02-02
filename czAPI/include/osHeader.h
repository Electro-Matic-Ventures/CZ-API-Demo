﻿//****************************************************************************************************************
//****                                  LED产品JetFileII协议中的os函数模块 
//****			                              遵循CZ DEPT开发标准
//****                                          开发人:YangLei
//****                                      最后修改日期:2013-03-22
//****************************************************************************************************************
#ifndef __CZ_OS_HEADER_H__
#define __CZ_OS_HEADER_H__
#include "czType.h"
#include <stdio.h>

#ifdef __cplusplus
extern "C" {
#endif

//================================================================================================================
//==== 读写时间用到的结构
//================================================================================================================
typedef struct 
{
	INT16U year;
	INT8U  month;
	INT8U  day;

	INT8U  hour;
	INT8U  min;
	INT8U  sec;
	INT8U  week;

	INT16S tzMins;												//time+this=GMT
	INT8U  tz;													//JetFileII时区索引
	INT8U  Rev;
}czDTime;


#ifndef czMax
#define czMax(a,b)            (((a) > (b)) ? (a) : (b))
#endif

#ifndef czMin
#define czMin(a,b)            (((a) < (b)) ? (a) : (b))
#endif

#ifndef czABS
#define czABS(a)            (((a) > (0)) ? (a) : ((a)*-1))
#endif

//****************************************************************************************************************
//**** 函数名:czSocketup
//**** 功  能:初始化网络
//**** 参  数:
//****        none            - none
//**** 返回值:
//****       none
//****************************************************************************************************************
CZAPI_DECLARE(void) czSocketup();

//****************************************************************************************************************
//**** 函数名:czCleanSocket
//**** 功  能:WSACleanup调用
//**** 参  数:
//****        none            - none
//**** 返回值:
//****        none
//****************************************************************************************************************
CZAPI_DECLARE(void) czCleanSocket();


//****************************************************************************************************************
//**** 函数名:czTLSGet
//**** 功  能:TLS GET
//**** 参  数:
//****        none            - none
//**** 返回值:
//****        none
//****************************************************************************************************************
CZAPI_DECLARE(void*) czTLSGet(INT32U type);

//****************************************************************************************************************
//**** 函数名:czGetPCTempFilename
//**** 功  能:获得一个临时文件路径和文件名
//**** 参  数:
//****        store_path      - store_path
//****        max_path        - max path
//****        ext             - ext
//**** 返回值:
//****        0               - 成功
//****        other           - 失败
//****************************************************************************************************************
CZAPI_DECLARE(INT32U) czGetPCTempFilename(char* store_path, INT32U max_path, char* ext);

//****************************************************************************************************************
//**** 函数名:czGetShortFileName
//**** 功  能:获取短的文件名
//**** 参  数:
//****        src_path        - 源路径
//****        dst	          - 获得的短文件名
//****        max_len         - 短文件名最大长度
//**** 返回值:
//****        返回长度
//****************************************************************************************************************
CZAPI_DECLARE(INT32U) czGetShortFileName(const char* src_path, char* dst, INT32U max_len);

//****************************************************************************************************************
//**** 函数名:czSleep
//**** 功  能:sleep micsec
//**** 参  数:
//****        msec		      - msec
//**** 返回值:
//****        none            - none
//****************************************************************************************************************
CZAPI_DECLARE(void) czSleep(INT32U msec);


//****************************************************************************************************************
//**** 函数名:czGetDOSTime
//**** 功  能:获取dos格式的日期和时间
//**** 参  数:
//****        date		      - 返回dos格式的日期
//****        time		      - 返回dos格式的时间
//**** 返回值:
//****        none            - none
//****************************************************************************************************************
CZAPI_DECLARE(void) czGetDOSTime(INT16U *date, INT16U *time);

//****************************************************************************************************************
//**** 函数名:czGetDateTime
//**** 功  能:获取系统当前时间
//**** 参  数:
//****        dt		      - 返回时间结构体
//**** 返回值:
//****        none            - none
//****************************************************************************************************************
CZAPI_DECLARE(void) czGetDateTime(czDTime* dt);

//****************************************************************************************************************
//**** 函数名:czEnumSerial
//**** 功  能:列出电脑中所有可用的串口
//**** 参  数:
//****        serialList      - 保存的缓冲区，串口以|分隔，如"COM1|COM2|COM3"
//****        size            - 缓冲区的大小
//**** 返回值:
//****        0               - 成功
//****        other           - 失败
//****************************************************************************************************************
CZAPI_DECLARE(INT32U) czEnumSerial(char* serialList, INT32U size);

//****************************************************************************************************************
//**** 函数名:czGetPCTempFilename
//**** 功  能:获得一个临时文件路径和文件名
//**** 参  数:
//****        store_path      - store_path
//****        max_path        - max path
//****        ext             - ext
//**** 返回值:
//****        0               - 成功
//****        other           - 失败
//****************************************************************************************************************
CZAPI_DECLARE(INT32U) czGetPCTempFilename(char* store_path, INT32U max_path, char* ext);

//****************************************************************************************************************
//**** 函数名:czPrintBuf
//**** 功  能:拼接字符串
//**** 参  数:
//****        buf		      - 
//****        ext             - 扩展名
//**** 返回值:
//****        0               - 成功
//****        other           - 失败
//****************************************************************************************************************
CZAPI_DECLARE(INT32U) czPrintBuf(char*buf, INT32U maxBufSize, const char *fmt, ...);



//****************************************************************************************************************
//**** 函数名:czFOpen
//**** 功  能:open file
//**** 参  数:
//****        filename	      - filename
//****        mode            - mode
//**** 返回值:
//****        0               - file handle
//****************************************************************************************************************
CZAPI_DECLARE(FILE*) czFOpen(const char* filename, const char *mode);

//****************************************************************************************************************
//**** 函数名:czSystemUpTimeSec
//**** 功    能:系统上电以来经过的秒数
//**** 参    数:
//****       NONE             - NONE
//**** 返回值:
//****       seconds from power on
//****************************************************************************************************************
CZAPI_DECLARE(INT32U) czSystemUpTimeSec();

//****************************************************************************************************************
//**** 函数名:czFSDelete
//**** 功  能:delete file
//**** 参  数:
//****        filename	      - filename
//**** 返回值:
//****        0               - delete failed
//****        other           - delete ok
//****************************************************************************************************************
CZAPI_DECLARE(INT32U) czFSDelete(const char*filename);

//****************************************************************************************************************
//**** 函数名:czOSCreateDir
//**** 功  能:create directory
//**** 参  数:
//****        filepath      - filepath
//**** 返回值:
//****        0               - create failed
//****        other           - create ok
//****************************************************************************************************************
CZAPI_DECLARE(INT32U) czOSCreateDir(const char*filepath);

//****************************************************************************************************************
//**** 函数名:czOSCopyFile
//**** 功  能:copy file
//**** 参  数:
//****        destname      - destname
//****        filename      - filename
//****        bFailIfExists - bFailIfExists
//**** 返回值:
//****        0               - copy failed
//****        other           - copy ok
//****************************************************************************************************************
CZAPI_DECLARE(INT32U) czOSCopyFile(const char*filename,const char*destname,const bool bFailIfExists);

//****************************************************************************************************************
//**** 函数名:czOSGetFileSize
//**** 功  能:copy file
//**** 参  数:
//****        destname      - destname
//**** 返回值:
//****        0               - copy failed
//****        other           - copy ok
//****************************************************************************************************************
CZAPI_DECLARE(INT32U) czOSGetFileSize(const char*filename);

/**
 ******************************************************************************************************************
 **** @brief 路径分解处理
 ****
 **** @param path 源路径
 **** @param drive 盘
 **** @param dir 路径
 **** @param fname 文件名
 **** @param ext 扩展名
 **** @retval 
 ******************************************************************************************************************
 */
CZAPI_DECLARE(void) czStr_splitpath(const char *path, char * drive,	INT8U driveNumberOfElements,char * dir,	
	INT8U dirNumberOfElements,	char * fname,	INT8U nameNumberOfElements,char * ext, INT8U extNumberOfElements);


//****************************************************************************************************************
//**** 函数名:czSysUpTimeMS
//**** 功  能:获取系统从启动到现在经过时间(ms)
//**** 参  数:
//**** 返回值:
//****       返回时间
//****************************************************************************************************************
CZAPI_DECLARE(INT32U) czSysUpTimeMS();

//****************************************************************************************************************
//**** 函数名:czGetINIWithInt
//**** 功  能:Get int value from ini file
//**** 参  数:
//****        sectname      - destname
//****        keyname       - filename
//****        defValue		- default value
//****        iniPath		- ini filepath
//****        returnValue	- returnValue
//**** 返回值:
//****        0               - ok
//****        other           - faild
//****************************************************************************************************************
CZAPI_DECLARE(INT32U) czGetINIWithInt(const char* sectname,const char* keyname,const int defValue,const char* iniPath, int* returnValue);

//****************************************************************************************************************
//**** 函数名:czGetINIWithInt
//**** 功  能:Get int value from ini file
//**** 参  数:
//****        sectname      - destname
//****        keyname       - filename
//****        newValue		- new value
//****        iniPath		- ini filepath
//**** 返回值:
//****        0               - ok
//****        other           - faild
//****************************************************************************************************************
CZAPI_DECLARE(INT32U) czSetINIWithString(const char* sectname,const char* keyname,const char* newValue,const char* iniPath);

#ifdef __cplusplus
}
#endif
#endif 
