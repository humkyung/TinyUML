// SourceParser.cpp: implementation of the CSourceParser class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "ClassParser.h"
#include "SourceParser.h"
#include "FileContext.h"
#include "DefineContext.h"
#include "ClassContext.h"
#include "StructContext.h"
#include "CommentContext.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

/**
 * CSourceParser:
 *
 * @param pFileContext 
 * @return  
 */
CSourceParser::CSourceParser(CFileContext* pFileContext)
{
	m_pFileContext = pFileContext;
}

CSourceParser::~CSourceParser()
{

}

/**
 * Parse:
 *
 * @param rFileName 
 * @return void 
 */
void CSourceParser::Parse(const CString &rFileName)
{
	CContextScanner contextScanner(rFileName);
	
	CString rToken;
	while("" != (rToken = contextScanner.GetNextToken()))
	{
		if(CDefineContext::IsKeyword(rToken)){
			CDefineContext* pDefine = new CDefineContext(rToken,&contextScanner);
			m_pFileContext->AppendContext(pDefine);
		}else if(CStructContext::IsKeyword(rToken)){
			CStructContext* pContext = new CStructContext(&contextScanner);
			if(pContext->Parse())
				m_pFileContext->AppendContext(pContext);
			else	delete pContext;
		}else if(CClassContext::IsKeyword(rToken)){
			CClassContext* pContext = new CClassContext(&contextScanner);
			if(pContext->Parse())
				m_pFileContext->AppendContext(pContext);
			else	delete pContext;
		}else if(CCommentContext::IsKeyword(rToken)){
			CCommentContext* pComment = new CCommentContext(&contextScanner);
			pComment->SetTypeString(rToken);
			pComment->Parse();
			m_pFileContext->AppendContext(pComment);
		}else if(CPreprocessorContext::IsKeyword(rToken,&contextScanner)){
			CParserContext* pContext=CPreprocessorContext::CreateContext(&contextScanner);
			if(pContext) pContext->Parse();
			m_pFileContext->AppendContext(pContext);
		}
	}

	const int nPos = rFileName.ReverseFind('.');
	CString rCPPFilePath = rFileName.Left(nPos) + _T(".cpp");
}
