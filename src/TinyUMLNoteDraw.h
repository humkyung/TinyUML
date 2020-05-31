// TinyUMLNoteDraw.h: interface for the CTinyUMLNoteDraw class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_TINYUMLNOTEDRAW_H__29657EEF_0902_4C4E_BC23_3D2D342D9CB6__INCLUDED_)
#define AFX_TINYUMLNOTEDRAW_H__29657EEF_0902_4C4E_BC23_3D2D342D9CB6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "TinyUMLTheme.h"

class CTinyUMLNoteDraw : public CIsDrawObject  
{
public:
	virtual void DrawFocusObject(CDC *pDC, CIsDrawEntity *pEnt , CIsDrawEntContainer* pDoc , const CIsDrawEditor* pDrawEditor);
	CTinyUMLNoteDraw();
	virtual ~CTinyUMLNoteDraw();

	IS_DECLARE_DRAW_FUNC()
protected:
	virtual void DrawObject(CDC *pDC, CIsDrawEntity *pEnt , CIsDrawEntContainer* pDoc , const CIsDrawEditor* pDrawEditor);
private:
	void DrawShadow(CDC* pDC,const CPoint& ptOrigin,const double& nWidth,const double& nHeight , 
		const long& cornerWidth , const long& cornerHeight);
	CTinyUMLTheme* m_pTheme;
	
	COLORREF m_fillColor;
};

#endif // !defined(AFX_TINYUMLNOTEDRAW_H__29657EEF_0902_4C4E_BC23_3D2D342D9CB6__INCLUDED_)
