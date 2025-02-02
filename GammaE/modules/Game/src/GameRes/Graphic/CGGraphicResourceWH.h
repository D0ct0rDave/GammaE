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
#ifndef CGGraphicResourceWHH
#define CGGraphicResourceWHH
// ----------------------------------------------------------------------------
#include "GammaE_Misc.h"
#include "CGGraphicResource.h"
// ----------------------------------------------------------------------------
DECLARE_WAREHOUSE(CGGraphicResourceWH,CGDiskResourceWH,CGGraphicResource)
{
    public:
        virtual CGGraphicResource* poLoadResource(const CGString &_sFilename);
};
// ----------------------------------------------------------------------------
#endif
// ----------------------------------------------------------------------------
