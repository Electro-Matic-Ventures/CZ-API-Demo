//****************************************************************************************************************
//****                                  LED产品JetFileII协议中的OffLineTicker函数模块 
//****			                              遵循CZ DEPT开发标准
//****                                          开发人:YangLei
//****                                      最后修改日期:2013-03-22
//****************************************************************************************************************
#ifndef __CZ_OFFLINETICKERAPI_H__
#define __CZ_OFFLINETICKERAPI_H__

#include "czType.h"
#ifdef __cplusplus
extern "C" {
#endif

CZAPI_DECLARE(INT32U) czOffLineTickerStart(INT8U mode, INT8U dir,INT8U speed, INT8U sec);
CZAPI_DECLARE(INT32U) czOffLineTickerStop();
#ifdef __cplusplus
}
#endif
#endif