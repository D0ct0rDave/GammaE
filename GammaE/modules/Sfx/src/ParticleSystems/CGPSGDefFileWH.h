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
#ifndef CGPSGDefFileWHH
#define CGPSGDefFileWHH
// ----------------------------------------------------------------------------
#include "GammaE_Misc.h"
// ----------------------------------------------------------------------------
DECLARE_WAREHOUSE(CGPSGDefFileWH,CGDiskResourceWH,CGTextResource)
{
    public:
        virtual CGTextResource* poLoadResource(const CGString& _sFilename);
        virtual void Reload();

    private:

        void ProcessPSGDefFile(const CGString &_sPSGDefFilename);
};
// ----------------------------------------------------------------------------
#endif
// ----------------------------------------------------------------------------
