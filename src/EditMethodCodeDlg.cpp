// EditMethodCodeDlg.cpp : implementation file
//

#include "stdafx.h"
#include "TinyUML.h"
#include "ToolShell.h"
#include "EditMethodCodeDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CEditMethodCodeDlg dialog


CEditMethodCodeDlg::CEditMethodCodeDlg(CTinyUMLClass::Method* pMethod,CWnd* pParent /*=NULL*/)
	: CDialog(CEditMethodCodeDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CEditMethodCodeDlg)
	m_rComment = _T("");
	m_rDefine = _T("");
	m_rName = _T("");
	m_rBegin= _T("{");
	m_rEnd  = _T("}");
	m_hSHEdit= NULL;
	m_pMethod = pMethod;
	//}}AFX_DATA_INIT
}


void CEditMethodCodeDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CEditMethodCodeDlg)
	DDX_Text(pDX,IDC_EDIT_COMMENTS,m_rComment);
	DDX_Text(pDX,IDC_EDIT_NAME,m_rName);
	DDX_Text(pDX,IDC_EDIT_BEGIN,m_rBegin);
	DDX_Text(pDX,IDC_EDIT_END,m_rEnd);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CEditMethodCodeDlg, CDialog)
	//{{AFX_MSG_MAP(CEditMethodCodeDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CEditMethodCodeDlg message handlers

/**
 * Show:
 *
 * @return void 
 */
void CEditMethodCodeDlg::Show()
{
	CToolShell* pParent=CToolShell::GetInstance();
	if(NULL != pParent){
		pParent->SetDlg(this);
		pParent->SetWindowText(_T("Edit Method Code"));
	}
}

/**
 * OnButtonClose:
 *
 * @return void 
 */
void CEditMethodCodeDlg::OnCancel() 
{	
	m_rName   = _T("");
	m_rDefine = _T("");
	CToolShell* pShell=CToolShell::GetInstance();
	pShell->m_dlgNoTool.Show();

	CDialog::OnCancel();
}

/**
 * SetMethodName:
 *
 * @param rName 
 * @return void 
 */
void CEditMethodCodeDlg::SetMethodName(const CString &rName)
{
	m_rName = rName;
	UpdateData(FALSE);
}

/**
 * SetMethodDefine:
 *
 * @param rDefine 
 * @return void 
 */
void CEditMethodCodeDlg::SetMethodDefine(const CString &rDefine)
{
	m_rDefine = rDefine;
	UpdateData(FALSE);
}

/**
 * OnButtonSave:
 *
 * @return void 
 */
void CEditMethodCodeDlg::OnOK() 
{
	UpdateData();
	m_pMethod->strDefine = SHEdit_GetText(m_hSHEdit);
	
	/*
	if(NULL != m_pClass){
		const int nSize=m_pClass->methodsCount();
		for(int i=0;i < nSize;i++){
			CTinyUMLClass::Method method=m_pClass->GetMethodAt(i);
			if(m_rName == method.name){
				method.rComment = m_rComment;
				method.strDefine = m_rDefine;
				m_pClass->SetMethodAt(method,i);
				break;
			}
		}
	}
	*/
	
	CDialog::OnOK();
}

struct SHEDIT_SYNTAX_DEF
{
	BOOL bCase;
	TCHAR* pszDelimiter;
	TCHAR chQuotation1;
	TCHAR chQuotation2;
	TCHAR chEscape;
	TCHAR* pszLineComment;
	TCHAR* pszLineComment2;
	BOOL bTextComment;				// ���ڷε� �ּ��ΰ�
	BOOL bTextComment2;				// ���ڷε� �ּ��ΰ�
	TCHAR* pszCommentOn;
	TCHAR* pszCommentOff;
	TCHAR* pszCommentOn2;
	TCHAR* pszCommentOff2;
	TCHAR chContinuance;			// ������ ���� ����
	TCHAR* pszScriptBegin;
	TCHAR* pszScriptEnd;
	TCHAR* pszKeyword1;
	TCHAR* pszKeyword2;
	TCHAR* pszKeyword3;
	TCHAR* pszKeyword4;
	TCHAR* pszKeyword5;
	TCHAR* pszKeyword6;
	TCHAR* pszKeyword7;
	TCHAR* pszKeyword8;
};

