// StructContext.h: interface for the CStructContext class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_STRUCTCONTEXT_H__27627E62_7CFD_451D_96EF_4A49AD576DDD__INCLUDED_)
#define AFX_STRUCTCONTEXT_H__27627E62_7CFD_451D_96EF_4A49AD576DDD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "ParserContext.h"
class CStructContext : public CParserContext
{
public:
	void ParseBody();
	static bool IsKeyword(const CString& rString);
	bool Parse();
	CStructContext(CContextScanner* pContextScanner);
	virtual ~CStructContext();

};

#endif // !defined(AFX_STRUCTCONTEXT_H__27627E62_7CFD_451D_96EF_4A49AD576DDD__INCLUDED_)
