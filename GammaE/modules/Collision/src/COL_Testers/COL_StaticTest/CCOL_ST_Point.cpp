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

// CCOL_ST_Point
#include "COL_Testers\COL_StaticTest\CCOL_ST_Point.h"

// Class CCOL_ST_Point

CCOL_ST_Point::CCOL_ST_Point()
{
}

CCOL_ST_Point::~CCOL_ST_Point()
{
}

int CCOL_ST_Point::iTestSphere (const CVect3& _oSPoint, const CVect3& _oDCenter, float _fDRadius)
{
    return ( _oSPoint.fSqDistance(_oDCenter) < _SQ_(_fDRadius) );
}

int CCOL_ST_Point::iTestBox (const CVect3& _oSPoint, const CVect3& _oDMaxs, const CVect3& _oDMins)
{
    return ( _oSPoint.bInside(_oDMaxs,_oDMins) );
}

int CCOL_ST_Point::iTestPoint (const CVect3& _oSPoint, const CVect3& _oDPoint)
{
    return ( _oSPoint.bEqual(_oDPoint) );
}

// Additional Declarations
