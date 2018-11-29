//==============================================================================
//
// Title:		TestCircuitWaferNew
// Purpose:		A short description of the application.
//
// Created on:	2018/8/2 at 13:59:41 by user.
// Copyright:	. All Rights Reserved.
//
//==============================================================================

//==============================================================================
// Include files


#include "ReportX.h"
#include <formatio.h>
#include <rs232.h>
#include "asynctmr.h"
#include "progressbar.h"
#include <ansi_c.h>
#include <cvirte.h>		
#include <userint.h>
#include "TestCircuitWaferNew.h"
#include "toolbox.h"
#include "sys.h"
#include "functions.h"
#include "cmdtable.h"

//==============================================================================
// Constants
#define BUTTON_COLUMN 1 
#define UP_LEVEL 1
#define LOW_LEVEL 0
#define FRISTADSEND 1
#define SECONDADSEND 2
#define THIRDADSEND 3
#define MAX_DATE_LEN        35
//MircoDIInputTureResult
const u8 MircoDIInputFristResultUpLevel  [4] = { 0x02, 0x00 ,0x00, 0x00 };
const u8 MircoDIInputFristResultLowLevel [4] = { 0x03, 0x00 ,0x00, 0x00 };
const u8 MircoDIInputSecondResultUpLevel  [4] = { 0x01, 0x00 ,0x00, 0x00 };
const u8 MircoDIInputSecondResultLowLevel [4] = { 0x03, 0x00 ,0x00, 0x00 };
const u8 MircoDIInputThirdResultUpLevel  [4] = { 0x07, 0x00 ,0x00, 0x00 };
const u8 MircoDIInputThirdResultLowLevel [4] = { 0x03, 0x00 ,0x00, 0x00 };
const u8 MircoDIInputFourthResultUpLevel  [4] = { 0x0b, 0x00 ,0x00, 0x00 };
const u8 MircoDIInputFourthResultLowLevel [4] = { 0x03, 0x00 ,0x00, 0x00 };
const u8 MircoDIInputFifthResultUpLevel  [4] = { 0x13, 0x00 ,0x00, 0x00 };
const u8 MircoDIInputFifthResultLowLevel [4] = { 0x03, 0x00 ,0x00, 0x00 };
const u8 MircoDIInputSixthResultUpLevel  [4] = { 0x23, 0x00 ,0x00, 0x00 };
const u8 MircoDIInputSixthResultLowLevel [4] = { 0x03, 0x00 ,0x00, 0x00 };
//================================================================================
//MircoDOOutTrueResult
const u8 MircoDOOutFristResultUpLevel  [4]= { 0xff,0x00 ,0x00,0x00 };
const u8 MircoDOOutFristResultLowLevel  [4]= { 0xfe,0x00 ,0x00,0x00 };
const u8 MircoDOOutSecondResultUpLevel  [4]= { 0xfc,0x00 ,0x00,0x00 };
const u8 MircoDOOutSecondResultLowLevel  [4]= { 0xfe,0x00 ,0x00,0x00 };
const u8 MircoDOOutThirdResultUpLevel  [4]= { 0xfa,0x00 ,0x00,0x00 };
const u8 MircoDOOutThirdResultLowLevel  [4]= { 0xfe,0x00 ,0x00,0x00 };
const u8 MircoDOOutFourthResultUpLevel  [4]= { 0xf6,0x00 ,0x00,0x00 };
const u8 MircoDOOutFourthResultLowLevel  [4]= { 0xfe,0x00 ,0x00,0x00 };
const u8 MircoDOOutFifthResultUpLevel  [4]= { 0xee,0x00 ,0x00,0x00 };
const u8 MircoDOOutFifthResultLowLevel  [4]= { 0xfe,0x00 ,0x00,0x00 };
const u8 MircoDOOutSixthResultUpLevel  [4]= { 0xde,0x00 ,0x00,0x00 };
const u8 MircoDOOutSixthResultLowLevel  [4]= { 0xfe,0x00 ,0x00,0x00 };
const u8 MircoDOOutSeventhResultUpLevel  [4]= { 0xbe,0x00 ,0x00,0x00 };
const u8 MircoDOOutSeventhResultLowLevel  [4]= { 0xfe,0x00 ,0x00,0x00 };
const u8 MircoDOOutEighthResultUpLevel  [4]= { 0x7e,0x00 ,0x00,0x00 };
const u8 MircoDOOutEighthResultLowLevel  [4]= { 0xfe,0x00 ,0x00,0x00 };
//==============================================================================
//Mirco429RoadResult
const u8 result[4] = {0xFE,0xFF,0x03,0x00};
//==============================================================================
//MircoBeepType
const u8 BeepClose [10] = {0x7E, 0x05, 0x00,0xA6,0x00,0x00,0x00, 0x00, 0xE1, 0xE7};//�رշ�����
const u8 BeepContinue [10] = {0x7E, 0x05, 0x00,0xA6,0x01,0x00,0x00, 0x00, 0x55, 0x91};//����
const u8 BeepIntermittent  [10] = {0x7E, 0x05, 0x00,0xA6,0x02,0x00,0x00, 0x00, 0x89, 0x0A};//����
//==============================================================================
//RS232 ����
const u8 RS232TestCMD [9] = {0x7E, 0x04, 0x00, 0xB0, 0x01, 0x00, 0x06, 0x27,0xa6};//����RS232����ָ��
//==============================================================================
//RS232 ���Է��صĽ��
const u8 RS232TestCMDReslut[3] = {0x01, 0x00, 0x06};
//==============================================================================
//�ϣ��µ�ָ��
const u8 UpPower[7] = {0x7E, 0x02, 0x00, 0xC1, 0x01, 0x44, 0x35};
const u8 DownPower[7] = {0x7E, 0x02, 0x00, 0xC1, 0x00, 0x65, 0x25};
//==============================================================================
//DO У׼����ָ��
const u8 DOCalibration[10] = {0x7E, 0x05, 0x00, 0x93, 0x00, 0x00, 0x00, 0x00, 0x58, 0xc8};
//==============================================================================
//Ŀ��帴λָ��
const u8 ResetTargetBoard[6] = {0x7e,0x01,0x00,0xc0,0xfb,0xfd};   
//==============================================================================
// Types
 typedef struct
{
	u16 rev_StrLen;
	u8 revData[COM_REVICE_MAXLEN];
} strUart;
strUart uart;

struct BB
{
	char Text1[40];	   char Text15[40];
	char Text2[40];	   char Text16[40];
	char Text3[40];	   char Text17[40];
	char Text4[40];	   char Text18[40];
	char Text5[40];	   char Text19[40];
	char Text6[40];	   char Text20[40];
	char Text7[40];	   char Text21[40];
	char Text8[40];	   char Text22[40];
	char Text9[40];	   char Text23[40];
	char Text10[40];   char Text24[40];
	char Text11[40];   char Text25[40];
	char Text12[40];   char Text26[40];
	char Text13[40];   char Text27[40];
	char Text14[40];   
}bb;

//==============================================================================
// Static global variables
static int timerId ,timerIdRec;
static int panelHandle = 0;
static int panelComConfig,panelHandleMain,panelHandleSelfTest,panelHandlePrint;
static int panelHandleSelfPrint,panelHandleWarning;
static int g_hcheckBmp 				= 0;
static int g_hxBmp                  = 0;
static int g_hsolidBmp              = 0;
static int g_hemptyBmp              = 0;
//static CAObjHandle objecthandle;  //���������
static CAObjHandle objectHandleTable;
static u8 errorDICount=0;  //DI ���Գ��ֵĴ������
static u8 errorDOCount=0;  //DO ���Գ��ֵĴ������
static u8 errorADCount=0;  //AD ���Գ��ֵĴ������
static u8 errorLoadCount=0;  //ͨ�� ���Գ��ֵĴ������
static u8 errorBeepCount = 0;//
//==============================================================================
// Static functions

//==============================================================================
// Global variables
int comSelect = 0;
int operation = 1;
int calibrateOperation = 0; //У׼�����Ƿ��
int indexAll = 1;   //΢����DI�����������
int indexMirocDo = 1;  //΢����DO�������
int indexMirocAD = 1;  //΢����AD��������
int sendFlag = 0;	  //�첽��ʱ���Ƿ���
int ActiveId = 1 ;	  //�첽��ʱ��ִ���ĸ�������Ŀ
float pfvalue = 1.0 ;   //������ʱ��ֵ
int showPROGRESSBAR = 0;//�Ƿ���ʾ������ʱ��ֵ
int selfTestContinue = 0;//�Ƿ������Լ���������
int OtherOperationIndex = 1;
u16 str16[10] = {0};//429ͨ�����Խ����ϵ��ַ�
u16 Micro_429_SendData_Flag = 0;//����429ͨ������Ƿ����û�������͵�����
int AutoSendValibrationFlag = 0;
static int processIndex = 0;	 //������ʵʱֵ
int printResult[27]={0};//�洢��ӡ��� 0:δ���ԣ�����  1:��ȷ 2������
int printResultIndex = 0;
const char *OperatrionMessage =
	"ע������:\n"
	"ÿ�ε��һ������,\n"
	"���������Ϻ�,\n"
	"���������'��λ'����\n" 
	"��ѡ����������.";
	
//==============================================================================
// Global functions
int CVICALLBACK asynchCB (int panel,int timeid ,int event ,void *callbackDatat, int eventData1,int eventData2);
int CVICALLBACK asynchCBRec (int panel,int timeid ,int event ,void *callbackDatat, int eventData1,int eventData2);

u16 sendConfigMessage(int index);  //΢����DI����
u16 sendMircoDOOutConfigMessage(int index); //΢����DO���
u16 sendMircoADInputConfigMessage(int index); //΢����AD����
int  analysis(u8 *p);  //����΢����DI��������
int showResult(u8 *p); //��ʾ΢����DI�������ս��
 
int analysisMicro_DO(u8 *p);
int showResultMicro_DO(u8 *p); //��ʾ΢����DO���ս��

int analysisMicro_DOCalibration(u8 *p);//DO У׼����

int analysisMicro_AD(u8 *p);
int showResultMicro_AD(u8 *p); //��ʾ΢����DO���ս��

int analysisMicro_429( u8 *p);//����429ͨ��
int analysisSelfTestType(u8 *p);//�����Լ�������
u16 MessgaeType(u8 *p);
u16 StrToHex(char *str,int strLen) ;//�ַ���ת16���ƺ���
u16 send429Road (int roadNum);//429ͨ���������ݲ���
int analysisRS232Test(u8 *p);//����RS232���Ե�����
int ReSend(int id,int sendType);//�ط�����
static void SetPowerOperationAccordance(int val);//���õ�Դ������ťһ��
u16 getADvalue(float v);//AD��������
/// HIFN The main entry-point function.
int main (int argc, char *argv[])
{
	int error = 0;
	
	/* initialize and load resources */
	nullChk (InitCVIRTE (0, argv, 0));
	errChk (panelHandleMain = LoadPanel (0, "TestCircuitWaferNew.uir", PANEL));  //������
	errChk (panelHandle = LoadPanel (0, "TestCircuitWaferNew.uir", PANEL_2));//΢������Խ���
	errChk (panelComConfig = LoadPanel (0, "TestCircuitWaferNew.uir", PANEL_3));  //�������ý���
	errChk (panelHandleSelfTest = LoadPanel (0, "TestCircuitWaferNew.uir", PANEL_4)); //�Լ����
	errChk (panelHandlePrint = LoadPanel (0, "TestCircuitWaferNew.uir", PANEL_5));  //��ӡ����
	errChk (panelHandleSelfPrint = LoadPanel (0, "TestCircuitWaferNew.uir", PANEL_6));  //��ӡ����
	errChk (panelHandleWarning = LoadPanel (0, "TestCircuitWaferNew.uir", PANEL_7));//��ʾ����
	//��ȡ��ӡ�б��б�ľ��
	GetObjHandleFromActiveXCtrl(panelHandlePrint,PANEL_5_REPORTX,&objectHandleTable);
	//���ؼ�ת���ɽ�����
	//ProgressBar = ProgressBar_Create(panelHandleMain,"������ʾ",418,
	ProgressBar_ConvertFromSlide(panelHandleMain,PANEL_NUMERICSLIDE);
	
	/*register asynchCB timer*/
	timerId = NewAsyncTimer (1.0,-1,0,asynchCB,NULL);
	timerIdRec = NewAsyncTimer (1.0,-1,0,asynchCBRec,NULL);
	
	if (GetBitmapFromFile ("ico/check.ico", &g_hcheckBmp) 
    	|| GetBitmapFromFile ("ico/x.ico", &g_hxBmp)
		|| GetBitmapFromFile ("ico/solid.ico", &g_hsolidBmp) 
	   	|| GetBitmapFromFile ("ico/empty.ico", &g_hemptyBmp))
    	{
    	goto Errors;
    	}
	//Open Com;ComValue = 3
	SetCtrlVal(panelComConfig,PANEL_3_OpenCom,1);
	OpenCom_callback(panelComConfig,PANEL_3_OpenCom,1,NULL,0,0);
	
	SetCtrlVal(panelHandleMain,PANEL_TEXTBOX,OperatrionMessage);
	/* display the panel and run the user interface */
	errChk (DisplayPanel (panelHandleMain));
	errChk (RunUserInterface ());

Error:
	/* clean up */
	if (panelHandleMain > 0)
		DiscardPanel (panelHandleMain);
	if (panelHandle > 0)
		DiscardPanel (panelHandle);
	if (panelComConfig > 0)
		DiscardPanel (panelComConfig);
	if (panelHandleSelfTest > 0)
		DiscardPanel (panelHandleSelfTest);
	if (panelHandlePrint > 0)
		DiscardPanel (panelHandlePrint);
	if (panelHandleSelfPrint > 0)
		DiscardPanel (panelHandleSelfPrint);
	if (panelHandleWarning > 0)
		DiscardPanel (panelHandleWarning);
	DiscardAsyncTimer (timerId);
	DiscardAsyncTimer (timerIdRec);
	return 0;
Errors:
	if (g_hcheckBmp)
		DiscardBitmap (g_hcheckBmp);
	if (g_hxBmp)
		DiscardBitmap (g_hxBmp);
	if (g_hsolidBmp)
		DiscardBitmap (g_hsolidBmp);
	if (g_hemptyBmp)
		DiscardBitmap (g_hemptyBmp);
	
    CloseCVIRTE ();
}


