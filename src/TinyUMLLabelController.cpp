#include "StdAfx.h"
#include <assert.h>
#include <DrawTextEdit.h>
#include "IsDrawEditor.h"
#include "TinyUMLLabelController.h"
#include "TinyUMLLabelPropertyPage.h"
#include "TinyUMLLabel.h"
#include "TinyUMLEditor.h"

IS_IMPLEMENT_CONTROLLER_FUNC(CTinyUMLLabelController)

//////////////////////////////////////////////////////////////////////////
CTinyUMLLabelController::CTinyUMLLabelController()
{
}

CTinyUMLLabelController::~CTinyUMLLabelController()
{
}

/**
 * SetLabelText:
 *
 * @param pEnt 
 * @param rString 
 * @return void 
 */
void SetLabelText(CIsDrawEditor* pEditor , CIsDrawEntity* pEnt , const CString& rString)
{
	CTinyUMLLabel* pUMLNote=(CTinyUMLLabel*)(pEnt);
	pUMLNote->SetName(rString);
}

/**
 * OnLButtonDblClk:
 *
 * @param mouse_event 
 * @return void 
 */
void CTinyUMLLabelController::OnLButtonDblClk(const IS_MOUSE_EVENT &mouse_event)
{
	assert(mouse_event.pEnt && "mouse_event.pEnt is NULL");
	
	if(mouse_event.pEnt)
	{
		CTinyUMLLabel* pEnt=static_cast<CTinyUMLLabel*>(mouse_event.pEnt);
		if(pEnt->GetRect().PtInRect(mouse_event.virtpoint))
		{
			CTinyUMLEditor* pUMLEditor=static_cast<CTinyUMLEditor*>(mouse_event.pEditor);
			CDrawTextEdit* pEditCtrl=pUMLEditor->BeginEditText(pEnt->Name(),pEnt->GetRect(),pEnt->GetFont(),ES_MULTILINE);
			pEditCtrl->SetAssociate((CIsDrawEntity*)(pEnt));
			pEditCtrl->RegisterCallbackFunc(SetLabelText);
		}//else	ModifyProperties();
	}
}

/**
 * ModifyProperties:
 *
 * @return void 
 */
void CTinyUMLLabelController::ModifyProperties()
{
	CPropertySheet sheet("Element properties");
	CTinyUMLLabelPropertyPage labelPropertyPage;
	CTinyUMLLabel* pEnt=static_cast<CTinyUMLLabel*>(GetEntity());
	
	// setup pages
	labelPropertyPage.m_label = pEnt->Name();
	
	//LOGFONT logfont;
	//(pEnt->GetTextFont())->GetLogFont(&logfont);
	//notePropertyPage.m_rTextFont = logfont.lfFaceName;
	
	// add pages
	sheet.AddPage(&labelPropertyPage);
	
	if(IDOK == sheet.DoModal())
	{
		pEnt->SetName(labelPropertyPage.m_label);
		//pEnt->m_fillColor = notePropertyPage.m_clrTextColor;

		//CFont* pNoteFont = new CFont();
		//VERIFY(pNoteFont->CreateFont(logfont.lfHeight, 0, 0, 0, FW_NORMAL,
		//	false, false, false,
		//	ANSI_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY,
		//	DEFAULT_PITCH, notePropertyPage.m_rTextFont));
		//pEnt->SetTextFont(pNoteFont);

		//////////////////////////////////////////////////////////////////////////
		pEnt->GetDoc()->SetModified(TRUE);
	}
}
