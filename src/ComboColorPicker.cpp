// ComboColorPicker.cpp : implementation file
//

#include "stdafx.h"
#include "TinyUML.h"
#include "ComboColorPicker.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CComboColorPicker
CComboColorPicker::COLORANDNAME CComboColorPicker::m_aryStandardColors[] = 
{
	{RGB(0, 0, 0),"Black",0, 0, 0},
	{RGB(255, 255, 255),"White",255, 255, 255},
	{RGB(128, 0, 0),"Dark Red",128, 0, 0},
	{RGB(0, 128, 0),"Dark Green",0, 128, 0},
	{RGB(128, 128, 0),"Dark Yellow",128, 128, 0},
	{RGB(0, 0, 128),"Dark Blue",0, 0, 128},
	{RGB(128, 0, 128),"Dark Magenta",128, 0, 128},
	{RGB(0, 128, 128),"Dark Cyan",0, 128, 128},
	{RGB(192, 192, 192),"Light Grey",192, 192, 192},
	{RGB(128, 128, 128),"Dark Grey",128, 128, 128},
	{RGB(255, 0, 0),"Red",255, 0, 0},
	{RGB(0, 255, 0),"Green",0, 255, 0},
	{RGB(255, 255, 0),"Yellow",255, 255, 0},
	{RGB(0, 0, 255),"Blue",0, 0, 255},
	{RGB(255, 0, 255),"Magenta",255, 0, 255},
	{RGB(0, 255, 255),"Cyan",0, 255, 255}
	};

//	parameter	:
//	description	:
//	remarks		:
//	returns		:
CComboColorPicker::CComboColorPicker()
{
	m_bInitialized = false;
}

CComboColorPicker::~CComboColorPicker()
{
}


BEGIN_MESSAGE_MAP(CComboColorPicker, CComboBox)
	//{{AFX_MSG_MAP(CComboColorPicker)
		ON_WM_CREATE()
		ON_WM_SIZE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CComboColorPicker message handlers
int CComboColorPicker::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CComboBox::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	InitializeData();
	SetCurSel(0);

	return 0;
}

//	parameter	:
//	description	:
//	remarks		:
//	returns		:
void CComboColorPicker::InitializeData()
{
	if (m_bInitialized) return;

	int nItem=-1;
	for (int nColor = 0;nColor < 16/*nColor < sizeof(m_aryStandardColors)/sizeof(CComboColorPicker::COLORANDNAME)*/; nColor++){
		nItem = AddString((LPCTSTR)CComboColorPicker::m_aryStandardColors[nColor].m_szColor);	// Here we could affect the sort order at run-time

		if (CB_ERRSPACE == nItem)
			break;
		else	SetItemData(nItem,CComboColorPicker::m_aryStandardColors[nColor].m_nColor);
	}
	SetCurSel(0);
	m_bInitialized = true;
}

//	parameter	:
//	description	:
//	remarks		:
//	returns		:
void CComboColorPicker::OnSize(UINT nType, int cx, int cy) 
{
	CComboBox::OnSize(nType, cx, cy);
}


