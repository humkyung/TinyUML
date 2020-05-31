#if !defined(AFX_CLASSEDIT_H__45B99A3B_8400_4DC9_ACE5_F89DCD042094__INCLUDED_)
#define AFX_CLASSEDIT_H__45B99A3B_8400_4DC9_ACE5_F89DCD042094__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ClassEdit.h : header file
//
#include "TinyUMLClass.h"
/////////////////////////////////////////////////////////////////////////////
// CClassEdit window

class CClassEdit : public CEdit
{
// Construction
public:
	CClassEdit();

// Attributes
public:
private:
	CTinyUMLEntity* m_pEnt;
// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CClassEdit)
	public:
	//}}AFX_VIRTUAL

// Implementation
public:
	void RegisterCallbackFunc(void (*f)(CTinyUMLEntity* pEnt,const CString& rString));
	void SetAssociate(CTinyUMLEntity* pEnt);
	virtual ~CClassEdit();

	// Generated message map functions
protected:
	//{{AFX_MSG(CClassEdit)
	afx_msg void OnKillfocus();
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CLASSEDIT_H__45B99A3B_8400_4DC9_ACE5_F89DCD042094__INCLUDED_)
