// MemeberContext.h: interface for the CMemberContext class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MEMBERCONTEXT_H__551EB9FD_DF36_4D5E_AB65_B84BCF6B80C0__INCLUDED_)
#define AFX_MEMBERCONTEXT_H__551EB9FD_DF36_4D5E_AB65_B84BCF6B80C0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "StdAfx.h"
#include <afxtempl.h>
#include "ParserContext.h"

class AFX_EXT_CLASS CMemberContext : public CParserContext
{
public:
	CString GetName();
	CString GetAt(const long& lIndex);
	static CParserContext::TYPE ContextType();
	bool SetTokens(CArray<CString,CString> tempEntry);
	CMemberContext(CContextScanner* pContextScanner);
	virtual ~CMemberContext();
public:
	CString GetType();
	CArray<CString,CString> m_tokenEntry;
};

#endif // !defined(AFX_MEMBERCONTEXT_H__551EB9FD_DF36_4D5E_AB65_B84BCF6B80C0__INCLUDED_)
