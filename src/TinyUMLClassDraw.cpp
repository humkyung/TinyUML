// TinyUMLClassDraw.cpp: implementation of the CTinyUMLClassDraw class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "TinyUML.h"
#include "TinyUMLClassDraw.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

IS_IMPLEMENT_DRAW_FUNC(CTinyUMLClassDraw)
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CTinyUMLClassDraw::CTinyUMLClassDraw()
{
	m_publicMemberBmp.LoadBitmap(IDB_PUBLIC_MEMBER);
	m_protectedMemberBmp.LoadBitmap(IDB_PROTECTED_MEMBER);
	m_privateMemberBmp.LoadBitmap(IDB_PRIVATE_MEMBER);
	m_publicMethodBmp.LoadBitmap(IDB_PUBLIC_METHOD);
	m_protectedMethodBmp.LoadBitmap(IDB_PROTECTED_METHOD);
	m_privateMethodBmp.LoadBitmap(IDB_PRIVATE_METHOD);
}

CTinyUMLClassDraw::~CTinyUMLClassDraw()
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
void CTinyUMLClassDraw::DrawObject(CDC *pDC, CIsDrawEntity *pEnt, CIsDrawEntContainer *pDoc , const CIsDrawEditor* pDrawEditor)
{
	m_pTheme = static_cast<CTinyUMLTheme*>(pDoc->GetTheme());

	/*
	m_nameHeight = pUMLTheme->nameHeight();
	m_stereotypeHeight = pUMLTheme->stereotypeHeight();
	m_attributeHeight = pUMLTheme->attributeHeight();
	m_methodHeight = pUMLTheme->methodHeight();
	m_compartimentNameHeight = pUMLTheme->compartimentNameHeight();
	
	m_newAttributeHeight = m_attributeHeight / 2;
	m_newMethodHeight = m_methodHeight / 2;
	
	m_pStereotypeFont = pUMLTheme->stereotypeFont();
	m_pNameFont = pUMLTheme->GetNameFont();
	m_pMemberFont = pUMLTheme->GetMemberFont();
	m_pStaticAttributeFont = pUMLTheme->staticAttributeFont();
	m_pMethodFont = pUMLTheme->GetMethodFont();
	m_pAbstractMethodFont = pUMLTheme->abstractMethodFont();
	m_pAbstractNameFont = pUMLTheme->abstractNameFont();
	m_pStaticMethodFont = pUMLTheme->staticMethodFont();
	m_pCompartimentNameFont = pUMLTheme->compartimentNameFont();
	
	//////////////////////////////////////////////////////////////////////////
	/// colors
	m_titleColor= pUMLTheme->classTitleColor();
	m_pFillColor = pUMLTheme->classColor();
	m_lineColor = pUMLTheme->GetLineColor();
	m_nameColor = pUMLTheme->GetNameColor();
	m_shadowColor = pUMLTheme->GetShadowColor();
	m_stereotypeColor = pUMLTheme->stereotypeColor();
	m_attributeColor = pUMLTheme->GetAttributeColor();
	m_methodColor = pUMLTheme->GetMethodColor();
	m_compartimentNameColor = pUMLTheme->compartimentNameColor();
	m_pClrFolder = pUMLTheme->GetFolderColor();
	
	m_bDoneSetupTheme = true;
	*/

	CTinyUMLClass* pClass = static_cast<CTinyUMLClass*>(pEnt);
	CPen pen(PS_SOLID, 0, *(m_pTheme->GetLineColor())), *pOldPen;
	CBrush fillBrush(*(m_pTheme->classColor())), *pOldBrush=NULL;
	CFont *pOldFont;
	
	pOldPen = pDC->SelectObject(&pen);
	pOldFont = pDC->SelectObject(pClass->IsAbstract() ? m_pTheme->abstractNameFont() : m_pTheme->GetNameFont());
	
	DrawBody(pDC , pEnt);
	DrawTitleBar(pDC , pEnt);
	
	CPoint ptOrigin(pClass->GetLeft() , pClass->GetTop());
	DWORD nWidth = pClass->GetRight() - pClass->GetLeft();
	if(pClass->IsShowAttributes())
	{
		pDC->MoveTo(ptOrigin + CSize(0, pClass->yCache(2)));
		pDC->LineTo(ptOrigin + CSize(nWidth, pClass->yCache(2)));
	}
	
	if(pClass->IsShowMethods())
	{
		long index = 4 + pClass->attributesCount();
		pDC->MoveTo(ptOrigin + CSize(0, pClass->yCache(index)));
		pDC->LineTo(ptOrigin + CSize(nWidth, pClass->yCache(index)));
	}
	
	pDC->SetBkMode(TRANSPARENT);
	// name
	pDC->SetTextColor(*(m_pTheme->GetNameColor()));
	pDC->DrawText(pClass->Name(), pClass->GetNameRect(),
		DT_CENTER | DT_SINGLELINE | DT_VCENTER | DT_END_ELLIPSIS | DT_NOPREFIX);		
	
	// stereotype
	if(pClass->IsShowStereotype())
	{
		CString stereotype;
		stereotype.Format("<<%s>>", pClass->stereotype());
		
		CFont* pOldFont1 = pDC->SelectObject(m_pTheme->stereotypeFont());
		pDC->SetTextColor(m_pTheme->stereotypeColor());
		pDC->DrawText(stereotype, pClass->stereotypeRect(),
			DT_CENTER | DT_SINGLELINE | DT_VCENTER | DT_END_ELLIPSIS | DT_NOPREFIX);
		pDC->SelectObject(pOldFont1);
	}
	
	// compartiment names
	if(pClass->IsShowCompartimentName())
	{
		CFont* pOldFont2 = pDC->SelectObject(m_pTheme->compartimentNameFont());
		pDC->SetTextColor(m_pTheme->compartimentNameColor());
		
		if(pClass->IsShowAttributes())
			pDC->DrawText("Members", pClass->attributesCompartimentNameRect(),
			DT_CENTER | DT_SINGLELINE | DT_VCENTER | DT_END_ELLIPSIS | DT_NOPREFIX);
		
		if(pClass->IsShowMethods())
			pDC->DrawText("Methods", pClass->methodsCompartimentNameRect(),
			DT_CENTER | DT_SINGLELINE | DT_VCENTER | DT_END_ELLIPSIS | DT_NOPREFIX);
		
		pDC->SelectObject(pOldFont2);
	}
	
	// attributes
	DrawMembers(pDC , pClass);
	
	// methods
	DrawMethods(pDC , pClass);
	
	pDC->SelectObject(pOldPen);
	pDC->SelectObject(pOldFont);
}

