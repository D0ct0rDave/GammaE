//## begin module%3AFEFFA101CC.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3AFEFFA101CC.cm

//## begin module%3AFEFFA101CC.cp preserve=no
//## end module%3AFEFFA101CC.cp

//## Module: CTerrainTesselatorGM%3AFEFFA101CC; Pseudo Package body
//## Source file: i:\Projects\GammaE\Terrain\TerrainTesselators\CTerrainTesselatorGM.cpp

//## begin module%3AFEFFA101CC.additionalIncludes preserve=no
//## end module%3AFEFFA101CC.additionalIncludes

//## begin module%3AFEFFA101CC.includes preserve=yes
//## end module%3AFEFFA101CC.includes

// CTerrainTesselatorGM
#include "Terrain\TerrainTesselators\CTerrainTesselatorGM.h"
//## begin module%3AFEFFA101CC.additionalDeclarations preserve=yes

#define TSL_UGM_TRISTRIP

//---------------------------------------------------------------------------
inline int iLog2(int x)
{
	int Res = -1;
    while(x)
    {
    	x >>=1;
        Res++;
    }
	return(Res);
}
//-----------------------------------------------------------------------------
inline float fInterpolate(float _fA,float _fB,float _fFactor)
{
    return( _fA + _fFactor*(_fB - _fA) );
    // return(_fA*(1.0f - _fFactor) + _fB*_fFactor );
}
//-----------------------------------------------------------------------------
inline float  fSelectInterpolationFactor(float _fALOD,float _fBLOD)
{
    // Get factor from lower LOD sector (for convenion)
	if (_fALOD > _fBLOD)
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

//## end module%3AFEFFA101CC.additionalDeclarations


// Class CTerrainTesselatorGM 















CTerrainTesselatorGM::CTerrainTesselatorGM()
  //## begin CTerrainTesselatorGM::CTerrainTesselatorGM%.hasinit preserve=no
      : HData(NULL), LData(NULL), VXs(NULL), VCs(NULL), UVs(NULL), Idxs(NULL), MaxVertexs(0), Mesh(NULL), uiSectorRes(0), fTileLODPar(0)
  //## end CTerrainTesselatorGM::CTerrainTesselatorGM%.hasinit
  //## begin CTerrainTesselatorGM::CTerrainTesselatorGM%.initialization preserve=yes
  //## end CTerrainTesselatorGM::CTerrainTesselatorGM%.initialization
{
  //## begin CTerrainTesselatorGM::CTerrainTesselatorGM%.body preserve=yes
  //## end CTerrainTesselatorGM::CTerrainTesselatorGM%.body
}


CTerrainTesselatorGM::~CTerrainTesselatorGM()
{
  //## begin CTerrainTesselatorGM::~CTerrainTesselatorGM%.body preserve=yes
	Invalidate();
  //## end CTerrainTesselatorGM::~CTerrainTesselatorGM%.body
}



//## Other Operations (implementation)
void CTerrainTesselatorGM::Init (int iMaxVertexs)
{
  //## begin CTerrainTesselatorGM::Init%989790244.body preserve=yes
	MaxVertexs  = iMaxVertexs;

	HData = new float [MaxVertexs  ];
	LData = new float [MaxVertexs*3];
	
	Mesh = new CMesh;
	
	#ifdef TSL_UGM_TRISTRIP

			Mesh->Init(	MaxVertexs,
						2*MaxVertexs,
						E3D_MESH_TRISTRIPS,
						MESH_FIELD_VERTEXS | MESH_FIELD_UVCOORDS | MESH_FIELD_COLORS | MESH_FIELD_INDEXES);
	#else
	
			Mesh->Init(	MaxVertexs,
						2*MaxVertexs,
						E3D_MESH_TRIS,					
						MESH_FIELD_VERTEXS | MESH_FIELD_UVCOORDS | MESH_FIELD_COLORS | MESH_FIELD_INDEXES);

	#endif

	VXs  = Mesh->VXs;
	VCs  = Mesh->VCs;
	UVs  = Mesh->UVs;
	Idxs = Mesh->Idxs;
  //## end CTerrainTesselatorGM::Init%989790244.body
}

void CTerrainTesselatorGM::Invalidate ()
{
  //## begin CTerrainTesselatorGM::Invalidate%990132091.body preserve=yes
	if (MaxVertexs) 
	{
		// Free previously allocated resources
		if (HData) delete []HData;	HData = NULL;
		if (LData) delete []LData;	LData = NULL;
		if (Mesh ) delete Mesh;		Mesh  = NULL;

		VXs  = NULL;
		VCs  = NULL;
		UVs  = NULL;
		Idxs = NULL;
	}
  //## end CTerrainTesselatorGM::Invalidate%990132091.body
}

void CTerrainTesselatorGM::GenerateVertexData ()
{
  //## begin CTerrainTesselatorGM::GenerateVertexData%990132088.body preserve=yes
    unsigned int    cI,cJ;
	float           fSpaceXCur,fSpaceYCur;    
	float          *pH	= HData;    
    CVect3		   *pVX = VXs;
    float           fSpaceStep;

    // Spatial distance betweem two adjacent vertexs
	fSpaceStep    = fXYScale* (1<<iLODs[0]);

    // Generate vertex data
    fSpaceYCur = 0;
    for (cJ=0;cJ<uiSectorRes;cJ++)
    {
        fSpaceXCur = 0;
        for (cI=0;cI< uiSectorRes;cI++)
        {
            pVX->V3(fSpaceXCur,fSpaceYCur,*pH);
	
	        fSpaceXCur += fSpaceStep;
			pH ++;
			pVX++;
        }

        fSpaceYCur+= fSpaceStep;
    }
	
	CVect3 Maxs,Mins;
	Mins.V3(0,0,HF->GetMinHeight());
	Maxs.V3(fSpaceStep*(uiSectorRes & 0xfffffffe),fSpaceStep*(uiSectorRes& 0xfffffffe),HF->GetMaxHeight());
	Mesh->GetBoundVol()->Init(Maxs,Mins);

  //## end CTerrainTesselatorGM::GenerateVertexData%990132088.body
}

void CTerrainTesselatorGM::GenerateVertexColorData ()
{
  //## begin CTerrainTesselatorGM::GenerateVertexColorData%995233491.body preserve=yes
	unsigned int    cI,cJ;
    float			*pL	= LData;
	CVect4			*pVC= VCs;

    // Generate Color Map   
	for (cJ=0;cJ<uiSectorRes;cJ++)
        for (cI=0;cI<uiSectorRes;cI++)
        {
			pVC->v[0] = pL[0];
			pVC->v[1] = pL[1];
			pVC->v[2] = pL[2];
			pVC->v[3] = 1.0f;

			pL += 3;
			pVC++;
        }

  //## end CTerrainTesselatorGM::GenerateVertexColorData%995233491.body
}

void CTerrainTesselatorGM::GenerateLightData ()
{
  //## begin CTerrainTesselatorGM::GenerateLightData%990132090.body preserve=yes
  	LM->GetLODData(iLODs[0],LData);
  //## end CTerrainTesselatorGM::GenerateLightData%990132090.body
}

void CTerrainTesselatorGM::GenerateGlobalCoordData ()
{
  //## begin CTerrainTesselatorGM::GenerateGlobalCoordData%990132089.body preserve=yes
    unsigned int    cI,cJ;
    int             iVXPos;
    float           fTexUCur;
    float           fTexVCur;
    float           fGMapStep;
	CVect2		   *pUV = UVs;
    
    // Global Map texture step
    fGMapStep  = 1.0f / (float)(uiSectorRes & 0xfffffffe);

    iVXPos     = 0;
    fTexVCur   = 0;
	for (cJ = 0; cJ < uiSectorRes; cJ++)
	{
        fTexUCur = 0;

		for  (cI = 0; cI < uiSectorRes; cI++)
		{
			pUV->V2(fTexUCur,fTexVCur);
            
			fTexUCur   += fGMapStep;
			pUV++;
        }
        
        fTexVCur   += fGMapStep;
    }
  //## end CTerrainTesselatorGM::GenerateGlobalCoordData%990132089.body
}

int CTerrainTesselatorGM::GetTileLOD (float fDistance, int iMaxLODs)
{
  //## begin CTerrainTesselatorGM::GetTileLOD%995799277.body preserve=yes
	#ifndef _e_
	#define _e_ 2.7182818284590452353602874713527
	#endif

    return( iMaxLODs * (1.0f - powf(_e_,-1*(fTileLODPar/2500.0f)*fDistance)) );
  //## end CTerrainTesselatorGM::GetTileLOD%995799277.body
}

void CTerrainTesselatorGM::TesselateGrid ()
{
  //## begin CTerrainTesselatorGM::TesselateGrid%990132095.body preserve=yes
    
	// -------------------------------------------
    // Generate strips:
    // -------------------------------------------
    int				 iIdx;
    int				 iVXPos1,iVXPos2;
    unsigned int     j,i;
	int				 iStep;

	#ifdef TSL_UGM_TRISTRIP

		iIdx    = 0;
    
		iVXPos1 = 0;
		iVXPos2 = uiSectorRes;
		
		Idxs[iIdx++] = iVXPos1;		// For back face culling ->
		Idxs[iIdx++] = iVXPos1;
		for (j = 0; j < uiSectorRes-1; j++)
		{
			Idxs[iIdx++] = iVXPos1;		
					
			for (i = 0; i < uiSectorRes; i++)
			{
				// first tri
				Idxs[iIdx++] = iVXPos1;
				Idxs[iIdx++] = iVXPos2;			

				// update vertexes
				iVXPos1 ++;
				iVXPos2 ++;
			}
			
			Idxs[iIdx++] = iVXPos2-1;
		}

		Mesh->eMeshType  = E3D_MESH_TRISTRIPS;
		Mesh->usNumIdxs  = iIdx;
		Mesh->usNumPrims = iIdx-2;	

	#else

		iIdx    = 0;
    
		iVXPos1 = 0;
		iVXPos2 = uiSectorRes;

		for (j = 0; j < uiSectorRes-1; j++)
		{
			for (i = 0; i < uiSectorRes-1; i++)
			{
				// first tri
				Idxs[iIdx++] = iVXPos1;
				Idxs[iIdx++] = iVXPos1+1;
				Idxs[iIdx++] = iVXPos2;
				
				
				// second tri
				Idxs[iIdx++] = iVXPos1+1;
				Idxs[iIdx++] = iVXPos2+1;
				Idxs[iIdx++] = iVXPos2;				

				// update vertexes
				iVXPos1 ++;
				iVXPos2 ++;
			}
			
			iVXPos1 ++;
			iVXPos2 ++;
		}
		
		Mesh->eMeshType  = E3D_MESH_TRIS;
		Mesh->usNumIdxs  = iIdx;
		Mesh->usNumPrims = iIdx/3;

	#endif
  //## end CTerrainTesselatorGM::TesselateGrid%990132095.body
}

void CTerrainTesselatorGM::Render ()
{
  //## begin CTerrainTesselatorGM::Render%989790245.body preserve=yes
	SetupRenderVariables ();

	GenerateHeightData();
	GenerateVertexData();

	GenerateLightData();
	GenerateVertexColorData();

	GenerateGlobalCoordData ();
	TesselateGrid ();
		
	SetupTileMaterial();	

	gpoE3DRenderer->RenderMesh(Mesh , poTileMaterial);
  //## end CTerrainTesselatorGM::Render%989790245.body
}

void CTerrainTesselatorGM::SetupRenderVariables ()
{
  //## begin CTerrainTesselatorGM::SetupRenderVariables%995233496.body preserve=yes
	uiSectorRes = ((HF->GetResolution() & 0xfffffffe) >> iLODs[0]) + 1;
  //## end CTerrainTesselatorGM::SetupRenderVariables%995233496.body
}

void CTerrainTesselatorGM::GenerateHeightData ()
{
  //## begin CTerrainTesselatorGM::GenerateHeightData%990132087.body preserve=yes
	HF->GetLODData(iLODs[0],HData);	

    unsigned int cSegment;
    unsigned int uiInnerPoints = (uiSectorRes >>1);    
    unsigned int uiLastSeg     = (uiSectorRes - 3);

    float		 fFactor = fLODs[0] - iLODs[0];

    switch (uiSectorRes)
    {
		case 2:
				//        Controled in other part of the code        
			    break;
        case 3: // Only the central point
                HData[4] = fInterpolate(HData[4],(HData[2] + HData[6] )*0.5f,fFactor);

                GenerateHeightData_Horizontal_3pN(1,0);   // North LOD
                GenerateHeightData_Vertical_3pN  (2,2);   // East LOD
                GenerateHeightData_Horizontal_3pN(3,2);   // South LOD
                GenerateHeightData_Vertical_3pN  (4,0);   // West LOD
                return;

        default:// 5 or more points
				for (cSegment=2;cSegment<=uiLastSeg;cSegment+=2)
                {
                    GenerateHeightData_Vertical  (cSegment,uiInnerPoints,fFactor);
                    GenerateHeightData_Horizontal(cSegment,uiInnerPoints,fFactor);                    
                }
                
                GenerateHeightData_Inner(fFactor);

                GenerateHeightData_Horizontal_N(1,0            );  	  // North
                GenerateHeightData_Vertical_N  (2,uiSectorRes-1);     // East
                GenerateHeightData_Horizontal_N(3,uiSectorRes-1);     // South
                GenerateHeightData_Vertical_N  (4,0            );     // West
                break;
    }
  //## end CTerrainTesselatorGM::GenerateHeightData%990132087.body
}

void CTerrainTesselatorGM::GenerateHeightData_Inner (float fFactor)
{
  //## begin CTerrainTesselatorGM::GenerateHeightData_Inner%995639493.body preserve=yes
    unsigned int cJ,cI;
    unsigned int uiQuads  = (uiSectorRes >> 1);
    unsigned int uiStride =  uiSectorRes + 1;
    float        *h0,*h1,*h2;

    // Diagonal tri is from upper right to bottom left    
    h0 = HData + 2;
    h1 = h0 + uiSectorRes - 1;
    h2 = h1 + uiSectorRes - 1;

    for (cJ=0;cJ<uiQuads;cJ++)
    {
        for (cI=0;cI<uiQuads;cI++)    
        {
            // *h1 += (((*h0 + *h2)*0.5f - *h1) * _fFactor);
            *h1 = fInterpolate(*h1, (*h0 + *h2)*0.5f,fFactor);

            h0 += 2;
            h1 += 2;
            h2 += 2;
        }

        h0 += uiStride;
        h1 += uiStride;
        h2 += uiStride;
    }
  //## end CTerrainTesselatorGM::GenerateHeightData_Inner%995639493.body
}

void CTerrainTesselatorGM::GenerateHeightData_Horizontal_3pN (int iNeight, int iY)
{
  //## begin CTerrainTesselatorGM::GenerateHeightData_Horizontal_3pN%995639487.body preserve=yes
    float   *fH            = &HData[iY* 3];
    float   fInterpolation = (fH[0]+fH[2])*0.5f;
    float   c05;
    float   fFactor;

    // 3 cases: LOD[0] <  LOD[_uiLOD]
    //          LOD[0] == LOD[_uiLOD]
    //          LOD[0] >  LOD[_uiLOD]
    if (iLODs[0] >= iLODs[iNeight])
    {        
        fFactor = fSelectInterpolationFactor(fLODs[0],fLODs[iNeight]);
        c05     = fH[1];
        fH[1] = fInterpolate(c05,fInterpolation,fFactor);
        return;
     }
	else
	{
        // The neighbourg has only 2 vertices: interpolate between them
        fH[1] = fInterpolation;
        return;
    }
  //## end CTerrainTesselatorGM::GenerateHeightData_Horizontal_3pN%995639487.body
}

void CTerrainTesselatorGM::GenerateHeightData_Vertical_3pN (int iNeight, int iX)
{
  //## begin CTerrainTesselatorGM::GenerateHeightData_Vertical_3pN%995639488.body preserve=yes
    #define     fH(y)    HData[(y)*uiSectorRes + iX]

    float   fInterpolation = (fH(0)+fH(2))*0.5f;
    float   c05;
    float   fFactor;
    
    // 3 cases: LOD[0] <  LOD[_uiLOD]   // better detail than neigh
    //          LOD[0] == LOD[_uiLOD]   // equal detail than neigh
    //          LOD[0] >  LOD[_uiLOD]   // lower
    
	if (iLODs[0] >= iLODs[iNeight])
    {        
        c05     = fH(1);
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
  //## end CTerrainTesselatorGM::GenerateHeightData_Vertical_3pN%995639488.body
}

void CTerrainTesselatorGM::GenerateHeightData_Horizontal_N (int iNeight, int iY)
{
  //## begin CTerrainTesselatorGM::GenerateHeightData_Horizontal_N%995639489.body preserve=yes
    unsigned int cJ,cJx2,cJx2_1,cJ_1x2,cJx4;
    unsigned int uiInnerPoints        = (uiSectorRes >>1);		// Num intermediate points
    unsigned int uiInnerPointsNextLOD = (uiInnerPoints>>1);		// Num intermediate points next LOD
    float 		 c0,c05,c1;
    float        fInterpolation;
    float        fFactor;
    float		 *fH;
    
	// Control special case
    fH = &HData[iY*uiSectorRes];

    // Control neighbours
    if (iLODs[0] < iLODs[iNeight])
    {
        // The current LOD is greater than the neighbour
        fFactor = fLODs[iNeight] - (float)iLODs[iNeight];

        for (cJ=0;cJ<uiInnerPointsNextLOD;cJ++)
        {
            cJx4 = cJ<<2;
     
			c0   = fH[cJx4  ];
            c05  = fH[cJx4+2];
            c1   = fH[cJx4+4];

            fInterpolation = fInterpolate(c05,( c0+c1 )*0.5f,fFactor);

            fH[cJx4+1] = (c0+fInterpolation)*0.5f;
            fH[cJx4+2] = fInterpolation;
            fH[cJx4+3] = (fInterpolation+c1)*0.5f;
        }
    }
    else
    {
        // Equal integer level of detail or LOD(Current) > LOD(Neight)
        fFactor = fSelectInterpolationFactor(fLODs[0],fLODs[iNeight]);
        GenerateHeightData_Horizontal(iY,uiInnerPoints,fFactor);
    }
  //## end CTerrainTesselatorGM::GenerateHeightData_Horizontal_N%995639489.body
}

void CTerrainTesselatorGM::GenerateHeightData_Vertical_N (int iNeight, int iX)
{
  //## begin CTerrainTesselatorGM::GenerateHeightData_Vertical_N%995639490.body preserve=yes
    #define     fH(y)    HData[(y)*uiSectorRes+ iX]

    unsigned int cJ,cJx4;
    unsigned int uiInnerPoints        = (uiSectorRes >>1);		// Num intermediate points
    unsigned int uiInnerPointsNextLOD = (uiInnerPoints>>1);		// Num intermediate points next LOD
    float 		 c0,c05,c1;
    float 		 fInterpolation;
    float 		 fFactor;

    // Control neighbours
    if (iLODs[0] < iLODs[iNeight])
    {   
        // The current LOD is greater than the neighbour
        fFactor = fLODs[iNeight] - (float)iLODs[iNeight];

        for (cJ=0;cJ<uiInnerPointsNextLOD;cJ++)
        {
            cJx4 = cJ<<2;

            c0   = fH(cJx4  );
            c05  = fH(cJx4+2);
            c1   = fH(cJx4+4);

			fInterpolation = fInterpolate(c05,(c0+c1)*0.5f,fFactor);

            fH(cJx4+1) = (c0+fInterpolation)*0.5f;
            fH(cJx4+2) = fInterpolation;
            fH(cJx4+3) = (fInterpolation+c1)*0.5f;
        }
    }
    else
    {
        // Equal integer level of detail or LOD(Current) > LOD(Neight)
        fFactor = fSelectInterpolationFactor(fLODs[0],fLODs[iNeight]);
        GenerateHeightData_Vertical(iX,uiInnerPoints,fFactor);
    }
	
	#undef fH
  //## end CTerrainTesselatorGM::GenerateHeightData_Vertical_N%995639490.body
}

void CTerrainTesselatorGM::GenerateHeightData_Horizontal (int iY, int iRes, float fFactor)
{
  //## begin CTerrainTesselatorGM::GenerateHeightData_Horizontal%995639491.body preserve=yes
    unsigned int cI,cI2;
    float        *fH = &HData[iY*uiSectorRes];

    cI2   = 1;
    for (cI=0;cI<iRes;cI++)
    {
        fH[cI2] = fInterpolate(fH[cI2],(fH[cI2-1]+fH[cI2+1])*0.5f,fFactor);
        cI2 += 2;
    }  
  //## end CTerrainTesselatorGM::GenerateHeightData_Horizontal%995639491.body
}

void CTerrainTesselatorGM::GenerateHeightData_Vertical (int iX, int iRes, float fFactor)
{
  //## begin CTerrainTesselatorGM::GenerateHeightData_Vertical%995639492.body preserve=yes
    #define     fH(y)    HData[(y)*uiSectorRes + iX]

    unsigned int cJ,cJ2;
    // iRes--;
    cJ2   = 1;
    for (cJ=0;cJ<iRes;cJ++)
    {
        fH(cJ2) = fInterpolate(fH(cJ2),(fH(cJ2-1)+fH(cJ2+1))*0.5f,fFactor);
        cJ2 += 2;
    }
    #undef fH
  //## end CTerrainTesselatorGM::GenerateHeightData_Vertical%995639492.body
}

void CTerrainTesselatorGM::SetupTileMaterial ()
{
  //## begin CTerrainTesselatorGM::SetupTileMaterial%996008330.body preserve=yes
	float		fDist;
	CVect3		Center;
	CTile		&Tile = (CTile &)TM->GetValue(0,0);
	float		fSectorSize = (HF->GetResolution() & 0xfffffffe) * fXYScale;
		
	// Center value:
	// X = Res /2
	// Y = Res /2
	// Pos = (Y*Res)+ X
	// Pos = Res * (Res/2) + Res/2
	// Pos = (Res + 1)*Res / 2	
	Center.V3(fSectorSize*0.5f,fSectorSize*0.5f,HData[ (uiSectorRes + 1) * (uiSectorRes>>1) ]);
	int   LOD  = GetTileLOD(Center.Distance(Cam),TB->GetMaxLODs());
	

	CE3D_Shader			*poSh = TB->poGetTileMaterial(Tile.TileIdx,LOD);
	CE3D_ShIns_TexOp	*poTI = (CE3D_ShIns_TexOp *)poSh->pGetInstruction(0);	// dirty casting
	CEval_Const			*poEv = (CEval_Const *)poTI->poEval;

	switch (Tile.GetRotationType())
	{
		case 0:	poEv->SetConstant(0);
				break;
		case 1:	poEv->SetConstant(270);
				break;
		case 2:	poEv->SetConstant(180);
				break;
		case 3:	poEv->SetConstant(90);
				break;
	}

	poTileMaterial = poSh;
  //## end CTerrainTesselatorGM::SetupTileMaterial%996008330.body
}

void CTerrainTesselatorGM::SetTileLODPar (float _fTileLODPar)
{
  //## begin CTerrainTesselatorGM::SetTileLODPar%996008331.body preserve=yes
	fTileLODPar = _fTileLODPar;
  //## end CTerrainTesselatorGM::SetTileLODPar%996008331.body
}

void CTerrainTesselatorGM::SetBoundVol (CGraphBV *_BVol)
{
  //## begin CTerrainTesselatorGM::SetBoundVol%996790583.body preserve=yes
	Mesh->GetBoundVol()->Copy(_BVol);
  //## end CTerrainTesselatorGM::SetBoundVol%996790583.body
}

// Additional Declarations
  //## begin CTerrainTesselatorGM%3AFEFFA101CC.declarations preserve=yes
  //## end CTerrainTesselatorGM%3AFEFFA101CC.declarations

//## begin module%3AFEFFA101CC.epilog preserve=yes
//## end module%3AFEFFA101CC.epilog
