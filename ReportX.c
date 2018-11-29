#include "ReportX.h"
#include <userint.h>

static void CVIFUNC IReportXEventsRegOnOnActivate_EventVTableFunc (void *thisPtr);

static void CVIFUNC IReportXEventsRegOnOnClick_EventVTableFunc (void *thisPtr);

static void CVIFUNC IReportXEventsRegOnOnCreate_EventVTableFunc (void *thisPtr);

static void CVIFUNC IReportXEventsRegOnOnDblClick_EventVTableFunc (void *thisPtr);

static void CVIFUNC IReportXEventsRegOnOnDestroy_EventVTableFunc (void *thisPtr);

static void CVIFUNC IReportXEventsRegOnOnDeactivate_EventVTableFunc (void *thisPtr);

static void CVIFUNC IReportXEventsRegOnOnKeyPress_EventVTableFunc (void *thisPtr,
                                                                   short *key);

static void CVIFUNC IReportXEventsRegOnOnPaint_EventVTableFunc (void *thisPtr);

static long CVIFUNC IReportXEventsRegOnOnSelectChange_EventVTableFunc (void *thisPtr,
                                                                       long aCol1,
                                                                       long aRow1,
                                                                       long aCol2,
                                                                       long aRow2);

static long CVIFUNC IReportXEventsRegOnOnInputChange_EventVTableFunc (void *thisPtr,
                                                                      long aCol,
                                                                      long aRow);

static long CVIFUNC IReportXEventsRegOnOnPoleLUp_EventVTableFunc (void *thisPtr,
                                                                  long aIndex,
                                                                  long aOrientation);

static long CVIFUNC IReportXEventsRegOnOnPoleRDown_EventVTableFunc (void *thisPtr,
                                                                    long aIndex,
                                                                    long aOrientation,
                                                                    long aScreenX,
                                                                    long aScreenY);

static long CVIFUNC IReportXEventsRegOnOnCellLUp_EventVTableFunc (void *thisPtr,
                                                                  long aCol,
                                                                  long aRow);

static long CVIFUNC IReportXEventsRegOnOnCellRDown_EventVTableFunc (void *thisPtr,
                                                                    long aCol,
                                                                    long aRow,
                                                                    long aScreenX,
                                                                    long aScreenY);

static long CVIFUNC IReportXEventsRegOnOnCellDblCLick_EventVTableFunc (void *thisPtr,
                                                                       long aCol,
                                                                       long aRow);

static long CVIFUNC IReportXEventsRegOnOnCellChanged_EventVTableFunc (void *thisPtr,
                                                                      long aCol,
                                                                      long aRow,
                                                                      BSTR aCellValue);

static long CVIFUNC IReportXEventsRegOnOnCellChanging_EventVTableFunc (void *thisPtr,
                                                                       long aCol,
                                                                       long aRow,
                                                                       BSTR *cellValue,
                                                                       VBOOL *cellChange);

static long CVIFUNC IReportXEventsRegOnOnLeftChange_EventVTableFunc (void *thisPtr,
                                                                     long aIndex);

static long CVIFUNC IReportXEventsRegOnOnTopChange_EventVTableFunc (void *thisPtr,
                                                                    long aIndex);

static long CVIFUNC IReportXEventsRegOnOnError_EventVTableFunc (void *thisPtr,
                                                                BSTR aMessage);

static long CVIFUNC IReportXEventsRegOnOnBeginPrintDoc_EventVTableFunc (void *thisPtr,
                                                                        long aPrinter,
                                                                        BSTR *title,
                                                                        VBOOL *titleChange);

static long CVIFUNC IReportXEventsRegOnOnEndPrintDoc_EventVTableFunc (void *thisPtr,
                                                                      long aPrinter);

static long CVIFUNC IReportXEventsRegOnOnSelectObject_EventVTableFunc (void *thisPtr,
                                                                       long objectType,
                                                                       BSTR objectName);

static long CVIFUNC IReportXEventsRegOnOnObjectRDown_EventVTableFunc (void *thisPtr,
                                                                      long aObjectType,
                                                                      BSTR aObjectName,
                                                                      long aScreenX,
                                                                      long aScreenY);

static long CVIFUNC IReportXEventsRegOnOnButtonClick_EventVTableFunc (void *thisPtr,
                                                                      long aCol,
                                                                      long aRow,
                                                                      BSTR aButtonText,
                                                                      BSTR *buttonScript);

static long CVIFUNC IReportXEventsRegOnOnAdjustedSeries_EventVTableFunc (void *thisPtr,
                                                                         BSTR aChartName,
                                                                         long aIndex,
                                                                         long aSeriesType,
                                                                         BSTR aSeriesSignText,
                                                                         BSTR aSeriesDataText,
                                                                         BSTR aSeriesCell);

static long CVIFUNC IReportXEventsRegOnOnDropDown_EventVTableFunc (void *thisPtr,
                                                                   long aCol,
                                                                   long aRow,
                                                                   BSTR *listText);

static long CVIFUNC IReportXEventsRegOnOnCellLDown_EventVTableFunc (void *thisPtr,
                                                                    long aCol,
                                                                    long aRow);

static long CVIFUNC IReportXEventsRegOnOnPoleLDown_EventVTableFunc (void *thisPtr,
                                                                    long aIndex,
                                                                    long aOrientation);

static long CVIFUNC IReportXEventsRegOnOnPreviewShow_EventVTableFunc (void *thisPtr,
                                                                      long aPrinter,
                                                                      BSTR *previewParameter,
                                                                      VBOOL *previewChange);

#define __ActiveXCtrlErrorHandler() \
if ((ctrlId) > 0) \
	{ \
	if (controlID) \
		*controlID = (ctrlId); \
	if (UILError) \
		*UILError = 0; \
	__result = S_OK; \
	} \
else if ((ctrlId) == UIEActiveXError) \
	{ \
	if (controlID) \
		*controlID = 0; \
	if (UILError) \
		*UILError = 0; \
	} \
else \
	{ \
	if (controlID) \
		*controlID = 0; \
	if (UILError) \
		*UILError = (ctrlId); \
	__result = E_CVIAUTO_CVI_UI_ERROR; \
	}

typedef interface tagReportProj1_IReportX_Interface ReportProj1_IReportX_Interface;

typedef struct tagReportProj1_IReportX_VTable
{
	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( ReportProj1_IReportX_Interface __RPC_FAR * This, 
	                                                         REFIID riid, 
	                                                         void __RPC_FAR *__RPC_FAR *ppvObject);

	ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( ReportProj1_IReportX_Interface __RPC_FAR * This);

	ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( ReportProj1_IReportX_Interface __RPC_FAR * This);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( ReportProj1_IReportX_Interface __RPC_FAR * This, 
	                                                           UINT __RPC_FAR *pctinfo);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( ReportProj1_IReportX_Interface __RPC_FAR * This, 
	                                                      UINT iTInfo, 
	                                                      LCID lcid, 
	                                                      ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( ReportProj1_IReportX_Interface __RPC_FAR * This, 
	                                                        REFIID riid, 
	                                                        LPOLESTR __RPC_FAR *rgszNames, 
	                                                        UINT cNames, 
	                                                        LCID lcid, 
	                                                        DISPID __RPC_FAR *rgDispId);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( ReportProj1_IReportX_Interface __RPC_FAR * This, 
	                                                 DISPID dispIdMember, 
	                                                 REFIID riid, 
	                                                 LCID lcid, 
	                                                 WORD wFlags, 
	                                                 DISPPARAMS __RPC_FAR *pDispParams, 
	                                                 VARIANT __RPC_FAR *pVarResult, 
	                                                 EXCEPINFO __RPC_FAR *pExcepInfo, 
	                                                 UINT __RPC_FAR *puArgErr);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetVisible_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                     VBOOL *value);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetVisible_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                     VBOOL value);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetAutoScroll_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                        VBOOL *value);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetAutoScroll_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                        VBOOL value);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetAutoSize_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                      VBOOL *value);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetAutoSize_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                      VBOOL value);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetAxBorderStyle_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                           long *value);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetAxBorderStyle_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                           long value);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetCaption_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                     BSTR *value);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetCaption_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                     BSTR value);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetColor_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                   unsigned long *value);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetColor_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                   unsigned long value);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetFont_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                  LPDISPATCH *value);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetFont_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                  LPDISPATCH value);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetByRefFont_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                       LPDISPATCH *value);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetKeyPreview_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                        VBOOL *value);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetKeyPreview_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                        VBOOL value);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetPixelsPerInch_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                           long *value);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetPixelsPerInch_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                           long value);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetPrintScale_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                        long *value);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetPrintScale_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                        long value);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetScaled_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                    VBOOL *value);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetScaled_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                    VBOOL value);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetActive_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                    VBOOL *value);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetDropTarget_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                        VBOOL *value);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetDropTarget_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                        VBOOL value);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetHelpFile_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                      BSTR *value);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetHelpFile_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                      BSTR value);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetDoubleBuffered_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                            VBOOL *value);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetDoubleBuffered_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                            VBOOL value);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetAlignDisabled_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                           VBOOL *value);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetVisibleDockClientCount_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                                    long *value);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetEnabled_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                     VBOOL *value);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetEnabled_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                     VBOOL value);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetCursor_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                    short *value);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetCursor_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                    short value);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetHelpType_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                      long *value);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetHelpType_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                      long value);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetHelpKeyword_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                         BSTR *value);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetHelpKeyword_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                         BSTR value);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *InsertCol_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                    long aCol, 
	                                                    long aCount);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *InsertRow_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                    long aRow, 
	                                                    long aCount);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *AppendCol_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                    long aCount);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *AppendRow_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                    long aCount);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *DeleteCol_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                    long aCol, 
	                                                    long aCount);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *DeleteRow_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                    long aRow, 
	                                                    long aCount);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *MergeCell_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                    long aCol1, 
	                                                    long aRow1, 
	                                                    long aCol2, 
	                                                    long aRow2);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SplitCell_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                    long aCol1, 
	                                                    long aRow1, 
	                                                    long aCol2, 
	                                                    long aRow2);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SaveReport_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                     BSTR aFileName);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *OpenReport_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                     BSTR aFileName);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CutCell_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                  long aCol1, 
	                                                  long aRow1, 
	                                                  long aCol2, 
	                                                  long aRow2);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CopyCell_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                   long aCol1, 
	                                                   long aRow1, 
	                                                   long aCol2, 
	                                                   long aRow2);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Paste_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                long aCol, 
	                                                long aRow, 
	                                                VBOOL aSize);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetCellFontName_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                          long aCol, 
	                                                          long aRow, 
	                                                          BSTR aFontName);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetCellFontSize_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                          long aCol, 
	                                                          long aRow, 
	                                                          long aFontSize);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetCellFontColor_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                           long aCol, 
	                                                           long aRow, 
	                                                           long aFontColor);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetCellFontStyle_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                           long aCol, 
	                                                           long aRow, 
	                                                           long aFontStyle, 
	                                                           VBOOL aStyleBool);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetCellFontName_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                          long aCol, 
	                                                          long aRow, 
	                                                          BSTR *value);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetCellFontSize_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                          long aCol, 
	                                                          long aRow, 
	                                                          long *value);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetCellFontColor_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                           long aCol, 
	                                                           long aRow, 
	                                                           long *value);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetCellFontStyle_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                           long aCol, 
	                                                           long aRow, 
	                                                           long aFontStyle, 
	                                                           VBOOL *value);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetCellHAlignment_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                            long aCol, 
	                                                            long aRow, 
	                                                            long aHAlignment);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetCellVAlignment_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                            long aCol, 
	                                                            long aRow, 
	                                                            long aVAlignment);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetCellHAlignment_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                            long aCol, 
	                                                            long aRow, 
	                                                            long *value);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetCellVAlignment_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                            long aCol, 
	                                                            long aRow, 
	                                                            long *value);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetCellMultiline_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                           long aCol, 
	                                                           long aRow, 
	                                                           VBOOL aMultiline);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetCellMultiline_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                           long aCol, 
	                                                           long aRow, 
	                                                           VBOOL *value);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *PrintPreview_) (ReportProj1_IReportX_Interface __RPC_FAR *This);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetColWidth_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                      long aCol, 
	                                                      long aWidth);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetRowHeight_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                       long aRow, 
	                                                       long aHeight);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetTextCell_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                      long aCol, 
	                                                      long aRow);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetDropCell_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                      long aCol, 
	                                                      long aRow, 
	                                                      BSTR aListText);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetButtonCell_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                        long aCol, 
	                                                        long aRow, 
	                                                        BSTR aButtonText, 
	                                                        BSTR aButtonScript);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetCheckCell_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                       long aCol, 
	                                                       long aRow, 
	                                                       BSTR aCheckText);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetRadioCell_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                       long aCol, 
	                                                       long aRow, 
	                                                       BSTR aRadioText);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *AddObjectChart_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                         long aCol, 
	                                                         long aRow, 
	                                                         BSTR aChartName, 
	                                                         long aWidth, 
	                                                         long aHeight, 
	                                                         BSTR aTitleText, 
	                                                         BSTR aHorizontalText, 
	                                                         BSTR aVerticalText, 
	                                                         BSTR *value);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetDateCell_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                      long aCol, 
	                                                      long aRow);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetCellFormat_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                        long aCol, 
	                                                        long aRow, 
	                                                        long aFormatType, 
	                                                        BSTR aFormatText);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetCellFormat_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                        long aCol, 
	                                                        long aRow, 
	                                                        long *formatType, 
	                                                        BSTR *formatText);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetCellIme_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                     long aCol, 
	                                                     long aRow, 
	                                                     BSTR aImeName);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetCellIme_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                     long aCol, 
	                                                     long aRow, 
	                                                     BSTR *value);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetCellControl_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                         long aCol, 
	                                                         long aRow, 
	                                                         long aControlType);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetCellControl_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                         long aCol, 
	                                                         long aRow, 
	                                                         long *value);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetCellBorder_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                        long aCol, 
	                                                        long aRow, 
	                                                        long aBorderType, 
	                                                        long aBorderWidth, 
	                                                        long aBorderStyle);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetCellBorder_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                        long aCol, 
	                                                        long aRow, 
	                                                        long aBorderType, 
	                                                        long *borderWidth, 
	                                                        long *borderStyle);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *DelObjectChart_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                         BSTR aChartName);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *AddChartSeries_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                         BSTR aChartName, 
	                                                         long aSeriesType, 
	                                                         BSTR aSeriesSignText, 
	                                                         BSTR aSeriesDataText, 
	                                                         BSTR aSeriesCell);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *AddCellPicture_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                         long aCol, 
	                                                         long aRow, 
	                                                         BSTR aFileName, 
	                                                         VBOOL aStretch);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetTimeCell_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                      long aCol, 
	                                                      long aRow);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetDisplayColCount_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                             long *value);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetDisplayRowCount_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                             long *value);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetSaved_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                   VBOOL *value);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetSaved_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                   VBOOL value);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetSeparatorLine_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                           VBOOL *value);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetSeparatorLine_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                           VBOOL value);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetFrozenCol_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                       long aFrozenStart, 
	                                                       long aFrozenEnd);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetFrozenRow_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                       long aFrozenStart, 
	                                                       long aFrozenEnd);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetLinkCell_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                      long aCol, 
	                                                      long aRow, 
	                                                      BSTR aLinkText, 
	                                                      BSTR aLinkAddress);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetCellBackColor_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                           long aCol, 
	                                                           long aRow, 
	                                                           long aBackColor);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetCellBackColor_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                           long aCol, 
	                                                           long aRow, 
	                                                           long *value);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetColWidth_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                      long aCol, 
	                                                      long *value);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetRowHeight_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                       long aRow, 
	                                                       long *value);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetCellReadOnly_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                          long aCol, 
	                                                          long aRow, 
	                                                          VBOOL aReadOnly);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetCellReadOnly_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                          long aCol, 
	                                                          long aRow, 
	                                                          VBOOL *value);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ClearChartSeries_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                           BSTR aChartName);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetCellAlias_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                       long aCol, 
	                                                       long aRow, 
	                                                       BSTR aAlias);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetCellAlias_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                       long aCol, 
	                                                       long aRow, 
	                                                       BSTR *value);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetCellValue_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                       long aCol, 
	                                                       long aRow, 
	                                                       BSTR aValue);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetCellValue_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                       long aCol, 
	                                                       long aRow, 
	                                                       BSTR *value);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetPoleWidth_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                       long *value);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetPoleWidth_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                       long value);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetPoleHeight_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                        long *value);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetPoleHeight_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                        long value);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetColCount_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                      long *value);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetColCount_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                      long value);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetRowCount_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                      long *value);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetRowCount_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                      long value);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetLeftCol_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                     long *value);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetLeftCol_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                     long value);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTopRow_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                    long *value);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetTopRow_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                    long value);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *PrintSheet_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                     VBOOL aDialog);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *PrintSetup_) (ReportProj1_IReportX_Interface __RPC_FAR *This);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ImportXML_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                    BSTR aXML);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ExportXML_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                    long aType, 
	                                                    BSTR aEncoding, 
	                                                    BSTR *value);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *InvalidatePaint_) (ReportProj1_IReportX_Interface __RPC_FAR *This);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ValidatePaint_) (ReportProj1_IReportX_Interface __RPC_FAR *This);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetPainted_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                     VBOOL *value);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetPainted_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                     VBOOL value);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetCellExpression_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                            long aCol, 
	                                                            long aRow, 
	                                                            BSTR aExpression);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetCellExpression_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                            long aCol, 
	                                                            long aRow, 
	                                                            BSTR *value);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ExplainCellExpression_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                                long aCol, 
	                                                                long aRow);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ExplainAllExpresion_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                              long aOrder);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ExportExcel_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                      BSTR aFileName, 
	                                                      BSTR aSheetName, 
	                                                      VBOOL aDisplayValue);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ExportExcelOle_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                         BSTR aFileName, 
	                                                         long aCol1, 
	                                                         long aRow1, 
	                                                         long aCol2, 
	                                                         long aRow2, 
	                                                         BSTR aSheetName, 
	                                                         VBOOL aOleText);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ImportExcelOle_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                         BSTR aFileName, 
	                                                         long aCol1, 
	                                                         long aRow1, 
	                                                         long aCol2, 
	                                                         long aRow2, 
	                                                         VBOOL aOleText);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetCellScript_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                        long aCol, 
	                                                        long aRow, 
	                                                        long aScriptType, 
	                                                        BSTR aScriptText);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetCellScript_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                        long aCol, 
	                                                        long aRow, 
	                                                        long *scriptType, 
	                                                        BSTR *scriptText);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *DelCellPicture_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                         long aCol, 
	                                                         long aRow);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Transpose_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                    long aCol1, 
	                                                    long aRow1, 
	                                                    long aCol2, 
	                                                    long aRow2);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *EditCellScript_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                         long aCol, 
	                                                         long aRow);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ExportHtml_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                     BSTR aPicturePath, 
	                                                     VBOOL aExportObject, 
	                                                     BSTR *value);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ExportPdf_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                    BSTR aFileName);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ExportText_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                     long aCol1, 
	                                                     long aRow1, 
	                                                     long aCol2, 
	                                                     long aRow2, 
	                                                     BSTR aSeparator, 
	                                                     BSTR *value);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ImportText_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                     long aCol, 
	                                                     long aRow, 
	                                                     BSTR aText, 
	                                                     BSTR aSeparator);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *NewReport_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                    long aColCount, 
	                                                    long aRowCount);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetSelectCell_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                        long aCol1, 
	                                                        long aRow1, 
	                                                        long aCol2, 
	                                                        long aRow2);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetSelectCell_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                        long *col1, 
	                                                        long *row1, 
	                                                        long *col2, 
	                                                        long *row2);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetInputCell_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                       long *col, 
	                                                       long *row);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CutObject_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                    BSTR aObjectName);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CopyObject_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                     BSTR aObjectName);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetColPageBreak_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                          long aCol, 
	                                                          VBOOL aPageBreak);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetRowPageBreak_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                          long aRow, 
	                                                          VBOOL aPageBreak);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SaveString_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                     VBOOL aCompression, 
	                                                     BSTR *value);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *OpenString_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                     BSTR aReport, 
	                                                     VBOOL aCompression);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetEnterTo_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                     long *value);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetEnterTo_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                     long value);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetMoveChart_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                       VBOOL *value);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetMoveChart_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                       VBOOL value);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetUpdateChart_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                         VBOOL *value);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetUpdateChart_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                         VBOOL value);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetExpandCell_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                        long *col1, 
	                                                        long *row1, 
	                                                        long *col2, 
	                                                        long *row2);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetChartRange_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                        BSTR aChartName, 
	                                                        long *chartWidth, 
	                                                        long *chartHeight);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetCellCoordinate_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                            BSTR aAlias, 
	                                                            long *col, 
	                                                            long *row);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetCellPrintHide_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                           long aCol, 
	                                                           long aRow, 
	                                                           VBOOL aPrintHide);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetCellPrintHide_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                           long aCol, 
	                                                           long aRow, 
	                                                           VBOOL *value);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetCellNextPos_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                         long aCol, 
	                                                         long aRow, 
	                                                         long aNextCol, 
	                                                         long aNextRow);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetCellNextPos_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                         long aCol, 
	                                                         long aRow, 
	                                                         long *nextCol, 
	                                                         long *nextRow);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Find_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                               long aCol1, 
	                                               long aRow1, 
	                                               long aCol2, 
	                                               long aRow2, 
	                                               VBOOL aColOrRow, 
	                                               VBOOL aUpOrDown, 
	                                               VBOOL aCaseSensitive, 
	                                               VBOOL aWholeWords, 
	                                               BSTR aFindString, 
	                                               VBOOL *value);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Replace_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                  long aCol1, 
	                                                  long aRow1, 
	                                                  long aCol2, 
	                                                  long aRow2, 
	                                                  VBOOL aCaseSensitive, 
	                                                  VBOOL aWholeWords, 
	                                                  BSTR aFindString, 
	                                                  BSTR aReplaceString);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SortCol_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                  long aCol, 
	                                                  long aCol1, 
	                                                  long aRow1, 
	                                                  long aCol2, 
	                                                  long aRow2, 
	                                                  VBOOL aAscending);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SortRow_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                  long aRow, 
	                                                  long aCol1, 
	                                                  long aRow1, 
	                                                  long aCol2, 
	                                                  long aRow2, 
	                                                  VBOOL aAscending);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetChartRange_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                        BSTR aChartName, 
	                                                        long aChartWidth, 
	                                                        long aChartHeight);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetCellType_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                      long aCol, 
	                                                      long aRow, 
	                                                      long *value);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetSelectObjectChart_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                               BSTR aChartName);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetSelectChartName_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                             BSTR *value);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetPrinterIndex_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                          long *value);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetPrinterIndex_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                          long value);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetPaperSize_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                       long *value);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetPaperSize_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                       long value);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetPageWidth_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                       long *value);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetPageWidth_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                       long value);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetPageHeight_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                        long *value);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetPageHeight_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                        long value);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetPrintOrientation_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                              VBOOL *value);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetPrintOrientation_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                              VBOOL value);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetPrintCopies_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                         long *value);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetPrintCopies_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                         long value);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetLeftMargin_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                        long *value);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetLeftMargin_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                        long value);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTopMargin_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                       long *value);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetTopMargin_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                       long value);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetRightMargin_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                         long *value);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetRightMargin_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                         long value);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetBottomMargin_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                          long *value);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetBottomMargin_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                          long value);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetHeaderMargin_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                          long *value);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetHeaderMargin_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                          long value);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetFooterMargin_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                          long *value);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetFooterMargin_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                          long value);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetPrintBorders_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                          VBOOL *value);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetPrintBorders_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                          VBOOL value);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetPrintBackColor_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                            VBOOL *value);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetPrintBackColor_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                            VBOOL value);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetPageFontName_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                          BSTR *value);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetPageFontName_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                          BSTR value);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetPageFontSize_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                          long *value);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetPageFontSize_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                          long value);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetPageHeaderLeftText_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                                BSTR *value);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetPageHeaderLeftText_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                                BSTR value);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetPageFooterLeftText_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                                BSTR *value);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetPageFooterLeftText_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                                BSTR value);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetLeftColCount_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                          long *value);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetLeftColCount_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                          long value);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTopRowCount_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                         long *value);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetTopRowCount_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                         long value);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetRightColCount_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                           long *value);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetRightColCount_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                           long value);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetBottomRowCount_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                            long *value);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetBottomRowCount_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                            long value);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetPrintZoom_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                       long *value);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetPrintZoom_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                       long value);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetPrintArea_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                       BSTR *value);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetPrintArea_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                       BSTR value);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetPrintOrder_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                        VBOOL *value);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetPrintOrder_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                        VBOOL value);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetCellButtonText_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                            long aCol, 
	                                                            long aRow, 
	                                                            BSTR *value);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetCellButtonScript_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                              long aCol, 
	                                                              long aRow, 
	                                                              BSTR *value);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetCellDropText_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                          long aCol, 
	                                                          long aRow, 
	                                                          BSTR *value);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetCellTextLength_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                            long aCol, 
	                                                            long aRow, 
	                                                            long aTextLength);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetCellTextLength_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                            long aCol, 
	                                                            long aRow, 
	                                                            long *value);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetCellCharCase_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                          long aCol, 
	                                                          long aRow, 
	                                                          long aCharCase);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetCellCharCase_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                          long aCol, 
	                                                          long aRow, 
	                                                          long *value);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetCellAppendDataLength_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                                  long aCol, 
	                                                                  long aRow, 
	                                                                  long aNoteLength);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetCellAppendDataLength_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                                  long aCol, 
	                                                                  long aRow, 
	                                                                  long *value);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetCellAppendData_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                            long aCol, 
	                                                            long aRow, 
	                                                            long aIndex, 
	                                                            BSTR aAppendData);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetCellAppendData_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                            long aCol, 
	                                                            long aRow, 
	                                                            long aIndex, 
	                                                            BSTR *value);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Fill_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                               long aCol1, 
	                                               long aRow1, 
	                                               long aCol2, 
	                                               long aRow2, 
	                                               long aDirection, 
	                                               long aFillType);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetChartReadOnly_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                           BSTR aChartName, 
	                                                           VBOOL aReadOnly);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetChartReadOnly_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                           BSTR aChartName, 
	                                                           VBOOL *value);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetChartSeries_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                         BSTR aChartName, 
	                                                         long aIndex, 
	                                                         long *seriesType, 
	                                                         BSTR *seriesSignText, 
	                                                         BSTR *seriesDataText, 
	                                                         BSTR *seriesCell);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetChartSeriesCount_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                              BSTR aChartName, 
	                                                              long *value);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *DelChartSeries_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                         BSTR aChartName, 
	                                                         long aIndex);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetFrozenCol_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                       long *frozenStart, 
	                                                       long *frozenEnd);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetFrozenRow_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                       long *frozenStart, 
	                                                       long *frozenEnd);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ChangeChartSeires_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                            BSTR aChartName, 
	                                                            long aIndex, 
	                                                            long aSeriesType, 
	                                                            BSTR aSeriesSignText, 
	                                                            BSTR aSeriesDataText, 
	                                                            BSTR aSeriesCell);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetColBestWidth_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                          long aCol, 
	                                                          long *value);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetRowBestHeight_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                           long aRow, 
	                                                           long *value);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ExplainCellScript_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                            long aCol, 
	                                                            long aRow);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetColPageBreak_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                          long aCol, 
	                                                          VBOOL *value);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetRowPageBreak_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                          long aRow, 
	                                                          VBOOL *value);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetPoleText_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                      long aOrientation, 
	                                                      long aIndex, 
	                                                      BSTR aText);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetPoleText_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                      long aOrientation, 
	                                                      long aIndex, 
	                                                      BSTR *value);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *EndEditCell_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                      VBOOL aCancel);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetExecuteScript_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                           VBOOL *value);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetExecuteScript_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                           VBOOL value);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetCellSign_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                      long aCol, 
	                                                      long aRow, 
	                                                      long *value);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetGridLine_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                      VBOOL *value);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetGridLine_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                      VBOOL value);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetObjectChart_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                         BSTR aChartName, 
	                                                         BSTR *aTitleText, 
	                                                         BSTR *aHorizontalText, 
	                                                         BSTR *aVerticalText);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ChangeObjectChart_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                            BSTR aChartName, 
	                                                            long aCol, 
	                                                            long aRow, 
	                                                            BSTR aTitleText, 
	                                                            BSTR aHorizontalText, 
	                                                            BSTR aVerticalText);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ClearCell_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                    long aCol1, 
	                                                    long aRow1, 
	                                                    long aCol2, 
	                                                    long aRow2);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetAllChartName_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                          BSTR *value);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *AddPicture_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                     BSTR aFileName);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *DelPicture_) (ReportProj1_IReportX_Interface __RPC_FAR *This);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetCellNote_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                      long aCol, 
	                                                      long aRow, 
	                                                      BSTR aNoteText);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetCellNote_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                      long aCol, 
	                                                      long aRow, 
	                                                      BSTR *value);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetPoleReadOnly_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                          VBOOL *value);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetPoleReadOnly_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                          VBOOL value);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetCellReadOnlyProp_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                              VBOOL *value);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetCellReadOnlyProp_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                              VBOOL value);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CopyRangeToRange_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                           long aCol1, 
	                                                           long aRow1, 
	                                                           long aCol2, 
	                                                           long aRow2, 
	                                                           long aToCol, 
	                                                           long aToRow, 
	                                                           long aCount);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetRightWidth_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                        long *value);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetRightWidth_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                        long value);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetBottomHeight_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                          long *value);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetBottomHeight_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                          long value);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ClearData_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                    long aCol1, 
	                                                    long aRow1, 
	                                                    long aCol2, 
	                                                    long aRow2);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetPaperSource_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                         long *value);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetPaperSource_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                         long value);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetCellWidth_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                       long *value);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetCellWidth_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                       long value);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetCellHeight_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                        long *value);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetCellHeight_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                        long value);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetFontName_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                      BSTR *value);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetFontName_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                      BSTR value);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetFontSize_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                      long *value);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetFontSize_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                      long value);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetCellLabel_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                       long aCol, 
	                                                       long aRow, 
	                                                       BSTR *value);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetRangeLabel_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                        long aCol1, 
	                                                        long aRow1, 
	                                                        long aCol2, 
	                                                        long aRow2, 
	                                                        BSTR *value);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *OpenDatabaseGuide_) (ReportProj1_IReportX_Interface __RPC_FAR *This);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetConnectionString_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                              BSTR *value);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetConnectionString_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                              BSTR value);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *AddField_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                   BSTR aFieldName, 
	                                                   BSTR aFieldAttribute, 
	                                                   long aFieldIndex);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *DelField_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                   long aFieldIndex);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ChangeField_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                      long aFieldIndex, 
	                                                      BSTR aFieldName, 
	                                                      BSTR aFieldAttribute);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetQueryFrom_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                       BSTR *value);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetQueryFrom_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                       BSTR value);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetQueryWhere_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                        BSTR *value);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetQueryWhere_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                        BSTR value);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetQueryHaving_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                         BSTR *value);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetQueryHaving_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                         BSTR value);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ClearField_) (ReportProj1_IReportX_Interface __RPC_FAR *This);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *AddFieldOrder_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                        BSTR aFieldName, 
	                                                        VBOOL aFieldOrder, 
	                                                        long aFieldIndex);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *DelFieldOrder_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                        long aFieldIndex);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *OpenQuery_) (ReportProj1_IReportX_Interface __RPC_FAR *This);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetField_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                   long aFieldIndex, 
	                                                   BSTR *fieldName, 
	                                                   BSTR *fieldAttribute);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetAllField_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                      BSTR *value);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetFeildOrder_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                        long aFieldIndex, 
	                                                        BSTR *fieldName, 
	                                                        VBOOL *fieldOrder);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetAllFieldOrder_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                           BSTR *value);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ClearFieldOrder_) (ReportProj1_IReportX_Interface __RPC_FAR *This);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetReportType_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                        long *value);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetReportType_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                        long value);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetGroupType_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                       long *value);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetGroupType_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                       long value);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetGroupPageBreak_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                            VBOOL *value);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetGroupPageBreak_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                            VBOOL value);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetReportLeft_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                        long *value);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetReportLeft_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                        long value);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetReportTop_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                       long *value);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetReportTop_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                       long value);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *AddFieldCell_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                       BSTR aAlias, 
	                                                       BSTR aFieldName, 
	                                                       long aFieldFunction);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *DelFieldCell_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                       BSTR aAlias);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ClearFieldCell_) (ReportProj1_IReportX_Interface __RPC_FAR *This);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetAllFieldCell_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                          BSTR *value);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetAlternatingColor_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                              long *value);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetAlternatingColor_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                              long value);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetColTotal_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                      VBOOL *value);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetColTotal_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                      VBOOL value);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetRowTotal_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                      VBOOL *value);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetRowTotal_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                      VBOOL value);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ChangeFieldOrder_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                           long aFieldIndex, 
	                                                           BSTR aFieldName, 
	                                                           VBOOL aFieldOrder);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ChangeFieldCell_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                          BSTR aAlias, 
	                                                          BSTR aFieldName, 
	                                                          long aFieldFunction);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetFieldCell_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                       BSTR aAlias, 
	                                                       BSTR *fieldName, 
	                                                       long *fieldFunction);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetSqlText_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                     BSTR *value);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetPoleSelectColor_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                             long *value);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetPoleSelectColor_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                             long value);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetCellSelectColor_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                             long aColor1, 
	                                                             long aColor2);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetCellSelectColor_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                             long *color1, 
	                                                             long *color2);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetPoleColor_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                       long *value);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetPoleColor_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                       long value);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetPoleSeparatorColor_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                                long *value);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetPoleSeparatorColor_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                                long value);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetCellSeparatorColor_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                                long *value);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetCellSeparatorColor_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                                long value);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetBarCodeCell_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                         long aCol, 
	                                                         long aRow, 
	                                                         long aCode, 
	                                                         VBOOL aOrientation);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetCellCode_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                      long aCol, 
	                                                      long aRow, 
	                                                      long *value);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetDisplayZero_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                         VBOOL *value);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetDisplayZero_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                         VBOOL value);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetPageFontColor_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                           long *value);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetPageFontColor_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                           long value);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetPageFontStyleBold_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                               VBOOL *value);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetPageFontStyleBold_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                               VBOOL value);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetPageFontStyleItalic_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                                 VBOOL *value);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetPageFontStyleItalic_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                                 VBOOL value);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetPageHeaderCenterText_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                                  BSTR *value);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetPageHeaderCenterText_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                                  BSTR value);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetPageFooterCenterText_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                                  BSTR *value);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetPageFooterCenterText_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                                  BSTR value);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetPageHeaderRightText_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                                 BSTR *value);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetPageHeaderRightText_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                                 BSTR value);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetPageFooterRightText_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                                 BSTR *value);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetPageFooterRightText_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                                 BSTR value);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetCellCaption_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                         long aCol, 
	                                                         long aRow, 
	                                                         BSTR *value);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetLabelRange_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                        BSTR aLabel, 
	                                                        long *col1, 
	                                                        long *row1, 
	                                                        long *col2, 
	                                                        long *row2, 
	                                                        VBOOL *value);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetRichTextCell_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                          long aCol, 
	                                                          long aRow);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetRichTextFontName_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                              BSTR aFontName);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetRichTextFontSize_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                              long aFontSize);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetRichTextFontColor_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                               long aFontColor);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetRichTextFontStyle_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                               long aFontStyle, 
	                                                               VBOOL aStyleBool);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetRichTextOffset_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                            long aOffset);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetRichTextFontName_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                              BSTR *value);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetRichTextFontSize_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                              long *value);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetRichTextFontColor_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                               long *value);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetRichTextFontStyle_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                               long aFontStyle, 
	                                                               VBOOL *value);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetRichTextOffset_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                            long *value);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *LoadIcon_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                   BSTR aFileName);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetCellRichTextValue_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                               long aCol, 
	                                                               long aRow, 
	                                                               BSTR aValue);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetCellRichTextValue_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                               long aCol, 
	                                                               long aRow, 
	                                                               BSTR *value);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTopReport_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                       long *value);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetTopReport_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                       long value);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetPrintPage_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                       BSTR *value);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetPrintPage_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                       BSTR value);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetColHide_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                     long aCol, 
	                                                     VBOOL aHide);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetRowHide_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                     long aRow, 
	                                                     VBOOL aHide);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *AddColTreeNode_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                         long aLevel, 
	                                                         long aCol1, 
	                                                         long aCol2);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *AddRowTreeNode_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                         long aLevel, 
	                                                         long aRow1, 
	                                                         long aRow2);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *DelColTreeNode_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                         long aCol1, 
	                                                         long aCol2);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *DelRowTreeNode_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                         long aRow1, 
	                                                         long aRow2);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ClearColTreeNode_) (ReportProj1_IReportX_Interface __RPC_FAR *This);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ClearRowTreeNode_) (ReportProj1_IReportX_Interface __RPC_FAR *This);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetAllColTreeNode_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                            long aLevel, 
	                                                            BSTR *value);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetAllRowTreeNode_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                            long aLevel, 
	                                                            BSTR *value);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetChartCell_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                       long aCol, 
	                                                       long aRow, 
	                                                       BSTR aTitleText, 
	                                                       BSTR aHorizontalText, 
	                                                       BSTR aVerticalText, 
	                                                       BSTR aSeriesType, 
	                                                       BSTR aSeriesSignText, 
	                                                       BSTR aSeriesDataText);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetCellChart_) (ReportProj1_IReportX_Interface __RPC_FAR *This, 
	                                                       long aCol, 
	                                                       long aRow, 
	                                                       BSTR *value);

} ReportProj1_IReportX_VTable;

