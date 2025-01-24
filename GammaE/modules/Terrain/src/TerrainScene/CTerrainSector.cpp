//	  %X% %Q% %Z% %W%
#include "GammaE_Mem.h"

// CTerrainSector
#include "TerrainScene\CTerrainSector.h"


// Class CTerrainSector 

CTerrainSector::CTerrainSector() : fLODs(NULL), iLODs(NULL), HF(NULL), LM(NULL), TM(NULL), TB(NULL), Tess(NULL), fXYScale(0)
{
  	bFrustumTest = true;
	BVol = CGraphBV_Manager::poCreate();	
}


CTerrainSector::~CTerrainSector()
{
  	mDel BVol;
}



void CTerrainSector::Render ()
{
  	if (Tess) 
	{
		bool bEnableDefMode = CGRenderer::I()->UsingDefferredMode();
		
		// Get local camera
		CMatrix4x4	M;
		CVect4		Pos;
		CVect3		CamPos;
		CGRenderer::I()->GetWorldMatrix(&M);
		Pos = M.GetColVector(3);
		CamPos.V3(-Pos.x,-Pos.y,-Pos.z);
					
		CGRenderer::I()->DisableDefferredMode();
		
			iLODs = (int   *)CE3D_RenderVars.poGetVar("iLODs");
			fLODs = (float *)CE3D_RenderVars.poGetVar("fLODs");
			
			Tess->SetCameraPos(CamPos);
			Tess->SetData(HF,LM,TM,TB,fLODs,iLODs,fXYScale);
			Tess->Render();
		
		if (bEnableDefMode) CGRenderer::I()->EnableDefferredMode();
	}
}

CGraphBV* CTerrainSector::poCreateBoundVol()
{
  	eGraphBV_TypeID eOldType = CGraphBV_Manager::eGetBVMode();
	CGraphBV_Manager::SetBVMode(eGraphBV_Box);

  		CGraphBV* poBVol = CGraphBV_Manager::poCreate();

	CGraphBV_Manager::SetBVMode(eOldType);	
	return(poBVol);
}

void CTerrainSector::ComputeBoundVol ()
{
  	BVol->Init(Maxs,Mins);
}

CGraphBV* CTerrainSector::poGetBoundVol ()
{
  	return (BVol);
}

void CTerrainSector::SetMaxsMins (CVect3& _Maxs, CVect3& _Mins)
{
  	Maxs.Assign(_Maxs);
	Mins.Assign(_Mins);
	
	BVol->Init(Maxs,Mins);
}

// Additional Declarations
    
