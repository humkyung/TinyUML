// MainFrm.cpp : implementation of the CMainFrame class
//

#include "stdafx.h"
#include <assert.h>
#include "TinyUML.h"
#include "Resource.h"
#include "MainFrm.h"
#include "ToolShell.h"
#include "ChildFrm.h"
#include "TinyUMLView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMainFrame

IMPLEMENT_DYNAMIC(CMainFrame, CMDIFrameWnd)


BEGIN_MESSAGE_MAP(CMainFrame, CMDIFrameWnd)
	//{{AFX_MSG_MAP(CMainFrame)
	ON_WM_CREATE()
	ON_UPDATE_COMMAND_UI(ID_VIEW_TOOLSBAR, OnUpdateViewToolsbar)
	//}}AFX_MSG_MAP
	ON_COMMAND(ID_VIEW_CUSTOMIZE, OnViewCustomize)
	ON_REGISTERED_MESSAGE(BCGM_RESETTOOLBAR, OnToolbarReset)
	ON_REGISTERED_MESSAGE(BCGM_TOOLBARMENU, OnToolbarContextMenu)
	ON_COMMAND(ID_VIEW_WORKSPACE, OnViewWorkspace)
	ON_UPDATE_COMMAND_UI(ID_VIEW_WORKSPACE, OnUpdateViewWorkspace)
	ON_COMMAND(ID_VIEW_TOOLSBAR, OnViewToolsbar)
	ON_UPDATE_COMMAND_UI(ID_INDICATOR_SNAP, OnUpdateIndicatorSnap)
	ON_UPDATE_COMMAND_UI(ID_INDICATOR_DATE, OnUpdateDate)
	ON_UPDATE_COMMAND_UI(ID_INDICATOR_TIME, OnUpdateTime)
	ON_UPDATE_COMMAND_UI(ID_INDICATOR_MOUSEPOS, OnUpdateIndicatorMousepos)
END_MESSAGE_MAP()

static SBACTPANEINFO indicators[] =
{
	{ID_SEPARATOR, _T("This gives us our normal status information"), SBACTF_COMMAND | SBACTF_HANDCURSOR },           // status line indicator
	{ID_INDICATOR_SNAP, _T("Left-Double Click to toggle snap"), SBACTF_COMMAND | SBACTF_HANDCURSOR },           // status line indicator
	{ID_INDICATOR_MOUSEPOS, _T("The current cursor position"), SBACTF_AUTOFIT , MAKEINTRESOURCE(IDC_MOUSE_CURSOR)}, 
	{ID_INDICATOR_CAPS, _T("Whether the Caps Lock is on. \nDouble-right-click or single-left-click to toggle"), 
		SBACTF_COMMAND | SBACTF_HANDCURSOR | SBACTF_DOUBLECLICK | SBACTF_SINGLECLICK | SBACTF_LEFTBUTTON | SBACTF_RIGHTBUTTON},
	{ID_INDICATOR_NUM, _T("Whether the Num Lock is on. \nDouble-left-click to toggle"), 
		SBACTF_COMMAND | SBACTF_HANDCURSOR},
	{ID_INDICATOR_SCRL, _T("Whether the Scroll Lock is on. \nDouble-left-click to toggle, or right click for menu"), 
		SBACTF_COMMAND | SBACTF_HANDCURSOR | SBACTF_DOUBLECLICK | SBACTF_SINGLECLICK | SBACTF_LEFTBUTTON | SBACTF_RIGHTBUTTON},
};

/////////////////////////////////////////////////////////////////////////////
// CMainFrame construction/destruction

CMainFrame::CMainFrame() : m_bSnap(true)
{
	// TODO: add member initialization code here
	
}

CMainFrame::~CMainFrame()
{
}

/**
 * OnCreate:
 *
 * @param lpCreateStruct 
 * @return int 
 */
