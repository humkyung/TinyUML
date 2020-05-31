// ParserContext.h: interface for the CParserContext class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PARSERCONTEXT_H__00DEFA1A_6A56_4739_B47C_CF91F122699C__INCLUDED_)
#define AFX_PARSERCONTEXT_H__00DEFA1A_6A56_4739_B47C_CF91F122699C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "StdAfx.h"
#include "ContextScanner.h"
class AFX_EXT_CLASS CParserContext  
{
public:
	CString GetBody();
	typedef enum{
		UNKNOWN		= 0xff,
		CLASS_CONTEXT	= 0x00,
		MEMBER_CONTEXT	= 0x01,
		METHOD_CONTEXT	= 0x02,
		ENUM_CONTEXT	= 0x03,
		TYPEDEF_CONTEXT	= 0x04,
		COMMENT_CONTEXT	= 0x05,
		DEFINE_CONTEXT	= 0x06
	}TYPE;

	virtual bool IsKindOf(const CParserContext::TYPE& type);
	virtual bool Parse(){return true;};
	CParserContext(CContextScanner* pFileContext);
	virtual ~CParserContext();
protected:
	CContextScanner* m_pFileContext;
	TYPE m_enmContextType;
	CString m_rBody;
};

#endif // !defined(AFX_PARSERCONTEXT_H__00DEFA1A_6A56_4739_B47C_CF91F122699C__INCLUDED_)
