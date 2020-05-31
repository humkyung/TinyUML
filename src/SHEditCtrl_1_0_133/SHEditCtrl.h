#ifndef __SHEDITCTRL_H__
#define __SHEDITCTRL_H__

/*//////////////////////////////////////////////////////////////////////////////////////////////////////
SHEditCtrl
	- DesyEdit�� ���Ե� Edit Engine

2005. 07. 21
������: �輼��

  �� ���α׷��� ��� �Ǹ��� �����ڿ��� ������,
  ����� �������� ���α׷��� ���� �����ϴ� ������ ���մϴ�.
//////////////////////////////////////////////////////////////////////////////////////////////////////*/

#include <windows.h>

#define SHEDIT_ACTIVE_LINE_NONE				0
#define SHEDIT_ACTIVE_LINE_RECTANGLE		1
#define SHEDIT_ACTIVE_LINE_DRAW_MARGIN		2
#define SHEDIT_ACTIVE_LINE_FILL_BACK		3

#define SHEDIT_CHARSET_UNDEFINED			-1	// �������� ����
#define SHEDIT_CHARSET_ASCII				0
#define SHEDIT_CHARSET_UNICODE				1	// Little Endian
#define SHEDIT_CHARSET_UTF_8				2
#define SHEDIT_CHARSET_UTF_8_NO_BOM			3

#define SHEDIT_FORMAT_DOS					1
#define SHEDIT_FORMAT_UNIX					2
#define SHEDIT_FORMAT_MAC					3

#define SHEDIT_VIEW_MODE_TEXT				0
#define SHEDIT_VIEW_MODE_HEX				1

#define SHEDIT_WORD_WRAP_NONE			0	// ����
#define SHEDIT_WORD_WRAP_CHARACTER		1	// ���ڴ���

#define SHEDIT_FIND_UP						0x1
#define SHEDIT_FIND_WHOLE_WORD				0x2
#define SHEDIT_FIND_MATCH_CASE				0x4
#define SHEDIT_FIND_WRAP					0x8
#define SHEDIT_FIND_REGULAR_EXPRESSION		0x40

struct SHEDIT_BLOCK
{
	int nStartIndex;
	int nEndIndex;
};


////////////////////////////////////////////////////////////////////
// Global Valriables
////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////
// Global Functions
////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////
// exports
////////////////////////////////////////////////////////////////////

/*******************************************************************************************************
	description	: SHEdit�� �����Ѵ�
	parameter	: hParent - �θ� ������ �ڵ�
				  nid - resource id
				  x - x ��ǥ
				  y - y ��ǥ
				  width - �ʺ�
				  height - ����
				  exstyle - ������ ����� Ȯ�� ��Ÿ��
				  style - ������ ����� ��Ÿ��
	returns		: �����ϸ� SHEdit�� Handle, �����ϸ� NULL
	remarks		:
*******************************************************************************************************/
extern "C" __declspec( dllexport )
  HWND SHEdit_Create( HWND hParent, UINT nid, int x, int y, int width, int height,
					  DWORD exstyle = WS_EX_CLIENTEDGE,
					  DWORD style = WS_CHILD | WS_VISIBLE | WS_HSCROLL | WS_VSCROLL
				 );


/*******************************************************************************************************
	description	: Redo�� �������� �Ǵ�
	parameter	: hWnd - SHEdit Handle
	returns		:
	remarks		:
*******************************************************************************************************/
extern "C" __declspec( dllexport ) BOOL SHEdit_CanRedo( HWND hWnd );

/*******************************************************************************************************
	description	: Undo�� �������� �Ǵ�
	parameter	: hWnd - SHEdit Handle
	returns		:
	remarks		:
*******************************************************************************************************/
extern "C" __declspec( dllexport ) BOOL SHEdit_CanUndo( HWND hWnd );

/*******************************************************************************************************
	description	: �ٿ� �ֱⰡ ������ �������� �˻�
	parameter	: hWnd - SHEdit Handle
	returns		: �ٿ� �ֱⰡ ������ �����̸� TRUE, �׷��� ������ FALSE
	remarks		:
*******************************************************************************************************/
extern "C" __declspec( dllexport ) BOOL SHEdit_EnablePaste( HWND hWnd );

/*******************************************************************************************************
	description	: ���ڰ˻�
	parameter	: hWnd - SHEdit Handle
				  nPos - �˻� ������ġ( -1�̸� ���� ��ġ)
				  pszFind - ã�� ���ڿ�
				  dwFlag - �˻� ����
	returns		: �˻��� �����ϸ� TRUE, �����ϸ� FALSE
	remarks		:
				  dwFlag
					SHEDIT_FIND_UP					: ���� ã��
					SHEDIT_FIND_WHOLE_WORD			: ������ �ܾ�
					SHEDIT_FIND_MATCH_CASE			: ��ҹ��� ����
					SHEDIT_FIND_WRAP				: ã�� ���ϸ� ó�� ���� ã��
					SHEDIT_FIND_REGULAR_EXPRESSION	: ���� ǥ����
*******************************************************************************************************/
extern "C" __declspec( dllexport ) BOOL SHEdit_FindText( HWND hWnd, int nPos, TCHAR* pszFind, DWORD dwFlag );

/*******************************************************************************************************
	description	: Autoselect Mode�� �����Ǿ��°�
	parameter	: hWnd - SHEdit Handle
	returns		: Autoselect Mode�� �����Ǿ����� TRUE, �׷��� ������ FALSE�� ����
	remarks		:
*******************************************************************************************************/
extern "C" __declspec( dllexport ) BOOL SHEdit_IsAutoSelectMode( HWND hWnd );

