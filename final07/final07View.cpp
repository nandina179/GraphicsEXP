// final07View.cpp : implementation of the CFinal07View class
//

#include "stdafx.h"
#include "final07.h"

#include "final07Doc.h"
#include "final07View.h"
#include "math.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CFinal07View

IMPLEMENT_DYNCREATE(CFinal07View, CView)

BEGIN_MESSAGE_MAP(CFinal07View, CView)
	//{{AFX_MSG_MAP(CFinal07View)
	ON_WM_LBUTTONDBLCLK()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_WM_KEYDOWN()
	ON_COMMAND(one, Onone)
	ON_COMMAND(two, Ontwo)
	ON_COMMAND(three, Onthree)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CFinal07View construction/destruction

CFinal07View::CFinal07View()
{
	// TODO: add construction code here

}

CFinal07View::~CFinal07View()
{
}

BOOL CFinal07View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CFinal07View drawing

void CFinal07View::OnDraw(CDC* pDC)
{
	CFinal07Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CFinal07View printing

BOOL CFinal07View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CFinal07View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CFinal07View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CFinal07View diagnostics

#ifdef _DEBUG
void CFinal07View::AssertValid() const
{
	CView::AssertValid();
}

void CFinal07View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CFinal07Doc* CFinal07View::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CFinal07Doc)));
	return (CFinal07Doc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CFinal07View message handlers

void CFinal07View::ClearScreen()
{

	CClientDC dc(this);
	CRect window;
	GetClientRect(window);
	dc.SelectStockObject(WHITE_PEN);
	dc.SelectStockObject(WHITE_BRUSH);
	dc.Rectangle(window);
}

void CFinal07View::OnLButtonDblClk(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	switch (TypeEXP)
	{
	case 7:	
	{
		if (boolLButtonDown)
		{
			pointList.Add(point);
			pointList.Add(point);
			ReleaseCapture();
			boolLButtonDown = false;
			boolRButtonDown = false;
			Draw3ColorBSpline();
		}

	}
	break;
	default:
		break;
	}
	CView::OnLButtonDblClk(nFlags, point);
}

void CFinal07View::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	switch (typeEXP7)
	{
	case 1:
	{
		this->SetCapture();	
		startPoint = point;
		endPoint = point;
		boolLButtonDown = true;
		
		pointList.Add(point);
		if(pointList.GetSize()<2){
			pointList.Add(point);
			pointList.Add(point);
		}

	}
	break;
	default:
		break;
	}
	CView::OnLButtonDown(nFlags, point);
}

void CFinal07View::OnLButtonUp(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	//ReleaseCapture();//ÊÍ·ÅÊó±ê
//	MapObj* obj = new MapObj();

	//boolLButtonDown = false;
	CView::OnLButtonUp(nFlags, point);
}

void CFinal07View::OnMouseMove(UINT nFlags, CPoint point) 
{
	if (boolLButtonDown || boolRButtonDown){
	// TODO: Add your message handler code here and/or call default
	CDC* pDC = this->GetDC();
	pDC->SetROP2(R2_NOT);

	pDC->MoveTo(startPoint);
	pDC->LineTo(endPoint);
	pDC->MoveTo(startPoint);
	pDC->LineTo(point);
	endPoint = point;
	}
	CView::OnMouseMove(nFlags, point);
}

