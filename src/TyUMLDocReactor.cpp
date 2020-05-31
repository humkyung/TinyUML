// TyUMLDocReactor.cpp: implementation of the CTyUMLDocReactor class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "TinyUML.h"
#include "TinyUMLDoc.h"
#include "TyUMLDocReactor.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CTyUMLDocReactor::CTyUMLDocReactor(CTinyUMLDoc* pDoc,CIsDrawEntContainer* pContainer)
{
	m_pDoc = pDoc;
	m_pContainer = pContainer;
}

CTyUMLDocReactor::~CTyUMLDocReactor()
{

}

/**
 * objectAppended:
 *
 * @param pTyEnt 
 * @return void 
 */
void CTyUMLDocReactor::objectAppened(const CIsDrawEntity* pTyEnt)
{
}

/**
 * objectErased:
 *
 * @param pTyEnt 
 * @return void 
 */
void CTyUMLDocReactor::objectErased(const CIsDrawEntity* pTyEnt)
{
}

/**
 * objectModified:
 *
 * @param pEnt 
 * @return void 
 */
void CTyUMLDocReactor::objectModified(const CIsDrawEntity* pEnt)
{
}