int CVICALLBACK PanelPrintCB (int panel, int event, void *callbackData,
							  int eventData1, int eventData2)
{
	int PanelHeight;
	int PanelWidth;
	switch (event)
	{
		case EVENT_PANEL_SIZING:
			GetPanelAttribute(panelHandlePrint,ATTR_HEIGHT,&PanelHeight);
			GetPanelAttribute(panelHandlePrint,ATTR_WIDTH,&PanelWidth);
			SetCtrlAttribute (panelHandlePrint, PANEL_5_REPORTX, ATTR_LEFT, 0);
			SetCtrlAttribute (panelHandlePrint, PANEL_5_REPORTX, ATTR_TOP, 24);
			SetCtrlAttribute (panelHandlePrint, PANEL_5_REPORTX, ATTR_HEIGHT, PanelHeight - 24);
			SetCtrlAttribute (panelHandlePrint, PANEL_5_REPORTX, ATTR_WIDTH, PanelWidth);

			break;
		case EVENT_CLOSE:
				HidePanel(panelHandlePrint);
				DisplayPanel(panelHandleMain);
			break;
		case EVENT_PANEL_SIZE:
			PanelPrintCB (panelHandlePrint, EVENT_PANEL_SIZING, 0,0,0);
			break;
	}
	return 0;
}

int CVICALLBACK CMD_SELF_TEST_AUTO_callback (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
		//	MessagePopup(
			break;
	}
	return 0;
}

//==============================================================================
// UI callback function prototypes

/// HIFN Exit when the user dismisses the panel.
int CVICALLBACK panelCB (int panel, int event, void *callbackData,
		int eventData1, int eventData2)
{
	if (event == EVENT_CLOSE)
		QuitUserInterface (0);
	return 0;
}

int CVICALLBACK CMD_RESET_MAIN_callback (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			DefaultCtrl(panelHandleMain,PANEL_BIN_POWER_OPRATION);
		//	DefaultPanel(panelHandleMain);
			//��λָ��
			CMD_RESET_callback (panelHandle, PANEL_2_CMD_RESET, 1,NULL,0,0);
			
			//У׼��λ
			CMD_RESET_CALIBRATION_callback (panelHandleSelfTest, PANEL_4_CMD_RESET_CALIBRATION, 1,NULL,0,0);
			//�ر��첽��ʱ��
			SetAsyncTimerAttribute (timerId, ASYNC_ATTR_ENABLED, 0);
		//	SetAsyncTimerAttribute (timerIdRec, ASYNC_ATTR_ENABLED, 0);
			//��ս�������
			memset(uart.revData,0,COM_REVICE_MAXLEN);
			
			showPROGRESSBAR = 0; 
			for(int i= 8 ;i<=10;i++)
			{
				SetCtrlAttribute(panel,i,ATTR_OFF_COLOR,VAL_BLACK);
				SetCtrlVal(panel,i,0);
				SetCtrlAttribute(panelHandleMain,i,ATTR_VISIBLE,0);	
			}
			ProgressBar_SetPercentage(panelHandleMain,PANEL_NUMERICSLIDE,0.0,"��ǰ���� 0%");

		/*	SetCtrlAttribute(panel,PANEL_LED,ATTR_OFF_COLOR,VAL_BLACK);
			SetCtrlVal(panel,PANEL_LED,0);
			SetCtrlAttribute(panel,PANEL_LED_2,ATTR_OFF_COLOR,VAL_BLACK);
			SetCtrlVal(panel,PANEL_LED_2,0);
			SetCtrlAttribute(panel,PANEL_LED_3,ATTR_OFF_COLOR,VAL_BLACK);
			SetCtrlVal(panel,PANEL_LED_3,0);
		  	SetCtrlAttribute(panelHandleMain,PANEL_LED,ATTR_VISIBLE,0);
		    SetCtrlAttribute(panelHandleMain,PANEL_LED_2,ATTR_VISIBLE,0); 
		    SetCtrlAttribute(panelHandleMain,PANEL_LED_3,ATTR_VISIBLE,0); */
			
			
			
			
		/*	DefaultCtrl(panelHandle,PANEL_2_TABLE_2);
			DefaultCtrl(panelHandle,PANEL_2_TABLE);
			DefaultCtrl(panelHandle,PANEL_2_TABLE_4);  */
		/*	SetTableCellRangeAttribute(panelHandle,PANEL_2_TABLE_2,VAL_TABLE_COLUMN_RANGE(3),ATTR_CTRL_VAL,0);
			SetTableCellRangeAttribute(panelHandle,PANEL_2_TABLE_2,VAL_TABLE_COLUMN_RANGE(4),ATTR_CTRL_VAL,0);
			SetTableCellRangeAttribute(panelHandle,PANEL_2_TABLE_2,VAL_TABLE_COLUMN_RANGE(5),ATTR_CTRL_VAL,0);
			
			SetTableCellRangeAttribute(panelHandle,PANEL_2_TABLE,VAL_TABLE_COLUMN_RANGE(3),ATTR_CTRL_VAL,0);
			SetTableCellRangeAttribute(panelHandle,PANEL_2_TABLE,VAL_TABLE_COLUMN_RANGE(4),ATTR_CTRL_VAL,0);
			SetTableCellRangeAttribute(panelHandle,PANEL_2_TABLE,VAL_TABLE_COLUMN_RANGE(5),ATTR_CTRL_VAL,0);
			
			SetTableCellRangeAttribute(panelHandle,PANEL_2_TABLE_4,VAL_TABLE_COLUMN_RANGE(3),ATTR_CTRL_VAL,0.0);
			SetTableCellRangeAttribute(panelHandle,PANEL_2_TABLE_4,VAL_TABLE_COLUMN_RANGE(4),ATTR_CTRL_VAL,0.0);
			SetTableCellRangeAttribute(panelHandle,PANEL_2_TABLE_4,VAL_TABLE_COLUMN_RANGE(5),ATTR_CTRL_VAL,0);  */ 
			
		//	MSComctlLib_IProgressBarSetControlDefault(objecthandle,NULL,0.0); 

		 //  SetCtrlAttribute(panelHandleMain,PANEL_3_PROGRESSBAR,ATTR_VISIBLE,0);  
			
			break;
	}
	return 0;
}

int CVICALLBACK CMD_QUIT_MAIN_callback (int panel, int control, int event,
										void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			//���Ͷϵ�ָ��
			ComWrt(comSelect,DownPower,7);
			Sleep(2);
			//��λָ��
			CMD_RESET_callback (panelHandle, PANEL_2_CMD_RESET, 1,NULL,0,0);
			//�ر��첽��ʱ��
			SetAsyncTimerAttribute (timerId, ASYNC_ATTR_ENABLED, 0);
			SetAsyncTimerAttribute (timerIdRec, ASYNC_ATTR_ENABLED, 0);
			
			DiscardAsyncTimer (timerId);
			DiscardAsyncTimer (timerIdRec);
			//��ս�������
			memset(uart.revData,0,COM_REVICE_MAXLEN);
			//�رմ���,��մ���
			if(comSelect>0)
			{
				FlushInQ(comSelect);
				FlushOutQ(comSelect);
				CloseCom(comSelect);
			}
			
			showPROGRESSBAR = 0;
			QuitUserInterface(0);
			break;
	}
	return 0;
}

int CVICALLBACK CMD_ALL_RUN_callback (int panel, int control, int event,
									  void *callbackData, int eventData1, int eventData2)
{
	static int i= 0;
	int val = 0;
	switch (event)
	{
		case EVENT_COMMIT:
			calibrateOperation = 0; 
		//	CMD_RESET_callback (panelHandle,PANEL_2_CMD_RESET, 1,NULL,0,0);
		//	Sleep(200);
			GetCtrlVal(panelHandleMain,PANEL_BIN_POWER_OPRATION,&val);
			if(val ==0)
			{
				SetCtrlVal(panelHandleMain,PANEL_BIN_POWER_OPRATION,1);
				BIN_POWER_OPRATION_callback (panelHandleMain,PANEL_BIN_POWER_OPRATION,1,NULL,0,0);
			}
		   showPROGRESSBAR = 1;
		   processIndex = 1;
		   Sleep(1000);
		   SetAsyncTimerAttribute (timerId, ASYNC_ATTR_ENABLED, 1);
		   SetAsyncTimerAttribute (timerId, ASYNC_ATTR_INTERVAL, 0.5);
		   sendFlag = 0;
		   AutoSendValibrationFlag = 1;
		   ActiveId = 1;
		  // MSComctlLib_IProgressBarSetMin(objecthandle,NULL,0.0);
		  // MSComctlLib_IProgressBarSetMax(objecthandle,NULL,20.0);
		  ProgressBar_SetPercentage(panelHandleMain,PANEL_NUMERICSLIDE,0.0,"��ǰ���� 0%");
		   for(int i= 8 ;i<=10;i++)
			{
				SetCtrlAttribute(panel,i,ATTR_OFF_COLOR,VAL_BLACK);
				SetCtrlVal(panel,i,0);
				SetCtrlAttribute(panelHandleMain,i,ATTR_VISIBLE,1);	
			}
		   
		//   SetCtrlAttribute(panelHandleMain,PANEL_PROGRESSBAR,ATTR_VISIBLE,1);
		
			break;
	}
	return 0;
}

int CVICALLBACK CMD_GO_TEST_UI_callback (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			calibrateOperation = 0;
			HidePanel(panelHandleMain);
			DisplayPanel(panelHandle);
			break;
	}
	return 0;
}

int CVICALLBACK CMD_SELF_TEST_callback (int panel, int control, int event,
										void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
		   HidePanel(panelHandleMain);
			DisplayPanel(panelHandleSelfTest);
			break;
	}
	return 0;
}

int CVICALLBACK MircoDIInputTable (int panel, int control, int event,
								   void *callbackData, int eventData1, int eventData2)
{
	Point focus;
	u8 buff[10];
	switch (event)
	{
		case EVENT_COMMIT:
			errorDICount=0;
			showPROGRESSBAR = 0;
		   memset(buff,0,10);
		   GetActiveTableCell (panel, control, &focus);
		   if (focus.x == BUTTON_COLUMN)
			{
		
				indexAll = focus.y;
			 
				sendConfigMessage(indexAll);
			
			} 
	
			break;
	}
	return 0;
}

int CVICALLBACK MircoDOOut (int panel, int control, int event,
							void *callbackData, int eventData1, int eventData2)
{
	Point focus;
	u8 buff[10];
	switch (event)
	{
		case EVENT_COMMIT:
			errorDOCount=0;
			showPROGRESSBAR = 0; 
			memset(buff,0,10);
		   GetActiveTableCell (panel, control, &focus);
		   if (focus.x == BUTTON_COLUMN)
			{
				indexMirocDo = focus.y ;
				sendMircoDOOutConfigMessage(indexMirocDo);
			}
			break;
	}
	return 0;
}

int CVICALLBACK MircoADInput (int panel, int control, int event,
							  void *callbackData, int eventData1, int eventData2)
{
	Point focus;
	u8 buff[10];
	
	switch (event)
	{
		case EVENT_COMMIT:
			errorADCount = 0;
		   showPROGRESSBAR = 0; 
		   memset(buff,0,10);
		   GetActiveTableCell (panel, control, &focus);
		   if (focus.x == BUTTON_COLUMN)
			{
				indexMirocAD = focus.y ;
				sendMircoADInputConfigMessage(indexMirocAD);		 
			}
			break;
	}
	return 0;
}

int CVICALLBACK Miroc_429_Road_1_Test_callback (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
    u8 sendBuff[11] = {0};
	u16 res = 0;
	sendBuff[0] = HOST_PAKAGE_HEAD;sendBuff[1] = 0x06;sendBuff[2] = 0x00;sendBuff[3] = CMD_429_Road_TEST;
	sendBuff[4] = 0x00;sendBuff[5] = 0x02;sendBuff[6] = 0x00;sendBuff[7] = 0x00;sendBuff[8] = 0x00;
	switch (event)
	{
		case EVENT_COMMIT:
			Micro_429_SendData_Flag = 0;
			
			res = GetCRC16(sendBuff+3,6);
				sendBuff[9]=(res&0x00ff);
				sendBuff[10]= ((res&0xff00)>>8);
	
				if(comSelect > 0)
					ComWrt(comSelect,sendBuff,11);
			break;
	}
	return 0;
}

int CVICALLBACK Miroc_429_Road_2_Test_callback (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	u8 sendBuff[11] = {0};
	u16 res = 0;
	sendBuff[0] = HOST_PAKAGE_HEAD;sendBuff[1] = 0x06;sendBuff[2] = 0x00;sendBuff[3] = CMD_429_Road_TEST;
	sendBuff[4] = 0x01;sendBuff[5] = 0x02;sendBuff[6] = 0x00;sendBuff[7] = 0x00;sendBuff[8] = 0x00;
	switch (event)												 
	{
		case EVENT_COMMIT:
				Micro_429_SendData_Flag = 0; 
				res = GetCRC16(sendBuff+3,6);
				sendBuff[9]=(res&0x00ff);
				sendBuff[10]= ((res&0xff00)>>8);
	
				if(comSelect > 0)
					ComWrt(comSelect,sendBuff,11);
	
				
			break;
	}
	return 0;
}

