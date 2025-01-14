//## begin module%3CCD3E0403E4.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3CCD3E0403E4.cm

//## begin module%3CCD3E0403E4.cp preserve=no
//## end module%3CCD3E0403E4.cp

//## Module: CSphereEntity%3CCD3E0403E4; Pseudo Package body
//## Source file: i:\Projects\GammaE\Game\Entities\CSphereEntity.cpp

//## begin module%3CCD3E0403E4.additionalIncludes preserve=no
//## end module%3CCD3E0403E4.additionalIncludes

//## begin module%3CCD3E0403E4.includes preserve=yes
#include "Scene/GammaE_Scene.h"
#include "Game/Globals/Globals.h"
//## end module%3CCD3E0403E4.includes

// CSphereEntity
#include "Game\Entities\CSphereEntity.h"
//## begin module%3CCD3E0403E4.additionalDeclarations preserve=yes

static CMesh_Sphere		*gpoSphereMesh = NULL;
static CObject3D_Leaf	*gpoSphereLeaf = NULL;

//## end module%3CCD3E0403E4.additionalDeclarations


// Class CSphereEntity 


CSphereEntity::CSphereEntity()
  //## begin CSphereEntity::CSphereEntity%.hasinit preserve=no
      : poGrObj(NULL)
  //## end CSphereEntity::CSphereEntity%.hasinit
  //## begin CSphereEntity::CSphereEntity%.initialization preserve=yes
  //## end CSphereEntity::CSphereEntity%.initialization
{
  //## begin CSphereEntity::CSphereEntity%.body preserve=yes

	ResponseType = CGame_ePRT_Stop;
	CGraphBV_Manager::SetBVMode(eGraphBV_Sphere);

	if (! gpoSphereMesh)
	{
		// 1 graphic object for all the box entities		
		gpoSphereMesh = (CMesh_Sphere *)mNew CMesh_Sphere();
		gpoSphereLeaf = mNew CObject3D_Leaf();
		gpoSphereLeaf->SetMesh(gpoSphereMesh);
		gpoSphereLeaf->SetShader(CE3D_ShaderWH::poCreateShader("MetalicFloor"));
	}

	// New graphic object
	poGrObj = mNew CObject3D_Transf;
	poGrObj->SetObject(gpoSphereLeaf);	
	poGrObj->ComputeBoundVol();

	// Init physic object
	oColObj.Init(0,NULL,NULL,eCOL_CT_Dynamic,eCOL_TT_BV,eCOL_TT_BV,poGrObj,64,5);

	// Add to game scene
	gDynObjs.iAddObject(poGrObj);

  //## end CSphereEntity::CSphereEntity%.body
}


CSphereEntity::~CSphereEntity()
{
  //## begin CSphereEntity::~CSphereEntity%.body preserve=yes
  //## end CSphereEntity::~CSphereEntity%.body
}



//## Other Operations (implementation)
void CSphereEntity::Think (float _fDelta)
{
  //## begin CSphereEntity::Think%1020082681.body preserve=yes

	// Set old position
	oColObj.OldPos.Assign(oColObj.Pos);

	// Setup speed
	oColObj.Speed.LineEq(oColObj.Speed,GRAVITY,_fDelta);

	// Setup pos
	oColObj.Pos.LineEq(oColObj.Pos,oColObj.Speed,_fDelta);

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
  //## end CSphereEntity::Think%1020082681.body
}

void CSphereEntity::Init (CVect3& _roPos, CVect3& _roSpeed)
{
  //## begin CSphereEntity::Init%1020082682.body preserve=yes
  
	// Setup graphic object
	poGrObj->SetPos(_roPos);

	// Setup physic object
	oColObj.Pos.Assign(_roPos);
	oColObj.OldPos.Assign(_roPos);
	oColObj.Speed.Assign(_roSpeed);

	iZombieTime = 0;
  //## end CSphereEntity::Init%1020082682.body
}

void CSphereEntity::Respawn ()
{
  //## begin CSphereEntity::Respawn%1020082683.body preserve=yes
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

  //## end CSphereEntity::Respawn%1020082683.body
}

// Additional Declarations
  //## begin CSphereEntity%3CCD3E0403E4.declarations preserve=yes
  //## end CSphereEntity%3CCD3E0403E4.declarations

//## begin module%3CCD3E0403E4.epilog preserve=yes
//## end module%3CCD3E0403E4.epilog
