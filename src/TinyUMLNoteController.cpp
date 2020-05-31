// TinyUMLNoteController.cpp: implementation of the CTinyUMLNoteController class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include <assert.h>
#include <IsDrawCtrlHost.h>
#include <IsDrawEditor.h>
#include <DrawTextEdit.h>
#include "TinyUML.h"
#include "TinyUMLEditor.h"
#include "TinyUMLNote.h"
#include "TinyUMLNoteController.h"
#include "TinyUMLNotePropertyPage.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

IS_IMPLEMENT_CONTROLLER_FUNC(CTinyUMLNoteController)
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CTinyUMLNoteController::CTinyUMLNoteController()
{

}

/**
 * ~CTinyUMLNoteController:
 *
 * @return  
 */
CTinyUMLNoteController::~CTinyUMLNoteController()
{

}

/**
 * OnLButtonDown:
 *
 * @param mouse_event 
 * @return void 
 */
void CTinyUMLNoteController::OnLButtonDown(const IS_MOUSE_EVENT& mouse_event)
{
	CIsDrawEditor* pEditor=mouse_event.pEditor;
	CIsDrawEntity* pEnt =mouse_event.pEnt;
	const CPoint point=mouse_event.virtpoint;

	if(NULL == mouse_event.pEnt)
	{
		CTinyUMLNote* pUMLNote=new CTinyUMLNote(pEditor->GetDoc(),this);
		if(NULL != pUMLNote)
		{
			pUMLNote->SetRect(mouse_event.virtpoint.x,mouse_event.virtpoint.y,
			pEditor->SnapX(mouse_event.virtpoint.x + 150),
			pEditor->SnapY(mouse_event.virtpoint.y + 75));
			
			//////////////////////////////////////////////////////////////////////////
			IS_NOTIFY notify;
			notify.hdr.hwndFrom = pEditor->GetSafeHwnd();
			notify.pEntFrom = pUMLNote;
			pEditor->SendMessage(WM_NOTIFY,(WPARAM)IS_CREATE_ENTITY,(LPARAM)(&notify));
		}
	}
	else
	{
		//pEditor->UnselectAll();
		//if(NULL != pEnt) pEnt->Select(TRUE);
		
		CPoint point(mouse_event.xsnapoint);
		point = mouse_event.pEditor->ScreenToVirtual(point,false);
		m_nHitCode = pEnt->HitTest(point);
		
		//////////////////////////////////////////////////////////////////////////
		IS_NOTIFY notify;
		notify.hdr.hwndFrom = pEditor->GetSafeHwnd();
		notify.pEntFrom = pEnt;
		pEditor->SendMessage(WM_NOTIFY,(WPARAM)IS_SELECT_ENTITY,(LPARAM)(&notify));
	}
	
	m_bLButtonDown = true;
	m_ptLDownPos = m_ptLastPos = mouse_event.virtpoint;
}

void SetNoteText(CIsDrawEditor* pEditor , CIsDrawEntity* pEnt , const CString& rString)
{
	CTinyUMLNote* pUMLNote=static_cast<CTinyUMLNote*>(pEnt);
	pUMLNote->SetText(rString);
}

/**
 * OnLButtonDblClk:
 *
 * @param mouse_event 
 * @return void 
 */
void CTinyUMLNoteController::OnLButtonDblClk(const IS_MOUSE_EVENT& mouse_event)
{
	assert(mouse_event.pEnt && "mouse_event.pEnt is NULL");

	if(mouse_event.pEnt)
	{
		CTinyUMLNote* pEnt=static_cast<CTinyUMLNote*>(mouse_event.pEnt);
		if(pEnt->GetTextRect().PtInRect(mouse_event.virtpoint))
		{
			CTinyUMLEditor* pUMLEditor=static_cast<CTinyUMLEditor*>(mouse_event.pEditor);
			CDrawTextEdit* pEditCtrl=pUMLEditor->BeginEditText(pEnt->GetText(),pEnt->GetTextRect(),pEnt->GetTextFont(),ES_MULTILINE);
			pEditCtrl->SetAssociate(pEnt);
			pEditCtrl->RegisterCallbackFunc(SetNoteText);
		}
		else
		{
			Set(mouse_event.pEnt,mouse_event.pEditor);
			ModifyProperties();
		}
	}
}

/**	\brief	The CTinyUMLNoteController::OnMouseMove function

	\param	mouse_event	a parameter of type const IS_MOUSE_EVENT&

	\return	void	
*/
void CTinyUMLNoteController::OnMouseMove(const IS_MOUSE_EVENT& mouse_event)
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
void CTinyUMLNoteController::ModifyProperties()
{
	CPropertySheet sheet("Element properties");
	CTinyUMLNotePropertyPage notePropertyPage;
	CTinyUMLNote* pEnt=static_cast<CTinyUMLNote*>(GetEntity());
	
	// setup pages
	notePropertyPage.m_text = pEnt->m_text;
	//notePropertyPage.m_clrTextColor = pEnt->m_fillColor;
	
	LOGFONT logfont;
	(pEnt->GetTextFont())->GetLogFont(&logfont);
	notePropertyPage.m_rTextFont = logfont.lfFaceName;
	
	// add pages
	sheet.AddPage(&notePropertyPage);
	
	if(IDOK == sheet.DoModal())
	{
		pEnt->m_text = notePropertyPage.m_text;
		//pEnt->m_fillColor = notePropertyPage.m_clrTextColor;

		CFont* pNoteFont = new CFont();
		VERIFY(pNoteFont->CreateFont(logfont.lfHeight, 0, 0, 0, FW_NORMAL,
			false, false, false,
			ANSI_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY,
			DEFAULT_PITCH, notePropertyPage.m_rTextFont));
		pEnt->SetTextFont(pNoteFont);

		//////////////////////////////////////////////////////////////////////////
		pEnt->GetDoc()->SetModified(TRUE);
	}
}
