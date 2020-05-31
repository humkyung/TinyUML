// CommentContext.h: interface for the CCommentContext class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_COMMENTCONTEXT_H__10A44527_6B4A_4870_9CEC_A31A9074F863__INCLUDED_)
#define AFX_COMMENTCONTEXT_H__10A44527_6B4A_4870_9CEC_A31A9074F863__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "ParserContext.h"
class CCommentContext : public CParserContext
{
public:
	typedef enum{
		UNKNOWN	   = 0xff,
		ONE_LINE   = 0x00,
		MULTI_LINE = 0x01
	}TYPE;

	virtual bool Parse();
	CCommentContext(CContextScanner* pFileContext);
	virtual ~CCommentContext();
public:
	void SetTypeString(const CString& rString);
	static bool IsKeyword(const CString& rString);
	TYPE m_enmType;
};

#endif // !defined(AFX_COMMENTCONTEXT_H__10A44527_6B4A_4870_9CEC_A31A9074F863__INCLUDED_)
