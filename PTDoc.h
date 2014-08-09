// FTDoc.h : interface of the CFTDoc class
//


#pragma once


class CPTDoc : public CDocument
{
protected: // create from serialization only
	CPTDoc();
	DECLARE_DYNCREATE(CPTDoc)

// Attributes
public:

// Operations
public:

// Overrides
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);

// Implementation
public:
	virtual ~CPTDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
};


