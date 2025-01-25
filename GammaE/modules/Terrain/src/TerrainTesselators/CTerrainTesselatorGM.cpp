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

// CTerrainTesselatorGM
#include "TerrainTesselators\CTerrainTesselatorGM.h"

#define TSL_UGM_TRISTRIP

// -----------------------------------------------------------------------------
inline int iLog2(int x)
{
    int Res = -1;
    while ( x )
    {
        x >>= 1;
        Res++;
    }
    return(Res);
}
// -----------------------------------------------------------------------------
inline float fInterpolate(float _fA,float _fB,float _fFactor)
{
    return( _fA + _fFactor * (_fB - _fA) );
    // return(_fA*(1.0f - _fFactor) + _fB*_fFactor );
}
// -----------------------------------------------------------------------------
inline float fSelectInterpolationFactor(float _fALOD,float _fBLOD)
{
    // Get factor from lower LOD sector (for convenion)
    if ( _fALOD > _fBLOD )
        return(_fALOD - (int)_fALOD);
    else
        return(_fBLOD - (int)_fBLOD);
    /*
       if (_fALOD > _fBLOD)
        return(_fALOD - floor(_fALOD));
       else
        return(_fBLOD - floor(_fBLOD));
     */
}

// Class CTerrainTesselatorGM

CTerrainTesselatorGM::CTerrainTesselatorGM()
    : HData(NULL), LData(NULL), VXs(NULL), VCs(NULL), UVs(NULL), Idxs(NULL), MaxVertexs(0), Mesh(NULL), uiSectorRes(0), fTileLODPar(0)
{
}

CTerrainTesselatorGM::~CTerrainTesselatorGM()
{
    Invalidate();
}

void CTerrainTesselatorGM::Init (int iMaxVertexs)
{
    MaxVertexs = iMaxVertexs;

    HData = mNew float [MaxVertexs  ];
    LData = mNew float [MaxVertexs * 3];

    Mesh = mNew CGMesh;

    #ifdef TSL_UGM_TRISTRIP

    Mesh->Init( MaxVertexs,
                2 * MaxVertexs,
                E3D_MESH_TRISTRIPS,
                MESH_FIELD_VERTEXS | MESH_FIELD_UVCOORDS | MESH_FIELD_COLORS | MESH_FIELD_INDEXES);
    #else

    Mesh->Init( MaxVertexs,
                2 * MaxVertexs,
                E3D_MESH_TRIS,
                MESH_FIELD_VERTEXS | MESH_FIELD_UVCOORDS | MESH_FIELD_COLORS | MESH_FIELD_INDEXES);

    #endif

    VXs = Mesh->m_poVX;
    VCs = Mesh->m_poVC;
    UVs = Mesh->m_poUV;
    Idxs = Mesh->m_pusIdx;
}

void CTerrainTesselatorGM::Invalidate ()
{
    if ( MaxVertexs )
    {
        // Free previously allocated resources
        if ( HData ) mDel [] HData;
        HData = NULL;
        if ( LData ) mDel [] LData;
        LData = NULL;
        if ( Mesh ) mDel Mesh;
        Mesh = NULL;

        VXs = NULL;
        VCs = NULL;
        UVs = NULL;
        Idxs = NULL;
    }
}

void CTerrainTesselatorGM::GenerateVertexData ()
{
    unsigned int cI,cJ;
    float fSpaceXCur,fSpaceYCur;
    float* pH = HData;
    CGVect3* pVX = VXs;
    float fSpaceStep;

    // Spatial distance betweem two adjacent vertexs
    fSpaceStep = fXYScale * (1 << iLODs[0]);

    // Generate vertex data
    fSpaceYCur = 0;
    for ( cJ = 0; cJ < uiSectorRes; cJ++ )
    {
        fSpaceXCur = 0;
        for ( cI = 0; cI < uiSectorRes; cI++ )
        {
            pVX->V3(fSpaceXCur,fSpaceYCur,*pH);

            fSpaceXCur += fSpaceStep;
            pH++;
            pVX++;
        }

        fSpaceYCur += fSpaceStep;
    }

    CGVect3 Maxs,Mins;
    Mins.Set( 0,0,HF->GetMinHeight() );
    Maxs.Set( fSpaceStep * (uiSectorRes & 0xfffffffe),fSpaceStep * (uiSectorRes & 0xfffffffe),HF->GetMaxHeight() );
    Mesh->poGetBoundVol()->Init(Maxs,Mins);
}

