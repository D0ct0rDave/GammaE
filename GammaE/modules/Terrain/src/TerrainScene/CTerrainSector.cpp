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
    bFrustumTest = true;
    m_poBV = CGraphBV_Manager::poCreate();
}

CTerrainSector::~CTerrainSector()
{
    mDel BVol;
}

void CTerrainSector::Render ()
{
    if ( Tess )
    {
        bool bEnableDefMode = CGRenderer::I()->UsingDefferredMode();

        // Get local camera
        CMatrix4x4 M;
        CVect4 Pos;
        CGVect3 CamPos;
        CGRenderer::I()->GetWorldMatrix(&M);
        Pos = M.GetColVector(3);
        CamPos.Set(-Pos.x,-Pos.y,-Pos.z);

        CGRenderer::I()->DisableDefferredMode();

        iLODs = (int*)CE3D_RenderVars.poGetVar("iLODs");
        fLODs = (float*)CE3D_RenderVars.poGetVar("fLODs");

        Tess->SetCameraPos(CamPos);
        Tess->SetData(HF,LM,TM,TB,fLODs,iLODs,fXYScale);
        Tess->Render();

        if ( bEnableDefMode ) CGRenderer::I()->EnableDefferredMode();
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
    m_poBV->Init(Maxs,Mins);
}

CGraphBV* CTerrainSector::poGetBV ()
{
    return (m_poBV);
}

void CTerrainSector::SetMaxsMins (CGVect3& _Maxs, CGVect3& _Mins)
{
    Maxs.Assign(_Maxs);
    Mins.Assign(_Mins);

    m_poBV->Init(Maxs,Mins);
}

// Additional Declarations
