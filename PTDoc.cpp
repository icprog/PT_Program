// FTDoc.cpp : implementation of the CFTDoc class
//

#include "stdafx.h"
#include "PT.h"

#include "PTDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CFTDoc

IMPLEMENT_DYNCREATE(CPTDoc, CDocument)

BEGIN_MESSAGE_MAP(CPTDoc, CDocument)
END_MESSAGE_MAP()


// CFTDoc construction/destruction

CPTDoc::CPTDoc()
{
	// TODO: add one-time construction code here

}

CPTDoc::~CPTDoc()
{
}

BOOL CPTDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}




// CFTDoc serialization

void CPTDoc::Serialize(CArchive& ar)
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


// CFTDoc diagnostics

#ifdef _DEBUG
void CPTDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CPTDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CFTDoc commands
