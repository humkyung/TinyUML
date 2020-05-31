// TinyUMLDependency.h: interface for the CTinyUMLDependency class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_TINYUMLDEPENDENCY_H__D311544F_6FE9_43B1_BCDC_D056340D93F4__INCLUDED_)
#define AFX_TINYUMLDEPENDENCY_H__D311544F_6FE9_43B1_BCDC_D056340D93F4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "TinyUMLRelation.h"
#include "TinyUMLDependencyController.h"

class CTinyUMLDependency : public CTinyUMLRelation  
{
	DECLARE_SERIAL(CTinyUMLDependency)
protected:
	CTinyUMLDependency();
public:
	bool IsShowArrow() const;
	virtual void Copy(CTinyUMLDependency* p);
	virtual void Serialize(CArchive &ar);
	virtual void OnNotify(const IS_NOTIFY& notify);
	virtual void SetupTheme(CTinyDrawTheme *pTheme);
	CTinyUMLDependency(CIsDrawEntContainer* pDoc,CIsControllerObject* pController,const CPoint &point, CTinyUMLEntity *pEnt);
	virtual ~CTinyUMLDependency();

	IS_OBJ_DECLARE_FUNC()
protected:
	bool m_bShowArrow;
private:
	friend class CTinyUMLDependencyController;
};

#endif // !defined(AFX_TINYUMLDEPENDENCY_H__D311544F_6FE9_43B1_BCDC_D056340D93F4__INCLUDED_)