typedef interface tagReportProj1_IReportX_Interface
{
	CONST_VTBL ReportProj1_IReportX_VTable __RPC_FAR *lpVtbl;
} ReportProj1_IReportX_Interface;

static CA_PARAMDATA _IReportXEvents_RegOnOnKeyPress_CA_PARAMDATA[] =
	{
		{"key", VT_I2 | VT_BYREF}
	};

static CA_PARAMDATA _IReportXEvents_RegOnOnSelectChange_CA_PARAMDATA[] =
	{
		{"aCol1", VT_I4},
        {"aRow1", VT_I4},
        {"aCol2", VT_I4},
        {"aRow2", VT_I4}
	};

static CA_PARAMDATA _IReportXEvents_RegOnOnInputChange_CA_PARAMDATA[] =
	{
		{"aCol", VT_I4},
        {"aRow", VT_I4}
	};

static CA_PARAMDATA _IReportXEvents_RegOnOnPoleLUp_CA_PARAMDATA[] =
	{
		{"aIndex", VT_I4},
        {"aOrientation", VT_I4}
	};

static CA_PARAMDATA _IReportXEvents_RegOnOnPoleRDown_CA_PARAMDATA[] =
	{
		{"aIndex", VT_I4},
        {"aOrientation", VT_I4},
        {"aScreenX", VT_I4},
        {"aScreenY", VT_I4}
	};

static CA_PARAMDATA _IReportXEvents_RegOnOnCellLUp_CA_PARAMDATA[] =
	{
		{"aCol", VT_I4},
        {"aRow", VT_I4}
	};

static CA_PARAMDATA _IReportXEvents_RegOnOnCellRDown_CA_PARAMDATA[] =
	{
		{"aCol", VT_I4},
        {"aRow", VT_I4},
        {"aScreenX", VT_I4},
        {"aScreenY", VT_I4}
	};

static CA_PARAMDATA _IReportXEvents_RegOnOnCellDblCLick_CA_PARAMDATA[] =
	{
		{"aCol", VT_I4},
        {"aRow", VT_I4}
	};

static CA_PARAMDATA _IReportXEvents_RegOnOnCellChanged_CA_PARAMDATA[] =
	{
		{"aCol", VT_I4},
        {"aRow", VT_I4},
        {"aCellValue", VT_BSTR}
	};

static CA_PARAMDATA _IReportXEvents_RegOnOnCellChanging_CA_PARAMDATA[] =
	{
		{"aCol", VT_I4},
        {"aRow", VT_I4},
        {"cellValue", VT_BSTR | VT_BYREF},
        {"cellChange", VT_BOOL | VT_BYREF}
	};

static CA_PARAMDATA _IReportXEvents_RegOnOnLeftChange_CA_PARAMDATA[] =
	{
		{"aIndex", VT_I4}
	};

static CA_PARAMDATA _IReportXEvents_RegOnOnTopChange_CA_PARAMDATA[] =
	{
		{"aIndex", VT_I4}
	};

static CA_PARAMDATA _IReportXEvents_RegOnOnError_CA_PARAMDATA[] =
	{
		{"aMessage", VT_BSTR}
	};

static CA_PARAMDATA _IReportXEvents_RegOnOnBeginPrintDoc_CA_PARAMDATA[] =
	{
		{"aPrinter", VT_I4},
        {"title", VT_BSTR | VT_BYREF},
        {"titleChange", VT_BOOL | VT_BYREF}
	};

static CA_PARAMDATA _IReportXEvents_RegOnOnEndPrintDoc_CA_PARAMDATA[] =
	{
		{"aPrinter", VT_I4}
	};

static CA_PARAMDATA _IReportXEvents_RegOnOnSelectObject_CA_PARAMDATA[] =
	{
		{"objectType", VT_I4},
        {"objectName", VT_BSTR}
	};

static CA_PARAMDATA _IReportXEvents_RegOnOnObjectRDown_CA_PARAMDATA[] =
	{
		{"aObjectType", VT_I4},
        {"aObjectName", VT_BSTR},
        {"aScreenX", VT_I4},
        {"aScreenY", VT_I4}
	};

static CA_PARAMDATA _IReportXEvents_RegOnOnButtonClick_CA_PARAMDATA[] =
	{
		{"aCol", VT_I4},
        {"aRow", VT_I4},
        {"aButtonText", VT_BSTR},
        {"buttonScript", VT_BSTR | VT_BYREF}
	};

static CA_PARAMDATA _IReportXEvents_RegOnOnAdjustedSeries_CA_PARAMDATA[] =
	{
		{"aChartName", VT_BSTR},
        {"aIndex", VT_I4},
        {"aSeriesType", VT_I4},
        {"aSeriesSignText", VT_BSTR},
        {"aSeriesDataText", VT_BSTR},
        {"aSeriesCell", VT_BSTR}
	};

static CA_PARAMDATA _IReportXEvents_RegOnOnDropDown_CA_PARAMDATA[] =
	{
		{"aCol", VT_I4},
        {"aRow", VT_I4},
        {"listText", VT_BSTR | VT_BYREF}
	};

static CA_PARAMDATA _IReportXEvents_RegOnOnCellLDown_CA_PARAMDATA[] =
	{
		{"aCol", VT_I4},
        {"aRow", VT_I4}
	};

static CA_PARAMDATA _IReportXEvents_RegOnOnPoleLDown_CA_PARAMDATA[] =
	{
		{"aIndex", VT_I4},
        {"aOrientation", VT_I4}
	};

static CA_PARAMDATA _IReportXEvents_RegOnOnPreviewShow_CA_PARAMDATA[] =
	{
		{"aPrinter", VT_I4},
        {"previewParameter", VT_BSTR | VT_BYREF},
        {"previewChange", VT_BOOL | VT_BYREF}
	};

static CA_METHODDATA _IReportXEvents_CA_METHODDATA[] =
	{
		{"OnActivate", NULL, 1, 0, CC_STDCALL, 0, DISPATCH_METHOD, VT_EMPTY},
        {"OnClick", NULL, 2, 1, CC_STDCALL, 0, DISPATCH_METHOD, VT_EMPTY},
        {"OnCreate", NULL, 3, 2, CC_STDCALL, 0, DISPATCH_METHOD, VT_EMPTY},
        {"OnDblClick", NULL, 5, 3, CC_STDCALL, 0, DISPATCH_METHOD, VT_EMPTY},
        {"OnDestroy", NULL, 6, 4, CC_STDCALL, 0, DISPATCH_METHOD, VT_EMPTY},
        {"OnDeactivate", NULL, 7, 5, CC_STDCALL, 0, DISPATCH_METHOD, VT_EMPTY},
        {"OnKeyPress", _IReportXEvents_RegOnOnKeyPress_CA_PARAMDATA, 11, 6, CC_STDCALL, 1, DISPATCH_METHOD, VT_EMPTY},
        {"OnPaint", NULL, 16, 7, CC_STDCALL, 0, DISPATCH_METHOD, VT_EMPTY},
        {"OnSelectChange", _IReportXEvents_RegOnOnSelectChange_CA_PARAMDATA, 4, 8, CC_STDCALL, 4, DISPATCH_METHOD, VT_I4},
        {"OnInputChange", _IReportXEvents_RegOnOnInputChange_CA_PARAMDATA, 8, 9, CC_STDCALL, 2, DISPATCH_METHOD, VT_I4},
        {"OnPoleLUp", _IReportXEvents_RegOnOnPoleLUp_CA_PARAMDATA, 9, 10, CC_STDCALL, 2, DISPATCH_METHOD, VT_I4},
        {"OnPoleRDown", _IReportXEvents_RegOnOnPoleRDown_CA_PARAMDATA, 10, 11, CC_STDCALL, 4, DISPATCH_METHOD, VT_I4},
        {"OnCellLUp", _IReportXEvents_RegOnOnCellLUp_CA_PARAMDATA, 12, 12, CC_STDCALL, 2, DISPATCH_METHOD, VT_I4},
        {"OnCellRDown", _IReportXEvents_RegOnOnCellRDown_CA_PARAMDATA, 13, 13, CC_STDCALL, 4, DISPATCH_METHOD, VT_I4},
        {"OnCellDblCLick", _IReportXEvents_RegOnOnCellDblCLick_CA_PARAMDATA, 14, 14, CC_STDCALL, 2, DISPATCH_METHOD, VT_I4},
        {"OnCellChanged", _IReportXEvents_RegOnOnCellChanged_CA_PARAMDATA, 15, 15, CC_STDCALL, 3, DISPATCH_METHOD, VT_I4},
        {"OnCellChanging", _IReportXEvents_RegOnOnCellChanging_CA_PARAMDATA, 17, 16, CC_STDCALL, 4, DISPATCH_METHOD, VT_I4},
        {"OnLeftChange", _IReportXEvents_RegOnOnLeftChange_CA_PARAMDATA, 18, 17, CC_STDCALL, 1, DISPATCH_METHOD, VT_I4},
        {"OnTopChange", _IReportXEvents_RegOnOnTopChange_CA_PARAMDATA, 19, 18, CC_STDCALL, 1, DISPATCH_METHOD, VT_I4},
        {"OnError", _IReportXEvents_RegOnOnError_CA_PARAMDATA, 20, 19, CC_STDCALL, 1, DISPATCH_METHOD, VT_I4},
        {"OnBeginPrintDoc", _IReportXEvents_RegOnOnBeginPrintDoc_CA_PARAMDATA, 21, 20, CC_STDCALL, 3, DISPATCH_METHOD, VT_I4},
        {"OnEndPrintDoc", _IReportXEvents_RegOnOnEndPrintDoc_CA_PARAMDATA, 22, 21, CC_STDCALL, 1, DISPATCH_METHOD, VT_I4},
        {"OnSelectObject", _IReportXEvents_RegOnOnSelectObject_CA_PARAMDATA, 23, 22, CC_STDCALL, 2, DISPATCH_METHOD, VT_I4},
        {"OnObjectRDown", _IReportXEvents_RegOnOnObjectRDown_CA_PARAMDATA, 24, 23, CC_STDCALL, 4, DISPATCH_METHOD, VT_I4},
        {"OnButtonClick", _IReportXEvents_RegOnOnButtonClick_CA_PARAMDATA, 25, 24, CC_STDCALL, 4, DISPATCH_METHOD, VT_I4},
        {"OnAdjustedSeries", _IReportXEvents_RegOnOnAdjustedSeries_CA_PARAMDATA, 26, 25, CC_STDCALL, 6, DISPATCH_METHOD, VT_I4},
        {"OnDropDown", _IReportXEvents_RegOnOnDropDown_CA_PARAMDATA, 27, 26, CC_STDCALL, 3, DISPATCH_METHOD, VT_I4},
        {"OnCellLDown", _IReportXEvents_RegOnOnCellLDown_CA_PARAMDATA, 28, 27, CC_STDCALL, 2, DISPATCH_METHOD, VT_I4},
        {"OnPoleLDown", _IReportXEvents_RegOnOnPoleLDown_CA_PARAMDATA, 29, 28, CC_STDCALL, 2, DISPATCH_METHOD, VT_I4},
        {"OnPreviewShow", _IReportXEvents_RegOnOnPreviewShow_CA_PARAMDATA, 30, 29, CC_STDCALL, 3, DISPATCH_METHOD, VT_I4}
	};

static CA_INTERFACEDATA _IReportXEvents_CA_INTERFACEDATA =
	{
		_IReportXEvents_CA_METHODDATA,
        (unsigned int)(sizeof (_IReportXEvents_CA_METHODDATA) / sizeof (*_IReportXEvents_CA_METHODDATA))
	};

static void * _IReportXEvents_EventVTable[] =
	{
		IReportXEventsRegOnOnActivate_EventVTableFunc,
        IReportXEventsRegOnOnClick_EventVTableFunc,
        IReportXEventsRegOnOnCreate_EventVTableFunc,
        IReportXEventsRegOnOnDblClick_EventVTableFunc,
        IReportXEventsRegOnOnDestroy_EventVTableFunc,
        IReportXEventsRegOnOnDeactivate_EventVTableFunc,
        IReportXEventsRegOnOnKeyPress_EventVTableFunc,
        IReportXEventsRegOnOnPaint_EventVTableFunc,
        IReportXEventsRegOnOnSelectChange_EventVTableFunc,
        IReportXEventsRegOnOnInputChange_EventVTableFunc,
        IReportXEventsRegOnOnPoleLUp_EventVTableFunc,
        IReportXEventsRegOnOnPoleRDown_EventVTableFunc,
        IReportXEventsRegOnOnCellLUp_EventVTableFunc,
        IReportXEventsRegOnOnCellRDown_EventVTableFunc,
        IReportXEventsRegOnOnCellDblCLick_EventVTableFunc,
        IReportXEventsRegOnOnCellChanged_EventVTableFunc,
        IReportXEventsRegOnOnCellChanging_EventVTableFunc,
        IReportXEventsRegOnOnLeftChange_EventVTableFunc,
        IReportXEventsRegOnOnTopChange_EventVTableFunc,
        IReportXEventsRegOnOnError_EventVTableFunc,
        IReportXEventsRegOnOnBeginPrintDoc_EventVTableFunc,
        IReportXEventsRegOnOnEndPrintDoc_EventVTableFunc,
        IReportXEventsRegOnOnSelectObject_EventVTableFunc,
        IReportXEventsRegOnOnObjectRDown_EventVTableFunc,
        IReportXEventsRegOnOnButtonClick_EventVTableFunc,
        IReportXEventsRegOnOnAdjustedSeries_EventVTableFunc,
        IReportXEventsRegOnOnDropDown_EventVTableFunc,
        IReportXEventsRegOnOnCellLDown_EventVTableFunc,
        IReportXEventsRegOnOnPoleLDown_EventVTableFunc,
        IReportXEventsRegOnOnPreviewShow_EventVTableFunc
	};

static CAEventClassDefn _IReportXEvents_CAEventClassDefn =
	{
		(int)sizeof(CAEventClassDefn),
        &ReportProj1_IID_IReportXEvents,
        _IReportXEvents_EventVTable,
        &_IReportXEvents_CA_INTERFACEDATA,
        0
	};

const IID ReportProj1_IID_IReportX =
	{
		0x85A18B9, 0xA4C, 0x42F5, 0xB1, 0x71, 0x4A, 0x1B, 0xE0, 0xD, 0x6C, 0xB3
	};

const IID ReportProj1_IID_IReportXEvents =
	{
		0x77677B42, 0x1FF7, 0x4A55, 0x95, 0x8C, 0xC6, 0x5, 0x93, 0xC7, 0x93, 0x82
	};

const IID ReportProj1_IID_Font =
	{
		0xBEF6E003, 0xA874, 0x101A, 0x8B, 0xBA, 0x0, 0xAA, 0x0, 0x30, 0xC, 0xAB
	};

HRESULT CVIFUNC ReportProj1_NewIReportX (int panel, const char *label, int top,
                                         int left, int *controlID, int *UILError)
{
	HRESULT __result = S_OK;
	int ctrlId;
	GUID clsid = {0xA5DA6E97, 0x1D4C, 0x4708, 0xB7, 0x5, 0x84, 0xA4, 0x57,
	              0x16, 0xB4, 0xDD};
	const char * licStr = NULL;

	ctrlId = NewActiveXCtrl (panel, label, top, left, &clsid,
	                         &ReportProj1_IID_IReportX, licStr, &__result);

	__ActiveXCtrlErrorHandler();

	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXGetVisible (CAObjHandle objectHandle,
                                                ERRORINFO *errorInfo,
                                                VBOOL *value)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	VBOOL value__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetVisible_ (__vtblIFacePtr,
	                                                 &value__Temp));

	if (value)
		{
		*value = value__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXSetVisible (CAObjHandle objectHandle,
                                                ERRORINFO *errorInfo,
                                                VBOOL value)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetVisible_ (__vtblIFacePtr, value));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXGetAutoScroll (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   VBOOL *value)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	VBOOL value__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetAutoScroll_ (__vtblIFacePtr,
	                                                    &value__Temp));

	if (value)
		{
		*value = value__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXSetAutoScroll (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   VBOOL value)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetAutoScroll_ (__vtblIFacePtr, value));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXGetAutoSize (CAObjHandle objectHandle,
                                                 ERRORINFO *errorInfo,
                                                 VBOOL *value)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	VBOOL value__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetAutoSize_ (__vtblIFacePtr,
	                                                  &value__Temp));

	if (value)
		{
		*value = value__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXSetAutoSize (CAObjHandle objectHandle,
                                                 ERRORINFO *errorInfo,
                                                 VBOOL value)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetAutoSize_ (__vtblIFacePtr, value));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXGetAxBorderStyle (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      enum ReportProj1Enum_TxActiveFormBorderStyle *value)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	long value__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetAxBorderStyle_ (__vtblIFacePtr,
	                                                       (long *)&value__Temp));

	if (value)
		{
		*value = value__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXSetAxBorderStyle (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      enum ReportProj1Enum_TxActiveFormBorderStyle value)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetAxBorderStyle_ (__vtblIFacePtr,
	                                                       value));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXGetCaption (CAObjHandle objectHandle,
                                                ERRORINFO *errorInfo,
                                                char **value)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	BSTR value__AutoType = 0;

	if (value)
		*value = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetCaption_ (__vtblIFacePtr,
	                                                 &value__AutoType));

	if (value)
		__caErrChk (CA_BSTRGetCString (value__AutoType, value));

Error:
	CA_FreeBSTR (value__AutoType);
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	if (FAILED(__result))
		{
		if (value)
			{
			CA_FreeMemory (*value);
			*value = 0;
			}
		}
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXSetCaption (CAObjHandle objectHandle,
                                                ERRORINFO *errorInfo,
                                                const char *value)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	BSTR value__AutoType = 0;

	__caErrChk (CA_CStringToBSTR (value, &value__AutoType));

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetCaption_ (__vtblIFacePtr,
	                                                 value__AutoType));

Error:
	CA_FreeBSTR (value__AutoType);
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXGetColor (CAObjHandle objectHandle,
                                              ERRORINFO *errorInfo,
                                              ReportProj1Type_OLE_COLOR *value)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	unsigned long value__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetColor_ (__vtblIFacePtr,
	                                               &value__Temp));

	if (value)
		{
		*value = value__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXSetColor (CAObjHandle objectHandle,
                                              ERRORINFO *errorInfo,
                                              ReportProj1Type_OLE_COLOR value)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetColor_ (__vtblIFacePtr, value));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXGetFont (CAObjHandle objectHandle,
                                             ERRORINFO *errorInfo,
                                             ReportProj1Obj_IFontDisp *value)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	LPDISPATCH value__AutoType = 0;
	LCID __locale;
	int __supportMultithreading;

	if (value)
		*value = 0;

	__caErrChk (CA_GetLocale (objectHandle, &__locale));
	__caErrChk (CA_GetSupportForMultithreading (objectHandle,
	                                            &__supportMultithreading));

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetFont_ (__vtblIFacePtr,
	                                              &value__AutoType));
	

	if (value)
		{
		__caErrChk (CA_CreateObjHandleFromInterface (value__AutoType,
		                                             &ReportProj1_IID_Font,
		                                             __supportMultithreading,
		                                             __locale, 0, 0, value));
		value__AutoType = 0;
		}

Error:
	if (value__AutoType)
		value__AutoType->lpVtbl->Release (value__AutoType);
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	if (FAILED(__result))
		{
		if (value)
			{
			CA_DiscardObjHandle (*value);
			*value = 0;
			}
		}
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXSetFont (CAObjHandle objectHandle,
                                             ERRORINFO *errorInfo,
                                             ReportProj1Obj_IFontDisp value)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	LPDISPATCH value__AutoType = 0;

	if (value)
		{
		__caErrChk (CA_GetInterfaceFromObjHandle (value, &ReportProj1_IID_Font, 1,
	                                          &value__AutoType, NULL));
		}

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetFont_ (__vtblIFacePtr,
	                                              value__AutoType));

