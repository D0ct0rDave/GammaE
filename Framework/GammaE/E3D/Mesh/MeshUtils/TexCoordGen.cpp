//---------------------------------------------------------------------------
#include "TexCoordGen.h"
//---------------------------------------------------------------------------
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
    	if (Mesh.VXs[cVect].v[2] - Center.v[2] < 0) UOffset = 0.5; else UOffset = 0;

        Mesh.UVs[cVect].v[0] = UOffset + ((0.5f + (Mesh.VXs[cVect].v[0] - Center.v[0])/BVol->GetRange(0) )/2.0f);
        Mesh.UVs[cVect].v[1] =            (0.5f + (Mesh.VXs[cVect].v[1] - Center.v[1])/BVol->GetRange(1) );
   }
}
//---------------------------------------------------------------------------