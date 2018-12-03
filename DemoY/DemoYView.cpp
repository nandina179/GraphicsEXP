// DemoYView.cpp : implementation of the CDemoYView class
//

#include "stdafx.h"
#include "DemoY.h"

#include "DemoYDoc.h"
#include "DemoYView.h"
#include "DialogEXP3.h"
#include "DialogEXP3_2.h"
#include "math.h"
//2
#include "MapObj.h"

//4
#include "SetColor.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDemoYView

IMPLEMENT_DYNCREATE(CDemoYView, CView)

BEGIN_MESSAGE_MAP(CDemoYView, CView)
	//{{AFX_MSG_MAP(CDemoYView)
	ON_COMMAND(ID_LINE, OnLine)
	ON_COMMAND(ID_POLYGON, OnPolygon)
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONUP()
	ON_WM_LBUTTONDBLCLK()
	ON_COMMAND(ID_SETWIDTH, OnSetwidth)
	ON_WM_KEYDOWN()
	ON_COMMAND(ID_CIRCLE, OnCircle)
	ON_COMMAND(ID_TIANCHONG, OnTianchong)
	ON_COMMAND(ID_ELLIPSE, OnEllipse)
	ON_COMMAND(ID_ALLCLEAR, OnAllclear)
	ON_COMMAND(IDP_ISOMETRIC, OnIsometric)
	ON_COMMAND(IDP_CABINET, OnCabinet)
	ON_COMMAND(IDP_PERSPECTIVE, OnPerspective)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDemoYView construction/destruction

CDemoYView::CDemoYView()
{
	// TODO: add construction code here
	//1
	//设置鼠标左键初始没有按下
	m_LButtonDown = false;
	//2+
	//程序初始状态不绘制任何图元
	type = 0;
	//type=6;
	//4+
	r=0;g=0;b=0;
	//exp003
	LBB3D = Point3D(-100, -100, -100);
	LBT3D = Point3D(-100, -100, +100);
	LFB3D = Point3D(-100, +100, -100);
	LFT3D = Point3D(-100, +100, +100);
	RBB3D = Point3D(+100, -100, -100);
	RBT3D = Point3D(+100, -100, +100);
	RFB3D = Point3D(+100, +100, -100);
	RFT3D = Point3D(+100, +100, +100);

	//
	perspectiveProjection = false;
	perspectiveX = 400;
	perspectiveY = 400;
	perspectiveZ = 300;
	shifting = 400;
	mStep = 1.5;
	pStep = 1;
	rStep = 0.05;
	axes = 1;
}

CDemoYView::~CDemoYView()
{
	//3
	for (int i=0;i<objList.GetSize();i++){
		MapObj* obj = (MapObj*)objList.GetAt(i);
		delete obj;
	}
}

BOOL CDemoYView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CDemoYView drawing

void CDemoYView::OnDraw(CDC* pDC)
{
	CDemoYDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
	/*
	//初始绘图演示
	pDC->MoveTo(10,10);
	pDC->LineTo(100,100);
	pDC->LineTo(200,100);
	*/
	/*
	//获得设备环境对象
	pDC->LineTo(100,100);
	CDC* pDC2 = this->GetDC();
	pDC2->LineTo(100,200);
	CClientDC dc(this);
	dc.LineTo(100,300);
	dc.LineTo(300,300);
	*/
	/*
	//画笔画刷使用
	CPen pen;
	CPen* oldpen;
	pen.CreatePen(PS_SOLID, 2,RGB(0,0,255));
	oldpen = pDC->SelectObject(&pen);
	pDC->MoveTo(100,100);
	pDC->LineTo(100,200);
	pDC->SelectObject(oldpen);
	
	CClientDC dc(this);
	CPen pen2;
	pen2.CreatePen(PS_SOLID,8,RGB(255,0,0));
	CBrush brush;
	CBrush* oldbrush;
	brush.CreateSolidBrush(RGB(0,255,0));
	oldpen = dc.SelectObject(&pen2);
	oldbrush=dc.SelectObject(&brush);
	dc.Rectangle(200,200,400,400);
	dc.SelectObject(oldpen);
	dc.SelectObject(oldbrush);
	*/
	/*
	//使用DDALine函数画线
	this->DDALine(pDC,100,100,300,200,RGB(255,0,0));
	*/
	/*
	//3
	for (int i=0;i<objList.GetSize();i++){
		MapObj* obj = (MapObj*)objList.GetAt(i);
		if (obj->type == 1){
			CPoint p1 = obj->points.GetAt(0);
			CPoint p2 = obj->points.GetAt(1);
			DDALine(pDC,p1.x,p1.y,p2.x,p2.y,RGB(0,0,0));
		}
		else if (obj->type == 2){
			CPoint p1 = obj->points.GetAt(0);
			CPoint p2;
			for (int j=1;j<obj->points.GetSize();j++){
				p2 = obj->points.GetAt(j);
				DDALine(pDC,p1.x,p1.y,p2.x,p2.y,RGB(0,0,0));
				p1 = p2;
			}
			p2 = obj->points.GetAt(0);
			DDALine(pDC,p1.x,p1.y,p2.x,p2.y,RGB(0,0,0));
		}
	}
	*/
	
	
	//4
	for (int i=0;i<objList.GetSize();i++){
		MapObj* obj = (MapObj*)objList.GetAt(i);
		if (obj->type == 1){
			CPoint p1 = obj->points.GetAt(0);
			CPoint p2 = obj->points.GetAt(1);
			DDALine(pDC,p1.x,p1.y,p2.x,p2.y,RGB(r,g,b));
		}
		else if (obj->type == 2){
			CPoint p1 = obj->points.GetAt(0);
			CPoint p2;
			for (int j=1;j<obj->points.GetSize();j++){
				p2 = obj->points.GetAt(j);
				DDALine(pDC,p1.x,p1.y,p2.x,p2.y,RGB(r,g,b));
				p1 = p2;
			}
			p2 = obj->points.GetAt(0);
			DDALine(pDC,p1.x,p1.y,p2.x,p2.y,RGB(r,g,b));
		}
	}
}

