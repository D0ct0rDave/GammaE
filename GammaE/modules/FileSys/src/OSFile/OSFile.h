// -----------------------------------------------------------------------------
/*! \file OSFile
 *  \brief Platform dependent file class.
 *  \author David M&aacute;rquez de la Cruz
 *  \version 1.5
 *  \date 1999-2009
 *  \par Copyright (c) 1999 David M&aacute;rquez de la Cruz
 *  \par GammaE License
 */
// -----------------------------------------------------------------------------
#ifndef OSFileH
#define OSFileH
// -----------------------------------------------------------------------------

#if defined (WIN32)
    #include "CGOSFileW32.h"
    #define OSFILE CGOSFileW32
#endif

// -----------------------------------------------------------------------------
#endif
// -----------------------------------------------------------------------------
