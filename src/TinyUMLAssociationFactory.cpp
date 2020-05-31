// TinyUMLAssociationFactory.cpp: implementation of the CTinyUMLAssociationFactory class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include <assert.h>
#include "TinyUML.h"
#include <IsDrawCtrlHost.h>
#include <IsDrawEditor.h>
#include "TinyUMLClass.h"
#include "TinyUMLAssociation.h"
#include "TinyUMLAssociationFactory.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CTinyUMLAssociationFactory::CTinyUMLAssociationFactory( bool bAggregation, bool bNavigable)
{
	m_bAggregation = bAggregation;
	m_bNavigable   = bNavigable;
}

CTinyUMLAssociationFactory::~CTinyUMLAssociationFactory()
{

}

/**	\brief	The CTinyUMLAssociationFactory::OnLButtonDown function

	\param	mouse_event	a parameter of type const IS_MOUSE_EVENT&

	\return	void
*/
void CTinyUMLAssociationFactory::OnLButtonDown(const IS_MOUSE_EVENT& mouse_event)
{
	assert(NULL == mouse_event.pEnt);

	CIsDrawEditor* pEditor=mouse_event.pEditor;
	long nHitCode=DEHT_NONE;
	CTinyUMLEntity *_pEnt = static_cast<CTinyUMLEntity*>(pEditor->GetAt(nHitCode,mouse_event.virtpoint));
	
	if((NULL  == _pEnt) || !_pEnt->IsKindOf(CTinyUMLClass::TypeString()))
	{
		IS_NOTIFY notify;
		notify.hdr.hwndFrom = pEditor->GetSafeHwnd();
		notify.pEntFrom = NULL;
		pEditor->SendMessage(WM_NOTIFY,(WPARAM)IS_ABORT,(LPARAM)(&notify));

		AfxMessageBox(IDS_SOURCE_AGGREGATION_ERROR);
		return;
	}
	
	Set(new CTinyUMLAssociation(pEditor->GetDoc(), this,mouse_event.virtpoint, _pEnt, m_bAggregation, m_bNavigable),NULL);
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

/**	\brief	The CTinyUMLAssociationFactory::OnMouseMove function

	\param	mouse_event	a parameter of type const IS_MOUSE_EVENT&

	\return	void	
*/
void CTinyUMLAssociationFactory::OnMouseMove(const IS_MOUSE_EVENT& mouse_event)
{
	assert(NULL == mouse_event.pEnt);

	if(NULL == GetEntity()) return;
	CTinyUMLAssociation* pRel=static_cast<CTinyUMLAssociation*>(GetEntity());
	CPoint point=mouse_event.virtpoint;
	pRel->DragTemp(point);

	CIsDrawEditor* pEditor=mouse_event.pEditor;
	pEditor->RedrawWindow();
}

/**
 * OnLButtonUp:
 *
 * @param mouse_event 
 * @return void 
 */
void CTinyUMLAssociationFactory::OnLButtonUp(const IS_MOUSE_EVENT& mouse_event)
{
	assert(NULL == mouse_event.pEnt);
	CPoint point=mouse_event.virtpoint;

	CIsDrawEditor* pEditor=mouse_event.pEditor;
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
		pEditor->RedrawWindow();
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
