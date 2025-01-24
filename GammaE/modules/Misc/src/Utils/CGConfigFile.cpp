// ----------------------------------------------------------------------------
#include "CGConfigFile.h"
// ----------------------------------------------------------------------------
#include "libconfig.h"
#include <windows.h>
// ----------------------------------------------------------------------------
CGConfigFile::CGConfigFile(const CGString& _sConfigFile) : m_pConfigObj(NULL)
{
	config_t* poCfg = (config_t*)mAlloc(sizeof(config_t));
	config_init(poCfg);

	if (config_read_file(poCfg, _sConfigFile.szString() ) == 0)
	{
		CGErrorLC::I()->Write("Line %d, %s\n",config_error_line(poCfg),config_error_text(poCfg));
		config_destroy(poCfg);
		mFree(poCfg);

		return;
	}

	m_pConfigObj = poCfg;
}
// ----------------------------------------------------------------------------
CGConfigFile::~CGConfigFile()
{
	if (m_pConfigObj != NULL)
	{
		config_destroy((config_t*)m_pConfigObj);
		mFree(m_pConfigObj);
	}
}
// ----------------------------------------------------------------------------
bool CGConfigFile::bInitialized() const
{
	return(m_pConfigObj != NULL);
}
// ----------------------------------------------------------------------------
CGString CGConfigFile::sGetString(const CGString& _sVar,const CGString& _sDefaultValue) const
{
	if (m_pConfigObj == NULL) return(_sDefaultValue);

	char* szValue = NULL;
	config_lookup_string((config_t*)m_pConfigObj,_sVar.szString(),(const char**)&szValue);

	if (szValue == NULL)
		return( _sDefaultValue );
	else
		return ( CGString(szValue) );
}
// ----------------------------------------------------------------------------
float CGConfigFile::fGetFloat(const CGString& _sVar,float _fDefaultValue) const
{
	if (m_pConfigObj == NULL) return(_fDefaultValue);

	double dValue = 0.0;
	config_lookup_float((config_t*)m_pConfigObj,_sVar.szString(),&dValue);

	return ( dValue );
}
// ----------------------------------------------------------------------------
int CGConfigFile::iGetInteger(const CGString& _sVar,uint _uiDefaultValue) const
{
	if (m_pConfigObj == NULL) return(_uiDefaultValue);

	long lValue = 0;
	config_lookup_int((config_t*)m_pConfigObj,_sVar.szString(),&lValue);

	return( lValue );
}
// ----------------------------------------------------------------------------
bool CGConfigFile::bGetBool(const CGString& _sVar,bool _bDefaultValue) const
{
	if (m_pConfigObj == NULL) return(_bDefaultValue);

	int iValue = 0;
	config_lookup_bool((config_t*)m_pConfigObj,_sVar.szString(),&iValue);

	return ( iValue );
}
// ----------------------------------------------------------------------------
