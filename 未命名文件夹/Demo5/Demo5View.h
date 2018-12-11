// Demo5View.h : interface of the CDemo5View class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_DEMO5VIEW_H__44AEC910_2073_47B2_B810_CA667C9D5241__INCLUDED_)
#define AFX_DEMO5VIEW_H__44AEC910_2073_47B2_B810_CA667C9D5241__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CDemo5View : public CView
{
protected: // create from serialization only
	CDemo5View();
	DECLARE_DYNCREATE(CDemo5View)

// Attributes
public:
	CDemo5Doc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDemo5View)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	void ClearScreen();
	double result[4][4];
	void MultiMatrix(int a[4][4],double b[4][2]);
	void DrawHermite();
	void B3Curves();
	void DrawCtrlPolygon();
	long Fac(int);
	double Cni(const int &n, const int &i);
	void DrawBezier();
	virtual ~CDemo5View();
	int typeEXP5;							//??????
	int N;									//??
	int K;									//??
	int nPoints;	
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	int n;
	int CtrlPointNum;
	CPoint *P;
	int type;
	bool bFlag;
	//{{AFX_MSG(CDemo5View)
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnBezier();
	afx_msg void On3b();
	afx_msg void OnH();
	afx_msg void OnExp54();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in Demo5View.cpp
inline CDemo5Doc* CDemo5View::GetDocument()
   { return (CDemo5Doc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DEMO5VIEW_H__44AEC910_2073_47B2_B810_CA667C9D5241__INCLUDED_)
