//-----------------------------------------------------------------------------
#ifndef MipMapWHH
#define MipMapWHH
//-----------------------------------------------------------------------------
#include "GammaE_Misc.h"
#include "CGMipMap.h"
//-----------------------------------------------------------------------------
DECLARE_WAREHOUSE(CMipMapWH,CGDiskResourceWH,CGMipMap)
{
    public:
		CMipMapWH();

      virtual CGMipMap* poLoadResource(const CGString& _sFilename);
      void AlternatePath(const CGString& _sAternatePath) { m_sAlternatePath = _sAternatePath; }

    protected:
      CGString m_sAlternatePath;
};
//-----------------------------------------------------------------------------
#endif
