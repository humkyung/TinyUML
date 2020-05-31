// TinyUMLView.h : interface of the CTinyUMLView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_TINYUMLVIEW_H__CCD427B9_B099_464A_952E_5FFD8937A3B2__INCLUDED_)
#define AFX_TINYUMLVIEW_H__CCD427B9_B099_464A_952E_5FFD8937A3B2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "TinyUMLDoc.h"
#include "TinyUMLEditor.h"
#include "TinyUMLClassFactory.h"
#include "TinyUMLNoteController.h"
#include "TinyUMLAssociationFactory.h"
#include "TinyUMLLabelFactory.h"
#include "TinyUMLGeneralizationController.h"

//////////////////////////////////////////////////////////////////////////
#include <IsDrawLineFactory.h>
#include <IsDrawRectFactory.h>
#include <IsDrawEllipseFactory.h>
#include <IsDrawArcFactory.h>

class CTinyUMLView : public CView
{
protected: // create from serialization only
	CTinyUMLView();
	DECLARE_DYNCREATE(CTinyUMLView)

// Attributes
	CIsDrawLineFactory*	m_pDrawLineFactory;
	CIsDrawRectFactory*	m_pDrawRectFactory;
	CIsDrawEllipseFactory*	m_pDrawEllipseFactory;
	CIsDrawArcFactory*	m_pDrawArcFactory;

	CTinyUMLLabelFactory*  m_pLabelFactory;
	CTinyUMLClassFactory* m_pClassFactory;
	CTinyUMLClassFactory* m_pInterfaceFactory;
	CTinyUMLNoteController* m_pNoteFactory;
	CTinyUMLGeneralizationController* m_pRealizeFactory;
	CTinyUMLAssociationFactory *m_pAssociation1Factory;
	CTinyUMLAssociationFactory *m_pAssociation2Factory;
	CTinyUMLAssociationFactory *m_pAssociation3Factory;
public:
	CTinyUMLDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTinyUMLView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual void OnInitialUpdate();
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual BOOL OnNotify(WPARAM wParam, LPARAM lParam, LRESULT* pResult);
	virtual void OnActivateView(BOOL bActivate, CView* pActivateView, CView* pDeactiveView);
	//}}AFX_VIRTUAL

// Implementation
public:
	CTinyUMLEditor* GetUMLEditor();
	virtual ~CTinyUMLView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	CTinyUMLEditor* m_pTyUMLEditor;
// Generated message map functions
protected:
	//{{AFX_MSG(CTinyUMLView)
	afx_msg void OnToolClass();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnUndo();
	afx_msg void OnUpdateUndo(CCmdUI* pCmdUI);
	afx_msg void OnUpdateRedo(CCmdUI* pCmdUI);
	afx_msg void OnRedo();
	afx_msg void OnToolGeneralization();
	afx_msg void OnToolSelect();
	afx_msg void OnUpdateToolClass(CCmdUI* pCmdUI);
	afx_msg void OnUpdateToolSelect(CCmdUI* pCmdUI);
	afx_msg void OnUpdateToolGeneralization(CCmdUI* pCmdUI);
	afx_msg void OnToolNote();
	afx_msg void OnUpdateToolNote(CCmdUI* pCmdUI);
	afx_msg void OnToolPackage();
	afx_msg void OnUpdateToolPackage(CCmdUI* pCmdUI);
	afx_msg void OnToolRealize();
	afx_msg void OnToolInterface();
	afx_msg void OnUpdateToolInterface(CCmdUI* pCmdUI);
	afx_msg void OnToolAssociation1();
	afx_msg void OnUpdateToolAssociation1(CCmdUI* pCmdUI);
	afx_msg void OnToolAssociation2();
	afx_msg void OnUpdateToolAssociation2(CCmdUI* pCmdUI);
	afx_msg void OnToolAssociation3();
	afx_msg void OnUpdateToolAssociation3(CCmdUI* pCmdUI);
	afx_msg void OnToolDependency();
	afx_msg void OnUpdateToolDependency(CCmdUI* pCmdUI);
	afx_msg void OnViewgrid();
	afx_msg void OnUpdateViewgrid(CCmdUI* pCmdUI);
	afx_msg void OnViewmin();
	afx_msg void OnUpdateViewmin(CCmdUI* pCmdUI);
	afx_msg void OnViewnormal();
	afx_msg void OnUpdateViewnormal(CCmdUI* pCmdUI);
	afx_msg void OnViewmax();
	afx_msg void OnUpdateViewmax(CCmdUI* pCmdUI);
	afx_msg void OnViewLock();
	afx_msg void OnUpdateViewLock(CCmdUI* pCmdUI);
	afx_msg void OnEditProperties();
	afx_msg void OnUpdateEditProperties(CCmdUI* pCmdUI);
	afx_msg void OnEditTheme();
	afx_msg void OnSaveTheme();
	afx_msg void OnLoadTheme();
	afx_msg void OnToolLabel();
	afx_msg void OnEditCopy();
	afx_msg void OnEditPaste();
	afx_msg void OnUpdateToolRealize(CCmdUI* pCmdUI);
	afx_msg void OnFilePurge();
	afx_msg void OnArrangeBringToFront();
	afx_msg void OnArrangeSendToBack();
	afx_msg void OnFileReadsource();
	afx_msg void OnUpdateToolLabel(CCmdUI* pCmdUI);
	afx_msg void OnDrawToolLine();
	afx_msg void OnUpdateDrawToolLine(CCmdUI* pCmdUI);
	afx_msg void OnDrawToolRect();
	afx_msg void OnUpdateDrawToolRect(CCmdUI* pCmdUI);
	afx_msg void OnDrawToolEllipse();
	afx_msg void OnUpdateDrawToolEllipse(CCmdUI* pCmdUI);
	afx_msg void OnDrawToolArc();
	afx_msg void OnUpdateDrawToolArc(CCmdUI* pCmdUI);
	
	//}}AFX_MSG
	afx_msg void OnContextMenu(CWnd*, CPoint point);
	afx_msg void OnFilePrintPreview();
	afx_msg void OnScaleSelect();
	afx_msg void OnDrawingLineColor();
	afx_msg void OnDrawingLineStyle();
	afx_msg void OnDrawingLineWeight();
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in TinyUMLView.cpp
inline CTinyUMLDoc* CTinyUMLView::GetDocument()
   { return (CTinyUMLDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TINYUMLVIEW_H__CCD427B9_B099_464A_952E_5FFD8937A3B2__INCLUDED_)
