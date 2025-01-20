#ifndef OSFileH
#define OSFileH

#if defined (WIN32) 
#include "OSFile/COSFileW32.h"
#define OSFILE COSFileW32
#endif

#endif