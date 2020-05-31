// GeneralThemePropertyPage.cpp : implementation file
//

#include "stdafx.h"
#include "TinyUML.h"
#include "GeneralThemePropertyPage.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CGeneralThemePropertyPage dialog


CGeneralThemePropertyPage::CGeneralThemePropertyPage() : CPropertyPage(CGeneralThemePropertyPage::IDD)
{
	//{{AFX_DATA_INIT(CGeneralThemePropertyPage)
	m_rNameFontSize = "0";
	//}}AFX_DATA_INIT
}

void CGeneralThemePropertyPage::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CGeneralThemePropertyPage)
	DDX_Control(pDX,IDC_BUTTON_NAME_COLOR,m_ctlNameColor);
	DDX_Control(pDX,IDC_BUTTON_LINE_COLOR,m_ctlLineColor);
	DDX_Control(pDX,IDC_BUTTON_SHADOW_COLOR,m_ctlShadowColor);
	
	DDX_Control(pDX,IDC_COMBO_NAME_FONT,m_ctlNameFontCombo);
	DDX_Text(pDX,IDC_EDIT_NAME_FONT_SIZE,m_rNameFontSize);
	//}}AFX_DATA_MAP
	DDX_ColorButton(pDX,IDC_BUTTON_NAME_COLOR,m_clrNameColor);
	DDX_ColorButton(pDX,IDC_BUTTON_LINE_COLOR,m_clrLineColor);
	DDX_ColorButton(pDX,IDC_BUTTON_SHADOW_COLOR,m_clrShadowColor);
	
	DDX_FontPreviewCombo (pDX, IDC_COMBO_NAME_FONT, m_rNameFont);
}

BEGIN_MESSAGE_MAP(CGeneralThemePropertyPage, CPropertyPage)
	//{{AFX_MSG_MAP(CGeneralThemePropertyPage)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_NAME_FONT_SIZE, OnDeltaposSpinNameFontSize)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CGeneralThemePropertyPage message handlers

BOOL CGeneralThemePropertyPage::OnInitDialog() 
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

/**
 * OnDeltaposSpinNameFontSize:
 *
 * @param pNMHDR 
 * @param pResult 
 * @return void 
 */
void CGeneralThemePropertyPage::OnDeltaposSpinNameFontSize(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_UPDOWN* pNMUpDown = (NM_UPDOWN*)pNMHDR;
	
	long nPos = atoi(m_rNameFontSize);
	nPos += pNMUpDown->iDelta;
	m_rNameFontSize.Format("%d",nPos);
	UpdateData(FALSE);
	
	*pResult = 0;
}