/*******************************************************************************************************
	description	: ���̳ʸ� ���� �����ΰ�
	parameter	: hWnd - SHEdit Handle
	returns		:
	remarks		:
*******************************************************************************************************/
extern "C" __declspec( dllexport ) BOOL SHEdit_IsBinary( HWND hWnd );

/*******************************************************************************************************
	description	: Column Block�� �����Ǿ��°�
	parameter	: hWnd - SHEdit Handle
	returns		: Column Block�� �����Ǿ����� TRUE, �׷��� ������ FALSE�� ����
	remarks		: Column Mode��� �ϴ���, �� �ٸ� ���� ���¶�� �Ϲ� ���̴�
*******************************************************************************************************/
extern "C" __declspec( dllexport ) BOOL SHEdit_IsColumnBlock( HWND hWnd );

/*******************************************************************************************************
	description	: Column Mode�� �����Ǿ��°�
	parameter	: hWnd - SHEdit Handle
	returns		: Column Mode�� �����Ǿ����� TRUE, �׷��� ������ FALSE�� ����
	remarks		:
*******************************************************************************************************/
extern "C" __declspec( dllexport ) BOOL SHEdit_IsColumnMode( HWND hWnd );

/*******************************************************************************************************
	description	: Bookmark�� �����ϴ°�
	parameter	: hWnd - SHEdit Handle
	returns		: Bookmark�� �����Ǿ� ������ TRUE, �׷��� ������ FALSE
	remarks		:
*******************************************************************************************************/
extern "C" __declspec( dllexport ) BOOL SHEdit_IsExistBookmark( HWND hWnd );

/*******************************************************************************************************
	description	: Home key�� 1���� �ٷΰ���
	parameter	: hWnd - SHEdit Handle
	returns		: Home key�� 1���� �ٷΰ����̸� TRUE, �׷��� ������ FALSE�� ����
	remarks		:
*******************************************************************************************************/
extern "C" __declspec( dllexport ) BOOL SHEdit_IsHomeToFirstCol( HWND hWnd );

/*******************************************************************************************************
	description	: ������ ���濩�θ� �˻�
	parameter	: hWnd - SHEdit Handle
	returns		: ������ ����Ǿ����� TRUE, �׷��� ������ FALSE�� ����
	remarks		:
*******************************************************************************************************/
extern "C" __declspec( dllexport ) BOOL SHEdit_IsModified( HWND hWnd );

/*******************************************************************************************************
	description	: ���� ���� ���� ����
	parameter	: hWnd - SHEdit Handle
	returns		:
	remarks		:
*******************************************************************************************************/
extern "C" __declspec( dllexport ) BOOL SHEdit_IsReadOnly( HWND hWnd );

/*******************************************************************************************************
	description	: ���õ� ���� �����ϴ��� �˻�
	parameter	: hWnd - SHEdit Handle
	returns		: ���õ� ���� �����ϸ� TRUE, ���õ� ���� �������� ������ FALSE
	remarks		:
*******************************************************************************************************/
extern "C" __declspec( dllexport ) BOOL SHEdit_IsSelected( HWND hWnd );

/*******************************************************************************************************
	description	: ��ȣ ¦ ã��
	parameter	: hWnd - SHEdit Handle
				  bSelect - ¦ ã�� ������ ������ �ƴ��� �Ǵ�
	returns		: �����ϸ� TRUE, �׷��� ������ FALSE�� ����
	remarks		: ã�� ��� ��ȣ�� ����
					(), {}, [], <>
*******************************************************************************************************/
extern "C" __declspec( dllexport ) BOOL SHEdit_MatchBrace( HWND hWnd, BOOL bSelect );

/*******************************************************************************************************
	description	: ������ ���ڼ��� �����Ѵ�
	parameter	: hWnd - SHEdit Handle
				  nNewFormat - ���� �����Ǵ� ���ڼ�
	returns		: �����ϸ� TRUE, �����ϸ� FALSE
	remarks		: nNewFormat: 
					SHEDIT_CHARSET_ASCII			: ASCII
					SHEDIT_CHARSET_UNICODE			: Unicode( Little Endian )
					SHEDIT_CHARSET_UTF_8			: Byte Order Mark ���Ե� UTF-8
					SHEDIT_CHARSET_UTF_8_NO_BOM		: Byte Order Mark ���Ե��� ���� UTF-8
*******************************************************************************************************/
extern "C" __declspec( dllexport ) BOOL SHEdit_SetFileCharSet( HWND hWnd, int nNewCharSet );

/*******************************************************************************************************
	description	: ���� OS ���� ����
	parameter	: hWnd - SHEdit Handle
				  nNewFormat - ���� �����Ǵ� ����
	returns		: �����ϸ� TRUE, �����ϸ� FALSE
	remarks		: nNewFormat: 
					SHEDIT_FORMAT_DOS - DOS(WIN) Format
					SHEDIT_FORMAT_UNIX - Unix Format
					SHEDIT_FORMAT_MAC - Macintosh Format
					
*******************************************************************************************************/
extern "C" __declspec( dllexport ) BOOL SHEdit_SetFileFormat( HWND hWnd, int nNewFormat );

