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

#ifndef CLightMap_h
#define CLightMap_h 1

// CSectorMatrix
#include "Sector\SectorMatrix\CSectorMatrix.h"
// CSLM_LMapSect
#include "Sector\SectorMatrix\CSectorLoaderManager\CSLM_LMapSect.h"
// CLMSector_RGB24
#include "Sector\LightMap\CLMSector_RGB24.h"

class CLightMap : public CSectorMatrix
{
    public:
        CLightMap();

        ~CLightMap();

        virtual unsigned long DataSize();

        virtual CSector* CreateClass();

        virtual void Init(int _SecsPerRow, int _SecsPerCol, int _SectorRes, int _SectorType, bool _b21);

        // Additional Public Declarations

    protected:
        // Additional Protected Declarations

    private:
        // Additional Private Declarations

    private:                    // Additional Implementation Declarations
};

// Class CLightMap

#endif
