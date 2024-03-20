//****************************************************************************************************************
//****                                  LED产品JetFileII协议中的Login函数模块 
//****			                              遵循chainazone标准
//****                                          开发人:YangLei
//****                                      最后修改日期:2013-03-22
//****************************************************************************************************************
#ifndef __CZ_LOGINAPI_H__
#define __CZ_LOGINAPI_H__
#include "czType.h"

#ifdef __cplusplus
extern "C" {
#endif

CZAPI_DECLARE(INT32U) czLogin (INT8U* userName, INT8U* password);
CZAPI_DECLARE(INT32U) czLogout();
CZAPI_DECLARE(INT32U) czChangePSW(INT8U* userName, INT8U* password, INT8U* newPassword);
CZAPI_DECLARE(INT32U) czReqCreateDynamicPsw();
CZAPI_DECLARE(INT32U) czVerifyDynamicPsw(INT8U* dynamicPsw);

CZAPI_DECLARE(INT32U) czGetAPIServerTable(INT32U* Num,CZAPISignST* apiSignEntry,INT32U maxEntryCount);

#ifdef __cplusplus
}
#endif
#endif