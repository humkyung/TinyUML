// TinyUMLPackageDraw.cpp: implementation of the CTinyUMLPackageDraw class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "TinyUML.h"
#include "TinyUMLPackage.h"
#include "TinyUMLPackageDraw.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

IS_IMPLEMENT_DRAW_FUNC(CTinyUMLPackageDraw)
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CTinyUMLPackageDraw::CTinyUMLPackageDraw()
{

}

CTinyUMLPackageDraw::~CTinyUMLPackageDraw()
{

}

void CTinyUMLPackageDraw::DrawObject(CDC *pDC, CIsDrawEntity *pEnt, CIsDrawEntContainer *pDoc , const CIsDrawEditor* pDrawEditor)
{
	CTinyUMLPackage* pPackage = static_cast<CTinyUMLPackage*>(pEnt);

	CPen pen(PS_SOLID, 0, pPackage->GetLineColor()), *pOldPen;
	CBrush brush(pPackage->GetFilleColor()), *pOldBrush;
	CFont *pOldFont;
	
	pOldPen = pDC->SelectObject(&pen);
	pOldBrush = pDC->SelectObject(&brush);
	pOldFont = pDC->SelectObject(pPackage->GetNameFont());
	
	CPoint ptOrigin(pPackage->GetLeft(),pPackage->GetTop());
	DWORD nWidth=pPackage->GetRight() - pPackage->GetLeft();
	DWORD nHeight=pPackage->GetBottom() - pPackage->GetTop();

	// shape
	pDC->Rectangle(CRect(ptOrigin, CSize(pPackage->GetTabWidth() , pPackage->GetTabHeight() + 10)));
	pDC->Rectangle(CRect(ptOrigin + CSize(0, pPackage->GetTabHeight()), CSize(nWidth, nHeight - pPackage->GetTabHeight())));
	
	// name
	pDC->SetTextColor(pPackage->GetNameColor());
	pDC->SetBkMode(TRANSPARENT);
	pDC->DrawText(pPackage->GetName() , pPackage->GetNameRect(),
		DT_CENTER | DT_SINGLELINE | DT_VCENTER | DT_END_ELLIPSIS | DT_NOPREFIX);
	
	pDC->SelectObject(pOldPen);
	pDC->SelectObject(pOldBrush);
	pDC->SelectObject(pOldFont);
}

void CTinyUMLPackageDraw::DrawFocusObject(CDC *pDC, CIsDrawEntity *pEnt, CIsDrawEntContainer *pDoc , const CIsDrawEditor* pDrawEditor)
{
	CTinyUMLPackage* pPackage = static_cast<CTinyUMLPackage*>(pEnt);

	CPen pen(PS_SOLID, 0, pPackage->GetLineColor()), *pOldPen;
	CBrush brush(pPackage->GetFilleColor()), *pOldBrush;
	CFont *pOldFont;
	
	pOldPen = pDC->SelectObject(&pen);
	pOldBrush = pDC->SelectObject(&brush);
	pOldFont = pDC->SelectObject(pPackage->GetNameFont());
	
	CPoint ptOrigin(pPackage->GetLeft(),pPackage->GetTop());
	DWORD nWidth=pPackage->GetRight() - pPackage->GetLeft(),nHeight=pPackage->GetBottom() - pPackage->GetTop();
	// shape
	pDC->Rectangle(CRect(ptOrigin, CSize(pPackage->GetTabWidth(), pPackage->GetTabHeight() + 10)));
	pDC->Rectangle(CRect(ptOrigin + CSize(0, pPackage->GetTabHeight()), CSize(nWidth, nHeight - pPackage->GetTabHeight())));
	
	// name
	pDC->SetTextColor(pPackage->GetNameColor());
	pDC->SetBkMode(TRANSPARENT);
	pDC->DrawText(pPackage->GetName(), pPackage->GetNameRect(),
		DT_CENTER | DT_SINGLELINE | DT_VCENTER | DT_END_ELLIPSIS | DT_NOPREFIX);
	
	pDC->SelectObject(pOldPen);
	pDC->SelectObject(pOldBrush);
	pDC->SelectObject(pOldFont);

	if(pPackage->IsSelected()) DrawSelectionMarkers(pDC,pPackage , pDrawEditor);
}
