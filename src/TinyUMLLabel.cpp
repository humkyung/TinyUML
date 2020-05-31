#include "StdAfx.h"
#include "TinyUMLLabelController.h"
#include "TinyUMLLabel.h"

IMPLEMENT_SERIAL(CTinyUMLLabel,CIsDrawEntity,1)
IS_OBJ_IMPLEMENT_FUNC(CTinyUMLLabel , CIsDrawEntity , "_TINY_UML_LABEL_")
//////////////////////////////////////////////////////////////////////////

/**
 * CTinyUMLLabel:
 *
 * @return  
 */
CTinyUMLLabel::CTinyUMLLabel() : CIsDrawEntity()
{
	SetTypeString ( CTinyUMLLabel::TypeString() );
	m_rName = _T("Label");
	CRect rect=GetRect();

	m_pLabelFont = new CFont();
	VERIFY(m_pLabelFont->CreateFont(16, 0, 0, 0, FW_BOLD, false, false, false,
		ANSI_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY,
		DEFAULT_PITCH, "Arial"));
}

/**
 * CTinyUMLLabel:
 *
 * @param pDoc 
 * @param pController 
 * @return  
 */
CTinyUMLLabel::CTinyUMLLabel(CIsDrawEntContainer* pDoc,CIsControllerObject* pController) : CIsDrawEntity(pDoc,pController)
{
	SetTypeString( CTinyUMLLabel::TypeString() );
	m_rName = _T("Label");

	m_pLabelFont = new CFont();
	VERIFY(m_pLabelFont->CreateFont(16, 0, 0, 0, FW_BOLD, false, false, false,
		ANSI_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY,
		DEFAULT_PITCH, "Arial"));
}

CTinyUMLLabel::~CTinyUMLLabel()
{
	try
	{
		if(NULL != m_pLabelFont) delete m_pLabelFont;
	}
	catch(...)
	{
	}
}

/**
 * SetRect:
 *
 * @param rect 
 * @return void 
 */
void CTinyUMLLabel::SetRect( CRect rect )
{
	CIsDrawEntity::SetRect(rect);
	
	LOGFONT logfont;
	m_pLabelFont->GetLogFont(&logfont);
	//logfont.lfHeight = rect.Height();
	//m_pLabelFont->CreateFontIndirect(&logfont);
}

/**
 * Copy:
 *
 * @param obj 
 * @return void 
 */
void CTinyUMLLabel::Copy( CIsDrawEntity* obj )
{
	CIsDrawEntity::Copy(obj);
	m_pLabelFont = static_cast<CTinyUMLLabel*>(obj)->m_pLabelFont;
}

/**
 * SetRect:
 *
 * @param left 
 * @param top 
 * @param right 
 * @param bottom 
 * @return void 
 */
void CTinyUMLLabel::SetRect(const double &left, const double &top, const double &right, const double &bottom)
{
	CIsDrawEntity::SetRect(left,top,right,bottom);

	CRect entRect=GetRect();
	delete m_pLabelFont;
	
	m_pLabelFont = new CFont();
	VERIFY(m_pLabelFont->CreateFont(entRect.Height(), entRect.Width()/(m_rName.GetLength()+1), 0, 0, FW_BOLD, false, false, false,
	ANSI_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY,
	DEFAULT_PITCH, "Arial"));
}

/**
 * GetFont:
 *
 * @return CFont* 
 */
CFont* CTinyUMLLabel::GetFont()
{
	return m_pLabelFont;
}

/**
 * Serialize:
 *
 * @param ar 
 * @return void 
 */
void CTinyUMLLabel::Serialize(CArchive &ar)
{
	CIsDrawEntity::Serialize(ar);
	
	if(ar.IsStoring())
	{	
		m_pLabelFont->Serialize(ar);
	}
	else
	{
		delete m_pLabelFont;
		m_pLabelFont = new CFont();
		m_pLabelFont->Serialize(ar);
	}
}
