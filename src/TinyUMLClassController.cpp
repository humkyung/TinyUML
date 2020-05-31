// TinyUMLClassController.cpp: implementation of the CTinyUMLClassController class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include <assert.h>
#include "TinyUML.h"
#include <IsDrawCtrlHost.h>
#include <DrawTextEdit.h>
#include "TinyUMLEditor.h"
#include "TinyUMLClass.h"
#include "TinyUMLClassController.h"
#include "TinyUMLClassPropertyPage.h"
#include "TinyUMLAttributesPropertyPage.h"
#include "TinyUMLMethodsPropertyPage.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

IS_IMPLEMENT_CONTROLLER_FUNC(CTinyUMLClassController)
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CTinyUMLClassController::CTinyUMLClassController()
{
	m_bInterface = false;
}

CTinyUMLClassController::~CTinyUMLClassController()
{

}

/**	\brief	The CTinyUMLClassController::OnLButtonDown function

	\param	mouse_event	a parameter of type const IS_MOUSE_EVENT&

	\return	void
*/
void CTinyUMLClassController::OnLButtonDown(const IS_MOUSE_EVENT& mouse_event)
{
	CIsDrawEditor* pEditor=mouse_event.pEditor;

	if(NULL != mouse_event.pEnt)
	{
		//////////////////////////////////////////////////////////////////////////
		/// select entity
		CPoint point(mouse_event.xsnapoint);
		m_nHitCode = mouse_event.pEnt->HitTest(point);
		if(DEHT_FOLDER == m_nHitCode)
		{
			CTinyUMLClass* pClass=static_cast<CTinyUMLClass*>(mouse_event.pEnt);
			pClass->ToggleFolder();
			pClass->NotifyToReactors();
		}
		else
		{
			IS_NOTIFY notify;
			notify.hdr.hwndFrom = pEditor->GetSafeHwnd();
			notify.pEntFrom = mouse_event.pEnt;
			pEditor->SendMessage(WM_NOTIFY,(WPARAM)IS_SELECT_ENTITY,(LPARAM)(&notify));
		}
	}

	m_bLButtonDown = true;
	m_ptLDownPos = m_ptLastPos = mouse_event.virtpoint;
}

void SetClassName(CIsDrawEditor* pEditor , CIsDrawEntity* pEnt , const CString& rString)
{
	CTinyUMLClass* pUMLClass=static_cast<CTinyUMLClass*>(pEnt);
	pUMLClass->SetName(rString);

	//////////////////////////////////////////////////////////////////////////
	pEnt->GetDoc()->SetModified(TRUE);
	pEditor->SendMessage(TINY_UML_MODIFY_PROPERTY,0,(LPARAM)pEnt);
}

/**	\brief	The CTinyUMLClassController::OnLButtonDblClk function

	\param	mouse_event	a parameter of type const IS_MOUSE_EVENT&

	\return	void	
*/
void CTinyUMLClassController::OnLButtonDblClk(const IS_MOUSE_EVENT& mouse_event)
{
	assert(mouse_event.pEnt && "mouse_event.pEnt is NULL");

	if(mouse_event.pEnt)
	{
		CTinyUMLClass* pEnt=static_cast<CTinyUMLClass*>(mouse_event.pEnt);
		if(pEnt->GetNameRect().PtInRect(mouse_event.virtpoint))
		{
			CTinyUMLEditor* pUMLEditor=static_cast<CTinyUMLEditor*>(mouse_event.pEditor);
			CDrawTextEdit* pEditCtrl=pUMLEditor->BeginEditText(pEnt->Name(),pEnt->GetNameRect(),pEnt->GetNameFont(),ES_CENTER);
			pEditCtrl->SetAssociate(pEnt);
			pEditCtrl->RegisterCallbackFunc(SetClassName);
		}
		else
		{
			Set(mouse_event.pEnt,mouse_event.pEditor);
			ModifyProperties();
		}
	}
}

/**
 * OnMouseMove:
 *
 * @param mouse_event 
 * @return void 
 */
