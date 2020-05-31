// TinyUMLClass.cpp: implementation of the CTinyUMLClass class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include <assert.h>
#include <IsDrawCtrlHost.h>
#include <IsDrawEditor.h>
#include "TinyUMLEditor.h"
#include "TinyUML.h"
#include "TinyUMLClass.h"
#include "TinyUMLClassController.h"
#include "GUID.h"
#include "TinyUMLTheme.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

IMPLEMENT_SERIAL(CTinyUMLClass, CTinyUMLEntity, 1)
IS_OBJ_IMPLEMENT_FUNC(CTinyUMLClass , CTinyUMLEntity , "_TINY_UML_CLASS_")
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////


/**
 * CTinyUMLClass:
 *
 * @return  
 */
CTinyUMLClass::CTinyUMLClass()
{
	SetTypeString( CTinyUMLClass::TypeString() );
	m_rPathName = ".h";
	m_bFolderOpen = true;
	m_sizFolder.cx = m_sizFolder.cy = 12;
	m_rNote = "";

	//////////////////////////////////////////////////////////////////////////
	/// initialize variables
	m_pStereotypeFont = NULL;
	m_pNameFont = NULL;
	m_pMemberFont = NULL;
	m_pStaticAttributeFont = NULL;
	m_pMethodFont = NULL;
	m_pAbstractMethodFont = NULL;
	m_pAbstractNameFont = NULL;
	m_pStaticMethodFont = NULL;
	m_pCompartimentNameFont = NULL;

	m_pFillColor = NULL;
	m_lineColor = NULL;
	m_stereotypeColor = NULL;
	m_nameColor = NULL;
	m_attributeColor = NULL;
	m_methodColor = NULL;
	m_compartimentNameColor = NULL;
}

/**
 * CTinyUMLClass:
 *
 * @param pTinyDrawEditor 
 * @param pController 
 * @param bInterface 
 * @return  
 */
CTinyUMLClass::CTinyUMLClass(CIsDrawEntContainer* pDoc,CIsControllerObject* pController, bool bInterface) : 
CTinyUMLEntity(pDoc,pController)
{
	SetTypeString( CTinyUMLClass::TypeString() );

	SetName(bInterface ? "NewInterface" : "NewClass");
	m_rPathName = m_rName + ".h";
	m_stereotype = bInterface ? "interface" : "class";
	m_bFolderOpen = true;
	m_sizFolder.cx = m_sizFolder.cy = 12;
	m_bShowStereotype = bInterface ? true : false;
	m_bAbstract = bInterface ? true : false;
	m_bShowAttributes = true;
	m_bShowMethods = true;
	m_bShowCompartimentName = true;
	m_rNote = "";
}

/**
 * CTinyUMLClass:
 *
 * @param TinyUMLClass 
 * @return CTinyUMLClass( const 
 */
CTinyUMLClass::CTinyUMLClass(const CTinyUMLClass &TinyUMLClass)
{
	Copy(const_cast<CTinyUMLClass*>(&TinyUMLClass));
}

/**
 * ~CTinyUMLClass:
 *
 * @return  
 */
CTinyUMLClass::~CTinyUMLClass()
{

}

/**
 * Copy:
 *
 * @param pTinyUMLClass 
 * @return void 
 */
