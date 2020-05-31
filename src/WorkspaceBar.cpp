// WorkspaceBar.cpp : implementation of the CWorkspaceBar class
//

#include "stdafx.h"
#include <assert.h>
#include "resource.h"
#include <BCMenu.h>
#include "TinyUML.h"
#include "WorkspaceBar.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CWorkspaceBar

BEGIN_MESSAGE_MAP(CWorkspaceBar, CBCGSizingControlBar)
	//{{AFX_MSG_MAP(CWorkspaceBar)
	ON_WM_CREATE()
	ON_WM_SIZE()
	ON_WM_CONTEXTMENU()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CWorkspaceBar construction/destruction

CWorkspaceBar::CWorkspaceBar()
{
	// TODO: add one-time construction code here

}

CWorkspaceBar::~CWorkspaceBar()
{
}

/////////////////////////////////////////////////////////////////////////////
// CWorkspaceBar message handlers

/**
 * OnCreate:
 *
 * @param lpCreateStruct 
 * @return int 
 */
int CWorkspaceBar::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CBCGSizingControlBar::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	//////////////////////////////////////////////////////////////////////////
	m_imgList.Create(16,16,FALSE,1,1);
	CBitmap bm[2];
	bm[0].LoadBitmap(IDB_PROJECT);m_imgList.Add(&bm[0],RGB(0,0,0));
	bm[1].LoadBitmap(IDB_CLASS);m_imgList.Add(&bm[1],RGB(0,0,0));

	CBitmap public_method_bitmp;
	public_method_bitmp.LoadBitmap(IDB_PUBLIC_METHOD);m_imgList.Add(&public_method_bitmp,RGB(0,0,0));
	CBitmap protected_method_bitmp;
	protected_method_bitmp.LoadBitmap(IDB_PROTECTED_METHOD);m_imgList.Add(&protected_method_bitmp,RGB(0,0,0));
	CBitmap private_method_bitmp;
	private_method_bitmp.LoadBitmap(IDB_PRIVATE_METHOD);m_imgList.Add(&private_method_bitmp,RGB(0,0,0));

	CBitmap member_bitmaps[3];
	member_bitmaps[0].LoadBitmap(IDB_PUBLIC_MEMBER);m_imgList.Add(&member_bitmaps[0],RGB(0,0,0));
	member_bitmaps[1].LoadBitmap(IDB_PROTECTED_MEMBER);m_imgList.Add(&member_bitmaps[1],RGB(0,0,0));
	member_bitmaps[2].LoadBitmap(IDB_PRIVATE_MEMBER);m_imgList.Add(&member_bitmaps[2],RGB(0,0,0));
	//////////////////////////////////////////////////////////////////////////

	CRect rectDummy;
	rectDummy.SetRectEmpty ();

	// Create tabs window:
	if (!m_wndTabs.Create (CBCGTabWnd::STYLE_3D, rectDummy, this, 1))
	{
		TRACE0("Failed to create workspace tab window\n");
		return -1;      // fail to create
	}
	m_wndTabs.SetImageList (m_imgList);

	// Create tree windows.
	// TODO: create your own tab windows here:
	const DWORD dwViewStyle =	WS_CHILD | WS_VISIBLE | TVS_HASLINES | 
								TVS_LINESATROOT | TVS_HASBUTTONS;
	
	if (!m_wndTree.Create (dwViewStyle, rectDummy, &m_wndTabs, 2))
	{
		TRACE0("Failed to create workspace view\n");
		return -1;      // fail to create
	}

	// Setup trees content:
	m_wndTree.SetImageList(&(m_imgList),TVSIL_NORMAL);
	HTREEITEM hRoot = m_wndTree.InsertItem (_T(""));

	// Attach tree windows to tab:
	m_wndTabs.AddTab (&m_wndTree, _T("ClassView"), 0 /* Image number */);

	if (!m_wndFileView.Create (dwViewStyle, rectDummy, &m_wndTabs, 2))
	{
		TRACE0("Failed to create FileView\n");
		return -1;      // fail to create
	}

	// Setup trees content:
	//m_wndFileView.SetImageList(&(m_imgList),TVSIL_NORMAL);
	
	// Attach tree windows to tab:
	m_wndTabs.AddTab (&m_wndFileView, _T("FileView"), 1 /* Image number */);

	return 0;
}

