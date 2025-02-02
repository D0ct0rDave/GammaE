// ----------------------------------------------------------------------------
/*! \class
 *  \brief
 *  \author David M&aacute;rquez de la Cruz
 *  \version 1.5
 *  \date 1999-2009
 *  \par Copyright (c) 1999 David M&aacute;rquez de la Cruz
 *  \par GammaE License
 */
// ----------------------------------------------------------------------------
#ifndef MiscUtilsH
#define MiscUtilsH
// ----------------------------------------------------------------------------

#include "Types/CGString.h"

// ----------------------------------------------------------------------------
namespace Utils {
// ----------------------------------------------------------------------------

CGString ExtractFileDir(const CGString& _sFullFilename);
CGString ExtractFileName(const CGString& _sFullFilename);
CGString ExtractShortFileName(const CGString& _sFullFilename);

// ----------------------------------------------------------------------------
}; // namespace Utils
// ----------------------------------------------------------------------------
#endif
// ----------------------------------------------------------------------------
