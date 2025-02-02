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

#ifndef CTerrainTesselatorTileGM_h
#define CTerrainTesselatorTileGM_h 1

// CTerrainTesselatorGM
#include "TerrainTesselators\CTerrainTesselatorGM.h"

class CTerrainTesselatorTileGM : public CTerrainTesselatorGM
{
    public:
        CTerrainTesselatorTileGM();

        ~CTerrainTesselatorTileGM();

        void GenerateTileCoordData();

        void RenderTile(int iX, int iY);

        void RenderTiling();

        CGShader* GetTileMaterial(int iX, int iY);

        // Additional Public Declarations

    protected:
        // Additional Protected Declarations

    private:
        // Data Members for Class Attributes

        int Tile_iMaxSteps;

        int Tile_iSteps;

        int Tile_iGridStep;

        int Tile_iStride;

        float Tile_fTexStep;

        float Tile_fMeters;

        CTile* Tile_Tile;

        // Additional Private Declarations

    private:                    // Additional Implementation Declarations
};

// Class CTerrainTesselatorTileGM

#endif