/*******************************************************************************************************
	description	: Bookmark�� ������ ����
	parameter	: hWnd - SHEdit Handle
	returns		: ������ �ϸ�ũ�� ����
	remarks		:
*******************************************************************************************************/
extern "C" __declspec( dllexport ) int SHEdit_GetBookmarkCount( HWND hWnd );

/*******************************************************************************************************
	description	: Bookmark�� Paragraph�� �迭�� �޴´�
	parameter	: hWnd - SHEdit Handle
				  pBookMarkArray - �ϸ�ũ�� ������ paramgraph�� index�� ���� �迭
	returns		: ������ �ϸ�ũ�� ����
	remarks		: ������ �ϸ�ũ��ŭ�� �迭�� ��Ƽ� �����Ƿ�,
				  �ݵ�� �ϸ�ũ�� ���� ��ŭ�� �迭 ������ Ȯ���Ұ�.
*******************************************************************************************************/
extern "C" __declspec( dllexport ) int SHEdit_GetBookmark( HWND hWnd, int* pBookMarkArray );

/*******************************************************************************************************
	description	: ���ܿ� ���� Character Index�� ���Ѵ�
	parameter	: hWnd - SHEdit Handle
				  nParaIndex - ���� Index
				  pBlock - SHEDIT_BLOCK Pointer
	returns		: ������ ���� �ε���
	remarks		: �����߻��� -1 ����
*******************************************************************************************************/
extern "C" __declspec( dllexport ) int SHEdit_GetCharIndexOfParagraph( HWND hWnd, int nParaIndex, SHEDIT_BLOCK* pBlock );

/*******************************************************************************************************
	description	: ���� ������ index�� ����
	parameter	: hWnd - SHEdit Handle
	returns		: current character index (�ɷ���ġ�� ����)
	remarks		: �����߻��� -1 ����
*******************************************************************************************************/
extern "C" __declspec( dllexport ) int SHEdit_GetCurrentCharIndex( HWND hWnd );

/*******************************************************************************************************
	description	: ���� ������ �� ���ο����� column index�� ����
	parameter	: hWnd - SHEdit Handle
	returns		: column index (�ɷ���ġ�� ����)
	remarks		: �����߻��� -1 ����
*******************************************************************************************************/
extern "C" __declspec( dllexport ) int SHEdit_GetCurrentCharColumnIndex( HWND hWnd );

/*******************************************************************************************************
	description	: ���� ������ index�� ����
	parameter	: hWnd - SHEdit Handle
	returns		: current paragraph index (�ɷ���ġ�� ���� index)
	remarks		:
*******************************************************************************************************/
extern "C" __declspec( dllexport ) int SHEdit_GetCurrentParagraphIndex( HWND hWnd );

/*******************************************************************************************************
	description	: ���� ������ �����´�
	parameter	: hWnd - SHEdit Handle
	returns		: �����Ǵ� ����
	remarks		: Format: 
					SHEDIT_CHARSET_ASCII			: ASCII
					SHEDIT_CHARSET_UNICODE			: Unicode( Little Endian )
					SHEDIT_CHARSET_UTF_8			: Byte Order Mark ���Ե� UTF-8
					SHEDIT_CHARSET_UTF_8_NO_BOM		: Byte Order Mark ���Ե��� ���� UTF-8
					
*******************************************************************************************************/
extern "C" __declspec( dllexport ) int SHEdit_GetFileCharSet( HWND hWnd );

/*******************************************************************************************************
	description	: ���� ������ �����´�
	parameter	: hWnd - SHEdit Handle
	returns		: �����Ǵ� ����
	remarks		: Format: 
					SHEDIT_FORMAT_DOS - DOS(WIN) Format
					SHEDIT_FORMAT_UNIX - Unix Format
					SHEDIT_FORMAT_MAC - Macintosh Format
					
*******************************************************************************************************/
extern "C" __declspec( dllexport ) int SHEdit_GetFileFormat( HWND hWnd );

/*******************************************************************************************************
	description	: ȭ��� ���̴� ù��° ������ index�� ���Ѵ�
	parameter	: hWnd - SHEdit Handle
	returns		: ȭ��� ���̴� ù��° ������ index
	remarks		:
*******************************************************************************************************/
extern "C" __declspec( dllexport ) int SHEdit_GetFirstVisibleLineIndex( HWND hWnd );

/*******************************************************************************************************
	description	: ���ΰ����� ���Ѵ�
	parameter	: hWnd - SHEdit Handle
	returns		:
	remarks		:
*******************************************************************************************************/
extern "C" __declspec( dllexport ) int SHEdit_GetLineCount( HWND hWnd );

/*******************************************************************************************************
	description	: �����ڵ带 �����´�
	parameter	: hWnd - SHEdit Handle
				  pBuf - ���ڸ� ������ ����
	returns		: �����ڵ��� char ���� ����
	remarks		: pBuf �� NULL �̸� ������ ������ ����
*******************************************************************************************************/
extern "C" __declspec( dllexport ) int SHEdit_GetNewLineCode( HWND hWnd, TCHAR* pBuf );

/*******************************************************************************************************
	description	: SHEdit�� ������ Text pointer�� ���̸� ����
	parameter	: hWnd - SHEdit Handle
	returns		: ������ Text pointer�� ����
	remarks		:
*******************************************************************************************************/
extern "C" __declspec( dllexport ) int SHEdit_GetTextLength( HWND hWnd );