int CVICALLBACK Miroc_429_Road_3_Test_callback (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	u8 sendBuff[11] = {0};
	u16 res = 0;
	sendBuff[0] = HOST_PAKAGE_HEAD;sendBuff[1] = 0x06;sendBuff[2] = 0x00;sendBuff[3] = CMD_429_Road_TEST;
	sendBuff[4] = 0x02;sendBuff[5] = 0x02;sendBuff[6] = 0x00;sendBuff[7] = 0x00;sendBuff[8] = 0x00;
	switch (event)												 
	{
		case EVENT_COMMIT:
				Micro_429_SendData_Flag = 0; 
				res = GetCRC16(sendBuff+3,6);
				sendBuff[9]=(res&0x00ff);
				sendBuff[10]= ((res&0xff00)>>8);
	
				if(comSelect > 0)
					ComWrt(comSelect,sendBuff,11);
	
				
			break;
	}
	return 0;
}

int CVICALLBACK CMD_RS232_TEST_callback (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			 if(comSelect > 0)
				 ComWrt(comSelect,RS232TestCMD,9);
			break;
	}
	return 0;
}
//RS232 ����ͨѶ���Խ���
int analysisRS232Test(u8 *p)
{
	for(int i = 1 ;i <= 3;i++)
	{
		if(*(p + i) != RS232TestCMDReslut[i-1] )
		{
			SetCtrlAttribute(panelHandle,PANEL_2_LED_2,ATTR_OFF_COLOR,VAL_RED);
			printResult[23] = 2; 
			ActiveId = 6;
			sendFlag = 0;
			return 0;
		}
	}
	 SetCtrlAttribute(panelHandle,PANEL_2_LED_2,ATTR_ON_COLOR,VAL_GREEN); 
	 SetCtrlVal(panelHandle,PANEL_2_LED_2,1);
	 printResult[23] = 1; 
	//һ�������õ�
	sendFlag = 0;
	ActiveId = 6;  
	return 0;
		
}
//429���ԣ�����ͨ�����Ժͷ������ݲ��ԣ�
int analysisMicro_429( u8 *p)  
{
	char rev[20];
	char chr[1024]={""};
	unsigned int data=0;
	
	if(errorLoadCount<5)
	{
		if((*(p +1 )==0xFF)&&(*(p+2)==0xFF)&&(*(p+3)==0xFF)&&(*(p+4)==0xFF))
		{
			 errorLoadCount++;
			 if(sendFlag == 1)
			 {
				 sendFlag=0;
		//	 	 SetCtrlVal(panelHandleMain,PANEL_NUMERIC,errorDICount);
			     return 0;
			 }
		}
		else
		{
			errorLoadCount=0;
		}
	}

	switch (*p)
	{
		case 0x00:
			if(Micro_429_SendData_Flag ==0)
			{
				//��һ�������ж�
				for(int i = 1; i <= 4 ; i++)
				{
					if(*(p + i) != result[i-1])
					{
						SetCtrlAttribute(panelHandle,PANEL_2_LED,ATTR_OFF_COLOR,VAL_RED);
						SetCtrlVal(panelHandle,PANEL_2_LED,0);
						printResult[20] = 2; 
						sendFlag = 0;
						return 0;
					}
				}
				SetCtrlAttribute(panelHandle,PANEL_2_LED,ATTR_ON_COLOR,VAL_GREEN);
				SetCtrlVal(panelHandle,PANEL_2_LED,1);
				printResult[20] = 1;
			}
			else
			{
				
				data=0;
				for(int i = 4; i >0 ; i--)
				{
					data=(data<<8)+ (*(p + i ));
					
				}   
				
				data=0x040000-data&0x03FFFF;
				
				for(int i=0;i<4;i++)
				{   
					sprintf(rev,"%02x ",(data>>(8*(3-i)))&0xFF);
					strcat(chr,rev);	
				}
				
				//sprintf(rev,"%08x ",(0x040000-data));
				//strcat(chr,rev);				 
								 
				strcat(chr,"\n");
				SetCtrlAttribute(panelHandle,PANEL_2_TEXTBOX_3,ATTR_CTRL_VAL,chr);
			}
			
			break;
		case 0x01:
			if(Micro_429_SendData_Flag ==0)
			{

				//��һ�������ж�
				for(int i = 1; i <= 4 ; i++)
				{
					if(*(p + i) != result[i-1])
					{
						SetCtrlAttribute(panelHandle,PANEL_2_LED_4,ATTR_OFF_COLOR,VAL_RED);
						SetCtrlVal(panelHandle,PANEL_2_LED_4,0);
						printResult[21] = 2; 
						sendFlag = 0;
						return 0;
					}
				}
				SetCtrlAttribute(panelHandle,PANEL_2_LED_4,ATTR_ON_COLOR,VAL_GREEN);
				SetCtrlVal(panelHandle,PANEL_2_LED_4,1);
				printResult[21] = 1; 
			}
			else
			{
				
				data=0;
				for(int i = 4; i >0 ; i--)
				{
					data=(data<<8)+ (*(p + i ));
					
				}   
				
				data=0x040000-data&0x03FFFF;
				
				for(int i=0;i<4;i++)
				{   
					sprintf(rev,"%02x ",(data>>(8*(3-i)))&0xFF);
					strcat(chr,rev);	
				}
				
				/*for(int i = 1; i <=4 ; i++)
				{
					sprintf(rev,"%02x ",*(p + i));
					strcat(chr,rev);
				}*/
				
				
				strcat(chr,"\n");
				SetCtrlAttribute(panelHandle,PANEL_2_TEXTBOX_4,ATTR_CTRL_VAL,chr);
			}

			break;
		case 0x02:
			if(Micro_429_SendData_Flag ==0)
			{

				//��һ�������ж�
				for(int i = 1; i <= 4 ; i++)
				{
					if(*(p + i) != result[i-1])
					{
						SetCtrlAttribute(panelHandle,PANEL_2_LED_6,ATTR_OFF_COLOR,VAL_RED);
						SetCtrlVal(panelHandle,PANEL_2_LED_6,0);
						printResult[22] = 2; 
						ActiveId = 5; 
						sendFlag = 0;
						return 0;
					}
				}
				SetCtrlAttribute(panelHandle,PANEL_2_LED_6,ATTR_ON_COLOR,VAL_GREEN);
				SetCtrlVal(panelHandle,PANEL_2_LED_6,1);
				printResult[22] = 1; 
			}
			else
			{
				data=0;
				for(int i = 4; i >0 ; i--)
				{
					data=(data<<8)+ (*(p + i ));
					
				}   
				
				data=0x040000-data&0x03FFFF;
				
				for(int i=0;i<4;i++)
				{   
					sprintf(rev,"%02x ",(data>>(8*(3-i)))&0xFF);
					strcat(chr,rev);	
				}
				
				/*for(int i = 1; i <=4 ; i++)
				{
					sprintf(rev,"%02x ",*(p + i));
					strcat(chr,rev);
				}*/
				
				strcat(chr,"\n");
				SetCtrlAttribute(panelHandle,PANEL_2_TEXTBOX_5,ATTR_CTRL_VAL,chr);
			}
			ActiveId = 5;     
			break;
	}
	//����һ�����Ե�ʱ���õ�
	sendFlag = 0;
	return 0;
}
int CVICALLBACK COMMANDBUTTON_6_callback (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
		   HidePanel(panelHandle);
		   DisplayPanel(panelComConfig);
			break;
	}
	return 0;
}

int CVICALLBACK CMD_BEEP_callback (int panel, int control, int event,
								   void *callbackData, int eventData1, int eventData2)
{
	int val = 0;
	switch (event)
	{
		case EVENT_COMMIT:
	
				if(comSelect > 0)
					ComWrt(comSelect,BeepIntermittent,10);
				
				val = ConfirmPopup("���������","�Ƿ���������������ʾ��");
				if(val == 1)//��������
				{
					ComWrt(comSelect,BeepContinue,10);//����������
					Sleep(5);
					val = ConfirmPopup("���������","�Ƿ���������������ʾ��");
					if(val == 1)	 //��������
					{
						ComWrt(comSelect,BeepClose,10);       
						SetCtrlAttribute(panelHandle,PANEL_2_LED_7,ATTR_ON_COLOR,VAL_GREEN);		
						SetCtrlVal(panelHandle,PANEL_2_LED_7,1);
						printResult[24] = 1;  
					}
					else		 //û������������
					{
						 ComWrt(comSelect,BeepClose,10);
						 SetCtrlAttribute(panelHandle,PANEL_2_LED_7,ATTR_OFF_COLOR,VAL_RED);
						 printResult[24] = 2; 
					}
					
				}
				else   //û������������ 
				{
					ComWrt(comSelect,BeepClose,10);
					SetCtrlAttribute(panelHandle,PANEL_2_LED_7,ATTR_OFF_COLOR,VAL_RED);
					printResult[24] = 2; 
				}
				if(sendFlag == 1)
				{
					ComWrt(comSelect,DownPower,7);
					//SetCtrlVal(panelHandleMain,PANEL_BIN_POWER_OPRATION,0);
					//SetCtrlVal(panelHandle,PANEL_2_BIN_POWER_UI,0);
					//SetCtrlVal(panelHandleSelfTest,PANEL_4_BIN_OPERATION_POWER_C,0);
					SetPowerOperationAccordance(0);
					SetAsyncTimerAttribute (timerId, ASYNC_ATTR_ENABLED, 0);
					DisplayPanel(panelHandleWarning);
				}
			break;
	}
	return 0;
}

int CVICALLBACK CMD_PRINT_callback (int panel, int control, int event,
									void *callbackData, int eventData1, int eventData2)
{
	char path[MAX_PATHNAME_LEN];
	switch (event)
	{
		case EVENT_COMMIT:
			HidePanel(panelHandle);
			 
			DisplayPanel(panelHandlePrint);
		    GetProjectDir(path);
			strcat(path,"/printModel/FK90.rpxe");
			ReportProj1_IReportXOpenReport (objectHandleTable, NULL, path);
			for(int i =0 ; i< 27;i++)
			{
				if(printResult[i] == 1)
				{
					ReportProj1_IReportXSetCellValue(objectHandleTable,NULL,7,6+i,"��ȷ");	
				}
				else if(printResult[i] == 2)
				{
					ReportProj1_IReportXSetCellValue(objectHandleTable,NULL,7,6+i,"����");
				}
				else
				{
					ReportProj1_IReportXSetCellValue(objectHandleTable,NULL,7,6+i," ");
					
				}
			}
			//ReportProj1_IReportXSetCellValue(objectHandleTable,NULL,7,6,"��ȷ");	
			break;
	}
	return 0;
}

int CVICALLBACK CMD_RESET_callback (int panel, int control, int event,
									void *callbackData, int eventData1, int eventData2)
{
	
	switch (event)
	{
		case EVENT_COMMIT:
			
			ComWrt(comSelect,DownPower,7);
		   // if(comSelect > 0)
		//			ComWrt(comSelect,sendBuff,6);
			 DefaultPanel(panelHandle);
			// DefaultCtrl(panel,PANEL_2_TABLE_2);
			SetTableCellRangeAttribute(panelHandle,PANEL_2_TABLE_2,VAL_TABLE_COLUMN_RANGE(3),ATTR_CTRL_VAL,0);
			SetTableCellRangeAttribute(panelHandle,PANEL_2_TABLE_2,VAL_TABLE_COLUMN_RANGE(4),ATTR_CTRL_VAL,0);
			SetTableCellRangeAttribute(panelHandle,PANEL_2_TABLE_2,VAL_TABLE_COLUMN_RANGE(5),ATTR_CTRL_VAL,0);
			
			SetTableCellRangeAttribute(panelHandle,PANEL_2_TABLE,VAL_TABLE_COLUMN_RANGE(3),ATTR_CTRL_VAL,0);
			SetTableCellRangeAttribute(panelHandle,PANEL_2_TABLE,VAL_TABLE_COLUMN_RANGE(4),ATTR_CTRL_VAL,0);
			SetTableCellRangeAttribute(panelHandle,PANEL_2_TABLE,VAL_TABLE_COLUMN_RANGE(5),ATTR_CTRL_VAL,0);
			
			SetTableCellRangeAttribute(panelHandle,PANEL_2_TABLE_4,VAL_TABLE_COLUMN_RANGE(3),ATTR_CTRL_VAL,0.0);
			SetTableCellRangeAttribute(panelHandle,PANEL_2_TABLE_4,VAL_TABLE_COLUMN_RANGE(4),ATTR_CTRL_VAL,0.0);
			SetTableCellRangeAttribute(panelHandle,PANEL_2_TABLE_4,VAL_TABLE_COLUMN_RANGE(5),ATTR_CTRL_VAL,0);  
			
			 //Reset LEDs
			SetCtrlAttribute(panelHandle,PANEL_2_LED,ATTR_OFF_COLOR,VAL_BLACK);
			SetCtrlVal(panelHandle,PANEL_2_LED,0);
			SetCtrlAttribute(panelHandle,PANEL_2_LED_4,ATTR_OFF_COLOR,VAL_BLACK);
			SetCtrlVal(panelHandle,PANEL_2_LED_4,0);
			SetCtrlAttribute(panelHandle,PANEL_2_LED_6,ATTR_OFF_COLOR,VAL_BLACK);
			SetCtrlVal(panelHandle,PANEL_2_LED_6,0);
			SetCtrlAttribute(panelHandle,PANEL_2_LED_2,ATTR_OFF_COLOR,VAL_BLACK);
			SetCtrlVal(panelHandle,PANEL_2_LED_4,0);
			SetCtrlAttribute(panelHandle,PANEL_2_LED_7,ATTR_OFF_COLOR,VAL_BLACK);
			SetCtrlVal(panelHandle,PANEL_2_LED_7,0);
			SetCtrlAttribute(panelHandle,PANEL_2_LED_8,ATTR_OFF_COLOR,VAL_BLACK);
			SetCtrlVal(panelHandle,PANEL_2_LED_8,0);
			SetCtrlAttribute(panelHandle,PANEL_2_LED_9,ATTR_OFF_COLOR,VAL_BLACK);
			SetCtrlVal(panelHandle,PANEL_2_LED_9,0);
			
			//Reset Flags
			 operation = 1;
			 calibrateOperation = 0; 
			 indexAll = 1;   
			 indexMirocDo = 1;  
			 indexMirocAD = 1;  
			 sendFlag = 0;	  
			 ActiveId = 0 ;	  
			 pfvalue = 1.0 ;   
			 showPROGRESSBAR = 0;
			 selfTestContinue = 0;
			 OtherOperationIndex = 1;
			 
			 errorDICount=0;  //DI ���Գ��ֵĴ������
			 errorDOCount=0;  //DO ���Գ��ֵĴ������
			 errorADCount=0;  //AD ���Գ��ֵĴ������
			 errorLoadCount=0;  //ͨ�� ���Գ��ֵĴ������
			 //Stop AsyncTimer
			 SetAsyncTimerAttribute (timerId, ASYNC_ATTR_ENABLED, 0);
			 //Reset RevBuff
			 memset(uart.revData,0, COM_REVICE_MAXLEN);
			 FlushInQ(comSelect);
			 FlushOutQ(comSelect);
			 break;
	}
	return 0;
}

