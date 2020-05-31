// TinyUMLAttributesPropertyPage.cpp : implementation file
//

#include "stdafx.h"
#include "TinyUML.h"
#include "TinyUMLAttributesPropertyPage.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

CArray<CString,const CString &> CTinyUMLAttributesPropertyPage::m_TypesArray;
/////////////////////////////////////////////////////////////////////////////
// CTinyUMLAttributesPropertyPage property page

IMPLEMENT_DYNCREATE(CTinyUMLAttributesPropertyPage, CPropertyPage)

CTinyUMLAttributesPropertyPage::CTinyUMLAttributesPropertyPage() : CPropertyPage(CTinyUMLAttributesPropertyPage::IDD)
{
	//{{AFX_DATA_INIT(CTinyUMLAttributesPropertyPage)
	m_name = _T("");
	m_bShowAttributes = FALSE;
	m_access = 0;
	m_isStatic = 0;
	//}}AFX_DATA_INIT
}

CTinyUMLAttributesPropertyPage::~CTinyUMLAttributesPropertyPage()
{
}

/**
 * DoDataExchange:
 *
 * @param pDX 
 * @return void 
 */
void CTinyUMLAttributesPropertyPage::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CTinyUMLAttributesPropertyPage)
	DDX_Control(pDX, IDC_ATTRIBUTE_TYPE,m_wndTypeCombo);
	DDX_Control(pDX, IDC_ATTRIBUTE_NAME,m_wndAttributeName);
	DDX_Control(pDX, IDC_ATTRIBUTES, m_attributesList);
	DDX_Control(pDX, IDC_MEMBER_ACCESS,m_wndAccessCombo);
	DDX_Text(pDX,IDC_ATTRIBUTE_TYPE,m_type);
	DDX_Text(pDX, IDC_ATTRIBUTE_NAME, m_name);

	DDX_Check(pDX, IDC_SHOW_ATTRIBUTES, m_bShowAttributes);
	DDX_CBIndex(pDX, IDC_MEMBER_ACCESS, m_access);
	DDX_Control(pDX,IDC_ADD_ATTRIBUTE,m_btnAddAttribute);
	DDX_Control(pDX,IDC_SET_ATTRIBUTE,m_btnSetAttribute);
	DDX_Control(pDX,IDC_REMOVE_ATTRIBUTE,m_btnRemoveAttribute);

	DDX_Check(pDX,IDC_CHECK_STATIC,m_isStatic);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CTinyUMLAttributesPropertyPage, CPropertyPage)
	//{{AFX_MSG_MAP(CTinyUMLAttributesPropertyPage)
	ON_BN_CLICKED(IDC_ADD_ATTRIBUTE, OnAddAttribute)
	ON_BN_CLICKED(IDC_SET_ATTRIBUTE, OnSetAttribute)
	ON_BN_CLICKED(IDC_REMOVE_ATTRIBUTE, OnRemoveAttribute)
	ON_NOTIFY(UDN_DELTAPOS, IDC_MOVE_ATTRIBUTE, OnDeltaposMoveAttribute)
	ON_CBN_SELCHANGE(IDC_MEMBER_ACCESS, OnSelchangeMemeberAccess)
	ON_EN_CHANGE(IDC_ATTRIBUTE_NAME, OnChangeAttributeName)
	ON_EN_CHANGE(IDC_EDIT_INITIAL_VALUE, OnChangeMemberInitial)
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_ATTRIBUTES, OnSelchangeAttributes)
	ON_WM_CTLCOLOR()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTinyUMLAttributesPropertyPage message handlers

/**
 * UpdateAttribute:
 *
 * @param index 
 * @param bSave 
 * @return void 
 */
