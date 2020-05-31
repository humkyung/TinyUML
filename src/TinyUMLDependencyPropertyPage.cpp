// TinyUMLDependencyPropertyPage.cpp : implementation file
//

#include "stdafx.h"
#include "TinyUML.h"
#include "TinyUMLDependencyPropertyPage.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTinyUMLDependencyPropertyPage property page

IMPLEMENT_DYNCREATE(CTinyUMLDependencyPropertyPage, CPropertyPage)

CTinyUMLDependencyPropertyPage::CTinyUMLDependencyPropertyPage() : CPropertyPage(CTinyUMLDependencyPropertyPage::IDD)
{
	//{{AFX_DATA_INIT(CTinyUMLDependencyPropertyPage)
	m_bShowArrow = FALSE;
	m_bShowName = FALSE;
	m_name = _T("");
	//}}AFX_DATA_INIT
}

CTinyUMLDependencyPropertyPage::~CTinyUMLDependencyPropertyPage()
{
}

void CTinyUMLDependencyPropertyPage::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CTinyUMLDependencyPropertyPage)
	DDX_Check(pDX, IDC_SHOW_ARROW, m_bShowArrow);
	DDX_Check(pDX, IDC_SHOW_NAME, m_bShowName);
	DDX_Text(pDX, IDC_NAME, m_name);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CTinyUMLDependencyPropertyPage, CPropertyPage)
	//{{AFX_MSG_MAP(CTinyUMLDependencyPropertyPage)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTinyUMLDependencyPropertyPage message handlers
