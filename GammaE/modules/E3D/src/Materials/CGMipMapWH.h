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
#ifndef MipMapWHH
#define MipMapWHH
// ----------------------------------------------------------------------------
#include "GammaE_Misc.h"
#include "CGMipMap.h"
// ----------------------------------------------------------------------------
DECLARE_WAREHOUSE(CGMipMapWH,CGDiskResourceWH,CGMipMap)
{
    public:
        CGMipMapWH();

        virtual CGMipMap* poLoadResource(const CGString& _sFilename);
        void AlternatePath(const CGString& _sAternatePath)
        {
            m_sAlternatePath = _sAternatePath;
        }

    protected:
        CGString m_sAlternatePath;
};
// ----------------------------------------------------------------------------
#endif
// ----------------------------------------------------------------------------