int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CMDIFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	// enable Office XP look:
	CBCGVisualManager::SetDefaultManager (RUNTIME_CLASS (CBCGVisualManagerXP));

	CBCGToolBar::EnableQuickCustomization ();

	EnableMDITabs ();


	// TODO: Define your own basic commands. Be sure, that each pulldown 
	// menu have at least one basic command.

	CList<UINT, UINT>	lstBasicCommands;

	lstBasicCommands.AddTail (ID_VIEW_TOOLBARS);
	lstBasicCommands.AddTail (ID_FILE_NEW);
	lstBasicCommands.AddTail (ID_FILE_OPEN);
	lstBasicCommands.AddTail (ID_FILE_SAVE);
	lstBasicCommands.AddTail (ID_FILE_PRINT);
	lstBasicCommands.AddTail (ID_APP_EXIT);
	lstBasicCommands.AddTail (ID_EDIT_CUT);
	lstBasicCommands.AddTail (ID_EDIT_PASTE);
	lstBasicCommands.AddTail (ID_EDIT_PROPERTIES);
	lstBasicCommands.AddTail (ID_APP_ABOUT);
	lstBasicCommands.AddTail (ID_VIEW_TOOLBAR);
	lstBasicCommands.AddTail (ID_VIEW_TOOLSBAR);
	lstBasicCommands.AddTail (ID_VIEW_CUSTOMIZE);
	lstBasicCommands.AddTail (ID_WINDOW_TILE_HORZ);

	CBCGToolBar::SetBasicCommands (lstBasicCommands);

	if (!m_wndMenuBar.Create (this))
	{
		TRACE0("Failed to create menubar\n");
		return -1;      // fail to create
	}

	m_wndMenuBar.SetBarStyle(m_wndMenuBar.GetBarStyle() | CBRS_SIZE_DYNAMIC);

	if (!m_wndToolBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_TOP
		| CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC) ||
		!m_wndToolBar.LoadToolBar(IDR_MAINFRAME))
	{
		TRACE0("Failed to create toolbar\n");
		return -1;      // fail to create
	}

	DWORD dwStyle = WS_CHILD | WS_VISIBLE | CBRS_BOTTOM
		| CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC;
	CRect rcBorders = CRect(0, 0, 0, 0);
	if (!m_wndDrawToolBar.CreateEx(this, TBSTYLE_FLAT, dwStyle, rcBorders, IDR_DRAW_TOOLBAR) ||
		!m_wndDrawToolBar.LoadToolBar(IDR_DRAW_TOOLBAR))
	{
		TRACE0("Failed to create toolbar\n");
		return -1;      // fail to create
	}

	if (!m_wndToolsBar.CreateEx(this, TBSTYLE_FLAT, dwStyle, rcBorders, IDR_TOOLSBAR) ||
		!m_wndToolsBar.LoadToolBar(IDR_UML_TOOLBAR))
	{
		TRACE0("Failed to create toolbar\n");
		return -1;      // fail to create
	}

	if (!CreateViewBar(dwStyle))
	{
		TRACE0("Failed to create view toolbar\n");
		return -1;      // fail to create
	}
	
	if (!m_wndDrawingStyleToolBar.CreateEx(this, TBSTYLE_FLAT, dwStyle , rcBorders , IDR_STYLE_TOOLBAR) ||
		!m_wndDrawingStyleToolBar.LoadToolBar(IDR_STYLE_TOOLBAR))
	{
		TRACE0("Failed to create toolbar\n");
		return -1;      // fail to create
	}

	/*if (!m_wndStatusBar.Create(this) ||
		!m_wndStatusBar.SetPanes(indicators,
		  sizeof(indicators)/sizeof(SBACTPANEINFO)))
	{
		TRACE0("Failed to create status bar\n");
		return -1;      // fail to create
	}
	*/
	
	if (!m_wndWorkSpace.Create (_T("Workspace"), this, CSize (200, 200),
		TRUE /* Has gripper */, ID_VIEW_WORKSPACE,
		WS_CHILD | WS_VISIBLE | CBRS_LEFT))
	{
		TRACE0("Failed to create workspace bar\n");
		return -1;      // fail to create
	}

	/*
	if(!m_wndOutput.Create(_T("WorkSpace"),this,CSize(440,200),ABS_DOCKLEFT|ABS_VISIBLE,100)){
		TRACE0("Failed to create sizing bar\n");
		return -1;
	}
	m_wndOutput.SetBarStyle (m_wndOutput.GetBarStyle() | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC);
	*/

	//if (!m_wndOutput.Create (_T("Class Editor"), this, CSize (150, 150),
	//	TRUE /* Has gripper */, ID_VIEW_OUTPUT,
	//	WS_CHILD | WS_VISIBLE | CBRS_BOTTOM))
	//{
	//	TRACE0("Failed to create output bar\n");
	//	return -1;      // fail to create
	//}

	CString strMainToolbarTitle;
	strMainToolbarTitle.LoadString (IDS_MAIN_TOOLBAR);
	m_wndToolBar.SetWindowText (strMainToolbarTitle);
	m_wndDrawToolBar.SetWindowText("Draw");
	m_wndToolsBar.SetWindowText("Tools");
	//m_wndObjectBar.SetWindowText("Object");
	// TODO: Delete these three lines if you don't want the toolbar to
	//  be dockable
	m_wndMenuBar.EnableDocking(CBRS_ALIGN_ANY);
	m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);
	m_wndDrawToolBar.EnableDocking(CBRS_ALIGN_ANY);
	m_wndToolsBar.EnableDocking(CBRS_ALIGN_ANY);
	m_viewBar.EnableDocking(CBRS_ALIGN_ANY);
	m_wndDrawingStyleToolBar.EnableDocking(CBRS_ALIGN_ANY);
	m_wndWorkSpace.EnableDocking(CBRS_ALIGN_ANY);
	EnableDocking(CBRS_ALIGN_ANY);
	DockControlBar(&m_wndMenuBar);
	DockControlBar(&m_wndToolBar, AFX_IDW_DOCKBAR_TOP);
	DockControlBar(&m_wndDrawToolBar);
	DockControlBar(&m_wndToolsBar, AFX_IDW_DOCKBAR_LEFT);
	
	DockControlBarLeftOf(&m_viewBar , &m_wndToolBar);
	DockControlBarLeftOf(&m_wndDrawingStyleToolBar , &m_viewBar);
	DockControlBar(&m_wndWorkSpace);

	/*
	// CG: The following block was inserted by 'Status Bar' component.
	{
		// Find out the size of the static variable 'indicators' defined
		// by AppWizard and copy it
		int nOrigSize = sizeof(indicators) / sizeof(UINT);

		UINT* pIndicators = new UINT[nOrigSize + 2];
		memcpy(pIndicators, indicators, sizeof(indicators));

		// Call the Status Bar Component's status bar creation function
		if (!InitStatusBar(pIndicators, nOrigSize, 60))
		{
			TRACE0("Failed to initialize Status Bar\n");
			return -1;
		}
		delete[] pIndicators;
	}
	*/