/////////////////////////////////////////////////////////////////////////////
// CDemoYView printing

BOOL CDemoYView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CDemoYView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CDemoYView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CDemoYView diagnostics

#ifdef _DEBUG
void CDemoYView::AssertValid() const
{
	CView::AssertValid();
}

void CDemoYView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CDemoYDoc* CDemoYView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDemoYDoc)));
	return (CDemoYDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CDemoYView message handlers
void CDemoYView::OnAllclear() 
{
	// TODO: Add your command handler code here
	type = 0;
	ClearScreen();
}
void CDemoYView::OnLine() 
{
	// TODO: Add your command handler code here
	//2
	type = 1;
	
}

void CDemoYView::OnPolygon() 
{
	// TODO: Add your command handler code here
	//2
	type = 2;
}

void CDemoYView::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	/*
	//1
	this->SetCapture();//捕捉鼠标
	//设置开始点和终止点，此时为同一点
	m_StartPoint = point;
	m_EndPoint = point;
	m_LButtonDown = true;//设置鼠标左键按下
	*/

	//2
	if (type ==1 || type == 2||type==3||type==4||type==5||type==6){
		this->SetCapture();//捕捉鼠标
		//设置开始点和终止点，此时为同一点
		m_StartPoint = point;
		m_EndPoint = point;
		m_LButtonDown = true;//设置鼠标左键按下
		pointList.Add(point);
		//ClearScreen();
	}
//	else if(type ==0 ){
		/*
		this->SetCapture();//捕捉鼠标
		//设置开始点和终止点，此时为同一点
		m_StartPoint = point;
		m_EndPoint = point;
		m_LButtonDown = true;//设置鼠标左键按下
		pointList.Add(point);
		*/
		//ClearScreen();
//	}
	
	CView::OnLButtonDown(nFlags, point);
}

void CDemoYView::OnMouseMove(UINT nFlags, CPoint point) 
{
	
	if ((m_LButtonDown && type == 1) || (type == 2 && pointList.GetSize() != 0)){
		CDC* pDC = this->GetDC();//构造设备环境对象
		pDC->SetROP2(R2_NOT);//设置绘图模式为R2_NOT
		//重新绘制前一个鼠标移动消息处理函数绘制的直线段
		//因为绘图模式的原因，结果就是擦除了该线段
		DDALine(pDC,m_StartPoint.x,m_StartPoint.y,m_EndPoint.x,m_EndPoint.y,RGB(0,0,0));
		//绘制新的直线段
		DDALine(pDC,m_StartPoint.x,m_StartPoint.y,point.x,point.y,RGB(0,0,0));
		//保存新的直线段终点
		m_EndPoint = point;
	}
	else if(type==3&&m_LButtonDown){
		CDC*pDC=this->GetDC();
		pDC->SetROP2(R2_NOT);
        Circle(pDC,m_StartPoint.x,m_StartPoint.y,m_EndPoint.x,m_EndPoint.y);
        Circle(pDC,m_StartPoint.x,m_StartPoint.y,point.x,point.y);
		m_EndPoint = point;
	}
	else if(type==4&&m_LButtonDown){
		CDC*pDC=this->GetDC();
		pDC->SetROP2(R2_NOT);
        Ellipse(pDC,m_StartPoint.x,m_StartPoint.y,m_EndPoint.x,m_EndPoint.y);
        Ellipse(pDC,m_StartPoint.x,m_StartPoint.y,point.x,point.y);
			m_EndPoint = point;
	}
	else if(type==5&&pointList.GetSize() != 0){
		CDC* pDC = this->GetDC();//构造设备环境对象
		pDC->SetROP2(R2_NOT);//设置绘图模式为R2_NOT
		//重新绘制前一个鼠标移动消息处理函数绘制的直线段
		//因为绘图模式的原因，结果就是擦除了该线段
		DDALine(pDC,m_StartPoint.x,m_StartPoint.y,m_EndPoint.x,m_EndPoint.y,RGB(0,0,0));
		//绘制新的直线段
		DDALine(pDC,m_StartPoint.x,m_StartPoint.y,point.x,point.y,RGB(0,0,0));
		//保存新的直线段终点
		m_EndPoint = point;
	}
	else if (type==6)
	{
		CDC*pDC=this->GetDC();
		//pDC->SetROP2(R2_NOT);
		//Isometric();
		//ClearScreen();
	}
	else if (type==7)
	{
		CDC*pDC=this->GetDC();
		//pDC->SetROP2(R2_NOT);
		//Isometric();
		//ClearScreen();
	}
	else if (type==8)
	{
		CDC*pDC=this->GetDC();
		//pDC->SetROP2(R2_NOT);
		//Isometric();
		//ClearScreen();
	}
	else if (type==0&&m_LButtonDown)
	{
			CDC*pDC=this->GetDC();
		pDC->SetROP2(R2_NOT);
		ClearScreen();
	}
	CView::OnMouseMove(nFlags, point);
}

void CDemoYView::OnLButtonUp(UINT nFlags, CPoint point) 
{
	//4
	if (type == 1){
		ReleaseCapture();//释放鼠标
		MapObj* obj = new MapObj();
		obj->type = 1;
		obj->points.Add(m_StartPoint);
		obj->points.Add(m_EndPoint);
		objList.Add(obj);
		pointList.RemoveAll();
		CDC* dc = this->GetDC();
		DDALine(dc,m_StartPoint.x,m_StartPoint.y,m_EndPoint.x,m_EndPoint.y,RGB(r,g,b));
	}
	else if(type==3||type==4||type==0||type==6||type==7||type==8)
	{
		ReleaseCapture();//释放鼠标
		MapObj* obj = new MapObj();
	}
	m_LButtonDown = false;
	
	CView::OnLButtonUp(nFlags, point);
}

