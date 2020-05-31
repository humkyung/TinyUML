// MethodContext.cpp: implementation of the CMethodContext class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "ClassParser.h"
#include "MethodContext.h"
#include "CommentContext.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CMethodContext::CMethodContext(CArray<CString,CString>& tokenEntry,CContextScanner* pContextScanner)
 : CParserContext(pContextScanner)
{
	m_enmContextType = CParserContext::METHOD_CONTEXT;
	m_tokenEntry.Copy(tokenEntry);
}

CMethodContext::~CMethodContext()
{

}

/**
 * Parse:
 *
 * @return void 
 */
bool CMethodContext::Parse()
{
	bool bRet = false;

	CString rToken;
	while("" != (rToken = m_pFileContext->GetNextToken()))
	{
		if(rToken == ";")
		{
			bRet = true;
			break;
		}
		else if(rToken == "{")
		{
			ParseBody();
			bRet = true;
			break;
		}
		else if(rToken == "}")
		{
			m_pFileContext->PushBack(rToken);
			break;
		}
		else if((rToken == "public") || 
			 (rToken == "protected") || 
			 (rToken == "private"))
		{
			m_pFileContext->PushBack(rToken);
			break;
		}
		else if(CCommentContext::IsKeyword(rToken))
		{
			CCommentContext* pComment=new CCommentContext(m_pFileContext);
			pComment->Parse();
			continue;
		}else	m_tokenEntry.Add(rToken);
	}

	return bRet;
}

/**
 * Desc:
 *
 * @return CParserContext::TYPE 
 */
CParserContext::TYPE CMethodContext::Desc()
{
	return CParserContext::METHOD_CONTEXT;
}

/**
 * GetAt:
 *
 * @param lIndex 
 * @return CString 
 */
CString CMethodContext::GetAt(const long& lIndex)
{
	if(lIndex < m_tokenEntry.GetSize()){
		return m_tokenEntry.GetAt(lIndex);
	}else	return "";
}

/**
 * ParseBody:
 *
 * @return void 
 */
void CMethodContext::ParseBody()
{
	int lBrace=1;
	CString rToken;
	while("" != (rToken = m_pFileContext->GetNextToken()))
	{
		if(rToken == "{") lBrace++;
		else if(rToken == "}")
		{
			lBrace--;
			if(0 == lBrace) break;
		}
	}
}

/**
 * GetName:
 *
 * @return CString 
 */
CString CMethodContext::GetName()
{
	CString rName;

	for(int i=0;(i < m_tokenEntry.GetSize()) && ("(" != m_tokenEntry.ElementAt(i));i++);
	if(i > 0)
	{
		rName = m_tokenEntry.ElementAt(i - 1);
		for(;i < m_tokenEntry.GetSize();i++)
		{
			rName += m_tokenEntry.ElementAt(i) + _T(" ");
		}
	}
	
	return rName;
}

/**
 * GetType:
 *
 * @return CString 
 */
CString CMethodContext::GetType()
{
	for(int i=0;i < m_tokenEntry.GetSize();i++)
	{
		if((i > 1) && ("(" == m_tokenEntry.ElementAt(i)))
		{
			CString rType = m_tokenEntry.ElementAt(i - 2);
			if((_T("virtual") != rType) && (_T("static") != rType))
				return rType;
			else	return CString("");
		}
	}
	
	return CString("");
}
