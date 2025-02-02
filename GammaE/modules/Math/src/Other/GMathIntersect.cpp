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
#include "GMathIntersect.h"
#include "GMathUtils.h"
#include "GMathCommon.h"
#include "Vector\CGVect3.h"
#include "GammaE_Misc.h"
#include <assert.h>
// ----------------------------------------------------------------------------
namespace Math {
// ----------------------------------------------------------------------------
bool bBVsIntersect(class CGBoundingVolume const& _poBVA, class CGBoundingVolume const& _poBVB)
{
    assert(false && "Warning Not Implemented");
    return(false);
}
// ----------------------------------------------------------------------------
bool bBVsIntersect(const CGBoundingVolume& _oBV1, const CGMatrix4x4& _oTransfBV1, const CGBoundingVolume& _oBV2, const CGMatrix4x4& _oTransfBV2)
{
    assert(false && "Warning Not Implemented");
    return(false);
}
// ----------------------------------------------------------------------------
// / Test the intersection of a given bounding volume against a given frustum
// ----------------------------------------------------------------------------
bool bBVIntersectFrustum(const CGBoundingVolume& _oBV,const CGBVFrustum& _oFrustum)
{
    switch ( _oBV.eGetType() )
    {
        // ---------------------------------------
        // Test point against frustum
        // ---------------------------------------
        case BVT_POINT:
        {
            CGVect3 oTransfPoint = ( (const CGBVPoint &)_oBV ).oGetCenter();
            // The plane normals point to outside, then, if a distance point is >0
            // the point is outside the plane (in front of the plane,
            // in oposition to the back face of the plane)

            // WARNING: In release near plane doens't work properly
            for ( uint i = 0; i < 6; i++ )
                if ( iTestPointPlane( oTransfPoint,_oFrustum.oGetPlane(i) ) >= 0 )
                    return(false);

            return(true);
        }
        break;

        case BVT_SPHERE:
        {
            CGVect3 oTransfPoint = ( (const CGBVSphere &)_oBV ).oGetCenter();
            // The plane normals point to outside, then, if a distance point is >0
            // the point is outside the plane (in front of the plane,
            // in oposition to the back face of the plane)

            // WARNING: In release near plane doens't work properly
            for ( uint i = 0; i < 6; i++ )
                if ( iTestSpherePlane( oTransfPoint,( (const CGBVSphere &)_oBV ).fGetRadius(),_oFrustum.oGetPlane(i) ) == 1 )
                    return(false);

            return(true);
        }
        break;

        case BVT_AABB:
        {
            // The plane normals point to outside, then, if a distance point is >0
            // the point is outside the plane (in front of the plane,
            // in oposition to the back face of the plane)

            // WARNING: In release near plane doens't work properly
            for ( uint i = 0; i < 6; i++ )
            {
                if ( iTestBoxPlane( ( (const CGBVAABB &)_oBV ).oGetMax(),( (const CGBVAABB &)_oBV ).oGetMin(),_oFrustum.oGetPlane(i) ) == 1 )
                    return(false);
            }

            return(true);
        }
        break;

        default:
        // Not implemented for cylinders, frustums, other
        return(true);
    }

    return(true);
}
// ----------------------------------------------------------------------------
// / Test the intersection of a given bounding volume with an specific transform against a given frustum
// ----------------------------------------------------------------------------
bool bBVIntersectFrustum(const CGBoundingVolume& _oBV,const CGMatrix4x4& _oTransfBV,const CGBVFrustum& _oFrustum)
{
    switch ( _oBV.eGetType() )
    {
        // ---------------------------------------
        // Test point against frustum
        // ---------------------------------------
        case BVT_POINT:
        {
            CGVect3 oTransfPoint = ( (const CGBVPoint &)_oBV ).oGetCenter();
            _oTransfBV.TransformPoint(&oTransfPoint);

            // The plane normals point to outside, then, if a distance point is >0
            // the point is outside the plane (in front of the plane,
            // in oposition to the back face of the plane)

            // WARNING: In release near plane doens't work properly
            for ( uint i = 0; i < 6; i++ )
                if ( iTestPointPlane( oTransfPoint,_oFrustum.oGetPlane(i) ) >= 0 )
                    return(false);

            return(true);
        }
        break;

        case BVT_SPHERE:
        {
            CGVect3 oTransfPoint = ( (const CGBVSphere &)_oBV ).oGetCenter();
            _oTransfBV.TransformPoint(&oTransfPoint);

            // The plane normals point to outside, then, if a distance point is >0
            // the point is outside the plane (in front of the plane,
            // in oposition to the back face of the plane)

            // WARNING: In release near plane doens't work properly
            for ( uint i = 0; i < 6; i++ )
                if ( iTestSpherePlane( oTransfPoint,( (const CGBVSphere &)_oBV ).fGetRadius(),_oFrustum.oGetPlane(i) ) == 1 )
                    return(false);

            return(true);
        }
        break;

        case BVT_AABB:
        {
            CGMatrix4x4 oInvMat = _oTransfBV;
            oInvMat.RTInverse();

            // The plane normals point to outside, then, if a distance point is >0
            // the point is outside the plane (in front of the plane,
            // in oposition to the back face of the plane)

            // WARNING: In release near plane doens't work properly
            for ( uint i = 0; i < 6; i++ )
            {
                CGPlane oTransfPlane = _oFrustum.oGetPlane(i);
                oTransfPlane.Transform(oInvMat);

                if ( iTestBoxPlane( ( (const CGBVAABB &)_oBV ).oGetMax(),( (const CGBVAABB &)_oBV ).oGetMin(),oTransfPlane ) == 1 )
                    return(false);
            }

            return(true);
        }
        break;

        default:
        // Not implemented for cylinders, frustums, other
        return(true);
    }

    return(true);
}
// ----------------------------------------------------------------------------
}; // namespace Math
// ----------------------------------------------------------------------------
