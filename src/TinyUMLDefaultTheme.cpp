// PresentationTheme.cpp: implementation of the CTinyUMLDefaultTheme class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "TinyUML.h"
#include "TinyUMLDefaultTheme.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

IMPLEMENT_SERIAL(CTinyUMLDefaultTheme, CTinyUMLTheme, 1)
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CTinyUMLDefaultTheme::CTinyUMLDefaultTheme()
{
	//////////////////////////////////////////////////////////////////////////
	m_pNameFont = new CFont();
	VERIFY(m_pNameFont->CreateFont(16, 0, 0, 0, FW_BOLD, false, false, false,
		ANSI_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY,
		DEFAULT_PITCH, "Arial"));
	
	m_pAbstractNameFont = new CFont();
	VERIFY(m_pAbstractNameFont->CreateFont(16, 0, 0, 0, FW_BOLD, true, false, false,
		ANSI_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY,
		DEFAULT_PITCH, "Arial"));
	
	m_pStereotypeFont = new CFont();
	VERIFY(m_pStereotypeFont->CreateFont(16, 0, 0, 0, FW_NORMAL, false, false, false,
		ANSI_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY,
		DEFAULT_PITCH, "Arial"));
	
	m_pNoteFont = new CFont();
	VERIFY(m_pNoteFont->CreateFont(14, 0, 0, 0, FW_NORMAL, false, false, false,
		ANSI_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY,
		DEFAULT_PITCH, "Arial"));
	
	m_pMemberFont = new CFont();
	VERIFY(m_pMemberFont->CreateFont(16, 0, 0, 0, FW_NORMAL, false, false, false,
		ANSI_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY,
		DEFAULT_PITCH, "Arial"));

	m_pStaticAttributeFont = new CFont();
	VERIFY(m_pStaticAttributeFont->CreateFont(16, 0, 0, 0, FW_NORMAL, false, true, false,
		ANSI_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY,
		DEFAULT_PITCH, "Arial"));

	m_pMethodFont = new CFont();
	VERIFY(m_pMethodFont->CreateFont(16, 0, 0, 0, FW_NORMAL, false, false, false,
		ANSI_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY,
		DEFAULT_PITCH, "Arial"));

	m_pAbstractMethodFont = new CFont();
	VERIFY(m_pAbstractMethodFont->CreateFont(16, 0, 0, 0, FW_NORMAL, true, false, false,
		ANSI_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY,
		DEFAULT_PITCH, "Arial"));

	m_pStaticMethodFont = new CFont();
	VERIFY(m_pStaticMethodFont->CreateFont(16, 0, 0, 0, FW_NORMAL, false, true, false,
		ANSI_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY,
		DEFAULT_PITCH, "Arial"));
	
	m_pCompartimentNameFont = new CFont();
	VERIFY(m_pCompartimentNameFont->CreateFont(14, 0, 0, 0, FW_BOLD, false, false, false,
		ANSI_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY,
		DEFAULT_PITCH, "Arial"));

	m_pRelationNameFont = new CFont();
	VERIFY(m_pRelationNameFont->CreateFont(14, 0, 0, 0, FW_NORMAL, false, false, false,
		ANSI_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY,
		DEFAULT_PITCH, "Arial"));

	m_pMultiplicityFont = new CFont();
	VERIFY(m_pMultiplicityFont->CreateFont(14, 0, 0, 0, FW_NORMAL, false, false, false,
		ANSI_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY,
		DEFAULT_PITCH, "Arial"));
	//////////////////////////////////////////////////////////////////////////
		
	m_handleSize = 4;
	m_cornerSize = 20;
	m_nameHeight = 20;
	m_stereotypeHeight = 20;
	m_attributeHeight = 20;
	m_methodHeight = 20;
	m_compartimentNameHeight = 16;

	m_paperColor = RGB(224, 224, 224);
	m_gridColor = RGB(100, 100, 100);
	
	// normal theme
	m_nameColor = RGB(0, 0, 0);
	m_lineColor = RGB(0, 0, 0);
	m_packageColor = RGB(255, 255, 200);
	m_textColor = RGB(0, 0, 0);
	m_noteColor = RGB(200, 255, 255);
	m_shadowColor = RGB(200, 200, 200);
	m_classColor = RGB(200, 255, 200);
	m_classTitleColor = RGB(248,249,217);
	m_attributeColor = RGB(100, 0, 0);
	m_methodColor = RGB(0, 0, 100);
	m_compartimentNameColor = RGB(128, 128, 128);
	m_stereotypeColor = RGB(0, 0, 0);
	m_endSymbolColor = RGB(224, 224, 224);
	m_clrFolder = RGB(245,245,220);
}

CTinyUMLDefaultTheme::~CTinyUMLDefaultTheme()
{
}

/**
 * Serialize:
 *
 * @param ar 
 * @return void 
 */
void CTinyUMLDefaultTheme::Serialize(CArchive &ar)
{
	CTinyUMLTheme::Serialize(ar);
}