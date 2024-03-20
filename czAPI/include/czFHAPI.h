//****************************************************************************************************************
//****                                  LED产品JetFileII协议中的FTPHTTP开关函数模块 
//****			                              遵循CZ DEPT开发标准
//****                                          开发人:YangLei
//****                                      最后修改日期:2013-03-22
//****************************************************************************************************************
#ifndef __CZ_FHAPI_H__
#define __CZ_FHAPI_H__

#include "czType.h"

#ifdef __cplusplus
extern "C" {
#endif

CZAPI_DECLARE(INT32U) czSetFH(INT8U FtpSwitch, INT8U HttpSwitch);
CZAPI_DECLARE(INT32U) czGetFH(INT8U *FtpSwitch, INT8U *HttpSwitch);


#ifdef __cplusplus
}
#endif
#endif
