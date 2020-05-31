#if !defined(AFX_FILEVIEWTREECTRL_H__802B49C1_8585_4A09_90F8_B206E760BA73__INCLUDED_)
#define AFX_FILEVIEWTREECTRL_H__802B49C1_8585_4A09_90F8_B206E760BA73__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ClassTreeCtrl.h : header file
//

#include "ContentFile.h"

#define IS_CLASS	0x01
#define IS_ATTRIBUTE	0x02
#define IS_METHOD	0x03

/////////////////////////////////////////////////////////////////////////////
// CFileViewTreeCtrl window

class CFileViewTreeCtrl : public CTreeCtrl
{
// Construction
public:
	CFileViewTreeCtrl();

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFileViewTreeCtrl)
	//}}AFX_VIRTUAL

// Implementation
public:
	void InitFileViewTree();
	void AddFile(CContentFile* pFile);
	void SetTitle(const CString& rTitle);
	virtual ~CFileViewTreeCtrl();

	// Generated message map functions
protected:
	//{{AFX_MSG(CFileViewTreeCtrl)
	afx_msg void OnKeydown(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnSelchanged(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDblclk(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
private:
	int m_nSysImgSize;
	BOOL GetSysImgList();
	CImageList m_imgList;
	HTREEITEM  m_hRoot;
	HTREEITEM  m_hSourceFile;
	HTREEITEM  m_hHeaderFile;
	HTREEITEM  m_hResourceFile;
	HTREEITEM  m_hOtherFiles;
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FILEVIEWTREECTRL_H__802B49C1_8585_4A09_90F8_B206E760BA73__INCLUDED_)
