// EnumContextFactory.h: interface for the CEnumFactory class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_ENUMCONTEXTFACTORY_H__BC590DFB_D45A_4BB2_B7BB_0113D441EB3F__INCLUDED_)
#define AFX_ENUMCONTEXTFACTORY_H__BC590DFB_D45A_4BB2_B7BB_0113D441EB3F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "ParserContext.h"

class CEnumContextFactory  
{
public:
	static CParserContext* Parse(CContextScanner* pContextScanner);
	static bool IsKeyword(const CString& rString);
	CEnumContextFactory();
	virtual ~CEnumContextFactory();

};

#endif // !defined(AFX_ENUMCONTEXTFACTORY_H__BC590DFB_D45A_4BB2_B7BB_0113D441EB3F__INCLUDED_)
