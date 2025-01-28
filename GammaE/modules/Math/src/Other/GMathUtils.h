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
#ifndef Utils_h
#define Utils_H
// ----------------------------------------------------------------------------
// CGRay
#include "..\Ray\CGRay.h"
// CGPlane
#include "..\Plane\CGPlane.h"
// CGVect3
#include "..\Vector\CGVect3.h"
// CGTriangle
#include "..\Triangle\CGTriangle.h"
// CGSegment
#include "..\Segment\CGSegment.h"
// ----------------------------------------------------------------------------
namespace Math {
// ----------------------------------------------------------------------------

void GetPNVertexs(const CGVect3& _oMaxs, const CGVect3& _oMins, const CGPlane& _oPlane, CGVect3& P, CGVect3& N);

int iTestBoxPlane(const CGVect3& _oMaxs, const CGVect3& _oMins, const CGPlane& _oPlane);

int iTestSpherePlane(const CGVect3& _oCenter, float _fRadius, const CGPlane& _oPlane);

int iTestPointPlane(const CGVect3& _oPoint, const CGPlane& _oPlane);

float fTriPointDistance(const CGTriangle& _oTri, const CGVect3& _oPoint);

float fTriPointSqDistance(const CGTriangle& _oTri, const CGVect3& _oPoint);

CGVect3 oNearestTriPoint(const CGVect3& _oPoint, const CGTriangle& _oTri);

void GetMaxMins(float a, float b, float c, float &fMax, float& fMin);

int iTestRayTriIntersection(const CGRay& _oRay, const CGTriangle& _oTri);

int iTestRayTriIntersection(const CGRay& _oRay, const CGTriangle& _oTri, CGVect3* _poProjectedPoint);

int iTestSegTriIntersection(const CGRay& _oRay, const CGTriangle& _oTri);

int iTestSegTriIntersection(const CGRay& _oRay, const CGTriangle& _oTri, CGVect3* _poProjectedPoint);

float fGetT();

int iPointInsideTriangle(const CGTriangle& _oTri, const CGVect3& _oPoint, CGVect3* _poProjectedPoint);

int iPointInsideTriangle(const CGTriangle& _oTri, const CGVect3& _oPoint);

int iTest3PlaneIntersection(const CGPlane& _oPlane0, const CGPlane& _oPlane1, const CGPlane& _oPlane2, CGVect3* _poIntersectionPoint);

int iTest2PlaneIntersection(const CGPlane& _oPlane0, const CGPlane& _oPlane1, const CGRay& _oRay);

int iTestRayAABBIntersection(const CGRay& _oRay, const CGVect3& _oMaxs, const CGVect3& _oMins);

// ----------------------------------------------------------------------------
inline void GetMaxMins (float a, float b, float c, float &fMax, float& fMin)
{
    if ( a > b )
    {
        if ( b > c )
        {
            fMax = a;
            fMin = c;
        }
        else
        {
            if ( a > c )
            {
                fMax = a;
                fMin = b;
            }
            else
            {
                fMax = c;
                fMin = b;
            }
        }
    }
    else
    {
        // b > a
        if ( a > c )
        {
            fMax = b;
            fMin = c;
        }
        else
        {
            // a < c
            if ( b > c )
            {
                fMax = b;
                fMin = a;
            }
            else
            {
                fMax = c;
                fMin = a;
            }
        }
    }
}
// ----------------------------------------------------------------------------
}; // namespace Math
// ----------------------------------------------------------------------------
#endif
// ----------------------------------------------------------------------------
