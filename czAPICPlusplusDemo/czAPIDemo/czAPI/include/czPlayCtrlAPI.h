//****************************************************************************************************************
//****                                  LED产品JetFileII协议中的PlayCtrl函数模块 
//****			                              遵循CZ DEPT开发标准
//****                                          开发人:YangLei
//****                                      最后修改日期:2013-03-22
//****************************************************************************************************************
#ifndef __CZ_PLAYCTRLAPI_H__
#define __CZ_PLAYCTRLAPI_H__

#include "czType.h"
#ifdef __cplusplus
extern "C" {
#endif

//================================================================================================================
//====PlayControl  functions
//================================================================================================================
CZAPI_DECLARE(INT32U) czReplayList();
CZAPI_DECLARE(INT32U) czReplayCurrFile();
CZAPI_DECLARE(INT32U) czPlayPause();
CZAPI_DECLARE(INT32U) czPlayContinue();
CZAPI_DECLARE(INT32U) czPlayNext();
CZAPI_DECLARE(INT32U) czPlayPriority (INT8U Drive, INT8U Type,INT8U* FileName);
CZAPI_DECLARE(INT32U) czGetPlayingFileName(INT8U* FileName,INT32U NameLen);
CZAPI_DECLARE(INT32U) czGetNextPlayFileName(INT8U* FileName, INT32U NameLen);
CZAPI_DECLARE(INT32U) czPlayPrevious();
CZAPI_DECLARE(INT32U) czPlayForword();
CZAPI_DECLARE(INT32U) czPlayBack();
CZAPI_DECLARE(INT32U) czPlayNextFrame();
CZAPI_DECLARE(INT32U) czSoundCtrl(INT8U SoundSwitch,INT8U mode,INT8U time);
CZAPI_DECLARE(INT32U) czBeginTiming(INT8U day, INT8U hour,INT8U min,INT8U sec);
CZAPI_DECLARE(INT32U) czStopTiming();
CZAPI_DECLARE(INT32U) czPauseTiming();
CZAPI_DECLARE(INT32U) czContinueTiming();
CZAPI_DECLARE(INT32U) czReadTJRadarLog2File(INT8U *pcpath);
CZAPI_DECLARE(INT32U) czClearTJRadarLog();

CZAPI_DECLARE(INT32U) czReadCurScreentshot(INT8U* pcpath);
CZAPI_DECLARE(INT32U) czPlaySoundFile(SoundST soundST,INT8U* soundpath);
CZAPI_DECLARE(INT32U) czPlaySoundFile4j(SoundST * soundST, INT8U * soundpath);
CZAPI_DECLARE(INT32U) czAdjustVolume(INT8U soundVolume);
CZAPI_DECLARE(INT32U) czReadCurVolume(INT8U* soundVolume);
CZAPI_DECLARE(INT32U) czReadDefaultScreenSet(DefScreenSetST* defScreenSet);
CZAPI_DECLARE(INT32U) czWriteDefaultScreenSet(DefScreenSetST* defScreenSet);
CZAPI_DECLARE(INT32U) czPlaySpePlaylist(INT8U playListIndex);
CZAPI_DECLARE(INT32U) czReadSpePlayListIndex(INT8U* playListIndex);

#ifdef __cplusplus
}
#endif

#endif