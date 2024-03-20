//****************************************************************************************************************
//****                                  LED产品JetFileII协议中的OnLineTicker函数模块 
//****			                              遵循chainazone标准
//****                                          开发人:YangLei
//****                                      最后修改日期:2013-03-22
//****************************************************************************************************************
#ifndef __CZ_ONLINETICKERAPI_H__
#define __CZ_ONLINETICKERAPI_H__

#include "czType.h"

#ifdef __cplusplus
extern "C" {
#endif

CZAPI_DECLARE(INT32U) czTickerStart(INT8U dir,INT8U speed, INT8U dataFormat);
CZAPI_DECLARE(INT32U) czTickerStop();
CZAPI_DECLARE(INT32U) czGetBufferStatus(INT16U* statusCode);
CZAPI_DECLARE(INT32U) czUploadBuffer(INT8U* Data, INT32U dataLen);


#ifdef __cplusplus
}
#endif
#endif
