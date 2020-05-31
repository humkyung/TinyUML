// PreprocessorContext.h: interface for the CPreprocessorContext class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PREPROCESSORCONTEXT_H__CF0C7982_712F_4AD8_92C0_0EDD9A325E68__INCLUDED_)
#define AFX_PREPROCESSORCONTEXT_H__CF0C7982_712F_4AD8_92C0_0EDD9A325E68__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "ParserContext.h"

class AFX_EXT_CLASS CPreprocessorContext : public CParserContext
{
public:
	typedef enum{
		UNKNOWN		 = 0xff,
		INCLUDE_PROCESSOR= 0x00,
		DEFINE_PROCESSOR = 0x01
	}TYPE;
	
	static CParserContext* CreateContext(CContextScanner* pFileContext);
	static bool IsKeyword(const CString& rString,CContextScanner* pFileContext);
	CPreprocessorContext(CContextScanner* pFileContext);
	virtual ~CPreprocessorContext();
};

#endif // !defined(AFX_PREPROCESSORCONTEXT_H__CF0C7982_712F_4AD8_92C0_0EDD9A325E68__INCLUDED_)
