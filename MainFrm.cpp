// MainFrm.cpp : implementation of the CMainFrame class
//
/*version information
V1.0.1	2011/3/7
		1.Use H181's PT program change to H163's
		2.change when test pass&fail read SFC's reponse
V1.0.2	2011/4/9
		1.change wait way when SFC not reponse
		2.Modfiy a bug:program don't show pass/fail when test end
V1.0.3	2011/4/14
		1.Modfiy a bug:Don't recode test log to server
V1.0.4	2011/5/30
		1.change program to UI program
		2.change init.ini file to struct way,in program which use the parameter also as struct
V1.0.5	2011/6/15
		1.delete WIFI test command at UI program
		--->just used for U12H187
V1.0.6	2011/7/1
		1.Add MydasDebug parameter used for debug mydas without OnSFIS
		2.Add show Mydas sent data(detail/error/main) for Mydas debug
		3.add WIFI test command at UI program
		--->When used in other project,the WIFI test command is must.If not have,some test items cann't test
		4.cannell change program version at init.ini file
V1.0.7	2011/7/1
		1.add a "," at end of detail test data.(because VN Mydas set if detail is null ,cann't insert data to server)
		2.change updata data to MYDAS judge logic to:((OnSFIS && PostMydas) || MydasDebug ) 
		3.add show more debug information about MYDAS (after collect data , before send to MYDAS )
		4.delete WIFI test command at UI program
		--->New program will not need WIFI test command used in UI.
V1.0.1.0	2011/7/2
		1.Use new name rules mark version infomation
		2.Pass and fail funtion add adjust(if no test foxconn normally test)
		3.change Run_WiFiTest() timeout from 1500*200 to 15000*100
		4.add adjust before read Ambit_test_flow.ini
		5.error code define change (group by 2.4G/5G)
		6.change Run_WiFiTest() timeout from 15000*100 to 150000*100
		7.change error code part by 2.4G/5G/ U12H189 have a bug:test 2.4G first so error code errored
V1.1.1.0	2011/8/8
		1.change disable wireless station from RUN_TEST to ON_PASS
		--->Because if just test by bat,the Disable wireless code will become to unreachable
		2.modfiy a bug:2.4G EVM/Power fail but error code is 5G's 
		--->In 2.4G's Run_WiFiTest() , case value marked error
		3.use new ParseData.h(add "_b"/"_f")
		--->old ParseData.h just surport 5g test by .bat file,but U12H189 all test items test by .bat 
V1.2.1.0	2011/9/1
		1.check "RF01" failed,but program show passed!
		--->because at "RF01" just send failed result,but not return lead program going continue
		2.check disable wireless funtion 
		--->at funtion logic is so choas,find queer things:show error code ono by one time,but last result is passs
V1.3.1.0	2011/10/7
		1.add TFTP server before test	
V1.4.1.0	2011/10/17
		1.add funtion:Run_WiFiTest_IQDemo(),used for run IQ lite program all ourself(used with Dai-Xin's "LP_Script_Generator.exe").
		2.modfiy bug:when close the program,program will report error messagebox.--->Dai-Xin&Jack
		3.add funtion:GetItemPower( char *TestItems ),used for get Power SPEC at test items.
		4.add higt power lever error code.(2g:PR05/PR06/PR08;5g:PR15/PR16/PR18)
V1.5.1.1	2011/11/2
		1.add funtion:Run_WiFiTest_IQDemo(),used for run IQ lite program all ourself(used with Dai-Xin's "LP_Script_Generator.exe").
V1.6.1.1	2011/11/8
		1.add recode log file to server(Mark by falg:RecordFilePathServer)
		2.SLxx/SRxx/SYxx don't sent to Mydas.
		3.Bug:at Run_WiFiTest() if return value=16,show error code "IN10",but it not mean "IN10"
		4.add mark program build data and time at program title
end*/



