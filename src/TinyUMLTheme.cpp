// TinyUMLTheme.cpp: implementation of the CTinyUMLTheme class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include <assert.h>
#include "TinyUML.h"
#include "TinyUMLTheme.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

IMPLEMENT_SERIAL(CTinyUMLTheme, CTinyDrawTheme, 1)
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

/**
 * CTinyUMLTheme:
 *
 * @return  
 */
CTinyUMLTheme::CTinyUMLTheme()
{
	m_pNameFont = NULL;
	m_pMemberFont = NULL;
	m_pStaticAttributeFont = NULL;
	m_pMethodFont = NULL;
	m_pAbstractMethodFont = NULL;
	m_pStaticMethodFont = NULL;
	m_pCompartimentNameFont = NULL;
	m_pRelationNameFont = NULL;
	m_pEditFont = NULL;
}

/**
 * ~CTinyUMLTheme:
 *
 * @return  
 */
CTinyUMLTheme::~CTinyUMLTheme()
{
	try{
		if(NULL != m_pNameFont) delete m_pNameFont;
		if(NULL != m_pMemberFont) delete m_pMemberFont;
		if(NULL != m_pStaticAttributeFont) delete m_pStaticAttributeFont;
		if(NULL != m_pMethodFont) delete m_pMethodFont;
		if(NULL != m_pAbstractMethodFont) delete m_pAbstractMethodFont;
		if(NULL != m_pStaticMethodFont) delete m_pStaticMethodFont;
		if(NULL != m_pCompartimentNameFont) delete m_pCompartimentNameFont;
		if(NULL != m_pRelationNameFont) delete m_pRelationNameFont;
	}catch(...){}
}

/**
 * Serialize:
 *
 * @param ar 
 * @return void 
 */
void CTinyUMLTheme::Serialize(CArchive &ar)
{
	CTinyDrawTheme::Serialize(ar);
	
	if(ar.IsStoring()){
		ar << m_nameColor;
		ar << m_lineColor;
		ar << m_packageColor;
		ar << m_textColor;
		ar << m_noteColor;
		ar << m_shadowColor;
		ar << m_classColor;
		ar << m_classTitleColor;
		ar << m_attributeColor;
		ar << m_methodColor;
		ar << m_compartimentNameColor;
		ar << m_stereotypeColor;
		ar << m_endSymbolColor;
		ar << m_clrFolder;

		ar << m_handleSize;
		ar << m_cornerSize;
		ar << m_stereotypeHeight;
		ar << m_nameHeight;
		ar << m_attributeHeight;
		ar << m_methodHeight;
		ar << m_compartimentNameHeight;

		m_pNameFont->Serialize(ar);
		m_pMemberFont->Serialize(ar);
		m_pStaticAttributeFont->Serialize(ar);
		m_pMethodFont->Serialize(ar);
		m_pAbstractMethodFont->Serialize(ar);
		m_pStaticMethodFont->Serialize(ar);
		m_pCompartimentNameFont->Serialize(ar);;
		m_pRelationNameFont->Serialize(ar);
		m_pAbstractNameFont->Serialize(ar);
		m_pStereotypeFont->Serialize(ar);
		m_pNoteFont->Serialize(ar);
		m_pMultiplicityFont->Serialize(ar);

		ar << (long)(m_bRelativeNodes);
	}else{
		ar >> m_nameColor;
		ar >> m_lineColor;
		ar >> m_packageColor;
		ar >> m_textColor;
		ar >> m_noteColor;
		ar >> m_shadowColor;
		ar >> m_classColor;
		ar >> m_classTitleColor;
		ar >> m_attributeColor;
		ar >> m_methodColor;
		ar >> m_compartimentNameColor;
		ar >> m_stereotypeColor;
		ar >> m_endSymbolColor;
		ar >> m_clrFolder;

		ar >> m_handleSize;
		ar >> m_cornerSize;
		ar >> m_stereotypeHeight;
		ar >> m_nameHeight;
		ar >> m_attributeHeight;
		ar >> m_methodHeight;
		ar >> m_compartimentNameHeight;

		m_pNameFont = new CFont();
		m_pNameFont->Serialize(ar);
		
		m_pMemberFont = new CFont();
		m_pMemberFont->Serialize(ar);

		m_pStaticAttributeFont = new CFont();
		m_pStaticAttributeFont->Serialize(ar);
		
		m_pMethodFont = new CFont();
		m_pMethodFont->Serialize(ar);
		
		m_pAbstractMethodFont = new CFont();
		m_pAbstractMethodFont->Serialize(ar);
		
		m_pStaticMethodFont = new CFont();
		m_pStaticMethodFont->Serialize(ar);
		
		m_pCompartimentNameFont = new CFont();
		m_pCompartimentNameFont->Serialize(ar);
		
		m_pRelationNameFont = new CFont();
		m_pRelationNameFont->Serialize(ar);

		m_pAbstractNameFont = new CFont;
		m_pAbstractNameFont->Serialize(ar);
		
		m_pStereotypeFont = new CFont;
		m_pStereotypeFont->Serialize(ar);

		m_pNoteFont = new CFont();
		m_pNoteFont->Serialize(ar);

		m_pMultiplicityFont = new CFont();
		m_pMultiplicityFont->Serialize(ar);

		long l;
		ar >> l; m_bRelativeNodes = l ? true : false;
	}
}

