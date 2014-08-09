// FTView.cpp : implementation of the CFTView class
//

#include "stdafx.h"
#include "PT.h"

#include "PTDoc.h"



#include "PTView.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CFTView

IMPLEMENT_DYNCREATE(CPTView, CView)

BEGIN_MESSAGE_MAP(CPTView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_CREATE()
END_MESSAGE_MAP()

// CFTView construction/destruction

CPTView::CPTView()
{
	// TODO: add construction code here

}

CPTView::~CPTView()
{
}

BOOL CPTView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CFTView drawing

void CPTView::OnDraw(CDC* /*pDC*/)
{
	CPTDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// CFTView printing

BOOL CPTView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CPTView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CPTView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}


// CFTView diagnostics

#ifdef _DEBUG
void CPTView::AssertValid() const
{
	CView::AssertValid();
}

void CPTView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CPTDoc* CPTView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CPTDoc)));
	return (CPTDoc*)m_pDocument;
}
#endif //_DEBUG


// CFTView message handlers
class CHandleMap;
int CPTView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  Add your specialized creation code here
	m_RunInfo.Create(IDD_RUNINFO,this);	
	return 0;
}



void CPTView::OnInitialUpdate()
{
	CView::OnInitialUpdate();
//	m_RunInfo.SetWindowPos(NULL,0,0,880,600,SWP_SHOWWINDOW);
	// TODO: Add your specialized code here and/or call the base class
}

CRunInfo* CPTView::RetriveDlgPoint()
{
	return &m_RunInfo;
}
