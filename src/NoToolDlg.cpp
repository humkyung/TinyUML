// NoToolDlg.cpp : implementation file
//

#include "stdafx.h"
#include "TinyUML.h"
#include "ToolShell.h"
#include "NoToolDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CNoToolDlg dialog


CNoToolDlg::CNoToolDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CNoToolDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CNoToolDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CNoToolDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CNoToolDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CNoToolDlg, CDialog)
	//{{AFX_MSG_MAP(CNoToolDlg)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CNoToolDlg message handlers

/**
 * Show:
 *
 * @return void 
 */
void CNoToolDlg::Show()
{
	CToolShell* pParent=CToolShell::GetInstance();
	if(NULL != pParent){
		pParent->SetDlg(this);
		pParent->SetWindowText(_T("NoTool"));
	}
}
