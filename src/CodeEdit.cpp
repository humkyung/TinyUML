// CodeEdit.cpp : implementation file
//
// Copyright 2002, Jimmy Venema
// All rights are reserved. Reproduction in whole or part is prohibited
// without the written consent of the copyright owner.
// Philips Digital Video Systems, Eindhoven, The Netherlands.
// Distributed under the zlib/libpng License
//

#include "stdafx.h"
#include "CodeEdit.h"
#include "IteratorWizardDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCodeEdit

CCodeEdit::CCodeEdit(DataModel* pDataModel) : CEdit()
{
    m_current = -1;
    m_last = -1;
    m_putChar = FALSE;
    m_storeNewState = TRUE;
    m_pMethod = 0;
    m_pDataModel = pDataModel;
    m_indentSize = m_pDataModel->GetIndentSize();
}

CCodeEdit::CCodeEdit(Method* pMethod) : CEdit()
{
    m_current = -1;
    m_last = -1;
    m_putChar = FALSE;
    m_storeNewState = TRUE;
    m_pMethod = pMethod;
    m_pDataModel = pMethod->GetBaseClass()->GetDataModelDoc()->GetDataModel();
    m_indentSize = m_pDataModel->GetIndentSize();
}

CCodeEdit::~CCodeEdit()
{
}


BEGIN_MESSAGE_MAP(CCodeEdit, CEdit)
    //{{AFX_MSG_MAP(CCodeEdit)
    ON_WM_SYSKEYDOWN()
    ON_WM_CONTEXTMENU()
    ON_WM_CHAR()
    ON_WM_KEYDOWN()
    ON_WM_LBUTTONDBLCLK()
    //}}AFX_MSG_MAP
END_MESSAGE_MAP()

void CCodeEdit::PutChar(unsigned char c)
{
    m_putChar = TRUE;
    SendChar(c);
    m_putChar = FALSE;
}

void CCodeEdit::PutString(const CString& string)
{
    m_putChar = TRUE;
    int stringLen = string.GetLength();
    for (int i = 0; i < stringLen; i++)
        SendChar(string[i]);
    m_putChar = FALSE;
}

void CCodeEdit::SendString(const CString& string)
{
    int stringLen = string.GetLength();
    for (int i = 0; i < stringLen; i++)
        SendChar(string[i]);
}

CString CCodeEdit::GetStrippedCode()
{
    int start;
    int end;
    GetSel(start, end);

    CString code;
    GetWindowText(code);
    code = code.Left(start);

    StripComment(code);
    StripBracketCode(code);

    return code;
}

void CCodeEdit::OnInsertIterator()
{
    if (m_pMethod)
    {
        CIteratorWizardDialog dlg(m_pMethod, GetStrippedCode());
        if (dlg.DoModal() == IDOK)
        {
            m_storeNewState = FALSE;

            SendString(dlg.m_insertCode);

            m_storeNewState = TRUE;

            StoreNewState();
        }
    }
}

void CCodeEdit::OnRedo()
{
    if (m_current < m_last)
    {
        m_current++;
        SetWindowText(m_code[m_current&CODEEDIT_UNDOMASK]);
        SetSel(m_start[m_current&CODEEDIT_UNDOMASK], m_end[m_current&CODEEDIT_UNDOMASK]);
    }
}

void CCodeEdit::OnUndo()
{
    if (m_current > 0 && (m_last - m_current) < CODEEDIT_UNDOMASK)
    {
        m_current--;
        SetWindowText(m_code[m_current&CODEEDIT_UNDOMASK]);
        SetSel(m_start[m_current&CODEEDIT_UNDOMASK], m_end[m_current&CODEEDIT_UNDOMASK]);
    }
}

void CCodeEdit::OnSelectAll()
{
    SetSel(0, -1);
    CEdit::OnChar(1, 1, 0);
}