Error:
	if (value__AutoType)
		value__AutoType->lpVtbl->Release (value__AutoType);
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXSetByRefFont (CAObjHandle objectHandle,
                                                  ERRORINFO *errorInfo,
                                                  ReportProj1Obj_IFontDisp *value)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	LPDISPATCH  value__AutoType = 0;

	if (value)
		{
		__caErrChk (CA_GetInterfaceFromObjHandle (*value, &ReportProj1_IID_Font, 1,
	                                          &value__AutoType, NULL));
		}

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetByRefFont_ (__vtblIFacePtr,
	                                                   &value__AutoType));

Error:
	if (value__AutoType)
		value__AutoType->lpVtbl->Release (value__AutoType);
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXGetKeyPreview (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   VBOOL *value)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	VBOOL value__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetKeyPreview_ (__vtblIFacePtr,
	                                                    &value__Temp));

	if (value)
		{
		*value = value__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXSetKeyPreview (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   VBOOL value)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetKeyPreview_ (__vtblIFacePtr, value));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXGetPixelsPerInch (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      long *value)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	long value__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetPixelsPerInch_ (__vtblIFacePtr,
	                                                       &value__Temp));

	if (value)
		{
		*value = value__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXSetPixelsPerInch (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      long value)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetPixelsPerInch_ (__vtblIFacePtr,
	                                                       value));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXGetPrintScale (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   enum ReportProj1Enum_TxPrintScale *value)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	long value__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetPrintScale_ (__vtblIFacePtr,
	                                                    (long *)&value__Temp));

	if (value)
		{
		*value = value__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXSetPrintScale (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   enum ReportProj1Enum_TxPrintScale value)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetPrintScale_ (__vtblIFacePtr, value));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXGetScaled (CAObjHandle objectHandle,
                                               ERRORINFO *errorInfo,
                                               VBOOL *value)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	VBOOL value__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetScaled_ (__vtblIFacePtr,
	                                                &value__Temp));

	if (value)
		{
		*value = value__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXSetScaled (CAObjHandle objectHandle,
                                               ERRORINFO *errorInfo, VBOOL value)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetScaled_ (__vtblIFacePtr, value));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXGetActive (CAObjHandle objectHandle,
                                               ERRORINFO *errorInfo,
                                               VBOOL *value)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	VBOOL value__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetActive_ (__vtblIFacePtr,
	                                                &value__Temp));

	if (value)
		{
		*value = value__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXGetDropTarget (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   VBOOL *value)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	VBOOL value__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetDropTarget_ (__vtblIFacePtr,
	                                                    &value__Temp));

	if (value)
		{
		*value = value__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXSetDropTarget (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   VBOOL value)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetDropTarget_ (__vtblIFacePtr, value));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXGetHelpFile (CAObjHandle objectHandle,
                                                 ERRORINFO *errorInfo,
                                                 char **value)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	BSTR value__AutoType = 0;

	if (value)
		*value = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetHelpFile_ (__vtblIFacePtr,
	                                                  &value__AutoType));

	if (value)
		__caErrChk (CA_BSTRGetCString (value__AutoType, value));

Error:
	CA_FreeBSTR (value__AutoType);
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	if (FAILED(__result))
		{
		if (value)
			{
			CA_FreeMemory (*value);
			*value = 0;
			}
		}
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXSetHelpFile (CAObjHandle objectHandle,
                                                 ERRORINFO *errorInfo,
                                                 const char *value)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	BSTR value__AutoType = 0;

	__caErrChk (CA_CStringToBSTR (value, &value__AutoType));

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetHelpFile_ (__vtblIFacePtr,
	                                                  value__AutoType));

Error:
	CA_FreeBSTR (value__AutoType);
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXGetDoubleBuffered (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       VBOOL *value)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	VBOOL value__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetDoubleBuffered_ (__vtblIFacePtr,
	                                                        &value__Temp));

	if (value)
		{
		*value = value__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXSetDoubleBuffered (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       VBOOL value)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetDoubleBuffered_ (__vtblIFacePtr,
	                                                        value));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXGetAlignDisabled (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      VBOOL *value)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	VBOOL value__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetAlignDisabled_ (__vtblIFacePtr,
	                                                       &value__Temp));

	if (value)
		{
		*value = value__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXGetVisibleDockClientCount (CAObjHandle objectHandle,
                                                               ERRORINFO *errorInfo,
                                                               long *value)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	long value__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetVisibleDockClientCount_ (__vtblIFacePtr,
	                                                                &value__Temp));

	if (value)
		{
		*value = value__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXGetEnabled (CAObjHandle objectHandle,
                                                ERRORINFO *errorInfo,
                                                VBOOL *value)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	VBOOL value__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetEnabled_ (__vtblIFacePtr,
	                                                 &value__Temp));

	if (value)
		{
		*value = value__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXSetEnabled (CAObjHandle objectHandle,
                                                ERRORINFO *errorInfo,
                                                VBOOL value)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetEnabled_ (__vtblIFacePtr, value));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXGetCursor (CAObjHandle objectHandle,
                                               ERRORINFO *errorInfo,
                                               short *value)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	short value__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetCursor_ (__vtblIFacePtr,
	                                                &value__Temp));

	if (value)
		{
		*value = value__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXSetCursor (CAObjHandle objectHandle,
                                               ERRORINFO *errorInfo, short value)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetCursor_ (__vtblIFacePtr, value));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXGetHelpType (CAObjHandle objectHandle,
                                                 ERRORINFO *errorInfo,
                                                 enum ReportProj1Enum_TxHelpType *value)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	long value__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetHelpType_ (__vtblIFacePtr,
	                                                  (long *)&value__Temp));

	if (value)
		{
		*value = value__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXSetHelpType (CAObjHandle objectHandle,
                                                 ERRORINFO *errorInfo,
                                                 enum ReportProj1Enum_TxHelpType value)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetHelpType_ (__vtblIFacePtr, value));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXGetHelpKeyword (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    char **value)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	BSTR value__AutoType = 0;

	if (value)
		*value = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetHelpKeyword_ (__vtblIFacePtr,
	                                                     &value__AutoType));

	if (value)
		__caErrChk (CA_BSTRGetCString (value__AutoType, value));

Error:
	CA_FreeBSTR (value__AutoType);
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	if (FAILED(__result))
		{
		if (value)
			{
			CA_FreeMemory (*value);
			*value = 0;
			}
		}
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXSetHelpKeyword (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    const char *value)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	BSTR value__AutoType = 0;

	__caErrChk (CA_CStringToBSTR (value, &value__AutoType));

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetHelpKeyword_ (__vtblIFacePtr,
	                                                     value__AutoType));

Error:
	CA_FreeBSTR (value__AutoType);
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXInsertCol (CAObjHandle objectHandle,
                                               ERRORINFO *errorInfo, long aCol,
                                               long aCount)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->InsertCol_ (__vtblIFacePtr, aCol,
	                                                aCount));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXInsertRow (CAObjHandle objectHandle,
                                               ERRORINFO *errorInfo, long aRow,
                                               long aCount)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->InsertRow_ (__vtblIFacePtr, aRow,
	                                                aCount));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXAppendCol (CAObjHandle objectHandle,
                                               ERRORINFO *errorInfo, long aCount)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->AppendCol_ (__vtblIFacePtr, aCount));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXAppendRow (CAObjHandle objectHandle,
                                               ERRORINFO *errorInfo, long aCount)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->AppendRow_ (__vtblIFacePtr, aCount));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXDeleteCol (CAObjHandle objectHandle,
                                               ERRORINFO *errorInfo, long aCol,
                                               long aCount)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->DeleteCol_ (__vtblIFacePtr, aCol,
	                                                aCount));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXDeleteRow (CAObjHandle objectHandle,
                                               ERRORINFO *errorInfo, long aRow,
                                               long aCount)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->DeleteRow_ (__vtblIFacePtr, aRow,
	                                                aCount));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXMergeCell (CAObjHandle objectHandle,
                                               ERRORINFO *errorInfo, long aCol1,
                                               long aRow1, long aCol2,
                                               long aRow2)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->MergeCell_ (__vtblIFacePtr, aCol1,
	                                                aRow1, aCol2, aRow2));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXSplitCell (CAObjHandle objectHandle,
                                               ERRORINFO *errorInfo, long aCol1,
                                               long aRow1, long aCol2,
                                               long aRow2)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SplitCell_ (__vtblIFacePtr, aCol1,
	                                                aRow1, aCol2, aRow2));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXSaveReport (CAObjHandle objectHandle,
                                                ERRORINFO *errorInfo,
                                                const char *aFileName)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	BSTR aFileName__AutoType = 0;

	__caErrChk (CA_CStringToBSTR (aFileName, &aFileName__AutoType));

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SaveReport_ (__vtblIFacePtr,
	                                                 aFileName__AutoType));

Error:
	CA_FreeBSTR (aFileName__AutoType);
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXOpenReport (CAObjHandle objectHandle,
                                                ERRORINFO *errorInfo,
                                                const char *aFileName)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	BSTR aFileName__AutoType = 0;

	__caErrChk (CA_CStringToBSTR (aFileName, &aFileName__AutoType));

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->OpenReport_ (__vtblIFacePtr,
	                                                 aFileName__AutoType));

Error:
	CA_FreeBSTR (aFileName__AutoType);
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXCutCell (CAObjHandle objectHandle,
                                             ERRORINFO *errorInfo, long aCol1,
                                             long aRow1, long aCol2, long aRow2)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->CutCell_ (__vtblIFacePtr, aCol1, aRow1,
	                                              aCol2, aRow2));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXCopyCell (CAObjHandle objectHandle,
                                              ERRORINFO *errorInfo, long aCol1,
                                              long aRow1, long aCol2, long aRow2)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->CopyCell_ (__vtblIFacePtr, aCol1,
	                                               aRow1, aCol2, aRow2));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXPaste (CAObjHandle objectHandle,
                                           ERRORINFO *errorInfo, long aCol,
                                           long aRow, VBOOL aSize)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->Paste_ (__vtblIFacePtr, aCol, aRow,
	                                            aSize));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXSetCellFontName (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     long aCol, long aRow,
                                                     const char *aFontName)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	BSTR aFontName__AutoType = 0;

	__caErrChk (CA_CStringToBSTR (aFontName, &aFontName__AutoType));

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetCellFontName_ (__vtblIFacePtr, aCol,
	                                                      aRow,
	                                                      aFontName__AutoType));

Error:
	CA_FreeBSTR (aFontName__AutoType);
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXSetCellFontSize (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     long aCol, long aRow,
                                                     long aFontSize)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetCellFontSize_ (__vtblIFacePtr, aCol,
	                                                      aRow, aFontSize));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXSetCellFontColor (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      long aCol, long aRow,
                                                      long aFontColor)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetCellFontColor_ (__vtblIFacePtr,
	                                                       aCol, aRow,
	                                                       aFontColor));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXSetCellFontStyle (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      long aCol, long aRow,
                                                      long aFontStyle,
                                                      VBOOL aStyleBool)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetCellFontStyle_ (__vtblIFacePtr,
	                                                       aCol, aRow,
	                                                       aFontStyle,
	                                                       aStyleBool));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXGetCellFontName (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     long aCol, long aRow,
                                                     char **value)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	BSTR value__AutoType = 0;

	if (value)
		*value = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetCellFontName_ (__vtblIFacePtr, aCol,
	                                                      aRow,
	                                                      &value__AutoType));

	if (value)
		__caErrChk (CA_BSTRGetCString (value__AutoType, value));

Error:
	CA_FreeBSTR (value__AutoType);
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	if (FAILED(__result))
		{
		if (value)
			{
			CA_FreeMemory (*value);
			*value = 0;
			}
		}
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXGetCellFontSize (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     long aCol, long aRow,
                                                     long *value)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	long value__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetCellFontSize_ (__vtblIFacePtr, aCol,
	                                                      aRow, &value__Temp));

	if (value)
		{
		*value = value__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXGetCellFontColor (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      long aCol, long aRow,
                                                      long *value)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	long value__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetCellFontColor_ (__vtblIFacePtr,
	                                                       aCol, aRow,
	                                                       &value__Temp));

	if (value)
		{
		*value = value__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXGetCellFontStyle (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      long aCol, long aRow,
                                                      long aFontStyle,
                                                      VBOOL *value)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	VBOOL value__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetCellFontStyle_ (__vtblIFacePtr,
	                                                       aCol, aRow,
	                                                       aFontStyle,
	                                                       &value__Temp));

	if (value)
		{
		*value = value__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXSetCellHAlignment (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       long aCol, long aRow,
                                                       long aHAlignment)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetCellHAlignment_ (__vtblIFacePtr,
	                                                        aCol, aRow,
	                                                        aHAlignment));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXSetCellVAlignment (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       long aCol, long aRow,
                                                       long aVAlignment)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetCellVAlignment_ (__vtblIFacePtr,
	                                                        aCol, aRow,
	                                                        aVAlignment));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXGetCellHAlignment (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       long aCol, long aRow,
                                                       long *value)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	long value__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetCellHAlignment_ (__vtblIFacePtr,
	                                                        aCol, aRow,
	                                                        &value__Temp));

	if (value)
		{
		*value = value__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXGetCellVAlignment (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       long aCol, long aRow,
                                                       long *value)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	long value__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetCellVAlignment_ (__vtblIFacePtr,
	                                                        aCol, aRow,
	                                                        &value__Temp));

	if (value)
		{
		*value = value__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXSetCellMultiline (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      long aCol, long aRow,
                                                      VBOOL aMultiline)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetCellMultiline_ (__vtblIFacePtr,
	                                                       aCol, aRow,
	                                                       aMultiline));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXGetCellMultiline (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      long aCol, long aRow,
                                                      VBOOL *value)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	VBOOL value__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetCellMultiline_ (__vtblIFacePtr,
	                                                       aCol, aRow,
	                                                       &value__Temp));

	if (value)
		{
		*value = value__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXPrintPreview (CAObjHandle objectHandle,
                                                  ERRORINFO *errorInfo)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->PrintPreview_ (__vtblIFacePtr));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXSetColWidth (CAObjHandle objectHandle,
                                                 ERRORINFO *errorInfo, long aCol,
                                                 long aWidth)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetColWidth_ (__vtblIFacePtr, aCol,
	                                                  aWidth));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXSetRowHeight (CAObjHandle objectHandle,
                                                  ERRORINFO *errorInfo,
                                                  long aRow, long aHeight)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetRowHeight_ (__vtblIFacePtr, aRow,
	                                                   aHeight));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXSetTextCell (CAObjHandle objectHandle,
                                                 ERRORINFO *errorInfo, long aCol,
                                                 long aRow)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetTextCell_ (__vtblIFacePtr, aCol,
	                                                  aRow));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXSetDropCell (CAObjHandle objectHandle,
                                                 ERRORINFO *errorInfo, long aCol,
                                                 long aRow,
                                                 const char *aListText)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	BSTR aListText__AutoType = 0;

	__caErrChk (CA_CStringToBSTR (aListText, &aListText__AutoType));

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetDropCell_ (__vtblIFacePtr, aCol,
	                                                  aRow,
	                                                  aListText__AutoType));

Error:
	CA_FreeBSTR (aListText__AutoType);
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXSetButtonCell (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   long aCol, long aRow,
                                                   const char *aButtonText,
                                                   const char *aButtonScript)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	BSTR aButtonText__AutoType = 0;
	BSTR aButtonScript__AutoType = 0;

	__caErrChk (CA_CStringToBSTR (aButtonText, &aButtonText__AutoType));
	__caErrChk (CA_CStringToBSTR (aButtonScript, &aButtonScript__AutoType));

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetButtonCell_ (__vtblIFacePtr, aCol,
	                                                    aRow,
	                                                    aButtonText__AutoType,
	                                                    aButtonScript__AutoType));

Error:
	CA_FreeBSTR (aButtonText__AutoType);
	CA_FreeBSTR (aButtonScript__AutoType);
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXSetCheckCell (CAObjHandle objectHandle,
                                                  ERRORINFO *errorInfo,
                                                  long aCol, long aRow,
                                                  const char *aCheckText)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	BSTR aCheckText__AutoType = 0;

	__caErrChk (CA_CStringToBSTR (aCheckText, &aCheckText__AutoType));

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetCheckCell_ (__vtblIFacePtr, aCol,
	                                                   aRow,
	                                                   aCheckText__AutoType));

Error:
	CA_FreeBSTR (aCheckText__AutoType);
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXSetRadioCell (CAObjHandle objectHandle,
                                                  ERRORINFO *errorInfo,
                                                  long aCol, long aRow,
                                                  const char *aRadioText)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	BSTR aRadioText__AutoType = 0;

	__caErrChk (CA_CStringToBSTR (aRadioText, &aRadioText__AutoType));

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetRadioCell_ (__vtblIFacePtr, aCol,
	                                                   aRow,
	                                                   aRadioText__AutoType));

Error:
	CA_FreeBSTR (aRadioText__AutoType);
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXAddObjectChart (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    long aCol, long aRow,
                                                    const char *aChartName,
                                                    long aWidth, long aHeight,
                                                    const char *aTitleText,
                                                    const char *aHorizontalText,
                                                    const char *aVerticalText,
                                                    char **value)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	BSTR aChartName__AutoType = 0;
	BSTR aTitleText__AutoType = 0;
	BSTR aHorizontalText__AutoType = 0;
	BSTR aVerticalText__AutoType = 0;
	BSTR value__AutoType = 0;

	if (value)
		*value = 0;

	__caErrChk (CA_CStringToBSTR (aChartName, &aChartName__AutoType));
	__caErrChk (CA_CStringToBSTR (aTitleText, &aTitleText__AutoType));
	__caErrChk (CA_CStringToBSTR (aHorizontalText, &aHorizontalText__AutoType));
	__caErrChk (CA_CStringToBSTR (aVerticalText, &aVerticalText__AutoType));

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->AddObjectChart_ (__vtblIFacePtr, aCol,
	                                                     aRow,
	                                                     aChartName__AutoType,
	                                                     aWidth, aHeight,
	                                                     aTitleText__AutoType,
	                                                     aHorizontalText__AutoType,
	                                                     aVerticalText__AutoType,
	                                                     &value__AutoType));

	if (value)
		__caErrChk (CA_BSTRGetCString (value__AutoType, value));

Error:
	CA_FreeBSTR (aChartName__AutoType);
	CA_FreeBSTR (aTitleText__AutoType);
	CA_FreeBSTR (aHorizontalText__AutoType);
	CA_FreeBSTR (aVerticalText__AutoType);
	CA_FreeBSTR (value__AutoType);
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	if (FAILED(__result))
		{
		if (value)
			{
			CA_FreeMemory (*value);
			*value = 0;
			}
		}
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXSetDateCell (CAObjHandle objectHandle,
                                                 ERRORINFO *errorInfo, long aCol,
                                                 long aRow)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetDateCell_ (__vtblIFacePtr, aCol,
	                                                  aRow));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXSetCellFormat (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   long aCol, long aRow,
                                                   long aFormatType,
                                                   const char *aFormatText)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	BSTR aFormatText__AutoType = 0;

	__caErrChk (CA_CStringToBSTR (aFormatText, &aFormatText__AutoType));

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetCellFormat_ (__vtblIFacePtr, aCol,
	                                                    aRow, aFormatType,
	                                                    aFormatText__AutoType));

Error:
	CA_FreeBSTR (aFormatText__AutoType);
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXGetCellFormat (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   long aCol, long aRow,
                                                   long *formatType,
                                                   char **formatText)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	long formatType__Temp;
	BSTR formatText__AutoType = 0;

	if (formatText)
		*formatText = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetCellFormat_ (__vtblIFacePtr, aCol,
	                                                    aRow,
	                                                    &formatType__Temp,
	                                                    &formatText__AutoType));

	if (formatType)
		{
		*formatType = formatType__Temp;
		}
	if (formatText)
		__caErrChk (CA_BSTRGetCString (formatText__AutoType, formatText));

Error:
	CA_FreeBSTR (formatText__AutoType);
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	if (FAILED(__result))
		{
		if (formatText)
			{
			CA_FreeMemory (*formatText);
			*formatText = 0;
			}
		}
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXSetCellIme (CAObjHandle objectHandle,
                                                ERRORINFO *errorInfo, long aCol,
                                                long aRow, const char *aImeName)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	BSTR aImeName__AutoType = 0;

	__caErrChk (CA_CStringToBSTR (aImeName, &aImeName__AutoType));

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetCellIme_ (__vtblIFacePtr, aCol,
	                                                 aRow, aImeName__AutoType));

Error:
	CA_FreeBSTR (aImeName__AutoType);
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXGetCellIme (CAObjHandle objectHandle,
                                                ERRORINFO *errorInfo, long aCol,
                                                long aRow, char **value)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	BSTR value__AutoType = 0;

	if (value)
		*value = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetCellIme_ (__vtblIFacePtr, aCol,
	                                                 aRow, &value__AutoType));

	if (value)
		__caErrChk (CA_BSTRGetCString (value__AutoType, value));

Error:
	CA_FreeBSTR (value__AutoType);
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	if (FAILED(__result))
		{
		if (value)
			{
			CA_FreeMemory (*value);
			*value = 0;
			}
		}
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXSetCellControl (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    long aCol, long aRow,
                                                    long aControlType)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetCellControl_ (__vtblIFacePtr, aCol,
	                                                     aRow, aControlType));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXGetCellControl (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    long aCol, long aRow,
                                                    long *value)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	long value__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetCellControl_ (__vtblIFacePtr, aCol,
	                                                     aRow, &value__Temp));

	if (value)
		{
		*value = value__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXSetCellBorder (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   long aCol, long aRow,
                                                   long aBorderType,
                                                   long aBorderWidth,
                                                   long aBorderStyle)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetCellBorder_ (__vtblIFacePtr, aCol,
	                                                    aRow, aBorderType,
	                                                    aBorderWidth,
	                                                    aBorderStyle));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXGetCellBorder (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   long aCol, long aRow,
                                                   long aBorderType,
                                                   long *borderWidth,
                                                   long *borderStyle)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetCellBorder_ (__vtblIFacePtr, aCol,
	                                                    aRow, aBorderType,
	                                                    borderWidth,
	                                                    borderStyle));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXDelObjectChart (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    const char *aChartName)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	BSTR aChartName__AutoType = 0;

	__caErrChk (CA_CStringToBSTR (aChartName, &aChartName__AutoType));

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->DelObjectChart_ (__vtblIFacePtr,
	                                                     aChartName__AutoType));

Error:
	CA_FreeBSTR (aChartName__AutoType);
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXAddChartSeries (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    const char *aChartName,
                                                    long aSeriesType,
                                                    const char *aSeriesSignText,
                                                    const char *aSeriesDataText,
                                                    const char *aSeriesCell)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	BSTR aChartName__AutoType = 0;
	BSTR aSeriesSignText__AutoType = 0;
	BSTR aSeriesDataText__AutoType = 0;
	BSTR aSeriesCell__AutoType = 0;

	__caErrChk (CA_CStringToBSTR (aChartName, &aChartName__AutoType));
	__caErrChk (CA_CStringToBSTR (aSeriesSignText, &aSeriesSignText__AutoType));
	__caErrChk (CA_CStringToBSTR (aSeriesDataText, &aSeriesDataText__AutoType));
	__caErrChk (CA_CStringToBSTR (aSeriesCell, &aSeriesCell__AutoType));

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->AddChartSeries_ (__vtblIFacePtr,
	                                                     aChartName__AutoType,
	                                                     aSeriesType,
	                                                     aSeriesSignText__AutoType,
	                                                     aSeriesDataText__AutoType,
	                                                     aSeriesCell__AutoType));

Error:
	CA_FreeBSTR (aChartName__AutoType);
	CA_FreeBSTR (aSeriesSignText__AutoType);
	CA_FreeBSTR (aSeriesDataText__AutoType);
	CA_FreeBSTR (aSeriesCell__AutoType);
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXAddCellPicture (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    long aCol, long aRow,
                                                    const char *aFileName,
                                                    VBOOL aStretch)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	BSTR aFileName__AutoType = 0;

	__caErrChk (CA_CStringToBSTR (aFileName, &aFileName__AutoType));

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->AddCellPicture_ (__vtblIFacePtr, aCol,
	                                                     aRow,
	                                                     aFileName__AutoType,
	                                                     aStretch));

Error:
	CA_FreeBSTR (aFileName__AutoType);
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXSetTimeCell (CAObjHandle objectHandle,
                                                 ERRORINFO *errorInfo, long aCol,
                                                 long aRow)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetTimeCell_ (__vtblIFacePtr, aCol,
	                                                  aRow));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXGetDisplayColCount (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        long *value)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	long value__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetDisplayColCount_ (__vtblIFacePtr,
	                                                         &value__Temp));

	if (value)
		{
		*value = value__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXGetDisplayRowCount (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        long *value)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	long value__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetDisplayRowCount_ (__vtblIFacePtr,
	                                                         &value__Temp));

	if (value)
		{
		*value = value__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXGetSaved (CAObjHandle objectHandle,
                                              ERRORINFO *errorInfo, VBOOL *value)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	VBOOL value__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetSaved_ (__vtblIFacePtr,
	                                               &value__Temp));

	if (value)
		{
		*value = value__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXSetSaved (CAObjHandle objectHandle,
                                              ERRORINFO *errorInfo, VBOOL value)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetSaved_ (__vtblIFacePtr, value));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXGetSeparatorLine (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      VBOOL *value)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	VBOOL value__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetSeparatorLine_ (__vtblIFacePtr,
	                                                       &value__Temp));

	if (value)
		{
		*value = value__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXSetSeparatorLine (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      VBOOL value)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetSeparatorLine_ (__vtblIFacePtr,
	                                                       value));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXSetFrozenCol (CAObjHandle objectHandle,
                                                  ERRORINFO *errorInfo,
                                                  long aFrozenStart,
                                                  long aFrozenEnd)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetFrozenCol_ (__vtblIFacePtr,
	                                                   aFrozenStart,
	                                                   aFrozenEnd));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXSetFrozenRow (CAObjHandle objectHandle,
                                                  ERRORINFO *errorInfo,
                                                  long aFrozenStart,
                                                  long aFrozenEnd)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetFrozenRow_ (__vtblIFacePtr,
	                                                   aFrozenStart,
	                                                   aFrozenEnd));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXSetLinkCell (CAObjHandle objectHandle,
                                                 ERRORINFO *errorInfo, long aCol,
                                                 long aRow,
                                                 const char *aLinkText,
                                                 const char *aLinkAddress)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	BSTR aLinkText__AutoType = 0;
	BSTR aLinkAddress__AutoType = 0;

	__caErrChk (CA_CStringToBSTR (aLinkText, &aLinkText__AutoType));
	__caErrChk (CA_CStringToBSTR (aLinkAddress, &aLinkAddress__AutoType));

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetLinkCell_ (__vtblIFacePtr, aCol,
	                                                  aRow,
	                                                  aLinkText__AutoType,
	                                                  aLinkAddress__AutoType));

Error:
	CA_FreeBSTR (aLinkText__AutoType);
	CA_FreeBSTR (aLinkAddress__AutoType);
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXSetCellBackColor (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      long aCol, long aRow,
                                                      long aBackColor)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetCellBackColor_ (__vtblIFacePtr,
	                                                       aCol, aRow,
	                                                       aBackColor));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXGetCellBackColor (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      long aCol, long aRow,
                                                      long *value)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	long value__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetCellBackColor_ (__vtblIFacePtr,
	                                                       aCol, aRow,
	                                                       &value__Temp));

	if (value)
		{
		*value = value__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXGetColWidth (CAObjHandle objectHandle,
                                                 ERRORINFO *errorInfo, long aCol,
                                                 long *value)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	long value__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetColWidth_ (__vtblIFacePtr, aCol,
	                                                  &value__Temp));

	if (value)
		{
		*value = value__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXGetRowHeight (CAObjHandle objectHandle,
                                                  ERRORINFO *errorInfo,
                                                  long aRow, long *value)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	long value__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetRowHeight_ (__vtblIFacePtr, aRow,
	                                                   &value__Temp));

	if (value)
		{
		*value = value__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXSetCellReadOnly (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     long aCol, long aRow,
                                                     VBOOL aReadOnly)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetCellReadOnly_ (__vtblIFacePtr, aCol,
	                                                      aRow, aReadOnly));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXGetCellReadOnly (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     long aCol, long aRow,
                                                     VBOOL *value)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	VBOOL value__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetCellReadOnly_ (__vtblIFacePtr, aCol,
	                                                      aRow, &value__Temp));

	if (value)
		{
		*value = value__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXClearChartSeries (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      const char *aChartName)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	BSTR aChartName__AutoType = 0;

	__caErrChk (CA_CStringToBSTR (aChartName, &aChartName__AutoType));

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->ClearChartSeries_ (__vtblIFacePtr,
	                                                       aChartName__AutoType));

