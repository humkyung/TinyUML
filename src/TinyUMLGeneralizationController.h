// TinyUMLGeneralizationController.h: interface for the CTinyUMLGeneralizationController class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_TINYUMLGENERALIZATIONCONTROLLER_H__47BD8272_95D8_44D1_8E05_AB19EDE91495__INCLUDED_)
#define AFX_TINYUMLGENERALIZATIONCONTROLLER_H__47BD8272_95D8_44D1_8E05_AB19EDE91495__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <IsDrawEntController.h>

class CTinyUMLGeneralizationController : public CIsDrawEntController  
{
public:
	virtual void OnMouseMove(const IS_MOUSE_EVENT& mouse_event);
	virtual void OnLButtonUp(const IS_MOUSE_EVENT& mouse_event);
	virtual void OnLButtonDown(const IS_MOUSE_EVENT& mouse_event);
	CTinyUMLGeneralizationController();
	virtual ~CTinyUMLGeneralizationController();

	IS_DECLARE_CONTROLLER_FUNC()
public:
	virtual void ModifyProperties();
	bool m_bRealize;
};

#endif // !defined(AFX_TINYUMLGENERALIZATIONCONTROLLER_H__47BD8272_95D8_44D1_8E05_AB19EDE91495__INCLUDED_)
