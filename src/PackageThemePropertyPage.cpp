// PackageThemePropertyPage.cpp : implementation file
//

#include "stdafx.h"
#include "TinyUML.h"
#include "PackageThemePropertyPage.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPackageThemePropertyPage dialog


CPackageThemePropertyPage::CPackageThemePropertyPage() : CPropertyPage(CPackageThemePropertyPage::IDD)
{
	//{{AFX_DATA_INIT(CPackageThemePropertyPage)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CPackageThemePropertyPage::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPackageThemePropertyPage)
	DDX_Control(pDX,IDC_BUTTON_FILL_COLOR,m_ctlFillColor);
	DDX_Control(pDX,IDC_COMBO_NAME_FONT,m_ctlNameFontCombo);
	//}}AFX_DATA_MAP
	DDX_ColorButton(pDX,IDC_BUTTON_FILL_COLOR,m_clrFillColor);
	DDX_FontPreviewCombo (pDX, IDC_COMBO_NAME_FONT, m_rNameFont);
}


BEGIN_MESSAGE_MAP(CPackageThemePropertyPage, CPropertyPage)
	//{{AFX_MSG_MAP(CPackageThemePropertyPage)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPackageThemePropertyPage message handlers
BOOL CPackageThemePropertyPage::OnInitDialog() 
{
	CPropertyPage::OnInitDialog();
	
	m_ctlNameFontCombo.SetFontHeight (20);

	int nPos = 0;
	if((nPos = m_ctlNameFontCombo.FindString(0, m_rNameFont)) != CB_ERR)
	{
		m_ctlNameFontCombo.SetCurSel(nPos);
	}

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}