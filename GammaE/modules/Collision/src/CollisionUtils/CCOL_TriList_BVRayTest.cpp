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

// CCOL_TriList_BVRayTest
#include "CollisionUtils\CCOL_TriList_BVRayTest.h"

// Class CCOL_TriList_BVRayTest
CCOL_TriList_BVRayTest::CCOL_TriList_BVRayTest()
{
}

CCOL_TriList_BVRayTest::~CCOL_TriList_BVRayTest()
{
}

void CCOL_TriList_BVRayTest::Test (CGVect3& _Center, CCOL_TriList& _TriList, int _iRayMask, float* _pa6fDists, int* _pa6iTris)
{
    CGRay Ray;
    int iAxis;
    CGVect3 Axis[6] = { CGVect3( 1.0f,0.0f,0.0f),
                       CGVect3(-1.0f,0.0f,0.0f),
                       CGVect3(0.0f, 1.0f,0.0f),
                       CGVect3(0.0f,-1.0f,0.0f),
                       CGVect3(0.0f,0.0f, 1.0f),
                       CGVect3(0.0f,0.0f,-1.0f)};

    // Init ray origin as the center ob the BV object
    Ray.Origin.Assign(_Center);

    for ( iAxis = 0; iAxis < 6; iAxis++ )
    {
        // Init as non colliding axis
        _pa6iTris [iAxis] = -1;
        _pa6fDists[iAxis] = -1.0f;

        // Need to test this axis?
        if ( _iRayMask & (1 << iAxis) )
        {
            // Assign axis direction
            Ray.Dir.Assign(Axis[iAxis]);

            // Get the minimum distance of the triangle and the tris
            _pa6fDists[iAxis] = fGetRayTriListMinDist(Ray,_TriList,Ray.Origin,_pa6iTris[iAxis]);

            if ( _pa6iTris[iAxis] != -1 )
                _pa6fDists[iAxis] = Math::fSqrt(_pa6fDists[iAxis]);
        }
    }
}

float CCOL_TriList_BVRayTest::fGetRayTriListMinDist (CGRay& _ay, CCOL_TriList& _TriList, CGVect3& _Point, int& _iIdx)
{
    // <UNMAINTAINED>
    CGTriangle Tri;

    CGVect3 IPoint;              // Intersection point
    int iTri;
    float fDist;
    float fMinDist;

    _iIdx = -1;
    fMinDist = 1e6;
    for ( iTri = 0; iTri < _TriList.iNumTris; iTri++ )
    {
        Tri.Init(&_TriList.poVXs[3 * iTri], _TriList.poVNs[iTri] );
        Tri.ComputeAll();

        if ( Math::iTestSegTriIntersection(_ay,Tri,IPoint) )
        {
            fDist = _ay.Origin.fSqDistance(IPoint);
            if ( fDist < fMinDist )
            {
                fMinDist = fDist;
                _iIdx = iTri;
            }
        }
    }

    return(fMinDist);
}

// Additional Declarations

// Detached code regions:
// WARNING: this code will be lost if code is regenerated.
#if 0
int iCorner;
int iTest;

CGRay Ray;
CGVect3* Corner;
CGVect3 Center;
CGVect3 Extents;

Center = _pBV.GetCenter();
Extents = _pBV.GetExtents();
Extents.Scale(0.5f);

Ray.Origin.Assign(Center);
Ray.Origin.V3 (Center.x - Extents.x,Center.y - Extents.y,Center.z - Extents.z);

iTest = 0;
Corner = _pBV.Vol.Points;
for ( iCorner = 0; iCorner < 8; iCorner++ )
{
    Ray.Origin.Assign(*Corner);

    // Test in X direction
    Ray.Dir.Set(1.0f,0.0f,0.0f);
    _pa24fDists[iTest] = fGetRayTriListMinDist(Ray,_TriList,*Corner,_pa24iTris[iTest]);
    iTest++;

    Ray.Dir.Set(0.0f,1.0f,0.0f);
    _pa24fDists[iTest] = fGetRayTriListMinDist(Ray,_TriList,*Corner,_pa24iTris[iTest]);
    iTest++;

    Ray.Dir.Set(0.0f,0.0f,1.0f);
    _pa24fDists[iTest] = fGetRayTriListMinDist(Ray,_TriList,*Corner,_pa24iTris[iTest]);
    iTest++;

    Corner++;
}
#endif
