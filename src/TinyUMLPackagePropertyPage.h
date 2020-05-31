#if !defined(AFX_TINYUMLPACKAGEPROPERTYPAGE_H__8BDFF9A8_C6DB_4AED_AC41_4ECF5CF0E8B0__INCLUDED_)
#define AFX_TINYUMLPACKAGEPROPERTYPAGE_H__8BDFF9A8_C6DB_4AED_AC41_4ECF5CF0E8B0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// TinyUMLPackagePropertyPage.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CTinyUMLPackagePropertyPage dialog

class CTinyUMLPackagePropertyPage : public CPropertyPage
{
	DECLARE_DYNCREATE(CTinyUMLPackagePropertyPage)

// Construction
public:
	CTinyUMLPackagePropertyPage();
	~CTinyUMLPackagePropertyPage();

// Dialog Data
	//{{AFX_DATA(CTinyUMLPackagePropertyPage)
	enum { IDD = IDD_PROP_PACKAGE };
	CString	m_name;
		// NOTE - ClassWizard will add data members here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_DATA


// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(CTinyUMLPackagePropertyPage)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	// Generated message map functions
	//{{AFX_MSG(CTinyUMLPackagePropertyPage)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TINYUMLPACKAGEPROPERTYPAGE_H__8BDFF9A8_C6DB_4AED_AC41_4ECF5CF0E8B0__INCLUDED_)
