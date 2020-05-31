#if !defined(AFX_TINYUMLASSOCIATIONPROPERTYPAGE_H__66F1E082_A5AC_4B37_AB9D_F52B425698D3__INCLUDED_)
#define AFX_TINYUMLASSOCIATIONPROPERTYPAGE_H__66F1E082_A5AC_4B37_AB9D_F52B425698D3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// TinyUMLAssociationPropertyPage.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CTinyUMLAssociationPropertyPage dialog

class CTinyUMLAssociationPropertyPage : public CPropertyPage
{
	DECLARE_DYNCREATE(CTinyUMLAssociationPropertyPage)

// Construction
public:
	CTinyUMLAssociationPropertyPage();
	~CTinyUMLAssociationPropertyPage();

// Dialog Data
	//{{AFX_DATA(CTinyUMLAssociationPropertyPage)
	enum { IDD = IDD_PROP_ASSOCIATION };
	BOOL	m_bAggregation;
	BOOL	m_bNavigable;
	BOOL	m_bShowDestMultiplicity;
	BOOL	m_bShowSrcMultiplicity;
	CString	m_destMultiplicity;
	CString	m_srcMultiplicity;
	CString	m_name;
	BOOL	m_bShowName;
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_DATA


// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(CTinyUMLAssociationPropertyPage)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	// Generated message map functions
	//{{AFX_MSG(CTinyUMLAssociationPropertyPage)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TINYUMLASSOCIATIONPROPERTYPAGE_H__66F1E082_A5AC_4B37_AB9D_F52B425698D3__INCLUDED_)
