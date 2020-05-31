// ThemePropSheet.cpp: implementation of the CThemePropSheet class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "TinyUML.h"
#include "ThemePropSheet.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

IMPLEMENT_DYNAMIC(CThemePropSheet, CPropertySheet)
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CThemePropSheet::CThemePropSheet(UINT nIDCaption, CWnd* pParentWnd, UINT iSelectPage)
	:CPropertySheet(nIDCaption, pParentWnd, iSelectPage)
{
}

CThemePropSheet::CThemePropSheet(LPCTSTR pszCaption, CWnd* pParentWnd, UINT iSelectPage)
	:CPropertySheet(pszCaption, pParentWnd, iSelectPage)
{
}

CThemePropSheet::~CThemePropSheet()
{

}

BEGIN_MESSAGE_MAP(CThemePropSheet, CPropertySheet)
	//{{AFX_MSG_MAP(CThemePropSheet)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()