#include "CGScriptResourceWH.h"
// ----------------------------------------------------------------------------
CGScriptResource* CGScriptResourceWH::poLoadResource(const CGString& _sFilename)
{
	CGScriptResource* poRes = mNew CGScriptResource;
	
	poRes->SetData(ParseUtils_ReadFile((char*)_sFilename.szString()));
	poRes->Init();
	
	return(poRes);
}
// ----------------------------------------------------------------------------
