//-----------------------------------------------------------------------------
#ifndef CSampleWH_h
#define CSampleWH_h 1
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#include "GammaE_Misc.h"
#include "Sound\CSample.h"

//-----------------------------------------------------------------------------

DECLARE_WAREHOUSE(CSampleWH,CGDiskResourceWH,CSample)
{
    public:
		CSampleWH() : m_uiForcedSRate(22050), m_uiForcedBits(16) {}
	public:

      virtual int iLoad(const CGString& _sFilename,bool _bStream = false);      
      virtual CSample* poLoadResource(const CGString& _sFilename);
      virtual CSample* poLoadResourceExt(const CGString& _sFilename,bool _bStream = false);
      void SetForcedParams (uint _uiForcedSRate, uint _uiForcedBits);
	
	private:
      uint m_uiForcedSRate;
      uint m_uiForcedBits;
};
//-----------------------------------------------------------------------------
#endif
//-----------------------------------------------------------------------------
