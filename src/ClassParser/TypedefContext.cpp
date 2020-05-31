// TypedefContext.cpp: implementation of the CTypedefContext class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "ClassParser.h"
#include "TypedefContext.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CTypedefContext::CTypedefContext(CContextScanner* pContextScanner) : CParserContext(pContextScanner)
{
	m_enmContextType = CParserContext::TYPEDEF_CONTEXT;
}

CTypedefContext::~CTypedefContext()
{

}

/**
 * Desc:
 *
 * @return CParserContext::TYPE 
 */
CParserContext::TYPE CTypedefContext::Desc()
{
	return CParserContext::TYPEDEF_CONTEXT;
}

/**
 * Parse:
 *
 * @return void 
 */
bool CTypedefContext::Parse()
{
	int nOpened=0;
	CString rToken;
	while("" != (rToken = m_pFileContext->GetNextToken())){
		if(rToken == "{")
			nOpened++;
		else if(rToken == "}")
			nOpened--;
		else if((rToken == ";") && (0 == nOpened)) break;
	}

	return true;
}

/**
 * IsKeyword:
 *
 * @param rString 
 * @return bool 
 */
bool CTypedefContext::IsKeyword(const CString &rString)
{
	static const CString rKeyword="typedef";

	return (rString == rKeyword) ? true : false;
}