void CTinyUMLAttributesPropertyPage::UpdateAttribute(long index, bool bSave)
{
	ASSERT(index >= 0 && index < m_attributes.GetSize());
	const static TCHAR szAccess[4][2]={"+","#","-",""};

	CTinyUMLClass::Member attribute = m_attributes[index];

	if(bSave){
		UpdateData(true);
		/*
		attribute.type = m_type;
		
		// update listbox only if name was changed
		if((attribute.access != m_access) || (attribute.name != m_name)){
			int oldCaretIndex = m_attributesList.GetCaretIndex();
			m_attributesList.DeleteString(index);
			m_attributesList.InsertString(index, m_type + " " + m_name);
			m_attributesList.SetCaretIndex(oldCaretIndex);
		}
		attribute.name = m_name;

		switch(m_access){
			case 0: attribute.access = CTinyUMLClass::Attribute::public_attribute; break;
			case 1: attribute.access = CTinyUMLClass::Attribute::protected_attribute; break;
			case 2: attribute.access = CTinyUMLClass::Attribute::private_attribute; break;
			case 3: attribute.access = CTinyUMLClass::Attribute::static_attribute; break;
		}

		m_attributes[index] = attribute;
		*/
		attribute.property = (m_isStatic == TRUE) ? CTinyUMLClass::Member::static_property : 0x00;
	}else{
		m_type = attribute.type;
		m_wndTypeCombo.SetWindowText(m_type);
		
		m_name = attribute.name;

		switch(attribute.access){
			case CTinyUMLClass::Member::public_member: m_access = 0; break;
			case CTinyUMLClass::Member::protected_member: m_access = 1; break;
			case CTinyUMLClass::Member::private_member: m_access = 2; break;
		}

		m_isStatic = (attribute.property & CTinyUMLClass::Member::static_property) ? TRUE : FALSE;

		UpdateData(false);
	}
}

/**
 * OnAddAttribute:
 *
 * @return void 
 */
void CTinyUMLAttributesPropertyPage::OnAddAttribute() 
{
	UpdateData();

	long index = m_attributesList.GetItemCount();// != 0 ? currentAttribute() + 1 : 0;
	
	CTinyUMLClass::Member newAttribute;
	newAttribute.type   = m_type;
	newAttribute.name   = m_name;
	newAttribute.access = m_access;
		
	m_attributes.InsertAt(index, newAttribute);
	m_attributesList.InsertItem(index, newAttribute.type,newAttribute.name,
		CTinyUMLClass::Member::public_member    == newAttribute.access ? "public" : 
		CTinyUMLClass::Member::protected_member == newAttribute.access ? "protected" : "private");
	
	UpdateAttribute(index, false);
}

/**
 * OnSetAttribute:
 *
 * @return void 
 */
void CTinyUMLAttributesPropertyPage::OnSetAttribute() 
{
	UpdateData();

	UINT uSelectedCount = m_attributesList.GetSelectedCount();
	int nItem=-1;
	// Update all of the selected items.
	if (uSelectedCount > 0){
		nItem = m_attributesList.GetNextItem(nItem, LVNI_SELECTED);
		ASSERT(nItem != -1);
		CTinyUMLClass::Member newAttribute;
		newAttribute.type = m_type;
		newAttribute.name = m_name;
		newAttribute.access = m_access;
		
		m_attributes.SetAt(nItem,newAttribute);
		m_attributesList.SetItemText(nItem,0,newAttribute.type);
		m_attributesList.SetItemText(nItem,1,newAttribute.name);
		switch(newAttribute.access)
		{
			case CTinyUMLClass::Member::public_member:
				m_attributesList.SetItemText(nItem,2,_T("public"));
				break;
			case CTinyUMLClass::Member::protected_member:
				m_attributesList.SetItemText(nItem,2,_T("protected"));
				break;
			case CTinyUMLClass::Member::private_member: 
				m_attributesList.SetItemText(nItem,2,_T("private"));
				break;
		}

		UpdateAttribute(nItem, false);
	}
}

/**
 * OnRemoveAttribute:
 *
 * @return void 
 */
void CTinyUMLAttributesPropertyPage::OnRemoveAttribute() 
{
	UINT uSelectedCount = m_attributesList.GetSelectedCount();
	int  nItem = -1;
	
	// Update all of the selected items.
	if (uSelectedCount > 0){
		nItem = m_attributesList.GetNextItem(nItem, LVNI_SELECTED);
		ASSERT(nItem != -1);
		m_attributesList.DeleteItem(nItem);
		m_attributes.RemoveAt(nItem);
	}
}

/**
 * OnDeltaposMoveAttribute:
 *
 * @param pNMHDR 
 * @param pResult 
 * @return void 
 */
