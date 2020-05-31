// TinyUMLDoc.cpp : implementation of the CTinyUMLDoc class
//

#include "stdafx.h"
#include <assert.h>
#include "TinyUML.h"
#include "TinyUMLDoc.h"
#include "MainFrm.h"
#include "ClassParser/FileContext.h"
#include "ClassParser/ClassContext.h"
#include "ClassParser/MemberContext.h"
#include "ClassParser/MethodContext.h"
#include "WriteSourceFiles.h"
#include "TinyUMLView.h"

#include <algorithm>
using namespace std;

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTinyUMLDoc

IMPLEMENT_DYNCREATE(CTinyUMLDoc, CDocument)

BEGIN_MESSAGE_MAP(CTinyUMLDoc, CDocument)
	//{{AFX_MSG_MAP(CTinyUMLDoc)
	ON_COMMAND(ID_FILE_SAVESOURCE, OnFileSavesource)
	ON_UPDATE_COMMAND_UI(ID_FILE_SAVE, OnUpdateFileSave)
	ON_COMMAND(ID_FILE_ADD_TO_DOCUMENT, OnFileAddToDocument)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTinyUMLDoc construction/destruction

CTinyUMLDoc::CTinyUMLDoc()
{
}

/**
 * ~CTinyUMLDoc:
 *
 * @return  
 */
CTinyUMLDoc::~CTinyUMLDoc()
{
	try
	{
	}
	catch(...)
	{
		for(vector<CContentFile*>::iterator itr = m_contentFiles.begin(); itr != m_contentFiles.end();itr++)
		{
			delete (*itr);
			m_contentFiles.erase(itr--);
		}
	}
}

/**
 * OnNewDocument:
 *
 * @return BOOL 
 */
BOOL CTinyUMLDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;
	
	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)
	m_container.AddReactor(new CTyUMLDocReactor(this,&m_container));
	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CTinyUMLDoc serialization

/**
 * Serialize:
 *
 * @param ar 
 * @return void 
 */
void CTinyUMLDoc::Serialize(CArchive& ar)
{
	CDocument::Serialize(ar);
	
	if(ar.IsStoring())
	{
		m_Header.headID = MAKEFOURCC('U', 'M', 'L', 'S');
		m_Header.version = CURRENT_FILE_VERSION;
		ar << m_Header.headID;
		ar << m_Header.version;
	}
	else
	{
		// let's put a short header for versioning.
		ar >> m_Header.headID;
		ar >> m_Header.version;
		
		if (m_Header.headID != MAKEFOURCC('U', 'M', 'L', 'S'))
		{
			ar.Flush();
			// it's a file that didn't have a header, so say version 0
			ar.GetFile()->SeekToBegin();
			m_Header.version = 0;
		}
		
		// warning message if version can be read, but will be overwritten
		if (m_Header.version < CURRENT_FILE_VERSION)
		{
			CString warnMess;
			warnMess.LoadString(IDS_FILE_OUTDATED_WARNING);
			MessageBox(NULL, warnMess, _T("TinyUML"), MB_OK);
		}
		
		// see if it is beyond our program to understand this version
		if (m_Header.version > CURRENT_FILE_VERSION)
		{
			CString errMess;
			errMess.LoadString(IDS_FILE_TOO_NEW_ERROR);
			MessageBox(NULL, errMess, _T("TinyUML"), MB_OK);
			return;
		}
	}
	
	m_container.Serialize(ar);
	
	if(ar.IsStoring())
	{
		long contentFiles = m_contentFiles.size();
		ar << contentFiles;
		for(int i = 0;i < contentFiles;i++)
		{
			m_contentFiles.at(i)->Serialize(ar);
		}
	}
	else
	{
		long contentFiles = 0L;
		ar >> contentFiles;
		for(int i = 0;i < contentFiles;i++)
		{
			CContentFile* pContentFile = new CContentFile;
			pContentFile->Serialize(ar);
			m_contentFiles.push_back(pContentFile);
		}
	}

	//////////////////////////////////////////////////////////////////////////
	CMainFrame* pFrame=static_cast<CMainFrame*>(AfxGetMainWnd());
	CWorkspaceBar* pWorkspaceBar=pFrame->GetWorkspaceBar();
	pWorkspaceBar->SetTitle(ar.GetFile()->GetFileName());
}

/////////////////////////////////////////////////////////////////////////////
// CTinyUMLDoc diagnostics

#ifdef _DEBUG
void CTinyUMLDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CTinyUMLDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CTinyUMLDoc commands

/**
 * DisplayContentsOnWorkspace:
 *
 * @return void 
 */
