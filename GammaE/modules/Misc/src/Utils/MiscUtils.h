//-----------------------------------------------------------------------------
#ifndef MiscUtilsH
#define MiscUtilsH
//-----------------------------------------------------------------------------

#include "Types/CGString.h"

//-----------------------------------------------------------------------------

CGString ExtractFileDir(const CGString& _sFullFilename);
CGString ExtractFileName(const CGString& _sFullFilename);
CGString ExtractShortFileName(const CGString& _sFullFilename);

//-----------------------------------------------------------------------------
#endif
//-----------------------------------------------------------------------------
