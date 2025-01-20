//## begin module%3B5C902D0082.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3B5C902D0082.cm

//## begin module%3B5C902D0082.cp preserve=no
//## end module%3B5C902D0082.cp

//## Module: CTerrainTesselatorTileGM%3B5C902D0082; Pseudo Package body
//## Source file: i:\Projects\GammaE\Terrain\TerrainTesselators\CTerrainTesselatorTileGM.cpp

//## begin module%3B5C902D0082.additionalIncludes preserve=no
//## end module%3B5C902D0082.additionalIncludes

//## begin module%3B5C902D0082.includes preserve=yes
//## end module%3B5C902D0082.includes

// CTerrainTesselatorTileGM
#include "Terrain\TerrainTesselators\CTerrainTesselatorTileGM.h"
//## begin module%3B5C902D0082.additionalDeclarations preserve=yes
//## end module%3B5C902D0082.additionalDeclarations


// Class CTerrainTesselatorTileGM 








CTerrainTesselatorTileGM::CTerrainTesselatorTileGM()
  //## begin CTerrainTesselatorTileGM::CTerrainTesselatorTileGM%.hasinit preserve=no
      : Tile_iMaxSteps(0), Tile_iSteps(0), Tile_iGridStep(0), Tile_iStride(0), Tile_fTexStep(0), Tile_fMeters(0), Tile_Tile(NULL)
  //## end CTerrainTesselatorTileGM::CTerrainTesselatorTileGM%.hasinit
  //## begin CTerrainTesselatorTileGM::CTerrainTesselatorTileGM%.initialization preserve=yes
  //## end CTerrainTesselatorTileGM::CTerrainTesselatorTileGM%.initialization
{
  //## begin CTerrainTesselatorTileGM::CTerrainTesselatorTileGM%.body preserve=yes
  //## end CTerrainTesselatorTileGM::CTerrainTesselatorTileGM%.body
}


CTerrainTesselatorTileGM::~CTerrainTesselatorTileGM()
{
  //## begin CTerrainTesselatorTileGM::~CTerrainTesselatorTileGM%.body preserve=yes
  //## end CTerrainTesselatorTileGM::~CTerrainTesselatorTileGM%.body
}



//## Other Operations (implementation)
void CTerrainTesselatorTileGM::GenerateTileCoordData ()
{
  //## begin CTerrainTesselatorTileGM::GenerateTileCoordData%995922489.body preserve=yes
    /*
	int             cI,cJ,iVXPos;
    float           fTexUCur    = 0;
    float           fTexVCur    = 0;

    // Offsets to the current rotation types in the UV array
    switch (_eRotFlag)
    {
        case TM_RFLAGS_NO_ROTATION:  // 0 degrees
									iVXPos = 0;
									for (cJ = 0; cJ <= m_uiTileSteps; cJ++)
									{
										fTexUCur = 0;
										for  (cI = 0; cI <= m_uiTileSteps; cI++)
										{
											m_pfUVs[((m_uiTileYOfs+cJ)*m_uiSectorRes + m_uiTileXOfs + cI) * 2    ] = fTexUCur;
											m_pfUVs[((m_uiTileYOfs+cJ)*m_uiSectorRes + m_uiTileXOfs + cI) * 2 + 1] = fTexVCur;

											fTexUCur   += m_fTexStep;
										}

										fTexVCur   += m_fTexStep;
									}
									break;
        case TM_RFLAGS_ROTATION_90: // 90 degrees
									iVXPos = 0;
									for (cJ = 0; cJ <= m_uiTileSteps; cJ++)
									{
										fTexUCur = 0;

										for  (cI = 0; cI <= m_uiTileSteps; cI++)
										{           
											m_pfUVs[((m_uiTileYOfs+cJ)*m_uiSectorRes + m_uiTileXOfs + cI) * 2    ] = fTexVCur;
											m_pfUVs[((m_uiTileYOfs+cJ)*m_uiSectorRes + m_uiTileXOfs + cI) * 2 + 1] = 1.0f - fTexUCur;

											fTexUCur   += m_fTexStep;
										}
                                       
										fTexVCur   += m_fTexStep;
									}
	                                break;
        case TM_RFLAGS_ROTATION_180:// 180 degrees 
									iVXPos = 0;
									for (cJ = 0; cJ <= m_uiTileSteps; cJ++)
									{
										fTexUCur = 0;

										for  (cI = 0; cI <= m_uiTileSteps; cI++)
										{           
											m_pfUVs[((m_uiTileYOfs+cJ)*m_uiSectorRes + m_uiTileXOfs + cI) * 2    ] = 1.0f - fTexUCur;
											m_pfUVs[((m_uiTileYOfs+cJ)*m_uiSectorRes + m_uiTileXOfs + cI) * 2 + 1] = 1.0f - fTexVCur;

											fTexUCur   += m_fTexStep;
										}

										fTexVCur   += m_fTexStep;
									}
									break;
        case TM_RFLAGS_ROTATION_270:// 0 degrees
									iVXPos = 0;
									for (cJ = 0; cJ <= m_uiTileSteps; cJ++)
									{
										fTexUCur = 0;

										for  (cI = 0; cI <= m_uiTileSteps; cI++)
										{           
											m_pfUVs[((m_uiTileYOfs+cJ)*m_uiSectorRes + m_uiTileXOfs + cI) * 2    ] = 1.0f - fTexVCur;
											m_pfUVs[((m_uiTileYOfs+cJ)*m_uiSectorRes + m_uiTileXOfs + cI) * 2 + 1] = fTexUCur;
                                        
											fTexUCur   += m_fTexStep;
										}
                                       
										fTexVCur   += m_fTexStep;
									}
									break;
    }
	*/
  //## end CTerrainTesselatorTileGM::GenerateTileCoordData%995922489.body
}

