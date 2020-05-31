#ifndef __SHEDITCTRL_H__
#define __SHEDITCTRL_H__

/*//////////////////////////////////////////////////////////////////////////////////////////////////////
SHEditCtrl
	- DesyEdit에 포함된 Edit Engine

2005. 07. 21
제작자: 김세훈

  이 프로그램의 모든 권리는 제작자에게 있으며,
  상업적 목적으로 프로그램을 수정 배포하는 행위를 금합니다.
//////////////////////////////////////////////////////////////////////////////////////////////////////*/

#include <windows.h>

#define SHEDIT_ACTIVE_LINE_NONE				0
#define SHEDIT_ACTIVE_LINE_RECTANGLE		1
#define SHEDIT_ACTIVE_LINE_DRAW_MARGIN		2
#define SHEDIT_ACTIVE_LINE_FILL_BACK		3

#define SHEDIT_CHARSET_UNDEFINED			-1	// 지정되지 않음
#define SHEDIT_CHARSET_ASCII				0
#define SHEDIT_CHARSET_UNICODE				1	// Little Endian
#define SHEDIT_CHARSET_UTF_8				2
#define SHEDIT_CHARSET_UTF_8_NO_BOM			3

#define SHEDIT_FORMAT_DOS					1
#define SHEDIT_FORMAT_UNIX					2
#define SHEDIT_FORMAT_MAC					3

#define SHEDIT_VIEW_MODE_TEXT				0
#define SHEDIT_VIEW_MODE_HEX				1

#define SHEDIT_WORD_WRAP_NONE			0	// 없음
#define SHEDIT_WORD_WRAP_CHARACTER		1	// 문자단위

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
	description	: SHEdit를 생성한다
	parameter	: hParent - 부모 윈도우 핸들
				  nid - resource id
				  x - x 좌표
				  y - y 좌표
				  width - 너비
				  height - 높이
				  exstyle - 생성에 사용할 확장 스타일
				  style - 생성에 사용할 스타일
	returns		: 성공하면 SHEdit의 Handle, 실패하면 NULL
	remarks		:
*******************************************************************************************************/
extern "C" __declspec( dllexport )
  HWND SHEdit_Create( HWND hParent, UINT nid, int x, int y, int width, int height,
					  DWORD exstyle = WS_EX_CLIENTEDGE,
					  DWORD style = WS_CHILD | WS_VISIBLE | WS_HSCROLL | WS_VSCROLL
				 );


/*******************************************************************************************************
	description	: Redo가 가능한지 판단
	parameter	: hWnd - SHEdit Handle
	returns		:
	remarks		:
*******************************************************************************************************/
extern "C" __declspec( dllexport ) BOOL SHEdit_CanRedo( HWND hWnd );

/*******************************************************************************************************
	description	: Undo가 가능한지 판단
	parameter	: hWnd - SHEdit Handle
	returns		:
	remarks		:
*******************************************************************************************************/
extern "C" __declspec( dllexport ) BOOL SHEdit_CanUndo( HWND hWnd );

/*******************************************************************************************************
	description	: 붙여 넣기가 가능한 상태인지 검사
	parameter	: hWnd - SHEdit Handle
	returns		: 붙여 넣기가 가능한 상태이면 TRUE, 그렇지 않으면 FALSE
	remarks		:
*******************************************************************************************************/
extern "C" __declspec( dllexport ) BOOL SHEdit_EnablePaste( HWND hWnd );

/*******************************************************************************************************
	description	: 문자검색
	parameter	: hWnd - SHEdit Handle
				  nPos - 검색 시작위치( -1이면 현재 위치)
				  pszFind - 찾을 문자열
				  dwFlag - 검색 조건
	returns		: 검색에 성공하며 TRUE, 실패하면 FALSE
	remarks		:
				  dwFlag
					SHEDIT_FIND_UP					: 위로 찾기
					SHEDIT_FIND_WHOLE_WORD			: 완전한 단어
					SHEDIT_FIND_MATCH_CASE			: 대소문자 구분
					SHEDIT_FIND_WRAP				: 찾지 못하면 처음 부터 찾기
					SHEDIT_FIND_REGULAR_EXPRESSION	: 정규 표현식
*******************************************************************************************************/
extern "C" __declspec( dllexport ) BOOL SHEdit_FindText( HWND hWnd, int nPos, TCHAR* pszFind, DWORD dwFlag );

/*******************************************************************************************************
	description	: Autoselect Mode가 설정되었는가
	parameter	: hWnd - SHEdit Handle
	returns		: Autoselect Mode가 설정되었으면 TRUE, 그렇지 않으면 FALSE를 리턴
	remarks		:
*******************************************************************************************************/
extern "C" __declspec( dllexport ) BOOL SHEdit_IsAutoSelectMode( HWND hWnd );

/*******************************************************************************************************
	description	: 바이너리 파일 편집인가
	parameter	: hWnd - SHEdit Handle
	returns		:
	remarks		:
*******************************************************************************************************/
extern "C" __declspec( dllexport ) BOOL SHEdit_IsBinary( HWND hWnd );

