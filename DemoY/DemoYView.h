// DemoYView.h : interface of the CDemoYView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_DEMOYVIEW_H__F14AB2C7_B5B0_4B10_ABEB_8D3DE88AAB71__INCLUDED_)
#define AFX_DEMOYVIEW_H__F14AB2C7_B5B0_4B10_ABEB_8D3DE88AAB71__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
//注释1部分：只绘制直线段
//注释2部分：绘制直线段及多边形
//注释3部分：重画
//注释4部分：颜色
//注释5部分：平移

//2+
#include <afxtempl.h>
#include "math.h"
class CDemoYView : public CView
{

protected: // create from serialization only
	CDemoYView();
	DECLARE_DYNCREATE(CDemoYView)

// Attributes
public:
	CDemoYDoc* GetDocument();
	//1
	CPoint m_StartPoint,m_EndPoint;//橡皮线的两个端点
	bool m_LButtonDown;//判断鼠标左键是否按下
	//2+
	CArray<CPoint,CPoint> pointList;//顶点列表
	int type;//选择绘制的图元类型
	
	//3+
	CObArray objList;//图元列表
	
	//4+
	int r,g,b;
	//4caijian
	typedef enum{
		TC_STRAIGHTLINE_COHEN,TC_STRAIGHTLINE_MIDDLEPOINT,TC_STRAIGHTLINE_LB,TC_POLYGON,TC_NONE
	}Type_Cut;

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDemoYView)
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
	void From3dTo2d();
	void DrawCubic();
	void DrawRect(CPoint P1,CPoint P2,CPoint P3,CPoint P4);
	void ClearScreen();
	void FILLANYTHING(UINT nFlags,CPoint point);
	void PatternFill(CDC *pDC, int x, int y);
//	void OnRButtonDblClk(UINT nFlags, CPoint point);
	bool m_RButtonDown;
	void Ellipse(CDC *pDC,int x1, int y1, int x2, int y2);
	void Circle(CDC *pDC,int x1, int y1, int x2, int y2);
	//void EdgeMarkFill(PointArray& ptArray,COLORREF color);
	void DDALine(CDC* pDC, int x1, int y1, int x2, int y2, COLORREF color);
	//5
	void Move(CPoint* point,int x, int y);
	virtual ~CDemoYView();

private:
	
	Point3D LBB3D;//LEFT BACK BOTTOM
	CPoint	LBB2D;//PROJECTION OF LEFT BACK BOTTOM POINT IN 2D
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
	//m-proj-matri
	bool perspectiveProjection;
public:
	Type_Cut m_type_cut;
	//bool m_LBDown;
	//bool m_RBDown;
	CPoint m_LTPoint;
	CPoint m_RBPoint;
	CPoint EPoint;//end point
	CPoint BPoint;//begin point 
	CArray<CPoint, CPoint> pointCutList;

	CPoint m_Polygon[512];
	int m_Num_Ply;
	CPoint m_ClipedPly[512];
	int m_NumCliped_Ply;

public:
	//void OnRButtonUp(UINT nFlags, CPoint point);
	//void OnRButtonDown(UINT nFlags, CPoint point);
	void DrawRect(CDC* pDC, CPoint P1, CPoint P3);
	void CutRight();
	void CutBottom();
	void CutLeft();
	void CutTop();
	void Makecode(CPoint Point,int& Code);
	void ShowLineSeg(CPoint BPoint,CPoint EPoint);
	void CorrectWindow();
	void RotateChange(double angle);
	void ProportionChange(double scale);
	void Isometric();
	//偏移量
	int shifting;
	//变化程度
	double mStep;	//平移
	double pStep;	//比例
	double rStep;	//旋转
	//透视点
	double perspectiveX;
	double perspectiveY;
	double perspectiveZ;
	//坐标轴
	int axes;
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CDemoYView)
	afx_msg void OnLine();
	afx_msg void OnPolygon();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnSetwidth();
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnCircle();
	afx_msg void OnTianchong();
	afx_msg void OnEllipse();
	afx_msg void OnAllclear();
	afx_msg void OnIsometric();
	afx_msg void OnCabinet();
	afx_msg void OnPerspective();
	afx_msg void OnCUT();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnRButtonDblClk(UINT nFlags, CPoint point);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in DemoYView.cpp
inline CDemoYDoc* CDemoYView::GetDocument()
   { return (CDemoYDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DEMOYVIEW_H__F14AB2C7_B5B0_4B10_ABEB_8D3DE88AAB71__INCLUDED_)