Error:
	CA_FreeBSTR (aChartName__AutoType);
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXSetCellAlias (CAObjHandle objectHandle,
                                                  ERRORINFO *errorInfo,
                                                  long aCol, long aRow,
                                                  const char *aAlias)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	BSTR aAlias__AutoType = 0;

	__caErrChk (CA_CStringToBSTR (aAlias, &aAlias__AutoType));

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetCellAlias_ (__vtblIFacePtr, aCol,
	                                                   aRow, aAlias__AutoType));

Error:
	CA_FreeBSTR (aAlias__AutoType);
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXGetCellAlias (CAObjHandle objectHandle,
                                                  ERRORINFO *errorInfo,
                                                  long aCol, long aRow,
                                                  char **value)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	BSTR value__AutoType = 0;

	if (value)
		*value = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetCellAlias_ (__vtblIFacePtr, aCol,
	                                                   aRow, &value__AutoType));

	if (value)
		__caErrChk (CA_BSTRGetCString (value__AutoType, value));

Error:
	CA_FreeBSTR (value__AutoType);
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	if (FAILED(__result))
		{
		if (value)
			{
			CA_FreeMemory (*value);
			*value = 0;
			}
		}
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXSetCellValue (CAObjHandle objectHandle,
                                                  ERRORINFO *errorInfo,
                                                  long aCol, long aRow,
                                                  const char *aValue)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	BSTR aValue__AutoType = 0;

	__caErrChk (CA_CStringToBSTR (aValue, &aValue__AutoType));

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetCellValue_ (__vtblIFacePtr, aCol,
	                                                   aRow, aValue__AutoType));

Error:
	CA_FreeBSTR (aValue__AutoType);
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXGetCellValue (CAObjHandle objectHandle,
                                                  ERRORINFO *errorInfo,
                                                  long aCol, long aRow,
                                                  char **value)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	BSTR value__AutoType = 0;

	if (value)
		*value = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetCellValue_ (__vtblIFacePtr, aCol,
	                                                   aRow, &value__AutoType));

	if (value)
		__caErrChk (CA_BSTRGetCString (value__AutoType, value));

Error:
	CA_FreeBSTR (value__AutoType);
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	if (FAILED(__result))
		{
		if (value)
			{
			CA_FreeMemory (*value);
			*value = 0;
			}
		}
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXGetPoleWidth (CAObjHandle objectHandle,
                                                  ERRORINFO *errorInfo,
                                                  long *value)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	long value__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetPoleWidth_ (__vtblIFacePtr,
	                                                   &value__Temp));

	if (value)
		{
		*value = value__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXSetPoleWidth (CAObjHandle objectHandle,
                                                  ERRORINFO *errorInfo,
                                                  long value)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetPoleWidth_ (__vtblIFacePtr, value));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXGetPoleHeight (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   long *value)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	long value__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetPoleHeight_ (__vtblIFacePtr,
	                                                    &value__Temp));

	if (value)
		{
		*value = value__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXSetPoleHeight (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   long value)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetPoleHeight_ (__vtblIFacePtr, value));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXGetColCount (CAObjHandle objectHandle,
                                                 ERRORINFO *errorInfo,
                                                 long *value)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	long value__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetColCount_ (__vtblIFacePtr,
	                                                  &value__Temp));

	if (value)
		{
		*value = value__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXSetColCount (CAObjHandle objectHandle,
                                                 ERRORINFO *errorInfo,
                                                 long value)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetColCount_ (__vtblIFacePtr, value));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXGetRowCount (CAObjHandle objectHandle,
                                                 ERRORINFO *errorInfo,
                                                 long *value)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	long value__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetRowCount_ (__vtblIFacePtr,
	                                                  &value__Temp));

	if (value)
		{
		*value = value__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXSetRowCount (CAObjHandle objectHandle,
                                                 ERRORINFO *errorInfo,
                                                 long value)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetRowCount_ (__vtblIFacePtr, value));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXGetLeftCol (CAObjHandle objectHandle,
                                                ERRORINFO *errorInfo,
                                                long *value)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	long value__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetLeftCol_ (__vtblIFacePtr,
	                                                 &value__Temp));

	if (value)
		{
		*value = value__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXSetLeftCol (CAObjHandle objectHandle,
                                                ERRORINFO *errorInfo, long value)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetLeftCol_ (__vtblIFacePtr, value));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXGetTopRow (CAObjHandle objectHandle,
                                               ERRORINFO *errorInfo, long *value)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	long value__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetTopRow_ (__vtblIFacePtr,
	                                                &value__Temp));

	if (value)
		{
		*value = value__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXSetTopRow (CAObjHandle objectHandle,
                                               ERRORINFO *errorInfo, long value)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetTopRow_ (__vtblIFacePtr, value));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXPrintSheet (CAObjHandle objectHandle,
                                                ERRORINFO *errorInfo,
                                                VBOOL aDialog)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->PrintSheet_ (__vtblIFacePtr, aDialog));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXPrintSetup (CAObjHandle objectHandle,
                                                ERRORINFO *errorInfo)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->PrintSetup_ (__vtblIFacePtr));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXImportXML (CAObjHandle objectHandle,
                                               ERRORINFO *errorInfo,
                                               const char *aXML)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	BSTR aXML__AutoType = 0;

	__caErrChk (CA_CStringToBSTR (aXML, &aXML__AutoType));

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->ImportXML_ (__vtblIFacePtr,
	                                                aXML__AutoType));

Error:
	CA_FreeBSTR (aXML__AutoType);
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXExportXML (CAObjHandle objectHandle,
                                               ERRORINFO *errorInfo, long aType,
                                               const char *aEncoding,
                                               char **value)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	BSTR aEncoding__AutoType = 0;
	BSTR value__AutoType = 0;

	if (value)
		*value = 0;

	__caErrChk (CA_CStringToBSTR (aEncoding, &aEncoding__AutoType));

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->ExportXML_ (__vtblIFacePtr, aType,
	                                                aEncoding__AutoType,
	                                                &value__AutoType));

	if (value)
		__caErrChk (CA_BSTRGetCString (value__AutoType, value));

Error:
	CA_FreeBSTR (aEncoding__AutoType);
	CA_FreeBSTR (value__AutoType);
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	if (FAILED(__result))
		{
		if (value)
			{
			CA_FreeMemory (*value);
			*value = 0;
			}
		}
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXInvalidatePaint (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->InvalidatePaint_ (__vtblIFacePtr));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXValidatePaint (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->ValidatePaint_ (__vtblIFacePtr));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXGetPainted (CAObjHandle objectHandle,
                                                ERRORINFO *errorInfo,
                                                VBOOL *value)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	VBOOL value__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetPainted_ (__vtblIFacePtr,
	                                                 &value__Temp));

	if (value)
		{
		*value = value__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXSetPainted (CAObjHandle objectHandle,
                                                ERRORINFO *errorInfo,
                                                VBOOL value)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetPainted_ (__vtblIFacePtr, value));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXSetCellExpression (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       long aCol, long aRow,
                                                       const char *aExpression)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	BSTR aExpression__AutoType = 0;

	__caErrChk (CA_CStringToBSTR (aExpression, &aExpression__AutoType));

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetCellExpression_ (__vtblIFacePtr,
	                                                        aCol, aRow,
	                                                        aExpression__AutoType));

Error:
	CA_FreeBSTR (aExpression__AutoType);
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXGetCellExpression (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       long aCol, long aRow,
                                                       char **value)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	BSTR value__AutoType = 0;

	if (value)
		*value = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetCellExpression_ (__vtblIFacePtr,
	                                                        aCol, aRow,
	                                                        &value__AutoType));

	if (value)
		__caErrChk (CA_BSTRGetCString (value__AutoType, value));

Error:
	CA_FreeBSTR (value__AutoType);
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	if (FAILED(__result))
		{
		if (value)
			{
			CA_FreeMemory (*value);
			*value = 0;
			}
		}
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXExplainCellExpression (CAObjHandle objectHandle,
                                                           ERRORINFO *errorInfo,
                                                           long aCol, long aRow)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->ExplainCellExpression_ (__vtblIFacePtr,
	                                                            aCol, aRow));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXExplainAllExpresion (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo,
                                                         long aOrder)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->ExplainAllExpresion_ (__vtblIFacePtr,
	                                                          aOrder));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXExportExcel (CAObjHandle objectHandle,
                                                 ERRORINFO *errorInfo,
                                                 const char *aFileName,
                                                 const char *aSheetName,
                                                 VBOOL aDisplayValue)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	BSTR aFileName__AutoType = 0;
	BSTR aSheetName__AutoType = 0;

	__caErrChk (CA_CStringToBSTR (aFileName, &aFileName__AutoType));
	__caErrChk (CA_CStringToBSTR (aSheetName, &aSheetName__AutoType));

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->ExportExcel_ (__vtblIFacePtr,
	                                                  aFileName__AutoType,
	                                                  aSheetName__AutoType,
	                                                  aDisplayValue));

Error:
	CA_FreeBSTR (aFileName__AutoType);
	CA_FreeBSTR (aSheetName__AutoType);
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXExportExcelOle (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    const char *aFileName,
                                                    long aCol1, long aRow1,
                                                    long aCol2, long aRow2,
                                                    const char *aSheetName,
                                                    VBOOL aOleText)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	BSTR aFileName__AutoType = 0;
	BSTR aSheetName__AutoType = 0;

	__caErrChk (CA_CStringToBSTR (aFileName, &aFileName__AutoType));
	__caErrChk (CA_CStringToBSTR (aSheetName, &aSheetName__AutoType));

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->ExportExcelOle_ (__vtblIFacePtr,
	                                                     aFileName__AutoType,
	                                                     aCol1, aRow1, aCol2,
	                                                     aRow2,
	                                                     aSheetName__AutoType,
	                                                     aOleText));

Error:
	CA_FreeBSTR (aFileName__AutoType);
	CA_FreeBSTR (aSheetName__AutoType);
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXImportExcelOle (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    const char *aFileName,
                                                    long aCol1, long aRow1,
                                                    long aCol2, long aRow2,
                                                    VBOOL aOleText)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	BSTR aFileName__AutoType = 0;

	__caErrChk (CA_CStringToBSTR (aFileName, &aFileName__AutoType));

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->ImportExcelOle_ (__vtblIFacePtr,
	                                                     aFileName__AutoType,
	                                                     aCol1, aRow1, aCol2,
	                                                     aRow2, aOleText));

Error:
	CA_FreeBSTR (aFileName__AutoType);
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXSetCellScript (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   long aCol, long aRow,
                                                   long aScriptType,
                                                   const char *aScriptText)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	BSTR aScriptText__AutoType = 0;

	__caErrChk (CA_CStringToBSTR (aScriptText, &aScriptText__AutoType));

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetCellScript_ (__vtblIFacePtr, aCol,
	                                                    aRow, aScriptType,
	                                                    aScriptText__AutoType));

Error:
	CA_FreeBSTR (aScriptText__AutoType);
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXGetCellScript (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   long aCol, long aRow,
                                                   long *scriptType,
                                                   char **scriptText)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	long scriptType__Temp;
	BSTR scriptText__AutoType = 0;

	if (scriptText)
		*scriptText = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetCellScript_ (__vtblIFacePtr, aCol,
	                                                    aRow,
	                                                    &scriptType__Temp,
	                                                    &scriptText__AutoType));

	if (scriptType)
		{
		*scriptType = scriptType__Temp;
		}
	if (scriptText)
		__caErrChk (CA_BSTRGetCString (scriptText__AutoType, scriptText));

Error:
	CA_FreeBSTR (scriptText__AutoType);
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	if (FAILED(__result))
		{
		if (scriptText)
			{
			CA_FreeMemory (*scriptText);
			*scriptText = 0;
			}
		}
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXDelCellPicture (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    long aCol, long aRow)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->DelCellPicture_ (__vtblIFacePtr, aCol,
	                                                     aRow));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXTranspose (CAObjHandle objectHandle,
                                               ERRORINFO *errorInfo, long aCol1,
                                               long aRow1, long aCol2,
                                               long aRow2)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->Transpose_ (__vtblIFacePtr, aCol1,
	                                                aRow1, aCol2, aRow2));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXEditCellScript (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    long aCol, long aRow)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->EditCellScript_ (__vtblIFacePtr, aCol,
	                                                     aRow));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXExportHtml (CAObjHandle objectHandle,
                                                ERRORINFO *errorInfo,
                                                const char *aPicturePath,
                                                VBOOL aExportObject,
                                                char **value)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	BSTR aPicturePath__AutoType = 0;
	BSTR value__AutoType = 0;

	if (value)
		*value = 0;

	__caErrChk (CA_CStringToBSTR (aPicturePath, &aPicturePath__AutoType));

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->ExportHtml_ (__vtblIFacePtr,
	                                                 aPicturePath__AutoType,
	                                                 aExportObject,
	                                                 &value__AutoType));

	if (value)
		__caErrChk (CA_BSTRGetCString (value__AutoType, value));

Error:
	CA_FreeBSTR (aPicturePath__AutoType);
	CA_FreeBSTR (value__AutoType);
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	if (FAILED(__result))
		{
		if (value)
			{
			CA_FreeMemory (*value);
			*value = 0;
			}
		}
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXExportPdf (CAObjHandle objectHandle,
                                               ERRORINFO *errorInfo,
                                               const char *aFileName)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	BSTR aFileName__AutoType = 0;

	__caErrChk (CA_CStringToBSTR (aFileName, &aFileName__AutoType));

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->ExportPdf_ (__vtblIFacePtr,
	                                                aFileName__AutoType));

Error:
	CA_FreeBSTR (aFileName__AutoType);
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXExportText (CAObjHandle objectHandle,
                                                ERRORINFO *errorInfo, long aCol1,
                                                long aRow1, long aCol2,
                                                long aRow2,
                                                const char *aSeparator,
                                                char **value)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	BSTR aSeparator__AutoType = 0;
	BSTR value__AutoType = 0;

	if (value)
		*value = 0;

	__caErrChk (CA_CStringToBSTR (aSeparator, &aSeparator__AutoType));

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->ExportText_ (__vtblIFacePtr, aCol1,
	                                                 aRow1, aCol2, aRow2,
	                                                 aSeparator__AutoType,
	                                                 &value__AutoType));

	if (value)
		__caErrChk (CA_BSTRGetCString (value__AutoType, value));

Error:
	CA_FreeBSTR (aSeparator__AutoType);
	CA_FreeBSTR (value__AutoType);
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	if (FAILED(__result))
		{
		if (value)
			{
			CA_FreeMemory (*value);
			*value = 0;
			}
		}
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXImportText (CAObjHandle objectHandle,
                                                ERRORINFO *errorInfo, long aCol,
                                                long aRow, const char *aText,
                                                const char *aSeparator)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	BSTR aText__AutoType = 0;
	BSTR aSeparator__AutoType = 0;

	__caErrChk (CA_CStringToBSTR (aText, &aText__AutoType));
	__caErrChk (CA_CStringToBSTR (aSeparator, &aSeparator__AutoType));

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->ImportText_ (__vtblIFacePtr, aCol,
	                                                 aRow, aText__AutoType,
	                                                 aSeparator__AutoType));

Error:
	CA_FreeBSTR (aText__AutoType);
	CA_FreeBSTR (aSeparator__AutoType);
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXNewReport (CAObjHandle objectHandle,
                                               ERRORINFO *errorInfo,
                                               long aColCount, long aRowCount)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->NewReport_ (__vtblIFacePtr, aColCount,
	                                                aRowCount));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXSetSelectCell (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   long aCol1, long aRow1,
                                                   long aCol2, long aRow2)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetSelectCell_ (__vtblIFacePtr, aCol1,
	                                                    aRow1, aCol2, aRow2));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXGetSelectCell (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   long *col1, long *row1,
                                                   long *col2, long *row2)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	long col1__Temp;
	long row1__Temp;
	long col2__Temp;
	long row2__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetSelectCell_ (__vtblIFacePtr,
	                                                    &col1__Temp,
	                                                    &row1__Temp,
	                                                    &col2__Temp,
	                                                    &row2__Temp));

	if (col1)
		{
		*col1 = col1__Temp;
		}
	if (row1)
		{
		*row1 = row1__Temp;
		}
	if (col2)
		{
		*col2 = col2__Temp;
		}
	if (row2)
		{
		*row2 = row2__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXGetInputCell (CAObjHandle objectHandle,
                                                  ERRORINFO *errorInfo,
                                                  long *col, long *row)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	long col__Temp;
	long row__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetInputCell_ (__vtblIFacePtr,
	                                                   &col__Temp, &row__Temp));

	if (col)
		{
		*col = col__Temp;
		}
	if (row)
		{
		*row = row__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXCutObject (CAObjHandle objectHandle,
                                               ERRORINFO *errorInfo,
                                               const char *aObjectName)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	BSTR aObjectName__AutoType = 0;

	__caErrChk (CA_CStringToBSTR (aObjectName, &aObjectName__AutoType));

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->CutObject_ (__vtblIFacePtr,
	                                                aObjectName__AutoType));

Error:
	CA_FreeBSTR (aObjectName__AutoType);
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXCopyObject (CAObjHandle objectHandle,
                                                ERRORINFO *errorInfo,
                                                const char *aObjectName)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	BSTR aObjectName__AutoType = 0;

	__caErrChk (CA_CStringToBSTR (aObjectName, &aObjectName__AutoType));

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->CopyObject_ (__vtblIFacePtr,
	                                                 aObjectName__AutoType));

Error:
	CA_FreeBSTR (aObjectName__AutoType);
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXSetColPageBreak (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     long aCol, VBOOL aPageBreak)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetColPageBreak_ (__vtblIFacePtr, aCol,
	                                                      aPageBreak));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXSetRowPageBreak (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     long aRow, VBOOL aPageBreak)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetRowPageBreak_ (__vtblIFacePtr, aRow,
	                                                      aPageBreak));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXSaveString (CAObjHandle objectHandle,
                                                ERRORINFO *errorInfo,
                                                VBOOL aCompression, char **value)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	BSTR value__AutoType = 0;

	if (value)
		*value = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SaveString_ (__vtblIFacePtr,
	                                                 aCompression,
	                                                 &value__AutoType));

	if (value)
		__caErrChk (CA_BSTRGetCString (value__AutoType, value));

Error:
	CA_FreeBSTR (value__AutoType);
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	if (FAILED(__result))
		{
		if (value)
			{
			CA_FreeMemory (*value);
			*value = 0;
			}
		}
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXOpenString (CAObjHandle objectHandle,
                                                ERRORINFO *errorInfo,
                                                const char *aReport,
                                                VBOOL aCompression)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	BSTR aReport__AutoType = 0;

	__caErrChk (CA_CStringToBSTR (aReport, &aReport__AutoType));

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->OpenString_ (__vtblIFacePtr,
	                                                 aReport__AutoType,
	                                                 aCompression));

Error:
	CA_FreeBSTR (aReport__AutoType);
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXGetEnterTo (CAObjHandle objectHandle,
                                                ERRORINFO *errorInfo,
                                                long *value)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	long value__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetEnterTo_ (__vtblIFacePtr,
	                                                 &value__Temp));

	if (value)
		{
		*value = value__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXSetEnterTo (CAObjHandle objectHandle,
                                                ERRORINFO *errorInfo, long value)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetEnterTo_ (__vtblIFacePtr, value));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXGetMoveChart (CAObjHandle objectHandle,
                                                  ERRORINFO *errorInfo,
                                                  VBOOL *value)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	VBOOL value__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetMoveChart_ (__vtblIFacePtr,
	                                                   &value__Temp));

	if (value)
		{
		*value = value__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXSetMoveChart (CAObjHandle objectHandle,
                                                  ERRORINFO *errorInfo,
                                                  VBOOL value)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetMoveChart_ (__vtblIFacePtr, value));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXGetUpdateChart (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    VBOOL *value)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	VBOOL value__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetUpdateChart_ (__vtblIFacePtr,
	                                                     &value__Temp));

	if (value)
		{
		*value = value__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXSetUpdateChart (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    VBOOL value)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetUpdateChart_ (__vtblIFacePtr, value));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXGetExpandCell (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   long *col1, long *row1,
                                                   long *col2, long *row2)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetExpandCell_ (__vtblIFacePtr, col1,
	                                                    row1, col2, row2));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXGetChartRange (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   const char *aChartName,
                                                   long *chartWidth,
                                                   long *chartHeight)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	BSTR aChartName__AutoType = 0;
	long chartWidth__Temp;
	long chartHeight__Temp;

	__caErrChk (CA_CStringToBSTR (aChartName, &aChartName__AutoType));

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetChartRange_ (__vtblIFacePtr,
	                                                    aChartName__AutoType,
	                                                    &chartWidth__Temp,
	                                                    &chartHeight__Temp));

	if (chartWidth)
		{
		*chartWidth = chartWidth__Temp;
		}
	if (chartHeight)
		{
		*chartHeight = chartHeight__Temp;
		}

Error:
	CA_FreeBSTR (aChartName__AutoType);
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXGetCellCoordinate (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       const char *aAlias,
                                                       long *col, long *row)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	BSTR aAlias__AutoType = 0;
	long col__Temp;
	long row__Temp;

	__caErrChk (CA_CStringToBSTR (aAlias, &aAlias__AutoType));

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetCellCoordinate_ (__vtblIFacePtr,
	                                                        aAlias__AutoType,
	                                                        &col__Temp,
	                                                        &row__Temp));

	if (col)
		{
		*col = col__Temp;
		}
	if (row)
		{
		*row = row__Temp;
		}

Error:
	CA_FreeBSTR (aAlias__AutoType);
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXSetCellPrintHide (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      long aCol, long aRow,
                                                      VBOOL aPrintHide)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetCellPrintHide_ (__vtblIFacePtr,
	                                                       aCol, aRow,
	                                                       aPrintHide));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXGetCellPrintHide (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      long aCol, long aRow,
                                                      VBOOL *value)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	VBOOL value__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetCellPrintHide_ (__vtblIFacePtr,
	                                                       aCol, aRow,
	                                                       &value__Temp));

	if (value)
		{
		*value = value__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXSetCellNextPos (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    long aCol, long aRow,
                                                    long aNextCol, long aNextRow)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetCellNextPos_ (__vtblIFacePtr, aCol,
	                                                     aRow, aNextCol,
	                                                     aNextRow));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXGetCellNextPos (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    long aCol, long aRow,
                                                    long *nextCol, long *nextRow)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	long nextCol__Temp;
	long nextRow__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetCellNextPos_ (__vtblIFacePtr, aCol,
	                                                     aRow, &nextCol__Temp,
	                                                     &nextRow__Temp));

	if (nextCol)
		{
		*nextCol = nextCol__Temp;
		}
	if (nextRow)
		{
		*nextRow = nextRow__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXFind (CAObjHandle objectHandle,
                                          ERRORINFO *errorInfo, long aCol1,
                                          long aRow1, long aCol2, long aRow2,
                                          VBOOL aColOrRow, VBOOL aUpOrDown,
                                          VBOOL aCaseSensitive,
                                          VBOOL aWholeWords,
                                          const char *aFindString, VBOOL *value)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	BSTR aFindString__AutoType = 0;
	VBOOL value__Temp;

	__caErrChk (CA_CStringToBSTR (aFindString, &aFindString__AutoType));

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->Find_ (__vtblIFacePtr, aCol1, aRow1,
	                                           aCol2, aRow2, aColOrRow,
	                                           aUpOrDown, aCaseSensitive,
	                                           aWholeWords,
	                                           aFindString__AutoType,
	                                           &value__Temp));

	if (value)
		{
		*value = value__Temp;
		}

Error:
	CA_FreeBSTR (aFindString__AutoType);
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXReplace (CAObjHandle objectHandle,
                                             ERRORINFO *errorInfo, long aCol1,
                                             long aRow1, long aCol2, long aRow2,
                                             VBOOL aCaseSensitive,
                                             VBOOL aWholeWords,
                                             const char *aFindString,
                                             const char *aReplaceString)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	BSTR aFindString__AutoType = 0;
	BSTR aReplaceString__AutoType = 0;

	__caErrChk (CA_CStringToBSTR (aFindString, &aFindString__AutoType));
	__caErrChk (CA_CStringToBSTR (aReplaceString, &aReplaceString__AutoType));

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->Replace_ (__vtblIFacePtr, aCol1, aRow1,
	                                              aCol2, aRow2, aCaseSensitive,
	                                              aWholeWords,
	                                              aFindString__AutoType,
	                                              aReplaceString__AutoType));

Error:
	CA_FreeBSTR (aFindString__AutoType);
	CA_FreeBSTR (aReplaceString__AutoType);
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXSortCol (CAObjHandle objectHandle,
                                             ERRORINFO *errorInfo, long aCol,
                                             long aCol1, long aRow1, long aCol2,
                                             long aRow2, VBOOL aAscending)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SortCol_ (__vtblIFacePtr, aCol, aCol1,
	                                              aRow1, aCol2, aRow2,
	                                              aAscending));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXSortRow (CAObjHandle objectHandle,
                                             ERRORINFO *errorInfo, long aRow,
                                             long aCol1, long aRow1, long aCol2,
                                             long aRow2, VBOOL aAscending)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SortRow_ (__vtblIFacePtr, aRow, aCol1,
	                                              aRow1, aCol2, aRow2,
	                                              aAscending));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXSetChartRange (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   const char *aChartName,
                                                   long aChartWidth,
                                                   long aChartHeight)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	BSTR aChartName__AutoType = 0;

	__caErrChk (CA_CStringToBSTR (aChartName, &aChartName__AutoType));

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetChartRange_ (__vtblIFacePtr,
	                                                    aChartName__AutoType,
	                                                    aChartWidth,
	                                                    aChartHeight));

Error:
	CA_FreeBSTR (aChartName__AutoType);
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXGetCellType (CAObjHandle objectHandle,
                                                 ERRORINFO *errorInfo, long aCol,
                                                 long aRow, long *value)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	long value__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetCellType_ (__vtblIFacePtr, aCol,
	                                                  aRow, &value__Temp));

	if (value)
		{
		*value = value__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXSetSelectObjectChart (CAObjHandle objectHandle,
                                                          ERRORINFO *errorInfo,
                                                          const char *aChartName)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	BSTR aChartName__AutoType = 0;

	__caErrChk (CA_CStringToBSTR (aChartName, &aChartName__AutoType));

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetSelectObjectChart_ (__vtblIFacePtr,
	                                                           aChartName__AutoType));

Error:
	CA_FreeBSTR (aChartName__AutoType);
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXGetSelectChartName (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        char **value)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	BSTR value__AutoType = 0;

	if (value)
		*value = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetSelectChartName_ (__vtblIFacePtr,
	                                                         &value__AutoType));

	if (value)
		__caErrChk (CA_BSTRGetCString (value__AutoType, value));

