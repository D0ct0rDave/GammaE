//-----------------------------------------------------------------------------
#ifndef TransformMeshH
#define TransformMeshH
//-----------------------------------------------------------------------------
#include "../../BoundingVolume/CBoundingVolume.h"
#include "../CMesh.h"

void MeshTransform_Translate(CMesh &Mesh,CVect3 &T);
void MeshTransform_Scale	(CMesh &Mesh,CVect3 &S);
void MeshTransform_Rotate	(CMesh &Mesh,CVect3 &R,float _fAngle);
void MeshTransform_Transform(CMesh &Mesh,CMatrix4x4 &M);

//-----------------------------------------------------------------------------
#endif
//-----------------------------------------------------------------------------