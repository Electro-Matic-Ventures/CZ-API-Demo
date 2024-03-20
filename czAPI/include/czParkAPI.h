//****************************************************************************************************************
//****                                  LED��ƷJetFileIIЭ���е�Park����ģ�� 
//****			                              ��ѭCZ DEPT������׼
//****                                        ������:fm
//****                                      ����޸�����:2018-08-28
//****************************************************************************************************************
#ifndef __CZ_ParkAPI_H__
#define __CZ_ParkAPI_H__
#include "czType.h"

#ifdef __cplusplus
extern "C" {
#endif

	CZAPI_DECLARE(INT32U) czDivideZone(INT8U pageID, INT8U flag,ZoneSetHead zoneSetHead,ZoneSet* zoneSetArrs);
	CZAPI_DECLARE(INT32U) czGetZone(ZoneSetHead* zoneSetHead,ZoneSet* zoneSetEntry,INT8U maxEntryCount,INT8U pageID=1);
	CZAPI_DECLARE(INT32U) czSetDisplay(INT8U pageID, INT8U zoneNum, INT8U setMode, ZoneDisplaySet parameter, INT8U* content);
	CZAPI_DECLARE(INT32U) czSetContentDisplay(INT8U pageID, INT8U zoneNum, ZoneDisplayContentSet parameter, INT8U* content);

	//�ṹ����������ô�ֵ
	CZAPI_DECLARE(INT32U) czDivideZone4j(INT8U pageID, INT8U flag, ZoneSetHead *zoneSetHead, ZoneSet** zoneSetArrs);
	CZAPI_DECLARE(INT32U) czGetZone4j(ZoneSetHead* zoneSetHead, ZoneSet** zoneSetEntry, INT8U maxEntryCount, INT8U pageID = 1);
	CZAPI_DECLARE(INT32U) czSetDisplay4j(INT8U pageID, INT8U zoneNum, INT8U setMode, ZoneDisplaySet* parameter, INT8U* content);
	CZAPI_DECLARE(INT32U) czSetContentDisplay4j(INT8U pageID, INT8U zoneNum, ZoneDisplayContentSet* parameter, INT8U* content);

	CZAPI_DECLARE(INT32U) czSetEnableMulitZone(INT8U enabled);
	CZAPI_DECLARE(INT32U) czSetPageCount(INT8U pageCount);
	CZAPI_DECLARE(INT32U) czDivideSpeZone(INT8U pageID, SpeZoneSet speZoneSet, SpeZoneXY* speZoneXYArrs);
	CZAPI_DECLARE(INT32U) czGetMulitZoneSetting(INT8U* enabled, INT8U* pageCount);

#ifdef __cplusplus
}
#endif
#endif