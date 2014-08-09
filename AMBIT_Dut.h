#ifndef _LP_DUT_H_
#define _LP_DUT_H_


#ifdef LP_DUT_EXPORTS
    #define LP_DUT_API extern "C" __declspec(dllexport)
#else
    #ifdef __cplusplus
        #define LP_DUT_API extern "C" __declspec(dllimport) 
    #else
        #define LP_DUT_API extern
    #endif
#endif



// WiFi DUT DLL needs to export only one function: WIFI_DutRegister()
typedef void (*pfnCmd)(vector<string> &cmdList,bool b);
// WiFi DUT DLL needs to export only one function: WIFI_DutRegister()
LP_DUT_API int WIFI_DutRegister(void);
LP_DUT_API void RegisterCallBackForSingleBand(pfnCmd f);
LP_DUT_API void RegisterCallBackForDualBand(pfnCmd f);
LP_DUT_API void SetFlagForIsSameDut(bool b);


#endif