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
#ifndef CGMathIntersectH
#define CGMathIntersectH
// ----------------------------------------------------------------------------
#include "BoundingVolume/CGBVAABB.h"
#include "BoundingVolume/CGBVSphere.h"
#include "BoundingVolume/CGBVCylinder.h"
#include "BoundingVolume/CGBVFrustum.h"
#include "BoundingVolume/CGBVPoint.h"
#include "BoundingVolume/CGBoundingVolume.h"
// ----------------------------------------------------------------------------
namespace Math {
// ----------------------------------------------------------------------------

bool bBVsIntersect(const CGBoundingVolume& _oBV1,const CGBoundingVolume& _oBV2);
bool bBVsIntersect(const CGBoundingVolume& _oBV1,const CGMatrix4x4& _oTransfBV1,const CGBoundingVolume& _oBV2,const CGMatrix4x4& _oTransfBV2);

// / Test the intersection of a given bounding volume with an specific transform against a given frustum
bool bBVIntersectFrustum(const CGBoundingVolume& _oBV,const CGMatrix4x4& _oTransfBV,const CGBVFrustum& _oFrustum);

// / Test the intersection of a given bounding volume against a given frustum
bool bBVIntersectFrustum(const CGBoundingVolume& _oBV,const CGBVFrustum& _oFrustum);

// ----------------------------------------------------------------------------
}; // namespace Math
// ----------------------------------------------------------------------------
#endif
// ----------------------------------------------------------------------------