/*	
	typedef struct _WIN32_FIND_DATA { 
		DWORD dwFileAttributes; 
		FILETIME ftCreationTime; 
		FILETIME ftLastAccessTime; 
		FILETIME ftLastWriteTime; 
		DWORD nFileSizeHigh; 
		DWORD nFileSizeLow; 
		DWORD dwOID; 
		TCHAR cFileName[MAX_PATH]; 
	} WIN32_FIND_DATA; 
*/
	/*
	HINSTANCE hInstDll = LoadLibrary("./draw.dll");
	if(!hInstDll) AfxMessageBox("Fail to load draw.dll");
	*/
		
	CToolShell* pShell=CToolShell::GetInstance();
	pShell->Create(this);

	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CMDIFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// CMainFrame diagnostics

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CMDIFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CMDIFrameWnd::Dump(dc);
}

#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMainFrame message handlers


void CMainFrame::OnViewCustomize()
{
	//------------------------------------
	// Create a customize toolbars dialog:
	//------------------------------------
	CBCGToolbarCustomize* pDlgCust = new CBCGToolbarCustomize (this,
		TRUE /* Automatic menus scaning */
		, (	BCGCUSTOMIZE_MENU_SHADOWS | BCGCUSTOMIZE_TEXT_LABELS | 
			BCGCUSTOMIZE_LOOK_2000 | BCGCUSTOMIZE_MENU_ANIMATIONS,
			BCGCUSTOMIZE_SELECT_SKINS)
		);

	pDlgCust->Create ();
}

