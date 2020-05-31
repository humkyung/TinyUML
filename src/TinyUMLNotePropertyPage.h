#if !defined(AFX_TINYUMLNOTEPROPERTYPAGE_H__9FD1CF38_D92F_45CF_AC0A_87FC8F123D96__INCLUDED_)
#define AFX_TINYUMLNOTEPROPERTYPAGE_H__9FD1CF38_D92F_45CF_AC0A_87FC8F123D96__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// TinyUMLNotePropertyPage.h : header file
//

#include <ColorButton.h>
#include <FontPreviewCombo.h>
/////////////////////////////////////////////////////////////////////////////
// CTinyUMLNotePropertyPage dialog

class CTinyUMLNotePropertyPage : public CPropertyPage
{
	DECLARE_DYNCREATE(CTinyUMLNotePropertyPage)

// Construction
public:
	CTinyUMLNotePropertyPage();
	~CTinyUMLNotePropertyPage();

// Dialog Data
	//{{AFX_DATA(CTinyUMLNotePropertyPage)
	enum { IDD = IDD_PROP_NOTE };
	CString	m_text;
	CColorButton m_ctlTextColor;
	COLORREF m_clrTextColor;
	CFontPreviewCombo m_textFontCombo;
	//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_DATA
	CString m_rTextFont;

// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(CTinyUMLNotePropertyPage)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	// Generated message map functions
	//{{AFX_MSG(CTinyUMLNotePropertyPage)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TINYUMLNOTEPROPERTYPAGE_H__9FD1CF38_D92F_45CF_AC0A_87FC8F123D96__INCLUDED_)
