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
	ON_COMMAND(ID_Hermite, OnH)
	ON_COMMAND(Exp54, OnExp54)
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
	if(type==1){
	if(0!=CtrlPointNum)
      DrawHermite(); 
	}

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

void CDemo5View::OnH() 
{
	// TODO: Add your command handler code here
	bFlag=true;
	RedrawWindow();
	type=1;
	CtrlPointNum=0;	
}

void CDemo5View::DrawHermite()
{
	CDC *pDC=GetDC();
	CPen NewPen,*pOldPen;
	NewPen.CreatePen(PS_SOLID,1,RGB(0,0,255));//曲线颜色为蓝色
	pOldPen=pDC->SelectObject(&NewPen);	

	int a[4][4]={{2,-2,1,1},{-3,3,-2,-1},{0,0,1,0},{1,0,0,0}};
	double b[4][2]={{P[0].x,P[0].y},{P[2].x,P[2].y},{P[1].x-P[0].x,P[1].y-P[0].y},{P[3].x-P[2].x,P[3].y-P[2].y}};
	CPoint pt;
	

	MultiMatrix(a,b);
	pt.x=P[0].x;
	pt.y=P[0].y;
	pDC->MoveTo(pt);
	for(double i=0;i<=1;i+=0.01){
		pt.x=Round(i*i*i*result[0][0]+i*i*result[1][0]+i*result[2][0]+result[3][0]);
		pt.y=Round(i*i*i*result[0][1]+i*i*result[1][1]+i*result[2][1]+result[3][1]);
		pDC->LineTo(pt);
		
}
	
}

void CDemo5View::MultiMatrix(int a[][4], double b[][2])
{
	
	int i,j,k;
	for(i=0;i<4;i++)
		for(j=0;j<2;j++)
			result[i][j]=0;

	for(i=0;i<2;i++)
		for(j=0;j<4;j++)
			for(k=0;k<4;k++)
				result[j][i]+=a[j][k]*b[k][i];

}

void CDemo5View::OnExp54() 
{
	// TODO: Add your command handler code here
	type = 5;
	ClearScreen();

	typeEXP5 = 1;
	N = 3;
	K = 4;
	nPoints = 30;
	typeEXP5 = 4;
	ControlPoint = new Point3D[(N + 1)*(N + 1)];	

	CDialogEXP5 mdialog;
	if (mdialog.DoModal() == IDOK)
	{
		ControlPoint[0] = Point3D(mdialog.x0, mdialog.y0, mdialog.z0);
		ControlPoint[1] = Point3D(mdialog.x1, mdialog.y1, mdialog.z1);
		ControlPoint[2] = Point3D(mdialog.x2, mdialog.y2, mdialog.z2);
		ControlPoint[3] = Point3D(mdialog.x3, mdialog.y3, mdialog.z3);
		ControlPoint[4] = Point3D(mdialog.x4, mdialog.y4, mdialog.z4);
		ControlPoint[5] = Point3D(mdialog.x5, mdialog.y5, mdialog.z5);
		ControlPoint[6] = Point3D(mdialog.x6, mdialog.y6, mdialog.z6);
		ControlPoint[7] = Point3D(mdialog.x7, mdialog.y7, mdialog.z7);
		ControlPoint[8] = Point3D(mdialog.x8, mdialog.y8, mdialog.z8);
		ControlPoint[9] = Point3D(mdialog.x9, mdialog.y9, mdialog.z9);
		ControlPoint[10] = Point3D(mdialog.x10, mdialog.y10, mdialog.z10);
		ControlPoint[11] = Point3D(mdialog.x11, mdialog.y11, mdialog.z11);
		ControlPoint[12] = Point3D(mdialog.x12, mdialog.y12, mdialog.z12);
		ControlPoint[13] = Point3D(mdialog.x13, mdialog.y13, mdialog.z13);
		ControlPoint[14] = Point3D(mdialog.x14, mdialog.y14, mdialog.z14);
		ControlPoint[15] = Point3D(mdialog.x15, mdialog.y15, mdialog.z15);
		DrawBezier3D();
	}
	else if (mdialog.DoModal() == IDCANCEL)
	{
		return;
	}
}

void CDemo5View::ClearScreen()
{
	CClientDC dc(this);
	CRect window;
	GetClientRect(window);
	dc.SelectStockObject(WHITE_PEN);
	dc.SelectStockObject(WHITE_BRUSH);
	dc.Rectangle(window);
}