void CWorkspaceBar::OnSize(UINT nType, int cx, int cy) 
{
	CBCGSizingControlBar::OnSize(nType, cx, cy);

	// Tab control should cover a whole client area:
	m_wndTabs.SetWindowPos (NULL, -1, -1, cx, cy,
		SWP_NOMOVE | SWP_NOACTIVATE | SWP_NOZORDER);
}

/**
 * OnContextMenu:
 *
 * @param pWnd 
 * @param point 
 * @return void 
 */
void CWorkspaceBar::OnContextMenu(CWnd* pWnd, CPoint point) 
{
	int iActiveTab = m_wndTabs.GetActiveTab ();
	if (iActiveTab < 0)
	{
		return;
	}
	
	CTreeCtrl* pWndTree = (CTreeCtrl*) m_wndTabs.GetActiveWnd ();
	ASSERT_VALID (pWndTree);
	
	if(0 == iActiveTab)
	{
		if (point != CPoint (-1, -1))
		{
			//---------------------
			// Select clicked item:
			//---------------------
			CPoint ptTree = point;
			pWndTree->ScreenToClient (&ptTree);
			
			UINT flags;
			HTREEITEM hTreeItem = pWndTree->HitTest(ptTree,&flags);
			if((hTreeItem != NULL) && (NULL != pWndTree->GetParentItem(hTreeItem)) && 
				((flags & TVHT_ONITEMRIGHT) || (flags & TVHT_ONITEMINDENT) || (flags & TVHT_ONITEM)))
			{
				if(NULL != pWndTree->GetChildItem(hTreeItem))
				{
					pWndTree->SelectItem (hTreeItem);

					pWndTree->SetFocus ();
					theApp.ShowPopupMenu (IDR_CONTEXT_MENU, point, AfxGetMainWnd ());
				}
			}
		}
	}
	else
	{
		if (point != CPoint (-1, -1))
		{
			//---------------------
			// Select clicked item:
			//---------------------
			CPoint ptTree = point;
			pWndTree->ScreenToClient (&ptTree);
			
			UINT flags;
			HTREEITEM hTreeItem = pWndTree->HitTest(ptTree,&flags);
			if((hTreeItem != NULL) && (NULL == pWndTree->GetParentItem(hTreeItem)) && (flags & TVHT_ONITEM))
			{
				pWndTree->SelectItem (hTreeItem);

				pWndTree->SetFocus ();

				BCMenu PopMenu;
				PopMenu.LoadMenu(IDR_FILEVIEW_CONTEXT_MENU);
				BCMenu* pSubMenu = (BCMenu *)PopMenu.GetSubMenu(0);

				if(pSubMenu)
				{
					pSubMenu->TrackPopupMenu(TPM_LEFTALIGN|TPM_RIGHTBUTTON , point.x , point.y , AfxGetMainWnd());
					PopMenu.DestroyMenu();
				}
			}
		}
	}
}

/**
 * AttachClass:
 *
 * @param pClass 
 * @return void 
 */
