//## begin module%3BE874C8016B.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3BE874C8016B.cm

//## begin module%3BE874C8016B.cp preserve=no
//## end module%3BE874C8016B.cp

//## Module: SCNUt_ComputeBoundingBox%3BE874C8016B; Pseudo Package body
//## Source file: i:\Projects\GammaE\Scene\SceneUtils\ScnBBoxGen\SCNUt_ComputeBoundingBox.cpp

//## begin module%3BE874C8016B.additionalIncludes preserve=no
//## end module%3BE874C8016B.additionalIncludes

//## begin module%3BE874C8016B.includes preserve=yes
//## end module%3BE874C8016B.includes

// SCNUt_ComputeBoundingBox
#include "Scene\SceneUtils\ScnBBoxGen\SCNUt_ComputeBoundingBox.h"
//## begin module%3BE874C8016B.additionalDeclarations preserve=yes
//## end module%3BE874C8016B.additionalDeclarations


// Class SCNUt_ComputeBoundingBox 

SCNUt_ComputeBoundingBox::SCNUt_ComputeBoundingBox()
  //## begin SCNUt_ComputeBoundingBox::SCNUt_ComputeBoundingBox%.hasinit preserve=no
  //## end SCNUt_ComputeBoundingBox::SCNUt_ComputeBoundingBox%.hasinit
  //## begin SCNUt_ComputeBoundingBox::SCNUt_ComputeBoundingBox%.initialization preserve=yes
  //## end SCNUt_ComputeBoundingBox::SCNUt_ComputeBoundingBox%.initialization
{
  //## begin SCNUt_ComputeBoundingBox::SCNUt_ComputeBoundingBox%.body preserve=yes
  //## end SCNUt_ComputeBoundingBox::SCNUt_ComputeBoundingBox%.body
}


SCNUt_ComputeBoundingBox::~SCNUt_ComputeBoundingBox()
{
  //## begin SCNUt_ComputeBoundingBox::~SCNUt_ComputeBoundingBox%.body preserve=yes
  //## end SCNUt_ComputeBoundingBox::~SCNUt_ComputeBoundingBox%.body
}



//## Other Operations (implementation)
CBoundingBox * SCNUt_ComputeBoundingBox::poComputeBoundingBox (SCNUt_TriScene* _poScene)
{
  //## begin SCNUt_ComputeBoundingBox::poComputeBoundingBox%1005085993.body preserve=yes
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
			if (poVX->X() > oMaxs.X()) oMaxs.SetX(poVX->X());
			if (poVX->X() < oMins.X()) oMins.SetX(poVX->X());
			if (poVX->Y() > oMaxs.Y()) oMaxs.SetY(poVX->Y());
			if (poVX->Y() < oMins.Y()) oMins.SetY(poVX->Y());
			if (poVX->Z() > oMaxs.Z()) oMaxs.SetZ(poVX->Z());
			if (poVX->Z() < oMins.Z()) oMins.SetZ(poVX->Z());
			poVX++;
		}
	}
	
	static CBoundingBox oBox;
	oBox.Init(oMaxs,oMins);
	return(&oBox); 
  //## end SCNUt_ComputeBoundingBox::poComputeBoundingBox%1005085993.body
}

// Additional Declarations
  //## begin SCNUt_ComputeBoundingBox%3BE874C8016B.declarations preserve=yes
  //## end SCNUt_ComputeBoundingBox%3BE874C8016B.declarations

//## begin module%3BE874C8016B.epilog preserve=yes
//## end module%3BE874C8016B.epilog
