// StructContext.cpp: implementation of the CStructContext class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "ClassParser.h"
#include "StructContext.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CStructContext::CStructContext(CContextScanner* pContextScanner) : CParserContext(pContextScanner)
{

}

CStructContext::~CStructContext()
{

}

/**
 * Parse:
 *
 * @return void 
 */
bool CStructContext::Parse()
{
	CString rToken;
	while("" != (rToken = m_pFileContext->GetNextToken()))
	{
		if(rToken == "{") ParseBody();
		if(rToken == ";") break;
	}
	return true;
}

/**
 * IsKeyword:
 *
 * @param rString 
 * @return bool 
 */
bool CStructContext::IsKeyword(const CString &rString)
{
	static const CString rKeyword[]={"struct"};
		
	const int nSiz=sizeof(rKeyword)/sizeof(rKeyword[0]);
	for(int i=0;i < nSiz;i++)
	{
		if(rKeyword[i] == rString) return true;
	}
	
	return false;
}

/**
 * ParseBody:
 *
 * @return void 
 */
void CStructContext::ParseBody()
{
	long lOpened=1L;
	CString rToken;
	while("" != (rToken = m_pFileContext->GetNextToken()))
	{
		if(rToken == "{") lOpened++;
		else if(rToken == "}")
		{
			lOpened--;
			if(0 == lOpened) break;
		}
	}
}
