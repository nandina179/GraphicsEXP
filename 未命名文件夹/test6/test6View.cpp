// test6View.cpp : implementation of the CTest6View class
//

#include "stdafx.h"
#include "test6.h"

#include "test6Doc.h"
#include "test6View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTest6View

IMPLEMENT_DYNCREATE(CTest6View, CView)

BEGIN_MESSAGE_MAP(CTest6View, CView)
	//{{AFX_MSG_MAP(CTest6View)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONDBLCLK()
	ON_COMMAND(ID_START, OnStart)
	ON_COMMAND(ID_END, OnEnd)
	ON_WM_TIMER()
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTest6View construction/destruction

CTest6View::CTest6View()
{
	// TODO: add construction code here
	
	x_step=1;
    y_step=1;
	m_ButtonDown=false;
	PCount=0;

}

CTest6View::~CTest6View()
{
}

BOOL CTest6View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CTest6View drawing

void CTest6View::OnDraw(CDC* pDC)
{
	CTest6Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CTest6View printing

BOOL CTest6View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CTest6View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CTest6View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CTest6View diagnostics

#ifdef _DEBUG
void CTest6View::AssertValid() const
{
	CView::AssertValid();
}

void CTest6View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CTest6Doc* CTest6View::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CTest6Doc)));
	return (CTest6Doc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CTest6View message handlers

void CTest6View::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	this->SetCapture();
	m_ButtonDown=true;
	m_StartPoint=point;
	m_EndPoint=point;
	pointList.Add(point);
	
	CView::OnLButtonDown(nFlags, point);
}

void CTest6View::OnLButtonUp(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	m_ButtonDown=false;
	CView::OnLButtonUp(nFlags, point);
}

void CTest6View::OnMouseMove(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	//CClientDC dc(this);
	if(pointList.GetSize()>0)
	{
	CDC* pDC = this->GetDC();//构造设备环境对象
	pDC->SetROP2(R2_NOT);//设置绘图模式为R2_NOT
	pDC->MoveTo(m_StartPoint);
	pDC->LineTo(m_EndPoint);
	pDC->MoveTo(m_StartPoint);
	pDC->LineTo(point);
	m_EndPoint=point;
	}
	
	CView::OnMouseMove(nFlags, point);
}

void CTest6View::OnLButtonDblClk(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	ReleaseCapture();
	CClientDC dc(this);
	int m=pointList.GetSize();
	PCount=m;
	CPoint p1,p2;
	p1=pointList.GetAt(0);
	p2=pointList.GetAt(m-1);
	dc.MoveTo(p2);
	dc.LineTo(p1);
	for(int i=0;i<m;i++)
	{
		PCon[i]=pointList.GetAt(i);
	}
	pointList.RemoveAll();

	DrawBez2();
	/*CPen pen;
	pen.CreatePen(PS_SOLID,1,RGB(255,0,0));
	CPen *oldpen;
	oldpen=dc.SelectObject(&pen);
	dc.MoveTo(PCon[0]);
	dc.LineTo(PCon[1]);
	dc.LineTo(PCon[3]);*/
	
	CView::OnLButtonDblClk(nFlags, point);
}

void CTest6View::Bez_to_point2(Point P[], Point pts[], int npoints)
{
	double t,delt;
	Point pt;
	delt=1.0/npoints;
	t=0.0;
	int i;
	for(i=0;i<=npoints;i++)
	{
		pts[i]=decas(P,t);
		t+=delt;
	}
	CClientDC dc(this);
	CPen pen;
	pen.CreatePen(PS_SOLID,1,RGB(255,0,0));
	CPen *oldpen;
	oldpen=dc.SelectObject(&pen);
    dc.SelectObject(&pen);
	dc.MoveTo((CPoint)pts[0]);
	for(i=1;i<npoints;i++)
	{
		dc.LineTo((CPoint)pts[i]);
	}
    dc.SelectObject(oldpen);
}
#include"math.h"

