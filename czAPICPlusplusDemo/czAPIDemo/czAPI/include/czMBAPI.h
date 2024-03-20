//****************************************************************************************************************
//****                                   LED产品Modbus协议中的函数模块 
//****			                              遵循chainazone标准
//****                                          开发人:YD、shunming
//****                                      最后修改日期:2015-3-31
//****************************************************************************************************************
#ifndef __CZ_MBAPI_H__
#define __CZ_MBAPI_H__

#include "czType.h"
#ifdef __cplusplus
extern "C" {
#endif

//================================================================================================================
//====  modbus用到的定义(开始)
//================================================================================================================
#define CZMB_LC_REG_MASTERIP0				0					//MASTER IP[0]地址
#define CZMB_LC_REG_MASTERIP1				1					//MASTER IP[1]地址
#define CZMB_LC_REG_MASTERIP2				2					//MASTER IP[2]地址
#define CZMB_LC_REG_MASTERIP3				3					//MASTER IP[3]地址
#define CZMB_LC_REG_SLAVEIP0				4					//SLAVE IP[0]地址
#define CZMB_LC_REG_SLAVEIP1				5					//SLAVE IP[1]地址
#define CZMB_LC_REG_SLAVEIP2				6					//SLAVE IP[2]地址
#define CZMB_LC_REG_SLAVEIP3				7					//SLAVE IP[3]地址
#define CZMB_LC_REG_DEVNUM					8					//DEVnum 预设设备数量
#define CZMB_LC_REG_ONLINEDEV				9					//OnLineDEVnum 在线设备数量
#define CZMB_LC_REG_ID						10					//Local controller modbus ID
#define CZMB_LC_REG_ALCSWDT					11					//ALCS中心通信看门狗时间（ALCSWDT）
#define CZMB_LC_REG_MLCSWDT					12					//MLCS中心通信看门狗时间（MLCSWDT）
#define CZMB_LC_REG_VSLSWDT					13					//VSLC中心通信看门狗时间（VSLSWDT）
#define CZMB_LC_REG_CTRLMODE				14					//控制模式寄存器 CTRLMODE
#define CZMB_LC_REG_YSYNC					0x0f				//黄灯同步信号
#define CZMB_LC_REG_SYSTEM					0x10				//系统控制
#define CZMB_LC_REG_COMSTA					0x11				//通信状态
#define CZMB_LC_REG_PASSWORD				0x12				//密码
#define CZMB_LC_REG_VERSION					22					//程序版本(Version)
#define CZMB_LC_REG_DEV0					23					//DEVINF DEV0 - 31,用偏移值 
#define CZMB_LC_REG_DEV31					54					//DEVINF DEV0 - 31,用偏移值
#define CZMB_LC_REG_LCNAME0					0x37				//LCNAME0 - LCNAME7,用偏移值
#define CZMB_LC_REG_LCNAME7					0x3e				//LCNAME0 - LCNAME7,用偏移值
#define CZMB_LC_REG_MAX						0x3f				//判断的最大位
//================================================================================================================
//==== TLS交通灯的寄存器配置类型 
//================================================================================================================
#define	CZMB_TLS_REG_CTRLCODE				0					//	控制代码(TLSCtrlCode)
#define	CZMB_TLS_REG_MINGRNTIME				1					//	最小绿灯时间(MinGrnTime)
#define	CZMB_TLS_REG_REDYELLOWTIME			2					//	红黄灯时间(REDYellowTime)
#define	CZMB_TLS_REG_YELLOWTIME				3					//	黄灯时间(YellowTime)
#define	CZMB_TLS_REG_BRIGHTNESS				5					//	亮度(Brightness)
#define	CZMB_TLS_REG_RPFT					7					//	R Pixel failure threshold
#define	CZMB_TLS_REG_YPFT					8					//	Y Pixel failure threshold
#define	CZMB_TLS_REG_GPFT					9					//	G Pixel failure threshold
#define	CZMB_TLS_REG_RF						11					//	红灯状态(R failure)
#define	CZMB_TLS_REG_YF						12					//	黄灯状态(Y failure)
#define	CZMB_TLS_REG_GF						13					//	绿灯状态(G failure)
#define	CZMB_TLS_REG_ACTIVE					15					//	当前信号灯状态状态(Active)
#define	CZMB_TLS_REG_CTRLMODE				20					//	控制模式
#define	CZMB_TLS_REG_VERSION				22					//	程序版本(Version)
#define CZMB_TLS_REG_SYSTEM					23					//	系统控制
#define CZMB_TLS_REG_WDT					26					//	看门狗时间
#define CZMB_TLS_REG_MAX					27					//  该类型最大值，用于判断传入参数在类型范围里

//================================================================================================================
//==== ALCS-Aspects lane control signal的寄存器配置类型 
//================================================================================================================
#define	CZMB_ALCS_REG_CTRLCODE				0					//	控制代码(ALCSCtrlCode)
#define	CZMB_ALCS_REG_BRIGHTNESS			5					//	亮度(Brightness)
#define	CZMB_ALCS_REG_FLASHRATIO			6					//	闪烁比例（FlashRatio）
#define	CZMB_ALCS_REG_RPFT					7					//	R Pixel failure threshold
#define	CZMB_ALCS_REG_YPFT					8					//	Y Pixel failure threshold
#define	CZMB_ALCS_REG_GPFT					9					//	G Pixel failure threshold
#define	CZMB_ALCS_REG_A_RF					11					//	A面红灯状态(R failure)
#define	CZMB_ALCS_REG_A_YF					12					//	A面黄灯状态(Y failure)
#define	CZMB_ALCS_REG_A_GF					13					//	A面绿灯状态(G failure)
#define	CZMB_ALCS_REG_A_ACTIVE				15					//	当前信号灯状态状态(ALCSActive)
#define CZMB_ALCS_REG_ALCSMASK				16					//	设置屏蔽位
#define	CZMB_ALCS_REG_LWDT					17					//	本地通信看门狗时间(LWDT)
#define	CZMB_ALCS_REG_B_RF					18					//	B面红灯状态(R failure)
#define	CZMB_ALCS_REG_B_YF					19					//	B面黄灯状态(Y failure)
#define	CZMB_ALCS_REG_B_GF					20					//	B面绿灯状态(G failure)
#define	CZMB_ALCS_REG_VERSION				22					//	程序版本(Version)
#define CZMB_ALCS_REG_SYSTEM				23					//	系统控制
#define CZMB_ALCS_REG_STADIS				27					//	上电时显示信息
#define CZMB_ALCS_REG_COMERRDIS				28					//	通信失败时的信息
#define CZMB_ALCS_REG_MAX					29					//  该类型最大值，用于判断传入参数在类型范围里

//================================================================================================================
//==== MLCS-Matrix lane control signal的寄存器配置类型 
//================================================================================================================
#define	CZMB_MLCS_REG_CTRLCODE				0					//	控制代码(MLCSCtrlCode)
#define	CZMB_MLCS_REG_BRIGHTNESS			5					//	亮度(Brightness)
#define	CZMB_MLCS_REG_FLASHRATIO			6					//	闪烁比例（FlashRatio）
#define	CZMB_MLCS_REG_RPFT					7					//	R Pixel failure threshold
#define	CZMB_MLCS_REG_GPFT					9					//	G Pixel failure threshold
#define	CZMB_MLCS_REG_WWPFT					10					//	WW Pixel failure threshold
#define	CZMB_MLCS_REG_RF					11					//	红灯状态(R failure)
#define	CZMB_MLCS_REG_GF					13					//	绿灯状态(G failure)
#define	CZMB_MLCS_REG_WWF					14					//	WW状态(WW failure)
#define	CZMB_MLCS_REG_ACTIVE				15					//	当前状态(LCSActive)
#define	CZMB_MLCS_REG_ARROWMASK				16					//	箭头屏蔽ARROWMASK
#define	CZMB_MLCS_REG_LWDT					17					//	本地通信看门狗时间(LWDT)
#define	CZMB_MLCS_REG_VERSION				22					//	程序版本(Version)
#define CZMB_MLCS_REG_SYSTEM				23					//	系统控制
#define CZMB_MLCS_REG_STADIS				27					//	上电时显示信息
#define CZMB_MLCS_REG_COMERRDIS				28					//	通信失败时的信息
#define CZMB_MLCS_REG_MAX					29					//  该类型最大值，用于判断传入参数在类型范围里
//================================================================================================================
//==== TOR-Turn on radio的寄存器配置类型 
//================================================================================================================
#define	CZMB_TOR_REG_CTRLCODE				0					//	控制代码(WWCtrlCode)
#define	CZMB_TOR_REG_BRIGHTNESS				5					//	亮度(Brightness)
#define	CZMB_TOR_REG_FLASHRATIO				6					//	闪烁比例（FlashRatio）
#define	CZMB_TOR_REG_WWPFT					10					//	WW Pixel failure threshold
#define	CZMB_TOR_REG_WWF					14					//	WW状态(WW failure)
#define	CZMB_TOR_REG_ACTIVE					15					//	当前状态状态(WWSActive)
#define	CZMB_TOR_REG_VERSION				22					//	程序版本(Version)
#define CZMB_TOR_REG_SYSTEM					23					//	系统控制
#define CZMB_TOR_REG_MAX					24					//  该类型最大值，用于判断传入参数在类型范围里

//================================================================================================================
//==== PVMS-Prismatic variable message sign的寄存器配置类型 
//================================================================================================================
#define	CZMB_PVMS_REG_WW_NUMBER				0x08				//	黄闪灯数量
#define	CZMB_PVMS_REG_WDT					0x0B				//	看门狗时间
#define	CZMB_PVMS_REG_CTRMODE				0x0E				//	控制模式寄存器 CTRLMODE
#define	CZMB_PVMS_REG_SYSTEM				0x10				//	系统控制
#define	CZMB_PVMS_REG_VERSION				0x16				//	版本
#define	CZMB_PVMS_REG_WWActiveCache0		0x3f				//	黄闪灯状态缓冲
#define	CZMB_PVMS_REG_WWActiveCache1		0x40				//	黄闪灯状态缓冲
#define	CZMB_PVMS_REG_WWActiveCache2		0x41				//	黄闪灯状态缓冲
#define	CZMB_PVMS_REG_WWActiveCache3		0x42				//	黄闪灯状态缓冲
#define	CZMB_PVMS_REG_MAX					0x43				//	该类型最大值，用于判断传入参数在类型范围里

#define	CZMB_PVMS_DEVREG_SYSTEM				0x17				//	系统控制


//================================================================================================================
//==== VSLS-Variable speed limit signal 的寄存器配置类型
//================================================================================================================
#define	CZMB_VSLS_REG_CTRLCODE				0					//	控制代码(VSLSCtrlCode)
#define	CZMB_VSLS_REG_BRIGHTNESS			5					//	亮度(Brightness)
#define	CZMB_VSLS_REG_FLASHRATIO			6					//	闪烁比例（FlashRatio）
#define	CZMB_VSLS_REG_RPFT					7					//	R Pixel failure threshold
#define	CZMB_VSLS_REG_YPFT					8					//	Y Pixel failure threshold
#define	CZMB_VSLS_REG_WWPFT					10					//	WW Pixel failure threshold
#define	CZMB_VSLS_REG_RF					11					//	红灯状态(R failure)
#define	CZMB_VSLS_REG_YF					12					//	黄灯状态(Y failure)
#define	CZMB_VSLS_REG_WWF					14					//	WW状态(WW failure)
#define	CZMB_VSLS_REG_ACTIVE				15					//	当前状态状态(VSLSSActive)
#define	CZMB_VSLS_REG_LWDT					17					//	本地通信看门狗时间(LWDT)
#define	CZMB_VSLS_REG_VERSION				22					//	程序版本(Version)
#define CZMB_VSLS_REG_SYSTEM				23					//	系统控制
#define CZMB_VSLS_REG_STADIS				27					//	上电时显示信息
#define CZMB_VSLS_REG_COMERRDIS				28					//	通信失败时的信息
#define CZMB_VSLS_REG_MAX					29					//  该类型最大值，用于判断传入参数在类型范围里

//================================================================================================================
//==== VMS-Variable speed limit signal 的寄存器配置类型 
//================================================================================================================
#define	CZMB_VMS_REG_CTRLCODE				0					//	控制代码(VMSCtrlCode)
#define	CZMB_VMS_REG_BRIGHTNESS				5					//	亮度(VMSBrightness)
#define	CZMB_VMS_REG_FLASHRATIO				6					//	闪烁比例（FlashRatio）
#define	CZMB_VMS_REG_RPFT					7					//	R Pixel failure threshold
#define	CZMB_VMS_REG_GPFT					9					//	G Pixel failure threshold
#define	CZMB_VMS_REG_WWPFT					10					//	WW Pixel failure threshold
#define	CZMB_VMS_REG_RF						11					//	红灯状态(R failure)
#define	CZMB_VMS_REG_GF						13					//	绿灯状态(G failure)
#define	CZMB_VMS_REG_WWF					14					//	WW状态(WW failure)
#define	CZMB_VMS_REG_ACTIVE					15					//	当前状态状态(VMSActive)
#define CZMB_VMS_REG_FANERRINF				16					//  失效风扇数
#define CZMB_VMS_REG_FILELISTCRC			17					//  列表文件CRC
#define	CZMB_VMS_REG_LSENSOR2				18					//	光控状态(LSENSOR)
#define	CZMB_VMS_REG_LSENSOR3				19					//	光控状态(LSENSOR)
#define	CZMB_VMS_REG_CTRLMODE				20					//	光控状态(LSENSOR)
#define	CZMB_VMS_REG_PASSWORD				21					//	密码
#define	CZMB_VMS_REG_VERSION				22					//	程序版本(Version)
#define CZMB_VMS_REG_SYSTEM					23					//	系统控制
#define	CZMB_VMS_REG_BPFT					24					//	B Pixel failure threshold
#define	CZMB_VMS_REG_BF						25					//	蓝色灯状态(B failure)
#define	CZMB_VMS_REG_WDT					26					//	VMS中心通信看门狗时间（VMSWDT）
#define	CZMB_VMS_REG_STARTUPDIS				27					//	上电显示信息 (STARTUPDIS)
#define	CZMB_VMS_REG_COMERRDIS				28					//	通信失败显示信息(COMERRDIS)
#define	CZMB_VMS_REG_DEFDIS					29					//	默认显示信息(DEFDIS)
#define	CZMB_VMS_REG_LSENSOR				30					//	光控状态(LSENSOR)
#define	CZMB_VMS_REG_TEMPINF				31					//	温度信息(TEMPINF)
#define	CZMB_VMS_REG_PWRINF					32					//	电源状态(PWRINF)
#define	CZMB_VMS_REG_TEST					33					//	测试
#define	CZMB_VMS_REG_VMSH					34					//	VMS高度
#define	CZMB_VMS_REG_VMSW					35					//	VMS宽度
#define	CZMB_VMS_REG_FANINFO				36					//	VMS风扇信息
#define	CZMB_VMS_REG_DEFAULT_DIMMING		37					//	默认亮度
#define	CZMB_VMS_REG_DEBUG					100					//	debug位
#define	CZMB_VMS_REG_MAX					101					//	宏定义最大值
//================================================================================================================
//====  modbus用到的定义(结束)
//================================================================================================================

//================================================================================================================
//====　czMB_LED interface
//================================================================================================================
CZAPI_DECLARE(INT32U) czMB_LCGet(INT8U addr, INT16U type, INT16U *reg);
CZAPI_DECLARE(INT32U) czMB_LCSet(INT8U addr, INT16U type, INT16U  reg);
CZAPI_DECLARE(INT32U) czLCReadUpdateStatus(INT8U GG,INT8U UU,INT8U* IsUpdating,INT8U* IsSuccess);

CZAPI_DECLARE(INT32U) czMB_TLSGet(INT8U addr,INT8U daddr, INT16U type, INT16U *reg);
CZAPI_DECLARE(INT32U) czMB_TLSSet(INT8U addr,INT8U daddr, INT16U type, INT16U  reg);

CZAPI_DECLARE(INT32U) czMB_ALCSGet(INT8U addr,INT8U daddr, INT16U type, INT16U *reg);
CZAPI_DECLARE(INT32U) czMB_ALCSSet(INT8U addr,INT8U daddr, INT16U type, INT16U  reg);


CZAPI_DECLARE(INT32U) czMB_MLCSGet(INT8U addr,INT8U daddr, INT16U type, INT16U *reg);
CZAPI_DECLARE(INT32U) czMB_MLCSSet(INT8U addr,INT8U daddr, INT16U type, INT16U  reg);

CZAPI_DECLARE(INT32U) czMB_VSLSGet(INT8U addr,INT8U daddr, INT16U type, INT16U *reg);
CZAPI_DECLARE(INT32U) czMB_VSLSSet(INT8U addr,INT8U daddr, INT16U type, INT16U  reg);


CZAPI_DECLARE(INT32U) czMB_TORGet(INT8U addr,INT8U daddr, INT16U type, INT16U *reg);
CZAPI_DECLARE(INT32U) czMB_TORSet(INT8U addr,INT8U daddr, INT16U type, INT16U  reg);

CZAPI_DECLARE(INT32U) czMB_VMSGet(INT8U addr,INT8U daddr, INT16U type, INT16U *reg);
CZAPI_DECLARE(INT32U) czMB_VMSSet(INT8U addr,INT8U daddr, INT16U type, INT16U  reg);


#ifdef __cplusplus
}
#endif
#endif