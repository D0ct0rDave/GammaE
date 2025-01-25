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

#ifndef CCorona_h
#define CCorona_h 1

// GammaE_E3D
#include "GammaE_E3D.h"

class CCorona
{
    public:
        CCorona();

        ~CCorona();

        // Data Members for Class Attributes

        CGColor oColor;

        CGShader* poMat;

        CGVect3 oPos;

        float fXYSize;

        // Additional Public Declarations

    protected:
        // Additional Protected Declarations

    private:
        // Additional Private Declarations

    private:                    // Additional Implementation Declarations
};

// Class CCorona

#endif
