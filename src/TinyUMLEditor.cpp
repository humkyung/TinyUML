// TinyUMLEditor.cpp: implementation of the CTinyUMLEditor class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "TinyUML.h"

#include <IsDrawLine.h>
#include <IsDrawLineController.h>
#include <IsDrawLineDraw.h>
#include <IsDrawRect.h>
#include <IsDrawRectController.h>
#include <IsDrawRectDraw.h>
#include <IsDrawEllipse.h>
#include <IsDrawEllipseController.h>
#include <IsDrawEllipseDraw.h>
#include <IsDrawArc.h>
#include <IsDrawArcController.h>
#include <IsDrawArcDraw.h>
#include <EntityTypeMap.h>

#include "TinyUMLClass.h"
#include "TinyUMLClassDraw.h"
#include "TinyUMLNote.h"
#include "TinyUMLNoteDraw.h"
#include "TinyUMLPackage.h"
#include "TinyUMLPackageDraw.h"
#include "TinyUMLLabelController.h"
#include "TinyUMLLabel.h"
#include "TinyUMLLabelDraw.h"
#include "TinyUMLGeneralization.h"
#include "TinyUMLGeneralizationDraw.h"
#include "TinyUMLAssociation.h"
#include "TinyUMLAssociationDraw.h"
#include "TinyUMLDependency.h"
#include "TinyUMLDependencyDraw.h"
#include "TinyUMLEditor.h"
#include "TinyUMLClipboardManager.h"
#include "TinyUMLTheme.h"
#include "TinyObjectTemplate.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

static EntityTypeMap __EntityTypeMap[]=
{
	{CIsDrawLine::TypeString , CIsDrawLineController::CreateInstance , CIsDrawLineDraw::CreateInstance} ,
	{CIsDrawRect::TypeString , CIsDrawRectController::CreateInstance , CIsDrawRectDraw::CreateInstance} ,
	{CIsDrawEllipse::TypeString , CIsDrawEllipseController::CreateInstance , CIsDrawEllipseDraw::CreateInstance} ,
	{CIsDrawArc::TypeString , CIsDrawArcController::CreateInstance , CIsDrawArcDraw::CreateInstance} ,

	//////////////////////////////////////////////////////////////////////////
	{CTinyUMLClass::TypeString , CTinyUMLClassController::CreateInstance , CTinyUMLClassDraw::CreateInstance} ,
	{CTinyUMLNote::TypeString , CTinyUMLNoteController::CreateInstance , CTinyUMLNoteDraw::CreateInstance} ,
	{CTinyUMLPackage::TypeString , CTinyUMLPackageController::CreateInstance , CTinyUMLPackageDraw::CreateInstance} ,
	{CTinyUMLGeneralization::TypeString , CTinyUMLGeneralizationController::CreateInstance , CTinyUMLGeneralizationDraw::CreateInstance} ,
	{CTinyUMLAssociation::TypeString , CTinyUMLAssociationController::CreateInstance , CTinyUMLAssociationDraw::CreateInstance} ,
	{CTinyUMLDependency::TypeString , CTinyUMLDependencyController::CreateInstance , CTinyUMLDependencyDraw::CreateInstance} ,
	{CTinyUMLLabel::TypeString , CTinyUMLLabelController::CreateInstance , CTinyUMLLabelDraw::CreateInstance}
};

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

/**
 * CTinyUMLEditor:
 *
 * @param pEntContainer 
 * @return  
 */
CTinyUMLEditor::CTinyUMLEditor(CTinyUMLEntityContainer* pEntContainer)
 : CIsDrawEditor(pEntContainer)
{
	m_pEditCtrl = NULL;
}

CTinyUMLEditor::~CTinyUMLEditor()
{
}

BEGIN_MESSAGE_MAP(CTinyUMLEditor, CIsDrawEditor)
	//{{AFX_MSG_MAP(CTinyUMLEditor)
	//}}AFX_MSG_MAP
	ON_WM_CREATE()
	ON_MESSAGE(TINY_UML_PREMODIFY_PROPERTY,  OnPreModifyProperty)
	ON_MESSAGE(TINY_UML_MODIFY_PROPERTY,  OnModifyProperty)

	ON_NOTIFY_EX(TTN_NEEDTEXT, 0, OnToolTipNotify)
END_MESSAGE_MAP()

/**
 * OnCreate:
 *
 * @param lpCreateStruct 
 * @return int 
 */
int CTinyUMLEditor::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	CIsDrawEditor::OnCreate(lpCreateStruct);

	size_t nCount = sizeof(__EntityTypeMap) / sizeof(EntityTypeMap);
	for(size_t i = 0;i < nCount;i++)
	{
		AddEntityTypeMap(__EntityTypeMap[i].TypeString() , &(__EntityTypeMap[i]));
	}
	
	CIsDrawCtrlHost* pApp = CIsDrawCtrlHost::GetInstance();
	pApp->RegisterClipboardManager(new CTinyUMLClipboardManager);
	
	return 0;
}

BOOL CTinyUMLEditor::OnToolTipNotify(UINT /*id*/, NMHDR* pNMHDR, LRESULT* /*pResult*/)
{
	TOOLTIPTEXT *pTTT = (TOOLTIPTEXT *)pNMHDR;    
	UINT nID = pNMHDR->idFrom;
	
	pTTT->lpszText = _T("Radio Button Control");
	return TRUE;
	
	return FALSE;
}

/**
 * DrawGrid:
 *
 * @param pDC 
 * @param rect 
 * @return void 
 */
