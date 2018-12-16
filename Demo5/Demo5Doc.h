// Demo5Doc.h : interface of the CDemo5Doc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_DEMO5DOC_H__82BB50F7_6579_4D44_8045_1E112E216E34__INCLUDED_)
#define AFX_DEMO5DOC_H__82BB50F7_6579_4D44_8045_1E112E216E34__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CDemo5Doc : public CDocument
{
protected: // create from serialization only
	CDemo5Doc();
	DECLARE_DYNCREATE(CDemo5Doc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDemo5Doc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CDemo5Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CDemo5Doc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DEMO5DOC_H__82BB50F7_6579_4D44_8045_1E112E216E34__INCLUDED_)
