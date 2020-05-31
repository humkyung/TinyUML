#include "StdAfx.h"
#include <assert.h>
#include "IsDrawEditor.h"
#include "TinyUMLLabelFactory.h"
#include "TinyUMLLabel.h"

CTinyUMLLabelFactory::CTinyUMLLabelFactory()
{
}

CTinyUMLLabelFactory::~CTinyUMLLabelFactory()
{
}

/**
 * OnLButtonDown:
 *
 * @param mouse_event 
 * @return void 
 */
void CTinyUMLLabelFactory::OnLButtonDown(const IS_MOUSE_EVENT& mouse_event)
{
	CIsDrawEditor* pEditor=mouse_event.pEditor;
	const CPoint point=mouse_event.virtpoint;

	CTinyUMLLabel* pLabel=new CTinyUMLLabel(pEditor->GetDoc(),this);
	if(NULL != pLabel)
	{
		CRect rect(point.x,point.y,pEditor->SnapX(point.x + 150),pEditor->SnapY(point.y + 150));
		pLabel->SetRect(rect);
		
		//////////////////////////////////////////////////////////////////////////
		IS_NOTIFY notify;
		notify.hdr.hwndFrom = pEditor->GetSafeHwnd();
		notify.pEntFrom = pLabel;
		pEditor->SendMessage(WM_NOTIFY,(WPARAM)IS_CREATE_ENTITY,(LPARAM)(&notify));
	}
}