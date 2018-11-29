/**************************************************************************/
/* LabWindows/CVI User Interface Resource (UIR) Include File              */
/*                                                                        */
/* WARNING: Do not add to, delete from, or otherwise modify the contents  */
/*          of this include file.                                         */
/**************************************************************************/

#include <userint.h>

#ifdef __cplusplus
    extern "C" {
#endif

     /* Panels and Controls: */

#define  PANEL                            1       /* callback function: panelCB */
#define  PANEL_CMD_SELF_TEST_AUTO         2       /* control type: command, callback function: CMD_SELF_TEST_AUTO_callback */
#define  PANEL_CMD_SELF_TEST              3       /* control type: command, callback function: CMD_SELF_TEST_callback */
#define  PANEL_CMD_GO_TEST_UI             4       /* control type: command, callback function: CMD_GO_TEST_UI_callback */
#define  PANEL_CMD_ALL_RUN                5       /* control type: command, callback function: CMD_ALL_RUN_callback */
#define  PANEL_CMD_QUIT_MAIN              6       /* control type: command, callback function: CMD_QUIT_MAIN_callback */
#define  PANEL_CMD_RESET_MAIN             7       /* control type: command, callback function: CMD_RESET_MAIN_callback */
#define  PANEL_LED_3                      8       /* control type: LED, callback function: (none) */
#define  PANEL_LED_2                      9       /* control type: LED, callback function: (none) */
#define  PANEL_LED                        10      /* control type: LED, callback function: (none) */
#define  PANEL_NUMERICSLIDE               11      /* control type: scale, callback function: (none) */
#define  PANEL_DECORATION                 12      /* control type: deco, callback function: (none) */
#define  PANEL_DECORATION_2               13      /* control type: deco, callback function: (none) */
#define  PANEL_DECORATION_3               14      /* control type: deco, callback function: (none) */
#define  PANEL_TEXTMSG                    15      /* control type: textMsg, callback function: (none) */
#define  PANEL_TEXTMSG_2                  16      /* control type: textMsg, callback function: (none) */
#define  PANEL_DECORATION_4               17      /* control type: deco, callback function: (none) */
#define  PANEL_TEXTMSG_3                  18      /* control type: textMsg, callback function: (none) */
#define  PANEL_TEXTMSG_4                  19      /* control type: textMsg, callback function: (none) */
#define  PANEL_TEXTBOX                    20      /* control type: textBox, callback function: (none) */
#define  PANEL_BIN_POWER_OPRATION         21      /* control type: binary, callback function: BIN_POWER_OPRATION_callback */
#define  PANEL_NUMERIC_3                  22      /* control type: numeric, callback function: (none) */
#define  PANEL_NUMERIC_2                  23      /* control type: numeric, callback function: (none) */
#define  PANEL_NUMERIC                    24      /* control type: numeric, callback function: (none) */

#define  PANEL_2                          2
#define  PANEL_2_TEXTBOX_5                2       /* control type: textBox, callback function: (none) */
#define  PANEL_2_TEXTBOX_4                3       /* control type: textBox, callback function: (none) */
#define  PANEL_2_CMD_Mirco_AD_ALL_SELF    4       /* control type: command, callback function: CMD_Mirco_AD_ALL_SELF_callback */
#define  PANEL_2_Mir_429_All_Self_Test    5       /* control type: command, callback function: Mir_429_All_Self_Test_callback */
#define  PANEL_2_LED_8                    6       /* control type: LED, callback function: (none) */
#define  PANEL_2_TEXTBOX_3                7       /* control type: textBox, callback function: (none) */
#define  PANEL_2_STRING_5                 8       /* control type: string, callback function: (none) */
#define  PANEL_2_CMD_429_ROAD_3_SEND      9       /* control type: command, callback function: CMD_429_ROAD_3_SEND_callback */
#define  PANEL_2_LED_9                    10      /* control type: LED, callback function: (none) */
#define  PANEL_2_STRING_4                 11      /* control type: string, callback function: (none) */
#define  PANEL_2_STRING_3                 12      /* control type: string, callback function: (none) */
#define  PANEL_2_CMD_429_ROAD_1_SEND      13      /* control type: command, callback function: CMD_429_ROAD_1_SEND_callback */
#define  PANEL_2_CMD_MAIN_QUIT            14      /* control type: command, callback function: CMD_MAIN_QUIT_callback */
#define  PANEL_2_TABLE_2                  15      /* control type: table, callback function: MircoDIInputTable */
#define  PANEL_2_Miroc_429_Road_3_Test    16      /* control type: command, callback function: Miroc_429_Road_3_Test_callback */
#define  PANEL_2_LED_6                    17      /* control type: LED, callback function: (none) */
#define  PANEL_2_TABLE_4                  18      /* control type: table, callback function: MircoADInput */
#define  PANEL_2_TABLE                    19      /* control type: table, callback function: MircoDOOut */
#define  PANEL_2_Miroc_429_Road_2_Test    20      /* control type: command, callback function: Miroc_429_Road_2_Test_callback */
#define  PANEL_2_LED_4                    21      /* control type: LED, callback function: (none) */
#define  PANEL_2_NUMERIC_3                22      /* control type: numeric, callback function: (none) */
#define  PANEL_2_NUMERIC_2                23      /* control type: numeric, callback function: (none) */
#define  PANEL_2_NUMERIC                  24      /* control type: numeric, callback function: (none) */
#define  PANEL_2_Miroc_429_Road_1_Test    25      /* control type: command, callback function: Miroc_429_Road_1_Test_callback */
#define  PANEL_2_LED                      26      /* control type: LED, callback function: (none) */
#define  PANEL_2_CMD_PRINT                27      /* control type: command, callback function: CMD_PRINT_callback */
#define  PANEL_2_CMD_BEEP                 28      /* control type: command, callback function: CMD_BEEP_callback */
#define  PANEL_2_COMMANDBUTTON_6          29      /* control type: command, callback function: COMMANDBUTTON_6_callback */
#define  PANEL_2_CMD_RESET                30      /* control type: command, callback function: CMD_RESET_callback */
#define  PANEL_2_DECORATION               31      /* control type: deco, callback function: (none) */
#define  PANEL_2_TEXTMSG                  32      /* control type: textMsg, callback function: (none) */
#define  PANEL_2_DECORATION_2             33      /* control type: deco, callback function: (none) */
#define  PANEL_2_TEXTMSG_2                34      /* control type: textMsg, callback function: (none) */
#define  PANEL_2_DECORATION_3             35      /* control type: deco, callback function: (none) */
#define  PANEL_2_TEXTMSG_3                36      /* control type: textMsg, callback function: (none) */
#define  PANEL_2_DECORATION_5             37      /* control type: deco, callback function: (none) */
#define  PANEL_2_DECORATION_4             38      /* control type: deco, callback function: (none) */
#define  PANEL_2_TEXTMSG_5                39      /* control type: textMsg, callback function: (none) */
#define  PANEL_2_TEXTMSG_4                40      /* control type: textMsg, callback function: (none) */
#define  PANEL_2_CMD_429_ROAD_2_SEND      41      /* control type: command, callback function: CMD_429_ROAD_2_SEND_callback */
#define  PANEL_2_CMD_RS232_TEST           42      /* control type: command, callback function: CMD_RS232_TEST_callback */
#define  PANEL_2_LED_7                    43      /* control type: LED, callback function: (none) */
#define  PANEL_2_LED_2                    44      /* control type: LED, callback function: (none) */
#define  PANEL_2_DECORATION_7             45      /* control type: deco, callback function: (none) */
#define  PANEL_2_DECORATION_6             46      /* control type: deco, callback function: (none) */
#define  PANEL_2_BIN_POWER_UI             47      /* control type: binary, callback function: BIN_POWER_UI_callback */

#define  PANEL_3                          3
#define  PANEL_3_RING_5                   2       /* control type: ring, callback function: (none) */
#define  PANEL_3_RING_4                   3       /* control type: ring, callback function: (none) */
#define  PANEL_3_RING_3                   4       /* control type: ring, callback function: (none) */
#define  PANEL_3_RING_2                   5       /* control type: ring, callback function: (none) */
#define  PANEL_3_RING                     6       /* control type: ring, callback function: (none) */
#define  PANEL_3_OpenCom                  7       /* control type: binary, callback function: OpenCom_callback */
#define  PANEL_3_LED                      8       /* control type: LED, callback function: (none) */
#define  PANEL_3_TEXTBOX                  9       /* control type: textBox, callback function: (none) */
#define  PANEL_3_CMD_COM_RETURN_MAIN      10      /* control type: command, callback function: CMD_COM_RETURN_MAIN_callback */

#define  PANEL_4                          4
#define  PANEL_4_CMD_RESET_CALIBRATION    2       /* control type: command, callback function: CMD_RESET_CALIBRATION_callback */
#define  PANEL_4_CMD_SHOW_SELF_PRINT      3       /* control type: command, callback function: CMD_SHOW_SELF_PRINT_callback */
#define  PANEL_4_CMD_SELE_RETURN_MAIN     4       /* control type: command, callback function: CMD_SELE_RETURN_MAIN_callback */
#define  PANEL_4_DECORATION               5       /* control type: deco, callback function: (none) */
#define  PANEL_4_DECORATION_6             6       /* control type: deco, callback function: (none) */
#define  PANEL_4_DECORATION_5             7       /* control type: deco, callback function: (none) */
#define  PANEL_4_DECORATION_4             8       /* control type: deco, callback function: (none) */
#define  PANEL_4_DECORATION_3             9       /* control type: deco, callback function: (none) */
#define  PANEL_4_TEXTMSG                  10      /* control type: textMsg, callback function: (none) */
#define  PANEL_4_TEXTMSG_6                11      /* control type: textMsg, callback function: (none) */
#define  PANEL_4_TEXTMSG_5                12      /* control type: textMsg, callback function: (none) */
#define  PANEL_4_TEXTMSG_4                13      /* control type: textMsg, callback function: (none) */
#define  PANEL_4_TEXTMSG_3                14      /* control type: textMsg, callback function: (none) */
#define  PANEL_4_TABLE_2                  15      /* control type: table, callback function: MircoDIInputTableCalibration */
#define  PANEL_4_TABLE                    16      /* control type: table, callback function: MircoDOOutCalibration */
#define  PANEL_4_TABLE_4                  17      /* control type: table, callback function: MircoADInputCalibration */
#define  PANEL_4_BIN_OPERATION_POWER_C    18      /* control type: binary, callback function: BIN_OPERATION_POWER_C_callback */

#define  PANEL_5                          5       /* callback function: PanelPrintCB */
#define  PANEL_5_REPORTX                  2       /* control type: activeX, callback function: (none) */

#define  PANEL_6                          6
#define  PANEL_6_REPORTX                  2       /* control type: activeX, callback function: (none) */

#define  PANEL_7                          7
#define  PANEL_7_CMD_SHOWTESTUI           2       /* control type: command, callback function: CMD_SHOWTESTUI_callback */
#define  PANEL_7_CMD_SHOWPRINT            3       /* control type: command, callback function: CMD_SHOWPRINT_callback */
#define  PANEL_7_CMD_RETURN_MAIN          4       /* control type: command, callback function: CMD_RETURN_MAIN_callback */


     /* Control Arrays: */

          /* (no control arrays in the resource file) */


     /* Menu Bars, Menus, and Menu Items: */

#define  MENUBAR                          1
#define  MENUBAR_FILEOPERATION            2
#define  MENUBAR_FILEOPERATION_FILEPRINT  3       /* callback function: FilePrint */
#define  MENUBAR_FILEOPERATION_FILEOUTEXCEL 4     /* callback function: FileOutExcel */
#define  MENUBAR_FILEOPERATION_FILERETURN 5       /* callback function: FileReturn */


     /* Callback Prototypes: */

int  CVICALLBACK BIN_OPERATION_POWER_C_callback(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK BIN_POWER_OPRATION_callback(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK BIN_POWER_UI_callback(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK CMD_429_ROAD_1_SEND_callback(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK CMD_429_ROAD_2_SEND_callback(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK CMD_429_ROAD_3_SEND_callback(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK CMD_ALL_RUN_callback(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK CMD_BEEP_callback(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK CMD_COM_RETURN_MAIN_callback(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK CMD_GO_TEST_UI_callback(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK CMD_MAIN_QUIT_callback(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK CMD_Mirco_AD_ALL_SELF_callback(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK CMD_PRINT_callback(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK CMD_QUIT_MAIN_callback(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK CMD_RESET_CALIBRATION_callback(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK CMD_RESET_callback(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK CMD_RESET_MAIN_callback(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK CMD_RETURN_MAIN_callback(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK CMD_RS232_TEST_callback(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK CMD_SELE_RETURN_MAIN_callback(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK CMD_SELF_TEST_AUTO_callback(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK CMD_SELF_TEST_callback(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK CMD_SHOW_SELF_PRINT_callback(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK CMD_SHOWPRINT_callback(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK CMD_SHOWTESTUI_callback(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK COMMANDBUTTON_6_callback(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
void CVICALLBACK FileOutExcel(int menubar, int menuItem, void *callbackData, int panel);
void CVICALLBACK FilePrint(int menubar, int menuItem, void *callbackData, int panel);
void CVICALLBACK FileReturn(int menubar, int menuItem, void *callbackData, int panel);
int  CVICALLBACK Mir_429_All_Self_Test_callback(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK MircoADInput(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK MircoADInputCalibration(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK MircoDIInputTable(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK MircoDIInputTableCalibration(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK MircoDOOut(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK MircoDOOutCalibration(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK Miroc_429_Road_1_Test_callback(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK Miroc_429_Road_2_Test_callback(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK Miroc_429_Road_3_Test_callback(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK OpenCom_callback(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK panelCB(int panel, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK PanelPrintCB(int panel, int event, void *callbackData, int eventData1, int eventData2);


#ifdef __cplusplus
    }
#endif