void CDemoYView::OnLButtonDblClk(UINT nFlags, CPoint point) 
{
	
	
	//4
	if (type == 2){
		ReleaseCapture();//释放鼠标
		MapObj* obj = new MapObj();
		obj->type = 2;
		for (int i=0;i<pointList.GetSize();i++)
			obj->points.Add(pointList.GetAt(i));
		objList.Add(obj);
		pointList.RemoveAll();
		CDC* pDC = this->GetDC();
		CPoint p1 = obj->points.GetAt(0);
		CPoint p2;
		for (int j=1;j<obj->points.GetSize();j++){
			p2 = obj->points.GetAt(j);
			DDALine(pDC,p1.x,p1.y,p2.x,p2.y,RGB(r,g,b));
			p1 = p2;
		}
		p2 = obj->points.GetAt(0);
		DDALine(pDC,p1.x,p1.y,p2.x,p2.y,RGB(r,g,b));
	}
	else if(type==5)	
	{
		if (!m_LButtonDown && pointList.GetSize()>0)
		{//
	ReleaseCapture();//释放鼠标
		MapObj* obj = new MapObj();
		obj->type = 5;
		for (int i1=0;i1<pointList.GetSize();i1++)
			obj->points.Add(pointList.GetAt(i1));
		objList.Add(obj);
	//	pointList.RemoveAll();
		CDC* pDC = this->GetDC();
		CPoint px = obj->points.GetAt(0);
		CPoint py;
		for (int j=1;j<obj->points.GetSize();j++){
			py = obj->points.GetAt(j);
			DDALine(pDC,px.x,px.y,py.x,py.y,RGB(r,g,b));
			px = py;
		}
		py = obj->points.GetAt(0);
		DDALine(pDC,px.x,px.y,py.x,py.y,RGB(r,g,b));
			//
		//	CDC* pDC = this->GetDC();
			CPoint p1,p2,p3;
			//取矩阵最小扫描界
			int maxX, minX, maxY, minY;
			p1 = pointList.GetAt(0);
			maxX = p1.x;
			minX = p1.x;
			maxY = p1.y;
			minY = p1.y;
			for (int i = 1; i < pointList.GetSize(); i++) {
				p1 = pointList.GetAt(i);
				if (p1.x > maxX) maxX = p1.x;
				if (p1.x < minX) minX = p1.x;
				if (p1.y > maxY) maxY = p1.y;
				if (p1.y < minY) minY = p1.y;
			}
			//改变极值点
			p1 = pointList.GetAt(pointList.GetSize()-1);
			p2 = pointList.GetAt(0);
			p3 = pointList.GetAt(1);
			if ((p1.y - p2.y)*(p2.y - p3.y) < 0)
			{
				pDC->SetPixel(p2.x, p2.y, RGB(255, 255, 255));
			}
			for (int ii = 1; ii < pointList.GetSize(); ii++) {
				p1 = pointList.GetAt(ii-1);
				p2 = pointList.GetAt(ii);
				if (ii != pointList.GetSize()-1)
				{
					p3 = pointList.GetAt(ii+1);
				}
				else 
				{
					p3 = pointList.GetAt(0);
				}
				if ((p1.y-p2.y)*(p2.y-p3.y)<0)
				{
					pDC->SetPixel(p2.x, p2.y, RGB(255, 255, 255));
				}
			}
			//填充
			bool inside = false;	//是否在多边形中
			bool flag = true;		//是否需要改变
			bool bder = false;		//是否为边界值
			for (int y = minY-1; y < maxY+1; y++)
			{
				inside = false;
				flag = false;
				for (int x = minX-1; x < maxX+1; x++)
				{
					bder = (pDC->GetPixel(x, y) == RGB(0, 0, 0));
					if (bder && flag)
					{
						inside = !inside;
						flag = false;
					}
					else if (!bder && !flag)
					{
						flag = true;
					}
					if (inside && !bder) PatternFill(pDC,x,y);
				}
			}
			pointList.RemoveAll();
			ReleaseCapture();//释放鼠标
		}
	
	}
	
	else if(type==6||type==7||type==8)
	{
		CDialogEXP3 mdialog;
		if (mdialog.DoModal() == IDOK)
		{
			axes = mdialog.isXYZ;
		}
		else if (mdialog.DoModal() == IDCANCEL)
		{
			return;
		}
	}
	CView::OnLButtonDblClk(nFlags, point);
}

void CDemoYView::OnSetwidth() 
{
	// TODO: Add your command handler code here
	//4
	SetColor s;
	s.m_r = r;s.m_g = g;s.m_b = b;
	if (s.DoModal() == IDOK){
		r = s.m_r;g = s.m_g;b = s.m_b;
		this->Invalidate(true);
	}
}

