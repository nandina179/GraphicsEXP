// Demo5Doc.cpp : implementation of the CDemo5Doc class
//

#include "stdafx.h"
#include "Demo5.h"

#include "Demo5Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDemo5Doc

IMPLEMENT_DYNCREATE(CDemo5Doc, CDocument)

BEGIN_MESSAGE_MAP(CDemo5Doc, CDocument)
	//{{AFX_MSG_MAP(CDemo5Doc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDemo5Doc construction/destruction

CDemo5Doc::CDemo5Doc()
{
	// TODO: add one-time construction code here

}

CDemo5Doc::~CDemo5Doc()
{
}

BOOL CDemo5Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CDemo5Doc serialization

void CDemo5Doc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// CDemo5Doc diagnostics

#ifdef _DEBUG
void CDemo5Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CDemo5Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CDemo5Doc commands