/*******************************************************************************************************
	description	: Column Block이 설정되었는가
	parameter	: hWnd - SHEdit Handle
	returns		: Column Block이 설정되었으면 TRUE, 그렇지 않으면 FALSE를 리턴
	remarks		: Column Mode라고 하더라도, 한 줄만 선택 상태라면 일반 블럭이다
*******************************************************************************************************/
extern "C" __declspec( dllexport ) BOOL SHEdit_IsColumnBlock( HWND hWnd );

/*******************************************************************************************************
	description	: Column Mode가 설정되었는가
	parameter	: hWnd - SHEdit Handle
	returns		: Column Mode가 설정되었으면 TRUE, 그렇지 않으면 FALSE를 리턴
	remarks		:
*******************************************************************************************************/
extern "C" __declspec( dllexport ) BOOL SHEdit_IsColumnMode( HWND hWnd );

/*******************************************************************************************************
	description	: Bookmark가 존재하는가
	parameter	: hWnd - SHEdit Handle
	returns		: Bookmark가 설정되어 있으면 TRUE, 그렇지 않으면 FALSE
	remarks		:
*******************************************************************************************************/
extern "C" __declspec( dllexport ) BOOL SHEdit_IsExistBookmark( HWND hWnd );

/*******************************************************************************************************
	description	: Home key는 1열로 바로가기
	parameter	: hWnd - SHEdit Handle
	returns		: Home key는 1열로 바로가기이면 TRUE, 그렇지 않으면 FALSE를 리턴
	remarks		:
*******************************************************************************************************/
extern "C" __declspec( dllexport ) BOOL SHEdit_IsHomeToFirstCol( HWND hWnd );

/*******************************************************************************************************
	description	: 내용의 변경여부를 검사
	parameter	: hWnd - SHEdit Handle
	returns		: 내용이 변경되었으면 TRUE, 그렇지 않으면 FALSE를 리턴
	remarks		:
*******************************************************************************************************/
extern "C" __declspec( dllexport ) BOOL SHEdit_IsModified( HWND hWnd );

/*******************************************************************************************************
	description	: 편집 가능 여부 조사
	parameter	: hWnd - SHEdit Handle
	returns		:
	remarks		:
*******************************************************************************************************/
extern "C" __declspec( dllexport ) BOOL SHEdit_IsReadOnly( HWND hWnd );

/*******************************************************************************************************
	description	: 선택된 블럭이 존재하는지 검사
	parameter	: hWnd - SHEdit Handle
	returns		: 선택된 블럭이 존재하면 TRUE, 선택된 블럭이 존재하지 않으면 FALSE
	remarks		:
*******************************************************************************************************/
extern "C" __declspec( dllexport ) BOOL SHEdit_IsSelected( HWND hWnd );

/*******************************************************************************************************
	description	: 괄호 짝 찾기
	parameter	: hWnd - SHEdit Handle
				  bSelect - 짝 찾아 선택할 것인지 아닌지 판단
	returns		: 성공하면 TRUE, 그렇지 않으면 FALSE를 리턴
	remarks		: 찾기 대상 괄호의 종류
					(), {}, [], <>
*******************************************************************************************************/
extern "C" __declspec( dllexport ) BOOL SHEdit_MatchBrace( HWND hWnd, BOOL bSelect );

/*******************************************************************************************************
	description	: 문서의 문자셋을 설정한다
	parameter	: hWnd - SHEdit Handle
				  nNewFormat - 새로 설정되는 문자셋
	returns		: 성공하면 TRUE, 실패하면 FALSE
	remarks		: nNewFormat: 
					SHEDIT_CHARSET_ASCII			: ASCII
					SHEDIT_CHARSET_UNICODE			: Unicode( Little Endian )
					SHEDIT_CHARSET_UTF_8			: Byte Order Mark 포함된 UTF-8
					SHEDIT_CHARSET_UTF_8_NO_BOM		: Byte Order Mark 포함되지 않은 UTF-8
*******************************************************************************************************/
extern "C" __declspec( dllexport ) BOOL SHEdit_SetFileCharSet( HWND hWnd, int nNewCharSet );

/*******************************************************************************************************
	description	: 문서 OS 포맷 설정
	parameter	: hWnd - SHEdit Handle
				  nNewFormat - 새로 설정되는 포멧
	returns		: 성공하면 TRUE, 실패하면 FALSE
	remarks		: nNewFormat: 
					SHEDIT_FORMAT_DOS - DOS(WIN) Format
					SHEDIT_FORMAT_UNIX - Unix Format
					SHEDIT_FORMAT_MAC - Macintosh Format
					
*******************************************************************************************************/
extern "C" __declspec( dllexport ) BOOL SHEdit_SetFileFormat( HWND hWnd, int nNewFormat );

/*******************************************************************************************************
	description	: Bookmark의 개수를 리턴
	parameter	: hWnd - SHEdit Handle
	returns		: 설정된 북마크의 개수
	remarks		:
*******************************************************************************************************/
extern "C" __declspec( dllexport ) int SHEdit_GetBookmarkCount( HWND hWnd );

