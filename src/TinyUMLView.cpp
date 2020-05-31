// TinyUMLView.cpp : implementation of the CTinyUMLView class
//

#include "stdafx.h"
#include "TinyUML.h"

#include "MainFrm.h"
#include "TinyUMLDoc.h"
#include "TinyUMLView.h"

#include "TinyUMLClipboardManager.h"

#include "TinyUMLClass.h"
#include "TinyUMLClassController.h"
#include "TinyUMLGeneralization.h"
#include "TinyUMLGeneralizationController.h"
#include "TinyUMLNote.h"
#include "TinyUMLPackage.h"
#include "TinyUMLPackageController.h"
#include "TinyUMLAssociation.h"
#include "TinyUMLAssociationController.h"
#include "TinyUMLDependency.h"
#include "TinyUMLDependencyController.h"

#include "ThemePropSheet.h"
#include "GeneralThemePropertyPage.h"
#include "ClassThemePropertyPage.h"
#include "NoteThemePropertyPage.h"
#include "PackageThemePropertyPage.h"
#include "RelationThemePropertyPage.h"

#include "ClassParser/FileContext.h"
#include "ClassParser/ClassContext.h"
#include "ClassParser/MethodContext.h"
#include "ClassParser/MemberContext.h"
#include "TinyUMLTheme.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTinyUMLView

IMPLEMENT_DYNCREATE(CTinyUMLView, CView)

BEGIN_MESSAGE_MAP(CTinyUMLView, CView)
	//{{AFX_MSG_MAP(CTinyUMLView)
	ON_COMMAND(ID_TOOL_CLASS, OnToolClass)
	ON_WM_SIZE()
	ON_WM_ERASEBKGND()
	ON_COMMAND(ID_EDIT_UNDO, OnUndo)
	ON_UPDATE_COMMAND_UI(ID_EDIT_UNDO, OnUpdateUndo)
	ON_UPDATE_COMMAND_UI(ID_EDIT_REDO, OnUpdateRedo)
	ON_COMMAND(ID_EDIT_REDO, OnRedo)
	ON_COMMAND(ID_TOOL_GENERALIZATION, OnToolGeneralization)
	ON_COMMAND(ID_TOOL_SELECT, OnToolSelect)
	ON_UPDATE_COMMAND_UI(ID_TOOL_CLASS, OnUpdateToolClass)
	ON_UPDATE_COMMAND_UI(ID_TOOL_SELECT, OnUpdateToolSelect)
	ON_UPDATE_COMMAND_UI(ID_TOOL_GENERALIZATION, OnUpdateToolGeneralization)
	ON_COMMAND(ID_TOOL_NOTE, OnToolNote)
	ON_UPDATE_COMMAND_UI(ID_TOOL_NOTE, OnUpdateToolNote)
	ON_COMMAND(ID_TOOL_PACKAGE, OnToolPackage)
	ON_UPDATE_COMMAND_UI(ID_TOOL_PACKAGE, OnUpdateToolPackage)
	ON_COMMAND(ID_TOOL_REALIZE, OnToolRealize)
	ON_COMMAND(ID_TOOL_INTERFACE, OnToolInterface)
	ON_UPDATE_COMMAND_UI(ID_TOOL_INTERFACE, OnUpdateToolInterface)
	ON_COMMAND(ID_TOOL_ASSOCIATION1, OnToolAssociation1)
	ON_UPDATE_COMMAND_UI(ID_TOOL_ASSOCIATION1, OnUpdateToolAssociation1)
	ON_COMMAND(ID_TOOL_ASSOCIATION2, OnToolAssociation2)
	ON_UPDATE_COMMAND_UI(ID_TOOL_ASSOCIATION2, OnUpdateToolAssociation2)
	ON_COMMAND(ID_TOOL_ASSOCIATION3, OnToolAssociation3)
	ON_UPDATE_COMMAND_UI(ID_TOOL_ASSOCIATION3, OnUpdateToolAssociation3)
	ON_COMMAND(ID_TOOL_DEPENDENCY, OnToolDependency)
	ON_UPDATE_COMMAND_UI(ID_TOOL_DEPENDENCY, OnUpdateToolDependency)
	ON_COMMAND(ID_VIEWGRID, OnViewgrid)
	ON_UPDATE_COMMAND_UI(ID_VIEWGRID, OnUpdateViewgrid)
	ON_COMMAND(ID_VIEWMIN, OnViewmin)
	ON_UPDATE_COMMAND_UI(ID_VIEWMIN, OnUpdateViewmin)
	ON_COMMAND(ID_VIEWNORMAL, OnViewnormal)
	ON_UPDATE_COMMAND_UI(ID_VIEWNORMAL, OnUpdateViewnormal)
	ON_COMMAND(ID_VIEWMAX, OnViewmax)
	ON_UPDATE_COMMAND_UI(ID_VIEWMAX, OnUpdateViewmax)
	ON_COMMAND(ID_VIEW_LOCK, OnViewLock)
	ON_UPDATE_COMMAND_UI(ID_VIEW_LOCK, OnUpdateViewLock)
	ON_COMMAND(ID_EDIT_PROPERTIES, OnEditProperties)
	ON_UPDATE_COMMAND_UI(ID_EDIT_PROPERTIES, OnUpdateEditProperties)
	ON_COMMAND(ID_EDIT_THEME, OnEditTheme)
	ON_COMMAND(ID_SAVE_THEME, OnSaveTheme)
	ON_COMMAND(ID_LOAD_THEME, OnLoadTheme)
	ON_COMMAND(ID_TOOL_LABEL, OnToolLabel)
	ON_COMMAND(ID_EDIT_COPY, OnEditCopy)
	ON_COMMAND(ID_EDIT_PASTE, OnEditPaste)
	ON_UPDATE_COMMAND_UI(ID_TOOL_REALIZE, OnUpdateToolRealize)
	ON_COMMAND(ID_FILE_PURGE, OnFilePurge)
	ON_COMMAND(ID_ARRANGE_BRING_TO_FRONT, OnArrangeBringToFront)
	ON_COMMAND(ID_ARRANGE_SEND_TO_BACK, OnArrangeSendToBack)
	ON_COMMAND(ID_FILE_READSOURCE, OnFileReadsource)
	ON_UPDATE_COMMAND_UI(ID_TOOL_LABEL, OnUpdateToolLabel)
	ON_COMMAND(ID_DRAW_TOOL_LINE, OnDrawToolLine)
	ON_UPDATE_COMMAND_UI(ID_DRAW_TOOL_LINE, OnUpdateDrawToolLine)
	ON_COMMAND(ID_DRAW_TOOL_RECT, OnDrawToolRect)
	ON_UPDATE_COMMAND_UI(ID_DRAW_TOOL_RECT, OnUpdateDrawToolRect)
	ON_COMMAND(ID_DRAW_TOOL_ELLIPSE, OnDrawToolEllipse)
	ON_UPDATE_COMMAND_UI(ID_DRAW_TOOL_ELLIPSE, OnUpdateDrawToolEllipse)
	ON_COMMAND(ID_DRAW_TOOL_ARC, OnDrawToolArc)
	ON_UPDATE_COMMAND_UI(ID_DRAW_TOOL_ARC, OnUpdateDrawToolArc)
	//}}AFX_MSG_MAP
	ON_WM_CONTEXTMENU()
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, OnFilePrintPreview)
	ON_CBN_SELENDOK(ID_SCALE_COMBO, OnScaleSelect)
	ON_CBN_EDITCHANGE(ID_SCALE_COMBO,OnScaleSelect)
	ON_CBN_SELENDOK(ID_DRAWING_LINE_COLOR , OnDrawingLineColor)
	ON_CBN_EDITCHANGE(ID_DRAWING_LINE_COLOR , OnDrawingLineColor)
	ON_CBN_SELENDOK(ID_DRAWING_LINE_STYLE , OnDrawingLineStyle)
	ON_CBN_EDITCHANGE(ID_DRAWING_LINE_STYLE , OnDrawingLineStyle)
	ON_CBN_SELENDOK(ID_DRAWING_LINE_WEIGHT , OnDrawingLineWeight)
	ON_CBN_EDITCHANGE(ID_DRAWING_LINE_WEIGHT , OnDrawingLineWeight)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTinyUMLView construction/destruction

