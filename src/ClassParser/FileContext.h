// FileContext.h: interface for the CFileContext class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_FILECONTEXT_H__1E9887A1_9620_42D4_808B_D722381D077E__INCLUDED_)
#define AFX_FILECONTEXT_H__1E9887A1_9620_42D4_808B_D722381D077E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "StdAfx.h"
#include <afxtempl.h>
#include "ParserContext.h"

class AFX_EXT_CLASS CFileContext  
{
public:
	CParserContext* GetAt(const long& lIndex);
	void AppendContext(CParserContext* pContext);
	void Parse();
	CFileContext(const CString& rFileName);
	virtual ~CFileContext();
private:
	CString m_rFileName;

	CArray<CParserContext*,CParserContext*> m_contextEntry;
};

#endif // !defined(AFX_FILECONTEXT_H__1E9887A1_9620_42D4_808B_D722381D077E__INCLUDED_)