void CTerrainTesselatorGM::GenerateVertexColorData ()
{
    unsigned int cI,cJ;
    float* pL = LData;
    CGColor* pVC = VCs;

    // Generate Color Map
    for ( cJ = 0; cJ < uiSectorRes; cJ++ )
        for ( cI = 0; cI < uiSectorRes; cI++ )
        {
            pVC->r = pL[0];
            pVC->g = pL[1];
            pVC->b = pL[2];
            pVC->a = 1.0f;

            pL += 3;
            pVC++;
        }
}

void CTerrainTesselatorGM::GenerateLightData ()
{
    LM->GetLODData(iLODs[0],LData);
}

void CTerrainTesselatorGM::GenerateGlobalCoordData ()
{
    unsigned int cI,cJ;
    int iVXPos;
    float fTexUCur;
    float fTexVCur;
    float fGMapStep;
    CGVect2* pUV = UVs;

    // Global Map texture step
    const float fUVOfs = 2.0f / 256.0f;
    fGMapStep = (1.0f - 2 * fUVOfs) / (float)(uiSectorRes & 0xfffffffe);

    iVXPos = 0;
    fTexVCur = fUVOfs;
    for ( cJ = 0; cJ < uiSectorRes; cJ++ )
    {
        fTexUCur = fUVOfs;
        for ( cI = 0; cI < uiSectorRes; cI++ )
        {
            pUV->V2(fTexUCur,fTexVCur);

            fTexUCur += fGMapStep;
            pUV++;
        }

        fTexVCur += fGMapStep;
    }
}

int CTerrainTesselatorGM::GetTileLOD (float fDistance, int iMaxLODs)
{
    #ifndef _e_
    #define _e_ 2.7182818284590452353602874713527
    #endif

    // return( iMaxLODs * (1.0f - pow(_e_,-1*(fTileLODPar/2500.0f)*fDistance)) );
    int iLOD = iMaxLODs * ( fDistance / (fTileLODPar * 500.0f) );
    if ( iLOD >= iMaxLODs ) iLOD = iMaxLODs - 1;
    return(iLOD);
}

void CTerrainTesselatorGM::TesselateGrid ()
{
    // -------------------------------------------
    // Generate strips:
    // -------------------------------------------
    int iIdx;
    int iVXPos1,iVXPos2;
    unsigned int j,i;
    int iStep;

    #ifdef TSL_UGM_TRISTRIP

    iIdx = 0;

    iVXPos1 = 0;
    iVXPos2 = uiSectorRes;

    Idxs[iIdx++] = iVXPos1;                    // For back face culling ->
    Idxs[iIdx++] = iVXPos1;
    for ( j = 0; j < uiSectorRes - 1; j++ )
    {
        Idxs[iIdx++] = iVXPos1;

        for ( i = 0; i < uiSectorRes; i++ )
        {
            // first tri
            Idxs[iIdx++] = iVXPos1;
            Idxs[iIdx++] = iVXPos2;

            // update vertexes
            iVXPos1++;
            iVXPos2++;
        }

        Idxs[iIdx++] = iVXPos2 - 1;
    }

    Mesh->m_eMeshType = E3D_MESH_TRISTRIPS;
    Mesh->m_uiNumIdxs = iIdx;
    Mesh->m_uiNumPrims = iIdx - 2;

    #else

    iIdx = 0;

    iVXPos1 = 0;
    iVXPos2 = uiSectorRes;

    for ( j = 0; j < uiSectorRes - 1; j++ )
    {
        for ( i = 0; i < uiSectorRes - 1; i++ )
        {
            // first tri
            Idxs[iIdx++] = iVXPos1;
            Idxs[iIdx++] = iVXPos1 + 1;
            Idxs[iIdx++] = iVXPos2;

            // second tri
            Idxs[iIdx++] = iVXPos1 + 1;
            Idxs[iIdx++] = iVXPos2 + 1;
            Idxs[iIdx++] = iVXPos2;

            // update vertexes
            iVXPos1++;
            iVXPos2++;
        }

        iVXPos1++;
        iVXPos2++;
    }

    Mesh->m_eMeshType = E3D_MESH_TRIS;
    Mesh->m_uiNumIdxs = iIdx;
    Mesh->m_uiNumPrims = iIdx / 3;

    #endif
}

