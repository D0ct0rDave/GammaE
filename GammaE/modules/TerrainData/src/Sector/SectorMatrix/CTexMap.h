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

#ifndef CTexMap_h
#define CTexMap_h 1

// CSectorMatrix
#include "Sector\SectorMatrix\CSectorMatrix.h"
// CSLM_TMapSect
#include "Sector\SectorMatrix\CSectorLoaderManager\CSLM_TMapSect.h"
// CTMSector_8_16
#include "Sector\TexMap\CTMSector_8_16.h"

class CTexMap : public CSectorMatrix
{
    public:
        CTexMap();

        virtual ~CTexMap();

        // Creates a new object of the same class as the current
        // object
        virtual CSector* CreateClass();

        virtual void Init(int _SecsPerRow, int _SecsPerCol, int _SectorRes, int _SectorType, bool _b21);

        // The size of the data from this object
        virtual unsigned long DataSize();

        // Additional Public Declarations

    protected:
        // Additional Protected Declarations

    private:
        // Additional Private Declarations

    private:                    // Additional Implementation Declarations
};

// Class CTexMap

#endif
