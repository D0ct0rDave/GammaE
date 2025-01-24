//-----------------------------------------------------------------------------
#include "TransformMesh.h"
//-----------------------------------------------------------------------------
void MeshTransform_Translate(CMesh &Mesh,CVect3 &T)
{
    unsigned int cV;
    if (Mesh.VXs)
    {
	    for (cV=0;cV<Mesh.usNumVerts;cV++) Mesh.VXs[cV].Add(T);
}
}
//-----------------------------------------------------------------------------
// Fixme: Transform normals also
//-----------------------------------------------------------------------------
void MeshTransform_Scale(CMesh &Mesh,CVect3 &S)
{
    unsigned int cV;

    if (Mesh.VXs)
    {
		// Transform vertexs
	    for (cV=0;cV<Mesh.usNumVerts;cV++)
    	{
    		Mesh.VXs[cV].x *= S.x;
	    	Mesh.VXs[cV].y *= S.y;
	    	Mesh.VXs[cV].z *= S.z;
    	}
}
}
//-----------------------------------------------------------------------------
void MeshTransform_Rotate(CMesh &Mesh,CVect3 &R,float _fAngle)
{
    unsigned int cV;
    CMatrix4x4 M;

    M.LoadIdentity();
    M.RotateFromArbitraryAxis(R.x,R.y,R.z,_fAngle);

    // Transform vertexs
    if (Mesh.VXs)
    	for (cV=0;cV<Mesh.usNumVerts;cV++)
        	M.TransformPoint(Mesh.VXs[cV]);

	// Transform vertexs normals
    if (Mesh.VNs)
	    for (cV=0;cV<Mesh.usNumVerts;cV++)
    	    M.TransformVector(Mesh.VNs[cV]);
}
//-----------------------------------------------------------------------------
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
//-----------------------------------------------------------------------------