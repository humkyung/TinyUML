// CodeEdit.h : header file
//

#ifndef _CODEEDIT_H
#define _CODEEDIT_H

/////////////////////////////////////////////////////////////////////////////
// CCodeEdit window

#define CODEEDIT_UNDOSIZE 64 // must be power of 2
#define CODEEDIT_UNDOMASK CODEEDIT_UNDOSIZE-1

class AFX_EXT_CLASS CCodeEdit : public CEdit
{
private:
    int m_start[CODEEDIT_UNDOSIZE];
    int m_end[CODEEDIT_UNDOSIZE];
    MyCString m_code[CODEEDIT_UNDOSIZE];
    BOOL m_join[CODEEDIT_UNDOSIZE];
    int m_current;
    int m_last;

    BOOL m_putChar;
    BOOL m_storeNewState;

    int m_indentSize;
    DataModel* m_pDataModel;
    Method* m_pMethod;

public:
    CCodeEdit(DataModel* pDataModel);
    CCodeEdit(Method* pMethod);
    virtual ~CCodeEdit();

    void StoreNewState(BOOL join = FALSE, BOOL joinable = FALSE);
    void SendChar(unsigned char c) { SendMessage(WM_CHAR, c, 1); }
    void SendString(const CString& string);
    BOOL CanUndo() {return (m_current > 0 && (m_last - m_current) < CODEEDIT_UNDOMASK); }
    BOOL CanRedo() {return (m_current < m_last); }

    CString GetStrippedCode();

// Overrides
    // ClassWizard generated virtual function overrides
    //{{AFX_VIRTUAL(CCodeEdit)
    //}}AFX_VIRTUAL

protected:
    //{{AFX_MSG(CCodeEdit)
    afx_msg void OnSysKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
    afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
    afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
    afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
    afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
    //}}AFX_MSG

    DECLARE_MESSAGE_MAP()

private:
    void OnUndo();
    void OnRedo();
    void OnSelectAll();
    void OnInsertIterator();

    int GetLineIndent(int start);
    int GetIndent();
    int GetNextLineIndent(const CString& line, BOOL init = FALSE);
    void OnAltF8Char();
    void OnNewLineChar(UINT nChar, UINT nRepCnt, UINT nFlags);
    void OnTabChar(UINT nChar, UINT nRepCnt, UINT nFlags);
    void OnBracketOpenChar(UINT nChar, UINT nRepCnt, UINT nFlags);
    void OnBracketCloseChar(UINT nChar, UINT nRepCnt, UINT nFlags);
    void OnHekjeChar(UINT nChar, UINT nRepCnt, UINT nFlags);
    void OnNormalChar(UINT nChar, UINT nRepCnt, UINT nFlags);
    void PutChar(unsigned char c);
    void PutString(const CString& string);

    static BOOL StripComment(CString& code);
    static void StripBracketCode(CString& code);
};

#endif
/////////////////////////////////////////////////////////////////////////////
