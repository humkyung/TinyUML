#if !defined(AFX_DRAWINGSTYLETOOLBAR_H__989EDA50_4994_44A1_82D1_7CB900FC9030__INCLUDED_)
#define AFX_DRAWINGSTYLETOOLBAR_H__989EDA50_4994_44A1_82D1_7CB900FC9030__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DrawingStyleToolBar.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDrawingStyleToolBar window
#include "ComboColorPicker.h"
#include "ComboLineStyle.h"
#include "ComboLineWeight.h"
//#include "ComboLineArrow.h"

class CDrawingStyleToolBar : public CToolBar
{
// Construction
public:
	CDrawingStyleToolBar();

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDrawingStyleToolBar)
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CDrawingStyleToolBar();
public:
	BOOL LoadToolBar(UINT lpszResourceName);
	BOOL InitToolBar(CWnd *pParentWnd,UINT lpszResourceName);
	// Generated message map functions
protected:
	//{{AFX_MSG(CDrawingStyleToolBar)
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
public:
	CComboColorPicker m_wndComboColorPicker;
	CComboLineStyle	  m_wndComboLineStyle;
	CComboLineWeight  m_wndComboLineWeight;
	//CComboLineArrow   m_wndComboLineStartArrow,m_wndComboLineEndArrow;
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DRAWINGSTYLETOOLBAR_H__989EDA50_4994_44A1_82D1_7CB900FC9030__INCLUDED_)
