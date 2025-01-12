#include "memory/gammae_mem.h"
#include "NormalGen.h"
//---------------------------------------------------------------------------
CVect3 NormalGen_ComputeVertexNormal(CMesh &Mesh,CVect3 *pPNs,int iVX)
{	
	CVect3	Accum;
	int		iNumFaces;
	int		iPri;
	int		iNumVXPerFace;
	int		cVert;
	
	Accum.V3(0,0,0);
	iNumFaces = 0;
	
	if (Mesh.eMeshType == E3D_MESH_TRIS) iNumVXPerFace = 3; else iNumVXPerFace = 4;

	// Get the average of the normals of the faces from the vertex belongs	
	for (iPri=0;iPri<Mesh.usNumPrims;iPri++)
	{
		for (cVert=0;cVert<iNumVXPerFace;cVert++)
		{
			if (Mesh.Idxs[iPri*iNumVXPerFace+cVert] == iVX)
			{
				Accum.Add(pPNs[iPri]);
				iNumFaces++;
			}
		}
	}

	if (iNumFaces)	Accum.Scale(1.0f / (float)iNumFaces);
	return (Accum);
}
//---------------------------------------------------------------------------
CVect3 *NormalGen_ComputePrimitiveNormals(CMesh &Mesh)
{
    unsigned int	cPri;
    CVect3			ab,cb,db,na,nb;
    CVect3			VSum;

    CVect3		   *pPNs;
	
	pPNs = mNew CVect3[Mesh.usNumPrims];

	switch ( Mesh.GetMeshType() )
	{
		// --------------------------------
		// Compute triangle normal
		// --------------------------------
		case E3D_MESH_TRIS:
		{
			for (cPri=0;cPri<Mesh.usNumPrims;cPri++)
			{
				// Compute triangle normal
				pPNs[cPri].Normal(Mesh.VXs[ Mesh.Idxs[cPri*3+0] ],
								  Mesh.VXs[ Mesh.Idxs[cPri*3+1] ],
								  Mesh.VXs[ Mesh.Idxs[cPri*3+2] ]);
				pPNs[cPri].Normalize();
			}
		}
		break;

		// --------------------------------
		// Compute quad normal
		// --------------------------------
		case E3D_MESH_QUADS:	
		{
			for (cPri=0;cPri<Mesh.usNumPrims;cPri++)
			{
	    		// Get triagle segments
    			ab.Assign(Mesh.VXs[ Mesh.Idxs[cPri*4+0] ]);
				ab.Sub   (Mesh.VXs[ Mesh.Idxs[cPri*4+1] ]);
				cb.Assign(Mesh.VXs[ Mesh.Idxs[cPri*4+2] ]);									
				cb.Sub   (Mesh.VXs[ Mesh.Idxs[cPri*4+1] ]);
				db.Assign(Mesh.VXs[ Mesh.Idxs[cPri*4+3] ]);
				db.Sub   (Mesh.VXs[ Mesh.Idxs[cPri*4+1] ]);

				// Compute quad normal
				na.CrossProd(ab,cb);

				pPNs[cPri].CrossProd(cb,db);
				pPNs[cPri].Add(na);
				pPNs[cPri].Scale(0.5);
				pPNs[cPri].Normalize();
			}
		}
		break;
	}    

	return (pPNs);
}
//---------------------------------------------------------------------------
void NormalGen_ComputeVertexsNormals(CMesh &Mesh)
{
	bool bErasePNs = (Mesh.TNs == NULL);
	// Compute primitive normals
	Mesh.TNs = NormalGen_ComputePrimitiveNormals(Mesh);

	// --------------------------------
	// Compute vertexs normal
    // --------------------------------
	unsigned int cVert;

	for (cVert=0;cVert<Mesh.usNumVerts;cVert++)	
		Mesh.VNs[cVert] = NormalGen_ComputeVertexNormal(Mesh,Mesh.TNs,cVert);


	if (bErasePNs) 
	{
		mDel []Mesh.TNs;
		Mesh.TNs = NULL;
	}
}
//---------------------------------------------------------------------------