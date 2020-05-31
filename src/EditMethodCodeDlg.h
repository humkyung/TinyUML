#if !defined(AFX_EDITMETHODCODEDLG_H__912CCCA0_909D_40E6_8A69_0F24A6B019A6__INCLUDED_)
#define AFX_EDITMETHODCODEDLG_H__912CCCA0_909D_40E6_8A69_0F24A6B019A6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// EditMethodCodeDlg.h : header file
//

#include "TinyUMLClass.h"
#include "./SHEditCtrl_1_0_133/SHEditCtrl.h"
/////////////////////////////////////////////////////////////////////////////
// CEditMethodCodeDlg dialog

class CEditMethodCodeDlg : public CDialog
{
// Construction
public:
	void SetMethodDefine(const CString& rDefine);
	void SetMethodName(const CString& rName);
	void Show();
	CEditMethodCodeDlg(CTinyUMLClass::Method* pMethod,CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CEditMethodCodeDlg)
	enum { IDD = IDD_EDIT_METHOD_CODE };
	CString m_rComment;
	CString m_rBegin;
	CString m_rDefine;
	CString m_rEnd;
	//}}AFX_DATA
	HWND m_hSHEdit;

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEditMethodCodeDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual BOOL DestroyWindow();
protected:

	// Generated message map functions
	//{{AFX_MSG(CEditMethodCodeDlg)
	virtual void OnCancel();
	afx_msg void OnOK();
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	CString m_rName;
	CTinyUMLClass::Method* m_pMethod;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EDITMETHODCODEDLG_H__912CCCA0_909D_40E6_8A69_0F24A6B019A6__INCLUDED_)