/*******************************************************************************************************
	description	: ������ View��带 �����Ѵ�
	parameter	: hWnd - SHEdit Handle
	returns		: ������ View���
	remarks		: SHEDIT_VIEW_MODE_TEXT		: TEXT VIEW
				  SHEDIT_VIEW_MODE_HEX		: HEX VIEW
*******************************************************************************************************/
extern "C" __declspec( dllexport ) int SHEdit_GetViewMode( HWND hWnd );

/*******************************************************************************************************
	description	: ������ word wrap mode�� �˻��Ѵ�
	parameter	: hWnd - SHEdit Handle
	returns		:
	remarks		: SHEDIT_WORD_WRAP_NONE			: ����
				  SHEDIT_WORD_WRAP_CHARACTER	: ���ڴ���
*******************************************************************************************************/
extern "C" __declspec( dllexport ) int SHEdit_GetWordWrap( HWND hWnd );

/*******************************************************************************************************
	description	: ���� �ٲٱ�
	parameter	: hWnd - SHEdit Handle
				  nPos - �˻� ������ġ( -1�̸� ���� ��ġ)
				  pszFind - ã�� ���ڿ�
				  pszReplace - �ٲ� ���ڿ�
				  dwFlag - �˻� ����
	returns		: ���õ� ������ ���� ã�⸸ �ϸ� 1
				  ã��� �ٲٱ� 2
				  �˻� ���� 0
	remarks		:
				  dwFlag
					SHEDIT_FIND_UP					: ���� ã��
					SHEDIT_FIND_WHOLE_WORD			: ������ �ܾ�
					SHEDIT_FIND_MATCH_CASE			: ��ҹ��� ����
					SHEDIT_FIND_WRAP				: ã�� ���ϸ� ó�� ���� ã��
					SHEDIT_FIND_REGULAR_EXPRESSION	: ���� ǥ����
*******************************************************************************************************/
extern "C" __declspec( dllexport ) int SHEdit_ReplaceText( HWND hWnd, int nPos, TCHAR* pszFind, TCHAR* pszReplace, DWORD dwFlag );

/*******************************************************************************************************
	description	: SHEdit�� ������ Text pointer�� ����
	parameter	: hWnd - SHEdit Handle
	returns		: ������ Text pointer
	remarks		: null termination�� �������� �����Ƿ�, ������ ���̸� �ޱ� ���ؼ��� �ݵ��
				  SHEdit_GetTextLength �Լ��� ȣ���Ͽ� ���̸� Ȯ���Ұ�
*******************************************************************************************************/
extern "C" __declspec( dllexport ) TCHAR* SHEdit_GetText( HWND hWnd );

/*******************************************************************************************************
	description	: ���� ���۰� ���� �����̱�
	parameter	: hWnd - SHEdit Handle
				  pszStart - ���� ���ۿ� ���� ���ڿ� ����
				  nStartLen - ���� ���ۿ� ���� ����
				  pszEnd - ���� ���� ���� ���ڿ� ����
				  nEndLen - ���� ���� ���� ����
				  bRecordUndo - Undo ��� ����
	returns		:
	remarks		:
*******************************************************************************************************/
extern "C" __declspec( dllexport ) 
  void SHEdit_AttachOnLine( HWND hWnd,
							TCHAR* pszStart, int nStartLen,
							TCHAR* pszEnd, int nEndLen, BOOL bRecordUndo );

/*******************************************************************************************************
	description	: Bookmark
	parameter	: hWnd - SHEdit Handle
				  nParaIndex - bookmark �� paragraph (-1 �̸� ���� paragraph)
	returns		:
	remarks		:
*******************************************************************************************************/
extern "C" __declspec( dllexport ) void SHEdit_Bookmark( HWND hWnd, int nParaIndex );

/*******************************************************************************************************
	description	: ��ҹ��� ��ȯ�� �Ѵ�
	parameter	: hWnd - SHEdit Handle
				  nCase - ��ȯ ����
	returns		:
	remarks		: 0 �ҹ��ڸ� �빮�ڷ�
				  1 �빮�ڸ� �ҹ��ڷ�
				  2 ��ҹ��ڸ� �ݴ��
*******************************************************************************************************/
extern "C" __declspec( dllexport ) void SHEdit_ChangeCase( HWND hWnd, int nCase );

/*******************************************************************************************************
	description	: ��� �ϸ�ũ ����
	parameter	: hWnd - SHEdit Handle
	returns		:
	remarks		:
*******************************************************************************************************/
extern "C" __declspec( dllexport ) void SHEdit_ClearBookmark( HWND hWnd );

/*******************************************************************************************************
	description	: ������ ������ ����
	parameter	: hWnd - SHEdit Handle
				  nType - ���� ���
	returns		:
	remarks		: nType
				  0 - ��ü ����
				  1 - ������ ó���� ����
*******************************************************************************************************/
extern "C" __declspec( dllexport ) void SHEdit_ConvertSpaceToTab( HWND hWnd, int nType );

/*******************************************************************************************************
	description	: ���� �������� ��ȯ
	parameter	: hWnd - SHEdit Handle
	returns		:
	remarks		:
*******************************************************************************************************/
extern "C" __declspec( dllexport ) void SHEdit_ConvertTabToSpace( HWND hWnd );

/*******************************************************************************************************
	description	: ���� ���۰� ���� ������
	parameter	: hWnd - SHEdit Handle
				  pszStart - ���� ���ۿ��� ���� ���ڿ� ����
				  nStartLen - ���� ���ۿ��� ���� ����
				  pszEnd - ���� ������ ���� ���ڿ� ����
				  nEndLen - ���� ������ ���� ����
				  bRecordUndo - Undo ��� ����
	returns		:
	remarks		:
*******************************************************************************************************/
extern "C" __declspec( dllexport ) 
  void SHEdit_DetachOnLine( HWND hWnd, TCHAR* pszStart, int nStartLen, TCHAR* pszEnd, int nEndLen, BOOL bRecordUndo );

