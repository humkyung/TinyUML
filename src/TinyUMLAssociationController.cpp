// TinyUMLAssociationController.cpp: implementation of the CTinyUMLAssociationController class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "TinyUML.h"
#include <IsDrawCtrlHost.h>
#include <IsDrawEditor.h>
#include "TinyUMLClass.h"
#include "TinyUMLAssociation.h"
#include "TinyUMLAssociationController.h"
#include "TinyUMLAssociationPropertyPage.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

IS_IMPLEMENT_CONTROLLER_FUNC(CTinyUMLAssociationController)
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CTinyUMLAssociationController::CTinyUMLAssociationController()
{

}

CTinyUMLAssociationController::~CTinyUMLAssociationController()
{

}

/**
 * OnLButtonDown:
 *
 * @param mouse_event 
 * @return void 
 */
void CTinyUMLAssociationController::OnLButtonDown(const IS_MOUSE_EVENT& mouse_event)
{
	CIsDrawEditor* pEditor=mouse_event.pEditor;

	if(NULL == mouse_event.pEnt)
	{
	}
	else
	{
		CTinyUMLAssociation* pUMLEnt=static_cast<CTinyUMLAssociation*>(mouse_event.pEnt);
		m_nHitCode = mouse_event.pEnt->HitTest(mouse_event.xsnapoint);
		if(mouse_event.pEnt->IsSelected())
		{
			pUMLEnt->BeginDrag(mouse_event.virtpoint, pUMLEnt->handleAt(mouse_event.xsnapoint));
		}
		else
		{
			if(NULL != mouse_event.pEnt) mouse_event.pEnt->Select(TRUE);
			
			//////////////////////////////////////////////////////////////////////////
			IS_NOTIFY notify;
			notify.hdr.hwndFrom = pEditor->GetSafeHwnd();
			notify.pEntFrom = mouse_event.pEnt;
			pEditor->SendMessage(WM_NOTIFY,(WPARAM)IS_SELECT_ENTITY,(LPARAM)(&notify));

			pUMLEnt->BeginDrag(mouse_event.virtpoint,pUMLEnt->handleAt(mouse_event.xsnapoint));
		}
	}
}

/**	\brief	The CTinyUMLAssociationController::OnMouseMove function

	\param	mouse_event	a parameter of type const IS_MOUSE_EVENT&

	\return	void	
*/
void CTinyUMLAssociationController::OnMouseMove(const IS_MOUSE_EVENT& mouse_event)
{
	CIsDrawEditor* pEditor=mouse_event.pEditor;

	if(NULL != mouse_event.pEnt)
	{
		if(mouse_event.pEnt->IsSelected())
		{
			CTinyUMLAssociation* pUMLEnt=static_cast<CTinyUMLAssociation*>(mouse_event.pEnt);
			pUMLEnt->Drag(mouse_event.virtpoint);
			pEditor->RedrawWindow();

			pUMLEnt->GetDoc()->SetModified(TRUE);
		}
	}
	else
	{

	}
}

/**	\brief	The CTinyUMLAssociationController::OnLButtonUp function

	\param	mouse_event	a parameter of type const IS_MOUSE_EVENT&

	\return	void	
*/
void CTinyUMLAssociationController::OnLButtonUp(const IS_MOUSE_EVENT& mouse_event)
{
	if(NULL == mouse_event.pEnt){
	}else{
		CTinyUMLRelation* pRel=static_cast<CTinyUMLRelation*>(mouse_event.pEnt);
		pRel->EndDrag();
	}
}

/**
 * ModifyProperties:
 *
 * @return void 
 */
void CTinyUMLAssociationController::ModifyProperties()
{
	CPropertySheet sheet("Element properties");
	CTinyUMLAssociationPropertyPage associationPropertyPage;
	
	// setup pages
	CTinyUMLAssociation* pEnt=static_cast<CTinyUMLAssociation*>(GetEntity());

	associationPropertyPage.m_bAggregation = pEnt->m_bAggregation;
	associationPropertyPage.m_bNavigable = pEnt->m_bNavigable;
	associationPropertyPage.m_srcMultiplicity = pEnt->m_srcMultiplicity;
	associationPropertyPage.m_destMultiplicity = pEnt->m_destMultiplicity;
	associationPropertyPage.m_bShowSrcMultiplicity = pEnt->m_bShowSrcMultiplicity;
	associationPropertyPage.m_bShowDestMultiplicity = pEnt->m_bShowDestMultiplicity;
	associationPropertyPage.m_bShowName = pEnt->m_bShowName;
	associationPropertyPage.m_name = pEnt->m_name;

	// add pages
	sheet.AddPage(&associationPropertyPage);
	
	if(sheet.DoModal() == IDOK){
		pEnt->m_bAggregation = associationPropertyPage.m_bAggregation ? true : false;
		pEnt->m_bNavigable = associationPropertyPage.m_bNavigable ? true : false;
		pEnt->m_srcMultiplicity = associationPropertyPage.m_srcMultiplicity;
		pEnt->m_destMultiplicity = associationPropertyPage.m_destMultiplicity;
		pEnt->m_bShowSrcMultiplicity = associationPropertyPage.m_bShowSrcMultiplicity ? true : false;
		pEnt->m_bShowDestMultiplicity = associationPropertyPage.m_bShowDestMultiplicity ? true : false;
		pEnt->m_bShowName = associationPropertyPage.m_bShowName ? true : false;
		pEnt->m_name = associationPropertyPage.m_name;

		//////////////////////////////////////////////////////////////////////////
		pEnt->GetDoc()->SetModified(TRUE);
	}
}
