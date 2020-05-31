// TinyUMLAssociationPropertyPage.cpp : implementation file
//

#include "stdafx.h"
#include "TinyUML.h"
#include "TinyUMLAssociationPropertyPage.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTinyUMLAssociationPropertyPage property page

IMPLEMENT_DYNCREATE(CTinyUMLAssociationPropertyPage, CPropertyPage)

CTinyUMLAssociationPropertyPage::CTinyUMLAssociationPropertyPage() : CPropertyPage(CTinyUMLAssociationPropertyPage::IDD)
{
	//{{AFX_DATA_INIT(CTinyUMLAssociationPropertyPage)
	m_bAggregation = FALSE;
	m_bNavigable = FALSE;
	m_bShowDestMultiplicity = FALSE;
	m_bShowSrcMultiplicity = FALSE;
	m_destMultiplicity = _T("");
	m_srcMultiplicity = _T("");
	m_name = _T("");
	m_bShowName = FALSE;
	//}}AFX_DATA_INIT
}

CTinyUMLAssociationPropertyPage::~CTinyUMLAssociationPropertyPage()
{
}

void CTinyUMLAssociationPropertyPage::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CTinyUMLAssociationPropertyPage)
	DDX_Check(pDX, IDC_AGGREGATION, m_bAggregation);
	DDX_Check(pDX, IDC_NAVIGABLE, m_bNavigable);
	DDX_Check(pDX, IDC_SHOW_DEST_MULTIPLICITY, m_bShowDestMultiplicity);
	DDX_Check(pDX, IDC_SHOW_SRC_MULTIPLICITY, m_bShowSrcMultiplicity);
	DDX_CBString(pDX, IDC_DEST_MULTIPLICITY, m_destMultiplicity);
	DDX_CBString(pDX, IDC_SOURCE_MULTIPLICITY, m_srcMultiplicity);
	DDX_Text(pDX, IDC_NAME, m_name);
	DDX_Check(pDX, IDC_SHOW_NAME, m_bShowName);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CTinyUMLAssociationPropertyPage, CPropertyPage)
	//{{AFX_MSG_MAP(CTinyUMLAssociationPropertyPage)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTinyUMLAssociationPropertyPage message handlers
