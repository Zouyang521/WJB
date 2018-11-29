#ifndef __COMTABLE_H
#define __COMTABLE_H

#define HOST_PAKAGE_HEAD  0x7e	 
/*#define HOST_PAKAGE_TAIL  0xef
#define HOST_PAKAGE_LENGTH 12
#define SLAVE_PAKAGE_HEAD 0x6d	 
#define SLAVE_PAKAGE_TAIL 0xde
#define HOST_DATA_LENGTH  0x07*/

/* Cmd Type*/
typedef enum
{
  CMD_429_CONFIG =  			((unsigned char)0x90), 
  CMD_429_SEND =  				((unsigned char)0x91),
  CMD_429_REC =  				((unsigned char)0x92),
  CMD_429_SELF_INSPECTION =  	((unsigned char)0xA8),
  CMD_DO_Micro_DI =  			((unsigned char)0x93),
  CMD_Micro_DI =  				((unsigned char)0xA5),
  CMD_DO_Test_DI =  			((unsigned char)0xA4),
  CMD_Test_DI =  				((unsigned char)0x94),
  CMD_AD_Micro_AI =             ((unsigned char)0x95),
  CMD_Micro_AI =                ((unsigned char)0x96),
  CMD_429_Road_TEST =            ((unsigned char)0x97),
  CMD_429_Road_TEST_RESULT =     ((unsigned char)0x98),
  CMD_429_Micro_All_SelfTest =			((unsigned char)0xA0),
  CMD_429_Micro_All_SelfTest_RSSULT =  ((unsigned char)0xA1),
  CMD_Micro_AD_ALL_SELF_INSPECTION = ((unsigned char)0xA2),
  CMD_Micro_AD_ALL_SELF_INSPECTION_RESULT = ((unsigned char)0xA3),
  CMD_Micro_Beep =              ((unsigned char)0xA6),
  CMD_Micro_BeepRec =              ((unsigned char)0xA7),
  CMD_Micro_RS232_SEND =         ((unsigned char)0xB0),
  CMD_Micro_RS232_REC =          ((unsigned char)0xB1),
  CMD_TEST_IO_SELF_INSPECTION =  ((unsigned char)0xB2),
  CMD_TEST_IO_SELF_INSPECTION_RESULT = ((unsigned char)0xB3),
  CMD_DO_Micro_DI_CALIBRATE_SEND =		((unsigned char)0xD0),
  CMD_DO_Micro_DI_CALIBRATE_REV =		((unsigned char)0xD1),
  CMD_DO_Test_DI_CALIBRATE_SEND =  		((unsigned char)0xD2),
  CMD_DO_Test_DI_CALIBRATE_REV =  		((unsigned char)0xD3),
  CMD_AD_Micro_AI_CALIBRATE_SEND =      ((unsigned char)0xD4),
  CMD_AD_Micro_AI_CALIBRATE_REV =       ((unsigned char)0xD5)
}
CMD_SYSCONTROL1_TypeDef;
/*系统相关参数 cmd==1*/
typedef enum
{
	CMD_SYSCONTROL_FRIST     =  ((unsigned char)0x01),
	CMD_SYSCONTROL_SECOND    =  ((unsigned char)0x02),
	CMD_SYSCONTROL_THIRD     =  ((unsigned char)0x04),
	CMD_SYSCONTROL_FOURTH    =  ((unsigned char)0x08),
	CMD_SYSCONTROL_FIFTH 	 =  ((unsigned char)0x10),
	CMD_SYSCONTROL_SIXTH 	 =  ((unsigned char)0x20),
	CMD_SYSCONTROL_SEVENTH   =  ((unsigned char)0x40),
	CMD_SYSCONTROL_EIGHTH    =  ((unsigned char)0x80)
}
CMD_SYSCONTROL_TypeDef;


//微机板429总线自检发送与正确结果
const unsigned char Miro429AllSelfTestSend [6] = {0x7e,0x01,0x00,0xA0,0xEA,0xB5};
const unsigned char Miro429AllSelfTestRev[4] = {0x01,0x00,0x00,0x00};
//===============================================================================
//微机板AD总线自检
const unsigned char MiroADAllSelfTestSend [6] = {0x7e,0x01,0x00,0xA2,0xa8,0x95};
const unsigned char MiroADAllSelfTestRev[4] = {0x00,0x00,0x00,0x00};
//===============================================================================
//微机板蜂鸣器控制
const unsigned char MiroADBuzzerSend [6] = {0x7E,0x05,0x00,0xA6,0x00,0x00,0x00,0x00,0xE1,0xE7 };
const unsigned char MiroADBuzzerRev[4] = {0xff,0xff,0xff,0xff};
//===============================================================================


#endif
