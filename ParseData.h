#ifdef _dx_parseIQ_data_
#define IQAPIDLL extern "C" __declspec(dllexport)
#else
#define IQAPIDLL extern "C" __declspec(dllimport)
#endif

#ifndef _DX_PARSE_DATA_H_
#define _DX_PARSE_DATA_H_ 
enum ERR_VAL {
	ERR_OK=0,
	ERR_NO_CONFIG_FILE,
	ERR_NO_TEST_ITEM,
};

//5g test by .bat file,use 5gconfig.txt marked test items
IQAPIDLL int _dxGetData5g(char *pReturn, char *pFullFilename);
//2g test by .bat file,use 2gconfig.txt marked test items
IQAPIDLL int _dxGetData2g(char *pReturn, char *pFullFilename);
//2g/5g test by Foxconn old program,use config_f.txt marked test items
IQAPIDLL int _dxGetData_f(char *pReturn, char *pFullFilename);


#endif

/*Change list
20110407	DaiXin create this project
20110411	DaiXin modfiy some bug
			--->Foxcon old program test more time,but log just in one log.So the data to Mydas is more when other
20110809	1.Fa-Hong add "_b" and "_f" after _dxGetData5g()/_dxGetData2g()
			--->U12H189 all test items is test by .bat file.But config.txt which include test items is just surport 5g test by .bat
				So add "_b" marked test by .bat,"_f" marked by foxconn old program	
			2.Fa-Hong change _dxGetData5g()/_dxGetData2g() uded test items config file
			--->Just use .bat test log file need port by 2.4G and 5G  
20110813	1.Fa-Hong at the versify program:find no Power data,add catch Power data
			--->same as TxData/RxData
			2.Fa-Hong at the versify program:find 5G data add more unusefully ","
			--->a.at H189 5G PT log,no state "DISCONNECT_IQ_TESTER",
				  lead program read test item twice(one is testing,another is list test result).
			  so need 1.add "DISCONNECT_IQ_TESTER" at test flow
				      2.at 5gconfig.txt add more information,part "Testing items" and "list result"
				
		

end*/