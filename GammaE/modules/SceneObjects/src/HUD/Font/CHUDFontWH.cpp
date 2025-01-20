//-----------------------------------------------------------------------------
#include "CHUDFontWH.h"
//-----------------------------------------------------------------------------
CHUDFont* CHUDFontWH::poLoadResource(const CGString &_sFilename)
{
	// Try top initialize the font
	CHUDFont* poFont = mNew CHUDFont;
	if (! poFont->bInit( _sFilename.szString() ))
	{
		mDel poFont;
		return (NULL);
	}

	return(poFont);
}
//-----------------------------------------------------------------------------