/*******************************************************************************************************
	description	: Bookmark된 Paragraph의 배열을 받는다
	parameter	: hWnd - SHEdit Handle
				  pBookMarkArray - 북마크가 설정된 paramgraph의 index를 받을 배열
	returns		: 설정된 북마크의 개수
	remarks		: 설정된 북마크만큼을 배열에 담아서 보내므로,
				  반드시 북마크의 개수 만큼의 배열 공간을 확보할것.
*******************************************************************************************************/
extern "C" __declspec( dllexport ) int SHEdit_GetBookmark( HWND hWnd, int* pBookMarkArray );

/*******************************************************************************************************
	description	: 문단에 속한 Character Index를 구한다
	parameter	: hWnd - SHEdit Handle
				  nParaIndex - 문단 Index
				  pBlock - SHEDIT_BLOCK Pointer
	returns		: 문단의 라인 인덱스
	remarks		: 오류발생시 -1 리턴
*******************************************************************************************************/
extern "C" __declspec( dllexport ) int SHEdit_GetCharIndexOfParagraph( HWND hWnd, int nParaIndex, SHEDIT_BLOCK* pBlock );

/*******************************************************************************************************
	description	: 현재 문자의 index를 리턴
	parameter	: hWnd - SHEdit Handle
	returns		: current character index (케럿위치의 문자)
	remarks		: 오류발생시 -1 리턴
*******************************************************************************************************/
extern "C" __declspec( dllexport ) int SHEdit_GetCurrentCharIndex( HWND hWnd );

/*******************************************************************************************************
	description	: 현재 문자의 현 라인에서의 column index를 리턴
	parameter	: hWnd - SHEdit Handle
	returns		: column index (케럿위치의 문자)
	remarks		: 오류발생시 -1 리턴
*******************************************************************************************************/
extern "C" __declspec( dllexport ) int SHEdit_GetCurrentCharColumnIndex( HWND hWnd );

/*******************************************************************************************************
	description	: 현재 문단의 index를 리턴
	parameter	: hWnd - SHEdit Handle
	returns		: current paragraph index (케럿위치의 문단 index)
	remarks		:
*******************************************************************************************************/
extern "C" __declspec( dllexport ) int SHEdit_GetCurrentParagraphIndex( HWND hWnd );

/*******************************************************************************************************
	description	: 문서 포멧을 가져온다
	parameter	: hWnd - SHEdit Handle
	returns		: 설정되는 포멧
	remarks		: Format: 
					SHEDIT_CHARSET_ASCII			: ASCII
					SHEDIT_CHARSET_UNICODE			: Unicode( Little Endian )
					SHEDIT_CHARSET_UTF_8			: Byte Order Mark 포함된 UTF-8
					SHEDIT_CHARSET_UTF_8_NO_BOM		: Byte Order Mark 포함되지 않은 UTF-8
					
*******************************************************************************************************/
extern "C" __declspec( dllexport ) int SHEdit_GetFileCharSet( HWND hWnd );

/*******************************************************************************************************
	description	: 문서 포멧을 가져온다
	parameter	: hWnd - SHEdit Handle
	returns		: 설정되는 포멧
	remarks		: Format: 
					SHEDIT_FORMAT_DOS - DOS(WIN) Format
					SHEDIT_FORMAT_UNIX - Unix Format
					SHEDIT_FORMAT_MAC - Macintosh Format
					
*******************************************************************************************************/
extern "C" __declspec( dllexport ) int SHEdit_GetFileFormat( HWND hWnd );

/*******************************************************************************************************
	description	: 화면상에 보이는 첫번째 라인의 index를 구한다
	parameter	: hWnd - SHEdit Handle
	returns		: 화면상에 보이는 첫번째 라인의 index
	remarks		:
*******************************************************************************************************/
extern "C" __declspec( dllexport ) int SHEdit_GetFirstVisibleLineIndex( HWND hWnd );

/*******************************************************************************************************
	description	: 라인개수를 구한다
	parameter	: hWnd - SHEdit Handle
	returns		:
	remarks		:
*******************************************************************************************************/
extern "C" __declspec( dllexport ) int SHEdit_GetLineCount( HWND hWnd );

/*******************************************************************************************************
	description	: 개행코드를 가져온다
	parameter	: hWnd - SHEdit Handle
				  pBuf - 문자를 복사할 버퍼
	returns		: 개행코드의 char 수를 리턴
	remarks		: pBuf 가 NULL 이면 문자의 개수만 리턴
*******************************************************************************************************/
extern "C" __declspec( dllexport ) int SHEdit_GetNewLineCode( HWND hWnd, TCHAR* pBuf );

/*******************************************************************************************************
	description	: SHEdit에 설정된 Text pointer의 길이를 리턴
	parameter	: hWnd - SHEdit Handle
	returns		: 설정된 Text pointer의 길이
	remarks		:
*******************************************************************************************************/
extern "C" __declspec( dllexport ) int SHEdit_GetTextLength( HWND hWnd );

/*******************************************************************************************************
	description	: 설정된 View모드를 조사한다
	parameter	: hWnd - SHEdit Handle
	returns		: 설정된 View모드
	remarks		: SHEDIT_VIEW_MODE_TEXT		: TEXT VIEW
				  SHEDIT_VIEW_MODE_HEX		: HEX VIEW
*******************************************************************************************************/
extern "C" __declspec( dllexport ) int SHEdit_GetViewMode( HWND hWnd );

