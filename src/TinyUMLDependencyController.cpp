// TinyUMLDependencyController.cpp: implementation of the CTinyUMLDependencyController class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "TinyUML.h"
#include <IsDrawCtrlHost.h>
#include <IsDrawEditor.h>
#include "TinyUMLClass.h"
#include "TinyUMLDependency.h"
#include "TinyUMLDependencyController.h"
#include "TinyUMLDependencyPropertyPage.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

IS_IMPLEMENT_CONTROLLER_FUNC(CTinyUMLDependencyController)
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CTinyUMLDependencyController::CTinyUMLDependencyController()
{
	m_defaultType = Diagonal;
}

CTinyUMLDependencyController::~CTinyUMLDependencyController()
{

}

/**
 * OnLButtonDown:
 *
 * @param mouse_event 
 * @return void 
 */
void CTinyUMLDependencyController::OnLButtonDown(const IS_MOUSE_EVENT& mouse_event)
{
	CIsDrawEditor* pEditor=mouse_event.pEditor;
	CPoint point = mouse_event.virtpoint;

	if(NULL == mouse_event.pEnt)
	{
		long nHitCode=DEHT_NONE;
		CTinyUMLEntity *pUMLEnt = static_cast<CTinyUMLEntity*>(pEditor->GetAt(nHitCode,mouse_event.xsnapoint));
		
		if((NULL == pUMLEnt) || !pUMLEnt->IsKindOf(CTinyUMLClass::TypeString()))
		{
			IS_NOTIFY notify;
			notify.hdr.hwndFrom = pEditor->GetSafeHwnd();
			notify.pEntFrom = NULL;
			pEditor->SendMessage(WM_NOTIFY,(WPARAM)IS_ABORT,(LPARAM)(&notify));
			
			AfxMessageBox(IDS_SOURCE_GENERALIZATION_ERROR);
			return;
		}
		
		Set(new CTinyUMLDependency(pEditor->GetDoc(), this,mouse_event.virtpoint, pUMLEnt),mouse_event.pEditor);
		if(NULL != pEditor)
		{
			GetEntity()->SetupTheme(pEditor->GetDoc()->GetTheme());
			
			//////////////////////////////////////////////////////////////////////////
			IS_NOTIFY notify;
			notify.hdr.hwndFrom = pEditor->GetSafeHwnd();
			notify.pEntFrom = GetEntity();
			pEditor->SendMessage(WM_NOTIFY,(WPARAM)IS_START_CREATE_ENTITY,(LPARAM)(&notify));
		}
	}
	else
	{
		CTinyUMLDependency* pUMLEnt=static_cast<CTinyUMLDependency*>(mouse_event.pEnt);
		m_nHitCode = pUMLEnt->GetHitCode(point);
		if(pUMLEnt->IsSelected())
		{
			pUMLEnt->BeginDrag(point, pUMLEnt->handleAt(point));
		}
		else
		{
			if(NULL != pUMLEnt) pUMLEnt->Select(TRUE);
			//////////////////////////////////////////////////////////////////////////
			IS_NOTIFY notify;
			notify.hdr.hwndFrom = pEditor->GetSafeHwnd();
			notify.pEntFrom = pUMLEnt;
			pEditor->SendMessage(WM_NOTIFY,(WPARAM)IS_SELECT_ENTITY,(LPARAM)(&notify));
			
			pUMLEnt->BeginDrag(point,pUMLEnt->handleAt(mouse_event.xsnapoint));
		}
	}
}

/**	\brief	The CTinyUMLDependencyController::OnMouseMove function

	\param	mouse_event	a parameter of type const IS_MOUSE_EVENT&

	\return	void	
*/
void CTinyUMLDependencyController::OnMouseMove(const IS_MOUSE_EVENT& mouse_event)
{
	CIsDrawEditor* pEditor=mouse_event.pEditor;

	if(NULL != mouse_event.pEnt)
	{
		if(mouse_event.pEnt->IsSelected())
		{
			CTinyUMLDependency* pUMLEnt=static_cast<CTinyUMLDependency*>(mouse_event.pEnt);
			pUMLEnt->Drag(mouse_event.virtpoint);
			pEditor->RedrawWindow();

			pUMLEnt->GetDoc()->SetModified(TRUE);
		}
	}
	else
	{
		if(NULL == GetEntity()) return;
		CTinyUMLRelation* pRel=static_cast<CTinyUMLRelation*>(GetEntity());
		pRel->DragTemp(mouse_event.virtpoint);
		pEditor->RedrawWindow();
	}
}

