//****************************************************************************************************************
//****                                                 宏定义模块 
//****                                           遵循QS DEPT 开发标准
//****                                              开发人:YangLei
//****                                          最后修改日期:2009-06-20
//****************************************************************************************************************
#ifndef __DEFINE_H__
#define __DEFINE_H__
       
typedef unsigned char  INT8U;          							/* Unsigned  8 bit quantity 					*/
typedef signed   char  INT8S;          							/* Signed    8 bit quantity 					*/
typedef unsigned short INT16U;         							/* Unsigned 16 bit quantity 					*/
typedef signed   short INT16S;         							/* Signed   16 bit quantity 					*/
typedef unsigned int   INT32U;         							/* Unsigned 32 bit quantity 					*/
typedef signed   int   INT32S;         							/* Signed   32 bit quantity 					*/
typedef unsigned long long  INT64U;


#if defined(CZ_PLATFORM_OS_LINUX)
#define CZAPI_DECLARE(type)          extern "C" type
#else 
#if defined(JETFILEII_EXPORTS)
#define CZAPI_DECLARE(type)          extern "C" __declspec(dllexport) type __stdcall
#else
#define CZAPI_DECLARE(type)          extern "C" type __stdcall
#endif
#endif

#define CZ_INTERFACE_TLS				0
#define CZ_PROPERTY_TLS					1
#define CZ_PLAYLIST_TLS					2

#endif

