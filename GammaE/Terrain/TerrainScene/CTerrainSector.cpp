//## begin module%3AFEFE430136.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3AFEFE430136.cm

//## begin module%3AFEFE430136.cp preserve=no
//## end module%3AFEFE430136.cp

//## Module: CTerrainSector%3AFEFE430136; Pseudo Package body
//## Source file: i:\Projects\GammaE\Terrain\TerrainScene\CTerrainSector.cpp

//## begin module%3AFEFE430136.additionalIncludes preserve=no
//## end module%3AFEFE430136.additionalIncludes

//## begin module%3AFEFE430136.includes preserve=yes
//## end module%3AFEFE430136.includes

// CTerrainSector
#include "Terrain\TerrainScene\CTerrainSector.h"
//## begin module%3AFEFE430136.additionalDeclarations preserve=yes
//## end module%3AFEFE430136.additionalDeclarations


// Class CTerrainSector 











CTerrainSector::CTerrainSector()
  //## begin CTerrainSector::CTerrainSector%.hasinit preserve=no
      : fLODs(NULL), iLODs(NULL), HF(NULL), LM(NULL), TM(NULL), TB(NULL), Tess(NULL), fXYScale(0)
  //## end CTerrainSector::CTerrainSector%.hasinit
  //## begin CTerrainSector::CTerrainSector%.initialization preserve=yes
  //## end CTerrainSector::CTerrainSector%.initialization
{
  //## begin CTerrainSector::CTerrainSector%.body preserve=yes
	bFrustumTest = true;
	BVol = CGraphBV_Manager::poCreate();	
  //## end CTerrainSector::CTerrainSector%.body
}


CTerrainSector::~CTerrainSector()
{
  //## begin CTerrainSector::~CTerrainSector%.body preserve=yes
  //## end CTerrainSector::~CTerrainSector%.body
}



//## Other Operations (implementation)
void CTerrainSector::Render ()
{
  //## begin CTerrainSector::Render%989790237.body preserve=yes
	if (Tess) 
	{
		bool bEnableDefMode = gpoE3DRenderer->UsingDefferredMode();
		
		// Get local camera
		CMatrix4x4	M;
		CVect4		Pos;
		CVect3		CamPos;
		gpoE3DRenderer->GetCurrentMatrix(&M);
		Pos = M.GetColVector(3);
		CamPos.V3(-Pos.v[0],-Pos.v[1],-Pos.v[2]);
					
		gpoE3DRenderer->DisableDefferredMode();
		
			iLODs = (int   *)CE3D_RenderVars::pGetRenderVar("iLODs");
			fLODs = (float *)CE3D_RenderVars::pGetRenderVar("fLODs");
			
			Tess->SetCameraPos(CamPos);
			Tess->SetData(HF,LM,TM,TB,fLODs,iLODs,fXYScale);
			Tess->Render();
		
		if (bEnableDefMode) gpoE3DRenderer->EnableDefferredMode();
	}
  //## end CTerrainSector::Render%989790237.body
}

void CTerrainSector::ComputeBoundVol ()
{
  //## begin CTerrainSector::ComputeBoundVol%997221309.body preserve=yes
	BVol->Init(Maxs,Mins);
  //## end CTerrainSector::ComputeBoundVol%997221309.body
}

CGraphBV* CTerrainSector::poGetBoundVol ()
{
  //## begin CTerrainSector::poGetBoundVol%997221310.body preserve=yes
	return (BVol);
  //## end CTerrainSector::poGetBoundVol%997221310.body
}

void CTerrainSector::SetMaxsMins (CVect3& _Maxs, CVect3& _Mins)
{
  //## begin CTerrainSector::SetMaxsMins%1007327359.body preserve=yes
	Maxs.Assign(_Maxs);
	Mins.Assign(_Mins);
	
	BVol->Init(Maxs,Mins);
  //## end CTerrainSector::SetMaxsMins%1007327359.body
}

// Additional Declarations
  //## begin CTerrainSector%3AFEFE430136.declarations preserve=yes
  //## end CTerrainSector%3AFEFE430136.declarations

//## begin module%3AFEFE430136.epilog preserve=yes
//## end module%3AFEFE430136.epilog
