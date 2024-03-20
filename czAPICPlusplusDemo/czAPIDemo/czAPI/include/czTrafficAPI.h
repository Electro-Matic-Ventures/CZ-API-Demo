//****************************************************************************************************************
//****                                  LED产品JetFileII协议中的Traffic函数模块 
//****			                              遵循chainazone标准
//****                                          开发人:YangLei
//****                                      最后修改日期:2013-03-22
//****************************************************************************************************************
#ifndef __CZ_TRAFFICAPI_H__
#define __CZ_TRAFFICAPI_H__

#include "czType.h"

#ifdef __cplusplus
extern "C" {
#endif

//================================================================================================================
//====　traffic base interface.
//================================================================================================================
CZAPI_DECLARE(INT32U) czReadTCMonitor(INT32U type, INT8U* Field,INT32U *FiledLen);
CZAPI_DECLARE(INT32U) czReadTCStatus(INT8U* Field,INT32U *FiledLen);
CZAPI_DECLARE(INT32U) czTCManual(INT8U ManualType);
CZAPI_DECLARE(INT32U) czTCJKBLightTest(INT8U* LightStatus, INT8U Len);
CZAPI_DECLARE(INT32U) czTCJKCLightTest(INT8U* LightStatus, INT8U MotorLen, INT8U ManLen);
CZAPI_DECLARE(INT32U) czTCGetRealStatus(INT8U* Status, INT32U maxLen, INT8U cross);
CZAPI_DECLARE(INT32U) czReadTrafficTime(INT16U *Y,INT8U *M,INT8U *D,INT8U *H,
	                                       INT8U *MM,INT8U *S,INT8U *W,INT8U *TZ);
CZAPI_DECLARE(INT32U) czAjustTrafficTime(INT16U Y,INT8U M,INT8U D,INT8U H,INT8U MM,INT8U S,INT8U W,INT8U TZ);

//================================================================================================================
//====　traffic logic interface.
//================================================================================================================
CZAPI_DECLARE(INT32U) czReadTrafficStatus(INT8U* PCPath);
CZAPI_DECLARE(INT32U) czReadTrafficMonitor(INT8U* PCPath);
CZAPI_DECLARE(INT32U) czReadTrafficErrLog(INT8U* PCPath,INT8U* name, INT32S (*cb)(WaringLog *Log));
CZAPI_DECLARE(INT32U) czReadTrafficTempLog(INT8U* PCPath,INT8U* name, INT32S (*cb)(TCTempLog *Log));
CZAPI_DECLARE(INT32U) czReadTrafficRealStatus(INT8U* PCPath);
CZAPI_DECLARE(INT32U) czTrafficTempPhaseRun(INT8U* phasepath, INT32U runmins);
CZAPI_DECLARE(INT32U) czTrafficRFlow(INT8U* arg, INT8U* filename);

#ifdef __cplusplus
}
#endif

#endif