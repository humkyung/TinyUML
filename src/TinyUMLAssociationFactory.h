// TinyUMLAssociationFactory.h: interface for the CTinyUMLAssociationFactory class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_TINYUMLASSOCIATIONFACTORY_H__FE048562_CD49_4D23_B1DE_CC32767FCE0D__INCLUDED_)
#define AFX_TINYUMLASSOCIATIONFACTORY_H__FE048562_CD49_4D23_B1DE_CC32767FCE0D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <IsDrawEntController.h>

class CTinyUMLAssociationFactory : public CIsDrawEntController  
{
public:
	enum Type { Diagonal, Rectangular };
public:
	virtual void OnLButtonUp(const IS_MOUSE_EVENT& mouse_event);
	virtual void OnMouseMove(const IS_MOUSE_EVENT& mouse_event);
	virtual void OnLButtonDown(const IS_MOUSE_EVENT& mouse_event);
	CTinyUMLAssociationFactory( bool bAggregation, bool bNavigable);
	virtual ~CTinyUMLAssociationFactory();
protected:
	bool m_bAggregation;
	bool m_bNavigable;

	Type m_defaultType;
};

#endif // !defined(AFX_TINYUMLASSOCIATIONFACTORY_H__FE048562_CD49_4D23_B1DE_CC32767FCE0D__INCLUDED_)
