// TinyUMLNote.h: interface for the CTinyUMLNote class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_TINYUMLNOTE_H__DEE60051_5FCE_4946_AF16_39B6454F9C3C__INCLUDED_)
#define AFX_TINYUMLNOTE_H__DEE60051_5FCE_4946_AF16_39B6454F9C3C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <IsDrawEntController.h>
#include "TinyUMLEntity.h"
#include "TinyUMLNoteController.h"

class CTinyUMLNote : public CTinyUMLEntity  
{
	DECLARE_SERIAL(CTinyUMLNote)
protected:
	CTinyUMLNote();
public:
	virtual void SetupTheme(CTinyDrawTheme *pTheme);
	const long cornerHeight() const;
	const long cornerWidth() const;
	void SetTextFont(CFont* pFont);
	CFont* GetTextFont();
	void Copy(CTinyUMLNote* pTinyUMLNote);
	void SetText(const CString& rString);
	CString& GetText();
	virtual CRect GetTextRect() const;
	virtual void Serialize(CArchive &ar);
	CTinyUMLNote(CIsDrawEntContainer* pDoc,CIsControllerObject* pController);

	virtual ~CTinyUMLNote();

	IS_OBJ_DECLARE_FUNC()
protected:	
	CString m_text;
	long m_cornerWidth;
	long m_cornerHeight;

	CFont m_TextFont;
private:
	friend class CTinyUMLNoteController;
};

#endif // !defined(AFX_TINYUMLNOTE_H__DEE60051_5FCE_4946_AF16_39B6454F9C3C__INCLUDED_)
