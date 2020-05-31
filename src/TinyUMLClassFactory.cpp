// TinyUMLClassFactory.cpp: implementation of the CTinyUMLClassFactory class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "TinyUML.h"
#include <IsDrawCtrlHost.h>
#include <IsDrawEditor.h>
#include "TinyUMLClass.h"
#include "TinyUMLClassFactory.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

/**
 * CTinyUMLClassFactory:
 *
 * @param bInterface 
 * @return  
 */
CTinyUMLClassFactory::CTinyUMLClassFactory(bool bInterface)
{
	m_bInterface = bInterface;
}

CTinyUMLClassFactory::~CTinyUMLClassFactory()
{

}

/**	\brief	The CTinyUMLClassFactory::OnLButtonDown function

	\param	mouse_event	a parameter of type const IS_MOUSE_EVENT&

	\return	void	
*/
void CTinyUMLClassFactory::OnLButtonDown(const IS_MOUSE_EVENT& mouse_event)
{
	CIsDrawEditor* pEditor=mouse_event.pEditor;
	const CPoint point=mouse_event.virtpoint;

	CTinyUMLClass* pUMLClass=new CTinyUMLClass(pEditor->GetDoc(),this,m_bInterface);
	if(NULL != pUMLClass)
	{
		pUMLClass->SetupTheme(pEditor->GetDoc()->GetTheme());

		const int right =pEditor->SnapX(point.x + pUMLClass->GetMinimumSize().cx);
		const int bottom=pEditor->SnapY(point.y + pUMLClass->GetMinimumSize().cy);
		pUMLClass->SetRect(point.x,point.y,right,bottom);
		
		//////////////////////////////////////////////////////////////////////////
		IS_NOTIFY notify;
		notify.hdr.hwndFrom = pEditor->GetSafeHwnd();
		notify.pEntFrom = pUMLClass;
		pEditor->SendMessage(WM_NOTIFY,(WPARAM)IS_CREATE_ENTITY,(LPARAM)(&notify));
	}
}

