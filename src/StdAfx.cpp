// stdafx.cpp : source file that includes just the standard includes
//	TinyUML.pch will be the pre-compiled header
//	stdafx.obj will contain the pre-compiled type information

#include "stdafx.h"
#include "MainFrm.h"
#include "ChildFrm.h"
#include "TinyUMLView.h"
#include "TinyUMLEditor.h"

/**
 * TinyGetCurEditor:
 *
 * @return CTinyUMLEditor* 
 */
CTinyUMLEditor* TinyGetCurEditor()
{
	CMainFrame* pMainFrame = static_cast<CMainFrame*>(AfxGetMainWnd());
	CChildFrame* pFrame = static_cast<CChildFrame*>(pMainFrame->GetActiveFrame());
	CTinyUMLView* pView = static_cast<CTinyUMLView*>(pFrame->GetActiveView());
	
	return pView->GetUMLEditor();
}