/*******************************************************************************************************
	description	: 설정된 word wrap mode를 검색한다
	parameter	: hWnd - SHEdit Handle
	returns		:
	remarks		: SHEDIT_WORD_WRAP_NONE			: 없음
				  SHEDIT_WORD_WRAP_CHARACTER	: 문자단위
*******************************************************************************************************/
extern "C" __declspec( dllexport ) int SHEdit_GetWordWrap( HWND hWnd );

/*******************************************************************************************************
	description	: 문자 바꾸기
	parameter	: hWnd - SHEdit Handle
				  nPos - 검색 시작위치( -1이면 현재 위치)
				  pszFind - 찾을 문자열
				  pszReplace - 바꿀 문자열
				  dwFlag - 검색 조건
	returns		: 선택된 내용이 없어 찾기만 하면 1
				  찾기와 바꾸기 2
				  검색 실패 0
	remarks		:
				  dwFlag
					SHEDIT_FIND_UP					: 위로 찾기
					SHEDIT_FIND_WHOLE_WORD			: 완전한 단어
					SHEDIT_FIND_MATCH_CASE			: 대소문자 구분
					SHEDIT_FIND_WRAP				: 찾지 못하면 처음 부터 찾기
					SHEDIT_FIND_REGULAR_EXPRESSION	: 정규 표현식
*******************************************************************************************************/
extern "C" __declspec( dllexport ) int SHEdit_ReplaceText( HWND hWnd, int nPos, TCHAR* pszFind, TCHAR* pszReplace, DWORD dwFlag );

/*******************************************************************************************************
	description	: SHEdit에 설정된 Text pointer를 리턴
	parameter	: hWnd - SHEdit Handle
	returns		: 설정된 Text pointer
	remarks		: null termination은 존재하지 않으므로, 설정된 길이를 받기 위해서는 반드시
				  SHEdit_GetTextLength 함수를 호출하여 길이를 확인할것
*******************************************************************************************************/
extern "C" __declspec( dllexport ) TCHAR* SHEdit_GetText( HWND hWnd );

/*******************************************************************************************************
	description	: 줄의 시작과 끝에 덧붙이기
	parameter	: hWnd - SHEdit Handle
				  pszStart - 줄의 시작에 넣을 문자열 버퍼
				  nStartLen - 줄의 시작에 넣을 길이
				  pszEnd - 줄의 끝에 넣을 문자열 버퍼
				  nEndLen - 줄의 끝에 넣을 길이
				  bRecordUndo - Undo 기록 여부
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
				  nParaIndex - bookmark 할 paragraph (-1 이면 현재 paragraph)
	returns		:
	remarks		:
*******************************************************************************************************/
extern "C" __declspec( dllexport ) void SHEdit_Bookmark( HWND hWnd, int nParaIndex );

/*******************************************************************************************************
	description	: 대소문자 변환을 한다
	parameter	: hWnd - SHEdit Handle
				  nCase - 변환 형식
	returns		:
	remarks		: 0 소문자를 대문자로
				  1 대문자를 소문자로
				  2 대소문자를 반대로
*******************************************************************************************************/
extern "C" __declspec( dllexport ) void SHEdit_ChangeCase( HWND hWnd, int nCase );

/*******************************************************************************************************
	description	: 모든 북마크 제거
	parameter	: hWnd - SHEdit Handle
	returns		:
	remarks		:
*******************************************************************************************************/
extern "C" __declspec( dllexport ) void SHEdit_ClearBookmark( HWND hWnd );

/*******************************************************************************************************
	description	: 공백을 탭으로 변경
	parameter	: hWnd - SHEdit Handle
				  nType - 변경 방식
	returns		:
	remarks		: nType
				  0 - 전체 변경
				  1 - 라인의 처음만 변경
*******************************************************************************************************/
extern "C" __declspec( dllexport ) void SHEdit_ConvertSpaceToTab( HWND hWnd, int nType );

/*******************************************************************************************************
	description	: 탭을 공백으로 변환
	parameter	: hWnd - SHEdit Handle
	returns		:
	remarks		:
*******************************************************************************************************/
extern "C" __declspec( dllexport ) void SHEdit_ConvertTabToSpace( HWND hWnd );

/*******************************************************************************************************
	description	: 줄의 시작과 끝에 때내기
	parameter	: hWnd - SHEdit Handle
				  pszStart - 줄의 시작에서 때낼 문자열 버퍼
				  nStartLen - 줄의 시작에서 때낼 길이
				  pszEnd - 줄의 끝에서 때낼 문자열 버퍼
				  nEndLen - 줄의 끝에서 때낼 길이
				  bRecordUndo - Undo 기록 여부
	returns		:
	remarks		:
*******************************************************************************************************/
extern "C" __declspec( dllexport ) 
  void SHEdit_DetachOnLine( HWND hWnd, TCHAR* pszStart, int nStartLen, TCHAR* pszEnd, int nEndLen, BOOL bRecordUndo );

/*******************************************************************************************************
	description	: SHEdit를 제거한다
	parameter	: hWnd - SHEdit Handle
	returns		:
	remarks		:
*******************************************************************************************************/
extern "C" __declspec( dllexport ) void SHEdit_Destroy( HWND hWnd );