Error:
	CA_FreeBSTR (value__AutoType);
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	if (FAILED(__result))
		{
		if (value)
			{
			CA_FreeMemory (*value);
			*value = 0;
			}
		}
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXGetPrinterIndex (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     long *value)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	long value__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetPrinterIndex_ (__vtblIFacePtr,
	                                                      &value__Temp));

	if (value)
		{
		*value = value__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXSetPrinterIndex (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     long value)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetPrinterIndex_ (__vtblIFacePtr,
	                                                      value));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXGetPaperSize (CAObjHandle objectHandle,
                                                  ERRORINFO *errorInfo,
                                                  long *value)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	long value__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetPaperSize_ (__vtblIFacePtr,
	                                                   &value__Temp));

	if (value)
		{
		*value = value__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXSetPaperSize (CAObjHandle objectHandle,
                                                  ERRORINFO *errorInfo,
                                                  long value)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetPaperSize_ (__vtblIFacePtr, value));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXGetPageWidth (CAObjHandle objectHandle,
                                                  ERRORINFO *errorInfo,
                                                  long *value)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	long value__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetPageWidth_ (__vtblIFacePtr,
	                                                   &value__Temp));

	if (value)
		{
		*value = value__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXSetPageWidth (CAObjHandle objectHandle,
                                                  ERRORINFO *errorInfo,
                                                  long value)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetPageWidth_ (__vtblIFacePtr, value));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXGetPageHeight (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   long *value)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	long value__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetPageHeight_ (__vtblIFacePtr,
	                                                    &value__Temp));

	if (value)
		{
		*value = value__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXSetPageHeight (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   long value)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetPageHeight_ (__vtblIFacePtr, value));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXGetPrintOrientation (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo,
                                                         VBOOL *value)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	VBOOL value__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetPrintOrientation_ (__vtblIFacePtr,
	                                                          &value__Temp));

	if (value)
		{
		*value = value__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXSetPrintOrientation (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo,
                                                         VBOOL value)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetPrintOrientation_ (__vtblIFacePtr,
	                                                          value));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXGetPrintCopies (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    long *value)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	long value__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetPrintCopies_ (__vtblIFacePtr,
	                                                     &value__Temp));

	if (value)
		{
		*value = value__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXSetPrintCopies (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    long value)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetPrintCopies_ (__vtblIFacePtr, value));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXGetLeftMargin (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   long *value)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	long value__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetLeftMargin_ (__vtblIFacePtr,
	                                                    &value__Temp));

	if (value)
		{
		*value = value__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXSetLeftMargin (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   long value)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetLeftMargin_ (__vtblIFacePtr, value));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXGetTopMargin (CAObjHandle objectHandle,
                                                  ERRORINFO *errorInfo,
                                                  long *value)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	long value__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetTopMargin_ (__vtblIFacePtr,
	                                                   &value__Temp));

	if (value)
		{
		*value = value__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXSetTopMargin (CAObjHandle objectHandle,
                                                  ERRORINFO *errorInfo,
                                                  long value)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetTopMargin_ (__vtblIFacePtr, value));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXGetRightMargin (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    long *value)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	long value__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetRightMargin_ (__vtblIFacePtr,
	                                                     &value__Temp));

	if (value)
		{
		*value = value__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXSetRightMargin (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    long value)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetRightMargin_ (__vtblIFacePtr, value));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXGetBottomMargin (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     long *value)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	long value__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetBottomMargin_ (__vtblIFacePtr,
	                                                      &value__Temp));

	if (value)
		{
		*value = value__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXSetBottomMargin (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     long value)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetBottomMargin_ (__vtblIFacePtr,
	                                                      value));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXGetHeaderMargin (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     long *value)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	long value__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetHeaderMargin_ (__vtblIFacePtr,
	                                                      &value__Temp));

	if (value)
		{
		*value = value__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXSetHeaderMargin (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     long value)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetHeaderMargin_ (__vtblIFacePtr,
	                                                      value));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXGetFooterMargin (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     long *value)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	long value__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetFooterMargin_ (__vtblIFacePtr,
	                                                      &value__Temp));

	if (value)
		{
		*value = value__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXSetFooterMargin (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     long value)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetFooterMargin_ (__vtblIFacePtr,
	                                                      value));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXGetPrintBorders (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     VBOOL *value)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	VBOOL value__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetPrintBorders_ (__vtblIFacePtr,
	                                                      &value__Temp));

	if (value)
		{
		*value = value__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXSetPrintBorders (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     VBOOL value)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetPrintBorders_ (__vtblIFacePtr,
	                                                      value));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXGetPrintBackColor (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       VBOOL *value)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	VBOOL value__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetPrintBackColor_ (__vtblIFacePtr,
	                                                        &value__Temp));

	if (value)
		{
		*value = value__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXSetPrintBackColor (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       VBOOL value)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetPrintBackColor_ (__vtblIFacePtr,
	                                                        value));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXGetPageFontName (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     char **value)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	BSTR value__AutoType = 0;

	if (value)
		*value = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetPageFontName_ (__vtblIFacePtr,
	                                                      &value__AutoType));

	if (value)
		__caErrChk (CA_BSTRGetCString (value__AutoType, value));

Error:
	CA_FreeBSTR (value__AutoType);
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	if (FAILED(__result))
		{
		if (value)
			{
			CA_FreeMemory (*value);
			*value = 0;
			}
		}
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXSetPageFontName (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     const char *value)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	BSTR value__AutoType = 0;

	__caErrChk (CA_CStringToBSTR (value, &value__AutoType));

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetPageFontName_ (__vtblIFacePtr,
	                                                      value__AutoType));

Error:
	CA_FreeBSTR (value__AutoType);
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXGetPageFontSize (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     long *value)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	long value__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetPageFontSize_ (__vtblIFacePtr,
	                                                      &value__Temp));

	if (value)
		{
		*value = value__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXSetPageFontSize (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     long value)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetPageFontSize_ (__vtblIFacePtr,
	                                                      value));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXGetPageHeaderLeftText (CAObjHandle objectHandle,
                                                           ERRORINFO *errorInfo,
                                                           char **value)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	BSTR value__AutoType = 0;

	if (value)
		*value = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetPageHeaderLeftText_ (__vtblIFacePtr,
	                                                            &value__AutoType));

	if (value)
		__caErrChk (CA_BSTRGetCString (value__AutoType, value));

Error:
	CA_FreeBSTR (value__AutoType);
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	if (FAILED(__result))
		{
		if (value)
			{
			CA_FreeMemory (*value);
			*value = 0;
			}
		}
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXSetPageHeaderLeftText (CAObjHandle objectHandle,
                                                           ERRORINFO *errorInfo,
                                                           const char *value)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	BSTR value__AutoType = 0;

	__caErrChk (CA_CStringToBSTR (value, &value__AutoType));

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetPageHeaderLeftText_ (__vtblIFacePtr,
	                                                            value__AutoType));

Error:
	CA_FreeBSTR (value__AutoType);
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXGetPageFooterLeftText (CAObjHandle objectHandle,
                                                           ERRORINFO *errorInfo,
                                                           char **value)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	BSTR value__AutoType = 0;

	if (value)
		*value = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetPageFooterLeftText_ (__vtblIFacePtr,
	                                                            &value__AutoType));

	if (value)
		__caErrChk (CA_BSTRGetCString (value__AutoType, value));

Error:
	CA_FreeBSTR (value__AutoType);
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	if (FAILED(__result))
		{
		if (value)
			{
			CA_FreeMemory (*value);
			*value = 0;
			}
		}
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXSetPageFooterLeftText (CAObjHandle objectHandle,
                                                           ERRORINFO *errorInfo,
                                                           const char *value)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	BSTR value__AutoType = 0;

	__caErrChk (CA_CStringToBSTR (value, &value__AutoType));

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetPageFooterLeftText_ (__vtblIFacePtr,
	                                                            value__AutoType));

Error:
	CA_FreeBSTR (value__AutoType);
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXGetLeftColCount (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     long *value)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	long value__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetLeftColCount_ (__vtblIFacePtr,
	                                                      &value__Temp));

	if (value)
		{
		*value = value__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXSetLeftColCount (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     long value)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetLeftColCount_ (__vtblIFacePtr,
	                                                      value));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXGetTopRowCount (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    long *value)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	long value__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetTopRowCount_ (__vtblIFacePtr,
	                                                     &value__Temp));

	if (value)
		{
		*value = value__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXSetTopRowCount (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    long value)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetTopRowCount_ (__vtblIFacePtr, value));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXGetRightColCount (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      long *value)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	long value__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetRightColCount_ (__vtblIFacePtr,
	                                                       &value__Temp));

	if (value)
		{
		*value = value__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXSetRightColCount (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      long value)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetRightColCount_ (__vtblIFacePtr,
	                                                       value));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXGetBottomRowCount (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       long *value)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	long value__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetBottomRowCount_ (__vtblIFacePtr,
	                                                        &value__Temp));

	if (value)
		{
		*value = value__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXSetBottomRowCount (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       long value)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetBottomRowCount_ (__vtblIFacePtr,
	                                                        value));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXGetPrintZoom (CAObjHandle objectHandle,
                                                  ERRORINFO *errorInfo,
                                                  long *value)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	long value__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetPrintZoom_ (__vtblIFacePtr,
	                                                   &value__Temp));

	if (value)
		{
		*value = value__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXSetPrintZoom (CAObjHandle objectHandle,
                                                  ERRORINFO *errorInfo,
                                                  long value)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetPrintZoom_ (__vtblIFacePtr, value));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXGetPrintArea (CAObjHandle objectHandle,
                                                  ERRORINFO *errorInfo,
                                                  char **value)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	BSTR value__AutoType = 0;

	if (value)
		*value = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetPrintArea_ (__vtblIFacePtr,
	                                                   &value__AutoType));

	if (value)
		__caErrChk (CA_BSTRGetCString (value__AutoType, value));

Error:
	CA_FreeBSTR (value__AutoType);
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	if (FAILED(__result))
		{
		if (value)
			{
			CA_FreeMemory (*value);
			*value = 0;
			}
		}
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXSetPrintArea (CAObjHandle objectHandle,
                                                  ERRORINFO *errorInfo,
                                                  const char *value)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	BSTR value__AutoType = 0;

	__caErrChk (CA_CStringToBSTR (value, &value__AutoType));

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetPrintArea_ (__vtblIFacePtr,
	                                                   value__AutoType));

Error:
	CA_FreeBSTR (value__AutoType);
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXGetPrintOrder (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   VBOOL *value)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	VBOOL value__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetPrintOrder_ (__vtblIFacePtr,
	                                                    &value__Temp));

	if (value)
		{
		*value = value__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXSetPrintOrder (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   VBOOL value)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetPrintOrder_ (__vtblIFacePtr, value));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXGetCellButtonText (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       long aCol, long aRow,
                                                       char **value)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	BSTR value__AutoType = 0;

	if (value)
		*value = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetCellButtonText_ (__vtblIFacePtr,
	                                                        aCol, aRow,
	                                                        &value__AutoType));

	if (value)
		__caErrChk (CA_BSTRGetCString (value__AutoType, value));

Error:
	CA_FreeBSTR (value__AutoType);
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	if (FAILED(__result))
		{
		if (value)
			{
			CA_FreeMemory (*value);
			*value = 0;
			}
		}
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXGetCellButtonScript (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo,
                                                         long aCol, long aRow,
                                                         char **value)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	BSTR value__AutoType = 0;

	if (value)
		*value = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetCellButtonScript_ (__vtblIFacePtr,
	                                                          aCol, aRow,
	                                                          &value__AutoType));

	if (value)
		__caErrChk (CA_BSTRGetCString (value__AutoType, value));

Error:
	CA_FreeBSTR (value__AutoType);
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	if (FAILED(__result))
		{
		if (value)
			{
			CA_FreeMemory (*value);
			*value = 0;
			}
		}
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXGetCellDropText (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     long aCol, long aRow,
                                                     char **value)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	BSTR value__AutoType = 0;

	if (value)
		*value = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetCellDropText_ (__vtblIFacePtr, aCol,
	                                                      aRow,
	                                                      &value__AutoType));

	if (value)
		__caErrChk (CA_BSTRGetCString (value__AutoType, value));

Error:
	CA_FreeBSTR (value__AutoType);
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	if (FAILED(__result))
		{
		if (value)
			{
			CA_FreeMemory (*value);
			*value = 0;
			}
		}
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXSetCellTextLength (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       long aCol, long aRow,
                                                       long aTextLength)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetCellTextLength_ (__vtblIFacePtr,
	                                                        aCol, aRow,
	                                                        aTextLength));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXGetCellTextLength (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       long aCol, long aRow,
                                                       long *value)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	long value__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetCellTextLength_ (__vtblIFacePtr,
	                                                        aCol, aRow,
	                                                        &value__Temp));

	if (value)
		{
		*value = value__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXSetCellCharCase (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     long aCol, long aRow,
                                                     long aCharCase)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetCellCharCase_ (__vtblIFacePtr, aCol,
	                                                      aRow, aCharCase));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXGetCellCharCase (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     long aCol, long aRow,
                                                     long *value)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	long value__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetCellCharCase_ (__vtblIFacePtr, aCol,
	                                                      aRow, &value__Temp));

	if (value)
		{
		*value = value__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXSetCellAppendDataLength (CAObjHandle objectHandle,
                                                             ERRORINFO *errorInfo,
                                                             long aCol,
                                                             long aRow,
                                                             long aNoteLength)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetCellAppendDataLength_ (__vtblIFacePtr,
	                                                              aCol, aRow,
	                                                              aNoteLength));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXGetCellAppendDataLength (CAObjHandle objectHandle,
                                                             ERRORINFO *errorInfo,
                                                             long aCol,
                                                             long aRow,
                                                             long *value)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	long value__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetCellAppendDataLength_ (__vtblIFacePtr,
	                                                              aCol, aRow,
	                                                              &value__Temp));

	if (value)
		{
		*value = value__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXSetCellAppendData (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       long aCol, long aRow,
                                                       long aIndex,
                                                       const char *aAppendData)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	BSTR aAppendData__AutoType = 0;

	__caErrChk (CA_CStringToBSTR (aAppendData, &aAppendData__AutoType));

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetCellAppendData_ (__vtblIFacePtr,
	                                                        aCol, aRow, aIndex,
	                                                        aAppendData__AutoType));

Error:
	CA_FreeBSTR (aAppendData__AutoType);
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXGetCellAppendData (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       long aCol, long aRow,
                                                       long aIndex, char **value)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	BSTR value__AutoType = 0;

	if (value)
		*value = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetCellAppendData_ (__vtblIFacePtr,
	                                                        aCol, aRow, aIndex,
	                                                        &value__AutoType));

	if (value)
		__caErrChk (CA_BSTRGetCString (value__AutoType, value));

Error:
	CA_FreeBSTR (value__AutoType);
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	if (FAILED(__result))
		{
		if (value)
			{
			CA_FreeMemory (*value);
			*value = 0;
			}
		}
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXFill (CAObjHandle objectHandle,
                                          ERRORINFO *errorInfo, long aCol1,
                                          long aRow1, long aCol2, long aRow2,
                                          long aDirection, long aFillType)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->Fill_ (__vtblIFacePtr, aCol1, aRow1,
	                                           aCol2, aRow2, aDirection,
	                                           aFillType));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXSetChartReadOnly (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      const char *aChartName,
                                                      VBOOL aReadOnly)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	BSTR aChartName__AutoType = 0;

	__caErrChk (CA_CStringToBSTR (aChartName, &aChartName__AutoType));

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetChartReadOnly_ (__vtblIFacePtr,
	                                                       aChartName__AutoType,
	                                                       aReadOnly));

Error:
	CA_FreeBSTR (aChartName__AutoType);
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXGetChartReadOnly (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      const char *aChartName,
                                                      VBOOL *value)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	BSTR aChartName__AutoType = 0;
	VBOOL value__Temp;

	__caErrChk (CA_CStringToBSTR (aChartName, &aChartName__AutoType));

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetChartReadOnly_ (__vtblIFacePtr,
	                                                       aChartName__AutoType,
	                                                       &value__Temp));

	if (value)
		{
		*value = value__Temp;
		}

Error:
	CA_FreeBSTR (aChartName__AutoType);
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXGetChartSeries (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    const char *aChartName,
                                                    long aIndex,
                                                    long *seriesType,
                                                    char **seriesSignText,
                                                    char **seriesDataText,
                                                    char **seriesCell)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	BSTR aChartName__AutoType = 0;
	long seriesType__Temp;
	BSTR seriesSignText__AutoType = 0;
	BSTR seriesDataText__AutoType = 0;
	BSTR seriesCell__AutoType = 0;

	if (seriesSignText)
		*seriesSignText = 0;
	if (seriesDataText)
		*seriesDataText = 0;
	if (seriesCell)
		*seriesCell = 0;

	__caErrChk (CA_CStringToBSTR (aChartName, &aChartName__AutoType));

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetChartSeries_ (__vtblIFacePtr,
	                                                     aChartName__AutoType,
	                                                     aIndex,
	                                                     &seriesType__Temp,
	                                                     &seriesSignText__AutoType,
	                                                     &seriesDataText__AutoType,
	                                                     &seriesCell__AutoType));

	if (seriesType)
		{
		*seriesType = seriesType__Temp;
		}
	if (seriesSignText)
		__caErrChk (CA_BSTRGetCString (seriesSignText__AutoType, seriesSignText));
	if (seriesDataText)
		__caErrChk (CA_BSTRGetCString (seriesDataText__AutoType, seriesDataText));
	if (seriesCell)
		__caErrChk (CA_BSTRGetCString (seriesCell__AutoType, seriesCell));

Error:
	CA_FreeBSTR (aChartName__AutoType);
	CA_FreeBSTR (seriesSignText__AutoType);
	CA_FreeBSTR (seriesDataText__AutoType);
	CA_FreeBSTR (seriesCell__AutoType);
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	if (FAILED(__result))
		{
		if (seriesSignText)
			{
			CA_FreeMemory (*seriesSignText);
			*seriesSignText = 0;
			}
		if (seriesDataText)
			{
			CA_FreeMemory (*seriesDataText);
			*seriesDataText = 0;
			}
		if (seriesCell)
			{
			CA_FreeMemory (*seriesCell);
			*seriesCell = 0;
			}
		}
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXGetChartSeriesCount (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo,
                                                         const char *aChartName,
                                                         long *value)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	BSTR aChartName__AutoType = 0;
	long value__Temp;

	__caErrChk (CA_CStringToBSTR (aChartName, &aChartName__AutoType));

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetChartSeriesCount_ (__vtblIFacePtr,
	                                                          aChartName__AutoType,
	                                                          &value__Temp));

	if (value)
		{
		*value = value__Temp;
		}

Error:
	CA_FreeBSTR (aChartName__AutoType);
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXDelChartSeries (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    const char *aChartName,
                                                    long aIndex)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	BSTR aChartName__AutoType = 0;

	__caErrChk (CA_CStringToBSTR (aChartName, &aChartName__AutoType));

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->DelChartSeries_ (__vtblIFacePtr,
	                                                     aChartName__AutoType,
	                                                     aIndex));

Error:
	CA_FreeBSTR (aChartName__AutoType);
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXGetFrozenCol (CAObjHandle objectHandle,
                                                  ERRORINFO *errorInfo,
                                                  long *frozenStart,
                                                  long *frozenEnd)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	long frozenStart__Temp;
	long frozenEnd__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetFrozenCol_ (__vtblIFacePtr,
	                                                   &frozenStart__Temp,
	                                                   &frozenEnd__Temp));

	if (frozenStart)
		{
		*frozenStart = frozenStart__Temp;
		}
	if (frozenEnd)
		{
		*frozenEnd = frozenEnd__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXGetFrozenRow (CAObjHandle objectHandle,
                                                  ERRORINFO *errorInfo,
                                                  long *frozenStart,
                                                  long *frozenEnd)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	long frozenStart__Temp;
	long frozenEnd__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetFrozenRow_ (__vtblIFacePtr,
	                                                   &frozenStart__Temp,
	                                                   &frozenEnd__Temp));

	if (frozenStart)
		{
		*frozenStart = frozenStart__Temp;
		}
	if (frozenEnd)
		{
		*frozenEnd = frozenEnd__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXChangeChartSeires (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       const char *aChartName,
                                                       long aIndex,
                                                       long aSeriesType,
                                                       const char *aSeriesSignText,
                                                       const char *aSeriesDataText,
                                                       const char *aSeriesCell)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	BSTR aChartName__AutoType = 0;
	BSTR aSeriesSignText__AutoType = 0;
	BSTR aSeriesDataText__AutoType = 0;
	BSTR aSeriesCell__AutoType = 0;

	__caErrChk (CA_CStringToBSTR (aChartName, &aChartName__AutoType));
	__caErrChk (CA_CStringToBSTR (aSeriesSignText, &aSeriesSignText__AutoType));
	__caErrChk (CA_CStringToBSTR (aSeriesDataText, &aSeriesDataText__AutoType));
	__caErrChk (CA_CStringToBSTR (aSeriesCell, &aSeriesCell__AutoType));

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->ChangeChartSeires_ (__vtblIFacePtr,
	                                                        aChartName__AutoType,
	                                                        aIndex,
	                                                        aSeriesType,
	                                                        aSeriesSignText__AutoType,
	                                                        aSeriesDataText__AutoType,
	                                                        aSeriesCell__AutoType));

Error:
	CA_FreeBSTR (aChartName__AutoType);
	CA_FreeBSTR (aSeriesSignText__AutoType);
	CA_FreeBSTR (aSeriesDataText__AutoType);
	CA_FreeBSTR (aSeriesCell__AutoType);
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXGetColBestWidth (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     long aCol, long *value)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	long value__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetColBestWidth_ (__vtblIFacePtr, aCol,
	                                                      &value__Temp));

	if (value)
		{
		*value = value__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXGetRowBestHeight (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      long aRow, long *value)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	long value__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetRowBestHeight_ (__vtblIFacePtr,
	                                                       aRow, &value__Temp));

	if (value)
		{
		*value = value__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXExplainCellScript (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       long aCol, long aRow)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->ExplainCellScript_ (__vtblIFacePtr,
	                                                        aCol, aRow));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXGetColPageBreak (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     long aCol, VBOOL *value)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	VBOOL value__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetColPageBreak_ (__vtblIFacePtr, aCol,
	                                                      &value__Temp));

	if (value)
		{
		*value = value__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXGetRowPageBreak (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     long aRow, VBOOL *value)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	VBOOL value__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetRowPageBreak_ (__vtblIFacePtr, aRow,
	                                                      &value__Temp));

	if (value)
		{
		*value = value__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXSetPoleText (CAObjHandle objectHandle,
                                                 ERRORINFO *errorInfo,
                                                 long aOrientation, long aIndex,
                                                 const char *aText)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	BSTR aText__AutoType = 0;

	__caErrChk (CA_CStringToBSTR (aText, &aText__AutoType));

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetPoleText_ (__vtblIFacePtr,
	                                                  aOrientation, aIndex,
	                                                  aText__AutoType));

Error:
	CA_FreeBSTR (aText__AutoType);
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXGetPoleText (CAObjHandle objectHandle,
                                                 ERRORINFO *errorInfo,
                                                 long aOrientation, long aIndex,
                                                 char **value)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	BSTR value__AutoType = 0;

	if (value)
		*value = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetPoleText_ (__vtblIFacePtr,
	                                                  aOrientation, aIndex,
	                                                  &value__AutoType));

	if (value)
		__caErrChk (CA_BSTRGetCString (value__AutoType, value));

Error:
	CA_FreeBSTR (value__AutoType);
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	if (FAILED(__result))
		{
		if (value)
			{
			CA_FreeMemory (*value);
			*value = 0;
			}
		}
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXEndEditCell (CAObjHandle objectHandle,
                                                 ERRORINFO *errorInfo,
                                                 VBOOL aCancel)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->EndEditCell_ (__vtblIFacePtr, aCancel));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXGetExecuteScript (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      VBOOL *value)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	VBOOL value__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetExecuteScript_ (__vtblIFacePtr,
	                                                       &value__Temp));

	if (value)
		{
		*value = value__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXSetExecuteScript (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      VBOOL value)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetExecuteScript_ (__vtblIFacePtr,
	                                                       value));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXGetCellSign (CAObjHandle objectHandle,
                                                 ERRORINFO *errorInfo, long aCol,
                                                 long aRow, long *value)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	long value__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetCellSign_ (__vtblIFacePtr, aCol,
	                                                  aRow, &value__Temp));

	if (value)
		{
		*value = value__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXGetGridLine (CAObjHandle objectHandle,
                                                 ERRORINFO *errorInfo,
                                                 VBOOL *value)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	VBOOL value__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetGridLine_ (__vtblIFacePtr,
	                                                  &value__Temp));

	if (value)
		{
		*value = value__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXSetGridLine (CAObjHandle objectHandle,
                                                 ERRORINFO *errorInfo,
                                                 VBOOL value)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetGridLine_ (__vtblIFacePtr, value));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXGetObjectChart (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    const char *aChartName,
                                                    char **aTitleText,
                                                    char **aHorizontalText,
                                                    char **aVerticalText)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	BSTR aChartName__AutoType = 0;
	BSTR aTitleText__AutoType = 0;
	BSTR aHorizontalText__AutoType = 0;
	BSTR aVerticalText__AutoType = 0;

	if (aTitleText)
		*aTitleText = 0;
	if (aHorizontalText)
		*aHorizontalText = 0;
	if (aVerticalText)
		*aVerticalText = 0;

	__caErrChk (CA_CStringToBSTR (aChartName, &aChartName__AutoType));

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetObjectChart_ (__vtblIFacePtr,
	                                                     aChartName__AutoType,
	                                                     &aTitleText__AutoType,
	                                                     &aHorizontalText__AutoType,
	                                                     &aVerticalText__AutoType));

	if (aTitleText)
		__caErrChk (CA_BSTRGetCString (aTitleText__AutoType, aTitleText));
	if (aHorizontalText)
		__caErrChk (CA_BSTRGetCString (aHorizontalText__AutoType, aHorizontalText));
	if (aVerticalText)
		__caErrChk (CA_BSTRGetCString (aVerticalText__AutoType, aVerticalText));

Error:
	CA_FreeBSTR (aChartName__AutoType);
	CA_FreeBSTR (aTitleText__AutoType);
	CA_FreeBSTR (aHorizontalText__AutoType);
	CA_FreeBSTR (aVerticalText__AutoType);
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	if (FAILED(__result))
		{
		if (aTitleText)
			{
			CA_FreeMemory (*aTitleText);
			*aTitleText = 0;
			}
		if (aHorizontalText)
			{
			CA_FreeMemory (*aHorizontalText);
			*aHorizontalText = 0;
			}
		if (aVerticalText)
			{
			CA_FreeMemory (*aVerticalText);
			*aVerticalText = 0;
			}
		}
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXChangeObjectChart (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       const char *aChartName,
                                                       long aCol, long aRow,
                                                       const char *aTitleText,
                                                       const char *aHorizontalText,
                                                       const char *aVerticalText)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	BSTR aChartName__AutoType = 0;
	BSTR aTitleText__AutoType = 0;
	BSTR aHorizontalText__AutoType = 0;
	BSTR aVerticalText__AutoType = 0;

	__caErrChk (CA_CStringToBSTR (aChartName, &aChartName__AutoType));
	__caErrChk (CA_CStringToBSTR (aTitleText, &aTitleText__AutoType));
	__caErrChk (CA_CStringToBSTR (aHorizontalText, &aHorizontalText__AutoType));
	__caErrChk (CA_CStringToBSTR (aVerticalText, &aVerticalText__AutoType));

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->ChangeObjectChart_ (__vtblIFacePtr,
	                                                        aChartName__AutoType,
	                                                        aCol, aRow,
	                                                        aTitleText__AutoType,
	                                                        aHorizontalText__AutoType,
	                                                        aVerticalText__AutoType));

Error:
	CA_FreeBSTR (aChartName__AutoType);
	CA_FreeBSTR (aTitleText__AutoType);
	CA_FreeBSTR (aHorizontalText__AutoType);
	CA_FreeBSTR (aVerticalText__AutoType);
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXClearCell (CAObjHandle objectHandle,
                                               ERRORINFO *errorInfo, long aCol1,
                                               long aRow1, long aCol2,
                                               long aRow2)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->ClearCell_ (__vtblIFacePtr, aCol1,
	                                                aRow1, aCol2, aRow2));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXGetAllChartName (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     char **value)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	BSTR value__AutoType = 0;

	if (value)
		*value = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetAllChartName_ (__vtblIFacePtr,
	                                                      &value__AutoType));

	if (value)
		__caErrChk (CA_BSTRGetCString (value__AutoType, value));

Error:
	CA_FreeBSTR (value__AutoType);
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	if (FAILED(__result))
		{
		if (value)
			{
			CA_FreeMemory (*value);
			*value = 0;
			}
		}
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXAddPicture (CAObjHandle objectHandle,
                                                ERRORINFO *errorInfo,
                                                const char *aFileName)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	BSTR aFileName__AutoType = 0;

	__caErrChk (CA_CStringToBSTR (aFileName, &aFileName__AutoType));

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->AddPicture_ (__vtblIFacePtr,
	                                                 aFileName__AutoType));

Error:
	CA_FreeBSTR (aFileName__AutoType);
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXDelPicture (CAObjHandle objectHandle,
                                                ERRORINFO *errorInfo)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->DelPicture_ (__vtblIFacePtr));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXSetCellNote (CAObjHandle objectHandle,
                                                 ERRORINFO *errorInfo, long aCol,
                                                 long aRow,
                                                 const char *aNoteText)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	BSTR aNoteText__AutoType = 0;

	__caErrChk (CA_CStringToBSTR (aNoteText, &aNoteText__AutoType));

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetCellNote_ (__vtblIFacePtr, aCol,
	                                                  aRow,
	                                                  aNoteText__AutoType));

Error:
	CA_FreeBSTR (aNoteText__AutoType);
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXGetCellNote (CAObjHandle objectHandle,
                                                 ERRORINFO *errorInfo, long aCol,
                                                 long aRow, char **value)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	BSTR value__AutoType = 0;

	if (value)
		*value = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetCellNote_ (__vtblIFacePtr, aCol,
	                                                  aRow, &value__AutoType));

	if (value)
		__caErrChk (CA_BSTRGetCString (value__AutoType, value));

