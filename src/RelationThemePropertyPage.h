#if !defined(AFX_RELATIONTHEMEPROPERTYPAGE_H__D2FB3E3A_D536_4000_B0F8_C1B5D6407083__INCLUDED_)
#define AFX_RELATIONTHEMEPROPERTYPAGE_H__D2FB3E3A_D536_4000_B0F8_C1B5D6407083__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// RelationThemePropertyPage.h : header file
//
#include <ColorButton.h>
/////////////////////////////////////////////////////////////////////////////
// CRelationThemePropertyPage dialog

class CRelationThemePropertyPage : public CPropertyPage
{
// Construction
public:
	CRelationThemePropertyPage();   // standard constructor

// Dialog Data
	//{{AFX_DATA(CRelationThemePropertyPage)
	enum { IDD = IDD_PROP_RELATION_THEME };
	CColorButton m_ctlEndSymbolColor;
	//}}AFX_DATA
	COLORREF m_clrEndSymbolColor;

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRelationThemePropertyPage)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CRelationThemePropertyPage)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_RELATIONTHEMEPROPERTYPAGE_H__D2FB3E3A_D536_4000_B0F8_C1B5D6407083__INCLUDED_)
