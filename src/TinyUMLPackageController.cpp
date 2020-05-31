// TinyUMLPackageController.cpp: implementation of the CTinyUMLPackageController class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include <assert.h>
#include "TinyUML.h"
#include "TinyUMLEditor.h"
#include <DrawTextEdit.h>
#include <IsDrawCtrlHost.h>
#include <IsDrawEditor.h>
#include "TinyUMLPackage.h"
#include "TinyUMLPackageController.h"
#include "TinyUMLPackagePropertyPage.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

IS_IMPLEMENT_CONTROLLER_FUNC(CTinyUMLPackageController)
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CTinyUMLPackageController::CTinyUMLPackageController()
{

}

CTinyUMLPackageController::~CTinyUMLPackageController()
{

}

/**	\brief	The CTinyUMLPackageController::OnLButtonDown function

	\param	mouse_event	a parameter of type const IS_MOUSE_EVENT&

	\return	void	
*/
void CTinyUMLPackageController::OnLButtonDown(const IS_MOUSE_EVENT& mouse_event)
{
	CIsDrawEditor* pEditor=mouse_event.pEditor;
	CIsDrawEntity* pEnt=mouse_event.pEnt;

	if(NULL == mouse_event.pEnt)
	{
		CTinyUMLPackage* pUMLPackage=new CTinyUMLPackage(pEditor->GetDoc(),this);
		if(NULL != pUMLPackage)
		{
			pUMLPackage->SetRect(mouse_event.virtpoint.x,mouse_event.virtpoint.y,
			pEditor->SnapX(mouse_event.virtpoint.x + 150),
			pEditor->SnapY(mouse_event.virtpoint.y + 100));
			
			//////////////////////////////////////////////////////////////////////////
			IS_NOTIFY notify;
			notify.hdr.hwndFrom = pEditor->GetSafeHwnd();
			notify.pEntFrom = pUMLPackage;
			pEditor->SendMessage(WM_NOTIFY,(WPARAM)IS_CREATE_ENTITY,(LPARAM)(&notify));
		}
	}
	else
	{
		pEditor->UnselectAll();
		if(NULL != pEnt) pEnt->Select(TRUE);
		
		CPoint point(mouse_event.xsnapoint);
		point = mouse_event.pEditor->ScreenToVirtual(point,false);
		m_nHitCode = pEnt->HitTest(point);
		
		IS_NOTIFY notify;
		notify.hdr.hwndFrom = pEditor->GetSafeHwnd();
		notify.pEntFrom = mouse_event.pEnt;
		pEditor->SendMessage(WM_NOTIFY,(WPARAM)IS_SELECT_ENTITY,(LPARAM)(&notify));
	}
	
	m_bLButtonDown = true;
	m_ptLDownPos = m_ptLastPos = mouse_event.virtpoint;
}

void SetPakckageName(CIsDrawEditor* pEditor , CIsDrawEntity* pEnt , const CString& rString)
{
	CTinyUMLPackage* pUMLPackage=static_cast<CTinyUMLPackage*>(pEnt);
	pUMLPackage->SetName(rString);
}

/**
 * OnLButtonDblClk:
 *
 * @param mouse_event 
 * @return void 
 */
void CTinyUMLPackageController::OnLButtonDblClk(const IS_MOUSE_EVENT& mouse_event)
{
	assert(mouse_event.pEnt && "mouse_event.pEnt is NULL");

	if(mouse_event.pEnt)
	{
		CTinyUMLPackage* pEnt=static_cast<CTinyUMLPackage*>(mouse_event.pEnt);
		if(pEnt->GetNameRect().PtInRect(mouse_event.virtpoint))
		{
			CTinyUMLEditor* pUMLEditor=static_cast<CTinyUMLEditor*>(mouse_event.pEditor);
			CDrawTextEdit* pEditCtrl=pUMLEditor->BeginEditText(pEnt->GetName(),pEnt->GetNameRect(),pEnt->GetNameFont(),ES_CENTER);
			pEditCtrl->SetAssociate(pEnt);
			pEditCtrl->RegisterCallbackFunc(SetPakckageName);
		}else	ModifyProperties();
	}
}

/**	\brief	The CTinyUMLPackageController::OnMouseMove function

	\param	mouse_event	a parameter of type const IS_MOUSE_EVENT&

	\return	void	
*/
void CTinyUMLPackageController::OnMouseMove(const IS_MOUSE_EVENT& mouse_event)
{
	CIsDrawEditor* pEditor=mouse_event.pEditor;

	if(NULL != mouse_event.pEnt)
	{
		if(DEHT_BODY != m_nHitCode)
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
void CTinyUMLPackageController::ModifyProperties()
{
	CPropertySheet sheet("Element properties");
	CTinyUMLPackagePropertyPage packagePropertyPage;
	
	CTinyUMLPackage* pEnt=static_cast<CTinyUMLPackage*>(GetEntity());
	// setup pages
	packagePropertyPage.m_name = pEnt->m_name;
	
	// add pages
	sheet.AddPage(&packagePropertyPage);
	
	if(sheet.DoModal() == IDOK)
	{
		static_cast<CTinyUMLPackage*>(GetEntity())->m_name = packagePropertyPage.m_name;
		
		//////////////////////////////////////////////////////////////////////////
		pEnt->GetDoc()->SetModified(TRUE);
	}
}
