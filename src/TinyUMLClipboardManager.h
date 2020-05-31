// TinyUMLClipboardManager.h: interface for the CTinyUMLClipboardManager class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_TINYUMLCLIPBOARDMANAGER_H__B2B55794_E095_4545_AAFD_7D458AEBC46C__INCLUDED_)
#define AFX_TINYUMLCLIPBOARDMANAGER_H__B2B55794_E095_4545_AAFD_7D458AEBC46C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <ClipboardManager.h>

class CTinyUMLClipboardManager : public CClipboardManager
{
public:
	CTinyUMLClipboardManager();
	virtual ~CTinyUMLClipboardManager();
public:
	virtual void SetData(CIsDrawEntitySet* pEntSet);
};

#endif // !defined(AFX_TINYUMLCLIPBOARDMANAGER_H__B2B55794_E095_4545_AAFD_7D458AEBC46C__INCLUDED_)
