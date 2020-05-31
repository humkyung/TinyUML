// EnumContext.h: interface for the CEnumContext class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_ENUMCONTEXT_H__FCD7F50A_711B_448A_9F03_F9F46E175B88__INCLUDED_)
#define AFX_ENUMCONTEXT_H__FCD7F50A_711B_448A_9F03_F9F46E175B88__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "MemberContext.h"

class AFX_EXT_CLASS CEnumContext : public CMemberContext
{
public:
	static bool IsKeyword(const CString& rString);
	bool Parse();
	static CParserContext::TYPE ContextType();
	CEnumContext(CContextScanner* pContextScanner);
	virtual ~CEnumContext();

};

#endif // !defined(AFX_ENUMCONTEXT_H__FCD7F50A_711B_448A_9F03_F9F46E175B88__INCLUDED_)
