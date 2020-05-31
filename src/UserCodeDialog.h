#if !defined(AFX_USERCODEDIALOG_H__543220E4_CCF4_11D4_8006_0080C7484D8B__INCLUDED_)
#define AFX_USERCODEDIALOG_H__543220E4_CCF4_11D4_8006_0080C7484D8B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// UserCodeDialog.h : header file
//
#include "CodeEdit.h"

/////////////////////////////////////////////////////////////////////////////
// UserCodeDialog dialog

class AFX_EXT_CLASS UserCodeDialog : public CDialog
{
// Construction
public:
	UserCodeDialog(Class* pClass, int section, bool header, int start = 0, int end = 0, CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(UserCodeDialog)
	enum { IDD = IDD_USERCODE };
	CString	m_code;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(UserCodeDialog)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
    Class* m_pClass;
    int m_section;
    bool m_header;
    int m_start;
    int m_end;

    CFont m_font;
    CRect m_rect;
    CRect m_codeRect;
    CRect m_okRect;
    CRect m_cancelRect;
    CCodeEdit m_codeEdit;

	// Generated message map functions
	//{{AFX_MSG(UserCodeDialog)
	virtual BOOL OnInitDialog();
	afx_msg void OnGetMinMaxInfo(MINMAXINFO FAR* lpMMI);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	virtual void OnOK();
	afx_msg void OnShowWindow(BOOL bShow, UINT nStatus);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_USERCODEDIALOG_H__543220E4_CCF4_11D4_8006_0080C7484D8B__INCLUDED_)
