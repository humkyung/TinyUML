// WriteSourceFiles.cpp : implementation file
//

#include "stdafx.h"
#include <assert.h>
#include "TinyUML.h"
#include "TinyUMLClass.h"
#include "TinyUMLGeneralization.h"
#include "WriteSourceFiles.h"
#include "GUID.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CWriteSourceFiles dialog


/**
 * CWriteSourceFiles:
 *
 * @param pParent 
 * @return  
 */
CWriteSourceFiles::CWriteSourceFiles(CWnd* pParent /*=NULL*/)
	: CDialog(CWriteSourceFiles::IDD, pParent)
{
	//{{AFX_DATA_INIT(CWriteSourceFiles)
	m_rRepository = _T("");
	//}}AFX_DATA_INIT
}

void CWriteSourceFiles::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CWriteSourceFiles)
	DDX_Control(pDX,IDC_BUTTON_SELECT_REPOSITORY,m_btnSelectRepository);
	DDX_Text(pDX,IDC_EDIT_REPOSITORY,m_rRepository);
	DDX_Control(pDX,IDC_LIST_FILES,m_ctlFiles);
	DDX_Control(pDX,IDOK,m_btnOk);
	DDX_Control(pDX,IDCANCEL,m_btnCancel);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CWriteSourceFiles, CDialog)
	//{{AFX_MSG_MAP(CWriteSourceFiles)
	ON_BN_CLICKED(IDC_BUTTON_SELECT_REPOSITORY, OnButtonSelectRepository)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CWriteSourceFiles message handlers

/**
 * OnInitDialog:
 *
 * @return BOOL 
 */
BOOL CWriteSourceFiles::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	m_btnSelectRepository.SetIcon(IDI_OPEN,16,16);
	
	m_ctlFiles.SetHeadings(_T("Id, 50;Name, 250"));
	for(int i=0;i < m_entitySet.GetSize();i++)
	{
		CString rName = m_entitySet.ElementAt(i)->Name();
		CString rId; rId.Format("%d",m_ctlFiles.GetItemCount());
		m_ctlFiles.InsertItem(m_ctlFiles.GetItemCount(),rId,rName);
	}

	m_btnOk.SetIcon(IDI_OK);
	m_btnCancel.SetIcon(IDI_CANCEL);
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

/**
 * Write:
 *
 * @return void 
 */
void CWriteSourceFiles::Write()
{
	if(m_entitySet.GetSize())
	{
		for(int i=0;i < m_entitySet.GetSize();i++)
		{
			CIsDrawEntity* pTyEnt=m_entitySet.GetAt(i);
			if(pTyEnt->IsKindOf(CTinyUMLClass::TypeString()))
			{
				CTinyUMLClass* pTyUMLClass=static_cast<CTinyUMLClass*>(pTyEnt);
				WriteClass(pTyUMLClass);
			}
		}
	}else	AfxMessageBox("No selected entities.");
}

/**
 * OnOK:
 *
 * @return void 
 */
void CWriteSourceFiles::OnOK() 
{
	UpdateData();
	if(m_rRepository != _T(""))
	{
		Write();
		AfxMessageBox("Save is done.");
	}
	
	CDialog::OnOK();
}

/**
 * WriteClass:
 *
 * @param pClass 
 * @return void 
 */
void CWriteSourceFiles::WriteClass(CTinyUMLClass *pClass)
{
	assert(pClass && "pClass is NULL");

	if(pClass){
		//////////////////////////////////////////////////////////////////////////
		m_publicMethod.RemoveAll();
		m_protectedMethod.RemoveAll();
		m_privateMethod.RemoveAll();
		m_publicAttribute.RemoveAll();
		m_protectedAttribute.RemoveAll();
		m_privateAttribute.RemoveAll();
		
		for(int i=0;i < pClass->methodsCount();i++)
		{
			CTinyUMLClass::Method method=pClass->GetMethodAt(i);
			if(CTinyUMLClass::Method::public_method == method.access){
				m_publicMethod.Add(method);
			}else if(CTinyUMLClass::Method::protected_method == method.access){
				m_protectedMethod.Add(method);
			}else if(CTinyUMLClass::Method::private_method == method.access){
				m_privateMethod.Add(method);
			}
		}

		for(i=0;i < pClass->attributesCount();i++)
		{
			CTinyUMLClass::Member attribute=pClass->GetAttbuteAt(i);
			if(CTinyUMLClass::Member::public_member == attribute.access){
				m_publicAttribute.Add(attribute);
			}else if(CTinyUMLClass::Member::protected_member == attribute.access){
				m_protectedAttribute.Add(attribute);
			}else if(CTinyUMLClass::Member::private_member == attribute.access){
				m_privateAttribute.Add(attribute);
			}
		}
		//////////////////////////////////////////////////////////////////////////

		WriteHeaderFile(pClass);
		WriteCPPFile(pClass);
	}
}

/**
 * WriteHeaderFile:
 *
 * @param pClass 
 * @return void 
 */
