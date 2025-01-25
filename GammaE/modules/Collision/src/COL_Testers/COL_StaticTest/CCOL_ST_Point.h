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

#ifndef CCOL_ST_Point_h
#define CCOL_ST_Point_h 1

// GammaE_Math
#include "GammaE_Math.h"

class CCOL_ST_Point
{
    public:
        CCOL_ST_Point();

        ~CCOL_ST_Point();

        static int iTestSphere(const CGVect3& _oSPoint, const CGVect3& _oDCenter, float _fDRadius);

        static int iTestBox(const CGVect3& _oSPoint, const CGVect3& _oDMaxs, const CGVect3& _oDMins);

        static int iTestPoint(const CGVect3& _oSPoint, const CGVect3& _oDPoint);

        // Additional Public Declarations

    protected:
        // Additional Protected Declarations

    private:
        // Additional Private Declarations

    private:   // Additional Implementation Declarations
};

// Class CCOL_ST_Point

#endif
