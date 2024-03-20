//****************************************************************************************************************
//****                                  LED产品JetFileII协议中的czCore函数模块 
//****			                              遵循chainazone标准
//****                                          开发人:YangLei
//****                                      最后修改日期:2014-10-15
//****************************************************************************************************************
#ifndef __CZ_PLAYERAPI_H__
#define __CZ_PLAYERAPI_H__

#include "czType.h"

#ifdef __cplusplus
extern "C" {
#endif

CZAPI_DECLARE(INT32U) czCoreGetFileProperty(INT8U* fileName, INT8U *rtnData, INT32U rtnDataSize);
CZAPI_DECLARE(INT32U) czCorePlayWindowProgram(INT8U* prjPath, INT8U *listName, INT8U* wndName,INT8U* prgName);
CZAPI_DECLARE(INT32U) czCoreRegInfo(INT8U* ip, INT16U Port);
CZAPI_DECLARE(INT32U) czCoreStopPlay(INT8U *wndName);
CZAPI_DECLARE(INT32U) czCoreWinMode(INT8U winMode,INT32U* data,INT32U dataLen);
CZAPI_DECLARE(INT32U) czCoreProjectInfo(INT8U* prjName, INT16U prjCrc, INT16U connPort);
CZAPI_DECLARE(INT32U) czCorePrjSyncProgress(INT8U* status, INT8U* precent);
CZAPI_DECLARE(INT32U) czCoreGetPlayInfo(INT8U* data, INT32U dataLen);
CZAPI_DECLARE(INT32U) czCoreSwitchProgram(INT8U* wndName,INT8U direction);
CZAPI_DECLARE(INT32U) czCoreProjectInfoEx(INT8U* prjName, INT16U prjCrc, INT16U connPort,INT8U* ip);

#ifdef __cplusplus
}
#endif

#endif

