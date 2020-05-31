// ClassContext.cpp: implementation of the CClassContext class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include <assert.h>
#include "ClassParser.h"
#include "ClassContext.h"
#include "MemberContext.h"
#include "MethodContext.h"
#include "TypedefContext.h"
#include "EnumContextFactory.h"
#include "PreprocessorContext.h"
#include "CommentContext.h"
#include "StructContext.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

/**
 * CClassSection:
 *
 * @return  
 */
CClassSection::CClassSection()
{
}

/**
 * CClassSection:
 *
 * @param rSecName 
 * @return  
 */
CClassSection::CClassSection(const CString& rSecName)
{
	m_rSecName = rSecName;
}

/**
 * GetSecName:
 *
 * @return CString 
 */
CString CClassSection::GetSecName()
{
	return m_rSecName;
}

/**
 * Parse:
 *
 * @param pFileContext 
 * @return void 
 */
void CClassSection::Parse(CContextScanner* pFileContext)
{
	assert(pFileContext && "pFileContext is NULL");

	if(pFileContext){
		TCHAR szBuf[2]={0,};
		long lOpened=0L;
		
		CArray<CString,CString> tempEntry;
		CString rToken;
		while((lOpened >= 0) && ("" != (rToken = pFileContext->GetNextToken())))
		{
			m_rBody += rToken;
			if(rToken == "{")
			{
				lOpened++;
			}
			else if(rToken == "}")
			{
				lOpened--;
				if(lOpened < 0)
				{
					pFileContext->PushBack(rToken);
					break;
				}
			}
			else if((rToken == "public") || 
				(rToken == "protected") || 
				(rToken == "private")){
				pFileContext->PushBack(rToken);
				break;
			}
			else if(CPreprocessorContext::IsKeyword(rToken,pFileContext))
			{
				CParserContext* pContext=CPreprocessorContext::CreateContext(pFileContext);
				pContext->Parse();
				m_contextEntry.Add(pContext);
			}
			else if(CCommentContext::IsKeyword(rToken))
			{
				CCommentContext* pComment=new CCommentContext(pFileContext);
				pComment->Parse();
				m_contextEntry.Add(pComment);
			}
			else if(CStructContext::IsKeyword(rToken))
			{
				CStructContext* pContext = new CStructContext(pFileContext);
				if(pContext->Parse())
					m_contextEntry.Add(pContext);
				else	delete pContext;
			}else if(rToken == ";"){
				if(tempEntry.GetSize() > 0)
				{
					CMemberContext* pMember=new CMemberContext(pFileContext); 
					pMember->m_tokenEntry.Copy(tempEntry);
					m_contextEntry.Add(pMember);
					for(int i=tempEntry.GetSize() - 1;i >= 0;i--) tempEntry.RemoveAt(i);
				}
			}
			else if(rToken == "(")
			{
				tempEntry.Add(rToken);
				CMethodContext* pMethod=new CMethodContext(tempEntry,pFileContext);
				if(true == pMethod->Parse()) m_contextEntry.Add(pMethod);
				for(int i=tempEntry.GetSize() - 1;i >= 0;i--) tempEntry.RemoveAt(i);
			}
			else if(CTypedefContext::IsKeyword(rToken))
			{
				CTypedefContext* pTypedef=new CTypedefContext(pFileContext);
				pTypedef->Parse();
				m_contextEntry.Add(pTypedef);
			}
			else if(CEnumContextFactory::IsKeyword(rToken))
			{
				CParserContext* pContext = CEnumContextFactory::Parse(pFileContext);
				m_contextEntry.Add(pContext);
			}
			else
			{
				tempEntry.Add(rToken);
			}
		}
	}
}


/**
 * GetAt:
 *
 * @param lIndex 
 * @return CParserContext* 
 */
