//****************************************************************************************************************
//****                                  LED产品JetFileII协议中的Write函数模块 
//****			                              遵循chainazone标准
//****                                          开发人:YangLei
//****                                      最后修改日期:2013-03-22
//****************************************************************************************************************
#ifndef __CZ_WRITEAPI_H__
#define __CZ_WRITEAPI_H__

#include "czType.h"

#ifdef __cplusplus
extern "C" {
#endif

//================================================================================================================
//====Write  functions
//================================================================================================================
CZAPI_DECLARE(INT32U) czWriteSystemFile (INT8U* FileName,INT8U* PCPath);
CZAPI_DECLARE(INT32U) czWriteFontFile(INT8U* FontName,INT8U* PCPath);
CZAPI_DECLARE(INT32U) czWriteTextFile(INT8U Drive,INT8U* TextName,INT8U* PCPath);
CZAPI_DECLARE(INT32U) czWriteStringFile(INT8U Drive,INT8U* StringName,INT8U* PCPath);
CZAPI_DECLARE(INT32U) czWritePictureFile(INT8U Drive,INT8U* PictureName,INT8U* PCPath);
CZAPI_DECLARE(INT32U) czWriteArrPicFile(INT8U Drive,INT8U* ArrPicName,INT8U* PCPath);
CZAPI_DECLARE(INT32U) czWriteSpecFile(INT8U* SpecialFile,INT8U* PCPath);
CZAPI_DECLARE(INT32U) czWriteUrgentMsg(INT8U StayTime, INT8U SoundSwitch,INT8U* TextMsg,INT32U MsgLen);
CZAPI_DECLARE(INT32U) czWriteBrightCtrlBlock(BRIGHT_CTRL* brightCtrl);
CZAPI_DECLARE(INT32U) czWriteSNMAC(INT8U* SN,INT32U SNLen, INT8U* MAC,INT32U MACLen);
CZAPI_DECLARE(INT32U) czWriteDefDisplayStyle(DEFAULT_SET* defaultSet);
CZAPI_DECLARE(INT32U) czWriteSpecFileEx(INT8U* SpecialFile,INT8U* PCPath);
CZAPI_DECLARE(INT32U) czWriteFileOptimize(INT8U* SpecialFile,INT8U* PCPath);
CZAPI_DECLARE(INT32U) czWriteCRCForFile(INT8U* FileName,INT32U FileSize,INT16U FileCRC);
CZAPI_DECLARE(INT32U) czWriteDataFlashFile(INT8U* PCPath,INT32U SendDataSize=0);

CZAPI_DECLARE(INT32U) czLCSetUpdateStatus(INT8U GG,INT8U UU,INT8U status);
CZAPI_DECLARE(INT32U) czWriteAbsoluteAddress(INT8U GG,INT8U UU,INT8U* FileName);

#ifdef __cplusplus
}
#endif


#endif
