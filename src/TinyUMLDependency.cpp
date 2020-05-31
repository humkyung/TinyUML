// TinyUMLDependency.cpp: implementation of the CTinyUMLDependency class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "TinyUML.h"
#include <IsDrawCtrlHost.h>
#include <IsDrawEditor.h>
#include "TinyUMLEditor.h"
#include "TinyUMLDependency.h"
#include "TinyUMLTheme.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

IMPLEMENT_SERIAL(CTinyUMLDependency, CTinyUMLRelation, 1)
IS_OBJ_IMPLEMENT_FUNC(CTinyUMLDependency , CTinyUMLRelation , "_TINY_UML_DEPENDENCY_")
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CTinyUMLDependency::CTinyUMLDependency() : CTinyUMLRelation()
{
	SetTypeString( CTinyUMLDependency::TypeString() );
}

CTinyUMLDependency::CTinyUMLDependency(CIsDrawEntContainer* pDoc,CIsControllerObject* pController,const CPoint &point, CTinyUMLEntity *pEnt) : 
		CTinyUMLRelation(pDoc,pController,point,pEnt)
{
	SetTypeString( CTinyUMLDependency::TypeString() );
	m_bShowArrow = true;
	m_penStyle = PS_DOT;
	//SetupTheme();
}

CTinyUMLDependency::~CTinyUMLDependency()
{
	try
	{
	}
	catch(...)
	{
	}
}

/**
 * SetupTheme:
 *
 * @return void 
 */
void CTinyUMLDependency::SetupTheme(CTinyDrawTheme *pTheme)
{	
	CTinyUMLRelation::SetupTheme(pTheme);

	if(NULL != pTheme)
	{
		CTinyUMLTheme* pUMLTheme=static_cast<CTinyUMLTheme*>(pTheme);
	
		m_lineColor = pUMLTheme->GetLineColor();
	}
}

/**
 * OnNotify:
 *
 * @param notify 
 * @return void 
 */
void CTinyUMLDependency::OnNotify(const IS_NOTIFY& notify)
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
 * Serialize:
 *
 * @param ar 
 * @return void 
 */
void CTinyUMLDependency::Serialize(CArchive &ar)
{
	CTinyUMLRelation::Serialize(ar);
	
	if(ar.IsStoring())
	{
		ar << long(m_bShowArrow);
	}else{
		long _flag;
		ar >> _flag; m_bShowArrow = _flag ? true : false;
		
		m_penStyle = PS_DOT;
	}
}

/**
 * Copy:
 *
 * @param p 
 * @return void 
 */
void CTinyUMLDependency::Copy(CTinyUMLDependency *p)
{
	CTinyUMLRelation::Copy(p);

	m_bShowArrow = p->m_bShowArrow;
}

bool CTinyUMLDependency::IsShowArrow() const
{
	return m_bShowArrow;
}