/*******************************************************************************************************
	description	: SHEdit�� �����Ѵ�
	parameter	: hWnd - SHEdit Handle
	returns		:
	remarks		:
*******************************************************************************************************/
extern "C" __declspec( dllexport ) void SHEdit_Destroy( HWND hWnd );

/*******************************************************************************************************
	description	: �ٹ�ȣ ǥ�� ���� ����
	parameter	: hWnd - SHEdit Handle
				  bEnable - �ٹ�ȣ�� ���ϰ����� ���������� �����ϴ� flag
	returns		:
	remarks		:
*******************************************************************************************************/
extern "C" __declspec( dllexport ) void SHEdit_EnableLineNo( HWND hWnd, BOOL bEnable );

/*******************************************************************************************************
	description	: ������ ǥ��
	parameter	: hWnd - SHEdit Handle
				  bEnable - �����ڸ� ���ϰ����� ���������� �����ϴ� flag
	returns		:
	remarks		:
*******************************************************************************************************/
extern "C" __declspec( dllexport ) void SHEdit_EnableRuler( HWND hWnd, BOOL bEnable );

/*******************************************************************************************************
	description	: ���� ����
	parameter	: hWnd - SHEdit Handle
				  bEnable - ������ ���ϰ����� ���������� �����ϴ� flag
	returns		:
	remarks		:
*******************************************************************************************************/
extern "C" __declspec( dllexport ) void SHEdit_EnableSelectionMargin( HWND hWnd, BOOL bEnable );

/*******************************************************************************************************
	description	: ���� ���� ��뿩�� ����
	parameter	: hWnd - SHEdit Handle
				  bEnable - ���� ���� ��뿩��
	returns		:
	remarks		:
*******************************************************************************************************/
extern "C" __declspec( dllexport ) void SHEdit_EnableVirtualSpace( HWND hWnd, BOOL bEnable );

/*******************************************************************************************************
	description	: ���� ���� ���۰� ���� ���Ѵ�
	parameter	: hWnd - SHEdit Handle
				  pBlock - SHEDIT_BLOCK Pointer
	returns		:
	remarks		:
*******************************************************************************************************/
extern "C" __declspec( dllexport ) void SHEdit_GetBlock( HWND hWnd, SHEDIT_BLOCK* pBlock );

/*******************************************************************************************************
	description	: ���� ���� �� ���� �϶�, ù��° ���� BYTE ���� ���Ѵ�
	parameter	: hWnd - SHEdit Handle
				  pnCount - ���õ� ���� byte ���� ���� Pointer
	returns		:
	remarks		:
*******************************************************************************************************/
extern "C" __declspec( dllexport ) void SHEdit_GetBlockColumnCount( HWND hWnd, int* pnCount );

/*******************************************************************************************************
	description	: �־��� ��ġ�� �ܾ �˻�
	parameter	: hWnd - SHEdit Handle
				  nPos - �˻��Ϸ��� ��ġ
				  pBlock - SHEDIT_BLOCK Pointer
	returns		:
	remarks		:
*******************************************************************************************************/
extern "C" __declspec( dllexport ) void SHEdit_GetCurrentWord( HWND hWnd, int nPos, SHEDIT_BLOCK* pBlock );

/*******************************************************************************************************
	description	: �־��� ��ġ�� ���ο��� ������ �ܾ �˻� �ܾ�
	parameter	: hWnd - SHEdit Handle
				  nPos - �˻��Ϸ��� ��ġ
				  pBlock - SHEDIT_BLOCK Pointer
	returns		:
	remarks		: �̰��� �˻� ������ġ���� ������ ������ ���ڸ� �ܾ�� �Ǵ��Ѵ�
*******************************************************************************************************/
extern "C" __declspec( dllexport ) void SHEdit_GetCurrentWordInLine( HWND hWnd, int nPos, SHEDIT_BLOCK* pBlock );

/*******************************************************************************************************
	description	: ������ �޴´�
	parameter	: hWnd - SHEdit Handle
				  pszBuffer - ������ ���� ����
	returns		:
	remarks		: nBufferSize - null termination �� ���̰� ���Ե��� ���� ������ ����
*******************************************************************************************************/
extern "C" __declspec( dllexport ) void SHEdit_GetTextRange( HWND hWnd, LPTSTR pszBuffer, int nBufferSize, int nStart, int nEnd );

/*******************************************************************************************************
	description	: ������ �޴´�
	parameter	: hWnd - SHEdit Handle
				  pszBuffer - ������ ���� ����
	returns		: nBufferSize - null termination �� ���̰� ���Ե��� ���� ������ ����
	remarks		: nCharSet �� -1 �̸�, ���� ������ ���ڼ��� �����Ѵ�
*******************************************************************************************************/
extern "C" __declspec( dllexport ) void SHEdit_GetTextRangeEx( HWND hWnd, LPTSTR pszBuffer, int nBufferSize, int nStart, int nEnd, int nCharSet );

/*******************************************************************************************************
	description	: å������ġ�� �̵�
	parameter	: hWnd - SHEdit Handle
				  bDown - ���� ��ġ������ å���Ǹ� ã���� ����
	returns		:
	remarks		:
*******************************************************************************************************/
extern "C" __declspec( dllexport ) void SHEdit_GotoBookmark( HWND hWnd, BOOL bDown );