Error:
	CA_FreeBSTR (value__AutoType);
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	if (FAILED(__result))
		{
		if (value)
			{
			CA_FreeMemory (*value);
			*value = 0;
			}
		}
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXGetPoleReadOnly (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     VBOOL *value)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	VBOOL value__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetPoleReadOnly_ (__vtblIFacePtr,
	                                                      &value__Temp));

	if (value)
		{
		*value = value__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXSetPoleReadOnly (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     VBOOL value)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetPoleReadOnly_ (__vtblIFacePtr,
	                                                      value));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXGetCellReadOnlyProp (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo,
                                                         VBOOL *value)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	VBOOL value__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetCellReadOnlyProp_ (__vtblIFacePtr,
	                                                          &value__Temp));

	if (value)
		{
		*value = value__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXSetCellReadOnlyProp (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo,
                                                         VBOOL value)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetCellReadOnlyProp_ (__vtblIFacePtr,
	                                                          value));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXCopyRangeToRange (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      long aCol1, long aRow1,
                                                      long aCol2, long aRow2,
                                                      long aToCol, long aToRow,
                                                      long aCount)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->CopyRangeToRange_ (__vtblIFacePtr,
	                                                       aCol1, aRow1, aCol2,
	                                                       aRow2, aToCol,
	                                                       aToRow, aCount));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXGetRightWidth (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   long *value)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	long value__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetRightWidth_ (__vtblIFacePtr,
	                                                    &value__Temp));

	if (value)
		{
		*value = value__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXSetRightWidth (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   long value)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetRightWidth_ (__vtblIFacePtr, value));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXGetBottomHeight (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     long *value)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	long value__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetBottomHeight_ (__vtblIFacePtr,
	                                                      &value__Temp));

	if (value)
		{
		*value = value__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXSetBottomHeight (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     long value)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetBottomHeight_ (__vtblIFacePtr,
	                                                      value));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXClearData (CAObjHandle objectHandle,
                                               ERRORINFO *errorInfo, long aCol1,
                                               long aRow1, long aCol2,
                                               long aRow2)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->ClearData_ (__vtblIFacePtr, aCol1,
	                                                aRow1, aCol2, aRow2));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXGetPaperSource (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    long *value)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	long value__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetPaperSource_ (__vtblIFacePtr,
	                                                     &value__Temp));

	if (value)
		{
		*value = value__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXSetPaperSource (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    long value)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetPaperSource_ (__vtblIFacePtr, value));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXGetCellWidth (CAObjHandle objectHandle,
                                                  ERRORINFO *errorInfo,
                                                  long *value)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	long value__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetCellWidth_ (__vtblIFacePtr,
	                                                   &value__Temp));

	if (value)
		{
		*value = value__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXSetCellWidth (CAObjHandle objectHandle,
                                                  ERRORINFO *errorInfo,
                                                  long value)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetCellWidth_ (__vtblIFacePtr, value));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXGetCellHeight (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   long *value)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	long value__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetCellHeight_ (__vtblIFacePtr,
	                                                    &value__Temp));

	if (value)
		{
		*value = value__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXSetCellHeight (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   long value)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetCellHeight_ (__vtblIFacePtr, value));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXGetFontName (CAObjHandle objectHandle,
                                                 ERRORINFO *errorInfo,
                                                 char **value)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	BSTR value__AutoType = 0;

	if (value)
		*value = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetFontName_ (__vtblIFacePtr,
	                                                  &value__AutoType));

	if (value)
		__caErrChk (CA_BSTRGetCString (value__AutoType, value));

Error:
	CA_FreeBSTR (value__AutoType);
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	if (FAILED(__result))
		{
		if (value)
			{
			CA_FreeMemory (*value);
			*value = 0;
			}
		}
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXSetFontName (CAObjHandle objectHandle,
                                                 ERRORINFO *errorInfo,
                                                 const char *value)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	BSTR value__AutoType = 0;

	__caErrChk (CA_CStringToBSTR (value, &value__AutoType));

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetFontName_ (__vtblIFacePtr,
	                                                  value__AutoType));

Error:
	CA_FreeBSTR (value__AutoType);
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXGetFontSize (CAObjHandle objectHandle,
                                                 ERRORINFO *errorInfo,
                                                 long *value)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	long value__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetFontSize_ (__vtblIFacePtr,
	                                                  &value__Temp));

	if (value)
		{
		*value = value__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXSetFontSize (CAObjHandle objectHandle,
                                                 ERRORINFO *errorInfo,
                                                 long value)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetFontSize_ (__vtblIFacePtr, value));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXGetCellLabel (CAObjHandle objectHandle,
                                                  ERRORINFO *errorInfo,
                                                  long aCol, long aRow,
                                                  char **value)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	BSTR value__AutoType = 0;

	if (value)
		*value = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetCellLabel_ (__vtblIFacePtr, aCol,
	                                                   aRow, &value__AutoType));

	if (value)
		__caErrChk (CA_BSTRGetCString (value__AutoType, value));

Error:
	CA_FreeBSTR (value__AutoType);
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	if (FAILED(__result))
		{
		if (value)
			{
			CA_FreeMemory (*value);
			*value = 0;
			}
		}
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXGetRangeLabel (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   long aCol1, long aRow1,
                                                   long aCol2, long aRow2,
                                                   char **value)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	BSTR value__AutoType = 0;

	if (value)
		*value = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetRangeLabel_ (__vtblIFacePtr, aCol1,
	                                                    aRow1, aCol2, aRow2,
	                                                    &value__AutoType));

	if (value)
		__caErrChk (CA_BSTRGetCString (value__AutoType, value));

Error:
	CA_FreeBSTR (value__AutoType);
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	if (FAILED(__result))
		{
		if (value)
			{
			CA_FreeMemory (*value);
			*value = 0;
			}
		}
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXOpenDatabaseGuide (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->OpenDatabaseGuide_ (__vtblIFacePtr));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXGetConnectionString (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo,
                                                         char **value)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	BSTR value__AutoType = 0;

	if (value)
		*value = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetConnectionString_ (__vtblIFacePtr,
	                                                          &value__AutoType));

	if (value)
		__caErrChk (CA_BSTRGetCString (value__AutoType, value));

Error:
	CA_FreeBSTR (value__AutoType);
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	if (FAILED(__result))
		{
		if (value)
			{
			CA_FreeMemory (*value);
			*value = 0;
			}
		}
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXSetConnectionString (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo,
                                                         const char *value)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	BSTR value__AutoType = 0;

	__caErrChk (CA_CStringToBSTR (value, &value__AutoType));

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetConnectionString_ (__vtblIFacePtr,
	                                                          value__AutoType));

Error:
	CA_FreeBSTR (value__AutoType);
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXAddField (CAObjHandle objectHandle,
                                              ERRORINFO *errorInfo,
                                              const char *aFieldName,
                                              const char *aFieldAttribute,
                                              long aFieldIndex)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	BSTR aFieldName__AutoType = 0;
	BSTR aFieldAttribute__AutoType = 0;

	__caErrChk (CA_CStringToBSTR (aFieldName, &aFieldName__AutoType));
	__caErrChk (CA_CStringToBSTR (aFieldAttribute, &aFieldAttribute__AutoType));

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->AddField_ (__vtblIFacePtr,
	                                               aFieldName__AutoType,
	                                               aFieldAttribute__AutoType,
	                                               aFieldIndex));

Error:
	CA_FreeBSTR (aFieldName__AutoType);
	CA_FreeBSTR (aFieldAttribute__AutoType);
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXDelField (CAObjHandle objectHandle,
                                              ERRORINFO *errorInfo,
                                              long aFieldIndex)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->DelField_ (__vtblIFacePtr, aFieldIndex));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXChangeField (CAObjHandle objectHandle,
                                                 ERRORINFO *errorInfo,
                                                 long aFieldIndex,
                                                 const char *aFieldName,
                                                 const char *aFieldAttribute)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	BSTR aFieldName__AutoType = 0;
	BSTR aFieldAttribute__AutoType = 0;

	__caErrChk (CA_CStringToBSTR (aFieldName, &aFieldName__AutoType));
	__caErrChk (CA_CStringToBSTR (aFieldAttribute, &aFieldAttribute__AutoType));

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->ChangeField_ (__vtblIFacePtr,
	                                                  aFieldIndex,
	                                                  aFieldName__AutoType,
	                                                  aFieldAttribute__AutoType));

Error:
	CA_FreeBSTR (aFieldName__AutoType);
	CA_FreeBSTR (aFieldAttribute__AutoType);
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXGetQueryFrom (CAObjHandle objectHandle,
                                                  ERRORINFO *errorInfo,
                                                  char **value)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	BSTR value__AutoType = 0;

	if (value)
		*value = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetQueryFrom_ (__vtblIFacePtr,
	                                                   &value__AutoType));

	if (value)
		__caErrChk (CA_BSTRGetCString (value__AutoType, value));

Error:
	CA_FreeBSTR (value__AutoType);
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	if (FAILED(__result))
		{
		if (value)
			{
			CA_FreeMemory (*value);
			*value = 0;
			}
		}
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXSetQueryFrom (CAObjHandle objectHandle,
                                                  ERRORINFO *errorInfo,
                                                  const char *value)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	BSTR value__AutoType = 0;

	__caErrChk (CA_CStringToBSTR (value, &value__AutoType));

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetQueryFrom_ (__vtblIFacePtr,
	                                                   value__AutoType));

Error:
	CA_FreeBSTR (value__AutoType);
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXGetQueryWhere (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   char **value)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	BSTR value__AutoType = 0;

	if (value)
		*value = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetQueryWhere_ (__vtblIFacePtr,
	                                                    &value__AutoType));

	if (value)
		__caErrChk (CA_BSTRGetCString (value__AutoType, value));

Error:
	CA_FreeBSTR (value__AutoType);
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	if (FAILED(__result))
		{
		if (value)
			{
			CA_FreeMemory (*value);
			*value = 0;
			}
		}
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXSetQueryWhere (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   const char *value)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	BSTR value__AutoType = 0;

	__caErrChk (CA_CStringToBSTR (value, &value__AutoType));

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetQueryWhere_ (__vtblIFacePtr,
	                                                    value__AutoType));

Error:
	CA_FreeBSTR (value__AutoType);
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXGetQueryHaving (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    char **value)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	BSTR value__AutoType = 0;

	if (value)
		*value = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetQueryHaving_ (__vtblIFacePtr,
	                                                     &value__AutoType));

	if (value)
		__caErrChk (CA_BSTRGetCString (value__AutoType, value));

Error:
	CA_FreeBSTR (value__AutoType);
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	if (FAILED(__result))
		{
		if (value)
			{
			CA_FreeMemory (*value);
			*value = 0;
			}
		}
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXSetQueryHaving (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    const char *value)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	BSTR value__AutoType = 0;

	__caErrChk (CA_CStringToBSTR (value, &value__AutoType));

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetQueryHaving_ (__vtblIFacePtr,
	                                                     value__AutoType));

Error:
	CA_FreeBSTR (value__AutoType);
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXClearField (CAObjHandle objectHandle,
                                                ERRORINFO *errorInfo)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->ClearField_ (__vtblIFacePtr));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXAddFieldOrder (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   const char *aFieldName,
                                                   VBOOL aFieldOrder,
                                                   long aFieldIndex)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	BSTR aFieldName__AutoType = 0;

	__caErrChk (CA_CStringToBSTR (aFieldName, &aFieldName__AutoType));

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->AddFieldOrder_ (__vtblIFacePtr,
	                                                    aFieldName__AutoType,
	                                                    aFieldOrder,
	                                                    aFieldIndex));

Error:
	CA_FreeBSTR (aFieldName__AutoType);
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXDelFieldOrder (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   long aFieldIndex)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->DelFieldOrder_ (__vtblIFacePtr,
	                                                    aFieldIndex));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXOpenQuery (CAObjHandle objectHandle,
                                               ERRORINFO *errorInfo)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->OpenQuery_ (__vtblIFacePtr));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXGetField (CAObjHandle objectHandle,
                                              ERRORINFO *errorInfo,
                                              long aFieldIndex, char **fieldName,
                                              char **fieldAttribute)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	BSTR fieldName__AutoType = 0;
	BSTR fieldAttribute__AutoType = 0;

	__caErrChk (CA_CStringToBSTR (*fieldName, &fieldName__AutoType));
	__caErrChk (CA_CStringToBSTR (*fieldAttribute, &fieldAttribute__AutoType));

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetField_ (__vtblIFacePtr, aFieldIndex,
	                                               &fieldName__AutoType,
	                                               &fieldAttribute__AutoType));

	if (fieldName)
		{
		CA_FreeMemory (*fieldName);
		*fieldName = 0;
		}
	if (fieldName)
		__caErrChk (CA_BSTRGetCString (fieldName__AutoType, fieldName));
	if (fieldAttribute)
		{
		CA_FreeMemory (*fieldAttribute);
		*fieldAttribute = 0;
		}
	if (fieldAttribute)
		__caErrChk (CA_BSTRGetCString (fieldAttribute__AutoType, fieldAttribute));

Error:
	CA_FreeBSTR (fieldName__AutoType);
	CA_FreeBSTR (fieldAttribute__AutoType);
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	if (FAILED(__result))
		{
		if (fieldName)
			{
			CA_FreeMemory (*fieldName);
			*fieldName = 0;
			}
		if (fieldAttribute)
			{
			CA_FreeMemory (*fieldAttribute);
			*fieldAttribute = 0;
			}
		}
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXGetAllField (CAObjHandle objectHandle,
                                                 ERRORINFO *errorInfo,
                                                 char **value)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	BSTR value__AutoType = 0;

	if (value)
		*value = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetAllField_ (__vtblIFacePtr,
	                                                  &value__AutoType));

	if (value)
		__caErrChk (CA_BSTRGetCString (value__AutoType, value));

Error:
	CA_FreeBSTR (value__AutoType);
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	if (FAILED(__result))
		{
		if (value)
			{
			CA_FreeMemory (*value);
			*value = 0;
			}
		}
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXGetFeildOrder (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   long aFieldIndex,
                                                   char **fieldName,
                                                   VBOOL *fieldOrder)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	BSTR fieldName__AutoType = 0;

	__caErrChk (CA_CStringToBSTR (*fieldName, &fieldName__AutoType));

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetFeildOrder_ (__vtblIFacePtr,
	                                                    aFieldIndex,
	                                                    &fieldName__AutoType,
	                                                    fieldOrder));

	if (fieldName)
		{
		CA_FreeMemory (*fieldName);
		*fieldName = 0;
		}
	if (fieldName)
		__caErrChk (CA_BSTRGetCString (fieldName__AutoType, fieldName));

Error:
	CA_FreeBSTR (fieldName__AutoType);
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	if (FAILED(__result))
		{
		if (fieldName)
			{
			CA_FreeMemory (*fieldName);
			*fieldName = 0;
			}
		}
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXGetAllFieldOrder (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      char **value)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	BSTR value__AutoType = 0;

	if (value)
		*value = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetAllFieldOrder_ (__vtblIFacePtr,
	                                                       &value__AutoType));

	if (value)
		__caErrChk (CA_BSTRGetCString (value__AutoType, value));

Error:
	CA_FreeBSTR (value__AutoType);
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	if (FAILED(__result))
		{
		if (value)
			{
			CA_FreeMemory (*value);
			*value = 0;
			}
		}
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXClearFieldOrder (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->ClearFieldOrder_ (__vtblIFacePtr));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXGetReportType (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   long *value)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	long value__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetReportType_ (__vtblIFacePtr,
	                                                    &value__Temp));

	if (value)
		{
		*value = value__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXSetReportType (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   long value)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetReportType_ (__vtblIFacePtr, value));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXGetGroupType (CAObjHandle objectHandle,
                                                  ERRORINFO *errorInfo,
                                                  long *value)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	long value__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetGroupType_ (__vtblIFacePtr,
	                                                   &value__Temp));

	if (value)
		{
		*value = value__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXSetGroupType (CAObjHandle objectHandle,
                                                  ERRORINFO *errorInfo,
                                                  long value)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetGroupType_ (__vtblIFacePtr, value));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXGetGroupPageBreak (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       VBOOL *value)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	VBOOL value__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetGroupPageBreak_ (__vtblIFacePtr,
	                                                        &value__Temp));

	if (value)
		{
		*value = value__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXSetGroupPageBreak (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       VBOOL value)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetGroupPageBreak_ (__vtblIFacePtr,
	                                                        value));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXGetReportLeft (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   long *value)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	long value__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetReportLeft_ (__vtblIFacePtr,
	                                                    &value__Temp));

	if (value)
		{
		*value = value__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXSetReportLeft (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   long value)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetReportLeft_ (__vtblIFacePtr, value));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXGetReportTop (CAObjHandle objectHandle,
                                                  ERRORINFO *errorInfo,
                                                  long *value)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	long value__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetReportTop_ (__vtblIFacePtr,
	                                                   &value__Temp));

	if (value)
		{
		*value = value__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXSetReportTop (CAObjHandle objectHandle,
                                                  ERRORINFO *errorInfo,
                                                  long value)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetReportTop_ (__vtblIFacePtr, value));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXAddFieldCell (CAObjHandle objectHandle,
                                                  ERRORINFO *errorInfo,
                                                  const char *aAlias,
                                                  const char *aFieldName,
                                                  long aFieldFunction)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	BSTR aAlias__AutoType = 0;
	BSTR aFieldName__AutoType = 0;

	__caErrChk (CA_CStringToBSTR (aAlias, &aAlias__AutoType));
	__caErrChk (CA_CStringToBSTR (aFieldName, &aFieldName__AutoType));

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->AddFieldCell_ (__vtblIFacePtr,
	                                                   aAlias__AutoType,
	                                                   aFieldName__AutoType,
	                                                   aFieldFunction));

Error:
	CA_FreeBSTR (aAlias__AutoType);
	CA_FreeBSTR (aFieldName__AutoType);
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXDelFieldCell (CAObjHandle objectHandle,
                                                  ERRORINFO *errorInfo,
                                                  const char *aAlias)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	BSTR aAlias__AutoType = 0;

	__caErrChk (CA_CStringToBSTR (aAlias, &aAlias__AutoType));

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->DelFieldCell_ (__vtblIFacePtr,
	                                                   aAlias__AutoType));

Error:
	CA_FreeBSTR (aAlias__AutoType);
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXClearFieldCell (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->ClearFieldCell_ (__vtblIFacePtr));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXGetAllFieldCell (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     char **value)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	BSTR value__AutoType = 0;

	if (value)
		*value = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetAllFieldCell_ (__vtblIFacePtr,
	                                                      &value__AutoType));

	if (value)
		__caErrChk (CA_BSTRGetCString (value__AutoType, value));

Error:
	CA_FreeBSTR (value__AutoType);
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	if (FAILED(__result))
		{
		if (value)
			{
			CA_FreeMemory (*value);
			*value = 0;
			}
		}
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXGetAlternatingColor (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo,
                                                         long *value)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	long value__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetAlternatingColor_ (__vtblIFacePtr,
	                                                          &value__Temp));

	if (value)
		{
		*value = value__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXSetAlternatingColor (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo,
                                                         long value)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetAlternatingColor_ (__vtblIFacePtr,
	                                                          value));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXGetColTotal (CAObjHandle objectHandle,
                                                 ERRORINFO *errorInfo,
                                                 VBOOL *value)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	VBOOL value__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetColTotal_ (__vtblIFacePtr,
	                                                  &value__Temp));

	if (value)
		{
		*value = value__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXSetColTotal (CAObjHandle objectHandle,
                                                 ERRORINFO *errorInfo,
                                                 VBOOL value)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetColTotal_ (__vtblIFacePtr, value));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXGetRowTotal (CAObjHandle objectHandle,
                                                 ERRORINFO *errorInfo,
                                                 VBOOL *value)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	VBOOL value__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetRowTotal_ (__vtblIFacePtr,
	                                                  &value__Temp));

	if (value)
		{
		*value = value__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXSetRowTotal (CAObjHandle objectHandle,
                                                 ERRORINFO *errorInfo,
                                                 VBOOL value)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetRowTotal_ (__vtblIFacePtr, value));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXChangeFieldOrder (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      long aFieldIndex,
                                                      const char *aFieldName,
                                                      VBOOL aFieldOrder)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	BSTR aFieldName__AutoType = 0;

	__caErrChk (CA_CStringToBSTR (aFieldName, &aFieldName__AutoType));

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->ChangeFieldOrder_ (__vtblIFacePtr,
	                                                       aFieldIndex,
	                                                       aFieldName__AutoType,
	                                                       aFieldOrder));

Error:
	CA_FreeBSTR (aFieldName__AutoType);
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXChangeFieldCell (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     const char *aAlias,
                                                     const char *aFieldName,
                                                     long aFieldFunction)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	BSTR aAlias__AutoType = 0;
	BSTR aFieldName__AutoType = 0;

	__caErrChk (CA_CStringToBSTR (aAlias, &aAlias__AutoType));
	__caErrChk (CA_CStringToBSTR (aFieldName, &aFieldName__AutoType));

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->ChangeFieldCell_ (__vtblIFacePtr,
	                                                      aAlias__AutoType,
	                                                      aFieldName__AutoType,
	                                                      aFieldFunction));

Error:
	CA_FreeBSTR (aAlias__AutoType);
	CA_FreeBSTR (aFieldName__AutoType);
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXGetFieldCell (CAObjHandle objectHandle,
                                                  ERRORINFO *errorInfo,
                                                  const char *aAlias,
                                                  char **fieldName,
                                                  long *fieldFunction)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	BSTR aAlias__AutoType = 0;
	BSTR fieldName__AutoType = 0;

	__caErrChk (CA_CStringToBSTR (aAlias, &aAlias__AutoType));
	__caErrChk (CA_CStringToBSTR (*fieldName, &fieldName__AutoType));

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetFieldCell_ (__vtblIFacePtr,
	                                                   aAlias__AutoType,
	                                                   &fieldName__AutoType,
	                                                   fieldFunction));

	if (fieldName)
		{
		CA_FreeMemory (*fieldName);
		*fieldName = 0;
		}
	if (fieldName)
		__caErrChk (CA_BSTRGetCString (fieldName__AutoType, fieldName));

Error:
	CA_FreeBSTR (aAlias__AutoType);
	CA_FreeBSTR (fieldName__AutoType);
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	if (FAILED(__result))
		{
		if (fieldName)
			{
			CA_FreeMemory (*fieldName);
			*fieldName = 0;
			}
		}
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXGetSqlText (CAObjHandle objectHandle,
                                                ERRORINFO *errorInfo,
                                                char **value)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	BSTR value__AutoType = 0;

	if (value)
		*value = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetSqlText_ (__vtblIFacePtr,
	                                                 &value__AutoType));

	if (value)
		__caErrChk (CA_BSTRGetCString (value__AutoType, value));

Error:
	CA_FreeBSTR (value__AutoType);
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	if (FAILED(__result))
		{
		if (value)
			{
			CA_FreeMemory (*value);
			*value = 0;
			}
		}
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXGetPoleSelectColor (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        long *value)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	long value__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetPoleSelectColor_ (__vtblIFacePtr,
	                                                         &value__Temp));

	if (value)
		{
		*value = value__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXSetPoleSelectColor (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        long value)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetPoleSelectColor_ (__vtblIFacePtr,
	                                                         value));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXSetCellSelectColor (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        long aColor1,
                                                        long aColor2)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetCellSelectColor_ (__vtblIFacePtr,
	                                                         aColor1, aColor2));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXGetCellSelectColor (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        long *color1,
                                                        long *color2)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetCellSelectColor_ (__vtblIFacePtr,
	                                                         color1, color2));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXGetPoleColor (CAObjHandle objectHandle,
                                                  ERRORINFO *errorInfo,
                                                  long *value)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	long value__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetPoleColor_ (__vtblIFacePtr,
	                                                   &value__Temp));

	if (value)
		{
		*value = value__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXSetPoleColor (CAObjHandle objectHandle,
                                                  ERRORINFO *errorInfo,
                                                  long value)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetPoleColor_ (__vtblIFacePtr, value));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXGetPoleSeparatorColor (CAObjHandle objectHandle,
                                                           ERRORINFO *errorInfo,
                                                           long *value)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	long value__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetPoleSeparatorColor_ (__vtblIFacePtr,
	                                                            &value__Temp));

	if (value)
		{
		*value = value__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXSetPoleSeparatorColor (CAObjHandle objectHandle,
                                                           ERRORINFO *errorInfo,
                                                           long value)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetPoleSeparatorColor_ (__vtblIFacePtr,
	                                                            value));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXGetCellSeparatorColor (CAObjHandle objectHandle,
                                                           ERRORINFO *errorInfo,
                                                           long *value)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	long value__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetCellSeparatorColor_ (__vtblIFacePtr,
	                                                            &value__Temp));

	if (value)
		{
		*value = value__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXSetCellSeparatorColor (CAObjHandle objectHandle,
                                                           ERRORINFO *errorInfo,
                                                           long value)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetCellSeparatorColor_ (__vtblIFacePtr,
	                                                            value));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXSetBarCodeCell (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    long aCol, long aRow,
                                                    long aCode,
                                                    VBOOL aOrientation)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetBarCodeCell_ (__vtblIFacePtr, aCol,
	                                                     aRow, aCode,
	                                                     aOrientation));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXGetCellCode (CAObjHandle objectHandle,
                                                 ERRORINFO *errorInfo, long aCol,
                                                 long aRow, long *value)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	long value__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetCellCode_ (__vtblIFacePtr, aCol,
	                                                  aRow, &value__Temp));

	if (value)
		{
		*value = value__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXGetDisplayZero (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    VBOOL *value)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	VBOOL value__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetDisplayZero_ (__vtblIFacePtr,
	                                                     &value__Temp));

	if (value)
		{
		*value = value__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXSetDisplayZero (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    VBOOL value)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetDisplayZero_ (__vtblIFacePtr, value));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXGetPageFontColor (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      long *value)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	long value__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetPageFontColor_ (__vtblIFacePtr,
	                                                       &value__Temp));

	if (value)
		{
		*value = value__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXSetPageFontColor (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      long value)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetPageFontColor_ (__vtblIFacePtr,
	                                                       value));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXGetPageFontStyleBold (CAObjHandle objectHandle,
                                                          ERRORINFO *errorInfo,
                                                          VBOOL *value)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	VBOOL value__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetPageFontStyleBold_ (__vtblIFacePtr,
	                                                           &value__Temp));

	if (value)
		{
		*value = value__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXSetPageFontStyleBold (CAObjHandle objectHandle,
                                                          ERRORINFO *errorInfo,
                                                          VBOOL value)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetPageFontStyleBold_ (__vtblIFacePtr,
	                                                           value));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXGetPageFontStyleItalic (CAObjHandle objectHandle,
                                                            ERRORINFO *errorInfo,
                                                            VBOOL *value)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	VBOOL value__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetPageFontStyleItalic_ (__vtblIFacePtr,
	                                                             &value__Temp));

	if (value)
		{
		*value = value__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXSetPageFontStyleItalic (CAObjHandle objectHandle,
                                                            ERRORINFO *errorInfo,
                                                            VBOOL value)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetPageFontStyleItalic_ (__vtblIFacePtr,
	                                                             value));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXGetPageHeaderCenterText (CAObjHandle objectHandle,
                                                             ERRORINFO *errorInfo,
                                                             char **value)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	BSTR value__AutoType = 0;

	if (value)
		*value = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetPageHeaderCenterText_ (__vtblIFacePtr,
	                                                              &value__AutoType));

	if (value)
		__caErrChk (CA_BSTRGetCString (value__AutoType, value));

Error:
	CA_FreeBSTR (value__AutoType);
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	if (FAILED(__result))
		{
		if (value)
			{
			CA_FreeMemory (*value);
			*value = 0;
			}
		}
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXSetPageHeaderCenterText (CAObjHandle objectHandle,
                                                             ERRORINFO *errorInfo,
                                                             const char *value)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	BSTR value__AutoType = 0;

	__caErrChk (CA_CStringToBSTR (value, &value__AutoType));

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetPageHeaderCenterText_ (__vtblIFacePtr,
	                                                              value__AutoType));

Error:
	CA_FreeBSTR (value__AutoType);
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXGetPageFooterCenterText (CAObjHandle objectHandle,
                                                             ERRORINFO *errorInfo,
                                                             char **value)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	BSTR value__AutoType = 0;

	if (value)
		*value = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetPageFooterCenterText_ (__vtblIFacePtr,
	                                                              &value__AutoType));

	if (value)
		__caErrChk (CA_BSTRGetCString (value__AutoType, value));

Error:
	CA_FreeBSTR (value__AutoType);
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	if (FAILED(__result))
		{
		if (value)
			{
			CA_FreeMemory (*value);
			*value = 0;
			}
		}
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXSetPageFooterCenterText (CAObjHandle objectHandle,
                                                             ERRORINFO *errorInfo,
                                                             const char *value)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	BSTR value__AutoType = 0;

	__caErrChk (CA_CStringToBSTR (value, &value__AutoType));

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetPageFooterCenterText_ (__vtblIFacePtr,
	                                                              value__AutoType));

Error:
	CA_FreeBSTR (value__AutoType);
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXGetPageHeaderRightText (CAObjHandle objectHandle,
                                                            ERRORINFO *errorInfo,
                                                            char **value)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	BSTR value__AutoType = 0;

	if (value)
		*value = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetPageHeaderRightText_ (__vtblIFacePtr,
	                                                             &value__AutoType));

	if (value)
		__caErrChk (CA_BSTRGetCString (value__AutoType, value));

