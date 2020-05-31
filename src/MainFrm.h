// MainFrm.h : interface of the CMainFrame class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MAINFRM_H__CEDBCA48_5B74_4432_A65B_C383E3399780__INCLUDED_)
#define AFX_MAINFRM_H__CEDBCA48_5B74_4432_A65B_C383E3399780__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <CJFlatComboBox.h>
#include <IsStatusBar.h>
#include "DrawingStyleToolBar.h"
#include "WorkspaceBar.h"

#define CMDIFrameWnd CBCGMDIFrameWnd

class CMainFrame : public CMDIFrameWnd
{
	DECLARE_DYNAMIC(CMainFrame)
public:
	CMainFrame();

// Attributes
public:
	CCJFlatComboBox m_wndScaleCombo;
protected:
	CFont m_Font;
// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMainFrame)
	public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual BOOL OnCommand(WPARAM wParam, LPARAM lParam);
	//}}AFX_VIRTUAL

// Implementation
public:
	CDrawingStyleToolBar* GetDrawingStyleToolBar();
	CWorkspaceBar* GetWorkspaceBar();
	int m_nDatePaneNo;
	int m_nTimePaneNo;
	virtual ~CMainFrame();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:  // control bar embedded members
	CBCGMenuBar	m_wndMenuBar;
	//CIsStatusBar	m_wndStatusBar;
	CStatusBar	m_wndStatusBar;
	/*CBCGToolBar*/CToolBar	m_wndToolBar;
	CToolBar	m_wndDrawToolBar;
	CToolBar	m_wndToolsBar;
	CToolBar	m_viewBar;
	CDrawingStyleToolBar	m_wndDrawingStyleToolBar;
	//CBCGToolBar	m_wndObjectBar;
	CWorkspaceBar	m_wndWorkSpace;
	//CClassEditorBar	m_wndOutput;

	bool m_bSnap;
// Generated message map functions
protected:
	BOOL CreateViewBar(DWORD dwStyle);
	//{{AFX_MSG(CMainFrame)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnUpdateViewToolsbar(CCmdUI* pCmdUI);
	//}}AFX_MSG
	afx_msg void OnViewCustomize();
	afx_msg LRESULT OnToolbarReset(WPARAM,LPARAM);
	afx_msg LRESULT OnToolbarContextMenu(WPARAM,LPARAM);
	afx_msg void OnViewWorkspace();
	afx_msg void OnUpdateViewWorkspace(CCmdUI* pCmdUI);
	afx_msg void OnViewToolsbar();
	afx_msg void OnUpdateIndicatorSnap(CCmdUI* pCmdUI);
	afx_msg void OnUpdateDate(CCmdUI* pCmdUI);
	afx_msg void OnUpdateTime(CCmdUI* pCmdUI);
	afx_msg void OnUpdateIndicatorMousepos(CCmdUI* pCmdUI);
	DECLARE_MESSAGE_MAP()

	virtual BOOL OnShowPopupMenu (CBCGPopupMenu* pMenuPopup);
	void DockControlBarLeftOf(CToolBar *pBar, CToolBar *pLeftOf);
private:
	BOOL InitStatusBar(UINT *pIndicators, int nSize, int nSeconds);
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MAINFRM_H__CEDBCA48_5B74_4432_A65B_C383E3399780__INCLUDED_)