void CTinyUMLClass::Copy(CTinyUMLClass *pTinyUMLClass)
{
	CTinyUMLEntity::Copy(pTinyUMLClass);
	
	m_rPathName = pTinyUMLClass->m_rPathName;
	//////////////////////////////////////////////////////////////////////////
	/// font
	m_pStereotypeFont = pTinyUMLClass->m_pStereotypeFont;
	m_pNameFont = pTinyUMLClass->m_pNameFont;
	m_pMemberFont = pTinyUMLClass->m_pMemberFont;
	m_pStaticAttributeFont = pTinyUMLClass->m_pStaticAttributeFont;
	m_pMethodFont = pTinyUMLClass->m_pMethodFont;
	m_pAbstractMethodFont = pTinyUMLClass->m_pAbstractMethodFont;
	m_pStaticMethodFont = pTinyUMLClass->m_pStaticMethodFont;
	m_pCompartimentNameFont = pTinyUMLClass->m_pCompartimentNameFont;
	//////////////////////////////////////////////////////////////////////////

	m_rNote= pTinyUMLClass->m_rNote;
	m_bFolderOpen = pTinyUMLClass->m_bFolderOpen;
	m_bShowStereotype = pTinyUMLClass->m_bShowStereotype;
	m_bShowAttributes = pTinyUMLClass->m_bShowAttributes;
	m_bShowMethods = pTinyUMLClass->m_bShowMethods;
	m_bShowCompartimentName = pTinyUMLClass->m_bShowCompartimentName;
	m_bAbstract = pTinyUMLClass->m_bAbstract;
	m_stereotype = pTinyUMLClass->m_stereotype;
	
	m_nameHeight = pTinyUMLClass->m_nameHeight;
	m_stereotypeHeight = pTinyUMLClass->m_stereotypeHeight;
	m_attributeHeight = pTinyUMLClass->m_attributeHeight;
	m_methodHeight = pTinyUMLClass->m_methodHeight;
	m_compartimentNameHeight = pTinyUMLClass->m_compartimentNameHeight;
	m_newAttributeHeight = pTinyUMLClass->m_newAttributeHeight;
	m_newMethodHeight = pTinyUMLClass->m_newMethodHeight;
		
	m_sizFolder = pTinyUMLClass->m_sizFolder;
	m_copySize  = pTinyUMLClass->m_copySize;
	//////////////////////////////////////////////////////////////////////////
	m_attributes.Copy(pTinyUMLClass->m_attributes);
	m_methods.Copy(pTinyUMLClass->m_methods);
	memcpy(m_yCache,pTinyUMLClass->m_yCache,sizeof(long)*128);
	
	//////////////////////////////////////////////////////////////////////////
	/// color
	m_pFillColor = pTinyUMLClass->m_pFillColor;
	m_lineColor = pTinyUMLClass->m_lineColor;
	m_stereotypeColor = pTinyUMLClass->m_stereotypeColor;
	m_nameColor = pTinyUMLClass->m_nameColor;
	m_shadowColor = pTinyUMLClass->m_shadowColor;
	m_attributeColor = pTinyUMLClass->m_attributeColor;
	m_methodColor = pTinyUMLClass->m_methodColor;
	m_compartimentNameColor = pTinyUMLClass->m_compartimentNameColor;
	//////////////////////////////////////////////////////////////////////////
	
	CopyMemory(m_yCache,pTinyUMLClass->m_yCache,sizeof(long)*128);
}

/**
 * SetupTheme:
 *
 * @return void 
 */
void CTinyUMLClass::SetupTheme(CTinyDrawTheme* pTheme)
{	
	assert(pTheme && "pTheme is NULL");

	if(NULL != pTheme)
	{
		CTinyUMLTheme* pUMLTheme = static_cast<CTinyUMLTheme*>(pTheme);

		m_nameHeight = pUMLTheme->nameHeight();
		m_stereotypeHeight = pUMLTheme->stereotypeHeight();
		m_attributeHeight = pUMLTheme->attributeHeight();
		m_methodHeight = pUMLTheme->methodHeight();
		m_compartimentNameHeight = pUMLTheme->compartimentNameHeight();

		m_newAttributeHeight = m_attributeHeight / 2;
		m_newMethodHeight = m_methodHeight / 2;

		m_pNameFont = pUMLTheme->GetNameFont();
		m_pAbstractNameFont = pUMLTheme->abstractNameFont();

		UpdateYCache();
	}
}


CFont* CTinyUMLClass::GetNameFont() const
{
	return m_bAbstract ? m_pAbstractNameFont : m_pNameFont;
}

/**
 * GetNameRect:
 *
 * @return CRect 
 */
CRect CTinyUMLClass::GetNameRect()
{
	CPoint ptOrigin(GetLeft() + GetFolderRect().Width(),GetTop());
	DWORD nWidth=GetRight() - GetLeft() - GetFolderRect().Width();
	CRect r(ptOrigin + CSize(0, m_yCache[1]), CSize(nWidth, m_nameHeight));
	r.DeflateRect(4, 2);
	return r;
}

/**
 * attributesCount:
 *
 * @return long 
 */
long CTinyUMLClass::attributesCount() const
{
	return m_attributes.GetSize();
}