void CWorkspaceBar::AttachClass(CTinyUMLClass *pClass)
{
	assert(pClass && "pClass is NULL");

	if(pClass)
	{
		TV_INSERTSTRUCT TI;
		
		TI.hParent = m_wndTree.GetRootItem();
		TI.item.mask= TVIF_TEXT | TVIF_IMAGE | TVIF_SELECTEDIMAGE;
		TI.item.iImage = 2;
		TI.item.iSelectedImage = 2;
		TI.item.pszText = _T((char*)(pClass->Name().operator LPCTSTR()));
		HTREEITEM hClassItem=m_wndTree.InsertItem(&TI);
		m_wndTree.SetItemData(hClassItem,(DWORD)pClass);
		m_wndTree.SetItemState(hClassItem, INDEXTOSTATEIMAGEMASK(0), TVIS_STATEIMAGEMASK );
		m_map.SetAt(pClass,hClassItem);

		long nCount=pClass->methodsCount();
		for(long i=0;i < nCount;i++)
		{
			CTinyUMLClass::Method method=pClass->GetMethodAt(i);
			
			TI.hParent = hClassItem;
			TI.item.mask= TVIF_TEXT | TVIF_IMAGE | TVIF_SELECTEDIMAGE;
			if(CTinyUMLClass::Method::public_method == method.access)
			{
				TI.item.iImage = 5;
				TI.item.iSelectedImage = 5;
			}
			else if(CTinyUMLClass::Method::protected_method == method.access)
			{
				TI.item.iImage = 6;
				TI.item.iSelectedImage = 6;
			}
			else if(CTinyUMLClass::Method::private_method == method.access)
			{
				TI.item.iImage = 7;
				TI.item.iSelectedImage = 7;
			}
			TI.item.pszText = _T((char*)method.name.operator LPCTSTR());
			HTREEITEM hItem=m_wndTree.InsertItem(&TI);
			m_wndTree.SetItemData(hItem,(DWORD)IS_METHOD);
			m_wndTree.SetItemState(hItem, INDEXTOSTATEIMAGEMASK(0), TVIS_STATEIMAGEMASK );
		}
		
		nCount=pClass->attributesCount();
		for(i=0;i < nCount;i++)
		{
			CTinyUMLClass::Member attribute=pClass->GetAttbuteAt(i);
			
			TI.hParent = hClassItem;
			TI.item.mask= TVIF_TEXT | TVIF_IMAGE | TVIF_SELECTEDIMAGE;
			if(CTinyUMLClass::Member::public_member == attribute.access)
			{
				TI.item.iImage = 8;
				TI.item.iSelectedImage = 8;
			}
			else if(CTinyUMLClass::Member::protected_member == attribute.access)
			{
				TI.item.iImage = 9;
				TI.item.iSelectedImage = 9;
			}
			else if(CTinyUMLClass::Member::private_member == attribute.access)
			{
				TI.item.iImage = 10;
				TI.item.iSelectedImage = 10;
			}

			CString rString=attribute.type.operator LPCTSTR();
			rString += " " + attribute.name;
			TI.item.pszText = _T((char*)rString.operator LPCTSTR());
			HTREEITEM hItem=m_wndTree.InsertItem(&TI);
			m_wndTree.SetItemData(hItem,(DWORD)IS_ATTRIBUTE);
			m_wndTree.SetItemState(hItem, INDEXTOSTATEIMAGEMASK(0), TVIS_STATEIMAGEMASK );
		}

		m_wndTree.SortChildren(TI.hParent);
	}
}

/**
 * DetachClass:
 *
 * @param pClass 
 * @return void 
 */
void CWorkspaceBar::DetachClass(CTinyUMLClass* pClass)
{
	assert(pClass && "pClass is NULL");

	if(pClass){
		HTREEITEM hItem;
		if(m_map.Lookup(pClass,hItem)) m_wndTree.DeleteItem(hItem);
	}
}

/**
 * ModifyClassProperty:
 *
 * @param pClass 
 * @return void 
 */
