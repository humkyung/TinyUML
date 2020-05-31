// ContextScanner.cpp: implementation of the CContextScanner class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "ClassParser.h"
#include "ContextScanner.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CContextScanner::CContextScanner(const CString& rFileName)
{
	m_rFileName = rFileName;
	
	CFileException ex;
	try{
		m_file.Open(m_rFileName,CFile::modeRead,&ex);
	}catch(...){}
}

CContextScanner::~CContextScanner()
{
	try{
		m_file.Close();
	}catch(...){}
}

/**
 * GetNextToken:
 *
 * @return CString 
 */
CString CContextScanner::GetNextToken()
{
	static const CString rDelimiter="/[]()<>{}!=*%,\\#\":; \t";
	/*static */TCHAR szBuf[MAX_PATH];
	CString rToken;

	SkipWhiteChars();
	UINT iRead=0;
	while((iRead = m_file.Read(szBuf,1)) > 0){
		if(("" == rToken) && ('/' == szBuf[0])){
			rToken += szBuf[0];
			if((m_file.Read(szBuf,1) > 0) && 
			   (('/' == szBuf[0]) || ('*' == szBuf[0]))){
				rToken += szBuf[0];
				break;
			}
		}else if('*' == szBuf[0]){
			rToken += szBuf[0];
			if((m_file.Read(szBuf,1) > 0) && ('/' == szBuf[0])){
				rToken += szBuf[0];
				break;
			}
		}else if(('\r' == szBuf[0]) || ('\n' == szBuf[0])) continue;
			
		int nPos = rDelimiter.Find(szBuf[0],0);
		if(-1 != nPos){
			if("" != rToken)
				m_file.Seek(-1,CFile::current);
			else	rToken += szBuf[0];
			break;
		}else	rToken += szBuf[0];
	}

	return rToken;
}

/**
 * SkipWhiteChars:
 *
 * @return void 
 */
void CContextScanner::SkipWhiteChars()
{
	TCHAR szCh[2]={0,};

	int iRead=0;
	do{
		iRead = m_file.Read(szCh,1);
	}while((iRead > 0) && IsWhiteChar(szCh[0]));
	if(iRead > 0) m_file.Seek(-(iRead),CFile::current);
}

/**
 * IsWhiteChar:
 *
 * @param ch 
 * @return bool 
 */
bool CContextScanner::IsWhiteChar(const TCHAR &ch)
{
	static const CString rWhiteChars=" \t\r\n";

	return (-1 == rWhiteChars.Find(ch,0)) ? false : true;
}

/**
 * PushBack:
 *
 * @param rToken 
 * @return void 
 */
void CContextScanner::PushBack(const CString &rToken)
{
	m_file.Seek(-(rToken.GetLength()),CFile::current);
}

/**
 * GetLine:
 *
 * @param rString 
 * @return bool
 */
bool CContextScanner::GetLine(CString &rString)
{
	static const CString rEndOfLine="\r\n";
	static TCHAR szBuf[MAX_PATH]={0,};
	bool bRet=false;

	UINT iRead = 0;
	while((iRead = m_file.Read(szBuf,MAX_PATH)) > 0){
		if(NULL != strstr(szBuf,rEndOfLine)){
			CString rText(szBuf);
			int nPos = rText.Find(rEndOfLine,0);
			m_file.Seek(-(iRead - (nPos + 2)),CFile::current);
			rText = rText.Left(nPos);
			rString += rText;
			bRet = true;
			break;
		}else	rString += szBuf;
	}

	return bRet;
}

/**
 * Read:
 *
 * @param pszBuf 
 * @param nBufSiz 
 * @return UINT 
 */
UINT CContextScanner::Read(TCHAR *pszBuf, const int nBufSiz)
{
	return m_file.Read(pszBuf,nBufSiz);
}