void CCodeEdit::StoreNewState(BOOL join, BOOL joinable)
{
    if (m_storeNewState)
    {
        int start;
        int end;
        GetSel(start, end);

        if (join && m_join[m_last&CODEEDIT_UNDOMASK] && (m_end[m_last&CODEEDIT_UNDOMASK]+1 == end))
        {
            m_start[m_last&CODEEDIT_UNDOMASK] = m_end[m_last&CODEEDIT_UNDOMASK] = end;
            GetWindowText(m_code[m_last&CODEEDIT_UNDOMASK]);
        }
        else
        {
            CString code;
            GetWindowText(code);
            if (m_code[m_last&CODEEDIT_UNDOMASK] != code)
            {
                m_last = m_current = m_current + 1;
            }
            m_start[m_last&CODEEDIT_UNDOMASK] = start;
            m_end[m_last&CODEEDIT_UNDOMASK] = end;
            m_join[m_last&CODEEDIT_UNDOMASK] = joinable;
            m_code[m_last&CODEEDIT_UNDOMASK] = code;
        }
    }
}

int CCodeEdit::GetNextLineIndent(const CString& line, BOOL init)
{
    static refIndent = m_indentSize;
    static indent;
    static char prevLastChar = '{';

    if (init)
        indent = m_indentSize;

    int lineLength = line.GetLength();
    if (lineLength)
    {
        int lineIndent = 0;
        for (int i = 0; i < lineLength && isspace(line[i]); i++)
        {
            if (line[i] == '\t')
                lineIndent = ((lineIndent+8)/8)*8;
            else
                lineIndent++;
        }

        // This is a line starting with '#', ignore it for indent calculation.
        if (i < lineLength && line[i] == '#')
        {
            return indent;
        }

        if ((prevLastChar == '{' || prevLastChar == '}' || prevLastChar == ';'))
        {
            refIndent = lineIndent;
        }

        char lineLastChar = line[lineLength-1];

        if (lineLastChar == '}')
            refIndent = indent = lineIndent;
        else if (lineLastChar == '{')
            indent = refIndent + m_indentSize;
        else if (lineLastChar == ';')
            indent = refIndent;
        else if (lineLastChar == ':')
            indent = refIndent + m_indentSize;
        else
        {
            if (prevLastChar == '{' || prevLastChar == '}' || prevLastChar == ';')
                indent = refIndent + m_indentSize;
            else
                indent = lineIndent;
        }

        if (lineLastChar != ':')
            prevLastChar = lineLastChar;
    }

    return indent;
}

BOOL CCodeEdit::StripComment(CString& code)
{
    CString newCode;
    int index;

    // Strip line comment
    while ((index = code.Find("//")) != -1)
    {
        newCode = code.Left(index);
        code = code.Mid(index+2);
        if ((index = code.Find(NL)) != -1)
            newCode += NL + code.Mid(index+2);

        code = newCode;
    }

    // Strip block comment
    while ((index = code.Find("/*")) != -1)
    {
        newCode = code.Left(index);
        code = code.Mid(index+2);
        if ((index = code.Find("*/")) != -1)
            newCode += code.Mid(index+2);
        else
            return TRUE;

        code = newCode;
    }

    return FALSE;
}

void CCodeEdit::StripBracketCode(CString& code)
{
    int openIndex;
    int closeIndex;
    while ((closeIndex = code.ReverseFind('}')) != -1)
    {
        int open = 0;
        for(openIndex = closeIndex; openIndex >= 0; openIndex--)
        {
            if (code[openIndex] != '{')
                open--;
            if (code[openIndex] != '}')
                open++;

            if (open == 0)
                break;
        }

        if (openIndex == -1)
            break;

        code = code.Left(openIndex) + code.Mid(closeIndex+1);
    }
}

int CCodeEdit::GetLineIndent(int start)
{
    int startLine = LineFromChar(start);
    int lineLength = LineLength(startLine);
    LPTSTR line = new TCHAR[lineLength+1];
    GetLine(startLine, line, lineLength);
    int lineIndent = 0;
    for (int i = 0; i < lineLength && isspace(line[i]); i++)
    {
        if (line[i] == '\t')
            lineIndent = ((lineIndent+8)/8)*8;
        else
            lineIndent++;
    }
    delete line;

    return lineIndent;
}

