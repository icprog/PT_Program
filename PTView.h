// FTView.h : interface of the CFTView class
//


#pragma once

#include "RunInfo.h"
#include "PTDoc.h"
class CPTView : public CView
{
protected: // create from serialization only
	CPTView();
	DECLARE_DYNCREATE(CPTView)

// Attributes
public:
	CPTDoc* GetDocument() const;

// Operations
public:

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// Implementation
public:
	virtual ~CPTView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
private:
	CRunInfo m_RunInfo;
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	virtual void OnInitialUpdate();

public:
	afx_msg void OnClose();
public:
//	virtual BOOL DestroyWindow();
	CRunInfo* RetriveDlgPoint();
};

#ifndef _DEBUG  // debug version in FTView.cpp
inline CPTDoc* CPTView::GetDocument() const
   { return reinterpret_cast<CPTDoc*>(m_pDocument); }
#endif

