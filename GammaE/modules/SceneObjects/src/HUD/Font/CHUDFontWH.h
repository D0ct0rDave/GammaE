//-----------------------------------------------------------------------------
#ifndef CHUDFontWHH
#define CHUDFontWHH
// ----------------------------------------------------------------------------
#include "GammaE_Misc.h"
#include "CHUDFont.h"
// ----------------------------------------------------------------------------
DECLARE_WAREHOUSE(CHUDFontWH,CGDiskResourceWH,CHUDFont)
{
    public:
		CHUDFontWH(){}

	public:

      virtual CHUDFont* poLoadResource(const CGString &_sFilename);
};
// ----------------------------------------------------------------------------
#endif
// ----------------------------------------------------------------------------
