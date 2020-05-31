#if !defined(AFX_CLASSTHEMEPROPERTYPAGE_H__6C5C08E2_9FFB_44AF_AA8F_76BDC990DC35__INCLUDED_)
#define AFX_CLASSTHEMEPROPERTYPAGE_H__6C5C08E2_9FFB_44AF_AA8F_76BDC990DC35__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ClassThemePropertyPage.h : header file
//

#include <ColorButton.h>
#include <FontPreviewCombo.h>
/////////////////////////////////////////////////////////////////////////////
// CClassThemePropertyPage dialog

class CClassThemePropertyPage : public CPropertyPage
{
	DECLARE_DYNCREATE(CClassThemePropertyPage)
// Construction
public:
	CClassThemePropertyPage();   // standard constructor

// Dialog Data
	//{{AFX_DATA(CClassThemePropertyPage)
	enum { IDD = IDD_PROP_CLASS_THEME };
	// NOTE: the ClassWizard will add data members here
	CColorButton m_ctlClassTitleColor;
	CColorButton m_ctlClassBackColor;
	CColorButton m_ctlFolderColor;
	CColorButton m_ctlAttributeColor;
	CColorButton m_ctlMethodColor;
	
	CFontPreviewCombo m_attributeFontCombo;
	CFontPreviewCombo m_methodFontCombo;
	CString m_rMemberFont;
	CString m_rMemberFontSize;
	CString m_rMethodFont;
	CString m_rMethodFontSize;
	//}}AFX_DATA

	COLORREF m_clrTitleColor;
	COLORREF m_clrBackColor;
	COLORREF m_clrFolderColor;
	COLORREF m_clrAttributeColor;
	COLORREF m_clrMethodColor;
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CClassThemePropertyPage)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CClassThemePropertyPage)
	virtual BOOL OnInitDialog();
	afx_msg void OnDeltaposSpinAttributeFontSize(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDeltaposSpinMethodFontSize(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CLASSTHEMEPROPERTYPAGE_H__6C5C08E2_9FFB_44AF_AA8F_76BDC990DC35__INCLUDED_)