/*******************************************************************************************************
	description	: ���ڿ��� �����Ѵ�
	parameter	: hWnd - SHEdit Handle
				  pstr - ���ڿ� ������
				  len - pstr length
				  bRecordUndo - Undo ��� ����
	returns		:
	remarks		: ���� ĳ���� ��ġ�� ����
*******************************************************************************************************/
extern "C" __declspec( dllexport ) void SHEdit_Insert( HWND hWnd, TCHAR* pstr, int len, BOOL bRecordUndo );

/*******************************************************************************************************
	description	: SHEdit�� ��� ���� �ʱ�ȭ
	parameter	: hWnd - SHEdit Handle
	returns		:
	remarks		:
*******************************************************************************************************/
extern "C" __declspec( dllexport ) void SHEdit_Reset( HWND hWnd );

/*******************************************************************************************************
	description	: Ȱ���� ���� �����Ѵ�
	parameter	: hWnd - SHEdit Handle
				  clr - Ȱ���� ���� �����Ѵ�
	returns		:
	remarks		:
*******************************************************************************************************/
extern "C" __declspec( dllexport ) void SHEdit_SetActiveLineColor( HWND hWnd, COLORREF clr );

/*******************************************************************************************************
	description	: Ȱ���� ǥ�� ����� ����
	parameter	: hWnd - SHEdit Handle
				  nType - ���� type
	returns		:
	remarks		: type  SHEDIT_ACTIVE_LINE_NONE - ǥ�� ��� ����
						SHEDIT_ACTIVE_LINE_RECTANGLE - �簢 ���� �ѷ��α�
						SHEDIT_ACTIVE_LINE_FILL_BACK - �������� ä���
						SHEDIT_ACTIVE_LINE_DRAW_MARGIN - ���ÿ��鿡 ǥ��
*******************************************************************************************************/
extern "C" __declspec( dllexport ) void SHEdit_SetActiveLineType( HWND hWnd, int nType );

/*******************************************************************************************************
	description	: �ڵ� �鿩���� ����
	parameter	: hWnd - SHEdit Handle
				  bIndent - �ڵ� �鿩���� ����
	returns		:
	remarks		:
*******************************************************************************************************/
extern "C" __declspec( dllexport ) void SHEdit_SetAutoIndentation( HWND hWnd, BOOL bIndent );

/*******************************************************************************************************
	description	: �ڵ� ���� ��� ����
	parameter	: hWnd - SHEdit Handle
				  bAuto - �ڵ� ���� ����
	returns		:
	remarks		:
*******************************************************************************************************/
extern "C" __declspec( dllexport ) void SHEdit_SetAutoSelect( HWND hWnd, BOOL bAuto );

/*******************************************************************************************************
	description	: ������ �����Ѵ�
	parameter	: hWnd - SHEdit Handle
				  clr - ������ �����Ѵ�
	returns		:
	remarks		:
*******************************************************************************************************/
extern "C" __declspec( dllexport ) void SHEdit_SetBackColor( HWND hWnd, COLORREF clr );

/*******************************************************************************************************
	description	: å���ǻ��� �����Ѵ�
	parameter	: hWnd - SHEdit Handle
				  clr - å���ǻ�
	returns		:
	remarks		:
*******************************************************************************************************/
extern "C" __declspec( dllexport ) void SHEdit_SetBookmarkColor( HWND hWnd, COLORREF clr );

/*******************************************************************************************************
	description	: å���� ���ڻ��� �����Ѵ�
	parameter	: hWnd - SHEdit Handle
				  clr - å���� ���ڻ�
	returns		:
	remarks		:
*******************************************************************************************************/
extern "C" __declspec( dllexport ) void SHEdit_SetBookmarkForeColor( HWND hWnd, COLORREF clr );

/*******************************************************************************************************
	description	: ��ȣ ǥ�� �� ����
	parameter	: hWnd - SHEdit Handle
				  clr - ��ȣ ǥ�� ��
	returns		:
	remarks		:
*******************************************************************************************************/
extern "C" __declspec( dllexport ) void SHEdit_SetCodeColor( HWND hWnd, COLORREF clr );

/*******************************************************************************************************
	description	: Column Mode�� ����
	parameter	: hWnd - SHEdit Handle
				  bColumn - �÷� ���
	returns		:
	remarks		:
*******************************************************************************************************/
extern "C" __declspec( dllexport ) void SHEdit_SetColumnMode( HWND hWnd, BOOL bColumn );

/*******************************************************************************************************
	description	: ���� ǥ�� �� ����
	parameter	: hWnd - SHEdit Handle
				  clr - ���� ǥ�� ��
	returns		:
	remarks		:
*******************************************************************************************************/
extern "C" __declspec( dllexport ) void SHEdit_SetCurrentTagColor( HWND hWnd, COLORREF clr );

/*******************************************************************************************************
	description	: ���� ǥ�� ���ڻ� ����
	parameter	: hWnd - SHEdit Handle
				  clr - ���� ǥ�� ��
	returns		:
	remarks		:
*******************************************************************************************************/
extern "C" __declspec( dllexport ) void SHEdit_SetCurrentTagForeColor( HWND hWnd, COLORREF clr );

