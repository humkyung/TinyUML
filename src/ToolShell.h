#if !defined(AFX_TOOLSHELL_H__6E17B8FB_1790_42C7_9502_C4D0AC243055__INCLUDED_)
#define AFX_TOOLSHELL_H__6E17B8FB_1790_42C7_9502_C4D0AC243055__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ToolShell.h : header file
//

#include "NoToolDlg.h"
#include "EditMethodCodeDlg.h"

/////////////////////////////////////////////////////////////////////////////
// CToolShell window

class CToolShell : public CWnd
{
// Construction
public:
	CToolShell();

// Attributes
public:
	CNoToolDlg m_dlgNoTool;
	//CEditMethodCodeDlg m_dlgEditMethodCode;
// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CToolShell)
	//}}AFX_VIRTUAL

// Implementation
public:
	void SetDlg(CDialog *pDlg);
	static CToolShell* GetInstance();
	void Create(CWnd *pParent);
	virtual ~CToolShell();

	// Generated message map functions
protected:
	//{{AFX_MSG(CToolShell)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	CDialog* m_pCurrentTool;
	static CToolShell* m_pInst;
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TOOLSHELL_H__6E17B8FB_1790_42C7_9502_C4D0AC243055__INCLUDED_)
