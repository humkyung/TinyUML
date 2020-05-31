// TinyUMLEditor.h: interface for the CTinyUMLEditor class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_TINYUMLEDITOR_H__EB2BE361_73AC_4DAB_B308_889A76ECA5D2__INCLUDED_)
#define AFX_TINYUMLEDITOR_H__EB2BE361_73AC_4DAB_B308_889A76ECA5D2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "IsDrawEditor.h"
#include "TinyUMLEntityContainer.h"
#include "ClassEdit.h"
#include <IsDrawObject.h>

#include <map>
using namespace std;

#define TINY_UML_PREMODIFY_PROPERTY	WM_USER + 1020
#define TINY_UML_MODIFY_PROPERTY	WM_USER + 1021

class CTinyUMLEditor : public CIsDrawEditor  
{
public:
	void OnDrawingLineWeight(const int& lweight);
	void OnDrawingLineStyle(const int& lstyle);
	void OnDrawingLineColor(COLORREF color);
	virtual int SelectByRect(CRect& rect);
	CTinyUMLEditor(CTinyUMLEntityContainer* pEntContainer);
	virtual ~CTinyUMLEditor();
protected:
	virtual void DrawObjects( CDC* dc, const CRect& rect ) const;
	virtual void DrawBackground(CDC* pDC,CRect rect);
	virtual void DrawGrid(CDC *pDC, CRect rect);

	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg LONG OnPreModifyProperty(UINT lParam,LONG wParam);
	afx_msg LONG OnModifyProperty(UINT lParam, LONG wParam);
	

	BOOL OnToolTipNotify(UINT id, NMHDR* pNMHDR, LRESULT* pResult);
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTinyUMLView)
	//}}AFX_VIRTUAL
protected:
	DECLARE_MESSAGE_MAP()

};

#endif // !defined(AFX_TINYUMLEDITOR_H__EB2BE361_73AC_4DAB_B308_889A76ECA5D2__INCLUDED_)
