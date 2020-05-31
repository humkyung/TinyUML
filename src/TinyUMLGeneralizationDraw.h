// TinyUMLGeneralizationDraw.h: interface for the CTinyUMLGeneralizationDraw class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_TINYUMLGENERALIZATIONDRAW_H__32D36ADF_0ACE_4AA6_B15B_92573FDB214B__INCLUDED_)
#define AFX_TINYUMLGENERALIZATIONDRAW_H__32D36ADF_0ACE_4AA6_B15B_92573FDB214B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "TinyUMLRelationDraw.h"

class CTinyUMLGeneralizationDraw : public CTinyUMLRelationDraw  
{
public:
	virtual void DrawFocusObject(CDC *pDC, CIsDrawEntity *pEnt , CIsDrawEntContainer* pDoc , const CIsDrawEditor* pDrawEditor);
	CTinyUMLGeneralizationDraw();
	virtual ~CTinyUMLGeneralizationDraw();

	IS_DECLARE_DRAW_FUNC()
protected:
	virtual void DrawObject(CDC *pDC, CIsDrawEntity *pEnt , CIsDrawEntContainer* pDoc , const CIsDrawEditor* pDrawEditor);
};

#endif // !defined(AFX_TINYUMLGENERALIZATIONDRAW_H__32D36ADF_0ACE_4AA6_B15B_92573FDB214B__INCLUDED_)
