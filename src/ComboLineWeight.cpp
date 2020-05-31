// ComboLineWeight.cpp : implementation file
//

#include "stdafx.h"
#include "TinyUML.h"
#include "ComboLineWeight.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CComboLineWeight
CComboLineWeight::LINEWEIGHT CComboLineWeight::m_aryLineWeight[] = 
{
	{1,"1"},{2,"2"},{3,"3"},{4,"4"},{5,"5"},{6,"6"},{7,"7"},{8,"8"}
};

CComboLineWeight::CComboLineWeight()
{
	m_bInitialized = false;
}

CComboLineWeight::~CComboLineWeight()
{
}


BEGIN_MESSAGE_MAP(CComboLineWeight, CComboBox)
	//{{AFX_MSG_MAP(CComboLineWeight)
	ON_WM_CREATE()
	ON_WM_SIZE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CComboLineWeight message handlers

int CComboLineWeight::OnCreate(LPCREATESTRUCT lpCreateStruct) 
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
void CComboLineWeight::InitializeData(){
	if (m_bInitialized) return;

	int nItem=-1;
	for (int nLineWeight = 0;nLineWeight < sizeof(m_aryLineWeight)/sizeof(CComboLineWeight::LINEWEIGHT);nLineWeight++){
		nItem = AddString((LPCTSTR)CComboLineWeight::m_aryLineWeight[nLineWeight].m_szName);	// Here we could affect the sort order at run-time

		if (CB_ERRSPACE == nItem)
			break;
		else	SetItemData(nItem,CComboLineWeight::m_aryLineWeight[nLineWeight].m_nLineWeight);
	}
	SetCurSel(0);
	m_bInitialized = true;
}

//	parameter	:
//	description	:
//	remarks		:
//	returns		:
void CComboLineWeight::DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct)
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
	int		nLineWeight = 1;
	COLORREF	crNormal = GetSysColor( COLOR_WINDOW );
	COLORREF	crSelected = GetSysColor( COLOR_HIGHLIGHT );
	COLORREF	crText = GetSysColor( COLOR_WINDOWTEXT );
	
	if( !dcContext.Attach( lpDrawItemStruct -> hDC ) )				// Attach CDC Object
		return;												// Stop If Attach Failed
	
	iFourthWidth = (rBlockRect.Width()*5/6);				// Get 1/4 Of Item Area
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
	rBlockRect.right = iFourthWidth;						// Set Width Of Color Block
	
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
		}else	nLineWeight = GetItemData( iItem );// Get Color Value
		
		//dcContext.SetBkMode(TRANSPARENT );				// Transparent Background
		//dcContext.TextOut( rTextRect.left, rTextRect.top,);	// Draw Color Name
		
		// Draw Line Weight
		int cx=rBlockRect.right - rBlockRect.left;
		dcContext.FillSolidRect(rBlockRect.left,rBlockRect.top,cx,rBlockRect.bottom - rBlockRect.top,RGB(255,255,255));
		dcContext.FillSolidRect(rBlockRect.left,(int)((rBlockRect.top + rBlockRect.bottom)*0.5) - (int)(nLineWeight*0.5),cx,nLineWeight,RGB(0,0,0));
	}
	dcContext.Detach();
}

//	parameter	:
//	description	:
//	remarks		:
//	returns		:
int CComboLineWeight::GetSelectedLineWeight()
{
	int nItem = GetCurSel();
	if (CB_ERR == nItem) return 1; // Default to 1

	return m_aryLineWeight[nItem].m_nLineWeight;
}

void CComboLineWeight::OnSize(UINT nType, int cx, int cy) 
{
	CComboBox::OnSize(nType, cx, cy);
	
	
}