/**
 * DrawBody:
 *
 * @param pDC 
 * @param pEnt 
 * @param isOnMouse 
 * @return void 
 */
void CTinyUMLClassDraw::DrawBody(CDC *pDC, CIsDrawEntity *pEnt , const bool isOnMouse)
{
	CBrush fillBrush(*(m_pTheme->classColor()));
	pDC->FillRect(&pEnt->GetRect(),&fillBrush);
	if(false == isOnMouse)
		pDC->Draw3dRect(&pEnt->GetRect(),RGB(177,177,177),RGB(0,0,0));
	else	pDC->Draw3dRect(&pEnt->GetRect(),RGB(0,0,0),RGB(177,177,177));
}

/**
 * DrawTitleBar:
 *
 * @param pDC 
 * @param pEnt 
 * @return void 
 */
void CTinyUMLClassDraw::DrawTitleBar(CDC *pDC , CIsDrawEntity *pEnt)
{
	CBrush titleBrush(*(m_pTheme->classTitleColor()));

	CTinyUMLClass* pClass = static_cast<CTinyUMLClass*>(pEnt);
	CRect rect = pClass->GetRect();
	rect.DeflateRect(1,0,1,0);
	rect.top = pClass->GetNameRect().top - 1;
	rect.bottom = pClass->GetNameRect().bottom + 1;
	pDC->FillRect(&rect,&titleBrush);
}

