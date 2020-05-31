// EnumContext.cpp: implementation of the CEnumContext class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "ClassParser.h"
#include "EnumContext.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

/**
 * CEnumContext:
 *
 * @param pContextScanner 
 * @return  
 */
CEnumContext::CEnumContext(CContextScanner* pContextScanner) : CMemberContext(pContextScanner)
{
	m_enmContextType = CParserContext::ENUM_CONTEXT;
}

CEnumContext::~CEnumContext()
{

}

/**
 * Type:
 *
 * @return CParserContext::TYPE 
 */
CParserContext::TYPE ContextType()
{
	return CParserContext::ENUM_CONTEXT;
}

/**
 * Parse:
 *
 * @return bool 
 */
bool CEnumContext::Parse()
{
	int nOpened=0;
	CString rToken;
	while("" != (rToken = m_pFileContext->GetNextToken()))
	{
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
bool CEnumContext::IsKeyword(const CString &rString)
{
	static const CString rKeyword("enum");

	return (rString == rKeyword) ? true : false;
}