void CFinal07View::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	// TODO: Add your message handler code here and/or call default
		ClearScreen();
		if (nChar == 'Q') {
			typeEXP7 = 1;
			pointList.RemoveAll();
			pointPrintList.RemoveAll();
		}
		if (nChar == 'W') {
			typeEXP7 = 2;
			pointPrintList.RemoveAll();
			Draw3ColorBSpline();
			CPoint tempP = pointList.GetAt(0);
			int xcenter = tempP.x;
			for (int i = 1; i < pointList.GetSize(); i++)
			{
				tempP = pointList.GetAt(i);
				tempP.x = xcenter * 2 - tempP.x;
				pointList.SetAt(i, tempP);
			}
			pointPrintList.RemoveAll();
			Draw3ColorBSpline();
		}
		if (nChar == 'E') {
			typeEXP7 = 3;
			double L = 0.5;
			double Alpha = 45;
			Alpha *= 3.1415926 / 180;
			double c = cos(Alpha);
			double s = sin(Alpha);
			mPM[0][0] = 1;
			mPM[0][1] = 0;
			mPM[0][2] = L * c;
			mPM[0][3] = 0;
			mPM[1][0] = 0;
			mPM[1][1] = 1;
			mPM[1][2] = L * s;
			mPM[1][3] = 0;
			mPM[2][0] = 0;
			mPM[2][1] = 0;
			mPM[2][2] = 0;
			mPM[2][3] = 0;
			mPM[3][0] = 0;
			mPM[3][1] = 0;
			mPM[3][2] = 0;
			mPM[3][3] = 1;
	
			Point3D *curve = new Point3D[pointPrintList.GetSize()];
			CPoint tempP = pointList.GetAt(0);
			CClientDC pDC(this);
			CPen *oldpen;
			COLORREF color[3] = { RGB(255,0,0), RGB(0,255,0), RGB(0,0,255) };
			int xcenter = tempP.x;
			for (int i = 0; i < 36; i++)
			{
				
				Alpha = i * 10 * 3.1415926 / 180;
				for (int j = 0; j < pointPrintList.GetSize(); j++)
				{
					tempP = pointPrintList.GetAt(j);
					curve[j].x = (tempP.x - xcenter) * cos(Alpha) + xcenter;
					curve[j].y = tempP.y;
					curve[j].z = (tempP.x - xcenter) * sin(Alpha);
				}
				
				From3DTo2D(curve, pointPrintList.GetSize());
			
				pDC.MoveTo(pointPrint3DList.GetAt(0));
				for (j = 1; j < pointPrint3DList.GetSize(); j++)
				{
					CPen pen;
					pen.CreatePen(PS_SOLID, 2, color[j / (nPoints + 1) % 3]);
					oldpen = pDC.SelectObject(&pen);
					pDC.LineTo(pointPrint3DList.GetAt(j));
					pDC.SelectObject(oldpen);
				}
			}
		}
	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}

void CFinal07View::Draw3ColorBSpline()
{
	CClientDC pDC(this);
	CPen *oldpen;
	COLORREF color[3] = { RGB(255,0,0), RGB(0,255,0), RGB(0,0,255) };
	BSplineToPoints();
	pDC.MoveTo(pointPrintList.GetAt(0));

	for (int i = 1; i < pointPrintList.GetSize(); i++)
	{
		CPen pen;
		pen.CreatePen(PS_SOLID, 3, color[i / (nPoints + 1) % 3]);
		oldpen = pDC.SelectObject(&pen);
		pDC.LineTo(pointPrintList.GetAt(i));
		pDC.SelectObject(oldpen);
	}
}

void CFinal07View::From3DTo2D(Point3D *c, int n)
{
	double r;
	CPoint tempP;
	pointPrint3DList.RemoveAll();
	for (int i = 0; i < n; i++)
	{
		r = c[i].x * mPM[3][0] + c[i].y * mPM[3][1] + c[i].z * mPM[3][2] + mPM[3][3];
		tempP.x = long((c[i].x * mPM[0][0] + c[i].y * mPM[0][1] + c[i].z * mPM[0][2] + mPM[0][4]) / r);
		tempP.y = long((c[i].x * mPM[1][0] + c[i].y * mPM[1][1] + c[i].z * mPM[1][2] + mPM[1][4]) / r);
		pointPrint3DList.Add(tempP);
	}
}

void CFinal07View::BSplineToPoints()
{
	double *knots = new double[N + K + 1];
	//double *knots = new double[N + K + 1];
	double u;
	double delt;
	for (int j = 0; j < pointList.GetSize() - N; j++)
	{
		for (int i = 0; i < N + K + 1; i++)
		{
			knots[i] = i;
		}
		u = knots[K - 1];
		delt = (knots[N + 1] - knots[K - 1]) / (double)(nPoints);
		for (i = 1; i < nPoints; i++)
		{
			pointPrintList.Add(BSpline(knots, N + K + 5, u, j));
			u += delt;
		}
	}
}

CPoint CFinal07View::BSpline(double knot[], int num, double u, int t)
{
	CPoint ret = CPoint(0, 0);
	double temp;
	for (int i = 0; i < N + 1; i++)
	{
		temp = Base(i, K, knot, num, u);
		
		ret.x += long(pointList.GetAt(i + t).x * temp);
		ret.y += long(pointList.GetAt(i + t).y * temp);
	}
	return ret;
}