LRESULT CMainFrame::OnToolbarContextMenu(WPARAM,LPARAM lp)
{
	CPoint point (BCG_GET_X_LPARAM(lp), BCG_GET_Y_LPARAM(lp));

	CMenu menu;
	VERIFY(menu.LoadMenu (IDR_POPUP_TOOLBAR));

	CMenu* pPopup = menu.GetSubMenu(0);
	ASSERT(pPopup != NULL);

	CBCGPopupMenu* pPopupMenu = new CBCGPopupMenu;
	pPopupMenu->Create (this, point.x, point.y, pPopup->Detach ());

	return 0;
}

afx_msg LRESULT CMainFrame::OnToolbarReset(WPARAM /*wp*/,LPARAM)
{
	// TODO: reset toolbar with id = (UINT) wp to its initial state:
	//
	// UINT uiToolBarId = (UINT) wp;
	// if (uiToolBarId == IDR_MAINFRAME)
	// {
	//		do something with m_wndToolBar
	// }

	return 0;
}

BOOL CMainFrame::OnShowPopupMenu (CBCGPopupMenu* pMenuPopup)
{
	//---------------------------------------------------------
	// Replace ID_VIEW_TOOLBARS menu item to the toolbars list:
	//---------------------------------------------------------
    CMDIFrameWnd::OnShowPopupMenu (pMenuPopup);

    if (pMenuPopup != NULL &&
		pMenuPopup->GetMenuBar ()->CommandToIndex (ID_VIEW_TOOLBARS) >= 0)
    {
		if (CBCGToolBar::IsCustomizeMode ())
		{
			//----------------------------------------------------
			// Don't show toolbars list in the cuztomization mode!
			//----------------------------------------------------
			return FALSE;
		}

		pMenuPopup->RemoveAllItems ();

		CMenu menu;
		VERIFY(menu.LoadMenu (IDR_POPUP_TOOLBAR));

		CMenu* pPopup = menu.GetSubMenu(0);
		ASSERT(pPopup != NULL);

		pMenuPopup->GetMenuBar ()->ImportFromMenu (*pPopup, TRUE);
    }

	return TRUE;
}

void CMainFrame::OnViewWorkspace() 
{
	ShowControlBar (&m_wndWorkSpace,
					!(m_wndWorkSpace.GetStyle () & WS_VISIBLE),
					FALSE);
	RecalcLayout ();
}

void CMainFrame::OnUpdateViewWorkspace(CCmdUI* pCmdUI) 
{
	pCmdUI->SetCheck (m_wndWorkSpace.GetStyle () & WS_VISIBLE);
}

//DEL void CMainFrame::OnViewOutput() 
//DEL {
//DEL 	ShowControlBar (&m_wndOutput,
//DEL 					!(m_wndOutput.GetStyle () & WS_VISIBLE),
//DEL 					FALSE);
//DEL 	RecalcLayout ();
//DEL }

void CMainFrame::OnViewToolsbar() 
{
	ShowControlBar(&m_wndToolsBar, !(m_wndToolsBar.GetStyle() & WS_VISIBLE), false);
}