/*******************************************************************************************************
	description	: 줄번호 표시 여부 설정
	parameter	: hWnd - SHEdit Handle
				  bEnable - 줄버호를 보일것인지 말것인지를 결정하는 flag
	returns		:
	remarks		:
*******************************************************************************************************/
extern "C" __declspec( dllexport ) void SHEdit_EnableLineNo( HWND hWnd, BOOL bEnable );

/*******************************************************************************************************
	description	: 눈금자 표시
	parameter	: hWnd - SHEdit Handle
				  bEnable - 눈금자를 보일것인지 말것인지를 결정하는 flag
	returns		:
	remarks		:
*******************************************************************************************************/
extern "C" __declspec( dllexport ) void SHEdit_EnableRuler( HWND hWnd, BOOL bEnable );

/*******************************************************************************************************
	description	: 마진 설정
	parameter	: hWnd - SHEdit Handle
				  bEnable - 마진을 보일것인지 말것인지를 결정하는 flag
	returns		:
	remarks		:
*******************************************************************************************************/
extern "C" __declspec( dllexport ) void SHEdit_EnableSelectionMargin( HWND hWnd, BOOL bEnable );

/*******************************************************************************************************
	description	: 가상 공백 사용여부 설정
	parameter	: hWnd - SHEdit Handle
				  bEnable - 가상 공백 사용여부
	returns		:
	remarks		:
*******************************************************************************************************/
extern "C" __declspec( dllexport ) void SHEdit_EnableVirtualSpace( HWND hWnd, BOOL bEnable );

/*******************************************************************************************************
	description	: 선택 블럭의 시작과 끝을 구한다
	parameter	: hWnd - SHEdit Handle
				  pBlock - SHEDIT_BLOCK Pointer
	returns		:
	remarks		:
*******************************************************************************************************/
extern "C" __declspec( dllexport ) void SHEdit_GetBlock( HWND hWnd, SHEDIT_BLOCK* pBlock );

/*******************************************************************************************************
	description	: 선택 블럭이 열 선택 일때, 첫번째 열의 BYTE 수를 구한다
	parameter	: hWnd - SHEdit Handle
				  pnCount - 선택된 열의 byte 수를 받을 Pointer
	returns		:
	remarks		:
*******************************************************************************************************/
extern "C" __declspec( dllexport ) void SHEdit_GetBlockColumnCount( HWND hWnd, int* pnCount );

/*******************************************************************************************************
	description	: 주어진 위치의 단어를 검색
	parameter	: hWnd - SHEdit Handle
				  nPos - 검색하려는 위치
				  pBlock - SHEDIT_BLOCK Pointer
	returns		:
	remarks		:
*******************************************************************************************************/
extern "C" __declspec( dllexport ) void SHEdit_GetCurrentWord( HWND hWnd, int nPos, SHEDIT_BLOCK* pBlock );

/*******************************************************************************************************
	description	: 주어진 위치의 라인에서 근접한 단어를 검색 단어
	parameter	: hWnd - SHEdit Handle
				  nPos - 검색하려는 위치
				  pBlock - SHEDIT_BLOCK Pointer
	returns		:
	remarks		: 이경우는 검색 시작위치에서 공백을 제외한 문자를 단어로 판단한다
*******************************************************************************************************/
extern "C" __declspec( dllexport ) void SHEdit_GetCurrentWordInLine( HWND hWnd, int nPos, SHEDIT_BLOCK* pBlock );

/*******************************************************************************************************
	description	: 내용을 받는다
	parameter	: hWnd - SHEdit Handle
				  pszBuffer - 내용을 받을 버퍼
	returns		:
	remarks		: nBufferSize - null termination 의 길이가 포함되지 않은 버퍼의 길이
*******************************************************************************************************/
extern "C" __declspec( dllexport ) void SHEdit_GetTextRange( HWND hWnd, LPTSTR pszBuffer, int nBufferSize, int nStart, int nEnd );

/*******************************************************************************************************
	description	: 내용을 받는다
	parameter	: hWnd - SHEdit Handle
				  pszBuffer - 내용을 받을 버퍼
	returns		: nBufferSize - null termination 의 길이가 포함되지 않은 버퍼의 길이
	remarks		: nCharSet 이 -1 이면, 현재 설정된 문자셋을 적용한다
*******************************************************************************************************/
extern "C" __declspec( dllexport ) void SHEdit_GetTextRangeEx( HWND hWnd, LPTSTR pszBuffer, int nBufferSize, int nStart, int nEnd, int nCharSet );

/*******************************************************************************************************
	description	: 책갈피위치로 이동
	parameter	: hWnd - SHEdit Handle
				  bDown - 현재 위치다음의 책갈피를 찾을지 결정
	returns		:
	remarks		:
*******************************************************************************************************/
extern "C" __declspec( dllexport ) void SHEdit_GotoBookmark( HWND hWnd, BOOL bDown );

