// TinyUMLEntity.h: interface for the CTinyUMLEntity class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_TINYUMLENTITY_H__F410B452_FEA7_41BD_94CB_13E5E8D364E9__INCLUDED_)
#define AFX_TINYUMLENTITY_H__F410B452_FEA7_41BD_94CB_13E5E8D364E9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <IsDrawEntity.h>

class CTinyUMLEntity : public CIsDrawEntity  
{
	DECLARE_SERIAL(CTinyUMLEntity)
protected:
	CTinyUMLEntity();
public:
	static const CString TypeString();
	virtual bool IsKindOf(CString rType);
	virtual void Serialize(CArchive &ar);
	CTinyUMLEntity(CIsDrawEntContainer* pDoc,CIsControllerObject* pController);
	virtual ~CTinyUMLEntity();
protected:
	virtual void Copy(CTinyUMLEntity* pTinyUMLEntity);
	long m_dragHandle;
	bool m_bDoneSetupTheme;
};

#endif // !defined(AFX_TINYUMLENTITY_H__F410B452_FEA7_41BD_94CB_13E5E8D364E9__INCLUDED_)
