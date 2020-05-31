// TinyUMLGeneralizationDraw.cpp: implementation of the CTinyUMLGeneralizationDraw class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "TinyUML.h"
#include "TinyUMLGeneralization.h"
#include "TinyUMLGeneralizationDraw.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

IS_IMPLEMENT_DRAW_FUNC(CTinyUMLGeneralizationDraw)
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CTinyUMLGeneralizationDraw::CTinyUMLGeneralizationDraw()
{

}

CTinyUMLGeneralizationDraw::~CTinyUMLGeneralizationDraw()
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
void CTinyUMLGeneralizationDraw::DrawObject(CDC *pDC, CIsDrawEntity *pEnt, CIsDrawEntContainer *pDoc , const CIsDrawEditor* pDrawEditor)
{
	CTinyUMLRelationDraw::DrawObject(pDC , pEnt , pDoc , pDrawEditor);
	
	CTinyUMLGeneralization* pRel = static_cast<CTinyUMLGeneralization*>(pEnt);
	if(pRel->IsCreated())
	{
		CPoint p[] =
		{
			CPoint(20, 10),
			CPoint(0, 0),
			CPoint(20, -10),
		};
		
		pRel->destTransform(p, 3);
		
		CPen pen(PS_SOLID, 0, pRel->GetLineColor()), *pOldPen;
		CBrush brush(pRel->GetFillColor()), *pOldBrush;
		
		pOldPen = pDC->SelectObject(&pen);
		pOldBrush = pDC->SelectObject(&brush);
		
		pDC->Polygon(p, 3);
		
		pDC->SelectObject(pOldPen);
		pDC->SelectObject(pOldBrush);
	}
}

void CTinyUMLGeneralizationDraw::DrawFocusObject(CDC *pDC, CIsDrawEntity *pEnt, CIsDrawEntContainer *pDoc , const CIsDrawEditor* pDrawEditor)
{
	CTinyUMLRelationDraw::DrawFocusObject(pDC , pEnt , pDoc , pDrawEditor);
	
	CTinyUMLGeneralization* pRel = static_cast<CTinyUMLGeneralization*>(pEnt);
	if(pRel->IsCreated())
	{
		CPoint p[] =
		{
			CPoint(20, 10),
			CPoint(0, 0),
			CPoint(20, -10),
		};
		
		pRel->destTransform(p, 3);
		
		COLORREF line_color=RGB(0,0,255);
		CPen pen(PS_SOLID, 0, line_color), *pOldPen;
		CBrush brush(pRel->GetFillColor()), *pOldBrush;
		
		pOldPen = pDC->SelectObject(&pen);
		pOldBrush = pDC->SelectObject(&brush);
		
		pDC->Polygon(p, 3);
		
		pDC->SelectObject(pOldPen);
		pDC->SelectObject(pOldBrush);
	}

	if(pRel->IsSelected()) DrawSelectionMarkers(pDC,pRel , pDrawEditor);
}