/*******************************************************************************************************
	description	: ���� ǥ�� ����
	parameter	: hWnd - SHEdit Handle
				  nLineIndex - �����Ϸ��� line index
	returns		:
	remarks		: line index�� -1�� �����ϸ� ���� ǥ�� ����
*******************************************************************************************************/
extern "C" __declspec( dllexport ) void SHEdit_SetCurrentTag( HWND hWnd, int nLineIndex );

/*******************************************************************************************************
	description	: �ܾ� �����ڸ� �����Ѵ�
	parameter	: hWnd - SHEdit Handle
				  pszDelimiterString - ������ ���ڿ�
	returns		:
	remarks		:
*******************************************************************************************************/
extern "C" __declspec( dllexport ) void SHEdit_SetDelimiter( HWND hWnd, TCHAR* pszDelimiterString );

/*******************************************************************************************************
	description	: ��Ʈ ����
	parameter	: hWnd - SHEdit Handle
				  pLogFont - Font
	returns		:
	remarks		: ��Ʈ�� �����ϸ� ��� View�� ���� ����ȴ�
*******************************************************************************************************/
extern "C" __declspec( dllexport ) void SHEdit_SetFont( HWND hWnd, LOGFONT* pLogFont );

/*******************************************************************************************************
	description	: Hex ��Ʈ ����
	parameter	: hWnd - SHEdit Handle
				  pLogFont - Font
	returns		:
	remarks		: ��Ʈ�� �����ϸ� ��� View�� ���� ����ȴ�
*******************************************************************************************************/
extern "C" __declspec( dllexport ) void SHEdit_SetFontHex( HWND hWnd, LOGFONT* pLogFontHex );

/*******************************************************************************************************
	description	: ������� �����Ѵ�
	parameter	: hWnd - SHEdit Handle
				  clr - �����
	returns		:
	remarks		:
*******************************************************************************************************/
extern "C" __declspec( dllexport ) void SHEdit_SetForeColor( HWND hWnd, COLORREF clr );

/*******************************************************************************************************
	description	: Home Key�� 1���� �ٷΰ��� ����
	parameter	: hWnd - SHEdit Handle
				  b - Home Key�� 1���� �ٷΰ���
	returns		:
	remarks		:
*******************************************************************************************************/
extern "C" __declspec( dllexport ) void SHEdit_SetHomeToFirstCol( HWND hWnd, BOOL b );

/*******************************************************************************************************
	description	: �ִ� Undo Record ũ�� ����
	parameter	: hWnd - SHEdit Handle
				  size - ���� ũ��
	returns		:
	remarks		: size�� ����Ʈ �����̴�
*******************************************************************************************************/
extern "C" __declspec( dllexport ) void SHEdit_SetMaxUndoSize( HWND hWnd, int size );

/*******************************************************************************************************
	description	: �� ���� ����
	parameter	: hWnd - SHEdit Handle
				  nLineSpacing - �� ����( % )
	returns		:
	remarks		:
*******************************************************************************************************/
extern "C" __declspec( dllexport ) void SHEdit_SetLineSpacing( HWND hWnd, int nLineSpacing );

/*******************************************************************************************************
	description	: ���� ���� ����
	parameter	: hWnd - SHEdit Handle
				  bMod - ���� ����
	returns		:
	remarks		:
*******************************************************************************************************/
extern "C" __declspec( dllexport ) void SHEdit_SetModified( HWND hWnd, BOOL bMod );

/*******************************************************************************************************
	description	: Insert mode, ovrewrite mode �� ����
	parameter	: hWnd - SHEdit Handle
				  bOvr - TRUE �̸� overwrite mode, FALSE�̸� insert mode
	returns		:
	remarks		:
*******************************************************************************************************/
extern "C" __declspec( dllexport ) void SHEdit_SetOverwriteMode( HWND hWnd, BOOL bOvr );

/*******************************************************************************************************
	description	: ���� ���� ��� ����
	parameter	: hWnd - SHEdit Handle
				  bReadOnly - ���� ���� ����
	returns		:
	remarks		:
*******************************************************************************************************/
extern "C" __declspec( dllexport ) void SHEdit_SetReadOnly( HWND hWnd, BOOL bReadOnly );

/*******************************************************************************************************
	description	: ���� ���û��·� �����
	parameter	: hWnd - SHEdit Handle
				  nStartChar - ���� ��ġ
				  nEndChar - ���� ��ġ
				  bNoScroll - ĳ���� ���õ� ��ġ�� ��ũ�� �Ǿ� ������ �ʵ��� ����
	returns		:
	remarks		: nStartChar�� 0 �̰�, nEndChar�� -1�̸� ��ü ���û����̸�,
				  nStartChar -1�̸� ���� ���õ� ������ ���ŵȴ�
*******************************************************************************************************/
extern "C" __declspec( dllexport ) void SHEdit_SetSel( HWND hWnd, int nStartChar, int nEndChar, BOOL bNoScroll );

/*******************************************************************************************************
	description	: ���ÿ����� ����
	parameter	: hWnd - SHEdit Handle
				  clr - ���ÿ�����
	returns		:
	remarks		:
*******************************************************************************************************/
extern "C" __declspec( dllexport ) void SHEdit_SetSelBackColor( HWND hWnd, COLORREF clr );

/*******************************************************************************************************
	description	: ���ÿ��� ����� ����
	parameter	: hWnd - SHEdit Handle
				  clr - ���ÿ��� �����
	returns		:
	remarks		:
*******************************************************************************************************/
extern "C" __declspec( dllexport ) void SHEdit_SetSelForeColor( HWND hWnd, COLORREF clr );

