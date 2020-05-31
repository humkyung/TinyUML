// TinyUMLAssociation.cpp: implementation of the CTinyUMLAssociation class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include <math.h>
#include <IsDrawCtrlHost.h>
#include "TinyUML.h"
#include "TinyUMLEditor.h"
#include "TinyUMLAssociation.h"
#include "TinyUMLTheme.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

IMPLEMENT_SERIAL(CTinyUMLAssociation, CTinyUMLRelation, 1)
IS_OBJ_IMPLEMENT_FUNC(CTinyUMLAssociation , CTinyUMLEntity , "_TINY_UML_ASSOCIATION_")
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CTinyUMLAssociation::CTinyUMLAssociation()
{
	SetTypeString( CTinyUMLAssociation::TypeString() );
}

CTinyUMLAssociation::CTinyUMLAssociation(CIsDrawEntContainer* pDoc, CIsControllerObject *pController,
					 const CPoint &point, CTinyUMLEntity *pEnt,bool bAggregation, bool bNavigable) 
					 : CTinyUMLRelation(pDoc,pController,point,pEnt)
{
	SetTypeString( CTinyUMLAssociation::TypeString() );

	m_bAggregation = bAggregation;
	m_bNavigable = bNavigable;
	m_srcMultiplicity = "1";
	m_destMultiplicity = "1";
	m_bShowSrcMultiplicity = false;
	m_bShowDestMultiplicity = false;
	m_srcMultiplicityOffset = CSize(0, 0);
	m_destMultiplicityOffset = CSize(0, 0);
}

CTinyUMLAssociation::~CTinyUMLAssociation()
{
	try{
	}catch(...){}
}

/**
 * SetupTheme:
 *
 * @return void 
 */
void CTinyUMLAssociation::SetupTheme(CTinyDrawTheme* pTheme)
{
	CTinyUMLRelation::SetupTheme(pTheme);

	if(NULL != pTheme)
	{
		CTinyUMLTheme* pUMLTheme=static_cast<CTinyUMLTheme*>(pTheme);
		
		m_lineColor = pUMLTheme->GetLineColor();
		m_fillColor = (*pUMLTheme->GetEndSymbolColor());
		m_pMultiplicityFont = pUMLTheme->multiplicityFont();
	}
}

CRect CTinyUMLAssociation::srcMultiplicityRect() const
{
	ASSERT(m_bCreated == true);
	
	long index = 0;
	CPoint A = m_src.point();
	CPoint B = index == m_nodes.GetSize() ? m_dest.point() : m_nodes[index];
	CRect R = m_src.pEnt->GetRect();
	R.InflateRect(16, 16);
	
	double dx = B.x - A.x;
	double dy = B.y - A.y;
	double ox = dx > 0 ? (R.right - A.x + 10) : (R.left - A.x - 10);
	double oy = ox * (dy / dx) - 14;
	
	if(A.y + oy > R.bottom || A.y + oy < R.top)
	{
		oy = dy > 0 ? (R.bottom - A.y + 6) : (R.top - A.y - 6);
		ox = oy * (dx / dy) + 18;
	}
	
	CPoint O(long(A.x + ox), long(A.y + oy));
	CRect rect(O, CSize(0, 0));
	rect.InflateRect(18, 8);
	rect.OffsetRect(m_srcMultiplicityOffset);
	return rect;
}

CRect CTinyUMLAssociation::destMultiplicityRect() const
{
	ASSERT(m_bCreated == true);
	
	long index = m_nodes.GetSize();
	CPoint B = index == 0 ? m_src.point() : m_nodes[index - 1];
	CPoint A = m_dest.point();
	CRect R = m_dest.pEnt->GetRect();
	R.InflateRect(16, 16);
	
	double dx = B.x - A.x;
	double dy = B.y - A.y;
	double ox = dx > 0 ? (R.right - A.x + 10) : (R.left - A.x - 10);
	double oy = ox * (dy / dx) - 14;
	
	if(A.y + oy > R.bottom || A.y + oy < R.top)
	{
		oy = dy > 0 ? (R.bottom - A.y + 6) : (R.top - A.y - 6);
		ox = oy * (dx / dy) + 18;
	}
	
	CPoint O(long(A.x + ox), long(A.y + oy));
	CRect rect(O, CSize(0, 0));
	rect.InflateRect(18, 8);
	rect.OffsetRect(m_destMultiplicityOffset);
	return rect;
}

/**
 * OnNotify:
 *
 * @param notify 
 * @return void 
 */
void CTinyUMLAssociation::OnNotify(const IS_NOTIFY& notify)
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
			if(pEnt == m_src.pEnt){
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
			}else if(pEnt == m_dest.pEnt){
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

int CTinyUMLAssociation::GetHitCode(CPoint point)
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

void CTinyUMLAssociation::Serialize(CArchive &ar)
{
	CTinyUMLRelation::Serialize(ar);
	
	if(ar.IsStoring())
	{
		ar << long(m_bAggregation);
		ar << long(m_bNavigable);
		ar << m_srcMultiplicity;
		ar << m_destMultiplicity;
		ar << long(m_bShowSrcMultiplicity);
		ar << long(m_bShowDestMultiplicity);
		ar << m_srcMultiplicityOffset;
		ar << m_destMultiplicityOffset;		
	}else{
		long _flag;
		
		ar >> _flag; m_bAggregation = _flag ? true : false;
		ar >> _flag; m_bNavigable = _flag ? true : false;
		ar >> m_srcMultiplicity;
		ar >> m_destMultiplicity;
		ar >> _flag; m_bShowSrcMultiplicity = _flag ? true : false;
		ar >> _flag; m_bShowDestMultiplicity = _flag ? true : false;
		ar >> m_srcMultiplicityOffset;
		ar >> m_destMultiplicityOffset;
	}
}

COLORREF CTinyUMLAssociation::GetFillColor() const
{
	return m_fillColor;
}

CFont* CTinyUMLAssociation::GetMultiplicityFont() const
{
	return m_pMultiplicityFont;
}

bool CTinyUMLAssociation::IsAggregation() const
{
	return m_bAggregation;
}

bool CTinyUMLAssociation::IsNavigable() const
{
	return m_bNavigable;
}

bool CTinyUMLAssociation::IsShowSrcMultiplicity() const
{
	return m_bShowSrcMultiplicity;
}

bool CTinyUMLAssociation::IsShowDestMultiplicity() const
{
	return m_bShowDestMultiplicity;
}

CString CTinyUMLAssociation::GetSrcMultiplicity() const
{
	return m_srcMultiplicity;
}

CString CTinyUMLAssociation::GetDestMultiplicity() const
{
	return m_destMultiplicity;
}
