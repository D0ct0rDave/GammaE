//## begin module%3D11F886028B.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3D11F886028B.cm

//## begin module%3D11F886028B.cp preserve=no
//## end module%3D11F886028B.cp

//## Module: SCNUt_PlanarMapper%3D11F886028B; Pseudo Package body
//## Source file: i:\Projects\GammaE\Scene\SceneUtils\ScnPlanarMapper\SCNUt_PlanarMapper.cpp

//## begin module%3D11F886028B.additionalIncludes preserve=no
//## end module%3D11F886028B.additionalIncludes

//## begin module%3D11F886028B.includes preserve=yes
//## end module%3D11F886028B.includes

// SCNUt_PlanarMapper
#include "Scene\SceneUtils\ScnPlanarMapper\SCNUt_PlanarMapper.h"
//## begin module%3D11F886028B.additionalDeclarations preserve=yes
//## end module%3D11F886028B.additionalDeclarations


// Class SCNUt_PlanarMapper 

SCNUt_PlanarMapper::SCNUt_PlanarMapper()
  //## begin SCNUt_PlanarMapper::SCNUt_PlanarMapper%.hasinit preserve=no
  //## end SCNUt_PlanarMapper::SCNUt_PlanarMapper%.hasinit
  //## begin SCNUt_PlanarMapper::SCNUt_PlanarMapper%.initialization preserve=yes
  //## end SCNUt_PlanarMapper::SCNUt_PlanarMapper%.initialization
{
  //## begin SCNUt_PlanarMapper::SCNUt_PlanarMapper%.body preserve=yes
  //## end SCNUt_PlanarMapper::SCNUt_PlanarMapper%.body
}


SCNUt_PlanarMapper::~SCNUt_PlanarMapper()
{
  //## begin SCNUt_PlanarMapper::~SCNUt_PlanarMapper%.body preserve=yes
  //## end SCNUt_PlanarMapper::~SCNUt_PlanarMapper%.body
}



//## Other Operations (implementation)
void SCNUt_PlanarMapper::PlanarMap (SCNUt_TriScene& _roTriScn)
{
  //## begin SCNUt_PlanarMapper::PlanarMap%1024588005.body preserve=yes
	
	// Normalize the scene
	SCNUt_TriScene	oTriScene;
	
	// Make a copy of the triangle scene
	oTriScene = _roTriScn;

    // Compute object dimensions
    SCNUt_ComputeBoundingBox oBBoxCmp;
    CBoundingBox             *poBBox;

    poBBox = oBBoxCmp.poComputeBoundingBox(&oTriScene);

    // Get object dimensions
    CVect3 oDims;
    oDims.Assign(poBBox->Maxs);
    oDims.Sub   (poBBox->Mins);

	// Modify texcoords
	float fU,fV,fVOfs;	
	
	for (int iTri=0;iTri<_roTriScn.NumTris;iTri++)
	{		
		// Mirar la componente Z de la normal del triángulo
		CVect3 oNormal;
		oNormal.Normal(	_roTriScn.Tris[iTri].VXs[0],
						_roTriScn.Tris[iTri].VXs[1],
						_roTriScn.Tris[iTri].VXs[2]);
						
		if (oNormal.Z() < 0.0f) fVOfs = 0.5f; else fVOfs = 0;

		for (int iVX=0;iVX<3;iVX++)
		{
			fU = (_roTriScn.Tris[iTri].VXs[iVX].X() - poBBox->Mins.X()) / oDims.X();
			fV = (_roTriScn.Tris[iTri].VXs[iVX].Y() - poBBox->Mins.Y()) / oDims.Y();

			_roTriScn.Tris[iTri].UVs[iVX].V2(fU,0.5f*fV + fVOfs);
		}
	}
  //## end SCNUt_PlanarMapper::PlanarMap%1024588005.body
}

// Additional Declarations
  //## begin SCNUt_PlanarMapper%3D11F886028B.declarations preserve=yes
  //## end SCNUt_PlanarMapper%3D11F886028B.declarations

//## begin module%3D11F886028B.epilog preserve=yes
//## end module%3D11F886028B.epilog