#include "stdafx.h"
#include "PT.h"
#include "PTView.h"
#include "MainFrm.h"
//#include "Version.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#define Version "V1.4.1.0"
#define Author	"FH"
#define	Data	"2011/10/17"

// CMainFrame

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	ON_WM_CREATE()
	ON_WM_CLOSE()
END_MESSAGE_MAP()

static UINT indicators[] =
{
	ID_SEPARATOR,           // status line indicator
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};


char	ProgramVersion[MINBUFFERSIZE] = "";
char	ProgramAuthor[MINBUFFERSIZE] = "";
char	ProgramData[MINBUFFERSIZE] = "";


// CMainFrame construction/destruction

CMainFrame::CMainFrame()
{
	// TODO: add member initialization code here
}

CMainFrame::~CMainFrame()
{
}


int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	if (!m_wndToolBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_TOP
		| CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC) ||
		!m_wndToolBar.LoadToolBar(IDR_MAINFRAME))
	{
		TRACE0("Failed to create toolbar\n");
		return -1;      // fail to create
	}

	if (!m_wndStatusBar.Create(this) ||
		!m_wndStatusBar.SetIndicators(indicators,
		  sizeof(indicators)/sizeof(UINT)))
	{
		TRACE0("Failed to create status bar\n");
		return -1;      // fail to create
	}

	// TODO: Delete these three lines if you don't want the toolbar to be dockable
	m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);
	EnableDocking(CBRS_ALIGN_ANY);
	DockControlBar(&m_wndToolBar);
	m_wndToolBar.ShowWindow(SW_HIDE);
	m_wndStatusBar.ShowWindow(SW_HIDE);

//	int cx = GetSystemMetrics(SM_CXSCREEN);
//	int cy = GetSystemMetrics(SM_CYSCREEN);
	SetWindowLong(m_hWnd,GWL_STYLE,GetWindowLong(m_hWnd,GWL_STYLE)&~(WS_MAXIMIZEBOX | WS_MINIMIZEBOX|WS_SIZEBOX));
	SetWindowPos(NULL,0,0,890,610,SWP_SHOWWINDOW);
		
	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if(!NewReadIniFile())
		return FALSE;
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs
	cs.style&=~FWS_ADDTOTITLE;
	char	szBuf[MAXBUFFERSIZE];
	
	//printf("Built Date:      \t%s\n",__DATE__);
	//printf("Built Time:      \t%s\n",__TIME__);

	sprintf_s( szBuf , MAXBUFFERSIZE , "PT IQLite %s Author:%s Data:%s                                                        Built Date:%s_%s" , 
		_T(PROVER.ProgramVersion) , 
		_T(PROVER.ProgramAuthor) , 
		_T(PROVER.ProgramData)  ,
		_T(__DATE__) ,
		_T(__TIME__) );
	//char Buf[16];
	//sprintf(Buf,"%s",_GetVersion());
	//sprintf_s( szBuf , MAXBUFFERSIZE , "PT IQLite %s Author:%s Data:%s" ,/*_T(Buf),*/ _T(Version) , _T(Author) , _T(Data));
	cs.lpszName = _T(szBuf);
	return TRUE;
}


// CMainFrame diagnostics

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CFrameWnd::Dump(dc);
}

#endif //_DEBUG


// CMainFrame message handlers

#include "Winsock2.h"