/**
 * CreateViewBar:
 *
 * @param dwStyle 
 * @return BOOL 
 */
BOOL CMainFrame::CreateViewBar(DWORD dwStyle)
{
	const int nDropHeight = 200;
	CRect rcBorders = CRect(0, 0, 0, 0);
	CRect rect;
	
	if (!m_viewBar.CreateEx(this, TBSTYLE_FLAT, dwStyle, rcBorders, IDR_VIEWBAR) ||
		!m_viewBar.LoadToolBar(IDR_VIEWBAR))
	{
		TRACE0("Failed to create toolbar\n");
		return FALSE;      // fail to create
	}

	int nIndex = m_viewBar.GetToolBarCtrl().CommandToIndex(ID_SCALE_COMBO);
	
	m_viewBar.SetButtonInfo(nIndex, ID_SCALE_COMBO, TBBS_SEPARATOR, 100);
	m_viewBar.GetToolBarCtrl().GetItemRect(nIndex, &rect);
	rect.top = 1;
	rect.bottom = rect.top + nDropHeight;
	if(!m_wndScaleCombo.Create(CBS_DROPDOWN | WS_VISIBLE |
		WS_TABSTOP | WS_VSCROLL, rect, &m_viewBar, ID_SCALE_COMBO))
	{
		TRACE(_T("Failed to create combo-box\n"));
		return FALSE;
	}
	
	//  Fill the combo box
	CString szStyle;
	
	if (szStyle.LoadString(IDS_25PERCENT))
		m_wndScaleCombo.AddString((LPCTSTR)szStyle);
	if (szStyle.LoadString(IDS_50PERCENT))
		m_wndScaleCombo.AddString((LPCTSTR)szStyle);
	if (szStyle.LoadString(IDS_100PERCENT))
		m_wndScaleCombo.AddString((LPCTSTR)szStyle);
	if (szStyle.LoadString(IDS_150PERCENT))
		m_wndScaleCombo.AddString((LPCTSTR)szStyle);
	if (szStyle.LoadString(IDS_200PERCENT))
		m_wndScaleCombo.AddString((LPCTSTR)szStyle);
	if (szStyle.LoadString(IDS_500PERCENT))
		m_wndScaleCombo.AddString((LPCTSTR)szStyle);
	
	// set to 100% which is default
	m_wndScaleCombo.SetCurSel(2);
	
	//  Create a font for the combobox
	LOGFONT logFont;
	memset(&logFont, 0, sizeof(logFont));
	
	if (!::GetSystemMetrics(SM_DBCSENABLED)){
		// Since design guide says toolbars are fixed height so is the font.
		logFont.lfHeight = -12;
		logFont.lfWeight = FW_BOLD;
		logFont.lfPitchAndFamily = VARIABLE_PITCH | FF_SWISS;
		CString strDefaultFont;
		strDefaultFont.LoadString(IDS_DEFAULT_FONT);
		lstrcpy(logFont.lfFaceName, strDefaultFont);
		if (!m_Font.CreateFontIndirect(&logFont))
			TRACE0("Could Not create font for combo\n");
		else	m_wndScaleCombo.SetFont(&m_Font);
	}else{
		m_Font.Attach(::GetStockObject(SYSTEM_FONT));
		m_wndScaleCombo.SetFont(&m_Font);
	}

	return TRUE;
}

/**
 * InitStatusBar:
 *
 * @param pIndicators 
 * @param nSize 
 * @param nSeconds 
 * @return BOOL 
 */
