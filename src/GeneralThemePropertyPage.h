#if !defined(AFX_GENERALTHEMEPROPERTYPAGE_H__36B71E6B_1921_4625_9D83_678745FEA8AF__INCLUDED_)
#define AFX_GENERALTHEMEPROPERTYPAGE_H__36B71E6B_1921_4625_9D83_678745FEA8AF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// GeneralThemePropertyPage.h : header file
//
#include <ColorButton.h>
#include <FontPreviewCombo.h>
/////////////////////////////////////////////////////////////////////////////
// CGeneralThemePropertyPage dialog

class CGeneralThemePropertyPage : public CPropertyPage
{
// Construction
public:
	CGeneralThemePropertyPage();   // standard constructor

// Dialog Data
	//{{AFX_DATA(CGeneralThemePropertyPage)
	enum { IDD = IDD_PROP_GENERAL_THEME };
	CColorButton m_ctlNameColor;
	CColorButton m_ctlLineColor;
	CColorButton m_ctlShadowColor;
	
	CFontPreviewCombo m_ctlNameFontCombo;
	//}}AFX_DATA
	COLORREF m_clrNameColor;
	COLORREF m_clrLineColor;
	COLORREF m_clrShadowColor;
	CString m_rNameFont;
	CString m_rNameFontSize;

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGeneralThemePropertyPage)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CGeneralThemePropertyPage)
	virtual BOOL OnInitDialog();
	afx_msg void OnDeltaposSpinNameFontSize(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GENERALTHEMEPROPERTYPAGE_H__36B71E6B_1921_4625_9D83_678745FEA8AF__INCLUDED_)