/**
 * DrawMembers:
 *
 * @param pDC 
 * @param pClass 
 * @return void 
 */
void CTinyUMLClassDraw::DrawMembers(CDC *pDC , CTinyUMLClass* pClass)
{
	if(pClass->IsShowAttributes())
	{
		CFont* pOldFont = pDC->SelectObject(m_pTheme->GetMemberFont());
		//////////////////////////////////////////////////////////////////////////
			
		pDC->SetTextColor(*(m_pTheme->GetAttributeColor()));
		
		for(int i = 0; i < pClass->attributesCount(); ++i)
		{
			CRect rect(pClass->attributeRect(i));
			rect.left -= 2;

			CTinyUMLClass::Member member = pClass->GetAttbuteAt(i);
			if(CTinyUMLClass::Member::public_member == member.access)
				DrawBitmap(pDC, &m_publicMemberBmp, rect);
			else if(CTinyUMLClass::Member::protected_member == member.access)
				DrawBitmap(pDC, &m_protectedMemberBmp, rect);
			else if(CTinyUMLClass::Member::private_member == member.access)
				DrawBitmap(pDC, &m_privateMemberBmp, rect);
			
			rect = pClass->attributeRect(i);
			rect.left += 16;
			
			pDC->SelectObject(attributeFont(i , pClass));
			pDC->DrawText(member.type + " " + member.name,
				rect,DT_LEFT | DT_SINGLELINE | DT_VCENTER | DT_END_ELLIPSIS | DT_NOPREFIX);
		}
		
		//////////////////////////////////////////////////////////////////////////
		pDC->SelectObject(pOldFont);
	}
}

/**
 * attributeFont:
 *
 * @param index 
 * @param pClass 
 * @return CFont* 
 */
CFont* CTinyUMLClassDraw::attributeFont(long index , CTinyUMLClass* pClass) const
{
	ASSERT(index >= 0 && index < pClass->attributesCount());
	
	CTinyUMLClass::Member member = pClass->GetAttbuteAt(index);
	switch(member.access)
	{
		case CTinyUMLClass::Member::public_member:
		case CTinyUMLClass::Member::protected_member:
		case CTinyUMLClass::Member::private_member:
			return m_pTheme->GetMemberFont();
		default:
			ASSERT(false);
			return NULL;
	}
}

/**
 * DrawBitmap:
 *
 * @param pDC 
 * @param pBitmap 
 * @param rectTaget 
 * @return void 
 */
void CTinyUMLClassDraw::DrawBitmap(CDC *pDC, CBitmap *pBitmap, const CRect &rectTaget)
{
	int nMapMode = pDC->GetMapMode();
	BITMAP bm;
	if (!pBitmap->GetBitmap(&bm)) return;
	
	// bitmap을 cell에 맞게 scale을 정한다.
	CSize bsize;
	bsize.cx = bm.bmWidth;
	bsize.cy = bm.bmHeight;
	
	CDC memDC;
	memDC.CreateCompatibleDC(pDC);
	CBitmap *pOldBitmap = memDC.SelectObject(pBitmap);
	
	if (nMapMode == MM_LOMETRIC || nMapMode == MM_HIMETRIC) bsize.cy = -bsize.cy;
	
	pDC->StretchBlt(rectTaget.left, rectTaget.top, bsize.cx, bsize.cy, &memDC, 0, 0, bm.bmWidth, bm.bmHeight, SRCAND);
	
	memDC.SelectObject(pOldBitmap);
}

/**
 * DrawMethods:
 *
 * @param pDC 
 * @param pClass 
 * @return void 
 */
