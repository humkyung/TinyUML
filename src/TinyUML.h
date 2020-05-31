// TinyUML.h : main header file for the TINYUML application
//

#if !defined(AFX_TINYUML_H__C8BF78A2_91AF_4810_8D48_329B0487B153__INCLUDED_)
#define AFX_TINYUML_H__C8BF78A2_91AF_4810_8D48_329B0487B153__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CTinyUMLApp:
// See TinyUML.cpp for the implementation of this class
//

class CTinyUMLApp : public CWinApp, public CBCGWorkspace
{
public:
	CTinyUMLApp();

	// Override from CBCGWorkspace
	virtual void PreLoadState ();
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTinyUMLApp)
	public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CTinyUMLApp)
	afx_msg void OnAppAbout();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


extern CTinyUMLApp theApp;

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TINYUML_H__C8BF78A2_91AF_4810_8D48_329B0487B153__INCLUDED_)
