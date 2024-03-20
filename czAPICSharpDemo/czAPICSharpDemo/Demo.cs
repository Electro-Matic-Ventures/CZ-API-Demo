using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Runtime.InteropServices;
using System.Threading;
using System.Diagnostics;
using System.IO;
using System.Globalization;
using Demo;

namespace czAPICSharpDemo
{
    class Demo
    {
        [StructLayout(LayoutKind.Sequential, Pack = 1)]
        public struct DIRECTORY_ENTRY_STRUCT_JETFILEII
        {
            //这个结构没有结束符
            [MarshalAs(UnmanagedType.ByValArray, SizeConst = 11)]
            public byte[] badir_name;
            public byte bdir_attr;
            public byte bdir_rev;
            public byte bcrt_time_tecth;
            public UInt32 wcrt_time;
            public UInt32 wcrt_date;
            public UInt32 wlast_acc_time;
            public UInt32 wfst_clus_hi;
            public UInt32 wwrt_time;
            public UInt32 wwrt_date;
            public UInt32 wfst_clus_lo;
            public UInt32 dwfile_size;
        }

        [StructLayout(LayoutKind.Sequential, Pack = 1)]
        public struct GRAY_TEST_PARAM
        {
            public uint Type;
            public uint Red;
            public uint Green;
            public uint Blue;
            public uint Level;
        }

        [StructLayout(LayoutKind.Sequential, Pack = 1)]
        public struct czBrightInfoExt
        {
            public Byte BrightType;
            public Byte BrightPrecent1;
            public UInt16 BrightSensorAD1;
            public Byte Rev;
            public Byte BrightPrecent2;
            public UInt16 BrightSensorAD2;
        }

        [StructLayout(LayoutKind.Sequential, Pack = 1)]
        public struct ZoneSetHead
        {
            public Byte BGColor_R;                                            //帧背景色红
            public Byte BGColor_G;                                            //帧背景色绿
            public Byte BGColor_B;                                            //帧背景色蓝
            public Byte ZoneNum;                                              //需要设置的区域的数量
            public UInt16 PageStayTime;                                    //帧停留时间，单位：10ms，0为无限循环显示
            public Byte PortraitMode;                                     //0:横向(默认)   1:竖向
            public Byte Rev;
        }

        [StructLayout(LayoutKind.Sequential, Pack = 1)]
        public struct ZoneSet
        {
            public byte ZoneID;                                               //标识 固定为:NG(4EH,47H)
            [MarshalAs(UnmanagedType.ByValArray, SizeConst = 3)]
            public byte[] Rev;
            public UInt16 XPos;                                                //X坐标					
            public UInt16 YPos;                                            //Y坐标
            public UInt16 ZoneWidth;                                           //区域宽度
            public UInt16 ZoneHeight;    										//区域高度
        }

        [StructLayout(LayoutKind.Sequential, Pack = 1)]
        public struct ZoneDisplaySet
        {
            public UInt16 ZoneSize;                                            //区域显示数据大小
            public Byte ZoneID;                                               //区域ID
            public Byte ZoneType;                                         //内容类型	0:文字; 1:图片; 2:特殊对象					
            public Byte CodeType;                                         //编码类型	0:单字节(ASCII码)  1:双字节(Unicode编码)
            public Byte InMode;                                               //入花样
            public Byte OutMode;                                          //出花样
            public Byte Align;                                                //水平垂直对齐	[7:4]：垂直方向  [3:0]: 水平方向
            public Byte FGColor_R;                                            //内容前景色红
            public Byte FGColor_G;                                            //内容前景色绿
            public Byte FGColor_B;                                            //内容前景色蓝
            public Byte BGColor_R;                                            //内容背景色红
            public Byte BGColor_G;                                            //内容背景色绿
            public Byte BGColor_B;                                            //内容背景色蓝
            public Byte AutoLine;                                         //自动换行
            public Byte AutoWidth;                                            //变宽字体	0:等宽字体  1：非等宽字体
            public UInt16 Speed;                                               //花样速度  n pixels per 10ms
            public Byte StayTime;                                         //停留时间  单位秒，0:无限循环显示
            public Byte Times;                                                //播放次数	0:无限循环显示
            public Byte FontStyle;                                            //字体Index
            public Byte LineSpace;                                            //行间距
            public Byte CloumnSpace;                                      //列间距
            public Byte Rev;                                              //保留
            public UInt16 BlinkOnTime;                                     //闪烁亮的时间(单位:10ms)
            public UInt16 BlinkOffTime;                                        //闪烁灭的时间(单位:10ms)
            public UInt16 ContentSize;                                     //内容数据的长度
            [MarshalAs(UnmanagedType.ByValArray, SizeConst = 2)]
            public Byte[] Rev2;                                          //保留2
        }

        [StructLayout(LayoutKind.Sequential, Pack = 1)]
        public struct ZoneDisplayContentSet
        {

            public UInt16 ZoneSize;                                            //区域显示内容大小
            public Byte ZoneID;                                               //区域ID
            public Byte CodeType;                                         //编码类型	0:单字节(ASCII码)  1:双字节(Unicode编码)					
            public Byte ZoneType;                                         //内容类型	0:文字; 1:图片; 2:特殊对象	
            public Byte Rev;                                                  //保留
            public UInt16 ContentSize;                                     //内容数据长度
        }

        //================================================================================================================
        //====                        默认配置结构体声明
        //================================================================================================================
        [StructLayout(LayoutKind.Sequential, Pack = 1)]
        public struct DEFAULT_SET
        {
            public UInt16 ID;                                                  //55aa
            public Byte PlayListLoc;                                          //播放列表保存位置
            public Byte TimePre0En;                                           //时间前置0,如果是1表示时间没有前置0

            public Byte Ddrive;                                               //默认盘
            public Byte Dback_color;                                          //默认背景色
            public Byte Dfont_color;                                          //默认前景色
            public Byte Dhor_just;                                            //水平对齐

            public Byte Dver_just;                                            //垂直对齐
            public Byte Dline_space;                                          //行间距
            public Byte Dfont;                                                //字体
            public Byte Din_mode;                                             //入模式

            public Byte Dout_mode;                                            //出模式
            public Byte Dspeed;                                               //速度
            public Byte Dstay_time;                                           //停留时间
            public Byte Dwrap;                                                //自动换行

            public UInt32 Lstay_time;                                          //长停留时间,当Dstay_Time为0时,用这个值

            public Byte TimeFormat;
            public Byte HeadTailPlayMode;
            public Byte HeadTailMoveDirection;
            public Byte HeadTailMoveSpeed;

            public Byte HeadTailPauseTime;
            public Byte Play_num;                                             //循环播放播放列表的次数, 0表示永久播放, 播放完后黑屏
            public UInt16 Version;                                             //版本号,从0xAAF1开始, Add 2017/9/12

            public UInt16 ShowDefaultBmpTime;                                  //单位秒,未收到JetFileII消息,显示默认图片;TE18-233合同
            [MarshalAs(UnmanagedType.ByValArray, SizeConst = 22)]
            public Byte[] rev;
        }

        [StructLayout(LayoutKind.Sequential, Pack = 1)]
        public struct CZLog_File_Head
        {
            public UInt16 ID;                                                  //标志头	‘LG’=0x4C47
            public UInt16 RecordBytes;                                     //每条记录字节数，当前记录的大小统一为32
            public UInt32 RecordNums;                                          //当前记录条数
            public UInt32 WriteLocation;                                       //当前记录写入位置
            public UInt32 MaxRecordNums;                                       //最大记录条数	当前主板为1000
        }

        [StructLayout(LayoutKind.Sequential, Pack = 1)]
        public struct CZLogDataST
        {
            public UInt32 DataTime;
            public Byte AlarmType;                                            //报警类型，0='DoorOpen'	1='HighTemp'	2='PixelError'	3='Crash'碰撞
            public Byte AlarmStatus;                                      //状态，1=‘OCCUR’状态发生	0=‘CLEAR’状态清除
            public UInt32 AlarmValue;                                          //AlarmType=1或者2时有效
            [MarshalAs(UnmanagedType.ByValArray, SizeConst = 22)]
            public Byte[] rev;
        }

        [DllImport("czJetFileII.dll", CharSet = CharSet.Ansi)]
        public extern static uint czCrayTest(ref GRAY_TEST_PARAM grayParam);

        [DllImport("czJetFileII.dll", CharSet = CharSet.Ansi)]
        public extern static uint czStopTest();

        #region Win32API
        [DllImport("msvcrt.dll", CallingConvention = CallingConvention.Cdecl)]
        static extern int vsprintf(StringBuilder buffer, string format, IntPtr ptr);

        [DllImport("msvcrt.dll", CallingConvention = CallingConvention.Cdecl)]
        static extern int _vscprintf(string format, IntPtr ptr);

        #endregion

        #region constant

        const String TEST_SIGN_IP = "169.254.18.183";
        const String TEST_SIGN_COM = "COM13";
        const UInt32 TEST_SIGN_COM_BAUDRATE = 19200;
        const UInt16 TEST_SIGN_COM_GGUU = 0x0101;
        const UInt32 CZ_MODE_MOVEUP = 0x35;
        const UInt32 CZ_MODE_RAND = 0x2F;
        const UInt32 CZ_FONT_EN_14x8 = 0x32;
        const UInt32 CZ_FONT_ENB_16x12 = 0x50;
        const UInt32 CZ_FONT_EN_16x9 = 0x34;
        const UInt32 CZ_FONT_EN_7x6 = 0x31;
        const UInt32 CZ_FONT_EN_5x5 = 0x30;
        const UInt32 CZ_COLOR_AMBER = 0x33;
        const UInt32 CZ_MODE_STATIC = 0x30;
        const UInt32 CZ_FONT_CH_ST_16x16 = 0x35;
        const UInt32 TEST_IPCOUNT = 2;
        const UInt32 CZ_ERROR_OK = 0x0;
        const UInt32 MAX_ZONE_COUNT = 9;
        const Int32 PARK_SLEEP_TIME = 3000;
        const UInt32 MAX_PATH = 255;

        public readonly static int CZ_ENCODING_GB2312 = 0;
        public readonly static int CZ_ENCODING_UNICODE = 1;
        #endregion

        #region Struct

        /// <summary>
        /// Init Struct
        /// </summary>
        [StructLayout(LayoutKind.Sequential, Pack = 1)]
        public struct czinterface
        {
            public enum conn_type
            {
                COMM_UDP,
                COMM_TCP,
                COMM_COM
            }

            [UnmanagedFunctionPointer(CallingConvention.Cdecl)]
            public delegate void PreCommFun(ref czinterface inter);

            [UnmanagedFunctionPointer(CallingConvention.Cdecl)]
            public delegate void PostCommFun(ref czinterface inter);

            [UnmanagedFunctionPointer(CallingConvention.Cdecl)]
            public delegate void UpdateStatusFun(ref czinterface inter, UInt32 code, UInt32 precent);

            [UnmanagedFunctionPointer(CallingConvention.Cdecl)]
            public delegate UInt32 ReadFun(IntPtr par, StringBuilder buf, UInt32 size, UInt32 timeoutms);

            [UnmanagedFunctionPointer(CallingConvention.Cdecl)]
            public delegate UInt32 WriteFun(IntPtr par, String buf, UInt32 size);

            [UnmanagedFunctionPointer(CallingConvention.Cdecl)]
            public delegate void LogFun(ref czinterface inter, string file, int line, int level, string format, IntPtr args);

            [UnmanagedFunctionPointer(CallingConvention.Cdecl)]
            public delegate void CurShowFilterFun(ref czinterface inter, String srcfile, String dstfile, int frames, int delays);

            [UnmanagedFunctionPointer(CallingConvention.Cdecl)]
            public delegate void GetTemporaryPath(ref czinterface inter, String store_path, UInt32 max_path);

