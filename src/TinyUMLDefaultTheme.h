// PresentationTheme.h: interface for the CTinyUMLDefaultTheme class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_TINYUMLDEFAULTTHEME_H__085F9428_E381_4035_8376_CD4FC1FE9CD1__INCLUDED_)
#define AFX_TINYUMLDEFAULTTHEME_H__085F9428_E381_4035_8376_CD4FC1FE9CD1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "TinyUMLTheme.h"
class CTinyUMLDefaultTheme : public CTinyUMLTheme
{
	DECLARE_SERIAL(CTinyUMLDefaultTheme)
public:
	virtual void Serialize(CArchive &ar);
	CTinyUMLDefaultTheme();
	virtual ~CTinyUMLDefaultTheme();
};

#endif // !defined(AFX_TINYUMLDEFAULTTHEME_H__085F9428_E381_4035_8376_CD4FC1FE9CD1__INCLUDED_)