void CTinyUMLEditor::DrawGrid(CDC *pDC, CRect rect)
{
	CTinyUMLTheme* pUMLTheme=static_cast<CTinyUMLTheme*>(GetDoc()->GetTheme());
	COLORREF gridColor = pUMLTheme->GetGridColor();
	
	CRect clipBox;
	pDC->GetClipBox(clipBox);
	clipBox.right = rect.right;clipBox.bottom = rect.bottom;
	clipBox.NormalizeRect();
	clipBox.InflateRect(m_gridSize.cx,m_gridSize.cy);
	
	
	int stepx = GetVirtualSize().cx / GetGridSize().cx;
	int stepy = GetVirtualSize().cy / GetGridSize().cy;
	for( int x = 0 ; x <= stepx ; x++ ){
		for(int y=0;y <= stepy; y++){
			pDC->SetPixelV( round( static_cast< double >( GetGridSize().cx * x )),
					round( static_cast< double >( GetGridSize().cy * y )),
					gridColor);
		}
	}
}

/**
 * DrawBackground:
 *
 * @param pDC 
 * @param rect 
 * @return void 
 */
void CTinyUMLEditor::DrawBackground(CDC *pDC, CRect rect)
{
	CTinyUMLTheme* pUMLTheme=static_cast<CTinyUMLTheme*>(GetDoc()->GetTheme());
	pDC->FillSolidRect( &rect, pUMLTheme->GetPaperColor());
}

/**
 * OnPreModifyProperty:
 *
 * @param lParam 
 * @param wParam 
 * @return LONG 
 */
LONG CTinyUMLEditor::OnPreModifyProperty(UINT lParam, LONG wParam)
{
	CIsDrawEntity* pEnt=(CIsDrawEntity*)(wParam);

	CIsDrawEntitySet entSet;
	entSet.Append(pEnt);
	RegisterCommand(new CIsDrawCommand(this,&entSet));

	return TRUE;
}

/**
 * OnModifyProperty:
 *
 * @param lParam 
 * @param wParam 
 * @return LONG 
 */
LONG CTinyUMLEditor::OnModifyProperty(UINT lParam, LONG wParam)
{
	CIsDrawEntity* pEnt=(CIsDrawEntity*)(wParam);

	//////////////////////////////////////////////////////////////////////////
	IS_NOTIFY notify;
	notify.hdr.hwndFrom = GetSafeHwnd();
	notify.pEntFrom = pEnt;
	(GetParent())->SendMessage(WM_NOTIFY,(WPARAM)TINY_UML_MODIFY_PROPERTY,(LPARAM)&notify);

	return TRUE;
}


/**
 * SelectByRect:
 *
 * @param rect 
 * @return int 
 */
int CTinyUMLEditor::SelectByRect(CRect &rect)
{
	int nRet=0;

	if(NULL != m_pDoc)
	{
		if(rect.left > rect.right) swap(rect.left,rect.right);
		if(rect.top > rect.bottom) swap(rect.top,rect.bottom);
		
		long i=0L;
		CTinyDocIterator* pIter=m_pDoc->CreateIteator();
		for(;!pIter->IsDone();pIter->Next())
		{
			CIsDrawEntity* pEnt=pIter->GetData();
			if(pEnt->IsKindOf(CTinyUMLRelation::TypeString())) continue;
			if(!pEnt->IsErased() && pEnt->IsInRect(rect))
			{
				pEnt->Select(TRUE);
				m_pSelectionSet->Append(pEnt);
				nRet++;
			}
		}
		delete pIter;
	}

	return nRet;
}

/**
 * DrawObjects:
 *
 * @param dc 
 * @param rect 
 * @return void 
 */
void CTinyUMLEditor::DrawObjects(CDC *dc, const CRect &rect) const
{
	if( m_pDoc )
	{
		const size_t siz = m_pDoc->GetEntCount();
		for(size_t i=0;i < siz ;i++)
		{
			CIsDrawEntity* obj=static_cast<CIsDrawEntity*>(m_pDoc->GetAt(i));
			if((m_pOnCursorEntity != obj) && !obj->IsErased())
			{
				EntityTypeMap* pTemplate = GetEntityTypeMap(obj->GetTypeString());
				if(pTemplate) pTemplate->GetDraw()->Draw(dc , obj , GetDoc() , this);
			}
			else if(!obj->IsErased() && (NULL != m_pOnCursorEntity) && m_pOnCursorEntity->IsKindOf(CTinyUMLPackage::TypeString()))
			{
				EntityTypeMap* pTemplate = GetEntityTypeMap(obj->GetTypeString());
				if(pTemplate) pTemplate->GetDraw()->Draw(dc , obj , GetDoc() , this);
			}
		}
		if(NULL != m_pOnCursorEntity)
		{
			if(!m_pOnCursorEntity->IsKindOf(CTinyUMLPackage::TypeString()))
			{
				EntityTypeMap* pTemplate = GetEntityTypeMap(m_pOnCursorEntity->GetTypeString());
				if(pTemplate) pTemplate->GetDraw()->DrawFocusObject(dc , m_pOnCursorEntity , GetDoc() , this);
			}
		}
	}
	if(NULL != m_pGhost)
	{
		EntityTypeMap* pTemplate = GetEntityTypeMap(m_pGhost->GetTypeString());
		if(pTemplate) pTemplate->GetDraw()->DrawTracker(dc , m_pGhost , GetDoc() ,this);
	}
}

void CTinyUMLEditor::OnDrawingLineColor(COLORREF color)
{
	m_lcolor = color;
}

void CTinyUMLEditor::OnDrawingLineStyle(const int &lstyle)
{
	m_lstyle = lstyle;
}

void CTinyUMLEditor::OnDrawingLineWeight(const int &lweight)
{
	m_lweight = lweight;
}