void CTinyUMLAttributesPropertyPage::OnDeltaposMoveAttribute(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_UPDOWN* pNMUpDown = (NM_UPDOWN*)pNMHDR;
	*pResult = 0;

	POSITION pos=m_attributesList.GetFirstSelectedItemPosition();
	int index=m_attributesList.GetNextSelectedItem(pos);
	if(-1 != index){
		CTinyUMLClass::Member attribute = m_attributes[index];
		
		m_attributes.RemoveAt(index);
		m_attributesList.DeleteItem(index);
		
		index = pNMUpDown->iDelta < 0 ? index - 1 : index + 1;
		
		if(index < 0)
			index = 0;
		if(index > m_attributes.GetSize())
			index = m_attributes.GetSize();
		
		m_attributes.InsertAt(index, attribute);
		m_attributesList.InsertItem(index, attribute.type,attribute.name,attribute.property);
		//	m_attributesList.SetSel(-1, false);
		//	m_attributesList.SetSel(index);
	}
}

void CTinyUMLAttributesPropertyPage::OnSelchangeMemeberAccess() 
{
	UpdateData(true);
	//UpdateAttribute(currentAttribute(), true);
}

void CTinyUMLAttributesPropertyPage::OnChangeAttributeName() 
{
	UpdateData(true);
	//UpdateAttribute(currentAttribute(), true);
}

void CTinyUMLAttributesPropertyPage::OnChangeMemberInitial() 
{
	UpdateData(true);
}

/**
 * OnInitDialog:
 *
 * @return BOOL 
 */
BOOL CTinyUMLAttributesPropertyPage::OnInitDialog() 
{
	CPropertyPage::OnInitDialog();

	m_attributesList.SetHeadings(_T("Type, 150; Name, 200; Access, 50"));

	for(long i = 0; i < m_attributes.GetSize(); ++i)
	{
		if(CB_ERR == m_wndTypeCombo.FindStringExact(-1, m_attributes[i].type))
			m_wndTypeCombo.AddString(m_attributes[i].type);
	}
	m_wndTypeCombo.EnableAutoCompletion(TRUE);
	
	for(i = 0; i < m_attributes.GetSize(); ++i)
		m_attributesList.InsertItem(i,m_attributes[i].type,m_attributes[i].name,
		CTinyUMLClass::Member::public_member    == m_attributes[i].access ? "public" : 
		CTinyUMLClass::Member::protected_member == m_attributes[i].access ? "protected" : "private");

	if(m_attributes.GetSize() != 0){
		//m_attributesList.SetSel(0);
		UpdateAttribute(0, false);
	}

	m_btnAddAttribute.SetIcon(IDI_ADD,16,16);
	m_btnSetAttribute.SetIcon(IDI_SET,16,16);
	m_btnRemoveAttribute.SetIcon(IDI_REMOVE,16,16);
	
	return true;
}

/**
 * OnCtlColor:
 *
 * @param pDC 
 * @param pWnd 
 * @param nCtlColor 
 * @return HBRUSH 
 */
HBRUSH CTinyUMLAttributesPropertyPage::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
{
	HBRUSH hbr = CPropertyPage::OnCtlColor(pDC, pWnd, nCtlColor);
	
	// set the combo boxes text and background colors...
	int nItem = pWnd->GetDlgCtrlID();
	switch (nItem){
		case IDC_ATTRIBUTE_TYPE:
			if( pWnd->IsWindowEnabled( )) 
				pDC->SetTextColor(RGB(0,0,255));
			break;

		case IDC_MEMBER_ACCESS:
			if( pWnd->IsWindowEnabled( ))
				pDC->SetTextColor(RGB(0,0,255));
			break;
	}

	return hbr;
}

/**
 * OnSelchangeAttributes:
 *
 * @param pNMHDR 
 * @param pResult 
 * @return void 
 */
void CTinyUMLAttributesPropertyPage::OnSelchangeAttributes(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_LISTVIEW* pNMListView = (NM_LISTVIEW*)pNMHDR;
	
	UpdateAttribute(pNMListView->iItem,false);
	
	*pResult = 0;
}
