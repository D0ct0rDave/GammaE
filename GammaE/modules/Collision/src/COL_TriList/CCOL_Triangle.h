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

#ifndef CCOL_Triangle_h
#define CCOL_Triangle_h 1

// GammaE_Math
#include "GammaE_Math.h"
class CCOL_Triangle
{
    public:
        CCOL_Triangle();

        ~CCOL_Triangle();

        // Data Members for Class Attributes

        CGVect3 oVXs[3];

        CGVect3 oVN;

        int iMat;

        float fDelta;

        // Additional Public Declarations

    protected:
        // Additional Protected Declarations

    private:
        // Additional Private Declarations

    private:   // Additional Implementation Declarations
};

// Class CCOL_Triangle
#endif