/**
 * classColor:
 *
 * @return COLORREF* 
 */
COLORREF* CTinyUMLTheme::classColor()
{
	return &m_classColor;
}

/**
 * classTitleColor:
 *
 * @return COLORREF*
 */
COLORREF* CTinyUMLTheme::classTitleColor()
{
	return &m_classTitleColor;
}

/**
 * GetFolderColor:
 *
 * @return COLORREF* 
 */
COLORREF* CTinyUMLTheme::GetFolderColor()
{
	return (&m_clrFolder);
}

/**
 * SetFolderColor:
 *
 * @param color 
 * @return void 
 */
void CTinyUMLTheme::SetFolderColor(const COLORREF& color)
{
	m_clrFolder = color;
}

void CTinyUMLTheme::SetClassBackColor(const COLORREF& color)
{
	m_classColor = color;
}

void CTinyUMLTheme::SetClassTitleColor(const COLORREF& color)
{
	m_classTitleColor = color;
}

/**
 * SetLineColor:
 *
 * @param color 
 * @return void 
 */
void CTinyUMLTheme::SetLineColor(const COLORREF& color)
{
	m_lineColor = color;
}
/**
 * GetLineColor:
 *
 * @return COLORREF* 
 */
COLORREF* CTinyUMLTheme::GetLineColor()
{
	return (&m_lineColor);
}


/**
 * SetNameColor:
 *
 * @param color 
 * @return void 
 */
void CTinyUMLTheme::SetNameColor(const COLORREF& color)
{
	m_nameColor = color;
}

/**
 * GetNameColor:
 *
 * @return COLORREF* 
 */
COLORREF* CTinyUMLTheme::GetNameColor()
{
	return (&m_nameColor);
}

/**
 * GetNameFont:
 *
 * @return CFont* 
 */
CFont* CTinyUMLTheme::GetNameFont() const
{
	return m_pNameFont;
}

/**
 * SetNameFont:
 *
 * @param pFont 
 * @return void 
 */
void CTinyUMLTheme::SetNameFont(CFont* pFont)
{
	assert(pFont && "pFont is NULL");

	if(pFont)
	{
		if(NULL != m_pNameFont) m_pNameFont->DeleteObject();
		LOGFONT logfont;
		pFont->GetLogFont(&logfont);
		m_pNameFont->CreateFontIndirect(&logfont);
	}
}

long CTinyUMLTheme::nameHeight() const
{
	return m_nameHeight;
}

long CTinyUMLTheme::attributeHeight() const
{
	return m_attributeHeight;
}

long CTinyUMLTheme::compartimentNameHeight() const
{
	return m_compartimentNameHeight;
}

CFont * CTinyUMLTheme::compartimentNameFont() const
{
	return m_pCompartimentNameFont;
}

COLORREF CTinyUMLTheme::compartimentNameColor() const
{
	return m_compartimentNameColor;
}

/**
 * SetAttributeColor:
 *
 * @param color 
 * @return void 
 */
void CTinyUMLTheme::SetAttributeColor(const COLORREF& color)
{
	m_attributeHeight = color;
}

/**
 * GetAttributeColor:
 *
 * @return COLORREF* 
 */
COLORREF* CTinyUMLTheme::GetAttributeColor()
{
	 return (&m_attributeColor);
}

/**
 * GetMemberFont:
 *
 * @return CFont* 
 */
CFont* CTinyUMLTheme::GetMemberFont() const
{
	return m_pMemberFont;
}

/**
 * SetMemberFont:
 *
 * @param pFont 
 * @return void 
 */