Error:
	CA_FreeBSTR (value__AutoType);
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	if (FAILED(__result))
		{
		if (value)
			{
			CA_FreeMemory (*value);
			*value = 0;
			}
		}
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXSetPageHeaderRightText (CAObjHandle objectHandle,
                                                            ERRORINFO *errorInfo,
                                                            const char *value)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	BSTR value__AutoType = 0;

	__caErrChk (CA_CStringToBSTR (value, &value__AutoType));

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetPageHeaderRightText_ (__vtblIFacePtr,
	                                                             value__AutoType));

Error:
	CA_FreeBSTR (value__AutoType);
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXGetPageFooterRightText (CAObjHandle objectHandle,
                                                            ERRORINFO *errorInfo,
                                                            char **value)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	BSTR value__AutoType = 0;

	if (value)
		*value = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetPageFooterRightText_ (__vtblIFacePtr,
	                                                             &value__AutoType));

	if (value)
		__caErrChk (CA_BSTRGetCString (value__AutoType, value));

Error:
	CA_FreeBSTR (value__AutoType);
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	if (FAILED(__result))
		{
		if (value)
			{
			CA_FreeMemory (*value);
			*value = 0;
			}
		}
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXSetPageFooterRightText (CAObjHandle objectHandle,
                                                            ERRORINFO *errorInfo,
                                                            const char *value)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	BSTR value__AutoType = 0;

	__caErrChk (CA_CStringToBSTR (value, &value__AutoType));

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetPageFooterRightText_ (__vtblIFacePtr,
	                                                             value__AutoType));

Error:
	CA_FreeBSTR (value__AutoType);
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXGetCellCaption (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    long aCol, long aRow,
                                                    char **value)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	BSTR value__AutoType = 0;

	if (value)
		*value = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetCellCaption_ (__vtblIFacePtr, aCol,
	                                                     aRow,
	                                                     &value__AutoType));

	if (value)
		__caErrChk (CA_BSTRGetCString (value__AutoType, value));

Error:
	CA_FreeBSTR (value__AutoType);
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	if (FAILED(__result))
		{
		if (value)
			{
			CA_FreeMemory (*value);
			*value = 0;
			}
		}
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXGetLabelRange (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   const char *aLabel,
                                                   long *col1, long *row1,
                                                   long *col2, long *row2,
                                                   VBOOL *value)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	BSTR aLabel__AutoType = 0;
	long col1__Temp;
	long row1__Temp;
	long col2__Temp;
	long row2__Temp;
	VBOOL value__Temp;

	__caErrChk (CA_CStringToBSTR (aLabel, &aLabel__AutoType));

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetLabelRange_ (__vtblIFacePtr,
	                                                    aLabel__AutoType,
	                                                    &col1__Temp,
	                                                    &row1__Temp,
	                                                    &col2__Temp,
	                                                    &row2__Temp,
	                                                    &value__Temp));

	if (col1)
		{
		*col1 = col1__Temp;
		}
	if (row1)
		{
		*row1 = row1__Temp;
		}
	if (col2)
		{
		*col2 = col2__Temp;
		}
	if (row2)
		{
		*row2 = row2__Temp;
		}
	if (value)
		{
		*value = value__Temp;
		}

Error:
	CA_FreeBSTR (aLabel__AutoType);
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXSetRichTextCell (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     long aCol, long aRow)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetRichTextCell_ (__vtblIFacePtr, aCol,
	                                                      aRow));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXSetRichTextFontName (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo,
                                                         const char *aFontName)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	BSTR aFontName__AutoType = 0;

	__caErrChk (CA_CStringToBSTR (aFontName, &aFontName__AutoType));

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetRichTextFontName_ (__vtblIFacePtr,
	                                                          aFontName__AutoType));

Error:
	CA_FreeBSTR (aFontName__AutoType);
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXSetRichTextFontSize (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo,
                                                         long aFontSize)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetRichTextFontSize_ (__vtblIFacePtr,
	                                                          aFontSize));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXSetRichTextFontColor (CAObjHandle objectHandle,
                                                          ERRORINFO *errorInfo,
                                                          long aFontColor)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetRichTextFontColor_ (__vtblIFacePtr,
	                                                           aFontColor));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXSetRichTextFontStyle (CAObjHandle objectHandle,
                                                          ERRORINFO *errorInfo,
                                                          long aFontStyle,
                                                          VBOOL aStyleBool)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetRichTextFontStyle_ (__vtblIFacePtr,
	                                                           aFontStyle,
	                                                           aStyleBool));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXSetRichTextOffset (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       long aOffset)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetRichTextOffset_ (__vtblIFacePtr,
	                                                        aOffset));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXGetRichTextFontName (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo,
                                                         char **value)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	BSTR value__AutoType = 0;

	if (value)
		*value = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetRichTextFontName_ (__vtblIFacePtr,
	                                                          &value__AutoType));

	if (value)
		__caErrChk (CA_BSTRGetCString (value__AutoType, value));

Error:
	CA_FreeBSTR (value__AutoType);
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	if (FAILED(__result))
		{
		if (value)
			{
			CA_FreeMemory (*value);
			*value = 0;
			}
		}
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXGetRichTextFontSize (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo,
                                                         long *value)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	long value__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetRichTextFontSize_ (__vtblIFacePtr,
	                                                          &value__Temp));

	if (value)
		{
		*value = value__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXGetRichTextFontColor (CAObjHandle objectHandle,
                                                          ERRORINFO *errorInfo,
                                                          long *value)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	long value__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetRichTextFontColor_ (__vtblIFacePtr,
	                                                           &value__Temp));

	if (value)
		{
		*value = value__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXGetRichTextFontStyle (CAObjHandle objectHandle,
                                                          ERRORINFO *errorInfo,
                                                          long aFontStyle,
                                                          VBOOL *value)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	VBOOL value__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetRichTextFontStyle_ (__vtblIFacePtr,
	                                                           aFontStyle,
	                                                           &value__Temp));

	if (value)
		{
		*value = value__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXGetRichTextOffset (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       long *value)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	long value__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetRichTextOffset_ (__vtblIFacePtr,
	                                                        &value__Temp));

	if (value)
		{
		*value = value__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXLoadIcon (CAObjHandle objectHandle,
                                              ERRORINFO *errorInfo,
                                              const char *aFileName)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	BSTR aFileName__AutoType = 0;

	__caErrChk (CA_CStringToBSTR (aFileName, &aFileName__AutoType));

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->LoadIcon_ (__vtblIFacePtr,
	                                               aFileName__AutoType));

Error:
	CA_FreeBSTR (aFileName__AutoType);
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXSetCellRichTextValue (CAObjHandle objectHandle,
                                                          ERRORINFO *errorInfo,
                                                          long aCol, long aRow,
                                                          const char *aValue)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	BSTR aValue__AutoType = 0;

	__caErrChk (CA_CStringToBSTR (aValue, &aValue__AutoType));

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetCellRichTextValue_ (__vtblIFacePtr,
	                                                           aCol, aRow,
	                                                           aValue__AutoType));

Error:
	CA_FreeBSTR (aValue__AutoType);
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXGetCellRichTextValue (CAObjHandle objectHandle,
                                                          ERRORINFO *errorInfo,
                                                          long aCol, long aRow,
                                                          char **value)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	BSTR value__AutoType = 0;

	if (value)
		*value = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetCellRichTextValue_ (__vtblIFacePtr,
	                                                           aCol, aRow,
	                                                           &value__AutoType));

	if (value)
		__caErrChk (CA_BSTRGetCString (value__AutoType, value));

Error:
	CA_FreeBSTR (value__AutoType);
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	if (FAILED(__result))
		{
		if (value)
			{
			CA_FreeMemory (*value);
			*value = 0;
			}
		}
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXGetTopReport (CAObjHandle objectHandle,
                                                  ERRORINFO *errorInfo,
                                                  long *value)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	long value__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetTopReport_ (__vtblIFacePtr,
	                                                   &value__Temp));

	if (value)
		{
		*value = value__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXSetTopReport (CAObjHandle objectHandle,
                                                  ERRORINFO *errorInfo,
                                                  long value)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetTopReport_ (__vtblIFacePtr, value));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXGetPrintPage (CAObjHandle objectHandle,
                                                  ERRORINFO *errorInfo,
                                                  char **value)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	BSTR value__AutoType = 0;

	if (value)
		*value = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetPrintPage_ (__vtblIFacePtr,
	                                                   &value__AutoType));

	if (value)
		__caErrChk (CA_BSTRGetCString (value__AutoType, value));

Error:
	CA_FreeBSTR (value__AutoType);
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	if (FAILED(__result))
		{
		if (value)
			{
			CA_FreeMemory (*value);
			*value = 0;
			}
		}
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXSetPrintPage (CAObjHandle objectHandle,
                                                  ERRORINFO *errorInfo,
                                                  const char *value)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	BSTR value__AutoType = 0;

	__caErrChk (CA_CStringToBSTR (value, &value__AutoType));

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetPrintPage_ (__vtblIFacePtr,
	                                                   value__AutoType));

Error:
	CA_FreeBSTR (value__AutoType);
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXSetColHide (CAObjHandle objectHandle,
                                                ERRORINFO *errorInfo, long aCol,
                                                VBOOL aHide)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetColHide_ (__vtblIFacePtr, aCol,
	                                                 aHide));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXSetRowHide (CAObjHandle objectHandle,
                                                ERRORINFO *errorInfo, long aRow,
                                                VBOOL aHide)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetRowHide_ (__vtblIFacePtr, aRow,
	                                                 aHide));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXAddColTreeNode (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    long aLevel, long aCol1,
                                                    long aCol2)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->AddColTreeNode_ (__vtblIFacePtr,
	                                                     aLevel, aCol1, aCol2));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXAddRowTreeNode (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    long aLevel, long aRow1,
                                                    long aRow2)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->AddRowTreeNode_ (__vtblIFacePtr,
	                                                     aLevel, aRow1, aRow2));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXDelColTreeNode (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    long aCol1, long aCol2)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->DelColTreeNode_ (__vtblIFacePtr, aCol1,
	                                                     aCol2));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXDelRowTreeNode (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    long aRow1, long aRow2)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->DelRowTreeNode_ (__vtblIFacePtr, aRow1,
	                                                     aRow2));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXClearColTreeNode (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->ClearColTreeNode_ (__vtblIFacePtr));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXClearRowTreeNode (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->ClearRowTreeNode_ (__vtblIFacePtr));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXGetAllColTreeNode (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       long aLevel, char **value)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	BSTR value__AutoType = 0;

	if (value)
		*value = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetAllColTreeNode_ (__vtblIFacePtr,
	                                                        aLevel,
	                                                        &value__AutoType));

	if (value)
		__caErrChk (CA_BSTRGetCString (value__AutoType, value));

Error:
	CA_FreeBSTR (value__AutoType);
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	if (FAILED(__result))
		{
		if (value)
			{
			CA_FreeMemory (*value);
			*value = 0;
			}
		}
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXGetAllRowTreeNode (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       long aLevel, char **value)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	BSTR value__AutoType = 0;

	if (value)
		*value = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetAllRowTreeNode_ (__vtblIFacePtr,
	                                                        aLevel,
	                                                        &value__AutoType));

	if (value)
		__caErrChk (CA_BSTRGetCString (value__AutoType, value));

Error:
	CA_FreeBSTR (value__AutoType);
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	if (FAILED(__result))
		{
		if (value)
			{
			CA_FreeMemory (*value);
			*value = 0;
			}
		}
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXSetChartCell (CAObjHandle objectHandle,
                                                  ERRORINFO *errorInfo,
                                                  long aCol, long aRow,
                                                  const char *aTitleText,
                                                  const char *aHorizontalText,
                                                  const char *aVerticalText,
                                                  const char *aSeriesType,
                                                  const char *aSeriesSignText,
                                                  const char *aSeriesDataText)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	BSTR aTitleText__AutoType = 0;
	BSTR aHorizontalText__AutoType = 0;
	BSTR aVerticalText__AutoType = 0;
	BSTR aSeriesType__AutoType = 0;
	BSTR aSeriesSignText__AutoType = 0;
	BSTR aSeriesDataText__AutoType = 0;

	__caErrChk (CA_CStringToBSTR (aTitleText, &aTitleText__AutoType));
	__caErrChk (CA_CStringToBSTR (aHorizontalText, &aHorizontalText__AutoType));
	__caErrChk (CA_CStringToBSTR (aVerticalText, &aVerticalText__AutoType));
	__caErrChk (CA_CStringToBSTR (aSeriesType, &aSeriesType__AutoType));
	__caErrChk (CA_CStringToBSTR (aSeriesSignText, &aSeriesSignText__AutoType));
	__caErrChk (CA_CStringToBSTR (aSeriesDataText, &aSeriesDataText__AutoType));

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetChartCell_ (__vtblIFacePtr, aCol,
	                                                   aRow,
	                                                   aTitleText__AutoType,
	                                                   aHorizontalText__AutoType,
	                                                   aVerticalText__AutoType,
	                                                   aSeriesType__AutoType,
	                                                   aSeriesSignText__AutoType,
	                                                   aSeriesDataText__AutoType));

Error:
	CA_FreeBSTR (aTitleText__AutoType);
	CA_FreeBSTR (aHorizontalText__AutoType);
	CA_FreeBSTR (aVerticalText__AutoType);
	CA_FreeBSTR (aSeriesType__AutoType);
	CA_FreeBSTR (aSeriesSignText__AutoType);
	CA_FreeBSTR (aSeriesDataText__AutoType);
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXGetCellChart (CAObjHandle objectHandle,
                                                  ERRORINFO *errorInfo,
                                                  long aCol, long aRow,
                                                  char **value)
{
	HRESULT __result = S_OK;
	ReportProj1_IReportX_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	BSTR value__AutoType = 0;

	if (value)
		*value = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &ReportProj1_IID_IReportX, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetCellChart_ (__vtblIFacePtr, aCol,
	                                                   aRow, &value__AutoType));

	if (value)
		__caErrChk (CA_BSTRGetCString (value__AutoType, value));

