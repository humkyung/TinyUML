// IncludeContext.cpp: implementation of the CIncludeContext class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "ClassParser.h"
#include "IncludeContext.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CIncludeContext::CIncludeContext(CContextScanner* pFileContext) : CPreprocessorContext(pFileContext)
{

}

CIncludeContext::~CIncludeContext()
{

}

/**
 * IsKeyword:
 *
 * @param rString 
 * @return bool 
 */
bool CIncludeContext::IsKeyword(const CString &rString)
{
	static const CString rKeyword("#include");
	
	const int nSiz=sizeof(rKeyword)/sizeof(rKeyword[0]);
	for(int i=0;i < nSiz;i++)
	{
		if(rKeyword[i] == rString) return true;
	}
	
	return false;
}

/**
 * Parse:
 *
 * @return void 
 */
bool CIncludeContext::Parse()
{
	CString rToken;
	
	m_pFileContext->SkipWhiteChars();
	m_rBody=m_pFileContext->GetNextToken();
	if("\"" == m_rBody)
	{
		TCHAR szBuf[2]={0,};
		while(m_pFileContext->Read(szBuf,1) > 0)
		{
			m_rBody += szBuf[0];
			if('\"' == szBuf[0]) break;
		}
	}
	else if("<" == m_rBody)
	{
		TCHAR szBuf[2]={0,};
		while(m_pFileContext->Read(szBuf,1) > 0)
		{
			m_rBody += szBuf[0];
			if('>' == szBuf[0]) break;
		}
	}

	return true;
}
