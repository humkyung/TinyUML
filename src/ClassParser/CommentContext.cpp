// CommentContext.cpp: implementation of the CCommentContext class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "ClassParser.h"
#include "CommentContext.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CCommentContext::CCommentContext(CContextScanner* pFileContext) : CParserContext(pFileContext)
{
	m_enmContextType = CParserContext::COMMENT_CONTEXT;
	m_enmType = CCommentContext::ONE_LINE;
	m_rBody = "";
}

CCommentContext::~CCommentContext()
{

}

/**
 * Parse:
 *
 * @return void 
 */
bool CCommentContext::Parse()
{
	if(CCommentContext::ONE_LINE == m_enmType)
	{
		m_pFileContext->GetLine(m_rBody);
	}
	else
	{
		CString rToken;
		while("" != (rToken = m_pFileContext->GetNextToken()))
		{
			if(rToken == "*")
			{
				if("/" == (rToken = m_pFileContext->GetNextToken()))
				{
					break;
				}else	m_pFileContext->PushBack(rToken);
			}
		}

		if("/" != rToken) return false;
	}

	return true;
}

/**
 * IsKeyword:
 *
 * @param rString 
 * @return bool 
 */
bool CCommentContext::IsKeyword(const CString &rString)
{
	static const char* pKeywords[]={"//","/*","*/"};
	bool bRet=false;

	const int nSiz=sizeof(pKeywords)/sizeof(pKeywords[0]);
	for(int i=0;i < nSiz;i++){
		if(rString == pKeywords[i]){
			bRet = true;
			break;
		}
	}

	return bRet;
}

/**
 * SetTypeString:
 *
 * @param rString 
 * @return void 
 */
void CCommentContext::SetTypeString(const CString &rString)
{
	if(rString == "//")
		m_enmType = CCommentContext::ONE_LINE;
	else if(rString == "/*")
		m_enmType = CCommentContext::MULTI_LINE;
	else	m_enmType = CCommentContext::UNKNOWN;
}
