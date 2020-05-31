// TinyUMLClassPropertyPage.cpp : implementation file
//

#include "stdafx.h"
#include "TinyUML.h"
#include "TinyUMLClassPropertyPage.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTinyUMLClassPropertyPage property page

IMPLEMENT_DYNCREATE(CTinyUMLClassPropertyPage, CPropertyPage)

CTinyUMLClassPropertyPage::CTinyUMLClassPropertyPage() : CPropertyPage(CTinyUMLClassPropertyPage::IDD)
{
	//{{AFX_DATA_INIT(CTinyUMLClassPropertyPage)
	m_bAbstract = FALSE;
	m_name = _T("");
	m_rNote= _T("");
	m_bShowStereotype = FALSE;
	m_stereotype = _T("");
	m_bShowCompartimentName = FALSE;
	//}}AFX_DATA_INIT
}

CTinyUMLClassPropertyPage::~CTinyUMLClassPropertyPage()
{
}

void CTinyUMLClassPropertyPage::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CTinyUMLClassPropertyPage)
	DDX_Check(pDX, IDC_ABSTRACT_CLASS, m_bAbstract);
	DDX_Text(pDX, IDC_NAME, m_name);
	DDX_Check(pDX, IDC_SHOW_STEREOTYPE, m_bShowStereotype);
	DDX_CBString(pDX, IDC_STEREOTYPE, m_stereotype);
	DDX_Check(pDX, IDC_SHOW_COMPARTIMENTS_NAME, m_bShowCompartimentName);
	DDX_Text(pDX,IDC_EDIT_NOTE,m_rNote);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CTinyUMLClassPropertyPage, CPropertyPage)
	//{{AFX_MSG_MAP(CTinyUMLClassPropertyPage)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTinyUMLClassPropertyPage message handlers
