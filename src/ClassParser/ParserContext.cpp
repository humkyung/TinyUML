// ParserContext.cpp: implementation of the CParserContext class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "ClassParser.h"
#include "ParserContext.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CParserContext::CParserContext(CContextScanner* pFileContext)
{
	m_pFileContext = pFileContext;
	m_enmContextType = CParserContext::UNKNOWN;
	m_rBody = "";
}

CParserContext::~CParserContext()
{

}

/**
 * IsKindOf:
 *
 * @param type 
 * @return bool 
 */
bool CParserContext::IsKindOf(const CParserContext::TYPE& type)
{
	return (m_enmContextType == type) ? true : false;
}

/**
 * GetBody:
 *
 * @return CString 
 */
CString CParserContext::GetBody()
{
	return m_rBody;
}
