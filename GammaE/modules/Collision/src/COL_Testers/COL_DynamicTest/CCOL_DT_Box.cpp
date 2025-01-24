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

// CCOL_DT_Box
#include "COL_Testers\COL_DynamicTest\CCOL_DT_Box.h"

int CCOL_DT_Box::iColAxis = 0;

#define     NOCOLLISION_TIME     1.0f

// -----------------------------------------------------------------------------
static bool bClip (float _fDenom, float _fNumer, float& _fT0, float& _fT1)
{
    // Return value is 'true' if line segment intersects the current test
    // plane.  Otherwise 'false' is returned in which case the line segment
    // is entirely clipped.

    if ( _fDenom > 0.0f )
    {
        if ( _fNumer > _fDenom * _fT1 )
            return(false);

        if ( _fNumer > _fDenom * _fT0 )
            _fT0 = _fNumer / _fDenom;

        return(true);
    }
    else if ( _fDenom < 0.0f )
    {
        if ( _fNumer > _fDenom * _fT0 )
            return (false);

        if ( _fNumer > _fDenom * _fT1 )
            _fT1 = _fNumer / _fDenom;

        return(true);
    }
    else
    {
        return (_fNumer <= 0.0f);
    }
}
// -----------------------------------------------------------------------------
bool bFindIntersection (CVect3& _oOrigin,CVect3& _oDir,CVect3& _oExt,float &_fT0,float &_fT1)
{
    float fSaveT0 = _fT0, fSaveT1 = _fT1;

    bool bNotEntirelyClipped =
        bClip(+_oDir.x,-_oOrigin.x - _oExt.x,_fT0,_fT1) &&
        bClip(-_oDir.x,+_oOrigin.x - _oExt.x,_fT0,_fT1) &&
        bClip(+_oDir.y,-_oOrigin.y - _oExt.y,_fT0,_fT1) &&
        bClip(-_oDir.y,+_oOrigin.y - _oExt.y,_fT0,_fT1) &&
        bClip(+_oDir.z,-_oOrigin.z - _oExt.z,_fT0,_fT1) &&
        bClip(-_oDir.z,+_oOrigin.z - _oExt.z,_fT0,_fT1);

    return ( bNotEntirelyClipped &&
            ( (_fT0 != fSaveT0) || (_fT1 != fSaveT1) ) );
}
// -----------------------------------------------------------------------------

// Class CCOL_DT_Box

CCOL_DT_Box::CCOL_DT_Box()
{
}

CCOL_DT_Box::~CCOL_DT_Box()
{
}

float CCOL_DT_Box::fTestSphere (CVect3& _oSMaxs, CVect3& _oSMins, CVect3& _oDCenter, float _fDRadius)
{
    CVect3 DMaxs,DMins;

    // Setup destination bounding box
    DMaxs.Assign( _oDCenter );
    DMaxs.Add   (_fDRadius,_fDRadius,_fDRadius);

    DMins.Assign( _oDCenter );
    DMins.Sub   (_fDRadius,_fDRadius,_fDRadius);

    return( fTestBox(_oSMaxs,_oSMins,DMaxs,DMins) );
}