/**
 * CTinyUMLView:
 *
 * @return  
 */
CTinyUMLView::CTinyUMLView()
{
	m_pTyUMLEditor = NULL;

	m_pDrawLineFactory	= static_cast<CIsDrawLineFactory*>(CIsDrawLineFactory::CreateInstance());
	m_pDrawRectFactory	= static_cast<CIsDrawRectFactory*>(CIsDrawRectFactory::CreateInstance());
	m_pDrawEllipseFactory	= static_cast<CIsDrawEllipseFactory*>(CIsDrawEllipseFactory::CreateInstance());
	m_pDrawArcFactory	= static_cast<CIsDrawArcFactory*>(CIsDrawArcFactory::CreateInstance());

	m_pLabelFactory = new CTinyUMLLabelFactory;
	m_pClassFactory = new CTinyUMLClassFactory(false);
	m_pInterfaceFactory = new CTinyUMLClassFactory(true);
	m_pNoteFactory = new CTinyUMLNoteController;
	m_pRealizeFactory = new CTinyUMLGeneralizationController;
	m_pRealizeFactory->m_bRealize = true;

	m_pAssociation1Factory = new CTinyUMLAssociationFactory(false, true);
	m_pAssociation2Factory = new CTinyUMLAssociationFactory(false, false);
	m_pAssociation3Factory = new CTinyUMLAssociationFactory(true, false);
}

/**
 * ~CTinyUMLView:
 *
 * @return  
 */
CTinyUMLView::~CTinyUMLView()
{
	try
	{
		if(NULL != m_pTyUMLEditor) delete m_pTyUMLEditor;
		if(NULL != m_pLabelFactory) delete m_pLabelFactory;
		if(NULL != m_pClassFactory) delete m_pClassFactory;
		if(NULL != m_pInterfaceFactory) delete m_pInterfaceFactory;
		if(NULL != m_pNoteFactory) delete m_pNoteFactory;
		if(NULL != m_pAssociation1Factory) delete m_pAssociation1Factory;
		if(NULL != m_pAssociation2Factory) delete m_pAssociation2Factory;
		if(NULL != m_pAssociation3Factory) delete m_pAssociation3Factory;

		if(NULL != m_pDrawArcFactory) delete m_pDrawArcFactory;
	}
	catch(...)
	{
	}
}

/////////////////////////////////////////////////////////////////////////////
// CTinyUMLView drawing

