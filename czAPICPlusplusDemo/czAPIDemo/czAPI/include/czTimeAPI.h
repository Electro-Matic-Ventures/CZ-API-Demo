//****************************************************************************************************************
//****                                  LED产品JetFileII协议中的Time函数模块 
//****			                              遵循chainazone标准
//****                                          开发人:YangLei
//****                                      最后修改日期:2013-03-22
//****************************************************************************************************************
#ifndef __CZ_TIMEAPI_H__
#define __CZ_TIMEAPI_H__

#include "czType.h"

#ifdef __cplusplus
extern "C" {
#endif

//================================================================================================================
//====time  functions
//================================================================================================================
CZAPI_DECLARE(INT32U) czReadLEDTime(INT16U *Y, INT8U *M, INT8U *D, INT8U *H,INT8U *MM, 
	                                   INT8U *S,INT8U *W,INT8U *TZ);
CZAPI_DECLARE(INT32U) czAjustLEDTimeEx(INT16U Y, INT8U M, INT8U D, INT8U H,INT8U MM, INT8U S,INT8U W,INT8U TZ);
CZAPI_DECLARE(INT32U) czSendTempHumi(INT8U Humidity, INT8S Temperature);
CZAPI_DECLARE(INT32U) czWriteSpeedLimit(INT16U limitSpeed,INT16U limitOffset);



#ifdef __cplusplus
}
#endif
#endif

