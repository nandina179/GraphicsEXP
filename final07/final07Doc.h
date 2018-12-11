// final07Doc.h : interface of the CFinal07Doc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_FINAL07DOC_H__7AEDC64F_2736_4F13_83C4_472A5D27F8DC__INCLUDED_)
#define AFX_FINAL07DOC_H__7AEDC64F_2736_4F13_83C4_472A5D27F8DC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CFinal07Doc : public CDocument
{
protected: // create from serialization only
	CFinal07Doc();
	DECLARE_DYNCREATE(CFinal07Doc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFinal07Doc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CFinal07Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CFinal07Doc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FINAL07DOC_H__7AEDC64F_2736_4F13_83C4_472A5D27F8DC__INCLUDED_)
