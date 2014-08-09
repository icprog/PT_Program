#ifndef _2345_H_
#define _2345_H_

#ifndef _VersionDll_
#define APIDLL extern "C" __declspec(dllexport)
#else
#define APIDLL extern "C" __declspec(dllimport)
#endif

APIDLL char* _GetVersion();
#endif