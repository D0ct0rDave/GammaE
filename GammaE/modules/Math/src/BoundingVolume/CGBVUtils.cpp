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
#include "CGBVUtils.h"
// ----------------------------------------------------------------------------
namespace Utils
{
// ----------------------------------------------------------------------------
void TransformBoundingVolume(CGBoundingVolume* _poBV,const CGMatrix4x4& _oMatrix)
{
    switch ( _poBV->eGetType() )
    {
        case BVT_POINT:
        break;

        case BVT_SPHERE:
        break;

        case BVT_AABB:
        break;

        case BVT_CYLINDER:
        break;

        case BVT_FRUSTUM:
        break;
    }
}
// ----------------------------------------------------------------------------
};
// ----------------------------------------------------------------------------
