// TinyUMLGeneralization.h: interface for the CTinyUMLGeneralization class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_TINYUMLGENERALIZATION_H__DFE2DB31_DF40_4B44_89EB_92DAD6F1AC70__INCLUDED_)
#define AFX_TINYUMLGENERALIZATION_H__DFE2DB31_DF40_4B44_89EB_92DAD6F1AC70__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "TinyUMLRelation.h"
#include "TinyUMLGeneralizationController.h"

class CTinyUMLGeneralization : public CTinyUMLRelation  
{
	DECLARE_SERIAL(CTinyUMLGeneralization)
protected:
	CTinyUMLGeneralization();
public:
	COLORREF GetFillColor() const;
	virtual void Copy(CTinyUMLGeneralization* p);
	virtual void Serialize(CArchive &ar);
	virtual int GetHitCode(CPoint point);
	virtual void OnNotify(const IS_NOTIFY& notify);
	virtual void SetupTheme(CTinyDrawTheme *pTheme);
	CTinyUMLGeneralization(CIsDrawEntContainer* pDoc,CIsControllerObject* pController,
		const CPoint &point, CTinyUMLEntity *pEnt,bool bRealize);
	virtual ~CTinyUMLGeneralization();

	IS_OBJ_DECLARE_FUNC()
protected:
	virtual void DrawSelectionMarkers( CDC* dc, CRect rect ) const;

	bool m_bRealize;
	COLORREF m_fillColor;
private:
	friend class CTinyUMLGeneralizationController;
};

#endif // !defined(AFX_TINYUMLGENERALIZATION_H__DFE2DB31_DF40_4B44_89EB_92DAD6F1AC70__INCLUDED_)
