//****************************************************************************************************************
//****                                  LED产品JetFileII协议中的逻辑函数模块 
//****			                              遵循chainazone标准
//****                                          开发人:YangLei
//****                                      最后修改日期:2013-03-22
//****************************************************************************************************************
#ifndef __CZ_BASELOGICAPI_H__
#define __CZ_BASELOGICAPI_H__

#include "czType.h"
#include "czStructsDefine.h"

#ifdef __cplusplus
extern "C" {
#endif

//================================================================================================================
//====　API初始
//================================================================================================================
CZAPI_DECLARE(char*) czAPIVersion();
CZAPI_DECLARE(INT32U) czInitAPI(_czinterface* czif);
CZAPI_DECLARE(INT32U) czFreeAPI(_czinterface* czif);

CZAPI_DECLARE(INT32U) czInitProperty();
CZAPI_DECLARE(INT32U) czGetProperty(void *buf, INT32U bufsize, INT32U type);

//================================================================================================================
//====　通用接口
//================================================================================================================
CZAPI_DECLARE(INT32U) czEnumSerial(char* serialList, INT32U size);


//================================================================================================================
//====　read PlayLog
//================================================================================================================
CZAPI_DECLARE(INT32U) czReadPlayLogExt(INT8U*pcpath,INT32U SignID,INT32U BoardType,
	                                     INT32S (*cb)(INT32U SID,playLog* Log));
CZAPI_DECLARE(INT32U) czReadTileInfo(INT8U*pcpath,INT32U SignID,INT32U BoardType,
	                                    INT32S (*cb)(INT32U ID,TileInfo *TI));
CZAPI_DECLARE(INT32U) czReadPixelInfo(INT8U*pcpath,INT32U SignID,INT32U BoardType,
	                                     INT32S (*cb)(INT32U ID,PixelInfo *PI));
CZAPI_DECLARE(INT32U) czReadSignLog(INT8U*pcpath,INT32U SignID,INT32U BoardType,
	                                   INT32S (*cb)(INT32U SignID,SignLog *SL));
CZAPI_DECLARE(INT32U) czReadTempLog(INT8U*pcpath,INT32U SignID,INT32U BoardType,
	                                   INT32S (*cb)(INT32U SignID,tempLog *TI));
CZAPI_DECLARE(INT32U) czReadStatusInfo(INT8U* WorkPathForSign,INT32U SignID,INT32U BoardType,
	                           INT32S (*cb)(INT32U ID,signState *SS, const INT8U* auxs, const INT8U *filename),
							   float GPSLong=0, float GPSLat=0, INT8U flashFlag=0);
CZAPI_DECLARE(INT32U) czReadRadarLog(INT8U *pcpath,INT32U SignID,INT32U BoardType,
	                                    INT32S (*cb)(INT32U ID, radarLog *RL));
CZAPI_DECLARE(INT32U) czReadEventLog(INT8U*pcpath,INT32U SignID,INT32U BoardType,
	                                 INT32S (*cb)(INT32U ID,EventLogInfo *TI));
CZAPI_DECLARE(INT32U) czReadTJRadarLog(INT8U *na,INT32U SignID,INT32U BoardType,
	                                      INT32S (*cb)(INT32U ID, TJRadarLog *RL));
CZAPI_DECLARE(INT32U) czReadSignWaringLog(INT8U* pcpath,INT8U* name, INT32S (*cb)(WaringLog *Log));
CZAPI_DECLARE(INT32U) czUpdate3Info(BAThirdInfo *info, INT8U* pcpath);

CZAPI_DECLARE(INT32U) czTubeSet(INT8U Cmd, INT8U *Arg, INT32U ArgLen);

CZAPI_DECLARE(INT32U) czBmp2Nmg(INT8U *bmpFullName, INT8U *nmgFullName, INT16U stay_time_sec, INT8U mode);

//================================================================================================================
//====　interface.
//================================================================================================================
CZAPI_DECLARE(INT32U) czExecFileCMD(INT8U* filecmd);
CZAPI_DECLARE(INT32U) czLstLongFolderCallBack( INT8U* signpath, 
	                                  INT32S (*cb)(DIRECTORY_ENTRY_STRUCTEx *dirEntry, void *cbObj), void *cbObj);
CZAPI_DECLARE(INT32U) czRWFile(const INT8U* pcpath, const INT8U* signpath, INT32U type);
CZAPI_DECLARE(INT32U) czCurrentMsg2Gif(INT8U* signpath,INT8U* pcpath);
CZAPI_DECLARE(INT32U) czMakeSignPath(char* pc_file_path, char* sign_path,  INT32U sign_path_size, 
	                                  INT8U drive, INT8U *folder, INT8U filename[12]);

CZAPI_DECLARE(INT32U) czReadBatInfoLog(INT8U *pcpath,INT32U SignID,INT32U BoardType,INT8U LogType,
	INT32S (*cb)(INT32U ID, batinfoLog *BL));
CZAPI_DECLARE(INT32U)  czReadCommunicationSet(COMMUNICATICON_ST* commSet);
CZAPI_DECLARE(INT32U)  czWriteCommunicationSet(COMMUNICATICON_ST* commSet);

CZAPI_DECLARE(INT32U)  czTestPattern();			//test  测试正则表达式
CZAPI_DECLARE(INT16U)  czTM_DecodeDosTime(INT32U DosTime,INT8U *dateTimeBuf, INT8U bufSize);

#ifdef __cplusplus
}
#endif
#endif

