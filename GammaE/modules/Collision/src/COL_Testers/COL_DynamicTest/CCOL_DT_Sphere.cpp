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

// CCOL_DT_Sphere
#include "COL_Testers\COL_DynamicTest\CCOL_DT_Sphere.h"
#include "CollisionSystem\CCOL_ColState.h"

// Article by Miguel Gómez Gamasutra

inline bool bQuadraticFormula(float a,float b,float c,float &r1,float &r2)
{
    // ---------------------------------------------------
    // Valid solutions in a quadratic function:
    //         _________
    // -b +- \/b^2 - 4ac
    // -----------------
    // 2a
    // ---------------------------------------------------

    float q = b * b - 4 * a * c;

    if ( q >= 0 )
    {
        float sq = Math::fSqrt(q);
        float d = 1.0f / (2 * a);

        r1 = (-b + sq) * d;
        r2 = (-b - sq) * d;

        return (true);
    }
    else
        return (false);
}

float CCOL_DT_Sphere::fTestSphere (const CGVect3& _oSCenter, float _fSRadius, const CGVect3& _oDCenter, float _fDRadius)
{
    CGVect3 vA;
    CGVect3 vB;
    CGVect3 BA;
    CGVect3 vBA;

    float fRadiiSum;
    float fSqRadiiSum;
    float fSqDist;
    float a,b,c,u0,u1;

    // Radius of separation
    fRadiiSum = _fSRadius + _fDRadius;
    fSqRadiiSum = fRadiiSum * fRadiiSum;

    // Relative position of B from A
    BA.Assign(_oDCenter);
    BA.Sub(_oSCenter);

    // Squared distance between A and B
    fSqDist = BA.fSqModule();

    // Check if they are currently colliding at instant 0
    if ( fSqDist <= fSqRadiiSum )
        return (0.0f);              // Trivial rejection

    // Velocities
    vA.Assign(CCOL_ColState::SrcFPos);
    vA.Sub   (CCOL_ColState::SrcIPos);

    vB.Assign(CCOL_ColState::DstFPos);
    vB.Assign(CCOL_ColState::DstIPos);

    // Get relative speed of B from A
    vBA.Assign(CCOL_ColState::DSSp);
    vBA.Assign(vB);
    vBA.Sub   (vA);

    // u*u coheficient
    a = vBA.fSqModule();
    if ( !a ) return(-1.0f);    // Objects are not moving

    // u coheficient
    b = 2 * vBA.fDotProd(BA);

    // constant term
    c = fSqDist - fSqRadiiSum;

    // Check for collision during dDelta
    if ( bQuadraticFormula(a,b,c,u0,u1) )
    {
        if ( u0 > u1 )
        {
            if ( u1 < 1.0f )
                return (u1);
            else
                return(-1.0f);
        }
        else
        {
            if ( u0 < 1.0f )
                return (u0);
            else
                return(-1.0f);
        }
    }
    else
        return (-1.0f);
}

float CCOL_DT_Sphere::fTestBox (const CGVect3& _oSCenter, float _fSRadius, const CGVect3& _oDMaxs, const CGVect3& _oDMins)
{
    CGVect3 DCenter;
    float DRadius;

    DCenter.Assign(_oDMaxs);
    DCenter.Sub   (_oDMins);
    DRadius = DCenter.fModule() * 0.5f;

    DCenter.Interpolate(_oDMins,_oDMaxs,0.5f);

    return( fTestSphere(_oSCenter,_fSRadius,DCenter,DRadius) );

    /*
       if (CCOL_ST_Sphere::iTestBox(_oSCenter,_fSRadius,_oDMaxs,_oDMins)) return(0.0f);

       CGVect3 vA;
       CGVect3 vB;
       CGVect3 BA;
       CGVect3 vBA;

       float fRadiiSum;
       float fSqRadiiSum;
       float fSqDist;
       float a,b,c,u0,u1;

       CSegment oSeg;
       oSeg.Init(CCOL_ColState::SrcIPos,CCOL_ColState::SrcFPos);

       CGVect3 BoxCenter;
       BoxCenter.Interpolate(_oDMins,_oDMaxs,0.5f);

       CGVect3 SegCenter;
       SegCenter.Interpolate(CCOL_ColState::SrcIPos,
                          CCOL_ColState::SrcFPos,0.5f);

       CGVect3 SegNormal;
       SegNormal.Orthogonal();

       CGVect3 BSCenters;
       BSCenters.Assign( SegCenter );
       BSCenters.Sub   ( BoxCenter );

       // Relative position of B from A
       BA.Assign(_oDCenter);	BA.Sub(_oSCenter);

       // Squared distance between A and B
       fSqDist = BA.SqModule();

       // Check if they are currently colliding at instant 0
       if (fSqDist <= fSqRadiiSum)
        return (0.0f);				// Trivial rejection


       // Velocities
       vA.Assign(CCOL_ColState::SrcFPos);
       vA.Sub   (CCOL_ColState::SrcIPos);

       vB.Assign(CCOL_ColState::DstFPos);
       vB.Assign(CCOL_ColState::DstIPos);


       // Get relative speed of B from A
       vBA.Assign(CCOL_ColState::DSSp);
       vBA.Assign(vB);
       vBA.Sub   (vA);

       // u*u coheficient
       a = vBA.SqModule();
       if (! a) return(-1.0f);	// Objects are not moving
     */
}

float CCOL_DT_Sphere::fTestPoint(const CGVect3& _oSCenter, float _fSRadius, const CGVect3& _oDPoint)
{
    CGVect3 oIPos;
    CGVect3 oSeg;
    float a,b,c,u0,u1;
    float fSqDist;
    float fSqRadii;

    // Get initial position relative to the sphere
    oIPos.Assign(_oDPoint);
    oIPos.Sub   (_oSCenter);

    fSqDist = oIPos.fSqModule();
    fSqRadii = _SQ_(_fSRadius);

    // Test for trivial rejection at instant 0
    c = fSqDist - fSqRadii; // useful later

    if ( c < 0.0f ) // This means that the point is inside the sphere
        return(0.0f);

    // Get final position relative to sphere Ref system
    oSeg.Assign(CCOL_ColState::DSSp);
    oSeg.Scale (CCOL_ColState::fDeltaT);

    a = oSeg.fSqModule();

    b = 2 * oSeg.fDotProd(oIPos);

    // Check for collision during dDelta
    if ( bQuadraticFormula(a,b,c,u0,u1) )
    {
        if ( u0 > u1 )
            return (u1* CCOL_ColState::fDeltaT);
        else
            return (u0* CCOL_ColState::fDeltaT);
    }
    else
        return (-1.0f);
}

// Additional Declarations
