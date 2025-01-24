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
#ifndef CGPathDefinitionFileWHH
#define CGPathDefinitionFileWHH
// ----------------------------------------------------------------------------
#include "GammaE_Misc.h"
// ----------------------------------------------------------------------------
DECLARE_WAREHOUSE(CGPathDefinitionFileWH,CGDiskResourceWH,CGTextResource)
{
    public:
        virtual CGTextResource* poLoadResource(const CGString &_sFilename);

    protected:
        void ProcessPathDefFile(const CGString &_sPathDefFilename);
};
// ----------------------------------------------------------------------------
#endif
// ----------------------------------------------------------------------------