int CVICALLBACK CMD_MAIN_QUIT_callback (int panel, int control, int event,
										void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			
			CMD_RESET_callback (panel,PANEL_2_CMD_RESET, 1,NULL,0,0);
									
			
			//���Ͷϵ�ָ��
			ComWrt(comSelect,DownPower,7);
			Sleep(2);
			SetCtrlVal(panelHandle,PANEL_2_BIN_POWER_UI,0);
			SetCtrlVal(panelHandleMain,PANEL_BIN_POWER_OPRATION,0);
			SetCtrlVal(panelHandleSelfTest,PANEL_4_BIN_OPERATION_POWER_C,0);
			
			HidePanel(panelHandle);
			DisplayPanel(panelHandleMain);
			break;
	}
	return 0;
}

int CVICALLBACK Mir_429_All_Self_Test_callback (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	
	switch (event)
	{
		case EVENT_COMMIT:
		   if(comSelect > 0)
					ComWrt(comSelect,Miro429AllSelfTestSend,6);
		    
			break;
		
			
	}
	return 0;
}

int CVICALLBACK CMD_Mirco_AD_ALL_SELF_callback (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			if(comSelect > 0)
				ComWrt(comSelect,MiroADAllSelfTestSend,6);
			
			break;
	}
	return 0;
}

int CVICALLBACK CMD_SELE_RETURN_MAIN_callback (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			HidePanel(panelHandleSelfTest);
			DisplayPanel(panelHandleMain);
			break;
	}
	return 0;
}

int CVICALLBACK CMD_429_ROAD_1_SEND_callback (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
/*	char str[12] = {""};
	int lenStr = 0;
	int i = 0;
	int j = 0;
	int status = 1;
    u8 sendBuff[11] = {0};
	u16 res = 0;
	sendBuff[0] = HOST_PAKAGE_HEAD;sendBuff[1] = 0x06;sendBuff[2] = 0x00;sendBuff[3] = CMD_429_Road_TEST;
	sendBuff[4] = 0x00;sendBuff[5] = 0x02;sendBuff[6] = 0x00;sendBuff[7] = 0x00;sendBuff[8] = 0x00;*/
	switch (event)
	{
		case EVENT_COMMIT:
			Micro_429_SendData_Flag = 1;
			send429Road (1);
		/*	GetCtrlVal(panelHandle,PANEL_2_STRING_3,str);
			lenStr = strlen(str);
			StrToHex(str,lenStr);
			for(int i = 0;i <= 3 ;i++)
			sendBuff[i + 5] = str16[i];
			res = GetCRC16(sendBuff+3,6);
				sendBuff[9]=(res&0x00ff);
				sendBuff[10]= ((res&0xff00)>>8);
	
				if(comSelect > 0)
					ComWrt(comSelect,sendBuff,11);
			 */
			break;
	}
	return 0;
}
u16 send429Road (int roadNum)
{
	char str[12] = {""};
	int lenStr = 0;
    u8 sendBuff[11] = {0};
	u16 res = 0;
	sendBuff[0] = HOST_PAKAGE_HEAD;sendBuff[1] = 0x06;sendBuff[2] = 0x00;sendBuff[3] = CMD_429_Road_TEST;
	sendBuff[4] = 0x00;sendBuff[5] = 0x02;sendBuff[6] = 0x00;sendBuff[7] = 0x00;sendBuff[8] = 0x00;
	
	switch (roadNum)
	{
		case 1:
			GetCtrlVal(panelHandle,PANEL_2_STRING_3,str);
			lenStr = strlen(str);
			StrToHex(str,lenStr);
			
			break;
		case 2:
			sendBuff[4] = 0x01;
			GetCtrlVal(panelHandle,PANEL_2_STRING_4,str);
			lenStr = strlen(str);
			StrToHex(str,lenStr);
			break;
		case 3:
			sendBuff[4] = 0x02;
			GetCtrlVal(panelHandle,PANEL_2_STRING_5,str);
			lenStr = strlen(str);
			StrToHex(str,lenStr);
			
			break;
	}
	for(int i = 0;i <= 3 ;i++)
		sendBuff[i + 5] = str16[3-i];
	
		sendBuff[8] =0x00;
		sendBuff[7] &=0x3F;
		
	
	res = GetCRC16(sendBuff+3,6);
		sendBuff[9]=(res&0x00ff);
		sendBuff[10]= ((res&0xff00)>>8);

		if(comSelect > 0)
			ComWrt(comSelect,sendBuff,11);
	
	 return 0;
	
}
int CVICALLBACK CMD_429_ROAD_3_SEND_callback (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			Micro_429_SendData_Flag = 1;
			
			send429Road (3);
			break;
	}
	return 0;
}

int CVICALLBACK CMD_429_ROAD_2_SEND_callback (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			Micro_429_SendData_Flag = 1;
			
		    send429Road (2);
			break;
	}
	return 0;
}

u16  StrToHex(char *str,int strLen)
{
	int i = 0;
	int j = 0;
	int status = 1;
	
	u8 tempStr16[4] = {0};
	memset(str16,0,10);
	for(i,j; i < strLen ; i++)
	{
		if(str[i] !=' ')
		{
			switch(status)
			{
				case 1:
					tempStr16[0] = str[i];
					status = 2;
					break;
				case 2:
					tempStr16[1] = str[i];
					Fmt(&str16[j],"%x<%s",tempStr16);
					
					j++;
					status = 1;
					break;
			}
		}
	}
	return 0;
}
int CVICALLBACK OpenCom_callback (int panel, int control, int event,
								  void *callbackData, int eventData1, int eventData2)
{
	int ComStatus,Openstatus;
	int ComValue,BtlValue,jyValue,DataValue,StopValue;
    switch (event)
	{
		case EVENT_COMMIT:
			GetCtrlVal(panel,7,&ComStatus);
			if(ComStatus)
			{
				GetCtrlVal(panel,6,&ComValue);	
				GetCtrlVal(panel,5,&BtlValue);	
				GetCtrlVal(panel,4,&jyValue);	
				GetCtrlVal(panel,3,&DataValue);	
				GetCtrlVal(panel,2,&StopValue);
				DisableBreakOnLibraryErrors();
				
			//	Openstatus = OpenComConfig(eventData1,"",BtlValue,jyValue,DataValue,StopValue,COM_REVICE_MAXLEN,COM_REVICE_MAXLEN);
				Openstatus = OpenComConfig(ComValue,"",BtlValue,jyValue,DataValue,StopValue,COM_REVICE_MAXLEN,COM_REVICE_MAXLEN);
				comSelect = ComValue;
				SetComTime(comSelect,1.0);
				EnableBreakOnLibraryErrors();
				if(Openstatus < 0)
				{
					MessagePopup("warning","Com Open failed");
					return 0;
				}
				
				SetCTSMode(comSelect,LWRS_HWHANDSHAKE_OFF);
				FlushInQ(comSelect);
				FlushOutQ(comSelect);
		
				SetAsyncTimerAttribute (timerIdRec, ASYNC_ATTR_ENABLED, 1);
				SetAsyncTimerAttribute (timerIdRec, ASYNC_ATTR_INTERVAL, 0.01);  
			
				SetCtrlVal(panel,PANEL_3_LED,1);
			}
			else
			{
				DisableBreakOnLibraryErrors();
				CloseCom(comSelect);
				MessagePopup("slogan","Com Closed");
				SetCtrlVal(panel,PANEL_3_LED,0);
	
			}
			break;
	}
	return 0;
}

