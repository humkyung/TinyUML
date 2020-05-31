// MethodContext.h: interface for the CMethodContext class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_METHODCONTEXT_H__BACB2D3F_70D8_4243_ADCA_5132CA9023DD__INCLUDED_)
#define AFX_METHODCONTEXT_H__BACB2D3F_70D8_4243_ADCA_5132CA9023DD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "StdAfx.h"
#include <afxtempl.h>
#include "ParserContext.h"
class AFX_EXT_CLASS CMethodContext : public CParserContext
{
public:
	CString GetType();
	CString GetName();
	void ParseBody();
	CString GetAt(const long& lIndex);
	static CParserContext::TYPE Desc();
	bool Parse();
	CMethodContext(CArray<CString,CString>& tokenEntry,CContextScanner* pContextScanner);
	virtual ~CMethodContext();
private:
	CArray<CString,CString> m_tokenEntry;
};

#endif // !defined(AFX_METHODCONTEXT_H__BACB2D3F_70D8_4243_ADCA_5132CA9023DD__INCLUDED_)
