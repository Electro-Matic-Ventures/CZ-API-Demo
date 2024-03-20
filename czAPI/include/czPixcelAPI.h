//****************************************************************************************************************
//****                                  LED产品JetFileII协议中的PixcelCheck函数模块 
//****			                              遵循CZ DEPT开发标准
//****                                          开发人:YangLei
//****                                      最后修改日期:2013-03-22
//****************************************************************************************************************
#ifndef __CZ_PIXCELAPI_H__
#define __CZ_PIXCELAPI_H__

#include "czType.h"
#ifdef __cplusplus
extern "C" {
#endif

CZAPI_DECLARE(INT32U) czBeginPixCheck();
CZAPI_DECLARE(INT32U) czReadPixResult(INT8U* PCPath);
CZAPI_DECLARE(INT32U) czReadSignalResult(INT8U* PCPath);
CZAPI_DECLARE(INT32U) czPixProgress(INT8U* Progress);
CZAPI_DECLARE(INT32U) czPxlChk(INT8U* PCPxlPath, INT8U* PCSignalPath);

#ifdef __cplusplus
}
#endif
#endif