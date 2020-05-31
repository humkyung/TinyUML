#if !defined(AFX_COMBOCOLORPICKER_H__E910202D_CCDD_49EC_AC6C_9B7507A9F0B2__INCLUDED_)
#define AFX_COMBOCOLORPICKER_H__E910202D_CCDD_49EC_AC6C_9B7507A9F0B2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ComboColorPicker.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CComboColorPicker window
#define	CCB_MAX_COLORS			16							// Colors In List
#define	CCB_MAX_COLOR_NAME		16							// Max Chars For Color Name - 1

class CComboColorPicker : public CComboBox
{
	typedef struct tagColorAndName{
		COLORREF m_nColor;			// Actual Color RGB Value
		char	 m_szColor[CCB_MAX_COLOR_NAME];	// Actual Name For Color
		unsigned char r,g,b;
	}COLORANDNAME;

// Construction
public:
	CComboColorPicker();

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CComboColorPicker)
protected:
	//}}AFX_VIRTUAL
	virtual void DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct);
	void MeasureItem(LPMEASUREITEMSTRUCT lpMeasureItemStruct){}
// Implementation
public:
	virtual ~CComboColorPicker();
public:
	void InitializeData();

	void     SelectColor(const unsigned char r,const unsigned char g,const unsigned char b);
	COLORREF GetSelectedColor();
	void     GetSelectedColorValue(unsigned char& r,unsigned char& g,unsigned char& b);
	// Generated message map functions
protected:
	//{{AFX_MSG(CComboColorPicker)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
private:
	bool m_bInitialized;
	static COLORANDNAME m_aryStandardColors[];
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_COMBOCOLORPICKER_H__E910202D_CCDD_49EC_AC6C_9B7507A9F0B2__INCLUDED_)
