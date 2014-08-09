#pragma once
#include "ConenctTimeControl.h"
#include "IsStartSfis.h"
#include "Com.h"
#include <fstream>
#include "Winsock2.h"
#include "PTSC.h"
#include "ParseData.h"

using namespace std;
#include "ambit_config.h"

// CRunInfo dialog


class CRunInfo : public CDialog
{
	DECLARE_DYNAMIC(CRunInfo)

public:
	CRunInfo(CWnd* pParent = NULL);   // standard constructor
	virtual ~CRunInfo();

// Dialog Data
	enum { IDD = IDD_RUNINFO };
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
protected:
	virtual void    OnOK();

public:
	typedef struct _IniGeneral
	{
		char		szTestByBat[MINBUFSIZE];
		char        szDefaultIP[MINBUFSIZE];
		char		szDisableWireless[MINBUFSIZE];	
		char		szSFCProductLength[MINBUFSIZE];
		char		szDebugShow[MINBUFSIZE];

	}IniGeneral,*pIniGeneral;
//IniGeneral			GEN;

public:
	typedef struct _IniConnectControl
	{
		char		szConnectControlFlag[MINBUFSIZE] ;
		char		szDutName[MAX_PATH] ;
		char		szTestTime[MINBUFSIZE] ;
		char		szTestTimeN[MINBUFSIZE] ;
		char		szTestTimeC[MINBUFSIZE] ;
	}IniConnectControl,*pIniConnectControl;
//IniConnectControl			CC;

public:
	typedef struct _IniTestFlow
	{
		char		szTestWiFiCommonFlag[MINBUFSIZE] ;
		char		szTest5G[MINBUFSIZE] ;
		char		szTest2G[MINBUFSIZE] ;	
		char		szIQDemoRunFlag[MINBUFSIZE] ;
		
	}IniTestFlow,*pIniTestFlow;
//IniTestFlow			TF;
public:
	typedef struct _IniDownLoadImage
	{
		char		szDownLoadImageFlag[MINBUFSIZE] ;
		char		szDownloadFinishFlag[MINBUFSIZE] ;		
		char		szDownloadDetectedFlag[MINBUFSIZE] ;	
	}IniDownLoadImage,*pIniDownLoadImage;
//IniDownLoad			DLI;

public:
	typedef struct _IniIQDemoRun
	{
		char		szIQDemoRunMarkFlag[MINBUFSIZE] ;		
		char		szIQDemoRunFileName[MINBUFSIZE] ;		
	}IniIQDemoRun,*pIniIQDemoRun;
//IniIQDemoRun			IDR;

public:
	typedef struct _IniProgramVersion
	{
		char		ProgramVersion[MINBUFSIZE] ;
		char		ProgramAuthor[MINBUFSIZE] ;
		char		ProgramData[MINBUFSIZE] ;	
	}IniProgramVersion,*pIniProgramVersion ;
//IniProgramVersion	PVER;

public:
	typedef struct _IniFilePath
	{
		char		szPath[MINBUFSIZE] ;/*init.ini path on server*/
		char		szPath1[MINBUFSIZE] ;/*2gconfig.txt path on server*/
		char	    szPath2[MINBUFSIZE] ;/*5gconfig.txt path on server*/
		char		szPath3[MINBUFSIZE] ;/*file path on server*/
		char		szPath4[MINBUFSIZE] ;/*file path on server*/
		char		szPath5[MINBUFSIZE] ;/*file path on server*/
		char        szStoreSrvPath[MINBUFSIZE] ;//recode disk file path
		char        szRecodeServerFlag[MINBUFSIZE] ;//Recode Server Flag,1:recode on server
		char		Log[MINBUFSIZE] ; //Recode server file path
	}IniFilePath,*pIniFilePath;
//IniFilePath			FP;

public:
	typedef struct _Ini5GBatTest
	{
			
		char        RunBATName_5G[MINBUFSIZE] ;
		char        IQLogFile_5G[MINBUFSIZE] ;
		char        IQLogPath_5G[MINBUFSIZE] ;
		char		IQTestFinishFlagFile_5G[MINBUFSIZE] ;
		char		BATFilePath_5G[MINBUFSIZE] ;
		char		ServeBATPath_5G[MINBUFSIZE] ;
		char		WindowsName_5G[MINBUFSIZE] ;
	}Ini5GBatTest,*pIni5GBatTest;
//Ini5GBatTest		T5G;

public:
	typedef struct _Ini2GBatTest
	{
			
		char        RunBATName_2G[MINBUFSIZE] ;
		char        IQLogFile_2G[MINBUFSIZE] ;
		char        IQLogPath_2G[MINBUFSIZE] ;
		char		IQTestFinishFlagFile_2G[MINBUFSIZE] ;
		char		BATFilePath_2G[MINBUFSIZE] ;
		char		ServeBATPath_2G[MINBUFSIZE] ;
		char		WindowsName_2G[MINBUFSIZE] ;
	}Ini2GBatTest,*pIni2GBatTest;
//Ini2GBatTest		T2G;

public:
	typedef struct _IniMYDAS
	{
		char		szPostMydas[MINBUFSIZE]; 
		char		szMydasDebug[MINBUFSIZE]; 
	}IniMYDAS,*pIni_IniMYDAS;
//IniMYDAS		MY;

public:
	typedef struct _IniSFC
	{
		char		szSFCBegin[MINBUFSIZE]; 
		char		szSFCPass[MINBUFSIZE];
		char		szSFCFail[MINBUFSIZE];
	}IniSFC,*pIni_IniSFC;
//IniSFC			SFC;
public:
	struct _Iniinfo
	{
		IniGeneral			GEN;	
		IniFilePath			FP;
		IniTestFlow			TF;
		IniProgramVersion	PVER;
		Ini5GBatTest		T5G;
		Ini2GBatTest		T2G;
		IniMYDAS			MY;
		IniConnectControl	CC;
		IniSFC				SFC;
		IniDownLoadImage	DLI;
		IniIQDemoRun		IDR;
	}Iniinfo,INI;
//Iniinfo				INI;


public:
	afx_msg void   OnTimer(UINT_PTR nIDEvent);
	afx_msg int    OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void   OnBnClickedBtnStart();
	afx_msg void   OnBnClickedBtnQuit();
	afx_msg void   OnCbnSelchangeCom();
private:
	afx_msg LRESULT  OnRecvComData(WPARAM wParam,LPARAM lParam);
	afx_msg LRESULT  OnPass(WPARAM wParam,LPARAM lParam);
	afx_msg LRESULT  OnFail(WPARAM wParam,LPARAM lParam);
	afx_msg HBRUSH   OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
private:
	CTime			m_TestTimeCount;
	CFont			m_SupMinft, m_Minft, m_Midft, m_Maxft, m_Supft;
	CBrush			m_Redbh, m_Greenbh, m_Yellowbh, m_Grancybh, m_Blackbh;
	CIsStartSfis	m_IsStartSfis;	
	CCom			m_ComSfis;
	CCom			m_ComTest;
	SOCKET		    m_Socket;
	bool			m_blIsOpenSfis;
	bool			m_blIsSfis;
	
private:	
	CString        m_strCom;
	CString        m_strSfisStatus;
	CString        m_strTestResult;
	CString        m_strErroCode;
	CString		   m_strMAC;
	CConenctTimeControl m_ConnectTime;
	CConenctTimeControl m_ConnectTimeN;
	CConenctTimeControl m_ConnectTimeC;
	
public:
	CString    m_strProductName;
	CString    m_strTestTime;
	CString    m_strPcName;
	CString    m_strIniProductName;
	CString    m_strStoreEthernetData;
	CString    m_strSN;
	double     m_TestTime;  //Recode TestTime
	CString	   m_FileTime;
	int		   m_strConnectTime;
	int		   m_strConnectTimeN;
	int		   m_strConnectTimeC;
	int iCOM;
	int iConnectTime;
	int iConnectTimeN;
	int iConnectTimeC;
	fstream fsPass;
	fstream fsFail;
private:
	void    IsDisplayErrorCode(bool Flag);
	void    CountTestResult(bool IsPass);
	
public:
	void    DisplayRunTimeInfo(const char* pRunInfo);
	void    DisplayTestInfo(char *Describe , char *parameter );
	void    SendSfisResultAndShowFail(char* ErroCode);
	void    SendSfisResultAndShowPass();
	bool    InitSocket();
	HANDLE  m_hEvt;
	bool    PingSpecifyIP(char* IP, int nSuccessCount);
	void    DeleteSpecifyExe(char* exeName);
	int     Run_WiFiTest(CString RunBATName , 
						  CString IQLogFile , 
						  CString IQLogPath ,
						  CString IQTestFinishFlagFile ,
						  CString BATFilePath ,
						//  CString ServeBATPath ,
						  CString WindowsName 
						  );
	int		Get5gTestErorCode(char *szLine);
	static  UINT __cdecl  ReadComForSfis(LPVOID param);
	static  UINT __cdecl  FunctionTestRun(LPVOID parameter);
	
	void    TestPass();
	void    TestFail(char* ErroCode);
	void    SendEthernetCmd(char* SendData);
	int     CRunInfo::RunSpecifyExeAndRead(CString& strArpOutInfo,char* RunFileName,bool bIsShow = false);
	
	bool    CRunInfo::ReadIniFile();
	bool    RunTelnetExe(char* GetMacValue);
public:
	afx_msg void OnDestroy();
	afx_msg LRESULT  OnRecvEthernetData(WPARAM wParam,LPARAM lParam);
public:
	CString CRunInfo::GetMydasData(CString szResult);
public:
	int CRunInfo::GetSFISData(/*[in]*/char InputBuf[MINBUFSIZE] , /*[out]*/char RtnBuf[MINBUFSIZE]);
public:
	void    GetMac(IN char* source,OUT char* target);
public:
	bool	SendDutCommand(char *pCmd, char *pRtn, int iDelay=1000);
public:
	bool Funtion_Downlaod_image();
	int Read_ini();
	int Run_WiFiTest_IQDemo();
	int GetItemPower( char *TestItems );

};



