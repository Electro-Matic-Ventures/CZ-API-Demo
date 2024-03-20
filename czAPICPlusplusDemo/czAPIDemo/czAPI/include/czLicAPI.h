//****************************************************************************************************************
//****                                  LED产品JetFileII协议中的FTPHTTP开关函数模块 
//****			                              遵循chainazone标准
//****                                          开发人:YangLei
//****                                      最后修改日期:2013-03-22
//****************************************************************************************************************
#ifndef __CZ_LICAPI_H__
#define __CZ_LICAPI_H__

#include "czType.h"

#ifdef __cplusplus
extern "C" {
#endif

CZAPI_DECLARE(INT32U) czLicGetID(INT8U *IDData, INT32U dataSize);
CZAPI_DECLARE(INT32U) czLicSendData(INT8U *LicData, INT32U dataSize);

#ifdef __cplusplus
}
#endif
#endif