void CDemoYView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	if(type==6||type==7||type==8)
	{
		ClearScreen();
		if(nChar == 'Q')
		{
			CDialogEXP3_2 mdialog;
			INT_PTR nResponse = mdialog.DoModal();
			if (nResponse == IDOK)
			{
				perspectiveX = mdialog.mX;
				perspectiveY = mdialog.mY;
				perspectiveZ = mdialog.mZ;

				mPM[0][0] = 1;
				mPM[0][1] = 0;
				mPM[0][2] = perspectiveX / (-perspectiveZ);
				mPM[0][3] = 0;
				mPM[1][0] = 0;
				mPM[1][1] = 1;
				mPM[1][2] = perspectiveY / (-perspectiveZ);
				mPM[1][3] = 0;
				mPM[2][0] = 0;
				mPM[2][1] = 0;
				mPM[2][2] = 0;
				mPM[2][3] = 0;
				mPM[3][0] = 0;
				mPM[3][1] = 0;
				mPM[3][2] = 1 / (-perspectiveZ);
				mPM[3][3] = 1;
			}
			else if (nResponse == IDCANCEL)
			{
				return;
			}
		}
		if (nChar == VK_LEFT) {
			LBB3D.x -= mStep;
			LBT3D.x -= mStep;
			LFB3D.x -= mStep;
			LFT3D.x -= mStep;
			RBB3D.x -= mStep;
			RBT3D.x -= mStep;
			RFB3D.x -= mStep;
			RFT3D.x -= mStep;
		}
		if (nChar == VK_RIGHT) {
			LBB3D.x += mStep;
			LBT3D.x += mStep;
			LFB3D.x += mStep;
			LFT3D.x += mStep;
			RBB3D.x += mStep;
			RBT3D.x += mStep;
			RFB3D.x += mStep;
			RFT3D.x += mStep;
		}
		if (nChar == VK_UP) {
			LBB3D.y -= mStep;
			LBT3D.y -= mStep;
			LFB3D.y -= mStep;
			LFT3D.y -= mStep;
			RBB3D.y -= mStep;
			RBT3D.y -= mStep;
			RFB3D.y -= mStep;
			RFT3D.y -= mStep;
		}
		if (nChar == VK_DOWN) {
			LBB3D.y += mStep;
			LBT3D.y += mStep;
			LFB3D.y += mStep;
			LFT3D.y += mStep;
			RBB3D.y += mStep;
			RBT3D.y += mStep;
			RFB3D.y += mStep;
			RFT3D.y += mStep;
		}
		if (nChar == VK_SHIFT) {
			LBB3D.z += mStep;
			LBT3D.z += mStep;
			LFB3D.z += mStep;
			LFT3D.z += mStep;
			RBB3D.z += mStep;
			RBT3D.z += mStep;
			RFB3D.z += mStep;
			RFT3D.z += mStep;
		}
		if (nChar == VK_CONTROL) {
			LBB3D.z -= mStep;
			LBT3D.z -= mStep;
			LFB3D.z -= mStep;
			LFT3D.z -= mStep;
			RBB3D.z -= mStep;
			RBT3D.z -= mStep;
			RFB3D.z -= mStep;
			RFT3D.z -= mStep;
		}
		if (nChar == 'W') {
			double scale = 1.1;
			scale *= pStep;
			ProportionChange(scale);
		}		
		if (nChar == 'S') {
			double scale = 0.9;
			scale *= pStep;
			ProportionChange(scale);
		}
		if (nChar == 'A') {
			RotateChange(-rStep);
		}
		if (nChar == 'D') {
			RotateChange(rStep);
		}
		From3dTo2d();
		DrawCubic();
	}
	// TODO: Add your message handler code here and/or call default
	//5
	/*
	if (nChar == VK_LEFT){
		for (int i=0;i<objList.GetSize();i++){
			MapObj* obj = (MapObj*)objList.GetAt(i);
			for (int j=0;j<obj->points.GetSize();j++){
				CPoint p = (CPoint)obj->points.GetAt(j);
				this->Move(&p,-1,0);
				obj->points.SetAt(j,p);
			}
		}
		this->Invalidate(true);
	}
	if (nChar == VK_RIGHT){
		for (int i=0;i<objList.GetSize();i++){
			MapObj* obj = (MapObj*)objList.GetAt(i);
			for (int j=0;j<obj->points.GetSize();j++){
				CPoint p = (CPoint)obj->points.GetAt(j);
				this->Move(&p,1,0);
				obj->points.SetAt(j,p);
			}
		}
		this->Invalidate(true);
	}
	if (nChar == VK_UP){
		for (int i=0;i<objList.GetSize();i++){
			MapObj* obj = (MapObj*)objList.GetAt(i);
			for (int j=0;j<obj->points.GetSize();j++){
				CPoint p = (CPoint)obj->points.GetAt(j);
				this->Move(&p,0,-1);
				obj->points.SetAt(j,p);
			}
		}
		this->Invalidate(true);
	}
	if (nChar == VK_DOWN){
		for (int i=0;i<objList.GetSize();i++){
			MapObj* obj = (MapObj*)objList.GetAt(i);
			for (int j=0;j<obj->points.GetSize();j++){
				CPoint p = (CPoint)obj->points.GetAt(j);
				this->Move(&p,0,1);
				obj->points.SetAt(j,p);
			}
		}
		this->Invalidate(true);
	}
	*/
	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}

//5
void CDemoYView::Move(CPoint* point, int x, int y)
{
	point->x = point->x + x;
	point->y = point->y + y;
}

void CDemoYView::DDALine(CDC *pDC, int x1, int y1, int x2, int y2, COLORREF color)
{
	double dx,dy,e,x,y;
	dx = x2 -x1;
	dy = y2- y1;
	e = (fabs(dx) > fabs(dy)) ? fabs(dx):fabs(dy);
	dx/=e;
	dy/=e;
	x = x1;
	y = y1;
	for (int i=1;i<=e;i++)
	{
		pDC->SetPixel((int)(x+0.5),(int)(y+0.5),color);
		x+=dx;
		y+=dy;
	}
}


void CDemoYView::OnCircle() 
{
	// TODO: Add your command handler code here
	type=3;
}

void CDemoYView::OnTianchong() 
{
	// TODO: Add your command handler code here
	type=5;
}

void CDemoYView::OnEllipse() 
{
	// TODO: Add your command handler code here
	type=4;
}

void CDemoYView::Circle(CDC *pDC, int x1, int y1, int x2, int y2)
{
int R;
	int xmid=x1;
	int ymid=y1;
	//int xmid=(x1+x2)/2;
	//int ymid=(y1+y2)/2;
	COLORREF color=RGB(0,0,255);
    R=(int)(sqrtf((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1)));
    int x,y,p;
	x=0;
	y=R;
	p=3-2*R;

	for(;x<=y;x++)
    {
		pDC->SetPixel(xmid+x,ymid+y,color);//1
       pDC->SetPixel(xmid+y,ymid+x,color);//2
       pDC->SetPixel(xmid+y,2*ymid-ymid-x,color);//3
	   pDC->SetPixel(xmid+x,2*ymid-ymid-y,color);//4
	   pDC->SetPixel(2*xmid-xmid-x,2*ymid-ymid-y,color);//5
	   pDC->SetPixel(2*xmid-xmid-y,2*ymid-ymid-x,color);//6
	   pDC->SetPixel(2*xmid-xmid-y,ymid+x,color);//7
	   pDC->SetPixel(2*xmid-xmid-x,ymid+y,color);
		if(p>=0)
		{
			p+=4*(x-y)+10;
			y--;
		}
		else
		{
			p+=4*x+6;
		}
	}

}

