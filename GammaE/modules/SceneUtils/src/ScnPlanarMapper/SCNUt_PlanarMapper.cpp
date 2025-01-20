




// SCNUt_PlanarMapper
#include "ScnPlanarMapper\SCNUt_PlanarMapper.h"


// Class SCNUt_PlanarMapper 

SCNUt_PlanarMapper::SCNUt_PlanarMapper()
        {
}


SCNUt_PlanarMapper::~SCNUt_PlanarMapper()
{
}



void SCNUt_PlanarMapper::PlanarMap (SCNUt_TriScene& _oTriScn)
{
  	
	// Normalize the scene
	SCNUt_TriScene	oTriScene;
	
	// Make a copy of the triangle scene
	oTriScene = _oTriScn;

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
	
	for (int iTri=0;iTri<_oTriScn.NumTris;iTri++)
	{		
		// Mirar la componente Z de la normal del triángulo
		CVect3 oNormal;
		oNormal.Normal(	_oTriScn.Tris[iTri].VXs[0],
						_oTriScn.Tris[iTri].VXs[1],
						_oTriScn.Tris[iTri].VXs[2]);
						
		if (oNormal.z < 0.0f) fVOfs = 0.5f; else fVOfs = 0;

		for (int iVX=0;iVX<3;iVX++)
		{
			fU = (_oTriScn.Tris[iTri].VXs[iVX].x - poBBox->Mins.x) / oDims.x;
			fV = (_oTriScn.Tris[iTri].VXs[iVX].y - poBBox->Mins.y) / oDims.y;

			_oTriScn.Tris[iTri].UVs[iVX].V2(fU,0.5f*fV + fVOfs);
		}
	}
}

// Additional Declarations
    
