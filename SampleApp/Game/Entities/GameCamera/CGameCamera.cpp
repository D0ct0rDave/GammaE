//## begin module%3B62D27300F0.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3B62D27300F0.cm

//## begin module%3B62D27300F0.cp preserve=no
//## end module%3B62D27300F0.cp

//## Module: CGameCamera%3B62D27300F0; Pseudo Package body
//## Source file: i:\Projects\GammaE\Game\Entities\GameCamera\CGameCamera.cpp

//## begin module%3B62D27300F0.additionalIncludes preserve=no
//## end module%3B62D27300F0.additionalIncludes

//## begin module%3B62D27300F0.includes preserve=yes
#include "Memory/GammaE_Mem.h"
#include "Game/Globals/Globals.h"

#include "Game/Entities/CBoxEntity.h"
#include "Game/Entities/CSphereEntity.h"
#include "Game/Entities/CGPEntityType.h"
//## end module%3B62D27300F0.includes

// CGameCamera
#include "Game\Entities\GameCamera\CGameCamera.h"
//## begin module%3B62D27300F0.additionalDeclarations preserve=yes
#define CAMCTRL_EPSILON		 0.001f
#define	CAMCTRL_DAMPTIME	 0.5f
#define CAMCTRL_DSTPC		 -100.0f
#define CAMCTRL_ZFACTOR		 50.0f

inline float Interp(float a,float b,float f)
{
	return (a + (b-a)*f);
}

#define _BSIZE_		25.0f

CMesh				gCameraMesh;
CObject3D_Leaf		gCameraLeaf;
CObject3D_Transf	gCameraTransf;

CObject3D_Transf	poCamGRObj;

CBoxEntity			*gCameraBox;
CSphereEntity		*gCameraSphere;

// #define				_FOLLOW_PLAYER_
//## end module%3B62D27300F0.additionalDeclarations


// Class CGameCamera 





CGameCamera::CGameCamera()
  //## begin CGameCamera::CGameCamera%.hasinit preserve=no
  //## end CGameCamera::CGameCamera%.hasinit
  //## begin CGameCamera::CGameCamera%.initialization preserve=yes
  //## end CGameCamera::CGameCamera%.initialization
{
  //## begin CGameCamera::CGameCamera%.body preserve=yes
	CVect3 Maxs,Mins;
	Maxs.V3( _BSIZE_, _BSIZE_, _BSIZE_);
	Mins.V3(-_BSIZE_,-_BSIZE_,-_BSIZE_);
	
	ResponseType = CGame_ePRT_Slide;
	// ResponseType = CGame_ePRT_Stop;


	// CGraphBV_Manager::SetBVMode(eGraphBV_Point);
	// CGraphBV_Manager::SetBVMode(eGraphBV_Sphere);
	CGraphBV_Manager::SetBVMode(eGraphBV_Box);

	CObject3D_Node	*pGrObj = mNew CObject3D_Node;
	pGrObj->poGetBoundVol()->Init(Maxs,Mins);
	poCamGRObj.SetObject(pGrObj);

	oColObj.Init(CGPET_Camera,NULL,NULL,
				eCOL_CT_Dynamic,eCOL_TT_Tris,eCOL_TT_BV,
				&poCamGRObj,256,5);

	// Initialize graphic object
	gCameraMesh.usNumPrims = 0;
	gCameraMesh.usNumIdxs  = 0;
	gCameraMesh.usNumVerts = 0;

	gCameraLeaf.SetMesh(&gCameraMesh);
	gCameraLeaf.SetShader(NULL);

	gCameraTransf.SetObject(&gCameraLeaf);
	gDynObjs.iAddObject(&gCameraTransf);	// Add object to render	

	// gCameraBox = mNew CBoxEntity;
	// gCameraSphere = mNew CSphereEntity;
  //## end CGameCamera::CGameCamera%.body
}


CGameCamera::~CGameCamera()
{
  //## begin CGameCamera::~CGameCamera%.body preserve=yes
  //## end CGameCamera::~CGameCamera%.body
}