void CTerrainTesselatorGM::Render ()
{
    SetupRenderVariables ();

    GenerateHeightData();
    GenerateVertexData();

    GenerateLightData();
    GenerateVertexColorData();

    GenerateGlobalCoordData ();
    TesselateGrid ();

    SetupTileMaterial();

    CGRenderer::I()->RenderMesh(Mesh, poTileMaterial);
}

void CTerrainTesselatorGM::SetupRenderVariables ()
{
    uiSectorRes = ( (HF->GetResolution() & 0xfffffffe) >> iLODs[0] ) + 1;
}

void CTerrainTesselatorGM::GenerateHeightData ()
{
    HF->GetLODData(iLODs[0],HData);

    unsigned int cSegment;
    unsigned int uiInnerPoints = (uiSectorRes >> 1);
    unsigned int uiLastSeg = (uiSectorRes - 3);

    float fFactor = fLODs[0] - iLODs[0];

    switch ( uiSectorRes )
    {
        case 2:
        // Controled in other part of the code
        break;

        case 3:                    // Only the central point
        HData[4] = fInterpolate(HData[4],(HData[2] + HData[6]) * 0.5f,fFactor);

        GenerateHeightData_Horizontal_3pN(1,0);                    // North LOD
        GenerateHeightData_Vertical_3pN  (2,2);                    // East LOD
        GenerateHeightData_Horizontal_3pN(3,2);                    // South LOD
        GenerateHeightData_Vertical_3pN  (4,0);                    // West LOD
        return;

        default:                    // 5 or more points
        for ( cSegment = 2; cSegment <= uiLastSeg; cSegment += 2 )
        {
            GenerateHeightData_Vertical  (cSegment,uiInnerPoints,fFactor);
            GenerateHeightData_Horizontal(cSegment,uiInnerPoints,fFactor);
        }

        GenerateHeightData_Inner(fFactor);

        GenerateHeightData_Horizontal_N(1,0            );                    // North
        GenerateHeightData_Vertical_N  (2,uiSectorRes - 1);                    // East
        GenerateHeightData_Horizontal_N(3,uiSectorRes - 1);                    // South
        GenerateHeightData_Vertical_N  (4,0            );                    // West
        break;
    }
}

void CTerrainTesselatorGM::GenerateHeightData_Inner (float fFactor)
{
    unsigned int cJ,cI;
    unsigned int uiQuads = (uiSectorRes >> 1);
    unsigned int uiStride = uiSectorRes + 1;
    float* h0,* h1,* h2;

    // Diagonal tri is from upper right to bottom left
    h0 = HData + 2;
    h1 = h0 + uiSectorRes - 1;
    h2 = h1 + uiSectorRes - 1;

    for ( cJ = 0; cJ < uiQuads; cJ++ )
    {
        for ( cI = 0; cI < uiQuads; cI++ )
        {
            // *h1 += (((*h0 + *h2)*0.5f - *h1) * _fFactor);
            *h1 = fInterpolate(*h1, (*h0 + *h2) * 0.5f,fFactor);

            h0 += 2;
            h1 += 2;
            h2 += 2;
        }

        h0 += uiStride;
        h1 += uiStride;
        h2 += uiStride;
    }
}

