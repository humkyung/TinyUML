// IncludeContext.h: interface for the CIncludeContext class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_INCLUDECONTEXT_H__DE5BCD32_9258_447E_B165_9D76AF2EFBFB__INCLUDED_)
#define AFX_INCLUDECONTEXT_H__DE5BCD32_9258_447E_B165_9D76AF2EFBFB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "PreprocessorContext.h"
class CIncludeContext : public CPreprocessorContext
{
public:
	bool Parse();
	static bool IsKeyword(const CString& rString);
	CIncludeContext(CContextScanner* pFileContext);
	virtual ~CIncludeContext();

};

#endif // !defined(AFX_INCLUDECONTEXT_H__DE5BCD32_9258_447E_B165_9D76AF2EFBFB__INCLUDED_)
