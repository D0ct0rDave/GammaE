




// SCNUt_ComputeBoundingBox
#include "ScnBBoxGen\SCNUt_ComputeBoundingBox.h"


// Class SCNUt_ComputeBoundingBox 

SCNUt_ComputeBoundingBox::SCNUt_ComputeBoundingBox()
        {
}


SCNUt_ComputeBoundingBox::~SCNUt_ComputeBoundingBox()
{
}



CBoundingBox * SCNUt_ComputeBoundingBox::poComputeBoundingBox (SCNUt_TriScene* _poScene)
{
  	CVect3 oMaxs,oMins;
	oMaxs.V3(-1e6f,-1e6f,-1e6f);
	oMins.V3( 1e6f, 1e6f, 1e6f);
	
	int		iTri;
	int		iVX;
	CVect3 *poVX;
	for (iTri=0;iTri<_poScene->NumTris;iTri++)
	{
		poVX = _poScene->Tris[iTri].VXs;
		for (iVX=0;iVX<3;iVX++)
		{			
			if (poVX->x > oMaxs.x) oMaxs.x = poVX->x;
			if (poVX->x < oMins.x) oMins.x = poVX->x;
			if (poVX->y > oMaxs.y) oMaxs.y = poVX->y;
			if (poVX->y < oMins.y) oMins.y = poVX->y;
			if (poVX->z > oMaxs.z) oMaxs.y = poVX->z;
			if (poVX->z < oMins.z) oMins.y = poVX->z;
			poVX++;
		}
	}
	
	static CBoundingBox oBox;
	oBox.Init(oMaxs,oMins);
	return(&oBox); 
}

// Additional Declarations
    
