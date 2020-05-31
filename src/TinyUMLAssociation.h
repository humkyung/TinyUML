// TinyUMLAssociation.h: interface for the CTinyUMLAssociation class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_TINYUMLASSOCIATION_H__DD28489F_A652_478E_90FB_392BD6202F1F__INCLUDED_)
#define AFX_TINYUMLASSOCIATION_H__DD28489F_A652_478E_90FB_392BD6202F1F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "TinyUMLRelation.h"
#include "TinyUMLAssociationController.h"

class CTinyUMLAssociation : public CTinyUMLRelation  
{
	DECLARE_SERIAL(CTinyUMLAssociation)
protected:
	CTinyUMLAssociation();
public:
	CString GetDestMultiplicity() const;
	CString GetSrcMultiplicity() const;
	bool IsShowDestMultiplicity() const;
	bool IsShowSrcMultiplicity() const;
	bool IsNavigable() const;
	bool IsAggregation() const;
	CFont* GetMultiplicityFont() const;
	COLORREF GetFillColor() const;
	virtual void Serialize(CArchive &ar);
	virtual int GetHitCode(CPoint point);
	virtual void OnNotify(const IS_NOTIFY& notify);
	virtual void SetupTheme(CTinyDrawTheme* pTheme);
	virtual CRect destMultiplicityRect() const;
	virtual CRect srcMultiplicityRect() const;

	CTinyUMLAssociation(CIsDrawEntContainer* pDoc,CIsControllerObject* pController,
		const CPoint &point, CTinyUMLEntity *pEnt,bool bAggregation, bool bNavigable);
	virtual ~CTinyUMLAssociation();

	IS_OBJ_DECLARE_FUNC()
protected:
	COLORREF m_fillColor;
	CFont *m_pMultiplicityFont;

	bool m_bAggregation;
	bool m_bNavigable;
	CString m_srcMultiplicity;
	CString m_destMultiplicity;
	bool m_bShowSrcMultiplicity;
	bool m_bShowDestMultiplicity;
	CSize m_srcMultiplicityOffset;
	CSize m_destMultiplicityOffset;
private:
	friend class CTinyUMLAssociationController;
};

#endif // !defined(AFX_TINYUMLASSOCIATION_H__DD28489F_A652_478E_90FB_392BD6202F1F__INCLUDED_)
