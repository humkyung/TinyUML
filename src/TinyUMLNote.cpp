// TinyUMLNote.cpp: implementation of the CTinyUMLNote class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include <assert.h>
#include <IsDrawCtrlHost.h>
#include "TinyUML.h"
#include "TinyUMLEditor.h"
#include "TinyUMLNote.h"
#include "TinyUMLNoteController.h"
#include "TinyUMLTheme.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

IMPLEMENT_SERIAL(CTinyUMLNote, CTinyUMLEntity, 1)
IS_OBJ_IMPLEMENT_FUNC(CTinyUMLNote , CTinyUMLEntity , "_TINY_UML_NOTE_")
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

/**
 * CTinyUMLNote:
 *
 * @return  
 */
CTinyUMLNote::CTinyUMLNote() : CTinyUMLEntity()
{
	SetTypeString( CTinyUMLNote::TypeString() );
	m_text = "New note";
}

/**
 * CTinyUMLNote:
 *
 * @param pDoc 
 * @param pController 
 * @return  
 */
CTinyUMLNote::CTinyUMLNote(CIsDrawEntContainer* pDoc,CIsControllerObject* pController) : CTinyUMLEntity(pDoc,pController)
{
	SetTypeString( CTinyUMLNote::TypeString() );
	m_text = "New note";
}

/**
 * ~CTinyUMLNote:
 *
 * @return  
 */
CTinyUMLNote::~CTinyUMLNote()
{

}

/**
 * GetTextRect:
 *
 * @return CRect 
 */
CRect CTinyUMLNote::GetTextRect() const
{
	CPoint ptOrigin(GetLeft(),GetTop());
	DWORD nWidth=GetRight() - GetLeft(),nHeight=GetBottom() - GetTop();
	CRect r(ptOrigin, CSize(nWidth - m_cornerWidth, nHeight));
	r.DeflateRect(8, 4, 3, 3);
	return r;
}

/**
 * Serialize:
 *
 * @param ar 
 * @return void 
 */
void CTinyUMLNote::Serialize(CArchive &ar)
{
	CTinyUMLEntity::Serialize(ar);
	
	if(ar.IsStoring())
	{
		ar << m_text;
		m_TextFont.Serialize(ar);
		//ar << m_fillColor;
	}
	else
	{
		ar >> m_text;
		m_TextFont.Serialize(ar);
		//ar >> m_fillColor;
	}
}

CString& CTinyUMLNote::GetText()
{
	return m_text;
}

void CTinyUMLNote::SetText(const CString &rString)
{
	m_text = rString;
}

/**
 * GetNoteFont:
 *
 * @return CFont* 
 */
CFont* CTinyUMLNote::GetTextFont()
{
	return &(m_TextFont);
}

/**
 * Copy:
 *
 * @param pTinyUMLNote 
 * @return void 
 */
void CTinyUMLNote::Copy(CTinyUMLNote *pTinyUMLNote)
{
	assert(pTinyUMLNote && "pTinyUMLNote is NULL");

	if(pTinyUMLNote)
	{
		CTinyUMLEntity::Copy(pTinyUMLNote);

		m_cornerHeight = pTinyUMLNote->m_cornerHeight;
		m_cornerWidth  = pTinyUMLNote->m_cornerWidth;
		//m_fillColor    = pTinyUMLNote->m_fillColor;
		//m_lineColor    = pTinyUMLNote->m_lineColor;
		LOGFONT logFont;
		pTinyUMLNote->m_TextFont.GetLogFont(&logFont);
		m_TextFont.CreateFontIndirect(&logFont);
		//m_shadowColor  = pTinyUMLNote->m_shadowColor;
		m_text         = pTinyUMLNote->m_text;
		//m_textColor    = pTinyUMLNote->m_textColor;
	}
}

/**
 * SetTextFont:
 *
 * @param pFont 
 * @return void 
 */
void CTinyUMLNote::SetTextFont(CFont *pFont)
{
	assert(pFont && "pFont is NULL");

	if(pFont)
	{		
		LOGFONT logFont;
		if(pFont->GetLogFont(&logFont))
		{
			m_TextFont.DeleteObject();
			m_TextFont.CreateFontIndirect(&logFont);
		}
	}
}

/**
 * cornerWidth:
 *
 * @return const long 
 */
const long CTinyUMLNote::cornerWidth() const
{
	return m_cornerWidth;
}

/**
 * cornerHeight:
 *
 * @return const long 
 */
const long CTinyUMLNote::cornerHeight() const
{
	return m_cornerHeight;
}

/**
 * SetupTheme:
 *
 * @param pTheme 
 * @return void 
 */
void CTinyUMLNote::SetupTheme(CTinyDrawTheme *pTheme)
{
	CTinyUMLTheme* pUMLTheme = static_cast<CTinyUMLTheme*>(pTheme);
	if(NULL != pUMLTheme)
	{	
		m_cornerWidth = pUMLTheme->cornerSize();
		m_cornerHeight = pUMLTheme->cornerSize();
		LOGFONT logFont;
		pUMLTheme->noteFont()->GetLogFont(&logFont);
		m_TextFont.CreateFontIndirect(&logFont);
	}
}
