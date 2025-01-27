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

#ifndef CCOL_ST_Box_h
#define CCOL_ST_Box_h 1

// GammaE_Math
#include "GammaE_Math.h"

class CCOL_ST_Box
{
    public:
        static int iTestSphere(const CGVect3& _oSMaxs, const CGVect3& _oSMins, const CGVect3& _oDCenter, float _fDRadius);

        static int iTestBox(const CGVect3& _oSMaxs, const CGVect3& _oSMins, const CGVect3& _oDMaxs, const CGVect3& _oDMins);

        static int iTestPoint(const CGVect3& _oSMaxs, const CGVect3& _oSMins, const CGVect3& _oDPoint);
};

// Class CCOL_ST_Box

#endif
