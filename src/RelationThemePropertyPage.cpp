// RelationThemePropertyPage.cpp : implementation file
//

#include "stdafx.h"
#include "TinyUML.h"
#include "RelationThemePropertyPage.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CRelationThemePropertyPage dialog


CRelationThemePropertyPage::CRelationThemePropertyPage() : CPropertyPage(CRelationThemePropertyPage::IDD)
{
	//{{AFX_DATA_INIT(CRelationThemePropertyPage)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CRelationThemePropertyPage::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CRelationThemePropertyPage)
	DDX_Control(pDX,IDC_BUTTON_SYMBOL_COLOR,m_ctlEndSymbolColor);
	//}}AFX_DATA_MAP
	DDX_ColorButton(pDX,IDC_BUTTON_SYMBOL_COLOR,m_clrEndSymbolColor);
}


BEGIN_MESSAGE_MAP(CRelationThemePropertyPage, CPropertyPage)
	//{{AFX_MSG_MAP(CRelationThemePropertyPage)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CRelationThemePropertyPage message handlers
