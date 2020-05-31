#if !defined(AFX_TINYUMLMMETHODSPROPERTYPAGE_H__5F0045F1_45B6_454D_A3A3_2FF70BA99049__INCLUDED_)
#define AFX_TINYUMLMMETHODSPROPERTYPAGE_H__5F0045F1_45B6_454D_A3A3_2FF70BA99049__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// TinyUMLMMethodsPropertyPage.h : header file
//

#include <CJFlatComboBox.h>
#include <EditFlat.h>
#include <ReportCtrl.h>
#include <BtnST.h>
#include "TinyUMLClass.h"
/////////////////////////////////////////////////////////////////////////////
// CTinyUMLMethodsPropertyPage dialog

class CTinyUMLMethodsPropertyPage : public CPropertyPage
{
	DECLARE_DYNCREATE(CTinyUMLMethodsPropertyPage)

// Construction
public:
	CTinyUMLMethodsPropertyPage();
	~CTinyUMLMethodsPropertyPage();

// Dialog Data
	//{{AFX_DATA(CTinyUMLMethodsPropertyPage)
	enum { IDD = IDD_PROP_METHODS };
	CArray<CTinyUMLClass::Method, const CTinyUMLClass::Method &> m_methods;
	CCJFlatComboBox m_wndMethodType;
	CEditFlat m_wndMethodName;
	CCJFlatComboBox m_wndMethodAccess;
	CButtonST m_btnAddMethod;
	CButtonST m_btnSetMethod;
	CReportCtrl m_ctrlMethodsList;
	CButtonST m_btnEditMethod;
	CButtonST m_btnRemoveMethod;
	
	CString	m_type;
	CString	m_name;
	int	m_access;
	int	m_property;
	BOOL	m_bShowMethods;
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_DATA


// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(CTinyUMLMethodsPropertyPage)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

	BOOL m_isVirtual;
	BOOL m_isPure;
	BOOL m_isConst;
	BOOL m_isInline;
	BOOL m_isStatic;
// Implementation
protected:
	virtual void UpdateMethod(long index, bool bSave);
//	virtual long currentMethod() const { return m_methodsList.GetCaretIndex(); }
	// Generated message map functions
	//{{AFX_MSG(CTinyUMLMethodsPropertyPage)
	virtual BOOL OnInitDialog();
	afx_msg void OnSelchangeMethodType();
	afx_msg void OnChangeMethodName();
	afx_msg void OnSelchangeMethodAccess();
	afx_msg void OnAddMethod();
	afx_msg void OnSetMethod();
	afx_msg void OnEditMethod();
	afx_msg void OnRemoveMethod();
	afx_msg void OnSelchangeMethods(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TINYUMLMMETHODSPROPERTYPAGE_H__5F0045F1_45B6_454D_A3A3_2FF70BA99049__INCLUDED_)