/*******************************************************************************************************
	description	: 문자열을 삽입한다
	parameter	: hWnd - SHEdit Handle
				  pstr - 문자열 포인터
				  len - pstr length
				  bRecordUndo - Undo 기록 여부
	returns		:
	remarks		: 현재 캐럿의 위치에 삽입
*******************************************************************************************************/
extern "C" __declspec( dllexport ) void SHEdit_Insert( HWND hWnd, TCHAR* pstr, int len, BOOL bRecordUndo );

/*******************************************************************************************************
	description	: SHEdit의 모든 내용 초기화
	parameter	: hWnd - SHEdit Handle
	returns		:
	remarks		:
*******************************************************************************************************/
extern "C" __declspec( dllexport ) void SHEdit_Reset( HWND hWnd );

/*******************************************************************************************************
	description	: 활성줄 색을 설정한다
	parameter	: hWnd - SHEdit Handle
				  clr - 활성줄 색을 설정한다
	returns		:
	remarks		:
*******************************************************************************************************/
extern "C" __declspec( dllexport ) void SHEdit_SetActiveLineColor( HWND hWnd, COLORREF clr );

/*******************************************************************************************************
	description	: 활성줄 표시 방식을 결정
	parameter	: hWnd - SHEdit Handle
				  nType - 설정 type
	returns		:
	remarks		: type  SHEDIT_ACTIVE_LINE_NONE - 표시 방식 없음
						SHEDIT_ACTIVE_LINE_RECTANGLE - 사각 영역 둘러싸기
						SHEDIT_ACTIVE_LINE_FILL_BACK - 배경색으로 채우기
						SHEDIT_ACTIVE_LINE_DRAW_MARGIN - 선택여백에 표시
*******************************************************************************************************/
extern "C" __declspec( dllexport ) void SHEdit_SetActiveLineType( HWND hWnd, int nType );

/*******************************************************************************************************
	description	: 자동 들여쓰기 설정
	parameter	: hWnd - SHEdit Handle
				  bIndent - 자동 들여쓰기 여부
	returns		:
	remarks		:
*******************************************************************************************************/
extern "C" __declspec( dllexport ) void SHEdit_SetAutoIndentation( HWND hWnd, BOOL bIndent );

/*******************************************************************************************************
	description	: 자동 선택 모드 설정
	parameter	: hWnd - SHEdit Handle
				  bAuto - 자동 선택 여부
	returns		:
	remarks		:
*******************************************************************************************************/
extern "C" __declspec( dllexport ) void SHEdit_SetAutoSelect( HWND hWnd, BOOL bAuto );

/*******************************************************************************************************
	description	: 배경색을 설정한다
	parameter	: hWnd - SHEdit Handle
				  clr - 배경색을 설정한다
	returns		:
	remarks		:
*******************************************************************************************************/
extern "C" __declspec( dllexport ) void SHEdit_SetBackColor( HWND hWnd, COLORREF clr );

/*******************************************************************************************************
	description	: 책갈피색을 설정한다
	parameter	: hWnd - SHEdit Handle
				  clr - 책갈피색
	returns		:
	remarks		:
*******************************************************************************************************/
extern "C" __declspec( dllexport ) void SHEdit_SetBookmarkColor( HWND hWnd, COLORREF clr );

/*******************************************************************************************************
	description	: 책갈피 글자색을 설정한다
	parameter	: hWnd - SHEdit Handle
				  clr - 책갈피 글자색
	returns		:
	remarks		:
*******************************************************************************************************/
extern "C" __declspec( dllexport ) void SHEdit_SetBookmarkForeColor( HWND hWnd, COLORREF clr );

/*******************************************************************************************************
	description	: 기호 표시 색 설정
	parameter	: hWnd - SHEdit Handle
				  clr - 기호 표시 색
	returns		:
	remarks		:
*******************************************************************************************************/
extern "C" __declspec( dllexport ) void SHEdit_SetCodeColor( HWND hWnd, COLORREF clr );

/*******************************************************************************************************
	description	: Column Mode를 설정
	parameter	: hWnd - SHEdit Handle
				  bColumn - 컬럼 모드
	returns		:
	remarks		:
*******************************************************************************************************/
extern "C" __declspec( dllexport ) void SHEdit_SetColumnMode( HWND hWnd, BOOL bColumn );

/*******************************************************************************************************
	description	: 현재 표시 색 설정
	parameter	: hWnd - SHEdit Handle
				  clr - 현재 표시 색
	returns		:
	remarks		:
*******************************************************************************************************/
extern "C" __declspec( dllexport ) void SHEdit_SetCurrentTagColor( HWND hWnd, COLORREF clr );

/*******************************************************************************************************
	description	: 현재 표시 글자색 설정
	parameter	: hWnd - SHEdit Handle
				  clr - 현재 표시 색
	returns		:
	remarks		:
*******************************************************************************************************/
extern "C" __declspec( dllexport ) void SHEdit_SetCurrentTagForeColor( HWND hWnd, COLORREF clr );

/*******************************************************************************************************
	description	: 현재 표시 설정
	parameter	: hWnd - SHEdit Handle
				  nLineIndex - 설정하려는 line index
	returns		:
	remarks		: line index를 -1로 설정하면 현재 표시 해제
*******************************************************************************************************/
extern "C" __declspec( dllexport ) void SHEdit_SetCurrentTag( HWND hWnd, int nLineIndex );

