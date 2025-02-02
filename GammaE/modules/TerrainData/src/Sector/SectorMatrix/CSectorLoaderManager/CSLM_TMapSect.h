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
// %X% %Q% %Z% %W%

#ifndef CSLM_TMapSect_h
#define CSLM_TMapSect_h 1

// CSectorLoaderManager
#include "Sector\SectorMatrix\CSectorLoaderManager\CSectorLoaderManager.h"
// CTMSector_8_16
#include "Sector\TexMap\CTMSector_8_16.h"

class CSLM_TMapSect : public CSectorLoaderManager
{
    public:
        CSLM_TMapSect();

        ~CSLM_TMapSect();

        virtual CSector* poCreateClass(FILE* _FD);

        // Additional Public Declarations

    protected:
        // Additional Protected Declarations

    private:
        // Additional Private Declarations

    private:                    // Additional Implementation Declarations
};

// Class CSLM_TMapSect

#endif