float CCOL_DT_Box::fTestBox (CVect3& _oSMaxs, CVect3& _oSMins, CVect3& _oDMaxs, CVect3& _oDMins)
{
    // Check if they were colliding in the previous frame
    if ( CCOL_ST_Box::iTestBox(_oSMaxs,_oSMins,_oDMaxs,_oDMins) ) return(0.0f);

    int i;
    CVect3 vA;
    CVect3 vB;
    CVect3 vBA;
    CVect3 u0,u1;
    float fU0,fU1;

    // Velocities
    vA.Assign(CCOL_ColState::SrcFPos);  // Traversed space in the current frame time
    vA.Sub   (CCOL_ColState::SrcIPos);

    vB.Assign(CCOL_ColState::DstFPos);  // Traversed space in the current delta time
    vB.Sub   (CCOL_ColState::DstIPos);

    // Get relative speed of B from A
    vBA.Assign(vB);
    vBA.Sub   (vA);

    // The objects could only collide if their velocities are different
    // vBA != (0,0,0);
    // if (vBA = (0,0,0)) the objects could only collide if at time 0 are
    // colliding. At this time the object hadn't collided due to the first
    // test.
    if ( (vBA.x == 0) && (vBA.y == 0) && (vBA.z == 0) ) return(NOCOLLISION_TIME);

    // First time of overlap along each axis
    u0.V3(-1.0f,-1.0f,-1.0f);
    // Last time of overlap along each axis
    u1.V3(1.0f,1.0f,1.0f);

    // Find the possible first and last times of overlap along each axis
    for ( i = 0; i < 3; i++ )
    {
        // max   min
        // |-a-|     |-b-|
        if ( _oSMaxs.v(i) <= _oDMins.v(i) )   // A
        {
            if ( vBA.v(i) < 0.0f )
            {
                // max   min
                // |-a-|     |-b-|
                // <--
                u0.v(i) = ( _oSMaxs.v(i) - _oDMins.v(i) ) / vBA.v(i);
            }
            else
            {
                return(NOCOLLISION_TIME);
            }
        }
        // max   min
        // |-b-|     |-a-|
        else if ( _oDMaxs.v(i) <= _oSMins.v(i) )
        {
            if ( vBA.v(i) > 0.0f )
            {
                // max   min
                // |-b-|     |-a-|
                // -->
                u0.v(i) = ( _oSMins.v(i) - _oDMaxs.v(i) ) / vBA.v(i);
            }
            else
            {
                return(NOCOLLISION_TIME);
            }
        }

        // last time overlap
        if ( ( _oDMaxs.v(i) < _oSMins.v(i) ) && (vBA.v(i) < 0.0f) )
        {
            u1.v(i) = ( _oSMins.v(i) - _oDMaxs.v(i) ) / vBA.v(i);
        }
        else if ( ( _oSMaxs.v(i) > _oDMins.v(i) ) && (vBA.v(i) > 0.0f) )
        {
            u1.v(i) = ( _oSMaxs.v(i) - _oDMins.v(i) ) / vBA.v(i);
        }
    }

    if ( u0.v(0) > u0.v(1) )
    {
        if ( u0.v(0) > u0.v(2) )
        {
            // 0 > 1  && 0 > 2
            fU0 = u0.v(0);
            iColAxis = 0;
        }
        else
        {
            // 0 > 1 && 2 > 0
            fU0 = u0.v(2);
            iColAxis = 2;
        }
    }
    else
    {
        if ( u0.v(1) > u0.v(2) )
        {
            // 1 > 0  && 1 > 2
            fU0 = u0.v(1);
            iColAxis = 1;
        }
        else
        {
            // 1 > 0 && 2 > 1
            fU0 = u0.v(2);
            iColAxis = 2;
        }
    }

    if ( u1.v(0) < u1.v(1) )
    {
        if ( u1.v(0) < u1.v(2) )
            // 0 < 1 && 0 < 2
            fU1 = u1.v(0);
        else
            // 0 < 1 && 2 < 0
            fU1 = u1.v(2);
    }
    else
    {
        if ( u1.v(1) < u1.v(2) )
            // 1 < 0 && 1 < 2
            fU1 = u1.v(1);
        else
            // 1 < 0 && 2 < 1
            fU1 = u1.v(2);
    }

    if ( (fU0 <= fU1) && (fU0 < NOCOLLISION_TIME) )
    {
        return(fU0);
    }
    else
        return(NOCOLLISION_TIME);

    /*
       // Miguel Gomez algorithm

       int i;
       for (i=0;i<3;i++)
       {
        // u0 times: Compute firsts times of colision
        if ((_SMaxs.v(i) < _DMins.v(i)) && (vBA.v(i)<0.0f))
        {
            u0.v(i) = (_SMaxs.v(i) - _DMins.v(i)) / vBA.v(i);
        }

       else if ((_DMaxs.v(i) < _SMins.v(i)) && (vBA.v(i)>0.0f))
        {
            u0.v(i) = (_SMins.v(i) - _DMaxs.v(i)) / vBA.v(i);
        }

        // u1 times: Compute lasts times of colision
        if ((_DMaxs.v(i) > _SMins.v(i)) && (vBA.v(i)<0.0f))
        {
            u1.v(i) = (_SMins.v(i) - _DMaxs.v(i)) / vBA.v(i);
        }
       else if ((_SMaxs.v(i) > _DMins.v(i)) && (vBA.v(i)>0.0f))
        {
            u1.v(i) = (_SMaxs.v(i) - _DMins.v(i)) / vBA.v(i);
        }
       }

       MATH_Utils::GetMaxMins(u0.x,u0.y,u0.z,fU0,fAux);
       MATH_Utils::GetMaxMins(u1.x,u1.y,u1.z,fAux,fU1);

       // if the first time of overlap happens after last time of overlap
       // the object have not collided

       if (fU0 > fU1) return(-1.0f);
       if (fU0==0.0f) return(-1.0f);
       return(fU0);
     */
}

float CCOL_DT_Box::fTestPoint (CVect3& _oSMaxs, CVect3& _oSMins, CVect3& _oDPoint)
{
    if ( CCOL_ST_Box::iTestPoint(_oSMaxs,_oSMins,_oDPoint) )
        return(0.0f);

    // Based on Magic Software, Inc.
    // http://www.magic-software.com
    // Copyright (c) 2000, 2001.  All Rights Reserved

    // convert segment to box coordinates and test:
    // Vector3 kDiff = rkSegment.Origin() - rkBox.Center(); == oPI
    // Vector3 kOrigin(kDiff.Dot(rkBox.Axis(0)),kDiff.Dot(rkBox.Axis(1)),kDiff.Dot(rkBox.Axis(2)));
    // rkBox.Axis(0) = (1,0,0) rkBox.Axis(1) = (0,1,0) ..., then rkOrigin = kDiff = oPI

    // Vector3 kDirection(rkSegment.Direction().Dot(rkBox.Axis(0)),
    // rkSegment.Direction().Dot(rkBox.Axis(1)),rkSegment.Direction().Dot(rkBox.Axis(2)));
    // Same for segment direction

    // El segmento tiene como vector director respecto al sistema de coordenadas de la caja
    // el mismo vector velocidad de Dst respecto a Src, es decir, CCOL_ColState::DSSp

    CVect3 oPI;     // Initial Point
    CVect3 oBoxC;   // Box center
    CVect3 oBExt;   // Box extents

    // Compute box center
    oBoxC.Interpolate(_oSMaxs,_oSMins,0.5f);

    // Point initial position in Box Ref system
    oPI.Assign(_oDPoint);
    oPI.Sub(oBoxC);

    // Compute box extents
    oBExt.Assign(_oSMaxs);
    oBExt.Sub   (_oSMins);
    oBExt.Scale (0.5f);

    float fT0 = 0.0f, fT1 = 1.0f;

    if ( bFindIntersection(oPI,CCOL_ColState::DSSp,oBExt,fT0,fT1) )
        return(fT0);
    else
        return(-1.0f);
}

// Additional Declarations
