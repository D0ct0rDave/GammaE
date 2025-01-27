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
#include "COL_Testers\COL_StaticTest\CCOL_ST_Box.h"

int CCOL_ST_Box::iTestSphere (const CGVect3& _oSMaxs, const CGVect3& _oSMins, const CGVect3& _oDCenter, float _fDRadius)
{
    // OPTIMIZABLE!!!

    // Perfoming separating axis test
    float fSqRad = _SQ_(_fDRadius);
    float fDiff;

    for ( int i = 0; i < 3; i++ )
    {
        if ( _oDCenter.v(i) < _oSMins.v(i) )
        {
            fDiff = _oSMins.v(i) - _oDCenter.v(i);
            if ( _SQ_(fDiff) > fSqRad ) return(0);
        }
        else
        {
            if ( _oDCenter.v(i) > _oSMaxs.v(i) )
            {
                fDiff = _oDCenter.v(i) - _oSMaxs.v(i);
                if ( _SQ_(fDiff) > fSqRad ) return(0);
            }
        }
    }

    return(1);
}

int CCOL_ST_Box::iTestBox (const CGVect3& _oSMaxs, const CGVect3& _oSMins, const CGVect3& _oDMaxs, const CGVect3& _oDMins)
{
    // OPTIMIZABLE!!!
    for ( int i = 0; i < 3; i++ )
        if ( ( _oSMins.v(i) > _oDMaxs.v(i) ) || ( _oSMaxs.v(i) < _oDMins.v(i) ) )
            return(0);

    return(1);
}

int CCOL_ST_Box::iTestPoint (const CGVect3& _oSMaxs, const CGVect3& _oSMins, const CGVect3& _oDPoint)
{
    return ( _oDPoint.bInside(_oSMaxs,_oSMins) );
}