/*******************************************************************************************************
	description	: 단어 구분자를 설정한다
	parameter	: hWnd - SHEdit Handle
				  pszDelimiterString - 구분자 문자열
	returns		:
	remarks		:
*******************************************************************************************************/
extern "C" __declspec( dllexport ) void SHEdit_SetDelimiter( HWND hWnd, TCHAR* pszDelimiterString );

/*******************************************************************************************************
	description	: 폰트 설정
	parameter	: hWnd - SHEdit Handle
				  pLogFont - Font
	returns		:
	remarks		: 폰트를 변경하면 모든 View가 같이 적용된다
*******************************************************************************************************/
extern "C" __declspec( dllexport ) void SHEdit_SetFont( HWND hWnd, LOGFONT* pLogFont );

/*******************************************************************************************************
	description	: Hex 폰트 설정
	parameter	: hWnd - SHEdit Handle
				  pLogFont - Font
	returns		:
	remarks		: 폰트를 변경하면 모든 View가 같이 적용된다
*******************************************************************************************************/
extern "C" __declspec( dllexport ) void SHEdit_SetFontHex( HWND hWnd, LOGFONT* pLogFontHex );

/*******************************************************************************************************
	description	: 전경색을 설정한다
	parameter	: hWnd - SHEdit Handle
				  clr - 전경색
	returns		:
	remarks		:
*******************************************************************************************************/
extern "C" __declspec( dllexport ) void SHEdit_SetForeColor( HWND hWnd, COLORREF clr );

/*******************************************************************************************************
	description	: Home Key는 1열로 바로가기 설정
	parameter	: hWnd - SHEdit Handle
				  b - Home Key는 1열로 바로가기
	returns		:
	remarks		:
*******************************************************************************************************/
extern "C" __declspec( dllexport ) void SHEdit_SetHomeToFirstCol( HWND hWnd, BOOL b );

/*******************************************************************************************************
	description	: 최대 Undo Record 크기 설정
	parameter	: hWnd - SHEdit Handle
				  size - 변경 크기
	returns		:
	remarks		: size는 바이트 단위이다
*******************************************************************************************************/
extern "C" __declspec( dllexport ) void SHEdit_SetMaxUndoSize( HWND hWnd, int size );

/*******************************************************************************************************
	description	: 줄 간격 설정
	parameter	: hWnd - SHEdit Handle
				  nLineSpacing - 줄 간격( % )
	returns		:
	remarks		:
*******************************************************************************************************/
extern "C" __declspec( dllexport ) void SHEdit_SetLineSpacing( HWND hWnd, int nLineSpacing );

/*******************************************************************************************************
	description	: 문서 변경 설정
	parameter	: hWnd - SHEdit Handle
				  bMod - 변경 여부
	returns		:
	remarks		:
*******************************************************************************************************/
extern "C" __declspec( dllexport ) void SHEdit_SetModified( HWND hWnd, BOOL bMod );

/*******************************************************************************************************
	description	: Insert mode, ovrewrite mode 를 선택
	parameter	: hWnd - SHEdit Handle
				  bOvr - TRUE 이면 overwrite mode, FALSE이면 insert mode
	returns		:
	remarks		:
*******************************************************************************************************/
extern "C" __declspec( dllexport ) void SHEdit_SetOverwriteMode( HWND hWnd, BOOL bOvr );

/*******************************************************************************************************
	description	: 편집 가능 기능 설정
	parameter	: hWnd - SHEdit Handle
				  bReadOnly - 편집 가능 여부
	returns		:
	remarks		:
*******************************************************************************************************/
extern "C" __declspec( dllexport ) void SHEdit_SetReadOnly( HWND hWnd, BOOL bReadOnly );

/*******************************************************************************************************
	description	: 글자 선택상태로 만든다
	parameter	: hWnd - SHEdit Handle
				  nStartChar - 시작 위치
				  nEndChar - 종료 위치
				  bNoScroll - 캐럿이 선택된 위치로 스크롤 되어 보이지 않도록 설정
	returns		:
	remarks		: nStartChar이 0 이고, nEndChar이 -1이면 전체 선택상태이며,
				  nStartChar -1이면 현재 선택된 영역이 제거된다
*******************************************************************************************************/
extern "C" __declspec( dllexport ) void SHEdit_SetSel( HWND hWnd, int nStartChar, int nEndChar, BOOL bNoScroll );

/*******************************************************************************************************
	description	: 선택영역색 설정
	parameter	: hWnd - SHEdit Handle
				  clr - 선택영역색
	returns		:
	remarks		:
*******************************************************************************************************/
extern "C" __declspec( dllexport ) void SHEdit_SetSelBackColor( HWND hWnd, COLORREF clr );

/*******************************************************************************************************
	description	: 선택영역 전경색 설정
	parameter	: hWnd - SHEdit Handle
				  clr - 선택영역 전경색
	returns		:
	remarks		:
*******************************************************************************************************/
extern "C" __declspec( dllexport ) void SHEdit_SetSelForeColor( HWND hWnd, COLORREF clr );

