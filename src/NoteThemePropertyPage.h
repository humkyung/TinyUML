#if !defined(AFX_CNoteThemePropertyPage_H__765508D4_8726_44E8_B733_B2E56212B603__INCLUDED_)
#define AFX_CNoteThemePropertyPage_H__765508D4_8726_44E8_B733_B2E56212B603__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// CNoteThemePropertyPage.h : header file
//

#include <ColorButton.h>
#include <FontPreviewCombo.h>
/////////////////////////////////////////////////////////////////////////////
// CNoteThemePropertyPage dialog

class CNoteThemePropertyPage : public CPropertyPage
{
// Construction
public:
	CNoteThemePropertyPage();   // standard constructor

// Dialog Data
	//{{AFX_DATA(CNoteThemePropertyPage)
	enum { IDD = IDD_PROP_NOTE_THEME };
	CColorButton m_ctlTextColor;
	COLORREF m_clrTextColor;
	CFontPreviewCombo m_textFontCombo;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CNoteThemePropertyPage)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CNoteThemePropertyPage)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CNoteThemePropertyPage_H__765508D4_8726_44E8_B733_B2E56212B603__INCLUDED_)
