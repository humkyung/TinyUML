// TinyUMLClipboardManager.cpp: implementation of the CTinyUMLClipboardManager class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include <assert.h>
#include "TinyUML.h"
#include "TinyUMLRelation.h"
#include "TinyUMLClipboardManager.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

/**
 * CTinyUMLClipboardManager:
 *
 * @return  
 */
CTinyUMLClipboardManager::CTinyUMLClipboardManager() : CClipboardManager()
{

}

/**
 * ~CTinyUMLClipboardManager:
 *
 * @return  
 */
CTinyUMLClipboardManager::~CTinyUMLClipboardManager()
{

}

/**
 * SetData:
 *
 * @param pEntSet 
 * @return void 
 */
void CTinyUMLClipboardManager::SetData(CIsDrawEntitySet *pEntSet)
{
	assert( pEntSet && "pEntSet is NULL");
	
	if(pEntSet){
		CSharedFile sf(GMEM_MOVEABLE | GMEM_SHARE | GMEM_ZEROINIT);	
		{
			CArchive ar(&sf,CArchive::store);
			
			CObArray objs;
			const size_t nSiz=pEntSet->GetCount();
			for(long i=0;i < nSiz;i++)
			{
				CIsDrawEntity* pEnt=pEntSet->GetAt(i);
				if(!pEnt->IsKindOf(CTinyUMLRelation::TypeString())) objs.Add(pEnt);
			}
			objs.Serialize(ar);
			ar.Close();
		}
		
		if (sf.GetLength() > 0) {
			// Put the data on the clipboard
			OpenClipboard(NULL);
			EmptyClipboard();
			SetClipboardData(m_nClipboardFormat, sf.Detach());
			CloseClipboard();
		}
	}
}

