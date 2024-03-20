//****************************************************************************************************************
//****                                  LED产品JetFileII协议中的Test函数模块 
//****			                              遵循CZ DEPT开发标准
//****                                          开发人:YangLei
//****                                      最后修改日期:2015-10-13(改：shunming)
//****************************************************************************************************************
#ifndef __CZ_TESTAPI_H__
#define __CZ_TESTAPI_H__

#include "czType.h"

#ifdef __cplusplus
extern "C" {
#endif

//================================================================================================================
//====Test  functions
//================================================================================================================
CZAPI_DECLARE(INT32U) czConnectTest(INT16U* FirmwareVer, INT16U* FPGAVer,  INT32U* IPAddress);
CZAPI_DECLARE(INT32U) czPatternTest(INT32U PatternMode);
CZAPI_DECLARE(INT32U) czStopTest();
CZAPI_DECLARE(INT32U) czCrayTest(GRAY_TEST_PARAM*  grayParam);
CZAPI_DECLARE(INT32U) czColorTest(INT8U red, INT8U green, INT8U blue);
CZAPI_DECLARE(INT32U) czAreaTest(AREA_STRUCT areaStruct);
CZAPI_DECLARE(INT32U) czLocationTest(INT16U W,INT16U H,INT16U MODW,INT16U MODH,INT16U *Lines,
	                                    INT32U lineNum,INT16U type);
CZAPI_DECLARE(INT32U) czDebugInfoSetting(INT32U totalDebug);
CZAPI_DECLARE(INT32U) czStabilityTest(INT8U* Buf,INT8U BufLen, INT16U CurPackID);
CZAPI_DECLARE(INT32U) czCustomTest(INT8U mCMD,INT8U sCMD,INT8U* Buf,INT8U BufLen,INT8U* Data,INT8U DataLen, bool crcSuport, 
								   INT8U* mSendBuf, INT8U* mSendBufLen, INT8U* mRecvBuf, INT8U* mRecvBufLen);

#ifdef __cplusplus
}
#endif

#endif