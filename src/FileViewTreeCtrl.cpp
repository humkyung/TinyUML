// ClassTreeCtrl.cpp : implementation file
//

#include "stdafx.h"
#include <assert.h>
#include <Shlwapi.h>
#include <IsDrawCtrlHost.h>
#include "TinyUML.h"
#include "MainFrm.h"
#include "ChildFrm.h"
#include "TinyUMLView.h"
#include "TinyUMLClass.h"
#include "FileViewTreeCtrl.h"
#include "ToolShell.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CFileViewTreeCtrl

CFileViewTreeCtrl::CFileViewTreeCtrl()
{
	m_nSysImgSize = 0;
	m_hRoot = NULL;
	m_hSourceFile = NULL;
	m_hHeaderFile = NULL;
	m_hResourceFile = NULL;
	m_hOtherFiles = NULL;
}

CFileViewTreeCtrl::~CFileViewTreeCtrl()
{
	m_imgList.Detach();
}


BEGIN_MESSAGE_MAP(CFileViewTreeCtrl, CTreeCtrl)
	//{{AFX_MSG_MAP(CFileViewTreeCtrl)
	ON_NOTIFY_REFLECT(TVN_KEYDOWN, OnKeydown)
	ON_NOTIFY_REFLECT(TVN_SELCHANGED, OnSelchanged)
	ON_NOTIFY_REFLECT(NM_DBLCLK, OnDblclk)
	ON_WM_CREATE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CFileViewTreeCtrl message handlers

int CFileViewTreeCtrl::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CTreeCtrl::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	GetSysImgList();
	m_nSysImgSize = m_imgList.GetImageCount();
	
	CBitmap bmpProject;
	bmpProject.LoadBitmap(IDB_PROJECT);
	m_imgList.Add(&bmpProject,RGB(255 , 255 , 255));
	CBitmap bmpClass;
	bmpClass.LoadBitmap(IDB_CLASS);
	m_imgList.Add(&bmpClass,RGB(0,0,0));
	SetImageList(&(m_imgList),TVSIL_NORMAL);
	
	InitFileViewTree();

	return 0;
}

/**
 * OnKeydown:
 *
 * @param pNMHDR 
 * @param pResult 
 * @return void 
 */
void CFileViewTreeCtrl::OnKeydown(NMHDR* pNMHDR, LRESULT* pResult) 
{
	TV_KEYDOWN* pTVKeyDown = (TV_KEYDOWN*)pNMHDR;
	
	switch(pTVKeyDown->wVKey)
	{
		case VK_DELETE:
		{
			HTREEITEM hItem=GetSelectedItem();
			if((hItem != m_hRoot) && (hItem != m_hHeaderFile) && (hItem != m_hSourceFile))
			{
				CContentFile* pContentFile=(CContentFile*)GetItemData(hItem);
				if(NULL != pContentFile)
				{
					CMainFrame* pFrame = (CMainFrame*)AfxGetMainWnd();
					CTinyUMLDoc* pUMLDoc = (CTinyUMLDoc*)(pFrame->MDIGetActive()->GetActiveDocument());
					if(pUMLDoc) 
						pUMLDoc->RemoveContentFile(pContentFile);
					else	AfxMessageBox("NULL");
				}
				DeleteItem(hItem);
			}
			       }		
		break;
	}

	*pResult = 0;
}

/**	\brief	The CFileViewTreeCtrl::OnSelchanged function

	\param	pNMHDR	a parameter of type NMHDR*
	\param	pResult	a parameter of type LRESULT*

	\return	void	
*/
void CFileViewTreeCtrl::OnSelchanged(NMHDR* pNMHDR, LRESULT* pResult) 
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

void ShowErrorMsg(LPTSTR lpszFunction) 
{ 
	LPVOID lpMsgBuf;
	LPVOID lpDisplayBuf;
	DWORD dw = GetLastError(); 
	
	FormatMessage(
		FORMAT_MESSAGE_ALLOCATE_BUFFER | 
		FORMAT_MESSAGE_FROM_SYSTEM,
		NULL,
		dw,
		MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
		(LPTSTR) &lpMsgBuf,
		0, NULL );
	
	lpDisplayBuf = LocalAlloc(LMEM_ZEROINIT, 
		strlen((const char*)lpMsgBuf)+strlen(lpszFunction)+40); 
	wsprintf((char*)lpDisplayBuf, 
		"%s failed with error %d: %s", 
		lpszFunction, dw, lpMsgBuf); 
	MessageBox(NULL, (const char*)lpDisplayBuf, "Error", MB_OK); 
	
	LocalFree(lpMsgBuf);
	LocalFree(lpDisplayBuf);
}

/**
 * OnDblclk:
 *
 * @param pNMHDR 
 * @param pResult 
 * @return void 
 */
