// final07Doc.cpp : implementation of the CFinal07Doc class
//

#include "stdafx.h"
#include "final07.h"

#include "final07Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CFinal07Doc

IMPLEMENT_DYNCREATE(CFinal07Doc, CDocument)

BEGIN_MESSAGE_MAP(CFinal07Doc, CDocument)
	//{{AFX_MSG_MAP(CFinal07Doc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CFinal07Doc construction/destruction

CFinal07Doc::CFinal07Doc()
{
	// TODO: add one-time construction code here

}

CFinal07Doc::~CFinal07Doc()
{
}

BOOL CFinal07Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CFinal07Doc serialization

void CFinal07Doc::Serialize(CArchive& ar)
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
// CFinal07Doc diagnostics

#ifdef _DEBUG
void CFinal07Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CFinal07Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CFinal07Doc commands
