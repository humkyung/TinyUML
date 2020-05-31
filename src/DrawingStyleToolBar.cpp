// DrawingStyleToolBar.cpp : implementation file
//

#include "stdafx.h"
#include "TinyUML.h"
#include "DrawingStyleToolBar.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDrawingStyleToolBar

CDrawingStyleToolBar::CDrawingStyleToolBar()
{
}

CDrawingStyleToolBar::~CDrawingStyleToolBar()
{
}


BEGIN_MESSAGE_MAP(CDrawingStyleToolBar, CToolBar)
	//{{AFX_MSG_MAP(CDrawingStyleToolBar)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDrawingStyleToolBar message handlers
BOOL CDrawingStyleToolBar::LoadToolBar(UINT lpszResourceName)
{
	BOOL bReturn = CToolBar::LoadToolBar(lpszResourceName);
	
	// Check if we loaded the toolbar.
	if (bReturn == FALSE)	return bReturn;

	RECT rect={0};
	//for(int index = 0;GetItemID(index) != ID_DRAWING_LINE_COLOR;index++);
	int index = GetToolBarCtrl().CommandToIndex(ID_DRAWING_LINE_COLOR);
	//m_wndDrawingStyleToolBar.SetButtonInfo(index, ID_DRAWING_LINE_COLOR,TBBS_SEPARATOR,50);
	GetItemRect(index , &rect);
	rect.bottom += 100;
	
	if(!m_wndComboColorPicker.Create(CBS_DROPDOWN | WS_VISIBLE | WS_TABSTOP | WS_VSCROLL | 
		CBS_DROPDOWNLIST|CBS_OWNERDRAWFIXED|CBS_OWNERDRAWVARIABLE , rect, this , ID_DRAWING_LINE_COLOR))
	{
		TRACE(_T("Failed to create combo-box\n"));
		return FALSE;
	}
	
	index = GetToolBarCtrl().CommandToIndex(ID_DRAWING_LINE_STYLE);
	GetItemRect(index , &rect);
	rect.bottom += 100;
	
	if(!m_wndComboLineStyle.Create(CBS_DROPDOWN | WS_VISIBLE | WS_TABSTOP | WS_VSCROLL | 
		CBS_DROPDOWNLIST|CBS_OWNERDRAWFIXED|CBS_OWNERDRAWVARIABLE , rect, this , ID_DRAWING_LINE_STYLE))
	{
		TRACE(_T("Failed to create combo-box\n"));
		return FALSE;
	}

	index = GetToolBarCtrl().CommandToIndex(ID_DRAWING_LINE_WEIGHT);
	GetItemRect(index , &rect);
	rect.bottom += 100;
	
	if(!m_wndComboLineWeight.Create(CBS_DROPDOWN | WS_VISIBLE | WS_TABSTOP | WS_VSCROLL | 
		CBS_DROPDOWNLIST | CBS_OWNERDRAWFIXED | CBS_OWNERDRAWVARIABLE , rect, this , ID_DRAWING_LINE_WEIGHT))
	{
		TRACE(_T("Failed to create combo-box\n"));
		return FALSE;
	}

	/*

	for(index = 0;GetItemID(index) != ID_DRAWING_LINE_WEIGHT;index++);
	SetButtonInfo(index, ID_DRAWING_LINE_WEIGHT,TBBS_SEPARATOR,40);
	GetItemRect(index,&rect);
	rect.bottom += 150;

	m_wndComboLineWeight.Create(WS_CHILD|WS_VISIBLE|CBS_DROPDOWNLIST|CBS_OWNERDRAWFIXED|CBS_OWNERDRAWVARIABLE,rect,this,0);
	m_wndComboLineWeight.ShowWindow(SW_SHOW);

	for(index = 0;GetItemID(index) != ID_DRAWING_LINE_START_ARROW;index++);
	SetButtonInfo(index, ID_DRAWING_LINE_START_ARROW,TBBS_SEPARATOR,40);
	GetItemRect(index,&rect);
	rect.bottom += 150;

	m_wndComboLineStartArrow.SetArrowDir(AD_LEFT);
	m_wndComboLineStartArrow.Create(WS_CHILD|WS_VISIBLE|CBS_DROPDOWNLIST|CBS_OWNERDRAWFIXED|CBS_OWNERDRAWVARIABLE,rect,this,0);
	m_wndComboLineStartArrow.ShowWindow(SW_SHOW);

	for(index = 0;GetItemID(index) != ID_DRAWING_LINE_END_ARROW;index++);
	SetButtonInfo(index, ID_DRAWING_LINE_END_ARROW,TBBS_SEPARATOR,40);
	GetItemRect(index,&rect);
	rect.bottom += 150;

	m_wndComboLineEndArrow.SetArrowDir(AD_RIGHT);
	m_wndComboLineEndArrow.Create(WS_CHILD|WS_VISIBLE|CBS_DROPDOWNLIST|CBS_OWNERDRAWFIXED|CBS_OWNERDRAWVARIABLE,rect,this,0);
	m_wndComboLineEndArrow.ShowWindow(SW_SHOW);
	*/

	// Set the text for each button
	CToolBarCtrl& bar = GetToolBarCtrl();

	return bReturn;
}

//	parameter	:
//	description	:
//	remarks		:
//	returns		:
BOOL CDrawingStyleToolBar::InitToolBar(CWnd *pParentWnd,UINT lpszResourceName)
{
	DWORD dwStyle = TBSTYLE_FLAT | WS_CHILD | WS_VISIBLE | CBRS_TOP | CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC;
	CRect rect;

	if(!CreateEx(pParentWnd,TBSTYLE_FLAT,dwStyle) || !LoadToolBar(lpszResourceName))
	{
		TRACE0("Failed to create toolbar\n");
		return -1;
	}
	
	return TRUE;
}