void CWorkspaceBar::ModifyClassProperty(CTinyUMLClass *pClass)
{
	assert(pClass && "pClass is NULL");
	
	if(pClass){
		HTREEITEM hClassItem=static_cast<HTREEITEM>(m_map.GetValueAt((void*)pClass));
		
		CString str=pClass->Name();
		m_wndTree.SetItemText(hClassItem,str.operator LPCTSTR());
		
		HTREEITEM hChildItem=m_wndTree.GetChildItem(hClassItem),hSiblingItem;
		while(NULL != hChildItem){
			hSiblingItem=m_wndTree.GetNextSiblingItem(hChildItem);
			m_wndTree.DeleteItem(hChildItem);
			hChildItem = hSiblingItem;
		}
		
		TV_INSERTSTRUCT TI;

		TCHAR szBuf[MAX_PATH]={0,};
		long nCount=pClass->methodsCount();
		for(long i=0;i < nCount;i++){
			CTinyUMLClass::Method method=pClass->GetMethodAt(i);
			
			TI.hParent = hClassItem;
			TI.item.mask= TVIF_TEXT | TVIF_IMAGE | TVIF_SELECTEDIMAGE;
			if(CTinyUMLClass::Method::public_method == method.access){
				TI.item.iImage = 2;
				TI.item.iSelectedImage = 2;
			}else if(CTinyUMLClass::Method::protected_method == method.access){
				TI.item.iImage = 3;
				TI.item.iSelectedImage = 3;
			}else if(CTinyUMLClass::Method::private_method == method.access){
				TI.item.iImage = 4;
				TI.item.iSelectedImage = 4;
			}
			strcpy(szBuf,method.type.operator LPCTSTR());strcat(szBuf," ");
			strcat(szBuf,method.name.operator LPCTSTR());
			TI.item.pszText = _T(szBuf);
			HTREEITEM hItem=m_wndTree.InsertItem(&TI);
			m_wndTree.SetItemData(hItem,(DWORD)IS_METHOD);
			m_wndTree.SetItemState(hItem, INDEXTOSTATEIMAGEMASK(0), TVIS_STATEIMAGEMASK );
		}

		nCount=pClass->attributesCount();
		for(i=0;i < nCount;i++){
			CTinyUMLClass::Member attribute=pClass->GetAttbuteAt(i);
			
			TI.hParent = hClassItem;
			TI.item.mask= TVIF_TEXT | TVIF_IMAGE | TVIF_SELECTEDIMAGE;
			if(CTinyUMLClass::Member::public_member == attribute.access){
				TI.item.iImage = 5;
				TI.item.iSelectedImage = 5;
			}else if(CTinyUMLClass::Member::protected_member == attribute.access){
				TI.item.iImage = 6;
				TI.item.iSelectedImage = 6;
			}else if(CTinyUMLClass::Member::private_member == attribute.access){
				TI.item.iImage = 7;
				TI.item.iSelectedImage = 7;
			}

			strcpy(szBuf,attribute.type.operator LPCTSTR());strcat(szBuf," ");
			strcat(szBuf,attribute.name.operator LPCTSTR());
			TI.item.pszText = _T(szBuf);
			HTREEITEM hItem=m_wndTree.InsertItem(&TI);
			m_wndTree.SetItemData(hItem,(DWORD)IS_ATTRIBUTE);
			m_wndTree.SetItemState(hItem, INDEXTOSTATEIMAGEMASK(0), TVIS_STATEIMAGEMASK );
		}

		m_wndTree.SortChildren(m_hRoot);
	}
}

/**
 * SetTitle:
 *
 * @param strTitle 
 * @return void 
 */
void CWorkspaceBar::SetTitle(const CString strTitle)
{
	m_hRoot=m_wndTree.GetRootItem();
	CString* rString=new CString(strTitle);
	if(NULL == m_hRoot)
		m_hRoot = m_wndTree.InsertItem (rString->operator LPCTSTR());
	else	m_wndTree.SetItemText(m_wndTree.GetRootItem(),rString->operator LPCTSTR());

	if(IsWindow(m_wndFileView.m_hWnd))
	{
		m_wndFileView.SetTitle(strTitle);
	}
}

/**
 * Clear:
 *
 * @return void 
 */
void CWorkspaceBar::Clear()
{
	m_wndTree.DeleteAllItems();
	HTREEITEM hRoot = m_wndTree.InsertItem ("");

	m_wndFileView.InitFileViewTree();
}

/**
 * RedrawClassTree:
 *
 * @return void 
 */
void CWorkspaceBar::RedrawClassTree()
{
	m_wndTree.RedrawWindow();
}

/**
 * AddFileToFileView:
 *
 * @param pFile 
 * @return void 
 */
void CWorkspaceBar::AddFileToFileView(CContentFile *pFile)
{
	assert(pFile && "pFile is NULL");

	if(pFile && ::IsWindow(m_wndFileView.m_hWnd))
	{
		m_wndFileView.AddFile(pFile);
	}
}


void CWorkspaceBar::RedrawFileViewTree()
{
	m_wndFileView.RedrawWindow();
}