void CMainFrame::OnClose()
{
	// TODO: Add your message handler code here and/or call default
	WSACleanup();

	CPTView *pView = ((CPTView*)GetActiveView());
	CRunInfo *pRunInfo = pView->RetriveDlgPoint();

	char szConnectControlFlag[MAX_PATH] ="";
	char szDutName[MAX_PATH] = "";

	char szINITPath[MAX_PATH]="";		
	char szFoxLiteStartup[MAX_PATH]="";

	GetCurrentDirectory(sizeof(szINITPath),szINITPath);

	lstrcat(szINITPath,"\\init.ini");
	sprintf_s(szFoxLiteStartup,MAX_PATH,"%s\\%s",szINITPath,"TestStartUp.ini");
	WritePrivateProfileString("TESTER_CONTROL","CTRL_MODE","999",szFoxLiteStartup);

	GetPrivateProfileString("ConnectControl","DutName","0" ,szDutName, MAX_PATH,szINITPath);	
	GetPrivateProfileString("ConnectControl","ConnectcontrolFlag","0" ,szConnectControlFlag, MAX_PATH,szINITPath);
	
	if(strstr(szConnectControlFlag , "1") != NULL)
	{
		HKEY   hk;
		DWORD  dwDisp;		
		char RegBuf[MAX_PATH] = "";
		sprintf_s(RegBuf , MAX_PATH , "SYSTEM\\CurrentControlSet\\Services\\%s" , szDutName);		
		if(RegCreateKeyEx(HKEY_LOCAL_MACHINE,
			RegBuf,
			0,
			NULL,
			REG_OPTION_NON_VOLATILE,
			KEY_WRITE | KEY_QUERY_VALUE,
			NULL,
			&hk,
			&dwDisp))
		{
			AfxMessageBox("Open registry fail...");
		}
		else
		{
			char szCOM[256]="";
			char FileTime[256] = "";
			char szTestTime[256] = "";
			char szTestTimeN[256] = "";
			char szTestTimeC[256] = "";

			int iCOM=((CComboBox*)(pRunInfo->GetDlgItem(IDC_EDIT_COM)))->GetCurSel();
			sprintf_s(FileTime,256,pRunInfo->m_FileTime);

			_itoa_s(pRunInfo->m_strConnectTime, szTestTime, 256, 10);
			_itoa_s(pRunInfo->m_strConnectTimeN,szTestTimeN, 256, 10);
			_itoa_s(pRunInfo->m_strConnectTimeC,szTestTimeC, 256, 10);


			sprintf_s(szTestTime,256,szTestTime);
			sprintf_s(szTestTimeN,256,szTestTimeN);
			sprintf_s(szTestTimeC,256,szTestTimeC);
			sprintf_s(szCOM,256,"%d",iCOM);

			if(RegSetValueEx(hk,"COM",0,REG_SZ,(LPBYTE)szCOM,(DWORD)strlen(szCOM)+1)
				|| RegSetValueEx(hk,"FILETIME",0,REG_SZ,(LPBYTE)FileTime,(DWORD)strlen(FileTime)+1)
				|| RegSetValueEx(hk,"CONNECTTIME",0,REG_SZ,(LPBYTE)szTestTime,(DWORD)strlen(szTestTime)+1)
				|| RegSetValueEx(hk,"CONNECTTIMEN",0,REG_SZ,(LPBYTE)szTestTimeN,(DWORD)strlen(szTestTimeN)+1)
				|| RegSetValueEx(hk,"CONNECTTIMEC",0,REG_SZ,(LPBYTE)szTestTimeC,(DWORD)strlen(szTestTimeC)+1))

			{
				RegCloseKey(hk); 		
			}

		}

		RegCloseKey(hk);
	}	
	// kill IQRun_Console.exe
	pRunInfo->DeleteSpecifyExe("IQrun_Console.exe");
	pRunInfo->DeleteSpecifyExe("Netgear_TFTP_Server.exe");
	CFrameWnd::OnClose();	
}
bool CMainFrame::NewReadIniFile()
{	
	char szProPath[MINBUFSIZE]="";	

	GetCurrentDirectory(sizeof(szProPath),szProPath);
	lstrcat(szProPath,"\\init.ini");
	GetPrivateProfileString("ProgramVersion","ProgramVersion","V1.2.1.0",PROVER.ProgramVersion,MINBUFSIZE,szProPath);
	GetPrivateProfileString("ProgramVersion","ProgramAuthor","FH",PROVER.ProgramAuthor, MINBUFSIZE,szProPath);
	GetPrivateProfileString("ProgramVersion","ProgramData","2011/8/8",PROVER.ProgramData, MINBUFSIZE,szProPath);

	return 1;
}