// ThemePropSheet.h: interface for the CThemePropSheet class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_THEMEPROPSHEET_H__34A81658_E3EB_4D58_AF4D_A3BCF77BAA05__INCLUDED_)
#define AFX_THEMEPROPSHEET_H__34A81658_E3EB_4D58_AF4D_A3BCF77BAA05__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CThemePropSheet : public CPropertySheet
{
	DECLARE_DYNAMIC(CThemePropSheet)
public:
	CThemePropSheet(UINT nIDCaption, CWnd* pParentWnd = NULL, UINT iSelectPage = 0);
	CThemePropSheet(LPCTSTR pszCaption, CWnd* pParentWnd = NULL, UINT iSelectPage = 0);
	//CThemePropSheet();
	virtual ~CThemePropSheet();

protected:
	DECLARE_MESSAGE_MAP()
};

#endif // !defined(AFX_THEMEPROPSHEET_H__34A81658_E3EB_4D58_AF4D_A3BCF77BAA05__INCLUDED_)
