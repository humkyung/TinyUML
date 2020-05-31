// WorkspaceBar.h : interface of the CWorkspaceBar class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_WORKSPACEBAR_H__5EA32CCB_F28A_4DE5_823A_B6F26F2F9A93__INCLUDED_)
#define AFX_WORKSPACEBAR_H__5EA32CCB_F28A_4DE5_823A_B6F26F2F9A93__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "TinyUMLClass.h"
#include "ClassTreeCtrl.h"
#include "FileViewTreeCtrl.h"
#include "ContentFile.h"

class CWorkspaceBar : public CBCGSizingControlBar
{
public:
	CWorkspaceBar();

// Attributes
protected:
	CBCGTabWnd	m_wndTabs;

	CImageList	m_imgList;
	CClassTreeCtrl	  m_wndTree;
	CFileViewTreeCtrl m_wndFileView;
	CTypedPtrMap<CMapPtrToPtr,CTinyUMLEntity*,HTREEITEM> m_map;
	HTREEITEM m_hRoot;
// Operations
public:
	
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CWorkspaceBar)
	//}}AFX_VIRTUAL

// Implementation
public:
	void RedrawFileViewTree();
	void AddFileToFileView(CContentFile* pFile);
	void RedrawClassTree();
	void Clear();
	void SetTitle(const CString strTitle);
	void ModifyClassProperty(CTinyUMLClass* pClass);
	void AttachClass(CTinyUMLClass* pClass);
	void DetachClass(CTinyUMLClass* pClass);
	virtual ~CWorkspaceBar();
private:
// Generated message map functions
protected:
	//{{AFX_MSG(CWorkspaceBar)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_WORKSPACEBAR_H__5EA32CCB_F28A_4DE5_823A_B6F26F2F9A93__INCLUDED_)
