#if !defined(AFX_TINYUMLGENERALIZATIONPROPERTYPAGE_H__EEBC5EF4_0F37_4622_96EE_23B62ADDDE2B__INCLUDED_)
#define AFX_TINYUMLGENERALIZATIONPROPERTYPAGE_H__EEBC5EF4_0F37_4622_96EE_23B62ADDDE2B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// TinyUMLGeneralizationPropertyPage.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CTinyUMLGeneralizationPropertyPage dialog

class CTinyUMLGeneralizationPropertyPage : public CPropertyPage
{
	DECLARE_DYNCREATE(CTinyUMLGeneralizationPropertyPage)

// Construction
public:
	CTinyUMLGeneralizationPropertyPage();
	~CTinyUMLGeneralizationPropertyPage();

// Dialog Data
	//{{AFX_DATA(CTinyUMLGeneralizationPropertyPage)
	enum { IDD = IDD_PROP_GENERALIZATION };
	BOOL m_bRealize;
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_DATA


// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(CTinyUMLGeneralizationPropertyPage)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	// Generated message map functions
	//{{AFX_MSG(CTinyUMLGeneralizationPropertyPage)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TINYUMLGENERALIZATIONPROPERTYPAGE_H__EEBC5EF4_0F37_4622_96EE_23B62ADDDE2B__INCLUDED_)
