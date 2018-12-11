// final07View.h : interface of the CFinal07View class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_FINAL07VIEW_H__EE1F2982_63F8_4A0B_ADD3_CF46C011FE55__INCLUDED_)
#define AFX_FINAL07VIEW_H__EE1F2982_63F8_4A0B_ADD3_CF46C011FE55__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "Point3D.h"

class CFinal07View : public CView
{
protected: // create from serialization only
	CFinal07View();
	DECLARE_DYNCREATE(CFinal07View)

// Attributes
public:
	CFinal07Doc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFinal07View)
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
	double Base(int i, int k, double knot[], int num, double u);
	CPoint BSpline(double knot[], int num, double u, int t);
	void BSplineToPoints();
	void From3DTo2D(Point3D* c, int n);
	void Draw3ColorBSpline();
	int typeEXP7;
	CArray<CPoint, CPoint> pointList;
	int N;									
	int K;									
	int nPoints;							
	CArray<CPoint, CPoint> pointPrintList;	
	CArray<CPoint, CPoint> pointPrint3DList;
	CPoint startPoint;
	CPoint endPoint;
	int TypeEXP;
	
	bool boolLButtonDown;
	bool boolRButtonDown;
	void ClearScreen();
	virtual ~CFinal07View();
private:
	Point3D LBB3D;
	CPoint	LBB2D;
	Point3D LBT3D;
	CPoint	LBT2D;
	Point3D LFB3D;
	CPoint	LFB2D;
	Point3D LFT3D;
	CPoint	LFT2D;
	Point3D RBB3D;
	CPoint	RBB2D;
	Point3D RBT3D;
	CPoint	RBT2D;
	Point3D RFB3D;
	CPoint	RFB2D;
	Point3D RFT3D;
	CPoint	RFT2D;
	double mPM[4][4];
	
	bool perspectiveProjection;
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CFinal07View)
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void Onone();
	afx_msg void Ontwo();
	afx_msg void Onthree();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in final07View.cpp
inline CFinal07Doc* CFinal07View::GetDocument()
   { return (CFinal07Doc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FINAL07VIEW_H__EE1F2982_63F8_4A0B_ADD3_CF46C011FE55__INCLUDED_)
