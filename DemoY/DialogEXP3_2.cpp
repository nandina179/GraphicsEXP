// DialogEXP3_2.cpp : implementation file
//

#include "stdafx.h"
#include "DemoY.h"
#include "DialogEXP3_2.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDialogEXP3_2 dialog


CDialogEXP3_2::CDialogEXP3_2(CWnd* pParent /*=NULL*/)
	: CDialog(CDialogEXP3_2::IDD, pParent)

	//{{AFX_DATA_INIT(CDialogEXP3_2)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	, mX(0)
	, mY(0)
	, mZ(0)
{
}


void CDialogEXP3_2::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDialogEXP3_2)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
	DDX_Text(pDX, IDC_EDITX, mX);
	DDX_Text(pDX, IDC_EDITY, mY);
	DDX_Text(pDX, IDC_EDITZ, mZ);
}


BEGIN_MESSAGE_MAP(CDialogEXP3_2, CDialog)
	//{{AFX_MSG_MAP(CDialogEXP3_2)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDialogEXP3_2 message handlers