struct SHEDIT_SYNTAX_COLOR
{
	COLORREF clrNormalFore;				// �Ϲ� ���� �����
	COLORREF clrNormalBack;				// �Ϲ� ���� ����
	COLORREF clrQuotation1Fore;			// ���ڿ� 1 �����
	COLORREF clrQuotation1Back;			// ���ڿ� 1 ����
	COLORREF clrQuotation2Fore;			// ���ڿ� 2 �����
	COLORREF clrQuotation2Back;			// ���ڿ� 2 ����
	COLORREF clrNumberFore;				// ���� �����
	COLORREF clrNumberBack;				// ���� ����
	COLORREF clrComment1Fore;			// �ּ�1 �����
	COLORREF clrComment1Back;			// �ּ�1 ����
	COLORREF clrComment2Fore;			// �ּ�2 �����
	COLORREF clrComment2Back;			// �ּ�2 ����
	COLORREF clrEmbeddedScriptFore;		// Html Embedded Script �����
	COLORREF clrEmbeddedScriptBack;		// Html Embedded Script ����
	COLORREF clrKeyword1Fore;			// Keyword1 �����
	COLORREF clrKeyword1Back;			// Keyword1 ����
	COLORREF clrKeyword2Fore;			// Keyword2 �����
	COLORREF clrKeyword2Back;			// Keyword2 ����
	COLORREF clrKeyword3Fore;			// Keyword3 �����
	COLORREF clrKeyword3Back;			// Keyword3 ����
	COLORREF clrKeyword4Fore;			// Keyword4 �����
	COLORREF clrKeyword4Back;			// Keyword4 ����
	COLORREF clrKeyword5Fore;			// Keyword5 �����
	COLORREF clrKeyword5Back;			// Keyword5 ����
	COLORREF clrKeyword6Fore;			// Keyword6 �����
	COLORREF clrKeyword6Back;			// Keyword6 ����
	COLORREF clrKeyword7Fore;			// Keyword7 �����
	COLORREF clrKeyword7Back;			// Keyword7 ����
	COLORREF clrKeyword8Fore;			// Keyword8 �����
	COLORREF clrKeyword8Back;			// Keyword8 ����
};

// TODO: Add your command handler code here
SHEDIT_SYNTAX_DEF syntax = {
	TRUE,			// bCase
	"\"'\\.,<>:;/()[]{}~!@%^&*-+=?|$",	// pszDelimiter
	'"',			//chQuotation1
	'\'',			//chQuotation2;
	'\\',			//chEscape;
	"//",			//pszLineComment
	NULL,			//pszLineComment2;
	FALSE,			//bTextComment;
	FALSE,			//bTextComment2;
	"/*",			//pszCommentOn;
	"*/",			//pszCommentOff;
	NULL,			//pszCommentOn2;
	NULL,			//pszCommentOff2;
	NULL,			//chContinuance;
	NULL,			//pszScriptBegin;
	NULL,			//pszScriptEnd;
	//pszKeyword1;
	" auto "
	"break bool "
	"case char class const continue "
	"default do double defined "
	"else enum extern "
	"float for "
	"goto "
	"if int "
	"long "
	"private protected public "
	"register return "
	"short signed sizeof static struct switch "
	"typedef "
	"union unsigned "
	"virtual void volatile "
	"while "
	"__asm __based __cdecl __declspec __except __far __fastcall __finally __fortran __huge __inline __int16 __int32 __int64 __int8 __interrupt __leave __loadds __near __pascal __saveregs __segment __segname __self __stdcall __try __uuidof ",
	//pszKeyword2;
	" #define #error #include #elif #if #line #else #ifdef #pragma #endif #ifndef #undef ",
	//pszKeyword3;
	" dllexport dllimport naked thread uuid ",
	NULL,			//pszKeyword4;
	NULL,			//pszKeyword5;
	NULL,			//pszKeyword6;
	NULL,			//pszKeyword7;
	NULL			//pszKeyword8;
		
};