void CDemoYView::Ellipse(CDC *pDC, int x1, int y1, int x2, int y2)
{
	int xmid=(x2+x1)/2;
	int ymid=(y2+y1)/2;
	int x,y;
	COLORREF color=RGB(0,0,255);
	double d1,d2;
	int a=(int)(sqrtf((x2-x1)*(x2-x1))/2);
	int b=(int)(sqrtf((y2-y1)*(y2-y1))/2);
	x=0;y=b;
	d1=b*b+a*a*(-b+0.25);

	pDC->SetPixel(x,y,color);
	while(b*b*(x+1)<a*a*(y-0.5))
	{
		if(d1<0)
		{
			d1+=b*b*(2*x+3);
			x++;
		}
		else
		{
			d1+=(b*b*(2*x+3)+a*a*(-2*y+2));
			x++;
			y--;
		}
		pDC->SetPixel(xmid+x,ymid+y,color);//1
		pDC->SetPixel(xmid+x,2*ymid-ymid-y,color);//4
		 pDC->SetPixel(2*xmid-xmid-x,2*ymid-ymid-y,color);//5
		 pDC->SetPixel(2*xmid-xmid-x,ymid+y,color);//8
	}

	d2=sqrt(b*(x+0.5))+sqrt(a*(y-1))-sqrt(a*b);
	while(y>0)
	{
		if(d2<0)
		{
			d2+=b*b*(2*x+2)+a*a*(-2*y+3);
			x++;
			y--;
		}
		else
		{
			d2+=a*a*(-2*y+3);
			y--;
		}
		pDC->SetPixel(xmid+x,ymid+y,color);//2
		   pDC->SetPixel(xmid+x,2*ymid-ymid-y,color);//3
		   pDC->SetPixel(2*xmid-xmid-x,2*ymid-ymid-y,color);//6
		   pDC->SetPixel(2*xmid-xmid-x,ymid+y,color);//7
	}
}

void CDemoYView::OnRButtonDblClk(UINT nFlags, CPoint point)
{
	if(type==5)	
	{
		if ( pointList.GetSize()>0)
		{
			CDC* pDC = this->GetDC();
			CPoint p1,p2,p3;
			//取矩阵最小扫描界
			int maxX, minX, maxY, minY;
			p1 = pointList.GetAt(0);
			maxX = p1.x;
			minX = p1.x;
			maxY = p1.y;
			minY = p1.y;
			for (int i = 1; i < pointList.GetSize(); i++) {
				p1 = pointList.GetAt(i);
				if (p1.x > maxX) maxX = p1.x;
				if (p1.x < minX) minX = p1.x;
				if (p1.y > maxY) maxY = p1.y;
				if (p1.y < minY) minY = p1.y;
			}
			//改变极值点
			p1 = pointList.GetAt(pointList.GetSize()-1);
			p2 = pointList.GetAt(0);
			p3 = pointList.GetAt(1);
			if ((p1.y - p2.y)*(p2.y - p3.y) < 0)
			{
				pDC->SetPixel(p2.x, p2.y, RGB(255, 255, 255));
			}
			for (int ii = 1; ii < pointList.GetSize(); ii++) {
				p1 = pointList.GetAt(ii-1);
				p2 = pointList.GetAt(ii);
				if (ii != pointList.GetSize()-1)
				{
					p3 = pointList.GetAt(ii+1);
				}
				else 
				{
					p3 = pointList.GetAt(0);
				}
				if ((p1.y-p2.y)*(p2.y-p3.y)<0)
				{
					pDC->SetPixel(p2.x, p2.y, RGB(255, 255, 255));
				}
			}
			//填充
			bool inside = false;	//是否在多边形中
			bool flag = true;		//是否需要改变
			bool bder = false;		//是否为边界值
			for (int y = minY-1; y < maxY+1; y++)
			{
				inside = false;
				flag = false;
				for (int x = minX-1; x < maxX+1; x++)
				{
					bder = (pDC->GetPixel(x, y) == RGB(0, 0, 0));
					if (bder && flag)
					{
						inside = !inside;
						flag = false;
					}
					else if (!bder && !flag)
					{
						flag = true;
					}
					if (inside && !bder) PatternFill(pDC,x,y);
				}
			}
			pointList.RemoveAll();
		}
	
	}
	else if(type==6||type==7||type==8)
	{
		CDialogEXP3 mdialog;
		if (mdialog.DoModal() == IDOK)
		{
			axes = mdialog.isXYZ;
		}
		else if (mdialog.DoModal() == IDCANCEL)
		{
			return;
		}
	}
	/*else if(type==8||type==6||type==7)
	{
			CDialogEXP3_2 mdialog;
			INT_PTR nResponse = mdialog.DoModal();
			if (nResponse == IDOK)
			{
				perspectiveX = mdialog.mX;
				perspectiveY = mdialog.mY;
				perspectiveZ = mdialog.mZ;

				mPM[0][0] = 1;
				mPM[0][1] = 0;
				mPM[0][2] = perspectiveX / (-perspectiveZ);
				mPM[0][3] = 0;
				mPM[1][0] = 0;
				mPM[1][1] = 1;
				mPM[1][2] = perspectiveY / (-perspectiveZ);
				mPM[1][3] = 0;
				mPM[2][0] = 0;
				mPM[2][1] = 0;
				mPM[2][2] = 0;
				mPM[2][3] = 0;
				mPM[3][0] = 0;
				mPM[3][1] = 0;
				mPM[3][2] = 1 / (-perspectiveZ);
				mPM[3][3] = 1;
			}
			else if (nResponse == IDCANCEL)
			{
				return;
			}
	}
*/
	
	CView::OnRButtonDblClk(nFlags, point);
}

void CDemoYView::PatternFill(CDC *pDC, int x, int y)
{
	int rec[11][32] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
					0,1,1,1,1,1,1,0,0,1,1,1,1,1,1,0,0,1,1,1,1,1,1,0,0,1,1,1,1,1,1,0,
					0,1,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,1,0,0,0,0,0,0,0,1,0,
					0,1,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,1,0,0,0,0,0,0,0,1,0,
					0,1,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,1,0,0,0,0,0,0,0,1,0,
					0,1,0,0,0,0,1,0,0,1,1,1,1,1,1,0,0,1,0,0,0,0,1,0,0,1,1,1,1,1,1,0,
					0,1,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0,0,1,0,
					0,1,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0,0,1,0,
		            0,1,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0,0,1,0,
					0,1,1,1,1,1,1,0,0,1,1,1,1,1,1,0,0,1,1,1,1,1,1,0,0,1,1,1,1,1,1,0,
					0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };

	int a = x /2% 64;
	int b = y /2% 20;
	if (rec[b/2][a/2] == 1) pDC->SetPixel(x, y, RGB(255, 0, 0));
}

