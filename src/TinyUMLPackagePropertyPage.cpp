// TinyUMLPackagePropertyPage.cpp : implementation file
//

#include "stdafx.h"
#include "TinyUML.h"
#include "TinyUMLPackagePropertyPage.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTinyUMLPackagePropertyPage property page

IMPLEMENT_DYNCREATE(CTinyUMLPackagePropertyPage, CPropertyPage)

CTinyUMLPackagePropertyPage::CTinyUMLPackagePropertyPage() : CPropertyPage(CTinyUMLPackagePropertyPage::IDD)
{
	//{{AFX_DATA_INIT(CTinyUMLPackagePropertyPage)
		m_name = _T("");
	//}}AFX_DATA_INIT
}

CTinyUMLPackagePropertyPage::~CTinyUMLPackagePropertyPage()
{
}

void CTinyUMLPackagePropertyPage::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CTinyUMLPackagePropertyPage)
		DDX_Text(pDX, IDC_NAME, m_name);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CTinyUMLPackagePropertyPage, CPropertyPage)
	//{{AFX_MSG_MAP(CTinyUMLPackagePropertyPage)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTinyUMLPackagePropertyPage message handlers
