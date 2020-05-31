// TinyUMLDependencyController.h: interface for the CTinyUMLDependencyController class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_TINYUMLDEPENDENCYCONTROLLER_H__8EAE8E11_DC15_4019_8F25_E4D0CE2973EA__INCLUDED_)
#define AFX_TINYUMLDEPENDENCYCONTROLLER_H__8EAE8E11_DC15_4019_8F25_E4D0CE2973EA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <IsDrawEntController.h>

class CTinyUMLDependencyController : public CIsDrawEntController  
{
public:
	enum Type { Diagonal, Rectangular };
public:
	virtual void ModifyProperties();
	virtual void OnLButtonUp(const IS_MOUSE_EVENT& mouse_event);
	virtual void OnMouseMove(const IS_MOUSE_EVENT& mouse_event);
	virtual void OnLButtonDown(const IS_MOUSE_EVENT& mouse_event);
	CTinyUMLDependencyController();
	virtual ~CTinyUMLDependencyController();

	IS_DECLARE_CONTROLLER_FUNC()
protected:
	Type m_defaultType;
};

#endif // !defined(AFX_TINYUMLDEPENDENCYCONTROLLER_H__8EAE8E11_DC15_4019_8F25_E4D0CE2973EA__INCLUDED_)