BOOL CMainFrame::InitStatusBar(UINT *pIndicators, int nSize, int nSeconds)
{
	// CG: This function was inserted by 'Status Bar' component.
	
	// Create an index for the DATE pane
	m_nDatePaneNo = nSize++;
	pIndicators[m_nDatePaneNo] = ID_INDICATOR_DATE;
	// Create an index for the TIME pane
	m_nTimePaneNo = nSize++;
	nSeconds = 1;
	pIndicators[m_nTimePaneNo] = ID_INDICATOR_TIME;
	
	// TODO: Select an appropriate time interval for updating
	// the status bar when idling.
	m_wndStatusBar.SetTimer(0x1000, nSeconds * 1000, NULL);
	
	return m_wndStatusBar.SetIndicators(pIndicators, nSize);
}

void CMainFrame::OnUpdateDate(CCmdUI* pCmdUI)
{
	// CG: This function was inserted by 'Status Bar' component.

	// Get current date and format it
	CTime time = CTime::GetCurrentTime();
	CString strDate = time.Format(_T("%x"));

	// BLOCK: compute the width of the date string
	CSize size;
	{
		HGDIOBJ hOldFont = NULL;
		HFONT hFont = (HFONT)m_wndStatusBar.SendMessage(WM_GETFONT);
		CClientDC dc(NULL);
		if (hFont != NULL) 
			hOldFont = dc.SelectObject(hFont);
		size = dc.GetTextExtent(strDate);
		if (hOldFont != NULL) 
			dc.SelectObject(hOldFont);
	}

	// Update the pane to reflect the current date
	UINT nID, nStyle;
	int nWidth;
	m_wndStatusBar.GetPaneInfo(m_nDatePaneNo, nID, nStyle, nWidth);
	m_wndStatusBar.SetPaneInfo(m_nDatePaneNo, nID, nStyle, size.cx);
	pCmdUI->SetText(strDate);
	pCmdUI->Enable(TRUE);
}

void CMainFrame::OnUpdateTime(CCmdUI* pCmdUI)
{
	// CG: This function was inserted by 'Status Bar' component.

	// Get current date and format it
	CTime time = CTime::GetCurrentTime();
	CString strTime = time.Format(_T("%X"));

	// BLOCK: compute the width of the date string
	CSize size;
	{
		HGDIOBJ hOldFont = NULL;
		HFONT hFont = (HFONT)m_wndStatusBar.SendMessage(WM_GETFONT);
		CClientDC dc(NULL);
		if (hFont != NULL) 
			hOldFont = dc.SelectObject(hFont);
		size = dc.GetTextExtent(strTime);
		if (hOldFont != NULL) 
			dc.SelectObject(hOldFont);
	}

	// Update the pane to reflect the current time
	UINT nID, nStyle;
	int nWidth;
	m_wndStatusBar.GetPaneInfo(m_nTimePaneNo, nID, nStyle, nWidth);
	m_wndStatusBar.SetPaneInfo(m_nTimePaneNo, nID, nStyle, size.cx);
	pCmdUI->SetText(strTime);
	pCmdUI->Enable(TRUE);
}

void CMainFrame::OnUpdateViewToolsbar(CCmdUI* pCmdUI) 
{
	pCmdUI->SetCheck(m_wndToolsBar.GetStyle() & WS_VISIBLE);	
}

CWorkspaceBar* CMainFrame::GetWorkspaceBar()
{
	return &m_wndWorkSpace;
}

static void ToggleKey(UINT vk)
{
	keybd_event((BYTE)vk, 0, 0, 0);
	keybd_event((BYTE)vk, 0, KEYEVENTF_KEYUP, 0);
}

/**
 * OnCommand:
 *
 * @param wParam 
 * @param lParam 
 * @return BOOL 
 */
