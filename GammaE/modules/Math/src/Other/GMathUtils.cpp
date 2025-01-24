// ----------------------------------------------------------------------------
/*! \class
 *  \brief
 *  \author David M&aacute;rquez de la Cruz
 *  \version 1.5
 *  \date 1999-2009
 *  \par Copyright (c) 1999 David M&aacute;rquez de la Cruz
 *  \par GammaE License
 */
// ----------------------------------------------------------------------------
#include <math.h>
// ----------------------------------------------------------------------------
const float EPSILON = 1e-5f;
const float ONE_oPLUS_EPSILON = 1.0f + EPSILON;
// ----------------------------------------------------------------------------
#include "Other\GMathUtils.h"
#include "Other\GMathCommon.h"
#include "Vector\CGVect3.h"
// ----------------------------------------------------------------------------
namespace Math {
// ----------------------------------------------------------------------------
static float fU;
static float fV;
static float fT;
static float fDet;
static float fInvDet;
static CGVect3 PVec,TVec,QVec;
// ----------------------------------------------------------------------------
void GetPNVertexs (const CGVect3& _oMaxs, const CGVect3& _oMins, const CGPlane& _oPlane, CGVect3& P, CGVect3& N)
{
    if ( _oPlane.oGetNormal().z > 0 )
    {
        if ( _oPlane.oGetNormal().y > 0 )
        {
            if ( _oPlane.oGetNormal().x > 0 )
            {
                P = _oMaxs;
                N = _oMins;
            }
            else
            {
                P.Set( _oMins.x,_oMaxs.y,_oMaxs.z );
                N.Set( _oMaxs.x,_oMins.y,_oMins.z );
            }
        }
        else
        {
            if ( _oPlane.oGetNormal().x > 0 )
            {
                P.Set(_oMaxs.x,_oMins.y,_oMaxs.z );
                N.Set(_oMins.x,_oMaxs.y,_oMins.z );
            }
            else
            {
                P.Set(_oMins.x,_oMins.y,_oMaxs.z );
                N.Set(_oMaxs.x,_oMaxs.y,_oMins.z );
            }
        }
    }
    else
    {
        if ( _oPlane.oGetNormal().y > 0 )
        {
            if ( _oPlane.oGetNormal().x > 0 )
            {
                P.Set(_oMaxs.x,_oMaxs.y,_oMins.z);
                N.Set(_oMins.x,_oMins.y,_oMaxs.z);
            }
            else
            {
                P.Set(_oMins.x,_oMaxs.y,_oMins.z);
                N.Set(_oMaxs.x,_oMins.y,_oMaxs.z);
            }
        }
        else
        {
            if ( _oPlane.oGetNormal().x > 0 )
            {
                P.Set(_oMaxs.x,_oMins.y,_oMins.z);
                N.Set(_oMins.x,_oMaxs.y,_oMaxs.z);
            }
            else
            {
                P = _oMins;
                N = _oMaxs;
            }
        }
    }
}
// ----------------------------------------------------------------------------
int iTestBoxPlane (const CGVect3& _Maxs, const CGVect3& _Mins, const CGPlane& _oPlane)
{
    CGVect3 P,N;

    // Get PN vertices
    GetPNVertexs (_Maxs,_Mins,_oPlane,P,N);

    // Compute plane distance to a point
    if ( _oPlane.fGetDistanceToPoint(N) > 0.0f ) return(1);       // front
    if ( _oPlane.fGetDistanceToPoint(P) < 0.0f ) return(-1);      // back
    return (0);                                                   // Intersecting
}
// ----------------------------------------------------------------------------
int iTestSpherePlane (const CGVect3& _Center, float _fRadius, const CGPlane& _oPlane)
{
    float fDist = _oPlane.fGetDistanceToPoint(_Center);

    if ( fDist > _fRadius ) return(1);          // in front of plane
    else
    if ( fDist < -_fRadius ) return(-1);        // back of the plane
    return(0);                                    // intersecting
}
// ----------------------------------------------------------------------------
int iTestPointPlane (const CGVect3& _oPoint, const CGPlane& _oPlane)
{
    return ( (int)_oPlane.fGetDistanceToPoint(_oPoint) );
}
// ----------------------------------------------------------------------------
float fTriPointDistance (const CGTriangle& _oTri, const CGVect3& _oPoint)
{
    return ( fSqrt( fTriPointSqDistance(_oTri,_oPoint) ) );
}
// ----------------------------------------------------------------------------
float fTriPointSqDistance (const CGTriangle& _oTri, const CGVect3& _oPoint)
{
    CGVect3 oPnt = oNearestTriPoint(_oPoint,_oTri);
    return ( _oPoint.fSqDistance(oPnt) );
}
// ----------------------------------------------------------------------------
CGVect3 oNearestTriPoint (const CGVect3& _oPoint, const CGTriangle& _oTri)
{
    CGPlane oPlane;
    float fMu,fLambda;
    CGVect3 cp;
    CGVect3 c;

    oPlane.GeneratePlaneFromFields(_oTri.VXs[0],_oTri.Normal);
    c = oPlane.oProjectPoint(_oPoint);

    // Get vector c - p
    cp.Assign(c);
    cp.Sub   (_oTri.VXs[0]);

    if ( _oTri.e2.x != 0.0f )
    {
        float fAux = _oTri.e2.y / _oTri.e2.x;
        fMu = (cp.y - cp.x * fAux) / (_oTri.e1.y - _oTri.e1.x * fAux);
        fLambda = (cp.x - fMu * _oTri.e1.x) / _oTri.e2.x;
    }
    else
    {
        // float fAux = Tri.E2[0] / Tri.E2[1] = 0.0f / Tri.E2[1] = 0.0f;
        // fMu     = (cp[0] - cp[1]*fAux   )/(Tri.E1[0] - Tri.E1[1]*fAux);
        // fMu     = (cp[0] - cp[1]*0.0f   )/(Tri.E1[0] - Tri.E1[1]*0.0f);
        // fMu     = (cp[0]                  )/(Tri.E1[0]                   );
        fMu = cp.x / _oTri.e1.x;
        fLambda = (cp.y - fMu * _oTri.e1.y) / _oTri.e2.y;
    }

    // --------------
    // Select region:
    // --------------
    CGSegment oSeg;
    if ( fMu < 0.0f )
    {
        if ( fLambda <= 0.0f )
        {
            // Region A
            return (_oTri.VXs[0]);
        }
        else
        {
            if ( fLambda >= 1.0f )
                // Region E
                return (_oTri.VXs[2]);
            else
                // Region fGetD
                c.Interpolate(_oTri.VXs[0],_oTri.VXs[2],fLambda);
            return(c);
        }
    }
    else
    {
        if ( fLambda < 0.0f )
        {
            if ( fMu > 1.0f )
            {
                // Region C
                return(_oTri.VXs[1]);
            }
            else
            {
                // Region B

                // fMu >0.0f,fMu <1.0f
                c.Interpolate(_oTri.VXs[0],_oTri.VXs[1],fMu);
                return(c);
            }
        }
        else
        {
            // Region F
            if ( fMu + fLambda > 1.0f )
            {
                CGSegment oSeg;
                oSeg.Init(_oTri.VXs[1],_oTri.VXs[2]);
                return ( oSeg.ProjectPoint(c) );
            }
            else
            {
                // Region C
                return(c);
            }
        }
    }
}
// ----------------------------------------------------------------------------
int iTestRayTriIntersection (const CGRay& _oRay, const CGTriangle& _oTri)
{
    // Mirar si el punto cae dentro del triangulo

    /* Ray-Triangle Intersection Test Routine           */
    /* Different optimizations of my and Ben Trumbore's */
    /* code from journals of graphics tools (JGT)       */
    /* http://www.acm.org/jgt/                          */
    /* by Tomas Möller, May 2000                        */

    /* code rewritten to do tests on the sign of the determinant */
    /* the division is before the test of the sign of the det    */

    /* find vectors for two edges sharing vert0 */

    /*
       _oTri.e0;
       _oTri.e1;
     */
/*
    e1.Assign(_oTri.VXs[1]);	e1.Sub(_oTri.VXs[0]);
    e2.Assign(_oTri.VXs[2]);	e2.Sub(_oTri.VXs[0]);
 */
    /* begin calculating determinant - also used to calculate U parameter */
    PVec.CrossProd(_oRay.Dir,_oTri.e2);

    /* if determinant is near zero, ray lies in plane of triangle */
    // fDet = e1.DotProd(PVec);
    fDet = _oTri.e1.fDotProd(PVec);

    // Avoid divide by 0
    if ( fDet > -EPSILON && fDet < EPSILON ) return(0);

    // NOTE: The better approach of Tomar Möller in the intersection algorithm
    // uses a if statement wich implies conditional branching prediction misses
    // instead of this is preferable to perform the inverse multiplication of
    // fU and fV factors and compare against (0,1) range of values instead of
    // fU>0.0 and fu<fDet orfU<0.0 and fU >fDet when fDet is negative
    fInvDet = 1.0f / fDet;

    // calculate distance from vert0 to ray origin
    TVec.Assign(_oRay.Origin);
    TVec.Sub(_oTri.VXs[0]);

    // calculate U parameter and test bounds
    fU = TVec.fDotProd(PVec) * fInvDet;
    if ( fU < -EPSILON || fU > ONE_oPLUS_EPSILON ) return(0);

    // prepare to test V parameter
    // QVec.CrossProd(TVec,e1);
    QVec.CrossProd(TVec,_oTri.e1);

    // calculate V parameter and test bounds
    fV = _oRay.Dir.fDotProd(QVec) * fInvDet;
    if ( fV < -EPSILON || fU + fV > ONE_oPLUS_EPSILON ) return(0);

    return(1);
}
// ----------------------------------------------------------------------------
int iTestRayTriIntersection (const CGRay& _oRay, const CGTriangle& _oTri, CGVect3* _poPoint)
{
    if ( iTestRayTriIntersection(_oRay,_oTri) )
    {
        // calculate t, ray intersects triangle
        fT = _oTri.e2.fDotProd(QVec) * fInvDet;

        _poPoint->LineEq(_oRay.Origin,_oRay.Dir,fT);
        return(1);
    }
    else
        return(0);
}
// ----------------------------------------------------------------------------
int iTestSegTriIntersection (const CGRay& _oRay, const CGTriangle& _oTri)
{
    if ( iTestRayTriIntersection (_oRay, _oTri) )
    {
        // calculate t, ray intersects triangle
        fT = _oTri.e2.fDotProd(QVec) * fInvDet;

        return(fT >= 0.0f);                 // above the point of origin
    }

    return(0);
}
// ----------------------------------------------------------------------------
int iTestSegTriIntersection (const CGRay& _oRay, const CGTriangle& _oTri, CGVect3* _poPoint)
{
    if ( iTestSegTriIntersection(_oRay,_oTri) )
    {
        _poPoint->LineEq(_oRay.Origin,_oRay.Dir,fT);
        return(1);
    }
    return(0);
}

float fGetT ()
{
    return(fT);
}
// ----------------------------------------------------------------------------
int iPointInsideTriangle (const CGTriangle& _oTri, const CGVect3& _oPoint, const CGVect3& _oPPoint)
{
    CGRay Ray;

    Ray.Origin.Assign(_oPoint);
    Ray.Dir.Assign   (_oTri.Normal);

    return ( iTestRayTriIntersection (Ray, _oTri,_oPPoint) );
}
// ----------------------------------------------------------------------------
int iPointInsideTriangle (const CGTriangle& _oTri, const CGVect3& _oPoint)
{
    CGRay Ray;

    Ray.Origin.Assign(_oPoint);
    Ray.Dir.Assign   (_oTri.Normal);

    return ( iTestRayTriIntersection (Ray,_oTri) );
}
// ----------------------------------------------------------------------------
int iTest3PlaneIntersection (const CGPlane& _oPlane0, const CGPlane& _oPlane1, const CGPlane& _oPlane2, CGVect3* _poPoint)
{
    float fDet;
    CGMatrix4x4 oMat;
    CGVect3 a,b,c,p;

    // Setup matrix
    oMat.SetRow( 0,_oPlane0.oGetNormal().x,_oPlane0.oGetNormal().y,_oPlane0.oGetNormal().z,-1.0f * _oPlane0.fGetD() );
    oMat.SetRow( 1,_oPlane1.oGetNormal().x,_oPlane1.oGetNormal().y,_oPlane1.oGetNormal().z,-1.0f * _oPlane1.fGetD() );
    oMat.SetRow( 2,_oPlane2.oGetNormal().x,_oPlane2.oGetNormal().y,_oPlane2.oGetNormal().z,-1.0f * _oPlane2.fGetD() );
    oMat.SetRow(3,0.0f,0.0f,0.0f,1.0f);

    // Compute matrix determinant
    fDet = oMat.f3ColDeterminant(0,1,2);

    // Planes are linear dependent
    if ( fAbs(fDet) < _EPSILON_ ) return(0);

    a.CrossProd( _oPlane1.oGetNormal(),_oPlane2.oGetNormal() );
    a.Scale( -1.0f * _oPlane0.fGetD() );

    b.CrossProd( _oPlane2.oGetNormal(),_oPlane0.oGetNormal() );
    b.Scale( -1.0f * _oPlane1.fGetD() );

    c.CrossProd( _oPlane0.oGetNormal(),_oPlane1.oGetNormal() );
    c.Scale( -1.0f * _oPlane2.fGetD() );

    // Setup intersection point
    _poPoint->Assign(a);
    _poPoint->Add   (b);
    _poPoint->Add   (c);
    _poPoint->Scale (1.0f / fDet);

    return(1);
}
// ----------------------------------------------------------------------------
int iTest2PlaneIntersection (const CGPlane& _oPlane0, const CGPlane& _oPlane1, const CGRay& _oRay)
{
    /*
       Vector3d m, pt0;
       float demn;

       if ((plane2.GetNorm()).IsParallel(GetNorm()))
       return false;

       m.CrossVector(GetNorm(), plane2.GetNorm());
       // Sanity Check.
       ASSERT(m.GetMag() > 0.0f);

       float dx = ABS(m.GetX());
       float dy = ABS(m.GetY());
       float dz = ABS(m.GetZ());

       if (dx >= dy && dx >= dz) {
       ASSERT(!EQUAL4(m.GetX(), 0.0f));
       demn = n.GetY() * plane2.n.GetZ() - n.GetZ() * plane2.n.GetY();
       ASSERT(demn != 0.0f);  // Sanity Check.

       pt0.x = 0.0f;
       pt0.y = (d * plane2.n.GetZ() - n.GetZ() * plane2.d) / demn;
       pt0.z = (n.GetY() * plane2.d - plane2.n.GetY() * d) / demn;
       }
       else if (dy >= dx && dy >= dz) {
       ASSERT(!EQUAL4(m.GetY(), 0.0f));
       demn = n.GetZ() * plane2.n.GetX() - n.GetX() * plane2.n.GetZ();
       ASSERT(demn != 0.0f);

       pt0.x = (n.GetZ() * plane2.d - plane2.n.GetZ() * d) / demn;
       pt0.y = 0.0f;
       pt0.z = (plane2.n.GetX() * d - n.GetX() * plane2.d) / demn;
       }
       else { // m.GetZ() != 0.0f
       // Sanity.
       ASSERT(dz >= dx && dz >= dy);
       ASSERT(!EQUAL4(m.GetZ(), 0.0f));

       demn = n.GetY() * plane2.n.GetX() - n.GetX() * plane2.n.GetY();
       ASSERT(demn != 0.0f);  // Sanity Check.

       pt0.x = (n.GetY() * plane2.d - plane2.n.GetY() * d) / demn;
       pt0.y = (plane2.n.GetX() * d - n.GetX() * plane2.d) / demn;
       pt0.z = 0.0f;
       }

       l.NewLine(pt0, m);
       return true;
     */
    return(0);
}
// ----------------------------------------------------------------------------
int iTestRayAABBIntersection (const CGRay& _oRay, const CGVect3& _oMaxs, const CGVect3& _oMins)
{
    /*
       Fast Rat-Box Intersection
       by Andrew Woo
       from "Graphics Gems", Academic Press,1990
     */

#define Q_RIGHT  0
#define Q_LEFT   1
#define Q_MIDDLE 2

    int i;
    char cQuadrant[3];
    CGVect3 oCGPlane;
    CGVect3 oMaxT;
    bool bInside = true;
    int iWhichPlane;

    // Find candidate planes
    for ( i = 0; i < 3; i++ )
    {
        if ( _oRay.Origin.v(i) < _oMins.v(i) )
        {
            cQuadrant[i] = Q_LEFT;
            oCGPlane.v(i) = _oMins.v(i);
            bInside = false;
        }
        else
        if ( _oRay.Origin.v(i) > _oMaxs.v(i) )
        {
            cQuadrant[i] = Q_RIGHT;
            oCGPlane.v(i) = _oMaxs.v(i);
            bInside = false;
        }
        else
        {
            cQuadrant[i] = Q_MIDDLE;
        }
    }

    // Ray origin inside bounding box
    if ( bInside )
    {
        // IntersectionPoint = _oRay.Origin;
        return(1);
    }

    // Compute T distances to candidate planes
    for ( i = 0; i < 3; i++ )
    {
        if ( (cQuadrant[i] != Q_MIDDLE) && (_oRay.Dir.v(i) != 0.0f) )
            oMaxT.v(i) = ( oCGPlane.v(i) - _oRay.Origin.v(i) ) / _oRay.Dir.v(i);
        else
            oMaxT.v(i) = -1.0f;
    }

    // Get largest maxT for final choice of intersection
    iWhichPlane = 0;
    for ( i = 1; i < 3; i++ )
        if ( oMaxT.v(iWhichPlane) < oMaxT.v(iWhichPlane) )
            iWhichPlane = i;

    // Check final candidate actually inside box
    if ( oMaxT.v(iWhichPlane) < 0.0f ) return (0);

    CGVect3 oPoint;
    for ( i = 0; i < 3; i++ )
    {
        if ( iWhichPlane != i )
        {
            oPoint.v(i) = _oRay.Origin.v(i) + oMaxT.v(iWhichPlane) * _oRay.Dir.v(i);

            if ( ( oPoint.v(i) < _oMins.v(i) ) || ( oPoint.v(i) > _oMaxs.v(i) ) )
                return(0);
        }
        else
        {
            oPoint.v(i) = oCGPlane.v(i);
        }
    }

    return(1);

    #undef Q_RIGHT
    #undef Q_LEFT
    #undef Q_MIDDLE
}
// ----------------------------------------------------------------------------
}; // namespace Math
// ----------------------------------------------------------------------------
