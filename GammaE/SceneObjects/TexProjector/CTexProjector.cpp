//## begin module%3CB94617013A.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3CB94617013A.cm

//## begin module%3CB94617013A.cp preserve=no
//## end module%3CB94617013A.cp

//## Module: CTexProjector%3CB94617013A; Pseudo Package body
//## Source file: i:\Projects\GammaE\SceneObjects\TexProjector\CTexProjector.cpp

//## begin module%3CB94617013A.additionalIncludes preserve=no
//## end module%3CB94617013A.additionalIncludes

//## begin module%3CB94617013A.includes preserve=yes
#include "memory/gammae_mem.h"
//## end module%3CB94617013A.includes

// CTexProjector
#include "SceneObjects\TexProjector\CTexProjector.h"
//## begin module%3CB94617013A.additionalDeclarations preserve=yes

// arreglar
// int iMaxUVs = 0;

//## end module%3CB94617013A.additionalDeclarations


// Class CTexProjector 



CTexProjector::CTexProjector()
  //## begin CTexProjector::CTexProjector%.hasinit preserve=no
  //## end CTexProjector::CTexProjector%.hasinit
  //## begin CTexProjector::CTexProjector%.initialization preserve=yes
  //## end CTexProjector::CTexProjector%.initialization
{
  //## begin CTexProjector::CTexProjector%.body preserve=yes
  //## end CTexProjector::CTexProjector%.body
}


CTexProjector::~CTexProjector()
{
  //## begin CTexProjector::~CTexProjector%.body preserve=yes
	
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

  //## end CTexProjector::~CTexProjector%.body
}



//## Other Operations (implementation)
void CTexProjector::Setup (CMesh* _roSrcMesh, CE3D_Shader* _poShader, CMatrix4x4& _roPrjMatrix)
{
  //## begin CTexProjector::Setup%1018775600.body preserve=yes

	// Copy source data
 	oAuxMesh.BVol      = _roSrcMesh->BVol;
	oAuxMesh.eMeshType = _roSrcMesh->eMeshType;	
	oAuxMesh.Idxs      = _roSrcMesh->Idxs;
	oAuxMesh.VXs	   = _roSrcMesh->VXs;
	oAuxMesh.usNumIdxs = _roSrcMesh->usNumIdxs;
	oAuxMesh.usNumPrims= _roSrcMesh->usNumPrims;
	oAuxMesh.usNumVerts= _roSrcMesh->usNumVerts;	
	oAuxMesh.UVs	   = (CVect2*)_roSrcMesh->VXs;
	oAuxMesh.UVs2      = NULL;
	oAuxMesh.VCs       = NULL;						// _roSrcMesh->VCs;	
	oAuxMesh.VNs       = NULL;
	oAuxMesh.TNs       = NULL;
	
	// UVs
	/*
	if (_roSrcMesh->usNumVerts > iMaxUVs)
	{
		if (iMaxUVs)
			mDel []oAuxMesh.UVs;
		
		oAuxMesh.UVs = mNew CVect2[_roSrcMesh->usNumVerts];
		iMaxUVs = _roSrcMesh->usNumVerts;
	}

	// Project coordinates 
	CVect3	oUV;
	int		iV;
	for (iV=0;iV<_roSrcMesh->usNumVerts;iV++)
	{	
		// oUV.V4(oAuxMesh.VXs[iV].X(),oAuxMesh.VXs[iV].Y(),oAuxMesh.VXs[iV].Z(),1.0f);		
		oUV.Assign(oAuxMesh.VXs[iV]);		
		_roPrjMatrix.TransformVector(oUV);		

		// oAuxMesh.UVs[iV].V2(0.5f + 0.5f*oUV.X()/oUV.Z(),0.5f + 0.5f*oUV.Y()/oUV.Z());
		oAuxMesh.UVs[iV].V2(oUV.X()/oUV.Z(),oUV.Y()/oUV.Z());
	}
	*/
	SetShader(_poShader);
	SetMesh  (&oAuxMesh);	
  //## end CTexProjector::Setup%1018775600.body
}

void CTexProjector::Setup (CMesh* _roSrcMesh, CE3D_Shader* _poShader, CVect3& _roPos, CVect3& _roDir, float _fXSize, float _fYSize)
{
  //## begin CTexProjector::Setup%1019152544.body preserve=yes
	// Compute projection matrix
	CMatrix4x4 oPrjMat;
	
	// ...
	// ...
	// ...

	Setup(_roSrcMesh,_poShader,oPrjMat);
  //## end CTexProjector::Setup%1019152544.body
}

// Additional Declarations
  //## begin CTexProjector%3CB94617013A.declarations preserve=yes
  //## end CTexProjector%3CB94617013A.declarations

//## begin module%3CB94617013A.epilog preserve=yes
//## end module%3CB94617013A.epilog