BOOL CMainFrame::OnCommand(WPARAM wParam, LPARAM lParam) 
{
	switch (LOWORD(wParam))
	{
		case ID_INDICATOR_SNAP:
		{
			m_bSnap = !m_bSnap;
			
			CChildFrame* pFrame=(CChildFrame*)MDIGetActive();
			CIsDrawEditor* pUMLEditor=((CTinyUMLView*)(pFrame->GetActiveView()))->GetUMLEditor();
			pUMLEditor->SetSnap(m_bSnap);
		}
		break;
		case ID_INDICATOR_NUM:
		{
			ToggleKey(VK_NUMLOCK);
			return 0;
		}
		case ID_INDICATOR_CAPS:
		{
			if (lParam == WM_RBUTTONDBLCLK || lParam == WM_LBUTTONDOWN)
				ToggleKey(VK_CAPITAL);
			return 0;
		}
		case ID_INDICATOR_SCRL:
		{
			if (lParam == WM_RBUTTONDOWN)
				AfxMessageBox(_T("This would be a good place for a popup menu!"));
			else if (lParam == WM_LBUTTONDBLCLK)
				ToggleKey(VK_SCROLL);
			return 0;
		}
		case ID_SEPARATOR:
		{
			AfxMessageBox(_T("This could invoke an options dialog or something..."));
			break;
		}
	};
	
	return CMDIFrameWnd::OnCommand(wParam, lParam);
}

/**
 * OnUpdateIndicatorMousepos:
 *
 * @param pCmdUI 
 * @return void 
 */
void CMainFrame::OnUpdateIndicatorSnap(CCmdUI* pCmdUI) 
{
	pCmdUI->SetRadio((BOOL)!m_bSnap);
}

/**
 * OnUpdateIndicatorMousepos:
 *
 * @param pCmdUI 
 * @return void 
 */
void CMainFrame::OnUpdateIndicatorMousepos(CCmdUI* pCmdUI) 
{
	// figure out the mouse position, for the currently 
	// active view, and tell the status bar
	COleDateTime date = COleDateTime::GetCurrentTime();
	CString sPos = _T("Mouse position\nTime is: ") + date.Format();
	CPoint pt;
	GetCursorPos(&pt);
	// get upfront view
	CMDIChildWnd* pChild = (CMDIChildWnd*)MDIGetActive();
	CView* pView = NULL;
	if (pChild != NULL)
		pView = pChild->GetActiveView();
	if (pView != NULL)
	{
		CRect rc;
		pView->GetClientRect(&rc);
		pView->ScreenToClient(&pt);
		if (rc.PtInRect(pt))
			sPos.Format(_T("x: %d, y: %d"), pt.x, pt.y);
	}
	pCmdUI->SetText(sPos);
}

CDrawingStyleToolBar* CMainFrame::GetDrawingStyleToolBar()
{
	return (&m_wndDrawingStyleToolBar);
}

void CMainFrame::DockControlBarLeftOf(CToolBar *pBar, CToolBar *pLeftOf)
{
	assert(pBar    && "pBar is NULL");
	assert(pLeftOf && "pLeftOf is NULL");

	if(pBar && pLeftOf)
	{
		// get MFC to adjust the dimensions of all docked ToolBars
		// so that GetWindowRect will be accurate
		RecalcLayout();
		CRect rect;
		pLeftOf->GetWindowRect(&rect);
		rect.OffsetRect(1,0);
		DWORD dwStyle=pLeftOf->GetBarStyle();
		UINT n = 0;
		n = (dwStyle & CBRS_ALIGN_TOP) ?		AFX_IDW_DOCKBAR_TOP : n;
		n = (dwStyle & CBRS_ALIGN_BOTTOM && n==0) ?	AFX_IDW_DOCKBAR_BOTTOM : n;
		n = (dwStyle & CBRS_ALIGN_LEFT && n==0) ?	AFX_IDW_DOCKBAR_LEFT : n;
		n = (dwStyle & CBRS_ALIGN_RIGHT && n==0) ?	AFX_IDW_DOCKBAR_RIGHT : n;

		// When we take the default parameters on rect, DockControlBar will dock
		// each Toolbar on a seperate line.  By calculating a rectangle, we in effect
		// are simulating a Toolbar being dragged to that location and docked.
		DockControlBar(pBar,n,&rect);
	}
}