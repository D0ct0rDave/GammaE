




// CSkyBox
#include "SkyBox\CSkyBox.h"


// Class CSkyBox 






CSkyBox::CSkyBox()
        : poNode(NULL)
      {
}


CSkyBox::~CSkyBox()
{
  	/*
	for (int cSide=0;cSide<6;cSide++)
		Sides = mDel CMesh_Rect;		
	*/
}



void CSkyBox::InitSkyBox (float fSize, CVect3& Center, float fRoll, CE3D_Shader* *Materials)
{
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
	
	oMat.Scale(fSize,fSize,fSize);
	oMat.Rotate('z',fRoll);	
	oMat.Translate(Center);

	SetTransf(oMat);

	// Setup sky box as object
	SetObject(poNode);
}

// Additional Declarations
    