void CDemoYView::FILLANYTHING(UINT nFlags, CPoint point)
{
	if(type==5)	
	{
		if (!m_LButtonDown && pointList.GetSize()>0)
		{
			CDC* pDC = this->GetDC();
			CPoint p1,p2,p3;
			//取矩阵最小扫描界
			int maxX, minX, maxY, minY;
			p1 = pointList.GetAt(0);
			maxX = p1.x;
			minX = p1.x;
			maxY = p1.y;
			minY = p1.y;
			for (int i = 1; i < pointList.GetSize(); i++) {
				p1 = pointList.GetAt(i);
				if (p1.x > maxX) maxX = p1.x;
				if (p1.x < minX) minX = p1.x;
				if (p1.y > maxY) maxY = p1.y;
				if (p1.y < minY) minY = p1.y;
			}
			//改变极值点
			p1 = pointList.GetAt(pointList.GetSize()-1);
			p2 = pointList.GetAt(0);
			p3 = pointList.GetAt(1);
			if ((p1.y - p2.y)*(p2.y - p3.y) < 0)
			{
				pDC->SetPixel(p2.x, p2.y, RGB(255, 255, 255));
			}
			for (int ii = 1; ii < pointList.GetSize(); ii++) {
				p1 = pointList.GetAt(ii-1);
				p2 = pointList.GetAt(ii);
				if (ii != pointList.GetSize()-1)
				{
					p3 = pointList.GetAt(ii+1);
				}
				else 
				{
					p3 = pointList.GetAt(0);
				}
				if ((p1.y-p2.y)*(p2.y-p3.y)<0)
				{
					pDC->SetPixel(p2.x, p2.y, RGB(255, 255, 255));
				}
			}
			//填充
			bool inside = false;	//是否在多边形中
			bool flag = true;		//是否需要改变
			bool bder = false;		//是否为边界值
			for (int y = minY-1; y < maxY+1; y++)
			{
				inside = false;
				flag = false;
				for (int x = minX-1; x < maxX+1; x++)
				{
					bder = (pDC->GetPixel(x, y) == RGB(0, 0, 0));
					if (bder && flag)
					{
						inside = !inside;
						flag = false;
					}
					else if (!bder && !flag)
					{
						flag = true;
					}
					if (inside && !bder) PatternFill(pDC,x,y);
				}
			}
			pointList.RemoveAll();
		}
}}

void CDemoYView::ClearScreen()
{
	CClientDC dc(this);
	CRect window;
	GetClientRect(window);
	dc.SelectStockObject(WHITE_PEN);
	dc.SelectStockObject(WHITE_BRUSH);
	dc.Rectangle(window);
	//Invalidate(TRUE);

}



void CDemoYView::DrawRect(CPoint P1, CPoint P2, CPoint P3, CPoint P4)
{
	CDC* pDC = this->GetDC();
	COLORREF color=RGB(0,0,255);
	//pDC->MoveTo(100,100);
	//pDC->LineTo(200,200);
	pDC->MoveTo(P1);
	pDC->LineTo(P2);
	pDC->LineTo(P3);
	pDC->LineTo(P4);
	pDC->LineTo(P1);

}

void CDemoYView::DrawCubic()
{
	//Draw left face
	DrawRect(LBB2D, LBT2D, LFT2D, LFB2D);
	//Draw right face
	DrawRect(RBB2D, RBT2D, RFT2D, RFB2D);
	DrawRect(LBB2D, LBT2D, RBT2D, RBB2D);
	DrawRect(LFB2D, LFT2D, RFT2D, RFB2D);
	DrawRect(LBB2D, LFB2D, RFB2D, RBB2D);
	DrawRect(LBT2D, LFT2D, RFT2D, RBT2D);
}

