#if !defined(AFX_TINYUMLLABELPROPERTYPAGE_H__BDD373A4_C756_4B68_A219_92579511608D__INCLUDED_)
#define AFX_TINYUMLLABELPROPERTYPAGE_H__BDD373A4_C756_4B68_A219_92579511608D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// TinyUMLLabelPropertyPage.h : header file
//

#include "resource.h"

/////////////////////////////////////////////////////////////////////////////
// CTinyUMLLabelPropertyPage dialog

class CTinyUMLLabelPropertyPage : public CPropertyPage
{
	DECLARE_DYNCREATE(CTinyUMLLabelPropertyPage)

// Construction
public:
	CTinyUMLLabelPropertyPage();
	~CTinyUMLLabelPropertyPage();

// Dialog Data
	//{{AFX_DATA(CTinyUMLLabelPropertyPage)
	enum { IDD = IDD_PROP_LABEL };
		// NOTE - ClassWizard will add data members here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	CString	m_label;
	//}}AFX_DATA


// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(CTinyUMLLabelPropertyPage)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	// Generated message map functions
	//{{AFX_MSG(CTinyUMLLabelPropertyPage)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TINYUMLLABELPROPERTYPAGE_H__BDD373A4_C756_4B68_A219_92579511608D__INCLUDED_)
