// TinyUMLGeneralization.cpp: implementation of the CTinyUMLGeneralization class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include <math.h>
#include <IsDrawCtrlHost.h>
#include "TinyUML.h"
#include "TinyUMLEditor.h"
#include "TinyUMLGeneralization.h"
#include "TinyUMLGeneralizationController.h"
#include "TinyUMLTheme.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

IMPLEMENT_SERIAL(CTinyUMLGeneralization, CTinyUMLRelation, 1)
IS_OBJ_IMPLEMENT_FUNC(CTinyUMLGeneralization , CTinyUMLRelation , "_TINY_UML_GENERALIZATION_")
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

/**
 * CTinyUMLGeneralization:
 *
 * @return  
 */
CTinyUMLGeneralization::CTinyUMLGeneralization() : CTinyUMLRelation()
{
	SetTypeString(CTinyUMLGeneralization::TypeString());
}

CTinyUMLGeneralization::CTinyUMLGeneralization(CIsDrawEntContainer* pDoc,CIsControllerObject* pController,
					       const CPoint &point, CTinyUMLEntity *pEnt,bool bRealize) : 
						CTinyUMLRelation(pDoc,pController,point,pEnt)
{
	SetTypeString(CTinyUMLGeneralization::TypeString());
	m_bRealize = bRealize;
	m_penStyle = m_bRealize ? PS_DOT : PS_SOLID;
	//SetupTheme();
}

CTinyUMLGeneralization::~CTinyUMLGeneralization()
{

}

/**
 * SetupTheme:
 *
 * @return void 
 */
void CTinyUMLGeneralization::SetupTheme(CTinyDrawTheme *pTheme)
{
	CTinyUMLRelation::SetupTheme(pTheme);

	if(NULL != pTheme)
	{
		CTinyUMLTheme* pUMLTheme=static_cast<CTinyUMLTheme*>(pTheme);
		
		m_lineColor = pUMLTheme->GetLineColor();
		m_fillColor = *(pUMLTheme->GetEndSymbolColor());
	}
}

/**
 * OnNotify:
 *
 * @param notify 
 * @return void 
 */
void CTinyUMLGeneralization::OnNotify(const IS_NOTIFY& notify)
{
	if(m_bCreated)
	{
		CIsDrawEntity* pEnt=static_cast<CIsDrawEntity*>(notify.pEntFrom);

		if(IS_DELETE_ENTITY == notify.hdr.code)
		{
			if((pEnt == m_src.pEnt) || (pEnt == m_dest.pEnt)) Erase();
		}
		else
		{
			if(pEnt == m_src.pEnt)
			{
				CPoint oldSrcPoint = m_src.point();
				m_src.updatePoint();
				
				CSize srcDelta = m_src.point() - oldSrcPoint;
				//CTinyUMLEditor* pTinyUMLEditor=static_cast<CTinyUMLEditor*>(CTinyDrawCtrlApp::GetCurEditor());
				//if(NULL != pTinyUMLEditor){
				//	CTinyUMLTheme* pUMLTheme=static_cast<CTinyUMLTheme*>(pTinyUMLEditor->theme());
				//	if(pUMLTheme->relativeNodes()){
						long i = 0;
						
						for(; i < m_nodes.GetSize() / 2; ++i)
							m_nodes[i] += srcDelta;
					//}
				//}
			}
			else if(pEnt == m_dest.pEnt)
			{
				CPoint oldDestPoint = m_dest.point();
				m_dest.updatePoint();
				
				CSize destDelta = m_dest.point() - oldDestPoint;
				//CTinyUMLEditor* pTinyUMLEditor=static_cast<CTinyUMLEditor*>(CTinyDrawCtrlApp::GetCurEditor());
				//if(NULL != pTinyUMLEditor){
				//	CTinyUMLTheme* pUMLTheme=static_cast<CTinyUMLTheme*>(pTinyUMLEditor->theme());
				//	if(pUMLTheme->relativeNodes()){
						long i = 0;
						
						for(; i < m_nodes.GetSize(); ++i)
							m_nodes[i] += destDelta;
					//}
				//}
			}
		}
	}
}

/**
 * DrawSelectionMarkers:
 *
 * @param dc 
 * @param rect 
 * @return void 
 */
void CTinyUMLGeneralization::DrawSelectionMarkers(CDC *dc, CRect rect) const
{
	dc->SelectStockObject( BLACK_BRUSH );

	CRect rectSelect;
	int horz = m_varMarkerSize.cx * 0.5;
	int vert = m_varMarkerSize.cy * 0.5;
	
	rectSelect.left = m_src.point().x - horz;rectSelect.top    = m_src.point().y - vert;
	rectSelect.right= m_src.point().x + horz;rectSelect.bottom = m_src.point().y + vert;
	dc->Rectangle( rectSelect );
	for(long i = 0; i < m_nodes.GetSize(); ++i){
		rectSelect.left = m_nodes[i].x - horz;rectSelect.top    = m_nodes[i].y - vert;
		rectSelect.right= m_nodes[i].x + horz;rectSelect.bottom = m_nodes[i].y + vert;
		dc->Rectangle( rectSelect );
	}
	rectSelect.left = m_dest.point().x - horz;rectSelect.top    = m_dest.point().y - vert;
	rectSelect.right= m_dest.point().x + horz;rectSelect.bottom = m_dest.point().y + vert;
	dc->Rectangle( rectSelect );

	/*
	// name
	if(m_bShowName){
		CFont *pOldFont = pDC->SelectObject(m_pNameFont);
		pDC->SetTextColor(m_lineColor);
		pDC->SetBkMode(TRANSPARENT);
		pDC->DrawText(m_name, nameRect(),
			DT_CENTER | DT_SINGLELINE | DT_VCENTER | DT_END_ELLIPSIS | DT_NOPREFIX);
		pDC->SelectObject(pOldFont);
	}
	
	pDC->SelectObject(pOldPen);
	*/
}