void CTinyUMLTheme::SetMemberFont(CFont* pFont)
{
	assert(pFont && "pFont is NULL");

	if(pFont)
	{
		if(NULL != m_pMemberFont) m_pMemberFont->DeleteObject();
		LOGFONT logfont;
		pFont->GetLogFont(&logfont);
		m_pMemberFont->CreateFontIndirect(&logfont);
	}
}

CFont* CTinyUMLTheme::staticAttributeFont() const
{
	return m_pStaticAttributeFont;
}

/**
 * GetMethodFont:
 *
 * @return CFont* 
 */
CFont * CTinyUMLTheme::GetMethodFont() const
{
	return m_pMethodFont;
}

/**
 * SetMethodFont:
 *
 * @param pFont 
 * @return void 
 */
void CTinyUMLTheme::SetMethodFont(CFont* pFont)
{
	assert(pFont && "pFont is NULL");

	if(pFont)
	{
		if(NULL != m_pMethodFont) m_pMethodFont->DeleteObject();
		LOGFONT logfont;
		pFont->GetLogFont(&logfont);
		m_pMethodFont->CreateFontIndirect(&logfont);
	}
}

CFont* CTinyUMLTheme::abstractMethodFont() const
{
	return m_pAbstractMethodFont;
}

CFont* CTinyUMLTheme::staticMethodFont() const
{
	return m_pStaticMethodFont;
}

/**
 * SetMethodColor:
 *
 * @param color 
 * @return void 
 */
void CTinyUMLTheme::SetMethodColor(const COLORREF& color)
{
	m_methodColor = color;
}

/**
 * GetMethodColor:
 *
 * @return COLORREF* 
 */
COLORREF* CTinyUMLTheme::GetMethodColor()
{
	return (&m_methodColor);
}

long CTinyUMLTheme::methodHeight() const
{
	return m_methodHeight;
}

CFont* CTinyUMLTheme::relationNameFont() const
{
	return m_pRelationNameFont;
}

/**
 * SetEndSymbolColor:
 *
 * @param color 
 * @return void 
 */
void CTinyUMLTheme::SetEndSymbolColor(const COLORREF& color)
{
	m_endSymbolColor = color;
}
/**
 * GetEndSymbolColor:
 *
 * @return COLORREF* 
 */
COLORREF* CTinyUMLTheme::GetEndSymbolColor()
{
	return (&m_endSymbolColor);
}

long CTinyUMLTheme::handleSize() const
{
	return m_handleSize;
}

bool CTinyUMLTheme::relativeNodes() const
{
	return m_bRelativeNodes;
}

long CTinyUMLTheme::cornerSize() const
{
	return m_cornerSize;
}

CFont* CTinyUMLTheme::noteFont() const
{
	return m_pNoteFont;
}

COLORREF CTinyUMLTheme::textColor() const
{
	return m_textColor;
}

COLORREF CTinyUMLTheme::noteColor() const
{
	 return m_noteColor;
}

/**
 * SetShadowColor:
 *
 * @param color 
 * @return void 
 */
void CTinyUMLTheme::SetShadowColor(const COLORREF& color)
{
	m_shadowColor = color;
}

/**
 * GetShadowColor:
 *
 * @return COLORREF* 
 */
COLORREF* CTinyUMLTheme::GetShadowColor()
{
	return (&m_shadowColor);
}

/**
 * SetPackageColor:
 *
 * @param color 
 * @return void 
 */
void CTinyUMLTheme::SetPackageColor(const COLORREF color)
{
	m_packageColor = color;
}

COLORREF* CTinyUMLTheme::GetPackageColor()
{
	return (&m_packageColor);
}

CFont* CTinyUMLTheme::stereotypeFont() const
{
	return m_pStereotypeFont;
}

COLORREF CTinyUMLTheme::stereotypeColor() const
{
	 return m_stereotypeColor;
}

long CTinyUMLTheme::stereotypeHeight() const
{
	 return m_stereotypeHeight;
}

CFont * CTinyUMLTheme::abstractNameFont() const
{
	 return m_pAbstractNameFont;
}

CFont * CTinyUMLTheme::multiplicityFont() const
{
	 return m_pMultiplicityFont;
}

CFont * CTinyUMLTheme::editFont(CFont *pRefFont, double scale) const
{
	LOGFONT logFont;
	pRefFont->GetLogFont(&logFont);
	
	logFont.lfHeight = long(logFont.lfHeight * scale);
	
	delete m_pEditFont;
	m_pEditFont = new CFont;
	m_pEditFont->CreateFontIndirect(&logFont);
	return m_pEditFont;
}
