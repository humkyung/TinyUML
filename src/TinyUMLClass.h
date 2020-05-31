// TinyUMLClass.h: interface for the CTinyUMLClass class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_TINYUMLCLASS_H__4E8D0D54_6B22_4CAA_9166_08BFE4E7EF27__INCLUDED_)
#define AFX_TINYUMLCLASS_H__4E8D0D54_6B22_4CAA_9166_08BFE4E7EF27__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <afxtempl.h>
#include "TinyUMLEntity.h"
#include "TinyUMLClassController.h"
#include "TinyUMLTheme.h"

#define DEHT_FOLDER	11

class CTinyUMLClass : public CTinyUMLEntity  
{
	DECLARE_SERIAL(CTinyUMLClass)
protected:
	CTinyUMLClass();
public:
	struct Member
	{
		enum Access 
		{ 
			public_member, 
			protected_member , 
			private_member 
		};
		enum Property
		{
			static_property = 0x01
		};

		CString type;
		CString name;
		long access;
		long property;
	};

	struct Method
	{
		enum Access
		{ 
			public_method, 
			protected_method , 
			private_method , 
			abstract_method
		};
		enum Property
		{
			virtual_property= 0x01,
			inline_property	= 0x02,
			const_property	= 0x04,
			pure_property	= 0x08,
			static_property = 0x10
		};
		
		CString type;
		CString name;
		long access;
		long property;
		CString rComment;
		CString strDefine;
	};

	CTinyUMLClass(CIsDrawEntContainer* pDoc,CIsControllerObject* pController,bool bInterface=false);
	virtual ~CTinyUMLClass();
public:
	virtual const char* tooltipString() const;
	long yCache(const int& at);
	CString stereotype();
	virtual CRect stereotypeRect() const;
	virtual CRect attributesCompartimentNameRect() const;
	virtual CRect attributeRect(long index) const;
	virtual CRect methodRect(long index) const;
	virtual CRect methodsCompartimentNameRect() const;
	virtual void SetupTheme(CTinyDrawTheme* pTheme);
	bool IsShowStereotype();
	bool IsShowCompartimentName();
	bool IsShowMethods();
	bool IsShowAttributes();
	bool IsAbstract();
	CString GetPathName();
	void SetPathName(const CString& rPathName);
	int AddMember(CTinyUMLClass::Member member);
	int AddMethod(CTinyUMLClass::Method method);
	BOOL SetMethodAt(CTinyUMLClass::Method method,const long& nIndex);
	virtual CSize GetMinimumSize() const;
	virtual int GetHitCode( CPoint point );
	void ToggleFolder();
	CTinyUMLClass::Member GetAttbuteAt(const long nIndex);
	virtual long attributesCount() const;
	CTinyUMLClass::Method GetMethodAt(const long nIndex);
	virtual long methodsCount() const;
	virtual CRect GetNameRect();
	virtual CFont* GetNameFont() const;
	virtual void Serialize(CArchive &ar);
	
	void Copy(CTinyUMLClass* pTinyUMLClass);
	CTinyUMLClass(const CTinyUMLClass& TinyUMLClass);

	IS_OBJ_DECLARE_FUNC()
protected:
	virtual CSize MaxSize() const;
	virtual CSize MinSize() const;
	virtual void AdjustSize();
	virtual CFont* methodFont(long index) const;
	virtual CFont* attributeFont(long index) const;
	CString m_rNote;
	void UpdateYCache();

	bool m_bFolderOpen;
	bool m_bShowStereotype;
	bool m_bShowAttributes;
	bool m_bShowMethods;
	bool m_bShowCompartimentName;
	bool m_bAbstract;

	CString m_stereotype;
	
	CArray<Member, const Member &> m_attributes;
	CArray<Method, const Method &> m_methods;
	
	CFont *m_pStereotypeFont;
	CFont *m_pNameFont;
	CFont *m_pMemberFont;
	CFont *m_pStaticAttributeFont;
	CFont *m_pMethodFont;
	CFont *m_pAbstractMethodFont;
	CFont *m_pAbstractNameFont;
	CFont *m_pStaticMethodFont;
	CFont *m_pCompartimentNameFont;
	
	long m_nameHeight;
	long m_stereotypeHeight;
	long m_attributeHeight;
	long m_methodHeight;
	long m_compartimentNameHeight;
	
	long m_newAttributeHeight;
	long m_newMethodHeight;
	
	COLORREF* m_titleColor;
	COLORREF* m_pFillColor;
	COLORREF* m_lineColor;
	COLORREF* m_shadowColor;
	COLORREF* m_nameColor;
	COLORREF* m_attributeColor;
	COLORREF* m_methodColor;
	COLORREF m_compartimentNameColor;
	COLORREF m_stereotypeColor;
	COLORREF* m_pClrFolder;

	long m_yCache[128];
private:
	CRect GetFolderRect();
	
	CString m_rPathName;
	CSize m_sizFolder;
	CSize m_copySize;

	friend class CTinyUMLClassController;
};

template<>
void AFXAPI SerializeElements<CTinyUMLClass::Member>(
	CArchive &ar, CTinyUMLClass::Member *pData, int count);

template<>
void AFXAPI SerializeElements<CTinyUMLClass::Method>(
	CArchive &ar, CTinyUMLClass::Method *pData, int count);

#endif // !defined(AFX_TINYUMLCLASS_H__4E8D0D54_6B22_4CAA_9166_08BFE4E7EF27__INCLUDED_)