int CVICALLBACK CMD_COM_RETURN_MAIN_callback (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			HidePanel(panelComConfig);
			DisplayPanel(panelHandle);
			break;
	}
	return 0;
}
int CVICALLBACK asynchCB (int panel,int timeid ,int event ,void *callbackDatat, int eventData1,int eventData2)
{
//	static int processIndex = 1;
	char label[20];
	char str[20];
	/*������������*/

	//΢����DI�������
	if(sendFlag == 0 && ActiveId == 1)
	{

		sendConfigMessage(indexAll);
		sendFlag = 1;
	}

	//΢����DO�������
	if(sendFlag == 0 && ActiveId == 2)
	{
		sendMircoDOOutConfigMessage(indexMirocDo) ;
		sendFlag = 1;
	}
	//΢����AD�������
	if(sendFlag == 0 && ActiveId == 3)
	{
		sendMircoADInputConfigMessage(indexMirocAD);
		sendFlag = 1;
	}
	//΢����429ͨ�����Ժ��շ�����

	if(sendFlag == 0 && ActiveId == 4)
	{
		switch (OtherOperationIndex)
		{
			case 1:
				//429ͨ�� 1 ���
				Miroc_429_Road_1_Test_callback (panelHandle, PANEL_2_Miroc_429_Road_1_Test,
												1,NULL,0,0);
				sendFlag = 1;
				break;
		/*	case 2:
				//429 ͨ�� 1 �շ�����
				CMD_429_ROAD_1_SEND_callback (panelHandle, PANEL_2_CMD_429_ROAD_2_SEND,
											  1,NULL,0,0);
				sendFlag = 1;
				break;*/
			case 2:
				Miroc_429_Road_2_Test_callback (panelHandle, PANEL_2_Miroc_429_Road_2_Test,
												1,NULL,0,0);
				sendFlag = 1;
				break;
		/*	case 4:
				//429 ͨ�� 2 �շ�����
				CMD_429_ROAD_2_SEND_callback (panelHandle, PANEL_2_CMD_429_ROAD_3_SEND,
											  1,NULL,0,0);
				sendFlag = 1;
				break;*/
			case 3:

				//429ͨ�� 3 ���
				Miroc_429_Road_3_Test_callback (panelHandle, PANEL_2_Miroc_429_Road_3_Test,
												1,NULL,0,0);
				sendFlag = 1;
				break;
		/*	case 6:
				//429 ͨ�� 3 �շ�����
				CMD_429_ROAD_3_SEND_callback (panelHandle, PANEL_2_CMD_429_ROAD_1_SEND,
											  1,NULL,0,0);
				sendFlag = 1;
				break;*/
		}
		OtherOperationIndex++;
		if(OtherOperationIndex >3)
		{
			OtherOperationIndex = 1;
		}
	}

	//RS232 ����
	if(sendFlag == 0 && ActiveId == 5)
	{

		CMD_RS232_TEST_callback (panelHandle, PANEL_2_CMD_RS232_TEST, 1,
								 NULL,0,0);
		sendFlag = 1;
	}
	//����������
	if(sendFlag == 0 && ActiveId == 6)
	{
		sendFlag = 1;
		CMD_BEEP_callback (panelHandle, PANEL_2_CMD_BEEP, 1,
						   NULL, 0, 0);

	}
	/*�Լ���������*/
	/*if(sendFlag == 0 && i == 1 &&selfTestContinue == 1)
	{
		Mir_429_All_Self_Test_callback (panelHandleSelfTest, PANEL_4_Mir_429_All_Self_Test, 1,NULL,0,0);
		i++;
	}
	if(sendFlag == 0 && i == 2 &&selfTestContinue == 1)
	{
		CMD_Mirco_AD_ALL_SELF_callback (panelHandleSelfTest, PANEL_4_CMD_Mirco_AD_ALL_SELF, 1,NULL,0,0);
		i = 0;
	}
	/*	if(sendFlag == 0 && i == 3 &&selfTestContinue == 1)//��Э����ƺú���ȡ��ע��
	{
		Mir_429_All_Self_Test_callback (panelHandleSelfTest, PANEL_4_Mir_429_All_Self_Test, 1,NULL,0,0);
		i++;
	}	 */
	//	sendFlag = 1;
	if(processIndex <= 100)
	{
		label[0] = '\0';
		str[0] = '\0';  
		strcat(label,"��ǰ����Ϊ:");
		Fmt(str,"%s<%i",processIndex);
		strcat(label,str);
		strcat(label,"%");
		ProgressBar_SetPercentage(panelHandleMain,PANEL_NUMERICSLIDE,(double)processIndex,label);
		
//		ProcessSystemEvents();
		processIndex++;
	}  
	
	
	return 0;
}
int CVICALLBACK asynchCBRec (int panel,int timeid ,int event ,void *callbackDatat, int eventData1,int eventData2)
{
	static int datalen = 0;

	char rev[8];
	char chr[1024]="\0";
	unsigned int len=0;
	u8 *pt;
	int rev_Strlen;
	u8 c;
	static int revBuffIndex = 0;
	switch (event)
	{
		case EVENT_TIMER_TICK:
			//	 DisableBreakOnLibraryErrors();
			rev_Strlen=GetInQLen(comSelect);

			if(rev_Strlen>0)
			{

				for (int i=0; i<rev_Strlen; i++)
				{
					c = ComRdByte(comSelect);
					switch(revBuffIndex)
					{
						case 0:

							if(c == 0x7e)
							{
								revBuffIndex = 0;
								uart.revData[revBuffIndex]=c;
								revBuffIndex++;
							}
							else
							{
								revBuffIndex = 0;
								datalen = 0;
							}
							break;
						case 1:
							uart.revData[revBuffIndex]=c;
							datalen = c+4;
							revBuffIndex++;
							break;

						default:
							if(revBuffIndex==datalen)
							{

								uart.revData[revBuffIndex]=c;
								//showResult(uart.revData);
								pt = mycheckbuff(uart.revData,0);
								//if(pt == NULL) return ;
								if (pt!=NULL)
								{
									MessgaeType(pt);
								}
								revBuffIndex=0;
								datalen=0;
							}
							if(revBuffIndex<datalen)
							{
								uart.revData[revBuffIndex]=c;
								revBuffIndex++;
							}
							else
							{
								revBuffIndex=0;
								datalen=0;
							}
							break;
					}
					sprintf(rev,"%02x ",c);
					strcat(chr,rev);
				}

				len=strlen(chr);
				if(len>0)
				{
					SetCtrlAttribute(panelComConfig,PANEL_3_TEXTBOX,ATTR_CTRL_VAL,chr);
				}

			}
		   break;
	}

	return 0;
}
u16 MessgaeType(u8 *p)
{
	
	switch (*(p+3))
	{
		case CMD_429_CONFIG://���԰�429��������ָ��
		
			break;
		case CMD_429_REC: //��λ�����յ�429�������ݺ�ͨ����ָ�������λ��
		
			break;
		case CMD_Micro_DI://΢����DI(0xA5)״̬����ָ��
			if(calibrateOperation == 0)
			analysis(p+4);
			break;
		case CMD_Test_DI:// ���԰�DI״̬����ָ��
			if(calibrateOperation == 0)  
			analysisMicro_DO(p+4);
		//	else
		//	analysisMicro_DOCalibration(p + 4);
			break;
		case CMD_Micro_AI: //΢����AI״ָ̬��
			if(calibrateOperation == 0)  
			analysisMicro_AD(p+4);
			break;
		case CMD_429_Road_TEST_RESULT: //΢����429��·���Խ��ָ��
			analysisMicro_429(p+4);
			break;
		case CMD_429_Micro_All_SelfTest_RSSULT://΢����429�����Լ���ָ��
			analysisSelfTestType(p+3);
			break;
		case CMD_Micro_AD_ALL_SELF_INSPECTION_RESULT:
			analysisSelfTestType(p+3);
			break;
		case CMD_Micro_BeepRec:
		//	analysisSelfTestType(p+3);
			break;
		case CMD_Micro_RS232_REC://���԰�RS232�˿ڽ������ݷ���
			 analysisRS232Test(p+3);
			break;
		case CMD_TEST_IO_SELF_INSPECTION_RESULT://���԰�IO�Լ�������ָ��
			
			break;
		case CMD_DO_Micro_DI_CALIBRATE_REV://�����豸IO���У׼
			if(operation == 1)
				operation = 0;
			else
				operation = 1;
			break;
		case CMD_DO_Test_DI_CALIBRATE_REV: //�����豸IO����У׼
			analysisMicro_DOCalibration(p + 4);
			break;
		case CMD_AD_Micro_AI_CALIBRATE_REV://�����豸AD���У׼
			break;
		default :
			return 0;
	}
	
	return 0;	
}
u16 sendConfigMessage(int index)
{
	
		u8 configBuff[10]={0};
		u16 res = 0;
	
	
		//��ʼ��configBuff
		memset(configBuff,0,10);
	//	memset(verificationBuff,0,4); 
		//configBuff ��ֵ				  //dataLength
		configBuff[0] = HOST_PAKAGE_HEAD;configBuff[1] = 0x05;configBuff[2] = 0x00;configBuff[3] = CMD_DO_Micro_DI;
	
		configBuff[4] = 0x00;configBuff[5] = 0x00; configBuff[6] = 0x00; configBuff[7] = 0x00;
	
		if(calibrateOperation == 1)
			configBuff[3] = CMD_DO_Micro_DI_CALIBRATE_SEND;
		if(operation == UP_LEVEL)
		{
			
			switch (index)
			{
				case 1:
					configBuff [4] = CMD_SYSCONTROL_FRIST; 
			
					break;
				case 2:
					configBuff [4] = CMD_SYSCONTROL_SECOND; 
			
					break;
				case 3:
					configBuff [4] = CMD_SYSCONTROL_THIRD; 
				
					break;
				case 4:
					configBuff [4] = CMD_SYSCONTROL_FOURTH;
				
					break;
				case 5:
					configBuff [4] = CMD_SYSCONTROL_FIFTH;
				
					break;
				case 6:
					configBuff [4] = CMD_SYSCONTROL_SIXTH;
				
					break;
				}
		}
		
		res = GetCRC16(configBuff+3,5);
		configBuff[8]=(res&0x00ff);
		configBuff[9]= ((res&0xff00)>>8);
	
		if(comSelect > 0)
			ComWrt(comSelect,configBuff,10);
	
		return 0;
}