/**
 * UpdateYCache:
 *
 * @return void 
 */
void CTinyUMLClass::UpdateYCache()
{
	long y=0,index = 0;
	m_yCache[index++] = y;
	y += m_bShowStereotype ? m_stereotypeHeight : 0;
	
	// 1: name
	m_yCache[index++] = y;
	y += m_nameHeight;
	
	// 2: attributes compartiment
	m_yCache[index++] = y;
	if(m_bShowAttributes)
		y += m_bShowCompartimentName ? m_compartimentNameHeight : m_compartimentNameHeight / 3;

	// 3 .. : attributes
	for(int i = 0; i < attributesCount(); ++i)
	{
		m_yCache[index++] = y;
		y += m_bShowAttributes ? m_attributeHeight : 0;
	}

	// 3 + Na: new attribute
	m_yCache[index++] = y;
	y += m_bShowAttributes ? m_newAttributeHeight : 0;

	// 4 + Na: methods compartiment
	m_yCache[index++] = y;
	if(m_bShowMethods) y += m_bShowCompartimentName ? m_compartimentNameHeight : m_compartimentNameHeight / 3;

	// 5 + Na .. : methods
	for(i = 0; i < methodsCount(); ++i)
	{
		m_yCache[index++] = y;
		y += m_bShowMethods ? m_methodHeight : 0;
	}
	
	// 5 + Na + Nm: new method
	m_yCache[index++] = y;
	y += m_bShowMethods ? m_newMethodHeight : 0;
	
	// 6 + Na + Nm: bottom
	m_yCache[index++] = y;
	
	AdjustSize();
}

CRect CTinyUMLClass::attributesCompartimentNameRect() const
{
	CPoint ptOrigin(GetLeft(),GetTop());
	DWORD nWidth=GetRight() - GetLeft();
	CRect r(ptOrigin + CSize(0, m_yCache[2]), CSize(nWidth, m_compartimentNameHeight));
	r.DeflateRect(4, 2);
	return r;
}

CRect CTinyUMLClass::methodsCompartimentNameRect() const
{
	CPoint ptOrigin(GetLeft(),GetTop());
	DWORD nWidth=GetRight() - GetLeft();

	long index = 4 + attributesCount();
	CRect r(ptOrigin + CSize(0, m_yCache[index]), CSize(nWidth, m_compartimentNameHeight));
	r.DeflateRect(4, 2);
	return r;
}

CFont* CTinyUMLClass::attributeFont(long index) const
{
	ASSERT(index >= 0 && index < attributesCount());
	
	switch(m_attributes[index].access)
	{
		case Member::public_member:
		case Member::protected_member:
		case Member::private_member:
			return m_pMemberFont;
			
		default:
			ASSERT(false);
			return NULL;
	}
}

CRect CTinyUMLClass::attributeRect(long index) const
{
	ASSERT(index >= 0 && index < attributesCount());
	
	CPoint ptOrigin(GetLeft(),GetTop());
	DWORD nWidth=GetRight() - GetLeft();

	index += 3;
	CRect r(ptOrigin + CSize(0, m_yCache[index]), CSize(nWidth, m_attributeHeight));
	r.DeflateRect(10, 1, 4, 1);
	return r;
}

/**
 * methodsCount:
 *
 * @return long 
 */
long CTinyUMLClass::methodsCount() const
{
	return m_methods.GetSize();
}

/**
 * methodFont:
 *
 * @param index 
 * @return CFont* 
 */
CFont* CTinyUMLClass::methodFont(long index) const
{
	ASSERT(index >= 0 && index < methodsCount());
	
	switch(m_methods[index].access)
	{
		case Method::public_method:
		case Method::protected_method:
		case Method::private_method:
			return m_pMethodFont;
		case Method::abstract_method:
			return m_pAbstractMethodFont;
		default:
			ASSERT(false);
			return NULL;
	}
}

/**
 * methodRect:
 *
 * @param index 
 * @return CRect 
 */
CRect CTinyUMLClass::methodRect(long index) const
{
	ASSERT(index >= 0 && index < methodsCount());
	CPoint ptOrigin(GetLeft(),GetTop());
	DWORD nWidth=GetRight() - GetLeft();

	index += 5 + attributesCount();
	CRect r(ptOrigin + CSize(0, m_yCache[index]), CSize(nWidth, m_methodHeight));
	r.DeflateRect(10, 1, 4, 1);
	return r;
}

