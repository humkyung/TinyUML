// TinyUMLPackageController.h: interface for the CTinyUMLPackageController class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_TINYUMLPACKAGECONTROLLER_H__C3EAF3BC_71CA_4430_AE90_5B98A5ABA2FC__INCLUDED_)
#define AFX_TINYUMLPACKAGECONTROLLER_H__C3EAF3BC_71CA_4430_AE90_5B98A5ABA2FC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <IsDrawEntController.h>

class CTinyUMLPackageController : public CIsDrawEntController  
{
public:
	virtual void ModifyProperties();
	virtual void OnMouseMove(const IS_MOUSE_EVENT& mouse_event);
	virtual void OnLButtonDblClk(const IS_MOUSE_EVENT& mouse_event);
	virtual void OnLButtonDown(const IS_MOUSE_EVENT& mouse_event);
	CTinyUMLPackageController();
	virtual ~CTinyUMLPackageController();

	IS_DECLARE_CONTROLLER_FUNC()
};

#endif // !defined(AFX_TINYUMLPACKAGECONTROLLER_H__C3EAF3BC_71CA_4430_AE90_5B98A5ABA2FC__INCLUDED_)
