// TinyUMLMMethodsPropertyPage.cpp : implementation file
//

#include "stdafx.h"
#include "TinyUML.h"
#include "TinyUMLMethodsPropertyPage.h"
#include "EditMethodCodeDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTinyUMLMethodsPropertyPage property page

IMPLEMENT_DYNCREATE(CTinyUMLMethodsPropertyPage, CPropertyPage)

CTinyUMLMethodsPropertyPage::CTinyUMLMethodsPropertyPage() : CPropertyPage(CTinyUMLMethodsPropertyPage::IDD)
{
	//{{AFX_DATA_INIT(CTinyUMLMethodsPropertyPage)
	m_name = _T("");
	m_type = _T("");
	m_property = -1L;
	m_isVirtual = m_isPure = m_isInline = m_isConst = FALSE;
	m_isStatic  = FALSE;
	m_bShowMethods = FALSE;
	//}}AFX_DATA_INIT
}

/**
 * ~CTinyUMLMethodsPropertyPage:
 *
 * @return  
 */
CTinyUMLMethodsPropertyPage::~CTinyUMLMethodsPropertyPage()
{
}

/**
 * DoDataExchange:
 *
 * @param pDX 
 * @return void 
 */
void CTinyUMLMethodsPropertyPage::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CTinyUMLMethodsPropertyPage)
	DDX_Control(pDX, IDC_LIST_METHOD, m_ctrlMethodsList);
	DDX_Control(pDX,IDC_METHOD_TYPE,m_wndMethodType);
	DDX_Control(pDX,IDC_METHOD_NAME,m_wndMethodName);
	DDX_Text(pDX,IDC_METHOD_TYPE,m_type);
	DDX_Text(pDX, IDC_METHOD_NAME, m_name);
	DDX_Control(pDX,IDC_METHOD_ACCESS,m_wndMethodAccess);
	DDX_CBIndex(pDX, IDC_METHOD_ACCESS, m_access);
	DDX_Control(pDX,IDC_ADD_METHOD,m_btnAddMethod);
	DDX_Control(pDX,IDC_SET_METHOD,m_btnSetMethod);
	DDX_Check(pDX, IDC_SHOW_METHODS, m_bShowMethods);
	DDX_Control(pDX,IDC_EDIT_METHOD,m_btnEditMethod);
	DDX_Control(pDX,IDC_REMOVE_METHOD,m_btnRemoveMethod);

	DDX_Check(pDX,IDC_VIRTUAL,m_isVirtual);
	DDX_Check(pDX,IDC_PURE,m_isPure);
	DDX_Check(pDX,IDC_INLINE,m_isInline);
	DDX_Check(pDX,IDC_CONSTMETHOD,m_isConst);
	DDX_Check(pDX,IDC_STATIC_METHOD,m_isStatic);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CTinyUMLMethodsPropertyPage, CPropertyPage)
	//{{AFX_MSG_MAP(CTinyUMLMethodsPropertyPage)
	ON_CBN_SELCHANGE(IDC_METHOD_TYPE, OnSelchangeMethodType)
	ON_EN_CHANGE(IDC_METHOD_NAME, OnChangeMethodName)
	ON_CBN_SELCHANGE(IDC_METHOD_ACCESS, OnSelchangeMethodAccess)
	ON_BN_CLICKED(IDC_ADD_METHOD, OnAddMethod)
	ON_BN_CLICKED(IDC_SET_METHOD, OnSetMethod)
	ON_BN_CLICKED(IDC_EDIT_METHOD, OnEditMethod)
	ON_BN_CLICKED(IDC_REMOVE_METHOD, OnRemoveMethod)
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST_METHOD, OnSelchangeMethods)
	ON_WM_CTLCOLOR()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTinyUMLMethodsPropertyPage message handlers

/**
 * OnInitDialog:
 *
 * @return BOOL 
 */
