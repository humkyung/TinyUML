#if !defined(AFX_PACKAGETHEMEPROPERTYPAGE_H__B564B624_78E2_4D9F_A8F8_E65F2EE207F1__INCLUDED_)
#define AFX_PACKAGETHEMEPROPERTYPAGE_H__B564B624_78E2_4D9F_A8F8_E65F2EE207F1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// PackageThemePropertyPage.h : header file
//
#include <ColorButton.h>
#include <FontPreviewCombo.h>
/////////////////////////////////////////////////////////////////////////////
// CPackageThemePropertyPage dialog

class CPackageThemePropertyPage : public CPropertyPage
{
// Construction
public:
	CPackageThemePropertyPage();   // standard constructor

// Dialog Data
	//{{AFX_DATA(CPackageThemePropertyPage)
	enum { IDD = IDD_PROP_PACKAGE_THEME };
	CColorButton m_ctlFillColor;
	CFontPreviewCombo m_ctlNameFontCombo;
	//}}AFX_DATA
	COLORREF m_clrFillColor;
	CString m_rNameFont;

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPackageThemePropertyPage)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CPackageThemePropertyPage)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PACKAGETHEMEPROPERTYPAGE_H__B564B624_78E2_4D9F_A8F8_E65F2EE207F1__INCLUDED_)
