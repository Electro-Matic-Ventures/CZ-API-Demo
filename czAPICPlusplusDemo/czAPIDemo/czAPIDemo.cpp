#include "stdafx.h"
#include <stdio.h>
#include <malloc.h>
#include <winsync.h>
#include <iostream>
#include "process.h"

#include "czJetFileII.h"
#include "czEasyAPI.h"

#include "czEncodingConvert.h"

//================================================================================================================
//==== import lib
//================================================================================================================
#pragma comment(lib,"czAPI\\bin-win\\x86Debug\\czJetFileII.lib") 
#pragma comment(lib,"czAPI\\bin-win\\x86Debug\\czEncodingConvert.lib") 

using namespace std;

#define TEST_SIGN_IP  "169.254.18.183"
#define TEST_SIGN_COM "COM13"
#define TEST_SIGN_COM_BAUDRATE 19200
#define TEST_SIGN_COM_GGUU 0x0101
#define TEST_IPCOUNT 2
#define MAXZONECOUNT 9
#define PARKSLEEPTIME 3000
#define czAPIDemoVersion "1.77.8_Win 2019-01-16"
//****************************************************************************************************************
//**** NAME  :get_file_size
//**** FUNCT :get size of the file
//**** ARGS  :
//****        fp                   - pointer of the file
//**** RETURN:
//****        size of the file
//**************************************************************************************************************** 
long get_file_size(FILE *fp)
{
	if(!fp) return 0;

	long size(0);
	long   curpos = ftell(fp);
	fseek(fp, 0, SEEK_END);
	size = ftell(fp);
	fseek(fp, curpos, SEEK_SET);
	return size;
}


