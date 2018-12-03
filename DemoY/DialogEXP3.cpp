// DialogEXP3.cpp : implementation file
//

#include "stdafx.h"
#include "DemoY.h"
#include "DialogEXP3.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDialogEXP3 dialog


CDialogEXP3::CDialogEXP3(CWnd* pParent /*=NULL*/)
	: CDialog(CDialogEXP3::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDialogEXP3)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	int isXYZ;

}


void CDialogEXP3::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDialogEXP3)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
	//DDX_Control(pDX, IDC_COMBO_XYZ, comboXYZ);
}


BEGIN_MESSAGE_MAP(CDialogEXP3, CDialog)
	//{{AFX_MSG_MAP(CDialogEXP3)
	ON_BN_CLICKED(IDC_Z, OnZ)
	ON_BN_CLICKED(IDC_Y, OnY)
	ON_BN_CLICKED(IDC_X, OnX)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDialogEXP3 message handlers

BOOL CDialogEXP3::Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID, CCreateContext* pContext) 
{
	// TODO: Add your specialized code here and/or call the base class
	
	return CDialog::Create(IDD, pParentWnd);
}

void CDialogEXP3::CalcWindowRect(LPRECT lpClientRect, UINT nAdjustType) 
{
	// TODO: Add your specialized code here and/or call the base class
	
	CDialog::CalcWindowRect(lpClientRect, nAdjustType);
}



void CDialogEXP3::OnZ() 
{
	// TODO: Add your control notification handler code here
	isXYZ = 2;
}

void CDialogEXP3::OnY() 
{
	// TODO: Add your control notification handler code here
	isXYZ = 3;
}

void CDialogEXP3::OnX() 
{
	// TODO: Add your control notification handler code here
	isXYZ = 1;
}

void CDialogEXP3::OnCancel() 
{
	// TODO: Add extra cleanup here
	
	CDialog::OnCancel();
}

void CDialogEXP3::OnOK() 
{
	// TODO: Add extra validation here
	UpdateData(TRUE);
	//isXYZ = comboXYZ.GetCurSel() + 1;
	UpdateData(FALSE);
	CDialog::OnOK();
}
