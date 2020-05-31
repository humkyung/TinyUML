#if !defined(AFX_TINYUMLDEPENDENCYPROPERTYPAGE_H__7624D02D_1999_42D3_B36A_A73350C68F9A__INCLUDED_)
#define AFX_TINYUMLDEPENDENCYPROPERTYPAGE_H__7624D02D_1999_42D3_B36A_A73350C68F9A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// TinyUMLDependencyPropertyPage.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CTinyUMLDependencyPropertyPage dialog

class CTinyUMLDependencyPropertyPage : public CPropertyPage
{
	DECLARE_DYNCREATE(CTinyUMLDependencyPropertyPage)

// Construction
public:
	CTinyUMLDependencyPropertyPage();
	~CTinyUMLDependencyPropertyPage();

// Dialog Data
	//{{AFX_DATA(CTinyUMLDependencyPropertyPage)
	enum { IDD = IDD_PROP_DEPENDENCY };
	BOOL	m_bShowArrow;
	BOOL	m_bShowName;
	CString	m_name;
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_DATA


// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(CTinyUMLDependencyPropertyPage)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	// Generated message map functions
	//{{AFX_MSG(CTinyUMLDependencyPropertyPage)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TINYUMLDEPENDENCYPROPERTYPAGE_H__7624D02D_1999_42D3_B36A_A73350C68F9A__INCLUDED_)
