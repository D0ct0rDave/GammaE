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
class CGMesh;
class CGGraphBV;
class CGGraphBVSphere;
class CGGraphBVAABB;
// ----------------------------------------------------------------------------
namespace MeshUtils {
// ----------------------------------------------------------------------------
CGGraphBV* poComputeBV(const CGMesh &Mesh);
CGGraphBVAABB* poComputeBVAABB(const CGMesh &Mesh);
CGGraphBVSphere* poComputeBVSphere(const CGMesh &Mesh);
// ----------------------------------------------------------------------------
}; // namespace MeshUtils
// ----------------------------------------------------------------------------
#endif
// ----------------------------------------------------------------------------