            public conn_type type;
            public UInt32 inited;
            [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 32)]
            public String ip;
            [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 16)]
            public String com;
            public UInt32 port;
            public UInt32 baudrate;
            public IntPtr signPointer;
            public IntPtr taskPointer;
            public UInt16 SrcAddr;
            public UInt16 DstAddr;
            public UInt32 Retry;
            public UInt32 Timeoutms;
            public UInt32 Stoped;
            public UInt16 totalSteps;
            public UInt16 curSteps;
            public UInt16 packetSize;
            [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 26)]
            public String Rev;

            public PreCommFun pre_comm;
            public PostCommFun post_comm;
            public UpdateStatusFun update_status;
            public ReadFun read;
            public WriteFun write;
            public LogFun log;
            public CurShowFilterFun curShowFilter;
            public GetTemporaryPath getTemporaryPath;
        }

        /// <summary>
        /// Current State Struct
        /// </summary>
        [StructLayout(LayoutKind.Sequential, Pack = 1)]
        public struct CURRENT_STATE
        {
            public Byte sysState;
            public Byte inTemp;
            public Byte outTemp;
            public Byte AutoPower;
            public Byte Humidity;
            public Byte Samples;
            public Byte BrightLevel;
            public Byte Rev;
        }

        [StructLayout(LayoutKind.Sequential, Pack = 1)]
        public struct COMMUNICATICON_ST
        {
            [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 32)]
            public String ip;
            public UInt16 CustomPort;
            public Byte GroupAddr;
            public Byte UnitAddr;
            [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 32)]
            public String GatewayAddr;
            [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 32)]
            public String SubnetMaskAddr;
            [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 16)]
            public String Rev;
        }

        [StructLayout(LayoutKind.Sequential, Pack = 1)]
        public struct DIRECTORY_ENTRY_STRUCT
        {
            [MarshalAs(UnmanagedType.ByValArray, SizeConst = 11)]
            public char[] badir_name;
            public byte bdir_attr;
            public byte bdir_rev;
            public byte bcrt_time_tecth;
            public UInt16 wcrt_time;
            public UInt16 wcrt_date;
            public UInt16 wlast_acc_time;
            public UInt16 wfst_clus_hi;
            public UInt16 wwrt_time;
            public UInt16 wwrt_date;
            public UInt16 wfst_clus_lo;
            public UInt32 dwfile_size;
        }

        [StructLayout(LayoutKind.Sequential, Pack = 1)]
        public struct SoundST
        {
            public Byte BuzzerSwitch;                                     //蜂鸣器开关	1=播放音频文件	0=停止播放
            public Byte PlayTimes;                                            //播放次数		0xFF=循环播放	1=播放一次	2=播放两次
            [MarshalAs(UnmanagedType.ByValArray, SizeConst = 6)]
            public UInt16[] Rev;                                              //保留2
        }

        [StructLayout(LayoutKind.Sequential, Pack = 1)]
        public struct BEACON_ST
        {
            Byte R;                                                    //0xFF 关闭,0x01亮
            Byte Y;
            Byte G;
            Byte Mode;
            [MarshalAs(UnmanagedType.ByValArray, SizeConst = 4)]
            Byte[] Rev;
        }

        #endregion

        #region Interface

        [DllImport("czJetFileII.dll", CharSet = CharSet.Ansi)]
        public extern static UInt32 czInitAPI(ref czinterface czif);

        [DllImport("czJetFileII.dll", CharSet = CharSet.Ansi)]
        public extern static UInt32 czReadCurrentState(ref CURRENT_STATE State, IntPtr ExtData, UInt32 DataSize);

        [DllImport("czJetFileII.dll", CharSet = CharSet.Ansi)]
        public extern static UInt32 czWriteSpecFile(String SpecialFile, String PCPath);

        [DllImport("czJetFileII.dll", CharSet = CharSet.Ansi)]
        public extern static UInt32 czReadSpecPathFile(String SpecialFile, String PCPath);

        [DllImport("czJetFileII.dll", CharSet = CharSet.Ansi)]
        public extern static UInt32 czImposaGetTileStat(UInt16 tileAddr, ref UInt32 rtCode);

        [DllImport("czJetFileII.dll", CharSet = CharSet.Ansi)]
        public extern static UInt32 czImposaGetResult(UInt32 rtCode, StringBuilder result, UInt32 size, ref UInt16 resultCode);

        [DllImport("czJetFileII.dll", CharSet = CharSet.Ansi)]
        public extern static UInt32 czShowFiles(String[] files, UInt32 numFiles, UInt32 mode, UInt32 stayTimeSec,
                                    String signIp, UInt32 signPort, UInt32 isStoreRam = 0);

        [DllImport("czJetFileII.dll", CharSet = CharSet.Ansi)]
        public extern static UInt32 czShowFilesEx(String[] files, UInt32 numFiles, UInt32 mode, UInt32 stayTimeSec,
                                    String signIp, UInt32 signPort, UInt32 isStoreRam = 0,
                                    czinterface.conn_type type = czinterface.conn_type.COMM_UDP, String comStr = "COM3", UInt32 baudrate = 9600, UInt32 dstAddr = 0x0101);

        [DllImport("czJetFileII.dll", CharSet = CharSet.Ansi)]
        public extern static UInt32 czShowFilesSpe(String[] files, UInt32 numFiles, UInt32 mode, UInt32 stayTimeSec,
                                    String signIp, UInt32 signPort, UInt32 isStoreRam = 0,
                                    czinterface.conn_type type = czinterface.conn_type.COMM_UDP, String comStr = "COM3",
                                    UInt32 baudrate = 9600, UInt32 dstAddr = 0x0101, Byte sendType = 0);

        [DllImport("czJetFileII.dll", CharSet = CharSet.Ansi)]
        public extern static UInt32 czShowPic(Byte[] bitmap, UInt32 bmpSize, UInt32 mode, UInt32 stayTimeSec,
                                    String signIp, UInt32 signPort, UInt32 isStoreRam = 0);

        [DllImport("czJetFileII.dll", CharSet = CharSet.Ansi)]
        public extern static UInt32 czShowPicEx(Byte[] bitmap, UInt32 bmpSize, UInt32 mode, UInt32 stayTimeSec,
                                    String signIp, UInt32 signPort, UInt32 isStoreRam = 0,
                                    czinterface.conn_type type = czinterface.conn_type.COMM_UDP, String comStr = "COM3", UInt32 baudrate = 9600, UInt32 dstAddr = 0x0101);

        [DllImport("czJetFileII.dll", CharSet = CharSet.Ansi)]
        public extern static UInt32 czShowMsg(Byte[] msg, UInt32 msgSize, UInt32 font, UInt32 color, UInt32 mode,
                                  UInt32 stayTimeSec, String signIp, UInt32 signPort, UInt32 isStoreRam = 0,
                                  UInt32 isSendPlaylist = 1);

        [DllImport("czJetFileII.dll", CharSet = CharSet.Ansi)]
        public extern static UInt32 czShowMsgEx(String msg, UInt32 msgSize, UInt32 font, UInt32 color, UInt32 mode,
                                    UInt32 stayTimeSec, String signIp, UInt32 signPort, UInt32 isStoreRam = 0,
                                    UInt32 isSendPlaylist = 1,
                                    czinterface.conn_type type = czinterface.conn_type.COMM_UDP, String comStr = "COM3", UInt32 baudrate = 9600, UInt32 dstAddr = 0x0101);

        [DllImport("czJetFileII.dll", CharSet = CharSet.Ansi)]
        public extern static UInt32 czShowFilesII(String[] files, UInt32 numFiles, Byte[] stay_time_sec, UInt32 mode,
                                    String signIp, UInt32 signPort, UInt32 isStoreRam = 0,
                                    czinterface.conn_type type = czinterface.conn_type.COMM_UDP, String comStr = "COM3",
                                    UInt32 baudrate = 9600, UInt32 dstAddr = 0x0101, Byte sendType = 0);

        [DllImport("czJetFileII.dll", CharSet = CharSet.Ansi)]
        public extern static IntPtr czErrorDesc(UInt32 errCode);

        [DllImport("czJetFileII.dll", CharSet = CharSet.Ansi)]
        public extern static UInt32 czBrightAdjust(UInt16 bright);

        [DllImport("czJetFileII.dll", CharSet = CharSet.Ansi)]
        public extern static UInt32 czBeginPixCheck();

        [DllImport("czJetFileII.dll", CharSet = CharSet.Ansi)]
        public extern static UInt32 czReadPixResult(String PCPxlPath);

        [DllImport("czJetFileII.dll", CharSet = CharSet.Ansi)]
        public extern static UInt32 czReadSignalResult(String PCPxlPath);

        [DllImport("czJetFileII.dll", CharSet = CharSet.Ansi)]
        public extern static UInt32 czPixProgress(ref UInt16 resultCode);

        [DllImport("czJetFileII.dll", CharSet = CharSet.Ansi)]
        public extern static UInt32 czPxlChk(String PCPxlPath, String PCSignalPath);

        [DllImport("czJetFileII.dll", CharSet = CharSet.Ansi)]
        public extern static void czSleep(UInt32 msec);

        [DllImport("czJetFileII.dll", CharSet = CharSet.Ansi)]
        public extern static UInt32 czBlackScreen();

        [DllImport("czJetFileII.dll", CharSet = CharSet.Ansi)]
        public extern static UInt32 czReadCommunicationSet(ref COMMUNICATICON_ST commSet);

        [DllImport("czJetFileII.dll", CharSet = CharSet.Ansi)]
        public extern static UInt32 czWriteCommunicationSet(ref COMMUNICATICON_ST commSet);

        [DllImport("czJetFileII.dll", CharSet = CharSet.Ansi)]
        public extern static UInt32 czReadCurScreentshot(String pcpath);

        [DllImport("czJetFileII.dll", CharSet = CharSet.Ansi)]
        public extern static UInt32 czReadBrightInfoExt(ref czBrightInfoExt BrightInfo);

        [DllImport("czJetFileII.dll", CharSet = CharSet.Ansi)]
        public extern static UInt32 czGetPlayingFileName(StringBuilder FileName, UInt32 NameLen);

        [DllImport("czJetFileII.dll", CharSet = CharSet.Ansi)]
        public extern static UInt32 czGetDirFile(string path, ref UInt32 num, IntPtr dirEntry, UInt32 size);

        [DllImport("czJetFileII.dll", CharSet = CharSet.Ansi)]
        public extern static UInt32 czSetDisplay(byte pageID, byte zoneNum, byte setMode, ZoneDisplaySet parameter, StringBuilder content);

        [DllImport("czJetFileII.dll", CharSet = CharSet.Ansi)]
        public extern static UInt32 czSetDisplay(byte pageID, byte zoneNum, byte setMode, ZoneDisplaySet parameter, byte[] content);

        [DllImport("czJetFileII.dll", CharSet = CharSet.Ansi)]
        public extern static UInt32 czSetDisplay(byte pageID, byte zoneNum, byte setMode, ZoneDisplaySet parameter, String content);

        [DllImport("czJetFileII.dll", CharSet = CharSet.Ansi)]
        public extern static UInt32 czDivideZone(byte pageID, byte flag, ZoneSetHead zoneSetHead, ZoneSet[] zoneSetArrs);

        [DllImport("czJetFileII.dll", CharSet = CharSet.Ansi)]
        public extern static UInt32 czSetContentDisplay(byte pageID, byte zoneNum, ZoneDisplayContentSet parameter, StringBuilder content);

        [DllImport("czJetFileII.dll", CharSet = CharSet.Ansi)]
        public extern static UInt32 czSetContentDisplay(byte pageID, byte zoneNum, ZoneDisplayContentSet parameter, String content);

        [DllImport("czJetFileII.dll", CharSet = CharSet.Ansi)]
        public extern static UInt32 czSetContentDisplay(byte pageID, byte zoneNum, ZoneDisplayContentSet parameter, byte[] content);

        [DllImport("czJetFileII.dll", CharSet = CharSet.Ansi)]
        public extern static UInt32 czGetZone(ref ZoneSetHead zoneSetHead, IntPtr zoneSetEntry, byte maxEntryCount, byte PageID = 1);

        [DllImport("czJetFileII.dll", CharSet = CharSet.Ansi)]
        public extern static UInt32 czPlaySoundFile(SoundST soundST, String soundpath);

        [DllImport("czJetFileII.dll", CharSet = CharSet.Ansi)]
        public extern static UInt32 czAdjustVolume(Byte soundVolume);

        [DllImport("czJetFileII.dll", CharSet = CharSet.Ansi)]
        public extern static UInt32 czReadDefDisplayStyle(ref DEFAULT_SET defaultSet);

        [DllImport("czJetFileII.dll", CharSet = CharSet.Ansi)]
        public extern static UInt32 czWriteDefDisplayStyle(ref DEFAULT_SET defaultSet);

        [DllImport("czJetFileII.dll", CharSet = CharSet.Ansi)]
        public extern static UInt32 czPLInit(String workPath, String playListName);

        [DllImport("czJetFileII.dll", CharSet = CharSet.Ansi)]
        public extern static UInt32 czPLSendToLED(Byte isSendChangedFiles);

        [DllImport("czJetFileII.dll", CharSet = CharSet.Ansi)]
        public extern static UInt32 czReadCurVolume(ref Byte soundVolume);

        [DllImport("czJetFileII.dll", CharSet = CharSet.Ansi)]
        public extern static UInt32 czReadWarningLog(ref CZLog_File_Head logFileHead, IntPtr logDataEntry, Byte maxEntryCount);

        [DllImport("czJetFileII.dll", CharSet = CharSet.Ansi)]
        public extern static UInt32 czTM_DecodeDosTime(UInt32 DosTime, Byte[] dateTimeBuf, Byte bufSize);

        [DllImport("czJetFileII.dll", CharSet = CharSet.Ansi)]
        public extern static UInt32 czPLSpeSendToLED(Byte playListIndex, Byte isSendChangedFiles);

        [DllImport("czJetFileII.dll", CharSet = CharSet.Ansi)]
        public extern static UInt32 czLoadSYSFromXML(String fileName);

        [DllImport("czJetFileII.dll", CharSet = CharSet.Ansi)]
        public extern static UInt32 czPlaySpePlaylist(Byte playListIndex);

        [DllImport("czJetFileII.dll", CharSet = CharSet.Ansi)]
        public extern static UInt32 czReadSpePlayListIndex(ref Byte playListIndex);

        [DllImport("czJetFileII.dll", CharSet = CharSet.Ansi)]
        public extern static UInt32 czGetBeacon(ref BEACON_ST beacon);

        [DllImport("czJetFileII.dll", CharSet = CharSet.Ansi)]
        public extern static UInt32 czGetMulitZoneSetting(ref Byte enabled, ref Byte pageCount);

        [DllImport("czJetFileII.dll", CharSet = CharSet.Ansi)]
        public extern static UInt32 czSetEnableMulitZone(Byte enabled);

        [DllImport("czJetFileII.dll", CharSet = CharSet.Ansi)]
        public extern static UInt32 czSetPageCount(Byte pageCount);

        [DllImport("czJetFileII.dll", CharSet = CharSet.Ansi)]
        public extern static UInt32 czIsFileExist(String fileName);
        [DllImport("czJetFileII.dll", CharSet = CharSet.Ansi)]
        public extern static UInt32 czConnectTest(ref UInt16 FirmwareVer, ref UInt16 FPGAVer, ref UInt32 IPAddress);

        [DllImport("czJetFileII.dll", CharSet = CharSet.Ansi)]
        public extern static UInt32 czPlaySoundFile4j(ref SoundST soundST, String soundpath);

        [DllImport("czJetFileII.dll", CharSet = CharSet.Ansi)]
        public extern static UInt32 czPLReadFromLED(byte isReadChangedFiles);

        [DllImport("czJetFileII.dll", CharSet = CharSet.Ansi)]
        public extern static UInt32 czPLSave();

        [DllImport("czEncodingConvert", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.Cdecl)]
        public extern static UInt32 code_gb2312_to_unicode(UInt32 code);

        [DllImport("czEncodingConvert", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.Cdecl)]
        public extern static UInt32 code_unicode_to_gb2312(UInt32 code);

        [DllImport("czEncodingConvert", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.Cdecl)]
        public extern static UInt32 code_convert(UInt32 code, int srcencoding, int dstencoding);

        [DllImport("czJetFileII.dll", CharSet = CharSet.Ansi)]
        public extern static UInt32 czSetLCS(Byte actionType);

        [DllImport("czJetFileII.dll", CharSet = CharSet.Ansi)]
        public extern static UInt32 czGetLCS(ref Byte actionType);

        [DllImport("czJetFileII.dll", CharSet = CharSet.Ansi)]
        public extern static UInt32 czPlayVoice(Byte voiceSwitch, Byte voiceEncode, string Data, Byte DataLen);
        #endregion

        #region CallbackFunc

        private static czinterface.PreCommFun PreCommFunc = preComm;

        /// <summary>
        /// pre comm
        /// </summary>
        /// <param name="If">czinterface</param>
        public static void preComm(ref czinterface If)
        {
            return;
        }

        private static czinterface.PostCommFun PostCommFunc = postComm;

        /// <summary>
        /// post comm
        /// </summary>
        /// <param name="If">czinterface</param>
        public static void postComm(ref czinterface If)
        {
            return;
        }

        private static czinterface.UpdateStatusFun UpdateStatusFunc = updateStatus;

        /// <summary>
        /// update status call back
        /// </summary>
        /// <param name="inter">czinterface</param>
        /// <param name="code">code</param>
        /// <param name="precent">precent，0-95</param>
        public static void updateStatus(ref czinterface inter, UInt32 code, UInt32 precent)
        {
            return;
        }

        private static czinterface.ReadFun ReadFunc = read;

        /// <summary>
        /// read call back
        /// </summary>
        /// <param name="par">interface</param>
        /// <param name="buf">buffer</param>
        /// <param name="size">read size</param>
        /// <param name="timeoutms">timeout ms</param>
        /// <returns>size of read</returns>
        public static UInt32 read(IntPtr par, StringBuilder buf, UInt32 size, UInt32 timeoutms)
        {
            return 0;
        }

        private static czinterface.WriteFun WriteFunc = write;

        /// <summary>
        /// write call back
        /// </summary>
        /// <param name="par">interface</param>
        /// <param name="buf">buffer</param>
        /// <param name="size">write size</param>
        /// <returns>size of write</returns>
        public static UInt32 write(IntPtr par, String buf, UInt32 size)
        {
            return 0;
        }

        private static czinterface.LogFun LogFunc = log;

        /// <summary>
        /// log call back, Variable parameters are not supported
        /// </summary>
        /// <param name="inter">czinterface</param>
        /// <param name="file">file name</param>
        /// <param name="line">line number</param>
        /// <param name="level">level</param>
        /// <param name="fmt">format</param>
        /// <param name="p"></param>
        public static void log(ref czinterface inter, String file, int line, int level, String format, IntPtr args)
        {
            var bufferCapacity = _vscprintf(format, args);

            StringBuilder logMessage = new StringBuilder(256);
            var stringBuilder = new StringBuilder(bufferCapacity + 1);
            vsprintf(stringBuilder, format, args);
            Debug.WriteLine(stringBuilder.ToString());
        }

        #endregion

        /// <summary>
        /// init czinterface struct
        /// </summary>
        /// <param name="If">czinterface</param>
        public static void InitIFStruct(ref czinterface If)
        {
            If.type = czinterface.conn_type.COMM_UDP;
            If.ip = TEST_SIGN_IP;
            If.com = TEST_SIGN_COM;
            If.signPointer = IntPtr.Zero;
            If.taskPointer = IntPtr.Zero;
            If.baudrate = TEST_SIGN_COM_BAUDRATE;
            If.port = 9520;
            If.Retry = 5;
            If.Timeoutms = 3000;

            If.SrcAddr = 0;
            If.DstAddr = TEST_SIGN_COM_GGUU;
            If.Retry = 3;

            If.pre_comm = PreCommFunc;
            If.post_comm = PostCommFunc;
            If.update_status = UpdateStatusFunc;
            If.log = LogFunc;
            If.totalSteps = 1;
            If.curSteps = 1;
            If.packetSize = 768;
        }

        #region TestFunction

        /// <summary>
        /// read Tile Status
        /// </summary>
        public static void ReadImposaTileStatusDemo()
        {
            uint rtCode = 0;
            StringBuilder result = new StringBuilder(1024);
            ushort resultCode = 0;

            czImposaGetTileStat(0, ref rtCode);

            Thread.Sleep(500);

            czImposaGetResult(rtCode, result, 1024, ref resultCode);
        }

        /// <summary>
        /// Pixel Check
        /// </summary>
        public static void PixCheckDemo()
        {
            uint nResult, rValue, retryTime = 60;
            ushort Progress = 0;
            //============================================================================================================
            //==== 第1步:触发检测
            //============================================================================================================
            rValue = czBeginPixCheck();
            if (rValue != 0) return;

            //============================================================================================================
            //==== 第2步:查进度
            //============================================================================================================
            rValue = czPixProgress(ref Progress);
            while (retryTime > 0 && rValue == 0)
            {
                rValue = czPixProgress(ref Progress);
                if (Progress > 99) break;

                czSleep(1000);
            }

            //============================================================================================================
            //==== 第3步:读取文件
            //============================================================================================================
            if (rValue == 0)
            {
                czReadPixResult("F:\\pxl1.csv");
                czReadSignalResult("F:\\signal1.csv");
            }
        }

        /// <summary>
        /// read file list
        /// </summary>
        public static void ReadFileListByPathDemo()
        {
            uint ret;
            DIRECTORY_ENTRY_STRUCT[] entry = new DIRECTORY_ENTRY_STRUCT[100];
            UInt32 num = 0;
            string pathStr = "D:\\P\\";
            IntPtr pt = Marshal.AllocHGlobal(Marshal.SizeOf(typeof(DIRECTORY_ENTRY_STRUCT)) * 100);
            ret = czGetDirFile(pathStr, ref num, pt, 100);

            if (ret == 0)
            {
                string tmpName, tmpExt, tmpFileName, tmpAllName = "";
                DIRECTORY_ENTRY_STRUCT tmpEntry;
                int index = 0;
                Console.WriteLine("There are files in the 'D:/P/',as below:");
                for (int i = 0; i < num; i++)
                {
                    IntPtr ptr = (IntPtr)((UInt32)pt + i * Marshal.SizeOf(typeof(DIRECTORY_ENTRY_STRUCT)));

                    tmpEntry = (DIRECTORY_ENTRY_STRUCT)Marshal.PtrToStructure(ptr, typeof(DIRECTORY_ENTRY_STRUCT));

                    //clean up invalid files
                    tmpFileName = new string(tmpEntry.badir_name);
                    tmpFileName = tmpFileName.Split('\0')[0];
                    if (tmpFileName.Trim() == "." || tmpFileName.Trim() == "..")
                        continue;

                    //get the correct file name
                    tmpName = tmpFileName.Substring(0, 8);
                    tmpExt = tmpFileName.Substring(8, 3);
                    tmpFileName = tmpName.Trim() + "." + tmpExt.Trim();
                    Array.Clear(tmpEntry.badir_name, 0, tmpEntry.badir_name.Length);
                    tmpFileName.ToCharArray().CopyTo(tmpEntry.badir_name, 0);

                    entry[index] = tmpEntry;
                    index++;
                    Console.WriteLine(tmpFileName);
                }
                Console.WriteLine("Press any key to continue");
                Console.ReadKey();
            }
        }

        /// <summary>
        /// easy API
        /// </summary>
        public static void EasyAPIDemo()
        {
            System.Diagnostics.Stopwatch stopwatch = new Stopwatch();
            uint ret;

            ShowMultiLineDemo();

            // show playlist(many files) with no schedule
            stopwatch.Start();
            string[] filesStr = new string[] { "./1.bmp", "./2.bmp", "./3.bmp" };

            //ret = czShowFiles(filesStr, 3, CZ_MODE_MOVEUP, 2, TEST_SIGN_IP, 9520);
            //ret = czShowFilesEx(filesStr, 3, CZ_MODE_MOVEUP, 2, TEST_SIGN_IP, 9520, 0, czinterface.conn_type.COMM_UDP, TEST_SIGN_COM, TEST_SIGN_COM_BAUDRATE, TEST_SIGN_COM_GGUU);
            Byte[] stayTimes = { 1, 3, 8 };
            ret = czShowFilesII(filesStr, 3, stayTimes, CZ_MODE_MOVEUP, "169.254.10.149", 9520, 0);
            //return;
            stopwatch.Stop();
            Console.WriteLine("show 3 files on the sign");
            Console.WriteLine(" total time:" + stopwatch.Elapsed.TotalMilliseconds + " ms\r\n");
            Console.WriteLine("Press any key to continue");
            Console.ReadKey();

            // show bmp on the sign, rand mode, stay 3 sec.
            Stream stream = File.OpenRead(".\\demo.bmp");
            if (stream != null)
            {
                byte[] content = new byte[stream.Length];
                stream.Read(content, 0, content.Length);
                //czShowPic(content, (uint)content.Length, CZ_MODE_RAND, 3, TEST_SIGN_IP, 9520);
                ret = czShowPicEx(content, (uint)content.Length, CZ_MODE_RAND, 3, TEST_SIGN_IP, 9520, 0, czinterface.conn_type.COMM_UDP, TEST_SIGN_COM, TEST_SIGN_COM_BAUDRATE, TEST_SIGN_COM_GGUU);
            }
            Console.WriteLine("show demo picture on the sign");
            Console.WriteLine("Press any key to continue");
            Console.ReadKey();

            // show messgae "show demo msg" on the sign, static mode, stay 0 sec.
            //czShowMsg("show demo msg", 13, CZ_FONT_EN_14x8, CZ_COLOR_AMBER, CZ_MODE_STATIC, 0, TEST_SIGN_IP, 9520, 1);
            ret = czShowMsgEx("show demo msg", 13, CZ_FONT_EN_14x8, CZ_COLOR_AMBER, CZ_MODE_STATIC, 0, TEST_SIGN_IP, 9520, 1, 1, czinterface.conn_type.COMM_UDP, TEST_SIGN_COM, TEST_SIGN_COM_BAUDRATE, TEST_SIGN_COM_GGUU);

            Console.WriteLine("show 'show demo msg' on the sign");
            Console.WriteLine("Press any key to continue");
            Console.ReadKey();

            // show messgae "测试Demo" on the sign, static mode, stay 0 sec.
            var msg = Encoding.ASCII.GetBytes("测试Demo");
            czShowMsg(msg, 8, CZ_FONT_CH_ST_16x16, CZ_COLOR_AMBER, CZ_MODE_STATIC, 0, TEST_SIGN_IP, 9520);

            Console.WriteLine("show '测试Demo' on the sign");
            Console.WriteLine("Press any key to continue");
            Console.ReadKey();

            // show messgae "test it via easy api" on the sign with self-define color,, rand mode, stay 0 sec.
            uint COLOR;
            COLOR = (0 << 24) | (255 << 16) | (0 << 8) | '/';			//R-G-B-/
            msg = Encoding.ASCII.GetBytes("test it via easy api");
            czShowMsg(msg, 20, CZ_FONT_EN_14x8, COLOR, CZ_MODE_STATIC, 0, TEST_SIGN_IP, 9520);

            Console.WriteLine("show 'test it via easy api' on the sign");
            Console.WriteLine("Press any key to continue");
            Console.ReadKey();

            // czErrString.dll example
            string errDesc = string.Empty;
            var ptr = new IntPtr();
            ptr = czErrorDesc(0);
            errDesc = Marshal.PtrToStringAnsi(ptr);

            Console.WriteLine("show code 0 message:");
            Console.WriteLine(errDesc);
            Console.ReadKey();

            ptr = czErrorDesc(20736);
            errDesc = Marshal.PtrToStringAnsi(ptr);
            Console.WriteLine("show code 20736 message:");
            Console.WriteLine(errDesc);
            Console.ReadKey();

            ///////////////////////////////////////////////////////////////
            //
            //   czEncodingConvert  Demo
            //
            ///////////////////////////////////////////////////////////////
            string gb2312str = string.Empty;
            foreach (var ch in "欢迎")
            {
                UInt32 code = code_unicode_to_gb2312(ch);
                gb2312str += (char)code;
                Console.WriteLine($"gb2312 Code :0x{code.ToString("X2")}");
            }
            foreach (var ch in gb2312str)
            {
                UInt32 code = code_gb2312_to_unicode(ch);
                Console.WriteLine($"Unicode Encode:0x{code.ToString("X2")}");
                Console.WriteLine($"Unicode Char:{(char)code}");
            }
        }

        private static void SetBufferZero(IntPtr buffer, int size)
        {
            byte[] zeroBytes = new byte[size];
            for (int i = 0; i < zeroBytes.Length; i++)
            {
                zeroBytes[i] = 0;
            }
            Marshal.Copy(zeroBytes, 0, buffer, size);
        }

        private static void PredefinedPlaylistDemo()
        {
            uint nResult;
            byte curPLIndex = 0;
            //========================================================================================================
            //===== Playlist control
            //========================================================================================================	
            //according to the "DEMO1.LST" template file generates the required files, The file is in XML format
            czPLInit(".\\", "DEMO1.LST");

            //Send playlist1
            nResult = czPLSpeSendToLED(1, 1);

            //Load playlist2
            nResult = czLoadSYSFromXML("DEMO2.LST");

            //Send Playlist2
            nResult = czPLSpeSendToLED(2, 1);

            //Play playlist1
            nResult = czPlaySpePlaylist(1);

            //Get current playlist Index
            nResult = czReadSpePlayListIndex(ref curPLIndex);

            //Play playlist2
            nResult = czPlaySpePlaylist(2);

            //Get current playlist Index
            nResult = czReadSpePlayListIndex(ref curPLIndex);

            //Delete playlist1
            //nResult = czPLDeleteByIndex(1);

        }

        /// <summary>
        /// API Demo Advenced
        /// </summary>
        public static void APIDemoAdvenced()
        {
            try
            {
                // init interface struct
                var If = new czinterface();
                //czinterface If;

                // Call API Init
                InitIFStruct(ref If);

                uint ret = czInitAPI(ref If);

                if (ret != 0)
                {
                    Console.WriteLine("Error during API initialization. Error code: " + ret);
                }
                
                uint nResult = 0;
                //write PC ".\\1.bmp" to sign "D:\P\1.bmp"
                string path = ".\\1.bmp";
                string tarPath = "D:\\P\\1.bmp";
                //path = ".\\1";
                //tarPath = "E:\\S\\1";

                ret = czWriteSpecFile(tarPath, path);

                if (ret == 0)
                {
                    Console.WriteLine("Write D:\\P\\1.bmp successfully");
                }
                Console.WriteLine("Press any key to continue");
                Console.ReadKey();

                // read D:\P\1.bmp file to PC .\\1_1.bmp
                path = ".\\1_1.bmp";
                tarPath = "D:\\P\\1.bmp";

                ret = czReadSpecPathFile(tarPath, path);

                if (ret == 0)
                {
                    Console.WriteLine("Read D:\\P\\1.bmp successfully");
                }
                Console.WriteLine("Press any key to continue");
                Console.ReadKey();

                Console.WriteLine("ReadImposaTileStatus");

                // read tile status
                ReadImposaTileStatusDemo();

                //========================================================================================================
                //===== Pix check : easy way 
                //========================================================================================================	
                nResult = czPxlChk("F:\\pxl.csv", "F:\\signal.csv");

                //========================================================================================================
                //===== Pix check : ProgressInfo way 
                //========================================================================================================	
                PixCheckDemo();

                //========================================================================================================
                //===== Read Communication Setting
                //========================================================================================================	
                COMMUNICATICON_ST aCommSet = new COMMUNICATICON_ST();
                ret = czReadCommunicationSet(ref aCommSet);

                //========================================================================================================
                //===== Send Communication Setting
                //========================================================================================================	
                aCommSet.ip = "169.254.11.113";
                aCommSet.CustomPort = 9523;
                aCommSet.GatewayAddr = "169.254.11.1";
                nResult = czWriteCommunicationSet(ref aCommSet);

                //Reconnect the new IP,the sleep time based on the mainboard type!
                czSleep(10000);
                aCommSet.ip = "169.254.18.126";
                czInitAPI(ref If);
                aCommSet = new COMMUNICATICON_ST();
                ret = czReadCommunicationSet(ref aCommSet);

                //========================================================================================================
                //===== Get Current Play Content
                //========================================================================================================	
                nResult = czReadCurScreentshot("F:\\11.JPG");

                Console.WriteLine("Press any key to continue");
                Console.ReadKey();

                Console.WriteLine("ReadCurrentState");

                CURRENT_STATE state = new CURRENT_STATE();
                ret = czReadCurrentState(ref state, IntPtr.Zero, 0);

                if (ret == 0)
                {
                    Console.WriteLine("Sys state " + state.sysState);
                    Console.WriteLine("inTemp " + state.inTemp);
                    Console.WriteLine("outTemp " + state.outTemp);
                    Console.WriteLine("AutoPower " + state.AutoPower);
                    Console.WriteLine("Humidity " + state.Humidity);
                    Console.WriteLine("Samples " + state.Samples);
                    Console.WriteLine("BrightLevel " + state.BrightLevel);
                }
                else
                {
                    Console.WriteLine("error!! Code " + ret);
                }

                //========================================================================================================
                //===== Get list of files under some path 
                //========================================================================================================	
                ReadFileListByPathDemo();

                Console.WriteLine("Press any key to continue");
                Console.ReadKey();


                // ========================================================================================================
                // ===== Play Sound
                // ========================================================================================================
                nResult = czWriteSpecFile("C:\\Test.mp3", ".\\Test.mp3");

                SoundST soundST = new SoundST();
                soundST.BuzzerSwitch = 1;
                soundST.PlayTimes = 1;
                nResult = czPlaySoundFile(soundST, "c://Test.mp3");//"/usr/local/drivers/5.mp3"			//c://Test.mp3
                                                                           //Adjust Volume
                nResult = czAdjustVolume(80);
                nResult = czAdjustVolume(45);
                nResult = czAdjustVolume(90);
                //Stop Play
                soundST.BuzzerSwitch = 0;
                nResult = czPlaySoundFile(soundST, "c://Test.mp3");

                //Set DefaultScreen
                nResult = czWriteSpecFile("D:\\P\\logo.bmp", ".\\logo.bmp");

                //Set Communication Lost Time
                DEFAULT_SET dset = new DEFAULT_SET();
                nResult = czReadDefDisplayStyle(ref dset);
                dset.ShowDefaultBmpTime = 10;
                nResult = czWriteDefDisplayStyle(ref dset);

                Console.WriteLine("Press any key to continue");
                Console.ReadKey();
                
                soundST.BuzzerSwitch = 1;
                soundST.PlayTimes = 1;
                nResult = czPlaySoundFile(soundST, "c://Test.mp3");//"/usr/local/drivers/5.mp3"			//c://Test.mp3

				nResult = czPlaySoundFile4j(ref soundST, "c://Test.mp3");//"/usr/local/drivers/5.mp3"			//c://Test.mp3  
                Byte volume = new Byte(); 
                nResult = czReadCurVolume(ref volume);

                //Adjust Volume
                nResult = czAdjustVolume(80);
                nResult = czAdjustVolume(45);
                nResult = czAdjustVolume(90);

                nResult = czReadCurVolume(ref volume);

                //Stop Play
                soundST.BuzzerSwitch = 0;
                nResult = czPlaySoundFile(soundST, "c://Test.mp3");

                //Set DefaultScreen
                nResult = czWriteSpecFile("D:\\P\\logo.bmp", ".\\logo.bmp");

                //Set Communication Lost Time
                SetDefaultScreentParameter();

                //========================================================================================================
                //===== Playlist control
                //========================================================================================================	
                czPLInit(".\\", "DEMO.LST");
                //according to the "DEMO.LST" template file generates the required files, The file is in XML format
                czPLSendToLED(0);

                var logHead = new CZLog_File_Head();
                var logDataEntry = new CZLogDataST[50];
                var DateTimeStr = new Byte[32];

                IntPtr pt = Marshal.AllocHGlobal(Marshal.SizeOf(typeof(CZLogDataST)) * 50);
                SetBufferZero(pt, Marshal.SizeOf(typeof(CZLogDataST)) * 50);
                nResult = czReadWarningLog(ref logHead, pt, 50);
                for (int i = 0; i < 50; i++)
                {
                    IntPtr ptr = (IntPtr)((UInt32)pt + i * Marshal.SizeOf(typeof(CZLogDataST)));
                    logDataEntry[i] = (CZLogDataST)Marshal.PtrToStructure(ptr, typeof(CZLogDataST));
                }

                Marshal.FreeHGlobal(pt);
                // Get the Record DateTime
                nResult = czTM_DecodeDosTime(logDataEntry[9].DataTime, DateTimeStr, 32);

                PredefinedPlaylistDemo();
                //var beacon = new BEACON_ST();
                //nResult = czGetBeacon(ref beacon);

                ControlPlaylistDemo();

                Console.WriteLine("Press any key to continue");
                Console.ReadKey();
            }
            catch (Exception e)
            {
                ;
            }
        }

        public static void SetDefaultScreentParameter()
        {
            UInt32 nResult;

            var iniPath = ".\\TE18_233.cfg";
            nResult = czReadSpecPathFile("c:\\config\\TE18_233.cfg", iniPath);

            INIHelper.inifilepath = ".\\TE18_233.cfg";

            //get the current value
            var showDefaultBmpTime = Convert.ToUInt16(INIHelper.GetValue("DefaultSet", "ShowDefultBmpTime"));
            var blackScreenTime = Convert.ToUInt16(INIHelper.GetValue("DefaultSet", "BlackScreenTime"));

            //modify the value as you need
            showDefaultBmpTime = 1001;
            blackScreenTime = 2001;

            INIHelper.SetValue("DefaultSet", "ShowDefultBmpTime", showDefaultBmpTime.ToString());
            INIHelper.SetValue("DefaultSet", "BlackScreenTime", blackScreenTime.ToString());

            nResult = czWriteSpecFile("c:\\config\\TE18_233.cfg", iniPath);
        }

        public static void ShowFilesToMulitSigns()
        {
            Byte i = 0;
            UInt32 RT = CZ_ERROR_OK;

            string[] filesStr = new string[] { "./1.bmp", "./2.bmp", "./3.bmp" };

            string[] ipArray = { "169.254.15.124", "169.254.10.149" };

            //Send Files
            for (i = 0; i < TEST_IPCOUNT; i++)
            {
                RT = czShowFilesSpe(filesStr, 3, 0x30, 3, ipArray[i], 9520, 0, czinterface.conn_type.COMM_UDP, "COM3", 9600, 0x0101, 0x01);
            }

            for (i = 0; i < TEST_IPCOUNT && RT == CZ_ERROR_OK; i++)
            {
                // init interface struct
                var If = new czinterface();

                // Call API Init
                InitIFStruct(ref If);

                //Init _czinterface;
                uint ret = czInitAPI(ref If);
                RT = czBlackScreen();                                                               //BLACK Screen
            }

            //Send playlist
            for (i = 0; i < TEST_IPCOUNT; i++)
            {
                RT = czShowFilesSpe(filesStr, 3, 0x30, 3, ipArray[i], 9520, 0, czinterface.conn_type.COMM_UDP, "COM3", 9600, 0x0101, 0x02);
            }

            for (i = 0; i < TEST_IPCOUNT && RT == CZ_ERROR_OK; i++)
            {
                // init interface struct
                var If = new czinterface();

                // Call API Init
                InitIFStruct(ref If);

                //Init _czinterface;
                uint ret = czInitAPI(ref If);
                RT = czBlackScreen();                                                               //BLACK Screen
            }
        }

        #endregion

        private static void APITestFunctionsDemo()
        {

            try
            {
                // init interface struct
                var If = new czinterface();

                // Call API Init
                InitIFStruct(ref If);

                uint ret = czInitAPI(ref If);
                uint FirmwareVer = 0;
                uint FPGAVer = 0;
                uint IPAddress = 0;

                DoAllCrayTest();

                czStopTest();
            }
            catch (Exception e)
            {
                throw e;
            }
        }

        private static void DoAllCrayTest()
        {
            DoGrayTest(0, 0, 0, 0, 1);
            DoGrayTest(0, 0, 0, 0, 127);
            DoGrayTest(0, 0, 0, 0, 256);

            DoGrayTest(0, 0, 0, 1, 1);
            DoGrayTest(0, 0, 0, 1, 127);
            DoGrayTest(0, 0, 0, 1, 256);

            DoGrayTest(0, 0, 1, 0, 1);
            DoGrayTest(0, 0, 1, 0, 127);
            DoGrayTest(0, 0, 1, 0, 256);

            DoGrayTest(0, 0, 1, 1, 1);
            DoGrayTest(0, 0, 1, 1, 127);
            DoGrayTest(0, 0, 1, 1, 256);

            DoGrayTest(0, 1, 0, 0, 1);
            DoGrayTest(0, 1, 0, 0, 127);
            DoGrayTest(0, 1, 0, 0, 256);

            DoGrayTest(0, 1, 0, 1, 1);
            DoGrayTest(0, 1, 0, 1, 127);
            DoGrayTest(0, 1, 0, 1, 256);

            DoGrayTest(0, 1, 1, 0, 1);
            DoGrayTest(0, 1, 1, 0, 127);
            DoGrayTest(0, 1, 1, 0, 256);

            DoGrayTest(0, 1, 1, 1, 1);
            DoGrayTest(0, 1, 1, 1, 127);
            DoGrayTest(0, 1, 1, 1, 256);


            DoGrayTest(1, 0, 0, 0, 1);
            DoGrayTest(1, 0, 0, 0, 127);
            DoGrayTest(1, 0, 0, 0, 256);

            DoGrayTest(1, 0, 0, 1, 1);
            DoGrayTest(1, 0, 0, 1, 127);
            DoGrayTest(1, 0, 0, 1, 256);

            DoGrayTest(1, 0, 1, 0, 1);
            DoGrayTest(1, 0, 1, 0, 127);
            DoGrayTest(1, 0, 1, 0, 256);

            DoGrayTest(1, 0, 1, 1, 1);
            DoGrayTest(1, 0, 1, 1, 127);
            DoGrayTest(1, 0, 1, 1, 256);

            DoGrayTest(1, 1, 0, 0, 1);
            DoGrayTest(1, 1, 0, 0, 127);
            DoGrayTest(1, 1, 0, 0, 256);

            DoGrayTest(1, 1, 0, 1, 1);
            DoGrayTest(1, 1, 0, 1, 127);
            DoGrayTest(1, 1, 0, 1, 256);

            DoGrayTest(1, 1, 1, 0, 1);
            DoGrayTest(1, 1, 1, 0, 127);
            DoGrayTest(1, 1, 1, 0, 256);

            DoGrayTest(1, 1, 1, 1, 1);
            DoGrayTest(1, 1, 1, 1, 127);
            DoGrayTest(1, 1, 1, 1, 256);
        }

        private static void DoGrayTest(uint type, uint red, uint green, uint blue, uint level)
        {
            GRAY_TEST_PARAM grayParams = new GRAY_TEST_PARAM();

            grayParams.Type = type;
            grayParams.Red = red;
            grayParams.Green = green;
            grayParams.Blue = blue;
            grayParams.Level = level;

            var ret = czCrayTest(ref grayParams);
            if (ret == 0)
            {

                Console.WriteLine("--------------------------------------------------");
                Console.WriteLine("Ejecutando test Gray");
                Console.WriteLine("grayParams.Type: " + grayParams.Type);
                Console.WriteLine("grayParams.Red: " + grayParams.Red);
                Console.WriteLine("grayParams.Green: " + grayParams.Green);
                Console.WriteLine("grayParams.Blue: " + grayParams.Blue);
                Console.WriteLine("grayParams.Level: " + grayParams.Level);
                Console.WriteLine("--------------------------------------------------");
            }
            else
            {
                Console.WriteLine("FAILED DURING CRAYTEST");
            }
            Console.WriteLine("Press any key to continue");
            Console.ReadKey();
        }

        static private void dataInWorkThread(ref czinterface If)
        {
            czBrightInfoExt BrightInfo = new czBrightInfoExt();
            CURRENT_STATE State = new CURRENT_STATE(); ;
            StringBuilder FileName = new StringBuilder(128);

            UInt32 RT = 0;
            czInitAPI(ref If);
            while (true)
            {
                RT = czReadBrightInfoExt(ref BrightInfo);

                RT = czReadCurrentState(ref State, IntPtr.Zero, 0);

                FileName.Clear();
                RT = czGetPlayingFileName(FileName, 128);

                czSleep(1000);
            }
        }

        static private void MultiThreadDemo()
        {
            List<string> ipList = new List<string>();
            ipList.Add("169.254.18.125");
            ipList.Add("169.254.13.69");

            foreach (var address in ipList)
            {
                // init interface struct
                var If = new czinterface();

                // Call API Init
                InitIFStruct(ref If);
                If.ip = address;

                Task.Factory.StartNew(() =>
                {
                    dataInWorkThread(ref If);
                });

                czSleep(50);
            }
            Console.ReadKey();

        }

        private static void ShowMultiLineDemo()
        {
            UInt32 RT;
            var msgStr = new Byte[50];
            var strArr = new String[4];
            int nPos = 0;

            //Set text property
            msgStr[0] = 0x1E;           //text alignment tags
            msgStr[1] = 0x30;           //alignment value, align center:0x30; align left:0x31; align right:0x32;
            msgStr[2] = 0x08;           //line space tags
            msgStr[3] = 0x33;           //line space value, rangge: 0x30--0x39
            nPos = 4;

            strArr[0] = "Line1";
            strArr[1] = "Line2";
            strArr[2] = "Line3";
            strArr[3] = "Line4";
            for (int i = 0; i < 4; i++)
            {
                msgStr[nPos++] = 0x1C;  //color tags	
                msgStr[nPos++] = (byte)'/';   //custom color tags
                switch (i)
                {
                    case 0:
                        msgStr[nPos++] = 0x00;      //B
                        msgStr[nPos++] = 0x00;      //G
                        msgStr[nPos++] = 0xFF;      //R
                        break;
                    case 1:
                        msgStr[nPos++] = 0x00;
                        msgStr[nPos++] = 0xFF;
                        msgStr[nPos++] = 0x00;
                        break;
                    case 2:
                        msgStr[nPos++] = 0xFF;
                        msgStr[nPos++] = 0x00;
                        msgStr[nPos++] = 0x00;
                        break;
                    case 3:
                        msgStr[nPos++] = 0x00;
                        msgStr[nPos++] = 0xFF;
                        msgStr[nPos++] = 0xFF;
                        break;
                }

                var temp = Encoding.ASCII.GetBytes(strArr[i]);
                Array.Copy(temp, 0, msgStr, nPos, temp.Length);

                nPos += strArr[i].Length;
                msgStr[nPos++] = 0x0D;      //new line
            }

            RT = czShowMsg(msgStr, 50, CZ_FONT_EN_14x8, CZ_COLOR_AMBER, CZ_MODE_STATIC, 3, TEST_SIGN_IP, 9520, 0, 1);
        }

       
        private static void SingleZoneDemo(ZoneSetHead zoneSetHead, ZoneSet[] zoneSetEntry)
        {
            UInt32 RT, nPos;
            String content;
            byte[] msgStr = new byte[30];

            byte enabled = 0, pageCount = 0, colorR, colorG, colorB, zoneCount = 0, pageID = 0;

            colorR = 0xFF;
            colorG = 0xFF;
            colorB = 0xFF;
            //Get MulitZone Setting
            RT = czGetMulitZoneSetting(ref enabled, ref pageCount);

            //Four steps are necessary!
            //1.Enable Mulit Zone
            enabled = 1;
            RT = czSetEnableMulitZone(enabled);
            //2.Set the page number=1
            pageCount = 1;
            RT = czSetPageCount(pageCount);

            //Get MulitZone Setting
            RT = czGetMulitZoneSetting(ref enabled, ref pageCount);

            zoneSetHead = new ZoneSetHead
            {
                ZoneNum = 1
            };

            zoneSetEntry = new ZoneSet[MAX_ZONE_COUNT];
            zoneSetEntry[0].ZoneID = 1;
            zoneSetEntry[0].XPos = 0;
            zoneSetEntry[0].YPos = 0;
            zoneSetEntry[0].ZoneWidth = 0x40;
            zoneSetEntry[0].ZoneHeight = 0x10;

            pageID = 1;
            zoneCount = zoneSetHead.ZoneNum;
            //3.reset all zone
            RT = czDivideZone(pageID, 1, zoneSetHead, zoneSetEntry);

            //4.divide one zone
            RT = czDivideZone(pageID, 0, zoneSetHead, zoneSetEntry);


            ZoneDisplaySet zoneDisplayEntry = new ZoneDisplaySet
            {
                ZoneSize = (UInt16)(zoneSetEntry[0].ZoneWidth * zoneSetEntry[0].ZoneHeight),
                ZoneID = zoneSetEntry[0].ZoneID,
                ZoneType = 0,
                CodeType = 0,
                InMode = 3,
                OutMode = 4,
                Align = 0,
                FGColor_R = colorR,
                FGColor_G = colorG,
                FGColor_B = colorB,
                BGColor_R = 0,
                BGColor_G = 0,
                BGColor_B = 0,
                AutoLine = 0,
                AutoWidth = 1,
                Speed = 5,
                StayTime = 2,
                Times = 0,
                FontStyle = (byte)CZ_FONT_EN_14x8,       //CZ_FONT_EN_7x6
                LineSpace = 1,
                CloumnSpace = 1,
                BlinkOnTime = 0x0A,
                BlinkOffTime = 0x0A
            };
            content = "Welcome";
            zoneDisplayEntry.ContentSize = (UInt16)content.Length;
            //display a message with property in zone

            Thread.Sleep((int)PARK_SLEEP_TIME);

            RT = czSetDisplay(pageID, zoneCount, 0, zoneDisplayEntry, content);
                        ZoneDisplayContentSet zoneDisplayContentEntry = new ZoneDisplayContentSet
                        {
                            ZoneSize = (UInt16)(zoneSetEntry[0].ZoneWidth * zoneSetEntry[0].ZoneHeight),
                            ZoneID = zoneSetEntry[0].ZoneID
                        };
                        content = "Hello";
                        zoneDisplayContentEntry.ContentSize = (UInt16)content.Length;
                        //display a message without property in zone
                        Thread.Sleep((int)PARK_SLEEP_TIME);
                        RT = czSetContentDisplay(pageID, zoneCount, zoneDisplayContentEntry, content);

                        //display a message(English+chinese+English) without property in zone
                        zoneDisplayContentEntry = new ZoneDisplayContentSet
                        {
                            ZoneSize = (UInt16)(zoneSetEntry[0].ZoneWidth * zoneSetEntry[0].ZoneHeight),
                            ZoneID = zoneSetEntry[0].ZoneID
                        };
                        content = "123";
                        nPos = 0;

                        Array.Copy(Encoding.ASCII.GetBytes(content), 0, msgStr, nPos, content.Length);
                        nPos += (uint)content.Length;
                        msgStr[nPos++] = 0x08;
                        msgStr[nPos++] = 0x31;
                        msgStr[nPos++] = (byte)CZ_FONT_EN_5x5;
                        content = "123";
                        Array.Copy(Encoding.ASCII.GetBytes(content), 0, msgStr, nPos, content.Length);
                        nPos += (uint)content.Length;
                        msgStr[nPos++] = 0x08;              //switch font control code
                        msgStr[nPos++] = 0x31;              //switch font control code
                        msgStr[nPos++] = (byte)CZ_FONT_EN_16x9;    //font 7x6
                        content = "123";
                        Array.Copy(Encoding.ASCII.GetBytes(content), 0, msgStr, nPos, content.Length);
                        nPos += (uint)content.Length;
                        zoneDisplayContentEntry.ContentSize = (UInt16)nPos;
                        Thread.Sleep((int)PARK_SLEEP_TIME);
                        RT = czSetContentDisplay(pageID, zoneCount, zoneDisplayContentEntry, msgStr);

                        //display a message(Picture+text) without property in zone
                        zoneDisplayContentEntry = new ZoneDisplayContentSet
                        {
                            ZoneSize = (UInt16)(zoneSetEntry[0].ZoneWidth * zoneSetEntry[0].ZoneHeight),
                            ZoneID = zoneSetEntry[0].ZoneID
                        };
                        msgStr = new byte[30];
                        nPos = 0;
                        msgStr[nPos++] = 0x08;              //display picture control code
                        msgStr[nPos++] = 0x33;              //display picture control code
                        msgStr[nPos++] = 0x01;              //display picture control code
                        content = "Hello";
                        Array.Copy(Encoding.ASCII.GetBytes(content), 0, msgStr, nPos, content.Length);
                        nPos += (uint)content.Length;
                        zoneDisplayContentEntry.ContentSize = (UInt16)nPos;
                        Thread.Sleep((int)PARK_SLEEP_TIME);
                        RT = czSetContentDisplay(pageID, zoneCount, zoneDisplayContentEntry, msgStr);
        }
        private static void TwoZoneDemo(ZoneSetHead zoneSetHead, ZoneSet[] zoneSetEntry)
        {
            UInt32 RT, nPos;
            String content;
            byte[] msgStr = new byte[30];

            byte enabled = 0, pageCount = 0, colorR, colorG, colorB, zoneCount = 0, pageID = 0;

            colorR = 0xFF;
            colorG = 0xFF;
            colorB = 0x00;
            //Get MulitZone Setting
            RT = czGetMulitZoneSetting(ref enabled, ref pageCount);

            //Four steps are necessary!
            //1.Enable Mulit Zone
            enabled = 1;
            RT = czSetEnableMulitZone(enabled);
            //2.Set the page number=1
            pageCount = 1;
            RT = czSetPageCount(pageCount);

            //Get MulitZone Setting
            RT = czGetMulitZoneSetting(ref enabled, ref pageCount);

            zoneSetHead = new ZoneSetHead();
            zoneSetEntry = new ZoneSet[MAX_ZONE_COUNT];

            zoneSetHead.ZoneNum = 2;
            zoneSetEntry[0].ZoneID = 1;
            zoneSetEntry[0].XPos = 0;
            zoneSetEntry[0].YPos = 0;
            zoneSetEntry[0].ZoneWidth = 0x20;
            zoneSetEntry[0].ZoneHeight = 0x10;

            zoneSetEntry[1].ZoneID = 2;
            zoneSetEntry[1].XPos = 0;
            zoneSetEntry[1].YPos = 0x20;
            zoneSetEntry[1].ZoneWidth = 0x20;
            zoneSetEntry[1].ZoneHeight = 0x10;

            pageID = 1;
            zoneCount = zoneSetHead.ZoneNum;
            //3.reset all zone
            RT = czDivideZone(pageID, 1, zoneSetHead, zoneSetEntry);

            //4.divide two zone
            RT = czDivideZone(pageID, 0, zoneSetHead, zoneSetEntry);

            //============================================================================================================
            //==== a).display a message without propery
            //============================================================================================================
            ZoneDisplaySet zoneDisplayEntry = new ZoneDisplaySet
            {
                ZoneSize = (UInt16)(zoneSetEntry[0].ZoneWidth * zoneSetEntry[0].ZoneHeight),
                ZoneID = zoneSetEntry[0].ZoneID,
                FGColor_R = colorR,
                FGColor_G = colorG,
                FGColor_B = colorB,
                AutoWidth = 1,
                Speed = 1,
                StayTime = 1,
                FontStyle = 0x32,
                LineSpace = 1,
                CloumnSpace = 1,
                BlinkOnTime = 0x0A,
                BlinkOffTime = 0x0A
            };
            content = "Left";
            zoneDisplayEntry.ContentSize = (UInt16)content.Length;
            //display a message with property in zone 1
            RT = czSetDisplay(pageID, zoneCount, 0, zoneDisplayEntry, content);

            zoneDisplayEntry = new ZoneDisplaySet
            {
                ZoneSize = (UInt16)(zoneSetEntry[1].ZoneWidth * zoneSetEntry[1].ZoneHeight),
                ZoneID = zoneSetEntry[1].ZoneID,
                FGColor_R = 0x00,
                FGColor_G = 0xFF,
                FGColor_B = 0xFF,
                AutoWidth = 1,
                Speed = 1,
                StayTime = 1,
                FontStyle = 0x32,
                LineSpace = 1,
                CloumnSpace = 1,
                BlinkOnTime = 0x0A,
                BlinkOffTime = 0x0A
            };
            content = "Right";
            zoneDisplayEntry.ContentSize = (UInt16)content.Length;
            //display a message with property in zone 2
            RT = czSetDisplay(pageID, zoneCount, 0, zoneDisplayEntry, content);


            //============================================================================================================
            //==== b).display a message without propery
            //============================================================================================================
            ZoneDisplayContentSet zoneDisplayContentEntry = new ZoneDisplayContentSet();
            zoneDisplayContentEntry.ZoneSize = (UInt16)(zoneSetEntry[0].ZoneWidth * zoneSetEntry[0].ZoneHeight);
            zoneDisplayContentEntry.ZoneID = zoneSetEntry[0].ZoneID;
            content = "Up";
            zoneDisplayContentEntry.ContentSize = (UInt16)content.Length;
            //display a message without propery in zone 1
            Thread.Sleep(PARK_SLEEP_TIME);
            RT = czSetContentDisplay(pageID, zoneCount, zoneDisplayContentEntry, content);

            zoneDisplayContentEntry = new ZoneDisplayContentSet
            {
                ZoneSize = (UInt16)(zoneSetEntry[1].ZoneWidth * zoneSetEntry[1].ZoneHeight),
                ZoneID = zoneSetEntry[1].ZoneID
            };
            content = "NUM";
            zoneDisplayContentEntry.ContentSize = (UInt16)content.Length;
            //display a message without propery in zone 2
            Thread.Sleep(PARK_SLEEP_TIME);
            RT = czSetContentDisplay(pageID, zoneCount, zoneDisplayContentEntry, content);

            //============================================================================================================
            //==== c).Display Picture+Text
            //==== 1.send picture at first(this step is not necessary,you can also use the factory default)
            //==== 2.send message(Picture+text) in zone 1
            //==== 3.send message(Picture+text) in zone 2
            //============================================================================================================
            //if you want to display custom picture,send picture at first,the dest path must be "F:\\P\\x.bmp", x is a number greater than 9
            //czWriteSpecFile((INT8U*)("F:\\P\\10.bmp"), ".\\up.bmp");

            zoneDisplayContentEntry = new ZoneDisplayContentSet();
            zoneDisplayContentEntry.ZoneSize = (UInt16)(zoneSetEntry[0].ZoneWidth * zoneSetEntry[0].ZoneHeight);
            zoneDisplayContentEntry.ZoneID = zoneSetEntry[0].ZoneID;
            zoneDisplayContentEntry.ZoneType = 0;
            content = "12";
            msgStr = new byte[30];
            nPos = 0;
            msgStr[nPos++] = 0x08;              //display picture control code
            msgStr[nPos++] = 0x33;              //display picture control code
            msgStr[nPos++] = 0x01;              //"up arrow" picture

            Array.Copy(Encoding.ASCII.GetBytes(content), 0, msgStr, nPos, content.Length);
            nPos += (UInt32)content.Length;
            zoneDisplayContentEntry.ContentSize = (UInt16)nPos;

            //display a message(Picture+text) without propery in zone 1
            Thread.Sleep(PARK_SLEEP_TIME);
            RT = czSetContentDisplay(pageID, zoneCount, zoneDisplayContentEntry, msgStr);

            zoneDisplayContentEntry = new ZoneDisplayContentSet();
            zoneDisplayContentEntry.ZoneSize = (UInt16)(zoneSetEntry[1].ZoneWidth * zoneSetEntry[1].ZoneHeight);
            zoneDisplayContentEntry.ZoneID = zoneSetEntry[1].ZoneID;
            zoneDisplayContentEntry.ZoneType = 0;
            content = "30";
            msgStr = new byte[30];
            nPos = 0;
            msgStr[nPos++] = 0x08;              //display picture control code
            msgStr[nPos++] = 0x33;              //display picture control code
            msgStr[nPos++] = 0x03;              //"left arrow" picture
            Array.Copy(Encoding.ASCII.GetBytes(content), 0, msgStr, nPos, content.Length);
            nPos += (UInt32)content.Length;
            zoneDisplayContentEntry.ContentSize = (UInt16)nPos;

            //display a message(Picture+text) without propery in zone 2
            Thread.Sleep(PARK_SLEEP_TIME);
            RT = czSetContentDisplay(pageID, zoneCount, zoneDisplayContentEntry, msgStr);

        }

        private static void FourZoneDemo(ZoneSetHead zoneSetHead, ZoneSet[] zoneSetEntry)
        {
            UInt32 RT, nPos;
            String content;
            byte[] msgStr = new byte[30];

            byte enabled = 0, pageCount = 0, colorR, colorG, colorB, zoneCount = 0, pageID = 0;

            colorR = 0xFF;
            colorG = 0xFF;
            colorB = 0x00;
            //Get MulitZone Setting
            RT = czGetMulitZoneSetting(ref enabled, ref pageCount);

            //Four steps are necessary!
            //1.Enable Mulit Zone
            enabled = 1;
            RT = czSetEnableMulitZone(enabled);
            //2.Set the page number=1
            pageCount = 1;
            RT = czSetPageCount(pageCount);

            //Get MulitZone Setting
            RT = czGetMulitZoneSetting(ref enabled, ref pageCount);


            zoneSetHead = new ZoneSetHead();
            zoneSetEntry = new ZoneSet[MAX_ZONE_COUNT];

            zoneSetHead.ZoneNum = 4;
            zoneSetEntry[0].ZoneID = 1;
            zoneSetEntry[0].XPos = 0;
            zoneSetEntry[0].YPos = 0;
            zoneSetEntry[0].ZoneWidth = 0x15;
            zoneSetEntry[0].ZoneHeight = 0x10;

            zoneSetEntry[1].ZoneID = 2;
            zoneSetEntry[1].XPos = 0x10;
            zoneSetEntry[1].YPos = 0;
            zoneSetEntry[1].ZoneWidth = 0x10;
            zoneSetEntry[1].ZoneHeight = 0x10;

            zoneSetEntry[2].ZoneID = 3;
            zoneSetEntry[2].XPos = 0x20;
            zoneSetEntry[2].YPos = 0;
            zoneSetEntry[2].ZoneWidth = 0x10;
            zoneSetEntry[2].ZoneHeight = 0x10;

            zoneSetEntry[3].ZoneID = 4;
            zoneSetEntry[3].XPos = 0x30;
            zoneSetEntry[3].YPos = 0;
            zoneSetEntry[3].ZoneWidth = 0x10;
            zoneSetEntry[3].ZoneHeight = 0x10;

            pageID = 1;
            zoneCount = zoneSetHead.ZoneNum;
            //3.reset all zone
            RT = czDivideZone(pageID, 1, zoneSetHead, zoneSetEntry);

            //4.divide four zone
            RT = czDivideZone(pageID, 0, zoneSetHead, zoneSetEntry);

            ZoneDisplaySet zoneDisplayEntry = new ZoneDisplaySet
            {
                ZoneSize = (UInt16)(zoneSetEntry[0].ZoneWidth * zoneSetEntry[0].ZoneHeight),
                ZoneID = zoneSetEntry[0].ZoneID,
                FGColor_R = colorR,
                FGColor_G = colorG,
                FGColor_B = colorB,
                AutoWidth = 1,
                Speed = 1,
                StayTime = 1,
                FontStyle = 0x32,
                LineSpace = 1,
                CloumnSpace = 1,
                BlinkOnTime = 0x0A,
                BlinkOffTime = 0x0A,
                InMode = 3,
                OutMode = 3
            };
            content = "zone1";
            zoneDisplayEntry.ContentSize = (UInt16)content.Length;
            //display a message with property in zone 1
            RT = czSetDisplay(pageID, zoneCount, 0, zoneDisplayEntry, content);

            zoneDisplayEntry = new ZoneDisplaySet
            {
                ZoneSize = (UInt16)(zoneSetEntry[2].ZoneWidth * zoneSetEntry[2].ZoneHeight),
                ZoneID = zoneSetEntry[2].ZoneID,
                FGColor_R = colorR,
                FGColor_G = colorG,
                FGColor_B = colorB,
                AutoWidth = 1,
                Speed = 1,
                StayTime = 1,
                FontStyle = 0x32,
                LineSpace = 1,
                CloumnSpace = 1,
                BlinkOnTime = 0x0A,
                BlinkOffTime = 0x0A,
                InMode = 2,
                OutMode = 2
            };
            content = "zone2";
            zoneDisplayEntry.ContentSize = (UInt16)content.Length;
			Thread.Sleep((int)PARK_SLEEP_TIME);            //display a message with property in zone 2
            RT = czSetDisplay(pageID, zoneCount, 0, zoneDisplayEntry, content);

            ZoneDisplayContentSet zoneDisplayContentEntry = new ZoneDisplayContentSet
            {
                ZoneSize = (UInt16)(zoneSetEntry[0].ZoneWidth * zoneSetEntry[0].ZoneHeight),
                ZoneID = zoneSetEntry[0].ZoneID,
                ZoneType = 0
            };
            content = "";
            msgStr = new byte[30];
            nPos = 0;
            msgStr[nPos++] = 0x08;              //display picture control code
            msgStr[nPos++] = 0x33;              //display picture control code
            msgStr[nPos++] = 0x01;              //"up arrow" picture

            Array.Copy(Encoding.ASCII.GetBytes(content), 0, msgStr, nPos, content.Length);
            nPos += (UInt16)content.Length;
            zoneDisplayContentEntry.ContentSize = (UInt16)nPos;

            Thread.Sleep((int)PARK_SLEEP_TIME);
            //display a message(Picture+text) without propery in zone 1            RT = czSetContentDisplay(pageID, zoneCount, zoneDisplayContentEntry, msgStr);

            zoneDisplayContentEntry = new ZoneDisplayContentSet
            {
                ZoneSize = (UInt16)(zoneSetEntry[1].ZoneWidth * zoneSetEntry[1].ZoneHeight),
                ZoneID = zoneSetEntry[1].ZoneID
            };
            content = "12";
            zoneDisplayContentEntry.ContentSize = (UInt16)content.Length;

            Thread.Sleep((int)PARK_SLEEP_TIME);
            //display a message without propery in zone 2            RT = czSetContentDisplay(pageID, zoneCount, zoneDisplayContentEntry, content);

            zoneDisplayContentEntry = new ZoneDisplayContentSet
            {
                ZoneSize = (UInt16)(zoneSetEntry[2].ZoneWidth * zoneSetEntry[2].ZoneHeight),
                ZoneID = zoneSetEntry[2].ZoneID,
                ZoneType = 0
            };
            content = "";
            msgStr = new byte[30];
            nPos = 0;
            msgStr[nPos++] = 0x08;              //display picture control code
            msgStr[nPos++] = 0x33;              //display picture control code
            msgStr[nPos++] = 0x03;              //"left arrow" picture
            Array.Copy(Encoding.ASCII.GetBytes(content), 0, msgStr, nPos, content.Length);
            nPos += (UInt16)content.Length;
            zoneDisplayContentEntry.ContentSize = (UInt16)nPos;

            Thread.Sleep((int)PARK_SLEEP_TIME);
            //display a message(Picture+text) without propery in zone 3            RT = czSetContentDisplay(pageID, zoneCount, zoneDisplayContentEntry, msgStr);

            zoneDisplayContentEntry = new ZoneDisplayContentSet
            {
                ZoneSize = (UInt16)(zoneSetEntry[3].ZoneWidth * zoneSetEntry[3].ZoneHeight),
                ZoneID = zoneSetEntry[3].ZoneID
            };
            content = "50";
            zoneDisplayContentEntry.ContentSize = (UInt16)content.Length;

            Thread.Sleep((int)PARK_SLEEP_TIME);
            //display a message without propery in zone 4            RT = czSetContentDisplay(pageID, zoneCount, zoneDisplayContentEntry, content);
        }

        private static void MultiZoneDemo(ZoneSetHead zoneSetHead, ZoneSet[] zoneSetEntry)
        {
            UInt32 RT, nPos;
            String content = string.Empty;
            byte[] msgStr = new byte[30];
            byte enabled = 0;
            byte pageCount = 0;
            byte colorR, colorG, colorB, zoneCount = 0, pageID = 0;

            colorR = 0xFF;
            colorG = 0x00;
            colorB = 0x00;

            //Get MulitZone Setting
            RT = czGetMulitZoneSetting(ref enabled, ref pageCount);

            //Four steps are necessary!
            //1.Enable Mulit Zone
            enabled = 1;
            RT = czSetEnableMulitZone(enabled);
            //2.Set the page number=1
            pageCount = 1;
            RT = czSetPageCount(pageCount);

            //Get MulitZone Setting
            RT = czGetMulitZoneSetting(ref enabled, ref pageCount);

            zoneSetHead = new ZoneSetHead
            {
                ZoneNum = (byte)MAX_ZONE_COUNT
            };

            zoneSetEntry = new ZoneSet[zoneSetHead.ZoneNum];

            zoneSetEntry[0].ZoneID = 1;
            zoneSetEntry[0].XPos = 0xB4;
            zoneSetEntry[0].YPos = 0x00;
            zoneSetEntry[0].ZoneWidth = 0x1E;
            zoneSetEntry[0].ZoneHeight = 0x08;

            zoneSetEntry[1].ZoneID = 2;
            zoneSetEntry[1].XPos = 0x00;
            zoneSetEntry[1].YPos = 0x09;
            zoneSetEntry[1].ZoneWidth = 0x10;
            zoneSetEntry[1].ZoneHeight = 0x08;

            zoneSetEntry[2].ZoneID = 3;
            zoneSetEntry[2].XPos = 0x10;
            zoneSetEntry[2].YPos = 0x09;
            zoneSetEntry[2].ZoneWidth = 0x08;
            zoneSetEntry[2].ZoneHeight = 0x08;

            zoneSetEntry[3].ZoneID = 4;
            zoneSetEntry[3].XPos = 0x20;
            zoneSetEntry[3].YPos = 0x09;
            zoneSetEntry[3].ZoneWidth = 0x81;
            zoneSetEntry[3].ZoneHeight = 0x08;

            zoneSetEntry[4].ZoneID = 5;
            zoneSetEntry[4].XPos = 0xC1;
            zoneSetEntry[4].YPos = 0x09;
            zoneSetEntry[4].ZoneWidth = 0x10;
            zoneSetEntry[4].ZoneHeight = 0x08;

            zoneSetEntry[5].ZoneID = 6;
            zoneSetEntry[5].XPos = 0x00;
            zoneSetEntry[5].YPos = 0x14;
            zoneSetEntry[5].ZoneWidth = 0x10;
            zoneSetEntry[5].ZoneHeight = 0x08;

            zoneSetEntry[6].ZoneID = 7;
            zoneSetEntry[6].XPos = 0x10;
            zoneSetEntry[6].YPos = 0x14;
            zoneSetEntry[6].ZoneWidth = 0x08;
            zoneSetEntry[6].ZoneHeight = 0x08;

            zoneSetEntry[7].ZoneID = 8;
            zoneSetEntry[7].XPos = 0x20;
            zoneSetEntry[7].YPos = 0x14;
            zoneSetEntry[7].ZoneWidth = 0x81;
            zoneSetEntry[7].ZoneHeight = 0x08;

            zoneSetEntry[8].ZoneID = 9;
            zoneSetEntry[8].XPos = 0xC1;
            zoneSetEntry[8].YPos = 0x14;
            zoneSetEntry[8].ZoneWidth = 0x20;
            zoneSetEntry[8].ZoneHeight = 0x28;

            pageID = 1;
            zoneCount = zoneSetHead.ZoneNum;
            //3.reset all zone
            RT = czDivideZone(pageID, 1, zoneSetHead, zoneSetEntry);

            //4.divide nine zone
            RT = czDivideZone(pageID, 00, zoneSetHead, zoneSetEntry);

            var zoneDisplayEntry = new ZoneDisplaySet
            {
                ZoneSize = (UInt16)(zoneSetEntry[0].ZoneWidth * zoneSetEntry[0].ZoneHeight),
                ZoneID = zoneSetEntry[0].ZoneID,
                ZoneType = 2,
                InMode = 0,
                OutMode = 0,
                FGColor_R = colorR,
                FGColor_G = colorG,
                FGColor_B = colorB,
                Speed = 1,
                StayTime = 1,
                FontStyle = (byte)CZ_FONT_EN_7x6
            };
            msgStr = new byte[30];
            nPos = 0;
            msgStr[nPos++] = 0x08;
            msgStr[nPos++] = 0x00;
            zoneDisplayEntry.ContentSize = (UInt16)nPos;
            //display HH:MM with property in zone 1
            RT = czSetDisplay(pageID, zoneCount, 0, zoneDisplayEntry, msgStr);

            zoneDisplayEntry = new ZoneDisplaySet
            {
                ZoneSize = (UInt16)(zoneSetEntry[1].ZoneWidth * zoneSetEntry[1].ZoneHeight),
                ZoneType = 0,
                ZoneID = zoneSetEntry[1].ZoneID,
                InMode = 0,
                OutMode = 0,
                FGColor_R = colorR,
                FGColor_G = colorG,
                FGColor_B = colorB,
                Speed = 1,
                StayTime = 100,
                FontStyle = (byte)CZ_FONT_EN_7x6
            };
            content = "T6";
            zoneDisplayEntry.ContentSize = (UInt16)content.Length;
            //display static message with property in zone 2
            RT = czSetDisplay(pageID, zoneCount, 0, zoneDisplayEntry, content);

            zoneDisplayEntry = new ZoneDisplaySet
            {
                ZoneSize = (UInt16)(zoneSetEntry[2].ZoneWidth * zoneSetEntry[2].ZoneHeight),
                ZoneID = zoneSetEntry[2].ZoneID,
                InMode = 0,
                OutMode = 0,
                FGColor_R = colorR,
                FGColor_G = colorG,
                FGColor_B = colorB,
                Speed = 1,
                StayTime = 1,
                FontStyle = (byte)CZ_FONT_EN_7x6
            };
            content = "2";
            zoneDisplayEntry.ContentSize = (UInt16)content.Length;
            //display static message with property in zone 3
            RT = czSetDisplay(pageID, 9, 0, zoneDisplayEntry, content);

            zoneDisplayEntry = new ZoneDisplaySet
            {
                ZoneSize = (UInt16)(zoneSetEntry[3].ZoneWidth * zoneSetEntry[3].ZoneHeight),
                ZoneID = zoneSetEntry[3].ZoneID,
                InMode = 1,
                OutMode = 1,
                FGColor_R = colorR,
                FGColor_G = colorG,
                FGColor_B = colorB,
                Speed = 1,
                StayTime = 1,
                FontStyle = (byte)CZ_FONT_EN_7x6
            };
            content = "Hello,Welcome To China!";
            zoneDisplayEntry.ContentSize = (UInt16)content.Length;
            //display MoveLeft message with property in zone 4
            RT = czSetDisplay(pageID, zoneCount, 0, zoneDisplayEntry, content);

            zoneDisplayEntry = new ZoneDisplaySet
            {
                ZoneSize = (UInt16)(zoneSetEntry[4].ZoneWidth * zoneSetEntry[4].ZoneHeight),
                ZoneID = zoneSetEntry[4].ZoneID,
                InMode = 0,
                OutMode = 0,
                FGColor_R = colorR,
                FGColor_G = colorG,
                FGColor_B = colorB,
                Speed = 1,
                StayTime = 1,
                FontStyle = (byte)CZ_FONT_EN_7x6
            };
            content = "X0";
            zoneDisplayEntry.ContentSize = (UInt16)content.Length;
            //display static message with property in zone 5
            RT = czSetDisplay(pageID, zoneCount, 0, zoneDisplayEntry, content);

            zoneDisplayEntry = new ZoneDisplaySet
            {
                ZoneSize = (UInt16)(zoneSetEntry[5].ZoneWidth * zoneSetEntry[5].ZoneHeight),
                ZoneID = zoneSetEntry[5].ZoneID,
                InMode = 0,
                OutMode = 0,
                FGColor_R = colorR,
                FGColor_G = colorG,
                FGColor_B = colorB,
                Speed = 1,
                StayTime = 1,
                FontStyle = (byte)CZ_FONT_EN_7x6
            };
            content = "T6";
            zoneDisplayEntry.ContentSize = (UInt16)content.Length;
            //display static message with property in zone 6
            RT = czSetDisplay(pageID, zoneCount, 0, zoneDisplayEntry, content);

            zoneDisplayEntry = new ZoneDisplaySet
            {
                ZoneSize = (UInt16)(zoneSetEntry[6].ZoneWidth * zoneSetEntry[6].ZoneHeight),
                ZoneID = zoneSetEntry[6].ZoneID,
                InMode = 0,
                OutMode = 0,
                FGColor_R = colorR,
                FGColor_G = colorG,
                FGColor_B = colorB,
                Speed = 1,
                StayTime = 1,
                FontStyle = (byte)CZ_FONT_EN_7x6
            };
            content = "2";
            zoneDisplayEntry.ContentSize = (UInt16)content.Length;
            //display static message with property in zone 7
            RT = czSetDisplay(pageID, zoneCount, 0, zoneDisplayEntry, content);

            zoneDisplayEntry = new ZoneDisplaySet
            {
                ZoneSize = (UInt16)(zoneSetEntry[7].ZoneWidth * zoneSetEntry[7].ZoneHeight),
                ZoneID = zoneSetEntry[7].ZoneID,
                InMode = 1,
                OutMode = 1,
                FGColor_R = colorR,
                FGColor_G = colorG,
                FGColor_B = colorB,
                Speed = 1,
                StayTime = 1,
                FontStyle = (byte)CZ_FONT_EN_7x6
            };
            content = "This is Chainzone!";
            zoneDisplayEntry.ContentSize = (UInt16)content.Length;
            //display MoveLeft message with property in zone 8
            RT = czSetDisplay(pageID, zoneCount, 0, zoneDisplayEntry, content);

            zoneDisplayEntry = new ZoneDisplaySet
            {
                ZoneSize = (UInt16)(zoneSetEntry[8].ZoneWidth * zoneSetEntry[8].ZoneHeight),
                ZoneID = zoneSetEntry[8].ZoneID,
                InMode = 0,
                OutMode = 0,
                FGColor_R = colorR,
                FGColor_G = colorG,
                FGColor_B = colorB,
                Speed = 1,
                StayTime = 1,
                FontStyle = (byte)CZ_FONT_EN_7x6,
                Align = 0x11
            };
            content = "X0";
            zoneDisplayEntry.ContentSize = (UInt16)content.Length;
            //display static message with property in zone 9
            RT = czSetDisplay(pageID, zoneCount, 0, zoneDisplayEntry, content);

            ZoneDisplayContentSet zoneDisplayContentEntry;
            zoneDisplayContentEntry = new ZoneDisplayContentSet
            {
                ZoneSize = (UInt16)(zoneSetEntry[1].ZoneWidth * zoneSetEntry[1].ZoneHeight),
                ZoneID = zoneSetEntry[1].ZoneID
            };
            content = "T9";
            zoneDisplayContentEntry.ContentSize = (UInt16)content.Length;
            //display a new message without propery in zone 2(qucikly modify the message of zone 2)
            Thread.Sleep((int)PARK_SLEEP_TIME);
            RT = czSetContentDisplay(pageID, zoneCount, zoneDisplayContentEntry, content);

            zoneDisplayContentEntry = new ZoneDisplayContentSet
            {
                ZoneSize = (UInt16)(zoneSetEntry[3].ZoneWidth * zoneSetEntry[3].ZoneHeight),
                ZoneID = zoneSetEntry[3].ZoneID
            };
            content = "HELLO,WELCOME TO CHINA!";
            zoneDisplayContentEntry.ContentSize = (UInt16)content.Length;
            //display a new moveleft message without propery in zone 4(qucikly modify the message of zone 4)
            Thread.Sleep((int)PARK_SLEEP_TIME);
            RT = czSetContentDisplay(pageID, zoneCount, zoneDisplayContentEntry, content);
        }

        private static void FileExistDemo()
        {
            string fileName = "C:\\operator.cfg";
            var ret = czIsFileExist(fileName);
        }

        private static void ParkAPIDemo()
        {
            UInt32 RT;
            byte pageID = 1;

            czinterface If = new czinterface();
            InitIFStruct(ref If);
            czInitAPI(ref If);

            ZoneSetHead zoneSetHead = new ZoneSetHead();
            ZoneSet[] zoneSetEntry = new ZoneSet[MAX_ZONE_COUNT];

            IntPtr pt = Marshal.AllocHGlobal((int)(Marshal.SizeOf(typeof(ZoneSet)) * MAX_ZONE_COUNT));
            SetBufferZero(pt, (int)(Marshal.SizeOf(typeof(ZoneSet)) * MAX_ZONE_COUNT));
            RT = czGetZone(ref zoneSetHead, pt, (byte)MAX_ZONE_COUNT);

            for (int i = 0; i < MAX_ZONE_COUNT; i++)
            {
                IntPtr ptr = (IntPtr)((UInt32)pt + i * Marshal.SizeOf(typeof(ZoneSet)));
                zoneSetEntry[i] = (ZoneSet)Marshal.PtrToStructure(ptr, typeof(ZoneSet));
            }
            Marshal.FreeHGlobal(pt);

			var path = ".\\upArrow.bmp";
            var tmp = "D:\\P\\1.bmp";
            RT = czWriteSpecFile(tmp, path);
            path = ".\\leftArrow.bmp";
            tmp = "D:\\P\\2.bmp";
            RT = czWriteSpecFile(tmp, path);
            path = ".\\rigthArrow.bmp";
            tmp = "D:\\P\\3.bmp";
            RT = czWriteSpecFile(tmp, path);

            SingleZoneDemo(zoneSetHead, zoneSetEntry);

            TwoZoneDemo(zoneSetHead, zoneSetEntry);

            FourZoneDemo(zoneSetHead, zoneSetEntry);

            MultiZoneDemo(zoneSetHead, zoneSetEntry);
        }

        private class PixelCheckResult
        {
            public uint Port;
            public uint X;
            public uint Y;
            public uint ErrNum;
            public string Status;
            public string DateTime;
        }

        static void CSVTestDemo(ZoneSetHead zoneSetHead, ZoneSet[] zoneSetEntry)
        {
            //屏宽=112，屏高=48
            //根据主板坏点csv生成整屏像点检测的csv

            //var nResult = czPxlChk("F:\\pxl.csv", "PXL.csv");

            var datetime = DateTime.Now.ToString("yyyy/MM/dd HH:mm");

            var pixelCheckResult = new Dictionary<Tuple<uint ,uint>, PixelCheckResult>();
            using (StreamReader sr = new StreamReader("PXL.csv"))
            {
                // 跳过第一行
                string line = sr.ReadLine();

                line = sr.ReadLine();
                //生成行数据
                while (!(string.IsNullOrWhiteSpace(line) || line.CompareTo(",,,,,") == 0))
                {
                    var result = ReadlineToPixelCheckResult(line, 6);
                    if (pixelCheckResult.ContainsKey(Tuple.Create(result.X, result.Y)))
                    {
                        line = sr.ReadLine();
                        continue;
                    }
                    pixelCheckResult.Add(Tuple.Create(result.X, result.Y), result);
                    line = sr.ReadLine();
                }
            }

            if (pixelCheckResult.Count > 0)
            {
                datetime = pixelCheckResult.First().Value.DateTime;
            }

            // 生成新的文件
            using (StreamWriter sr = new StreamWriter("NewPXL.csv"))
            {
                sr.WriteLine("Port,X,Y,ErrNum,Status,DateTime");
                for (uint col = 0; col < 112; col++)
                {
                    for (uint row = 0; row < 48; row++)
                    {
                        PixelCheckResult reuslt;
                        pixelCheckResult.TryGetValue(Tuple.Create(col, row), out reuslt);

                        if (reuslt == null)
                        {
                            // 插入无问题数据
                            sr.WriteLine("0,{0},{1},0,\"\",{2}", col, row, datetime);
                            continue;
                        }

                        sr.WriteLine("{0},{1},{2},{3},\"{4}\",{5}", reuslt.Port, reuslt.X, reuslt.Y, reuslt.ErrNum, reuslt.Status, reuslt.DateTime);
                    }
                }
            }

            //在每行颜色不同的demo，参考SingleZoneDemo
            UInt32 RT, nPos;
            String content;
            byte[] msgStr = new byte[500];

            byte enabled = 0, pageCount = 0, colorR, colorG, colorB, zoneCount = 0, pageID = 0;

            colorR = 0xFF;
            colorG = 0xFF;
            colorB = 0xFF;
            //Get MulitZone Setting
            RT = czGetMulitZoneSetting(ref enabled, ref pageCount);

            //Four steps are necessary!
            //1.Enable Mulit Zone
            enabled = 1;
            RT = czSetEnableMulitZone(enabled);
            //2.Set the page number=1
            pageCount = 1;
            RT = czSetPageCount(pageCount);

            //Get MulitZone Setting
            RT = czGetMulitZoneSetting(ref enabled, ref pageCount);

            zoneSetHead = new ZoneSetHead
            {
                ZoneNum = 1
            };

            zoneSetEntry = new ZoneSet[MAX_ZONE_COUNT];
            zoneSetEntry[0].ZoneID = 1;
            zoneSetEntry[0].XPos = 0;
            zoneSetEntry[0].YPos = 0;
            zoneSetEntry[0].ZoneWidth = 0x40;
            zoneSetEntry[0].ZoneHeight = 0x30;

            pageID = 1;
            zoneCount = zoneSetHead.ZoneNum;
            //3.reset all zone
            RT = czDivideZone(pageID, 1, zoneSetHead, zoneSetEntry);

            //4.divide one zone
            RT = czDivideZone(pageID, 0, zoneSetHead, zoneSetEntry);

            ZoneDisplaySet zoneDisplayEntry = new ZoneDisplaySet
            {
                ZoneSize = (UInt16)(zoneSetEntry[0].ZoneWidth * zoneSetEntry[0].ZoneHeight),
                ZoneID = zoneSetEntry[0].ZoneID,
                ZoneType = 0,
                CodeType = 0,
                InMode = 0,
                OutMode = 0,
                Align = 0,
                FGColor_R = 0,
                FGColor_G = colorG,
                FGColor_B = colorB,
                BGColor_R = 0,
                BGColor_G = 0,
                BGColor_B = 0,
                AutoLine = 0,
                AutoWidth = 1,
                Speed = 0,
                StayTime = 2,
                Times = 0,
                FontStyle = (byte)CZ_FONT_EN_14x8,       //CZ_FONT_EN_7x6
                LineSpace = 1,
                CloumnSpace = 1,
                BlinkOnTime = 0x0A,
                BlinkOffTime = 0x0A
            };

            //display a message(English+chinese+English) without property in zone
            var zoneDisplayContentEntry = new ZoneDisplayContentSet
            {
                ZoneSize = (UInt16)(zoneSetEntry[0].ZoneWidth * zoneSetEntry[0].ZoneHeight),
                ZoneID = zoneSetEntry[0].ZoneID
            };
            nPos = 0;

            // line 1
            msgStr[nPos++] = 0x08;
            msgStr[nPos++] = 0x30;
            msgStr[nPos++] = 0xFF; // R
            msgStr[nPos++] = 0; // G
            msgStr[nPos++] = 0;// B
            content = "123\n";
            Array.Copy(Encoding.ASCII.GetBytes(content), 0, msgStr, nPos, content.Length);

            // line 2
            nPos += (uint)content.Length;
            msgStr[nPos++] = 0x08;
            msgStr[nPos++] = 0x30;
            msgStr[nPos++] = 0x80; // R
            msgStr[nPos++] = 0; // G
            msgStr[nPos++] = 0;// B
            content = "456\n";
            Array.Copy(Encoding.ASCII.GetBytes(content), 0, msgStr, nPos, content.Length);

            // line 3
            nPos += (uint)content.Length;
            msgStr[nPos++] = 0x08;              //switch font control code
            msgStr[nPos++] = 0x30;              //switch font control code
            msgStr[nPos++] = 0x0A; // R
            msgStr[nPos++] = 0; // G
            msgStr[nPos++] = 0;// B
            content = "789\n";
            Array.Copy(Encoding.ASCII.GetBytes(content), 0, msgStr, nPos, content.Length);
            nPos += (uint)content.Length;
            zoneDisplayContentEntry.ContentSize = (UInt16)nPos;
            Thread.Sleep((int)PARK_SLEEP_TIME);
            RT = czSetContentDisplay(pageID, zoneCount, zoneDisplayContentEntry, msgStr);
        }

        private static PixelCheckResult ReadlineToPixelCheckResult(string line, int count)
        {
            PixelCheckResult result = new PixelCheckResult();
            string[] strArray = line.Split(',');
            var idx = 0;
            if (count == strArray.Count())
            {
                result.Port = Convert.ToUInt32(strArray[idx++]);
                result.X = Convert.ToUInt32(strArray[idx++]);
                result.Y = Convert.ToUInt32(strArray[idx++]);
                result.ErrNum = Convert.ToUInt32(strArray[idx++]);
                result.Status = strArray[idx++];
                result.DateTime = strArray[idx++];
            }
            else
            {
                //deal with doublue " contains ,
                List<string> temp = new List<string>();
                for (int i = 0; i < line.ToArray().Length; i++)
                {
                    if (line[i] != '"')
                    {
                        int index = line.IndexOf(",", i);
                        if (index == -1)
                            temp.Add(line.Substring(i));
                        else
                        {
                            temp.Add(line.Substring(i, index - i));
                            i = index;
                        }
                    }
                    else if (line[i] == ',')
                    {
                        temp.Add(string.Empty);
                    }
                    else if (line[i] == '"')
                    {
                        int index = line.IndexOf("\"", i + 1);
                        temp.Add(line.Substring(i + 1, index - i - 1));
                        i = index;
                    }

                }
                if (line.EndsWith(",")) temp.Add(string.Empty);

                result.Port = Convert.ToUInt32(temp[idx++]);
                result.X = Convert.ToUInt32(temp[idx++]);
                result.Y = Convert.ToUInt32(temp[idx++]);
                result.ErrNum = Convert.ToUInt32(temp[idx++]);
                result.Status = temp[idx++];
                idx++;
                result.DateTime = temp[idx++];
            }
            return result;
        }

        private static void ControlPlaylistDemo()
        {
            UInt32 nResult;
            byte curPLIndex = 0;
            //========================================================================================================
            //===== Playlist control
            //========================================================================================================	

            //according to the "DEMO1.LST" template file generates the required files, The file is in XML format
            nResult = czPLInit(".\\", "DEMO.LST");

            //Read Current Playlist on the sign and save to "DEMO.LST", Use "czPLReadFromLED(1)" if you need to read files
            nResult = czPLReadFromLED(0);
            nResult = czPLSave();

            //Modify to what you want in the "DEMO.LST"
            //...

            //Load new Playlist
            nResult = czLoadSYSFromXML("DEMO.LST");

            //Send to new Playlist to the sign, Use "czPLSendToLED(1)" if you need to send files
            nResult = czPLSendToLED(0);
        }

        private static void ControlForSpecialLCS()
        {
            UInt32 RT;
            Byte action = 0;
            string msgStr = "测试";

            czinterface If = new czinterface();
            InitIFStruct(ref If);
            czInitAPI(ref If);

            RT = czGetLCS(ref action);     //0:close	1:red cross open	2: green arrow open
            RT = czSetLCS(action);      //0:close	1:red cross open	2: green arrow open

            Byte voiceSwitch = 1;       //0:close	1:open
            Byte voiceEncode = 3;       //0:GB2312	1:GBK	2:BIG5	3:UNICODE
            RT = czPlayVoice(voiceSwitch, voiceEncode, msgStr, (Byte)msgStr.Length);
        }

        static void Main(string[] args)
        {
            //============================================================================================================
            //==== Easy API Demo
            //============================================================================================================
            EasyAPIDemo();

            //============================================================================================================
            //==== API Demo (Advenced)
            //============================================================================================================
            APIDemoAdvenced();

            //============================================================================================================
            //==== Mulit Signs Content Update API Demo
            //============================================================================================================
            //ShowFilesToMulitSigns();

            //============================================================================================================
            //==== Mulit Thread Demo
            //============================================================================================================
            //MultiThreadDemo();

            //============================================================================================================
            //==== Park API Demo
            //============================================================================================================     
            //ParkAPIDemo();
        }

    }
}
