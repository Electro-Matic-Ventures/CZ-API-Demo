//****************************************************************************************************************
//****                                  LED产品JetFileII协议中的Blank函数模块 
//****			                              遵循CZ DEPT开发标准
//****                                          开发人:YangLei
//****                                      最后修改日期:2013-03-22
//****************************************************************************************************************
#ifndef __CZ_BLANKAPI_H__
#define __CZ_BLANKAPI_H__

#include "czType.h"
#ifdef __cplusplus
extern "C" {
#endif

//================================================================================================================
//====clear  functions
//================================================================================================================
CZAPI_DECLARE(INT32U) czBlackScreen();
CZAPI_DECLARE(INT32U) czEndBlackScreen();
CZAPI_DECLARE(INT32U) czResetSystem();
CZAPI_DECLARE(INT32U) czResetSystemCool();
CZAPI_DECLARE(INT32U) czPowerOnOff(INT8U OnOff);
CZAPI_DECLARE(INT32U) czGetPowerState(INT8U* MomState,INT8U* DriverState);
CZAPI_DECLARE(INT32U) czChangeBaudRate(INT8U BaudRate);
CZAPI_DECLARE(INT32U) czBrightAdjust(INT8U bright);
CZAPI_DECLARE(INT32U) czBrightAdjustEx(INT8U bright,INT8U port);
CZAPI_DECLARE(INT32U) czBrightAdjustSides(INT8U bright[8]);
CZAPI_DECLARE(INT32U) czSetEthCheck(INT8U ReSwitch,INT8U TimeInterval);
CZAPI_DECLARE(INT32U) czReadEthCheck(INT8U* ReSwitch,INT8U* TimeInterval);
CZAPI_DECLARE(INT32U) czSetBeacon(BEACON_ST* beacon);
CZAPI_DECLARE(INT32U) czGetBeacon(BEACON_ST* beacon);
CZAPI_DECLARE(INT32U) czCommitStatusRW(INT8U type, INT8U rwType,INT8U *procPrecent);
CZAPI_DECLARE(INT32U) czSwitchOnlineOffline(INT8U OnlineOffline);

CZAPI_DECLARE(INT32U) czResetSystemToDataFlash();
CZAPI_DECLARE(INT32U) czGeneratorSet(INT8U index,INT8U actionType,GENERATOR_ST* generator);
CZAPI_DECLARE(INT32U) czSetSignBeacon(BEACON_ST* beacon);
CZAPI_DECLARE(INT32U) czGetSignBeacon(BEACON_ST* beacon);
CZAPI_DECLARE(INT32U) czSetExternalEquipment(EXTEQUIPMENT_ST* EXTEquipment);
CZAPI_DECLARE(INT32U) czGetExternalEquipment(EXTEQUIPMENT_ST* EXTEquipment);
CZAPI_DECLARE(INT32U) czSetLCS(INT8U actionType);
CZAPI_DECLARE(INT32U) czGetLCS(INT8U* actionType);
CZAPI_DECLARE(INT32U) czPlayVoice(INT8U voiceSwitch,INT8U voiceEncode,INT8U* Data,INT8U DataLen);

#ifdef __cplusplus
}
#endif

#endif