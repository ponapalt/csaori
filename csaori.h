/*
 * csaori.h
 * 
 * written by Ukiya http://ukiya.sakura.ne.jp/
 * based by ���т���l "gethwnd.dll"
 */

#pragma once

#define SAORIAPI extern "C" __declspec(dllexport)

#define SAORICDECL __cdecl

#define WIN32_LEAN_AND_MEAN
#include <windows.h>

#include <string>
#include <vector>
#include <map>

//SAORI INTERFACES
SAORIAPI BOOL SAORICDECL load(HGLOBAL h,long len);
SAORIAPI BOOL SAORICDECL unload();
SAORIAPI HGLOBAL SAORICDECL request(HGLOBAL h,long* len);

//DLLMain
BOOL APIENTRY DllMain( HANDLE hModule, DWORD  ul_reason_for_call, LPVOID lpReserved);

#define SAORI_VERSIONSTRING_10		L"SAORI/1.0"
#define SAORI_VERSIONSTRING			SAORI_VERSIONSTRING_10
#define SAORI_SIZEOFVERSIONSTRING	(sizeof(SAORI_VERSIONSTRING) - 1)

typedef wchar_t char_t;
typedef std::basic_string<char_t> string_t;

typedef enum {CHARSET_Shift_JIS,CHARSET_ISO_2022_JP,CHARSET_EUC_JP,CHARSET_UTF_8} CHARSET;
typedef enum {SAORIRESULT_OK=200,SAORIRESULT_NO_CONTENT=204,SAORIRESULT_BAD_REQUEST=400,SAORIRESULT_INTERNAL_SERVER_ERROR=500} SAORIRESULT;

//global functions
namespace SAORI_FUNC{
	string_t intToString(int num);
	string_t::size_type  getLine(string_t &, const string_t &, string_t::size_type);
	string_t getResultString(int);

	std::string UnicodeToMultiByte(const std::wstring& Source, UINT CodePage=CP_OEMCP, DWORD Flags=0);
	std::wstring MultiByteToUnicode(const std::string& Source, UINT CodePage=CP_OEMCP, DWORD Flags=0);
	UINT CHARSETtoCodePage(CHARSET cset);
	std::wstring CHARSETtoString(CHARSET cset);
}

//Classes
class CSAORIInput{
public:
	CHARSET charset;
	string_t cmd;
	std::vector<string_t> args;
	std::map<string_t,string_t> opts;

	bool parseString(const string_t &src);
};

class CSAORIOutput{
public:
	CHARSET charset;
	SAORIRESULT result_code;
	string_t result;
	std::vector<string_t> values;
	std::map<string_t,string_t> opts;

	string_t toString();
};

class CSAORI{
public:
	CSAORI(){
		setlocale( LC_ALL, "Japanese");
	}

private:
	string_t module_path;

public:
	void setModulePath(const std::string &str);
	std::string request(const std::string &req);

	//�ȉ����������ׂ��֐�
	void exec(const CSAORIInput& in,CSAORIOutput& out);
	bool unload();
	bool load();
};