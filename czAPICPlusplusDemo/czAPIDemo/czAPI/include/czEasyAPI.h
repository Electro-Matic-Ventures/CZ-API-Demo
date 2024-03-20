#ifndef __EASY_JETFILEII__H__
#define __EASY_JETFILEII__H__

#include "czType.h"

#ifdef __cplusplus
extern "C" {
#endif

//================================================================================================================
//==== font define, 常用字体定义,字体控制符不限于这些,详细请参考JetFileII协议
//================================================================================================================
#define CZ_FONT_EN_5x5					0x30					// 5 * 5 标准英文字体
#define CZ_FONT_EN_7x6					0x31					// 7 * 6 标准英文字体
#define CZ_FONT_EN_14x8					0x32					// 14 * 8 标准英文字体
#define CZ_FONT_EN_15x9					0x33					// 15 * 9 标准英文字体
#define CZ_FONT_EN_16x9					0x34					// 16 * 9 标准英文字体,
#define CZ_FONT_CH_ST_16x16				0x35					// 16 * 16标准中文字体
#define CZ_FONT_EN_24x16				0x36					// 24 * 16 标准英文字体
#define CZ_FONT_CH_ST_24x24				0x37					// 24 * 24标准中文字体
#define CZ_FONT_EN_32x18				0x38					// 32 * 18 标准英文字体
#define CZ_FONT_CH_ST_32x32				0x39					// 32 * 32标准中文字体
#define CZ_FONT_EN_11x9					0x3a					// 11 * 9标准英文字体
#define CZ_FONT_EN_22x18				0x3c					// 22 * 18标准英文字体
#define CZ_FONT_EN_30x18				0x3d					// 30 * 18标准英文字体
#define CZ_FONT_EN_40x21				0x3e					// 40 * 21标准英文字体
#define CZ_FONT_BG_ST_16x16				0x3f					// 16 * 16繁体简码中文字库
#define CZ_FONT_CH_ST_40x40				0x47					// 40号宋体
#define CZ_FONT_CH_HT_40x40				0x48					// 40号黑体
#define CZ_FONT_CH_XW_40x40				0x49					// 40号新魏
#define CZ_FONT_CH_XK_40x40				0x4a					// 40号行楷
#define CZ_FONT_CH_LS_40x40				0x4b					// 40号隶书
#define CZ_FONT_CH_YY_40x40				0x4C					// 40号幼圆
#define CZ_FONT_CH_HT_24x24				0x57					// 24号黑体
#define CZ_FONT_CH_XW_24x24				0x58					// 24号新魏
#define CZ_FONT_CH_XK_24x24				0x59					// 24号行楷
#define CZ_FONT_CH_LS_24x24				0x5A					// 24号隶书
#define CZ_FONT_CH_YY_24x24				0x5B					// 24号幼圆
#define CZ_FONT_CH_HT_32x32				0x5c					// 32号黑体
#define CZ_FONT_CH_XW_32x32				0x5d					// 32号新魏
#define CZ_FONT_CH_XK_32x32				0x5e					// 32号行楷
#define CZ_FONT_CH_LS_32x32				0x5f					// 32号隶书
#define CZ_FONT_CH_YY_32x32				0x60					// 32号幼圆
#define CZ_FONT_ENB_14x10				0x4e					// 14 * 10粗体英文字体
#define CZ_FONT_ENB_15x10				0x4f					// 15 * 10粗体英文字体
#define CZ_FONT_ENB_16x12				0x50					// 16 * 12粗体英文字体
#define CZ_FONT_ENB_24x8				0x51					// 24 * 8粗体英文字体
#define CZ_FONT_ENB_32x8				0x52					// 32 * 8粗体英文字体
#define CZ_FONT_ENB_11x7				0x53					// 11 * 7粗体英文字体
#define CZ_FONT_CH_ST_64x64				0x63					// 64号宋体

//================================================================================================================
//==== color define,常用定义,不限于这些,详细请参考JetFileII协议,可以自定义颜色 [R][G][B]['/'], R为前高字节
//================================================================================================================
#define CZ_COLOR_BLACK					0x30					// 黑色
#define CZ_COLOR_RED					0x31					// red
#define CZ_COLOR_GREEN					0x32					// green
#define CZ_COLOR_AMBER					0x33					// amber

//================================================================================================================
//==== mode define,常用定义,不限于这些,详细请参考JetFileII协议
//================================================================================================================
#define CZ_MODE_RAND					0x2F					// 随机
#define CZ_MODE_STATIC					0x30					// 静止
#define CZ_MODE_MOVELEFT				0x31					// 左移
#define CZ_MODE_MOVERIGHT				0x32					// 右移
#define CZ_MODE_MOVEUP					0x35					// 上移
#define CZ_MODE_MOVEDOWN				0x36					// 下移

//****************************************************************************************************************
//**** 函数名:czShowMsg
//**** 功  能:控制显示屏显示信息,如果发送F盘成功,就把内容存放到F盘,否则就存放到D盘
//**** 参  数:
//****        msg             - 显示信息
//****        msg_size        - 信息大小
//****        font            - 字体,参考font define
//****        color           - 颜色,参考color define,如果最低字节定义为'/'表示自定义颜色,排列为"RGB/"
//****        mode            - 花样,参考mode define
//****        stay_time_sec   - 停留时间,0-9999 sec
//****        sign_ip         - 显示屏IP地址
//****        sign_port       - 显示屏端口
//****        is_store_ram    - 是否保存了RAM中,1=表示保存在RAM中，0表示保存在F盘或D盘
//****        is_send_playlist- 是否发送播放列表，默认是发送的
//**** 返回值:
//****        0               - 成功
//****        other           - 失败
//****************************************************************************************************************
CZAPI_DECLARE(INT32U) czShowMsg(char* msg, INT32U msg_size, INT32U font,INT32U color,INT32U mode, 
	                              INT32U stay_time_sec, char* sign_ip,INT32U sign_port,INT32U is_store_ram=0,
								  INT32U is_send_playlist=1);

//****************************************************************************************************************
//**** 函数名:czShowPic
//**** 功  能:控制显示屏显示图片,如果发送F盘成功,就把内容存放到F盘,否则就存放到D盘
//**** 参  数:
//****        bitmap          - bmp图片
//****        bmp_size        - 信息大小
//****        mode            - 花样,参考mode define
//****        stay_time_sec   - 停留时间,0-9999 sec
//****        sign_ip         - 显示屏IP地址
//****        sign_port       - 显示屏端口
//****        is_store_ram    - 是否保存了RAM中,1=表示保存在RAM中，0表示保存在F盘或D盘
//**** 返回值:
//****        0               - 成功
//****        other           - 失败
//****************************************************************************************************************
CZAPI_DECLARE(INT32U) czShowPic(char* bitmap, INT32U bmp_size, INT32U mode, INT32U stay_time_sec,
	                              char* sign_ip,INT32U sign_port,INT32U is_store_ram=0);


//****************************************************************************************************************
//**** 函数名:czShowFiles
//**** 功  能:控制显示屏显示一组文件，文件类型可以是bmp,pmg,nmg,qst,flw格式,
//*****       如果发送F盘成功,就把内容存放到F盘,否则就存放到D盘
//**** 参  数:
//****        files           - 文件在本机PC的路径，2维数组结构
//****        numfiles        - 文件个数,即1维的长度
//****        mode            - 花样,参考mode define,只对bmp有效(实际是修改屏的默认配置)
//****        stay_time_sec   - 停留时间,0-9999 sec,只对bmp有效，
//****        sign_ip         - 显示屏IP地址
//****        sign_port       - 显示屏端口
//****        is_store_ram    - 是否保存了RAM中,1=表示保存在RAM中，0表示保存在F盘或D盘
//**** 返回值:
//****        0               - 成功
//****        other           - 失败
//****************************************************************************************************************
CZAPI_DECLARE(INT32U) czShowFiles(char* files[], INT32U numfiles, INT32U mode, INT32U stay_time_sec,
	                                char* sign_ip,INT32U sign_port,INT32U is_store_ram=0);

//****************************************************************************************************************
//**** 函数名:czShowBmpToNmg
//**** 功  能:把图片转为Nmg文件
//**** 参  数:
//****        bmp_path_name   - bmp路径和文件名
//****        nmg_path_name   - nmg路径和文件名
//****        mode            - 花样,参考mode define
//****        stay_time_sec   - 停留时间,0-9999 sec
//**** 返回值:
//****        0               - 成功
//****        other           - 失败
//****************************************************************************************************************
CZAPI_DECLARE(INT32U) czShowBmpToNmg(char* bmp_path_name, char* nmg_path_name, INT32U mode, INT32U stay_time_sec);

//****************************************************************************************************************
//**** 函数名:czShowMsgToNmg
//**** 功  能:把char*转为Nmg文件
//**** 参  数:
//****        msg             - 显示文字
//****        msg_size        - msg size
//****        nmg_path_name   - nmg路径和文件名
//****        font            - 字体,参考font define
//****        color           - 颜色,参考color define,如果最低字节定义为'/'表示自定义颜色,排列为"RGB/"
//****        mode            - 花样,参考mode define
//****        stay_time_sec   - 停留时间,0-9999 sec
//**** 返回值:
//****        0               - 成功
//****        other           - 失败
//****************************************************************************************************************
CZAPI_DECLARE(INT32U) czShowMsgToNmg(char* msg, INT32U msg_size, char* nmg_path_name,INT32U font,INT32U color,
	                                 INT32U mode, INT32U stay_time_sec);

//****************************************************************************************************************
//**** 函数名:czTubeCtrl
//**** 功  能:计分牌控制
//**** 参  数:
//****        ctrl_cmd        - 控制命令
//****        ctrl            - 控制信息
//****        msg_size        - 信息大小
//****        sign_ip         - 显示屏IP地址
//****        sign_port       - 显示屏端口
//**** 返回值:
//****        0               - 成功
//****        other           - 失败
//****************************************************************************************************************
CZAPI_DECLARE(INT32U) czTubeCtrl(INT8U ctrl_cmd, INT8U* ctrl, INT32U msg_size, char* sign_ip,INT32U sign_port);

CZAPI_DECLARE(INT32U) czEasyWriteFile(char* pc_file_path, char* sign_file_path,char* sign_ip,INT32U sign_port);
CZAPI_DECLARE(INT32U) czEasyReadFile(char* pc_file_path, char* sign_file_path,char* sign_ip,INT32U sign_port);


//****************************************************************************************************************
//**** 函数名:czShowFilesEx
//**** 功  能:控制显示屏显示一组文件，文件类型可以是bmp,pmg,nmg,qst,flw格式,
//*****       如果发送F盘成功,就把内容存放到F盘,否则就存放到D盘(支持以太网,串口)
//**** 参  数:
//****        files           - 文件在本机PC的路径，2维数组结构
//****        numfiles        - 文件个数,即1维的长度
//****        mode            - 花样,参考mode define,只对bmp有效(实际是修改屏的默认配置)
//****        stay_time_sec   - 停留时间,0-9999 sec,只对bmp有效，
//****        sign_ip         - 显示屏IP地址
//****        sign_port       - 显示屏端口
//****        is_store_ram    - 是否保存了RAM中,1=表示保存在RAM中，0表示保存在F盘或D盘
//****        type			  - 通讯方式
//****        comStr		  - 串口标识符
//****        baudrate        - 波特率
//****        dstAddr         - GGUU地址
//**** 返回值:
//****        0               - 成功
//****        other           - 失败
//****************************************************************************************************************
CZAPI_DECLARE(INT32U) czShowFilesEx(char* files[], INT32U numfiles, INT32U mode, INT32U stay_time_sec,
	                                char* sign_ip,INT32U sign_port,INT32U is_store_ram=0,
									conn_type type=COMM_UDP,char* comStr="COM3",INT32U baudrate=9600,INT16U dstAddr=0x0101);

//****************************************************************************************************************
//**** 函数名:czShowMsgEx
//**** 功  能:控制显示屏显示信息,如果发送F盘成功,就把内容存放到F盘,否则就存放到D盘(支持以太网,串口)
//**** 参  数:
//****        msg             - 显示信息
//****        msg_size        - 信息大小
//****        font            - 字体,参考font define
//****        color           - 颜色,参考color define,如果最低字节定义为'/'表示自定义颜色,排列为"RGB/"
//****        mode            - 花样,参考mode define
//****        stay_time_sec   - 停留时间,0-9999 sec
//****        sign_ip         - 显示屏IP地址
//****        sign_port       - 显示屏端口
//****        is_store_ram    - 是否保存了RAM中,1=表示保存在RAM中，0表示保存在F盘或D盘
//****        is_send_playlist- 是否发送播放列表，默认是发送的
//****        type			  - 通讯方式
//****        comStr		  - 串口标识符
//****        baudrate        - 波特率
//****        dstAddr         - GGUU地址
//**** 返回值:
//****        0               - 成功
//****        other           - 失败
//****************************************************************************************************************
CZAPI_DECLARE(INT32U) czShowMsgEx(char* msg, INT32U msg_size, INT32U font,INT32U color,INT32U mode, 
	                              INT32U stay_time_sec, char* sign_ip,INT32U sign_port,INT32U is_store_ram=0,
								  INT32U is_send_playlist=1,
								  conn_type type=COMM_UDP,char* comStr="COM3",INT32U baudrate=9600,INT16U dstAddr=0x0101);

//****************************************************************************************************************
//**** 函数名:czShowPicEx
//**** 功  能:控制显示屏显示图片,如果发送F盘成功,就把内容存放到F盘,否则就存放到D盘(支持以太网,串口)
//**** 参  数:
//****        bitmap          - bmp图片
//****        bmp_size        - 信息大小
//****        mode            - 花样,参考mode define
//****        stay_time_sec   - 停留时间,0-9999 sec
//****        sign_ip         - 显示屏IP地址
//****        sign_port       - 显示屏端口
//****        is_store_ram    - 是否保存了RAM中,1=表示保存在RAM中，0表示保存在F盘或D盘
//****        type			  - 通讯方式
//****        comStr		  - 串口标识符
//****        baudrate        - 波特率
//****        dstAddr         - GGUU地址
//**** 返回值:
//****        0               - 成功
//****        other           - 失败
//****************************************************************************************************************
CZAPI_DECLARE(INT32U) czShowPicEx(char* bitmap, INT32U bmp_size, INT32U mode, INT32U stay_time_sec,
	                              char* sign_ip,INT32U sign_port,INT32U is_store_ram=0,
								  conn_type type=COMM_UDP,char* comStr="COM3",INT32U baudrate=9600,INT16U dstAddr=0x0101);

//****************************************************************************************************************
//**** 函数名:czTubeCtrlEx
//**** 功  能:计分牌控制(支持以太网,串口)
//**** 参  数:
//****        ctrl_cmd        - 控制命令
//****        ctrl            - 控制信息
//****        msg_size        - 信息大小
//****        sign_ip         - 显示屏IP地址
//****        sign_port       - 显示屏端口
//****        type			  - 通讯方式
//****        comStr		  - 串口标识符
//****        baudrate        - 波特率
//****        dstAddr         - GGUU地址
//**** 返回值:
//****        0               - 成功
//****        other           - 失败
//****************************************************************************************************************
CZAPI_DECLARE(INT32U) czTubeCtrlEx(INT8U ctrl_cmd, INT8U* ctrl, INT32U msg_size, char* sign_ip,INT32U sign_port,
								   conn_type type=COMM_UDP,char* comStr="COM3",INT32U baudrate=9600,INT16U dstAddr=0x0101);

//****************************************************************************************************************
//**** 函数名:czEasyWriteFileEx
//**** 功  能:写文件到屏中指定路径,如果发送F盘成功,就把内容存放到F盘,否则就存放到D盘(支持以太网,串口)
//**** 参  数:
//****        pc_file_path    - pc上的文件路径
//****        sign_file_path  - 屏体中的文件路径
//****        sign_ip         - 显示屏IP地址
//****        sign_port       - 显示屏端口
//****        type			  - 通讯方式
//****        comStr		  - 串口标识符
//****        baudrate        - 波特率
//****        dstAddr         - GGUU地址
//**** 返回值:
//****        0               - 成功
//****        other           - 失败
//****************************************************************************************************************
CZAPI_DECLARE(INT32U) czEasyWriteFileEx(char* pc_file_path, char* sign_file_path,char* sign_ip,INT32U sign_port,
										conn_type type=COMM_UDP,char* comStr="COM3",INT32U baudrate=9600,INT16U dstAddr=0x0101);

//****************************************************************************************************************
//**** 函数名:czEasyReadFileEx
//**** 功  能:从屏中指定路径读取文件(支持以太网,串口)
//**** 参  数:
//****        pc_file_path    - pc上的文件路径
//****        sign_file_path  - 屏体中的文件路径
//****        sign_ip         - 显示屏IP地址
//****        sign_port       - 显示屏端口
//****        type			  - 通讯方式
//****        comStr		  - 串口标识符
//****        baudrate        - 波特率
//****        dstAddr         - GGUU地址
//**** 返回值:
//****        0               - 成功
//****        other           - 失败
//****************************************************************************************************************
CZAPI_DECLARE(INT32U) czEasyReadFileEx(char* pc_file_path, char* sign_file_path,char* sign_ip,INT32U sign_port,
										conn_type type=COMM_UDP,char* comStr="COM3",INT32U baudrate=9600,INT16U dstAddr=0x0101);

//****************************************************************************************************************
//**** 函数名:czShowFilesSpe
//**** 功  能:控制显示屏显示一组文件，文件类型可以是bmp,pmg,nmg,qst,flw格式,
//*****       如果发送F盘成功,就把内容存放到F盘,否则就存放到D盘(支持以太网,串口)
//*****       将发文件和发播放列表区分开，用于同时显示相同内容在不同屏上
//**** 参  数:
//****        files           - 文件在本机PC的路径，2维数组结构
//****        numfiles        - 文件个数,即1维的长度
//****        mode            - 花样,参考mode define,只对bmp有效(实际是修改屏的默认配置)
//****        stay_time_sec   - 停留时间,0-9999 sec,只对bmp有效，
//****        sign_ip         - 显示屏IP地址
//****        sign_port       - 显示屏端口
//****        is_store_ram    - 是否保存了RAM中,1=表示保存在RAM中，0表示保存在F盘或D盘
//****        type			  - 通讯方式
//****        comStr		  - 串口标识符
//****        baudrate        - 波特率
//****        dstAddr         - GGUU地址
//****        sendType        - 发送方式  0：发送文件+播放列表
//****        							  1：仅发送文件
//****									  2: 仅发送播放列表
//**** 返回值:
//****        0               - 成功
//****        other           - 失败
//****************************************************************************************************************
CZAPI_DECLARE(INT32U) czShowFilesSpe(char* files[], INT32U numfiles, INT32U mode, INT32U stay_time_sec,
									char* sign_ip,INT32U sign_port,INT32U is_store_ram=0,
									conn_type type=COMM_UDP,char* comStr="COM3",INT32U baudrate=9600,
									INT16U dstAddr=0x0101,INT8U sendType=0);

//****************************************************************************************************************
//**** 函数名:czShowFilesII
//**** 功  能:控制显示屏显示一组文件，文件类型可以是bmp,pmg,nmg,qst,flw格式,
//*****       如果发送F盘成功,就把内容存放到F盘,否则就存放到D盘(支持以太网,串口)
//*****       每个图片对应不同的停留时间，使用第六种播放列表
//**** 参  数:
//****        files           - 文件在本机PC的路径，2维数组结构
//****        numfiles        - 文件个数,即1维的长度
//****        mode            - 花样,参考mode define,只对bmp有效(实际是修改屏的默认配置)
//****        stay_time_sec   - 停留时间,0-9999 sec,只对bmp有效，
//****        sign_ip         - 显示屏IP地址
//****        sign_port       - 显示屏端口
//****        is_store_ram    - 是否保存了RAM中,1=表示保存在RAM中，0表示保存在F盘或D盘
//****        type			  - 通讯方式
//****        comStr		  - 串口标识符
//****        baudrate        - 波特率
//****        dstAddr         - GGUU地址
//****        sendType        - 发送方式  0：发送文件+播放列表
//****        							  1：仅发送文件
//****									  2: 仅发送播放列表
//**** 返回值:
//****        0               - 成功
//****        other           - 失败
//****************************************************************************************************************
CZAPI_DECLARE(INT32U) czShowFilesII(char* files[], INT32U numfiles, INT8U stay_time_sec[], INT32U mode, 
									char* sign_ip,INT32U sign_port,INT32U is_store_ram=0,
									conn_type type=COMM_UDP,char* comStr="COM3",INT32U baudrate=9600,
									INT16U dstAddr=0x0101,INT8U sendType=0);
#ifdef __cplusplus
}
#endif
#endif