double CFinal07View::Base(int i, int k, double knot[], int num, double u)
{
	double temp1 = 0;
	double temp2 = 0;
	if (k == 1)
	{
		if (i == (num - 2))
		{
			if ((u >= knot[i]) && (u <= knot[i + 1])) return 1;
			else return 0;
		}
		else
		{
			if ((u >= knot[i]) && (u < knot[i + 1])) return 1;
			else return 0;
		}
	}
	else if (k > 1)
	{
		if (knot[i + k - 1] != knot[i])
		{
			temp1 = Base(i, k - 1, knot, num, u);
			temp1 = (u - knot[i])*temp1 / (knot[i + k - 1] - knot[i]);
		}
		if (knot[i + k] != knot[i + 1])
		{
			temp2 = Base(i + 1, k - 1, knot, num, u);
			temp2 = (knot[i + k] - u) * temp2 / (knot[i + k] - knot[i + 1]);
		}
		return temp1 + temp2;
	}
	return 0;
}

void CFinal07View::Onone() 
{
	// TODO: Add your command handler code here
	TypeEXP = 7;
	ClearScreen();

	typeEXP7 = 1;
	N = 3;
	K = 4;
	nPoints = 30;
	pointList.RemoveAll();
	pointPrintList.RemoveAll();
}

void CFinal07View::Ontwo() 
{
	// TODO: Add your command handler code here
	typeEXP7 = 2;
	pointPrintList.RemoveAll();
	Draw3ColorBSpline();
	CPoint tempP = pointList.GetAt(0);
	int xcenter = tempP.x;
	for (int i = 1; i < pointList.GetSize(); i++)
	{
		tempP = pointList.GetAt(i);
		tempP.x = xcenter * 2 - tempP.x;
		pointList.SetAt(i, tempP);
	}
	pointPrintList.RemoveAll();
	Draw3ColorBSpline();
}

void CFinal07View::Onthree() 
{
	// TODO: Add your command handler code here
	typeEXP7 = 3;
			
			double L = 0.5;
			double Alpha = 45;
			Alpha *= 3.1415926 / 180;
			double c = cos(Alpha);
			double s = sin(Alpha);
			mPM[0][0] = 1;
			mPM[0][1] = 0;
			mPM[0][2] = L * c;
			mPM[0][3] = 0;
			mPM[1][0] = 0;
			mPM[1][1] = 1;
			mPM[1][2] = L * s;
			mPM[1][3] = 0;
			mPM[2][0] = 0;
			mPM[2][1] = 0;
			mPM[2][2] = 0;
			mPM[2][3] = 0;
			mPM[3][0] = 0;
			mPM[3][1] = 0;
			mPM[3][2] = 0;
			mPM[3][3] = 1;
		
			Point3D *curve = new Point3D[pointPrintList.GetSize()];
			CPoint tempP = pointList.GetAt(0);
			CClientDC pDC(this);
			CPen *oldpen;
			COLORREF color[3] = { RGB(255,0,0), RGB(0,255,0), RGB(0,0,255) };
			int xcenter = tempP.x;
			for (int i = 0; i < 36; i++)
			{
				
				Alpha = i * 10 * 3.1415926 / 180;
				for (int j = 0; j < pointPrintList.GetSize(); j++)
				{
					tempP = pointPrintList.GetAt(j);
					curve[j].x = (tempP.x - xcenter) * cos(Alpha) + xcenter;
					curve[j].y = tempP.y;
					curve[j].z = (tempP.x - xcenter) * sin(Alpha);
				}
				
				From3DTo2D(curve, pointPrintList.GetSize());
			
				pDC.MoveTo(pointPrint3DList.GetAt(0));
				for (j = 1; j < pointPrint3DList.GetSize(); j++)
				{
					CPen pen;
					pen.CreatePen(PS_SOLID, 2, color[j / (nPoints + 1) % 3]);
					oldpen = pDC.SelectObject(&pen);
					pDC.LineTo(pointPrint3DList.GetAt(j));
					pDC.SelectObject(oldpen);
				}
			}
		}

