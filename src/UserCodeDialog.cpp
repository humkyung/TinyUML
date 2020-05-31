// UserCodeDialog.cpp : implementation file
//
// Copyright 2002, Jimmy Venema
// All rights are reserved. Reproduction in whole or part is prohibited
// without the written consent of the copyright owner.
// Philips Digital Video Systems, Eindhoven, The Netherlands.
// Distributed under the zlib/libpng License
//

#include "stdafx.h"
#include "ClassBuilderDoc.h"
#include "UserCodeDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// UserCodeDialog dialog


UserCodeDialog::UserCodeDialog(Class* pClass, int section, bool header, int start, int end, CWnd* pParent /*=NULL*/)
	: CDialog(UserCodeDialog::IDD, pParent)
    , m_codeEdit(pClass->GetDataModel())
    , m_rect(0, 0, 0, 0)
{
	//{{AFX_DATA_INIT(UserCodeDialog)
	m_code = _T("");
	//}}AFX_DATA_INIT

    m_pClass = pClass;
    m_section = section;
    m_header = header;
    m_start = start;
    m_end = end;

    if (m_header)
    {
        if (m_section == 1)
        {
            m_code = m_pClass->GetHUser1();
        }
        else if (m_section == 2)
        {
            m_code = m_pClass->GetHUser2();
        }
        else if (m_section == 3)
        {
            m_code = m_pClass->GetHUser3();
        }
    }
    else
    {
        if (m_section == 1)
        {
            m_code = m_pClass->GetCppUser1();
        }
        else if (m_section == 2)
        {
            m_code = m_pClass->GetCppUser2();
        }
        else if (m_section == 3)
        {
            m_code = m_pClass->GetCppUser3();
        }
    }
}


void UserCodeDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(UserCodeDialog)
	DDX_Text(pDX, IDC_CODE, m_code);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(UserCodeDialog, CDialog)
	//{{AFX_MSG_MAP(UserCodeDialog)
	ON_WM_GETMINMAXINFO()
	ON_WM_SIZE()
	ON_WM_SHOWWINDOW()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// UserCodeDialog message handlers

BOOL UserCodeDialog::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
    m_codeEdit.SubclassDlgItem(IDC_CODE, this);
    m_codeEdit.StoreNewState();

    GetClientRect(m_rect);
    GetDlgItem(IDC_CODE)->GetWindowRect(m_codeRect);
    GetDlgItem(IDOK)->GetWindowRect(m_okRect);
    GetDlgItem(IDCANCEL)->GetWindowRect(m_cancelRect);
    ScreenToClient(m_codeRect);
    ScreenToClient(m_okRect);
    ScreenToClient(m_cancelRect);

    m_font.CreatePointFont(100, "courier");
    GetDlgItem(IDC_CODE)->SetFont(&m_font);

    CString text;
    if (m_header)
    {
        if (m_section == 1)
        {
            text.Format("User section 1 '%s'", m_pClass->GetHFileWithoutPath());
        }
        else if (m_section == 2)
        {
            text.Format("User section 2 '%s'", m_pClass->GetHFileWithoutPath());
        }
        else if (m_section == 3)
        {
            text.Format("User section 3 '%s'", m_pClass->GetHFileWithoutPath());
        }
    }
    else
    {
        if (m_section == 1)
        {
            text.Format("User section 1 '%s'", m_pClass->GetCppFileWithoutPath());
        }
        else if (m_section == 2)
        {
            text.Format("User section 2 '%s'", m_pClass->GetCppFileWithoutPath());
        }
        else if (m_section == 3)
        {
            text.Format("User section 3 '%s'", m_pClass->GetCppFileWithoutPath());
        }
    }
    SetWindowText(text);

    m_codeEdit.SetSel(m_start, m_end);
    m_codeEdit.LineScroll(m_codeEdit.LineFromChar(m_start));
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void UserCodeDialog::OnGetMinMaxInfo(MINMAXINFO FAR* lpMMI) 
{
    lpMMI->ptMinTrackSize.x = 340;
    lpMMI->ptMinTrackSize.y = 200;

    CDialog::OnGetMinMaxInfo(lpMMI);
}

void UserCodeDialog::OnSize(UINT nType, int cx, int cy) 
{
    CDialog::OnSize(nType, cx, cy);

    if (m_rect.right && m_rect.bottom)
    {
        CRect rect;
        GetClientRect(rect);
        CRect grow(0, 0, rect.right-m_rect.right, rect.bottom-m_rect.bottom);
        CPoint offset(rect.right-m_rect.right, rect.bottom-m_rect.bottom);

        GetDlgItem(IDC_CODE)->MoveWindow(m_codeRect + grow);
        GetDlgItem(IDOK)->MoveWindow(m_okRect + offset);
        GetDlgItem(IDCANCEL)->MoveWindow(m_cancelRect + offset);
        Invalidate(FALSE);
    }
}

void UserCodeDialog::OnOK() 
{
	if (!UpdateData(TRUE))
	{
		return;
	}
	EndDialog(IDOK);

    bool update = false;
    if (m_header)
    {
        if (m_section == 1)
        {
            if (m_code != m_pClass->GetHUser1())
            {
                m_pClass->SaveState(1);
                update = true;
                m_pClass->SetHUser1(m_code);
            }
        }
        else if (m_section == 2)
        {
            if (m_code != m_pClass->GetHUser2())
            {
                m_pClass->SaveState(1);
                update = true;
                m_pClass->SetHUser2(m_code);
            }
        }
        else if (m_section == 3)
        {
            if (m_code != m_pClass->GetHUser3())
            {
                m_pClass->SaveState(1);
                update = true;
                m_pClass->SetHUser3(m_code);
            }
        }
    }
    else
    {
        if (m_section == 1)
        {
            if (m_code != m_pClass->GetCppUser1())
            {
                m_pClass->SaveState(1);
                update = true;
                m_pClass->SetCppUser1(m_code);
            }
        }
        else if (m_section == 2)
        {
            if (m_code != m_pClass->GetCppUser2())
            {
                m_pClass->SaveState(1);
                update = true;
                m_pClass->SetCppUser2(m_code);
            }
        }
        else if (m_section == 3)
        {
            if (m_code != m_pClass->GetCppUser3())
            {
                m_pClass->SaveState(1);
                update = true;
                m_pClass->SetCppUser3(m_code);
            }
        }
    }

    if (update)
    {
        m_pClass->GetDataModelDoc()->GetDocument()->SetModifiedFlag();
        m_pClass->GetDataModelDoc()->MarkLastUndo();
    }
}

void UserCodeDialog::OnShowWindow(BOOL bShow, UINT nStatus) 
{
	CDialog::OnShowWindow(bShow, nStatus);
	
	GetDlgItem(IDC_CODE)->SetFocus();	
}