SHEDIT_SYNTAX_COLOR color = 
{
	CLR_DEFAULT,			// �Ϲ� ���� �����
	CLR_DEFAULT,			// �Ϲ� ���� ����
	RGB( 255, 0, 255 ),		// ���ڿ� 1 �����
	CLR_DEFAULT,			// ���ڿ� 1 ����
	RGB( 255, 0, 255 ),		// ���ڿ� 2 �����
	CLR_DEFAULT,			// ���ڿ� 2 ����
	RGB( 255, 0, 0 ),		// ���� �����
	CLR_DEFAULT,			// ���� ����
	RGB( 0, 130, 0 ),		// �ּ�1 �����
	CLR_DEFAULT,			// �ּ�1 ����
	RGB( 0, 130, 0 ),		// �ּ�2 �����
	CLR_DEFAULT,			// �ּ�2 ����
	CLR_DEFAULT,			// Html Embedded Script �����
	CLR_DEFAULT,			// Html Embedded Script ����
	RGB( 0, 0, 255 ),		// Keyword1 �����
	CLR_DEFAULT,			// Keyword1 ����
	RGB( 0, 0, 255 ),		// Keyword2 �����
	CLR_DEFAULT,			// Keyword2 ����
	RGB( 0, 0, 255 ),		// Keyword3 �����
	CLR_DEFAULT,			// Keyword3 ����
	RGB( 0, 0, 255 ),		// Keyword4 �����
	CLR_DEFAULT,			// Keyword4 ����
	RGB( 0, 0, 255 ),		// Keyword5 �����
	CLR_DEFAULT,			// Keyword5 ����
	RGB( 0, 0, 255 ),		// Keyword6 �����
	CLR_DEFAULT,			// Keyword6 ����
	RGB( 0, 0, 255 ),		// Keyword7 �����
	CLR_DEFAULT,			// Keyword7 ����
	RGB( 0, 0, 255 ),		// Keyword8 �����
	CLR_DEFAULT				// Keyword8 ����
};

/*******************************************************************************************************
	description	: �Ϲ� ���� ���� ����
	parameter	: hWnd - SHEdit Handle
				  pSyntax - SHEDIT_SYNTAX_DEF Pointer
				  pSynColor - SHEDIT_SYNTAX_COLOR Pointer
	returns		: �����ϸ� TRUE, �����ϸ� FALSE
	remarks		:
*******************************************************************************************************/
extern "C" __declspec( dllexport )
 BOOL SHEdit_SetSyntaxGeneral( HWND hWnd,
							   SHEDIT_SYNTAX_DEF* pSyntax, SHEDIT_SYNTAX_COLOR* pSynColor );

/**
 * OnInitDialog:
 *
 * @return BOOL 
 */
BOOL CEditMethodCodeDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	SetDlgItemText(IDC_EDIT_NAME,m_pMethod->type + " " + m_pMethod->name);

	CRect rc;
	GetDlgItem( IDC_FRAME )->GetWindowRect( &rc );
	ScreenToClient( &rc );
	
	m_hSHEdit = SHEdit_Create( m_hWnd, 1000, rc.left, rc.top, rc.right - rc.left, rc.bottom - rc.top );
	if(NULL != m_hSHEdit){
		::MoveWindow( m_hSHEdit, rc.left, rc.top, rc.right - rc.left, rc.bottom - rc.top, TRUE );
		// �������� ���׷� ���Ͽ� �߰���
		::SendMessage( m_hSHEdit, WM_SIZE, SIZE_RESTORED, MAKEWPARAM( rc.right - rc.left, rc.bottom - rc.top ) );
		SHEdit_SetText(m_hSHEdit,m_pMethod->strDefine.GetBuffer(0),m_pMethod->strDefine.GetLength());

		SHEdit_SetActiveLineType(m_hSHEdit,SHEDIT_ACTIVE_LINE_DRAW_MARGIN);
		SHEdit_EnableLineNo(m_hSHEdit,TRUE);
		SHEdit_MatchBrace(m_hSHEdit,TRUE);
		SHEdit_SetTabSize(m_hSHEdit,8);
		//SHEdit_EnableRuler(m_hSHEdit,TRUE);
		
		static LOGFONT logfont;
		GetFont()->GetLogFont(&logfont);
		logfont.lfHeight = 16;
		SHEdit_SetFont(m_hSHEdit,&logfont);
		
		SHEdit_SetSyntaxGeneral( m_hSHEdit, &syntax, &color);
	}
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

/**
 * OnDestroy:
 *
 * @return void 
 */
BOOL CEditMethodCodeDlg::DestroyWindow() 
{
	SHEdit_Destroy( m_hSHEdit );
	
	return CDialog::DestroyWindow();
}

