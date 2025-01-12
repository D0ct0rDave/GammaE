//---------------------------------------------------------------------------
#include "TransformMesh.h"
//---------------------------------------------------------------------------
void MeshTransform_Translate(CMesh &Mesh,CVect3 &T)
{
    unsigned int cV;
    if (Mesh.VXs)
    {
	    for (cV=0;cV<Mesh.usNumVerts;cV++) Mesh.VXs[cV].Add(T);
    }
}
//---------------------------------------------------------------------------
// Fixme: Transform normals also
//---------------------------------------------------------------------------
void MeshTransform_Scale(CMesh &Mesh,CVect3 &S)
{
    unsigned int cV;

    if (Mesh.VXs)
    {
		// Transform vertexs
	    for (cV=0;cV<Mesh.usNumVerts;cV++)
    	{
    		Mesh.VXs[cV].v[0] *= S.v[0];
	    	Mesh.VXs[cV].v[1] *= S.v[1];
	    	Mesh.VXs[cV].v[2] *= S.v[2];
    	}
    }
}
//---------------------------------------------------------------------------
void MeshTransform_Rotate(CMesh &Mesh,CVect3 &R,float _fAngle)
{
    unsigned int cV;
    CMatrix4x4 M;

    M.LoadIdentity();
    M.RotateFromArbitraryAxis(R.X(),R.Y(),R.Z(),_fAngle);

    // Transform vertexs
    if (Mesh.VXs)
    	for (cV=0;cV<Mesh.usNumVerts;cV++)
        	M.TransformPoint(Mesh.VXs[cV]);

	// Transform vertexs normals
    if (Mesh.VNs)
	    for (cV=0;cV<Mesh.usNumVerts;cV++)
    	    M.TransformVector(Mesh.VNs[cV]);
}
//---------------------------------------------------------------------------
void MeshTransform_Transform(CMesh &Mesh,CMatrix4x4 &M)
{
    unsigned int cV;
    
    // Transform vertexs
    if (Mesh.VXs)
    	for (cV=0;cV<Mesh.usNumVerts;cV++)
        	M.TransformPoint(Mesh.VXs[cV]);

	// Transform vertexs normals
    if (Mesh.VNs)
	    for (cV=0;cV<Mesh.usNumVerts;cV++)
    	    M.TransformVector(Mesh.VNs[cV]);
}
//---------------------------------------------------------------------------