
/**  
******************************************************************************************************************
**** @file czAux.h
****  
**** @brief   协处理模块(Aux Module)
**** @details Aux API.
**** @author  Lei	
**** @version 1.0 
**** @date    2016-6-13
**** @todo 
**** @see      
**** @addtogroup CZAUX 协处理模块(AUX Module)
**** @{
******************************************************************************************************************
*/ 

#ifndef __CZAUX_MODULE__  
#define __CZAUX_MODULE__

#include "czType.h"
#include <stdio.h>

#ifdef __cplusplus
extern "C" {
#endif


CZAPI_DECLARE(INT16U) czChkSum(INT8U *buf, INT32U begin, INT32U end,INT32U chktype);
CZAPI_DECLARE(INT32U) czReadFileLine(FILE *fp, char *buf, INT32U bufSize);
#ifdef __cplusplus
}
#endif
#endif


