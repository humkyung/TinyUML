// TinyUMLAssociationDraw.cpp: implementation of the CTinyUMLAssociationDraw class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "TinyUML.h"
#include "TinyUMLAssociation.h"
#include "TinyUMLAssociationDraw.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

IS_IMPLEMENT_DRAW_FUNC(CTinyUMLAssociationDraw)
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CTinyUMLAssociationDraw::CTinyUMLAssociationDraw()
{

}

CTinyUMLAssociationDraw::~CTinyUMLAssociationDraw()
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
void CTinyUMLAssociationDraw::DrawObject(CDC *pDC, CIsDrawEntity *pEnt, CIsDrawEntContainer *pDoc , const CIsDrawEditor* pDrawEditor)
{
	CTinyUMLRelationDraw::DrawObject(pDC , pEnt , pDoc , pDrawEditor);
	
	CTinyUMLAssociation* pRel = static_cast<CTinyUMLAssociation*>(pEnt);
	if(pRel->IsCreated())
	{
		CPoint sp[] =
		{
			CPoint(25, 0),
			CPoint(12, 8),
			CPoint(0, 0),
			CPoint(12, -8),
		};
		
		CPoint dp[] =
		{
			CPoint(16, 8),
			CPoint(0, 0),
			CPoint(16, -8),
		};
		
		CPen pen(PS_SOLID, 0, pRel->GetLineColor()), *pOldPen;
		CBrush brush(pRel->GetFillColor()), *pOldBrush;
		CFont *pOldFont;
		
		pOldPen = pDC->SelectObject(&pen);
		pOldBrush = pDC->SelectObject(&brush);
		pOldFont = pDC->SelectObject(pRel->GetMultiplicityFont());
		
		pDC->SetTextColor(pRel->GetLineColor());
		pDC->SetBkMode(TRANSPARENT);
		
		// aggregation
		if(pRel->IsAggregation())
		{
			pRel->srcTransform(sp, 4);
			pDC->Polygon(sp, 4);
		}
		
		// navigability
		if(!pRel->IsNavigable())
		{
			pRel->destTransform(dp, 3);
			pDC->Polyline(dp, 3);
		}
		
		// source multiplicity
		if(pRel->IsShowSrcMultiplicity())
		{
			//pDC->Rectangle(srcMultiplicityRect());
			pDC->DrawText(pRel->GetSrcMultiplicity(), pRel->srcMultiplicityRect(),
				DT_CENTER | DT_SINGLELINE | DT_VCENTER | DT_END_ELLIPSIS | DT_NOPREFIX);
			
		}
		
		// destination multiplicity
		if(pRel->IsShowDestMultiplicity())
		{
			//pDC->Rectangle(destMultiplicityRect());
			pDC->DrawText(pRel->GetDestMultiplicity() , pRel->destMultiplicityRect(),
				DT_CENTER | DT_SINGLELINE | DT_VCENTER | DT_END_ELLIPSIS | DT_NOPREFIX);
		}
		
		pDC->SelectObject(pOldPen);
		pDC->SelectObject(pOldBrush);
		pDC->SelectObject(pOldFont);
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
void CTinyUMLAssociationDraw::DrawFocusObject(CDC *pDC, CIsDrawEntity *pEnt, CIsDrawEntContainer *pDoc , const CIsDrawEditor* pDrawEditor)
{
	CTinyUMLRelationDraw::DrawFocusObject(pDC , pEnt , pDoc , pDrawEditor);
	
	CTinyUMLAssociation* pRel = static_cast<CTinyUMLAssociation*>(pEnt);
	if(pRel->IsCreated())
	{
		CPoint sp[] =
		{
			CPoint(25, 0),
			CPoint(12, 8),
			CPoint(0, 0),
			CPoint(12, -8),
		};
		
		CPoint dp[] =
		{
			CPoint(16, 8),
			CPoint(0, 0),
			CPoint(16, -8),
		};
		
		CPen pen(PS_SOLID, 0, pRel->GetLineColor()), *pOldPen;
		CBrush brush(pRel->GetFillColor()), *pOldBrush;
		CFont *pOldFont;
		
		pOldPen = pDC->SelectObject(&pen);
		pOldBrush = pDC->SelectObject(&brush);
		pOldFont = pDC->SelectObject(pRel->GetMultiplicityFont());
		
		pDC->SetTextColor(pRel->GetLineColor());
		pDC->SetBkMode(TRANSPARENT);
		
		// aggregation
		if(pRel->IsAggregation())
		{
			pRel->srcTransform(sp, 4);
			pDC->Polygon(sp, 4);
		}
		
		// navigability
		if(!pRel->IsNavigable())
		{
			pRel->destTransform(dp, 3);
			pDC->Polyline(dp, 3);
		}
		
		// source multiplicity
		if(pRel->IsShowSrcMultiplicity())
		{
			//pDC->Rectangle(srcMultiplicityRect());
			pDC->DrawText(pRel->GetSrcMultiplicity(), pRel->srcMultiplicityRect(),
				DT_CENTER | DT_SINGLELINE | DT_VCENTER | DT_END_ELLIPSIS | DT_NOPREFIX);
			
		}
		
		// destination multiplicity
		if(pRel->IsShowDestMultiplicity())
		{
			//pDC->Rectangle(destMultiplicityRect());
			pDC->DrawText(pRel->GetDestMultiplicity(), pRel->destMultiplicityRect(),
				DT_CENTER | DT_SINGLELINE | DT_VCENTER | DT_END_ELLIPSIS | DT_NOPREFIX);
		}
		
		pDC->SelectObject(pOldPen);
		pDC->SelectObject(pOldBrush);
		pDC->SelectObject(pOldFont);
	}
}