void CTinyUMLClassDraw::DrawMethods(CDC *pDC, CTinyUMLClass *pClass)
{
	if(pClass->IsShowMethods())
	{
		CFont* pOldFont = pDC->SelectObject(m_pTheme->GetMethodFont());
		pDC->SetTextColor(*(m_pTheme->GetMethodColor()));
		
		for(int i = 0; i < pClass->methodsCount(); ++i)
		{
			CRect rect(pClass->methodRect(i));
			rect.left -= 2;

			CTinyUMLClass::Method method = pClass->GetMethodAt(i); 
			if(CTinyUMLClass::Method::public_method == method.access)
				DrawBitmap(pDC, &m_publicMethodBmp, rect);
			else if(CTinyUMLClass::Method::protected_method == method.access)
				DrawBitmap(pDC, &m_protectedMethodBmp, rect);
			else if(CTinyUMLClass::Method::private_method == method.access)
				DrawBitmap(pDC, &m_privateMethodBmp, rect);
			
			rect = pClass->methodRect(i);
			rect.left += 16;
			pDC->SelectObject(methodFont(i , pClass));
			pDC->DrawText(method.type + " " + method.name, rect ,
				DT_LEFT | DT_SINGLELINE | DT_VCENTER | DT_END_ELLIPSIS | DT_NOPREFIX);
		}
		
		//////////////////////////////////////////////////////////////////////////
		pDC->SelectObject(pOldFont);
	}
}

/**
 * methodFont:
 *
 * @param index 
 * @param pClass 
 * @return CFont* 
 */
CFont* CTinyUMLClassDraw::methodFont(long index, CTinyUMLClass *pClass) const
{
	ASSERT(index >= 0 && index < pClass->methodsCount());
	
	CTinyUMLClass::Method method = pClass->GetMethodAt(index); 
	switch(method.access)
	{
		case CTinyUMLClass::Method::public_method:
		case CTinyUMLClass::Method::protected_method:
		case CTinyUMLClass::Method::private_method:
			return m_pTheme->GetMethodFont();
		case CTinyUMLClass::Method::abstract_method:
			return m_pTheme->abstractMethodFont();
		default:
			ASSERT(false);
			return NULL;
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
void CTinyUMLClassDraw::DrawFocusObject(CDC *pDC, CIsDrawEntity *pEnt, CIsDrawEntContainer *pDoc , const CIsDrawEditor* pDrawEditor)
{
	m_pTheme = static_cast<CTinyUMLTheme*>(pDoc->GetTheme());
	CTinyUMLClass* pClass = static_cast<CTinyUMLClass*>(pEnt);

	CPen pen(PS_SOLID, 0, *(m_pTheme->GetLineColor()));
	CBrush brush(*(m_pTheme->classColor()));
	CBrush shadowBrush(*(m_pTheme->GetShadowColor()));
	CBrush *pOldBrush;
	
	CPen* pOldPen = (CPen *)pDC->SelectStockObject(NULL_PEN);
	pOldBrush = pDC->SelectObject(&shadowBrush);
	
	CPoint ptOrigin(pClass->GetLeft() , pClass->GetTop());
	DWORD nWidth=pClass->GetRight() - pClass->GetLeft(),nHeight=pClass->GetBottom() - pClass->GetTop();
	// shadow
	CPoint sp[5];
	sp[0] = ptOrigin + CSize(5, 5);
	sp[1] = ptOrigin + CSize(5, nHeight + 5);
	sp[2] = ptOrigin + CSize(nWidth + 5, nHeight + 5);
	sp[3] = ptOrigin + CSize(nWidth + 5, 5);
	sp[4] = ptOrigin + CSize(5, 5);
	pDC->Polygon(sp, 5);
	
	pDC->SelectObject(pOldPen);
	pDC->SelectObject(pOldBrush);
	
	CTinyUMLClassDraw::Draw(pDC , pEnt , pDoc , pDrawEditor);
}
