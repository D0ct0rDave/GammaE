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

#ifndef CSLM_HFieldSect_h
#define CSLM_HFieldSect_h 1

// CHFSector_FN
#include "Sector\HeightField\CHFSector_FN.h"
// CSectorLoaderManager
#include "Sector\SectorMatrix\CSectorLoaderManager\CSectorLoaderManager.h"

class CSLM_HFieldSect : public CSectorLoaderManager
{
    public:
        CSLM_HFieldSect();

        ~CSLM_HFieldSect();

        virtual CSector* poCreateClass(FILE* _FD);

        // Additional Public Declarations

    protected:
        // Additional Protected Declarations

    private:
        // Additional Private Declarations

    private:                    // Additional Implementation Declarations
};

// Class CSLM_HFieldSect

#endif
