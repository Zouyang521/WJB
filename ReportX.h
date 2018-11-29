#ifndef _REPORTPROJ1_H
#define _REPORTPROJ1_H

#include <cviauto.h>

#ifdef __cplusplus
    extern "C" {
#endif
/* NICDBLD_BEGIN> Type Library Specific Types */

enum ReportProj1Enum_TxActiveFormBorderStyle
{
	ReportProj1Const_afbNone = 0,
	ReportProj1Const_afbSingle = 1,
	ReportProj1Const_afbSunken = 2,
	ReportProj1Const_afbRaised = 3,
	_ReportProj1_TxActiveFormBorderStyleForceSizeToFourBytes = 0xFFFFFFFF
};
enum ReportProj1Enum_TxPrintScale
{
	ReportProj1Const_poNone = 0,
	ReportProj1Const_poProportional = 1,
	ReportProj1Const_poPrintToFit = 2,
	_ReportProj1_TxPrintScaleForceSizeToFourBytes = 0xFFFFFFFF
};
enum ReportProj1Enum_TxHelpType
{
	ReportProj1Const_htKeyword = 0,
	ReportProj1Const_htContext = 1,
	_ReportProj1_TxHelpTypeForceSizeToFourBytes = 0xFFFFFFFF
};
enum ReportProj1Enum_TxMouseButton
{
	ReportProj1Const_mbLeft = 0,
	ReportProj1Const_mbRight = 1,
	ReportProj1Const_mbMiddle = 2,
	_ReportProj1_TxMouseButtonForceSizeToFourBytes = 0xFFFFFFFF
};
typedef unsigned long ReportProj1Type_OLE_COLOR;
typedef CAObjHandle ReportProj1Obj_Font;
typedef CAObjHandle ReportProj1Obj_IFontDisp;
typedef HRESULT (CVICALLBACK *IReportXEventsRegOnOnActivate_CallbackType) (CAObjHandle caServerObjHandle,
                                                                           void *caCallbackData);
typedef HRESULT (CVICALLBACK *IReportXEventsRegOnOnClick_CallbackType) (CAObjHandle caServerObjHandle,
                                                                        void *caCallbackData);
typedef HRESULT (CVICALLBACK *IReportXEventsRegOnOnCreate_CallbackType) (CAObjHandle caServerObjHandle,
                                                                         void *caCallbackData);
typedef HRESULT (CVICALLBACK *IReportXEventsRegOnOnDblClick_CallbackType) (CAObjHandle caServerObjHandle,
                                                                           void *caCallbackData);
typedef HRESULT (CVICALLBACK *IReportXEventsRegOnOnDestroy_CallbackType) (CAObjHandle caServerObjHandle,
                                                                          void *caCallbackData);
typedef HRESULT (CVICALLBACK *IReportXEventsRegOnOnDeactivate_CallbackType) (CAObjHandle caServerObjHandle,
                                                                             void *caCallbackData);
typedef HRESULT (CVICALLBACK *IReportXEventsRegOnOnKeyPress_CallbackType) (CAObjHandle caServerObjHandle,
                                                                           void *caCallbackData,
                                                                           short *key);
typedef HRESULT (CVICALLBACK *IReportXEventsRegOnOnPaint_CallbackType) (CAObjHandle caServerObjHandle,
                                                                        void *caCallbackData);
typedef HRESULT (CVICALLBACK *IReportXEventsRegOnOnSelectChange_CallbackType) (CAObjHandle caServerObjHandle,
                                                                               void *caCallbackData,
                                                                               long  aCol1,
                                                                               long  aRow1,
                                                                               long  aCol2,
                                                                               long  aRow2,
                                                                               long *__returnValue);
typedef HRESULT (CVICALLBACK *IReportXEventsRegOnOnInputChange_CallbackType) (CAObjHandle caServerObjHandle,
                                                                              void *caCallbackData,
                                                                              long  aCol,
                                                                              long  aRow,
                                                                              long *__returnValue);
typedef HRESULT (CVICALLBACK *IReportXEventsRegOnOnPoleLUp_CallbackType) (CAObjHandle caServerObjHandle,
                                                                          void *caCallbackData,
                                                                          long  aIndex,
                                                                          long  aOrientation,
                                                                          long *__returnValue);
typedef HRESULT (CVICALLBACK *IReportXEventsRegOnOnPoleRDown_CallbackType) (CAObjHandle caServerObjHandle,
                                                                            void *caCallbackData,
                                                                            long  aIndex,
                                                                            long  aOrientation,
                                                                            long  aScreenX,
                                                                            long  aScreenY,
                                                                            long *__returnValue);
typedef HRESULT (CVICALLBACK *IReportXEventsRegOnOnCellLUp_CallbackType) (CAObjHandle caServerObjHandle,
                                                                          void *caCallbackData,
                                                                          long  aCol,
                                                                          long  aRow,
                                                                          long *__returnValue);
typedef HRESULT (CVICALLBACK *IReportXEventsRegOnOnCellRDown_CallbackType) (CAObjHandle caServerObjHandle,
                                                                            void *caCallbackData,
                                                                            long  aCol,
                                                                            long  aRow,
                                                                            long  aScreenX,
                                                                            long  aScreenY,
                                                                            long *__returnValue);
typedef HRESULT (CVICALLBACK *IReportXEventsRegOnOnCellDblCLick_CallbackType) (CAObjHandle caServerObjHandle,
                                                                               void *caCallbackData,
                                                                               long  aCol,
                                                                               long  aRow,
                                                                               long *__returnValue);
typedef HRESULT (CVICALLBACK *IReportXEventsRegOnOnCellChanged_CallbackType) (CAObjHandle caServerObjHandle,
                                                                              void *caCallbackData,
                                                                              long  aCol,
                                                                              long  aRow,
                                                                              char *aCellValue,
                                                                              long *__returnValue);
typedef HRESULT (CVICALLBACK *IReportXEventsRegOnOnCellChanging_CallbackType) (CAObjHandle caServerObjHandle,
                                                                               void *caCallbackData,
                                                                               long  aCol,
                                                                               long  aRow,
                                                                               char **cellValue,
                                                                               VBOOL *cellChange,
                                                                               long *__returnValue);
typedef HRESULT (CVICALLBACK *IReportXEventsRegOnOnLeftChange_CallbackType) (CAObjHandle caServerObjHandle,
                                                                             void *caCallbackData,
                                                                             long  aIndex,
                                                                             long *__returnValue);
typedef HRESULT (CVICALLBACK *IReportXEventsRegOnOnTopChange_CallbackType) (CAObjHandle caServerObjHandle,
                                                                            void *caCallbackData,
                                                                            long  aIndex,
                                                                            long *__returnValue);
typedef HRESULT (CVICALLBACK *IReportXEventsRegOnOnError_CallbackType) (CAObjHandle caServerObjHandle,
                                                                        void *caCallbackData,
                                                                        char *aMessage,
                                                                        long *__returnValue);
typedef HRESULT (CVICALLBACK *IReportXEventsRegOnOnBeginPrintDoc_CallbackType) (CAObjHandle caServerObjHandle,
                                                                                void *caCallbackData,
                                                                                long  aPrinter,
                                                                                char **title,
                                                                                VBOOL *titleChange,
                                                                                long *__returnValue);
typedef HRESULT (CVICALLBACK *IReportXEventsRegOnOnEndPrintDoc_CallbackType) (CAObjHandle caServerObjHandle,
                                                                              void *caCallbackData,
                                                                              long  aPrinter,
                                                                              long *__returnValue);
typedef HRESULT (CVICALLBACK *IReportXEventsRegOnOnSelectObject_CallbackType) (CAObjHandle caServerObjHandle,
                                                                               void *caCallbackData,
                                                                               long  objectType,
                                                                               char *objectName,
                                                                               long *__returnValue);
typedef HRESULT (CVICALLBACK *IReportXEventsRegOnOnObjectRDown_CallbackType) (CAObjHandle caServerObjHandle,
                                                                              void *caCallbackData,
                                                                              long  aObjectType,
                                                                              char *aObjectName,
                                                                              long  aScreenX,
                                                                              long  aScreenY,
                                                                              long *__returnValue);
typedef HRESULT (CVICALLBACK *IReportXEventsRegOnOnButtonClick_CallbackType) (CAObjHandle caServerObjHandle,
                                                                              void *caCallbackData,
                                                                              long  aCol,
                                                                              long  aRow,
                                                                              char *aButtonText,
                                                                              char **buttonScript,
                                                                              long *__returnValue);
typedef HRESULT (CVICALLBACK *IReportXEventsRegOnOnAdjustedSeries_CallbackType) (CAObjHandle caServerObjHandle,
                                                                                 void *caCallbackData,
                                                                                 char *aChartName,
                                                                                 long  aIndex,
                                                                                 long  aSeriesType,
                                                                                 char *aSeriesSignText,
                                                                                 char *aSeriesDataText,
                                                                                 char *aSeriesCell,
                                                                                 long *__returnValue);
typedef HRESULT (CVICALLBACK *IReportXEventsRegOnOnDropDown_CallbackType) (CAObjHandle caServerObjHandle,
                                                                           void *caCallbackData,
                                                                           long  aCol,
                                                                           long  aRow,
                                                                           char **listText,
                                                                           long *__returnValue);
typedef HRESULT (CVICALLBACK *IReportXEventsRegOnOnCellLDown_CallbackType) (CAObjHandle caServerObjHandle,
                                                                            void *caCallbackData,
                                                                            long  aCol,
                                                                            long  aRow,
                                                                            long *__returnValue);
typedef HRESULT (CVICALLBACK *IReportXEventsRegOnOnPoleLDown_CallbackType) (CAObjHandle caServerObjHandle,
                                                                            void *caCallbackData,
                                                                            long  aIndex,
                                                                            long  aOrientation,
                                                                            long *__returnValue);
typedef HRESULT (CVICALLBACK *IReportXEventsRegOnOnPreviewShow_CallbackType) (CAObjHandle caServerObjHandle,
                                                                              void *caCallbackData,
                                                                              long  aPrinter,
                                                                              char **previewParameter,
                                                                              VBOOL *previewChange,
                                                                              long *__returnValue);
/* NICDBLD_END> Type Library Specific Types */

extern const IID ReportProj1_IID_IReportX;
extern const IID ReportProj1_IID_IReportXEvents;

HRESULT CVIFUNC ReportProj1_NewIReportX (int panel, const char *label, int top,
                                         int left, int *controlID, int *UILError);

HRESULT CVIFUNC ReportProj1_IReportXGetVisible (CAObjHandle objectHandle,
                                                ERRORINFO *errorInfo,
                                                VBOOL *value);

HRESULT CVIFUNC ReportProj1_IReportXSetVisible (CAObjHandle objectHandle,
                                                ERRORINFO *errorInfo,
                                                VBOOL value);

HRESULT CVIFUNC ReportProj1_IReportXGetAutoScroll (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   VBOOL *value);

HRESULT CVIFUNC ReportProj1_IReportXSetAutoScroll (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   VBOOL value);

HRESULT CVIFUNC ReportProj1_IReportXGetAutoSize (CAObjHandle objectHandle,
                                                 ERRORINFO *errorInfo,
                                                 VBOOL *value);

HRESULT CVIFUNC ReportProj1_IReportXSetAutoSize (CAObjHandle objectHandle,
                                                 ERRORINFO *errorInfo,
                                                 VBOOL value);

HRESULT CVIFUNC ReportProj1_IReportXGetAxBorderStyle (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      enum ReportProj1Enum_TxActiveFormBorderStyle *value);

HRESULT CVIFUNC ReportProj1_IReportXSetAxBorderStyle (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      enum ReportProj1Enum_TxActiveFormBorderStyle value);

HRESULT CVIFUNC ReportProj1_IReportXGetCaption (CAObjHandle objectHandle,
                                                ERRORINFO *errorInfo,
                                                char **value);

HRESULT CVIFUNC ReportProj1_IReportXSetCaption (CAObjHandle objectHandle,
                                                ERRORINFO *errorInfo,
                                                const char *value);

HRESULT CVIFUNC ReportProj1_IReportXGetColor (CAObjHandle objectHandle,
                                              ERRORINFO *errorInfo,
                                              ReportProj1Type_OLE_COLOR *value);

HRESULT CVIFUNC ReportProj1_IReportXSetColor (CAObjHandle objectHandle,
                                              ERRORINFO *errorInfo,
                                              ReportProj1Type_OLE_COLOR value);

HRESULT CVIFUNC ReportProj1_IReportXGetFont (CAObjHandle objectHandle,
                                             ERRORINFO *errorInfo,
                                             ReportProj1Obj_IFontDisp *value);

HRESULT CVIFUNC ReportProj1_IReportXSetFont (CAObjHandle objectHandle,
                                             ERRORINFO *errorInfo,
                                             ReportProj1Obj_IFontDisp value);

HRESULT CVIFUNC ReportProj1_IReportXSetByRefFont (CAObjHandle objectHandle,
                                                  ERRORINFO *errorInfo,
                                                  ReportProj1Obj_IFontDisp *value);

HRESULT CVIFUNC ReportProj1_IReportXGetKeyPreview (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   VBOOL *value);

HRESULT CVIFUNC ReportProj1_IReportXSetKeyPreview (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   VBOOL value);

HRESULT CVIFUNC ReportProj1_IReportXGetPixelsPerInch (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      long *value);

HRESULT CVIFUNC ReportProj1_IReportXSetPixelsPerInch (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      long value);

HRESULT CVIFUNC ReportProj1_IReportXGetPrintScale (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   enum ReportProj1Enum_TxPrintScale *value);

HRESULT CVIFUNC ReportProj1_IReportXSetPrintScale (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   enum ReportProj1Enum_TxPrintScale value);

HRESULT CVIFUNC ReportProj1_IReportXGetScaled (CAObjHandle objectHandle,
                                               ERRORINFO *errorInfo,
                                               VBOOL *value);

HRESULT CVIFUNC ReportProj1_IReportXSetScaled (CAObjHandle objectHandle,
                                               ERRORINFO *errorInfo, VBOOL value);

HRESULT CVIFUNC ReportProj1_IReportXGetActive (CAObjHandle objectHandle,
                                               ERRORINFO *errorInfo,
                                               VBOOL *value);

HRESULT CVIFUNC ReportProj1_IReportXGetDropTarget (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   VBOOL *value);

HRESULT CVIFUNC ReportProj1_IReportXSetDropTarget (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   VBOOL value);

HRESULT CVIFUNC ReportProj1_IReportXGetHelpFile (CAObjHandle objectHandle,
                                                 ERRORINFO *errorInfo,
                                                 char **value);

HRESULT CVIFUNC ReportProj1_IReportXSetHelpFile (CAObjHandle objectHandle,
                                                 ERRORINFO *errorInfo,
                                                 const char *value);

HRESULT CVIFUNC ReportProj1_IReportXGetDoubleBuffered (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       VBOOL *value);

HRESULT CVIFUNC ReportProj1_IReportXSetDoubleBuffered (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       VBOOL value);

HRESULT CVIFUNC ReportProj1_IReportXGetAlignDisabled (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      VBOOL *value);

HRESULT CVIFUNC ReportProj1_IReportXGetVisibleDockClientCount (CAObjHandle objectHandle,
                                                               ERRORINFO *errorInfo,
                                                               long *value);

HRESULT CVIFUNC ReportProj1_IReportXGetEnabled (CAObjHandle objectHandle,
                                                ERRORINFO *errorInfo,
                                                VBOOL *value);

HRESULT CVIFUNC ReportProj1_IReportXSetEnabled (CAObjHandle objectHandle,
                                                ERRORINFO *errorInfo,
                                                VBOOL value);

HRESULT CVIFUNC ReportProj1_IReportXGetCursor (CAObjHandle objectHandle,
                                               ERRORINFO *errorInfo,
                                               short *value);

HRESULT CVIFUNC ReportProj1_IReportXSetCursor (CAObjHandle objectHandle,
                                               ERRORINFO *errorInfo, short value);

HRESULT CVIFUNC ReportProj1_IReportXGetHelpType (CAObjHandle objectHandle,
                                                 ERRORINFO *errorInfo,
                                                 enum ReportProj1Enum_TxHelpType *value);

HRESULT CVIFUNC ReportProj1_IReportXSetHelpType (CAObjHandle objectHandle,
                                                 ERRORINFO *errorInfo,
                                                 enum ReportProj1Enum_TxHelpType value);

HRESULT CVIFUNC ReportProj1_IReportXGetHelpKeyword (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    char **value);

HRESULT CVIFUNC ReportProj1_IReportXSetHelpKeyword (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    const char *value);

HRESULT CVIFUNC ReportProj1_IReportXInsertCol (CAObjHandle objectHandle,
                                               ERRORINFO *errorInfo, long aCol,
                                               long aCount);

HRESULT CVIFUNC ReportProj1_IReportXInsertRow (CAObjHandle objectHandle,
                                               ERRORINFO *errorInfo, long aRow,
                                               long aCount);

HRESULT CVIFUNC ReportProj1_IReportXAppendCol (CAObjHandle objectHandle,
                                               ERRORINFO *errorInfo, long aCount);

HRESULT CVIFUNC ReportProj1_IReportXAppendRow (CAObjHandle objectHandle,
                                               ERRORINFO *errorInfo, long aCount);

HRESULT CVIFUNC ReportProj1_IReportXDeleteCol (CAObjHandle objectHandle,
                                               ERRORINFO *errorInfo, long aCol,
                                               long aCount);

HRESULT CVIFUNC ReportProj1_IReportXDeleteRow (CAObjHandle objectHandle,
                                               ERRORINFO *errorInfo, long aRow,
                                               long aCount);

HRESULT CVIFUNC ReportProj1_IReportXMergeCell (CAObjHandle objectHandle,
                                               ERRORINFO *errorInfo, long aCol1,
                                               long aRow1, long aCol2,
                                               long aRow2);

HRESULT CVIFUNC ReportProj1_IReportXSplitCell (CAObjHandle objectHandle,
                                               ERRORINFO *errorInfo, long aCol1,
                                               long aRow1, long aCol2,
                                               long aRow2);

HRESULT CVIFUNC ReportProj1_IReportXSaveReport (CAObjHandle objectHandle,
                                                ERRORINFO *errorInfo,
                                                const char *aFileName);

HRESULT CVIFUNC ReportProj1_IReportXOpenReport (CAObjHandle objectHandle,
                                                ERRORINFO *errorInfo,
                                                const char *aFileName);

HRESULT CVIFUNC ReportProj1_IReportXCutCell (CAObjHandle objectHandle,
                                             ERRORINFO *errorInfo, long aCol1,
                                             long aRow1, long aCol2, long aRow2);

HRESULT CVIFUNC ReportProj1_IReportXCopyCell (CAObjHandle objectHandle,
                                              ERRORINFO *errorInfo, long aCol1,
                                              long aRow1, long aCol2, long aRow2);

HRESULT CVIFUNC ReportProj1_IReportXPaste (CAObjHandle objectHandle,
                                           ERRORINFO *errorInfo, long aCol,
                                           long aRow, VBOOL aSize);

HRESULT CVIFUNC ReportProj1_IReportXSetCellFontName (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     long aCol, long aRow,
                                                     const char *aFontName);

HRESULT CVIFUNC ReportProj1_IReportXSetCellFontSize (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     long aCol, long aRow,
                                                     long aFontSize);

HRESULT CVIFUNC ReportProj1_IReportXSetCellFontColor (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      long aCol, long aRow,
                                                      long aFontColor);

HRESULT CVIFUNC ReportProj1_IReportXSetCellFontStyle (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      long aCol, long aRow,
                                                      long aFontStyle,
                                                      VBOOL aStyleBool);

HRESULT CVIFUNC ReportProj1_IReportXGetCellFontName (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     long aCol, long aRow,
                                                     char **value);

HRESULT CVIFUNC ReportProj1_IReportXGetCellFontSize (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     long aCol, long aRow,
                                                     long *value);

HRESULT CVIFUNC ReportProj1_IReportXGetCellFontColor (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      long aCol, long aRow,
                                                      long *value);

HRESULT CVIFUNC ReportProj1_IReportXGetCellFontStyle (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      long aCol, long aRow,
                                                      long aFontStyle,
                                                      VBOOL *value);

HRESULT CVIFUNC ReportProj1_IReportXSetCellHAlignment (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       long aCol, long aRow,
                                                       long aHAlignment);

HRESULT CVIFUNC ReportProj1_IReportXSetCellVAlignment (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       long aCol, long aRow,
                                                       long aVAlignment);

HRESULT CVIFUNC ReportProj1_IReportXGetCellHAlignment (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       long aCol, long aRow,
                                                       long *value);

HRESULT CVIFUNC ReportProj1_IReportXGetCellVAlignment (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       long aCol, long aRow,
                                                       long *value);

HRESULT CVIFUNC ReportProj1_IReportXSetCellMultiline (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      long aCol, long aRow,
                                                      VBOOL aMultiline);

HRESULT CVIFUNC ReportProj1_IReportXGetCellMultiline (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      long aCol, long aRow,
                                                      VBOOL *value);

HRESULT CVIFUNC ReportProj1_IReportXPrintPreview (CAObjHandle objectHandle,
                                                  ERRORINFO *errorInfo);

HRESULT CVIFUNC ReportProj1_IReportXSetColWidth (CAObjHandle objectHandle,
                                                 ERRORINFO *errorInfo, long aCol,
                                                 long aWidth);

HRESULT CVIFUNC ReportProj1_IReportXSetRowHeight (CAObjHandle objectHandle,
                                                  ERRORINFO *errorInfo,
                                                  long aRow, long aHeight);

HRESULT CVIFUNC ReportProj1_IReportXSetTextCell (CAObjHandle objectHandle,
                                                 ERRORINFO *errorInfo, long aCol,
                                                 long aRow);

HRESULT CVIFUNC ReportProj1_IReportXSetDropCell (CAObjHandle objectHandle,
                                                 ERRORINFO *errorInfo, long aCol,
                                                 long aRow,
                                                 const char *aListText);

HRESULT CVIFUNC ReportProj1_IReportXSetButtonCell (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   long aCol, long aRow,
                                                   const char *aButtonText,
                                                   const char *aButtonScript);

HRESULT CVIFUNC ReportProj1_IReportXSetCheckCell (CAObjHandle objectHandle,
                                                  ERRORINFO *errorInfo,
                                                  long aCol, long aRow,
                                                  const char *aCheckText);

HRESULT CVIFUNC ReportProj1_IReportXSetRadioCell (CAObjHandle objectHandle,
                                                  ERRORINFO *errorInfo,
                                                  long aCol, long aRow,
                                                  const char *aRadioText);

HRESULT CVIFUNC ReportProj1_IReportXAddObjectChart (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    long aCol, long aRow,
                                                    const char *aChartName,
                                                    long aWidth, long aHeight,
                                                    const char *aTitleText,
                                                    const char *aHorizontalText,
                                                    const char *aVerticalText,
                                                    char **value);

HRESULT CVIFUNC ReportProj1_IReportXSetDateCell (CAObjHandle objectHandle,
                                                 ERRORINFO *errorInfo, long aCol,
                                                 long aRow);

HRESULT CVIFUNC ReportProj1_IReportXSetCellFormat (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   long aCol, long aRow,
                                                   long aFormatType,
                                                   const char *aFormatText);

HRESULT CVIFUNC ReportProj1_IReportXGetCellFormat (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   long aCol, long aRow,
                                                   long *formatType,
                                                   char **formatText);

HRESULT CVIFUNC ReportProj1_IReportXSetCellIme (CAObjHandle objectHandle,
                                                ERRORINFO *errorInfo, long aCol,
                                                long aRow, const char *aImeName);

HRESULT CVIFUNC ReportProj1_IReportXGetCellIme (CAObjHandle objectHandle,
                                                ERRORINFO *errorInfo, long aCol,
                                                long aRow, char **value);

HRESULT CVIFUNC ReportProj1_IReportXSetCellControl (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    long aCol, long aRow,
                                                    long aControlType);

HRESULT CVIFUNC ReportProj1_IReportXGetCellControl (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    long aCol, long aRow,
                                                    long *value);

HRESULT CVIFUNC ReportProj1_IReportXSetCellBorder (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   long aCol, long aRow,
                                                   long aBorderType,
                                                   long aBorderWidth,
                                                   long aBorderStyle);

HRESULT CVIFUNC ReportProj1_IReportXGetCellBorder (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   long aCol, long aRow,
                                                   long aBorderType,
                                                   long *borderWidth,
                                                   long *borderStyle);

HRESULT CVIFUNC ReportProj1_IReportXDelObjectChart (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    const char *aChartName);

HRESULT CVIFUNC ReportProj1_IReportXAddChartSeries (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    const char *aChartName,
                                                    long aSeriesType,
                                                    const char *aSeriesSignText,
                                                    const char *aSeriesDataText,
                                                    const char *aSeriesCell);

HRESULT CVIFUNC ReportProj1_IReportXAddCellPicture (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    long aCol, long aRow,
                                                    const char *aFileName,
                                                    VBOOL aStretch);

HRESULT CVIFUNC ReportProj1_IReportXSetTimeCell (CAObjHandle objectHandle,
                                                 ERRORINFO *errorInfo, long aCol,
                                                 long aRow);

HRESULT CVIFUNC ReportProj1_IReportXGetDisplayColCount (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        long *value);

HRESULT CVIFUNC ReportProj1_IReportXGetDisplayRowCount (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        long *value);

HRESULT CVIFUNC ReportProj1_IReportXGetSaved (CAObjHandle objectHandle,
                                              ERRORINFO *errorInfo, VBOOL *value);

HRESULT CVIFUNC ReportProj1_IReportXSetSaved (CAObjHandle objectHandle,
                                              ERRORINFO *errorInfo, VBOOL value);

HRESULT CVIFUNC ReportProj1_IReportXGetSeparatorLine (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      VBOOL *value);

HRESULT CVIFUNC ReportProj1_IReportXSetSeparatorLine (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      VBOOL value);

HRESULT CVIFUNC ReportProj1_IReportXSetFrozenCol (CAObjHandle objectHandle,
                                                  ERRORINFO *errorInfo,
                                                  long aFrozenStart,
                                                  long aFrozenEnd);

HRESULT CVIFUNC ReportProj1_IReportXSetFrozenRow (CAObjHandle objectHandle,
                                                  ERRORINFO *errorInfo,
                                                  long aFrozenStart,
                                                  long aFrozenEnd);

HRESULT CVIFUNC ReportProj1_IReportXSetLinkCell (CAObjHandle objectHandle,
                                                 ERRORINFO *errorInfo, long aCol,
                                                 long aRow,
                                                 const char *aLinkText,
                                                 const char *aLinkAddress);

HRESULT CVIFUNC ReportProj1_IReportXSetCellBackColor (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      long aCol, long aRow,
                                                      long aBackColor);

HRESULT CVIFUNC ReportProj1_IReportXGetCellBackColor (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      long aCol, long aRow,
                                                      long *value);

HRESULT CVIFUNC ReportProj1_IReportXGetColWidth (CAObjHandle objectHandle,
                                                 ERRORINFO *errorInfo, long aCol,
                                                 long *value);

HRESULT CVIFUNC ReportProj1_IReportXGetRowHeight (CAObjHandle objectHandle,
                                                  ERRORINFO *errorInfo,
                                                  long aRow, long *value);

HRESULT CVIFUNC ReportProj1_IReportXSetCellReadOnly (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     long aCol, long aRow,
                                                     VBOOL aReadOnly);

HRESULT CVIFUNC ReportProj1_IReportXGetCellReadOnly (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     long aCol, long aRow,
                                                     VBOOL *value);

HRESULT CVIFUNC ReportProj1_IReportXClearChartSeries (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      const char *aChartName);

HRESULT CVIFUNC ReportProj1_IReportXSetCellAlias (CAObjHandle objectHandle,
                                                  ERRORINFO *errorInfo,
                                                  long aCol, long aRow,
                                                  const char *aAlias);

HRESULT CVIFUNC ReportProj1_IReportXGetCellAlias (CAObjHandle objectHandle,
                                                  ERRORINFO *errorInfo,
                                                  long aCol, long aRow,
                                                  char **value);

HRESULT CVIFUNC ReportProj1_IReportXSetCellValue (CAObjHandle objectHandle,
                                                  ERRORINFO *errorInfo,
                                                  long aCol, long aRow,
                                                  const char *aValue);

HRESULT CVIFUNC ReportProj1_IReportXGetCellValue (CAObjHandle objectHandle,
                                                  ERRORINFO *errorInfo,
                                                  long aCol, long aRow,
                                                  char **value);

HRESULT CVIFUNC ReportProj1_IReportXGetPoleWidth (CAObjHandle objectHandle,
                                                  ERRORINFO *errorInfo,
                                                  long *value);

HRESULT CVIFUNC ReportProj1_IReportXSetPoleWidth (CAObjHandle objectHandle,
                                                  ERRORINFO *errorInfo,
                                                  long value);

HRESULT CVIFUNC ReportProj1_IReportXGetPoleHeight (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   long *value);

HRESULT CVIFUNC ReportProj1_IReportXSetPoleHeight (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   long value);

HRESULT CVIFUNC ReportProj1_IReportXGetColCount (CAObjHandle objectHandle,
                                                 ERRORINFO *errorInfo,
                                                 long *value);

HRESULT CVIFUNC ReportProj1_IReportXSetColCount (CAObjHandle objectHandle,
                                                 ERRORINFO *errorInfo,
                                                 long value);

HRESULT CVIFUNC ReportProj1_IReportXGetRowCount (CAObjHandle objectHandle,
                                                 ERRORINFO *errorInfo,
                                                 long *value);

HRESULT CVIFUNC ReportProj1_IReportXSetRowCount (CAObjHandle objectHandle,
                                                 ERRORINFO *errorInfo,
                                                 long value);

HRESULT CVIFUNC ReportProj1_IReportXGetLeftCol (CAObjHandle objectHandle,
                                                ERRORINFO *errorInfo,
                                                long *value);

HRESULT CVIFUNC ReportProj1_IReportXSetLeftCol (CAObjHandle objectHandle,
                                                ERRORINFO *errorInfo, long value);

HRESULT CVIFUNC ReportProj1_IReportXGetTopRow (CAObjHandle objectHandle,
                                               ERRORINFO *errorInfo, long *value);

HRESULT CVIFUNC ReportProj1_IReportXSetTopRow (CAObjHandle objectHandle,
                                               ERRORINFO *errorInfo, long value);

HRESULT CVIFUNC ReportProj1_IReportXPrintSheet (CAObjHandle objectHandle,
                                                ERRORINFO *errorInfo,
                                                VBOOL aDialog);

HRESULT CVIFUNC ReportProj1_IReportXPrintSetup (CAObjHandle objectHandle,
                                                ERRORINFO *errorInfo);

HRESULT CVIFUNC ReportProj1_IReportXImportXML (CAObjHandle objectHandle,
                                               ERRORINFO *errorInfo,
                                               const char *aXML);

HRESULT CVIFUNC ReportProj1_IReportXExportXML (CAObjHandle objectHandle,
                                               ERRORINFO *errorInfo, long aType,
                                               const char *aEncoding,
                                               char **value);

HRESULT CVIFUNC ReportProj1_IReportXInvalidatePaint (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo);

HRESULT CVIFUNC ReportProj1_IReportXValidatePaint (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo);

HRESULT CVIFUNC ReportProj1_IReportXGetPainted (CAObjHandle objectHandle,
                                                ERRORINFO *errorInfo,
                                                VBOOL *value);

HRESULT CVIFUNC ReportProj1_IReportXSetPainted (CAObjHandle objectHandle,
                                                ERRORINFO *errorInfo,
                                                VBOOL value);

HRESULT CVIFUNC ReportProj1_IReportXSetCellExpression (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       long aCol, long aRow,
                                                       const char *aExpression);

HRESULT CVIFUNC ReportProj1_IReportXGetCellExpression (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       long aCol, long aRow,
                                                       char **value);

HRESULT CVIFUNC ReportProj1_IReportXExplainCellExpression (CAObjHandle objectHandle,
                                                           ERRORINFO *errorInfo,
                                                           long aCol, long aRow);

HRESULT CVIFUNC ReportProj1_IReportXExplainAllExpresion (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo,
                                                         long aOrder);

HRESULT CVIFUNC ReportProj1_IReportXExportExcel (CAObjHandle objectHandle,
                                                 ERRORINFO *errorInfo,
                                                 const char *aFileName,
                                                 const char *aSheetName,
                                                 VBOOL aDisplayValue);

HRESULT CVIFUNC ReportProj1_IReportXExportExcelOle (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    const char *aFileName,
                                                    long aCol1, long aRow1,
                                                    long aCol2, long aRow2,
                                                    const char *aSheetName,
                                                    VBOOL aOleText);

HRESULT CVIFUNC ReportProj1_IReportXImportExcelOle (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    const char *aFileName,
                                                    long aCol1, long aRow1,
                                                    long aCol2, long aRow2,
                                                    VBOOL aOleText);

HRESULT CVIFUNC ReportProj1_IReportXSetCellScript (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   long aCol, long aRow,
                                                   long aScriptType,
                                                   const char *aScriptText);

HRESULT CVIFUNC ReportProj1_IReportXGetCellScript (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   long aCol, long aRow,
                                                   long *scriptType,
                                                   char **scriptText);

HRESULT CVIFUNC ReportProj1_IReportXDelCellPicture (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    long aCol, long aRow);

HRESULT CVIFUNC ReportProj1_IReportXTranspose (CAObjHandle objectHandle,
                                               ERRORINFO *errorInfo, long aCol1,
                                               long aRow1, long aCol2,
                                               long aRow2);

HRESULT CVIFUNC ReportProj1_IReportXEditCellScript (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    long aCol, long aRow);

HRESULT CVIFUNC ReportProj1_IReportXExportHtml (CAObjHandle objectHandle,
                                                ERRORINFO *errorInfo,
                                                const char *aPicturePath,
                                                VBOOL aExportObject,
                                                char **value);

HRESULT CVIFUNC ReportProj1_IReportXExportPdf (CAObjHandle objectHandle,
                                               ERRORINFO *errorInfo,
                                               const char *aFileName);

HRESULT CVIFUNC ReportProj1_IReportXExportText (CAObjHandle objectHandle,
                                                ERRORINFO *errorInfo, long aCol1,
                                                long aRow1, long aCol2,
                                                long aRow2,
                                                const char *aSeparator,
                                                char **value);

HRESULT CVIFUNC ReportProj1_IReportXImportText (CAObjHandle objectHandle,
                                                ERRORINFO *errorInfo, long aCol,
                                                long aRow, const char *aText,
                                                const char *aSeparator);

HRESULT CVIFUNC ReportProj1_IReportXNewReport (CAObjHandle objectHandle,
                                               ERRORINFO *errorInfo,
                                               long aColCount, long aRowCount);

HRESULT CVIFUNC ReportProj1_IReportXSetSelectCell (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   long aCol1, long aRow1,
                                                   long aCol2, long aRow2);

HRESULT CVIFUNC ReportProj1_IReportXGetSelectCell (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   long *col1, long *row1,
                                                   long *col2, long *row2);

HRESULT CVIFUNC ReportProj1_IReportXGetInputCell (CAObjHandle objectHandle,
                                                  ERRORINFO *errorInfo,
                                                  long *col, long *row);

HRESULT CVIFUNC ReportProj1_IReportXCutObject (CAObjHandle objectHandle,
                                               ERRORINFO *errorInfo,
                                               const char *aObjectName);

HRESULT CVIFUNC ReportProj1_IReportXCopyObject (CAObjHandle objectHandle,
                                                ERRORINFO *errorInfo,
                                                const char *aObjectName);

HRESULT CVIFUNC ReportProj1_IReportXSetColPageBreak (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     long aCol, VBOOL aPageBreak);

HRESULT CVIFUNC ReportProj1_IReportXSetRowPageBreak (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     long aRow, VBOOL aPageBreak);

HRESULT CVIFUNC ReportProj1_IReportXSaveString (CAObjHandle objectHandle,
                                                ERRORINFO *errorInfo,
                                                VBOOL aCompression, char **value);

HRESULT CVIFUNC ReportProj1_IReportXOpenString (CAObjHandle objectHandle,
                                                ERRORINFO *errorInfo,
                                                const char *aReport,
                                                VBOOL aCompression);

HRESULT CVIFUNC ReportProj1_IReportXGetEnterTo (CAObjHandle objectHandle,
                                                ERRORINFO *errorInfo,
                                                long *value);

HRESULT CVIFUNC ReportProj1_IReportXSetEnterTo (CAObjHandle objectHandle,
                                                ERRORINFO *errorInfo, long value);

HRESULT CVIFUNC ReportProj1_IReportXGetMoveChart (CAObjHandle objectHandle,
                                                  ERRORINFO *errorInfo,
                                                  VBOOL *value);

HRESULT CVIFUNC ReportProj1_IReportXSetMoveChart (CAObjHandle objectHandle,
                                                  ERRORINFO *errorInfo,
                                                  VBOOL value);

HRESULT CVIFUNC ReportProj1_IReportXGetUpdateChart (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    VBOOL *value);

HRESULT CVIFUNC ReportProj1_IReportXSetUpdateChart (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    VBOOL value);

HRESULT CVIFUNC ReportProj1_IReportXGetExpandCell (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   long *col1, long *row1,
                                                   long *col2, long *row2);

HRESULT CVIFUNC ReportProj1_IReportXGetChartRange (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   const char *aChartName,
                                                   long *chartWidth,
                                                   long *chartHeight);

HRESULT CVIFUNC ReportProj1_IReportXGetCellCoordinate (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       const char *aAlias,
                                                       long *col, long *row);

HRESULT CVIFUNC ReportProj1_IReportXSetCellPrintHide (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      long aCol, long aRow,
                                                      VBOOL aPrintHide);

HRESULT CVIFUNC ReportProj1_IReportXGetCellPrintHide (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      long aCol, long aRow,
                                                      VBOOL *value);

HRESULT CVIFUNC ReportProj1_IReportXSetCellNextPos (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    long aCol, long aRow,
                                                    long aNextCol, long aNextRow);

HRESULT CVIFUNC ReportProj1_IReportXGetCellNextPos (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    long aCol, long aRow,
                                                    long *nextCol, long *nextRow);

HRESULT CVIFUNC ReportProj1_IReportXFind (CAObjHandle objectHandle,
                                          ERRORINFO *errorInfo, long aCol1,
                                          long aRow1, long aCol2, long aRow2,
                                          VBOOL aColOrRow, VBOOL aUpOrDown,
                                          VBOOL aCaseSensitive,
                                          VBOOL aWholeWords,
                                          const char *aFindString, VBOOL *value);

HRESULT CVIFUNC ReportProj1_IReportXReplace (CAObjHandle objectHandle,
                                             ERRORINFO *errorInfo, long aCol1,
                                             long aRow1, long aCol2, long aRow2,
                                             VBOOL aCaseSensitive,
                                             VBOOL aWholeWords,
                                             const char *aFindString,
                                             const char *aReplaceString);

HRESULT CVIFUNC ReportProj1_IReportXSortCol (CAObjHandle objectHandle,
                                             ERRORINFO *errorInfo, long aCol,
                                             long aCol1, long aRow1, long aCol2,
                                             long aRow2, VBOOL aAscending);

HRESULT CVIFUNC ReportProj1_IReportXSortRow (CAObjHandle objectHandle,
                                             ERRORINFO *errorInfo, long aRow,
                                             long aCol1, long aRow1, long aCol2,
                                             long aRow2, VBOOL aAscending);

HRESULT CVIFUNC ReportProj1_IReportXSetChartRange (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   const char *aChartName,
                                                   long aChartWidth,
                                                   long aChartHeight);

HRESULT CVIFUNC ReportProj1_IReportXGetCellType (CAObjHandle objectHandle,
                                                 ERRORINFO *errorInfo, long aCol,
                                                 long aRow, long *value);

HRESULT CVIFUNC ReportProj1_IReportXSetSelectObjectChart (CAObjHandle objectHandle,
                                                          ERRORINFO *errorInfo,
                                                          const char *aChartName);

HRESULT CVIFUNC ReportProj1_IReportXGetSelectChartName (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        char **value);

HRESULT CVIFUNC ReportProj1_IReportXGetPrinterIndex (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     long *value);

HRESULT CVIFUNC ReportProj1_IReportXSetPrinterIndex (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     long value);

HRESULT CVIFUNC ReportProj1_IReportXGetPaperSize (CAObjHandle objectHandle,
                                                  ERRORINFO *errorInfo,
                                                  long *value);

HRESULT CVIFUNC ReportProj1_IReportXSetPaperSize (CAObjHandle objectHandle,
                                                  ERRORINFO *errorInfo,
                                                  long value);

HRESULT CVIFUNC ReportProj1_IReportXGetPageWidth (CAObjHandle objectHandle,
                                                  ERRORINFO *errorInfo,
                                                  long *value);

HRESULT CVIFUNC ReportProj1_IReportXSetPageWidth (CAObjHandle objectHandle,
                                                  ERRORINFO *errorInfo,
                                                  long value);

HRESULT CVIFUNC ReportProj1_IReportXGetPageHeight (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   long *value);

HRESULT CVIFUNC ReportProj1_IReportXSetPageHeight (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   long value);

HRESULT CVIFUNC ReportProj1_IReportXGetPrintOrientation (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo,
                                                         VBOOL *value);

HRESULT CVIFUNC ReportProj1_IReportXSetPrintOrientation (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo,
                                                         VBOOL value);

HRESULT CVIFUNC ReportProj1_IReportXGetPrintCopies (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    long *value);

HRESULT CVIFUNC ReportProj1_IReportXSetPrintCopies (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    long value);

HRESULT CVIFUNC ReportProj1_IReportXGetLeftMargin (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   long *value);

HRESULT CVIFUNC ReportProj1_IReportXSetLeftMargin (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   long value);

HRESULT CVIFUNC ReportProj1_IReportXGetTopMargin (CAObjHandle objectHandle,
                                                  ERRORINFO *errorInfo,
                                                  long *value);

HRESULT CVIFUNC ReportProj1_IReportXSetTopMargin (CAObjHandle objectHandle,
                                                  ERRORINFO *errorInfo,
                                                  long value);

HRESULT CVIFUNC ReportProj1_IReportXGetRightMargin (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    long *value);

HRESULT CVIFUNC ReportProj1_IReportXSetRightMargin (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    long value);

HRESULT CVIFUNC ReportProj1_IReportXGetBottomMargin (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     long *value);

HRESULT CVIFUNC ReportProj1_IReportXSetBottomMargin (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     long value);

HRESULT CVIFUNC ReportProj1_IReportXGetHeaderMargin (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     long *value);

HRESULT CVIFUNC ReportProj1_IReportXSetHeaderMargin (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     long value);

HRESULT CVIFUNC ReportProj1_IReportXGetFooterMargin (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     long *value);

HRESULT CVIFUNC ReportProj1_IReportXSetFooterMargin (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     long value);

HRESULT CVIFUNC ReportProj1_IReportXGetPrintBorders (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     VBOOL *value);

HRESULT CVIFUNC ReportProj1_IReportXSetPrintBorders (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     VBOOL value);

HRESULT CVIFUNC ReportProj1_IReportXGetPrintBackColor (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       VBOOL *value);

HRESULT CVIFUNC ReportProj1_IReportXSetPrintBackColor (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       VBOOL value);

HRESULT CVIFUNC ReportProj1_IReportXGetPageFontName (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     char **value);

HRESULT CVIFUNC ReportProj1_IReportXSetPageFontName (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     const char *value);

HRESULT CVIFUNC ReportProj1_IReportXGetPageFontSize (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     long *value);

HRESULT CVIFUNC ReportProj1_IReportXSetPageFontSize (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     long value);

HRESULT CVIFUNC ReportProj1_IReportXGetPageHeaderLeftText (CAObjHandle objectHandle,
                                                           ERRORINFO *errorInfo,
                                                           char **value);

HRESULT CVIFUNC ReportProj1_IReportXSetPageHeaderLeftText (CAObjHandle objectHandle,
                                                           ERRORINFO *errorInfo,
                                                           const char *value);

HRESULT CVIFUNC ReportProj1_IReportXGetPageFooterLeftText (CAObjHandle objectHandle,
                                                           ERRORINFO *errorInfo,
                                                           char **value);

HRESULT CVIFUNC ReportProj1_IReportXSetPageFooterLeftText (CAObjHandle objectHandle,
                                                           ERRORINFO *errorInfo,
                                                           const char *value);

HRESULT CVIFUNC ReportProj1_IReportXGetLeftColCount (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     long *value);

HRESULT CVIFUNC ReportProj1_IReportXSetLeftColCount (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     long value);

HRESULT CVIFUNC ReportProj1_IReportXGetTopRowCount (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    long *value);

HRESULT CVIFUNC ReportProj1_IReportXSetTopRowCount (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    long value);

HRESULT CVIFUNC ReportProj1_IReportXGetRightColCount (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      long *value);

HRESULT CVIFUNC ReportProj1_IReportXSetRightColCount (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      long value);

HRESULT CVIFUNC ReportProj1_IReportXGetBottomRowCount (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       long *value);

HRESULT CVIFUNC ReportProj1_IReportXSetBottomRowCount (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       long value);

HRESULT CVIFUNC ReportProj1_IReportXGetPrintZoom (CAObjHandle objectHandle,
                                                  ERRORINFO *errorInfo,
                                                  long *value);

HRESULT CVIFUNC ReportProj1_IReportXSetPrintZoom (CAObjHandle objectHandle,
                                                  ERRORINFO *errorInfo,
                                                  long value);

HRESULT CVIFUNC ReportProj1_IReportXGetPrintArea (CAObjHandle objectHandle,
                                                  ERRORINFO *errorInfo,
                                                  char **value);

HRESULT CVIFUNC ReportProj1_IReportXSetPrintArea (CAObjHandle objectHandle,
                                                  ERRORINFO *errorInfo,
                                                  const char *value);

HRESULT CVIFUNC ReportProj1_IReportXGetPrintOrder (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   VBOOL *value);

HRESULT CVIFUNC ReportProj1_IReportXSetPrintOrder (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   VBOOL value);

HRESULT CVIFUNC ReportProj1_IReportXGetCellButtonText (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       long aCol, long aRow,
                                                       char **value);

HRESULT CVIFUNC ReportProj1_IReportXGetCellButtonScript (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo,
                                                         long aCol, long aRow,
                                                         char **value);

HRESULT CVIFUNC ReportProj1_IReportXGetCellDropText (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     long aCol, long aRow,
                                                     char **value);

HRESULT CVIFUNC ReportProj1_IReportXSetCellTextLength (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       long aCol, long aRow,
                                                       long aTextLength);

HRESULT CVIFUNC ReportProj1_IReportXGetCellTextLength (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       long aCol, long aRow,
                                                       long *value);

HRESULT CVIFUNC ReportProj1_IReportXSetCellCharCase (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     long aCol, long aRow,
                                                     long aCharCase);

HRESULT CVIFUNC ReportProj1_IReportXGetCellCharCase (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     long aCol, long aRow,
                                                     long *value);

HRESULT CVIFUNC ReportProj1_IReportXSetCellAppendDataLength (CAObjHandle objectHandle,
                                                             ERRORINFO *errorInfo,
                                                             long aCol,
                                                             long aRow,
                                                             long aNoteLength);

HRESULT CVIFUNC ReportProj1_IReportXGetCellAppendDataLength (CAObjHandle objectHandle,
                                                             ERRORINFO *errorInfo,
                                                             long aCol,
                                                             long aRow,
                                                             long *value);

HRESULT CVIFUNC ReportProj1_IReportXSetCellAppendData (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       long aCol, long aRow,
                                                       long aIndex,
                                                       const char *aAppendData);

HRESULT CVIFUNC ReportProj1_IReportXGetCellAppendData (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       long aCol, long aRow,
                                                       long aIndex, char **value);

HRESULT CVIFUNC ReportProj1_IReportXFill (CAObjHandle objectHandle,
                                          ERRORINFO *errorInfo, long aCol1,
                                          long aRow1, long aCol2, long aRow2,
                                          long aDirection, long aFillType);

HRESULT CVIFUNC ReportProj1_IReportXSetChartReadOnly (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      const char *aChartName,
                                                      VBOOL aReadOnly);

HRESULT CVIFUNC ReportProj1_IReportXGetChartReadOnly (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      const char *aChartName,
                                                      VBOOL *value);

HRESULT CVIFUNC ReportProj1_IReportXGetChartSeries (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    const char *aChartName,
                                                    long aIndex,
                                                    long *seriesType,
                                                    char **seriesSignText,
                                                    char **seriesDataText,
                                                    char **seriesCell);

HRESULT CVIFUNC ReportProj1_IReportXGetChartSeriesCount (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo,
                                                         const char *aChartName,
                                                         long *value);

HRESULT CVIFUNC ReportProj1_IReportXDelChartSeries (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    const char *aChartName,
                                                    long aIndex);

HRESULT CVIFUNC ReportProj1_IReportXGetFrozenCol (CAObjHandle objectHandle,
                                                  ERRORINFO *errorInfo,
                                                  long *frozenStart,
                                                  long *frozenEnd);

HRESULT CVIFUNC ReportProj1_IReportXGetFrozenRow (CAObjHandle objectHandle,
                                                  ERRORINFO *errorInfo,
                                                  long *frozenStart,
                                                  long *frozenEnd);

HRESULT CVIFUNC ReportProj1_IReportXChangeChartSeires (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       const char *aChartName,
                                                       long aIndex,
                                                       long aSeriesType,
                                                       const char *aSeriesSignText,
                                                       const char *aSeriesDataText,
                                                       const char *aSeriesCell);

HRESULT CVIFUNC ReportProj1_IReportXGetColBestWidth (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     long aCol, long *value);

HRESULT CVIFUNC ReportProj1_IReportXGetRowBestHeight (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      long aRow, long *value);

HRESULT CVIFUNC ReportProj1_IReportXExplainCellScript (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       long aCol, long aRow);

HRESULT CVIFUNC ReportProj1_IReportXGetColPageBreak (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     long aCol, VBOOL *value);

HRESULT CVIFUNC ReportProj1_IReportXGetRowPageBreak (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     long aRow, VBOOL *value);

HRESULT CVIFUNC ReportProj1_IReportXSetPoleText (CAObjHandle objectHandle,
                                                 ERRORINFO *errorInfo,
                                                 long aOrientation, long aIndex,
                                                 const char *aText);

HRESULT CVIFUNC ReportProj1_IReportXGetPoleText (CAObjHandle objectHandle,
                                                 ERRORINFO *errorInfo,
                                                 long aOrientation, long aIndex,
                                                 char **value);

HRESULT CVIFUNC ReportProj1_IReportXEndEditCell (CAObjHandle objectHandle,
                                                 ERRORINFO *errorInfo,
                                                 VBOOL aCancel);

HRESULT CVIFUNC ReportProj1_IReportXGetExecuteScript (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      VBOOL *value);

HRESULT CVIFUNC ReportProj1_IReportXSetExecuteScript (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      VBOOL value);

HRESULT CVIFUNC ReportProj1_IReportXGetCellSign (CAObjHandle objectHandle,
                                                 ERRORINFO *errorInfo, long aCol,
                                                 long aRow, long *value);

HRESULT CVIFUNC ReportProj1_IReportXGetGridLine (CAObjHandle objectHandle,
                                                 ERRORINFO *errorInfo,
                                                 VBOOL *value);

HRESULT CVIFUNC ReportProj1_IReportXSetGridLine (CAObjHandle objectHandle,
                                                 ERRORINFO *errorInfo,
                                                 VBOOL value);

HRESULT CVIFUNC ReportProj1_IReportXGetObjectChart (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    const char *aChartName,
                                                    char **aTitleText,
                                                    char **aHorizontalText,
                                                    char **aVerticalText);

HRESULT CVIFUNC ReportProj1_IReportXChangeObjectChart (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       const char *aChartName,
                                                       long aCol, long aRow,
                                                       const char *aTitleText,
                                                       const char *aHorizontalText,
                                                       const char *aVerticalText);

HRESULT CVIFUNC ReportProj1_IReportXClearCell (CAObjHandle objectHandle,
                                               ERRORINFO *errorInfo, long aCol1,
                                               long aRow1, long aCol2,
                                               long aRow2);

HRESULT CVIFUNC ReportProj1_IReportXGetAllChartName (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     char **value);

HRESULT CVIFUNC ReportProj1_IReportXAddPicture (CAObjHandle objectHandle,
                                                ERRORINFO *errorInfo,
                                                const char *aFileName);

HRESULT CVIFUNC ReportProj1_IReportXDelPicture (CAObjHandle objectHandle,
                                                ERRORINFO *errorInfo);

HRESULT CVIFUNC ReportProj1_IReportXSetCellNote (CAObjHandle objectHandle,
                                                 ERRORINFO *errorInfo, long aCol,
                                                 long aRow,
                                                 const char *aNoteText);

HRESULT CVIFUNC ReportProj1_IReportXGetCellNote (CAObjHandle objectHandle,
                                                 ERRORINFO *errorInfo, long aCol,
                                                 long aRow, char **value);

HRESULT CVIFUNC ReportProj1_IReportXGetPoleReadOnly (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     VBOOL *value);

HRESULT CVIFUNC ReportProj1_IReportXSetPoleReadOnly (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     VBOOL value);

HRESULT CVIFUNC ReportProj1_IReportXGetCellReadOnlyProp (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo,
                                                         VBOOL *value);

HRESULT CVIFUNC ReportProj1_IReportXSetCellReadOnlyProp (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo,
                                                         VBOOL value);

HRESULT CVIFUNC ReportProj1_IReportXCopyRangeToRange (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      long aCol1, long aRow1,
                                                      long aCol2, long aRow2,
                                                      long aToCol, long aToRow,
                                                      long aCount);

HRESULT CVIFUNC ReportProj1_IReportXGetRightWidth (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   long *value);

HRESULT CVIFUNC ReportProj1_IReportXSetRightWidth (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   long value);

HRESULT CVIFUNC ReportProj1_IReportXGetBottomHeight (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     long *value);

HRESULT CVIFUNC ReportProj1_IReportXSetBottomHeight (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     long value);

HRESULT CVIFUNC ReportProj1_IReportXClearData (CAObjHandle objectHandle,
                                               ERRORINFO *errorInfo, long aCol1,
                                               long aRow1, long aCol2,
                                               long aRow2);

HRESULT CVIFUNC ReportProj1_IReportXGetPaperSource (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    long *value);

HRESULT CVIFUNC ReportProj1_IReportXSetPaperSource (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    long value);

HRESULT CVIFUNC ReportProj1_IReportXGetCellWidth (CAObjHandle objectHandle,
                                                  ERRORINFO *errorInfo,
                                                  long *value);

HRESULT CVIFUNC ReportProj1_IReportXSetCellWidth (CAObjHandle objectHandle,
                                                  ERRORINFO *errorInfo,
                                                  long value);

HRESULT CVIFUNC ReportProj1_IReportXGetCellHeight (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   long *value);

HRESULT CVIFUNC ReportProj1_IReportXSetCellHeight (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   long value);

HRESULT CVIFUNC ReportProj1_IReportXGetFontName (CAObjHandle objectHandle,
                                                 ERRORINFO *errorInfo,
                                                 char **value);

HRESULT CVIFUNC ReportProj1_IReportXSetFontName (CAObjHandle objectHandle,
                                                 ERRORINFO *errorInfo,
                                                 const char *value);

HRESULT CVIFUNC ReportProj1_IReportXGetFontSize (CAObjHandle objectHandle,
                                                 ERRORINFO *errorInfo,
                                                 long *value);

HRESULT CVIFUNC ReportProj1_IReportXSetFontSize (CAObjHandle objectHandle,
                                                 ERRORINFO *errorInfo,
                                                 long value);

HRESULT CVIFUNC ReportProj1_IReportXGetCellLabel (CAObjHandle objectHandle,
                                                  ERRORINFO *errorInfo,
                                                  long aCol, long aRow,
                                                  char **value);

HRESULT CVIFUNC ReportProj1_IReportXGetRangeLabel (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   long aCol1, long aRow1,
                                                   long aCol2, long aRow2,
                                                   char **value);

HRESULT CVIFUNC ReportProj1_IReportXOpenDatabaseGuide (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo);

HRESULT CVIFUNC ReportProj1_IReportXGetConnectionString (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo,
                                                         char **value);

HRESULT CVIFUNC ReportProj1_IReportXSetConnectionString (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo,
                                                         const char *value);

HRESULT CVIFUNC ReportProj1_IReportXAddField (CAObjHandle objectHandle,
                                              ERRORINFO *errorInfo,
                                              const char *aFieldName,
                                              const char *aFieldAttribute,
                                              long aFieldIndex);

HRESULT CVIFUNC ReportProj1_IReportXDelField (CAObjHandle objectHandle,
                                              ERRORINFO *errorInfo,
                                              long aFieldIndex);

HRESULT CVIFUNC ReportProj1_IReportXChangeField (CAObjHandle objectHandle,
                                                 ERRORINFO *errorInfo,
                                                 long aFieldIndex,
                                                 const char *aFieldName,
                                                 const char *aFieldAttribute);

HRESULT CVIFUNC ReportProj1_IReportXGetQueryFrom (CAObjHandle objectHandle,
                                                  ERRORINFO *errorInfo,
                                                  char **value);

HRESULT CVIFUNC ReportProj1_IReportXSetQueryFrom (CAObjHandle objectHandle,
                                                  ERRORINFO *errorInfo,
                                                  const char *value);

HRESULT CVIFUNC ReportProj1_IReportXGetQueryWhere (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   char **value);

HRESULT CVIFUNC ReportProj1_IReportXSetQueryWhere (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   const char *value);

HRESULT CVIFUNC ReportProj1_IReportXGetQueryHaving (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    char **value);

HRESULT CVIFUNC ReportProj1_IReportXSetQueryHaving (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    const char *value);

HRESULT CVIFUNC ReportProj1_IReportXClearField (CAObjHandle objectHandle,
                                                ERRORINFO *errorInfo);

HRESULT CVIFUNC ReportProj1_IReportXAddFieldOrder (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   const char *aFieldName,
                                                   VBOOL aFieldOrder,
                                                   long aFieldIndex);

HRESULT CVIFUNC ReportProj1_IReportXDelFieldOrder (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   long aFieldIndex);

HRESULT CVIFUNC ReportProj1_IReportXOpenQuery (CAObjHandle objectHandle,
                                               ERRORINFO *errorInfo);

HRESULT CVIFUNC ReportProj1_IReportXGetField (CAObjHandle objectHandle,
                                              ERRORINFO *errorInfo,
                                              long aFieldIndex, char **fieldName,
                                              char **fieldAttribute);

HRESULT CVIFUNC ReportProj1_IReportXGetAllField (CAObjHandle objectHandle,
                                                 ERRORINFO *errorInfo,
                                                 char **value);

HRESULT CVIFUNC ReportProj1_IReportXGetFeildOrder (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   long aFieldIndex,
                                                   char **fieldName,
                                                   VBOOL *fieldOrder);

HRESULT CVIFUNC ReportProj1_IReportXGetAllFieldOrder (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      char **value);

HRESULT CVIFUNC ReportProj1_IReportXClearFieldOrder (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo);

HRESULT CVIFUNC ReportProj1_IReportXGetReportType (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   long *value);

HRESULT CVIFUNC ReportProj1_IReportXSetReportType (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   long value);

HRESULT CVIFUNC ReportProj1_IReportXGetGroupType (CAObjHandle objectHandle,
                                                  ERRORINFO *errorInfo,
                                                  long *value);

HRESULT CVIFUNC ReportProj1_IReportXSetGroupType (CAObjHandle objectHandle,
                                                  ERRORINFO *errorInfo,
                                                  long value);

HRESULT CVIFUNC ReportProj1_IReportXGetGroupPageBreak (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       VBOOL *value);

HRESULT CVIFUNC ReportProj1_IReportXSetGroupPageBreak (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       VBOOL value);

HRESULT CVIFUNC ReportProj1_IReportXGetReportLeft (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   long *value);

HRESULT CVIFUNC ReportProj1_IReportXSetReportLeft (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   long value);

HRESULT CVIFUNC ReportProj1_IReportXGetReportTop (CAObjHandle objectHandle,
                                                  ERRORINFO *errorInfo,
                                                  long *value);

HRESULT CVIFUNC ReportProj1_IReportXSetReportTop (CAObjHandle objectHandle,
                                                  ERRORINFO *errorInfo,
                                                  long value);

HRESULT CVIFUNC ReportProj1_IReportXAddFieldCell (CAObjHandle objectHandle,
                                                  ERRORINFO *errorInfo,
                                                  const char *aAlias,
                                                  const char *aFieldName,
                                                  long aFieldFunction);

HRESULT CVIFUNC ReportProj1_IReportXDelFieldCell (CAObjHandle objectHandle,
                                                  ERRORINFO *errorInfo,
                                                  const char *aAlias);

HRESULT CVIFUNC ReportProj1_IReportXClearFieldCell (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo);

HRESULT CVIFUNC ReportProj1_IReportXGetAllFieldCell (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     char **value);

HRESULT CVIFUNC ReportProj1_IReportXGetAlternatingColor (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo,
                                                         long *value);

HRESULT CVIFUNC ReportProj1_IReportXSetAlternatingColor (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo,
                                                         long value);

HRESULT CVIFUNC ReportProj1_IReportXGetColTotal (CAObjHandle objectHandle,
                                                 ERRORINFO *errorInfo,
                                                 VBOOL *value);

HRESULT CVIFUNC ReportProj1_IReportXSetColTotal (CAObjHandle objectHandle,
                                                 ERRORINFO *errorInfo,
                                                 VBOOL value);

HRESULT CVIFUNC ReportProj1_IReportXGetRowTotal (CAObjHandle objectHandle,
                                                 ERRORINFO *errorInfo,
                                                 VBOOL *value);

HRESULT CVIFUNC ReportProj1_IReportXSetRowTotal (CAObjHandle objectHandle,
                                                 ERRORINFO *errorInfo,
                                                 VBOOL value);

HRESULT CVIFUNC ReportProj1_IReportXChangeFieldOrder (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      long aFieldIndex,
                                                      const char *aFieldName,
                                                      VBOOL aFieldOrder);

HRESULT CVIFUNC ReportProj1_IReportXChangeFieldCell (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     const char *aAlias,
                                                     const char *aFieldName,
                                                     long aFieldFunction);

HRESULT CVIFUNC ReportProj1_IReportXGetFieldCell (CAObjHandle objectHandle,
                                                  ERRORINFO *errorInfo,
                                                  const char *aAlias,
                                                  char **fieldName,
                                                  long *fieldFunction);

HRESULT CVIFUNC ReportProj1_IReportXGetSqlText (CAObjHandle objectHandle,
                                                ERRORINFO *errorInfo,
                                                char **value);

HRESULT CVIFUNC ReportProj1_IReportXGetPoleSelectColor (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        long *value);

HRESULT CVIFUNC ReportProj1_IReportXSetPoleSelectColor (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        long value);

HRESULT CVIFUNC ReportProj1_IReportXSetCellSelectColor (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        long aColor1,
                                                        long aColor2);

HRESULT CVIFUNC ReportProj1_IReportXGetCellSelectColor (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        long *color1,
                                                        long *color2);

HRESULT CVIFUNC ReportProj1_IReportXGetPoleColor (CAObjHandle objectHandle,
                                                  ERRORINFO *errorInfo,
                                                  long *value);

HRESULT CVIFUNC ReportProj1_IReportXSetPoleColor (CAObjHandle objectHandle,
                                                  ERRORINFO *errorInfo,
                                                  long value);

HRESULT CVIFUNC ReportProj1_IReportXGetPoleSeparatorColor (CAObjHandle objectHandle,
                                                           ERRORINFO *errorInfo,
                                                           long *value);

HRESULT CVIFUNC ReportProj1_IReportXSetPoleSeparatorColor (CAObjHandle objectHandle,
                                                           ERRORINFO *errorInfo,
                                                           long value);

HRESULT CVIFUNC ReportProj1_IReportXGetCellSeparatorColor (CAObjHandle objectHandle,
                                                           ERRORINFO *errorInfo,
                                                           long *value);

HRESULT CVIFUNC ReportProj1_IReportXSetCellSeparatorColor (CAObjHandle objectHandle,
                                                           ERRORINFO *errorInfo,
                                                           long value);

HRESULT CVIFUNC ReportProj1_IReportXSetBarCodeCell (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    long aCol, long aRow,
                                                    long aCode,
                                                    VBOOL aOrientation);

HRESULT CVIFUNC ReportProj1_IReportXGetCellCode (CAObjHandle objectHandle,
                                                 ERRORINFO *errorInfo, long aCol,
                                                 long aRow, long *value);

HRESULT CVIFUNC ReportProj1_IReportXGetDisplayZero (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    VBOOL *value);

HRESULT CVIFUNC ReportProj1_IReportXSetDisplayZero (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    VBOOL value);

HRESULT CVIFUNC ReportProj1_IReportXGetPageFontColor (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      long *value);

HRESULT CVIFUNC ReportProj1_IReportXSetPageFontColor (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      long value);

HRESULT CVIFUNC ReportProj1_IReportXGetPageFontStyleBold (CAObjHandle objectHandle,
                                                          ERRORINFO *errorInfo,
                                                          VBOOL *value);

HRESULT CVIFUNC ReportProj1_IReportXSetPageFontStyleBold (CAObjHandle objectHandle,
                                                          ERRORINFO *errorInfo,
                                                          VBOOL value);

HRESULT CVIFUNC ReportProj1_IReportXGetPageFontStyleItalic (CAObjHandle objectHandle,
                                                            ERRORINFO *errorInfo,
                                                            VBOOL *value);

HRESULT CVIFUNC ReportProj1_IReportXSetPageFontStyleItalic (CAObjHandle objectHandle,
                                                            ERRORINFO *errorInfo,
                                                            VBOOL value);

HRESULT CVIFUNC ReportProj1_IReportXGetPageHeaderCenterText (CAObjHandle objectHandle,
                                                             ERRORINFO *errorInfo,
                                                             char **value);

HRESULT CVIFUNC ReportProj1_IReportXSetPageHeaderCenterText (CAObjHandle objectHandle,
                                                             ERRORINFO *errorInfo,
                                                             const char *value);

HRESULT CVIFUNC ReportProj1_IReportXGetPageFooterCenterText (CAObjHandle objectHandle,
                                                             ERRORINFO *errorInfo,
                                                             char **value);

HRESULT CVIFUNC ReportProj1_IReportXSetPageFooterCenterText (CAObjHandle objectHandle,
                                                             ERRORINFO *errorInfo,
                                                             const char *value);

HRESULT CVIFUNC ReportProj1_IReportXGetPageHeaderRightText (CAObjHandle objectHandle,
                                                            ERRORINFO *errorInfo,
                                                            char **value);

HRESULT CVIFUNC ReportProj1_IReportXSetPageHeaderRightText (CAObjHandle objectHandle,
                                                            ERRORINFO *errorInfo,
                                                            const char *value);

HRESULT CVIFUNC ReportProj1_IReportXGetPageFooterRightText (CAObjHandle objectHandle,
                                                            ERRORINFO *errorInfo,
                                                            char **value);

HRESULT CVIFUNC ReportProj1_IReportXSetPageFooterRightText (CAObjHandle objectHandle,
                                                            ERRORINFO *errorInfo,
                                                            const char *value);

HRESULT CVIFUNC ReportProj1_IReportXGetCellCaption (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    long aCol, long aRow,
                                                    char **value);

HRESULT CVIFUNC ReportProj1_IReportXGetLabelRange (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   const char *aLabel,
                                                   long *col1, long *row1,
                                                   long *col2, long *row2,
                                                   VBOOL *value);

HRESULT CVIFUNC ReportProj1_IReportXSetRichTextCell (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     long aCol, long aRow);

HRESULT CVIFUNC ReportProj1_IReportXSetRichTextFontName (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo,
                                                         const char *aFontName);

HRESULT CVIFUNC ReportProj1_IReportXSetRichTextFontSize (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo,
                                                         long aFontSize);

HRESULT CVIFUNC ReportProj1_IReportXSetRichTextFontColor (CAObjHandle objectHandle,
                                                          ERRORINFO *errorInfo,
                                                          long aFontColor);

HRESULT CVIFUNC ReportProj1_IReportXSetRichTextFontStyle (CAObjHandle objectHandle,
                                                          ERRORINFO *errorInfo,
                                                          long aFontStyle,
                                                          VBOOL aStyleBool);

HRESULT CVIFUNC ReportProj1_IReportXSetRichTextOffset (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       long aOffset);

HRESULT CVIFUNC ReportProj1_IReportXGetRichTextFontName (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo,
                                                         char **value);

HRESULT CVIFUNC ReportProj1_IReportXGetRichTextFontSize (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo,
                                                         long *value);

HRESULT CVIFUNC ReportProj1_IReportXGetRichTextFontColor (CAObjHandle objectHandle,
                                                          ERRORINFO *errorInfo,
                                                          long *value);

HRESULT CVIFUNC ReportProj1_IReportXGetRichTextFontStyle (CAObjHandle objectHandle,
                                                          ERRORINFO *errorInfo,
                                                          long aFontStyle,
                                                          VBOOL *value);

HRESULT CVIFUNC ReportProj1_IReportXGetRichTextOffset (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       long *value);

HRESULT CVIFUNC ReportProj1_IReportXLoadIcon (CAObjHandle objectHandle,
                                              ERRORINFO *errorInfo,
                                              const char *aFileName);

HRESULT CVIFUNC ReportProj1_IReportXSetCellRichTextValue (CAObjHandle objectHandle,
                                                          ERRORINFO *errorInfo,
                                                          long aCol, long aRow,
                                                          const char *aValue);

HRESULT CVIFUNC ReportProj1_IReportXGetCellRichTextValue (CAObjHandle objectHandle,
                                                          ERRORINFO *errorInfo,
                                                          long aCol, long aRow,
                                                          char **value);

HRESULT CVIFUNC ReportProj1_IReportXGetTopReport (CAObjHandle objectHandle,
                                                  ERRORINFO *errorInfo,
                                                  long *value);

HRESULT CVIFUNC ReportProj1_IReportXSetTopReport (CAObjHandle objectHandle,
                                                  ERRORINFO *errorInfo,
                                                  long value);

HRESULT CVIFUNC ReportProj1_IReportXGetPrintPage (CAObjHandle objectHandle,
                                                  ERRORINFO *errorInfo,
                                                  char **value);

HRESULT CVIFUNC ReportProj1_IReportXSetPrintPage (CAObjHandle objectHandle,
                                                  ERRORINFO *errorInfo,
                                                  const char *value);

HRESULT CVIFUNC ReportProj1_IReportXSetColHide (CAObjHandle objectHandle,
                                                ERRORINFO *errorInfo, long aCol,
                                                VBOOL aHide);

HRESULT CVIFUNC ReportProj1_IReportXSetRowHide (CAObjHandle objectHandle,
                                                ERRORINFO *errorInfo, long aRow,
                                                VBOOL aHide);

HRESULT CVIFUNC ReportProj1_IReportXAddColTreeNode (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    long aLevel, long aCol1,
                                                    long aCol2);

HRESULT CVIFUNC ReportProj1_IReportXAddRowTreeNode (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    long aLevel, long aRow1,
                                                    long aRow2);

HRESULT CVIFUNC ReportProj1_IReportXDelColTreeNode (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    long aCol1, long aCol2);

HRESULT CVIFUNC ReportProj1_IReportXDelRowTreeNode (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    long aRow1, long aRow2);

HRESULT CVIFUNC ReportProj1_IReportXClearColTreeNode (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo);

HRESULT CVIFUNC ReportProj1_IReportXClearRowTreeNode (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo);

HRESULT CVIFUNC ReportProj1_IReportXGetAllColTreeNode (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       long aLevel, char **value);

HRESULT CVIFUNC ReportProj1_IReportXGetAllRowTreeNode (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       long aLevel, char **value);

HRESULT CVIFUNC ReportProj1_IReportXSetChartCell (CAObjHandle objectHandle,
                                                  ERRORINFO *errorInfo,
                                                  long aCol, long aRow,
                                                  const char *aTitleText,
                                                  const char *aHorizontalText,
                                                  const char *aVerticalText,
                                                  const char *aSeriesType,
                                                  const char *aSeriesSignText,
                                                  const char *aSeriesDataText);

HRESULT CVIFUNC ReportProj1_IReportXGetCellChart (CAObjHandle objectHandle,
                                                  ERRORINFO *errorInfo,
                                                  long aCol, long aRow,
                                                  char **value);

HRESULT CVIFUNC ReportProj1_IReportXEventsRegOnOnActivate (CAObjHandle serverObject,
                                                           IReportXEventsRegOnOnActivate_CallbackType callbackFunction,
                                                           void *callbackData,
                                                           int enableCallbacks,
                                                           int *callbackId);

HRESULT CVIFUNC ReportProj1_IReportXEventsRegOnOnClick (CAObjHandle serverObject,
                                                        IReportXEventsRegOnOnClick_CallbackType callbackFunction,
                                                        void *callbackData,
                                                        int enableCallbacks,
                                                        int *callbackId);

HRESULT CVIFUNC ReportProj1_IReportXEventsRegOnOnCreate (CAObjHandle serverObject,
                                                         IReportXEventsRegOnOnCreate_CallbackType callbackFunction,
                                                         void *callbackData,
                                                         int enableCallbacks,
                                                         int *callbackId);

HRESULT CVIFUNC ReportProj1_IReportXEventsRegOnOnDblClick (CAObjHandle serverObject,
                                                           IReportXEventsRegOnOnDblClick_CallbackType callbackFunction,
                                                           void *callbackData,
                                                           int enableCallbacks,
                                                           int *callbackId);

HRESULT CVIFUNC ReportProj1_IReportXEventsRegOnOnDestroy (CAObjHandle serverObject,
                                                          IReportXEventsRegOnOnDestroy_CallbackType callbackFunction,
                                                          void *callbackData,
                                                          int enableCallbacks,
                                                          int *callbackId);

HRESULT CVIFUNC ReportProj1_IReportXEventsRegOnOnDeactivate (CAObjHandle serverObject,
                                                             IReportXEventsRegOnOnDeactivate_CallbackType callbackFunction,
                                                             void *callbackData,
                                                             int enableCallbacks,
                                                             int *callbackId);

HRESULT CVIFUNC ReportProj1_IReportXEventsRegOnOnKeyPress (CAObjHandle serverObject,
                                                           IReportXEventsRegOnOnKeyPress_CallbackType callbackFunction,
                                                           void *callbackData,
                                                           int enableCallbacks,
                                                           int *callbackId);

HRESULT CVIFUNC ReportProj1_IReportXEventsRegOnOnPaint (CAObjHandle serverObject,
                                                        IReportXEventsRegOnOnPaint_CallbackType callbackFunction,
                                                        void *callbackData,
                                                        int enableCallbacks,
                                                        int *callbackId);

HRESULT CVIFUNC ReportProj1_IReportXEventsRegOnOnSelectChange (CAObjHandle serverObject,
                                                               IReportXEventsRegOnOnSelectChange_CallbackType callbackFunction,
                                                               void *callbackData,
                                                               int enableCallbacks,
                                                               int *callbackId);

HRESULT CVIFUNC ReportProj1_IReportXEventsRegOnOnInputChange (CAObjHandle serverObject,
                                                              IReportXEventsRegOnOnInputChange_CallbackType callbackFunction,
                                                              void *callbackData,
                                                              int enableCallbacks,
                                                              int *callbackId);

HRESULT CVIFUNC ReportProj1_IReportXEventsRegOnOnPoleLUp (CAObjHandle serverObject,
                                                          IReportXEventsRegOnOnPoleLUp_CallbackType callbackFunction,
                                                          void *callbackData,
                                                          int enableCallbacks,
                                                          int *callbackId);

HRESULT CVIFUNC ReportProj1_IReportXEventsRegOnOnPoleRDown (CAObjHandle serverObject,
                                                            IReportXEventsRegOnOnPoleRDown_CallbackType callbackFunction,
                                                            void *callbackData,
                                                            int enableCallbacks,
                                                            int *callbackId);

HRESULT CVIFUNC ReportProj1_IReportXEventsRegOnOnCellLUp (CAObjHandle serverObject,
                                                          IReportXEventsRegOnOnCellLUp_CallbackType callbackFunction,
                                                          void *callbackData,
                                                          int enableCallbacks,
                                                          int *callbackId);

HRESULT CVIFUNC ReportProj1_IReportXEventsRegOnOnCellRDown (CAObjHandle serverObject,
                                                            IReportXEventsRegOnOnCellRDown_CallbackType callbackFunction,
                                                            void *callbackData,
                                                            int enableCallbacks,
                                                            int *callbackId);

HRESULT CVIFUNC ReportProj1_IReportXEventsRegOnOnCellDblCLick (CAObjHandle serverObject,
                                                               IReportXEventsRegOnOnCellDblCLick_CallbackType callbackFunction,
                                                               void *callbackData,
                                                               int enableCallbacks,
                                                               int *callbackId);

HRESULT CVIFUNC ReportProj1_IReportXEventsRegOnOnCellChanged (CAObjHandle serverObject,
                                                              IReportXEventsRegOnOnCellChanged_CallbackType callbackFunction,
                                                              void *callbackData,
                                                              int enableCallbacks,
                                                              int *callbackId);

HRESULT CVIFUNC ReportProj1_IReportXEventsRegOnOnCellChanging (CAObjHandle serverObject,
                                                               IReportXEventsRegOnOnCellChanging_CallbackType callbackFunction,
                                                               void *callbackData,
                                                               int enableCallbacks,
                                                               int *callbackId);

HRESULT CVIFUNC ReportProj1_IReportXEventsRegOnOnLeftChange (CAObjHandle serverObject,
                                                             IReportXEventsRegOnOnLeftChange_CallbackType callbackFunction,
                                                             void *callbackData,
                                                             int enableCallbacks,
                                                             int *callbackId);

HRESULT CVIFUNC ReportProj1_IReportXEventsRegOnOnTopChange (CAObjHandle serverObject,
                                                            IReportXEventsRegOnOnTopChange_CallbackType callbackFunction,
                                                            void *callbackData,
                                                            int enableCallbacks,
                                                            int *callbackId);

HRESULT CVIFUNC ReportProj1_IReportXEventsRegOnOnError (CAObjHandle serverObject,
                                                        IReportXEventsRegOnOnError_CallbackType callbackFunction,
                                                        void *callbackData,
                                                        int enableCallbacks,
                                                        int *callbackId);

HRESULT CVIFUNC ReportProj1_IReportXEventsRegOnOnBeginPrintDoc (CAObjHandle serverObject,
                                                                IReportXEventsRegOnOnBeginPrintDoc_CallbackType callbackFunction,
                                                                void *callbackData,
                                                                int enableCallbacks,
                                                                int *callbackId);

HRESULT CVIFUNC ReportProj1_IReportXEventsRegOnOnEndPrintDoc (CAObjHandle serverObject,
                                                              IReportXEventsRegOnOnEndPrintDoc_CallbackType callbackFunction,
                                                              void *callbackData,
                                                              int enableCallbacks,
                                                              int *callbackId);

HRESULT CVIFUNC ReportProj1_IReportXEventsRegOnOnSelectObject (CAObjHandle serverObject,
                                                               IReportXEventsRegOnOnSelectObject_CallbackType callbackFunction,
                                                               void *callbackData,
                                                               int enableCallbacks,
                                                               int *callbackId);

HRESULT CVIFUNC ReportProj1_IReportXEventsRegOnOnObjectRDown (CAObjHandle serverObject,
                                                              IReportXEventsRegOnOnObjectRDown_CallbackType callbackFunction,
                                                              void *callbackData,
                                                              int enableCallbacks,
                                                              int *callbackId);

HRESULT CVIFUNC ReportProj1_IReportXEventsRegOnOnButtonClick (CAObjHandle serverObject,
                                                              IReportXEventsRegOnOnButtonClick_CallbackType callbackFunction,
                                                              void *callbackData,
                                                              int enableCallbacks,
                                                              int *callbackId);

HRESULT CVIFUNC ReportProj1_IReportXEventsRegOnOnAdjustedSeries (CAObjHandle serverObject,
                                                                 IReportXEventsRegOnOnAdjustedSeries_CallbackType callbackFunction,
                                                                 void *callbackData,
                                                                 int enableCallbacks,
                                                                 int *callbackId);

HRESULT CVIFUNC ReportProj1_IReportXEventsRegOnOnDropDown (CAObjHandle serverObject,
                                                           IReportXEventsRegOnOnDropDown_CallbackType callbackFunction,
                                                           void *callbackData,
                                                           int enableCallbacks,
                                                           int *callbackId);

HRESULT CVIFUNC ReportProj1_IReportXEventsRegOnOnCellLDown (CAObjHandle serverObject,
                                                            IReportXEventsRegOnOnCellLDown_CallbackType callbackFunction,
                                                            void *callbackData,
                                                            int enableCallbacks,
                                                            int *callbackId);

HRESULT CVIFUNC ReportProj1_IReportXEventsRegOnOnPoleLDown (CAObjHandle serverObject,
                                                            IReportXEventsRegOnOnPoleLDown_CallbackType callbackFunction,
                                                            void *callbackData,
                                                            int enableCallbacks,
                                                            int *callbackId);

HRESULT CVIFUNC ReportProj1_IReportXEventsRegOnOnPreviewShow (CAObjHandle serverObject,
                                                              IReportXEventsRegOnOnPreviewShow_CallbackType callbackFunction,
                                                              void *callbackData,
                                                              int enableCallbacks,
                                                              int *callbackId);
#ifdef __cplusplus
    }
#endif
#endif /* _REPORTPROJ1_H */
