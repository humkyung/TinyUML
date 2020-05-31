// TinyUMLNoteController.h: interface for the CTinyUMLNoteController class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_TINYUMLNOTECONTROLLER_H__3FD1760F_1736_4EC3_8DA2_735CE114B3C3__INCLUDED_)
#define AFX_TINYUMLNOTECONTROLLER_H__3FD1760F_1736_4EC3_8DA2_735CE114B3C3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <IsDrawEntController.h>

class CTinyUMLNoteController : public CIsDrawEntController  
{
public:
	virtual void ModifyProperties();
	virtual void OnMouseMove(const IS_MOUSE_EVENT& mouse_event);
	virtual void OnLButtonDblClk(const IS_MOUSE_EVENT& mouse_event);
	virtual void OnLButtonDown(const IS_MOUSE_EVENT& mouse_event);
	CTinyUMLNoteController();
	virtual ~CTinyUMLNoteController();

	IS_DECLARE_CONTROLLER_FUNC()

};

#endif // !defined(AFX_TINYUMLNOTECONTROLLER_H__3FD1760F_1736_4EC3_8DA2_735CE114B3C3__INCLUDED_)