Point CTest6View::decas(Point P[], double t)
{
	int m,i;
	Point *R,*Q,P0;
	R=new Point[3];
	Q=new Point[3];
	for(i=0;i<3;i++)
	{
	    R[i]=P[i];
	}
	for(m=2;m>0;m--)
	{
		for(i=0;i<=m-1;i++)
		{
			Q[i]=R[i]+(R[i+1]-R[i])*t;
		}
		for(i=0;i<=m-1;i++)
			R[i]=Q[i];
	}
	P0=R[0];
	delete R;
	delete Q;
	return (P0);
	/*CPoint R[3];
	CPoint Q[3];
	CPoint p0;
	for(i=0;i<3;i++)
	{
		R[i]=P[i];
	}
	for(m=2;m>0;m--)
	{
		for(i=0;i<m-1;i++)
		{
			Q[i].x=R[i].x+t*(R[i+1].x-R[i].x);
			Q[i].y=R[i].y+t*(R[i+1].y-R[i].x);
		}
		for(i=0;i<m-1;i++)
			R[i]=Q[i];
	}
	p0=R[0];
	return p0;*/
}

void CTest6View::DrawBez2()
{
    int i;
	Point T1,T2;
	Point *R;
	R=new Point[3];
	int npoints=1000;
	Point *pts;
	pts=new Point[1000];
	for(i=0;i<PCount;i++)
	{
			T1=PCon[i];
			T2=PCon[(i+1)%PCount];
			R[0]=(T1+T2)/2;
			R[1]=PCon[(i+1)%PCount];
			T1=PCon[(i+1)%PCount];
			T2=PCon[(i+2)%PCount];
			R[2]=(T1+T2)/2;
            Bez_to_point2(R,pts,npoints);
	}
}

void CTest6View::OnStart() 
{
	// TODO: Add your command handler code here
	SetTimer(1,50,NULL);
	int i;
	for(i=0;i<PCount;i++)
	{
	    step[i]=3;
	    //y_step[i]=3;
	}
	
}

void CTest6View::OnEnd() 
{
	// TODO: Add your command handler code here
	KillTimer(1);	
}
void CTest6View::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	int i;
	CClientDC dc(this);
	CRect rect;
	this->GetClientRect(rect);
	for(i=0;i<PCount;i++)
	{
		/*if(i%2==0)
		{
		    if(((PCon[i].y+y_step)>rect.bottom)||((PCon[i].y+y_step)<rect.top))
			{
		    	y_step=-y_step;

			}
	    	PCon[i].y=PCon[i].y+y_step;
		}
		if(i%2==1)
		{
		    if(((PCon[i].x+x_step)>rect.right)||((PCon[i].x+x_step)<rect.left))
			{
			    x_step=-x_step;
			}
		    PCon[i].x=PCon[i].x+x_step;
		}*/
		if(i%2==0)
		{
		    if(((PCon[i].y+step[i]*(i+1))>rect.bottom)||((PCon[i].y+step[i]*(i+1))<rect.top))
			{
		    	step[i]=-step[i];

			}
	    	PCon[i].y=PCon[i].y+step[i]*(i+1);
		}
		if(i%2==1)
		{
		    if(((PCon[i].x+step[i]*(i+1))>rect.right)||((PCon[i].x+step[i]*(i+1))<rect.left))
			{
			    step[i]=-step[i];
			}
		    PCon[i].x=PCon[i].x+step[i]*(i+1);
		}
	}
	ClearScreen();
	/*dc.MoveTo(PCon[0]);
	for(i=1;i<PCount;i++)
	{
		dc.LineTo(PCon[i]);
	}*/
		

	DrawBez2();

	
	CView::OnTimer(nIDEvent);
}

void CTest6View::ClearScreen()
{
    CClientDC dc(this);
	CRect window;
    GetClientRect(window);
	dc.SelectStockObject(WHITE_PEN);
	dc.SelectStockObject(WHITE_BRUSH);
	dc.Rectangle(window);
}
