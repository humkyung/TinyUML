// TinyUMLDependencyDraw.h: interface for the CTinyUMLDependencyDraw class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_TINYUMLDEPENDENCYDRAW_H__0738E300_C302_4627_B644_31A5F171454D__INCLUDED_)
#define AFX_TINYUMLDEPENDENCYDRAW_H__0738E300_C302_4627_B644_31A5F171454D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "TinyUMLRelationDraw.h"

class CTinyUMLDependencyDraw : public CTinyUMLRelationDraw  
{
public:
	virtual void DrawFocusObject(CDC *pDC, CIsDrawEntity *pEnt , CIsDrawEntContainer* pDoc , const CIsDrawEditor* pDrawEditor);
	CTinyUMLDependencyDraw();
	virtual ~CTinyUMLDependencyDraw();

	IS_DECLARE_DRAW_FUNC()
protected:
	virtual void DrawObject(CDC *pDC, CIsDrawEntity *pEnt , CIsDrawEntContainer* pDoc , const CIsDrawEditor* pDrawEditor);
};

#endif // !defined(AFX_TINYUMLDEPENDENCYDRAW_H__0738E300_C302_4627_B644_31A5F171454D__INCLUDED_)
