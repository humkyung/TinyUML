// SourceParser.h: interface for the CSourceParser class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SOURCEPARSER_H__A6855742_C616_4A17_92EB_E44F4B8D39D6__INCLUDED_)
#define AFX_SOURCEPARSER_H__A6855742_C616_4A17_92EB_E44F4B8D39D6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "FileContext.h"
class CSourceParser  
{
public:
	void Parse(const CString& rFileName);
	CSourceParser(CFileContext* pFileContext);
	virtual ~CSourceParser();
private:
	CFileContext* m_pFileContext;
};

#endif // !defined(AFX_SOURCEPARSER_H__A6855742_C616_4A17_92EB_E44F4B8D39D6__INCLUDED_)