int  analysis(u8 *p)
{
	
	static u8 flag[2] ={0};
	int  result = 0;
	static int tempIndexAll= 0; 
	
	
	if(errorDICount<5)
	{
		if((*p==0xFF)&&(*(p+1)==0xFF)&&(*(p+2)==0xFF)&&(*(p+3)==0xFF))
		{
			 errorDICount++;
			 if(sendFlag == 1)
			 {
				 operation = 1; 
				 sendFlag=0;
			 //	 SetCtrlVal(panelHandleMain,PANEL_NUMERIC,errorDICount);
			 	 SetCtrlVal(panelHandle,PANEL_2_NUMERIC,errorDICount);  
			     return 0;
			 }
			 else
			 {
				  operation = 1;
			 	  sendConfigMessage(indexAll);
				  SetCtrlVal(panelHandle,PANEL_2_NUMERIC,errorDICount); 
				  return 0;
			 }
		}
		else
		{
			errorDICount=0;
		}
	}
	 
	if(operation == UP_LEVEL)
	{
		
		operation = 0;
		memset (flag,0,2);
		switch(indexAll)
		{
			case 1:
			/*for (int i = 0;i<4 ;i++)
					if(*(p + i) != MircoDIInputFristResultUpLevel[i])   */
					if(((*p)&0x01)!=(MircoDIInputFristResultUpLevel[0]&0x01) )
						result = 1;
					break;
			 case 2:
					/*for (int i = 0;i<4 ;i++)
					if(*(p + i) != MircoDIInputSecondResultUpLevel[i]) */
					if(((*p)&0x02)!=(MircoDIInputSecondResultUpLevel[0]&0x02) )
					 result = 1;
				break;
			case 3:
			/*	for (int i = 0;i<4 ;i++)
					if(*(p + i) != MircoDIInputThirdResultUpLevel[i])  */
					if(((*p)&0x04)!=(MircoDIInputThirdResultUpLevel[0]&0x04) )
					result = 1;
				break;
			case 4:
				/*for (int i = 0;i<4 ;i++)
					if(*(p + i) != MircoDIInputFourthResultUpLevel[i])*/
					if(((*p)&0x08)!=(MircoDIInputFourthResultUpLevel[0]&0x08) )
					 result = 1;
				break;
			case 5:
			/*	for (int i = 0;i<4 ;i++)
					if(*(p + i) != MircoDIInputFifthResultUpLevel[i])  */
					if(((*p)&0x10)!=(MircoDIInputFifthResultUpLevel[0]&0x10) )
					result = 1;
				break;
			case 6:
			/*	for (int i = 0;i<4 ;i++)
					if(*(p + i) != MircoDIInputSixthResultUpLevel[i])*/
					if(((*p)&0x20)!=(MircoDIInputSixthResultUpLevel[0]&0x20) )
					   result = 1;
				break;
		}
		
		 if(result == 0)
		 {
		 	flag[0] = 1;
			SetTableCellVal(panelHandle,PANEL_2_TABLE_2 ,MakePoint(3,indexAll),g_hsolidBmp);
			SetTableCellVal(panelHandle,PANEL_2_TABLE_2 ,MakePoint(4,indexAll),g_hsolidBmp);
		 }
		 else
		 {
		    flag[0] = 2;
			SetTableCellVal(panelHandle,PANEL_2_TABLE_2 ,MakePoint(3,indexAll),g_hsolidBmp);
			SetTableCellVal(panelHandle,PANEL_2_TABLE_2 ,MakePoint(4,indexAll),g_hsolidBmp);
		 }
		 Sleep(500);
		 if(calibrateOperation == 0 )
		 sendConfigMessage(indexAll);
		 return 0;
	}
	else if (operation == LOW_LEVEL)
	{
		operation = 1;
		
		switch(indexAll)
		{
			case 1:
			/*	for (int i = 0;i<4 ;i++)
					if(*(p + i) != MircoDIInputFristResultLowLevel[i]) */
					if(((*p)&0x01)!=(MircoDIInputFristResultLowLevel[0]&0x01) )
					result = 1;
				break;
			 case 2:
			/*	for (int i = 0;i<4 ;i++)
					if(*(p + i) != MircoDIInputSecondResultLowLevel[i]) */
					if(((*p)&0x02)!=(MircoDIInputSecondResultLowLevel[0]&0x02) )
					result = 1;
				break;
			case 3:
			/*	for (int i = 0;i<4 ;i++)
					if(*(p + i) != MircoDIInputThirdResultLowLevel[i])  */
					if(((*p)&0x04)!=(MircoDIInputThirdResultLowLevel[0]&0x04) )
					result = 1;
				break;
			case 4:
			/*	for (int i = 0;i<4 ;i++)
					if(*(p + i) != MircoDIInputFourthResultLowLevel[i])  */
					if(((*p)&0x08)!=(MircoDIInputFourthResultLowLevel[0]&0x08) )
					result = 1;
				break;
			case 5:
			/*	for (int i = 0;i<4 ;i++)
					if(*(p + i) != MircoDIInputFifthResultLowLevel[i]) */
					if(((*p)&0x10)!=(MircoDIInputFifthResultLowLevel[0]&0x10) ) 
					result = 1;
				break;
			case 6:
			/*	for (int i = 0;i<4 ;i++)
					if(*(p + i) != MircoDIInputSixthResultLowLevel[i])  */
					 if(((*p)&0x20)!=(MircoDIInputSixthResultLowLevel[0]&0x20)) 
					result = 1;
				break;
		}
		 if(result == 0)
		 {
		 	flag[1] = 1;
			SetTableCellVal(panelHandle,PANEL_2_TABLE_2 ,MakePoint(3,indexAll ),g_hemptyBmp);
			SetTableCellVal(panelHandle,PANEL_2_TABLE_2 ,MakePoint(4,indexAll ),g_hemptyBmp);
			
			
		 }
		 else
		 {
		    flag[1] = 2;
			SetTableCellVal(panelHandle,PANEL_2_TABLE_2 ,MakePoint(3,indexAll ),g_hemptyBmp);
			SetTableCellVal(panelHandle,PANEL_2_TABLE_2 ,MakePoint(4,indexAll ),g_hemptyBmp);
			
			
		 }  
		 Sleep(500);
		 showResult(flag); 
		 return 0;
	}
	return 0;
	
}
int showResult(u8 *p)
{
	static int error = 0;
	static int resultFlag[6]={0};
	 //�����ʾ
	if(p[0] == 1 && p[1] == 1) //��ʾ��ȷ���
	{
		SetTableCellVal(panelHandle,PANEL_2_TABLE_2,MakePoint(5,indexAll),g_hcheckBmp);
		printResult[indexAll - 1 ] = 1;
		 
	}
	 else
	{
		SetTableCellVal(panelHandle,PANEL_2_TABLE_2,MakePoint(5,indexAll),g_hxBmp);
		
		printResult[indexAll - 1] = 2;
		//ReportProj1_IReportXSetCellValue(objectHandleTable,NULL,7,6,"����");
	//	sendFlag = 0;
	//	return 0;
	 
	}
	for(int i = 0;i<6;i++)
	{
		if(printResult[i]==2)
			error = 1;
		else
			error = 0;
	}
	if(indexAll == 6)	 
	{
	//	indexAll = 1;
		
		ActiveId = 2;
		if(sendFlag == 1)
		{
			if(error == 1)
			{
				error = 0;
				SetCtrlAttribute(panelHandleMain,PANEL_LED,ATTR_OFF_COLOR,VAL_RED);
				SetCtrlVal(panelHandleMain,PANEL_LED,0);
			 }else
			 {
				SetCtrlAttribute(panelHandleMain,PANEL_LED,ATTR_ON_COLOR,VAL_GREEN); 
				SetCtrlVal(panelHandleMain,PANEL_LED,1);
			 }
			 
			error = 0;
			sendFlag = 0;

		}
	}
			 

	if(sendFlag == 1 && indexAll < 6)
	{
		indexAll++;
		sendFlag = 0;
	}
	if(showPROGRESSBAR == 1)
	{
		pfvalue++;
	//	MSComctlLib_IProgressBarSetMousePointer(objecthandle,NULL,MSComctlLibConst_ccHourglass);
	//	MSComctlLib_IProgressBarSetValue(objecthandle,NULL,pfvalue);	 
	}
//	MSComctlLib_
	return 0;
}
int showResultMicro_DO(u8 *p)
{
	static int error = 0;
	 //�����ʾ
	if(p[0] == 1 && p[1] == 1) //��ʾ��ȷ���
	{
		SetTableCellVal(panelHandle,PANEL_2_TABLE,MakePoint(5,indexMirocDo),g_hcheckBmp);
		printResult[5 + indexMirocDo] = 1; 
	}
	 else
	{
		SetTableCellVal(panelHandle,PANEL_2_TABLE,MakePoint(5,indexMirocDo),g_hxBmp);
		printResult[5 + indexMirocDo] = 2;
	//	error = 1;
	//	sendFlag = 0;
	//	return 0;
	}
	for(int i = 6;i<=13;i++)
	{
		if(printResult[i]==2)
			error = 1;
		else
			error = 0;
	}
	if(indexMirocDo == 8)
	{
	//	indexMirocDo = 1;
		ActiveId = 3;
		if(error == 1){
		//	SetAsyncTimerAttribute(timerId,ASYNC_ATTR_ENABLED,0);
			SetCtrlAttribute(panelHandleMain,PANEL_LED_2,ATTR_OFF_COLOR,VAL_RED);
		//	return 0;
		}
		else
			SetCtrlVal(panelHandleMain,PANEL_LED_2,1);
		error = 0;
		sendFlag = 0;
	}
	if(sendFlag == 1 && indexMirocDo <8){
		indexMirocDo++;
		sendFlag = 0;
	}
	if(showPROGRESSBAR == 1)
	{
		pfvalue++;
	//	MSComctlLib_IProgressBarSetMousePointer(objecthandle,NULL,MSComctlLibConst_ccHourglass);
	//	MSComctlLib_IProgressBarSetValue(objecthandle,NULL,pfvalue);	 
	}
	return 0;
}
u16 sendMircoDOOutConfigMessage(int index)
{
	
		u8 configBuff[10]={0};
		u16 res = 0;
	
	
		//��ʼ��configBuff
		memset(configBuff,0,10);
	//	memset(verificationBuff,0,4); 
		//configBuff ��ֵ				  //dataLength
		configBuff[0] = HOST_PAKAGE_HEAD;configBuff[1] = 0x05;configBuff[2] = 0x00;configBuff[3] = CMD_DO_Test_DI;
	
		configBuff[4] = 0x00;configBuff[5] = 0x00; configBuff[6] = 0x00; configBuff[7] = 0x00;
	
		if(calibrateOperation == 1)
			configBuff[3] =  CMD_DO_Test_DI_CALIBRATE_SEND;
		if(operation == UP_LEVEL)
		{
			
			switch (index)
			{
				case 1:
					configBuff [4] = CMD_SYSCONTROL_FRIST; 
			
					break;
				case 2:
					configBuff [4] = CMD_SYSCONTROL_SECOND; 
		
					break;
				case 3:
					configBuff [4] = CMD_SYSCONTROL_THIRD; 
				
					break;
				case 4:
					configBuff [4] = CMD_SYSCONTROL_FOURTH;
			
					break;
				case 5:
					configBuff [4] = CMD_SYSCONTROL_FIFTH;
				
					break;
				case 6:
					configBuff [4] = CMD_SYSCONTROL_SIXTH;
			
					break;
				case 7:
					configBuff [4] = CMD_SYSCONTROL_SEVENTH; 
			
					break;
				case 8:
					configBuff [4] = CMD_SYSCONTROL_EIGHTH; 
			
					break;
				}
		}
		
		res = GetCRC16(configBuff+3,5);
		configBuff[8]=(res&0x00ff);
		configBuff[9]= ((res&0xff00)>>8);
	
		if(comSelect > 0)
			ComWrt(comSelect,configBuff,10);
	
		return 0;
}
int  analysisMicro_DO(u8 *p)							  
{
	static u8 flag[2] ={0};
	int  result = 0;
	
	if(errorDOCount<5)
	{
		if((*p==0xFF)&&(*(p+1)==0xFF)&&(*(p+2)==0xFF)&&(*(p+3)==0xFF))
		{
			
			 errorDOCount++;
			 if(sendFlag == 1)
			 {
				 operation = 1; 
				 sendFlag=0;
			//	 SetCtrlVal(panelHandleMain,PANEL_NUMERIC_3,errorDOCount);
				SetCtrlVal(panelHandle,PANEL_2_NUMERIC_3,errorDOCount);
				 return 0;		  
			 }
			 else
			 {
				operation = 1; 
			 	sendMircoDOOutConfigMessage(indexMirocDo);  
				SetCtrlVal(panelHandle,PANEL_2_NUMERIC_3,errorDOCount);
				return 0;
			 }
		}
		else
		{
			errorDOCount = 0;
		}
	}
	
	if(operation == UP_LEVEL)
	{
		operation = 0;
		memset (flag,0,2);
		switch(indexMirocDo)
		{
			case 1:
			/*	for (int i = 0;i<4 ;i++)
					if(*(p + i) != MircoDOOutFristResultUpLevel[i])  */
					if(((*p)&0x01)!=(MircoDOOutFristResultUpLevel[0]&0x01) )
						result = 1;
				break;
			 case 2:
			/*	for (int i = 0;i<4 ;i++)
					if(*(p + i) != MircoDOOutSecondResultUpLevel[i])
					result = 1;   */
			
					if(((*p)&0x02)!=(MircoDOOutSecondResultUpLevel[0]&0x02) )
						result = 1;
				break;
			case 3:
			/*	for (int i = 0;i<4 ;i++)
					if(*(p + i) != MircoDOOutThirdResultUpLevel[i])	   */
					if(((*p)&0x04)!=(MircoDOOutThirdResultUpLevel[0]&0x04) )
						result = 1;
			//		result = 1;
				break;
			case 4:
			/*	for (int i = 0;i<4 ;i++)
					if(*(p + i) != MircoDOOutFourthResultUpLevel[i])   */
					if(((*p)&0x08)!=(MircoDOOutFourthResultUpLevel[0]&0x08) )
						result = 1;
			//		result = 1;
				break;
			case 5:
			/*	for (int i = 0;i<4 ;i++)
					if(*(p + i) != MircoDOOutFifthResultUpLevel[i]) */
					if(((*p)&0x10)!=(MircoDOOutFifthResultUpLevel[0]&0x10) )
						result = 1;
			//		result = 1;
				break;
			case 6:
				/*for (int i = 0;i<4 ;i++)
					if(*(p + i) != MircoDOOutSixthResultUpLevel[i])  */
					if(((*p)&0x20)!=(MircoDOOutSixthResultUpLevel[0]&0x20) )
						result = 1;
				//	result = 1;
				break;
			case 7:
				/*for (int i = 0;i<4 ;i++)
				if(*(p + i) != MircoDOOutSeventhResultUpLevel[i])*/
				 if(((*p)&0x40)!=(MircoDOOutSeventhResultUpLevel[0]&0x40) )
						result = 1;
			//	result = 1;
				break;
			case 8:
				/*for (int i = 0;i<4 ;i++)
				if(*(p + i) != MircoDOOutEighthResultUpLevel[i]) */
				if(((*p)&0x80)!=(MircoDOOutEighthResultUpLevel[0]&0x80) )
						result = 1;
			//	result = 1;
			break;
		}
		
		 if(result == 0)
		 {
		 	flag[0] = 1;
			SetTableCellVal(panelHandle,PANEL_2_TABLE ,MakePoint(3,indexMirocDo),g_hsolidBmp);
			SetTableCellVal(panelHandle,PANEL_2_TABLE ,MakePoint(4,indexMirocDo),g_hsolidBmp);
		 }
		 else
		 {
		    flag[0] = 2;
			SetTableCellVal(panelHandle,PANEL_2_TABLE ,MakePoint(3,indexMirocDo),g_hsolidBmp);
			SetTableCellVal(panelHandle,PANEL_2_TABLE ,MakePoint(4,indexMirocDo),g_hsolidBmp);
		 }
		 Sleep(500);
		 sendMircoDOOutConfigMessage(indexMirocDo);
		 return 0;
	}
	else if (operation == LOW_LEVEL)
	{
		operation = 1;
		
		switch(indexMirocDo)
		{
			case 1:
				/*for (int i = 0;i<4 ;i++)
					if(*(p + i) != MircoDOOutFristResultLowLevel[i])
					result = 1; */		  
				if(((*p)&0x01)!=(MircoDOOutFristResultLowLevel[0]&0x01) )
						result = 1;
				break;
			 case 2:
				if(((*p)&0x02)!=(MircoDOOutSecondResultLowLevel[0]&0x02) )
						result = 1;
				break;
			case 3:
				if(((*p)&0x04)!=(MircoDOOutThirdResultLowLevel[0]&0x04) )
						result = 1;
				break;
			case 4:
				if(((*p)&0x08)!=(MircoDOOutFourthResultLowLevel[0]&0x08) )
						result = 1;
				break;
			case 5:
				if(((*p)&0x10)!=(MircoDOOutFifthResultLowLevel[0]&0x10) )
						result = 1;
				//	result = 1;
				break;
			case 6:
				if(((*p)&0x20)!=(MircoDOOutSixthResultLowLevel[0]&0x20) )
					result = 1;
				break;
			case 7:
				if(((*p)&0x40)!=(MircoDOOutSeventhResultLowLevel[0]&0x40) )
						result = 1;
			break;
			case 8:
				if(((*p)&0x80)!=(MircoDOOutEighthResultLowLevel[0]&0x80) )
						result = 1;
			//	result = 1;
			break;
		}
		 if(result == 0)
		 {
		 	flag[1] = 1;
			SetTableCellVal(panelHandle,PANEL_2_TABLE ,MakePoint(3,indexMirocDo),g_hemptyBmp);
			SetTableCellVal(panelHandle,PANEL_2_TABLE ,MakePoint(4,indexMirocDo),g_hemptyBmp);
			
			
		 }
		 else
		 {
		    flag[1] = 2;
			SetTableCellVal(panelHandle,PANEL_2_TABLE ,MakePoint(3,indexMirocDo),g_hemptyBmp);
			SetTableCellVal(panelHandle,PANEL_2_TABLE ,MakePoint(4,indexMirocDo),g_hemptyBmp);
			
			
		 }
		 Sleep(500);
		 showResultMicro_DO(flag);  
		 return 0;
	}
	return 0;
	
}

u16 getADvalue(float v)
{
	float result;
	//result=(v*10000-105.0)/9.8468;
	result=965.5*v+40.715;
	return((u16)result);
}