void CTerrainTesselatorGM::GenerateHeightData_Horizontal_3pN (int iNeight, int iY)
{
    float* fH = &HData[iY * 3];
    float fInterpolation = (fH[0] + fH[2]) * 0.5f;
    float c05;
    float fFactor;

    // 3 cases: LOD[0] <  LOD[_uiLOD]
    // LOD[0] == LOD[_uiLOD]
    // LOD[0] >  LOD[_uiLOD]
    if ( iLODs[0] >= iLODs[iNeight] )
    {
        fFactor = fSelectInterpolationFactor(fLODs[0],fLODs[iNeight]);
        c05 = fH[1];
        fH[1] = fInterpolate(c05,fInterpolation,fFactor);
        return;
    }
    else
    {
        // The neighbourg has only 2 vertices: interpolate between them
        fH[1] = fInterpolation;
        return;
    }
}

void CTerrainTesselatorGM::GenerateHeightData_Vertical_3pN (int iNeight, int iX)
{
#define     fH(y)    HData[(y) * uiSectorRes + iX]

    float fInterpolation = ( fH(0) + fH(2) ) * 0.5f;
    float c05;
    float fFactor;

    // 3 cases: LOD[0] <  LOD[_uiLOD]   // better detail than neigh
    // LOD[0] == LOD[_uiLOD]   // equal detail than neigh
    // LOD[0] >  LOD[_uiLOD]   // lower

    if ( iLODs[0] >= iLODs[iNeight] )
    {
        c05 = fH(1);
        fFactor = fSelectInterpolationFactor(fLODs[0],fLODs[iNeight]);
        fH(1) = fInterpolate(c05,fInterpolation,fFactor);
        return;
    }
    else
    {
        // The neighbourg has only 2 vertices: interpolate between them
        fH(1) = fInterpolation;
    }

    #undef fH
}

void CTerrainTesselatorGM::GenerateHeightData_Horizontal_N (int iNeight, int iY)
{
    unsigned int cJ,cJx2,cJx2_1,cJ_1x2,cJx4;
    unsigned int uiInnerPoints = (uiSectorRes >> 1);                    // Num intermediate points
    unsigned int uiInnerPointsNextLOD = (uiInnerPoints >> 1);                    // Num intermediate points next LOD
    float c0,c05,c1;
    float fInterpolation;
    float fFactor;
    float* fH;

    // Control special case
    fH = &HData[iY * uiSectorRes];

    // Control neighbours
    if ( iLODs[0] < iLODs[iNeight] )
    {
        // The current LOD is greater than the neighbour
        fFactor = fLODs[iNeight] - (float)iLODs[iNeight];

        for ( cJ = 0; cJ < uiInnerPointsNextLOD; cJ++ )
        {
            cJx4 = cJ << 2;

            c0 = fH[cJx4  ];
            c05 = fH[cJx4 + 2];
            c1 = fH[cJx4 + 4];

            fInterpolation = fInterpolate(c05,(c0 + c1) * 0.5f,fFactor);

            fH[cJx4 + 1] = (c0 + fInterpolation) * 0.5f;
            fH[cJx4 + 2] = fInterpolation;
            fH[cJx4 + 3] = (fInterpolation + c1) * 0.5f;
        }
    }
    else
    {
        // Equal integer level of detail or LOD(Current) > LOD(Neight)
        fFactor = fSelectInterpolationFactor(fLODs[0],fLODs[iNeight]);
        GenerateHeightData_Horizontal(iY,uiInnerPoints,fFactor);
    }
}

