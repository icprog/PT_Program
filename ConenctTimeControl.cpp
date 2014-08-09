// ConenctTimeControl.cpp : implementation file
//

#include "stdafx.h"
#include "PT.h"
#include "ConenctTimeControl.h"


// CConenctTimeControl dialog

IMPLEMENT_DYNAMIC(CConenctTimeControl, CDialog)

CConenctTimeControl::CConenctTimeControl(CWnd* pParent /*=NULL*/)
	: CDialog(CConenctTimeControl::IDD, pParent)
{

}

CConenctTimeControl::~CConenctTimeControl()
{
}

void CConenctTimeControl::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_PassWord);
}


BEGIN_MESSAGE_MAP(CConenctTimeControl, CDialog)
END_MESSAGE_MAP()


// CConenctTimeControl message handlers