//	parameter	:
//	description	:
//	remarks		:
//	returns		:
void CComboColorPicker::DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct)
{
	CDC		dcContext;
	CRect		rItemRect(lpDrawItemStruct -> rcItem );
	CRect		rBlockRect( rItemRect );
	CRect		rTextRect( rBlockRect );
	CBrush		brFrameBrush;
	int		iFourthWidth = 0;
	int		iItem = lpDrawItemStruct -> itemID;
	int		iAction = lpDrawItemStruct -> itemAction;
	int		iState = lpDrawItemStruct -> itemState;
	COLORREF	crColor = 0;
	COLORREF	crNormal = GetSysColor( COLOR_WINDOW );
	COLORREF	crSelected = GetSysColor( COLOR_HIGHLIGHT );
	COLORREF	crText = GetSysColor( COLOR_WINDOWTEXT );
	
	if( !dcContext.Attach( lpDrawItemStruct -> hDC ) )				// Attach CDC Object
		return;												// Stop If Attach Failed
	
	iFourthWidth = (rBlockRect.Width()*5/6 );				// Get 1/4 Of Item Area
	brFrameBrush.CreateStockObject( BLACK_BRUSH );			// Create Black Brush
	
	if( iState & ODS_SELECTED ){								// If Selected{														// Set Selected Attributes
		dcContext.SetTextColor(( 0x00FFFFFF & ~( crText ) ) );				// Set Inverted Text Color (With Mask)
		dcContext.SetBkColor( crSelected );					// Set BG To Highlight Color
		dcContext.FillSolidRect( &rBlockRect, crSelected );	// Erase Item
	}else{													// If Not Selected
		dcContext.SetTextColor( crText );					// Set Text Color
		dcContext.SetBkColor( crNormal );					// Set BG Color
		dcContext.FillSolidRect( &rBlockRect, crNormal );	// Erase Item
	}
	if( iState & ODS_FOCUS )								// If Item Has The Focus
		dcContext.DrawFocusRect( &rItemRect );				// Draw Focus Rect
	
	//
	//	Calculate Text Area
	//
	rTextRect.left += ( iFourthWidth + 2 );					// Set Start Of Text
	rTextRect.top += 2;										// Offset A Bit
	
	//
	//	Calculate Color Block Area
	//
	rBlockRect.DeflateRect( CSize( 2, 2 ) );				// Reduce Color Block Size
	rBlockRect.right = iFourthWidth;						// Set Width Of Color Block
	
	//
	//	Draw Color Text And Block
	//
	if( iItem != -1 ){	// If Not An Empty Item
		char szColor[32]; // No Need To Reallocate Each Time

		GetLBText( iItem, szColor );							// Get Color Text
		if( iState & ODS_DISABLED ){	// If Disabled
			crColor = GetSysColor( COLOR_INACTIVECAPTIONTEXT );
			dcContext.SetTextColor( crColor );				// Set Text Color
		}else					// If Normal
			crColor = GetItemData( iItem );					// Get Color Value
		
		//dcContext.SetBkMode(TRANSPARENT );				// Transparent Background
		//dcContext.TextOut( rTextRect.left, rTextRect.top,CComboColorPicker::m_aryStandardColors[iItem].m_szColor);	// Draw Color Name
		
		dcContext.FillSolidRect( &rBlockRect, crColor );	// Draw Color
		dcContext.FrameRect( &rBlockRect, &brFrameBrush );	// Draw Frame
	}
	dcContext.Detach();

	/*
	CDC dc;
	dc.Attach(lpDrawItemStruct->hDC);
	CRect rect(&(lpDrawItemStruct->rcItem));
	
	// This switch statement draws the item in the combo box based on the itemID.
	// The itemID corresponds to the index in the COLORREF array.
	switch(lpDrawItemStruct->itemID){
		// The automatic case
	case 16:
		{
			// Create the brush
			CBrush brush(CComboColorPicker::m_aryStandardColors[0].m_nColor);
			CRect rect(&(lpDrawItemStruct->rcItem));
			rect.InflateRect(-2, -2);
			// Color the area
			dc.FillRect(rect, &brush);
			// Draw teh focus rect if the mosue is either over the item, or if the item
			// is selected
			if (lpDrawItemStruct->itemState & ODS_SELECTED)
				dc.DrawFocusRect(rect);
			
			// Draw the text
			CString strColor = "Automatic";
			CSize textSize = dc.GetOutputTextExtent(strColor);
			dc.SetBkMode(TRANSPARENT);
			dc.SetTextColor(RGB(255, 255, 255));
			dc.DrawText(strColor, rect, DT_SINGLELINE | DT_CENTER);
			
		}
		break;
	default:
		// Drawing code for items accept the automatic color
		
		// Create the brush
		CBrush brush(CComboColorPicker::m_aryStandardColors[lpDrawItemStruct->itemID].m_nColor);
		CRect rect(&(lpDrawItemStruct->rcItem));
		rect.InflateRect(-2, -2);
		// Color the area
		dc.FillRect(rect, &brush);
		// Draw the focus rect if the mouse is either over the item, or if the item
		// is selected
		if (lpDrawItemStruct->itemState & ODS_SELECTED)
			dc.DrawFocusRect(rect);
		
	}
	
	// This draws the black frame around each of the colors so that they
	// do not look like they are kind of blended together
	CBrush frameBrush(RGB(0, 0, 0));
	dc.FrameRect(rect, &frameBrush);
	rect.InflateRect(-1, -1);
	
	dc.Detach();
	*/

/*
	CDC dc;
	CBrush brushBlack;
	brushBlack.CreateStockObject(BLACK_BRUSH);
	
	if (!dc.Attach(lpDrawItemStruct->hDC)) return;

	COLORREF rgbTextColor = dc.GetTextColor();
	COLORREF rgbBkColor = dc.GetBkColor();
	
	if (lpDrawItemStruct->itemAction & ODA_FOCUS){
		dc.DrawFocusRect(&lpDrawItemStruct->rcItem);
	}
	else if (lpDrawItemStruct->itemAction & ODA_DRAWENTIRE)
	{
		if (lpDrawItemStruct->itemState & ODS_FOCUS)
			dc.DrawFocusRect(&lpDrawItemStruct->rcItem);
		else
			dc.ExtTextOut(0, 0, ETO_OPAQUE, &lpDrawItemStruct->rcItem, _T("hello"), 0, NULL);
	}

	if (0 <= (int)lpDrawItemStruct->itemID)	// Any item selected?
	{
		::InflateRect(&lpDrawItemStruct->rcItem, -2, -2);
		
		dc.FillSolidRect(&lpDrawItemStruct->rcItem, (COLORREF)lpDrawItemStruct->itemData);
		dc.FrameRect(&lpDrawItemStruct->rcItem, &brushBlack);
	}

	// Restore the DC state
	dc.SetTextColor(rgbTextColor);
	dc.SetBkColor(rgbBkColor);
	dc.Detach();
*/
}

//	parameter	:
//	description	:
//	remarks		:
//	returns		:
void CComboColorPicker::SelectColor(const unsigned char r,const unsigned char g,const unsigned char b){	
	for (int nColor = 0;nColor < sizeof(m_aryStandardColors)/sizeof(CComboColorPicker::COLORANDNAME); nColor++){
		if(	(r == CComboColorPicker::m_aryStandardColors[nColor].r) && 
			(g == CComboColorPicker::m_aryStandardColors[nColor].g) &&
			(b == CComboColorPicker::m_aryStandardColors[nColor].b)) break;
	}
	SetCurSel(nColor);
}

//	parameter	:
//	description	:
//	remarks		:
//	returns		:
COLORREF CComboColorPicker::GetSelectedColor()
{
	int nItem = GetCurSel();
	if (CB_ERR == nItem)
		return RGB(0, 0, 0);	// Default to black if nothing is selected

	return m_aryStandardColors[nItem].m_nColor;
}

//	parameter	:
//	description	:
//	remarks		:
//	returns		:
void CComboColorPicker::GetSelectedColorValue(unsigned char& r,unsigned char& g,unsigned char& b)
{
	int nItem = GetCurSel();
	if (CB_ERR == nItem) r = g = b =0; // Default to black if nothing is selected
	
	r = m_aryStandardColors[nItem].r;
	g = m_aryStandardColors[nItem].g;
	b = m_aryStandardColors[nItem].b;
}
