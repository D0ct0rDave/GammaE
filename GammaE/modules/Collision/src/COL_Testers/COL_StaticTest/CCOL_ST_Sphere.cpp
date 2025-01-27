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

#include "COL_Testers\COL_StaticTest\CCOL_ST_Sphere.h"

int CCOL_ST_Sphere::iTestSphere (const CGVect3& _oSCenter, float _fSRadius, const CGVect3& _oDCenter, float _fDRadius)
{
    if ( _oSCenter.fSqDistance(_oDCenter) < _SQ_(_fSRadius + _fDRadius) )
        return(1);
    else
        return(0);
}

int CCOL_ST_Sphere::iTestBox (const CGVect3& _oSCenter, float _fSRadius, const CGVect3& _oDMaxs, const CGVect3& _oDMins)
{
    return ( CCOL_ST_Box::iTestSphere(_oDMaxs,_oDMins,_oSCenter,_fSRadius) );
}

int CCOL_ST_Sphere::iTestPoint (const CGVect3& _oSCenter, float _fSRadius, const CGVect3& _oDPoint)
{
    return ( _oDPoint.fSqDistance(_oSCenter) < _SQ_(_fSRadius) );
}

