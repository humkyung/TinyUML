// ClassTreeCtrl.cpp : implementation file
//

#include "stdafx.h"
#include <IsDrawCtrlHost.h>
#include "TinyUML.h"
#include "MainFrm.h"
#include "ChildFrm.h"
#include "TinyUMLView.h"
#include "TinyUMLClass.h"
#include "ClassTreeCtrl.h"
#include "ToolShell.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CClassTreeCtrl

CClassTreeCtrl::CClassTreeCtrl()
{
}

CClassTreeCtrl::~CClassTreeCtrl()
{
}


BEGIN_MESSAGE_MAP(CClassTreeCtrl, CTreeCtrl)
	//{{AFX_MSG_MAP(CClassTreeCtrl)
	ON_NOTIFY_REFLECT(TVN_KEYDOWN, OnKeydown)
	ON_NOTIFY_REFLECT(TVN_SELCHANGED, OnSelchanged)
	ON_NOTIFY_REFLECT(NM_DBLCLK, OnDblclk)
	ON_WM_CREATE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CClassTreeCtrl message handlers

/**
 * OnKeydown:
 *
 * @param pNMHDR 
 * @param pResult 
 * @return void 
 */
void CClassTreeCtrl::OnKeydown(NMHDR* pNMHDR, LRESULT* pResult) 
{
	TV_KEYDOWN* pTVKeyDown = (TV_KEYDOWN*)pNMHDR;
	
	switch(pTVKeyDown->wVKey)
	{
		case VK_DELETE:
			{
			HTREEITEM hItem=GetSelectedItem();
			HTREEITEM hRootItem=GetRootItem();
			if((hItem != hRootItem) && (NULL != GetChildItem(hItem)))
			{
				CTinyUMLClass* pUMLClass=(CTinyUMLClass*)GetItemData(hItem);
				if(NULL != pUMLClass)
				{
					CChildFrame* pFrame=(CChildFrame*)((CMainFrame*)AfxGetMainWnd())->MDIGetActive();
					CIsDrawEditor* pUMLEditor=((CTinyUMLView*)(pFrame->GetActiveView()))->GetUMLEditor();
					CTinyUMLClassController* pController = static_cast<CTinyUMLClassController*>(pUMLEditor->GetEntityTypeMap(CTinyUMLClass::TypeString())->GetController());
					
					//////////////////////////////////////////////////////////////////////////
					IS_KEY_EVENT key_event;
					key_event.nChar   = VK_DELETE;
					key_event.pEditor = TinyGetCurEditor();
					pController->OnKeyDown(key_event);
				}
				DeleteItem(hItem);
			}
			       }		
		break;
	}

	*pResult = 0;
}

/**	\brief	The CClassTreeCtrl::OnSelchanged function

	\param	pNMHDR	a parameter of type NMHDR*
	\param	pResult	a parameter of type LRESULT*

	\return	void	
*/
void CClassTreeCtrl::OnSelchanged(NMHDR* pNMHDR, LRESULT* pResult) 
{
	HTREEITEM hItem=GetSelectedItem();
	if(GetRootItem() != GetParentItem(hItem)) return;

	CTinyUMLClass* pUMLClass=(CTinyUMLClass*)GetItemData(hItem);
	if(NULL != pUMLClass)
	{
		CChildFrame* pFrame=(CChildFrame*)((CMainFrame*)AfxGetMainWnd())->MDIGetActive();
		CIsDrawEditor* pTyDrawEditor=((CTinyUMLView*)(pFrame->GetActiveView()))->GetUMLEditor();
		if((NULL != pTyDrawEditor) && !pUMLClass->IsSelected())
		{
			pTyDrawEditor->UnselectAll();
			pTyDrawEditor->Select(pUMLClass);
			pTyDrawEditor->RedrawWindow();
		}
	}
	
	*pResult = 0;
}

/**
 * OnDblclk:
 *
 * @param pNMHDR 
 * @param pResult 
 * @return void 
 */
void CClassTreeCtrl::OnDblclk(NMHDR* pNMHDR, LRESULT* pResult) 
{
	HTREEITEM hItem=GetSelectedItem();
	HTREEITEM hParentItem=GetParentItem(hItem);
	if(NULL != hParentItem)
	{
		DWORD data=GetItemData(hItem);
		if(IS_METHOD == GetItemData(hItem))
		{
			CToolShell* pShell=CToolShell::GetInstance();

			CString rText=GetItemText(hItem);
			CTinyUMLClass* pClass=(CTinyUMLClass*)GetItemData(hParentItem);
			const int nCount=pClass->methodsCount();
			for(int i=0;i < nCount;i++)
			{
				if(rText == pClass->GetMethodAt(i).name)
				{
					/*
					pShell->m_dlgEditMethodCode.m_pClass = pClass;
					rText = pClass->GetMethodAt(i).type + " " + pClass->GetMethodAt(i).name;
					pShell->m_dlgEditMethodCode.SetMethodName(rText);
					pShell->m_dlgEditMethodCode.SetMethodDefine(pClass->GetMethodAt(i).strDefine);
					pShell->m_dlgEditMethodCode.Show();
					*/
					break;
				}
			}

			
		}
	}
	
	*pResult = 0;
}

int CClassTreeCtrl::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CTreeCtrl::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	// TODO: Add your specialized creation code here
	
	return 0;
}
