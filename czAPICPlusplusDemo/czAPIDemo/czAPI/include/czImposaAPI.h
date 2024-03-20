//****************************************************************************************************************
//****                                  LED产品JetFileII协议中的imposa函数模块 
//****			                              遵循chainazone标准
//****                                          开发人:YangLei
//****                                      最后修改日期:2013-06-22
//****************************************************************************************************************
#ifndef __CZ_IMPOSAAPI_H__
#define __CZ_IMPOSAAPI_H__

#include "czType.h"

#ifdef __cplusplus
extern "C" {
#endif

CZAPI_DECLARE(INT32U) czImposaGetTileStat(INT16U tileAddr, INT32U *rtCode);
CZAPI_DECLARE(INT32U) czImposaGetResult(INT32U rtCode, INT8U *result, INT32U size, INT16U *resultCode);
CZAPI_DECLARE(INT32U) czImposaTileTest(INT16U tileAddr, INT8U testCmd, INT32U *rtCode);
CZAPI_DECLARE(INT32U) czImposaTilePxlLoad(void *pxl, INT32U bufSize, const char *fileName, INT32U TileType,
	                                         INT32U FPGAVer,INT32U TileW, INT32U TileH, INT32U ModW, INT32U ModH);
CZAPI_DECLARE(INT32U) czImposaTilePxlSave(void *pxl, INT32U bufSize, const char *fileName, INT32U TileType,
	                                        INT32U FPGAVer,INT32U TileW, INT32U TileH, INT32U ModW, INT32U ModH);

CZAPI_DECLARE(INT32U) czImposaWriteTileFile(const char *fileName, INT16U tileAddr, INT8U fileType);
CZAPI_DECLARE(INT32U) czImposaReadTileFile(const char *fileName, INT16U tileAddr, INT8U fileType);
CZAPI_DECLARE(INT32U) czImposaSetTileCmd( INT16U tileAddr, INT8U cmdType);

CZAPI_DECLARE(INT32U) czImposaFMCalOpt( INT32U Opt);
CZAPI_DECLARE(INT32U) czFlashPGMConnectCMD();

#ifdef __cplusplus
}
#endif
#endif
