//****************************************************************************************************************
//****                                  LED产品JetFileII协议中的FileCtrl函数模块 
//****			                              遵循CZ DEPT开发标准
//****                                          开发人:YangLei
//****                                      最后修改日期:2013-03-22
//****************************************************************************************************************
#ifndef __CZ_FILECTRLAPI_H__
#define __CZ_FILECTRLAPI_H__

#include "czType.h"

#ifdef __cplusplus
extern "C" {
#endif

CZAPI_DECLARE(INT32U) czFormatDrive(INT8U Drive);
CZAPI_DECLARE(INT32U) czCreateDir(INT8U* Dir);
CZAPI_DECLARE(INT32U) czRename(INT8U* SourceName, INT8U* DestName);
CZAPI_DECLARE(INT32U) czMove(INT8U* SourceName, INT8U* DestName);
CZAPI_DECLARE(INT32U) czDelete(INT8U* FileName);
CZAPI_DECLARE(INT32U) czDelTextFiles(INT8U Drive);
CZAPI_DECLARE(INT32U) czDelStringFiles(INT8U Drive);
CZAPI_DECLARE(INT32U) czDelPictureFiles(INT8U Drive);
CZAPI_DECLARE(INT32U) czDelArrpicFiles(INT8U Drive);
CZAPI_DECLARE(INT32U) czGetDirFile(INT8U* path,INT32U* Num,DIRECTORY_ENTRY_STRUCT* dirEntry,INT32U size);
CZAPI_DECLARE(INT32U) czGetDirFileEx(INT8U* path,INT16U StarNo,INT16U RNum,INT32U* Num,
	                                    DIRECTORY_ENTRY_STRUCT* dirEntry, INT32U size);
CZAPI_DECLARE(INT32U) czGetDirLongFileEx(INT8U* path, INT8U* pcpath);
CZAPI_DECLARE(INT32U) czGetDriveInfo(INT8U Drive, INT32U *totalSize, INT32U *remainSize, INT8U *driveName);
CZAPI_DECLARE(INT32U) czIsFileExist(INT8U* FileName);
CZAPI_DECLARE(INT32U) czClearAllPlayFiles(INT8U Operation,INT16U* Process);

CZAPI_DECLARE(INT32U) czLstFolder(INT8U* pcpath, INT8U* signpath);
CZAPI_DECLARE(INT32U) czLstLongFolderCB( INT8U* signpath, 
	                     INT32S (*cb)(DIRECTORY_ENTRY_STRUCTEx *dirEntry, void *cbObj), void *cbObj);

CZAPI_DECLARE(INT32U) czPLDeleteByIndex(INT8U playListIndex);

#ifdef __cplusplus
}
#endif
#endif