void CTinyUMLView::OnDraw(CDC* pDC)
{
	CTinyUMLDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CTinyUMLView printing

void CTinyUMLView::OnFilePrintPreview() 
{
	BCGPrintPreview (this);
}

BOOL CTinyUMLView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CTinyUMLView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CTinyUMLView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CTinyUMLView diagnostics

#ifdef _DEBUG
void CTinyUMLView::AssertValid() const
{
	CView::AssertValid();
}

void CTinyUMLView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CTinyUMLDoc* CTinyUMLView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CTinyUMLDoc)));
	return (CTinyUMLDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CTinyUMLView message handlers

/**
 * OnContextMenu:
 *
 * @param  
 * @param point 
 * @return void 
 */
void CTinyUMLView::OnContextMenu(CWnd*, CPoint point)
{
	CPoint screenPoint = point;
	ScreenToClient(&point);
	point = m_pTyUMLEditor->ScreenToVirtual(point , false);

	long nHitCode;
	CIsDrawEntity* pEnt=m_pTyUMLEditor->GetAt(nHitCode,point);
	if(NULL != pEnt)
	{
		CMenu menu;
		
		if(!pEnt->IsSelected()) m_pTyUMLEditor->Select(pEnt);
		theApp.ShowPopupMenu (IDR_CONTEXT_MENU , screenPoint, this);
	}
	else
	{
		CMenu menu;
		theApp.ShowPopupMenu (IDR_CONTEXT_MENU , screenPoint, this);
	}
}

/**
 * OnToolSelect:
 *
 * @return void 
 */
void CTinyUMLView::OnToolSelect() 
{
	CIsDrawSelectionController* pController=static_cast<CIsDrawSelectionController*>(CIsDrawEditor::GetSelectionController());
	m_pTyUMLEditor->SetCurController(pController);		
}

void CTinyUMLView::OnToolClass() 
{
	m_pTyUMLEditor->SetCurController(m_pClassFactory);
}

/**
 * OnInitialUpdate:
 *
 * @return void 
 */
void CTinyUMLView::OnInitialUpdate() 
{
	CView::OnInitialUpdate();
	
	if(NULL == m_pTyUMLEditor)
	{
		CTinyUMLDoc* pDoc = GetDocument();

		m_pTyUMLEditor = new CTinyUMLEditor(&(pDoc->m_container));
		
		CRect rect;
		GetClientRect( rect );
		m_pTyUMLEditor->Create(WS_CHILD | WS_VISIBLE, rect, this);

		// We get the screen resolution, which we will use 
		// for scaling to printer. See also OnDraw.
		CClientDC dc( this );
		int nScreenResolutionX = dc.GetDeviceCaps( LOGPIXELSX );
		
		// Setting up the virtual screen size
		// We want this to represent a single paper 
		// from the default printer.
		
		CPrintDialog printer( TRUE, PD_RETURNDC );
		printer.GetDefaults();
		HDC hdc = printer.GetPrinterDC();
		if( hdc )
		{
			double zoom = GetDeviceCaps( hdc, LOGPIXELSX ) / nScreenResolutionX;
			int horzSize = ::GetDeviceCaps( hdc, PHYSICALWIDTH );
			int vertSize = ::GetDeviceCaps( hdc, PHYSICALHEIGHT );
			
			m_pTyUMLEditor->SetVirtualSize( CSize( round( static_cast< double >( horzSize ) / zoom ), round( static_cast< double >( vertSize ) / zoom ) ) );
			
			int leftMarg = ::GetDeviceCaps( hdc, PHYSICALOFFSETX );
			int topMarg = ::GetDeviceCaps( hdc, PHYSICALOFFSETY );
			
			int horzPrintable = ::GetDeviceCaps( hdc, HORZRES );
			int vertPrintable = ::GetDeviceCaps( hdc, VERTRES );
			
			int rightMarg = horzSize - ( horzPrintable + leftMarg );
			int bottomMarg = vertSize - ( vertPrintable + topMarg );
			
			m_pTyUMLEditor->SetMargins( round( static_cast< double >( leftMarg ) / zoom ), round( static_cast< double >( topMarg ) / zoom ), round( static_cast< double >( rightMarg ) / zoom ), round( static_cast< double >( bottomMarg ) / zoom ) );
			
			::DeleteDC( hdc );
			
			//////////////////////////////////////////////////////////////////////////
			CString scaleText;
			int curSel;
			
			// hate to do it this way, but I need to get to the tool bars
			CMainFrame *mainWnd;
			mainWnd = DYNAMIC_DOWNCAST(CMainFrame, AfxGetApp()->GetMainWnd());
			ASSERT(mainWnd != NULL);
			
			// must've selected the drop list
			if ((curSel = mainWnd->m_wndScaleCombo.GetCurSel()) != CB_ERR){
				mainWnd->m_wndScaleCombo.GetLBText(curSel, scaleText);
			}
			else
			{
				// first check if scale is a valid range
				mainWnd->m_wndScaleCombo.GetWindowText(scaleText);
			}
			int scaleValue = atoi(scaleText);
			m_pTyUMLEditor->SetZoom(static_cast<double>(scaleValue)*0.01);
			//////////////////////////////////////////////////////////////////////////
				

			OnToolSelect();
		}
		else
		{
			// No default printer installed
			m_pTyUMLEditor->SetVirtualSize( CSize( 8 * nScreenResolutionX, 11 * nScreenResolutionX ) );
		}
		//m_pTyUMLEditor->SetModified( FALSE );
	}else	m_pTyUMLEditor->Clear();
	
}

void CTinyUMLView::OnSize(UINT nType, int cx, int cy) 
{
	CView::OnSize(nType, cx, cy);
	
	if( NULL != m_pTyUMLEditor) m_pTyUMLEditor->SetWindowPos(&(CWnd::wndTop),0,0,cx,cy,SWP_NOMOVE);//MoveWindow(0,0,cx,cy);
	
}

BOOL CTinyUMLView::OnEraseBkgnd(CDC* pDC) 
{
	return TRUE;	
}

/**
 * OnUndo:
 *
 * @return void 
 */
void CTinyUMLView::OnUndo() 
{
	m_pTyUMLEditor->Undo();	
}

void CTinyUMLView::OnUpdateUndo(CCmdUI* pCmdUI) 
{
	m_pTyUMLEditor->Undoable() ? pCmdUI->Enable(TRUE) : pCmdUI->Enable(FALSE);
}

void CTinyUMLView::OnUpdateRedo(CCmdUI* pCmdUI) 
{
	m_pTyUMLEditor->Redoable() ? pCmdUI->Enable(TRUE) : pCmdUI->Enable(FALSE);
}

void CTinyUMLView::OnRedo() 
{
	m_pTyUMLEditor->Redo();	
}

/**
 * OnNotify:
 *
 * @param wParam 
 * @param lParam 
 * @param pResult 
 * @return BOOL 
 */
BOOL CTinyUMLView::OnNotify(WPARAM wParam, LPARAM lParam, LRESULT* pResult) 
{
	if((IS_CREATE_ENTITY == wParam) || (IS_UNDELETE_ENTITY == wParam))
	{
		if(IS_CREATE_ENTITY == wParam) OnToolSelect();
		
		IS_NOTIFY* pNotify=(IS_NOTIFY*)(lParam);
		if(pNotify->pEntFrom->IsKindOf(CTinyUMLClass::TypeString()))
		{
			CMainFrame* pMainFrame=(CMainFrame*)(AfxGetApp()->GetMainWnd());
			pMainFrame->GetWorkspaceBar()->AttachClass((CTinyUMLClass*)(pNotify->pEntFrom));
			pMainFrame->GetWorkspaceBar()->RedrawClassTree();
		}
	}
	else if(TINY_UML_MODIFY_PROPERTY == wParam)
	{
		IS_NOTIFY* pNotify=(IS_NOTIFY*)(lParam);
		if(pNotify->pEntFrom->IsKindOf(CTinyUMLClass::TypeString()))
		{
			CMainFrame* pMainFrame=(CMainFrame*)(AfxGetApp()->GetMainWnd());
			pMainFrame->GetWorkspaceBar()->ModifyClassProperty((CTinyUMLClass*)(pNotify->pEntFrom));
		}
		m_pTyUMLEditor->RedrawWindow();
	}
	else if(IS_DELETE_ENTITY == wParam)
	{
		IS_NOTIFY* pNotify=(IS_NOTIFY*)(lParam);
		if((pNotify->pEntFrom) && (pNotify->pEntFrom->IsKindOf(CTinyUMLClass::TypeString())))
		{
			CMainFrame* pMainFrame=(CMainFrame*)(AfxGetApp()->GetMainWnd());
			pMainFrame->GetWorkspaceBar()->DetachClass((CTinyUMLClass*)(pNotify->pEntFrom));
		}
	}
	else if(IS_ABORT == wParam)
	{
		OnToolSelect();
	}

	return CView::OnNotify(wParam, lParam, pResult);
}

void CTinyUMLView::OnUpdateToolClass(CCmdUI* pCmdUI) 
{
	pCmdUI->SetRadio(m_pTyUMLEditor->GetCurController() == m_pClassFactory);	
}

void CTinyUMLView::OnUpdateToolSelect(CCmdUI* pCmdUI) 
{
	pCmdUI->SetRadio(m_pTyUMLEditor->GetCurController() == CIsDrawEditor::GetSelectionController());
}

/**
 * OnToolGeneralization:
 *
 * @return void 
 */
void CTinyUMLView::OnToolGeneralization() 
{
	CTinyUMLGeneralizationController* pController=static_cast<CTinyUMLGeneralizationController*>
		(
		GetUMLEditor()->GetEntityTypeMap(CTinyUMLGeneralization::TypeString())->GetController()
		);
	pController->m_bRealize = false;
	m_pTyUMLEditor->SetCurController(pController);
}

/**
 * OnUpdateToolGeneralization:
 *
 * @param pCmdUI 
 * @return void 
 */
void CTinyUMLView::OnUpdateToolGeneralization(CCmdUI* pCmdUI) 
{
	CTinyUMLGeneralizationController* pController=static_cast<CTinyUMLGeneralizationController*>
		(
		GetUMLEditor()->GetEntityTypeMap(CTinyUMLGeneralization::TypeString())->GetController()
		);
	pCmdUI->SetRadio(m_pTyUMLEditor->GetCurController() == pController);
}

/**
 * OnToolNote:
 *
 * @return void 
 */
void CTinyUMLView::OnToolNote() 
{
	m_pTyUMLEditor->SetCurController(m_pNoteFactory);
}

/**
 * OnUpdateToolNote:
 *
 * @param pCmdUI 
 * @return void 
 */
void CTinyUMLView::OnUpdateToolNote(CCmdUI* pCmdUI) 
{
	pCmdUI->SetRadio(m_pTyUMLEditor->GetCurController() == m_pNoteFactory);
}

void CTinyUMLView::OnToolPackage() 
{
	CTinyUMLPackageController* pController=static_cast<CTinyUMLPackageController*>
		(
		GetUMLEditor()->GetEntityTypeMap(CTinyUMLPackage::TypeString())->GetController()
		);
	m_pTyUMLEditor->SetCurController(pController);
}

void CTinyUMLView::OnUpdateToolPackage(CCmdUI* pCmdUI) 
{
	CTinyUMLPackageController* pController=static_cast<CTinyUMLPackageController*>
		(
		GetUMLEditor()->GetEntityTypeMap(CTinyUMLPackage::TypeString())->GetController()
		);
	pCmdUI->SetRadio(m_pTyUMLEditor->GetCurController() == pController);
	
}

/**
 * OnToolRealize:
 *
 * @return void 
 */
void CTinyUMLView::OnToolRealize() 
{
	m_pTyUMLEditor->SetCurController(m_pRealizeFactory);
}

void CTinyUMLView::OnToolInterface() 
{
	m_pTyUMLEditor->SetCurController(m_pInterfaceFactory);
}

void CTinyUMLView::OnUpdateToolInterface(CCmdUI* pCmdUI) 
{
	pCmdUI->SetRadio((m_pTyUMLEditor->GetCurController() == m_pInterfaceFactory));
}

void CTinyUMLView::OnToolAssociation1() 
{
	m_pTyUMLEditor->SetCurController(m_pAssociation1Factory);
}

void CTinyUMLView::OnUpdateToolAssociation1(CCmdUI* pCmdUI) 
{
	pCmdUI->SetRadio((m_pTyUMLEditor->GetCurController() == m_pAssociation1Factory));
}

void CTinyUMLView::OnToolAssociation2() 
{
	m_pTyUMLEditor->SetCurController(m_pAssociation2Factory);
}

void CTinyUMLView::OnUpdateToolAssociation2(CCmdUI* pCmdUI) 
{
	pCmdUI->SetRadio((m_pTyUMLEditor->GetCurController() == m_pAssociation2Factory));
}

void CTinyUMLView::OnToolAssociation3() 
{
	m_pTyUMLEditor->SetCurController(m_pAssociation3Factory);
}

void CTinyUMLView::OnUpdateToolAssociation3(CCmdUI* pCmdUI) 
{
	pCmdUI->SetRadio((m_pTyUMLEditor->GetCurController() == m_pAssociation3Factory));
}

void CTinyUMLView::OnToolDependency() 
{
	CTinyUMLDependencyController* pController=static_cast<CTinyUMLDependencyController*>
		(
		GetUMLEditor()->GetEntityTypeMap(CTinyUMLDependency::TypeString())->GetController()
		);
	m_pTyUMLEditor->SetCurController(pController);
}

void CTinyUMLView::OnUpdateToolDependency(CCmdUI* pCmdUI) 
{
	CTinyUMLDependencyController* pController=static_cast<CTinyUMLDependencyController*>
		(
		GetUMLEditor()->GetEntityTypeMap(CTinyUMLDependency::TypeString())->GetController()
		);
	pCmdUI->SetRadio((m_pTyUMLEditor->GetCurController() == pController));
}

void CTinyUMLView::OnViewgrid() 
{
	m_pTyUMLEditor->ShowGrid(m_pTyUMLEditor->IsGridVisible() ? false : true);
}

void CTinyUMLView::OnUpdateViewgrid(CCmdUI* pCmdUI) 
{
	pCmdUI->SetRadio(m_pTyUMLEditor->IsGridVisible() ? true : false);
}

void CTinyUMLView::OnViewmin() 
{
	m_pTyUMLEditor->SetZoom(0.5);
	
	CMainFrame *mainWnd;
	mainWnd = DYNAMIC_DOWNCAST(CMainFrame, AfxGetApp()->GetMainWnd());
	mainWnd->m_wndScaleCombo.SetCurSel(1);
}

void CTinyUMLView::OnUpdateViewmin(CCmdUI* pCmdUI) 
{
	pCmdUI->SetRadio(0.5 == m_pTyUMLEditor->GetZoom());
}

void CTinyUMLView::OnViewnormal() 
{
	m_pTyUMLEditor->SetZoom(1.f);

	CMainFrame *mainWnd;
	mainWnd = DYNAMIC_DOWNCAST(CMainFrame, AfxGetApp()->GetMainWnd());
	mainWnd->m_wndScaleCombo.SetCurSel(2);
}

void CTinyUMLView::OnUpdateViewnormal(CCmdUI* pCmdUI) 
{
	pCmdUI->SetRadio(1.f == m_pTyUMLEditor->GetZoom());
}

void CTinyUMLView::OnViewmax() 
{
	const static _min_scale=1.5;
	m_pTyUMLEditor->SetZoom(1.5f);

	CMainFrame *mainWnd;
	mainWnd = DYNAMIC_DOWNCAST(CMainFrame, AfxGetApp()->GetMainWnd());
	mainWnd->m_wndScaleCombo.SetCurSel(3);
}

void CTinyUMLView::OnUpdateViewmax(CCmdUI* pCmdUI) 
{
	pCmdUI->SetRadio(1.5f == m_pTyUMLEditor->GetZoom());
}

/**
 * OnScaleSelect:
 *
 * @return void 
 */
void CTinyUMLView::OnScaleSelect() 
{
	CString scaleText;
	int scaleValue;
	int curSel;
	
	// hate to do it this way, but I need to get to the tool bars
	CMainFrame *mainWnd;
	mainWnd = DYNAMIC_DOWNCAST(CMainFrame, AfxGetApp()->GetMainWnd());
	ASSERT(mainWnd != NULL);
	
	// must've selected the drop list
	if ((curSel = mainWnd->m_wndScaleCombo.GetCurSel()) != CB_ERR)
	{
		mainWnd->m_wndScaleCombo.GetLBText(curSel, scaleText);
	}
	else
	{
		// first check if scale is a valid range
		mainWnd->m_wndScaleCombo.GetWindowText(scaleText);
	}
	
	scaleValue = atoi(scaleText);
	
	// this is bad, don't set scale value
	if (scaleValue <= 0)
	{
		scaleText.Format(IDS_BAD_PERCENT, scaleValue);
		MessageBox(scaleText);
		return;
	}
	else
	{	// should we limit the upward bounds of scale?
		// convert to float value for scaling
		if(NULL != m_pTyUMLEditor)
		{
			m_pTyUMLEditor->SetZoom(scaleValue * 0.01);
			m_pTyUMLEditor->RedrawWindow();
		}
	}	
}


void CTinyUMLView::OnViewLock() 
{
	if(m_pTyUMLEditor->IsLocked())
		m_pTyUMLEditor->Unlock();
	else	m_pTyUMLEditor->Lock();
	
}

/**
 * OnUpdateViewLock:
 *
 * @param pCmdUI 
 * @return void 
 */
void CTinyUMLView::OnUpdateViewLock(CCmdUI* pCmdUI) 
{
	pCmdUI->SetCheck(m_pTyUMLEditor->IsLocked() ? 1 : 0);
}

/**
 * OnEditProperties:
 *
 * @return void 
 */
void CTinyUMLView::OnEditProperties() 
{
	CIsDrawEntitySet* pEntSet=m_pTyUMLEditor->GetSelectionSet();
	CIsDrawEntity* pEnt=pEntSet->GetAt(0);
	if(NULL != pEnt)
	{
		CIsDrawEditor* pUMLEditor = GetUMLEditor();
		CIsDrawEntController* pController = pUMLEditor->GetEntityTypeMap(pEnt->GetTypeString())->GetController();
		pController->Set(pEnt,m_pTyUMLEditor);
		pController->ModifyProperties();
	}
}

/**
 * OnUpdateEditProperties:
 *
 * @param pCmdUI 
 * @return void 
 */
void CTinyUMLView::OnUpdateEditProperties(CCmdUI* pCmdUI) 
{
	CIsDrawEntitySet* pEntSet=m_pTyUMLEditor->GetSelectionSet();
	pCmdUI->Enable(!pEntSet->IsEmpty());
}

/**
 * OnActivateView:
 *
 * @param bActivate 
 * @param pActivateView 
 * @param pDeactiveView 
 * @return void 
 */
void CTinyUMLView::OnActivateView(BOOL bActivate, CView* pActivateView, CView* pDeactiveView) 
{
	static CView* pPreActivateView=NULL;

	if((TRUE == bActivate) && (pPreActivateView != pActivateView))
	{
		CTinyUMLDoc* pDoc=GetDocument();
		pDoc->DisplayContentsOnWorkspace();

		pPreActivateView = pActivateView;
	}

	CView::OnActivateView(bActivate, pActivateView, pDeactiveView);
}

/**
 * GetUMLEditor:
 *
 * @return CTinyUMLEditor* 
 */
CTinyUMLEditor* CTinyUMLView::GetUMLEditor()
{
	return m_pTyUMLEditor;
}

/**
 * OnEditTheme:
 *
 * @return void 
 */
void CTinyUMLView::OnEditTheme() 
{
	CClassThemePropertyPage classThemePage;
	classThemePage.m_psp.dwFlags&= ~PSP_HASHELP;
	CNoteThemePropertyPage noteThemePage;
	noteThemePage.m_psp.dwFlags&= ~PSP_HASHELP;
	CPackageThemePropertyPage packageThemePage;
	packageThemePage.m_psp.dwFlags&= ~PSP_HASHELP;
	CRelationThemePropertyPage relationThemePage;
	relationThemePage.m_psp.dwFlags&= ~PSP_HASHELP;
	CGeneralThemePropertyPage generalThemePage;
	relationThemePage.m_psp.dwFlags&= ~PSP_HASHELP;
	
	CImageList DefaultImages, Images;
	DefaultImages.Create(IDB_THEME, 16, 0, RGB(0x00, 0x80, 0x80));

	CThemePropSheet sheet(_T("Theme properties"));
	sheet.m_psh.dwFlags |= PSH_NOAPPLYNOW;
	sheet.m_psh.dwFlags&= ~PSH_HASHELP;
	
	//////////////////////////////////////////////////////////////////////////
	// add pages
	sheet.AddPage(&generalThemePage);
	sheet.AddPage(&classThemePage);
	sheet.AddPage(&noteThemePage);
	sheet.AddPage(&packageThemePage);
	sheet.AddPage(&relationThemePage);
			
	CTinyUMLTheme* pTheme=static_cast<CTinyUMLTheme*>(m_pTyUMLEditor->GetDoc()->GetTheme());

	//////////////////////////////////////////////////////////////////////////
	/// general
	CGeneralThemePropertyPage* pGeneralThemePage=static_cast<CGeneralThemePropertyPage*>(sheet.GetPage(0));
	pGeneralThemePage->m_clrNameColor  = *(pTheme->GetNameColor());
	pGeneralThemePage->m_clrLineColor  = *(pTheme->GetLineColor());
	pGeneralThemePage->m_clrShadowColor= *(pTheme->GetShadowColor());

	LOGFONT logfont;
	(pTheme->GetNameFont())->GetLogFont(&logfont);
	pGeneralThemePage->m_rNameFont = logfont.lfFaceName;

	//////////////////////////////////////////////////////////////////////////
	/// class
	CClassThemePropertyPage* pClassThemePropPage=static_cast<CClassThemePropertyPage*>(sheet.GetPage(1));
	pClassThemePropPage->m_clrTitleColor = *(pTheme->classTitleColor());
	pClassThemePropPage->m_clrBackColor = *(pTheme->classColor());
	pClassThemePropPage->m_clrFolderColor = *(pTheme->GetFolderColor());
	pClassThemePropPage->m_clrAttributeColor = *(pTheme->GetAttributeColor());
	pClassThemePropPage->m_clrMethodColor = *(pTheme->GetMethodColor());
	
	(pTheme->GetMemberFont())->GetLogFont(&logfont);
	pClassThemePropPage->m_rMemberFontSize.Format("%d",logfont.lfHeight);
	pClassThemePropPage->m_rMemberFont = logfont.lfFaceName;
	(pTheme->GetMethodFont())->GetLogFont(&logfont);
	pClassThemePropPage->m_rMethodFontSize.Format("%d",logfont.lfHeight);
	pClassThemePropPage->m_rMethodFont = logfont.lfFaceName;
	
	//////////////////////////////////////////////////////////////////////////
	/// package
	CPackageThemePropertyPage* pPackageTheme=static_cast<CPackageThemePropertyPage*>(sheet.GetPage(3));
	pPackageTheme->m_clrFillColor = *(pTheme->GetPackageColor());

	//////////////////////////////////////////////////////////////////////////
	/// relation
	CRelationThemePropertyPage* pRelationTheme=static_cast<CRelationThemePropertyPage*>(sheet.GetPage(4));
	pRelationTheme->m_clrEndSymbolColor = *(pTheme->GetEndSymbolColor());
	
	if(IDOK == sheet.DoModal())
	{
		pTheme->SetLineColor(pGeneralThemePage->m_clrLineColor);
		pTheme->SetShadowColor(pGeneralThemePage->m_clrShadowColor);
		
		CFont* pNameFont = new CFont();
		(pTheme->GetNameFont())->GetLogFont(&logfont);
		VERIFY(pNameFont->CreateFont(logfont.lfHeight, 0, 0, 0, FW_NORMAL,
			false, false, false,
			ANSI_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY,
			DEFAULT_PITCH, pGeneralThemePage->m_rNameFont));
		pTheme->SetNameFont(pNameFont);

		pTheme->SetClassBackColor(pClassThemePropPage->m_clrBackColor);
		pTheme->SetClassTitleColor(pClassThemePropPage->m_clrTitleColor);
		pTheme->SetFolderColor(pClassThemePropPage->m_clrFolderColor);

		CFont* pMemberFont = new CFont();
		VERIFY(pMemberFont->CreateFont(atoi(pClassThemePropPage->m_rMemberFontSize), 0, 0, 0, FW_NORMAL,
			false, false, false,
			ANSI_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY,
			DEFAULT_PITCH, pClassThemePropPage->m_rMemberFont));
		pTheme->SetMemberFont(pMemberFont);

		CFont* pMethodFont = new CFont();
		VERIFY(pMethodFont->CreateFont(atoi(pClassThemePropPage->m_rMethodFontSize), 0, 0, 0, FW_NORMAL,
			false, false, false,
			ANSI_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY,
			DEFAULT_PITCH, pClassThemePropPage->m_rMethodFont));
		pTheme->SetMethodFont(pMethodFont);

		pTheme->SetPackageColor(pPackageTheme->m_clrFillColor);
		pTheme->SetEndSymbolColor(pRelationTheme->m_clrEndSymbolColor);
		
		m_pTyUMLEditor->RedrawWindow();
	}
}

/**
 * OnSaveTheme:
 *
 * @return void 
 */
void CTinyUMLView::OnSaveTheme() 
{
	CFileDialog dlg(FALSE, NULL,NULL, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,"uml theme(*.uthme)|*.uthme", this);
	if(IDOK != dlg.DoModal()) return;

	CFile file;
	if(file.Open(dlg.GetPathName(), CFile::modeCreate | CFile::modeWrite))
	{
		CArchive ar(&file, CArchive::store);
		m_pTyUMLEditor->GetDoc()->GetTheme()->Serialize(ar);
	}
}

/**
 * OnLoadTheme:
 *
 * @return void 
 */
void CTinyUMLView::OnLoadTheme() 
{
	CFileDialog dlg(TRUE, NULL,NULL, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,"uml theme(*.uthme)|*.uthme", this);
	if(IDOK != dlg.DoModal()) return;

	CFile file;
	if(file.Open(dlg.GetPathName(), CFile::modeRead))
	{
		CArchive ar(&file, CArchive::load);
		
		CTinyUMLTheme* pTheme = static_cast<CTinyUMLTheme*>(m_pTyUMLEditor->GetDoc()->GetTheme());
		pTheme->Serialize(ar);
		m_pTyUMLEditor->RedrawWindow();
	}
}

/**
 * OnToolLabel:
 *
 * @return void 
 */
void CTinyUMLView::OnToolLabel() 
{
	m_pTyUMLEditor->SetCurController(m_pLabelFactory);
}

/**
 * OnEditCopy:
 *
 * @return void 
 */
void CTinyUMLView::OnEditCopy() 
{
	if(m_pTyUMLEditor)
	{
		CIsDrawEntitySet* pEntSet=m_pTyUMLEditor->GetSelectionSet();
		if(NULL != pEntSet)
		{
			CIsDrawCtrlHost* pApp = CIsDrawCtrlHost::GetInstance();

			CClipboardManager* pClipMan = pApp->GetClipboardManager();
			pClipMan->SetData(pEntSet);
		}
	}
}

/**
 * OnEditPaste:
 *
 * @return void 
 */
void CTinyUMLView::OnEditPaste() 
{
	m_pTyUMLEditor->Paste();
	m_pTyUMLEditor->RedrawWindow();
}

/**
 * OnUpdateToolRealize:
 *
 * @param pCmdUI 
 * @return void 
 */
void CTinyUMLView::OnUpdateToolRealize(CCmdUI* pCmdUI) 
{
	pCmdUI->SetRadio(m_pTyUMLEditor->GetCurController() == m_pRealizeFactory);
}

/**
 * OnFilePurge:
 *
 * @return void 
 */
void CTinyUMLView::OnFilePurge() 
{
	if(m_pTyUMLEditor) m_pTyUMLEditor->Purge();
	
}

/**
 * OnArrangeBringToFront:
 *
 * @return void 
 */
void CTinyUMLView::OnArrangeBringToFront() 
{
	if(NULL != m_pTyUMLEditor)
	{
		CIsDrawEntitySet* pEntSet = m_pTyUMLEditor->GetSelectionSet();
		if(NULL != pEntSet)
		{
			CTinyUMLDoc* pDoc = GetDocument();
			CArray<CIsDrawEntity*,const CIsDrawEntity*> objs;
			CTinyDocIterator* pIter = pDoc->m_container.CreateIteator();
			for(;!pIter->IsDone();pIter->Next())
			{
				if(pEntSet->Exist(pIter->GetData()))
				{
					pDoc->m_container.BringToFront(pIter->GetData());
				}
			}
			delete pIter;
		}
	}
}

/**
 * OnArrangeSendToBack:
 *
 * @return void 
 */
void CTinyUMLView::OnArrangeSendToBack() 
{
	if(NULL != m_pTyUMLEditor)
	{
		CIsDrawEntitySet* pEntSet = m_pTyUMLEditor->GetSelectionSet();
		if(NULL != pEntSet)
		{
			CTinyUMLDoc* pDoc = GetDocument();
			CArray<CIsDrawEntity*,const CIsDrawEntity*> objs;
			CTinyDocIterator* pIter = pDoc->m_container.CreateIteator();
			for(pIter->End();!pIter->IsDone();pIter->Prev())
			{
				if(pEntSet->Exist(pIter->GetData()))
				{
					pDoc->m_container.SendToBack(pIter->GetData());
				}
			}
			delete pIter;
		}
	}
}

/**
 * OnFileReadsource:
 *
 * @return void 
 */
void CTinyUMLView::OnFileReadsource() 
{
	CFileDialog objDlg(TRUE, NULL,NULL, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,"Header file(*.h)|*.h|", this);
	if(IDOK == objDlg.DoModal())
	{
		CString rFilePath = objDlg.GetPathName();

		CFileContext fileContext(rFilePath);
		fileContext.Parse();
		
		long lIndex=0L;
		CParserContext* pContext=NULL;
		while(NULL != (pContext = fileContext.GetAt(lIndex++)))
		{
			if(pContext->IsKindOf(CParserContext::CLASS_CONTEXT))
			{
				CClassContext* pClassContext = static_cast<CClassContext*>(pContext);
				
				CTinyUMLClass* pNewClass = new CTinyUMLClass(&(GetDocument()->m_container),NULL);
				
				long lSection = 0L;
				CClassSection* pSection = NULL;
				while(NULL != (pSection = pClassContext->GetSectionAt(lSection++)))
				{
					long lContext = 0L;
					CParserContext* pContext = NULL;
					while(NULL != (pContext = pSection->GetAt(lContext++)))
					{
						if(pContext->IsKindOf(CParserContext::METHOD_CONTEXT))
						{
							CMethodContext* pMethodContext = static_cast<CMethodContext*>(pContext);
							
							CTinyUMLClass::Method method;
							method.access = CTinyUMLClass::Method::private_method;
							if(pSection->IsPublic())
								method.access = CTinyUMLClass::Method::public_method;
							else if(pSection->IsProtected())
								method.access = CTinyUMLClass::Method::protected_method;
							method.type = pMethodContext->GetType();
							method.name = pMethodContext->GetName();
							pNewClass->AddMethod(method);
						}
						else if(pContext->IsKindOf(CParserContext::MEMBER_CONTEXT))
						{
							CMemberContext* pMemberContext = static_cast<CMemberContext*>(pContext);
							
							CTinyUMLClass::Member member;
							member.access = CTinyUMLClass::Member::private_member;
							if(pSection->IsPublic())
								member.access = CTinyUMLClass::Member::public_member;
							else if(pSection->IsProtected())
								member.access = CTinyUMLClass::Member::protected_member;
							member.type = pMemberContext->GetType();
							member.name = pMemberContext->GetName();
							pNewClass->AddMember(member);
						}
					}
				}
				pNewClass->SetupTheme(m_pTyUMLEditor->GetDoc()->GetTheme());
				CRect rect = pNewClass->GetRect();
				const int right =m_pTyUMLEditor->SnapX(pNewClass->GetMinimumSize().cx);
				const int bottom=m_pTyUMLEditor->SnapY(pNewClass->GetMinimumSize().cy);
				pNewClass->SetRect(rect.left,rect.top,right,bottom);
				pNewClass->SetName(pClassContext->GetName());
				GetDocument()->m_container.Append(pNewClass);

				//////////////////////////////////////////////////////////////////////////
				IS_NOTIFY notify;
				notify.hdr.hwndFrom = m_pTyUMLEditor->GetSafeHwnd();
				notify.pEntFrom = pNewClass;
				m_pTyUMLEditor->SendMessage(WM_NOTIFY,(WPARAM)IS_CREATE_ENTITY,(LPARAM)(&notify));
			}
		}
		
		m_pTyUMLEditor->RedrawWindow();
	}
}

/**
 * OnUpdateToolLabel:
 *
 * @param pCmdUI 
 * @return void 
 */
void CTinyUMLView::OnUpdateToolLabel(CCmdUI* pCmdUI) 
{
	pCmdUI->SetRadio(m_pTyUMLEditor->GetCurController() == m_pLabelFactory);
}

void CTinyUMLView::OnDrawToolLine() 
{
	// TODO: Add your command handler code here
	m_pTyUMLEditor->SetCurController(m_pDrawLineFactory);
}

void CTinyUMLView::OnUpdateDrawToolLine(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetRadio(m_pTyUMLEditor->GetCurController() == m_pDrawLineFactory);
}

void CTinyUMLView::OnDrawToolRect() 
{
	// TODO: Add your command handler code here
	m_pTyUMLEditor->SetCurController(m_pDrawRectFactory);
}

void CTinyUMLView::OnUpdateDrawToolRect(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetRadio(m_pTyUMLEditor->GetCurController() == m_pDrawRectFactory);
}

void CTinyUMLView::OnDrawToolEllipse() 
{
	// TODO: Add your command handler code here
	m_pTyUMLEditor->SetCurController(m_pDrawEllipseFactory);
}

void CTinyUMLView::OnUpdateDrawToolEllipse(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetRadio(m_pTyUMLEditor->GetCurController() == m_pDrawEllipseFactory);
}

void CTinyUMLView::OnDrawToolArc() 
{
	// TODO: Add your command handler code here
	m_pTyUMLEditor->SetCurController(m_pDrawArcFactory);
}

void CTinyUMLView::OnUpdateDrawToolArc(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetRadio(m_pTyUMLEditor->GetCurController() == m_pDrawArcFactory);
}

void CTinyUMLView::OnDrawingLineColor() 
{
	// TODO: Add your command handler code here
	CMainFrame* pFrame = static_cast<CMainFrame*>(AfxGetMainWnd());
	COLORREF color = pFrame->GetDrawingStyleToolBar()->m_wndComboColorPicker.GetSelectedColor();
	m_pTyUMLEditor->OnDrawingLineColor(color);
}

void CTinyUMLView::OnDrawingLineStyle() 
{
	// TODO: Add your command handler code here
	CMainFrame* pFrame = static_cast<CMainFrame*>(AfxGetMainWnd());
	int lstyle = pFrame->GetDrawingStyleToolBar()->m_wndComboLineStyle.GetSelectedLineStyle();
	m_pTyUMLEditor->OnDrawingLineStyle(lstyle);
}

void CTinyUMLView::OnDrawingLineWeight() 
{
	// TODO: Add your command handler code here
	CMainFrame* pFrame = static_cast<CMainFrame*>(AfxGetMainWnd());
	int lweight = pFrame->GetDrawingStyleToolBar()->m_wndComboLineWeight.GetSelectedLineWeight();
	m_pTyUMLEditor->OnDrawingLineWeight(lweight);
}
