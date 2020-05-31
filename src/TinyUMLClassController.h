// TinyUMLClassController.h: interface for the CTinyUMLClassController class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_TINYUMLCLASSCONTROLLER_H__AEDF3562_9D82_4A7E_99E0_5CD9580D0B28__INCLUDED_)
#define AFX_TINYUMLCLASSCONTROLLER_H__AEDF3562_9D82_4A7E_99E0_5CD9580D0B28__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "IsDrawEntController.h"

class CTinyUMLClassController : public CIsDrawEntController  
{
public:
	virtual void OnLButtonDblClk(const IS_MOUSE_EVENT& mouse_event);
	virtual void OnMouseMove(const IS_MOUSE_EVENT& mouse_event);
	virtual void OnLButtonDown(const IS_MOUSE_EVENT& mouse_event);
	CTinyUMLClassController();
	virtual ~CTinyUMLClassController();

	IS_DECLARE_CONTROLLER_FUNC()
public:
	virtual void OnKeyDown(const IS_KEY_EVENT& key_event);
	virtual void ModifyProperties();
	bool m_bInterface;
private:
	CPoint m_ptOffset;
};

#endif // !defined(AFX_TINYUMLCLASSCONTROLLER_H__AEDF3562_9D82_4A7E_99E0_5CD9580D0B28__INCLUDED_)
