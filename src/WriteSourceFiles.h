#if !defined(AFX_WRITESOURCEFILES_H__B9693D1A_47D7_4BEC_848E_03E19EC1CAC5__INCLUDED_)
#define AFX_WRITESOURCEFILES_H__B9693D1A_47D7_4BEC_848E_03E19EC1CAC5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// WriteSourceFiles.h : header file
//

#include <ReportCtrl.h>
#include <BtnST.h>
/////////////////////////////////////////////////////////////////////////////
// CWriteSourceFiles dialog

class CWriteSourceFiles : public CDialog
{
// Construction
public:
	void Add(CIsDrawEntity* pEnt);
	CWriteSourceFiles(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CWriteSourceFiles)
	enum { IDD = IDD_WRITE_SOURCES };
	CButtonST m_btnSelectRepository;
	CString m_rRepository;
	CReportCtrl m_ctlFiles;
	CButtonST m_btnOk;
	CButtonST m_btnCancel;
	//}}AFX_DATA
	CArray<CIsDrawEntity*,CIsDrawEntity*> m_entitySet;

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CWriteSourceFiles)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	void Write();
	// Generated message map functions
	//{{AFX_MSG(CWriteSourceFiles)
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	afx_msg void OnButtonSelectRepository();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	void WriteMethodDeclaration(CFile& file,CTinyUMLClass::Method& method);
	void WriteCPPFile(CTinyUMLClass* pClass);
	void WriteMethodDefine(CFile& file,const CString& rClassName,CTinyUMLClass::Method* pMethod);
	void WriteHeaderFile(CTinyUMLClass* pClass);
	void WriteClass(CTinyUMLClass* pClass);

	CArray<CTinyUMLClass::Method,CTinyUMLClass::Method> m_publicMethod;
	CArray<CTinyUMLClass::Method,CTinyUMLClass::Method> m_protectedMethod;
	CArray<CTinyUMLClass::Method,CTinyUMLClass::Method> m_privateMethod;
	CArray<CTinyUMLClass::Member,CTinyUMLClass::Member> m_publicAttribute;
	CArray<CTinyUMLClass::Member,CTinyUMLClass::Member> m_protectedAttribute;
	CArray<CTinyUMLClass::Member,CTinyUMLClass::Member> m_privateAttribute;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_WRITESOURCEFILES_H__B9693D1A_47D7_4BEC_848E_03E19EC1CAC5__INCLUDED_)