void CWriteSourceFiles::WriteHeaderFile(CTinyUMLClass *pClass)
{
	assert(pClass && "pClass is NULL");

	if(pClass){
		TCHAR szBuf[MAX_PATH]={0,};

		CFile file;
		try{
			CGUID guid;
			CString rString,rFileName,rGuid;
			rFileName = pClass->Name();
			if('C' == rFileName[0])
				rFileName = rFileName.Right(rFileName.GetLength() - 1);
			CString rFilePath = m_rRepository + "\\" + rFileName;
			rGuid = guid(); 
			rGuid = rGuid.Left(rGuid.GetLength() - 1);
			rGuid = rGuid.Right(rGuid.GetLength() - 1);
			rGuid.Replace("-","_");
			
			//////////////////////////////////////////////////////////////////////////
			if(file.Open(rFilePath + ".h",CFile::modeCreate | CFile::modeWrite)){
				rString.Format("#ifndef "); file.Write(rString,rString.GetLength());
				rString.Format("TINY_%s_H_%s_INCLUDED_\r\n",rFileName,rGuid); rString.MakeUpper();
				file.Write(rString,rString.GetLength());
				rString.Format("#define "); file.Write(rString,rString.GetLength());
				rString.Format("TINY_%s_H_%s_INCLUDED_\r\n\r\n",rFileName,rGuid); rString.MakeUpper();
				file.Write(rString,rString.GetLength());

				CIsDrawEntitySet* pEntSet=pClass->GetReactors();
				CArray<CIsDrawEntity*,CIsDrawEntity*> inheritees;
				if(pEntSet)
				{
					CIsDrawEntity* pEnt=NULL;
					for(int i=0;pEnt = pEntSet->GetAt(i);i++)
					{
						if(pEnt->IsKindOf(CTinyUMLGeneralization::TypeString())){
							CTinyUMLGeneralization* pGeneralization=static_cast<CTinyUMLGeneralization*>(pEnt);
							if(pGeneralization->GetSourceEntity() == pClass){
								inheritees.Add(pGeneralization->GetDestEntity());
							}
						}
					}
				}
				if(inheritees.GetSize() > 0)
				{
					CString rParents;
					for(int i=0;i < inheritees.GetSize();i++)
					{
						CString rName = static_cast<CTinyUMLClass*>(inheritees.ElementAt(i))->Name();
						rParents += "public " + rName;

						if('C' == rName[0]) rName = rName.Right(rName.GetLength() - 1);
						rString.Format("#include \"%s.h\"\r\n",rName);
						file.Write(rString,rString.GetLength());
					}
					rString = "\r\n";
					file.Write(rString,rString.GetLength());
					rString.Format("class %s : %s\r\n{\r\n",pClass->Name(),rParents);
				}
				else
				{
					rString.Format("class %s\r\n{\r\n",pClass->Name());
				}
				file.Write(rString,rString.GetLength());
				
				rString.Format("public:\r\n");
				file.Write(rString,rString.GetLength());
				rString.Format("\t%s();\r\n",pClass->Name());
				file.Write(rString,rString.GetLength());
				rString.Format("\tvirtual ~%s();\r\n",pClass->Name());
				file.Write(rString,rString.GetLength());
				
				//////////////////////////////////////////////////////////////////////////
				rString = "public:\r\n";
				file.Write(rString,rString.GetLength());
				for(int i = 0;i < m_publicMethod.GetSize();i++) WriteMethodDeclaration(file,m_publicMethod.ElementAt(i));
				for(i = 0;i < m_publicAttribute.GetSize();i++)
				{
					rString.Format("\t%s %s;\r\n",m_publicAttribute.GetAt(i).type,m_publicAttribute.GetAt(i).name);
					file.Write(rString,rString.GetLength());
				}

				//////////////////////////////////////////////////////////////////////////
				rString = "protected:\r\n";
				file.Write(rString,rString.GetLength());
				for(i = 0;i < m_protectedMethod.GetSize();i++) WriteMethodDeclaration(file,m_protectedMethod.ElementAt(i));
				for(i = 0;i < m_protectedAttribute.GetSize();i++)
				{
					rString.Format("\t%s %s;\r\n",m_protectedAttribute.GetAt(i).type,m_protectedAttribute.GetAt(i).name);
					file.Write(rString,rString.GetLength());
				}

				//////////////////////////////////////////////////////////////////////////
				rString = "private:\r\n";
				file.Write(rString,rString.GetLength());
				for(i = 0;i < m_privateMethod.GetSize();i++) WriteMethodDeclaration(file,m_privateMethod.ElementAt(i));
				for(i = 0;i < m_privateAttribute.GetSize();i++)
				{
					rString.Format("\t%s %s;\r\n",m_privateAttribute.GetAt(i).type,m_privateAttribute.GetAt(i).name);
					file.Write(rString,rString.GetLength());
				}
				
				rString.Format("};\r\n\r\n");
				file.Write(rString,rString.GetLength());
				rString = _T("#endif");
				file.Write(rString,rString.GetLength());
				file.Close();
			}
		}
		catch(CFileException& ex)
		{
			TCHAR szErrMsg[MAX_PATH];
			ex.GetErrorMessage(szErrMsg,MAX_PATH);
			OutputDebugString(szErrMsg);
		}
	}
}

