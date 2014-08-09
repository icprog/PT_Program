// MainFrm.h : interface of the CMainFrame class
//


#pragma once

#define MAXBUFFERSIZE	102400
#define MINBUFFERSIZE	512

class CMainFrame : public CFrameWnd
{
	
protected: // create from serialization only
	CMainFrame();
	DECLARE_DYNCREATE(CMainFrame)

// Attributes
public:

// Operations
public:

// Overrides
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// Implementation
public:
	virtual ~CMainFrame();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:  // control bar embedded members
	CStatusBar  m_wndStatusBar;
	CToolBar    m_wndToolBar;

// Generated message map functions
protected:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnClose();
public:
	bool NewReadIniFile();
public:
	typedef struct _IniProgramVersion
	{
		char	ProgramVersion[MINBUFFERSIZE] ;
		char	ProgramAuthor[MINBUFFERSIZE] ;
		char	ProgramData[MINBUFFERSIZE] ;	
	}IniProgramVersion,*pIniProgramVersion;
public:
IniProgramVersion   PROVER;
};


