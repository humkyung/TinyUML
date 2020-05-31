// TinyUMLPackage.cpp: implementation of the CTinyUMLPackage class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include <IsDrawCtrlHost.h>
#include "TinyUML.h"
#include "TinyUMLEditor.h"
#include "TinyUMLPackage.h"
#include "TinyUMLTheme.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

IMPLEMENT_SERIAL(CTinyUMLPackage, CTinyUMLEntity, 1)
IS_OBJ_IMPLEMENT_FUNC(CTinyUMLPackage , CTinyUMLEntity , "_TINY_UML_PACKAGE_")
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

/**
 * CTinyUMLPackage:
 *
 * @return  
 */
CTinyUMLPackage::CTinyUMLPackage()
{
	SetTypeString( CTinyUMLPackage::TypeString() );
}

CTinyUMLPackage::CTinyUMLPackage(CIsDrawEntContainer* pDoc,CIsControllerObject* pController) : CTinyUMLEntity(pDoc,pController){
	SetTypeString( CTinyUMLPackage::TypeString() );
	
	m_name = "New package";
	m_tabWidth = 100;
}

CTinyUMLPackage::~CTinyUMLPackage()
{

}

/**
 * SetupTheme:
 *
 * @return void 
 */
void CTinyUMLPackage::SetupTheme(CTinyDrawTheme *pTheme)
{
	CTinyUMLTheme* pUMLTheme = static_cast<CTinyUMLTheme*>(pTheme);
	if(NULL != pUMLTheme)
	{
		m_tabHeight = pUMLTheme->nameHeight();
		m_pNameFont = pUMLTheme->GetNameFont();
		m_nameColor = pUMLTheme->GetNameColor();
		m_fillColor = *(pUMLTheme->GetPackageColor());
		m_lineColor = pUMLTheme->GetLineColor();
	}
}

CRect CTinyUMLPackage::GetNameRect() const
{
	CPoint ptOrigin(GetLeft(),GetTop());
	CRect r(ptOrigin, CSize(m_tabWidth, m_tabHeight));
	r.DeflateRect(4, 2);
	return r;
}

/**
 * Serialize:
 *
 * @param ar 
 * @return void 
 */
void CTinyUMLPackage::Serialize(CArchive &ar)
{
	CTinyUMLEntity::Serialize(ar);
	
	if(ar.IsStoring())
	{
		ar << m_name;
		ar << m_tabWidth;
	}else{
		ar >> m_name;
		ar >> m_tabWidth;
	}
}

void CTinyUMLPackage::SetName(const CString &rString)
{
	m_name = rString;
}

CString& CTinyUMLPackage::GetName()
{
	return m_name;
}

CFont* CTinyUMLPackage::GetNameFont() const
{
	return m_pNameFont;
}

/**
 * Copy:
 *
 * @param p 
 * @return void 
 */
void CTinyUMLPackage::Copy(CTinyUMLPackage *p)
{
	CTinyUMLEntity::Copy(p);

	m_name = p->m_name;
	m_tabWidth = p->m_tabWidth;
	m_tabHeight= p->m_tabHeight;
}

COLORREF CTinyUMLPackage::GetNameColor() const
{
	return (*m_nameColor);
}

long CTinyUMLPackage::GetTabWidth() const
{
	return m_tabWidth;
}

long CTinyUMLPackage::GetTabHeight() const
{
	return m_tabHeight;
}

COLORREF CTinyUMLPackage::GetLineColor() const
{
	return (*m_lineColor);
}

COLORREF CTinyUMLPackage::GetFilleColor() const
{
	return m_fillColor;
}