void CDemoYView::From3dTo2d()
{//
	
	double r;
	r = LBB3D.z * mPM[3][2] + 1;
	LBB2D.x = long((LBB3D.x * mPM[0][0] + LBB3D.y * mPM[0][1] + LBB3D.z * mPM[0][2] + mPM[0][4]) / r)+shifting;
	LBB2D.y = long((LBB3D.x * mPM[1][0] + LBB3D.y * mPM[1][1] + LBB3D.z * mPM[1][2] + mPM[1][4]) / r)+shifting;
	r = LBT3D.z * mPM[3][2] + 1;
	LBT2D.x = long((LBT3D.x * mPM[0][0] + LBT3D.y * mPM[0][1] + LBT3D.z * mPM[0][2] + mPM[0][4]) / r)+shifting;
	LBT2D.y = long((LBT3D.x * mPM[1][0] + LBT3D.y * mPM[1][1] + LBT3D.z * mPM[1][2] + mPM[1][4]) / r)+shifting;
	r = LFB3D.z * mPM[3][2] + 1;
	LFB2D.x = long((LFB3D.x * mPM[0][0] + LFB3D.y * mPM[0][1] + LFB3D.z * mPM[0][2] + mPM[0][4]) / r)+shifting;
	LFB2D.y = long((LFB3D.x * mPM[1][0] + LFB3D.y * mPM[1][1] + LFB3D.z * mPM[1][2] + mPM[1][4]) / r)+shifting;
	r = LFT3D.z * mPM[3][2] + 1;
	LFT2D.x = long((LFT3D.x * mPM[0][0] + LFT3D.y * mPM[0][1] + LFT3D.z * mPM[0][2] + mPM[0][4]) / r)+shifting;
	LFT2D.y = long((LFT3D.x * mPM[1][0] + LFT3D.y * mPM[1][1] + LFT3D.z * mPM[1][2] + mPM[1][4]) / r)+shifting;
	r = RBB3D.z * mPM[3][2] + 1;
	RBB2D.x = long((RBB3D.x * mPM[0][0] + RBB3D.y * mPM[0][1] + RBB3D.z * mPM[0][2] + mPM[0][4]) / r)+shifting;
	RBB2D.y = long((RBB3D.x * mPM[1][0] + RBB3D.y * mPM[1][1] + RBB3D.z * mPM[1][2] + mPM[1][4]) / r)+shifting;
	r = RBT3D.z * mPM[3][2] + 1;
	RBT2D.x = long((RBT3D.x * mPM[0][0] + RBT3D.y * mPM[0][1] + RBT3D.z * mPM[0][2] + mPM[0][4]) / r)+shifting;
	RBT2D.y = long((RBT3D.x * mPM[1][0] + RBT3D.y * mPM[1][1] + RBT3D.z * mPM[1][2] + mPM[1][4]) / r)+shifting;
	r = RFB3D.z * mPM[3][2] + 1;
	RFB2D.x = long((RFB3D.x * mPM[0][0] + RFB3D.y * mPM[0][1] + RFB3D.z * mPM[0][2] + mPM[0][4]) / r)+shifting;
	RFB2D.y = long((RFB3D.x * mPM[1][0] + RFB3D.y * mPM[1][1] + RFB3D.z * mPM[1][2] + mPM[1][4]) / r)+shifting;
	r = RFT3D.z * mPM[3][2] + 1;
	RFT2D.x = long((RFT3D.x * mPM[0][0] + RFT3D.y * mPM[0][1] + RFT3D.z * mPM[0][2] + mPM[0][4]) / r)+shifting;
	RFT2D.y = long((RFT3D.x * mPM[1][0] + RFT3D.y * mPM[1][1] + RFT3D.z * mPM[1][2] + mPM[1][4]) / r)+shifting;
	
	/*
	LBB2D.x = LBB3D.x * mPM[0][0] + LBB3D.y * mPM[0][1] + LBB3D.z * mPM[0][2] + mPM[0][4];
	LBB2D.y = LBB3D.x * mPM[1][0] + LBB3D.y * mPM[1][1] + LBB3D.z * mPM[1][2] + mPM[1][4];
	LBT2D.x = LBT3D.x * mPM[0][0] + LBT3D.y * mPM[0][1] + LBT3D.z * mPM[0][2] + mPM[0][4];
	LBT2D.y = LBT3D.x * mPM[1][0] + LBT3D.y * mPM[1][1] + LBT3D.z * mPM[1][2] + mPM[1][4];
	LFT2D.x = LFT3D.x * mPM[0][0] + LFT3D.y * mPM[0][1] + LFT3D.z * mPM[0][2] + mPM[0][4];
	LFT2D.y = LFT3D.x * mPM[1][0] + LFT3D.y * mPM[1][1] + LFT3D.z * mPM[1][2] + mPM[1][4];
	RBB2D.x = RBB3D.x * mPM[0][0] + RBB3D.y * mPM[0][1] + RBB3D.z * mPM[0][2] + mPM[0][4];
	RBB2D.y = RBB3D.x * mPM[1][0] + RBB3D.y * mPM[1][1] + RBB3D.z * mPM[1][2] + mPM[1][4];
	RBT2D.x = RBT3D.x * mPM[0][0] + RBT3D.y * mPM[0][1] + RBT3D.z * mPM[0][2] + mPM[0][4];
	RBT2D.y = RBT3D.x * mPM[1][0] + RBT3D.y * mPM[1][1] + RBT3D.z * mPM[1][2] + mPM[1][4];
	RFB2D.x = RFB3D.x * mPM[0][0] + RFB3D.y * mPM[0][1] + RFB3D.z * mPM[0][2] + mPM[0][4];
	RFB2D.y = RFB3D.x * mPM[1][0] + RFB3D.y * mPM[1][1] + RFB3D.z * mPM[1][2] + mPM[1][4];
	RFT2D.x = RFT3D.x * mPM[0][0] + RFT3D.y * mPM[0][1] + RFT3D.z * mPM[0][2] + mPM[0][4];
	RFT2D.y = RFT3D.x * mPM[1][0] + RFT3D.y * mPM[1][1] + RFT3D.z * mPM[1][2] + mPM[1][4];
	*/
}

void CDemoYView::OnIsometric() 
{
	// TODO: Add your command handler code here
	type=6;
	
	perspectiveProjection = false;
	mPM[0][0] = 0.70710678118655;
	mPM[0][1] = 0.70710678118655;;
	mPM[0][2] = 0;
	mPM[0][3] = 0;
	mPM[1][0] = -0.40824829046386;
	mPM[1][1] = 0.40824829046386;
	mPM[1][2] = 0.81648658092773;
	mPM[1][3] = 0;	
	mPM[2][0] = 0;
	mPM[2][1] = 0;
	mPM[2][2] = 0;
	mPM[2][3] = 0;	
	mPM[3][0] = 0;
	mPM[3][1] = 0;
	mPM[3][2] = 0;
	mPM[3][3] = 1;
	From3dTo2d();
	DrawCubic();
	
}

void CDemoYView::OnCabinet() 
{
	// TODO: Add your command handler code here
	//OnExp3();
	type = 7;
	perspectiveProjection = false;

	double L = 1;
	double Alpha = 45;
	Alpha *= 3.1415926 / 180;
	double c = cos(Alpha);
	double s = sin(Alpha);

	mPM[0][0] = 1;
	mPM[0][1] = 0;
	mPM[0][2] = L*c;
	mPM[0][3] = 0;
	mPM[1][0] = 0;
	mPM[1][1] = 1;
	mPM[1][2] = L*s;
	mPM[1][3] = 0;	
	mPM[2][0] = 0;
	mPM[2][1] = 0;
	mPM[2][2] = 0;
	mPM[2][3] = 0;	
	mPM[3][0] = 0;
	mPM[3][1] = 0;
	mPM[3][2] = 0;
	mPM[3][3] = 1;
	From3dTo2d();
	DrawCubic();
}

