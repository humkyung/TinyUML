#ifndef TINY_TYDRAWLABEL_H_0F963021_559C_4878_8668_08FA455AA6A4_INCLUDED_
#define TINY_TYDRAWLABEL_H_0F963021_559C_4878_8668_08FA455AA6A4_INCLUDED_

#include "IsDrawEntity.h"

class CTinyUMLLabel : public CIsDrawEntity
{
	DECLARE_SERIAL(CTinyUMLLabel)
public:
	CTinyUMLLabel(CIsDrawEntContainer* pDoc,CIsControllerObject* pController);
	CTinyUMLLabel();
	virtual ~CTinyUMLLabel();
public:
	virtual void Serialize(CArchive &ar);
	CFont* GetFont();
	virtual void SetRect( const double& left, const double& top, const double& right, const double& bottom );
	virtual void Copy( CIsDrawEntity* obj );
	virtual void SetRect( CRect rect );

	IS_OBJ_DECLARE_FUNC()
protected:
private:
	CFont* m_pLabelFont;
};

#endif
