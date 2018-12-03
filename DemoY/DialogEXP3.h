#if !defined(AFX_DIALOGEXP3_H__12531DC1_78DF_4689_982B_1CE707319117__INCLUDED_)
#define AFX_DIALOGEXP3_H__12531DC1_78DF_4689_982B_1CE707319117__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DialogEXP3.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDialogEXP3 dialog

class CDialogEXP3 : public CDialog
{
// Construction
public:
	CDialogEXP3(CWnd* pParent = NULL);   // standard constructor
public:

	int isXYZ;
	CComboBox comboXYZ;
	afx_msg void OnCbnSelchangeComboXyz();
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();

// Dialog Data
	//{{AFX_DATA(CDialogEXP3)
	enum { IDD = IDD_DIALOG2 };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDialogEXP3)
	public:
	virtual BOOL Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID, CCreateContext* pContext = NULL);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual void CalcWindowRect(LPRECT lpClientRect, UINT nAdjustType = adjustBorder);
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDialogEXP3)
	afx_msg void OnSelchangeList2();
	afx_msg void OnZ();
	afx_msg void OnY();
	afx_msg void OnX();
	virtual void OnCancel();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DIALOGEXP3_H__12531DC1_78DF_4689_982B_1CE707319117__INCLUDED_)
