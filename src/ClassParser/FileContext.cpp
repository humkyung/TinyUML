// FileContext.cpp: implementation of the CFileContext class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include <assert.h>
#include "FileContext.h"
#include "SourceParser.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

/**
 * CFileContext:
 *
 * @param rFileName 
 * @return  
 */
CFileContext::CFileContext(const CString& rFileName)
{
	m_rFileName = rFileName;	
}

/**
 * ~CFileContext:
 *
 * @return  
 */
CFileContext::~CFileContext()
{
	try{
		int nSiz=m_contextEntry.GetSize();
		if( nSiz > 0){
			for(int i=0;i < nSiz;i++){
				CParserContext* pContext = m_contextEntry.GetAt(i);
				delete pContext;
			}
		}
	}catch(...){}
}

/**
 * Parse:
 *
 * @return void 
 */
void CFileContext::Parse()
{
	CSourceParser parser(this);
	parser.Parse(m_rFileName);
}

/**
 * AppendContext:
 *
 * @param pContext 
 * @return void 
 */
void CFileContext::AppendContext(CParserContext *pContext)
{
	assert(pContext && "pContext is NULL");

	m_contextEntry.Add(pContext);
}

/**
 * GetAt:
 *
 * @param lIndex 
 * @return CParserContext* 
 */
CParserContext* CFileContext::GetAt(const long &lIndex)
{
	if(lIndex < m_contextEntry.GetSize()){
		return m_contextEntry.GetAt(lIndex);
	}else	return NULL;
}
