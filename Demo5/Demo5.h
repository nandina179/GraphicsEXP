// Demo5.h : main header file for the DEMO5 application
//

#if !defined(AFX_DEMO5_H__DBFCCEAB_D3FD_4DDA_A1AF_69AE9E60DC31__INCLUDED_)
#define AFX_DEMO5_H__DBFCCEAB_D3FD_4DDA_A1AF_69AE9E60DC31__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CDemo5App:
// See Demo5.cpp for the implementation of this class
//

class CDemo5App : public CWinApp
{
public:
	CDemo5App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDemo5App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CDemo5App)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DEMO5_H__DBFCCEAB_D3FD_4DDA_A1AF_69AE9E60DC31__INCLUDED_)