int CCodeEdit::GetIndent()
{
    int start;
    int end;
    GetSel(start, end);

    CString code;
    GetWindowText(code);
    code = code.Left(start);

    // Strip comment & check if we are in comment block
    if (StripComment(code))
        return GetLineIndent(start);

    // Init prediction of indent
    (void)GetNextLineIndent("", TRUE);

    // Process per line
    int index;
    CString line;
    while ((index = code.Find(NL)) != -1)
    {
        line = code.Left(index);
        line.TrimRight();
        (void)GetNextLineIndent(line);
        code = code.Mid(index+2);
    }

    code.TrimRight();
    return GetNextLineIndent(code);
}

void CCodeEdit::OnNewLineChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
    char resendChar = '\0';

    int start;
    int end;
    GetSel(start, end);
    if (start != end)
        Clear(); // Clear the selection

    CString code;
    GetWindowText(code);

    // Trim spaces after cursor
    int codeLength = code.GetLength();
    end = start;
    while (end < codeLength && (code[int(end)] == ' ' || code[int(end)] == '\t'))
        end++;
    if (end < codeLength && (code[int(end)] == '{'|| code[int(end)] == '}'|| code[int(end)] == '#'))
        resendChar = code[int(end++)];

    SetSel(start, end);
    Clear();

    // Put lines ending with ':' to the left
    code = code.Left(start);
    codeLength = code.GetLength()-1;
    while (codeLength >= 0 && (code[codeLength] == ' ' || code[codeLength] == '\t'))
        codeLength--;
    if (codeLength >= 0 && code[codeLength] == ':')
    {
        int line = LineFromChar(start);
        LPTSTR str = new TCHAR[m_indentSize+1];
        int lineLength = GetLine(line, str, m_indentSize);
        int newStart = LineIndex(line);
        for (int i = 0; i < m_indentSize && i < lineLength; i++)
        {
            if (!isspace(str[i]))
                break;
        }
        SetSel(newStart, newStart+i);
        Clear();
        delete str;
        newStart += LineLength();
        SetSel(start-i, start-i);
    }

    int indent = GetIndent();
    CEdit::OnChar(nChar, nRepCnt, nFlags);
    for (int i = 0; i < indent; i++)
        PutChar(' ');

    if (resendChar)
    {
        SendMessage(WM_CHAR, resendChar, 1);
        GetSel(start, end);
        SetSel(start-1, end-1);
    }

    StoreNewState();
}

void CCodeEdit::OnTabChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
    BOOL ctrlKeyDown = FALSE;
    if (GetKeyState(VK_CONTROL) & 0x8000)
        ctrlKeyDown = TRUE;
    BOOL shiftKeyDown = FALSE;
    if (GetKeyState(VK_SHIFT) & 0x8000)
        shiftKeyDown = TRUE;

    int start;
    int end;
    GetSel(start, end);
    SetFocus();

    if (!ctrlKeyDown)
    {
        int startLine = LineFromChar(start);
        int endLine = LineFromChar(end);
        if (startLine == endLine)
        {
            if (!shiftKeyDown)
            {
                int nrSpaces = m_indentSize - 
                               ((start - LineIndex(startLine)) % m_indentSize);
                for (int i = 0; i < nrSpaces; i++)
                    PutChar(' ');
            }
            else
            {
                int offset = (end - LineIndex(startLine)) % m_indentSize;
                if (offset == 0)
                    offset = m_indentSize;
                SetSel(end-offset, end-offset);
            }
        }
        else
        {
            if (LineIndex(endLine) == end)
                endLine--;

            for (int line = startLine; line <= endLine; line++)
            {
                if (!shiftKeyDown)
                {
                    int lineIndex = LineIndex(line);
                    SetSel(lineIndex, lineIndex);
                    for (int i = 0; i < m_indentSize; i++)
                        PutChar(' ');
                }
                else
                {
                    LPTSTR str = new TCHAR[m_indentSize+1];
                    int lineLength = GetLine(line, str, m_indentSize);
                    int newStart = LineIndex(line);
                    for (int i = 0; i < m_indentSize && i < lineLength; i++)
                    {
                        if (!isspace(str[i]))
                            break;
                    }
                    SetSel(newStart, newStart+i);
                    Clear();
                    delete str;
                }
            }

            SetSel(LineIndex(startLine), LineIndex(endLine+1));
        }
    }

    StoreNewState();
}

