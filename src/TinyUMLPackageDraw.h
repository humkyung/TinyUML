// TinyUMLPackageDraw.h: interface for the CTinyUMLPackageDraw class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_TINYUMLPACKAGEDRAW_H__C3B6BF51_1BD4_4AF9_A463_3396257B86B9__INCLUDED_)
#define AFX_TINYUMLPACKAGEDRAW_H__C3B6BF51_1BD4_4AF9_A463_3396257B86B9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CTinyUMLPackageDraw : public CIsDrawObject  
{
public:
	virtual void DrawFocusObject(CDC *pDC, CIsDrawEntity *pEnt , CIsDrawEntContainer* pDoc , const CIsDrawEditor* pDrawEditor);
	CTinyUMLPackageDraw();
	virtual ~CTinyUMLPackageDraw();

	IS_DECLARE_DRAW_FUNC()
protected:
	virtual void DrawObject(CDC *pDC, CIsDrawEntity *pEnt , CIsDrawEntContainer* pDoc , const CIsDrawEditor* pDrawEditor);
};

#endif // !defined(AFX_TINYUMLPACKAGEDRAW_H__C3B6BF51_1BD4_4AF9_A463_3396257B86B9__INCLUDED_)
