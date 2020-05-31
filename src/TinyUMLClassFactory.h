// TinyUMLClassFactory.h: interface for the CTinyUMLClassFactory class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_TINYUMLCLASSFACTORY_H__3F47E9A7_2ED3_42E1_ADAD_2BA86281F1C6__INCLUDED_)
#define AFX_TINYUMLCLASSFACTORY_H__3F47E9A7_2ED3_42E1_ADAD_2BA86281F1C6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <IsDrawEntController.h>

class CTinyUMLClassFactory : public CIsDrawEntController  
{
public:
	virtual void OnLButtonDown(const IS_MOUSE_EVENT& mouse_event);
	CTinyUMLClassFactory(bool bInterface);
	virtual ~CTinyUMLClassFactory();

private:
	bool m_bInterface;
};

#endif // !defined(AFX_TINYUMLCLASSFACTORY_H__3F47E9A7_2ED3_42E1_ADAD_2BA86281F1C6__INCLUDED_)
