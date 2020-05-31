// TinyUMLLabelDraw.h: interface for the CTinyUMLLabelDraw class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_TINYUMLLABELDRAW_H__1A49575E_1131_4716_BFC9_C21B6CA2BE2F__INCLUDED_)
#define AFX_TINYUMLLABELDRAW_H__1A49575E_1131_4716_BFC9_C21B6CA2BE2F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CTinyUMLLabelDraw : public CIsDrawObject  
{
public:
	virtual void DrawFocusObject(CDC *pDC, CIsDrawEntity *pEnt , CIsDrawEntContainer* pDoc , const CIsDrawEditor* pDrawEditor);
	CTinyUMLLabelDraw();
	virtual ~CTinyUMLLabelDraw();

	IS_DECLARE_DRAW_FUNC()
protected:
	virtual void DrawObject(CDC *pDC, CIsDrawEntity *pEnt , CIsDrawEntContainer* pDoc , const CIsDrawEditor* pDrawEditor);
};

#endif // !defined(AFX_TINYUMLLABELDRAW_H__1A49575E_1131_4716_BFC9_C21B6CA2BE2F__INCLUDED_)
