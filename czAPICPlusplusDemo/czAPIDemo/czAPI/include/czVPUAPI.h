//****************************************************************************************************************
//****                                  LED产品JetFileII协议中的VPU函数模块 
//****			                              遵循chainazone标准
//****                                          开发人:YangLei
//****                                      最后修改日期:2013-03-22
//****************************************************************************************************************
#ifndef __CZ_VPUAPI_H__
#define __CZ_VPUAPI_H__

#include "czType.h"
#include "czStructsDefine.h"

#ifdef __cplusplus
extern "C" {
#endif

//================================================================================================================
//====VPU  functions
//================================================================================================================
CZAPI_DECLARE(INT32U) czVPUSelChannel(INT8U ch);
CZAPI_DECLARE(INT32U) czVPUSetMode(INT8U mode, INT8U alpha);
CZAPI_DECLARE(INT32U) czVPUSetVideoRatio(INT8U ratio);
CZAPI_DECLARE(INT32U) czVPUSetDVIWin(INT16U type, INT16U value);
CZAPI_DECLARE(INT32U) czVPUSetVideoWin(INT16U type, INT16U value);
CZAPI_DECLARE(INT32U) czVPUSetVideoArg(INT16U type, INT16U value);
CZAPI_DECLARE(INT32U) czVPUGetSignalStatus(INT16U *videoW, INT16U *vedioH, INT16U *dviW, INT16U *divH);
CZAPI_DECLARE(INT32U) czVPUType(INT8U type);
CZAPI_DECLARE(INT32U) czVPUSlaverStartLine(INT16U StartLine);
CZAPI_DECLARE(INT32U) czVPUSetColorTemp(INT8U type,INT8U R, INT8U G, INT8U B);
CZAPI_DECLARE(INT32U) czVPUSetBright(INT8U type,INT8U manualValue, INT8U autoMin, INT8U autoMax);
CZAPI_DECLARE(INT32U) czVPUGetBright(INT8U *type,INT8U *manualValue, INT8U *autoMin, INT8U *autoMax);
CZAPI_DECLARE(INT32U) czVPUSetGamma(INT8U index);
CZAPI_DECLARE(INT32U) czVPUSetLDUNums(INT8U LDUNums);
CZAPI_DECLARE(INT32U) czVPUSetLDUPos(INT8U LDUID, INT16U x, INT16U y);
CZAPI_DECLARE(INT32U) czVPUGetInfo(VPUVerInfo *info);
CZAPI_DECLARE(INT32U) czVPUSetPixcelMode(INT8U mode);

#ifdef __cplusplus
}
#endif

#endif
