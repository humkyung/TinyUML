// ComboLineStyle.cpp : implementation file
//

#include "stdafx.h"
#include "TinyUML.h"
#include "ComboLineStyle.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CComboLineStyle
CComboLineStyle::LINESTYLE CComboLineStyle::m_aryLineStyle[] = 
{
	{PS_SOLID,"solid"},
	{PS_DASH,"dash"},
	{PS_DOT,"dot"},
	{PS_DASHDOT,"dast dot"},
	{PS_DASHDOTDOT,"dash dot dot"}
};

CComboLineStyle::CComboLineStyle()
{
	m_bInitialized = false;
}

CComboLineStyle::~CComboLineStyle()
{
}


BEGIN_MESSAGE_MAP(CComboLineStyle, CComboBox)
	//{{AFX_MSG_MAP(CComboLineStyle)
		ON_WM_CREATE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CComboLineStyle message handlers
int CComboLineStyle::OnCreate(LPCREATESTRUCT lpCreateStruct) 
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
void CComboLineStyle::InitializeData(){
	if (m_bInitialized) return;

	int nItem=-1;
	for (int nLineStyle = 0;nLineStyle < sizeof(m_aryLineStyle)/sizeof(CComboLineStyle::LINESTYLE);nLineStyle++){
		nItem = AddString((LPCTSTR)CComboLineStyle::m_aryLineStyle[nLineStyle].m_szName);	// Here we could affect the sort order at run-time

		if (CB_ERRSPACE == nItem)
			break;
		else	SetItemData(nItem,CComboLineStyle::m_aryLineStyle[nLineStyle].m_nLineStyle);
	}
	SetCurSel(0);
	m_bInitialized = true;
}

//	parameter	:
//	description	:
//	remarks		:
//	returns		:
void CComboLineStyle::DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct)
{
	CDC		dcContext;
	CRect		rItemRect(lpDrawItemStruct -> rcItem );
	CRect		rBlockRect( rItemRect );
	CRect		rTextRect( rBlockRect );
	CBrush		brFrameBrush;
	int		iItem = lpDrawItemStruct -> itemID;
	int		iAction = lpDrawItemStruct -> itemAction;
	int		iState = lpDrawItemStruct -> itemState;
	COLORREF	crNormal = GetSysColor( COLOR_WINDOW );
	COLORREF	crSelected = GetSysColor( COLOR_HIGHLIGHT );
	COLORREF	crText = GetSysColor( COLOR_WINDOWTEXT );
	
	if( !dcContext.Attach( lpDrawItemStruct -> hDC ) )				// Attach CDC Object
		return;												// Stop If Attach Failed
	
	int iFourthWidth = (rBlockRect.Width()*5/6);				// Get 1/4 Of Item Area
	brFrameBrush.CreateStockObject( BLACK_BRUSH );	// Create Black Brush
	
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
	rTextRect.left+= (iFourthWidth + 2);					// Set Start Of Text
	rTextRect.top += 2;										// Offset A Bit
	
	//
	//	Calculate Color Block Area
	//
	rBlockRect.DeflateRect(CSize(2,2));				// Reduce Color Block Size
	rBlockRect.right = lpDrawItemStruct->rcItem.right;//iFourthWidth;						// Set Width Of Color Block
	
	int nLineStyle = PS_SOLID;
	//
	//	Draw Color Text And Block
	//
	if( iItem != -1 ){	// If Not An Empty Item
		char szColor[32]; // No Need To Reallocate Each Time

		GetLBText( iItem, szColor );							// Get Color Text
		if( iState & ODS_DISABLED ){	// If Disabled
			COLORREF crColor = GetSysColor( COLOR_INACTIVECAPTIONTEXT );
			dcContext.SetTextColor(crColor);				// Set Text Color
		// If Normal
		}else	nLineStyle = GetItemData( iItem );// Get Color Value
		
		//dcContext.SetBkMode(TRANSPARENT );				// Transparent Background
		//dcContext.TextOut( rTextRect.left, rTextRect.top,CComboColorPicker::m_aryStandardColors[iItem].m_szColor);	// Draw Color Name
		
		// Draw Line Style
		HPEN hPen    = ::CreatePen(nLineStyle,1,RGB(0,0,0));
		HPEN hOldPen = (HPEN)dcContext.SelectObject(hPen);
		dcContext.FillSolidRect(rBlockRect.left,rBlockRect.top,rBlockRect.right - rBlockRect.left,rBlockRect.bottom - rBlockRect.top,RGB(255,255,255));
		dcContext.MoveTo(rBlockRect.left - 5,(int)((rBlockRect.top + rBlockRect.bottom)*0.5));
		dcContext.LineTo(rBlockRect.right,(int)((rBlockRect.top + rBlockRect.bottom)*0.5));
		dcContext.SelectObject(hOldPen);
		::DeleteObject(hPen);
	}
	dcContext.Detach();
}

int CComboLineStyle::GetSelectedLineStyle() const
{
	int nItem = GetCurSel();
	if (CB_ERR == nItem) return 1; // Default to 1

	return m_aryLineStyle[nItem].m_nLineStyle;
}
