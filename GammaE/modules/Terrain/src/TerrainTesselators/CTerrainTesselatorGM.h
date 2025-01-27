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

        void SetBoundVol(const CGGraphBV& _oBV);

        // Additional Public Declarations

    protected:
        // Data Members for Class Attributes

        float* HData;

        float* LData;

        int MaxVertexs;

        CGMesh* m_poGeometryMesh;
        CGUnmanagedMesh* m_poUnmanagedMesh;

        // Global variable
        unsigned int uiSectorRes;

        float fTileLODPar;

        CGShader* poTileMaterial;

        CGShInsTexture TileTex;

        CGShInsTexOp TileOp;

        CGEvalConst TileMatFunc;

        // Additional Protected Declarations

    private:
        // Additional Private Declarations

    private:                    // Additional Implementation Declarations
};

// Class CTerrainTesselatorGM

#endif
