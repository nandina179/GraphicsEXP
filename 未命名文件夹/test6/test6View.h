// test6View.h : interface of the CTest6View class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_TEST6VIEW_H__A0D13F17_0B12_47B9_8449_86ACE8E008BA__INCLUDED_)
#define AFX_TEST6VIEW_H__A0D13F17_0B12_47B9_8449_86ACE8E008BA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <afxtempl.h>
class Point
{
public:
	double x,y;
	Point(){x=0;y=0;};
	Point(double _x,double _y){x=_x;y=_y;};
	Point(CPoint p){x=p.x;y=p.y;};
	inline Point operator =(Point p){x=p.x;y=p.y;return (*this);};
	inline Point operator =(CPoint p){x=p.x;y=p.y;return (*this);};
	inline Point operator +=(Point p){x+=p.x;y+=p.y;return (*this);};
	inline Point operator +=(CPoint p){x+=p.x;y+=p.y;return (*this);};
    inline Point operator -=(Point p){x-=p.x;y-=p.y;return (*this);};
	inline Point operator -=(CPoint p){x-=p.x;y-=p.y;return (*this);};
    inline Point operator *=(double s){x*=s;y*=s;return (*this);};
	inline Point operator /=(double s){x/=s;y/=s;return (*this);};
    inline Point operator *(double s){Point t;t.x=x*s;t.y=y*s;return (t);};
	inline Point operator /(double s){Point t;t.x=x/s;t.y=y/s;return (t);};
	inline Point operator +(Point p){Point t;t.x=x+p.x;t.y=y+p.y;return (t);};
    inline Point operator +(CPoint p){Point t;t.x=x+p.x;t.y=y+p.y;return (t);};
    inline Point operator -(Point p){Point t;t.x=x-p.x;t.y=y-p.y;return (t);};
    inline Point operator -(CPoint p){Point t;t.x=x-p.x;t.y=y-p.y;return (t);};
	inline operator CPoint(){return CPoint((int)x,(int)y);};
};
static int step[100];
class CTest6View : public CView
{
public:
	bool m_ButtonDown;
	CPoint m_StartPoint;
	CPoint m_EndPoint;
	CArray<CPoint,CPoint> pointList;
	
    int x_step,y_step;

    //int y_step[100];
	int PCount;
	CPoint PCon[100];

protected: // create from serialization only
	CTest6View();
	DECLARE_DYNCREATE(CTest6View)

// Attributes
public:
	CTest6Doc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTest6View)
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
	void DrawBez2();
	Point decas(Point P[],double t);
	void Bez_to_point2(Point P[],Point pts[],int npoints);
	virtual ~CTest6View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CTest6View)
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnStart();
	afx_msg void OnEnd();
	afx_msg void OnTimer(UINT nIDEvent);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in test6View.cpp
inline CTest6Doc* CTest6View::GetDocument()
   { return (CTest6Doc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TEST6VIEW_H__A0D13F17_0B12_47B9_8449_86ACE8E008BA__INCLUDED_)