void CTinyUMLClassController::OnMouseMove(const IS_MOUSE_EVENT& mouse_event)
{
	CIsDrawEditor* pEditor=mouse_event.pEditor;

	if(NULL != mouse_event.pEnt)
	{
		if(DEHT_FOLDER == m_nHitCode)
			int i=0;
		else if(DEHT_BODY != m_nHitCode)
		{
			IS_NOTIFY notify;
			notify.hdr.hwndFrom = pEditor->GetSafeHwnd();
			notify.nHitCode = m_nHitCode;
			notify.virtPoint[0] = mouse_event.virtpoint;
			pEditor->SendMessage(WM_NOTIFY,(WPARAM)(IS_RESIZE_ENTITY),(LPARAM)(&notify));
		}
		else
		{
			IS_NOTIFY notify;
			notify.hdr.hwndFrom = pEditor->GetSafeHwnd();
			notify.virtPoint[0] = m_ptLastPos;
			notify.virtPoint[1] = mouse_event.virtpoint;
			pEditor->SendMessage(WM_NOTIFY,(WPARAM)(IS_MOVE_ENTITY),(LPARAM)(&notify));
		}
	}

	m_ptLastPos = mouse_event.virtpoint;
}

/**
 * ModifyProperties:
 *
 * @return void 
 */
void CTinyUMLClassController::ModifyProperties()
{
	CPropertySheet sheet("Element properties");
	
	CTinyUMLClassPropertyPage classPropertyPage;
	CTinyUMLAttributesPropertyPage attributesPropertyPage;
	CTinyUMLMethodsPropertyPage methodsPropertyPage;
	
	CTinyUMLClass* pEnt=static_cast<CTinyUMLClass*>(GetEntity());
	// setup pages
	classPropertyPage.m_bAbstract = pEnt->m_bAbstract;
	classPropertyPage.m_name = pEnt->Name();
	classPropertyPage.m_rNote= pEnt->m_rNote;
	classPropertyPage.m_stereotype = pEnt->m_stereotype;
	classPropertyPage.m_bShowStereotype = pEnt->m_bShowStereotype;
	classPropertyPage.m_bShowCompartimentName = pEnt->m_bShowCompartimentName;
	
	attributesPropertyPage.m_bShowAttributes = pEnt->m_bShowAttributes;
	attributesPropertyPage.m_attributes.Copy(pEnt->m_attributes);
	
	methodsPropertyPage.m_bShowMethods = pEnt->m_bShowMethods;
	methodsPropertyPage.m_methods.Copy(pEnt->m_methods);

	// add pages
	sheet.AddPage(&classPropertyPage);
	sheet.AddPage(&attributesPropertyPage);
	sheet.AddPage(&methodsPropertyPage);
	if(IDOK == sheet.DoModal())
	{
		//////////////////////////////////////////////////////////////////////////
		CIsDrawEditor* pEditor=(CIsDrawEditor*)m_control.first;
		pEditor->SendMessage(TINY_UML_PREMODIFY_PROPERTY,0,(LPARAM)pEnt);

		pEnt->m_bAbstract = classPropertyPage.m_bAbstract ? true : false;
		pEnt->SetName(classPropertyPage.m_name);
		pEnt->m_rNote= classPropertyPage.m_rNote;
		pEnt->m_stereotype = classPropertyPage.m_stereotype;
		pEnt->m_bShowStereotype = classPropertyPage.m_bShowStereotype ? true : false;
		pEnt->m_bShowCompartimentName = classPropertyPage.m_bShowCompartimentName ? true : false;
		
		pEnt->m_bShowAttributes = attributesPropertyPage.m_bShowAttributes ? true : false;
		pEnt->m_attributes.Copy(attributesPropertyPage.m_attributes);
		
		pEnt->m_bShowMethods = methodsPropertyPage.m_bShowMethods ? true : false;
		pEnt->m_methods.Copy(methodsPropertyPage.m_methods);
		
		pEnt->UpdateYCache();
		
		//////////////////////////////////////////////////////////////////////////
		pEnt->GetDoc()->SetModified(TRUE);
		pEditor->SendMessage(TINY_UML_MODIFY_PROPERTY,0,(LPARAM)pEnt);
	}
}

/**
 * OnKeyDown:
 *
 * @param key_event 
 * @return void 
 */
void CTinyUMLClassController::OnKeyDown(const IS_KEY_EVENT &key_event)
{
	CIsDrawEditor* pEditor=key_event.pEditor;

	switch(key_event.nChar)
	{
		case VK_DELETE:
		{
			IS_NOTIFY notify;
			notify.hdr.hwndFrom = pEditor->GetSafeHwnd();
			notify.pEntFrom = GetEntity();
			pEditor->SendMessage(WM_NOTIFY,(WPARAM)IS_DELETE_ENTITY,(LPARAM)(&notify));
		}
			break;
	}
}
