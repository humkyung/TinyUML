// ClassParser.h : main header file for the CLASSPARSER DLL
//

#if !defined(AFX_CLASSPARSER_H__562AB7FF_0DAB_459D_9CA7_89FEF775A341__INCLUDED_)
#define AFX_CLASSPARSER_H__562AB7FF_0DAB_459D_9CA7_89FEF775A341__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CClassParserApp
// See ClassParser.cpp for the implementation of this class
//

class CClassParserApp : public CWinApp
{
public:
	CClassParserApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CClassParserApp)
	//}}AFX_VIRTUAL

	//{{AFX_MSG(CClassParserApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CLASSPARSER_H__562AB7FF_0DAB_459D_9CA7_89FEF775A341__INCLUDED_)