BOOL CTinyUMLMethodsPropertyPage::OnInitDialog() 
{
	CPropertyPage::OnInitDialog();
	
	m_ctrlMethodsList.SetHeadings(_T("Type, 150; Name, 200; Access, 50"));

	for(long i = 0; i < m_methods.GetSize(); ++i)
	{
		m_ctrlMethodsList.InsertItem(i,m_methods[i].type,m_methods[i].name,
		CTinyUMLClass::Method::public_method    == m_methods[i].access ? "public" : 
		CTinyUMLClass::Method::protected_method == m_methods[i].access ? "protected" : "private");
	}
	
	if(m_methods.GetSize() != 0) m_ctrlMethodsList.SelectItem(0);
	
	m_btnAddMethod.SetIcon(IDI_ADD,16,16);
	m_btnSetMethod.SetIcon(IDI_SET,16,16);
	m_btnEditMethod.SetIcon(IDI_EDIT_METHOD,16,16);
	m_btnRemoveMethod.SetIcon(IDI_REMOVE,16,16);

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

/**
 * UpdateMethod:
 *
 * @param index 
 * @param bSave 
 * @return void 
 */
void CTinyUMLMethodsPropertyPage::UpdateMethod(long index, bool bSave)
{
	ASSERT(index >= 0 && index < m_methods.GetSize());

	CTinyUMLClass::Method method = m_methods[index];

	if(bSave)
	{
		UpdateData(true);

		// update listbox only if name was changed
		/*
		if(method.name != m_name)
		{
			int oldCaretIndex = m_ctrlMethodsList.GetCaretIndex();
			m_ctrlMethodsList.DeleteString(index);
			m_ctrlMethodsList.InsertString(index, m_name);
			m_ctrlMethodsList.SetCaretIndex(oldCaretIndex);
		}
		*/

		method.name = m_name;

		switch(m_access)
		{
			case 0: method.type = CTinyUMLClass::Method::public_method; break;
			case 1: method.type = CTinyUMLClass::Method::protected_method; break;
			case 2: method.type = CTinyUMLClass::Method::private_method; break;
			case 3: method.type = CTinyUMLClass::Method::abstract_method; break;
		}
		
		method.property = (m_isVirtual == TRUE) ? CTinyUMLClass::Method::virtual_property : 0x00;
		method.property |= (m_isPure == TRUE) ? CTinyUMLClass::Method::pure_property : 0x00;
		method.property |= (m_isConst == TRUE) ? CTinyUMLClass::Method::const_property : 0x00;
		method.property |= (m_isInline == TRUE) ? CTinyUMLClass::Method::inline_property : 0x00;
		method.property |= (m_isStatic == TRUE) ? CTinyUMLClass::Method::static_property : 0x00;
		
		m_methods[index] = method;
	}
	else
	{
		m_type = method.type;
		m_name = method.name;

		switch(method.access){
			case CTinyUMLClass::Method::public_method: m_access = 0; break;
			case CTinyUMLClass::Method::protected_method: m_access = 1; break;
			case CTinyUMLClass::Method::private_method: m_access = 2; break;
			case CTinyUMLClass::Method::abstract_method: m_access = 3; break;
		}

		m_isVirtual= (method.property & CTinyUMLClass::Method::virtual_property) ? TRUE : FALSE;
		m_isInline = (method.property & CTinyUMLClass::Method::inline_property) ? TRUE : FALSE;
		m_isConst  = (method.property & CTinyUMLClass::Method::const_property) ? TRUE : FALSE;
		m_isPure   = (method.property & CTinyUMLClass::Method::pure_property) ? TRUE : FALSE;
		m_isStatic = (method.property & CTinyUMLClass::Method::static_property) ? TRUE : FALSE;

		UpdateData(false);
	}
}

/**
 * OnSelchangeMethodType:
 *
 * @return void 
 */
void CTinyUMLMethodsPropertyPage::OnSelchangeMethodType() 
{
	UpdateData();
	//UpdateMethod(currentMethod(), true);	
}

void CTinyUMLMethodsPropertyPage::OnChangeMethodName() 
{
	UpdateData();
	//UpdateMethod(currentMethod(), true);
}

void CTinyUMLMethodsPropertyPage::OnSelchangeMethodAccess() 
{
	UpdateData();
	//UpdateMethod(currentMethod(), true);	
}

/**
 * OnAddMethod:
 *
 * @return void 
 */
void CTinyUMLMethodsPropertyPage::OnAddMethod() 
{
	UpdateData();

	long index = m_ctrlMethodsList.GetItemCount();
	
	CTinyUMLClass::Method newMethod;
	newMethod.type = m_type;
	newMethod.name = m_name;
	newMethod.access = m_access;
	newMethod.property = 
		m_isVirtual	? CTinyUMLClass::Method::Property::virtual_property : 0x00 + 
		m_isPure	? CTinyUMLClass::Method::Property::pure_property    : 0x00 + 
		m_isConst	? CTinyUMLClass::Method::Property::const_property   : 0x00 + 
		m_isInline	? CTinyUMLClass::Method::Property::inline_property  : 0x00 +
		m_isStatic	? CTinyUMLClass::Method::Property::static_property  : 0x00;

	m_methods.InsertAt(index, newMethod);
	m_ctrlMethodsList.InsertItem(index,newMethod.type,newMethod.name,
		CTinyUMLClass::Method::public_method    == newMethod.access ? "public" : 
		CTinyUMLClass::Method::protected_method == newMethod.access ? "protected" : "private");

	UpdateMethod(index, false);
}

/**
 * OnSetMethod:
 *
 * @return void 
 */
void CTinyUMLMethodsPropertyPage::OnSetMethod() 
{
	UpdateData();

	UINT uSelectedCount = m_ctrlMethodsList.GetSelectedCount();
	int  nItem = -1;
	
	// Update all of the selected items.
	if (uSelectedCount > 0){
		nItem = m_ctrlMethodsList.GetNextItem(nItem, LVNI_SELECTED);
		ASSERT(nItem != -1);
		
		CTinyUMLClass::Method newMethod;
		newMethod.type = m_type;
		newMethod.name = m_name;
		newMethod.access = m_access;
		newMethod.property = 
			m_isVirtual	? CTinyUMLClass::Method::Property::virtual_property : 0x00 + 
			m_isPure	? CTinyUMLClass::Method::Property::pure_property    : 0x00 + 
			m_isConst	? CTinyUMLClass::Method::Property::const_property   : 0x00 + 
			m_isInline	? CTinyUMLClass::Method::Property::inline_property  : 0x00 +
			m_isStatic	? CTinyUMLClass::Method::Property::static_property  : 0x00;
		
		m_methods.SetAt(nItem,newMethod);
		m_ctrlMethodsList.SetItemText(nItem,0,newMethod.type);
		m_ctrlMethodsList.SetItemText(nItem,1,newMethod.name);
		m_ctrlMethodsList.SetItemText(nItem,2,
			CTinyUMLClass::Method::public_method    == newMethod.access ? "public" : 
			CTinyUMLClass::Method::protected_method == newMethod.access ? "protected" : "private");
		
		UpdateMethod(nItem, false);
	}
}

/**
 * OnEditMethod:
 *
 * @return void 
 */
void CTinyUMLMethodsPropertyPage::OnEditMethod()
{
	UINT uSelectedCount = m_ctrlMethodsList.GetSelectedCount();
	int  nItem = -1;
	
	// Update all of the selected items.
	if (uSelectedCount > 0)
	{
		nItem = m_ctrlMethodsList.GetNextItem(nItem, LVNI_SELECTED);
		ASSERT(nItem != -1);
		
		CTinyUMLClass::Method method=m_methods.GetAt(nItem);
		//CEditMethodCodeDlg dlg(&method);
		//if(IDOK == dlg.DoModal()) m_methods.SetAt(nItem,method);
	}
}

/**
 * OnRemoveMethod:
 *
 * @return void 
 */
void CTinyUMLMethodsPropertyPage::OnRemoveMethod() 
{
	UINT uSelectedCount = m_ctrlMethodsList.GetSelectedCount();
	int  nItem = -1;
	
	// Update all of the selected items.
	if (uSelectedCount > 0){
		nItem = m_ctrlMethodsList.GetNextItem(nItem, LVNI_SELECTED);
		ASSERT(nItem != -1);
		m_ctrlMethodsList.DeleteItem(nItem);
		m_methods.RemoveAt(nItem);
	}
}

void CTinyUMLMethodsPropertyPage::OnSelchangeMethods(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_LISTVIEW* pNMListView = (NM_LISTVIEW*)pNMHDR;
	
	UpdateMethod(pNMListView->iItem,false);
	
	*pResult = 0;
}

HBRUSH CTinyUMLMethodsPropertyPage::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
{
	HBRUSH hbr = CPropertyPage::OnCtlColor(pDC, pWnd, nCtlColor);
	
	// set the combo boxes text and background colors...
	int nItem = pWnd->GetDlgCtrlID();
	switch (nItem){
		case IDC_METHOD_TYPE:
			if( pWnd->IsWindowEnabled( )) 
				pDC->SetTextColor(RGB(0,0,255));
			break;

		case IDC_METHOD_ACCESS:
			if( pWnd->IsWindowEnabled( ))
				pDC->SetTextColor(RGB(0,0,255));
			break;
	}

	return hbr;
}
