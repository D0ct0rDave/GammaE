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
#ifndef CGBVUtilsH
#define CGBVUtilsH
// ----------------------------------------------------------------------------
#include "CGBoundingVolume.h"
#include "Matrix/CGMatrix4x4.h"
// ----------------------------------------------------------------------------
// y
// |
// |
// |
// Center----- x
// /
// /
// z
// ----------------------------------------------------------------------------
namespace Utils
{
void TransformBoundingVolume(CGBoundingVolume* _poBV,const CGMatrix4x4& _oMatrix);
};
// ----------------------------------------------------------------------------
#endif
// ----------------------------------------------------------------------------
