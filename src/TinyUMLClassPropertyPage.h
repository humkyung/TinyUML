#if !defined(AFX_TINYUMLCLASSPROPERTYPAGE_H__A923FDC5_5383_4CAB_98C5_C636EFC7DF1F__INCLUDED_)
#define AFX_TINYUMLCLASSPROPERTYPAGE_H__A923FDC5_5383_4CAB_98C5_C636EFC7DF1F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// TinyUMLClassPropertyPage.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CTinyUMLClassPropertyPage dialog

class CTinyUMLClassPropertyPage : public CPropertyPage
{
	DECLARE_DYNCREATE(CTinyUMLClassPropertyPage)

// Construction
public:
	CTinyUMLClassPropertyPage();
	~CTinyUMLClassPropertyPage();

// Dialog Data
	//{{AFX_DATA(CTinyUMLClassPropertyPage)
	enum { IDD = IDD_PROP_CLASS };
	BOOL	m_bAbstract;
	CString	m_name;
	CString m_rNote;
	BOOL	m_bShowStereotype;
	CString	m_stereotype;
	BOOL	m_bShowCompartimentName;
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_DATA


// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(CTinyUMLClassPropertyPage)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	// Generated message map functions
	//{{AFX_MSG(CTinyUMLClassPropertyPage)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TINYUMLCLASSPROPERTYPAGE_H__A923FDC5_5383_4CAB_98C5_C636EFC7DF1F__INCLUDED_)
