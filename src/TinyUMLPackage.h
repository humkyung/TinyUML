// TinyUMLPackage.h: interface for the CTinyUMLPackage class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_TINYUMLPACKAGE_H__E1B56834_96AB_4865_9393_7E5577F8C852__INCLUDED_)
#define AFX_TINYUMLPACKAGE_H__E1B56834_96AB_4865_9393_7E5577F8C852__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "TinyUMLEntity.h"
#include "TinyUMLPackageController.h"
#include <TinyDrawTheme.h>

class CTinyUMLPackage : public CTinyUMLEntity  
{
	DECLARE_SERIAL(CTinyUMLPackage)
public:
	COLORREF GetFilleColor() const;
	COLORREF GetLineColor() const;
	long GetTabHeight() const;
	long GetTabWidth() const;
	COLORREF GetNameColor() const;
	virtual void Copy(CTinyUMLPackage* p);
	CFont* GetNameFont() const;
	virtual CRect GetNameRect() const;
	CString& GetName();
	void SetName(const CString& rString);
	virtual void SetupTheme(CTinyDrawTheme *pTheme);
	virtual void Serialize(CArchive &ar);

	CTinyUMLPackage();
	CTinyUMLPackage(CIsDrawEntContainer* pDoc,CIsControllerObject* pController);
	virtual ~CTinyUMLPackage();

	IS_OBJ_DECLARE_FUNC()
protected:	
	CString m_name;
	
	long m_tabWidth;
	long m_tabHeight;
	
	CFont *m_pNameFont;
	
	COLORREF* m_nameColor;
	COLORREF m_fillColor;
	COLORREF* m_lineColor;
private:
	friend class CTinyUMLPackageController;
};

#endif // !defined(AFX_TINYUMLPACKAGE_H__E1B56834_96AB_4865_9393_7E5577F8C852__INCLUDED_)
