//****************************************************************************************************************
//****                                  LED产品JetFileII协议中的MPU函数模块 
//****			                              遵循chainazone标准
//****                                          开发人:FangMing
//****                                      最后修改日期:2016-11-25
//****************************************************************************************************************
#ifndef __CZ_MPUAPI_H__
#define __CZ_MPUAPI_H__

#include "czType.h"
#include "czStructsDefine.h"

#ifdef __cplusplus
extern "C" {
#endif

//================================================================================================================
//====MPU  functions
//================================================================================================================
CZAPI_DECLARE(INT32U) czMPUSelChannel(INT8U ch,INT8U chType);
CZAPI_DECLARE(INT32U) czMPUSetVideoArg(INT8U type, INT8U value);
CZAPI_DECLARE(INT32U) czMPUSetEDID(INT8U ch,INT8U EDIDName[15]);
CZAPI_DECLARE(INT32U) czMPUSetINBPhase(INT8U ch,INT8U phaseValue);
CZAPI_DECLARE(INT32U) czMPUSetHDMI_DP_Out(INT16U outType,INT16U value);
CZAPI_DECLARE(INT32U) czMPUSelChannelEx(INT8U ch,INT8U chType);
CZAPI_DECLARE(INT32U) czMPUSetWin(INT16U chType, INT16U winX, INT16U winY, INT16U winW, INT16U winH, INT8U ratioMode, INT32U* taskID);
CZAPI_DECLARE(INT32U) czMPUProgressByTaskID(INT32U taskID,INT8U *Progress);

#ifdef __cplusplus
}
#endif

#endif