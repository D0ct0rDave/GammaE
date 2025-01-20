



#include "GammaE_Mem.h"

// CTexProjector
#include "TexProjector\CTexProjector.h"

// arreglar
// int iMaxUVs = 0;



// Class CTexProjector 



CTexProjector::CTexProjector()
        {
}


CTexProjector::~CTexProjector()
{
  	
	// Unlink projector mesh
   	oAuxMesh.BVol      = NULL;
	oAuxMesh.eMeshType = E3D_MESH_NONE;
	oAuxMesh.Idxs      = NULL;
	oAuxMesh.VXs	   = NULL;
	oAuxMesh.usNumIdxs = NULL;
	oAuxMesh.usNumPrims= NULL;
	oAuxMesh.usNumVerts= NULL;
	oAuxMesh.UVs	   = NULL;
	oAuxMesh.UVs2      = NULL;
	oAuxMesh.VCs       = NULL;
	oAuxMesh.VNs       = NULL;
	oAuxMesh.TNs       = NULL;
	
	SetMesh(NULL);

}



void CTexProjector::Setup (CMesh* _oSrcMesh, CE3D_Shader* _poShader, CMatrix4x4& _oPrjMatrix)
{
  
	// Copy source data
 	oAuxMesh.BVol      = _oSrcMesh->BVol;
	oAuxMesh.eMeshType = _oSrcMesh->eMeshType;	
	oAuxMesh.Idxs      = _oSrcMesh->Idxs;
	oAuxMesh.VXs	   = _oSrcMesh->VXs;
	oAuxMesh.usNumIdxs = _oSrcMesh->usNumIdxs;
	oAuxMesh.usNumPrims= _oSrcMesh->usNumPrims;
	oAuxMesh.usNumVerts= _oSrcMesh->usNumVerts;	
	oAuxMesh.UVs	   = (CVect2*)_oSrcMesh->VXs;
	oAuxMesh.UVs2      = NULL;
	oAuxMesh.VCs       = NULL;						// _oSrcMesh->VCs;	
	oAuxMesh.VNs       = NULL;
	oAuxMesh.TNs       = NULL;
	
	// UVs
	/*
	if (_oSrcMesh->usNumVerts > iMaxUVs)
	{
		if (iMaxUVs)
			mDel []oAuxMesh.UVs;
		
		oAuxMesh.UVs = mNew CVect2[_oSrcMesh->usNumVerts];
		iMaxUVs = _oSrcMesh->usNumVerts;
	}

	// Project coordinates 
	CVect3	oUV;
	int		iV;
	for (iV=0;iV<_oSrcMesh->usNumVerts;iV++)
	{	
		// oUV.V4(oAuxMesh.VXs[iV].x,oAuxMesh.VXs[iV].y,oAuxMesh.VXs[iV].z,1.0f);		
		oUV.Assign(oAuxMesh.VXs[iV]);		
		_oPrjMatrix.TransformVector(oUV);		

		// oAuxMesh.UVs[iV].V2(0.5f + 0.5f*oUV.x/oUV.z,0.5f + 0.5f*oUV.y/oUV.z);
		oAuxMesh.UVs[iV].V2(oUV.x/oUV.z,oUV.y/oUV.z);
	}
	*/
	SetShader(_poShader);
	SetMesh  (&oAuxMesh);	
}

void CTexProjector::Setup (CMesh* _oSrcMesh, CE3D_Shader* _poShader, CVect3& _oPos, CVect3& _oDir, float _fXSize, float _fYSize)
{
  	// Compute projection matrix
	CMatrix4x4 oPrjMat;
	
	// ...
	// ...
	// ...

	Setup(_oSrcMesh,_poShader,oPrjMat);
}

// Additional Declarations
    
