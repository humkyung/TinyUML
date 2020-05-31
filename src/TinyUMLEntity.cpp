// TinyUMLEntity.cpp: implementation of the CTinyUMLEntity class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "TinyUML.h"
#include "TinyUMLEntity.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

IMPLEMENT_SERIAL(CTinyUMLEntity, CIsDrawEntity, 1)
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
CTinyUMLEntity::CTinyUMLEntity() : CIsDrawEntity()
{
	m_bDoneSetupTheme = false;
}

/**
 * CTinyUMLEntity:
 *
 * @param pDoc 
 * @param pController 
 * @return  
 */
CTinyUMLEntity::CTinyUMLEntity(CIsDrawEntContainer* pDoc,CIsControllerObject* pController) : CIsDrawEntity(pDoc,pController)
{
	m_bDoneSetupTheme = false;
}

CTinyUMLEntity::~CTinyUMLEntity()
{

}

/**
 * Serialize:
 *
 * @param ar 
 * @return void 
 */
void CTinyUMLEntity::Serialize(CArchive &ar)
{
	CIsDrawEntity::Serialize(ar);
	
	if(ar.IsStoring())
	{
	}
	else
	{
	}
}

/**
 * Copy:
 *
 * @param pTinyUMLEntity 
 * @return void 
 */
void CTinyUMLEntity::Copy(CTinyUMLEntity *pTinyUMLEntity)
{
	CIsDrawEntity::Copy(pTinyUMLEntity);
	
	m_bDoneSetupTheme = pTinyUMLEntity->m_bDoneSetupTheme;
	m_dragHandle = pTinyUMLEntity->m_dragHandle;
}

/**
 * IsKindOf:
 *
 * @param rType 
 * @return bool 
 */
bool CTinyUMLEntity::IsKindOf(CString rType)
{
	if(TypeString() == rType) return true;

	return CIsDrawEntity::IsKindOf(rType);
}

/**
 * TypeString:
 *
 * @return const CString 
 */
const CString CTinyUMLEntity::TypeString()
{
	return _T("_tiny_uml_entity");
}
