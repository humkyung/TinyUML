// TinyUMLGeneralizationPropertyPage.cpp : implementation file
//

#include "stdafx.h"
#include "TinyUML.h"
#include "TinyUMLGeneralizationPropertyPage.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTinyUMLGeneralizationPropertyPage property page

IMPLEMENT_DYNCREATE(CTinyUMLGeneralizationPropertyPage, CPropertyPage)

CTinyUMLGeneralizationPropertyPage::CTinyUMLGeneralizationPropertyPage() : CPropertyPage(CTinyUMLGeneralizationPropertyPage::IDD)
{
	//{{AFX_DATA_INIT(CTinyUMLGeneralizationPropertyPage)
		m_bRealize = FALSE;
	//}}AFX_DATA_INIT
}

CTinyUMLGeneralizationPropertyPage::~CTinyUMLGeneralizationPropertyPage()
{
}

void CTinyUMLGeneralizationPropertyPage::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CTinyUMLGeneralizationPropertyPage)
		DDX_Check(pDX, IDC_REALIZE, m_bRealize);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CTinyUMLGeneralizationPropertyPage, CPropertyPage)
	//{{AFX_MSG_MAP(CTinyUMLGeneralizationPropertyPage)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTinyUMLGeneralizationPropertyPage message handlers