void CTinyUMLDoc::DisplayContentsOnWorkspace()
{
	CMainFrame* pMainFrame=(CMainFrame*)(AfxGetApp()->GetMainWnd());
	CWorkspaceBar* pWorkspaceBar = pMainFrame->GetWorkspaceBar();
	if(NULL != pWorkspaceBar)
	{
		pMainFrame->GetWorkspaceBar()->Clear();
		pMainFrame->GetWorkspaceBar()->SetTitle(GetTitle());
		
		CTinyDocIterator* pIter=m_container.CreateIteator();
		for(;!pIter->IsDone();pIter->Next())
		{
			CIsDrawEntity* pEnt=pIter->GetData();
			if(pEnt->IsErased()) continue;
			if(pEnt->IsKindOf(CTinyUMLClass::TypeString()))
				pMainFrame->GetWorkspaceBar()->AttachClass(static_cast<CTinyUMLClass*>(pEnt));
		}
		delete pIter;

		if(!m_contentFiles.empty())
		{
			for(vector<CContentFile*>::iterator itr = m_contentFiles.begin(); itr != m_contentFiles.end();itr++)
			{
				pWorkspaceBar->AddFileToFileView(*itr);
			}
		}
	}
}


/**
 * OnFileSavesource:
 *
 * @return void 
 */
void CTinyUMLDoc::OnFileSavesource() 
{
	CWriteSourceFiles writer;
	
	long l=0L;
	CTinyDocIterator* pIter=m_container.CreateIteator();
	for(;!pIter->IsDone();pIter->Next())
	{
		CIsDrawEntity* pTyEnt=pIter->GetData();
		if(pTyEnt->IsErased()) continue;
		if(pTyEnt->IsSelected()) writer.Add(pTyEnt);
	}
	delete pIter;
	//while(pTyEnt = m_container.GetAt(l++,CTinyDrawEntityContainer::tyForRead)){
	//	if(pTyEnt->IsErased()) continue;
	//	if(pTyEnt->IsSelected()) writer.Add(pTyEnt);
	//}

	writer.DoModal();
}

/**
 * OnOpenDocument:
 *
 * @param lpszPathName 
 * @return BOOL 
 */
BOOL CTinyUMLDoc::OnOpenDocument(LPCTSTR lpszPathName) 
{
	if (!CDocument::OnOpenDocument(lpszPathName))
		return FALSE;
	
	DisplayContentsOnWorkspace();
	
	return TRUE;
}

/**
 * SaveModified:
 *
 * @return BOOL 
 */
BOOL CTinyUMLDoc::SaveModified() 
{
	if(m_container.IsModified()) SetModifiedFlag();
	return CDocument::SaveModified();
}

/**
 * OnUpdateFileSave:
 *
 * @param pCmdUI 
 * @return void 
 */
void CTinyUMLDoc::OnUpdateFileSave(CCmdUI* pCmdUI) 
{
	if(m_container.IsModified() || IsModified())
		pCmdUI->Enable(TRUE);
	else	pCmdUI->Enable(FALSE);
}

/**
 * CanCloseFrame:
 *
 * @param pFrame 
 * @return BOOL 
 */
BOOL CTinyUMLDoc::CanCloseFrame(CFrameWnd* pFrame) 
{
	CTinyUMLApp* pApp=static_cast<CTinyUMLApp*>(AfxGetApp());
	if(pApp->GetOpenDocumentCount() > 1)
		return CDocument::CanCloseFrame(pFrame);
	else	return FALSE;
}

/**
 * OnFileAddToDocument:
 *
 * @return void 
 */
void CTinyUMLDoc::OnFileAddToDocument() 
{
	// TODO: Add your command handler code here

	CString rFilter = 
		"C++ Files(*.h;*.cpp)|*.h;*.cpp|"
		"Resource Files(*.rc)|*.rc|"
		"All Files(*.*)|*.*|";
	CFileDialog objDlg(TRUE, NULL,NULL, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT | OFN_ALLOWMULTISELECT, rFilter , AfxGetMainWnd());
	if(IDOK != objDlg.DoModal()) return;
	
	POSITION pos = objDlg.GetStartPosition();
	while(NULL != pos)
	{
		CString rPathName = objDlg.GetNextPathName(pos);
		
		int pos = rPathName.Find("." , 0);
		CString rExt = rPathName.Right(rPathName.GetLength() - pos);
		rExt.MakeUpper();
		bool isStore = ((rExt == ".H") || (rExt == ".CPP")) ? true : false;
		CContentFile* pContentFile = new CContentFile(rPathName , isStore);
		
		m_contentFiles.push_back(pContentFile);

		ParseFileContext(rPathName);
		//////////////////////////////////////////////////////////////////////////
		CMainFrame* pFrame = (CMainFrame*)AfxGetMainWnd();
		pFrame->GetWorkspaceBar()->AddFileToFileView(pContentFile);
	}
	SetModifiedFlag(TRUE);
	
	//////////////////////////////////////////////////////////////////////////
	CMainFrame* pFrame = (CMainFrame*)AfxGetMainWnd();
	pFrame->GetWorkspaceBar()->RedrawFileViewTree();
}

/**
 * RemoveContentFile:
 *
 * @param pContentFile 
 * @return void 
 */