void CFileViewTreeCtrl::OnDblclk(NMHDR* pNMHDR, LRESULT* pResult) 
{
	HTREEITEM hItem=GetSelectedItem();
	HTREEITEM hParentItem=GetParentItem(hItem);
	if(NULL != hParentItem)
	{
		CContentFile* pContentFile = (CContentFile*)(GetItemData(hItem));
		if(NULL != pContentFile)
		{
			CString rText = GetItemText(hParentItem);
			CString rString4;
			rString4.LoadString(IDS_FILE_VIEW_STRING4);
			if(rText == rString4)
			{
				if(pContentFile->GetLength())
				{
					if(TRUE != PathFileExists(pContentFile->GetRefPath())) pContentFile->Unpack();
					HINSTANCE hInst = ::ShellExecute(NULL , "open", pContentFile->GetRefPath() , NULL , NULL , SW_SHOWNORMAL);
					long lValue = (long)hInst;
					//if(lValue <= 32) ShowErrorMsg("open");
				}
				else
				{
					::ShellExecute(NULL , "open", pContentFile->GetRefPath() , NULL , NULL , SW_SHOWNORMAL);
				}
			}
		}
	}
	
	*pResult = 0;
}

void CFileViewTreeCtrl::SetTitle(const CString &rTitle)
{
	if(NULL != m_hRoot)
	{
		SetItemText(GetRootItem(),rTitle);	
	}
}

/**
 * AddFile:
 *
 * @param pFile 
 * @return void 
 */
void CFileViewTreeCtrl::AddFile(CContentFile *pFile)
{
	assert(pFile && "pFile is NULL");

	if(pFile)
	{
		// Adding the Item to the TreeCtrl with the current Icons
		/*
		SHFILEINFO shFinfo;
		CString    strTemp = pFile->GetRefPath();
						
		if ( !SHGetFileInfo( strTemp,0,&shFinfo,sizeof( shFinfo ),
			SHGFI_ICON | SHGFI_SMALLICON ) )
		{
			AfxMessageBox("Error Getting SystemFileInfo!");
			return;
		}
		
		int iIcon = shFinfo.iIcon;
		
		// we only need the index from the system image list
		DestroyIcon( shFinfo.hIcon );
		
		if ( !SHGetFileInfo( strTemp,0,&shFinfo,sizeof( shFinfo ),
			SHGFI_ICON | SHGFI_OPENICON | SHGFI_SMALLICON ) )
		{
			AfxMessageBox("Error Getting SystemFileInfo!");
			return;
		}
		
		int iIconSel = shFinfo.iIcon;
		
		// we only need the index of the system image list
		DestroyIcon( shFinfo.hIcon );
		*/
		int iIcon = 0;
		int iIconSel = 0;

		int pos = pFile->GetName().Find("." , 0);
		CString rExt = pFile->GetName().Right(pFile->GetName().GetLength() - pos);
		rExt.MakeUpper();
		if(rExt == ".H")
		{
			HTREEITEM hItem = InsertItem( pFile->GetName() , iIcon , iIconSel , m_hHeaderFile);
			SetItemData(hItem , (DWORD)pFile);
		}
		else if(rExt == ".CPP")
		{
			HTREEITEM hItem = InsertItem( pFile->GetName() , iIcon , iIconSel , m_hSourceFile);
			SetItemData(hItem , (DWORD)pFile);
		}
		else
		{
			HTREEITEM hItem = InsertItem( pFile->GetName() , iIcon , iIconSel , m_hOtherFiles);
			SetItemData(hItem , (DWORD)pFile);
		}
	}
}

/**
 * GetSysImgList:
 *
 * @return BOOL 
 */
BOOL CFileViewTreeCtrl::GetSysImgList()
{
	SHFILEINFO shFinfo;
	HIMAGELIST hImgList = NULL;
	
	hImgList = (HIMAGELIST)SHGetFileInfo( "C:\\",
		0,
		&shFinfo,
		sizeof( shFinfo ),
		SHGFI_SYSICONINDEX | 
		SHGFI_SMALLICON );
	if ( !hImgList )
	{
		//m_strError = "Cannot retrieve the Handle of SystemImageList!";
		return FALSE;
	}
	m_imgList.m_hImageList = hImgList;

	return TRUE;   // OK
}

/**
 * InitFileViewTree:
 *
 * @return void 
 */
void CFileViewTreeCtrl::InitFileViewTree()
{
	DeleteAllItems();

	CString rString1;
	rString1.LoadString(IDS_FILE_VIEW_STRING1);
	CString rString2;
	rString2.LoadString(IDS_FILE_VIEW_STRING2);
	CString rString3;
	rString3.LoadString(IDS_FILE_VIEW_STRING3);
	CString rString4;
	rString4.LoadString(IDS_FILE_VIEW_STRING4);

	m_hRoot         = InsertItem(_T("") , m_nSysImgSize , m_nSysImgSize);
	m_hSourceFile   = InsertItem(rString1 , m_nSysImgSize , m_nSysImgSize , m_hRoot);
	m_hHeaderFile   = InsertItem(rString2 , m_nSysImgSize , m_nSysImgSize , m_hRoot);
	m_hResourceFile = InsertItem(rString3 , m_nSysImgSize , m_nSysImgSize , m_hRoot);
	m_hOtherFiles   = InsertItem(rString4 , m_nSysImgSize , m_nSysImgSize , m_hRoot);
}