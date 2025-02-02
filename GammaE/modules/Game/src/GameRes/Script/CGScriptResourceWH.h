// -----------------------------------------------------------------------------
/*! \class
 *  \brief
 *  \author David M&aacute;rquez de la Cruz
 *  \version 1.5
 *  \date 1999-2009
 *  \par Copyright (c) 1999 David M&aacute;rquez de la Cruz
 *  \par GammaE License
 */
// -----------------------------------------------------------------------------
// ----------------------------------------------------------------------------
#ifndef CGScriptResourceWHH
#define CGScriptResourceWHH
// ----------------------------------------------------------------------------
#include "GammaE_Misc.h"
#include "CGScriptResource.h"
// ----------------------------------------------------------------------------
DECLARE_WAREHOUSE(CGScriptResourceWH,CGDiskResourceWH,CGScriptResource)
{
    public:
        virtual CGScriptResource* poLoadResource(const CGString &_sFilename);
};
// ----------------------------------------------------------------------------
#endif
// ----------------------------------------------------------------------------
