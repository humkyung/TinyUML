// DefineContext.cpp: implementation of the CDefineContext class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "ClassParser.h"
#include "DefineContext.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CDefineContext::CDefineContext(const CString& rType,CContextScanner* pFileContext) : CPreprocessorContext(pFileContext)
{
	m_enmContextType= CPreprocessorContext::DEFINE_CONTEXT;
	m_enmDefineType = CDefineContext::ParseType(rType);
}

CDefineContext::~CDefineContext()
{

}

/**
 * IsKeyword:
 *
 * @param rString 
 * @return bool 
 */
bool CDefineContext::IsKeyword(const CString &rString)
{
	return (CDefineContext::UNKNOWN == CDefineContext::ParseType(rString)) ? false : true;

	return false;
}

/**
 * Parse:
 *
 * @return void 
 */
bool CDefineContext::Parse()
{
	CString rToken;
	
	m_pFileContext->SkipWhiteChars();
	if(CDefineContext::DEFINE == m_enmDefineType){
		CString rLine;
		while(m_pFileContext->GetLine(rLine)){
			m_rBody += rLine;
			if(rLine != "\\n") break;
		}
	}else if((CDefineContext::IFDEF == m_enmDefineType) || 
		 (CDefineContext::IFNDEF == m_enmDefineType)){
		int nOpened=1;

		CString rToken;
		while("" != (rToken = m_pFileContext->GetNextToken())){
			if(rToken == "#"){
				CString temp = m_pFileContext->GetNextToken();
				if((temp == "ifdef") || (temp == "ifndef"))
				{
					nOpened++;
				}
				else if(temp == "endif")
				{
					nOpened--;
					if(0 == nOpened) break;
				}else	m_pFileContext->PushBack(temp);
			}
		}
	}

	return	true;
}

/**
 * ParseType:
 *
 * @param rType 
 * @return CDefineContext::TYPE 
 */
CDefineContext::TYPE CDefineContext::ParseType(const CString &rType)
{
	static const CString rKeyword[]={"#define","#ifdef"};
	static const CDefineContext::TYPE defineType[]={
		CDefineContext::DEFINE,
		CDefineContext::IFDEF,
		CDefineContext::IFNDEF};

	const int nSiz=sizeof(rKeyword)/sizeof(rKeyword[0]);
	for(int i=0;i < nSiz;i++){
		if(rKeyword[i] == rType) return defineType[i];
	}

	return CDefineContext::UNKNOWN;
}

/**
 * Desc:
 *
 * @return CParserContext::TYPE 
 */
CParserContext::TYPE CDefineContext::Desc()
{
	return CParserContext::DEFINE_CONTEXT;
}

/**
 * GetDefineType:
 *
 * @return CDefineContext::TYPE 
 */
CDefineContext::TYPE CDefineContext::GetDefineType()
{
	return m_enmDefineType;
}
