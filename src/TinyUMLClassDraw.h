// TinyUMLClassDraw.h: interface for the CTinyUMLClassDraw class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_TINYUMLCLASSDRAW_H__DB381ABB_8949_4592_B9E6_0B3DB39D6BD0__INCLUDED_)
#define AFX_TINYUMLCLASSDRAW_H__DB381ABB_8949_4592_B9E6_0B3DB39D6BD0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "TinyUMLClass.h"
#include <IsDrawObject.h>
#include "TinyUMLTheme.h"

class CTinyUMLClassDraw : public CIsDrawObject  
{
public:
	void DrawFocusObject(CDC *pDC , CIsDrawEntity* pEnt , CIsDrawEntContainer* pDoc , const CIsDrawEditor* pDrawEditor);
	CTinyUMLClassDraw();
	virtual ~CTinyUMLClassDraw();

	IS_DECLARE_DRAW_FUNC()
protected:
	virtual void DrawObject(CDC *pDC, CIsDrawEntity *pEnt , CIsDrawEntContainer* pDoc , const CIsDrawEditor* pDrawEditor);
private:
	void DrawBody(CDC* pDC , CIsDrawEntity *pEnt , const bool isOnMouse = false);
private:
	CFont* methodFont(long index , CTinyUMLClass* pClass) const;
	void DrawMethods(CDC* pDC , CTinyUMLClass* pClass);
	void DrawBitmap(CDC *pDC, CBitmap *pBitmap, const CRect &rectTaget);
	CFont* attributeFont(long index , CTinyUMLClass* pClass) const;
	void DrawMembers(CDC* pDC , CTinyUMLClass* pClass);
	void DrawTitleBar(CDC* pDC , CIsDrawEntity *pEnt);
	
	CTinyUMLTheme* m_pTheme;
	CBitmap m_publicMemberBmp;
	CBitmap m_protectedMemberBmp;
	CBitmap m_privateMemberBmp;
	CBitmap m_publicMethodBmp;
	CBitmap m_protectedMethodBmp;
	CBitmap m_privateMethodBmp;
};

#endif // !defined(AFX_TINYUMLCLASSDRAW_H__DB381ABB_8949_4592_B9E6_0B3DB39D6BD0__INCLUDED_)
