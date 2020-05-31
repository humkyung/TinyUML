#if !defined(AFX_TINYUMLATTRIBUTESPROPERTYPAGE_H__564B39C0_31F7_42B9_9249_DA0FB7E3D39A__INCLUDED_)
#define AFX_TINYUMLATTRIBUTESPROPERTYPAGE_H__564B39C0_31F7_42B9_9249_DA0FB7E3D39A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// TinyUMLAttributesPropertyPage.h : header file
//
#include <CJFlatComboBox.h>
#include <EditFlat.h>
#include <ReportCtrl.h>
#include <BtnST.h>
#include "TinyUMLClass.h"
/////////////////////////////////////////////////////////////////////////////
// CTinyUMLAttributesPropertyPage dialog

class CTinyUMLAttributesPropertyPage : public CPropertyPage
{
	DECLARE_DYNCREATE(CTinyUMLAttributesPropertyPage)

// Construction
public:
	CTinyUMLAttributesPropertyPage();
	~CTinyUMLAttributesPropertyPage();

// Dialog Data
	//{{AFX_DATA(CTinyUMLAttributesPropertyPage)
	enum { IDD = IDD_PROP_ATTRIBUTES };
	CArray<CTinyUMLClass::Member, const CTinyUMLClass::Member &> m_attributes;
	CCJFlatComboBox m_wndTypeCombo;
	CEditFlat m_wndAttributeName;
	CReportCtrl m_attributesList;
	CCJFlatComboBox m_wndAccessCombo;
	CButtonST m_btnAddAttribute;
	CButtonST m_btnSetAttribute;
	CButtonST m_btnRemoveAttribute;

	CString	m_type;
	CString	m_name;
	BOOL	m_bShowAttributes;
	int m_access;

	BOOL m_isStatic;
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_DATA


// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(CTinyUMLAttributesPropertyPage)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL
private:
	static CArray<CString,const CString &> m_TypesArray;
// Implementation
protected:
	virtual void UpdateAttribute(long index, bool bSave);
	//virtual long currentAttribute(){ return m_attributesList.GetFirstSelectedItemPosition()->; }
	// Generated message map functions
	//{{AFX_MSG(CTinyUMLAttributesPropertyPage)
	afx_msg void OnAddAttribute();
	afx_msg void OnSetAttribute();
	afx_msg void OnRemoveAttribute();
	afx_msg void OnDeltaposMoveAttribute(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnSelchangeMemeberAccess();
	afx_msg void OnChangeAttributeName();
	afx_msg void OnChangeMemberInitial();
	afx_msg void OnSelchangeAttributes(NMHDR* pNMHDR, LRESULT* pResult);
	virtual BOOL OnInitDialog();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TINYUMLATTRIBUTESPROPERTYPAGE_H__564B39C0_31F7_42B9_9249_DA0FB7E3D39A__INCLUDED_)
