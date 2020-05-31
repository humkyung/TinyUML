// TinyUMLNotePropertyPage.cpp : implementation file
//

#include "stdafx.h"
#include "TinyUML.h"
#include "TinyUMLNotePropertyPage.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTinyUMLNotePropertyPage property page

IMPLEMENT_DYNCREATE(CTinyUMLNotePropertyPage, CPropertyPage)

CTinyUMLNotePropertyPage::CTinyUMLNotePropertyPage() : CPropertyPage(CTinyUMLNotePropertyPage::IDD)
{
	//{{AFX_DATA_INIT(CTinyUMLNotePropertyPage)
		m_text = _T("");
		m_rTextFont = _T("");
	//}}AFX_DATA_INIT
}

CTinyUMLNotePropertyPage::~CTinyUMLNotePropertyPage()
{
}

void CTinyUMLNotePropertyPage::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CTinyUMLNotePropertyPage)
	DDX_Text(pDX, IDC_TEXT, m_text);
	DDX_Control(pDX,IDC_BUTTON_NOTE_COLOR,m_ctlTextColor);
	DDX_Control(pDX,IDC_COMBO_NOTE_FONT,m_textFontCombo);
	//}}AFX_DATA_MAP
	DDX_ColorButton(pDX,IDC_BUTTON_NOTE_COLOR,m_clrTextColor);
	DDX_FontPreviewCombo (pDX, IDC_COMBO_NOTE_FONT, m_rTextFont);
}


BEGIN_MESSAGE_MAP(CTinyUMLNotePropertyPage, CPropertyPage)
	//{{AFX_MSG_MAP(CTinyUMLNotePropertyPage)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTinyUMLNotePropertyPage message handlers

/**
 * OnInitDialog:
 *
 * @return BOOL 
 */
BOOL CTinyUMLNotePropertyPage::OnInitDialog() 
{
	CPropertyPage::OnInitDialog();
	
	m_textFontCombo.SetFontHeight (20);
	int nPos = 0;
	if((nPos = m_textFontCombo.FindString(0, m_rTextFont)) != CB_ERR)
	{
		m_textFontCombo.SetCurSel(nPos);
	}

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