void CCodeEdit::OnBracketCloseChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
    int start;
    int end;
    GetSel(start, end);
    int line = LineFromChar(start);
    PutChar('}');

    CString code;
    GetWindowText(code);
    code = code.Left(start);

    // Strip comment & check if we are in comment block
    if (!StripComment(code))
    {
        int size = start - LineIndex(line);
        if (size)
        {
            LPTSTR str = new TCHAR[size+1];
            GetLine(line, str, size);
            for (int i = 0; i < size; i++)
            {
                if (!isspace(str[i]))
                    break;
            }
            if (i == size)
            {
                SetSel(start-m_indentSize, start);
                Clear();
                SetSel(start-m_indentSize+1, start-m_indentSize+1);
            }
            delete str;
        }
    }

    StoreNewState();
}

void CCodeEdit::OnBracketOpenChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
    int start;
    int end;
    GetSel(start, end);
    int line = LineFromChar(start);
    PutChar('{');

    CString code;
    GetWindowText(code);
    code = code.Left(start);

    // Strip comment & check if we are in comment block
    if (!StripComment(code))
    {
        code.TrimRight();
        if (code[code.GetLength()-1] != ':')
        {
            int size = start - LineIndex(line);
            if (size)
            {
                LPTSTR str = new TCHAR[size+1];
                GetLine(line, str, size);
                for (int i = 0; i < size; i++)
                {
                    if (!isspace(str[i]))
                        break;
                }
                if (i == size)
                {
                    SetSel(start-m_indentSize, start);
                    Clear();
                    SetSel(start-m_indentSize+1, start-m_indentSize+1);
                }
                delete str;
            }
        }
    }

    StoreNewState();
}

void CCodeEdit::OnHekjeChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
    int start;
    int end;
    GetSel(start, end);
    int line = LineFromChar(start);
    PutChar('#');

    CString code;
    GetWindowText(code);
    code = code.Left(start);

    // Strip comment & check if we are in comment block
    if (!StripComment(code))
    {
        int size = start - LineIndex(line);
        if (size)
        {
            LPTSTR str = new TCHAR[size+1];
            GetLine(line, str, size);
            for (int i = 0; i < size; i++)
            {
                if (!isspace(str[i]))
                    break;
            }
            if (i == size)
            {
                SetSel(start-size, start);
                Clear();
                SetSel(start-size+1, start-size+1);
            }
            delete str;
        }
    }

    StoreNewState();
}

void CCodeEdit::OnNormalChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
    static UINT prevChar = 0;
    CEdit::OnChar(nChar, nRepCnt, nFlags);

    int prevCharType = 0;
    if (isspace(prevChar))
        prevCharType = 1;
    else if (__iscsymf(prevChar))
        prevCharType = 2;
    else if (isdigit(prevChar))
        prevCharType = 3;

    int charType = 0;
    if (isspace(nChar))
        charType = 1;
    else if (__iscsymf(nChar))
        charType = 2;
    else if (isdigit(nChar))
        charType = 3;

    StoreNewState(prevCharType == charType, TRUE);
    prevChar = nChar;
}

