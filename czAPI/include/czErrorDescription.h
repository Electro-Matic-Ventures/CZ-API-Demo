#ifndef __CZ_ERROR_CLASS_H__
#define __CZ_ERROR_CLASS_H__

#include "czType.h"

#ifdef __cplusplus
extern "C" {
#endif

//****************************************************************************************************************
//**** 函数名:czErrorDesc
//**** 功  能:获得指定代码的字符串,char字符串
//**** 参  数:
//****        errCode					- code
//**** 返回值:
//****                                  - error String
//****************************************************************************************************************	
CZAPI_DECLARE(char*) czErrorDesc(INT32U errCode);

#ifdef __cplusplus
}
#endif
#endif
