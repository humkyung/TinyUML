// TinyUMLEntityContainer.cpp: implementation of the CTinyUMLEntityContainer class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include <assert.h>
#include "TinyUML.h"
#include "TinyUMLEntityContainer.h"
#include "TinyUMLPackage.h"
#include "TinyUMLDefaultTheme.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

/**
 * CTinyUMLEntityContainer:
 *
 * @return  
 */
CTinyUMLEntityContainer::CTinyUMLEntityContainer() : CIsDrawEntContainer()
{
	SetTheme(new CTinyUMLDefaultTheme);
}

CTinyUMLEntityContainer::~CTinyUMLEntityContainer()
{

}

/**
 * Serialize:
 *
 * @param ar 
 * @return void 
 */
void CTinyUMLEntityContainer::Serialize(CArchive &ar)
{
	CIsDrawEntContainer::Serialize(ar);
}

/**
 * Append:
 *
 * @param obj 
 * @return void 
 */
void CTinyUMLEntityContainer::Append(CIsObject *obj)
{
	assert(obj && "obj is NULL");
	if(obj)
	{
		if(obj->IsKindOf(CTinyUMLPackage::TypeString()))
		{
			m_objs.InsertAt(0,obj);
		}
		else if(obj->IsKindOf( CIsDrawGroupEntity::TypeString() ))
		{
			if(NULL == m_pGroupTable) m_pGroupTable = new CTinyDrawEntityGroupTable;
			if(NULL != m_pGroupTable) m_pGroupTable->Append((CIsDrawGroupEntity*)obj);
		}
		else
		{
			m_objs.Add( obj );
			static_cast<CIsDrawEntity*>(obj)->SetDoc(this);
		}
		
		//////////////////////////////////////////////////////////////////////////
		for(int i=0;i < m_reactorEntry.GetSize();i++)
		{
			CTyDrawContainerReactor* pReactor=m_reactorEntry.GetAt(i);
			pReactor->objectAppened((CIsDrawEntity*)obj);
		}
		//////////////////////////////////////////////////////////////////////////
		
		SetModified( TRUE );
	}
}
