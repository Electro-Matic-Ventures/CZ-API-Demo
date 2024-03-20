#ifndef __CZ_ERROR_CLASS_H__
#define __CZ_ERROR_CLASS_H__

#include "czType.h"

#ifdef __cplusplus
extern "C" {
#endif

//****************************************************************************************************************
//**** ������:czErrorDesc
//**** ��  ��:���ָ��������ַ���,char�ַ���
//**** ��  ��:
//****        errCode					- code
//**** ����ֵ:
//****                                  - error String
//****************************************************************************************************************	
CZAPI_DECLARE(char*) czErrorDesc(INT32U errCode);

#ifdef __cplusplus
}
#endif
#endif