void CCodeEdit::OnAltF8Char()
{
	SetCursor(AfxGetApp()->LoadStandardCursor(IDC_WAIT));
    LockWindowUpdate();

    // Identify selected region
    int start;
    int end;
    GetSel(start, end);
    int startLine = LineFromChar(start);
    int endLine = LineFromChar(end);

    if (end == LineIndex(endLine))
        endLine--;

    m_storeNewState = FALSE;
    for (int line = startLine; line <= endLine; line++)
    {
        if (line)
        {
            start = LineIndex(line-1);
            start += LineLength(start);
            end = LineIndex(line);
            SetSel(start, end);
            SendMessage(WM_CHAR, 13, 1);
        }
        else
        {
            int lineLength = LineLength(0);
            LPTSTR str = new TCHAR[lineLength+1];
            GetLine(0, str, lineLength);
            for (int i = 0; i < lineLength; i++)
            {
                if (!isspace(str[i]))
                    break;
            }
            SetSel(0, i);
            Clear();
            delete str;

            SetSel(0, 0);
            for (i = 0; i < m_indentSize; i++)
                PutChar(' ');
        }
    }
    m_storeNewState = TRUE;

    SetSel(LineIndex(startLine), LineIndex(endLine+1));
    UnlockWindowUpdate();

    StoreNewState();
	SetCursor(AfxGetApp()->LoadStandardCursor(IDC_ARROW));
}

/////////////////////////////////////////////////////////////////////////////
// CCodeEdit message handlers

void CCodeEdit::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
    if (m_putChar)
    {
        CEdit::OnChar(nChar, nRepCnt, nFlags);
    }
    else
    {
        if (nChar == 1) // Ctrl_A
            OnSelectAll();
        else if (nChar == 12) // Ctrl_L
            OnInsertIterator();
        else if (nChar == 19) // Ctrl_S
        {
            CWnd* parent = GetParent();
            if (parent)
                parent->SendMessage(WM_COMMAND, ID_FILE_SAVE);
        }
        else if (nChar == 20) // Ctrl_T
        {
            CWnd* parent = GetParent();
            if (parent)
                parent->SendMessage(WM_COMMAND, ID_EDIT_THROWLIST);
        }
        else if (nChar == 25) // Ctrl_Y
            OnRedo();
        else if (nChar == 26) // Ctrl_Z
            OnUndo();
        else if (nChar == 13) // Newline
            OnNewLineChar(nChar, nRepCnt, nFlags);
        else if (nChar == '{')
            OnBracketOpenChar(nChar, nRepCnt, nFlags);
        else if (nChar == '}')
            OnBracketCloseChar(nChar, nRepCnt, nFlags);
        else if (nChar == '#')
            OnHekjeChar(nChar, nRepCnt, nFlags);
        else
            OnNormalChar(nChar, nRepCnt, nFlags);
    }
}

void CCodeEdit::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
    if (nChar == 46) // delete
        StoreNewState();

    if (nChar == 9) // Tab
        OnTabChar(nChar, nRepCnt, nFlags);
    else
        CEdit::OnKeyDown(nChar, nRepCnt, nFlags);
}

void CCodeEdit::OnSysKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
    if (nChar == 119) // Alt-F8
        OnAltF8Char();

    CEdit::OnSysKeyDown(nChar, nRepCnt, nFlags);
}

void CCodeEdit::OnContextMenu(CWnd* pWnd, CPoint point) 
{
    CMenu dummy;
    if (dummy.LoadMenu(IDR_SHORTCUT))
    {
        CMenu* pMenu = dummy.GetSubMenu(0);
        if (pMenu)
        {
            pMenu->TrackPopupMenu(TPM_LEFTALIGN, point.x, point.y, pWnd->GetParent());
        }
    }
}


void CCodeEdit::OnLButtonDblClk(UINT nFlags, CPoint point) 
{
    int start;
    int end;
    GetSel(start, end);

    CString code;
    GetWindowText(code);

    if (code[int(start)] == ' ')
        end = start;
    else
        end = start+1;

    if (__iscsym(code[int(start)]))
    {
        while (start && __iscsym(code[start-1]))
            start--;
        
        while (end < code.GetLength() && __iscsym(code[int(end)]))
            end++;
    }
    
    SetSel(start, end);
}
