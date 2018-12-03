#if !defined(AFX_DIALOGEXP3_2_H__FBEE5DF5_9350_4032_8447_D16B758E4327__INCLUDED_)
#define AFX_DIALOGEXP3_2_H__FBEE5DF5_9350_4032_8447_D16B758E4327__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DialogEXP3_2.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDialogEXP3_2 dialog

class CDialogEXP3_2 : public CDialog
{
// Construction
public:
	CDialogEXP3_2(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDialogEXP3_2)
	enum { IDD = IDD_DIALOG3_2 };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDialogEXP3_2)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDialogEXP3_2)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

public:
	double mX;
	double mY;
	double mZ;
};
//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DIALOGEXP3_2_H__FBEE5DF5_9350_4032_8447_D16B758E4327__INCLUDED_)
