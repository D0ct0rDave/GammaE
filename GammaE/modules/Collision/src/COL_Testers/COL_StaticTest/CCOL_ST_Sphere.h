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

#ifndef CCOL_ST_Sphere_h
#define CCOL_ST_Sphere_h 1

// GammaE_Math
#include "GammaE_Math.h"
// CCOL_ST_Box
#include "COL_Testers\COL_StaticTest\CCOL_ST_Box.h"

class CCOL_ST_Sphere
{
    public:
        CCOL_ST_Sphere();

        ~CCOL_ST_Sphere();

        static int iTestSphere(CVect3& _oSCenter, float _fSRadius, CVect3& _oDCenter, float _fDRadius);

        static int iTestBox(CVect3& _oSCenter, float _fSRadius, CVect3& _oDMaxs, CVect3& _oDMins);

        static int iTestPoint(CVect3& _oSCenter, float _fSRadius, CVect3& _oDPoint);

        // Additional Public Declarations

    protected:
        // Additional Protected Declarations

    private:
        // Additional Private Declarations

    private:   // Additional Implementation Declarations
};

// Class CCOL_ST_Sphere

#endif
