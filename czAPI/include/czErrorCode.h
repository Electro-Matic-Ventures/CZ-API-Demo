//****************************************************************************************************************
//****                                      CZ Error Code And Meaing
//****                              NTCIP 1203v02-35a/1201v0303b/JetFileII
//****                                       Developer:YangLei
//****                                          Version:1.0
//****                                 Lasted Modify Date:2010-09-23
//****************************************************************************************************************

//================================================================================================================
//==== 注意：修改本文件时，一定要与czError.cpp中的函数一起修改！！！
//================================================================================================================

//================================================================================================================
//==== chainzone API error code define
//================================================================================================================
#ifndef __CZERROR_CODE_H__
#define __CZERROR_CODE_H__

#ifdef __cplusplus
extern "C" {
#endif

//================================================================================================================
//==== DLL普通错误
//================================================================================================================
#define CZ_ERROR_OK						0x0						//成功
#define CZ_ERROR_SNMP_ERROR				0x1						//SNMP读写失败
#define CZ_ERROR_ARG					0x2						//调用函数的参数非法
#define CZ_ERROR_INTERFACE				0x3						//获取czinface错误，可能是没有调用init函数
#define CZ_ERROR_CMDTimeout				0x4						//调用函数的超时

#define CZ_ERROR_DLL_CALL				0x0100					//调用DLL时失败
#define CZ_ERROR_MEM_ERR				0x0101					//内在分配失败
#define CZ_ERROR_FILE_FORMAT_ERR		0x0102					//文件格式错误
#define CZ_ERROR_CANT_MODIFY_ERR		0x0103					//请求修改，但读取的结果不在修改状态下,NTCIP使用
#define CZ_ERROR_TASK_NOT_EXIST			0x0104					//任务不存在
#define CZ_ERROR_NO_THIS_FUNC			0x0105					//DLL没有该功能,或显示屏不支持该功能
#define CZ_ERROR_TASK_INIT_ERROR		0x0106					//任务初始在数据库中的错误，如果查询到该错误表示
                                                                //Server处理该错误时出现异常
#define CZ_ERROR_SIGN_NOT_CONNECT		0x0107					//在获取屏的动态ＩＰ时，屏不为GPRS方式或没有连上

#define CZ_ERROR_DB_OPEN				0x0200					//数据库打开失败
#define CZ_ERROR_DB_EXEC				0x0201					//执行数据库命令失败
#define CZ_ERROR_DB_EXCEPTION			0x0202					//数据库异常

//================================================================================================================
//==== JetFileII Error List
//================================================================================================================
#define CZ_PACKET_PROC_OK_CMD   		0x4B4F					//正确处理完一个命令的回送码
#define CZ_PACKET_PROC_ER_CMD   		0x5245					//不正确回送码

#define CZ_PACKET_PROC_OK      			0x9000					//正确处理完一个命令的回送码
#define CZ_SYN_ERR 		    			0x9001   				//通信同步头错误
#define CZ_CHKSUM_ERR          	     	0x9002   				//和校验错误
#define CZ_ADDRESS_ERR         	     	0x9003   				//地址错误

#define CZ_MAIN_CMD_ERR        	     	0x9004   				//大类命令非法
#define CZ_SUB_CMD_ERR         	     	0x9005   				//小类命令非法
#define CZ_DATALEN_ERR         	     	0x9006   				//包长度不对
#define CZ_FILE_NOTEXT_ERR     	     	0x9008   				//文件不存在
#define CZ_FILE_EOF_ERR					0x9009   				//文件已到文件尾,在读文件时,包序号过大
#define CZ_FILE_OPEN_FILED_ERR          0x9010   				//打开文件失败
#define CZ_SUB_CMD_SUSTAIN_ERR          0x9011   				//小类命令在这系统中不支持
#define CZ_FILE_WRITE_FILED_ERR         0x9012   				//文件写入失败
#define CZ_FILE_WRITE_PS_DS_ERR         0x9013   				//文件写入时,包大小大小1500或数据大小多于分包大小
#define CZ_FILE_WRITE_NOSEAIL_ERR       0x9014   				//文件写入时,没有按顺序发送
#define CZ_FILE_CUR_OPEN_ERR            0x9015   				//文件删除时,这个文件正在打开

#define CZ_LOGIN_FIRST_ERR              0x9030   				//请先登录,设置了密码管理,没有登录而进行的操作时返回
#define CZ_LOGIN_PASSWORD_ERR           0x9031   				//密码不对
#define CZ_LOGIN_USERNAME_ERR           0x9032   				//用户名不对
#define CZ_LOGIN_OLD_PASSWORD_ERR       0x9033   				//旧密码不对
#define CZ_LOGIN_PASSWORD_CHG_ERR       0x9000   				//密码更改成功
#define CZ_LOGIN_OTHER_SIDE_ERR         0x9035   				//在别处已经登录了!
#define CZ_LOGIN_USER_RIGHT_ERR         0x9036   				//用户非法,或没有权限
#define CZ_LOGIN_OK                     0x9000   				//登录成功
#define CZ_LOGIN_OUT_OK                 0x9000   				//注销成功

 
#define CZ_ABSOLUTE_READ_TOO_BIG_ERR    0x1101   				//绝对地址读时,要读取的数量太大
#define CZ_ABSOLUTE_READ_DISK_ERR       0x1102   				//绝对地址读写时,硬盘读写错误,可能是读取地址不正确.
#define CZ_CPU_UPDATE_FAILD             0x1F01   				//CPU升级不成功
#define CZ_CPU_UPDATE_ING               0x1F02   				//正在进行升级操作
#define CZ_CPU_UPDATE_NONE              0x1F03   				//没有进行升级操作
#define CZ_CPU_UPDATE_SUCESS            0x9000   				//CPU升级成功

#define CZ_WRITE_TOO_BIG_ERR            0x2101   				//写文件时,写入的数据量大小320K
#define CZ_WRITE_DIRVE_FULL_ERR        	0x2102   				//写文件时,磁盘空间不足
#define CZ_WRITE_C_DIRVE_FULL_ERR       0x2103   				//写文件时,C盘空间不足
#define CZ_WRITE_D_DIRVE_FULL_ERR       0x2104   				//写文件时,D盘空间不足
#define CZ_WRITE_E_DIRVE_FULL_ERR       0x2105   				//写文件时,E盘空间不足
#define CZ_WRITE_F_DIRVE_FULL_ERR       0x2106   				//写文件时,F盘空间不足
#define CZ_WRITE_G_DIRVE_FULL_ERR       0x2107   				//写文件时,G盘空间不足
#define CZ_WRITE_MEM_LACK_ERR           0x2000   				//写入文件时,管理内存块申请失败
#define CZ_WRITE_MSG_TOO_BIG_ERR        0x2901   				//写最急消息时,不能大小1024个字节

#define CZ_TEST_SHADE_NO_SURPORT        0x3A01   				//系统不支持灰度测试

#define CZ_INVAILD_LICENSE				0x6601  				//无效license

#define CZ_FILE_CTRL_NO_DISPLAY_ERR     0x6701   				//当前没有显示文件
#define CZ_FILE_CTRL_CUR_DIS_OP_ERR     0x6702   				//当前显示文件打开失败
#define CZ_FILE_CTRL_USE_EXT_ERR        0x6703   				//当前显示文件太大,请用扩展读取命令


#define CZ_FILE_CTRL_FORMAT_ERR         0x7201   				//格式化失败,可能原因是指定盘不存在
#define CZ_FILE_CTRL_CRT_DIR_ERR        0x7301   				//文件夹创建失败
#define CZ_FILE_CTRL_RENAME_ERR         0x7401   				//文件改名失败
#define CZ_FILE_CTRL_PATH_FORMAT_ERR    0x7402   				//改名时,路径格式不对
#define CZ_FILE_CTRL_MOVE_ERR           0x7501   				//移动文件失败
#define CZ_FILE_CTRL_DELETE_ERR         0x7601   				//删除文件失败
#define CZ_FILE_CTRL_OPEN_DIR_ERR       0x7B01   				//打开文件夹失败
#define CZ_FILE_CTRL_DRIVEINFO_ERR      0x7D01   				//读取磁盘信息失败(磁盘不存在,磁盘名称不对)
#define CZ_FILE_CTRL_FILE_NO_EXITS      0x7E01   				//指定的文件不存在

#define CZ_TIME_SET_ERR                 0x5201   				//时间设置不成功

//==== 0x36E1- 0x36EF多区域错误码
#define CZ_PAGE_ID_ILLEGAL              0x36E1					//PageID无效(可能是PageID超出实际页数,或者PageID为0);
#define CZ_PAGE_NOT_DEF                 0x36E2					//PageID有效,但该页还未被配置;
#define CZ_PAGE_NUM_ILLEGAL             0x36E3					//设置页总数失败,超出最大值,当前最多12页;


#define CZ_ZONE_ID_ILLEGAL              0x36E4					//ZoneID无效(可能是ZoneID超出该页实际区域数,或者ZoneID为0);
#define CZ_ZONE_NOT_DEF                 0x36E5					//ZoneID有效.但该区域还未被配置;
#define CZ_ZONE_NUM_ILLEGAL             0x36E6					//ZoneCount无效(命令中的总区域数与实际总区域数不匹配,或者超出最大值,当前最多20);
//================================================================================================================
//==== 0x5000 - 0x5100PC软件用了
//================================================================================================================
#define CZ_UserErrCode					0x5000					//用户错误
#define CZ_OpenCommErrCode				0x5001					//打开Com错误
#define CZ_ConnectTimeOutCode			0x5002					//连接超时
#define CZ_OperationFailCode			0x5003					//操作失败
#define CZ_RtnHeaderErrCode				0x5004					//头错误
#define CZ_RtnSurAddrErrCode			0x5005					//源地址错误
#define CZ_RtnDesAddrErrCode			0x5006					//目的地址错误
#define CZ_RtnPackIDErrCode				0x5007					//包序号错误
#define CZ_RtnMainCMDErrCode			0x5008					//主命令错误
#define CZ_RtnSubCMDErrCode				0x5009					//子命令错误
#define CZ_RtnCheckSumErrCode			0x5010					//和校验错误
#define CZ_RtnOperationAbort			0x5011					//操作放弃
#define CZ_RtnNoPlayListCode			0x5012					//没有播放列表
#define CZ_RtnInvalidFileFormat			0x5013
#define CZ_CommunicationError			0x5100					//通信错误
#define CZ_OpenPCFileError				0x5101					//打开ＰＣ文件失败
#define CZ_PCFileEmptyError				0x5102					//文件为空

#define CZ_LINK_PLAY_STAT1              0x8301   				//OLD_BUF	CUR_BUF在播放,DISPLAY_BUF可以接收
#define CZ_LINK_PLAY_STAT2              0x8302   				//CUR_BUF	DISPLAY_BUF在播放,OLD_BUF可以接收
#define CZ_LINK_PLAY_STAT3              0x8303   				//DISPLAY_BUF	OLD_BUF在播放,CUR_BUF可以接收

#define CZ_NOT_IN_LINK_STAT             0x8305   				//系统不在无限连接播放状态
#define CZ_LINK_PLAY_DATA_OVER          0x8306   				//发进去的数据超出范围,接收的缓冲区超出
#define CZ_LINK_PLAY_FORMAT_ERR         0x8307   				//发送的数据格式不对,屏处于8:8:8:n数据为1:1格式时出现

#define CZ_LOGIN_SERIAL_ERR             0xAA01   				//给出生成密码包的序列号不合法
#define CZ_LOGIN_GETPASSWOR_ERR         0xAA02   				//读密码包在开机前10秒可以读取,其它时间读取返回的错误

#define CZ_FTP_OPRC_ERR           	  	0xB101   				//操作FTP失败
#define CZ_HTTP_OPRC_ERR       		  	0xB102   				//操作HTTP失败

#define CZ_VMSSYN_ERROR        	   		0xC320   				//vms文件与数据同步失败
#define CZ_USERPWD_ERROR        	   	0xC330   				//用户名不存在或密码错误
#define CZ_ADDTASK_ERR                  0xC340   				//添加任务时失败,可能是任务列表太多或signID不存在

#define CZ_GET_FILE_LOCK_FIRST          0xC103   				//写文件前,需要先加锁操作
#define CZ_FILE_LOCK_BY_OTHER           0xC102   				//写文件时,该文件被别人加锁了


//================================================================================================================
//==== 控制板操作错误错误码
//================================================================================================================
#define CZ_5002_TASK_IN_BUF				0x0C00					//请求的命令尚在缓冲中
#define CZ_5002_TASK_SUCCESS			0x0C01					//任务成功
#define CZ_5002_TASK_QUEUE_ERR			0x0C02					//队列号错误
#define CZ_5002_TASK_PROCESSING			0x0C03					//正在处理中
#define CZ_5002_TASK_BUS_ERR			0x0C04					//端点总线故障
#define CZ_5002_TASK_RETRY_ERR			0x0C05					//重试次数大于设定次数
#define CZ_5002_TASK_NORMAL_ERR			0x0C06					//一般错误
#define CZ_5002_TASK_ID_ERR				0x0C07					//命令ID错误
#define CZ_5002_TASK_BROCAST_ERR		0x0C08					//广播写数据部分不成功
#define CZ_5002_TASK_LDUCTRL			0x0C09					//LDU控制
#define CZ_5002_TASK_LDUCTRLAddrFail	0x0C11					//LDU控制地址失败
#define CZ_TWICPYDataErr				0x0c12					//TWI数据错误
#define CZ_PixelProErr					0x0c13					//像点检测错误
#define CZ_5002_TASK_QUEUE_FULL			0xFFFF					//返回队列满的错误信息

#ifdef __cplusplus
}
#endif
#endif
