// TinyUMLDependencyDraw.cpp: implementation of the CTinyUMLDependencyDraw class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "TinyUML.h"
#include "TinyUMLDependency.h"
#include "TinyUMLDependencyDraw.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

IS_IMPLEMENT_DRAW_FUNC(CTinyUMLDependencyDraw)
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CTinyUMLDependencyDraw::CTinyUMLDependencyDraw()
{

}

CTinyUMLDependencyDraw::~CTinyUMLDependencyDraw()
{

}

/**
 * DrawObject:
 *
 * @param pDC 
 * @param pEnt 
 * @param pDoc 
 * @return void 
 */
void CTinyUMLDependencyDraw::DrawObject(CDC *pDC, CIsDrawEntity *pEnt, CIsDrawEntContainer *pDoc , const CIsDrawEditor* pDrawEditor)
{
	CTinyUMLRelationDraw::DrawObject(pDC , pEnt , pDoc , pDrawEditor);
	
	CTinyUMLDependency* pRel = static_cast<CTinyUMLDependency*>(pEnt);
	if(pRel->IsCreated())
	{
		CPoint p[] =
		{
			CPoint(16, 8),
			CPoint(0, 0),
			CPoint(16, -8),
		};
		
		if(pRel->IsShowArrow())
		{
			pRel->destTransform(p, 3);
			
			CPen pen(PS_SOLID, 0, pRel->GetLineColor()), *pOldPen;
			pOldPen = pDC->SelectObject(&pen);
			pDC->Polyline(p, 3);
			pDC->SelectObject(pOldPen);
		}
	}
}

/**
 * DrawFocusObject:
 *
 * @param pDC 
 * @param pEnt 
 * @param pDoc 
 * @return void 
 */
void CTinyUMLDependencyDraw::DrawFocusObject(CDC *pDC, CIsDrawEntity *pEnt, CIsDrawEntContainer *pDoc , const CIsDrawEditor* pDrawEditor)
{
	CTinyUMLRelationDraw::DrawFocusObject(pDC , pEnt , pDoc , pDrawEditor);

	CTinyUMLDependency* pRel = static_cast<CTinyUMLDependency*>(pEnt);
	if(pRel->IsCreated())
	{
		CPoint p[] =
		{
			CPoint(16, 8),
			CPoint(0, 0),
			CPoint(16, -8),
		};
		
		if(pRel->IsShowArrow())
		{
			pRel->destTransform(p, 3);
			
			CPen pen(PS_SOLID, 0, pRel->GetLineColor()), *pOldPen;
			pOldPen = pDC->SelectObject(&pen);
			pDC->Polyline(p, 3);
			pDC->SelectObject(pOldPen);
		}
	}
}