/**
 * Serialize:
 *
 * @param ar 
 * @return void 
 */
void CTinyUMLClass::Serialize(CArchive &ar)
{
	CTinyUMLEntity::Serialize(ar);
	
	if(ar.IsStoring())
	{
		ar << long(m_bShowStereotype);
		ar << long(m_bShowCompartimentName);
		ar << long(m_bShowAttributes);
		ar << long(m_bShowMethods);
		
		ar << m_rNote;
		ar << m_stereotype;
		ar << long(m_bAbstract);
		ar << long(m_bFolderOpen);
		ar << m_copySize;
	}
	else
	{
		long _flag;
				
		ar >> _flag; m_bShowStereotype = _flag ? true : false;
		ar >> _flag; m_bShowCompartimentName = _flag ? true : false;
		ar >> _flag; m_bShowAttributes = _flag ? true : false;
		ar >> _flag; m_bShowMethods = _flag ? true : false;
		
		ar >> m_rNote;
		ar >> m_stereotype;
		ar >> _flag; m_bAbstract = _flag ? true : false;
		ar >> _flag; m_bFolderOpen = _flag;
		ar >> m_copySize;
	}
	
	m_attributes.Serialize(ar);
	m_methods.Serialize(ar);
}

template<>
void AFXAPI SerializeElements<CTinyUMLClass::Member>(
	CArchive &ar, CTinyUMLClass::Member *pData, int count)
{
	if(ar.IsStoring()){
		for(int i = 0; i < count; ++i)
		{
			ar << pData[i].type;
			ar << pData[i].name;
			ar << pData[i].access;
			ar << pData[i].property;
		}
	}else{
		for(int i = 0; i < count; ++i)
		{
			ar >> pData[i].type;
			ar >> pData[i].name;
			ar >> pData[i].access;
			ar >> pData[i].property;
		}
	}
}

template<>
void AFXAPI SerializeElements<CTinyUMLClass::Method>(
	CArchive &ar, CTinyUMLClass::Method *pData, int count)
{
	if(ar.IsStoring()){
		for(int i = 0; i < count; ++i)
		{
			ar << pData[i].name;
			ar << pData[i].type;
			ar << pData[i].access;
			ar << pData[i].property;
			ar << pData[i].rComment;
			ar << pData[i].strDefine;
		}
	}else{
		for(int i = 0; i < count; ++i)
		{
			ar >> pData[i].name;
			ar >> pData[i].type;
			ar >> pData[i].access;
			ar >> pData[i].property;
			ar >> pData[i].rComment;
			ar >> pData[i].strDefine;
		}
	}
}

/**
 * stereotypeRect:
 *
 * @return CRect 
 */
CRect CTinyUMLClass::stereotypeRect() const
{
	CPoint ptOrigin(GetLeft(),GetTop());
	DWORD nWidth=GetRight() - GetLeft();

	CRect r(ptOrigin + CSize(0, m_yCache[0] + 2), CSize(nWidth, m_stereotypeHeight));
	r.DeflateRect(4, 2);
	return r;
}

/**
 * AdjustSize:
 *
 * @return void 
 */
void CTinyUMLClass::AdjustSize()
{
	CSize _minSize = MinSize();
	CSize _maxSize = MaxSize();
	
	ASSERT(_minSize.cx <= _maxSize.cx);
	ASSERT(_minSize.cy <= _maxSize.cy);
	
	double width=GetRight() - GetLeft(),height = GetBottom() - GetTop();
	if(width < _minSize.cx)  SetRight(GetLeft() + _minSize.cx);
	if(width > _maxSize.cx)  SetRight(GetLeft() + _maxSize.cx);
	if(height < _minSize.cy) SetBottom(GetTop() + _minSize.cy);
	if(height > _maxSize.cy) SetBottom(GetTop() + _maxSize.cy);
}

/**
 * MinSize:
 *
 * @return CSize 
 */
CSize CTinyUMLClass::MinSize() const
{
	long index = 6 + attributesCount() + methodsCount();
	return CSize(75, m_yCache[index]);
}

/**
 * MaxSize:
 *
 * @return CSize 
 */