void ShowMultiLineDemo()
{
	INT32U RT;
	char  msgStr[50];
	memset(msgStr, 0, sizeof(msgStr));
	string strArr[4];
	int nPos=0;

	//Set text property
	msgStr[0] = 0x1E;			//text alignment tags
	msgStr[1] = 0x32;			//alignment value, align center:0x30; align left:0x31; align right:0x32;
	msgStr[2] = 0x08;			//line space tags
	msgStr[3] = 0x33;			//line space value, rangge: 0x30--0x39
	nPos = 4;

	strArr[0] = "Line1";		//Red
	strArr[1] = "Line2";		//Green
	strArr[2] = "Line3";		//Blue
	strArr[3] = "Line4";		//Yellow
	for (int i=0;i<4;i++)
	{
		msgStr[nPos++] = 0x1C;	//color tags	
		msgStr[nPos++] = '/';	//custom color tags
		switch(i)
		{
		case 0:
			msgStr[nPos++] = 0x00;		//B
			msgStr[nPos++] = 0x00;		//G
			msgStr[nPos++] = 0xFF;		//R
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
		
		memcpy(&msgStr[nPos], strArr[i].c_str(), strArr[i].length());
		nPos += strArr[i].length(); 
		msgStr[nPos++] = 0x0D;		//new line
	}
	RT = czShowMsg(msgStr, 50, CZ_FONT_EN_14x8, CZ_COLOR_AMBER , CZ_MODE_STATIC, 3, TEST_SIGN_IP, 9520,0);
}

//****************************************************************************************************************
//**** NAME  :pre_comm
//**** FUNCT :call back
//**** ARGS  :
//****        If     					- _czinterface
//**** RETURN:
//****        none
//**************************************************************************************************************** 
void pre_comm(_czinterface* If)
{
	return;
}

//****************************************************************************************************************
//**** NAME  :post_comm
//**** FUNCT :call back
//**** ARGS  :
//****        If     					- _czinterface
//**** RETURN:
//****        none
//**************************************************************************************************************** 
void post_comm(_czinterface* If)
{
	return;
}

//****************************************************************************************************************
//**** NAME  :update_status
//**** FUNCT :call back
//**** ARGS  :
//****        If     					- _czinterface
//****        code     					- code　
//****        precent  					- precent，0-95
//**** RETURN:
//****        none
//**************************************************************************************************************** 
void update_status(_czinterface* If,INT32U code,INT32U precent)
{
	return;
}


//****************************************************************************************************************
//**** NAME  :read
//**** FUNCT :call back
//**** ARGS  :
//****        If     					- interface
//****        buf     					- buffer
//****        size  					- read size
//****        timeoutms                 - timeout ms
//**** RETURN:
//****        size of read
//**************************************************************************************************************** 
INT32U read (void *czif,INT8U *buf, INT32U size, INT32U timeoutms)
{	
	return 0;
}

//****************************************************************************************************************
//**** NAME  :write
//**** FUNCT :call back
//**** ARGS  :
//****        If     					- interface
//****        buf     					- buffer
//****        size  					- write size
//**** RETURN:
//****        size of write
//**************************************************************************************************************** 
INT32U write(void* czif,INT8U *buf, INT32U size)
{
	return 0;
}


//****************************************************************************************************************
//**** NAME  :log
//**** FUNCT :call back
//**** ARGS  :
//****        If     					- _czinterface
//****        file     					- file name
//****        line  					- line number
//****        level  					- level
//****        fmt    					- format.
//**** RETURN:
//****        none
//**************************************************************************************************************** 
void  log(_czinterface* If,const char *file, int line, int level,const char *fmt, ...)
{
	return;
}


//****************************************************************************************************************
//**** NAME  :InitIFStruct
//**** FUNCT :init interface struct
//**** ARGS  :
//****        If     					- _czinterface
//**** RETURN:
//****        none
//**************************************************************************************************************** 
static void InitIFStruct(_czinterface &If)
{
	memset(&If, 0 , sizeof(If));

	If.type  = COMM_UDP;
	If.read  = NULL;
	If.write = NULL;	
	If.Timeoutms = 3000;

	memcpy((char*)If.ip, TEST_SIGN_IP, 14);
	memcpy((char*)If.com, "COM3", 4);

	If.port        = 9520;
	If.baudrate    = TEST_SIGN_COM_BAUDRATE;
	If.signPointer = NULL;
	If.SrcAddr     = 0;
	If.DstAddr     = TEST_SIGN_COM_GGUU;
	If.taskPointer = NULL;
	If.Retry       = 3;

	If.pre_comm       = pre_comm;
	If.post_comm      = post_comm;
	If.update_status  = update_status;
	If.log            = log;
	If.curShowFilter  = NULL;

	If.totalSteps     = 1;								
	If.curSteps       = 1;
	If.packetSize     = 768;
}

void ReadImposaTileStatusDemo()
{
	INT32U rtCode;
	INT8U  result[1024];
	INT16U resultCode;

	czImposaGetTileStat(0, &rtCode);
	Sleep(500);
	czImposaGetResult(rtCode, result, 1024, &resultCode);
}

void PixCheckDemo()
{
	INT32U nResult,rValue,retryTime(60);
	INT8U Progress(0);
	//============================================================================================================
	//==== 第1步:触发检测
	//============================================================================================================
	rValue = czBeginPixCheck();
	if(rValue)  return ;

	//============================================================================================================
	//==== 第2步:查进度
	//============================================================================================================
	rValue = czPixProgress(&Progress);
	while(retryTime && rValue == 0)
	{
		rValue = czPixProgress(&Progress);
		if(Progress > 99) break;

		czSleep(1000);
	}

	//============================================================================================================
	//==== 第3步:读取文件
	//============================================================================================================
	if(rValue == 0)
	{
		czReadPixResult((INT8U*)".\\pxl1.csv");
		czReadSignalResult((INT8U*)".\\signal1.csv");
	}
}

void SetDefaultScreentParameter()
{
	INT32U nResult;
	INT8U  iniPath[MAX_PATH], tmp[8];
	WCHAR path[MAX_PATH], tmpW[8];
	INT16U showDefaultBmpTime, blackScreenTime;
	memset(path, 0, sizeof(path));
	memset(iniPath, 0, sizeof(iniPath));
	memset(tmp, 0, sizeof(tmp));
	memcpy(iniPath, ".\\TE18_233.cfg", 32);
	MultiByteToWideChar(CP_ACP, 0, (char*)iniPath, strlen((char*)iniPath) + 1, path, sizeof(path) / sizeof(path[0]));
	nResult = czReadSpecPathFile((INT8U*)"c:\\config\\TE18_233.cfg", (INT8U*)iniPath);

	//get the current value
	showDefaultBmpTime = GetPrivateProfileInt(_T("DefaultSet"), _T("ShowDefultBmpTime"), 0, path);
	blackScreenTime = GetPrivateProfileInt(_T("DefaultSet"), _T("BlackScreenTime"), 0, path);

	//modify the value as you need
	showDefaultBmpTime = 1000;
	blackScreenTime = 2000;

	czPrintBuf((char*)tmp, 8, "%d", showDefaultBmpTime);
	MultiByteToWideChar(CP_ACP, 0, (char*)tmp, strlen((char*)tmp) + 1, tmpW, sizeof(tmpW) / sizeof(tmpW[0]));
	WritePrivateProfileString(_T("DefaultSet"), _T("ShowDefultBmpTime"), tmpW, path);

	czPrintBuf((char*)tmp, 8, "%d", blackScreenTime);
	MultiByteToWideChar(CP_ACP, 0, (char*)tmp, strlen((char*)tmp) + 1, tmpW, sizeof(tmpW) / sizeof(tmpW[0]));
	WritePrivateProfileString(_T("DefaultSet"), _T("BlackScreenTime"), tmpW, path);

	nResult = czWriteSpecFile((INT8U*)"c:\\config\\TE18_233.cfg", (INT8U*)iniPath);
}

void ControlPlaylistDemo()
{
	INT32U nResult;
	INT8U curPLIndex=0;
	//========================================================================================================
	//===== Playlist control
	//========================================================================================================	

	//according to the "DEMO1.LST" template file generates the required files, The file is in XML format
	nResult = czPLInit((INT8U*)".\\", (INT8U*)"DEMO.LST");

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

void PredefinedPlaylistDemo()
{
	INT32U nResult;
	INT8U curPLIndex=0;
	//========================================================================================================
	//===== Playlist control
	//========================================================================================================	
	//according to the "DEMO1.LST" template file generates the required files, The file is in XML format
	czPLInit((INT8U*)".\\", (INT8U*)"DEMO1.LST");
	
	//Send playlist1
	nResult = czPLSpeSendToLED(1,1);

	//Load playlist2
	nResult = czLoadSYSFromXML("DEMO2.LST");

	//Send Playlist2
	nResult = czPLSpeSendToLED(2,1);
	
	//Play playlist1
	nResult = czPlaySpePlaylist(1);

	//Get current playlist Index
	nResult = czReadSpePlayListIndex(&curPLIndex);

	//Play playlist2
	nResult = czPlaySpePlaylist(2);

	//Get current playlist Index
	nResult = czReadSpePlayListIndex(&curPLIndex);

	//Delete playlist1
	//nResult = czPLDeleteByIndex(1);

}

//****************************************************************************************************************
//**** NAME  :EasyAPIDemo
//**** FUNCT :demo for easy api call
//**** ARGS  :
//****        none                 - none
//**** RETURN:
//****        none
//**************************************************************************************************************** 
void EasyAPIDemo()
{
	FILE *fp;
	INT32U RT;
	_czinterface If;
	DEFAULT_SET defaultset;
	INT8U stayTimes[3]={1,3,8};

	//============================================================================================================
	//===== show playlist(many files) with no schedule
	//============================================================================================================
	DWORD dStart = GetTickCount();
	
	char *file[3] = 
	{
		{".\\1.bmp"},
		{".\\2.bmp"},
		{".\\3.bmp"}
	};																			

	RT = czShowFiles((char**)file, 3, 48, 2,TEST_SIGN_IP, 9520);
	//support serial port
	RT = czShowFilesEx((char**)file, 3, CZ_MODE_MOVEUP, 2,TEST_SIGN_IP, 9520, 0,COMM_UDP,TEST_SIGN_COM,TEST_SIGN_COM_BAUDRATE,TEST_SIGN_COM_GGUU);
	//support individual stayTime for each file
	RT = czShowFilesII((char**)file, 3,(INT8U*)stayTimes, CZ_MODE_MOVEUP,"169.254.10.149", 9520,0);
	
	//============================================================================================================
	//===== show playlist(many files) with no schedule- cvt to nmg
	//============================================================================================================
	char *nmgfile[3] = 
	{
		{".\\1.nmg"},
		{".\\2.nmg"},
		{".\\3.nmg"}
	};
	//czShowBmpToNmg(file[0],nmgfile[0],0, 3);
	//czShowBmpToNmg(file[1],nmgfile[1],0, 3);
	//czShowMsgToNmg("Demo show",9,nmgfile[2],CZ_FONT_EN_14x8, CZ_COLOR_AMBER , CZ_MODE_STATIC,6);	
	//RT = czShowFiles((char**)nmgfile, 3, CZ_MODE_MOVEDOWN, 2,TEST_SIGN_IP, 9520);
	RT = czShowFilesEx((char**)nmgfile, 3, CZ_MODE_MOVEDOWN, 2,TEST_SIGN_IP, 9520, 0,COMM_UDP,TEST_SIGN_COM,TEST_SIGN_COM_BAUDRATE,TEST_SIGN_COM_GGUU);
	
	DWORD slip = GetTickCount() - dStart;

	cout << "show 3 files on the sign" << endl;
	printf(" total time:%d ms\r\n",slip);
	system("pause");
	
	//============================================================================================================
	//===== show bmp on the sign, rand mode, stay 3 sec.
	//============================================================================================================
	fp = fopen(".\\demo.bmp", "rb");
	if(fp)
	{
		long size = get_file_size(fp);
		char *buf = (char*)malloc(size);
		if(buf)
		{
			fread(buf, 1, size, fp);			
			//czShowPic(buf, size, CZ_MODE_RAND,3, TEST_SIGN_IP, 9520);
			RT = czShowPicEx(buf, size, CZ_MODE_RAND,3, TEST_SIGN_IP, 9520,0, COMM_UDP,TEST_SIGN_COM,TEST_SIGN_COM_BAUDRATE,TEST_SIGN_COM_GGUU);
		}
		free(buf);
		fclose(fp);
	}
	cout << "show demo picture on the sign" << endl;
	system("pause");
	
	//============================================================================================================
	//===== show messgae "show demo msg" on the sign, static mode, stay 0 sec.
	//============================================================================================================
	//czShowMsg("show demo msg", 13, CZ_FONT_EN_14x8, CZ_COLOR_AMBER , CZ_MODE_STATIC, 0, TEST_SIGN_IP, 9520,1);
	RT = czShowMsgEx("show demo msg", 13, CZ_FONT_EN_14x8, CZ_COLOR_AMBER , 0x33, 0, TEST_SIGN_IP, 9520,1,1, COMM_UDP,TEST_SIGN_COM,TEST_SIGN_COM_BAUDRATE,TEST_SIGN_COM_GGUU);
	cout << "show 'show demo msg' on the sign" << endl;
	system("pause");

	//============================================================================================================
	//===== show messgae "show demo msg" on the sign, modify text alignment.
	//============================================================================================================
	InitIFStruct(If);
	czInitAPI(&If);
	RT = czReadDefDisplayStyle(&defaultset);
	defaultset.Dhor_just = 0;			//0:Center		1:Left		2:Right
	defaultset.Dspeed = 0;
	RT = czWriteDefDisplayStyle(&defaultset);	
	RT = czWriteDefDisplayStyle(&defaultset);
	RT = czWriteDefDisplayStyle(&defaultset);

	//============================================================================================================
	//===== show messgae "测试Demo" on the sign, static mode, stay 0 sec.
	//============================================================================================================
	czShowMsg("测试Demo", 8, CZ_FONT_CH_ST_16x16, CZ_COLOR_AMBER , CZ_MODE_STATIC, 0, TEST_SIGN_IP, 9520);

	cout << "show '测试Demo' on the sign" << endl;
	system("pause");

	//============================================================================================================
	//===== show messgae "test it via easy api" on the sign with self-define color,, rand mode, stay 0 sec.
	//============================================================================================================
	INT32U COLOR;
	COLOR = (0 << 24) | (255 << 16) |(0 << 8) | '/';			//R-G-B-/
	czShowMsg("test it via easy api", 20, CZ_FONT_EN_14x8, COLOR , CZ_MODE_STATIC, 0, TEST_SIGN_IP, 9520);

	cout << "show 'test it via easy api' on the sign" << endl;
	system("pause");

	//============================================================================================================
	//===== show mulit line message example
	//============================================================================================================
	ShowMultiLineDemo();

	//============================================================================================================
	//===== czErrString.dll example
	//============================================================================================================
	char *errDesc;
	errDesc = czErrorDesc(0);

	cout << "show code 0 message:" << endl;
	cout << errDesc << endl;
	system("pause");

	errDesc = czErrorDesc(20736);

	cout << "show code 20736 message:" << endl;
	cout << errDesc << endl;
	system("pause");

	//============================================================================================================
	//===== czEncodingConvert  Demo
	//============================================================================================================
	UINT32 code = 0;
	wstring gb2312Str;
	wchar_t* srcstr = _T("欢迎");
	//In order to output Unicode string     setlocale(LC_ALL, "xxxxx"); xxxxx:zh_CN.UTF-8 etc..
	setlocale(LC_ALL, "");
	for (int idx = 0; idx < lstrlenW(srcstr); ++idx)
	{
		code = code_unicode_to_gb2312(srcstr[idx]);
		gb2312Str.append(1, code);
		printf("GB2312 code:0x%x\n", code);
	}

	for (int idx = 0; idx < gb2312Str.length(); ++idx)
	{
		code = code_gb2312_to_unicode(gb2312Str[idx]);
		printf("Unicode code:0x%x\n", code);
		wprintf(_T("Unicode char:%c\n"), code);
	}
	//C++ 11
	//for (wchar_t ch : _T("欢迎"))
	//{
	//	code = code_unicode_to_gb2312(ch);
	//	gb2312Str.append(1, code);
	//	printf("GB2312 code:0x%x\n", code);		
	//}
	//for (wchar_t ch : gb2312Str)
	//{
	//	code = code_gb2312_to_unicode(ch);
	//	printf("Unicode code:0x%x\n", code);
	//	wprintf(_T("Unicode char:%c\n"), code);
	//}
}

//****************************************************************************************************************
//**** NAME  :APIDemoAdvenced
//**** FUNCT :demo for cz api call
//**** ARGS  :
//****        none                 - none
//**** RETURN:
//****        none
//**************************************************************************************************************** 
void APIDemoAdvenced()
{
	
	FILE *fp;
	DWORD dStart = GetTickCount();
	_czinterface If;
	INT32U nResult;

	//============================================================================================================
	//===== 
	//============================================================================================================
	try
	{
		//========================================================================================================
		//===== init interface struct
		//========================================================================================================		
		InitIFStruct(If);

		//========================================================================================================
		//===== Call API Init
		//========================================================================================================	
		czInitAPI(&If);

		//========================================================================================================
		//===== write PC ".\\1.bmp" to sign "D:\P\1.bmp"
		//========================================================================================================	
		INT8U  path[MAX_PATH];
		memset(path, 0, sizeof(path));
		memcpy(path, ".\\1.bmp", 8);
		nResult = czWriteSpecFile((INT8U*)("D:\\P\\1.bmp"), path);
		if(nResult == 0)
		{
			cout << "Write D:\\P\\1.bmp successfully" << endl;
		}
		system("pause");
		//========================================================================================================
		//===== read D:\P\1.bmp file to PC .\\1_1.bmp
		//========================================================================================================	
		memcpy(path, ".\\1_1.bmp", 10);
		nResult = czReadSpecPathFile((INT8U*)("D:\\P\\1.bmp"), path);
		if(nResult == 0)
		{
			cout << "Read D:\\P\\1.bmp successfully" << endl;
		}

		//========================================================================================================
		//===== read tile status
		//========================================================================================================	
		ReadImposaTileStatusDemo();

		nResult = czBrightAdjust(80);

		//========================================================================================================
		//===== Pix check : easy way 
		//========================================================================================================	
		nResult = czPxlChk((INT8U*)".\\pxl.csv", (INT8U*)".\\signal.csv");

		//========================================================================================================
		//===== Pix check : ProgressInfo way 
		//========================================================================================================	
		PixCheckDemo();
		
		//========================================================================================================
		//===== Read Communication Setting
		//========================================================================================================	
		COMMUNICATICON_ST aCommSet;
		memset(&aCommSet,0,sizeof(aCommSet));
		nResult = czReadCommunicationSet(&aCommSet);

		//========================================================================================================
		//===== Send Communication Setting
		//========================================================================================================	
		memcpy((char*)aCommSet.IPAddr, "169.254.11.113", 32);
		aCommSet.CustomPort = 9523;
		memcpy((char*)aCommSet.GatewayAddr, "169.254.11.1", 32);
		nResult = czWriteCommunicationSet(&aCommSet);

		//Reconnect the new IP,the sleep time based on the mainboard type!
		czSleep(500);
		memcpy((char*)If.ip, "169.254.18.126", 32);
		czInitAPI(&If);
		memset(&aCommSet,0,sizeof(aCommSet));
		nResult = czReadCommunicationSet(&aCommSet);
		
		//========================================================================================================
		//===== Get Current Play Content
		//========================================================================================================	
		nResult = czReadCurScreentshot((INT8U *)"F:\\11.JPG");
		
		//========================================================================================================
		//===== Play Sound
		//========================================================================================================	
		memcpy(path, ".\\Test.mp3", 10);
		nResult = czWriteSpecFile((INT8U*)("C:\\Test.mp3"), path);

		SoundST soundST;
		memset(&soundST, 0, sizeof(soundST));
		soundST.BuzzerSwitch = 1;
		soundST.PlayTimes = 1;
		nResult = czPlaySoundFile(soundST, (INT8U *)"c://Test.mp3");//"/usr/local/drivers/5.mp3"			//c://Test.mp3
		
		nResult = czPlaySoundFile4j(&soundST, (INT8U *)"c://Test.mp3");
		//Read Current Volume
		INT8U volume;
		nResult = czReadCurVolume(&volume);

		//Adjust Volume
		nResult = czAdjustVolume(80);
		nResult = czAdjustVolume(45);
		nResult = czAdjustVolume(90);

		nResult = czReadCurVolume(&volume);
		//Stop Play
		soundST.BuzzerSwitch = 0;
		//nResult = czPlaySoundFile(soundST, (INT8U *)"c://Test.mp3");
		
		//Set DefaultScreen
		memcpy(path, ".\\logo.bmp", 10);
		nResult = czWriteSpecFile((INT8U*)("D:\\P\\logo.bmp"), path);
		
		//Set Communication Lost Time
		SetDefaultScreentParameter();

		//Read Warning Log
		CZLog_File_Head logHead;
		CZLogDataST logDataEntry[50];
		INT8U DateTimeStr[32];
		memset(&logHead,0,sizeof(logHead));
		memset(logDataEntry,0,sizeof(logDataEntry));
		memset(DateTimeStr,0,sizeof(DateTimeStr));
		nResult = czReadWarningLog(&logHead,logDataEntry,50);
		//Get the Record DateTime
		nResult = czTM_DecodeDosTime(logDataEntry[9].DataTime,DateTimeStr,32);

		//Predefined Playlist Control
		PredefinedPlaylistDemo();

		ControlPlaylistDemo();

		system("pause");
	}
	catch(...)
	{
		;
	}
	return;
}

void ShowFilesToMultiSigns()
{
	INT8U i=0;
	INT32U RT;
	char *file[3] = 
	{
		{".\\1.bmp"},
		{".\\2.bmp"},
		{".\\3.bmp"}
	};
	char* ipArray[TEST_IPCOUNT] = {"169.254.15.124","169.254.10.149"};

	//Send Files
	for (i = 0;i<TEST_IPCOUNT;i++)
	{
		RT=czShowFilesSpe((char**)file, 3, 0x30, 3, ipArray[i], 9520, 0, COMM_UDP, "COM3", 9600, 0x0101, 0x01);
	}

	for (i = 0; i<TEST_IPCOUNT && RT == CZ_ERROR_OK; i++)
	{
		_czinterface If;
		InitIFStruct(If);																	//Init _czinterface;
		memcpy((char*)If.ip, ipArray[i], 14);
		czInitAPI(&If);																		//Call this API before czReadStats
		RT = czBlackScreen();																//BLACK Screen
	}

	//Send playlist
	for (i = 0;i<TEST_IPCOUNT;i++)
	{
		RT=czShowFilesSpe((char**)file, 3, 0x30, 3, ipArray[i], 9520, 0, COMM_UDP, "COM3", 9600, 0x0101, 0x02);
	}

	for (i = 0; i<TEST_IPCOUNT && RT == CZ_ERROR_OK; i++)
	{
		_czinterface If;
		InitIFStruct(If);																	//Init _czinterface;
		memcpy((char*)If.ip, ipArray[i], 14);
		czInitAPI(&If);																		//Call this API before czReadStats
		RT = czEndBlackScreen();															//BLACK Screen
	}
}

INT32U WINAPI dataInWorkThread( void *arg )
{
	INT32U RT;
	czBrightInfoExt BrightInfo;
	CURRENT_STATE State;
	INT8U ExData[1024];
	INT8U FileName[128];

	_czinterface *aIf = (_czinterface*)arg;

	czInitAPI(aIf);	
	while(1)
	{
		RT = czReadBrightInfoExt(&BrightInfo);

		memset(ExData,0,1024);
		RT = czReadCurrentState(&State,ExData,1024);

		memset(FileName, 0 , sizeof(FileName));
		RT = czGetPlayingFileName(FileName, 128);

		czSleep(1000);
	}
	return 0;
}


void MultiThreadDemo()
{
	char* ipArray[TEST_IPCOUNT] = {"169.254.11.112","169.254.11.115"};

	//Send Files
	for (INT8U i = 0;i<TEST_IPCOUNT;i++)
	{
		INT32U dummy;
		HANDLE threadHandle;

		_czinterface If;
		InitIFStruct(If);	
		memcpy((char*)If.ip, ipArray[i], 14);

		threadHandle = (HANDLE) _beginthreadex( 0, 0,dataInWorkThread, &If, 0, &dummy );
		if ( ! (( (threadHandle) != 0 && (threadHandle) != INVALID_HANDLE_VALUE )) )
		{		
			cout << "Create Thread Error" << endl;
			return ;
		}
		czSleep(50);
	}
	system("pause");
}

void SingleZoneDemo(ZoneSetHead zoneSetHead, ZoneSet zoneSetEntry[])
{
	INT32U RT, nPos;
	std::string content;
	INT8U  msgStr[30];
	INT8U enabled,pageCount=0,colorR,colorG,colorB,zoneCount=0,pageID=0;

	colorR = 0xFF;
	colorG = 0xFF;
	colorB = 0xFF;
	//Get MulitZone Setting
	RT = czGetMulitZoneSetting(&enabled,&pageCount);

	//Four steps are necessary!
	//1.Enable Mulit Zone
	enabled = 1;
	RT = czSetEnableMulitZone(enabled);
	//2.Set the page number=1
	pageCount = 1;
	RT = czSetPageCount(pageCount);

	//Get MulitZone Setting
	RT = czGetMulitZoneSetting(&enabled,&pageCount);

	memset(&zoneSetHead, 0, sizeof(ZoneSetHead));
	memset(zoneSetEntry, 0, sizeof(ZoneSet) * MAXZONECOUNT);

	zoneSetHead.ZoneNum = 1;
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

	RT = czGetZone(&zoneSetHead, zoneSetEntry, MAXZONECOUNT,pageID);

	ZoneDisplaySet zoneDisplayEntry;
	memset(&zoneDisplayEntry, 0, sizeof(ZoneDisplaySet));
	zoneDisplayEntry.ZoneSize = zoneSetEntry[0].ZoneWidth * zoneSetEntry[0].ZoneHeight;
	zoneDisplayEntry.ZoneID = zoneSetEntry[0].ZoneID;
	zoneDisplayEntry.ZoneType = 0;
	zoneDisplayEntry.CodeType = 0;
	zoneDisplayEntry.InMode = 3;
	zoneDisplayEntry.OutMode = 4;
	zoneDisplayEntry.Align = 0;
	zoneDisplayEntry.FGColor_R = colorR;
	zoneDisplayEntry.FGColor_G = colorG;
	zoneDisplayEntry.FGColor_B = colorB;
	zoneDisplayEntry.BGColor_R = 0;
	zoneDisplayEntry.BGColor_G = 0;
	zoneDisplayEntry.BGColor_B = 0;
	zoneDisplayEntry.AutoLine = 0;
	zoneDisplayEntry.AutoWidth = 1;
	zoneDisplayEntry.Speed = 5;
	zoneDisplayEntry.StayTime = 2;
	zoneDisplayEntry.Times = 0;
	zoneDisplayEntry.FontStyle = CZ_FONT_EN_14x8;		//CZ_FONT_EN_7x6
	zoneDisplayEntry.LineSpace = 1;
	zoneDisplayEntry.CloumnSpace = 1;
	zoneDisplayEntry.BlinkOnTime = 0x0A;
	zoneDisplayEntry.BlinkOffTime = 0x0A;
	content = "Welcome";
	zoneDisplayEntry.ContentSize = content.length();
	//display a message with property in zone
	Sleep(PARKSLEEPTIME);
	RT = czSetDisplay(pageID, zoneCount, 0, zoneDisplayEntry, (INT8U*)content.c_str());

	ZoneDisplayContentSet zoneDisplayContentEntry;
	memset(&zoneDisplayContentEntry, 0, sizeof(ZoneDisplayContentSet));
	zoneDisplayContentEntry.ZoneSize = zoneSetEntry[0].ZoneWidth * zoneSetEntry[0].ZoneHeight;
	zoneDisplayContentEntry.ZoneID = zoneSetEntry[0].ZoneID;
	content = "Hello";
	zoneDisplayContentEntry.ContentSize = content.length();
	//display a message without property in zone
	Sleep(PARKSLEEPTIME);
	RT = czSetContentDisplay(pageID, zoneCount, zoneDisplayContentEntry, (INT8U*)content.c_str());

	//display a message(English+chinese+English) without property in zone (under construction...)
	memset(&zoneDisplayContentEntry, 0, sizeof(ZoneDisplayContentSet));
	zoneDisplayContentEntry.ZoneSize = zoneSetEntry[0].ZoneWidth * zoneSetEntry[0].ZoneHeight;
	zoneDisplayContentEntry.ZoneID = zoneSetEntry[0].ZoneID;
	memset(msgStr, 0, sizeof(msgStr));
	content = "123";
	nPos = 0;
	memcpy(&msgStr[nPos], content.c_str(), content.length());
	nPos += content.length();
	msgStr[nPos++] = 0x08;
	msgStr[nPos++] = 0x31;
	msgStr[nPos++] = CZ_FONT_CH_ST_16x16;	//Code Type must be the same.
	content = "欢迎";
	memcpy(&msgStr[nPos], content.c_str(), content.length());
	nPos += content.length();
	msgStr[nPos++] = 0x08;					//switch font control code
	msgStr[nPos++] = 0x31;					//switch font control code
	msgStr[nPos++] = CZ_FONT_EN_16x9;		//font 7x6
	content = "abc";
	memcpy(&msgStr[nPos], content.c_str(), content.length());
	nPos += content.length();
	zoneDisplayContentEntry.ContentSize = nPos;
	Sleep(PARKSLEEPTIME);
	RT = czSetContentDisplay(pageID, zoneCount, zoneDisplayContentEntry, (INT8U*)msgStr);

	//display a message(Picture+text) without property in zone
	memset(&zoneDisplayContentEntry, 0, sizeof(ZoneDisplayContentSet));
	zoneDisplayContentEntry.ZoneSize = zoneSetEntry[0].ZoneWidth * zoneSetEntry[0].ZoneHeight;
	zoneDisplayContentEntry.ZoneID = zoneSetEntry[0].ZoneID;
	memset(msgStr, 0, sizeof(msgStr));
	nPos = 0;
	msgStr[nPos++] = 0x08;				//display picture control code
	msgStr[nPos++] = 0x33;				//display picture control code
	msgStr[nPos++] = 0x01;				//display picture control code
	content = "Hello";
	memcpy(&msgStr[nPos], content.c_str(), content.length());
	nPos += content.length();
	zoneDisplayContentEntry.ContentSize = nPos;
	Sleep(PARKSLEEPTIME);
	RT = czSetContentDisplay(pageID, zoneCount, zoneDisplayContentEntry, (INT8U*)msgStr);
}

void TwoZoneDemo(ZoneSetHead zoneSetHead, ZoneSet zoneSetEntry[])
{
	FILE *fp;
	INT32U RT, nPos;
	std::string content;
	INT8U  msgStr[30];
	INT8U enabled,pageCount=0,colorR,colorG,colorB,zoneCount=0,pageID=0;

	colorR = 0xFF;
	colorG = 0xFF;
	colorB = 0x00;
	//Get MulitZone Setting
	RT = czGetMulitZoneSetting(&enabled,&pageCount);

	//Four steps are necessary!
	//1.Enable Mulit Zone
	enabled = 1;
	RT = czSetEnableMulitZone(enabled);
	//2.Set the page number=1
	pageCount = 1;
	RT = czSetPageCount(pageCount);

	//Get MulitZone Setting
	RT = czGetMulitZoneSetting(&enabled,&pageCount);

	memset(&zoneSetHead, 0, sizeof(ZoneSetHead));
	memset(zoneSetEntry, 0, sizeof(ZoneSet) * MAXZONECOUNT);

	zoneSetHead.ZoneNum = 2;
	zoneSetEntry[0].ZoneID = 1;
	zoneSetEntry[0].XPos = 0;
	zoneSetEntry[0].YPos = 0;
	zoneSetEntry[0].ZoneWidth = 0x20;
	zoneSetEntry[0].ZoneHeight = 0x10;

	zoneSetEntry[1].ZoneID = 2;
	zoneSetEntry[1].XPos = 0x20;
	zoneSetEntry[1].YPos = 0;
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
	ZoneDisplaySet zoneDisplayEntry;
	memset(&zoneDisplayEntry, 0, sizeof(ZoneDisplaySet));
	zoneDisplayEntry.ZoneSize = zoneSetEntry[0].ZoneWidth * zoneSetEntry[0].ZoneHeight;
	zoneDisplayEntry.ZoneID = zoneSetEntry[0].ZoneID;
	zoneDisplayEntry.FGColor_R = colorR;
	zoneDisplayEntry.FGColor_G = colorG;
	zoneDisplayEntry.FGColor_B = colorB;
	zoneDisplayEntry.AutoWidth = 1;
	zoneDisplayEntry.Speed = 1;
	zoneDisplayEntry.StayTime = 1;
	zoneDisplayEntry.FontStyle = 0x32;
	zoneDisplayEntry.LineSpace = 1;
	zoneDisplayEntry.CloumnSpace = 1;
	zoneDisplayEntry.BlinkOnTime = 0x0A;
	zoneDisplayEntry.BlinkOffTime = 0x0A;
	content = "Left";
	zoneDisplayEntry.ContentSize = content.length();
	Sleep(PARKSLEEPTIME);
	//display a message with property in zone 1
	RT = czSetDisplay(pageID, zoneCount, 0, zoneDisplayEntry, (INT8U*)content.c_str());

	memset(&zoneDisplayEntry, 0, sizeof(ZoneDisplaySet));
	zoneDisplayEntry.ZoneSize = zoneSetEntry[1].ZoneWidth * zoneSetEntry[1].ZoneHeight;
	zoneDisplayEntry.ZoneID = zoneSetEntry[1].ZoneID;
	zoneDisplayEntry.FGColor_R = 0x00;
	zoneDisplayEntry.FGColor_G = 0xFF;
	zoneDisplayEntry.FGColor_B = 0xFF;
	zoneDisplayEntry.AutoWidth = 1;
	zoneDisplayEntry.Speed = 1;
	zoneDisplayEntry.StayTime = 1;
	zoneDisplayEntry.FontStyle = 0x32;
	zoneDisplayEntry.LineSpace = 1;
	zoneDisplayEntry.CloumnSpace = 1;
	zoneDisplayEntry.BlinkOnTime = 0x0A;
	zoneDisplayEntry.BlinkOffTime = 0x0A;
	content = "Right";
	zoneDisplayEntry.ContentSize = content.length();
	Sleep(PARKSLEEPTIME);
	//display a message with property in zone 2
	RT = czSetDisplay(pageID, zoneCount, 0, zoneDisplayEntry, (INT8U*)content.c_str());


	//============================================================================================================
	//==== b).display a message without propery
	//============================================================================================================
	ZoneDisplayContentSet zoneDisplayContentEntry;
	memset(&zoneDisplayContentEntry, 0, sizeof(ZoneDisplayContentSet));
	zoneDisplayContentEntry.ZoneSize = zoneSetEntry[0].ZoneWidth * zoneSetEntry[0].ZoneHeight;
	zoneDisplayContentEntry.ZoneID = zoneSetEntry[0].ZoneID;
	content = "Up";
	zoneDisplayContentEntry.ContentSize = content.length();
	//display a message without propery in zone 1
	Sleep(PARKSLEEPTIME);
	RT = czSetContentDisplay(pageID, zoneCount, zoneDisplayContentEntry, (INT8U*)content.c_str());

	memset(&zoneDisplayContentEntry, 0, sizeof(ZoneDisplayContentSet));
	zoneDisplayContentEntry.ZoneSize = zoneSetEntry[1].ZoneWidth * zoneSetEntry[1].ZoneHeight;
	zoneDisplayContentEntry.ZoneID = zoneSetEntry[1].ZoneID;
	content = "NUM";
	zoneDisplayContentEntry.ContentSize = content.length();
	//display a message without propery in zone 2
	Sleep(PARKSLEEPTIME);
	RT = czSetContentDisplay(pageID, zoneCount, zoneDisplayContentEntry, (INT8U*)content.c_str());

	//============================================================================================================
	//==== c).Display Picture+Text
	//==== 1.send picture at first(this step is not necessary,you can also use the factory default)
	//==== 2.send message(Picture+text) in zone 1
	//==== 3.send message(Picture+text) in zone 2
	//============================================================================================================
	//if you want to display custom picture,send picture at first,the dest path must be "F:\\P\\x.bmp", x is a number greater than 9
	//czWriteSpecFile((INT8U*)("F:\\P\\10.bmp"), ".\\up.bmp");

	memset(&zoneDisplayContentEntry, 0, sizeof(ZoneDisplayContentSet));
	zoneDisplayContentEntry.ZoneSize = zoneSetEntry[0].ZoneWidth * zoneSetEntry[0].ZoneHeight;
	zoneDisplayContentEntry.ZoneID = zoneSetEntry[0].ZoneID;
	zoneDisplayContentEntry.ZoneType = 0;
	content = "12";
	memset(msgStr, 0, sizeof(msgStr));
	nPos = 0;
	msgStr[nPos++] = 0x08;				//display picture control code
	msgStr[nPos++] = 0x33;				//display picture control code
	msgStr[nPos++] = 0x01;				//"up arrow" picture
	memcpy(&msgStr[nPos], content.c_str(), content.length());
	nPos += content.length();
	zoneDisplayContentEntry.ContentSize = nPos;

	//display a message(Picture+text) without propery in zone 1
	Sleep(PARKSLEEPTIME);
	RT = czSetContentDisplay(pageID, zoneCount, zoneDisplayContentEntry, (INT8U*)msgStr);

	memset(&zoneDisplayContentEntry, 0, sizeof(ZoneDisplayContentSet));
	zoneDisplayContentEntry.ZoneSize = zoneSetEntry[1].ZoneWidth * zoneSetEntry[1].ZoneHeight;
	zoneDisplayContentEntry.ZoneID = zoneSetEntry[1].ZoneID;
	zoneDisplayContentEntry.ZoneType = 0;
	content = "30";
	memset(msgStr, 0, sizeof(msgStr));
	nPos = 0;
	msgStr[nPos++] = 0x08;				//display picture control code
	msgStr[nPos++] = 0x33;				//display picture control code
	msgStr[nPos++] = 0x03;				//"left arrow" picture
	memcpy(&msgStr[nPos], content.c_str(), content.length());
	nPos += content.length();
	zoneDisplayContentEntry.ContentSize = nPos;

	//display a message(Picture+text) without propery in zone 2
	Sleep(PARKSLEEPTIME);
	RT = czSetContentDisplay(pageID, zoneCount, zoneDisplayContentEntry, (INT8U*)msgStr);

}

void FourZoneDemo(ZoneSetHead zoneSetHead, ZoneSet zoneSetEntry[])
{
	INT32U RT, nPos;
	std::string content;
	INT8U  msgStr[30];
	INT8U enabled,pageCount=0,colorR,colorG,colorB,zoneCount=0,pageID=0;

	colorR = 0xFF;
	colorG = 0xFF;
	colorB = 0x00;
	//Get MulitZone Setting
	RT = czGetMulitZoneSetting(&enabled,&pageCount);

	//Four steps are necessary!
	//1.Enable Mulit Zone
	enabled = 1;
	RT = czSetEnableMulitZone(enabled);
	//2.Set the page number=1
	pageCount = 1;
	RT = czSetPageCount(pageCount);

	//Get MulitZone Setting
	RT = czGetMulitZoneSetting(&enabled,&pageCount);

	memset(&zoneSetHead, 0, sizeof(ZoneSetHead));
	memset(zoneSetEntry, 0, sizeof(ZoneSet) * MAXZONECOUNT);

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

	ZoneDisplaySet zoneDisplayEntry;
	memset(&zoneDisplayEntry, 0, sizeof(ZoneDisplaySet));
	zoneDisplayEntry.ZoneSize = zoneSetEntry[0].ZoneWidth * zoneSetEntry[0].ZoneHeight;
	zoneDisplayEntry.ZoneID = zoneSetEntry[0].ZoneID;
	zoneDisplayEntry.FGColor_R = colorR;
	zoneDisplayEntry.FGColor_G = colorG;
	zoneDisplayEntry.FGColor_B = colorB;
	zoneDisplayEntry.AutoWidth = 1;
	zoneDisplayEntry.Speed = 1;
	zoneDisplayEntry.StayTime = 1;
	zoneDisplayEntry.FontStyle = 0x32;
	zoneDisplayEntry.LineSpace = 1;
	zoneDisplayEntry.CloumnSpace = 1;
	zoneDisplayEntry.BlinkOnTime = 0x0A;
	zoneDisplayEntry.BlinkOffTime = 0x0A;
	zoneDisplayEntry.InMode = 3;
	zoneDisplayEntry.OutMode = 3;
	content = "zone1";
	zoneDisplayEntry.ContentSize = content.length();
	Sleep(PARKSLEEPTIME);
	//display a message with property in zone 1
	RT = czSetDisplay(pageID, zoneCount, 0, zoneDisplayEntry, (INT8U*)content.c_str());

	memset(&zoneDisplayEntry, 0, sizeof(ZoneDisplaySet));
	zoneDisplayEntry.ZoneSize = zoneSetEntry[2].ZoneWidth * zoneSetEntry[2].ZoneHeight;
	zoneDisplayEntry.ZoneID = zoneSetEntry[2].ZoneID;
	zoneDisplayEntry.FGColor_R = colorR;
	zoneDisplayEntry.FGColor_G = colorG;
	zoneDisplayEntry.FGColor_B = colorB;
	zoneDisplayEntry.AutoWidth = 1;
	zoneDisplayEntry.Speed = 1;
	zoneDisplayEntry.StayTime = 1;
	zoneDisplayEntry.FontStyle = 0x32;
	zoneDisplayEntry.LineSpace = 1;
	zoneDisplayEntry.CloumnSpace = 1;
	zoneDisplayEntry.BlinkOnTime = 0x0A;
	zoneDisplayEntry.BlinkOffTime = 0x0A;
	zoneDisplayEntry.InMode = 2;
	zoneDisplayEntry.OutMode = 2;
	content = "zone2";
	zoneDisplayEntry.ContentSize = content.length();
	Sleep(PARKSLEEPTIME);
	//display a message with property in zone 2
	RT = czSetDisplay(pageID, zoneCount, 0, zoneDisplayEntry, (INT8U*)content.c_str());

	ZoneDisplayContentSet zoneDisplayContentEntry;
	memset(&zoneDisplayContentEntry, 0, sizeof(ZoneDisplayContentSet));
	zoneDisplayContentEntry.ZoneSize = zoneSetEntry[0].ZoneWidth * zoneSetEntry[0].ZoneHeight;
	zoneDisplayContentEntry.ZoneID = zoneSetEntry[0].ZoneID;
	zoneDisplayContentEntry.ZoneType = 0;
	content = "";
	memset(msgStr, 0, sizeof(msgStr));
	nPos = 0;
	msgStr[nPos++] = 0x08;				//display picture control code
	msgStr[nPos++] = 0x33;				//display picture control code
	msgStr[nPos++] = 0x01;				//"up arrow" picture
	memcpy(&msgStr[nPos], content.c_str(), content.length());
	nPos += content.length();
	zoneDisplayContentEntry.ContentSize = nPos;
	//display a message(Picture+text) without propery in zone 1
	Sleep(PARKSLEEPTIME);
	RT = czSetContentDisplay(pageID, zoneCount, zoneDisplayContentEntry, (INT8U*)msgStr);

	memset(&zoneDisplayContentEntry, 0, sizeof(ZoneDisplayContentSet));
	zoneDisplayContentEntry.ZoneSize = zoneSetEntry[1].ZoneWidth * zoneSetEntry[1].ZoneHeight;
	zoneDisplayContentEntry.ZoneID = zoneSetEntry[1].ZoneID;
	content = "12";
	zoneDisplayContentEntry.ContentSize = content.length();
	//display a message without propery in zone 2
	Sleep(PARKSLEEPTIME);
	RT = czSetContentDisplay(pageID, zoneCount, zoneDisplayContentEntry, (INT8U*)content.c_str());

	memset(&zoneDisplayContentEntry, 0, sizeof(ZoneDisplayContentSet));
	zoneDisplayContentEntry.ZoneSize = zoneSetEntry[2].ZoneWidth * zoneSetEntry[2].ZoneHeight;
	zoneDisplayContentEntry.ZoneID = zoneSetEntry[2].ZoneID;
	zoneDisplayContentEntry.ZoneType = 0;
	content = "";
	memset(msgStr, 0, sizeof(msgStr));
	nPos = 0;
	msgStr[nPos++] = 0x08;				//display picture control code
	msgStr[nPos++] = 0x33;				//display picture control code
	msgStr[nPos++] = 0x03;				//"left arrow" picture
	memcpy(&msgStr[nPos], content.c_str(), content.length());
	nPos += content.length();
	zoneDisplayContentEntry.ContentSize = nPos;
	//display a message(Picture+text) without propery in zone 3
	Sleep(PARKSLEEPTIME);
	RT = czSetContentDisplay(pageID, zoneCount, zoneDisplayContentEntry, (INT8U*)msgStr);

	memset(&zoneDisplayContentEntry, 0, sizeof(ZoneDisplayContentSet));
	zoneDisplayContentEntry.ZoneSize = zoneSetEntry[3].ZoneWidth * zoneSetEntry[3].ZoneHeight;
	zoneDisplayContentEntry.ZoneID = zoneSetEntry[3].ZoneID;
	content = "50";
	zoneDisplayContentEntry.ContentSize = content.length();
	//display a message without propery in zone 4
	Sleep(PARKSLEEPTIME);
	RT = czSetContentDisplay(pageID, zoneCount, zoneDisplayContentEntry, (INT8U*)content.c_str());
}

void MultiZoneDemo(ZoneSetHead zoneSetHead, ZoneSet zoneSetEntry[])
{
	INT32U RT, nPos;
	std::string content;
	INT8U  msgStr[30];
	INT8U enabled,pageCount,colorR,colorG,colorB,zoneCount=0,pageID=0;

	colorR = 0xFF;
	colorG = 0x00;
	colorB = 0x00;
	//Get MulitZone Setting
	RT = czGetMulitZoneSetting(&enabled,&pageCount);

	//Four steps are necessary!
	//1.Enable Mulit Zone
	enabled = 1;
	RT = czSetEnableMulitZone(enabled);
	//2.Set the page number=1
	pageCount = 1;
	RT = czSetPageCount(pageCount);

	//Get MulitZone Setting
	RT = czGetMulitZoneSetting(&enabled,&pageCount);

	memset(&zoneSetHead, 0, sizeof(ZoneSetHead));
	memset(zoneSetEntry, 0, sizeof(ZoneSet) * zoneSetHead.ZoneNum);

	zoneSetHead.ZoneNum = MAXZONECOUNT;
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

	ZoneDisplaySet zoneDisplayEntry;
	memset(&zoneDisplayEntry, 0, sizeof(ZoneDisplaySet));
	zoneDisplayEntry.ZoneSize = zoneSetEntry[0].ZoneWidth * zoneSetEntry[0].ZoneHeight;
	zoneDisplayEntry.ZoneID = zoneSetEntry[0].ZoneID;
	zoneDisplayEntry.ZoneType = 2;
	zoneDisplayEntry.InMode = 0;
	zoneDisplayEntry.OutMode = 0;
	zoneDisplayEntry.FGColor_R = colorR;
	zoneDisplayEntry.FGColor_G = colorG;
	zoneDisplayEntry.FGColor_B = colorB;
	zoneDisplayEntry.Speed = 1;
	zoneDisplayEntry.StayTime = 1;
	zoneDisplayEntry.FontStyle = CZ_FONT_EN_7x6;
	memset(msgStr, 0, sizeof(msgStr));
	nPos = 0;
	msgStr[nPos++] = 0x08;
	msgStr[nPos++] = 0x00;
	zoneDisplayEntry.ContentSize = nPos;
	//display HH:MM with property in zone 1
	RT = czSetDisplay(pageID, zoneCount, 0, zoneDisplayEntry, (INT8U*)msgStr);

	memset(&zoneDisplayEntry, 0, sizeof(ZoneDisplaySet));
	zoneDisplayEntry.ZoneSize = zoneSetEntry[1].ZoneWidth * zoneSetEntry[1].ZoneHeight;
	zoneDisplayEntry.ZoneType = 0;
	zoneDisplayEntry.ZoneID = zoneSetEntry[1].ZoneID;
	zoneDisplayEntry.InMode = 0;
	zoneDisplayEntry.OutMode = 0;
	zoneDisplayEntry.FGColor_R = colorR;
	zoneDisplayEntry.FGColor_G = colorG;
	zoneDisplayEntry.FGColor_B = colorB;
	zoneDisplayEntry.Speed = 1;
	zoneDisplayEntry.StayTime = 100;
	zoneDisplayEntry.FontStyle = CZ_FONT_EN_7x6;
	content = "T6";
	zoneDisplayEntry.ContentSize = content.length();
	//display static message with property in zone 2
	RT = czSetDisplay(pageID, zoneCount, 0, zoneDisplayEntry, (INT8U*)content.c_str());

	memset(&zoneDisplayEntry, 0, sizeof(ZoneDisplaySet));
	zoneDisplayEntry.ZoneSize = zoneSetEntry[2].ZoneWidth * zoneSetEntry[2].ZoneHeight;
	zoneDisplayEntry.ZoneID = zoneSetEntry[2].ZoneID;
	zoneDisplayEntry.InMode = 0;
	zoneDisplayEntry.OutMode = 0;
	zoneDisplayEntry.FGColor_R = colorR;
	zoneDisplayEntry.FGColor_G = colorG;
	zoneDisplayEntry.FGColor_B = colorB;
	zoneDisplayEntry.Speed = 1;
	zoneDisplayEntry.StayTime = 1;
	zoneDisplayEntry.FontStyle = CZ_FONT_EN_7x6;
	content = "2";
	zoneDisplayEntry.ContentSize = content.length();
	//display static message with property in zone 3
	RT = czSetDisplay(pageID, 9, 0, zoneDisplayEntry, (INT8U*)content.c_str());

	memset(&zoneDisplayEntry, 0, sizeof(ZoneDisplaySet));
	zoneDisplayEntry.ZoneSize = zoneSetEntry[3].ZoneWidth * zoneSetEntry[3].ZoneHeight;
	zoneDisplayEntry.ZoneID = zoneSetEntry[3].ZoneID;
	zoneDisplayEntry.InMode = 1;
	zoneDisplayEntry.OutMode = 1;
	zoneDisplayEntry.FGColor_R = colorR;
	zoneDisplayEntry.FGColor_G = colorG;
	zoneDisplayEntry.FGColor_B = colorB;
	zoneDisplayEntry.Speed = 1;
	zoneDisplayEntry.StayTime = 1;
	zoneDisplayEntry.FontStyle = CZ_FONT_EN_7x6;
	content = "Hello,Welcome To China!";
	zoneDisplayEntry.ContentSize = content.length();
	//display MoveLeft message with property in zone 4
	RT = czSetDisplay(pageID, zoneCount, 0, zoneDisplayEntry, (INT8U*)content.c_str());

	memset(&zoneDisplayEntry, 0, sizeof(ZoneDisplaySet));
	zoneDisplayEntry.ZoneSize = zoneSetEntry[4].ZoneWidth * zoneSetEntry[4].ZoneHeight;
	zoneDisplayEntry.ZoneID = zoneSetEntry[4].ZoneID;
	zoneDisplayEntry.InMode = 0;
	zoneDisplayEntry.OutMode = 0;
	zoneDisplayEntry.FGColor_R = colorR;
	zoneDisplayEntry.FGColor_G = colorG;
	zoneDisplayEntry.FGColor_B = colorB;
	zoneDisplayEntry.Speed = 1;
	zoneDisplayEntry.StayTime = 1;
	zoneDisplayEntry.FontStyle = CZ_FONT_EN_7x6;
	content = "X0";
	zoneDisplayEntry.ContentSize = content.length();
	//display static message with property in zone 5
	RT = czSetDisplay(pageID, zoneCount, 0, zoneDisplayEntry, (INT8U*)content.c_str());

	memset(&zoneDisplayEntry, 0, sizeof(ZoneDisplaySet));
	zoneDisplayEntry.ZoneSize = zoneSetEntry[5].ZoneWidth * zoneSetEntry[5].ZoneHeight;
	zoneDisplayEntry.ZoneID = zoneSetEntry[5].ZoneID;
	zoneDisplayEntry.InMode = 0;
	zoneDisplayEntry.OutMode = 0;
	zoneDisplayEntry.FGColor_R = colorR;
	zoneDisplayEntry.FGColor_G = colorG;
	zoneDisplayEntry.FGColor_B = colorB;
	zoneDisplayEntry.Speed = 1;
	zoneDisplayEntry.StayTime = 1;
	zoneDisplayEntry.FontStyle = CZ_FONT_EN_7x6;
	content = "T6";
	zoneDisplayEntry.ContentSize = content.length();
	//display static message with property in zone 6
	RT = czSetDisplay(pageID, zoneCount, 0, zoneDisplayEntry, (INT8U*)content.c_str());

	memset(&zoneDisplayEntry, 0, sizeof(ZoneDisplaySet));
	zoneDisplayEntry.ZoneSize = zoneSetEntry[6].ZoneWidth * zoneSetEntry[6].ZoneHeight;
	zoneDisplayEntry.ZoneID = zoneSetEntry[6].ZoneID;
	zoneDisplayEntry.InMode = 0;
	zoneDisplayEntry.OutMode = 0;
	zoneDisplayEntry.FGColor_R = colorR;
	zoneDisplayEntry.FGColor_G = colorG;
	zoneDisplayEntry.FGColor_B = colorB;
	zoneDisplayEntry.Speed = 1;
	zoneDisplayEntry.StayTime = 1;
	zoneDisplayEntry.FontStyle = CZ_FONT_EN_7x6;
	content = "2";
	zoneDisplayEntry.ContentSize = content.length();
	//display static message with property in zone 7
	RT = czSetDisplay(pageID, zoneCount, 0, zoneDisplayEntry, (INT8U*)content.c_str());

	memset(&zoneDisplayEntry, 0, sizeof(ZoneDisplaySet));
	zoneDisplayEntry.ZoneSize = zoneSetEntry[7].ZoneWidth * zoneSetEntry[7].ZoneHeight;
	zoneDisplayEntry.ZoneID = zoneSetEntry[7].ZoneID;
	zoneDisplayEntry.InMode = 1;
	zoneDisplayEntry.OutMode = 1;
	zoneDisplayEntry.FGColor_R = colorR;
	zoneDisplayEntry.FGColor_G = colorG;
	zoneDisplayEntry.FGColor_B = colorB;
	zoneDisplayEntry.Speed = 1;
	zoneDisplayEntry.StayTime = 1;
	zoneDisplayEntry.FontStyle = CZ_FONT_EN_7x6;
	content = "This is Chainzone!";
	zoneDisplayEntry.ContentSize = content.length();
	//display MoveLeft message with property in zone 8
	RT = czSetDisplay(pageID, zoneCount, 0, zoneDisplayEntry, (INT8U*)content.c_str());

	memset(&zoneDisplayEntry, 0, sizeof(ZoneDisplaySet));
	zoneDisplayEntry.ZoneSize = zoneSetEntry[8].ZoneWidth * zoneSetEntry[8].ZoneHeight;
	zoneDisplayEntry.ZoneID = zoneSetEntry[8].ZoneID;
	zoneDisplayEntry.InMode = 0;
	zoneDisplayEntry.OutMode = 0;
	zoneDisplayEntry.FGColor_R = colorR;
	zoneDisplayEntry.FGColor_G = colorG;
	zoneDisplayEntry.FGColor_B = colorB;
	zoneDisplayEntry.Speed = 1;
	zoneDisplayEntry.StayTime = 1;
	zoneDisplayEntry.FontStyle = CZ_FONT_EN_7x6;
	zoneDisplayEntry.Align = 0x11;
	content = "X0";
	zoneDisplayEntry.ContentSize = content.length();
	//display static message with property in zone 9
	RT = czSetDisplay(pageID, zoneCount, 0, zoneDisplayEntry, (INT8U*)content.c_str());

	ZoneDisplayContentSet zoneDisplayContentEntry;
	memset(&zoneDisplayContentEntry, 0, sizeof(ZoneDisplayContentSet));
	zoneDisplayContentEntry.ZoneSize = zoneSetEntry[1].ZoneWidth * zoneSetEntry[1].ZoneHeight;
	zoneDisplayContentEntry.ZoneID = zoneSetEntry[1].ZoneID;
	content = "T9";
	zoneDisplayContentEntry.ContentSize = content.length();
	//display a new message without propery in zone 2(qucikly modify the message of zone 2)
	Sleep(PARKSLEEPTIME);
	RT = czSetContentDisplay(pageID, zoneCount, zoneDisplayContentEntry, (INT8U*)content.c_str());

	memset(&zoneDisplayContentEntry, 0, sizeof(ZoneDisplayContentSet));
	zoneDisplayContentEntry.ZoneSize = zoneSetEntry[3].ZoneWidth * zoneSetEntry[3].ZoneHeight;
	zoneDisplayContentEntry.ZoneID = zoneSetEntry[3].ZoneID;
	content = "HELLO,WELCOME TO CHINA!";
	zoneDisplayContentEntry.ContentSize = content.length();
	//display a new moveleft message without propery in zone 4(qucikly modify the message of zone 4)
	Sleep(PARKSLEEPTIME);
	RT = czSetContentDisplay(pageID, zoneCount, zoneDisplayContentEntry, (INT8U*)content.c_str());
}

void ParkAPIDemo()
{
	INT32U RT;
	INT8U pageID=1;

	_czinterface If;
	InitIFStruct(If);
	czInitAPI(&If);

	ZoneSetHead zoneSetHead;
	ZoneSet zoneSetEntry[MAXZONECOUNT];
	memset(&zoneSetHead, 0, sizeof(ZoneSetHead));
	memset(zoneSetEntry, 0, sizeof(ZoneSet) * MAXZONECOUNT);
	//must be czDivideZone at first,otherwise return error!
	RT = czGetZone(&zoneSetHead, zoneSetEntry, MAXZONECOUNT,pageID);

	INT8U  path[MAX_PATH];
	memset(path, 0, sizeof(path));
	memcpy(path, ".\\upArrow.bmp", 16);
	RT = czWriteSpecFile((INT8U*)("D:\\P\\1.bmp"), path);
	memset(path, 0, sizeof(path));
	memcpy(path, ".\\leftArrow.bmp", 16);
	RT = czWriteSpecFile((INT8U*)("D:\\P\\2.bmp"), path);
	memset(path, 0, sizeof(path));
	memcpy(path, ".\\rigthArrow.bmp", 16);
	RT = czWriteSpecFile((INT8U*)("D:\\P\\3.bmp"), path);

	SingleZoneDemo(zoneSetHead, zoneSetEntry);

	TwoZoneDemo(zoneSetHead, zoneSetEntry);

	FourZoneDemo(zoneSetHead,zoneSetEntry);

	MultiZoneDemo(zoneSetHead,zoneSetEntry);
}

void ControlForSpecialLCS()
{
	INT32U RT;
	INT8U action(0), voiceDataLen(0);
	char  msgStr[10];

	_czinterface If;
	InitIFStruct(If);
	czInitAPI(&If);

	RT = czGetLCS(&action);		//0:close	1:red cross open	2: green arrow open
	RT = czSetLCS(action);		//0:close	1:red cross open	2: green arrow open
	
	memset(msgStr,0,10);
	voiceDataLen = 4;
	memcpy(&msgStr[0], "测试", voiceDataLen);
	INT8U voiceSwitch(1);		//0:close	1:open
	INT8U voiceEncode(0);		//0:GB2312	1:GBK	2:BIG5	3:UNICODE
	RT = czPlayVoice(voiceSwitch, voiceEncode, (INT8U*)msgStr, voiceDataLen);
}

int _tmain(int argc, _TCHAR* argv[])
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
	//ShowFilesToMultiSigns();

	//============================================================================================================
	//==== Mulit Thread Demo
	//============================================================================================================
	//MultiThreadDemo();

	//============================================================================================================
	//==== Park API Demo
	//============================================================================================================
	//ParkAPIDemo();
}