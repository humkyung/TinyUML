// ContentFile.cpp: implementation of the CContentFile class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "TinyUML.h"
#include "ContentFile.h"

#include <fstream>
using namespace std;

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

static char drive[MAX_PATH] = {0,};
static char dir[MAX_PATH] = {0,};
static char fname[MAX_PATH] = {0,};
static char ext[MAX_PATH] = {0,};
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

/**
 * CContentFile:
 *
 * @return  
 */
CContentFile::CContentFile() : m_rRefPath("") , m_nLength(0L) , m_content(NULL)
{

}

/**
 * CContentFile:
 *
 * @param rPathName 
 * @return  
 */
CContentFile::CContentFile(const CString& rPathName , bool isLoad) : m_nLength(0L) , m_content(NULL)
{
	m_rRefPath = rPathName;

	char drive[MAX_PATH] , dir[MAX_PATH] , fname[MAX_PATH] , ext[MAX_PATH];
	_splitpath(rPathName , drive , dir , fname , ext);
	m_rFileName = fname;
	m_rFileName += ext;
	if(true == isLoad)
	{
		try
		{
			CFile file(m_rRefPath , CFile::modeRead);
			m_nLength = file.GetLength();
			if(NULL != (m_content = new char[m_nLength]))
			{
				file.ReadHuge(m_content , m_nLength);
			}
			file.Close();
		}
		catch(CFileException ex)
		{
		}
	}
}

CContentFile::~CContentFile()
{
	try
	{
		if(NULL != m_content) delete []m_content;
	}
	catch(...)
	{
	}
}


/**
 * GetName:
 *
 * @return CString 
 */
CString CContentFile::GetName()
{
	return m_rFileName;
}

/**
 * GetRefPath:
 *
 * @return CString 
 */
CString CContentFile::GetRefPath()
{
	return m_rRefPath;
}

/**
 * Serialize:
 *
 * @param ar 
 * @return void 
 */
void CContentFile::Serialize(CArchive &ar)
{
	if(ar.IsStoring())
	{
		//char isStored = (true == m_isStored) ? 1 : 0;
		//ar << isStored;
		ar << m_rRefPath;
		//ar << m_nLength;

		try
		{
			CFile file(m_rRefPath , CFile::modeRead);
			m_nLength = file.GetLength();
			ar << m_nLength;
			char* p = new char[m_nLength];
			file.Read(p , m_nLength);
			file.Close();

			ar.Write(p , m_nLength);
			delete []p;
		}
		catch(const CFileException& ex)
		{
			AfxMessageBox("");
		}
	}
	else
	{
		char isStored = 0;
		//ar >> isStored;
		//m_isStored = (1 == isStored) ? true : false;
		ar >> m_rRefPath;
		
		_splitpath(m_rRefPath , drive , dir , fname , ext);
		m_rFileName = fname;
		m_rFileName += ext;

		ar >> m_nLength;
		if(0L != m_nLength)
		{
			m_content = new char[m_nLength];
			ar.Read(m_content , m_nLength);
		}
	}
}

unsigned long CContentFile::GetLength()
{
	return m_nLength;
}

/**	\brief	The CContentFile::Unpack function


	\return	void	
*/
void CContentFile::Unpack()
{
	try
	{
		CFile file;
		file.Open(m_rRefPath , CFile::modeCreate | CFile::modeWrite);
		file.Write(m_content , m_nLength);
		file.Close();
	}
	catch(CFileException ex)
	{
		AfxMessageBox("Unpack Error");
	}
}

/**	\brief	The CContentFile::GetImageFromList function

	\param	lstImages	a parameter of type CImageList *
	\param	nImage	a parameter of type int

	\return	void	
*/
void CContentFile::GetImageFromList(CImageList *lstImages, int nImage)
{
	//First we want to create a temporary image list we can manipulate
	CImageList tmpList;
	tmpList.Create(lstImages);
	
	//Then swap the requested image to the first spot in the list 
	tmpList.Copy( 0, nImage, ILCF_SWAP );
	
	//Now we need to get some information about the image 
	IMAGEINFO lastImage;
	tmpList.GetImageInfo(0,&lastImage);
	
	CWnd desktop;
	desktop.Attach(GetDesktopWindow());
	//Heres where it gets fun
	//Create a Compatible Device Context using 
	//the valid DC of your calling window
	CDC dcMem;
	dcMem.CreateCompatibleDC (desktop.GetWindowDC()); 

	//This rect simply stored the size of the image we need
	CRect rect (lastImage.rcImage);
	
	//Using the bitmap passed in, Create a bitmap 
	//compatible with the window DC
	//We also know that the bitmap needs to be a certain size.
	m_icon.CreateCompatibleBitmap (desktop.GetWindowDC(), 
		rect.Width (), rect.Height ());
	
	//Select the new destination bitmap into the DC we created above
	CBitmap* pBmpOld = dcMem.SelectObject (&m_icon);
	
	//This call apparently "draws" the bitmap from the list, 
	//onto the new destination bitmap
	tmpList.DrawIndirect (&dcMem, 0, CPoint (0, 0), 
		CSize (rect.Width (), rect.Height ()), CPoint (0, 0));
	
	
	//cleanup by reselecting the old bitmap object into the DC
	dcMem.SelectObject (pBmpOld);
}

bool CContentFile::IsIconStored()
{
	return (NULL != m_icon.operator HBITMAP());
}
