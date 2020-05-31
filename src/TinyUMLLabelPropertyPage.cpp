// TinyUMLLabelPropertyPage.cpp : implementation file
//

#include "stdafx.h"
#include "TinyUML.h"
#include "TinyUMLLabelPropertyPage.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTinyUMLLabelPropertyPage property page

IMPLEMENT_DYNCREATE(CTinyUMLLabelPropertyPage, CPropertyPage)

CTinyUMLLabelPropertyPage::CTinyUMLLabelPropertyPage() : CPropertyPage(CTinyUMLLabelPropertyPage::IDD)
{
	//{{AFX_DATA_INIT(CTinyUMLLabelPropertyPage)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}

CTinyUMLLabelPropertyPage::~CTinyUMLLabelPropertyPage()
{
}

void CTinyUMLLabelPropertyPage::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CTinyUMLLabelPropertyPage)
	DDX_Text(pDX , IDC_LABEL , m_label);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CTinyUMLLabelPropertyPage, CPropertyPage)
	//{{AFX_MSG_MAP(CTinyUMLLabelPropertyPage)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTinyUMLLabelPropertyPage message handlers
