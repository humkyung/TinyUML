#if !defined(AFX_COMBOLINEWEIGHT_H__DA4437C8_8D51_46D3_A366_D2F727A6315B__INCLUDED_)
#define AFX_COMBOLINEWEIGHT_H__DA4437C8_8D51_46D3_A366_D2F727A6315B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ComboLineWeight.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CComboLineWeight window

class CComboLineWeight : public CComboBox
{
	typedef struct tagLineWeight
	{
		int  m_nLineWeight;
		char m_szName[16];
	}LINEWEIGHT;
// Construction
public:
	CComboLineWeight();

// Attributes
public:

// Operations
public:
	int GetSelectedLineWeight();
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CComboLineWeight)
	//}}AFX_VIRTUAL
protected:
	virtual void DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct);
	void MeasureItem(LPMEASUREITEMSTRUCT lpMeasureItemStruct){}
// Implementation
public:
	virtual ~CComboLineWeight();

	// Generated message map functions
protected:
	//{{AFX_MSG(CComboLineWeight)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
private:
	void InitializeData();
private:
	bool m_bInitialized;
	static LINEWEIGHT m_aryLineWeight[];
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_COMBOLINEWEIGHT_H__DA4437C8_8D51_46D3_A366_D2F727A6315B__INCLUDED_)
