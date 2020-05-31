// TinyUMLGeneralizationController.cpp: implementation of the CTinyUMLGeneralizationController class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include <assert.h>
#include <IsDrawCtrlHost.h>
#include <IsDrawEditor.h>
#include "TinyUML.h"
#include "TinyUMLClass.h"
#include "TinyUMLGeneralization.h"
#include "TinyUMLGeneralizationController.h"
#include "TinyUMLGeneralizationPropertyPage.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

IS_IMPLEMENT_CONTROLLER_FUNC(CTinyUMLGeneralizationController)
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CTinyUMLGeneralizationController::CTinyUMLGeneralizationController()
{
	m_bRealize = false;
}

CTinyUMLGeneralizationController::~CTinyUMLGeneralizationController()
{

}

/**	\brief	The CTinyUMLGeneralizationController::OnLButtonDown function

	\param	mouse_event	a parameter of type const IS_MOUSE_EVENT&

	\return	void	
*/
void CTinyUMLGeneralizationController::OnLButtonDown(const IS_MOUSE_EVENT& mouse_event)
{	
	CIsDrawEditor* pEditor=mouse_event.pEditor;
	const CPoint virtpoint=mouse_event.virtpoint;

	if(NULL == mouse_event.pEnt)
	{
		long nHitCode=DEHT_NONE;
		CTinyUMLEntity *pEnt = static_cast<CTinyUMLEntity*>(pEditor->GetAt(nHitCode,mouse_event.xsnapoint));
		
		if(pEnt == NULL || !pEnt->IsKindOf(CTinyUMLClass::TypeString()))
		{
			IS_NOTIFY notify;
			notify.hdr.hwndFrom = pEditor->GetSafeHwnd();
			notify.pEntFrom = NULL;
			pEditor->SendMessage(WM_NOTIFY,(WPARAM)IS_ABORT,(LPARAM)(&notify));
			
			AfxMessageBox(IDS_SOURCE_GENERALIZATION_ERROR);
			return;
		}
		
		Set(new CTinyUMLGeneralization(pEditor->GetDoc(), this,virtpoint, pEnt,m_bRealize),mouse_event.pEditor);
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
		CIsDrawEntity* pEnt=mouse_event.pEnt;

		CTinyUMLGeneralization* pUMLEnt=static_cast<CTinyUMLGeneralization*>(pEnt);
		m_nHitCode = pEnt->HitTest(mouse_event.xsnapoint);
		if(pEnt->IsSelected())
		{
			pUMLEnt->BeginDrag(virtpoint, pUMLEnt->handleAt(mouse_event.xsnapoint));
		}
		else
		{
			if(NULL != pEnt) pEnt->Select(TRUE);
			//////////////////////////////////////////////////////////////////////////
			IS_NOTIFY notify;
			notify.hdr.hwndFrom = pEditor->GetSafeHwnd();
			notify.pEntFrom = pEnt;
			pEditor->SendMessage(WM_NOTIFY,(WPARAM)IS_SELECT_ENTITY,(LPARAM)(&notify));

			pUMLEnt->BeginDrag(virtpoint,pUMLEnt->handleAt(mouse_event.xsnapoint));
		}
	}
}

/**	\brief	The CTinyUMLGeneralizationController::OnLButtonUp function

	\param	mouse_event	a parameter of type const IS_MOUSE_EVENT&

	\return	void	
*/
void CTinyUMLGeneralizationController::OnLButtonUp(const IS_MOUSE_EVENT& mouse_event)
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
			if(pRel->Finish(point, pUMLEnt))
			{	
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
			}
			else
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
				
				AfxMessageBox(IDS_DEST_SRC_GENERALIZATION_ERROR);
			}
			Set(NULL,mouse_event.pEditor);
		}
	}
	else
	{
		CTinyUMLRelation* pRel=static_cast<CTinyUMLRelation*>(mouse_event.pEnt);
		pRel->EndDrag();
	}
}

/**	\brief	The CTinyUMLGeneralizationController::OnMouseMove function

	\param	mouse_event	a parameter of type const IS_MOUSE_EVENT&

	\return	void	
*/
void CTinyUMLGeneralizationController::OnMouseMove(const IS_MOUSE_EVENT& mouse_event)
{
	CIsDrawEditor* pEditor=mouse_event.pEditor;
	CPoint virtpoint=mouse_event.virtpoint;
	
	if(NULL != mouse_event.pEnt){
		if(mouse_event.pEnt->IsSelected()){
			CTinyUMLGeneralization* pUMLEnt=static_cast<CTinyUMLGeneralization*>(mouse_event.pEnt);
			pUMLEnt->Drag(virtpoint);

			pEditor->RedrawWindow();
			mouse_event.pEnt->GetDoc()->SetModified(TRUE);
		}
	}else{
		if(NULL == GetEntity()) return;
		CTinyUMLRelation* pRel=static_cast<CTinyUMLRelation*>(GetEntity());
		pRel->DragTemp(virtpoint);
		pEditor->RedrawWindow();
	}
}

/**
 * ModifyProperties:
 *
 * @return void 
 */
void CTinyUMLGeneralizationController::ModifyProperties()
{
	CPropertySheet sheet("Element properties");
	CTinyUMLGeneralizationPropertyPage generalizationPropertyPage;
	
	// setup pages
	CTinyUMLGeneralization* pEnt=static_cast<CTinyUMLGeneralization*>(GetEntity());
	generalizationPropertyPage.m_bRealize = pEnt->m_bRealize;
	
	// add pages
	sheet.AddPage(&generalizationPropertyPage);
	
	if(sheet.DoModal() == IDOK){
		pEnt->m_bRealize = generalizationPropertyPage.m_bRealize ? true : false;
		pEnt->m_penStyle = m_bRealize ? PS_DOT : PS_SOLID;
		
		//////////////////////////////////////////////////////////////////////////
		pEnt->GetDoc()->SetModified(TRUE);
	}
}