/**
 * WriteMethodDefine:
 *
 * @param file 
 * @param pMethod 
 * @return void 
 */
void CWriteSourceFiles::WriteMethodDefine(CFile& file,const CString& rClassName,CTinyUMLClass::Method* pMethod)
{
	assert(pMethod && "pMethod is NULL");

	if(pMethod)
	{
		CString rString;
		rString = "\r\n";
		file.Write(rString,rString.GetLength());
		
		rString = pMethod->rComment + "\r\n";
		file.Write(rString,rString.GetLength());
		
		rString = pMethod->type + " " + rClassName + "::" + pMethod->name + "\r\n";
		file.Write(rString,rString.GetLength());
		rString = "{\r\n";
		file.Write(rString,rString.GetLength());
		rString = pMethod->strDefine;
		file.Write(rString,rString.GetLength());
		rString = "}\r\n";
		file.Write(rString,rString.GetLength());

	}
}

/**
 * WriteCPPFile:
 *
 * @param pClass 
 * @return void 
 */
void CWriteSourceFiles::WriteCPPFile(CTinyUMLClass *pClass)
{
	assert(pClass && "pClass is NULL");

	if(pClass){
		TCHAR szBuf[MAX_PATH]={0,};
		
		CFile file;
		try{
			CGUID guid;
			CString rString,rFileName,rGuid;
			rFileName = pClass->Name();
			if('C' == rFileName[0])
				rFileName = rFileName.Right(rFileName.GetLength() - 1);
			CString rFilePath = m_rRepository + "\\" + rFileName;
			rGuid = guid(); 
			rGuid = rGuid.Left(rGuid.GetLength() - 1);
			rGuid = rGuid.Right(rGuid.GetLength() - 1);
			rGuid.Replace("-","_");
			
			
			//////////////////////////////////////////////////////////////////////////
			file.Open(rFilePath + ".cpp",CFile::modeCreate | CFile::modeWrite);
			rString.Format("#include \"%s\"\r\n\r\n",rFileName + ".h");
			file.Write(rString,rString.GetLength());
			rString.Format("%s::%s()\r\n{\r\n",pClass->Name(),pClass->Name());
			file.Write(rString,rString.GetLength());
			rString = _T("}\r\n\r\n");
			file.Write(rString,rString.GetLength());
			rString.Format("%s::~%s()\r\n{\r\n",pClass->Name(),pClass->Name());
			file.Write(rString,rString.GetLength());
			rString = _T("}\r\n");
			file.Write(rString,rString.GetLength());
			
			for(int i = 0;i < m_publicMethod.GetSize();i++){
				CTinyUMLClass::Method method=m_publicMethod.GetAt(i);
				WriteMethodDefine(file,pClass->Name(),&method);
			}
			
			for(i = 0;i < m_protectedMethod.GetSize();i++){
				CTinyUMLClass::Method method=m_protectedMethod.GetAt(i);
				WriteMethodDefine(file,pClass->Name(),&method);
			}
			
			for(i = 0;i < m_privateMethod.GetSize();i++){
				CTinyUMLClass::Method method=m_privateMethod.GetAt(i);
				WriteMethodDefine(file,pClass->Name(),&method);
			}
			
			file.Close();
		}
		catch(CFileException& ex)
		{
			TCHAR szErrMsg[MAX_PATH];
			ex.GetErrorMessage(szErrMsg,MAX_PATH);
			OutputDebugString(szErrMsg);
		}
	}
}

/**
 * Add:
 *
 * @param pEnt 
 * @return void 
 */
void CWriteSourceFiles::Add(CIsDrawEntity *pEnt)
{
	assert(pEnt && "pEnt is NULL");

	if(pEnt && pEnt->IsKindOf(CTinyUMLClass::TypeString())) m_entitySet.Add(pEnt);
}

/**
 * OnButtonSelectRepository:
 *
 * @return void 
 */
void CWriteSourceFiles::OnButtonSelectRepository() 
{
	BROWSEINFO bi;
	ZeroMemory(&bi,sizeof(BROWSEINFO));
	bi.hwndOwner = GetSafeHwnd();
	LPITEMIDLIST pidl = SHBrowseForFolder(&bi);
	
	TCHAR szPath[MAX_PATH]={0};
	if(SHGetPathFromIDList(pidl,szPath)){
		SetDlgItemText(IDC_EDIT_REPOSITORY,szPath);
	}
}

/**
 * WriteMethod:
 *
 * @param file 
 * @param method 
 * @return void 
 */
void CWriteSourceFiles::WriteMethodDeclaration(CFile& file,CTinyUMLClass::Method& method)
{
	CString rString="\t";
	if(method.property & CTinyUMLClass::Method::Property::static_property){
		rString += "static ";
	}
	if(method.property & CTinyUMLClass::Method::Property::virtual_property){
		rString += "virtual ";
	}
	if(method.property & CTinyUMLClass::Method::Property::inline_property){
		rString += "inline ";
	}
	file.Write(rString,rString.GetLength());
	
	rString.Format(" %s %s;\r\n",method.type,method.name);
	file.Write(rString,rString.GetLength());
}