/*******************************************************************************************************
	description	: �ٹ�ȣ ��»��� �����Ѵ�
	parameter	: hWnd - SHEdit Handle
				  clr - �ٹ�ȣ ��»�
	returns		:
	remarks		:
*******************************************************************************************************/
extern "C" __declspec( dllexport ) void SHEdit_SetLineNoColor( HWND hWnd, COLORREF clr );

/*******************************************************************************************************
	description	: ���� �����ϰ� �� �鿩���� ��� ����
	parameter	: hWnd - SHEdit Handle
				  bSkip - ��� ����
	returns		:
	remarks		:
*******************************************************************************************************/
extern "C" __declspec( dllexport ) void SHEdit_SetSkipEmptyLineOnBlockIndent( HWND hWnd, BOOL bSkip );

/*******************************************************************************************************
	description	: �� ũ�� ����
	parameter	: hWnd - SHEdit Handle
				  nSize - �� ũ��
	returns		:
	remarks		: �� ũ��� �����̽� ����
*******************************************************************************************************/
extern "C" __declspec( dllexport ) void SHEdit_SetTabSize( HWND hWnd, int nSize );

/*******************************************************************************************************
	description	: �ǹ��ڸ� ���鹮�ڷ� ��ü
	parameter	: hWnd - SHEdit Handle
				  bTabToSpace - �� ����
	returns		:
	remarks		:
*******************************************************************************************************/
extern "C" __declspec( dllexport ) void SHEdit_SetTabToSpace( HWND hWnd, BOOL bTabToSpace );

/*******************************************************************************************************
	description	: SHEdit�� ���뼳��
	parameter	: hWnd - SHEdit Handle
				  pszStr - ������ ���ڿ�
				  dwLen - ������ ���ڿ� ����
	returns		:
	remarks		: �ݵ�� null termination �� �ʿ����� �ʴ�
*******************************************************************************************************/
extern "C" __declspec( dllexport ) void SHEdit_SetText( HWND hWnd, TCHAR* pszStr, DWORD dwLen );

/*******************************************************************************************************
	description	: ���뼳��
	parameter	: hWnd - SHEdit Handle
				  lpszString - ������ ���ڿ�
				  dwLen - ���ڿ� ����
				  nCharSet - ���ڼ�
	returns		:
	remarks		: ������ ������ �м��Ͽ� �����Ѵ�
				  nCharSet
				  SHEDIT_CHARSET_UNDEFINED		: �������� ����
				  SHEDIT_CHARSET_ASCII			: ASCII
				  SHEDIT_CHARSET_UNICODE		: Unicode( Little Endian )
				  SHEDIT_CHARSET_UTF_8			: Byte Order Mark ���Ե� UTF-8
				  SHEDIT_CHARSET_UTF_8_NO_BOM	: Byte Order Mark ���Ե��� ���� UTF-8

*******************************************************************************************************/
extern "C" __declspec( dllexport ) void SHEdit_SetTextEx( HWND hWnd, LPTSTR lpszString, DWORD dwLen, int nCharSet );

/*******************************************************************************************************
	description	: View�� �����Ѵ�
	parameter	: hWnd - SHEdit Handle
				  nNewMode - ���� ���� �� View ���
	returns		:
	remarks		: SHEDIT_VIEW_MODE_TEXT		: TEXT VIEW
				  SHEDIT_VIEW_MODE_HEX		: HEX VIEW
*******************************************************************************************************/
extern "C" __declspec( dllexport ) void SHEdit_SetViewMode( HWND hWnd, int nNewMode );

/*******************************************************************************************************
	description	: Word wrap mode�� ����
	parameter	: hWnd - SHEdit Handle
				  nMode - ���μ����Ǵ� mode
	returns		:
	remarks		: SHEDIT_WORD_WRAP_NONE			: ����
				  SHEDIT_WORD_WRAP_CHARACTER	: ���ڴ���
*******************************************************************************************************/
extern "C" __declspec( dllexport ) void SHEdit_SetWordWrap( HWND hWnd, int nMode );

/*******************************************************************************************************
	description	: �ܶ� ��ȣ ǥ��
	parameter	: hWnd - SHEdit Handle
				  bShow - �ܶ� ��ȣ ǥ�� ����
	returns		:
	remarks		:
*******************************************************************************************************/
extern "C" __declspec( dllexport ) void SHEdit_ShowBreakCode( HWND hWnd, BOOL bShow );

/*******************************************************************************************************
	description	: ���� ��ȣ ǥ��
	parameter	: hWnd - SHEdit Handle
				  bShow - ���� ��ȣ ǥ�� ����
	returns		:
	remarks		:
*******************************************************************************************************/
extern "C" __declspec( dllexport ) void SHEdit_ShowWhiteSpaceCode( HWND hWnd, BOOL bShow );

/*******************************************************************************************************
	description	: Column Mode�� ����/ �����Ѵ�
	parameter	: hWnd - SHEdit Handle
	returns		:
	remarks		:
*******************************************************************************************************/
extern "C" __declspec( dllexport ) void SHEdit_ToggleColumnMode( HWND hWnd );

/*******************************************************************************************************
	description	: �ٳ� ��������
	parameter	: hWnd - SHEdit Handle
	returns		:
	remarks		:
*******************************************************************************************************/
extern "C" __declspec( dllexport ) void SHEdit_TrimTrailingWhiteSpace( HWND hWnd );

#endif // __SHEDITCTRL_H__