void CDemoYView::OnPerspective() 
{
	// TODO: Add your command handler code here
	type = 8;
	perspectiveProjection = true;

	mPM[0][0] = 1;
	mPM[0][1] = 0;
	mPM[0][2] = perspectiveX / (-perspectiveZ);
	mPM[0][3] = 0;
	mPM[1][0] = 0;
	mPM[1][1] = 1;
	mPM[1][2] = perspectiveY / (-perspectiveZ);
	mPM[1][3] = 0;
	mPM[2][0] = 0;
	mPM[2][1] = 0;
	mPM[2][2] = 0;
	mPM[2][3] = 0;
	mPM[3][0] = 0;
	mPM[3][1] = 0;
	mPM[3][2] = 1/ (-perspectiveZ);
	mPM[3][3] = 1;
	From3dTo2d();
	DrawCubic();
}

void CDemoYView::Isometric()
{
	perspectiveProjection = false;
	
	mPM[0][0] = 0.70710678118655;
	mPM[0][1] = 0.70710678118655;;
	mPM[0][2] = 0;
	mPM[0][3] = 0;
	mPM[1][0] = -0.408248;
	mPM[1][1] = 0.408248;
	mPM[1][2] = 0.81648658092773;
	mPM[1][3] = 0;	
	mPM[2][0] = 0;
	mPM[2][1] = 0;
	mPM[2][2] = 0;
	mPM[2][3] = 0;	
	mPM[3][0] = 0;
	mPM[3][1] = 0;
	mPM[3][2] = 0;
	mPM[3][3] = 1;
	From3dTo2d();
	DrawCubic();
}

void CDemoYView::ProportionChange(double scale)
{
	LBB3D.x *= scale;
	LBT3D.x *= scale;
	LFB3D.x *= scale;
	LFT3D.x *= scale;
	RBB3D.x *= scale;
	RBT3D.x *= scale;
	RFB3D.x *= scale;
	RFT3D.x *= scale;

	LBB3D.y *= scale;
	LBT3D.y *= scale;
	LFB3D.y *= scale;
	LFT3D.y *= scale;
	RBB3D.y *= scale;
	RBT3D.y *= scale;
	RFB3D.y *= scale;
	RFT3D.y *= scale;

	LBB3D.z *= scale;
	LBT3D.z *= scale;
	LFB3D.z *= scale;
	LFT3D.z *= scale;
	RBB3D.z *= scale;
	RBT3D.z *= scale;
	RFB3D.z *= scale;
	RFT3D.z *= scale;
}

void CDemoYView::RotateChange(double angle)
{
	double c = cos(angle);
	double s = sin(angle);

	switch (axes)
	{
	case 1: 
	{
		double y = LBB3D.y;
		double z = LBB3D.z;
		LBB3D.y = y * c - z * s; LBB3D.z = y * s + z * c;
		y = LBT3D.y; z = LBT3D.z;
		LBT3D.y = y * c - z * s; LBT3D.z = y * s + z * c;
		y = LFB3D.y; z = LFB3D.z;
		LFB3D.y = y * c - z * s; LFB3D.z = y * s + z * c;
		y = LFT3D.y; z = LFT3D.z;
		LFT3D.y = y * c - z * s; LFT3D.z = y * s + z * c;
		y = RBB3D.y; z = RBB3D.z;
		RBB3D.y = y * c - z * s; RBB3D.z = y * s + z * c;
		y = RBT3D.y; z = RBT3D.z;
		RBT3D.y = y * c - z * s; RBT3D.z = y * s + z * c;
		y = RFB3D.y; z = RFB3D.z;
		RFB3D.y = y * c - z * s; RFB3D.z = y * s + z * c;
		y = RFT3D.y; z = RFT3D.z;
		RFT3D.y = y * c - z * s; RFT3D.z = y * s + z * c;
	}
	break;
	case 2: 
	{
		double z = LBB3D.z;
		double x = LBB3D.x;
		LBB3D.z = z * c - x * s; LBB3D.x = z * s + x * c;
		z = LBT3D.z; x = LBT3D.x;
		LBT3D.z = z * c - x * s; LBT3D.x = z * s + x * c;
		z = LFB3D.z; x = LFB3D.x;
		LFB3D.z = z * c - x * s; LFB3D.x = z * s + x * c;
		z = LFT3D.z; x = LFT3D.x;
		LFT3D.z = z * c - x * s; LFT3D.x = z * s + x * c;
		z = RBB3D.z; x = RBB3D.x;
		RBB3D.z = z * c - x * s; RBB3D.x = z * s + x * c;
		z = RBT3D.z; x = RBT3D.x;
		RBT3D.z = z * c - x * s; RBT3D.x = z * s + x * c;
		z = RFB3D.z; x = RFB3D.x;
		RFB3D.z = z * c - x * s; RFB3D.x = z * s + x * c;
		z = RFT3D.z; x = RFT3D.x;
		RFT3D.z = z * c - x * s; RFT3D.x = z * s + x * c;
	}
	break;
	case 3: 
	{
		double x = LBB3D.x;
		double y = LBB3D.y;
		LBB3D.x = x * c - y * s; LBB3D.y = x * s + y * c;
		x = LBT3D.x; y = LBT3D.y;
		LBT3D.x = x * c - y * s; LBT3D.y = x * s + y * c;
		x = LFB3D.x; y = LFB3D.y;
		LFB3D.x = x * c - y * s; LFB3D.y = x * s + y * c;
		x = LFT3D.x; y = LFT3D.y;
		LFT3D.x = x * c - y * s; LFT3D.y = x * s + y * c;
		x = RBB3D.x; y = RBB3D.y;
		RBB3D.x = x * c - y * s; RBB3D.y = x * s + y * c;
		x = RBT3D.x; y = RBT3D.y;
		RBT3D.x = x * c - y * s; RBT3D.y = x * s + y * c;
		x = RFB3D.x; y = RFB3D.y;
		RFB3D.x = x * c - y * s; RFB3D.y = x * s + y * c;
		x = RFT3D.x; y = RFT3D.y;
		RFT3D.x = x * c - y * s; RFT3D.y = x * s + y * c;
	}
	break;
	default:
		break;
	}
}
