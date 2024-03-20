//****************************************************************************************************************
//****                                  LED产品JetFileII协议中的czPlayList函数模块 
//****			                              遵循CZ DEPT开发标准
//****                                        开发人:YangLei&PLY
//****                                      最后修改日期:2015-04-15
//****************************************************************************************************************
#ifndef __CZ_PLAYLISTAPI_H__
#define __CZ_PLAYLISTAPI_H__

#include "czType.h"
#include "czAPICfg.h"
#include "czStructsDefine.h"

#ifdef __cplusplus
extern "C" {
#endif
    
#if CZCFG_HAS_PLAYLIST_MD == 1

//================================================================================================================
//====　playlist interface.
//================================================================================================================
CZAPI_DECLARE(INT32U) czPLInit(INT8U* workPath, INT8U *playListName);
CZAPI_DECLARE(INT32U) czPLReadFromLED(INT8U isReadChangedFiles);
CZAPI_DECLARE(INT32U) czPLSendToLED(INT8U isSendChangedFiles);
CZAPI_DECLARE(INT32U) czPLSave();
CZAPI_DECLARE(INT32U) czLoadPLSFromPC(char* fileName);
CZAPI_DECLARE(INT32U) czLoadSYSFromLED(char* fileName);
CZAPI_DECLARE(INT32U) czLoadSYSFromXML(char* fileName);


CZAPI_DECLARE(INT32U) czPLAddGroup(INT8U *path, INT16U index, INT8U *groupName, INT8U playType);
CZAPI_DECLARE(INT32U) czPLModifyGroup(INT8U *path, INT8U *groupName, INT8U playType);

CZAPI_DECLARE(INT32U) czPLAddFile(INT8U *path, INT16U index, CZPLAYLIST_FILE_INFO *fileInfo);
CZAPI_DECLARE(INT32U) czPLModifyFile(INT8U *path, CZPLAYLIST_FILE_INFO *fileInfo);
CZAPI_DECLARE(INT32U) czPLGetFile(INT8U *path, CZPLAYLIST_FILE_INFO *fileInfo);

CZAPI_DECLARE(INT32U) czPLMoveItem(INT8U *path, INT16U index, INT16U direction);
CZAPI_DECLARE(INT32U) czPLDelItem(INT8U *path,INT16U startIndex,INT16U endIndex);		
CZAPI_DECLARE(INT32U) czPLGetItems(INT8U *path, INT16U *count, CZPLAYLIST_ITEM* ItemInfos);

CZAPI_DECLARE(INT32U) czPLSpeSendToLED(INT8U playListIndex, INT8U isSendChangedFiles);

#endif

#ifdef __cplusplus
}
#endif
#endif