/**
 * GetHitCode:
 *
 * @param point 
 * @return int 
 */
int CTinyUMLGeneralization::GetHitCode(CPoint point)
{
	//////////////////////////////////////////////////////////////////////////
	/// check control points.
	int horz = m_varMarkerSize.cx * 0.5;
	int vert = m_varMarkerSize.cy * 0.5;
	CRect rectSelect;

	rectSelect.left = m_src.point().x - horz;rectSelect.top    = m_src.point().y - vert;
	rectSelect.right= m_src.point().x + horz;rectSelect.bottom = m_src.point().y + vert;
	if(rectSelect.PtInRect(point)) return DEHT_CTRLPOINT;

	for(long i = 0; i < m_nodes.GetSize(); ++i){
		rectSelect.left = m_nodes[i].x - horz;rectSelect.top    = m_nodes[i].y - vert;
		rectSelect.right= m_nodes[i].x + horz;rectSelect.bottom = m_nodes[i].y + vert;
		if(rectSelect.PtInRect(point)) return DEHT_CTRLPOINT;
	}
	rectSelect.left = m_dest.point().x - horz;rectSelect.top    = m_dest.point().y - vert;
	rectSelect.right= m_dest.point().x + horz;rectSelect.bottom = m_dest.point().y + vert;
	if(rectSelect.PtInRect(point)) return DEHT_CTRLPOINT;
	//////////////////////////////////////////////////////////////////////////


	const static float nTol=2.f;
	double dx[2]={0.f,},dy[2]={0.f,},dot=0.f,d=0.f,cross=0.,h=0.;
	CPoint ptStart=m_src.point(),ptEnd;
	for(i = 0; i < m_nodes.GetSize(); ++i){
		ptEnd = m_nodes[i];

		rectSelect.left  = (ptStart.x < ptEnd.x) ? ptStart.x - 1: ptEnd.x - 1;
		rectSelect.top   = (ptStart.y < ptEnd.y) ? ptStart.y - 1: ptEnd.y - 1;
		rectSelect.right = (ptStart.x > ptEnd.x) ? ptStart.x + 1: ptEnd.x + 1;
		rectSelect.bottom= (ptStart.y > ptEnd.y) ? ptStart.y + 1: ptEnd.y + 1;
		if(rectSelect.PtInRect(point)){
			dx[0]=ptEnd.x - ptStart.x;dy[0]=ptEnd.y - ptStart.y;
			dx[1]=point.x - ptStart.x;dy[1]=point.y - ptStart.y;
			dot = dx[0]*dx[1] + dy[0]*dy[1];
			d = sqrt(dx[0]*dx[0] + dy[0]*dy[0]);
			dx[0] = dx[0]*dot/d;dy[0] = dy[0]*dot/d;
			cross = dx[0]*dy[1] - dy[0]*dx[1];
			h = cross/(2*dot);
			if(fabs(h) <= nTol) return DEHT_BODY;
		}

		ptStart = ptEnd;
	}
	ptEnd = m_dest.point();
	
	rectSelect.left  = (ptStart.x < ptEnd.x) ? ptStart.x - 1: ptEnd.x - 1;
	rectSelect.top   = (ptStart.y < ptEnd.y) ? ptStart.y - 1: ptEnd.y - 1;
	rectSelect.right = (ptStart.x > ptEnd.x) ? ptStart.x + 1: ptEnd.x + 1;
	rectSelect.bottom= (ptStart.y > ptEnd.y) ? ptStart.y + 1: ptEnd.y + 1;
	if(rectSelect.PtInRect(point)){
		dx[0]=ptEnd.x - ptStart.x;dy[0]=ptEnd.y - ptStart.y;
		dx[1]=point.x - ptStart.x;dy[1]=point.y - ptStart.y;
		dot = dx[0]*dx[1] + dy[0]*dy[1];
		d = sqrt(dx[0]*dx[0] + dy[0]*dy[0]);
		dx[0] = dx[0]*dot/d;dy[0] = dy[0]*dot/d;
		cross = dx[0]*dy[1] - dy[0]*dx[1];
		h = cross/(2*dot);
		if(fabs(h) <= nTol) return DEHT_BODY;
	}

	return DEHT_NONE;
}

/**
 * Serialize:
 *
 * @param ar 
 * @return void 
 */
void CTinyUMLGeneralization::Serialize(CArchive &ar)
{
	CTinyUMLRelation::Serialize(ar);
	
	if(ar.IsStoring()){
		ar << long(m_bRealize);
	}else{
		long _flag;
		ar >> _flag; m_bRealize = _flag ? true : false;

		m_penStyle = m_bRealize ? PS_DOT : PS_SOLID;
	}
}

/**
 * Copy:
 *
 * @param p 
 * @return void 
 */
void CTinyUMLGeneralization::Copy(CTinyUMLGeneralization *p)
{
	CTinyUMLRelation::Copy(p);

	m_bRealize = p->m_bRealize;
	m_fillColor= p->m_fillColor;
}

COLORREF CTinyUMLGeneralization::GetFillColor() const
{
	return m_fillColor;
}
