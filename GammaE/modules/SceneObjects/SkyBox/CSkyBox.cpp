//## begin module%3B59802101A4.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3B59802101A4.cm

//## begin module%3B59802101A4.cp preserve=no
//## end module%3B59802101A4.cp

//## Module: CSkyBox%3B59802101A4; Pseudo Package body
//## Source file: i:\Projects\GammaE\SceneObjects\SkyBox\CSkyBox.cpp

//## begin module%3B59802101A4.additionalIncludes preserve=no
//## end module%3B59802101A4.additionalIncludes

//## begin module%3B59802101A4.includes preserve=yes
//## end module%3B59802101A4.includes

// CSkyBox
#include "SceneObjects\SkyBox\CSkyBox.h"
//## begin module%3B59802101A4.additionalDeclarations preserve=yes
//## end module%3B59802101A4.additionalDeclarations


// Class CSkyBox 






CSkyBox::CSkyBox()
  //## begin CSkyBox::CSkyBox%.hasinit preserve=no
      : poNode(NULL)
  //## end CSkyBox::CSkyBox%.hasinit
  //## begin CSkyBox::CSkyBox%.initialization preserve=yes
  //## end CSkyBox::CSkyBox%.initialization
{
  //## begin CSkyBox::CSkyBox%.body preserve=yes
  //## end CSkyBox::CSkyBox%.body
}


CSkyBox::~CSkyBox()
{
  //## begin CSkyBox::~CSkyBox%.body preserve=yes
	/*
	for (int cSide=0;cSide<6;cSide++)
		Sides = delete CMesh_Rect;		
	*/
  //## end CSkyBox::~CSkyBox%.body
}



//## Other Operations (implementation)
void CSkyBox::InitSkyBox (float fSize, CVect3& Center, float fRoll, CE3D_Shader* *Materials)
{
  //## begin CSkyBox::InitSkyBox%995721543.body preserve=yes
	poNode = mNew CObject3D_Node;
	
	// Store the 6 sides of the sky box	
	for (int cSide=0;cSide<6;cSide++)
	{
		// Create objects
		ObjSides [cSide] = mNew CObject3D_Leaf();
		MeshSides[cSide] = mNew CMesh_Rect;			
		MatsSides[cSide] = Materials[cSide];
		
		// bind material and mesh to object
		ObjSides[cSide]->SetShader(MatsSides[cSide]);
		ObjSides[cSide]->SetMesh  (MeshSides[cSide]);
		
		// bind leaf object to SkyBox 
		poNode->iAddObject(ObjSides[cSide]);
	}

	// Front/back
	MeshSides[0]->VXs[0].V3( 1,-1,-1);
	MeshSides[0]->VXs[1].V3(-1,-1,-1);
	MeshSides[0]->VXs[2].V3(-1,-1, 1);
	MeshSides[0]->VXs[3].V3( 1,-1, 1);
	MeshSides[0]->UVs[0].V2(1,1);
	MeshSides[0]->UVs[1].V2(0,1);
	MeshSides[0]->UVs[2].V2(0,0);
	MeshSides[0]->UVs[3].V2(1,0);

	MeshSides[1]->VXs[0].V3( 1, 1, 1);
	MeshSides[1]->VXs[1].V3(-1, 1, 1);
	MeshSides[1]->VXs[2].V3(-1, 1,-1);
	MeshSides[1]->VXs[3].V3( 1, 1,-1);	
	MeshSides[1]->UVs[0].V2(0,0);	
	MeshSides[1]->UVs[1].V2(1,0);
	MeshSides[1]->UVs[2].V2(1,1);
	MeshSides[1]->UVs[3].V2(0,1);
	
	// Right/Left	
	MeshSides[2]->VXs[0].V3(-1, 1,-1);
	MeshSides[2]->VXs[1].V3(-1, 1, 1);
	MeshSides[2]->VXs[2].V3(-1,-1, 1);
	MeshSides[2]->VXs[3].V3(-1,-1,-1);
	MeshSides[2]->UVs[0].V2(0,1);	
	MeshSides[2]->UVs[1].V2(0,0);
	MeshSides[2]->UVs[2].V2(1,0);
	MeshSides[2]->UVs[3].V2(1,1);

	MeshSides[3]->VXs[0].V3( 1, 1, 1);
	MeshSides[3]->VXs[1].V3( 1, 1,-1);
	MeshSides[3]->VXs[2].V3( 1,-1,-1);
	MeshSides[3]->VXs[3].V3( 1,-1, 1);
	MeshSides[3]->UVs[0].V2(1,0);	
	MeshSides[3]->UVs[1].V2(1,1);
	MeshSides[3]->UVs[2].V2(0,1);
	MeshSides[3]->UVs[3].V2(0,0);

	// Up/Down
	MeshSides[4]->VXs[0].V3(-1, 1, 1);
	MeshSides[4]->VXs[1].V3( 1, 1, 1);
	MeshSides[4]->VXs[2].V3( 1,-1, 1);
	MeshSides[4]->VXs[3].V3(-1,-1, 1);
	MeshSides[4]->UVs[0].V2(0,1);	
	MeshSides[4]->UVs[1].V2(0,0);
	MeshSides[4]->UVs[2].V2(1,0);
	MeshSides[4]->UVs[3].V2(1,1);
	
	MeshSides[5]->VXs[0].V3( 1, 1,-1);
	MeshSides[5]->VXs[1].V3(-1, 1,-1);
	MeshSides[5]->VXs[2].V3(-1,-1,-1);
	MeshSides[5]->VXs[3].V3( 1,-1,-1);
	MeshSides[5]->UVs[0].V2(0,0);	
	MeshSides[5]->UVs[1].V2(1,0);
	MeshSides[5]->UVs[2].V2(1,1);
	MeshSides[5]->UVs[3].V2(0,1);
	
	// Setup transformation	
	CMatrix4x4 oMat;
	
	oMat.Scale3f(fSize,fSize,fSize);
	oMat.RotateAxis('z',fRoll);	
	oMat.Translate(Center);

	SetTransf(oMat);

	// Setup sky box as object
	SetObject(poNode);
  //## end CSkyBox::InitSkyBox%995721543.body
}

// Additional Declarations
  //## begin CSkyBox%3B59802101A4.declarations preserve=yes
  //## end CSkyBox%3B59802101A4.declarations

//## begin module%3B59802101A4.epilog preserve=yes
//## end module%3B59802101A4.epilog
