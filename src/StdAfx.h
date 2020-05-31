// stdafx.h : include file for standard system include files,
//  or project specific include files that are used frequently, but
//      are changed infrequently
//

#if !defined(AFX_STDAFX_H__C1A0056A_94A7_4E47_8E1F_6256DC0F2FA1__INCLUDED_)
#define AFX_STDAFX_H__C1A0056A_94A7_4E47_8E1F_6256DC0F2FA1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define VC_EXTRALEAN		// Exclude rarely-used stuff from Windows headers

#include <afxwin.h>         // MFC core and standard components
#include <afxext.h>         // MFC extensions
#include <afxadv.h>
#include <afxdisp.h>        // MFC Automation classes
#include <afxdtctl.h>		// MFC support for Internet Explorer 4 Common Controls
#ifndef _AFX_NO_AFXCMN_SUPPORT
#include <afxcmn.h>			// MFC support for Windows Common Controls
#endif // _AFX_NO_AFXCMN_SUPPORT


#include <bcgcb.h>			// BCG Control Bar
#include <IsDrawCtrlHost.h>
#include "TinyUMLEditor.h"

extern CTinyUMLEditor* TinyGetCurEditor();
//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STDAFX_H__C1A0056A_94A7_4E47_8E1F_6256DC0F2FA1__INCLUDED_)
