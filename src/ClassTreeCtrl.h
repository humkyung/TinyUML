#if !defined(AFX_CLASSTREECTRL_H__802B49C1_8585_4A09_90F8_B206E760BA73__INCLUDED_)
#define AFX_CLASSTREECTRL_H__802B49C1_8585_4A09_90F8_B206E760BA73__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ClassTreeCtrl.h : header file
//

#define IS_CLASS	0x01
#define IS_ATTRIBUTE	0x02
#define IS_METHOD	0x03

/////////////////////////////////////////////////////////////////////////////
// CClassTreeCtrl window

class CClassTreeCtrl : public CTreeCtrl
{
// Construction
public:
	CClassTreeCtrl();

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CClassTreeCtrl)
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CClassTreeCtrl();

	// Generated message map functions
protected:
	//{{AFX_MSG(CClassTreeCtrl)
	afx_msg void OnKeydown(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnSelchanged(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDblclk(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CLASSTREECTRL_H__802B49C1_8585_4A09_90F8_B206E760BA73__INCLUDED_)
