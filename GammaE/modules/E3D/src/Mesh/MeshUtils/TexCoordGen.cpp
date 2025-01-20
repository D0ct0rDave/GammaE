//-----------------------------------------------------------------------------
#include "TexCoordGen.h"
//-----------------------------------------------------------------------------
void TexCoordGen_ComputeUVOrthoMapping(CMesh &Mesh)
{
	unsigned int	cVect;
	CGraphBV		*BVol;
    CVect3 			Center;    
    float			UOffset;

    if (! Mesh.Idxs) return;

    // We need the Min and Max mesh points
    BVol = Mesh.GetBoundVol();

    // Get the center point
	Center = BVol->GetCenter();

    // Compute UV coordinates
	for (cVect=0;cVect<Mesh.usNumVerts;cVect++)
	{
    	if (Mesh.VXs[cVect].z - Center.z < 0) UOffset = 0.5; else UOffset = 0;

        Mesh.UVs[cVect].x = UOffset + ((0.5f + (Mesh.VXs[cVect].x - Center.x)/BVol->GetRange(0) )/2.0f);
        Mesh.UVs[cVect].y =            (0.5f + (Mesh.VXs[cVect].y - Center.y)/BVol->GetRange(1) );
}
}
//-----------------------------------------------------------------------------