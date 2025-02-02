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

#ifndef CLensFlare_Elem_h
#define CLensFlare_Elem_h 1

// GammaE_E3D
#include "GammaE_E3D.h"

class CLensFlare_Elem
{
    public:
        CLensFlare_Elem();

        ~CLensFlare_Elem();

        // Data Members for Class Attributes

        float fSize;

        float fDist;

        CGColor Color;

        CGShader* pMaterial;

        // Additional Public Declarations

    protected:
        // Additional Protected Declarations

    private:
        // Additional Private Declarations

    private:                    // Additional Implementation Declarations
};

// Class CLensFlare_Elem

#endif