/**	\brief	The CTinyUMLDependencyController::OnLButtonUp function

	\param	mouse_event	a parameter of type const IS_MOUSE_EVENT&

	\return	void	
*/
void CTinyUMLDependencyController::OnLButtonUp(const IS_MOUSE_EVENT& mouse_event)
{
	CIsDrawEditor* pEditor=mouse_event.pEditor;
	CPoint point=mouse_event.virtpoint;
	
	if(NULL == mouse_event.pEnt)
	{
		if(NULL != GetEntity())
		{
			long nHitCode=DEHT_NONE;
			CTinyUMLEntity *pUMLEnt = static_cast<CTinyUMLEntity*>(pEditor->GetAt(nHitCode,point));
			
			if((NULL == pUMLEnt) || !(pUMLEnt->IsKindOf(CTinyUMLClass::TypeString())))
			{
				//////////////////////////////////////////////////////////////////////////
				IS_NOTIFY notify;
				notify.hdr.hwndFrom = pEditor->GetSafeHwnd();
				notify.pEntFrom = NULL;
				pEditor->SendMessage(WM_NOTIFY,(WPARAM)IS_START_CREATE_ENTITY,(LPARAM)(&notify));
							
				delete GetEntity();
				Set(NULL,mouse_event.pEditor);
				
				notify.hdr.hwndFrom = pEditor->GetSafeHwnd();
				notify.pEntFrom = NULL;
				pEditor->SendMessage(WM_NOTIFY,(WPARAM)IS_ABORT,(LPARAM)(&notify));
				
				AfxMessageBox(IDS_DESTINATION_GENERALIZATION_ERROR);
				return;
			}
			CTinyUMLRelation* pRel=static_cast<CTinyUMLRelation*>(GetEntity());
			pRel->Finish(point, pUMLEnt);
			
			//////////////////////////////////////////////////////////////////////////
			IS_NOTIFY notify;
			notify.hdr.hwndFrom = pEditor->GetSafeHwnd();
			notify.pEntFrom = NULL;
			pEditor->SendMessage(WM_NOTIFY,(WPARAM)IS_START_CREATE_ENTITY,(LPARAM)(&notify));
			
			//////////////////////////////////////////////////////////////////////////
			notify.hdr.hwndFrom = pEditor->GetSafeHwnd();
			notify.pEntFrom = GetEntity();
			pEditor->SendMessage(WM_NOTIFY,(WPARAM)IS_CREATE_ENTITY,(LPARAM)(&notify));
			pEditor->SendToBack(pRel);
			
			// align src point to grid
			pRel->BeginDrag(pRel->handlePoint(0), 0);
			pRel->Drag(pRel->handlePoint(0));
			pRel->EndDrag();
			
			// align dest point to grid
			pRel->BeginDrag(pRel->handlePoint(1), 1);
			pRel->Drag(pRel->handlePoint(1));
			pRel->EndDrag();
			
			Set(NULL,mouse_event.pEditor);
		}
	}
	else
	{
		CTinyUMLRelation* pRel=static_cast<CTinyUMLRelation*>(mouse_event.pEnt);
		pRel->EndDrag();
	}
}

/**
 * ModifyProperties:
 *
 * @return void 
 */
void CTinyUMLDependencyController::ModifyProperties()
{
	CPropertySheet sheet("Element properties");
	CTinyUMLDependencyPropertyPage dependencyPropertyPage;
	
	// setup pages
	CTinyUMLDependency* pEnt=static_cast<CTinyUMLDependency*>(GetEntity());

	dependencyPropertyPage.m_bShowArrow = pEnt->m_bShowArrow;
	dependencyPropertyPage.m_bShowName = pEnt->m_bShowName;
	dependencyPropertyPage.m_name = pEnt->m_name;
	
	// add pages
	sheet.AddPage(&dependencyPropertyPage);
	
	if(sheet.DoModal() == IDOK)
	{
		pEnt->m_bShowArrow = dependencyPropertyPage.m_bShowArrow ? true : false;
		pEnt->m_bShowName = dependencyPropertyPage.m_bShowName ? true : false;
		pEnt->m_name = dependencyPropertyPage.m_name;
		
		//////////////////////////////////////////////////////////////////////////
		pEnt->GetDoc()->SetModified(TRUE);
	}
}
