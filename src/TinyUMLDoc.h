// TinyUMLDoc.h : interface of the CTinyUMLDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_TINYUMLDOC_H__4909717A_E404_4416_ABE5_36E511493404__INCLUDED_)
#define AFX_TINYUMLDOC_H__4909717A_E404_4416_ABE5_36E511493404__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "TinyUMLEntityContainer.h"
#include "TyUMLDocReactor.h"
#include "ContentFile.h"

#include <vector>
using namespace std;

#define MAKEFOURCC(ch0, ch1, ch2, ch3)                              \
		((DWORD)(BYTE)(ch0) | ((DWORD)(BYTE)(ch1) << 8) |   \
		((DWORD)(BYTE)(ch2) << 16) | ((DWORD)(BYTE)(ch3) << 24 ))

//	upper word is major version, lower word is minor version
#define CURRENT_FILE_VERSION 0x00010001

typedef struct HEADER
{
	DWORD	headID;		// fourCC code
	DWORD	version;	// version number
} HEADER;

class CTinyUMLDoc;

class CTinyUMLDoc : public CDocument
{
protected: // create from serialization only
	CTinyUMLDoc();
	DECLARE_DYNCREATE(CTinyUMLDoc)

// Attributes
public:
	CTinyUMLEntityContainer m_container;
// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTinyUMLDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	virtual BOOL OnOpenDocument(LPCTSTR lpszPathName);
	virtual BOOL CanCloseFrame(CFrameWnd* pFrame);
	protected:
	virtual BOOL SaveModified();
	//}}AFX_VIRTUAL

// Implementation
public:
	void ParseFileContext(const CString& rFilePath);
	void RemoveContentFile(CContentFile* pContentFile);
	void DisplayContentsOnWorkspace();
	virtual ~CTinyUMLDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	HEADER m_Header;

	vector<CContentFile*> m_contentFiles;
// Generated message map functions
protected:
	//{{AFX_MSG(CTinyUMLDoc)
	afx_msg void OnFileSavesource();
	afx_msg void OnUpdateFileSave(CCmdUI* pCmdUI);
	afx_msg void OnFileAddToDocument();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TINYUMLDOC_H__4909717A_E404_4416_ABE5_36E511493404__INCLUDED_)
