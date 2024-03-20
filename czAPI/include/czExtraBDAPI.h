//****************************************************************************************************************
//****                                  LED产品JetFileII协议中的EXTRA BOARD函数模块 
//****			                              遵循CZ DEPT开发标准
//****                                          开发人:YangLei
//****                                      最后修改日期:2016-08-30
//****************************************************************************************************************
#ifndef __CZ_EXTRABDAPI_H__
#define __CZ_EXTRABDAPI_H__

#include "czType.h"
#include "czStructsDefine.h"

#ifdef __cplusplus
extern "C" {
#endif

//================================================================================================================
//====  采集板控制IO结构体
//================================================================================================================
typedef struct
{	
	INT8U OUT0 ;												//0:表示关闭，1：表示打开，0xff：表示不动作
	INT8U OUT1;
	INT8U AC_OUT;
	INT8U HEAT;
	INT8U FAN;
	INT8U Rev[3];
}czExtraIOCtrls;

//================================================================================================================
//====  采集板控制IO结构体
//================================================================================================================
typedef struct
{	
	INT8U IOS[12];												//0:表示关闭，1：表示打开，0xff：表示不动作
	INT8U Rev[4];
}czExtraSelCtrls;


//================================================================================================================
//====  采集板读取回来的信息结构体
//================================================================================================================
typedef struct
{	
	INT8S temp;													//温度，摄氏度，有效值为[-100,100] 
	INT8U humidity;												//湿度，% ,有效值为[0,100] 
	INT8U Power1Stat;											//有效值为[0,1],0=故障,1=正常，其它值表示无效
	INT8U Power2Stat;											//电源检状态，共2路，

	INT16U Power1MV;											//检测电压值(mv)
	INT16U Power2MV;											//检测电压值(mv)

	INT8U  REV;
	INT8U  ACOUTStat;											//关于设备状态(0:正常-关闭   1：正常-打开,3：错误)
	INT8U  HEATStat;
	INT8U  FANStat;

	INT16U AC_OUTMA;											//(灯箱继电器)电流值
	INT16U HEATMA;												//(加热器继电器) 电流值
	INT16U FANMA;												//(风扇继电器) 电流值

	INT16U AcceleratorX;										//加速计x轴数据(short型),加速计测量范围+-2g
	INT16U AcceleratorY;										//加速计y轴数据(short型)
	INT16U AcceleratorZ;										//加速计z轴数据(short型)

	INT16U GyroscopeX;											//陀螺仪x轴数据(short型),陀螺仪测量范围+-2000°/s
	INT16U GyroscopeY;											//陀螺仪y轴数据(short型)
	INT16U GyroscopeZ;											//陀螺仪z轴数据(short型)

	INT16U AC_POWER;											//电压值V
	INT8U  In1Stat;
	INT8U  In2Stat;

	INT8U  Out1Stat;
	INT8U  Out2Stat;
	INT16U Rev2;

}czExtraIOInfo;

//============================================================================================================
//==== IO板传感器状态结构体
//============================================================================================================
typedef struct
{
	INT8S   IO_Temp;											//IO板当前温度
	INT8U   IO_Humidity;										//IO板上的湿度
	INT8U   IO_Rev[2];											
	INT8U   IO_InStat[16];										//IO板16路输入状态
	INT8U   IO_OutStat[12];										//IO板12路输出状态

	INT16U	IO_ValueADC[8];										//IO板8路ADC值
	INT8U	IO_ADCStat[8];										//IO板8路ADC状态

	INT16S  CL_AcceleratorX;       								//加速计x轴数据(short型)
	INT16S  CL_AcceleratorY;        							//加速计y轴数据(short型)
	INT16S  CL_AcceleratorZ;            						//加速计z轴数据(short型)
	INT16S  CL_GyroscopeX;       								//陀螺仪x轴数据(short型)
	INT16S  CL_GyroscopeY;        								//陀螺仪y轴数据(short型)
	INT16S  CL_GyroscopeZ;            							//陀螺仪z轴数据(short型)
}czExtraSelInfo;

//============================================================================================================
//==== IO板wifi信息设置结构体
//============================================================================================================
typedef struct
{
	INT8U   Wifi_Modify;										//需要修改的参数（1为修改0为不改）具体参考协议
	INT8U   Wifi_Recv[3];										//数据对齐保留
	INT8U   Wifi_SSID[20];										//WIFI模块SSID	
	INT8U   Wifi_PSW[20];										//WIFI模块密码
	INT16U  Wifi_Port;											//WIFI模块port设置
	INT8U	Wifi_CommType;										//TCP/UDP模式选择（1为TCP,0为UDP）
	INT8U	Wifi_HideSSID;										//隐藏SSID（1为隐藏，0为显示）
}czExtraWifiSetStruct;

//============================================================================================================
//==== IO板wifi信息读回结构体
//============================================================================================================
typedef struct
{									//数据对齐保留
	INT8U   Wifi_SSID[20];										//WIFI模块SSID	
	INT8U   Wifi_PSW[20];										//WIFI模块密码
	INT8U	Wifi_CommType;										//TCP/UDP模式选择（1为TCP,0为UDP）
	INT8U	Wifi_HideSSID;										//隐藏SSID（1为隐藏，0为显示）
	INT8U	Wifi_Modify;										//设置时有用 需要修改的参数（1为修改0为不改）具体参考协议
	INT8U	Recv;												//数据对齐保留
}czExtraWifiStruct;

//================================================================================================================
//====　collect interface.
//================================================================================================================
CZAPI_DECLARE(INT32U) czExtraCollectCtrl(czExtraIOCtrls *Ctrls, INT8U CollectAddr);
CZAPI_DECLARE(INT32U) czExtraCollectRead(czExtraIOInfo *Info, INT8U CollectAddr);
CZAPI_DECLARE(INT32U) czExtraIOCtrl(czExtraSelCtrls *Ctrls, INT8U IOAddr);
CZAPI_DECLARE(INT32U) czExtraIORead(czExtraSelInfo *Info, INT8U IOAddr);

CZAPI_DECLARE(INT32U) czExtraWifiUnlock(INT8U *unLockKey,INT8U keyLen,INT32U *RtnKey);
CZAPI_DECLARE(INT32U) czExtraWifiSetInfo(czExtraWifiStruct *Ctrls);
CZAPI_DECLARE(INT32U) czExtraWifiGetInfo(czExtraWifiStruct *Info);
CZAPI_DECLARE(INT32U) czExtraWifiReset();


#ifdef __cplusplus
}
#endif

#endif