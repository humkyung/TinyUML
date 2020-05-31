// ContextParser.h: interface for the CContextScanner class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CONTEXTSCANNER_H__96BE5325_1444_4AF3_9D4B_78643EDBBD07__INCLUDED_)
#define AFX_CONTEXTSCANNER_H__96BE5325_1444_4AF3_9D4B_78643EDBBD07__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CContextScanner
{
public:
	CContextScanner(const CString& rFileName);
	virtual ~CContextScanner();
	UINT Read(TCHAR* pszBuf,const int nBufSiz);
	bool GetLine(CString& rString);
	void PushBack(const CString& rToken);
	CString GetNextToken();
	void SkipWhiteChars();
private:
	bool IsWhiteChar(const TCHAR& ch);
	CString m_rFileName;
	CFile m_file;
};

#endif // !defined(AFX_CONTEXTSCANNER_H__96BE5325_1444_4AF3_9D4B_78643EDBBD07__INCLUDED_)
