// OutputBar.h : interface of the CClassEditorBar class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_CLASSEDITORBAR_H__F0B63544_F3DF_44C4_9AF1_F52EB625D524__INCLUDED_)
#define AFX_CLASSEDITORBAR_H__F0B63544_F3DF_44C4_9AF1_F52EB625D524__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <editorctrl/TinyEditorWnd.h>
class CClassEditorBar : public CBCGSizingControlBar
{
public:
	CClassEditorBar();

// Attributes
protected:
	CBCGTabWnd m_wndTabs;
	CEdit m_wndEdit;
// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CClassEditorBar)
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CClassEditorBar();

// Generated message map functions
protected:
	//{{AFX_MSG(CClassEditorBar)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CLASSEDITORBAR_H__F0B63544_F3DF_44C4_9AF1_F52EB625D524__INCLUDED_)
