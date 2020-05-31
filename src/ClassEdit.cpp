// ClassEdit.cpp : implementation file
//

#include "stdafx.h"
#include "TinyUML.h"
#include "TinyUMLEntity.h"
#include "TinyUMLEditor.h"
#include "ClassEdit.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

void (*pCallbackFunc)(CTinyUMLEntity* pEnt,const CString& rString);
/////////////////////////////////////////////////////////////////////////////
// CClassEdit

CClassEdit::CClassEdit()
{
	m_pEnt = NULL;
}

CClassEdit::~CClassEdit()
{
}


BEGIN_MESSAGE_MAP(CClassEdit, CEdit)
	//{{AFX_MSG_MAP(CClassEdit)
	ON_CONTROL_REFLECT(EN_KILLFOCUS, OnKillfocus)
	ON_WM_KEYDOWN()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CClassEdit message handlers

void CClassEdit::OnKillfocus() 
{
	if(NULL != m_pEnt)
	{
		CString rString;
		GetWindowText(rString);
		//m_pEnt->SetName(rString);
		(*pCallbackFunc)(m_pEnt,rString);

		//CTinyDrawEditor* pEditor=CTinyDrawCtrlApp::GetCurEditor();
		CWnd* pParent=GetParent();
		pParent->SendMessage(TINY_UML_MODIFY_PROPERTY,0,(LPARAM)m_pEnt);
	}

	CEdit::DestroyWindow();
	delete this;
}


void CClassEdit::SetAssociate(CTinyUMLEntity *pEnt)
{
	m_pEnt = pEnt;
}

/**	\brief	The CClassEdit::OnKeyDown function

	\param	nChar	a parameter of type UINT
	\param	nRepCnt	a parameter of type UINT
	\param	nFlags	a parameter of type UINT

	\return	void	
*/
void CClassEdit::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	if((VK_RETURN == nChar) && !(GetStyle() & ES_MULTILINE)){
		if(NULL != m_pEnt){
			CString rString;
			GetWindowText(rString);
			(*pCallbackFunc)(m_pEnt,rString);
		}
		
		GetParent()->SetFocus();
		return;
	}else if(VK_ESCAPE == nChar){
		if(NULL != m_pEnt){
			//CString rString;
			//rString = m_pEnt->GetName();
			//SetWindowText(rString);
		}

		GetParent()->SetFocus();
		return;
	}
	
	CEdit::OnKeyDown(nChar, nRepCnt, nFlags);
}

void CClassEdit::RegisterCallbackFunc(void (*f)(CTinyUMLEntity* pEnt,const CString& rString)){
	pCallbackFunc = f;
}