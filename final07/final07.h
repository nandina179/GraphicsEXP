// final07.h : main header file for the FINAL07 application
//

#if !defined(AFX_FINAL07_H__4E6EA0E4_B047_4EF2_BE09_3DCD7A8B348D__INCLUDED_)
#define AFX_FINAL07_H__4E6EA0E4_B047_4EF2_BE09_3DCD7A8B348D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CFinal07App:
// See final07.cpp for the implementation of this class
//

class CFinal07App : public CWinApp
{
public:
	CFinal07App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFinal07App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CFinal07App)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FINAL07_H__4E6EA0E4_B047_4EF2_BE09_3DCD7A8B348D__INCLUDED_)
