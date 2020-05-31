// TyUMLDocReactor.h: interface for the CTyUMLDocReactor class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_TYUMLDOCREACTOR_H__D420ADA0_0B33_48D4_846C_33F0AAA21F50__INCLUDED_)
#define AFX_TYUMLDOCREACTOR_H__D420ADA0_0B33_48D4_846C_33F0AAA21F50__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <IsDrawEntContainer.h>
#include <TyDrawContainerReactor.h>

class CTinyUMLDoc;
class CTyUMLDocReactor : public CTyDrawContainerReactor
{
public:
	virtual void objectAppened(const CIsDrawEntity* pTyEnt);
	virtual void objectErased(const CIsDrawEntity* pTyEnt);
	virtual void objectModified(const CIsDrawEntity* pEnt);
	CTyUMLDocReactor(CTinyUMLDoc* pDoc,CIsDrawEntContainer* pContainer);
	virtual ~CTyUMLDocReactor();
private:
	CTinyUMLDoc* m_pDoc;
	CIsDrawEntContainer* m_pContainer;
};

#endif // !defined(AFX_TYUMLDOCREACTOR_H__D420ADA0_0B33_48D4_846C_33F0AAA21F50__INCLUDED_)
