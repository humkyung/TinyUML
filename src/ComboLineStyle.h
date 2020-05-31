#if !defined(AFX_COMBOLINESTYLE_H__149B9F30_7F34_4CA0_AA0E_BE54B5858699__INCLUDED_)
#define AFX_COMBOLINESTYLE_H__149B9F30_7F34_4CA0_AA0E_BE54B5858699__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ComboLineStyle.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CComboLineStyle window

class CComboLineStyle : public CComboBox
{
	typedef struct tagLineStyle
	{
		int  m_nLineStyle;
		char m_szName[16];
	}LINESTYLE;
// Construction
public:
	CComboLineStyle();

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CComboLineStyle)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	//}}AFX_VIRTUAL
protected:
	virtual void DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct);
	void MeasureItem(LPMEASUREITEMSTRUCT lpMeasureItemStruct){}
// Implementation
public:
	int GetSelectedLineStyle() const;
	virtual ~CComboLineStyle();

	// Generated message map functions
protected:
	//{{AFX_MSG(CComboLineStyle)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
private:
	void InitializeData();
private:
	bool m_bInitialized;
	static LINESTYLE m_aryLineStyle[];
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_COMBOLINESTYLE_H__149B9F30_7F34_4CA0_AA0E_BE54B5858699__INCLUDED_)
