// ContentFile.h: interface for the CContentFile class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CONTENTFILE_H__3F3CD759_1521_46C8_A33B_683AB81B883C__INCLUDED_)
#define AFX_CONTENTFILE_H__3F3CD759_1521_46C8_A33B_683AB81B883C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CContentFile  
{
public:
	void GetImageFromList(CImageList *lstImages, int nImage);
	bool IsIconStored();
	void Unpack();
	unsigned long GetLength();
	CContentFile();
	void Serialize(CArchive& ar);
	CString GetRefPath();
	CString GetName();
	CContentFile(const CString& rPathName , bool isLoad = false);
	virtual ~CContentFile();
private:
	CString m_rRefPath;
	CString m_rFileName;
	unsigned long m_nLength;
protected:
	bool m_isStored;
	CBitmap m_icon;
	char* m_content;
};

#endif // !defined(AFX_CONTENTFILE_H__3F3CD759_1521_46C8_A33B_683AB81B883C__INCLUDED_)
