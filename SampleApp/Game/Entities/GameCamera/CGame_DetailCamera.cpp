//## begin module%3C435D4603E3.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3C435D4603E3.cm

//## begin module%3C435D4603E3.cp preserve=no
//## end module%3C435D4603E3.cp

//## Module: CGame_DetailCamera%3C435D4603E3; Pseudo Package body
//## Source file: i:\Projects\GammaE\Game\Entities\GameCamera\CGame_DetailCamera.cpp

//## begin module%3C435D4603E3.additionalIncludes preserve=no
//## end module%3C435D4603E3.additionalIncludes

//## begin module%3C435D4603E3.includes preserve=yes
#include "Memory/GammaE_Mem.h"
#include "Game/Globals/Globals.h"
#include "Game/Entities/CGPEntityType.h"
//## end module%3C435D4603E3.includes

// CGame_DetailCamera
#include "Game\Entities\GameCamera\CGame_DetailCamera.h"
//## begin module%3C435D4603E3.additionalDeclarations preserve=yes
#define	_MAXTRIS_	5000
#define _BSIZE_		25.0f
//## end module%3C435D4603E3.additionalDeclarations


// Class CGame_DetailCamera 



CGame_DetailCamera::CGame_DetailCamera()
  //## begin CGame_DetailCamera::CGame_DetailCamera%.hasinit preserve=no
  //## end CGame_DetailCamera::CGame_DetailCamera%.hasinit
  //## begin CGame_DetailCamera::CGame_DetailCamera%.initialization preserve=yes
  //## end CGame_DetailCamera::CGame_DetailCamera%.initialization
{
  //## begin CGame_DetailCamera::CGame_DetailCamera%.body preserve=yes
  	CVect3 Maxs,Mins;
	Maxs.V3( _BSIZE_, _BSIZE_, _BSIZE_);
	Mins.V3(-_BSIZE_,-_BSIZE_,-_BSIZE_);
	
	ResponseType = CGame_ePRT_None;	
	
	CGraphBV_Manager::SetBVMode(eGraphBV_Sphere);

	CObject3D_Node	*pGrObj = mNew CObject3D_Node;
	pGrObj->poGetBoundVol()->Init(Maxs,Mins);

	oColObj.Init(CGPET_Camera,NULL,NULL,
				eCOL_CT_Dynamic,eCOL_TT_Tris,eCOL_TT_BV,
				pGrObj,_MAXTRIS_,0);
  //## end CGame_DetailCamera::CGame_DetailCamera%.body
}


CGame_DetailCamera::~CGame_DetailCamera()
{
  //## begin CGame_DetailCamera::~CGame_DetailCamera%.body preserve=yes
  //## end CGame_DetailCamera::~CGame_DetailCamera%.body
}



//## Other Operations (implementation)
void CGame_DetailCamera::SetCamera (CE3D_Camera *_Cam)
{
  //## begin CGame_DetailCamera::SetCamera%1011045655.body preserve=yes
	Cam = _Cam;
  //## end CGame_DetailCamera::SetCamera%1011045655.body
}

void CGame_DetailCamera::Think (float fDelta)
{
  //## begin CGame_DetailCamera::Think%1011045656.body preserve=yes
  	oColObj.OldPos = oColObj.Pos;
	oColObj.Pos    = Cam->Pos;
	
	oColObj.Speed.Assign(oColObj.Pos);
	oColObj.Speed.Sub   (oColObj.OldPos);

	if (bCheckCollisions()) 
	{
		oColObj.Reset ();
		int iNumTris = gCOLTrn_TLG.GetTriList(oColObj.GetTriList(),Cam->Pos,_BSIZE_);

		poDetailer->SetCamPos(Cam->Pos);
		poDetailer->SetVertexTris(oColObj.GetTriList().poVXs,iNumTris);
	}
	else
	{
		poDetailer->SetVertexTris(oColObj.GetTriList().poVXs,0);
	}	
  //## end CGame_DetailCamera::Think%1011045656.body
}

void CGame_DetailCamera::SetDetailer (CDetailer *_poDetailer)
{
  //## begin CGame_DetailCamera::SetDetailer%1011045657.body preserve=yes
	poDetailer = _poDetailer;
  //## end CGame_DetailCamera::SetDetailer%1011045657.body
}

// Additional Declarations
  //## begin CGame_DetailCamera%3C435D4603E3.declarations preserve=yes
  //## end CGame_DetailCamera%3C435D4603E3.declarations

//## begin module%3C435D4603E3.epilog preserve=yes
//## end module%3C435D4603E3.epilog
