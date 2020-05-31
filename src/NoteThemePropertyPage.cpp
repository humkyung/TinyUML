// CNoteThemePropertyPage.cpp : implementation file
//

#include "stdafx.h"
#include "TinyUML.h"
#include "NoteThemePropertyPage.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CNoteThemePropertyPage dialog


CNoteThemePropertyPage::CNoteThemePropertyPage(): CPropertyPage(CNoteThemePropertyPage::IDD)
{
	//{{AFX_DATA_INIT(CNoteThemePropertyPage)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CNoteThemePropertyPage::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CNoteThemePropertyPage)
	DDX_Control(pDX,IDC_BUTTON_NOTE_COLOR,m_ctlTextColor);
	DDX_Control(pDX,IDC_COMBO_NOTE_FONT,m_textFontCombo);
	//}}AFX_DATA_MAP
	DDX_ColorButton(pDX,IDC_BUTTON_NOTE_COLOR,m_clrTextColor);
}


BEGIN_MESSAGE_MAP(CNoteThemePropertyPage, CPropertyPage)
	//{{AFX_MSG_MAP(CNoteThemePropertyPage)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CNoteThemePropertyPage message handlers

BOOL CNoteThemePropertyPage::OnInitDialog() 
{
	CPropertyPage::OnInitDialog();
	
	m_textFontCombo.SetFontHeight (20);
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