u16 sendMircoADInputConfigMessage(int index)
{
		u8 configBuff[30]={0};
		u16 res = 0;
		u16 value;
	
		
		//��ʼ��configBuff
		memset(configBuff,0,30);
	
		//configBuff ��ֵ				  //dataLength
		configBuff[0] = HOST_PAKAGE_HEAD;configBuff[1] = 0x19;configBuff[2] = 0x00;configBuff[3] = CMD_AD_Micro_AI;
	
	//	configBuff[4] = 0x00;configBuff[5] = 0x00; configBuff[6] = 0x00; configBuff[7] = 0x00;
	
	//	operation = 3;
		if(calibrateOperation == 1)
			configBuff[3] = CMD_AD_Micro_AI_CALIBRATE_SEND;
		if(operation == FRISTADSEND)
		{		;
		/*	 switch (index)
			{
				case 1:
					SetTableCellVal(panelHandle,PANEL_2_TABLE_4,MakePoint(3,2),0.0);
					break;
				case 2:
					SetTableCellVal(panelHandle,PANEL_2_TABLE_4,MakePoint(3,3),0.0);
					break;
				case 3:
					SetTableCellVal(panelHandle,PANEL_2_TABLE_4,MakePoint(3,4),0);
					break;
				case 4:
					SetTableCellVal(panelHandle,PANEL_2_TABLE_4,MakePoint(3,5),0);
					break;
				case 5:
					SetTableCellVal(panelHandle,PANEL_2_TABLE_4,MakePoint(3,6),0);
					break;
				case 6:
					SetTableCellVal(panelHandle,PANEL_2_TABLE_4,MakePoint(3,7),0);
					break;
				}
			  */
		}
		else if(operation == SECONDADSEND)
		{
			value=getADvalue(1.5);
			switch (index)
			{
				case 1:
					configBuff [4] = (value)&0xFF; 
					configBuff [5] = (value>>8)&0xFF;
					//SetTableCellVal(panelHandle,PANEL_2_TABLE_4,MakePoint(3,1),1.5);
					break;
				case 2:
					configBuff [8] = (value)&0xFF; 
					configBuff [9] = (value>>8)&0xFF; 
				//	SetTableCellVal(panelHandle,PANEL_2_TABLE_4,MakePoint(3,2),1.5);
					break;
				case 3:
					configBuff [12] = (value)&0xFF; 
					configBuff [13] = (value>>8)&0xFF; 
				//	SetTableCellVal(panelHandle,PANEL_2_TABLE_4,MakePoint(3,3),1.5);
					break;
				case 4:
					configBuff [16] = (value)&0xFF; 
					configBuff [17] = (value>>8)&0xFF; 
				//	SetTableCellVal(panelHandle,PANEL_2_TABLE_4,MakePoint(3,4),1.5);
					break;
				case 5:
					configBuff [20] = (value)&0xFF;
					configBuff [21] = (value>>8)&0xFF; 
				//	SetTableCellVal(panelHandle,PANEL_2_TABLE_4,MakePoint(3,5),1.5);
					break;
				case 6:
					configBuff [24] = (value)&0xFF;
					configBuff [25] = (value>>8)&0xFF; 
				//	SetTableCellVal(panelHandle,PANEL_2_TABLE_4,MakePoint(3,6),1.5);
					break;
				}
		}
		else
		{
			value=getADvalue(3.47);
			switch (index)
			{
				case 1:
					configBuff [4] = (value)&0xFF; 
					configBuff [5] = (value>>8)&0xFF; 
				//	SetTableCellVal(panelHandle,PANEL_2_TABLE_4,MakePoint(3,1),3.474);
					break;
				case 2:
					configBuff [8] = (value)&0xFF; 
					configBuff [9] = (value>>8)&0xFF; 
				//	SetTableCellVal(panelHandle,PANEL_2_TABLE_4,MakePoint(3,2),3.474);
					break;
				case 3:
					configBuff [12] = (value)&0xFF; 
					configBuff [13] = (value>>8)&0xFF; 
				//	SetTableCellVal(panelHandle,PANEL_2_TABLE_4,MakePoint(3,3),3.474);
					break;
				case 4:
					configBuff [16] = (value)&0xFF; 
					configBuff [17] = (value>>8)&0xFF; 
				//	SetTableCellVal(panelHandle,PANEL_2_TABLE_4,MakePoint(3,4),3.474);
					break;
				case 5:
					configBuff [20] = (value)&0xFF;  
					configBuff [21] = (value>>8)&0xFF; 
				//	SetTableCellVal(panelHandle,PANEL_2_TABLE_4,MakePoint(3,5),3.474);
					break;
				case 6:
					configBuff [24] = (value)&0xFF; 
					configBuff [25] =(value>>8)&0xFF; 
				//	SetTableCellVal(panelHandle,PANEL_2_TABLE_4,MakePoint(3,6),3.474);
					break;
				}
		}
		res = GetCRC16(configBuff+3,25);
		configBuff[28]=(res&0x00ff);
		configBuff[29]= ((res&0xff00)>>8);
	
		if(comSelect > 0)
			ComWrt(comSelect,configBuff,30);
	
		return 0;
}
int analysisMicro_AD(u8 *p)
{
	static int error = 0;
	static u8 flag[3] ={0};

	double resultDouble [6] = {0};
	int j = 0;
	int sendADline = 0;
	if(errorADCount<5)
	{
		switch (indexMirocAD)
		{
			case 1:
				sendADline =0;
				break;
				case 2:
				sendADline =4;
				break;
				case 3:
				sendADline =8;
				break;
				case 4:
				sendADline =12;
				break;
				case 5:
				sendADline =16;
				break;
				case 6:
				sendADline =20;
				break;
		}
		if((*(p+sendADline)==0xFF)&&(*(p+1+sendADline)==0xFF)&&(*(p+2+sendADline)==0xFF)&&(*(p+3+sendADline)==0xFF))
		{
			 errorADCount++;
			 if(sendFlag == 1){
			 sendFlag=0;
		//	 SetCtrlVal(panelHandleMain,PANEL_NUMERIC_2,errorADCount);
			 SetCtrlVal(panelHandle,PANEL_2_NUMERIC_2,errorADCount);

			 return 0; }
			 else
			 {
			 	operation = 1; 
				sendMircoADInputConfigMessage(indexMirocAD);		 
				SetCtrlVal(panelHandle,PANEL_2_NUMERIC_2,errorADCount);
				return 0;
			 }
		}
		else
		{
			errorADCount=0;
		}
	}
	
	if(operation == FRISTADSEND)
	{
		
		for (int i = 0;i< 6;i++)
		{
			resultDouble [i] = (((double)(HexToInt(p+j,0)))+273)/760-0.35;
			j += 4;
		}
		operation = 2;
		memset (flag,0,3);
		switch(indexMirocAD)
		{
			case 1:
				SetTableCellVal(panelHandle,PANEL_2_TABLE_4,MakePoint(3,1),0.0);
				SetTableCellVal(panelHandle,PANEL_2_TABLE_4,MakePoint(4,1),resultDouble[0]);
				if (resultDouble[0]>=0  && 	resultDouble[0] < 0.5)
					flag[0] = 1;
				break;
			 case 2:
				 SetTableCellVal(panelHandle,PANEL_2_TABLE_4,MakePoint(3,2),0.0);
				SetTableCellVal(panelHandle,PANEL_2_TABLE_4,MakePoint(4,2),resultDouble[1]);
				if (resultDouble[1]>=0  && 	resultDouble[1] < 0.5)
					flag[0] = 1;
				break;
			case 3:
				SetTableCellVal(panelHandle,PANEL_2_TABLE_4,MakePoint(3,3),0.0);
				SetTableCellVal(panelHandle,PANEL_2_TABLE_4,MakePoint(4,3),resultDouble[2]);
				if (resultDouble[2]>=0  && 	resultDouble[2] < 0.5)
					flag[0] = 1;
				break;
			case 4:
				SetTableCellVal(panelHandle,PANEL_2_TABLE_4,MakePoint(3,4),0.0);
				SetTableCellVal(panelHandle,PANEL_2_TABLE_4,MakePoint(4,4),resultDouble[3]);
				if (resultDouble[3]>=0  && 	resultDouble[3] < 0.5)
					flag[0] = 1;
				break;
			case 5:
				SetTableCellVal(panelHandle,PANEL_2_TABLE_4,MakePoint(3,5),0.0);
				SetTableCellVal(panelHandle,PANEL_2_TABLE_4,MakePoint(4,5),resultDouble[4]);
				if (resultDouble[4]>=0  && 	resultDouble[4] < 0.5)
					flag[0] = 1;
				break;
			case 6:
				SetTableCellVal(panelHandle,PANEL_2_TABLE_4,MakePoint(3,6),0.0);
				SetTableCellVal(panelHandle,PANEL_2_TABLE_4,MakePoint(4,6),resultDouble[5]);
				if (resultDouble[5]>=0  && 	resultDouble[5] < 0.5)
					flag[0] = 1;
				break;
		}
		Sleep(200);
		 sendMircoADInputConfigMessage(indexMirocAD);
		 return 0;
	}
	else if (operation == SECONDADSEND)
	{
		
		operation = 3;
		for (int i = 0;i< 6;i++)
		{
			resultDouble [i] = (((double)(HexToInt(p+j,0)))+273)/786-0.22;
			j += 4;
		}
		switch(indexMirocAD)
		{
			case 1:
				SetTableCellVal(panelHandle,PANEL_2_TABLE_4,MakePoint(3,1),1.5);
				SetTableCellVal(panelHandle,PANEL_2_TABLE_4,MakePoint(4,1),resultDouble[0]);
				if (resultDouble[0]>1  && 	resultDouble[0] < 2)
					flag[1] = 1;
				break;
			 case 2:
				 SetTableCellVal(panelHandle,PANEL_2_TABLE_4,MakePoint(3,2),1.5);
				SetTableCellVal(panelHandle,PANEL_2_TABLE_4,MakePoint(4,2),resultDouble[1]);
				if (resultDouble[1]>1  && 	resultDouble[1] < 2)
					flag[1] = 1;
				break;
			case 3:
				SetTableCellVal(panelHandle,PANEL_2_TABLE_4,MakePoint(3,3),1.5);
				SetTableCellVal(panelHandle,PANEL_2_TABLE_4,MakePoint(4,3),resultDouble[2]);
				if (resultDouble[2]>1  && 	resultDouble[2] < 2)
					flag[1] = 1;
				break;
			case 4:
				SetTableCellVal(panelHandle,PANEL_2_TABLE_4,MakePoint(3,4),1.5);
				SetTableCellVal(panelHandle,PANEL_2_TABLE_4,MakePoint(4,4),resultDouble[3]);
				if (resultDouble[3]>1  && 	resultDouble[3] < 2)
					flag[1] = 1;
				break;
			case 5:
				SetTableCellVal(panelHandle,PANEL_2_TABLE_4,MakePoint(3,5),1.5);
				SetTableCellVal(panelHandle,PANEL_2_TABLE_4,MakePoint(4,5),resultDouble[4]);
				if (resultDouble[4]>1  && 	resultDouble[4] < 2)
					flag[1] = 1;
				break;
			case 6:
				SetTableCellVal(panelHandle,PANEL_2_TABLE_4,MakePoint(3,6),1.5);
				SetTableCellVal(panelHandle,PANEL_2_TABLE_4,MakePoint(4,6),resultDouble[5]);
				if (resultDouble[5]>1  && 	resultDouble[5] < 2)
					flag[1] = 1;
				break;
		}
		Sleep(200);
		sendMircoADInputConfigMessage(indexMirocAD); 
		return 0;
	}
	else
	{
		
		operation = 1;
		for (int i = 0;i< 6;i++)
		{
			resultDouble [i] = (((double)(HexToInt(p+j,0)))+273)/786-0.22;
			j += 4;
		}
		switch(indexMirocAD)
		{
			case 1:
				SetTableCellVal(panelHandle,PANEL_2_TABLE_4,MakePoint(3,1),3.474);
				SetTableCellVal(panelHandle,PANEL_2_TABLE_4,MakePoint(4,1),resultDouble[0]);
				if (resultDouble[0]>3  && 	resultDouble[0] < 4)
					flag[2] = 1;
				break;
			 case 2:
				 SetTableCellVal(panelHandle,PANEL_2_TABLE_4,MakePoint(3,2),3.474);
				SetTableCellVal(panelHandle,PANEL_2_TABLE_4,MakePoint(4,2),resultDouble[1]);
				if (resultDouble[1]>3  && 	resultDouble[1] <4)
					flag[2] = 1;
				break;
			case 3:
				SetTableCellVal(panelHandle,PANEL_2_TABLE_4,MakePoint(3,3),3.474);
				SetTableCellVal(panelHandle,PANEL_2_TABLE_4,MakePoint(4,3),resultDouble[2]);
				if (resultDouble[2]>3  && 	resultDouble[2] < 4)
					flag[2] = 1;
				break;
			case 4:
				SetTableCellVal(panelHandle,PANEL_2_TABLE_4,MakePoint(3,4),3.474);
				SetTableCellVal(panelHandle,PANEL_2_TABLE_4,MakePoint(4,4),resultDouble[3]);
				if (resultDouble[3]>3  && 	resultDouble[3] < 4)
					flag[2] = 1;
				break;
			case 5:
				SetTableCellVal(panelHandle,PANEL_2_TABLE_4,MakePoint(3,5),3.474);
				SetTableCellVal(panelHandle,PANEL_2_TABLE_4,MakePoint(4,5),resultDouble[4]);
				if (resultDouble[4]>3  && 	resultDouble[4] < 4)
					flag[2] = 1;
				break;
			case 6:
				SetTableCellVal(panelHandle,PANEL_2_TABLE_4,MakePoint(3,6),3.474);
				SetTableCellVal(panelHandle,PANEL_2_TABLE_4,MakePoint(4,6),resultDouble[5]);
				if (resultDouble[5]>3  && 	resultDouble[5] < 4)
					flag[2] = 1;
				break;
		}
			  if(flag[0] == 1 && flag[1] == 1 && flag[2] == 1)
			  {
				 SetTableCellVal(panelHandle,PANEL_2_TABLE_4,MakePoint(5,indexMirocAD),g_hcheckBmp);
				 printResult[13 + indexMirocAD] = 1; 
			  }
			  else
			  {
			  	SetTableCellVal(panelHandle,PANEL_2_TABLE_4,MakePoint(5,indexMirocAD),g_hxBmp);
				printResult[13 + indexMirocAD] = 2;
			//	error = 1;
			//	sendFlag = 0;
			//	return 0;
			  }
			  for (int i = 14 ;i<=19;i++)
			  {
			  	if(printResult[i]==2)
					error = 1;
				else
					error = 0;
			  }
			  if(indexMirocAD == 6)
			 {	  
		
			//	 indexMirocAD =1;
				 
				 if(error == 1)
				 {	
					// SetAsyncTimerAttribute (timerId, ASYNC_ATTR_ENABLED, 0);  
					 SetCtrlAttribute(panelHandleMain,PANEL_LED_3,ATTR_OFF_COLOR,VAL_RED);
				 }
				else 
				SetCtrlVal(panelHandleMain,PANEL_LED_3,1);
				ActiveId = 4; 
				sendFlag = 0; 
				error = 0;
			 }
			if(sendFlag == 1 && indexMirocAD < 6)
			{
				indexMirocAD++;
				sendFlag = 0;     
			}
			if(showPROGRESSBAR == 1)
			{
				pfvalue++;
			//	MSComctlLib_IProgressBarSetMousePointer(objecthandle,NULL,MSComctlLibConst_ccHourglass);
			//	MSComctlLib_IProgressBarSetValue(objecthandle,NULL,pfvalue);
				
			}
	  	  return 0;
	}
	//return 0;
}
int analysisSelfTestType(u8 *p)
{
	switch ((*p))
	{
		case CMD_429_Micro_All_SelfTest_RSSULT:  //΢����429�����Լ�
			for(int i =0 ;i<=3;i++)
				if(*(p+1+i) != Miro429AllSelfTestRev[i])
				{
					SetCtrlAttribute(panelHandle,PANEL_2_LED_8,ATTR_OFF_COLOR,VAL_RED);
					SetCtrlVal(panelHandle,PANEL_2_LED_8,0); 
					printResult[25] = 2;
					break;
				}else
				{
					SetCtrlVal(panelHandle,PANEL_2_LED_8,1);
					printResult[25] = 1;
				}
				
			break;
		case CMD_Micro_AD_ALL_SELF_INSPECTION_RESULT:	 //΢����AD�Լ�
				for (int i = 0;i < 4 ;i++)
				 if(*(p+1+i) == MiroADAllSelfTestRev[i])
				 {
					SetCtrlVal(panelHandle,PANEL_2_LED_9,1);
					printResult[26] = 1;
				 }
				else
				{
					SetCtrlAttribute(panelHandle,PANEL_2_LED_9,ATTR_OFF_COLOR,VAL_RED);
					SetCtrlVal(panelHandle,PANEL_2_LED_9,0); 
					printResult[26] = 2;
				}
			break;
	/*	case CMD_Micro_BeepRec://΢���������
			for (int i = 0;i < 4 ;i++)
				 if(*(p+1+i) == MiroADBuzzerRev[i])
					//SetCtrlVal(panelHandleSelfTest,PANEL_2_LED_9,1);
					MessagePopup("","���������Ƴɹ�");
				else
				{
					MessagePopup("","����������ʧ��");
				//	SetCtrlAttribute(panelHandleSelfTest,PANEL_2_LED_9,ATTR_OFF_COLOR,VAL_RED);
				//	SetCtrlVal(panelHandleSelfTest,PANEL_2_LED_9,0); 
				}
			break;  */
	}
	return 0;
}


