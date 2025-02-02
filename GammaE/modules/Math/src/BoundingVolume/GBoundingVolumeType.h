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
#ifndef EGBoundingVolumeType_h
#define EGBoundingVolumeType_H
// ----------------------------------------------------------------------------
typedef enum EGBoundingVolumeType
{
    BVT_NONE,

    BVT_POINT,
    BVT_SPHERE,
    BVT_AABB,
    BVT_CYLINDER,
    BVT_FRUSTUM,

    BVT_NUMBVTs
};
// ----------------------------------------------------------------------------
#endif
// ----------------------------------------------------------------------------
