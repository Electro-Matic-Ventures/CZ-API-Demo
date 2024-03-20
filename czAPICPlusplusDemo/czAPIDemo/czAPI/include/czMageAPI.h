//****************************************************************************************************************
//****                                  LED产品JetFileII协议中的Mage函数模块 
//****			                              遵循chainazone标准
//****                                          开发人:YangLei
//****                                      最后修改日期:2013-03-22
//****************************************************************************************************************
#ifndef __CZ_MAGEAPI_H__
#define __CZ_MAGEAPI_H__

#include "czType.h"
#ifdef __cplusplus
extern "C" {
#endif

//================================================================================================================
//=== mager箱体操作命令定义
//================================================================================================================
#define OPT_TILE_RESET					0x00 					//箱体复位
#define OPT_TILE_SET_GAMMA				0x01 					//设置Gamma曲线
#define OPT_TILE_START_PXLCHK			0x02 					//启动像点检测
#define OPT_TILE_EN_BRIGHT				0x03 					//启动逐点亮度调节功能
#define OPT_TILE_DIS_BRIGHT				0x04 					//禁止逐点亮度调节功能
#define OPT_TILE_BRIGHT_TO_FACTORY		0x05 					//把亮度数据写进出厂区
#define OPT_TILE_BRIGHT_TO_APPLY		0x06 					//把亮度数据写进应用区
#define OPT_TILE_BRIGHT_RESTORE			0x07 					//恢复出厂时的亮度数据
#define OPT_TILE_CPU_UPDATE				0x08 					//检查CPU，如果合法，就进行升级
#define OPT_TILE_WRITE_SN				0x09 					//写SN
#define OPT_TILE_INIT_BRI				0x0A 					//把箱体里所有的亮度调节值设置为指定的值　
#define OPT_TILE_ROTATE					0x0B 					//旋转
#define OPT_TILE_EN_BRI_ONLY			0x0C 					//启动逐点亮度调节功能(只有亮度)
#define OPT_TILE_INDICATOR_BRI			0x0D 					//调节箱体提示灯亮度
#define OPT_TILE_BUTTON_EN				0x0E 					//设置箱体按钮开关(是否能按)]

#define OPT_TILE_PHY_IN					0x0F					//进入PHY传亮度模式
#define OPT_TILE_PHY_OUT				0x10					//退出PHY传亮度模式
#define OPT_TILE_PHY_CHK				0x11					//让箱体把PHY亮度写入flash并计算模块亮度的CRC
#define OPT_TILE_REV					0x12					//占位，不再使用
#define OPT_TILE_CH_NO					0x13					//设置当前使用色度编号
#define OPT_TILE_CH2MOD					0x14					//把色度坐标写入到模块
#define OPT_TILE_CHKEPROM				0x15					//重新检查EPROM状态
#define OPT_TILE_CALGAP					0x16					//重新计算箱体的缝隙
#define OPT_TILE_SAVEPIC				0x17					//保存当前画面，用于无信号时显示
#define OPT_TILE_LOSTMODE				0x18					//信号中断时，屏体显示状态
#define OPT_TILE_DF2MOD					0x19					//把DF中模块信息写入Eeprom


CZAPI_DECLARE(INT32U) czMageTileTest(INT8U testType, INT8U port,INT16U tileAddr);
CZAPI_DECLARE(INT32U) czMageGetResult(INT32U rtCode, INT8U *result, INT32U size);
CZAPI_DECLARE(INT32U) czMageTileCMD(INT8U cmdType, INT8U port, INT16U tileAddr, INT8U* arg, INT32U argLen);
CZAPI_DECLARE(INT32U) czMageLDUCMD(INT8U cmdType, INT8U port);

CZAPI_DECLARE(INT32U) czMageWriteTileFile(INT8U *pcFile, INT8U fileType, INT8U port,INT16U tileAddr,
	INT32U *errRetryTime);  
CZAPI_DECLARE(INT32U) czMageReadTileFile(INT8U *pcFile, INT8U fileType, INT8U port,
	INT16U tileAddr, INT32U readLDUFileOnly,INT32U *errRetryTime);  
CZAPI_DECLARE(INT32U) czMageWriteTileFileExt(INT8U *pcFile, INT8U fileType, INT8U port,INT16U tileAddr,
	INT8U modeAddr,INT32U *errRetryTime);  
CZAPI_DECLARE(INT32U) czMageReadTileFileExt(INT8U *pcFile, INT8U fileType, INT8U port,INT16U tileAddr, 
	INT8U modeAddr,INT32U readLDUFileOnly,INT32U *errRetryTime);  

CZAPI_DECLARE(INT32U) czMageWritePxlCal(INT8U *pcFile, INT8U port,INT16U tileAddr,
	INT8U saveTo, INT32U *errRetryTime, void *pxlTarget);
CZAPI_DECLARE(INT32U) czMagePicCalShow(INT16U X, INT16U Y, INT16U W, INT16U H);

CZAPI_DECLARE(INT32U) czMageSyncBriMode(INT16U modeType);
CZAPI_DECLARE(INT32U) czMageWritePxlCalBurn(INT8U *pcFile, INT8U port,INT16U tileAddr,
	INT8U saveTo, INT32U *errRetryTime, void *pxlTarget, INT32U *returnCode);


CZAPI_DECLARE(INT32U) czMageTileCMDTimeout(INT8U cmdType, INT8U port, INT16U tileAddr, INT8U* arg, INT32U argLen, INT32U cmdTimeout);
CZAPI_DECLARE(INT32U) czMageReadTileFileTimeout(INT8U *pcFile, INT8U fileType, INT8U port,
	INT16U tileAddr, INT32U readLDUFileOnly,INT32U *errRetryTime, INT32U cmdTimeout);  

CZAPI_DECLARE(INT32U) czDirectTileTest(INT8U testType, INT8U port,INT16U tileAddr);
CZAPI_DECLARE(INT32U) czDirectTileCMD(INT8U cmdType, INT8U port, INT16U tileAddr, INT8U* arg, INT32U argLen);
CZAPI_DECLARE(INT32U) czDirectTileReadFileEx(INT8U *filePath, INT8U fileType, INT8U port,INT16U tileAddr, INT8U modAddr);
CZAPI_DECLARE(INT32U) czDirectTileWriteFileEx(INT8U *filePath, INT8U fileType, INT8U port,INT16U tileAddr, INT8U modeAddr);


#ifdef __cplusplus
}
#endif
#endif