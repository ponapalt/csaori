#include "csaori.h"
#include "CInetHelper.h"

bool CSAORI::load()
{
	return true;
}

bool CSAORI::unload()
{
	return true;
}

void CSAORI::exec(const CSAORIInput& in,CSAORIOutput& out)
{
	if (in.args.size() > 0) {
		string oResult;
		string url = SAORI_FUNC::UnicodeToMultiByte(in.args[0], CP_UTF8);
		wstring nResult = L"";
		int getResult = CInetHelper::getUrlContent(url.c_str(),nResult);
		if ( getResult==CIH_FAIL ) {
			out.result_code = SAORIRESULT_INTERNAL_SERVER_ERROR;
			out.result = nResult;
			return;
		} else {
			out.result_code = SAORIRESULT_OK;
			out.result = nResult;
		}
	}
}
