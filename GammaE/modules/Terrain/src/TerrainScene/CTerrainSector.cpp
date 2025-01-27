// -----------------------------------------------------------------------------
/*! \class
 *  \brief
 *  \author David M&aacute;rquez de la Cruz
 *  \version 1.5
 *  \date 1999-2009
 *  \par Copyright (c) 1999 David M&aacute;rquez de la Cruz
 *  \par GammaE License
 */
// -----------------------------------------------------------------------------
// %X% %Q% %Z% %W%
#include "GammaE_Mem.h"

// CTerrainSector
#include "TerrainScene\CTerrainSector.h"

// Class CTerrainSector

CTerrainSector::CTerrainSector() : fLODs(NULL), iLODs(NULL), HF(NULL), LM(NULL), TM(NULL), TB(NULL), Tess(NULL), fXYScale(0)
{
    m_poSectorBV = mNew CGGraphBVAABB();
    SetBV(m_poSectorBV);
}

CTerrainSector::~CTerrainSector()
{
    mDel m_poSectorBV;
}

void CTerrainSector::Render ()
{
    if ( Tess )
    {
        bool bEnableDefMode = CGRenderer::I()->bIsUsingDefferredMode();

        // Get local camera
        CGMatrix4x4 M;
        CGVect4 Pos;
        CGVect3 CamPos;
        CGRenderer::I()->GetWorldMatrix(&M);
        Pos = M.oGetCol(3);
        CamPos.Set(-Pos.x,-Pos.y,-Pos.z);

        CGRenderer::I()->DisableDefferredMode();

        iLODs = (int*)CGRenderVars::I()->poGetVar("iLODs");
        fLODs = (float*)CGRenderVars::I()->poGetVar("fLODs");

        Tess->SetCameraPos(CamPos);
        Tess->SetData(HF,LM,TM,TB,fLODs,iLODs,fXYScale);
        Tess->Render();

        if ( bEnableDefMode ) CGRenderer::I()->EnableDefferredMode();
    }
}

void CTerrainSector::SetMaxsMins (CGVect3& _Maxs, CGVect3& _Mins)
{
    Maxs.Assign(_Maxs);
    Mins.Assign(_Mins);

    m_poSectorBV->Init(Maxs,Mins);
}

// Additional Declarations