/*******************************************************************************************************
	description	: 줄번호 출력색을 설정한다
	parameter	: hWnd - SHEdit Handle
				  clr - 줄번호 출력색
	returns		:
	remarks		:
*******************************************************************************************************/
extern "C" __declspec( dllexport ) void SHEdit_SetLineNoColor( HWND hWnd, COLORREF clr );

/*******************************************************************************************************
	description	: 빈줄 제외하고 블럭 들여쓰기 기능 설정
	parameter	: hWnd - SHEdit Handle
				  bSkip - 기능 설정
	returns		:
	remarks		:
*******************************************************************************************************/
extern "C" __declspec( dllexport ) void SHEdit_SetSkipEmptyLineOnBlockIndent( HWND hWnd, BOOL bSkip );

/*******************************************************************************************************
	description	: 탭 크기 설정
	parameter	: hWnd - SHEdit Handle
				  nSize - 탭 크기
	returns		:
	remarks		: 탭 크기는 스페이스 개수
*******************************************************************************************************/
extern "C" __declspec( dllexport ) void SHEdit_SetTabSize( HWND hWnd, int nSize );

/*******************************************************************************************************
	description	: 탭문자를 공백문자로 대체
	parameter	: hWnd - SHEdit Handle
				  bTabToSpace - 새 설정
	returns		:
	remarks		:
*******************************************************************************************************/
extern "C" __declspec( dllexport ) void SHEdit_SetTabToSpace( HWND hWnd, BOOL bTabToSpace );

/*******************************************************************************************************
	description	: SHEdit의 내용설정
	parameter	: hWnd - SHEdit Handle
				  pszStr - 설정할 문자열
				  dwLen - 설정할 문자열 길이
	returns		:
	remarks		: 반드시 null termination 은 필요하지 않다
*******************************************************************************************************/
extern "C" __declspec( dllexport ) void SHEdit_SetText( HWND hWnd, TCHAR* pszStr, DWORD dwLen );

/*******************************************************************************************************
	description	: 내용설정
	parameter	: hWnd - SHEdit Handle
				  lpszString - 설정할 문자열
				  dwLen - 문자열 길이
				  nCharSet - 문자셋
	returns		:
	remarks		: 문서의 포멧을 분석하여 설정한다
				  nCharSet
				  SHEDIT_CHARSET_UNDEFINED		: 지정되지 않음
				  SHEDIT_CHARSET_ASCII			: ASCII
				  SHEDIT_CHARSET_UNICODE		: Unicode( Little Endian )
				  SHEDIT_CHARSET_UTF_8			: Byte Order Mark 포함된 UTF-8
				  SHEDIT_CHARSET_UTF_8_NO_BOM	: Byte Order Mark 포함되지 않은 UTF-8

*******************************************************************************************************/
extern "C" __declspec( dllexport ) void SHEdit_SetTextEx( HWND hWnd, LPTSTR lpszString, DWORD dwLen, int nCharSet );

/*******************************************************************************************************
	description	: View를 설정한다
	parameter	: hWnd - SHEdit Handle
				  nNewMode - 새로 설정 할 View 모드
	returns		:
	remarks		: SHEDIT_VIEW_MODE_TEXT		: TEXT VIEW
				  SHEDIT_VIEW_MODE_HEX		: HEX VIEW
*******************************************************************************************************/
extern "C" __declspec( dllexport ) void SHEdit_SetViewMode( HWND hWnd, int nNewMode );

/*******************************************************************************************************
	description	: Word wrap mode를 설정
	parameter	: hWnd - SHEdit Handle
				  nMode - 새로설정되는 mode
	returns		:
	remarks		: SHEDIT_WORD_WRAP_NONE			: 없음
				  SHEDIT_WORD_WRAP_CHARACTER	: 문자단위
*******************************************************************************************************/
extern "C" __declspec( dllexport ) void SHEdit_SetWordWrap( HWND hWnd, int nMode );

/*******************************************************************************************************
	description	: 단락 기호 표시
	parameter	: hWnd - SHEdit Handle
				  bShow - 단락 기호 표시 여부
	returns		:
	remarks		:
*******************************************************************************************************/
extern "C" __declspec( dllexport ) void SHEdit_ShowBreakCode( HWND hWnd, BOOL bShow );

/*******************************************************************************************************
	description	: 편집 기호 표시
	parameter	: hWnd - SHEdit Handle
				  bShow - 편집 기호 표시 여부
	returns		:
	remarks		:
*******************************************************************************************************/
extern "C" __declspec( dllexport ) void SHEdit_ShowWhiteSpaceCode( HWND hWnd, BOOL bShow );

/*******************************************************************************************************
	description	: Column Mode를 설정/ 해제한다
	parameter	: hWnd - SHEdit Handle
	returns		:
	remarks		:
*******************************************************************************************************/
extern "C" __declspec( dllexport ) void SHEdit_ToggleColumnMode( HWND hWnd );

/*******************************************************************************************************
	description	: 줄끝 공백제거
	parameter	: hWnd - SHEdit Handle
	returns		:
	remarks		:
*******************************************************************************************************/
extern "C" __declspec( dllexport ) void SHEdit_TrimTrailingWhiteSpace( HWND hWnd );

#endif // __SHEDITCTRL_H__
