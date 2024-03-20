//****************************************************************************************************************
//****                                  LED产品JetFileII协议中的Read函数模块 
//****			                              遵循CZ DEPT开发标准
//****                                          开发人:YangLei
//****                                      最后修改日期:2013-03-22
//****************************************************************************************************************
#ifndef __CZ_READAPI_H__
#define __CZ_READAPI_H__

#include "czType.h"
#include "czStructsDefine.h"

#ifdef __cplusplus
extern "C" {
#endif


//================================================================================================================
//====  czBrightInfoExt结构定义
//================================================================================================================
typedef struct
{	
	INT8U  BrightType;											//当前亮度类型 0=自动,1=手动,2=调度
	INT8U  BrightPrecent1;										//亮度百分比,有效值[1-100]，100表示最亮
	INT16U BrightSensorAD1;										//当前AD值
	INT8U  Rev;													//保留
	INT8U  BrightPrecent2;										//亮度百分比,有效值[1-100]，100表示最亮
	INT16U BrightSensorAD2;										//当前AD值
}czBrightInfoExt;

//================================================================================================================
//====  czDataFlashInfo结构定义
//================================================================================================================
typedef struct
{	
	INT16U PageSize;											//dataflash页大小
	INT16U ValidPageNumber;										//dataflash可用页数
	INT8U  Rev[8];												//保留8个字节,也被后期扩展
}czDataFlashInfo;

//================================================================================================================
//==== czReadStats statsType
//================================================================================================================
#define czReadStatsType_ALL				0						//请求所有的状态
#define czReadStatsType_INTEMP			1						//	1:温度(内)
#define czReadStatsType_OUTTEMP			2						//	2:温度(外)
#define czReadStatsType_INHUMI			3						//	3:湿度(内)
#define czReadStatsType_OUTHUMI			4						//	4:湿度(外)
#define czReadStatsType_TILT			5						//	5:倾斜角度
#define czReadStatsType_WINDIR			6						//	6:风向
#define czReadStatsType_WINSPEED		7						//	7:风速
#define czReadStatsType_BRI				8						//	8:亮度   
#define czReadStatsType_DOORST			9						//	9:开门状态
#define czReadStatsType_POWER			10						//10:电源状态
#define czReadStatsType_FVER			11						//11:firmware版本号
#define czReadStatsType_PXLNUM			12						//12:像点错误个数 


//================================================================================================================
//==== Read  functions
//================================================================================================================
CZAPI_DECLARE(INT32U) czReadSysFile(INT8U* systemFile,INT8U *PCPath);
CZAPI_DECLARE(INT32U) czReadFontFile (INT8U* fontName,INT8U* PCPath);
CZAPI_DECLARE(INT32U) czReadTextFile (INT8U Drive,INT8U* textName,INT8U* PCPath);
CZAPI_DECLARE(INT32U) czReadStringFile (INT8U Drive,INT8U* stringName,INT8U* PCPath);
CZAPI_DECLARE(INT32U) czReadPictureFile (INT8U Drive,INT8U* pictureName,INT8U* PCPath);
CZAPI_DECLARE(INT32U) czReadArrPicFile (INT8U Drive,INT8U* arrPicName,INT8U* PCPath);
CZAPI_DECLARE(INT32U) czReadSpecPathFile (INT8U* SpecialFile,INT8U* PCPath);
CZAPI_DECLARE(INT32U) czReadPlayLog (INT8U* PCPath);
CZAPI_DECLARE(INT32U) czReadSystemSet (SYSTEM_SET* systemSet);
CZAPI_DECLARE(INT32U) czReadCurrentState (CURRENT_STATE* State, void *ExtData, INT32U DataSize);
CZAPI_DECLARE(INT32U) czGetSNMAC (INT8U* SN,INT32U SNLen,INT8U* MAC,INT32U MACLen);
CZAPI_DECLARE(INT32U) czReadDefDisplayStyle(DEFAULT_SET* defaultSet);
CZAPI_DECLARE(INT32U) czReadSpecPathFileEx (INT8U* SpecialFile,INT8U* PCPath);
CZAPI_DECLARE(INT32U) czReadSystemInfo (INT8U* Info,INT32U BufLen,INT32U* size);
CZAPI_DECLARE(INT32U) czReadErrorLog (INT8U* Info,INT32U BufLen,INT32U* size);
CZAPI_DECLARE(INT32U) czReadDB(INT16U cmdType,INT8U* sql,INT8U* Field,INT32U FiledLen,
	                              INT8U* Record,INT32U RecordLen);
CZAPI_DECLARE(INT32U) czReadBrightInfo (INT8U* BrightType,INT8U* Percent,INT8U* ADValue);
CZAPI_DECLARE(INT32U) czReadBrightInfoExt(czBrightInfoExt *BrightInfo);
CZAPI_DECLARE(INT32U) czReadStats(INT8U statsType,INT8U* buf,INT32U bufsize);
CZAPI_DECLARE(INT32U) czReadPCBID(INT32U *ID);
CZAPI_DECLARE(INT32U) czReadPCBIDAndPort(INT32U *ID,INT8U *PortNum);
CZAPI_DECLARE(INT32U) czReadDataFlashInfo(czDataFlashInfo *DataFlashInfo);
CZAPI_DECLARE(INT32U) czReadDataFlashFile(INT8U* PCPath,INT32U ReadDataSize=0);
CZAPI_DECLARE(INT32U) czReadVirtualFile(INT8U* SpecialFile,INT8U* PCPath);

CZAPI_DECLARE(INT32U) czReadWarning(INT8U* pcpath);
CZAPI_DECLARE(INT32U) czReadWaringReport(INT32U (*cb)(ERROR_INFO_STRUCT *errorInfo));
CZAPI_DECLARE(INT32U) czReadPixelErrorReport(INT32U (*cb)(PixelInfo *PI));

CZAPI_DECLARE(INT32U) czReadCPUUpdateResult();
CZAPI_DECLARE(INT32U) czReadWarningLog(CZLog_File_Head* logFileHead,CZLogDataST* logDataEntry,INT8U maxEntryCount);

#ifdef __cplusplus
}
#endif

#endif