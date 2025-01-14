//## begin module%3C06CBDC022D.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3C06CBDC022D.cm

//## begin module%3C06CBDC022D.cp preserve=no
//## end module%3C06CBDC022D.cp

//## Module: CBoxEntity%3C06CBDC022D; Pseudo Package body
//## Source file: i:\Projects\GammaE\Game\Entities\CBoxEntity.cpp

//## begin module%3C06CBDC022D.additionalIncludes preserve=no
//## end module%3C06CBDC022D.additionalIncludes

//## begin module%3C06CBDC022D.includes preserve=yes
#include "Scene/GammaE_Scene.h"
#include "Game/Globals/Globals.h"
//## end module%3C06CBDC022D.includes

// CBoxEntity
#include "Game\Entities\CBoxEntity.h"
//## begin module%3C06CBDC022D.additionalDeclarations preserve=yes
static CMesh_Box		*gpoBoxMesh = NULL;
static CObject3D_Leaf	*gpoBoxLeaf = NULL;
//## end module%3C06CBDC022D.additionalDeclarations


// Class CBoxEntity 



CBoxEntity::CBoxEntity()
  //## begin CBoxEntity::CBoxEntity%.hasinit preserve=no
      : iState(0), poGrObj(NULL)
  //## end CBoxEntity::CBoxEntity%.hasinit
  //## begin CBoxEntity::CBoxEntity%.initialization preserve=yes
  //## end CBoxEntity::CBoxEntity%.initialization
{
  //## begin CBoxEntity::CBoxEntity%.body preserve=yes
	ResponseType = CGame_ePRT_Stop;
	CGraphBV_Manager::SetBVMode(eGraphBV_Box);

	if (! gpoBoxMesh)
	{
		// 1 graphic object for all the box entities
		// CGraphBV_Manager::SetBVMode(eGraphBV_Sphere);
		gpoBoxMesh = (CMesh_Box *)mNew CMesh_Box();
		gpoBoxLeaf = mNew CObject3D_Leaf();
		gpoBoxLeaf->SetMesh(gpoBoxMesh);
		gpoBoxLeaf->SetShader(CE3D_ShaderWH::poCreateShader("MetalicFloor"));			
	}
	
	// New graphic object	
	poGrObj = mNew CObject3D_Transf;
	poGrObj->SetObject(gpoBoxLeaf);	
	poGrObj->ComputeBoundVol();

	// Init physic object
	oColObj.Init(0,NULL,NULL,eCOL_CT_Dynamic,eCOL_TT_Tris,eCOL_TT_BV,poGrObj,64,5);

	// Add to game scene
	gDynObjs.iAddObject(poGrObj);
  //## end CBoxEntity::CBoxEntity%.body
}


CBoxEntity::~CBoxEntity()
{
  //## begin CBoxEntity::~CBoxEntity%.body preserve=yes
  //## end CBoxEntity::~CBoxEntity%.body
}



//## Other Operations (implementation)
void CBoxEntity::Think (float _fDelta)
{
  //## begin CBoxEntity::Think%1007074379.body preserve=yes

	// Set old position
	oColObj.OldPos.Assign(oColObj.Pos);

	// Setup speed
	oColObj.Speed.LineEq(oColObj.Speed,GRAVITY,_fDelta);

	// Setup pos
	oColObj.Pos.LineEq(oColObj.Pos,oColObj.Speed,_fDelta);

	if (! iState)
	{
		if (bCheckCollisions())
		{
			ComputeCollisionResponse();
				
			/*
			extern CMesh CameraMesh;
			CameraMesh.VXs = oColObj.GetTriList().VXs;
			CameraMesh.VNs = oColObj.GetTriList().VNs;
			CameraMesh.usNumPrims = oColObj.GetTriList().iNumTris;
			CameraMesh.usNumVerts = oColObj.GetTriList().iNumTris*3;
			CameraMesh.eMeshType  = E3D_MESH_NITRIS;
			CameraMesh.BVol = NULL;
			*/
		}
		else
		{				
			// Control whether the entity has reached the lowest height level
			if (oColObj.Pos.Z() <= -120.0f) Respawn();

			// Setup graphically the object
			poGrObj->SetPos(oColObj.Pos);
		}
	}
  //## end CBoxEntity::Think%1007074379.body
}

void CBoxEntity::Init (CVect3& _roPos, CVect3& _roSpeed)
{
  //## begin CBoxEntity::Init%1019293386.body preserve=yes

	// Setup graphic object
	poGrObj->SetPos(_roPos);

	// Setup physic object
	oColObj.Pos.Assign(_roPos);
	oColObj.OldPos.Assign(_roPos);
	oColObj.Speed.Assign(_roSpeed);

	iZombieTime = 0;
  //## end CBoxEntity::Init%1019293386.body
}

void CBoxEntity::Respawn ()
{
  //## begin CBoxEntity::Respawn%1007604303.body preserve=yes
	CVect3 oNewPos;
	CVect3 oNewSpeed;

	/*
	oNewPos.V3(200*((float)rand()/(float)RAND_MAX),
			   200*((float)rand()/(float)RAND_MAX),
	           _SCNHEIGHT_);
	*/

	oNewPos.V3(0.0f,0.0f,100.0f);

	oNewSpeed.V3(0.0f,0.0f,0.0f);

	Init(oNewPos,oNewSpeed);

	iZombieTime = 0;
  //## end CBoxEntity::Respawn%1007604303.body
}

// Additional Declarations
  //## begin CBoxEntity%3C06CBDC022D.declarations preserve=yes
  //## end CBoxEntity%3C06CBDC022D.declarations

//## begin module%3C06CBDC022D.epilog preserve=yes
//## end module%3C06CBDC022D.epilog