Error:
	CA_FreeBSTR (value__AutoType);
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	if (FAILED(__result))
		{
		if (value)
			{
			CA_FreeMemory (*value);
			*value = 0;
			}
		}
	CA_FillErrorInfoEx (objectHandle, &ReportProj1_IID_IReportX, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

static void CVIFUNC IReportXEventsRegOnOnActivate_EventVTableFunc (void *thisPtr)
{
	HRESULT __result = S_OK;
	void * __callbackData;
	CAObjHandle __serverObjHandle;
	IReportXEventsRegOnOnActivate_CallbackType __callbackFunction;
	
	

	__caErrChk (CA_GetEventCallback (thisPtr, 0, &__callbackFunction,
	                                 &__callbackData, &__serverObjHandle));

	if (__callbackFunction != NULL)
		{
	
		__result = __callbackFunction (__serverObjHandle, __callbackData);
	
		__caErrChk (__result);
		
		}
Error:

	return;
}

static void CVIFUNC IReportXEventsRegOnOnClick_EventVTableFunc (void *thisPtr)
{
	HRESULT __result = S_OK;
	void * __callbackData;
	CAObjHandle __serverObjHandle;
	IReportXEventsRegOnOnClick_CallbackType __callbackFunction;
	
	

	__caErrChk (CA_GetEventCallback (thisPtr, 1, &__callbackFunction,
	                                 &__callbackData, &__serverObjHandle));

	if (__callbackFunction != NULL)
		{
	
		__result = __callbackFunction (__serverObjHandle, __callbackData);
	
		__caErrChk (__result);
		
		}
Error:

	return;
}

static void CVIFUNC IReportXEventsRegOnOnCreate_EventVTableFunc (void *thisPtr)
{
	HRESULT __result = S_OK;
	void * __callbackData;
	CAObjHandle __serverObjHandle;
	IReportXEventsRegOnOnCreate_CallbackType __callbackFunction;
	
	

	__caErrChk (CA_GetEventCallback (thisPtr, 2, &__callbackFunction,
	                                 &__callbackData, &__serverObjHandle));

	if (__callbackFunction != NULL)
		{
	
		__result = __callbackFunction (__serverObjHandle, __callbackData);
	
		__caErrChk (__result);
		
		}
Error:

	return;
}

static void CVIFUNC IReportXEventsRegOnOnDblClick_EventVTableFunc (void *thisPtr)
{
	HRESULT __result = S_OK;
	void * __callbackData;
	CAObjHandle __serverObjHandle;
	IReportXEventsRegOnOnDblClick_CallbackType __callbackFunction;
	
	

	__caErrChk (CA_GetEventCallback (thisPtr, 3, &__callbackFunction,
	                                 &__callbackData, &__serverObjHandle));

	if (__callbackFunction != NULL)
		{
	
		__result = __callbackFunction (__serverObjHandle, __callbackData);
	
		__caErrChk (__result);
		
		}
Error:

	return;
}

static void CVIFUNC IReportXEventsRegOnOnDestroy_EventVTableFunc (void *thisPtr)
{
	HRESULT __result = S_OK;
	void * __callbackData;
	CAObjHandle __serverObjHandle;
	IReportXEventsRegOnOnDestroy_CallbackType __callbackFunction;
	
	

	__caErrChk (CA_GetEventCallback (thisPtr, 4, &__callbackFunction,
	                                 &__callbackData, &__serverObjHandle));

	if (__callbackFunction != NULL)
		{
	
		__result = __callbackFunction (__serverObjHandle, __callbackData);
	
		__caErrChk (__result);
		
		}
Error:

	return;
}

static void CVIFUNC IReportXEventsRegOnOnDeactivate_EventVTableFunc (void *thisPtr)
{
	HRESULT __result = S_OK;
	void * __callbackData;
	CAObjHandle __serverObjHandle;
	IReportXEventsRegOnOnDeactivate_CallbackType __callbackFunction;
	
	

	__caErrChk (CA_GetEventCallback (thisPtr, 5, &__callbackFunction,
	                                 &__callbackData, &__serverObjHandle));

	if (__callbackFunction != NULL)
		{
	
		__result = __callbackFunction (__serverObjHandle, __callbackData);
	
		__caErrChk (__result);
		
		}
Error:

	return;
}

static void CVIFUNC IReportXEventsRegOnOnKeyPress_EventVTableFunc (void *thisPtr,
                                                                   short *key)
{
	HRESULT __result = S_OK;
	void * __callbackData;
	CAObjHandle __serverObjHandle;
	IReportXEventsRegOnOnKeyPress_CallbackType __callbackFunction;
	
	

	__caErrChk (CA_GetEventCallback (thisPtr, 6, &__callbackFunction,
	                                 &__callbackData, &__serverObjHandle));

	if (__callbackFunction != NULL)
		{
	
		__result = __callbackFunction (__serverObjHandle, __callbackData, key);
	
		__caErrChk (__result);
		
		}
Error:

	return;
}

static void CVIFUNC IReportXEventsRegOnOnPaint_EventVTableFunc (void *thisPtr)
{
	HRESULT __result = S_OK;
	void * __callbackData;
	CAObjHandle __serverObjHandle;
	IReportXEventsRegOnOnPaint_CallbackType __callbackFunction;
	
	

	__caErrChk (CA_GetEventCallback (thisPtr, 7, &__callbackFunction,
	                                 &__callbackData, &__serverObjHandle));

	if (__callbackFunction != NULL)
		{
	
		__result = __callbackFunction (__serverObjHandle, __callbackData);
	
		__caErrChk (__result);
		
		}
Error:

	return;
}

static long CVIFUNC IReportXEventsRegOnOnSelectChange_EventVTableFunc (void *thisPtr,
                                                                       long aCol1,
                                                                       long aRow1,
                                                                       long aCol2,
                                                                       long aRow2)
{
	HRESULT __result = S_OK;
	void * __callbackData;
	CAObjHandle __serverObjHandle;
	IReportXEventsRegOnOnSelectChange_CallbackType __callbackFunction;
	long __returnValue = 0;
	
	

	__caErrChk (CA_GetEventCallback (thisPtr, 8, &__callbackFunction,
	                                 &__callbackData, &__serverObjHandle));

	if (__callbackFunction != NULL)
		{
	
		__result = __callbackFunction (__serverObjHandle, __callbackData, aCol1, aRow1,
		                               aCol2, aRow2, &__returnValue);
	
		__caErrChk (__result);
		
		}
Error:

	return __returnValue;
}

static long CVIFUNC IReportXEventsRegOnOnInputChange_EventVTableFunc (void *thisPtr,
                                                                      long aCol,
                                                                      long aRow)
{
	HRESULT __result = S_OK;
	void * __callbackData;
	CAObjHandle __serverObjHandle;
	IReportXEventsRegOnOnInputChange_CallbackType __callbackFunction;
	long __returnValue = 0;
	
	

	__caErrChk (CA_GetEventCallback (thisPtr, 9, &__callbackFunction,
	                                 &__callbackData, &__serverObjHandle));

	if (__callbackFunction != NULL)
		{
	
		__result = __callbackFunction (__serverObjHandle, __callbackData, aCol, aRow,
		                               &__returnValue);
	
		__caErrChk (__result);
		
		}
Error:

	return __returnValue;
}

static long CVIFUNC IReportXEventsRegOnOnPoleLUp_EventVTableFunc (void *thisPtr,
                                                                  long aIndex,
                                                                  long aOrientation)
{
	HRESULT __result = S_OK;
	void * __callbackData;
	CAObjHandle __serverObjHandle;
	IReportXEventsRegOnOnPoleLUp_CallbackType __callbackFunction;
	long __returnValue = 0;
	
	

	__caErrChk (CA_GetEventCallback (thisPtr, 10, &__callbackFunction,
	                                 &__callbackData, &__serverObjHandle));

	if (__callbackFunction != NULL)
		{
	
		__result = __callbackFunction (__serverObjHandle, __callbackData, aIndex,
		                               aOrientation, &__returnValue);
	
		__caErrChk (__result);
		
		}
Error:

	return __returnValue;
}

static long CVIFUNC IReportXEventsRegOnOnPoleRDown_EventVTableFunc (void *thisPtr,
                                                                    long aIndex,
                                                                    long aOrientation,
                                                                    long aScreenX,
                                                                    long aScreenY)
{
	HRESULT __result = S_OK;
	void * __callbackData;
	CAObjHandle __serverObjHandle;
	IReportXEventsRegOnOnPoleRDown_CallbackType __callbackFunction;
	long __returnValue = 0;
	
	

	__caErrChk (CA_GetEventCallback (thisPtr, 11, &__callbackFunction,
	                                 &__callbackData, &__serverObjHandle));

	if (__callbackFunction != NULL)
		{
	
		__result = __callbackFunction (__serverObjHandle, __callbackData, aIndex,
		                               aOrientation, aScreenX, aScreenY, &__returnValue);
	
		__caErrChk (__result);
		
		}
Error:

	return __returnValue;
}

static long CVIFUNC IReportXEventsRegOnOnCellLUp_EventVTableFunc (void *thisPtr,
                                                                  long aCol,
                                                                  long aRow)
{
	HRESULT __result = S_OK;
	void * __callbackData;
	CAObjHandle __serverObjHandle;
	IReportXEventsRegOnOnCellLUp_CallbackType __callbackFunction;
	long __returnValue = 0;
	
	

	__caErrChk (CA_GetEventCallback (thisPtr, 12, &__callbackFunction,
	                                 &__callbackData, &__serverObjHandle));

	if (__callbackFunction != NULL)
		{
	
		__result = __callbackFunction (__serverObjHandle, __callbackData, aCol, aRow,
		                               &__returnValue);
	
		__caErrChk (__result);
		
		}
Error:

	return __returnValue;
}

static long CVIFUNC IReportXEventsRegOnOnCellRDown_EventVTableFunc (void *thisPtr,
                                                                    long aCol,
                                                                    long aRow,
                                                                    long aScreenX,
                                                                    long aScreenY)
{
	HRESULT __result = S_OK;
	void * __callbackData;
	CAObjHandle __serverObjHandle;
	IReportXEventsRegOnOnCellRDown_CallbackType __callbackFunction;
	long __returnValue = 0;
	
	

	__caErrChk (CA_GetEventCallback (thisPtr, 13, &__callbackFunction,
	                                 &__callbackData, &__serverObjHandle));

	if (__callbackFunction != NULL)
		{
	
		__result = __callbackFunction (__serverObjHandle, __callbackData, aCol, aRow,
		                               aScreenX, aScreenY, &__returnValue);
	
		__caErrChk (__result);
		
		}
Error:

	return __returnValue;
}

static long CVIFUNC IReportXEventsRegOnOnCellDblCLick_EventVTableFunc (void *thisPtr,
                                                                       long aCol,
                                                                       long aRow)
{
	HRESULT __result = S_OK;
	void * __callbackData;
	CAObjHandle __serverObjHandle;
	IReportXEventsRegOnOnCellDblCLick_CallbackType __callbackFunction;
	long __returnValue = 0;
	
	

	__caErrChk (CA_GetEventCallback (thisPtr, 14, &__callbackFunction,
	                                 &__callbackData, &__serverObjHandle));

	if (__callbackFunction != NULL)
		{
	
		__result = __callbackFunction (__serverObjHandle, __callbackData, aCol, aRow,
		                               &__returnValue);
	
		__caErrChk (__result);
		
		}
Error:

	return __returnValue;
}

static long CVIFUNC IReportXEventsRegOnOnCellChanged_EventVTableFunc (void *thisPtr,
                                                                      long aCol,
                                                                      long aRow,
                                                                      BSTR aCellValue)
{
	HRESULT __result = S_OK;
	void * __callbackData;
	CAObjHandle __serverObjHandle;
	IReportXEventsRegOnOnCellChanged_CallbackType __callbackFunction;
	long __returnValue = 0;
	char * aCellValue__CType = 0;
	
	

	__caErrChk (CA_GetEventCallback (thisPtr, 15, &__callbackFunction,
	                                 &__callbackData, &__serverObjHandle));

	if (__callbackFunction != NULL)
		{
		__caErrChk (CA_BSTRGetCString (aCellValue, &aCellValue__CType));
	
		__result = __callbackFunction (__serverObjHandle, __callbackData, aCol, aRow,
		                               aCellValue__CType, &__returnValue);
	
		__caErrChk (__result);
		
		}
Error:
	CA_FreeMemory (aCellValue__CType);

	return __returnValue;
}

static long CVIFUNC IReportXEventsRegOnOnCellChanging_EventVTableFunc (void *thisPtr,
                                                                       long aCol,
                                                                       long aRow,
                                                                       BSTR *cellValue,
                                                                       VBOOL *cellChange)
{
	HRESULT __result = S_OK;
	void * __callbackData;
	CAObjHandle __serverObjHandle;
	IReportXEventsRegOnOnCellChanging_CallbackType __callbackFunction;
	long __returnValue = 0;
	char * cellValue__CType = 0;
	BSTR cellValue__AutoType = 0;
	
	

	__caErrChk (CA_GetEventCallback (thisPtr, 16, &__callbackFunction,
	                                 &__callbackData, &__serverObjHandle));

	if (__callbackFunction != NULL)
		{
		__caErrChk (CA_BSTRGetCString (*cellValue, &cellValue__CType));
		CA_FreeBSTR (*cellValue);
		*cellValue = 0;
	
		__result = __callbackFunction (__serverObjHandle, __callbackData, aCol, aRow,
		                               &cellValue__CType, cellChange, &__returnValue);
	
		__caErrChk (__result);
	
		__caErrChk (CA_CStringToBSTR (cellValue__CType, &cellValue__AutoType));
		*cellValue = cellValue__AutoType;
		cellValue__AutoType = 0;
		}
Error:
	CA_FreeMemory (cellValue__CType);
	CA_FreeBSTR (cellValue__AutoType);

	return __returnValue;
}

static long CVIFUNC IReportXEventsRegOnOnLeftChange_EventVTableFunc (void *thisPtr,
                                                                     long aIndex)
{
	HRESULT __result = S_OK;
	void * __callbackData;
	CAObjHandle __serverObjHandle;
	IReportXEventsRegOnOnLeftChange_CallbackType __callbackFunction;
	long __returnValue = 0;
	
	

	__caErrChk (CA_GetEventCallback (thisPtr, 17, &__callbackFunction,
	                                 &__callbackData, &__serverObjHandle));

	if (__callbackFunction != NULL)
		{
	
		__result = __callbackFunction (__serverObjHandle, __callbackData, aIndex,
		                               &__returnValue);
	
		__caErrChk (__result);
		
		}
Error:

	return __returnValue;
}

static long CVIFUNC IReportXEventsRegOnOnTopChange_EventVTableFunc (void *thisPtr,
                                                                    long aIndex)
{
	HRESULT __result = S_OK;
	void * __callbackData;
	CAObjHandle __serverObjHandle;
	IReportXEventsRegOnOnTopChange_CallbackType __callbackFunction;
	long __returnValue = 0;
	
	

	__caErrChk (CA_GetEventCallback (thisPtr, 18, &__callbackFunction,
	                                 &__callbackData, &__serverObjHandle));

	if (__callbackFunction != NULL)
		{
	
		__result = __callbackFunction (__serverObjHandle, __callbackData, aIndex,
		                               &__returnValue);
	
		__caErrChk (__result);
		
		}
Error:

	return __returnValue;
}

static long CVIFUNC IReportXEventsRegOnOnError_EventVTableFunc (void *thisPtr,
                                                                BSTR aMessage)
{
	HRESULT __result = S_OK;
	void * __callbackData;
	CAObjHandle __serverObjHandle;
	IReportXEventsRegOnOnError_CallbackType __callbackFunction;
	long __returnValue = 0;
	char * aMessage__CType = 0;
	
	

	__caErrChk (CA_GetEventCallback (thisPtr, 19, &__callbackFunction,
	                                 &__callbackData, &__serverObjHandle));

	if (__callbackFunction != NULL)
		{
		__caErrChk (CA_BSTRGetCString (aMessage, &aMessage__CType));
	
		__result = __callbackFunction (__serverObjHandle, __callbackData,
		                               aMessage__CType, &__returnValue);
	
		__caErrChk (__result);
		
		}
Error:
	CA_FreeMemory (aMessage__CType);

	return __returnValue;
}

static long CVIFUNC IReportXEventsRegOnOnBeginPrintDoc_EventVTableFunc (void *thisPtr,
                                                                        long aPrinter,
                                                                        BSTR *title,
                                                                        VBOOL *titleChange)
{
	HRESULT __result = S_OK;
	void * __callbackData;
	CAObjHandle __serverObjHandle;
	IReportXEventsRegOnOnBeginPrintDoc_CallbackType __callbackFunction;
	long __returnValue = 0;
	char * title__CType = 0;
	BSTR title__AutoType = 0;
	
	

	__caErrChk (CA_GetEventCallback (thisPtr, 20, &__callbackFunction,
	                                 &__callbackData, &__serverObjHandle));

	if (__callbackFunction != NULL)
		{
		__caErrChk (CA_BSTRGetCString (*title, &title__CType));
		CA_FreeBSTR (*title);
		*title = 0;
	
		__result = __callbackFunction (__serverObjHandle, __callbackData, aPrinter,
		                               &title__CType, titleChange, &__returnValue);
	
		__caErrChk (__result);
	
		__caErrChk (CA_CStringToBSTR (title__CType, &title__AutoType));
		*title = title__AutoType;
		title__AutoType = 0;
		}
Error:
	CA_FreeMemory (title__CType);
	CA_FreeBSTR (title__AutoType);

	return __returnValue;
}

static long CVIFUNC IReportXEventsRegOnOnEndPrintDoc_EventVTableFunc (void *thisPtr,
                                                                      long aPrinter)
{
	HRESULT __result = S_OK;
	void * __callbackData;
	CAObjHandle __serverObjHandle;
	IReportXEventsRegOnOnEndPrintDoc_CallbackType __callbackFunction;
	long __returnValue = 0;
	
	

	__caErrChk (CA_GetEventCallback (thisPtr, 21, &__callbackFunction,
	                                 &__callbackData, &__serverObjHandle));

	if (__callbackFunction != NULL)
		{
	
		__result = __callbackFunction (__serverObjHandle, __callbackData, aPrinter,
		                               &__returnValue);
	
		__caErrChk (__result);
		
		}
Error:

	return __returnValue;
}

static long CVIFUNC IReportXEventsRegOnOnSelectObject_EventVTableFunc (void *thisPtr,
                                                                       long objectType,
                                                                       BSTR objectName)
{
	HRESULT __result = S_OK;
	void * __callbackData;
	CAObjHandle __serverObjHandle;
	IReportXEventsRegOnOnSelectObject_CallbackType __callbackFunction;
	long __returnValue = 0;
	char * objectName__CType = 0;
	
	

	__caErrChk (CA_GetEventCallback (thisPtr, 22, &__callbackFunction,
	                                 &__callbackData, &__serverObjHandle));

	if (__callbackFunction != NULL)
		{
		__caErrChk (CA_BSTRGetCString (objectName, &objectName__CType));
	
		__result = __callbackFunction (__serverObjHandle, __callbackData, objectType,
		                               objectName__CType, &__returnValue);
	
		__caErrChk (__result);
		
		}
Error:
	CA_FreeMemory (objectName__CType);

	return __returnValue;
}

static long CVIFUNC IReportXEventsRegOnOnObjectRDown_EventVTableFunc (void *thisPtr,
                                                                      long aObjectType,
                                                                      BSTR aObjectName,
                                                                      long aScreenX,
                                                                      long aScreenY)
{
	HRESULT __result = S_OK;
	void * __callbackData;
	CAObjHandle __serverObjHandle;
	IReportXEventsRegOnOnObjectRDown_CallbackType __callbackFunction;
	long __returnValue = 0;
	char * aObjectName__CType = 0;
	
	

	__caErrChk (CA_GetEventCallback (thisPtr, 23, &__callbackFunction,
	                                 &__callbackData, &__serverObjHandle));

	if (__callbackFunction != NULL)
		{
		__caErrChk (CA_BSTRGetCString (aObjectName, &aObjectName__CType));
	
		__result = __callbackFunction (__serverObjHandle, __callbackData, aObjectType,
		                               aObjectName__CType, aScreenX, aScreenY,
		                               &__returnValue);
	
		__caErrChk (__result);
		
		}
Error:
	CA_FreeMemory (aObjectName__CType);

	return __returnValue;
}

static long CVIFUNC IReportXEventsRegOnOnButtonClick_EventVTableFunc (void *thisPtr,
                                                                      long aCol,
                                                                      long aRow,
                                                                      BSTR aButtonText,
                                                                      BSTR *buttonScript)
{
	HRESULT __result = S_OK;
	void * __callbackData;
	CAObjHandle __serverObjHandle;
	IReportXEventsRegOnOnButtonClick_CallbackType __callbackFunction;
	long __returnValue = 0;
	char * aButtonText__CType = 0;
	char * buttonScript__CType = 0;
	BSTR buttonScript__AutoType = 0;
	
	

	__caErrChk (CA_GetEventCallback (thisPtr, 24, &__callbackFunction,
	                                 &__callbackData, &__serverObjHandle));

	if (__callbackFunction != NULL)
		{
		__caErrChk (CA_BSTRGetCString (aButtonText, &aButtonText__CType));
		__caErrChk (CA_BSTRGetCString (*buttonScript, &buttonScript__CType));
		CA_FreeBSTR (*buttonScript);
		*buttonScript = 0;
	
		__result = __callbackFunction (__serverObjHandle, __callbackData, aCol, aRow,
		                               aButtonText__CType, &buttonScript__CType,
		                               &__returnValue);
	
		__caErrChk (__result);
	
		__caErrChk (CA_CStringToBSTR (buttonScript__CType, &buttonScript__AutoType));
		*buttonScript = buttonScript__AutoType;
		buttonScript__AutoType = 0;
		}
Error:
	CA_FreeMemory (aButtonText__CType);
	CA_FreeMemory (buttonScript__CType);
	CA_FreeBSTR (buttonScript__AutoType);

	return __returnValue;
}

static long CVIFUNC IReportXEventsRegOnOnAdjustedSeries_EventVTableFunc (void *thisPtr,
                                                                         BSTR aChartName,
                                                                         long aIndex,
                                                                         long aSeriesType,
                                                                         BSTR aSeriesSignText,
                                                                         BSTR aSeriesDataText,
                                                                         BSTR aSeriesCell)
{
	HRESULT __result = S_OK;
	void * __callbackData;
	CAObjHandle __serverObjHandle;
	IReportXEventsRegOnOnAdjustedSeries_CallbackType __callbackFunction;
	long __returnValue = 0;
	char * aChartName__CType = 0;
	char * aSeriesSignText__CType = 0;
	char * aSeriesDataText__CType = 0;
	char * aSeriesCell__CType = 0;
	
	

	__caErrChk (CA_GetEventCallback (thisPtr, 25, &__callbackFunction,
	                                 &__callbackData, &__serverObjHandle));

	if (__callbackFunction != NULL)
		{
		__caErrChk (CA_BSTRGetCString (aChartName, &aChartName__CType));
		__caErrChk (CA_BSTRGetCString (aSeriesSignText, &aSeriesSignText__CType));
		__caErrChk (CA_BSTRGetCString (aSeriesDataText, &aSeriesDataText__CType));
		__caErrChk (CA_BSTRGetCString (aSeriesCell, &aSeriesCell__CType));
	
		__result = __callbackFunction (__serverObjHandle, __callbackData,
		                               aChartName__CType, aIndex, aSeriesType,
		                               aSeriesSignText__CType, aSeriesDataText__CType,
		                               aSeriesCell__CType, &__returnValue);
	
		__caErrChk (__result);
		
		}
Error:
	CA_FreeMemory (aChartName__CType);
	CA_FreeMemory (aSeriesSignText__CType);
	CA_FreeMemory (aSeriesDataText__CType);
	CA_FreeMemory (aSeriesCell__CType);

	return __returnValue;
}

static long CVIFUNC IReportXEventsRegOnOnDropDown_EventVTableFunc (void *thisPtr,
                                                                   long aCol,
                                                                   long aRow,
                                                                   BSTR *listText)
{
	HRESULT __result = S_OK;
	void * __callbackData;
	CAObjHandle __serverObjHandle;
	IReportXEventsRegOnOnDropDown_CallbackType __callbackFunction;
	long __returnValue = 0;
	char * listText__CType = 0;
	BSTR listText__AutoType = 0;
	
	

	__caErrChk (CA_GetEventCallback (thisPtr, 26, &__callbackFunction,
	                                 &__callbackData, &__serverObjHandle));

	if (__callbackFunction != NULL)
		{
		__caErrChk (CA_BSTRGetCString (*listText, &listText__CType));
		CA_FreeBSTR (*listText);
		*listText = 0;
	
		__result = __callbackFunction (__serverObjHandle, __callbackData, aCol, aRow,
		                               &listText__CType, &__returnValue);
	
		__caErrChk (__result);
	
		__caErrChk (CA_CStringToBSTR (listText__CType, &listText__AutoType));
		*listText = listText__AutoType;
		listText__AutoType = 0;
		}
Error:
	CA_FreeMemory (listText__CType);
	CA_FreeBSTR (listText__AutoType);

	return __returnValue;
}

static long CVIFUNC IReportXEventsRegOnOnCellLDown_EventVTableFunc (void *thisPtr,
                                                                    long aCol,
                                                                    long aRow)
{
	HRESULT __result = S_OK;
	void * __callbackData;
	CAObjHandle __serverObjHandle;
	IReportXEventsRegOnOnCellLDown_CallbackType __callbackFunction;
	long __returnValue = 0;
	
	

	__caErrChk (CA_GetEventCallback (thisPtr, 27, &__callbackFunction,
	                                 &__callbackData, &__serverObjHandle));

	if (__callbackFunction != NULL)
		{
	
		__result = __callbackFunction (__serverObjHandle, __callbackData, aCol, aRow,
		                               &__returnValue);
	
		__caErrChk (__result);
		
		}
Error:

	return __returnValue;
}

static long CVIFUNC IReportXEventsRegOnOnPoleLDown_EventVTableFunc (void *thisPtr,
                                                                    long aIndex,
                                                                    long aOrientation)
{
	HRESULT __result = S_OK;
	void * __callbackData;
	CAObjHandle __serverObjHandle;
	IReportXEventsRegOnOnPoleLDown_CallbackType __callbackFunction;
	long __returnValue = 0;
	
	

	__caErrChk (CA_GetEventCallback (thisPtr, 28, &__callbackFunction,
	                                 &__callbackData, &__serverObjHandle));

	if (__callbackFunction != NULL)
		{
	
		__result = __callbackFunction (__serverObjHandle, __callbackData, aIndex,
		                               aOrientation, &__returnValue);
	
		__caErrChk (__result);
		
		}
Error:

	return __returnValue;
}

static long CVIFUNC IReportXEventsRegOnOnPreviewShow_EventVTableFunc (void *thisPtr,
                                                                      long aPrinter,
                                                                      BSTR *previewParameter,
                                                                      VBOOL *previewChange)
{
	HRESULT __result = S_OK;
	void * __callbackData;
	CAObjHandle __serverObjHandle;
	IReportXEventsRegOnOnPreviewShow_CallbackType __callbackFunction;
	long __returnValue = 0;
	char * previewParameter__CType = 0;
	BSTR previewParameter__AutoType = 0;
	
	

	__caErrChk (CA_GetEventCallback (thisPtr, 29, &__callbackFunction,
	                                 &__callbackData, &__serverObjHandle));

	if (__callbackFunction != NULL)
		{
		__caErrChk (CA_BSTRGetCString (*previewParameter, &previewParameter__CType));
		CA_FreeBSTR (*previewParameter);
		*previewParameter = 0;
	
		__result = __callbackFunction (__serverObjHandle, __callbackData, aPrinter,
		                               &previewParameter__CType, previewChange,
		                               &__returnValue);
	
		__caErrChk (__result);
	
		__caErrChk (CA_CStringToBSTR (previewParameter__CType,
		                              &previewParameter__AutoType));
		*previewParameter = previewParameter__AutoType;
		previewParameter__AutoType = 0;
		}
Error:
	CA_FreeMemory (previewParameter__CType);
	CA_FreeBSTR (previewParameter__AutoType);

	return __returnValue;
}

HRESULT CVIFUNC ReportProj1_IReportXEventsRegOnOnActivate (CAObjHandle serverObject,
                                                           IReportXEventsRegOnOnActivate_CallbackType callbackFunction,
                                                           void *callbackData,
                                                           int enableCallbacks,
                                                           int *callbackId)
{
	HRESULT __result = S_OK;

	__result = CA_RegisterEventCallback (serverObject,
	                                     &_IReportXEvents_CAEventClassDefn, 0,
	                                     callbackFunction, callbackData,
	                                     enableCallbacks, callbackId);

	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXEventsRegOnOnClick (CAObjHandle serverObject,
                                                        IReportXEventsRegOnOnClick_CallbackType callbackFunction,
                                                        void *callbackData,
                                                        int enableCallbacks,
                                                        int *callbackId)
{
	HRESULT __result = S_OK;

	__result = CA_RegisterEventCallback (serverObject,
	                                     &_IReportXEvents_CAEventClassDefn, 1,
	                                     callbackFunction, callbackData,
	                                     enableCallbacks, callbackId);

	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXEventsRegOnOnCreate (CAObjHandle serverObject,
                                                         IReportXEventsRegOnOnCreate_CallbackType callbackFunction,
                                                         void *callbackData,
                                                         int enableCallbacks,
                                                         int *callbackId)
{
	HRESULT __result = S_OK;

	__result = CA_RegisterEventCallback (serverObject,
	                                     &_IReportXEvents_CAEventClassDefn, 2,
	                                     callbackFunction, callbackData,
	                                     enableCallbacks, callbackId);

	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXEventsRegOnOnDblClick (CAObjHandle serverObject,
                                                           IReportXEventsRegOnOnDblClick_CallbackType callbackFunction,
                                                           void *callbackData,
                                                           int enableCallbacks,
                                                           int *callbackId)
{
	HRESULT __result = S_OK;

	__result = CA_RegisterEventCallback (serverObject,
	                                     &_IReportXEvents_CAEventClassDefn, 3,
	                                     callbackFunction, callbackData,
	                                     enableCallbacks, callbackId);

	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXEventsRegOnOnDestroy (CAObjHandle serverObject,
                                                          IReportXEventsRegOnOnDestroy_CallbackType callbackFunction,
                                                          void *callbackData,
                                                          int enableCallbacks,
                                                          int *callbackId)
{
	HRESULT __result = S_OK;

	__result = CA_RegisterEventCallback (serverObject,
	                                     &_IReportXEvents_CAEventClassDefn, 4,
	                                     callbackFunction, callbackData,
	                                     enableCallbacks, callbackId);

	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXEventsRegOnOnDeactivate (CAObjHandle serverObject,
                                                             IReportXEventsRegOnOnDeactivate_CallbackType callbackFunction,
                                                             void *callbackData,
                                                             int enableCallbacks,
                                                             int *callbackId)
{
	HRESULT __result = S_OK;

	__result = CA_RegisterEventCallback (serverObject,
	                                     &_IReportXEvents_CAEventClassDefn, 5,
	                                     callbackFunction, callbackData,
	                                     enableCallbacks, callbackId);

	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXEventsRegOnOnKeyPress (CAObjHandle serverObject,
                                                           IReportXEventsRegOnOnKeyPress_CallbackType callbackFunction,
                                                           void *callbackData,
                                                           int enableCallbacks,
                                                           int *callbackId)
{
	HRESULT __result = S_OK;

	__result = CA_RegisterEventCallback (serverObject,
	                                     &_IReportXEvents_CAEventClassDefn, 6,
	                                     callbackFunction, callbackData,
	                                     enableCallbacks, callbackId);

	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXEventsRegOnOnPaint (CAObjHandle serverObject,
                                                        IReportXEventsRegOnOnPaint_CallbackType callbackFunction,
                                                        void *callbackData,
                                                        int enableCallbacks,
                                                        int *callbackId)
{
	HRESULT __result = S_OK;

	__result = CA_RegisterEventCallback (serverObject,
	                                     &_IReportXEvents_CAEventClassDefn, 7,
	                                     callbackFunction, callbackData,
	                                     enableCallbacks, callbackId);

	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXEventsRegOnOnSelectChange (CAObjHandle serverObject,
                                                               IReportXEventsRegOnOnSelectChange_CallbackType callbackFunction,
                                                               void *callbackData,
                                                               int enableCallbacks,
                                                               int *callbackId)
{
	HRESULT __result = S_OK;

	__result = CA_RegisterEventCallback (serverObject,
	                                     &_IReportXEvents_CAEventClassDefn, 8,
	                                     callbackFunction, callbackData,
	                                     enableCallbacks, callbackId);

	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXEventsRegOnOnInputChange (CAObjHandle serverObject,
                                                              IReportXEventsRegOnOnInputChange_CallbackType callbackFunction,
                                                              void *callbackData,
                                                              int enableCallbacks,
                                                              int *callbackId)
{
	HRESULT __result = S_OK;

	__result = CA_RegisterEventCallback (serverObject,
	                                     &_IReportXEvents_CAEventClassDefn, 9,
	                                     callbackFunction, callbackData,
	                                     enableCallbacks, callbackId);

	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXEventsRegOnOnPoleLUp (CAObjHandle serverObject,
                                                          IReportXEventsRegOnOnPoleLUp_CallbackType callbackFunction,
                                                          void *callbackData,
                                                          int enableCallbacks,
                                                          int *callbackId)
{
	HRESULT __result = S_OK;

	__result = CA_RegisterEventCallback (serverObject,
	                                     &_IReportXEvents_CAEventClassDefn, 10,
	                                     callbackFunction, callbackData,
	                                     enableCallbacks, callbackId);

	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXEventsRegOnOnPoleRDown (CAObjHandle serverObject,
                                                            IReportXEventsRegOnOnPoleRDown_CallbackType callbackFunction,
                                                            void *callbackData,
                                                            int enableCallbacks,
                                                            int *callbackId)
{
	HRESULT __result = S_OK;

	__result = CA_RegisterEventCallback (serverObject,
	                                     &_IReportXEvents_CAEventClassDefn, 11,
	                                     callbackFunction, callbackData,
	                                     enableCallbacks, callbackId);

	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXEventsRegOnOnCellLUp (CAObjHandle serverObject,
                                                          IReportXEventsRegOnOnCellLUp_CallbackType callbackFunction,
                                                          void *callbackData,
                                                          int enableCallbacks,
                                                          int *callbackId)
{
	HRESULT __result = S_OK;

	__result = CA_RegisterEventCallback (serverObject,
	                                     &_IReportXEvents_CAEventClassDefn, 12,
	                                     callbackFunction, callbackData,
	                                     enableCallbacks, callbackId);

	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXEventsRegOnOnCellRDown (CAObjHandle serverObject,
                                                            IReportXEventsRegOnOnCellRDown_CallbackType callbackFunction,
                                                            void *callbackData,
                                                            int enableCallbacks,
                                                            int *callbackId)
{
	HRESULT __result = S_OK;

	__result = CA_RegisterEventCallback (serverObject,
	                                     &_IReportXEvents_CAEventClassDefn, 13,
	                                     callbackFunction, callbackData,
	                                     enableCallbacks, callbackId);

	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXEventsRegOnOnCellDblCLick (CAObjHandle serverObject,
                                                               IReportXEventsRegOnOnCellDblCLick_CallbackType callbackFunction,
                                                               void *callbackData,
                                                               int enableCallbacks,
                                                               int *callbackId)
{
	HRESULT __result = S_OK;

	__result = CA_RegisterEventCallback (serverObject,
	                                     &_IReportXEvents_CAEventClassDefn, 14,
	                                     callbackFunction, callbackData,
	                                     enableCallbacks, callbackId);

	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXEventsRegOnOnCellChanged (CAObjHandle serverObject,
                                                              IReportXEventsRegOnOnCellChanged_CallbackType callbackFunction,
                                                              void *callbackData,
                                                              int enableCallbacks,
                                                              int *callbackId)
{
	HRESULT __result = S_OK;

	__result = CA_RegisterEventCallback (serverObject,
	                                     &_IReportXEvents_CAEventClassDefn, 15,
	                                     callbackFunction, callbackData,
	                                     enableCallbacks, callbackId);

	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXEventsRegOnOnCellChanging (CAObjHandle serverObject,
                                                               IReportXEventsRegOnOnCellChanging_CallbackType callbackFunction,
                                                               void *callbackData,
                                                               int enableCallbacks,
                                                               int *callbackId)
{
	HRESULT __result = S_OK;

	__result = CA_RegisterEventCallback (serverObject,
	                                     &_IReportXEvents_CAEventClassDefn, 16,
	                                     callbackFunction, callbackData,
	                                     enableCallbacks, callbackId);

	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXEventsRegOnOnLeftChange (CAObjHandle serverObject,
                                                             IReportXEventsRegOnOnLeftChange_CallbackType callbackFunction,
                                                             void *callbackData,
                                                             int enableCallbacks,
                                                             int *callbackId)
{
	HRESULT __result = S_OK;

	__result = CA_RegisterEventCallback (serverObject,
	                                     &_IReportXEvents_CAEventClassDefn, 17,
	                                     callbackFunction, callbackData,
	                                     enableCallbacks, callbackId);

	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXEventsRegOnOnTopChange (CAObjHandle serverObject,
                                                            IReportXEventsRegOnOnTopChange_CallbackType callbackFunction,
                                                            void *callbackData,
                                                            int enableCallbacks,
                                                            int *callbackId)
{
	HRESULT __result = S_OK;

	__result = CA_RegisterEventCallback (serverObject,
	                                     &_IReportXEvents_CAEventClassDefn, 18,
	                                     callbackFunction, callbackData,
	                                     enableCallbacks, callbackId);

	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXEventsRegOnOnError (CAObjHandle serverObject,
                                                        IReportXEventsRegOnOnError_CallbackType callbackFunction,
                                                        void *callbackData,
                                                        int enableCallbacks,
                                                        int *callbackId)
{
	HRESULT __result = S_OK;

	__result = CA_RegisterEventCallback (serverObject,
	                                     &_IReportXEvents_CAEventClassDefn, 19,
	                                     callbackFunction, callbackData,
	                                     enableCallbacks, callbackId);

	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXEventsRegOnOnBeginPrintDoc (CAObjHandle serverObject,
                                                                IReportXEventsRegOnOnBeginPrintDoc_CallbackType callbackFunction,
                                                                void *callbackData,
                                                                int enableCallbacks,
                                                                int *callbackId)
{
	HRESULT __result = S_OK;

	__result = CA_RegisterEventCallback (serverObject,
	                                     &_IReportXEvents_CAEventClassDefn, 20,
	                                     callbackFunction, callbackData,
	                                     enableCallbacks, callbackId);

	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXEventsRegOnOnEndPrintDoc (CAObjHandle serverObject,
                                                              IReportXEventsRegOnOnEndPrintDoc_CallbackType callbackFunction,
                                                              void *callbackData,
                                                              int enableCallbacks,
                                                              int *callbackId)
{
	HRESULT __result = S_OK;

	__result = CA_RegisterEventCallback (serverObject,
	                                     &_IReportXEvents_CAEventClassDefn, 21,
	                                     callbackFunction, callbackData,
	                                     enableCallbacks, callbackId);

	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXEventsRegOnOnSelectObject (CAObjHandle serverObject,
                                                               IReportXEventsRegOnOnSelectObject_CallbackType callbackFunction,
                                                               void *callbackData,
                                                               int enableCallbacks,
                                                               int *callbackId)
{
	HRESULT __result = S_OK;

	__result = CA_RegisterEventCallback (serverObject,
	                                     &_IReportXEvents_CAEventClassDefn, 22,
	                                     callbackFunction, callbackData,
	                                     enableCallbacks, callbackId);

	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXEventsRegOnOnObjectRDown (CAObjHandle serverObject,
                                                              IReportXEventsRegOnOnObjectRDown_CallbackType callbackFunction,
                                                              void *callbackData,
                                                              int enableCallbacks,
                                                              int *callbackId)
{
	HRESULT __result = S_OK;

	__result = CA_RegisterEventCallback (serverObject,
	                                     &_IReportXEvents_CAEventClassDefn, 23,
	                                     callbackFunction, callbackData,
	                                     enableCallbacks, callbackId);

	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXEventsRegOnOnButtonClick (CAObjHandle serverObject,
                                                              IReportXEventsRegOnOnButtonClick_CallbackType callbackFunction,
                                                              void *callbackData,
                                                              int enableCallbacks,
                                                              int *callbackId)
{
	HRESULT __result = S_OK;

	__result = CA_RegisterEventCallback (serverObject,
	                                     &_IReportXEvents_CAEventClassDefn, 24,
	                                     callbackFunction, callbackData,
	                                     enableCallbacks, callbackId);

	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXEventsRegOnOnAdjustedSeries (CAObjHandle serverObject,
                                                                 IReportXEventsRegOnOnAdjustedSeries_CallbackType callbackFunction,
                                                                 void *callbackData,
                                                                 int enableCallbacks,
                                                                 int *callbackId)
{
	HRESULT __result = S_OK;

	__result = CA_RegisterEventCallback (serverObject,
	                                     &_IReportXEvents_CAEventClassDefn, 25,
	                                     callbackFunction, callbackData,
	                                     enableCallbacks, callbackId);

	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXEventsRegOnOnDropDown (CAObjHandle serverObject,
                                                           IReportXEventsRegOnOnDropDown_CallbackType callbackFunction,
                                                           void *callbackData,
                                                           int enableCallbacks,
                                                           int *callbackId)
{
	HRESULT __result = S_OK;

	__result = CA_RegisterEventCallback (serverObject,
	                                     &_IReportXEvents_CAEventClassDefn, 26,
	                                     callbackFunction, callbackData,
	                                     enableCallbacks, callbackId);

	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXEventsRegOnOnCellLDown (CAObjHandle serverObject,
                                                            IReportXEventsRegOnOnCellLDown_CallbackType callbackFunction,
                                                            void *callbackData,
                                                            int enableCallbacks,
                                                            int *callbackId)
{
	HRESULT __result = S_OK;

	__result = CA_RegisterEventCallback (serverObject,
	                                     &_IReportXEvents_CAEventClassDefn, 27,
	                                     callbackFunction, callbackData,
	                                     enableCallbacks, callbackId);

	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXEventsRegOnOnPoleLDown (CAObjHandle serverObject,
                                                            IReportXEventsRegOnOnPoleLDown_CallbackType callbackFunction,
                                                            void *callbackData,
                                                            int enableCallbacks,
                                                            int *callbackId)
{
	HRESULT __result = S_OK;

	__result = CA_RegisterEventCallback (serverObject,
	                                     &_IReportXEvents_CAEventClassDefn, 28,
	                                     callbackFunction, callbackData,
	                                     enableCallbacks, callbackId);

	return __result;
}

HRESULT CVIFUNC ReportProj1_IReportXEventsRegOnOnPreviewShow (CAObjHandle serverObject,
                                                              IReportXEventsRegOnOnPreviewShow_CallbackType callbackFunction,
                                                              void *callbackData,
                                                              int enableCallbacks,
                                                              int *callbackId)
{
	HRESULT __result = S_OK;

	__result = CA_RegisterEventCallback (serverObject,
	                                     &_IReportXEvents_CAEventClassDefn, 29,
	                                     callbackFunction, callbackData,
	                                     enableCallbacks, callbackId);

	return __result;
}
