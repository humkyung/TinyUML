// EnumContextFactory.cpp: implementation of the CEnumFactory class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include <assert.h>
#include "ClassParser.h"
#include "EnumContextFactory.h"
#include "MemberContext.h"
#include "EnumContext.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CEnumContextFactory::CEnumContextFactory()
{

}

CEnumContextFactory::~CEnumContextFactory()
{

}

/**
 * IsKeyword:
 *
 * @param rString 
 * @return bool 
 */
bool CEnumContextFactory::IsKeyword(const CString &rString)
{
	static const CString rKeyword("enum");

	return (rString == rKeyword) ? true : false;
}

/**
 * Parse:
 *
 * @param pContextScanner 
 * @return CParserContext* 
 */
CParserContext* CEnumContextFactory::Parse(CContextScanner* pContextScanner)
{
	assert(pContextScanner && "pContextScanner is NULL");
	CParserContext* pContext=NULL;

	if(pContextScanner)
	{
		int nOpened=0;
		CString rToken;
		while("" != (rToken = pContextScanner->GetNextToken()))
		{
			if(rToken == "{")
			{
				pContext = new CEnumContext(pContextScanner);
				nOpened++;
			}
			else if(rToken == "}")
			{
				nOpened--;
			}
			else if(nOpened > 0)
			{
				/// enum bodis
			}
			else if((rToken == ";") && (0 == nOpened)) break;
			else
			{
				if(NULL == pContext) pContext = new CMemberContext(pContextScanner);
			}
		}
	}

	return pContext;
}