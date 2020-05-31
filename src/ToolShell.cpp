// ToolShell.cpp : implementation file
//

#include "stdafx.h"
#include <assert.h>
#include "TinyUML.h"
#include "ToolShell.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

CToolShell* CToolShell::m_pInst = NULL;
/////////////////////////////////////////////////////////////////////////////
// CToolShell

CToolShell::CToolShell()
{
	m_pCurrentTool = NULL;
}

CToolShell::~CToolShell()
{
}


BEGIN_MESSAGE_MAP(CToolShell, CWnd)
	//{{AFX_MSG_MAP(CToolShell)
	ON_WM_CREATE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// CToolShell message handlers

/**
 * Create:
 *
 * @param pParent 
 * @return void 
 */
void CToolShell::Create(CWnd *pParent)
{
	assert(pParent && "pParent is NULL");

	
	CString s = AfxRegisterWndClass( CS_NOCLOSE, NULL, NULL, NULL );
	CRect rect;
	pParent->GetWindowRect( rect );
	rect.top += 80;
	rect.left = rect.right - 240;
	CWnd::CreateEx( WS_EX_TOOLWINDOW, s, "Tool", WS_POPUP | WS_BORDER | WS_CAPTION | WS_VISIBLE, rect, pParent, NULL );
}

/**
 * GetInstance:
 *
 * @return CToolShell* 
 */
CToolShell* CToolShell::GetInstance()
{
	if(NULL == CToolShell::m_pInst){
		CToolShell::m_pInst = new CToolShell;
		//if(CToolShell::m_pInst) CToolShell::m_pInst->Create(AfxGetMainWnd());
	}
	return CToolShell::m_pInst;
}

/**
 * SetDlg:
 *
 * @param pDlg 
 * @return void 
 */
void CToolShell::SetDlg(CDialog *pDlg)
{
	assert(pDlg && "pDlg is NULL");
	
	if(pDlg){
		if(NULL != m_pCurrentTool) m_pCurrentTool->ShowWindow(SW_HIDE);
		
		CRect rect(0,0,0,0);
		if (pDlg){
			pDlg->GetWindowRect( rect );
		}else{
			m_dlgNoTool.GetWindowRect( rect );
		}
		
		// Move ourselves
		CalcWindowRect( rect, 0 );
		SetWindowPos( NULL, 0,0, rect.Width(), rect.Height(), SWP_NOACTIVATE | SWP_NOMOVE | SWP_NOZORDER );
		
		// Now make sure the dlg is show and in the correct position
		if (pDlg){
			pDlg->ShowWindow( SW_SHOWNA );
			pDlg->SetWindowPos( &wndTop, 0,0, 0, 0, SWP_NOACTIVATE | SWP_NOSIZE );
		}
		
		if ((pDlg != &m_dlgNoTool) && m_dlgNoTool.m_hWnd != NULL){
			m_dlgNoTool.ShowWindow( SW_HIDE );
		}
		
		m_pCurrentTool = pDlg;
	}
}

/**
 * OnCreate:
 *
 * @param lpCreateStruct 
 * @return int 
 */
int CToolShell::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CWnd::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	m_dlgNoTool.Create(CNoToolDlg::IDD,this);
	//if(!m_dlgEditMethodCode.Create(CEditMethodCodeDlg::IDD,this)){
	//	AfxMessageBox("Fail to create edit method code dialog");
	//}
	SetDlg(&m_dlgNoTool);
	
	return 0;
}
