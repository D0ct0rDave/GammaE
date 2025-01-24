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
#ifndef TransformMeshH
#define TransformMeshH
// ----------------------------------------------------------------------------
#include "../CGMesh.h"
// ----------------------------------------------------------------------------
namespace MeshUtils {
// ----------------------------------------------------------------------------
void TranslateMesh(CGMesh &Mesh,CGVect3 &T);
void ScaleMesh(CGMesh &Mesh,CGVect3 &S);
void RotateMesh(CGMesh &Mesh,CGVect3 &R,float _fAngle);
void TransformMesh(CGMesh &Mesh,CGMatrix4x4 &M);
// ----------------------------------------------------------------------------
}; // MeshUtils
// ----------------------------------------------------------------------------
#endif
// ----------------------------------------------------------------------------
