#ifndef __MACAOUSR_DEFINE_H__
#define __MACAOUSR_DEFINE_H__

#include "czType.h"

#ifdef __cplusplus
extern "C" {
#endif

//================================================================================================================
//==== 日志要用到的宏定义　
//================================================================================================================
#define LOG_MARK						__FILE__,__LINE__

#define	LOG_EMERG						0						/* system is unusable							*/
#define	LOG_ALERT						1						/* action must be taken immediately				*/
#define	LOG_CRIT						2						/* critical conditions							*/
#define	LOG_ERR							3						/* error conditions								*/
#define	LOG_WARNING						4						/* warning conditions							*/
#define	LOG_NOTICE						5						/* normal but significant condition				*/
#define	LOG_INFO						6						/* informational								*/
#define	LOG_DEBUG						7						/* debug-level messages							*/

//================================================================================================================
//==== 文件格式头字符定义(标识符)
//================================================================================================================
#define SIGNSLIT_FLAG					0x564C                  //VL
#define USERSLIT_FLAG					0x554C                  //UL
#define OPTERLOG_FLAG					0x4C47                  //LG
#define VMSSTATUS_FLAG					0x5354                  //ST
#define SERVERSTATUS_FLAG				0x5353                  //SS
#define SIGNGROUP_FLAG					0x5347                  //SG
#define NTCIP_MSGFILE_FLAG				0x4E4D                  //NM
#define NTCIP_GRAPHICFILE_FLAG			0x4E47                  //NG
#define NTCIP_SCHFILE_FLAG				0x4E53                  //NS
#define NTCIP_TRAFFICLIGHT_FLAG			0x544C                  //TL
#define JF_PLSFILE_FLAG					0x504C                  //PL
#define CMD_FILE_FLAG					0x434D                  //CM
#define CONTROLLER_FILE_FLAG			0x4343                  //CC
#define TREE_FILE_FLAG					0x5452                  //TR
#define CROSSING_FILE_FLAG				0x5049                  //PI
#define SIDE_FILE_FLAG					0x5258                  //RX
#define LANE_FILE_FLAG					0x4C41                  //LA
#define LST_FOLDER_FILE_FLAG			0x4C46                  //LF
#define TC_MONITOR_FILE_FLAG			0x5443                  //TC
#define TC_STATUS_FILE_FLAG				0x544D                  //TM
#define TC_REALSTATUS_FILE_FLAG			0x5254                  //RT
#define TC_LIGHT_FILE_FLAG				0x4C49                  //LI
#define TC_TIMETASK_FILE_FLAG			0x5454                  //TT
#define TC_PASSAGEWAY_FILE_FLAG			0x5057                  //PW
#define TC_REDIRPWTREE_FILE_FLAG		0x4454                  //DT
#define TC_DIRECTION_FILE_FLAG			0x444C                  //DL
#define WARING_FILE_FLAG				0x574C                  //WL
#define TCFLOW_FILE_FLAG				0x464C                  //FL
#define PIXEL_FILE_FLAG					0x5058                  //PX
#define SIGN_STATUS_FILE_FLAG			0x5453                  //TS
#define OUTPUTLOG_FILE_FLAG				0x4F50                  //OP
#define JF_PLMFILE_FLAG					0x504D                  //PM

//================================================================================================================
//==== 主板类型，与tb_boardInfo表对应
//================================================================================================================
#define ST_CZ5800						1
#define ST_CZ5271_6058_VMS				2
#define ST_CZ5271_6058_VMSTail			3
#define ST_CZ5271_6058_RadarOnly		4
#define ST_CZ5271_6058_Trailer			5
#define ST_CZ5271_6058_Prismatic		6
#define ST_CZ9245_VMS					7
#define ST_CZ9246_VMS					8
#define ST_CZ5271_VMS					9



//================================================================================================================
//==== 主板报警类型定义
//================================================================================================================
#define WARING_Main_InTemp				0x01      //主板内部温度
#define WARING_Main_OutTemp				0x02      //主板外部温度
#define WARING_Main_Tile				0x03      //箱体
#define WARING_Main_Pixel				0x04      //像点检测
#define WARING_Main_Time				0x05      //时间

//================================================================================================================
//==== 报警类型:箱体次类型
//================================================================================================================
#define WARING_Tile_TEMP				0x01
#define WARING_Tile_Power_I				0x02
#define WARING_Tile_Power_II			0x03
#define WARING_Tile_FAN					0x04
#define WARING_Tile_PHY					0x05
#define WARING_Tile_CABLE				0x06
#define WARING_Tile_GAMMR				0x07
#define WARING_Tile_CPU					0x08
#define WARING_Tile_FPGA				0x09

//================================================================================================================
//==== 报警类型:像点检测状态
//================================================================================================================
#define WARING_PIXEL_RedBad				0x01
#define WARING_PIXEL_GreenBad			0x02
#define WARING_PIXEL_BlueBad			0x03
#define WARING_PIXEL_RedSignal			0x04
#define WARING_PIXEL_GreenSignal		0x05
#define WARING_PIXEL_BlueSignal			0x06

#define MAX_PATH								256


//================================================================================================================
//==== 文件格式定义(文件头)
//================================================================================================================
struct fileHead
{
	INT16U Flag;												//标志,signlist = "VL",userlist="UL"
	INT16U Count;												//后面记录条数
	INT32U fileSize;											//文件长度
	INT16U CountHi;												//
	INT16U Rev;													//保留
};

//================================================================================================================
//==== signlist.lst文件格式中的记录定义(152 B)
//================================================================================================================
struct VMSInfo
{	
	INT32U SignID;												//唯一
	INT32U CompanyID;											//公司ID
	INT32U Port;
	INT32U BaudRate;

	float  X;													//4 bytes,对应GPS的
	float  Y;													//4 bytes

	INT16U Width;
	INT16U Height;

	INT8U  ColorStyle;
	INT8U  SignType;	
	INT8U  TransMode;
	INT8U  GG;													//group address

	INT8U  UU;													//unit address
	INT8U  Protocal;
	INT8U  DeleteFlag;											//Delete标志,在更新时有效,1=删除
	INT8U  rev2;

	INT8U  Name[40];											//name
	INT8U  MobileNumber[20];
	INT8U  IP[16];
	INT8U  ComStr[12];

	float  GPSLong;												//4 bytes,GPS位置信息,固定的需+2000
	float  GPSLat;												//4 bytes
	INT8U  Rev3[20];;
};


//================================================================================================================
//==== signstatus.lst文件格式中的记录定义(364 B)
//================================================================================================================
struct DEVInfo
{	
	INT32U StateID;												//状态的ＩＤ号
	INT32U SignID;												//显示屏的ID
	INT8S  InsideTemp;											//屏内温度,-127表示无效
	INT8S  OutsdeTemp;											//屏外温度,-127表示无效
	INT8U  Humidity;											//湿度，0xFF表示无效
	INT8U  BrightPrecent;										//亮度百分比
	INT8U  SysStatus;											//显示屏系统所以的状态，不同的显示屏做有差别
	INT8U  IsLive;												//是否连接,1为连接
	INT16U BrightAD;											//AD值,0-255
	INT16U RadarCurSpeed;										//Radar当前检查到速度
	INT16U BatVlotageMV;										//电池电压,配置有电池的屏才有
	INT32U GPSDistance;											//GPS与设置点的距离
	float  GPSPosit_N;											//GPS坐标
	float  GPSPosit_S;											//GPS坐标
	INT32U Auxs;												//辅助功能,目前拖车有用
	INT8U  FileName[100];										//当前播放的文件名
	INT8U  RecordMsg[200];										//记录的信息
	INT8U  RecordDT[20];										//记录时间
	INT8U  Rev[8];												//保留
};

//================================================================================================================
//==== traffic.lst文件格式中的记录定义(212 B)
//================================================================================================================
struct TCInfo
{	
	INT32U ControllerID;										//每个控制机唯一
	INT32U CrossingID;											//所属路口的ID 
	INT32U RegionID;											//控制机所属区域的ID
	INT32U Port;
	INT32U BaudRate1;
	INT32U BaudRate2;

	float  Long;												//在地图上的X,对应GPS经度
	float  Lat;													//在地图上的Y,对应GPS纬度

	INT8U  ControllerType;										//控制机类型
	INT8U  TransMode;
	INT8U  GG;													//group address
	INT8U  UU;													//unit address	

	INT8U  Protocol;
	INT8U  DeleteFlag;											//Delete标志,在更新时有效,1=删除
	INT16U Rev;													//保留

	INT8U  Name[100];											//路口控制机名称
	INT8U  IP[16];	
	INT8U  MobileNumber[20];
	INT8U  ComStr[40];
};

//================================================================================================================
//==== tree.lst文件格式中的记录定义(228 B)
//================================================================================================================
struct TCTree
{	
	INT32U TNID;												//tree node id
	INT32U ParentID;											//parent id
	INT8U  Description[200];									//名称
	INT8U  DeleteFlag;											//保留
	INT8U  Rev[15];	
};

//================================================================================================================
//==== crossing.lst文件格式中的记录定义(220 B)
//================================================================================================================
struct TCCross
{	
	INT32U CrossingID;											//CrossingID
	INT32U RPID;												//RPID
	INT8U  Name[200];											//名称
	INT8U  LoopTag;												//环路
	INT8U  DeleteFlag;											//保留
	INT8U  Rev[10];	
};

//================================================================================================================
//==== side.lst文件格式中的记录定义(28 B)
//================================================================================================================
struct TCSide
{	
	INT32U SideID;												//SideID
	INT32U CrossingID;											//CrossingID
	INT32U RoadID;												//RoadID
	INT32U Angle;												//Angle
	INT8U  SIndex;												//SIndex
	INT8U  DeleteFlag;											//保留
	INT8U  Rev[14];	
};

//================================================================================================================
//==== lane.lst文件格式中的记录定义(20 B)
//================================================================================================================
struct TCLane
{	
	INT32U LaneID;												//LaneID
	INT32U SideID;												//SideID
	INT32U ToSideID;											//ToSideID
	INT8U  DireType;											//DirType
	INT8U  DeleteFlag;											
	INT8U  Rev[6];												//保留
};

//================================================================================================================
//==== light.lst文件格式中的记录定义(20 B)
//================================================================================================================
struct TCLight
{	
	INT32U LightID;												//LaneID
	INT32U LaneID;												//SideID
	INT32U Number;												//Number
	INT8U  Type;												//DireType
	INT8U  DeleteFlag;											
	INT8U  Rev[2];												//保留
};

//================================================================================================================
//==== passageway.lst文件格式中的记录定义(152 B)
//================================================================================================================
struct TCPassageWay
{	
	INT32U PWID;												//ID,每个唯一
	INT32U RegionID;											//树节点ID
	INT8U  Name[100];											//通道名称
	INT8U  BeginDT[20];											//开始日期
	INT8U  EndDT[20];											//结束日期
	INT8U  Enable;		
	INT8U  DeleteFlag;											
	INT8U  Rev[2];												//保留
};

//================================================================================================================
//==== redirpwtree.lst文件格式中的记录定义(16 B)
//================================================================================================================
struct TCReDirPWTree
{	
	INT32U DTID;												//ID,每个唯一
	INT32U DirectionID;											//方向ID
	INT32U TreeNodeID;											//树节点ID
	INT8U  DeleteFlag;											
	INT8U  Rev[3];												//保留
};

//================================================================================================================
//==== direction.lst文件格式中的记录定义(72 B)
//================================================================================================================
struct TCDirection
{	
	INT32U DIID;												//ID,每个唯一
	INT32U FrCrossingID;										//从哪里的路口ID
	INT32U FrControllerID;										//从哪里的控制机ID
	INT32U FrSideID	;											//从哪里的端口ID
	INT32U FrRoadID;											//从哪里的道路ID
	INT32U FrLaneID;											//从哪里的小道ID
	INT32U AmCrossingID;										//经过哪里的路口ID
	INT32U AmControllerID;										//经过哪里的控制机ID
	INT32U AmSideID;											//经过哪里的端口ID
	INT32U AmRoadID	;											//经过哪里的道路ID
	INT32U AmLaneID	;											//经过哪里的小道ID
	INT32U ToCrossingID;										//到哪里的路口ID
	INT32U ToControllerID;										//到哪里的控制机ID
	INT32U ToSideID	;											//到哪里的端口ID
	INT32U ToRoadID;											//到哪里的道路ID
	INT32U ToLaneID;											//到哪里的小道ID
	INT8U  DeleteFlag;											
	INT8U  Rev[3];												//保留
};

//================================================================================================================
//==== waring.lst文件格式中的记录定义(384 B)
//================================================================================================================
struct SWaring
{	
	INT32U WarnID;												//ID,每个唯一
	INT32U WaringLevel;											//警告级别
	INT8U  RecordDT[20];										//警告时间
	INT8U  Name[100];
	INT8U  WaringMSG[256];
	INT8U  DeleteFlag;
	INT8U  Rev[7];
};

//================================================================================================================
//==== tcflow.lst文件格式中的记录定义(48 B)
//================================================================================================================
struct SFlow
{	
	INT32U RoadID;												//ID,每个唯一
	INT32U SignID;												//检查器ID
	INT16U LaneIndex;											//检查器上Radar的编号
	INT16U Rev;													//保留
	INT16U carQuantity;											
	INT16U truckQuantity;
	INT16U carAverSpeed;
	INT16U truckAverSpeed;
	INT16U carMaxSpeed;
	INT16U truckMaxSpeed;
	INT16U carMinSpeed;
	INT16U truckMinSpeed;
	INT8U  RecordDT[20];	
};

//================================================================================================================
//==== signgroup.lst文件格式中的记录定义(284 B)
//================================================================================================================
struct SignGroup
{	
	INT32U SignGroupID;											//唯一
	INT8U  GroupName[64];										//分组名称
	INT8U  Description[200];									//分组描述
	INT8U  DeleteFlag;											//Delete标志,在更新时有效,1=删除
	INT8U  Rev[15];												//保留
};

//================================================================================================================
//==== userlist.lst文件格式中的记录定义(216 B)
//================================================================================================================
struct UserInfo
{
	INT32U UserID;
	INT32U CompanyID;
	INT16U RoleID;												//1=super admin,2=company admin, 3= user
	INT8U  DeleteFlag;											//Delete标志,在更新时有效,1=删除
	INT8U  Rev;

	INT8U  UserName[40];
	INT8U  Password[16];
	INT8U  RealName[40];
	INT8U  Phone[20];
	INT8U  Email[96];	
};

//================================================================================================================
//==== optlog.log文件格式中的记录定义(228 B)
//================================================================================================================
struct OPTLog
{	
	INT32U CMDStyle;
	INT32U ResultCode;
	INT32U Progress;
	INT8U  UserName[40];
	INT8U  SignName[40];
	INT8U  RequestDateTime[20];
	INT8U  ExceDateTime[20];
	INT8U  UserIP[16];
	INT8U  Note[148];	
};

//================================================================================================================
//==== linkstatus.sta文件格式中的记录定义(8 B)
//================================================================================================================
struct LinkInfo	
{	
	INT32U	SignID;
	INT16U	Status;
	INT8U   ntcipMsgType;
	INT8U	Rev;
}; 

//================================================================================================================
//==== timeTask交换用到
//================================================================================================================
struct timeTaskInfo
{	
	INT32U TTID;	
	INT32U ExecTimes;
	INT32U Interval;
	INT32U CMD;
	INT32U TaskID;
	INT32U SignID;
	INT8U  Enable;	
	INT8U  DeleteFlag;	
	INT8U  ClientUsed;	
	INT8U  Rev;	
	INT8U  ArgFilePath[256];	
	INT8U  PlanTime[20];
	INT8U  ExecTime[20];
	INT8U  Description[128];
};

//================================================================================================================
//==== MESSAGE.BIN DMS文件格式中的记录定义
//================================================================================================================
typedef struct 
{	
	INT32U MsgSize;												//大小
	INT8U  MemoryType;											//信息类型,
	INT8U  MessageBeacon;										//是否有Beacon，默认为0
	INT8U  PixelService	;										//是否支持像素服务,默认为0
	INT8U  RunTimePriority	;									//运行优先级,1-255,255最高
	INT16U MessageCRC;											//信息CRC，只读
	INT16U MessageNumber;										//信息编号
	INT8U  MessageStatus;										//信息状态，只读	
	INT8U  Event;												//信息事件0=不做操作,1=激活,2=作为door open message 
	INT16U MultiStringLen;										//显示信息长度
	INT8U  MessageOwner[64]	;									//信息拥有者
}dmsMsg; 


//================================================================================================================
//==== GRAPHIC.BIN DMS文件格式中的记录定义
//================================================================================================================
typedef struct 
{	
	INT32U DataLen;												//图形数据的长度
	INT8U  GraphicNumber;										//图片的编号
	INT8U  GraphicType;											//图片类型，color24bit=4 
	INT8U  TransparentEnabled;									//Graphic的颜色是否包含透明色
	INT8U  GraphicStatus	;									//图片状态，只读
	INT16U GraphicHeight;										//图片高度
	INT16U GraphicWidth;										//图片宽度
	INT16U GraphicID;											//Graphic ID 只读
	INT16U GraphicDataLen;										//指示Graphic数据长度
	INT32U TransparentColor;									//Graphic透明的颜色值
	INT8U  GraphicName[64]	;									//Graphic名称,最大63字符,以0结尾，不足以0填充
}dmsGraphic; 

//================================================================================================================
//==== SCHEDULE.BIN DMS文件格式中的记录定义
//================================================================================================================
typedef struct 
{	
	INT32U DataLen;												//调度数据的长度
	INT16U ScheNO;												//调度序号
	INT16U ScheMonth;											//调度月份
	INT8U  ScheDay;												//调度星期
	INT8U  ScheHour;											//调度小时
	INT8U  ScheMinute;											//调度分钟
	INT8U  MessType;											//消息类型
	INT32U ScheDate;											//调度日期
	INT16U MessNumber;											//消息序号
	INT16U MessageCRC;											//消息的CRC, 0表示无CRC验证
}dmsSchedule; 


//================================================================================================================
//==== Enumeration of connection type
//================================================================================================================
typedef enum 
{
    COMM_UDP,
    COMM_TCP,
    COMM_COM
}conn_type;

//================================================================================================================
//==== 错误报告错误类型
//================================================================================================================
typedef enum 
{
	ERROR_MAINBOARD,
	ERROR_TILE,
	ERROR_PIXEL,
	ERROR_SIGNAL
}error_type;

//================================================================================================================
//==== init函数中的初始结构体定义
//================================================================================================================
typedef struct czinterface
{
	conn_type type;												/* 通信类型										*/
	INT32U    inited;											/* 初始化标识，在init函数中置位，１表示已初始化	*/
	INT8U     ip[32];											/* IP地址,点分格式，如169.254.10.49				*/
	INT8U     com[16];											/* 串口通信时用到的com字符，如COM1				*/
	INT32U    port;												/* 网络通信时用到的端口号						*/
	INT32U    baudrate;											/* 串口通信时用到的baudrate,数值型,如115200		*/						
	void      *signPointer;										/* sign对象指针，用于控制,调用者使用			*/
	void      *taskPointer;										/* task对象指针，用于控制,调用者使用			*/
	INT16U    SrcAddr;											/* 源GGUU地址									*/
	INT16U    DstAddr;											/* 显示屏(目的)GGUU地址							*/
	INT32U    Retry;											/* 通信时，重试次数								*/
	INT32U    Timeoutms;										/* 通信时，超时时间，单位为ms					*/
	INT32U	  Stoped;											/* 停止通信										*/		
	INT16U	  totalSteps;										/* 写进度时，总进度个数							*/
	INT16U	  curSteps;											/* 当前写的进度所在部进度的步					*/
	INT16U    packetSize;										/* 通信时数据包的大小,有效值为64-1280			*/
	INT8U     Rev[26];											/* 保留											*/
    void (*pre_comm) (struct czinterface*);						/* 通信前调用的回调函数							*/
	void (*post_comm) (struct czinterface*);					/* 通信后调用的回调函数							*/
	//============================================================================================================
	//=== 更新状态回调函数
	//============================================================================================================
	void (*update_status) (struct czinterface*,INT32U code,INT32U precent);	
	//============================================================================================================
	//=== 从网络/串口上读写数据的回调函数，如果为空，表示使用DLL内部的网络／COM类
	//============================================================================================================
	INT32U (*read) (void*,INT8U *buf, INT32U size, INT32U timeoutms);			
    INT32U (*write)(void*,INT8U *buf, INT32U size);			

	//============================================================================================================
	//=== 日志回调，所有信息从这里输出
	//============================================================================================================
	void   (*log)  (struct czinterface*,const char *file, int line, int level,const char *fmt, ...);
	//============================================================================================================
	//=== 读取当前播放文件后期处理回调，DLL负责把显示内容读取出来，然后调用该回调生成GIF等
	//============================================================================================================
	void   (*curShowFilter) (struct czinterface*,const char *srcfile, const char *dstfile,int frames,int delays);
	//============================================================================================================
	//=== 获取系统的临时路径
	//============================================================================================================
	void   (*getTemporaryPath) (struct czinterface*,char *store_path, INT32U max_path);

}_czinterface;


#define TYPE_READ						1						//读取显示屏内容
#define TYPE_WRITE						2						//写入显示屏内容


//****************************************************************************************************************
//**** NTCIP DLL需要用到的结构体
//****************************************************************************************************************

//================================================================================================================
//==== MessageIDCode 
//================================================================================================================
typedef struct 
{
	INT8U	messageMemoryType;  								//INTEGER (0..255),
	INT16U	messageNumber;      								//INTEGER (0..65535),
	INT16U	messageCRC;      									//OCTET STRING (SIZE (2))
}MessageIDCode;

//================================================================================================================
//==== MessageActivationCode 
//================================================================================================================
typedef struct 
{
	INT16U 	duration;	         								//INTEGER (0..65535),
	INT8U	activatePriority;    								//INTEGER (0..255),
	INT8U	messageMemoryType;   								//INTEGER (0..255),
	INT16U	messageNumber;       								//INTEGER (0..65535),
	INT16U	messageCRC;          								//OCTET STRING (SIZE (2)),
	INT32U	sourceAddress;       								//OCTET STRING (SIZE (4))
}MessageActivationCode;


//****************************************************************************************************************
//**** JetFileII DLL需要用到的结构体
//****************************************************************************************************************
typedef struct
{
	INT16U cpuv;
	INT16U tcpv;
	INT16U filesv;
	INT16U fpga;
	INT16U width;
	INT16U height;
	INT16U protocol;
	INT8U  gg;
	INT8U  uu;
}SYSTEM_SET;

typedef struct
{
	INT8U sysState;
	INT8U inTemp;
	INT8U outTemp;
	INT8U AutoPower;
	INT8U Humidity;
	INT8U Samples;
	INT8U BrightLevel;    
	INT8U Rev;
}CURRENT_STATE;

//================================================================================================================
//====                        默认配置结构体声明
//================================================================================================================
typedef struct 
{
	INT16U ID;                                					//55aa
	INT8U PlayListLoc;                      					//播放列表保存位置
	INT8U TimePre0En;                        					//时间前置0,如果是1表示时间没有前置0
	
    INT8U Ddrive;                            					//默认盘
    INT8U Dback_color;                       					//默认背景色
    INT8U Dfont_color;                       					//默认前景色
    INT8U Dhor_just;               			 					//水平对齐
    
    INT8U Dver_just; 			             					//垂直对齐
    INT8U Dline_space;            			 					//行间距
    INT8U Dfont;                   			 					//字体
    INT8U Din_mode;                			 					//入模式

    INT8U Dout_mode;                         					//出模式
    INT8U Dspeed;                            					//速度
    INT8U Dstay_time;                        					//停留时间
    INT8U Dwrap;                             					//自动换行
    
    INT32U Lstay_time;						 					//长停留时间,当Dstay_Time为0时,用这个值

    INT8U TimeFormat;
	INT8U HeadTailPlayMode;
	INT8U HeadTailMoveDirection;
	INT8U HeadTailMoveSpeed;

	INT8U HeadTailPauseTime;
	INT8U Play_num;												//循环播放播放列表的次数, 0表示永久播放, 播放完后黑屏
	INT16U Version;												//版本号,从0xAAF1开始, Add 2017/9/12

	INT16U ShowDefaultBmpTime;									//单位秒,未收到JetFileII消息,显示默认图片;TE18-233合同

    INT8U rev[22];         
}DEFAULT_SET;

typedef struct
{
	INT8U WinName[64];		//以NULL结尾
	INT32U WinID;
	INT32U X;	
	INT32U Y;
	INT16U Z;
	INT16U Width;
	INT16U Height;
	INT8U  Transparency;	//0-100,0表示不透明,无效
	INT8U  PlayMode;		//无效
	INT8U  WinMode;			//0=RGB&YUV,1=RGB Only
	INT8U  Rev[3];
}WinInfo;

typedef struct
{
	INT16U x;				//X位置
	INT16U Y;				//Y位置
	INT8U  Red;
	INT8U  Green;
	INT8U  Blue;
	INT16U Width;
	INT16U Height;
}BRIGHT_CTRL;

typedef struct
{
	INT8U Type;				//0=固定, 1=渐变
	INT8U Red;				//0=没有Red分量, 1=有Red分量。
	INT8U Green;			//0=没有green分量, 1=有green分量。
	INT8U Blue;				//0=没有blue分量, 1=有blue分量。
	INT16U Level;			//1-256的灰度级别
} GRAY_TEST_PARAM;

typedef struct
{
	INT16U Beginx;
	INT16U Beginy;
	INT16U Endx;
	INT16U Endy;
	INT8U  nFlag;												//标志位，如果是0xF1表示抽点方式
	INT8U  Intensity;
	INT8U  Pattern;    
	INT8U  Red;
	INT8U  Green;
	INT8U  Blue;
	INT16U modWidth;
	INT16U modHeight;
	INT8U  nX;													//抽点方式的X抽点数
	INT8U  nY;													//抽点方式的Y抽点数
	INT16U nSteps;												//抽点的当前步
	INT16U Rev;
}AREA_STRUCT;

typedef struct
{
	INT8U R;													//0xFF 关闭,0x01亮
	INT8U Y;	
	INT8U G;
	INT8U Mode;
	INT8U Rev[4];
}BEACON_ST;

typedef struct
{
	INT8U Rev1;													//0xFF 关闭,0x01亮
	INT8U Generator;	
	INT8U Camera;
	INT8U Rev2;
	INT8U Rev[4];
}EXTEQUIPMENT_ST;

typedef struct
{
	INT8U IPAddr[32];              								//ip_addr
	INT16U CustomPort;											//自定义的网络端口   
	INT8U  GroupAddr;            								//GG
	INT8U  UnitAddr;             								//UU
	INT8U  GatewayAddr[32];          							//网关地址
	INT8U  SubnetMaskAddr[32];            						//掩码地址
	INT8U  Recv[16];											//保留
}COMMUNICATICON_ST;



#pragma pack(push) 
#pragma pack(1) 
typedef struct
{
	INT8U  GeneratorCount;													//0xFF 关闭,0x01亮
	INT16U GeneratorState;	
	INT8U  GeneratorStep;
	INT8U Rev[4];
}GENERATOR_ST;
#pragma pack(pop) 

typedef struct
{
	INT8U BrightType;	//当前亮度类型。0=自动,1=手动,2=调度
	INT8U Percent;		//亮度百分比，有效值[1-100]，100表示最亮
	INT16U ADValue;		//当前AD值，类型为自动时有效
	INT32U Rev;
}BRIGHT_INFO; 


typedef struct  //DirectoryEntryStructure
{
	INT8U badir_name[11];	    //文件名 
	INT8U bdir_attr;			//文件属性
	INT8U bdir_rev;				//保留
	INT8U bcrt_time_tecth;		//创建时间1，秒的计数
	INT16U wcrt_time;		    //创建时间2，时分的计数
	INT16U wcrt_date;		    //创建日期
	INT16U wlast_acc_time;	    //最后访问时间，时分
	INT16U wfst_clus_hi;			//
	INT16U wwrt_time;		    //最后修改时间
	INT16U wwrt_date;		    //最后修改日期
	INT16U wfst_clus_lo;
	INT32U dwfile_size;		    //文件大小
}DIRECTORY_ENTRY_STRUCT;

typedef struct  //DirectoryEntryStructure
{
	INT8U badir_name[255];	    //长文件名 
	INT8U bdir_attr;			//文件属性
	INT8U bdir_rev;				//保留
	INT8U bcrt_time_tecth;		//创建时间1，秒的计数
	INT16U wcrt_time;		    //创建时间2，时分的计数
	INT16U wcrt_date;		    //创建日期
	INT16U wlast_acc_time;	    //最后访问时间，时分
	INT16U wfst_clus_hi;			//
	INT16U wwrt_time;		    //最后修改时间
	INT16U wwrt_date;		    //最后修改日期
	INT16U wfst_clus_lo;
	INT32U dwfile_size;		    //文件大小
}DIRECTORY_ENTRY_STRUCTEx;		//jack modify 2016-4-11  支持长文件名的目录结构

typedef struct
{
	INT16U	Flag;				//”DL”文件标志  0x444C
	INT16U	HeadLen;			//可变文件头大小
	INT32U	Count;				//结构体个数
	INT32U	FileSize;			//文件大小
	INT32U	Recv;				//保留4字节
} DIRECTORY_ENTRY_STRUCTExHead;	//jack modify 2016-4-11  支持长文件名的目录结构可变文件头


//****************************************************************************************************************
//**** 读取像点检测时，要用到的PixelInfo
//****************************************************************************************************************
typedef struct
{
	error_type Type;			//错误类型：ERROR_PIXEL，ERROR_SIGNAL	
	INT32U X;
	INT16U Y;
	INT8U  Result[100];
	INT8U  RecordDT[20];
	INT16U port;
}PixelInfo;

//****************************************************************************************************************
//**** 同步像点信息用到的结构体
//****************************************************************************************************************
typedef struct
{
	INT32U SignID;
	INT16U X;
	INT16U Y;
	INT8U  Result[100];
	INT8U  RecordDT[20];
	INT8U  Rev[8];
}SYPixelInfo;

//****************************************************************************************************************
//**** 读取事件信息，要用到的EventLogInfo
//****************************************************************************************************************
typedef struct
{
	INT32U EventType;
	INT32U Status;
	INT8U  DateTime[20];
	INT8U  Note[100];
}EventLogInfo;


//****************************************************************************************************************
//**** VPU的版本信息
//****************************************************************************************************************
typedef struct
{
	INT16U cpuVer;
	INT16U fpga1Ver;
	INT16U fpga2Ver;
	INT16U fpga3Ver;
	INT8U  sn[12];
}VPUVerInfo;


//****************************************************************************************************************
//**** 读取箱体信息时，要用到的TileInfo
//****************************************************************************************************************
typedef struct
{
	INT32U Address;
	INT32U X;
	INT32U Y;
	INT32U Width;
	INT32U Height;
	INT32U Brightness;
	INT32U Temperature;
	INT8U  CPUVersion[16];
	INT8U  FPGAVersion[16];
	INT32U FrameFrequency;
	INT8U  Fan[4];
	INT32U FanCurrentmA;
	INT32U PowerVoltage1V;
	INT32U PowerVoltage2V;
	INT8U  EthernetState[52];
	INT32U TimeInHighTemp;
	INT8U  SN[52];
	INT32U GammaIndex;
	INT32U Driver1Temp;
	INT32U Driver2Temp;
	INT32U Driver3Temp;
	INT32U Driver4Temp;
	INT8U  DriverInformation[52];
	INT8U  IAPState[52];
	INT8U  RecordDT[20];
}TileInfo;

//****************************************************************************************************************
//**** 巴西客户要求的第三方数据库记录文件,保存在server/outputLog中
//****************************************************************************************************************
typedef struct 
{
	INT8U  devName[256];
	INT8U  devGroupName[256];
	INT8U  ipAddr[32];
	INT8U  phoneNum[20];

	INT8U  isLive;
	INT8U  insideTemp;
	INT8U  outsideTemp;
	INT8U  brightPrecent;

	INT8U  beaconONOFF;
	INT8U  commType;
	INT16U port;

	INT32U pixelErrNum;

	INT8U  MsgChanged;
	INT8U  Rev[3];
	
	INT8U  msgGroup[128];
	INT8U  msgType[128];
	INT8U  msgName[128];
	INT8U  msgBody[1024];
}BAThirdInfo;

//****************************************************************************************************************
//**** 巴西客户要求的第三方数据库记录文件,保存在数据库中
//****************************************************************************************************************
typedef struct 
{
	INT8U VMS_Name[256];
	INT8U VMS_Group[256];
	INT8U IP_Address[32];
	INT8U Port[12];
	INT8U Communication[16];
	INT8U Cell_Phone_Number[20];
	INT8U Date_Time[20];
	INT8U Status[256];
	INT8U Message_Group[128];
	INT8U Message_Type[128];
	INT8U Message_SubType[128];
	INT8U Body_Of_Message[1024];

	INT8U MessageChanged[64];

}BAThirdInfoDB;

//****************************************************************************************************************
//**** 读显示屏状态时，要用到的signState
//****************************************************************************************************************
typedef struct
{
	INT8U  InsideTemp;             								//屏内温度,0-127正值,128-254负值-1*(X&0x7f),255无效
	INT8U  OutsideTemp;            								//屏外温度,0-127正值,128-254负值-1*(X&0x7f),255无效
	INT8U  Humidity ;              								//湿度
	INT8U  BrightPercent ;         								//亮度百分比
	
	INT8U  GPRSCSQ;                								//GPRS信号质量(0-31,31最好,99表示无信息)
	INT8U  RadarTargetDirection;   								//当前Radar目标方向
    INT16U BrightAD;                							//当前光控传感头读值
	
	INT16U BatVoltageMV ;           							//电池当前电压
	INT16U BackBatVoltageMV;        							//后背电池电压
	INT16U GPRSDistance;            							//GPRS距离,两个GPRS之间距离(米)
	INT16U RadarCurSpeed;          								//当前Radar速度值,kph	
	
	INT32U BatDayInMAH;             							//电池当天冲电总电量mAH
	INT32U BatDayOutMAH ;           							//电池当天放电总电量mAH
	
	INT32U CurINCurrentMA;         								//当前冲电电流
	INT32U DayInMAXCurrentMA;      								//当天最大冲电电流
	INT32U CurOutCurrentMA;        								//当前放电电流	
	
	INT32U ReceiveSMS;											//接收短息条数
	INT32U SendSMS;	                							//发送短息条数
	INT32U ReceiveSMSErr;	        							//接收短息错误次数
	INT32U SendSMSErr;		        							//发送短息错误次数
	
	INT32U SMSRecvFulls;            							//接收队列已满次数
	INT32U SMSSendFulls;            							//发送队列已满次数
	
	INT16U DataFlashKSize;         								//data flash 大小,单位为KB
	INT16U FramKSize;              								//铁RAM 大小,单位为KB
	
	//==================== GPS位置信息 ============================================================================
	INT8U  LongitudeInd;       									//经度方向,'E'=east or W=west
	INT8U  LatitudeInd;											//维度方向, N/S Indicator  'N'=north or 'S'=south
	INT8U  SateLliteNums;
	INT8U  Rev1;
	INT16U LongitudeDeg;										//经度(10进制度)
	INT16U LongitudeMin;										//经度- 分(10进制)
	INT16U LongitudeSec;										//经度- 秒(10进制)
	INT16U LatitudeDeg;											//维度(10进制度)
	INT16U LatitudeMin;											//维度 - 分(10进制)
	INT16U LatitudeSec;											//维度 - 秒(10进制)	
    //==================== 发电机状态信息 =========================================================================
	INT8U  GeneratorStatus;										//发电机状态信息
	INT8U  RadaExistFlag;										//雷达是否存在标志
	INT16S CurAjustValue;										//0x7ffff:表示没有矫正 0从CPU 负载电流测试 矫正值(分正负的)
	//==================== 系统状态 ===============================================================================
	INT8U  SysStatus;											//vms屏体类型信息
	INT8U  CommonInIO;											//通用IO端口状态（同发电机状态信息，只是这里在定时器中检测，提高检测速度）
	INT8U  BATStatus;											//电池状态 0:Perfect 1:good 2:bad     
	INT8U  BATRemCap;											//电池剩余容量 0%-100%
	INT8U  IsValidEquipState;									//后面4个字节的外接设备状态(有无连接，和好坏的状态)，1:表示有效，0：表示无效(默认值)
	INT16U IsConnEquipState;									//16个bit外接设备连接状态
	INT16U IsGoodEquipState;									//16个bit外接设备好坏的状态
}signState;

//****************************************************************************************************************
//**** 读取signLog信息时，要用到的SignLog
//****************************************************************************************************************
typedef struct
{
	INT32U Type;
	INT8U  Operate[100];
	INT8U  Author[52];
	INT8U  Result[200];
	INT8U  RecordDT[20];
}SignLog;

//****************************************************************************************************************
//**** 读取tempLog信息时，要用到的tempLog
//****************************************************************************************************************
typedef struct
{
	INT8U  BeginDT[20];
	INT8U  EndDT[20];
	INT32U OutHightTemp;
	INT32U OutLowTemp ;
	INT32U OutAvgTemp ;
	INT32U InHightTemp ;
	INT32U InLowTemp ;
	INT32U InAvgTemp ;
	INT32U BoxHightTemp ;
	INT32U BoxLowTemp ;
	INT32U BoxAvgTemp ;
}tempLog;

//****************************************************************************************************************
//**** 读取播放日志信息时，要用到的playLog
//****************************************************************************************************************
typedef struct
{
	INT32U PlayTimes;
	INT32U TotalSecond;
	INT32U WinID ;

	INT8U  FileName[256];
	INT8U  RecordDT[20];
	INT8U  GroupName[100] ;
}playLog;

//****************************************************************************************************************
//**** 读写Radar日志信息时，要用到的radarLog
//****************************************************************************************************************
typedef struct
{
	INT32U Speed;
	INT32U VehicleLen;
	INT8U  RecordDT[20];
}radarLog;

//****************************************************************************************************************
//**** 读写TJRadar日志信息时，要用到的TJRadarLog
//****************************************************************************************************************
typedef struct
{
	INT32U LaneIndex;
	INT32U Quantity1;
	INT32U Quantity2;
	INT32U AverSpeed1;
	INT32U AverSpeed2;
	INT32U MaxSpeed1;
	INT32U MaxSpeed2;
	INT32U MinSpeed1;
	INT32U MinSpeed2;
	INT8U  RecordDT[20];
}TJRadarLog;

//================================================================================================================
//==== 文件格式定义(文件头)充电板日志
//================================================================================================================
typedef struct
{
	INT16U ID;												//标志,'LG'=0x4c47
	INT16U RecordBytes;										//每条记录字节数,记录都一样大小
	INT32U RecordNums;										//当前记录条数
	INT32U WriteLoc;										//当前记录写入位置 第一条是0
	INT32U MaxRecordNums;									//最大记录条数
}BATINFO_HEAD;

//****************************************************************************************************************
//**** 主板中存放的充电板日志信息结构体，要用到的batinfoLog
//****************************************************************************************************************
typedef struct
{
	INT32U DateTime;			//当前记录时间(DOS时间格式)
	INT32U Charge_Capacity;		//当前充电电量		单位:mAH
	INT32U DisCharge_Capacity;	//当前放电电量		单位:mAH
	INT16U Vol_Battery;			//当前电池电压		单位:mV
	INT16U Vol_Solar;			//当前太阳电池板输出电压		单位:mV
	INT16U Cur_Solar;			//当前太阳能电池板输出电流		单位:mA

	INT8U LongitudeInd;  		//经度方向  'E'=east or W=west
	INT8U LatitudeInd;  		//维度方向, N/S Indicator  'N'=north or 'S'=south
	INT16U LongitudeDeg; 		//经度
	INT16U LongitudeMin; 		//经度- 分
	INT16U LongitudeSec; 		//经度- 秒
	INT16U LatitudeDeg;  		//维度
	INT16U LatitudeMin;			//维度 - 分
	INT16U LatitudeSec; 		//维度 - 秒
}BATINFOLOG_STRUCT;

//****************************************************************************************************************
//**** 读写充电板日志信息时，要用到的batinfoLog
//****************************************************************************************************************
typedef struct
{
	INT32U Charge_Capacity;		//当前充电电量		单位:mAH
	INT32U DisCharge_Capacity;	//当前放电电量		单位:mAH
	INT16U Vol_Battery;			//当前电池电压		单位:mV
	INT16U Vol_Solar;			//当前太阳电池板输出电压		单位:mV
	INT16U Cur_Solar;			//当前太阳能电池板输出电流		单位:mA

	INT8U LongitudeInd;  		//经度方向  'E'=east or W=west
	INT8U LatitudeInd;  		//维度方向, N/S Indicator  'N'=north or 'S'=south
	INT16U LongitudeDeg; 		//经度
	INT16U LongitudeMin; 		//经度- 分
	INT16U LongitudeSec; 		//经度- 秒
	INT16U LatitudeDeg;  		//维度
	INT16U LatitudeMin;			//维度 - 分
	INT16U LatitudeSec; 		//维度 - 秒
	INT8U  RecordDT[20];
}batinfoLog;

//****************************************************************************************************************
//**** 操作VMSradar日志要用到结构
//****************************************************************************************************************
typedef struct
{
	INT32U RadarLogNum;											//日志中存在的Radar条数
	INT32U RadarWriteloc;										//最近一次日志写入偏移坐标
	INT16U RadarLastDate;          								//最近一次Radar日志写入的日期	
	INT16U RadarLastTime;										//最近一次Radar日志写入的日期
}RARAD_EXLOGHEAD_STRUCT;


#define RADARLOGNUM						20

typedef  struct
{
	INT16U RadarSpeed[RADARLOGNUM];								//新的程序中，0表示速度，1表示车长度，后面的没有用
	INT16U RadarDate;											//Radar日志写入的日期	
	INT16U RadarTime;											//Radar日志写入的日期
}RARAD_EXLOG_STRUCT;

typedef struct
{
    INT8U  style1;												//[ 2 bytes]：车辆类型0：7-25.5
    INT8U  style2;												//[ 2 bytes]：车辆类型1：2-7
    INT8U  average1;   											//[ 4 bytes]: 平均速度
    INT8U  maxSpeed1;											//最大速度
    
    INT8U  minSpeed1;											//最小速度
    INT8U  average2;  											//[ 4 bytes]: 平均速度
    INT8U  maxSpeed2;											//最大速度
    INT8U  minSpeed2;											//最小速度   
    
    INT16U date;
    INT16U time;

    INT8U  addr; 
    INT8U  style3;												//车辆类型1：>25 ，<2
    INT16U statistics;											// 所有通过的车子数目
}TJRADAR_CTRL;

//****************************************************************************************************************
//**** 控制机错误级别
//****************************************************************************************************************
#define WARING_LEVEL_CRITICAL			1						//非常严重
#define WARING_LEVEL_SERIOUS			2						//严重
#define WARING_LEVEL_PROBLEM			3						//一般问题
#define WARING_LEVEL_WARING				4						//警告

//****************************************************************************************************************
//**** 显示屏报警／控制机错误日志
//****************************************************************************************************************
typedef struct
{
	INT32U WaringLevel;
	INT8U  RecordDT[20];
	INT8U  Name[100];
	INT8U  WaringMSG[256];
}WaringLog;

//****************************************************************************************************************
//**** 控制机温度日志
//****************************************************************************************************************
typedef struct
{	
	INT8U  RecordDT[20];
    INT8U  Name[100];
	INT32U Temp;
	INT32U Type;
}TCTempLog;

//================================================================================================================
//==== 扩展命令文件的文件头格式定义
//================================================================================================================
struct CMDFileHead
{
	INT16U Flag;												//标志, "CM"
	INT16U Ver;													//版本号,目前为1
	INT32U MainCMD;												//大类命令
	INT32U SubCMD;												//小类命令
	INT32U Rev;													//保留
	INT8U  Description[100];									//命令描述，主要用于日志	
};

//================================================================================================================
//====Test  functions
//================================================================================================================
#define  CZ_TEST_PATTERN_AUTO			2						//auto test
#define  CZ_TEST_PATTERN_ALL_ON			3						//ALL ON
#define  CZ_TEST_PATTERN_RED_ON			4						//red on	
#define  CZ_TEST_PATTERN_GREEN_ON		5						//green on
#define  CZ_TEST_PATTERN_BLUE			6						//blue on
#define  CZ_TEST_PATTERN_HORIZONTAL		7						//Horizontal
#define  CZ_TEST_PATTERN_VERTICAL		8						//Vertical


//================================================================================================================
//====imposa tool Tile Test  functions
//================================================================================================================
#define  CZ_IMPOSA_TILETEST_ROWSCAN		0						//LINE SCAN
#define  CZ_IMPOSA_TILETEST_COLSCAN		1						//COL SCAN
#define  CZ_IMPOSA_TILETEST_R			2						//red on	
#define  CZ_IMPOSA_TILETEST_G			3						//green on
#define  CZ_IMPOSA_TILETEST_B			4						//blue on
#define  CZ_IMPOSA_TILETEST_W			5						//w
#define  CZ_IMPOSA_TILETEST_AUTO		6						//auto
#define  CZ_IMPOSA_TILETEST_END			7						//end test
#define  CZ_IMPOSA_TILETEST_INFO		8						//show info
#define  CZ_IMPOSA_TILETEST_BLANK		9						//blank
#define  CZ_IMPOSA_TILETEST_CON			16						//Coeffient on
#define  CZ_IMPOSA_TILETEST_COFF		17						//Coeffient off


//================================================================================================================
//==== 扩展命令定义,MainCMD
//================================================================================================================
#define FILECMD_M_WRITE					1

//================================================================================================================
//==== 扩展命令定义,SubCMD
//================================================================================================================
#define FILECMD_S_WRITEFILELST			1


//================================================================================================================
//====  第四种播放列表定义的结构体
//================================================================================================================
typedef  struct{
	INT16U year;       							/* 年，大小为2B, 2000年用数值0x2000 表示(BCD码表示)				*/
	INT8U  month;      							/* 月，大小为1B,1-12月，分别用数值0x01-0x12表示(BCD码表示) 		*/
	INT8U  day;        							/* 日，大小为1B,1-31日，分别用数值0x01-0x031表示(BCD码表示)		*/
	INT8U  hour;       							/* 小时，大小为1B, 0-23时，分别用数值0x0-0x23表示(BCD码表示)	*/
	INT8U  minute;    							/* 分钟，大小为1B, 0-59分，分别用数值0x00-0x59表示(BCD码表示)	*/
	INT8U  date_valid; 							/* 为真的时候(非0)，忽略日期，否则日期有效, 大小为1B			*/ 
	INT8U  time_valid; 							/* 为真的时候(非0)，忽略时间，否则时间有效, 大小为1B		    */
}DATE_TIME_STRUCT;

typedef struct
{
	INT16U wID;													//SQ
	INT8U  bType;       										//类型
	INT8U  bFlag;       										//有效标志位	
	INT16U wFileNum;    										//参加调度的文件个数
	INT16U wRev;        										//保留
}SEQUENT_FILE_HEAD;	
//================================================================================================================
//====                        第4种列表结构
//================================================================================================================
typedef struct
{
	INT8U  bdrive;												//分区号
	INT8U  btype;												//播放文件类型：TEXT用T表示， ARRAY PICTURE 用 A 表示
	INT8U  bfile_label;											//文件名（FILE LABEL）
	INT8U  bweek_rep;											//重复星期， 在后面有详细解析
	DATE_TIME_STRUCT sbegin_data_time;							//日期结构体，后面解析开始日期时间
	DATE_TIME_STRUCT send_data_time;							//结束日期时间
	INT16U dwcheck_sum;											//没用到
	INT16U dwfile_size;											//没用到
	INT8U bafile_name[12];										//文件名 8.3格式
}FULL_SEQUENT_FILE_STRUCT;

//================================================================================================================
//====                        第5种列表时段控制结构
//================================================================================================================
typedef struct
{
	INT8U bweek_rep;								//重复星期
	INT8U Rev;										//保留
	DATE_TIME_STRUCT sbegin_data_time;				//日期结构体，后面解析开始日期时间
	DATE_TIME_STRUCT send_data_time;				//结束日期时间
}SEQUENT5_TIME_STRUCT;

//================================================================================================================
//====                        第5种列表记录控制结构
//================================================================================================================
typedef struct
{
	INT16U ID;										//类型,分组='GP',文件项='FS'
	INT16U Len;    									//后面数据长度
	INT16U ItemNum;									//数据项个数
	INT8U  PlayArg;									//播放参数,对于分组来说是播放类型,对于文件项来说是播放次数
	INT8U  HeadSize;								//控制结构头大小
	INT32U Rev;										//对于分组来说是保留,对于文件项来说是文件大小(PC用)
	INT8U  Name[32];								//对于文件项来说是路径,对于分组来说是组名
}SEQUENT5_FILE_STRUCT;

//================================================================================================================
//====                        第6种列表记录控制结构
//================================================================================================================
typedef struct
{
	INT16U ID;										//类型,分组='GP',文件项='FS'
	INT16U Len;    									//后面数据长度
	INT16U ItemNum;									//数据项个数
	INT8U  PlayArg;									//播放参数,对于分组来说是播放类型,对于文件项来说是播放次数
	INT8U  WinID;								    //窗口ID，对文件有效
	INT32U HeadSize;								//控制结构头大小
	INT8U  GroupType;								//0为根文件夹   1为二级文件夹
	INT8U  RootIndex;								//根文件夹：根索引  ； 二级文件夹：所属根文件夹索引
	INT16U Rev1;									//对于分组来说是保留,对于文件项来说是文件大小(PC用)
}SEQUENT6_FILE_STRUCT;

//================================================================================================================
//====  list file info.
//================================================================================================================
typedef  struct
{
	INT8U fileName[256];							//文件名
	INT8U schCount;									//调度个数
	INT8U playTimes;								//播放次数
	INT8U Drive;									//屏上的哪个盘, D, F
	INT8U  Type;									//文件类型，T,P

	INT16U PicStaySec;								//停留时间
	INT8U  PicInMode;								//入模式
	INT8U  PicOutMode;								//出模式

	SEQUENT5_TIME_STRUCT sch[256];
	INT8U pcFileName[512];							//pc端带路径的文件名
}CZPLAYLIST_FILE_INFO;

typedef struct
{
	INT8U ItemType;									//节点类型	0：文件夹	1：文件
	INT8U ItemName[256];							//节点名
}CZPLAYLIST_ITEM;

//================================================================================================================
//====  PLS文件处理要用到的结构体
//================================================================================================================
typedef struct
{
	INT32U DataSize;       										//数据大小
	INT8U  bType;       										//类型,T=Text file, A=Array picture
	INT8U  bWeek;       										//调度星期
	INT16U Rev;    												//保留
	DATE_TIME_STRUCT dts;
	DATE_TIME_STRUCT dte;
	INT8U  fileName[64];
}PLS_Item;

//================================================================================================================
//====  PLM文件处理要用到的调度结构体
//================================================================================================================
typedef struct
{
	INT8U  bType;       										//类型,T=Text file, A=Array picture
	INT8U  Rev[3];    											//保留
	DATE_TIME_STRUCT dts;
	DATE_TIME_STRUCT dte;
}PLM_DT_Item;

//================================================================================================================
//====  bmp RC结构定义
//================================================================================================================
typedef struct
{	
	INT8U  ID;													//资源类型,1表示图片
	INT8U  FileLabel;											//资源文件名，调用时使用
	INT16U Rev1;												//保留
	INT32U size;												//资源文件大小
	INT32U Position;											//资源文件在TEXT FILE文件中的相对偏移地址
	INT16U Rev2[12];											//保留2
}BMPRC;

//================================================================================================================
//====  错误报告错误信息结构体
//================================================================================================================
typedef struct
{	
	error_type type;											//错误类型
	INT8U x;													//错误箱体所在列数，从0开始
	INT8U y;													//错误箱体所在行数，从0开始
	INT8U problem[64];											//问题
	INT8U description[256];										//问题描述
	INT8U time[64];												//时间
}ERROR_INFO_STRUCT;


#pragma pack(push) 
#pragma pack(1) 
//================================================================================================================
//==== 停车场屏区域设置头
//================================================================================================================
typedef struct 
{
	INT8U	BGColor_R;            								//帧背景色红
	INT8U	BGColor_G;											//帧背景色绿
	INT8U	BGColor_B;											//帧背景色蓝
	INT8U	ZoneNum;   											//需要设置的区域的数量
	INT16U	PageStayTime;   									//帧停留时间，单位：10ms，0为无限循环显示
	INT8U	PortraitMode;										//0:横向(默认)   1:竖向
	INT8U	Rev;
}ZoneSetHead;

//================================================================================================================
//==== 停车场屏区域设置
//================================================================================================================
typedef struct 
{
	INT8U	ZoneID;            									//区域ID
	INT8U	Rev[3];												//保留
	INT16U	XPos;												//X坐标					
	INT16U	YPos;   											//Y坐标
	INT16U	ZoneWidth;   										//区域宽度
	INT16U	ZoneHeight;    										//区域高度
}ZoneSet;

//================================================================================================================
//==== 停车场屏特殊区域设置(全点阵中四个角黄闪灯)
//================================================================================================================
typedef struct 
{
	INT8U	SpeZoneID;            								//特殊区域ID
	INT8U	PicID;												//图片ID
	INT8U	FreshPattern;										//闪烁花样					
	INT8U	Rev;   												//保留
	INT16U	FlashHZ;   											//闪烁的频率
	INT16U	ZoneNum;   											//区域个数
	INT16U	ZoneWidth;   										//区域宽度
	INT16U	ZoneHeight;    										//区域高度
}SpeZoneSet;

//================================================================================================================
//==== 停车场屏特殊区域XY坐标(全点阵中四个角黄闪灯)
//================================================================================================================
typedef struct 
{
	INT16U	ZoneX;   										//区域宽度
	INT16U	ZoneY;    										//区域高度
}SpeZoneXY;

//================================================================================================================
//==== 停车场屏帧区域显示设置
//================================================================================================================
typedef struct 
{
	INT16U	ZoneSize;          									//区域显示数据大小
	INT8U	ZoneID;												//区域ID
	INT8U	ZoneType;											//内容类型	0:文字; 1:图片; 2:特殊对象					
	INT8U	CodeType;   										//编码类型	0:单字节(ASCII码)  1:双字节(Unicode编码)
	INT8U	InMode;   											//入花样
	INT8U	OutMode;    										//出花样
	INT8U	Align;												//水平垂直对齐	[7:4]：垂直方向  [3:0]: 水平方向
	INT8U	FGColor_R;											//内容前景色红
	INT8U	FGColor_G;											//内容前景色绿
	INT8U	FGColor_B;											//内容前景色蓝
	INT8U	BGColor_R;											//内容背景色红
	INT8U	BGColor_G;											//内容背景色绿
	INT8U	BGColor_B;											//内容背景色蓝
	INT8U	AutoLine;											//自动换行
	INT8U	AutoWidth;											//变宽字体	0:等宽字体  1：非等宽字体
	INT16U	Speed;												//花样速度  n pixels per 10ms
	INT8U	StayTime;											//停留时间  单位秒，0:无限循环显示
	INT8U	Times;												//播放次数	0:无限循环显示
	INT8U	FontStyle;											//字体Index
	INT8U	LineSpace;											//行间距
	INT8U	CloumnSpace;										//列间距
	INT8U	Rev;												//保留
	INT16U	BlinkOnTime;										//闪烁亮的时间(单位:10ms)
	INT16U	BlinkOffTime;										//闪烁灭的时间(单位:10ms)
	INT16U	ContentSize;										//内容数据的长度
	INT8U	Rev2[2];											//保留2
}ZoneDisplaySet;

//================================================================================================================
//==== 停车场屏帧区域显示内容设置
//================================================================================================================
typedef struct 
{
	INT16U	ZoneSize;            								//区域显示内容大小
	INT8U	ZoneID;												//区域ID
	INT8U	CodeType;											//编码类型	0:单字节(ASCII码)  1:双字节(Unicode编码)					
	INT8U	ZoneType;   										//内容类型	0:文字; 1:图片; 2:特殊对象	
	INT8U	Rev;   												//保留
	INT16U	ContentSize;    									//内容数据长度
}ZoneDisplayContentSet;
#pragma pack(pop) 

//================================================================================================================
//====  音频播放控制结构定义
//================================================================================================================
typedef struct
{	
	INT8U  BuzzerSwitch;										//蜂鸣器开关	1=播放音频文件	0=停止播放
	INT8U  PlayTimes;											//播放次数		0xFF=循环播放	1=播放一次	2=播放两次
	INT8U  Rev[6];												//保留2
}SoundST;

//================================================================================================================
//====  默认画面设置结构定义
//================================================================================================================
typedef struct
{	
	INT16U  ShowDefaultBmpTime;									//单位秒,未收到JetFileII消息,显示默认图片;TE18-233合同
	INT16U  BlackScreenTime;									//单位秒,显示默认图片切换到黑屏的时间;TE18-233合同
}DefScreenSetST;


//================================================================================================================
//==== 报警日志文件头
//================================================================================================================
typedef struct 
{
	INT16U	ID;            										//标志头	‘LG’=0x4C47
	INT16U	RecordBytes;										//每条记录字节数，当前记录的大小统一为32
	INT32U	RecordNums;											//当前记录条数
	INT32U	WriteLocation;   									//当前记录写入位置
	INT32U	MaxRecordNums;   									//最大记录条数	当前主板为1000
}CZLog_File_Head;

//================================================================================================================
//==== 报警日志数据
//================================================================================================================
#pragma pack(push) 
#pragma pack(1) 
typedef struct 
{
	INT32U	DataTime;
	INT8U	AlarmType;            								//报警类型，0='DoorOpen'	1='HighTemp'	2='PixelError'	3='Crash'碰撞
	INT8U	AlarmStatus;										//状态，1=‘OCCUR’状态发生	0=‘CLEAR’状态清除
	INT32U	AlarmValue;											//AlarmType=1或者2时有效
	INT8U	Rev[22];
}CZLogDataST;
#pragma pack(pop) 


//================================================================================================================
//====  API Server屏列表结构定义
//================================================================================================================
typedef struct
{	
	INT16U  Port;										//跟API Server通讯时用到的端口
	INT16U  Rev;										//保留
	INT8U	NumberID[64];								//Modem中配置的ID
}CZAPISignST;

//================================================================================================================
//====  共用inline函数
//================================================================================================================
inline INT8U bcd2bin(INT8U c) {return (INT8U)(((c>>4)&0x0f)*10) + (c&0x0f);}
inline INT8U bin2bcd(INT8U c) {return (INT8U)(((c/10)<<4)+(c%10));}

const INT8U MonthDays[2][12] =
{
{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
{31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};






#ifdef __cplusplus
}
#endif


#endif 