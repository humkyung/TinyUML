// ChildFrm.cpp : implementation of the CChildFrame class
//

#include "stdafx.h"
#include "TinyUML.h"
#include "MainFrm.h"
#include "ChildFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CChildFrame

IMPLEMENT_DYNCREATE(CChildFrame, CMDIChildWnd)

BEGIN_MESSAGE_MAP(CChildFrame, CMDIChildWnd)
	//{{AFX_MSG_MAP(CChildFrame)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CChildFrame construction/destruction

CChildFrame::CChildFrame()
{
	// TODO: add member initialization code here
	
}

CChildFrame::~CChildFrame()
{
}

BOOL CChildFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	if( !CMDIChildWnd::PreCreateWindow(cs) )
		return FALSE;

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CChildFrame diagnostics

#ifdef _DEBUG
void CChildFrame::AssertValid() const
{
	CMDIChildWnd::AssertValid();
}

void CChildFrame::Dump(CDumpContext& dc) const
{
	CMDIChildWnd::Dump(dc);
}

#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CChildFrame message handlers

void CChildFrame::ActivateFrame(int nCmdShow) 
{
	// if another window is open, use default 
	if(GetMDIFrame()->MDIGetActive()) 
		CMDIChildWnd::ActivateFrame(nCmdShow); 
        else // else open maximized. 
		CMDIChildWnd::ActivateFrame(SW_SHOWMAXIMIZED);
	//CMDIChildWnd::ActivateFrame(nCmdShow);
}

/**
 * WindowProc:
 *
 * @param message 
 * @param wParam 
 * @param lParam 
 * @return LRESULT 
 */
LRESULT CChildFrame::WindowProc(UINT message, WPARAM wParam, LPARAM lParam) 
{
	BOOL bMax;
	((CMDIFrameWnd*)GetParentFrame())->MDIGetActive(&bMax);
	if(bMax && (message==WM_NCPAINT || message==174)) return 0;
	
	return CMDIChildWnd::WindowProc(message, wParam, lParam);
}
