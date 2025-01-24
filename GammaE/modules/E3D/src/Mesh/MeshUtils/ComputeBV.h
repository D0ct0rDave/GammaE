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
#ifndef ComputeBVH
#define ComputeBVH
// ----------------------------------------------------------------------------
#include "../CGMesh.h"
// ----------------------------------------------------------------------------
namespace MeshUtils {
// ----------------------------------------------------------------------------
CGBoundingVolume* poComputeBV(const CGMesh &Mesh);
CGBVAABB* poComputeBVAABB(const CGMesh &Mesh);
CGBVSphere* poComputeBVSphere(const CGMesh &Mesh);
// ----------------------------------------------------------------------------
}; // namespace MeshUtils
// ----------------------------------------------------------------------------
#endif
// ----------------------------------------------------------------------------
