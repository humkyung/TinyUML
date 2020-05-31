// PreprocessorContext.cpp: implementation of the CPreprocessorContext class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include <assert.h>
#include "ClassParser.h"
#include "PreprocessorContext.h"
#include "DefineContext.h"
#include "IncludeContext.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CPreprocessorContext::CPreprocessorContext(CContextScanner* pFileContext) : CParserContext(pFileContext)
{

}

CPreprocessorContext::~CPreprocessorContext()
{

}

static CPreprocessorContext::TYPE _gType=CPreprocessorContext::UNKNOWN;
static CString _gPreprocessor;
/**
 * IsKeyword:
 *
 * @param rString 
 * @param pFileContext 
 * @return bool 
 */
bool CPreprocessorContext::IsKeyword(const CString &rString, CContextScanner *pFileContext)
{
	assert(pFileContext && "pFileContext is NULL");
	bool bRet=false;

	if((rString == "#") && pFileContext){
		CString rToken=rString;
		rToken += pFileContext->GetNextToken();
		
		if(CDefineContext::IsKeyword(rToken)){
			_gType = CPreprocessorContext::DEFINE_PROCESSOR;
			_gPreprocessor = rToken;
			bRet = true;
		}else if(CIncludeContext::IsKeyword(rToken)){
			_gType = CPreprocessorContext::INCLUDE_PROCESSOR;
			bRet = true;
		}

	}

	return bRet;
}

/**
 * CreateContext:
 *
 * @param pFileContext 
 * @return CParserContext* 
 */
CParserContext* CPreprocessorContext::CreateContext(CContextScanner *pFileContext)
{
	assert(pFileContext && "pFileContext is NULL");
	CParserContext* pContext=NULL;

	if(pFileContext){
		switch(_gType){
			case CPreprocessorContext::INCLUDE_PROCESSOR:
				pContext = new CIncludeContext(pFileContext);
				break;
			case CPreprocessorContext::DEFINE_PROCESSOR:
				pContext=new CDefineContext(_gPreprocessor,pFileContext);
				break;
		}
	}

	return pContext;
}