//## Other Operations (implementation)
void CGameCamera::Think (float fDelta)
{
  //## begin CGameCamera::Think%996332271.body preserve=yes
	/*
	"Trucar" la posicion de la cámara para acercarse a la que debería de ser
	su posicion correcta y luego hacer un simple "look at"
	*/
	oColObj.OldPos = oColObj.Pos;
	oColObj.Pos    = Cam->Pos;

	oColObj.Speed.Assign(oColObj.Pos);
	oColObj.Speed.Sub   (oColObj.OldPos);
	oColObj.Speed.Scale (1.0f/ fDelta);

	gCameraMesh.usNumPrims = 0;
	gCameraMesh.usNumVerts = 0;			

	/*
	extern CObject3D			*poMapModel;
	CMesh *poMesh = ((CObject3D_Leaf *)poMapModel)->poGetMesh();
	
	CTriangle	oTri;
	CVect3		oNear;
	CVect3		oSpeed(0.0f,0.0f,0.0f);

	oTri.Init(poMesh->VXs);	
	oTri.ComputeAll();

	oNear = MATH_Utils::oNearestTriPoint(oColObj.Pos,oTri);
	
	gCameraBox->Init(oNear,oSpeed);
	*/

	/*if (bCheckCollisions()) 
	{	
		ComputeCollisionResponse();	
		Cam->Pos.Assign(oColObj.Pos);

		gCameraMesh.VXs			= oColObj.GetTriList().poVXs;
		gCameraMesh.VNs			= NULL;
		gCameraMesh.usNumPrims	= oColObj.GetTriList().iNumTris;
		gCameraMesh.usNumVerts	= oColObj.GetTriList().iNumTris*3;
		gCameraMesh.eMeshType	= E3D_MESH_NITRIS;
		gCameraMesh.BVol		= NULL;

		/*
		// Generate a plane from tris
		CPlane oPlane;
		CVect3 oSpeed(0.0f,0.0f,0.0f);
		CVect3 oPrjPoint;

		oPlane.GenerateFromPoints(gCameraMesh.VXs[0],gCameraMesh.VXs[1],gCameraMesh.VXs[2]);
		oPrjPoint = oPlane.ProjectPoint(oColObj.Pos);
		CTriangle oTri;
		
		oTri.Init(gCameraMesh.VXs);
		oTri.ComputeAll();
		oTri.Normal.Normalize();

		float fDist = MATH_Utils::fTriPointDistance(oTri,oColObj.Pos);
		gCameraBox->Init(oPrjPoint,oSpeed);
		*/
	// }

	poCamGRObj.SetPos(oColObj.Pos);

	#ifdef _FOLLOW_PLAYER_
	CVect3	NewPos;
	
	CVect3	PPos;
	PPos.Assign( gPlayerNode->roGetPos() );
	PPos.Add   (0.0f,0.0f,CAMCTRL_ZFACTOR);

	NewPos.LineEq(PPos,gPlayerNode->roGetDir(),CAMCTRL_DSTPC);	

	// float fCurCamHeight = CorrectCamHeight(NewPos,PPos);
	// NewPos.SetZ( fCurCamHeight );

	float fD_X    = NewPos.X() - Cam->Pos.X();
	float fD_Y    = NewPos.Y() - Cam->Pos.Y();
	float fD_Z    = NewPos.Z() - Cam->Pos.Z();
	float fFactor = fDelta/CAMCTRL_DAMPTIME;

	if (fabsf(fD_X) > CAMCTRL_EPSILON)
		Cam->Pos.SetX( Interp(Cam->Pos.X(),NewPos.X(),fFactor) );
	else
		Cam->Pos.SetX(NewPos.X());



	if (fabsf(fD_Y) > CAMCTRL_EPSILON)
		Cam->Pos.SetY( Interp(Cam->Pos.Y(),NewPos.Y(),fFactor) );
	else
		Cam->Pos.SetY(NewPos.Y());


	if (fabsf(fD_Z) > CAMCTRL_EPSILON)
		Cam->Pos.SetZ( Interp(Cam->Pos.Z(),NewPos.Z(),fFactor) );
	else
		Cam->Pos.SetZ(NewPos.Z());
	
	
	Cam->Dir.Assign ( gPlayerNode->roGetDir());
	Cam->Side.Assign( gPlayerNode->roGetSide());
	Cam->Up.Assign  ( gPlayerNode->roGetUp());
	
	CVect3 oTarget;
	oTarget.Assign( gPlayerNode->roGetPos() );
	oTarget.Add(0.0f,0.0f,gPlayerNode->poGetBoundVol()->GetExtents().Z());
	Cam->LookAt(oTarget);
	#endif
  //## end CGameCamera::Think%996332271.body
}

float CGameCamera::CorrectCamHeight (CVect3 &Src, CVect3 &Dst)
{
  //## begin CGameCamera::CorrectCamHeight%997742738.body preserve=yes
	CVect3 DistVect;

	DistVect.Assign(Dst);
	DistVect.Sub   (Src);

	float fDist  = DistVect.Module();
	float fStepD = fDist/5;
	
	float fStepX = DistVect.X()/ 5.0f;
	float fStepY = DistVect.Y()/ 5.0f;
	float fStepZ = DistVect.Z()/ 5.0f;
	
	float fActX  = Src.X() + fStepX;
	float fActY  = Src.Y() + fStepY;
	float fActZ  = Src.Z() + fStepZ;

	float fActD  = fStepD;

	float fCurHeight;	
	float fCamHeight = Src.Z();

	for (int cI=1;cI<5;cI++)
	{
		fCurHeight = CCOL_TRN_TriListGen::GetHeight(fActX,fActY);
		
		if (fActZ < fCurHeight)
		{
			fCamHeight = fDist*fCurHeight/(fDist-fActD);
			fActZ	   = fCamHeight;
			fStepZ	   = (Dst.Z() - fCamHeight) / (5-cI);
		}

		fActX += fStepX;
		fActY += fStepY;
		fActZ += fStepZ;
		fActD += fStepD;
	}

	return( fCamHeight );
  //## end CGameCamera::CorrectCamHeight%997742738.body
}

void CGameCamera::SetCamera (CE3D_Camera *_Cam)
{
  //## begin CGameCamera::SetCamera%1004042074.body preserve=yes
	Cam = _Cam;
	oColObj.Pos.Assign(_Cam->Pos);
	oColObj.OldPos.Assign(_Cam->Pos);
  //## end CGameCamera::SetCamera%1004042074.body
}

// Additional Declarations
  //## begin CGameCamera%3B62D27300F0.declarations preserve=yes
  //## end CGameCamera%3B62D27300F0.declarations

//## begin module%3B62D27300F0.epilog preserve=yes
//## end module%3B62D27300F0.epilog
