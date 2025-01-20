// ----------------------------------------------------------------------------
#include <assert.h>
#include <string.h>
#include "GammaE_Mem.h"
#include "SampleUtils/SampleUtils.h"
// ----------------------------------------------------------------------------
#ifdef _DEBUG
typedef struct{
	char FN[1024][256];
	int  iNumFiles;
}TFileList;
extern TFileList oFileList;
#endif
// ----------------------------------------------------------------------------
#include "Sound\CSampleWH.h"
// ----------------------------------------------------------------------------
CSample* CSampleWH::poLoadResourceExt(const CGString& _sFilename,bool _bStream)
{
	CSample *poSam = SampleUtils_LoadSample((char*)_sFilename.szString(),_bStream);
	if (poSam == NULL) return(NULL);

	// Reformat sample according to sound system specification
	SampleUtils_ConvertSample(poSam,poSam->iChannels,m_uiForcedBits,m_uiForcedSRate);

	// Return object
	return ( poSam );
}
// ----------------------------------------------------------------------------
CSample* CSampleWH::poLoadResource(const CGString& _sFilename)
{
	return ( poLoadResourceExt(_sFilename,false) );
}
// ----------------------------------------------------------------------------
int CSampleWH::iLoad(const CGString& _sFilename,bool _bStream)
{
	// Search for the file
	CSample* poObj = m_oWH.oGetVar(_sFilename);
	if (poObj == NULL)
	{
		CSample* poRes = poLoadResourceExt(_sFilename,_bStream);

		if (poRes != NULL)
			return(-1);

		return( this->uiAdd(poRes,_sFilename) );		// http://www.parashift.com/c++-faq-lite/templates.html#faq-35.19
	}
	else
	{
		return ( m_oWH.iGetElemIdx( poObj ) );
	}
}
// ----------------------------------------------------------------------------
void CSampleWH::SetForcedParams (uint _uiForcedSRate, uint _uiForcedBits)
{
	m_uiForcedSRate= _uiForcedSRate;
	m_uiForcedBits = _uiForcedBits;
}
// ----------------------------------------------------------------------------