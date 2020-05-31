// ClassThemePropertyPage.cpp : implementation file
//

#include "stdafx.h"
#include "TinyUML.h"
#include "ClassThemePropertyPage.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

IMPLEMENT_DYNCREATE(CClassThemePropertyPage, CPropertyPage)
/////////////////////////////////////////////////////////////////////////////
// CClassThemePropertyPage dialog


CClassThemePropertyPage::CClassThemePropertyPage()
	: CPropertyPage(CClassThemePropertyPage::IDD)
{
	//{{AFX_DATA_INIT(CClassThemePropertyPage)
	m_rMemberFontSize = "0";
	m_rMemberFont = _T("");
	m_rMethodFontSize = "0";
	m_rMethodFont = _T("");
	//}}AFX_DATA_INIT
}


void CClassThemePropertyPage::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CClassThemePropertyPage)
	DDX_Control(pDX,IDC_BUTTON_CLASS_TITLE_COLOR,m_ctlClassTitleColor);
	DDX_Control(pDX,IDC_BUTTON_CLASS_BACK_COLOR,m_ctlClassBackColor);
	DDX_Control(pDX,IDC_BUTTON_FOLDER_COLOR,m_ctlFolderColor);
	DDX_Control(pDX,IDC_BUTTON_ATTRIBUTE_COLOR,m_ctlAttributeColor);
	DDX_Control(pDX,IDC_BUTTON_METHOD_COLOR,m_ctlMethodColor);

	DDX_Control(pDX,IDC_COMBO_ATTRIBUTE_FONT,m_attributeFontCombo);
	DDX_Text(pDX,IDC_EDIT_ATTRIBUTE_FONT_SIZE,m_rMemberFontSize);
	DDX_Control(pDX,IDC_COMBO_METHOD_FONT,m_methodFontCombo);
	DDX_Text(pDX,IDC_EDIT_METHOD_FONT_SIZE,m_rMemberFontSize);
	//}}AFX_DATA_MAP
	COLORREF ThrowAwayColor;

	DDX_ColorButton(pDX, IDC_BUTTON_CLASS_TITLE_COLOR, m_clrTitleColor);
	DDX_ColorButton(pDX, IDC_BUTTON_CLASS_BACK_COLOR, m_clrBackColor);
	DDX_ColorButton(pDX, IDC_BUTTON_FOLDER_COLOR, m_clrFolderColor);
	DDX_ColorButton(pDX, IDC_BUTTON_ATTRIBUTE_COLOR, m_clrAttributeColor);
	DDX_ColorButton(pDX, IDC_BUTTON_METHOD_COLOR, m_clrMethodColor);

	DDX_FontPreviewCombo (pDX, IDC_COMBO_ATTRIBUTE_FONT, m_rMemberFont);
	DDX_FontPreviewCombo (pDX, IDC_COMBO_METHOD_FONT, m_rMethodFont);
}

BEGIN_MESSAGE_MAP(CClassThemePropertyPage, CPropertyPage)
	//{{AFX_MSG_MAP(CClassThemePropertyPage)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_ATTRIBUTE_FONT_SIZE, OnDeltaposSpinAttributeFontSize)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_METHOD_FONT_SIZE, OnDeltaposSpinMethodFontSize)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CClassThemePropertyPage message handlers

BOOL CClassThemePropertyPage::OnInitDialog() 
{
	CPropertyPage::OnInitDialog();
	
	m_attributeFontCombo.SetFontHeight (20);
	m_methodFontCombo.SetFontHeight (20);

	int nPos = 0;
	if((nPos = m_attributeFontCombo.FindString(0, m_rMemberFont)) != CB_ERR)
	{
		m_attributeFontCombo.SetCurSel(nPos);
	}
	
	if((nPos = m_methodFontCombo.FindString(0, m_rMethodFont)) != CB_ERR)
	{
		m_methodFontCombo.SetCurSel(nPos);
	}

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CClassThemePropertyPage::OnDeltaposSpinAttributeFontSize(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_UPDOWN* pNMUpDown = (NM_UPDOWN*)pNMHDR;
	
	long nPos = atoi(m_rMemberFontSize);
	nPos += pNMUpDown->iDelta;
	m_rMemberFontSize.Format("%d",nPos);
	UpdateData(FALSE);
	
	*pResult = 0;
}

/**
 * OnDeltaposSpinMethodFontSize:
 *
 * @param pNMHDR 
 * @param pResult 
 * @return void 
 */
void CClassThemePropertyPage::OnDeltaposSpinMethodFontSize(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_UPDOWN* pNMUpDown = (NM_UPDOWN*)pNMHDR;

	long nPos = atoi(m_rMethodFontSize);
	nPos += pNMUpDown->iDelta;
	m_rMethodFontSize.Format("%d",nPos);
	UpdateData(FALSE);

	*pResult = 0;
}
