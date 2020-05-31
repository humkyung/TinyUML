// TypedefContext.h: interface for the CTypedefContext class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_TYPEDEFCONTEXT_H__9C0FF41F_13CB_451D_9BDE_1CD306345019__INCLUDED_)
#define AFX_TYPEDEFCONTEXT_H__9C0FF41F_13CB_451D_9BDE_1CD306345019__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "ParserContext.h"
class AFX_EXT_CLASS CTypedefContext : public CParserContext
{
public:
	static bool IsKeyword(const CString& rString);
	bool Parse();
	static CParserContext::TYPE Desc();
	CTypedefContext(CContextScanner* pContextScanner);
	virtual ~CTypedefContext();

};

#endif // !defined(AFX_TYPEDEFCONTEXT_H__9C0FF41F_13CB_451D_9BDE_1CD306345019__INCLUDED_)