int CVICALLBACK CMD_PRINTING_SELF_callback (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:

			break;
	}
	return 0;
}
//�����豸ADУ׼
int CVICALLBACK MircoADInputCalibration (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	Point focus;
	switch (event)
	{
		case EVENT_COMMIT:
			calibrateOperation = 1;  
		   GetActiveTableCell (panel, control, &focus);
		   /*if (focus.x == BUTTON_COLUMN)
			{
				indexMirocAD = focus.y ;
				sendMircoADInputConfigMessage(indexMirocAD);		 
			}  */
			if(focus.x == 4)
			{
				operation = FRISTADSEND;
				indexMirocAD = focus.y ;
				sendMircoADInputConfigMessage(indexMirocAD);		 
				SetTableCellVal(panelHandleSelfTest,PANEL_4_TABLE_4 ,MakePoint(7,indexMirocAD),0.0);
			}
			if(focus.x == 5)
			{
				operation = SECONDADSEND;
				indexMirocAD = focus.y ;
				sendMircoADInputConfigMessage(indexMirocAD);		 
				SetTableCellVal(panelHandleSelfTest,PANEL_4_TABLE_4 ,MakePoint(7,indexMirocAD),1.5);
			}
			if(focus.x == 6)
			{
				operation = THIRDADSEND;
				indexMirocAD = focus.y ;
				sendMircoADInputConfigMessage(indexMirocAD);		 
				SetTableCellVal(panelHandleSelfTest,PANEL_4_TABLE_4 ,MakePoint(7,indexMirocAD),3.47);
			}

			break;
	}
	return 0;
}
//�����豸����У׼��DO У׼ ��
int CVICALLBACK MircoDOOutCalibration (int panel, int control, int event,
									   void *callbackData, int eventData1, int eventData2)
{
	Point focus;
	
	switch (event)
	{
		case EVENT_COMMIT:
			//��У׼����
		   calibrateOperation = 1;
			
		   GetActiveTableCell (panel, control, &focus);
		   if (focus.x == BUTTON_COLUMN)
			{
				indexMirocDo = focus.y ;
				sendMircoDOOutConfigMessage(indexMirocDo);
			}
			break;
	}
	return 0;
}
//�����豸���IOУ׼��DI У׼)
int CVICALLBACK MircoDIInputTableCalibration (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	Point focus;
	switch (event)
	{
		case EVENT_COMMIT:
			//��У׼����
		   calibrateOperation = 1;
		   GetActiveTableCell (panel, control, &focus);
		   if (focus.x == BUTTON_COLUMN)
			{
				indexAll = focus.y;
			 
				sendConfigMessage(indexAll);
			
			} 
		    if(operation == UP_LEVEL)
				SetTableCellVal(panelHandleSelfTest,PANEL_4_TABLE_2 ,MakePoint(4,indexAll),g_hsolidBmp);
			else
				SetTableCellVal(panelHandleSelfTest,PANEL_4_TABLE_2 ,MakePoint(4,indexAll),g_hemptyBmp);
			break;
	}
	return 0;
}

int CVICALLBACK CMD_OUT_SELF_EXCEL_callback (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:

			break;
	}
	return 0;
}

int CVICALLBACK CMD_PT_SF_RETURN_MAIN_callback (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
		    HidePanel(panelHandleSelfPrint);
			DisplayPanel(panelHandleMain);
			break;
	}
	return 0;
}

int CVICALLBACK CMD_SHOW_SELF_PRINT_callback (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	char **filename = "\0";
	switch (event)
	{
		case EVENT_COMMIT:
	/*		HidePanel(panelHandleSelfTest);
			DisplayPanel(panelHandleSelfPrint); */
			if(FileSelectPopup(".\\ģ��","*.*","*.*","��д��¼",
							   VAL_OK_BUTTON,0,1,1,0,filename)>0)
			{
				OpenDocumentInDefaultViewer(filename,VAL_NO_ZOOM);
			}
			break;
	}
	return 0;
}

void CVICALLBACK FilePrint (int menuBar, int menuItem, void *callbackData,
							int panel)
{
	ReportProj1_IReportXPrintSheet(objectHandleTable,NULL,VTRUE);
}

void CVICALLBACK FileOutExcel (int menuBar, int menuItem, void *callbackData,
							   int panel)
{	
	int	 month, day, year;
	char timeStr[MAX_DATE_LEN];

	
	char filename[MAX_PATHNAME_LEN] = {"d:\\����������"};
//	char strtemp[256];
	char *strtemp;

	GetSystemDate (&month, &day, &year);
												  
	sprintf (timeStr, "%d��%02d��%02d��", year,month,day );
	
	ReportProj1_IReportXGetCellValue(objectHandleTable,NULL,3,33,&strtemp);
	strcat(filename,"\\");
	strcat(filename,timeStr);
	strcat(filename,"_");
	strcat(filename,strtemp);
	strcat(filename,".xls");
	
	ReportProj1_IReportXExportExcel(objectHandleTable,NULL,filename,strtemp,VFALSE);
	
	MessagePopup("��ʾ",filename);

}

void CVICALLBACK FileReturn (int menuBar, int menuItem, void *callbackData,
							 int panel)
{
	HidePanel(panelHandlePrint);
	DisplayPanel(panelHandleMain);
}

int CVICALLBACK BIN_POWER_OPRATION_callback (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	int val = 0;
	
	switch (event)
	{
		case EVENT_COMMIT:
			GetCtrlVal(panel,PANEL_BIN_POWER_OPRATION,&val);
			if(val == 1)
			{
			   for (int i = 2;i<=5;i++)
			   SetInputMode(panel,i,1);
			   ComWrt(comSelect,UpPower,7);
			   //SetCtrlVal(panelHandle,PANEL_2_BIN_POWER_UI,1);
			   //SetCtrlVal(panelHandleSelfTest,PANEL_4_BIN_OPERATION_POWER_C,1);
			}
			else
			{
			   for (int i = 2;i<=5;i++)
			   SetInputMode(panel,i,0);
				ComWrt(comSelect,DownPower,7);
				//SetCtrlVal(panelHandle,PANEL_2_BIN_POWER_UI,0);
				//SetCtrlVal(panelHandleSelfTest,PANEL_4_BIN_OPERATION_POWER_C,0);
			}
			SetPowerOperationAccordance(val);
			break;
	}
	return 0;
}

int CVICALLBACK BIN_POWER_UI_callback (int panel, int control, int event,
									   void *callbackData, int eventData1, int eventData2)
{
	int val = 0;
	switch (event)
	{
		case EVENT_COMMIT:
			GetCtrlVal(panel,PANEL_2_BIN_POWER_UI,&val);
			if(val == 1)
			{
			//   SetCtrlVal(panelHandleMain,PANEL_BIN_POWER_OPRATION,1);
			//   SetCtrlVal(panelHandleSelfTest,PANEL_4_BIN_OPERATION_POWER_C,1);

			   ComWrt(comSelect,UpPower,7);
			}
			else
			{
			//	SetCtrlVal(panelHandleMain,PANEL_BIN_POWER_OPRATION,0);
			//    SetCtrlVal(panelHandleSelfTest,PANEL_4_BIN_OPERATION_POWER_C,0);

				ComWrt(comSelect,DownPower,7);
			}
			SetPowerOperationAccordance(val);
			break;
	}
	return 0;
}
int analysisMicro_DOCalibration(u8 *p)
{
	int n0 = 0;
	u8 outByte[1];
	outByte[0] = *(p + 0);
		switch(indexMirocDo)
		{
			case 1:
				n0 = (outByte[0] & 0x01) == 0x01 ? 1:0;
				break;
			case 2:
				n0 = (outByte[0] & 0x02) == 0x02 ? 1:0;
				break;
			case 3:
				n0 = (outByte[0] & 0x04) == 0x04 ? 1:0;
				break;
			case 4:
				n0 = (outByte[0] & 0x08) == 0x08 ? 1:0;
				break;
			case 5:
				n0 = (outByte[0] & 0x10) == 0x10 ? 1:0;
				break;
			case 6:
				n0 = (outByte[0] & 0x20) == 0x20 ? 1:0;
				break;
			case 7:
				n0 = (outByte[0] & 0x40) == 0x40 ? 1:0;
				break;
			case 8:
				n0 = (outByte[0] & 0x80) == 0x80 ? 1:0;
				break;
		}
		if(n0 == 0)
			SetTableCellVal(panelHandleSelfTest,PANEL_4_TABLE,MakePoint(4,indexMirocDo),g_hemptyBmp);
		else
			SetTableCellVal(panelHandleSelfTest,PANEL_4_TABLE,MakePoint(4,indexMirocDo),g_hsolidBmp);
		return 0;
}
int CVICALLBACK CMD_RETURN_MAIN_callback (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			CMD_RESET_callback (panelHandle,PANEL_2_CMD_RESET, 1,NULL,0,0);  
			HidePanel(panelHandleWarning);
			DisplayPanel(panelHandleMain);
			break;
	}
	return 0;
}

int CVICALLBACK CMD_SHOWPRINT_callback (int panel, int control, int event,
										void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			/*HidePanel(panelHandleWarning);
			DisplayPanel(panelHandlePrint); */
			CMD_PRINT_callback (panelHandle, PANEL_2_CMD_PRINT, 1,NULL,0,0);
									
			break;
	}
	return 0;
}

int CVICALLBACK CMD_SHOWTESTUI_callback (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			HidePanel(panelHandleWarning);
			DisplayPanel(panelHandle);
			break;
	}
	return 0;
}
int ReSend(int id,int sendType)
{
	switch(sendType)
	{
		case 1:
			ActiveId = 1;
			indexAll = id;
			break;
		case 2:
			ActiveId = 1;
			indexMirocDo = id;
			break;
		case 3:
			ActiveId = 2;
			indexMirocAD = id;
			break;
	}
	return 0;
}

int CVICALLBACK BIN_OPERATION_POWER_C_callback (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	int val = 0;
	switch (event)
	{
		case EVENT_COMMIT:
		   GetCtrlVal(panel,PANEL_4_BIN_OPERATION_POWER_C,&val);
		   if(val == 1)
			{
			 //  SetCtrlVal(panelHandleMain,PANEL_BIN_POWER_OPRATION,1);
			 //  SetCtrlVal(panelHandle,PANEL_2_BIN_POWER_UI,1);
			   ComWrt(comSelect,UpPower,7);
			}
			else
			{
			//	SetCtrlVal(panelHandleMain,PANEL_BIN_POWER_OPRATION,0); 
			//	SetCtrlVal(panelHandle,PANEL_2_BIN_POWER_UI,0);
				ComWrt(comSelect,DownPower,7);
			}
			SetPowerOperationAccordance(val);
			break;
	}
	return 0;
}

int CVICALLBACK CMD_RESET_CALIBRATION_callback (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			operation = 1; 
			SetTableCellRangeAttribute(panelHandleSelfTest,PANEL_4_TABLE_2,VAL_TABLE_COLUMN_RANGE(4),ATTR_CTRL_VAL,0);
			SetTableCellRangeAttribute(panelHandleSelfTest,PANEL_4_TABLE,VAL_TABLE_COLUMN_RANGE(4),ATTR_CTRL_VAL,0);
			SetTableCellRangeAttribute(panelHandleSelfTest,PANEL_4_TABLE_4,VAL_TABLE_COLUMN_RANGE(7),ATTR_CTRL_VAL,0.0);
			break;
	}
	return 0;
}
static void SetPowerOperationAccordance(int val)
{
	SetCtrlVal(panelHandle,PANEL_2_BIN_POWER_UI,val);
	SetCtrlVal(panelHandleSelfTest,PANEL_4_BIN_OPERATION_POWER_C,val);
	SetCtrlVal(panelHandleMain,PANEL_BIN_POWER_OPRATION,val);	}
