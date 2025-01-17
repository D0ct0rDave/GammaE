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
#include "Game/GameGlobals/GameGlobals.h"

// #include "Game/Entities/CBoxEntity.h"
// #include "Game/Entities/CSphereEntity.h"
#include "Game/Collision/CTRNUtils.h"
//## end module%3B62D27300F0.includes

// CGameCamera
#include "Game\Entities\GameCamera\CGameCamera.h"
//## begin module%3B62D27300F0.additionalDeclarations preserve=yes
#define CAMCTRL_EPSILON		 0.001f
#define	CAMCTRL_DAMPTIME	 0.5f
#define CAMCTRL_DSTPC		 -15.0f
#define CAMCTRL_ZFACTOR		 2.5f

inline float Interp(float a,float b,float f)
{
	return (a + (b-a)*f);
}

#define _BSIZE_		25.0f

CMesh				goCameraMesh;
CObject3D_Leaf		goCameraLeaf;
CObject3D_Transf	goCameraTransf;

// CBoxEntity			*gpoCameraBox;
// CSphereEntity		*gpoCameraSphere;

#define				_FOLLOW_PLAYER_
//## end module%3B62D27300F0.additionalDeclarations


// Class CGameCamera 





CGameCamera::CGameCamera()
  //## begin CGameCamera::CGameCamera%.hasinit preserve=no
  //## end CGameCamera::CGameCamera%.hasinit
  //## begin CGameCamera::CGameCamera%.initialization preserve=yes
  //## end CGameCamera::CGameCamera%.initialization
{
  //## begin CGameCamera::CGameCamera%.body preserve=yes

	// Initialize graphic object
	goCameraMesh.usNumPrims = 0;
	goCameraMesh.usNumIdxs  = 0;
	goCameraMesh.usNumVerts = 0;

	goCameraLeaf.SetMesh(&goCameraMesh);
	goCameraLeaf.SetShader(NULL);

	goCameraTransf.SetObject(&goCameraLeaf);
	goDynObjs.iAddObject(&goCameraTransf);	// Add object to render	
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
	goCameraMesh.usNumPrims = 0;
	goCameraMesh.usNumVerts = 0;			

	#ifdef _FOLLOW_PLAYER_
	CVect3	NewPos;
	
	CVect3	PPos;
	PPos.Assign( gpoPlayerNode->roPos() );
	PPos.Add   (0.0f,0.0f,CAMCTRL_ZFACTOR);

	NewPos.LineEq(PPos,gpoPlayerNode->roDir(),CAMCTRL_DSTPC);	

	float fCurCamHeight = CorrectCamHeight(NewPos,PPos);
	NewPos.SetZ( fCurCamHeight );

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
	
	float fMinHeight = CTRNUtils::fGetHeight(Cam->Pos);
	if (Cam->Pos.Z() < fMinHeight+CAMCTRL_ZFACTOR) 
		Cam->Pos.SetZ(fMinHeight+CAMCTRL_ZFACTOR);
	
	Cam->Dir.Assign ( gpoPlayerNode->roDir());
	Cam->Side.Assign( gpoPlayerNode->roSide());
	Cam->Up.Assign  ( gpoPlayerNode->roUp());
	
	CVect3 oTarget;
	oTarget.Assign( gpoPlayerNode->roPos() );
	oTarget.Add(0.0f,0.0f,gpoPlayerNode->poGetBoundVol()->GetExtents().Z());
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
		fCurHeight = CTRNUtils::fGetHeight(fActX,fActY);
		
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
  //## end CGameCamera::SetCamera%1004042074.body
}

// Additional Declarations
  //## begin CGameCamera%3B62D27300F0.declarations preserve=yes
  //## end CGameCamera%3B62D27300F0.declarations

//## begin module%3B62D27300F0.epilog preserve=yes
//## end module%3B62D27300F0.epilog
