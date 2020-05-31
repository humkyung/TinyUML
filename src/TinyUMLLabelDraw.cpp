// TinyUMLLabelDraw.cpp: implementation of the CTinyUMLLabelDraw class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "TinyUML.h"
#include "TinyUMLLabel.h"
#include "TinyUMLLabelDraw.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

IS_IMPLEMENT_DRAW_FUNC(CTinyUMLLabelDraw)
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CTinyUMLLabelDraw::CTinyUMLLabelDraw()
{

}

CTinyUMLLabelDraw::~CTinyUMLLabelDraw()
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
void CTinyUMLLabelDraw::DrawObject(CDC *pDC, CIsDrawEntity *pEnt, CIsDrawEntContainer *pDoc , const CIsDrawEditor* pDrawEditor)
{
	CTinyUMLLabel* pLabel = static_cast<CTinyUMLLabel*>(pEnt);

	int nPrevMode  = pDC->SetBkMode(TRANSPARENT);
	CFont* pOldFont= pDC->SelectObject(pLabel->GetFont());
	pDC->DrawText(pLabel->Name(), pLabel->GetRect(),
			DT_CENTER | DT_SINGLELINE | DT_VCENTER | DT_END_ELLIPSIS | DT_NOPREFIX);
	pDC->SelectObject(pOldFont);
	pDC->SetBkMode(nPrevMode);
}

void CTinyUMLLabelDraw::DrawFocusObject(CDC *pDC, CIsDrawEntity *pEnt, CIsDrawEntContainer *pDoc , const CIsDrawEditor* pDrawEditor)
{
	DrawObject(pDC , pEnt , pDoc , pDrawEditor);
	if(pEnt->IsSelected()) DrawSelectionMarkers(pDC , pEnt , pDrawEditor);
}
