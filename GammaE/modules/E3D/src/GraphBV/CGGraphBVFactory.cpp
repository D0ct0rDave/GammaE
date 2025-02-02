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
#include "GammaE_Mem.h"

#include "CGGraphBVFactory.h"
#include "CGGraphBVSphere.h"
#include "CGGraphBVPoint.h"
#include "CGGraphBVCylinder.h"
#include "CGGraphBVAABB.h"

// -----------------------------------------------------------------------------
EGBoundingVolumeType CGGraphBVFactory::m_eBVMode = EGBoundingVolumeType::BVT_SPHERE;
// -----------------------------------------------------------------------------
CGGraphBV* CGGraphBVFactory::poCreate (EGBoundingVolumeType _eBVMode)
{
    switch (_eBVMode)
    {
        case EGBoundingVolumeType::BVT_SPHERE:  return(mNew CGGraphBVSphere);
        case EGBoundingVolumeType::BVT_AABB:    return(mNew CGGraphBVAABB);
        case EGBoundingVolumeType::BVT_CYLINDER: return(mNew CGGraphBVCylinder);
        case EGBoundingVolumeType::BVT_POINT:   return(mNew CGGraphBVPoint);
    }

    return (NULL);
}

// -----------------------------------------------------------------------------
CGGraphBV* CGGraphBVFactory::poCreate()
{
    return poCreate(m_eBVMode);
}

// -----------------------------------------------------------------------------
// epilog: singleton initializer through static instantiation
// -----------------------------------------------------------------------------
static CGGraphBVFactory m_oInstance;
