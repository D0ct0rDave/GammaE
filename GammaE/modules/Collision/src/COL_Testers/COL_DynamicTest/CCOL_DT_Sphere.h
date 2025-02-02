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

#ifndef CCOL_DT_Sphere_h
#define CCOL_DT_Sphere_h 1

#include "Gammae_Math.h"

class CCOL_DT_Sphere
{
    public:
        static float fTestSphere(const CGVect3& _oSCenter, float _fSRadius,const CGVect3& _oDCenter, float _fDRadius);

        static float fTestBox(const CGVect3& _oSCenter, float _fSRadius, const CGVect3& _oDMaxs, const CGVect3& _oDMins);

        static float fTestPoint(const CGVect3& _oSCenter, float _fSRadius, const CGVect3& _oDPoint);
};

// Class CCOL_DT_Sphere

#endif
