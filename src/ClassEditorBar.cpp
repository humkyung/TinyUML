// OutputBar.cpp : implementation of the CClassEditorBar class
//

#include "stdafx.h"
#include "TinyUML.h"
#include "ClassEditorBar.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CClassEditorBar

BEGIN_MESSAGE_MAP(CClassEditorBar, CBCGSizingControlBar)
	//{{AFX_MSG_MAP(CClassEditorBar)
	ON_WM_CREATE()
	ON_WM_SIZE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CClassEditorBar construction/destruction

CClassEditorBar::CClassEditorBar()
{
	// TODO: add one-time construction code here

}

CClassEditorBar::~CClassEditorBar()
{
}

/////////////////////////////////////////////////////////////////////////////
// CClassEditorBar message handlers

int CClassEditorBar::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CBCGSizingControlBar::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	CRect rectDummy;
	rectDummy.SetRectEmpty ();
	
	// Create tabs window:
	if (!m_wndTabs.Create (CBCGTabWnd::STYLE_3D, rectDummy, this, 1))
	{
		TRACE0("Failed to create workspace tab window\n");
		return -1;      // fail to create
	}
	m_wndTabs.SetImageList (IDB_CLASS_EDITOR, 16, RGB (255, 0, 255));
	
	// Create tree windows.
	// TODO: create your own tab windows here:
	const DWORD dwViewStyle = WS_CHILD | WS_VISIBLE | ES_MULTILINE | WS_HSCROLL | WS_VSCROLL;
	
	if (!m_wndEdit.Create (dwViewStyle, rectDummy, &m_wndTabs, 2))
	{
		TRACE0("Failed to create workspace view\n");
		return -1;      // fail to create
	}
		
	// Attach tree windows to tab:
	m_wndTabs.AddTab (&m_wndEdit, _T("Edit"), 0 /* Image number */);

	return 0;
}

void CClassEditorBar::OnSize(UINT nType, int cx, int cy) 
{
	CBCGSizingControlBar::OnSize(nType, cx, cy);

	// Tab control should cover a whole client area:
	// Tab control should cover a whole client area:
	m_wndTabs.SetWindowPos (NULL, -1, -1, cx, cy,
		SWP_NOMOVE | SWP_NOACTIVATE | SWP_NOZORDER);
}

