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

#ifndef CTerrainTesselatorGM_h
#define CTerrainTesselatorGM_h 1

// CTerrainTesselator
#include "TerrainTesselators\CTerrainTesselator.h"
// GammaE_E3D
#include "GammaE_E3D.h"

class CTerrainTesselatorGM : public CTerrainTesselator
{
    public:
        CTerrainTesselatorGM();

        ~CTerrainTesselatorGM();

        void Init(int iMaxVertexs);

        void Invalidate();

        void GenerateVertexData();

        void GenerateVertexColorData();

        void GenerateLightData();

        void GenerateGlobalCoordData();

        int GetTileLOD(float fDistance, int iMaxLODs);

        void TesselateGrid();

        virtual void Render();

        void SetupRenderVariables();

        void GenerateHeightData();

        void GenerateHeightData_Inner(float fFactor);

        void GenerateHeightData_Horizontal_3pN(int iNeight, int iY);

        void GenerateHeightData_Vertical_3pN(int iNeight, int iX);

        void GenerateHeightData_Horizontal_N(int iNeight, int iY);

        void GenerateHeightData_Vertical_N(int iNeight, int iX);

        void GenerateHeightData_Horizontal(int iY, int iRes, float fFactor);

        void GenerateHeightData_Vertical(int iX, int iRes, float fFactor);

        void SetupTileMaterial();

        void SetTileLODPar(float _fTileLODPar);

        void SetBoundVol(CGBoundingVolume* _BVol);

        // Additional Public Declarations

    protected:
        // Data Members for Class Attributes

        float* HData;

        float* LData;

        CGVect3* VXs;

        CGColor* VCs;

        CGVect2* UVs;

        unsigned short* Idxs;

        int MaxVertexs;

        CGMesh* Mesh;

        // Global variable
        unsigned int uiSectorRes;

        float fTileLODPar;

        CGShader* poTileMaterial;

        CE3D_ShIns_Texture TileTex;

        CE3D_ShIns_TexOp TileOp;

        CEval_Const TileMatFunc;

        // Additional Protected Declarations

    private:
        // Additional Private Declarations

    private:                    // Additional Implementation Declarations
};

// Class CTerrainTesselatorGM

#endif
