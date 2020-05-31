#if !defined(AFX_NOTOOLDLG_H__1021461D_C589_4D9A_9F33_3CFCC4801030__INCLUDED_)
#define AFX_NOTOOLDLG_H__1021461D_C589_4D9A_9F33_3CFCC4801030__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// NoToolDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CNoToolDlg dialog

class CNoToolDlg : public CDialog
{
// Construction
public:
	void Show();
	CNoToolDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CNoToolDlg)
	enum { IDD = IDD_NO_TOOL };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CNoToolDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CNoToolDlg)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_NOTOOLDLG_H__1021461D_C589_4D9A_9F33_3CFCC4801030__INCLUDED_)
