// MemberContext.cpp: implementation of the CMemberContext class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "ClassParser.h"
#include "MemberContext.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

/**
 * CMemberContext:
 *
 * @param pContextScanner 
 * @return  
 */
CMemberContext::CMemberContext(CContextScanner* pContextScanner) : CParserContext(pContextScanner)
{
	m_enmContextType = CParserContext::MEMBER_CONTEXT;
}

CMemberContext::~CMemberContext()
{

}

/**
 * Desc:
 *
 * @return CParserContext::TYPE 
 */
CParserContext::TYPE CMemberContext::ContextType()
{
	return CParserContext::MEMBER_CONTEXT;
}

/**
 * GetAt:
 *
 * @param lIndex 
 * @return CString 
 */
CString CMemberContext::GetAt(const long& lIndex)
{
	if(lIndex < m_tokenEntry.GetSize()){
		return m_tokenEntry.GetAt(lIndex);
	}else	return "";
}

/**
 * operator=:
 *
 * @param tempEntry 
 * @return bool 
 */
bool CMemberContext::SetTokens(CArray<CString,CString> tempEntry)
{
	m_tokenEntry.Copy(tempEntry);
	return true;
}

/**
 * GetName:
 *
 * @return CString 
 */
CString CMemberContext::GetName()
{
	if(m_tokenEntry.GetSize() > 0)
	{
		const long lSiz = m_tokenEntry.GetSize();
		return m_tokenEntry.ElementAt(lSiz - 1);
	}

	return CString("");
}

/**
 * GetType:
 *
 * @return CString 
 */
CString CMemberContext::GetType()
{
	if(m_tokenEntry.GetSize() > 0)
	{
		CString rType;

		const long lSiz = m_tokenEntry.GetSize();
		for(int i= 0;i < lSiz - 1;i++)
		{
			rType += m_tokenEntry.ElementAt(i) + _T(" ");
		}

		return rType;
	}
	
	return CString("");
}
