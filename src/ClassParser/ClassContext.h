// ClassContext.h: interface for the CClassContext class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CLASSCONTEXT_H__D047B26D_B0F3_4C0D_A217_1A3421832480__INCLUDED_)
#define AFX_CLASSCONTEXT_H__D047B26D_B0F3_4C0D_A217_1A3421832480__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "StdAfx.h"
#include <afxtempl.h>
#include "ParserContext.h"

class AFX_EXT_CLASS CClassSection
{
public:
	CParserContext* GetAt(const long& lIndex);
	CString GetSecName();
	void Parse(CContextScanner* pFileContext);
	CClassSection(const CString& rSecName);
	CClassSection();
public:
	bool IsPrivate();
	bool IsProtected();
	bool IsPublic();
	CString m_rSecName;
	CString m_rBody;
private:
	CArray<CParserContext*,CParserContext*> m_contextEntry;
};

class AFX_EXT_CLASS CClassContext : public CParserContext
{
public:
	CClassSection* GetSectionAt(const long& lIndex);
	void AppendSection(CClassSection* pClassSection);
	CString GetName();
	typedef struct {
		CString m_rAccess;
		CString m_rName;
	}BaseClass;

	bool Parse();
	static CParserContext::TYPE Desc();
	static bool IsKeyword(const CString& rString);
	CClassContext(CContextScanner* pFileContext);
	virtual ~CClassContext();
private:
	void ParseBaseClassName();
	CString m_rName;
	BaseClass m_baseClass;
	
	CArray<CClassSection*,CClassSection*> m_sectionEntry;
};

#endif // !defined(AFX_CLASSCONTEXT_H__D047B26D_B0F3_4C0D_A217_1A3421832480__INCLUDED_)
