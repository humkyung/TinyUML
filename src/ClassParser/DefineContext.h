// DefineContext.h: interface for the CDefineContext class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_DEFINECONTEXT_H__D1ED0A1A_E481_44B5_872C_C91C7BDD07AC__INCLUDED_)
#define AFX_DEFINECONTEXT_H__D1ED0A1A_E481_44B5_872C_C91C7BDD07AC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "PreprocessorContext.h"

class AFX_EXT_CLASS CDefineContext : public CPreprocessorContext
{
public:
	typedef enum{
		UNKNOWN = 0xff,
		DEFINE	= 0x00,
		IF	= 0x01,
		IFDEF	= 0x02,
		IFNDEF	= 0x03
	}TYPE;
	
	CDefineContext::TYPE GetDefineType();
	static CParserContext::TYPE Desc();

	bool Parse();
	static bool IsKeyword(const CString& rString);
	CDefineContext(const CString& rType,CContextScanner* pFileContext);
	virtual ~CDefineContext();	
private:
	static CDefineContext::TYPE ParseType(const CString& rType);
	TYPE m_enmDefineType;
};

#endif // !defined(AFX_DEFINECONTEXT_H__D1ED0A1A_E481_44B5_872C_C91C7BDD07AC__INCLUDED_)
