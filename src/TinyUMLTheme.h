// TinyUMLTheme.h: interface for the CTinyUMLTheme class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_TINYUMLTHEME_H__7DB09B3D_DB7F_4D7E_BBE2_021D35E72075__INCLUDED_)
#define AFX_TINYUMLTHEME_H__7DB09B3D_DB7F_4D7E_BBE2_021D35E72075__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "TinyDrawTheme.h"
class CTinyUMLTheme : public CTinyDrawTheme
{
	DECLARE_SERIAL(CTinyUMLTheme)
public:
	CFont * editFont(CFont *pRefFont, double scale) const;
	CFont * multiplicityFont() const;
	CFont * abstractNameFont() const;
	long stereotypeHeight() const;
	COLORREF stereotypeColor() const;
	CFont* stereotypeFont() const;
	
	void SetPackageColor(const COLORREF color);
	COLORREF* GetPackageColor();
	
	void SetShadowColor(const COLORREF& color);
	COLORREF* GetShadowColor();

	COLORREF noteColor() const;
	COLORREF textColor() const;
	CFont* noteFont() const;
	long cornerSize() const;
	bool relativeNodes() const;
	long handleSize() const;
	void SetEndSymbolColor(const COLORREF& color);
	COLORREF* GetEndSymbolColor();
	CFont* relationNameFont() const;
	long methodHeight() const;
	CFont* staticMethodFont() const;
	CFont* abstractMethodFont() const;
	
	CFont* staticAttributeFont() const;
	COLORREF compartimentNameColor() const;
	CFont * compartimentNameFont() const;
	long compartimentNameHeight() const;
	
	CFont * GetMethodFont() const;
	void SetMethodFont(CFont* pFont);
	
	long attributeHeight() const;
	CFont* GetMemberFont() const;
	void SetMemberFont(CFont* pFont);

	long nameHeight() const;
	CFont* GetNameFont() const;
	void SetNameFont(CFont* pFont);
	
	void SetNameColor(const COLORREF& color);
	COLORREF* GetNameColor();
	void SetLineColor(const COLORREF& color);
	COLORREF* GetLineColor();
	void SetAttributeColor(const COLORREF& color);
	COLORREF* GetAttributeColor();
	void SetMethodColor(const COLORREF& color);
	COLORREF* GetMethodColor();
	
	void SetClassBackColor(const COLORREF& color);
	void SetClassTitleColor(const COLORREF& color);
	virtual COLORREF* classColor();
	virtual COLORREF* classTitleColor();
	COLORREF* GetFolderColor();
	void SetFolderColor(const COLORREF& color);
	
	virtual void Serialize(CArchive &ar);
	CTinyUMLTheme();
	virtual ~CTinyUMLTheme();
protected:
	CFont *m_pNameFont;
	CFont *m_pAbstractNameFont;
	CFont *m_pStereotypeFont;
	CFont *m_pNoteFont;
	CFont *m_pMemberFont;
	CFont *m_pStaticAttributeFont;
	CFont *m_pMethodFont;
	CFont *m_pAbstractMethodFont;
	CFont *m_pStaticMethodFont;
	CFont *m_pRelationNameFont;
	CFont *m_pCompartimentNameFont;
	CFont *m_pMultiplicityFont;

	mutable CFont *m_pEditFont;
	
	long m_handleSize;
	long m_cornerSize;
	long m_stereotypeHeight;
	long m_nameHeight;
	long m_attributeHeight;
	long m_methodHeight;
	long m_compartimentNameHeight;
	
	COLORREF m_nameColor;
	COLORREF m_lineColor;
	COLORREF m_packageColor;
	COLORREF m_textColor;
	COLORREF m_noteColor;
	COLORREF m_shadowColor;
	COLORREF m_classColor;
	COLORREF m_classTitleColor;
	COLORREF m_attributeColor;
	COLORREF m_methodColor;
	COLORREF m_compartimentNameColor;
	COLORREF m_stereotypeColor;
	COLORREF m_endSymbolColor;
	COLORREF m_clrFolder;

	bool m_bRelativeNodes;
};

#endif // !defined(AFX_TINYUMLTHEME_H__7DB09B3D_DB7F_4D7E_BBE2_021D35E72075__INCLUDED_)
