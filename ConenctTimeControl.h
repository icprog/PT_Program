#pragma once


// CConenctTimeControl dialog

class CConenctTimeControl : public CDialog
{
	DECLARE_DYNAMIC(CConenctTimeControl)

public:
	CConenctTimeControl(CWnd* pParent = NULL);   // standard constructor
	virtual ~CConenctTimeControl();

// Dialog Data
	enum { IDD = IDD_PASSWORD };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CString m_PassWord; 
};
