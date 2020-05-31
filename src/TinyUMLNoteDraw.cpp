// TinyUMLNoteDraw.cpp: implementation of the CTinyUMLNoteDraw class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "TinyUML.h"
#include "TinyUMLNote.h"
#include "TinyUMLNoteDraw.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

IS_IMPLEMENT_DRAW_FUNC(CTinyUMLNoteDraw)
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CTinyUMLNoteDraw::CTinyUMLNoteDraw()
{
	m_fillColor = RGB(200, 255, 255);
}

CTinyUMLNoteDraw::~CTinyUMLNoteDraw()
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
void CTinyUMLNoteDraw::DrawObject(CDC *pDC, CIsDrawEntity *pEnt, CIsDrawEntContainer *pDoc , const CIsDrawEditor* pDrawEditor)
{
	m_pTheme = static_cast<CTinyUMLTheme*>(pDoc->GetTheme());
	CTinyUMLNote* pNote = static_cast<CTinyUMLNote*>(pEnt);

	CPen pen(PS_SOLID, 0, *(m_pTheme->GetLineColor()));
	CPen *pOldPen;
	CBrush brush(m_fillColor);
	CBrush shadowBrush(*(m_pTheme->GetShadowColor()));
	CBrush *pOldBrush = NULL;
	CFont *pOldFont = NULL , *pNoteFont = pNote->GetTextFont();
	
	pOldPen = (CPen *)pDC->SelectStockObject(NULL_PEN);
	pOldBrush = pDC->SelectObject(&shadowBrush);
	if(NULL != pNoteFont)
		pOldFont = pDC->SelectObject(pNoteFont);
	else	pOldFont = pDC->SelectObject(m_pTheme->noteFont());
	
	CPoint ptOrigin(pNote->GetLeft(),pNote->GetTop());
	DWORD nWidth=pNote->GetRight() - pNote->GetLeft(),nHeight=pNote->GetBottom() - pNote->GetTop();
		
	// shape
	CPoint p[6];
	p[0] = ptOrigin;
	p[1] = ptOrigin + CSize(0, nHeight);
	p[2] = ptOrigin + CSize(nWidth, nHeight);
	p[3] = ptOrigin + CSize(nWidth, pNote->cornerHeight());
	p[4] = ptOrigin + CSize(nWidth - pNote->cornerWidth(), 0);
	p[5] = ptOrigin + CSize(nWidth - pNote->cornerWidth(), pNote->cornerHeight());
	pDC->SelectObject(&pen);
	pDC->SelectObject(&brush);
	pDC->Polygon(p, 5);
	pDC->MoveTo(p[3]);
	pDC->LineTo(p[5]);
	pDC->LineTo(p[4]);
	
	// text
	pDC->SetTextColor(m_pTheme->textColor());
	pDC->SetBkMode(TRANSPARENT);
	pDC->DrawText(pNote->GetText(), pNote->GetTextRect(), DT_WORDBREAK | DT_NOPREFIX);
	
	pDC->SelectObject(pOldPen);
	pDC->SelectObject(pOldBrush);
	pDC->SelectObject(pOldFont);
}

/**
 * DrawFocusObject:
 *
 * @param pDC 
 * @param pEnt 
 * @param pDoc 
 * @return void 
 */
void CTinyUMLNoteDraw::DrawFocusObject(CDC *pDC, CIsDrawEntity *pEnt, CIsDrawEntContainer *pDoc , const CIsDrawEditor* pDrawEditor)
{
	m_pTheme = static_cast<CTinyUMLTheme*>(pDoc->GetTheme());
	CTinyUMLNote* pNote = static_cast<CTinyUMLNote*>(pEnt);

	CPen pen(PS_SOLID, 0, *(m_pTheme->GetLineColor()));
	CPen *pOldPen;
	CBrush brush(m_fillColor);
	CBrush shadowBrush(*(m_pTheme->GetShadowColor()));
	CBrush *pOldBrush = NULL;
	CFont *pOldFont , *pNoteFont = pNote->GetTextFont();;
	
	pOldPen = (CPen *)pDC->SelectStockObject(NULL_PEN);
	pOldBrush = pDC->SelectObject(&shadowBrush);
	if(NULL != pNoteFont)
		pOldFont = pDC->SelectObject(pNoteFont);
	else	pOldFont = pDC->SelectObject(m_pTheme->noteFont());
	
	CPoint ptOrigin(pNote->GetLeft(),pNote->GetTop());
	DWORD nWidth=pNote->GetRight() - pNote->GetLeft();
	DWORD nHeight=pNote->GetBottom() - pNote->GetTop();
	DrawShadow(pDC,ptOrigin,nWidth,nHeight , pNote->cornerWidth() , pNote->cornerHeight());
	
	// shape
	CPoint p[6];
	p[0] = ptOrigin;
	p[1] = ptOrigin + CSize(0, nHeight);
	p[2] = ptOrigin + CSize(nWidth, nHeight);
	p[3] = ptOrigin + CSize(nWidth, pNote->cornerHeight());
	p[4] = ptOrigin + CSize(nWidth - pNote->cornerWidth(), 0);
	p[5] = ptOrigin + CSize(nWidth - pNote->cornerWidth(), pNote->cornerHeight());
	pDC->SelectObject(&pen);
	pDC->SelectObject(&brush);
	pDC->Polygon(p, 5);
	pDC->MoveTo(p[3]);
	pDC->LineTo(p[5]);
	pDC->LineTo(p[4]);
	
	// text
	pDC->SetTextColor(m_pTheme->textColor());
	pDC->SetBkMode(TRANSPARENT);
	pDC->DrawText(pNote->GetText(), pNote->GetTextRect(), DT_WORDBREAK | DT_NOPREFIX);
	
	pDC->SelectObject(pOldPen);
	pDC->SelectObject(pOldBrush);
	pDC->SelectObject(pOldFont);

	if(pNote->IsSelected()) DrawSelectionMarkers(pDC , pNote , pDrawEditor);
}

void CTinyUMLNoteDraw::DrawShadow(CDC *pDC, const CPoint &ptOrigin, const double &nWidth, const double &nHeight
				  , const long& cornerWidth , const long& cornerHeight)
{
	CPoint sp[5];
	sp[0] = ptOrigin + CSize(5, 5);
	sp[1] = ptOrigin + CSize(5, nHeight + 5);
	sp[2] = ptOrigin + CSize(nWidth + 5, nHeight + 5);
	sp[3] = ptOrigin + CSize(nWidth + 5, cornerHeight + 5);
	sp[4] = ptOrigin + CSize(nWidth - cornerWidth + 5, 5);
	pDC->Polygon(sp, 5);
}