CParserContext* CClassSection::GetAt(const long &lIndex)
{
	if(lIndex < m_contextEntry.GetSize()){
		return m_contextEntry.GetAt(lIndex);
	}else	return NULL;
}
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CClassContext::CClassContext(CContextScanner* pFileContext) : CParserContext(pFileContext)
{
	m_rName = "";
	m_enmContextType = CParserContext::CLASS_CONTEXT;
}

/**
 * ~CClassContext:
 *
 * @return  
 */
CClassContext::~CClassContext()
{
	try{
		const nSiz=m_sectionEntry.GetSize();
		if( nSiz > 0){
			for(int i=0;i < nSiz;i++){
				CClassSection* pSection = m_sectionEntry.GetAt(i);
				delete pSection;
			}
		}
	}catch(...){}
}

/**
 * IsKeyword:
 *
 * @param rString 
 * @return bool 
 */
bool CClassContext::IsKeyword(const CString &rString)
{
	static const CString rKeyword="class";

	return (rString == rKeyword) ? true : false;
}

/**
 * Desc:
 *
 * @return CParserContext::TYPE 
 */
CParserContext::TYPE CClassContext::Desc()
{
	return CParserContext::CLASS_CONTEXT;
}

/**
 * Parse:
 *
 * @return void 
 */
bool CClassContext::Parse()
{
	m_pFileContext->SkipWhiteChars();
	m_rName = m_pFileContext->GetNextToken();
	
	CString rToken;
	while("" != (rToken = m_pFileContext->GetNextToken()))
	{
		if("{" == rToken) break;
		else if(":" == rToken)
			ParseBaseClassName();
		else if(";" == rToken) return false;
		else	m_rName = rToken;
	}

	TCHAR szBuf[2]={0,};
	long lOpened=1;
	while((lOpened > 0) && ("" != (rToken = m_pFileContext->GetNextToken())))
	{
		m_rBody += rToken;
		if(rToken == "{")
			lOpened++;
		else if(rToken == "}"){
			lOpened--;
		}else if((rToken == "public") || 
			 (rToken == "protected") || 
			 (rToken == "private")){
			CString rColon = m_pFileContext->GetNextToken();
			assert(rColon == ":");
			CClassSection* pSection=new CClassSection(rToken);
			pSection->Parse(m_pFileContext);
			m_sectionEntry.Add(pSection);
		}else{
			m_pFileContext->PushBack(rToken);
			CClassSection* pSection=new CClassSection("private");
			pSection->Parse(m_pFileContext);
			m_sectionEntry.Add(pSection);
		}
	}

	return true;
}

/**
 * ParseBaseClassName:
 *
 * @return void 
 */
void CClassContext::ParseBaseClassName()
{
	m_baseClass.m_rAccess=m_pFileContext->GetNextToken();
	m_baseClass.m_rName = m_pFileContext->GetNextToken();
}

CString CClassContext::GetName()
{
	return m_rName;
}

/**
 * AppendContext:
 *
 * @param pContext 
 * @return void 
 */
void CClassContext::AppendSection(CClassSection* pSection)
{
	assert(pSection && "pSection is NULL");

	if(pSection) m_sectionEntry.Add(pSection);
}

/**
 * GetSectionAt:
 *
 * @param lIndex 
 * @return CClassSection* 
 */
CClassSection* CClassContext::GetSectionAt(const long &lIndex)
{
	if(lIndex < m_sectionEntry.GetSize()){
		return m_sectionEntry.GetAt(lIndex);
	}else	return NULL;
}

/**
 * IsPublic:
 *
 * @return bool 
 */
bool CClassSection::IsPublic()
{
	return (m_rSecName == _T("public"));
}

/**
 * IsProtected:
 *
 * @return bool 
 */
bool CClassSection::IsProtected()
{
	return (m_rSecName == _T("protected"));
}

/**
 * IsPrivate:
 *
 * @return bool 
 */
bool CClassSection::IsPrivate()
{
	return (m_rSecName == _T("private"));
}