void CTinyUMLDoc::RemoveContentFile(CContentFile *pContentFile)
{
	assert(pContentFile && "pContentFile is NULL");

	if(pContentFile)
	{
		/// delete class
		CTinyDocIterator* pIter=m_container.CreateIteator();
		for(;!pIter->IsDone();pIter->Next())
		{
			CIsDrawEntity* pEnt=pIter->GetData();
			if(pEnt->IsErased()) continue;
			if(pEnt->IsKindOf(CTinyUMLClass::TypeString()))
			{
				CTinyUMLClass* pClass = static_cast<CTinyUMLClass*>(pEnt);
				if(pClass->GetPathName() == pContentFile->GetRefPath())
				{
					pClass->Erase();
				}
			}
		}
		delete pIter;

		vector<CContentFile*>::iterator itr = find(m_contentFiles.begin() , m_contentFiles.end() , pContentFile);
		if(itr != m_contentFiles.end())
		{
			delete (*itr);
			m_contentFiles.erase(itr);
		}

		CTinyUMLEditor* pUMLEditor = NULL;
		POSITION pos = GetFirstViewPosition();
		if(NULL != pos)
		{
			CTinyUMLView* pUMLView = static_cast<CTinyUMLView*>(GetNextView(pos));
			pUMLView->Invalidate(FALSE);
		}

		SetModifiedFlag(TRUE);
	}
}

/**
 * ParseFileContext:
 *
 * @param rFilePath 
 * @return void 
 */
void CTinyUMLDoc::ParseFileContext(const CString &rFilePath)
{
	CFileContext fileContext(rFilePath);
	fileContext.Parse();
	
	long lIndex=0L;
	CParserContext* pContext=NULL;
	while(NULL != (pContext = fileContext.GetAt(lIndex++)))
	{
		if(pContext->IsKindOf(CParserContext::CLASS_CONTEXT))
		{
			CClassContext* pClassContext = static_cast<CClassContext*>(pContext);
			
			CTinyUMLClass* pNewClass = new CTinyUMLClass(&(m_container),NULL);
			pNewClass->SetPathName(rFilePath);
			
			long lSection = 0L;
			CClassSection* pSection = NULL;
			while(NULL != (pSection = pClassContext->GetSectionAt(lSection++)))
			{
				long lContext = 0L;
				CParserContext* pContext = NULL;
				while(NULL != (pContext = pSection->GetAt(lContext++)))
				{
					if(pContext->IsKindOf(CParserContext::METHOD_CONTEXT))
					{
						CMethodContext* pMethodContext = static_cast<CMethodContext*>(pContext);
						
						CTinyUMLClass::Method method;
						method.access = CTinyUMLClass::Method::private_method;
						if(pSection->IsPublic())
							method.access = CTinyUMLClass::Method::public_method;
						else if(pSection->IsProtected())
							method.access = CTinyUMLClass::Method::protected_method;
						method.type = pMethodContext->GetType();
						method.name = pMethodContext->GetName();
						pNewClass->AddMethod(method);
					}
					else if(pContext->IsKindOf(CParserContext::MEMBER_CONTEXT))
					{
						CMemberContext* pMemberContext = static_cast<CMemberContext*>(pContext);
						
						CTinyUMLClass::Member member;
						member.access = CTinyUMLClass::Member::private_member;
						if(pSection->IsPublic())
							member.access = CTinyUMLClass::Member::public_member;
						else if(pSection->IsProtected())
							member.access = CTinyUMLClass::Member::protected_member;
						member.type = pMemberContext->GetType();
						member.name = pMemberContext->GetName();
						pNewClass->AddMember(member);
					}
				}
			}

			pNewClass->SetupTheme(m_container.GetTheme());
			CRect rect = pNewClass->GetRect();
			//const int right  = pUMLEditor->SnapX(pNewClass->GetMinimumSize().cx);
			//const int bottom = pUMLEditor->SnapY(pNewClass->GetMinimumSize().cy);
			const int right  = pNewClass->GetMinimumSize().cx;
			const int bottom = pNewClass->GetMinimumSize().cy;
			pNewClass->SetRect(rect.left,rect.top,right,bottom);
			pNewClass->SetName(pClassContext->GetName());
			m_container.Append(pNewClass);
			
			POSITION pos = GetFirstViewPosition();
			if(NULL != pos)
			{
				CTinyUMLView* pUMLView = static_cast<CTinyUMLView*>(GetNextView(pos));
				CTinyUMLEditor* pUMLEditor = pUMLView->GetUMLEditor();
				
				//////////////////////////////////////////////////////////////////////////
				IS_NOTIFY notify;
				notify.hdr.hwndFrom = NULL;
				notify.pEntFrom     = pNewClass;
				pUMLEditor->SendMessage(WM_NOTIFY,(WPARAM)IS_CREATE_ENTITY,(LPARAM)(&notify));
			}
		}
	}
	//pUMLEditor->Invalidate(FALSE);
}
