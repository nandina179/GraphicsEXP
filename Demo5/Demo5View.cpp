// Demo5View.cpp : implementation of the CDemo5View class
//

#include "stdafx.h"
#include "Demo5.h"

#include "Demo5Doc.h"
#include "Demo5View.h"
#define N_MAX_POINT 21
#include "math.h"
#define Round(d) int(floor(d+0.5))//四舍五入宏定义
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDemo5View

IMPLEMENT_DYNCREATE(CDemo5View, CView)

BEGIN_MESSAGE_MAP(CDemo5View, CView)
	//{{AFX_MSG_MAP(CDemo5View)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONDBLCLK()
	ON_COMMAND(ID_Bezier, OnBezier)
	ON_COMMAND(ID_3B, On3b)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDemo5View construction/destruction

CDemo5View::CDemo5View()
{
	// TODO: add construction code here
	P=new CPoint[N_MAX_POINT];
	bFlag=FALSE;
	CtrlPointNum=0;

}

CDemo5View::~CDemo5View()
{
		if(P!=NULL)
	{
		delete []P;
		P=NULL;
	}
}

BOOL CDemo5View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CDemo5View drawing

void CDemo5View::OnDraw(CDC* pDC)
{
	CDemo5Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CDemo5View printing

BOOL CDemo5View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CDemo5View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CDemo5View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CDemo5View diagnostics

#ifdef _DEBUG
void CDemo5View::AssertValid() const
{
	CView::AssertValid();
}

void CDemo5View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CDemo5Doc* CDemo5View::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDemo5Doc)));
	return (CDemo5Doc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CDemo5View message handlers


void CDemo5View::DrawBezier()
{
	CDC *pDC=GetDC();
	CPen NewPen,*pOldPen;
	NewPen.CreatePen(PS_SOLID,1,RGB(0,0,255));//曲线颜色为蓝色
	pOldPen=pDC->SelectObject(&NewPen);	
	pDC->MoveTo(P[0]);
	for(double t=0.0;t<=1.0;t+=0.01)
	{		
		double x=0,y=0;
		for(int i=0;i<=n;i++)
		{
			x+=P[i].x*Cni(n,i)*pow(t,i)*pow(1-t,n-i);
			y+=P[i].y*Cni(n,i)*pow(t,i)*pow(1-t,n-i);
		}
		pDC->LineTo(Round(x),Round(y));
	}
	pDC->SelectObject(pOldPen);
	NewPen.DeleteObject();
	ReleaseDC(pDC);

}

double CDemo5View::Cni(const int &n, const int &i)
{
	return double(Fac(n))/(Fac(i)*Fac(n-i));

}

long CDemo5View::Fac(int m)
{
	long f;
	if(m==0||m==1)
		f=1;
	else
		f=m*Fac(m-1);
	return f;

}

void CDemo5View::DrawCtrlPolygon()
{
	CDC *pDC=GetDC();
	CBrush NewBrush,*pOldBrush;
	pOldBrush=(CBrush*)pDC->SelectStockObject(GRAY_BRUSH);//灰色实心圆绘制控制点
	for(int i=0;i<=n;i++)
	{
		if(0==i)
		{
			pDC->MoveTo(P[i]);
			pDC->Ellipse(P[i].x-2,P[i].y-2,P[i].x+2,P[i].y+2);
		}
		else
		{
			pDC->LineTo(P[i]);
			pDC->Ellipse(P[i].x-2,P[i].y-2,P[i].x+2,P[i].y+2);
		}
	}
	pDC->SelectObject(pOldBrush);
	ReleaseDC(pDC);

}

void CDemo5View::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	if(bFlag)
	{
		P[CtrlPointNum].x=point.x;
		P[CtrlPointNum].y=point.y;
		if(CtrlPointNum<N_MAX_POINT-1)//N_MAX_POINT为控制点个数的最大值
			CtrlPointNum++;
		else
			bFlag=FALSE;
		n=CtrlPointNum-1;
		DrawCtrlPolygon();
	}
	CView::OnLButtonDown(nFlags, point);

}

void CDemo5View::OnLButtonDblClk(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	if(type==2){
	if(0!=CtrlPointNum)
		DrawBezier();
	}
	if(type==3){
	if(0!=CtrlPointNum)
       B3Curves();
	}


	CView::OnLButtonDblClk(nFlags, point);
	
}

void CDemo5View::OnBezier() 
{
	// TODO: Add your command handler code here
	bFlag=true;
	RedrawWindow();
	type=2;
	CtrlPointNum=0;
}



void CDemo5View::On3b() 
{
	// TODO: Add your command handler code here
    bFlag=true;
	RedrawWindow();
	type=3;
	CtrlPointNum=0;	
}

void CDemo5View::B3Curves()
{
	CDC *pDC=GetDC();
	CPoint q;
	double F03,F13,F23,F33;
	CPen NewPen,*pOldPen;
	NewPen.CreatePen(PS_SOLID,1,RGB(0,0,255));//曲线颜色为蓝色
	pOldPen=pDC->SelectObject(&NewPen);	
	q.x=Round((P[0].x+4.0*P[1].x+P[2].x)/6.0);//t＝0的起点x坐标
	q.y=Round((P[0].y+4.0*P[1].y+P[2].y)/6.0);//t＝0的起点y坐标
	
	pDC->MoveTo(q);
	for(double t=0;t<=1;t+=0.01)
		{
			F03=(-t*t*t+3*t*t-3*t+1)/6;//计算F0,3(t)
			F13=(3*t*t*t-6*t*t+4)/6;//计算F1,3(t)
			F23=(-3*t*t*t+3*t*t+3*t+1)/6;//计算F2,3(t)
			F33=t*t*t/6;//计算B3,3(t)
			q.x=Round(P[0].x*F03+P[1].x*F13+P[2].x*F23+P[3].x*F33);
			q.y=Round(P[0].y*F03+P[1].y*F13+P[2].y*F23+P[3].y*F33);
			pDC->LineTo(q);
		}

	pDC->SelectObject(pOldPen);
	NewPen.DeleteObject();	

}