CSize CTinyUMLClass::MaxSize() const
{
	return MinSize() + CSize(1000, 1000);
}

/**
 * GetMethodAt:
 *
 * @param nIndex 
 * @return CTinyUMLClass::Method 
 */
CTinyUMLClass::Method CTinyUMLClass::GetMethodAt(const long nIndex)
{
	return (m_methods.GetAt(nIndex));
}

/**
 * GetAttbuteAt:
 *
 * @param nIndex 
 * @return CTinyUMLClass::Member
 */
CTinyUMLClass::Member CTinyUMLClass::GetAttbuteAt(const long nIndex)
{
	return (m_attributes.GetAt(nIndex));
}

/**	\brief	The CTinyUMLClass::ToggleFolder function


	\return	void	
*/
void CTinyUMLClass::ToggleFolder()
{
	//if(true == m_bFolderOpen){
	//	m_copySize.cx = GetRight() - GetLeft();
	//	m_copySize.cy = GetBottom()- GetTop();
	//}
	m_bFolderOpen = !m_bFolderOpen;
	if(m_bFolderOpen){
		UpdateYCache();
		//SetRight(GetLeft() + m_copySize.cx);
		//SetBottom(GetTop() + m_copySize.cy);
	}else{
		CRect rect=GetNameRect();
		rect.InflateRect(4,2); rect.left = GetRect().left;
		SetRect(rect);
	}
}

/**
 * GetFolderRect:
 *
 * @return CRect 
 */
CRect CTinyUMLClass::GetFolderRect()
{
	CRect rect(GetLeft(),GetTop(),GetLeft() + m_sizFolder.cx,GetTop() + m_sizFolder.cy);

	return rect;
}

/**
 * GetHitCode:
 *
 * @param point 
 * @return int 
 */
int CTinyUMLClass::GetHitCode(CPoint point)
{
	int nHitCode=DEHT_NONE;
	
	nHitCode = CTinyUMLEntity::HitTest(point);
	CRect rect=GetFolderRect();rect.DeflateRect(1,1,1,1);
	if(rect.PtInRect(point)) nHitCode = DEHT_FOLDER;

	return nHitCode;
}

/**
 * GetMinimumSize:
 *
 * @return CSize 
 */
CSize CTinyUMLClass::GetMinimumSize() const
{
	long index = 6 + attributesCount() + methodsCount();
	return CSize(125, m_yCache[index]);
}

/**
 * AddMember:
 *
 * @param member 
 * @return int 
 */
int CTinyUMLClass::AddMember(CTinyUMLClass::Member member)
{
	return m_attributes.Add(member);
}

/**
 * AddMethod:
 *
 * @param method 
 * @return int 
 */
int CTinyUMLClass::AddMethod(CTinyUMLClass::Method method)
{
	return m_methods.Add(method);
}

/**
 * SetMethodAt:
 *
 * @param nIndex 
 * @return BOOL 
 */
BOOL CTinyUMLClass::SetMethodAt(CTinyUMLClass::Method method,const long &nIndex)
{
	if((m_methods.GetSize() > 0) && (nIndex < m_methods.GetSize()))
	{
		m_methods.SetAt(nIndex,method);
		return TRUE;
	}
	
	return FALSE;
}

/**
 * SetPathName:
 *
 * @param rPathName 
 * @return void 
 */
void CTinyUMLClass::SetPathName(const CString &rPathName)
{
	m_rPathName = rPathName;
}

CString CTinyUMLClass::GetPathName()
{
	return m_rPathName;
}

bool CTinyUMLClass::IsAbstract()
{
	return m_bAbstract;
}

bool CTinyUMLClass::IsShowAttributes()
{
	return m_bShowAttributes;
}

bool CTinyUMLClass::IsShowMethods()
{
	return m_bShowMethods;
}

bool CTinyUMLClass::IsShowCompartimentName()
{
	return m_bShowCompartimentName;
}

bool CTinyUMLClass::IsShowStereotype()
{
	return m_bShowStereotype;
}

CString CTinyUMLClass::stereotype()
{
	return m_stereotype;
}

long CTinyUMLClass::yCache(const int &at)
{
	return m_yCache[at];
}

const char* CTinyUMLClass::tooltipString() const
{
	return m_rNote.operator const char*();
}
