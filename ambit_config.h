#ifndef _AMBIT_CONFIG_H_
#define _AMBIT_CONFIG_H_

//#define WIFI_TEST_EXPORTS

#ifdef AMBIT_CONFIG_EXPORT

#define AMBIT_CONFIG_API extern "C" __declspec(dllexport)
#else
    #ifdef __cplusplus
        #define AMBIT_CONFIG_API extern "C" __declspec(dllimport) 
    #else
        #define AMBIT_CONFIG_API extern
    #endif
#endif

#ifndef BUF_LEN 
#define BUF_LEN 256
#endif



enum TEST_TYPE
{
	PER,
	EVM,
	MASK
};

enum EVM_TEST_TYPE
{
	EVM_POWER,
	EVM_EVM,
	EVM_FREQ,
	ALL
};

enum RESULT
{
	PASS,
	FAIL,
	ERRORR,
};

typedef struct tagReturnInfo
{
	char   TestItem[BUF_LEN];
	char   ErrorDes[BUF_LEN];
	vector<string> RunInfo;
	BOOL   bFinish;
	RESULT Result;
	long   beginTestTime;
}ReturnInfo;

//typedef struct tagReturnValueCollection
//{
//	map<string,double> per;
//	map<string,double> evm;
//	map<string,double> power;
//	map<string,double> mask;
//	map<string,double> freq;
//}ReturnValueCollection;


typedef void (*RF_pfn)(const ReturnInfo *pReturnInfo/*,const ReturnValueCollection *pReturnValue*/);

AMBIT_CONFIG_API BOOL ambit_RegisterTechnologyDll();
AMBIT_CONFIG_API bool ambit_InitTestFlow(TCHAR *pTestFlowFileName);
AMBIT_CONFIG_API BOOL ambit_CONNECT_IQ_TESTER(char *pReturnInfo,DWORD bufSize);
AMBIT_CONFIG_API BOOL ambit_DISCONNECT_IQ_TESTER(char *pReturnInfo,DWORD bufSize);
AMBIT_CONFIG_API BOOL ambit_Disconnect_DUT(char *pReturnInfo,DWORD bufSize);
AMBIT_CONFIG_API BOOL ambit_INSERT_DUT(char *pReturnInfo,DWORD bufSize);
AMBIT_CONFIG_API BOOL ambit_INITIALIZE_DUT(char *pReturnInfo,DWORD bufSize);
AMBIT_CONFIG_API void ambit_Run_RF_Test(RF_pfn pfn);
AMBIT_CONFIG_API BOOL ambit_REMOVE_DUT(char *pReturnInfo,DWORD bufSize);
AMBIT_CONFIG_API void GetTestFlow(vector<string> &testflow);

//AMBIT_CONFIG_API BOOL ambit_RegisterTechnologyDll();
//AMBIT_CONFIG_API bool ambit_InitTestFlow(TCHAR *pTestFlowFileName);
//AMBIT_CONFIG_API BOOL ambit_CONNECT_IQ_TESTER(char *pReturnInfo,DWORD bufSize);
//AMBIT_CONFIG_API BOOL ambit_Disconnect_DUT(char *pReturnInfo,DWORD bufSize);
//AMBIT_CONFIG_API BOOL ambit_INSERT_DUT(char *pReturnInfo,DWORD bufSize);
//AMBIT_CONFIG_API BOOL ambit_INITIALIZE_DUT(char *pReturnInfo,DWORD bufSize);
//AMBIT_CONFIG_API void ambit_Run_RF_Test(RF_pfn pfn);
//AMBIT_CONFIG_API BOOL ambit_REMOVE_DUT(char *pReturnInfo,DWORD bufSize);
//AMBIT_CONFIG_API void GetTestFlow(vector<string> &testflow);





#endif