void CTerrainTesselatorTileGM::RenderTile (int iX, int iY)
{
  //## begin CTerrainTesselatorTileGM::RenderTile%995922490.body preserve=yes
    // GRID_ETMap_RotType eRotFlag;

    // Set current texture tile
	// TMaterial * TileMat = GetTileMaterial(iX,iY);
	CE3D_Shader*	poTileMat = TB->poGetTileMaterial(0,0);
	
    // Get rotation flag
    // eRotFlag = Tile_Tile->GetRotationType();
    // GenerateTilingCoordData(eRotFlag);

    // -----------------------------------------------
    // Compute the index list for this tile
    // -----------------------------------------------
	int i,j,iIdx = 0;
	
	int iVXPos1 = iX*Tile_iMaxSteps;
	int iVXPos2 = iVXPos1 + Tile_iStride;
	
	iIdx         = 0;
	Idxs[iIdx++] =  iVXPos1;
	for (j = 0; j < Tile_iSteps; j++)
	{        
		Idxs[iIdx++] =  iVXPos1;
        for (i = 0; i <= Tile_iSteps; i++)
		{
            Idxs[iIdx++] = iVXPos1;
            Idxs[iIdx++] = iVXPos2;

			iVXPos1 += Tile_iGridStep;
			iVXPos2 += Tile_iGridStep;
        }

		Idxs[iIdx] = Idxs[iIdx-1];
		iIdx++;

		iVXPos1 += (Tile_iStride - Tile_iGridStep*(Tile_iSteps+1));
		iVXPos2  = iVXPos1 + Tile_iStride;
    }
	
	gpoE3DRenderer->RenderMesh(Mesh,poTileMat);
  //## end CTerrainTesselatorTileGM::RenderTile%995922490.body
}

void CTerrainTesselatorTileGM::RenderTiling ()
{
  //## begin CTerrainTesselatorTileGM::RenderTiling%995922491.body preserve=yes
  	int				iX,iY;
    // -----------------------
    // Setup variables
    // -----------------------

    // Height pixels per tile
    Tile_iMaxSteps = (HF->GetResolution()-1) / TM->GetResolution();

    // Meters per tile
	Tile_fMeters   = fXYScale * Tile_iMaxSteps;

    // Número actual de subdivisiones por tile
    Tile_iSteps    = Tile_iMaxSteps >> iLODs[0];
	
	// Texture coord step between adjacent points
	Tile_fTexStep  = 1.0f / Tile_iSteps;

	Tile_iGridStep = ( 1 << iLODs[0]);
	
	Tile_iStride = uiSectorRes * Tile_iGridStep;
    /*
	// Compute the minimum tile size        
    // Number of lods of the tile bookmark
	int iNbLODs         = m_poTexSet->iGetNbLODS();
   
    // Size of the maximum tile LOD stored in the tile bookmark
	int iMaxTileSize    = ((E3D_TextureDesc *)m_poTexSet->poGetTile(0,0))->iGetWidth();
    int iMaxTileLOD     = MTH_Common::iLog2(iMaxTileSize);

    // Size of the minimum tile LOD stored int the tile bookmark
    
	int iMinTileLODSize = 4; /// ((E3D_TextureDesc *)m_poTexSet->poGetTile(0,iNbLODs-1))->iGetWidth();
    int iMinTileLOD     =  MTH_Common::iLog2(iMinTileLODSize);   

    m_uiTileLODRange = iMaxTileLOD - MTH_Common::iLog2(iMinTileLODSize) + 1;

    // Get the GlobalMap distance
    m_fGMapDistance  = m_poLODSel->pfGetLodDist(MTH_Common::iLog2(m_iMaxTileSteps) + 1);

    // Get the TileLODDistanc factor    
    m_fTileLODDistance = m_fGMapDistance / m_uiTileLODRange;

	// Tile texture step
 	m_fTexStep       = 1.0f / m_uiTileSteps;
    */

    //------------------------------------
    // Render the tiles
    //------------------------------------      
	for (iY = 0; iY<TM->GetResolution();iY++)
        for (iX = 0; iX<TM->GetResolution();iX++)
			RenderTile(iX,iY);

  //## end CTerrainTesselatorTileGM::RenderTiling%995922491.body
}

CE3D_Shader * CTerrainTesselatorTileGM::GetTileMaterial (int iX, int iY)
{
  //## begin CTerrainTesselatorTileGM::GetTileMaterial%995922492.body preserve=yes
	static CVect3					TileCenter;
    static int						i,j;
    static unsigned int				uiLOD;
    static unsigned int				uiTexIndex;
    static float					fDistance;

	// Get pixel at the center of the tile
    i   = ( ((float)iX + 0.5f)*Tile_iSteps  );
    j   = ( ((float)iY + 0.5f)*Tile_fMeters );

	// Get center point from the tile
	TileCenter.V3(i*fXYScale,j*fXYScale,HData[j*uiSectorRes+i]);

	// Get the distance from the tile to the camera
	fDistance  = TileCenter.Distance(Cam);

    uiTexIndex = Tile_Tile->GetTileIdx();
    uiLOD      = GetTileLOD(fDistance,TB->GetMaxLODs());

    return ( TB->poGetTileMaterial(uiTexIndex,uiLOD) );
  //## end CTerrainTesselatorTileGM::GetTileMaterial%995922492.body
}

// Additional Declarations
  //## begin CTerrainTesselatorTileGM%3B5C902D0082.declarations preserve=yes
  //## end CTerrainTesselatorTileGM%3B5C902D0082.declarations

//## begin module%3B5C902D0082.epilog preserve=yes
//## end module%3B5C902D0082.epilog