void CTerrainTesselatorGM::GenerateHeightData_Vertical_N (int iNeight, int iX)
{
#define     fH(y)    HData[(y) * uiSectorRes + iX]

    unsigned int cJ,cJx4;
    unsigned int uiInnerPoints = (uiSectorRes >> 1);                    // Num intermediate points
    unsigned int uiInnerPointsNextLOD = (uiInnerPoints >> 1);                    // Num intermediate points next LOD
    float c0,c05,c1;
    float fInterpolation;
    float fFactor;

    // Control neighbours
    if ( iLODs[0] < iLODs[iNeight] )
    {
        // The current LOD is greater than the neighbour
        fFactor = fLODs[iNeight] - (float)iLODs[iNeight];

        for ( cJ = 0; cJ < uiInnerPointsNextLOD; cJ++ )
        {
            cJx4 = cJ << 2;

            c0 = fH(cJx4  );
            c05 = fH(cJx4 + 2);
            c1 = fH(cJx4 + 4);

            fInterpolation = fInterpolate(c05,(c0 + c1) * 0.5f,fFactor);

            fH(cJx4 + 1) = (c0 + fInterpolation) * 0.5f;
            fH(cJx4 + 2) = fInterpolation;
            fH(cJx4 + 3) = (fInterpolation + c1) * 0.5f;
        }
    }
    else
    {
        // Equal integer level of detail or LOD(Current) > LOD(Neight)
        fFactor = fSelectInterpolationFactor(fLODs[0],fLODs[iNeight]);
        GenerateHeightData_Vertical(iX,uiInnerPoints,fFactor);
    }

    #undef fH
}

void CTerrainTesselatorGM::GenerateHeightData_Horizontal (int iY, int iRes, float fFactor)
{
    unsigned int cI,cI2;
    float* fH = &HData[iY * uiSectorRes];

    cI2 = 1;
    for ( cI = 0; cI < iRes; cI++ )
    {
        fH[cI2] = fInterpolate(fH[cI2],(fH[cI2 - 1] + fH[cI2 + 1]) * 0.5f,fFactor);
        cI2 += 2;
    }
}

void CTerrainTesselatorGM::GenerateHeightData_Vertical (int iX, int iRes, float fFactor)
{
#define     fH(y)    HData[(y) * uiSectorRes + iX]

    unsigned int cJ,cJ2;
    // iRes--;
    cJ2 = 1;
    for ( cJ = 0; cJ < iRes; cJ++ )
    {
        fH(cJ2) = fInterpolate(fH(cJ2),( fH(cJ2 - 1) + fH(cJ2 + 1) ) * 0.5f,fFactor);
        cJ2 += 2;
    }
    #undef fH
}

void CTerrainTesselatorGM::SetupTileMaterial ()
{
    float fDist;
    CGVect3 Center;
    CTile       &Tile = (CTile &)TM->GetValue(0,0);
    float fSectorSize = (HF->GetResolution() & 0xfffffffe) * fXYScale;

    // Center value:
    // X = Res /2
    // Y = Res /2
    // Pos = (Y*Res)+ X
    // Pos = Res * (Res/2) + Res/2
    // Pos = (Res + 1)*Res / 2
    Center.Set(fSectorSize * 0.5f,fSectorSize * 0.5f,HData[ (uiSectorRes + 1) * (uiSectorRes >> 1) ]);

    CGVect3 oDiff;
    oDiff.Assign(Center);
    oDiff.Sub(Cam);
    if ( oDiff.x > oDiff.y ) fDist = oDiff.y;
    else fDist = oDiff.x;

    // fDist = Center.Distance(Cam);
    // int   LOD  = GetTileLOD(fDist,TB->GetMaxLODs());

    CGShader* poSh = TB->poGetTileMaterial(Tile.TileIdx,0);
    CE3D_ShIns_TexOp* poTI = (CE3D_ShIns_TexOp*)poSh->pGetInstruction(0);                    // dirty casting
    CEval_Const* poEv = (CEval_Const*)poTI->poGetEvaluator();

    switch ( Tile.GetRotationType() )
    {
        case 0: poEv->SetConstant(0);
        break;

        case 1: poEv->SetConstant(270);
        break;

        case 2: poEv->SetConstant(180);
        break;

        case 3: poEv->SetConstant(90);
        break;
    }

    poTileMaterial = poSh;
}

void CTerrainTesselatorGM::SetTileLODPar (float _fTileLODPar)
{
    fTileLODPar = _fTileLODPar;
}

void CTerrainTesselatorGM::SetBoundVol (CGBoundingVolume* _BVol)
{
    Mesh->poGetBoundVol()->Copy(_BVol);
}

// Additional Declarations
