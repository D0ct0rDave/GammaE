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

#ifndef CTerrainCircuit_h
#define CTerrainCircuit_h 1

// CLODSelector
#include "TerrainMath\CLODSelector.h"
// CGSceneNode
#include "GammaE_Scene.h"

class CTerrainCircuit : public CGSceneGroup
{
    public:
        CTerrainCircuit();

        virtual ~CTerrainCircuit();

        void Init(int _SecsPerRow, int _SecsPerCol, float _SectorSize);

        void SetSector(int _iX, int _iY, CGSceneNode* _pSector);

        virtual void Render();

        void ComputeVISLODMatrix();

        void ComputeLODArrays(int iX, int iY);

        void SetLOD(int iBlockIdx, int iX, int iY);

        bool BlockInRange(int iX, int iY);

        CLODSelector* GetLODSelector();
        void SetLODSelector(CLODSelector* value);

        // Data Members for Associations

        CLODSelector* LODSelector;

        // Additional Public Declarations

    protected:
        // Additional Protected Declarations

    private:
        // Data Members for Class Attributes

        int SecsPerRow;

        int SecsPerCol;

        float SectorSize;

        int iLODs[5];

        float fLODs[5];

        float* fLODMatrix;

        bool* bVISMatrix;

        // Additional Private Declarations

    private:                    // Additional Implementation Declarations
};

// Class CTerrainCircuit

inline CLODSelector* CTerrainCircuit::GetLODSelector ()
{
    return(LODSelector);
}

inline void CTerrainCircuit::SetLODSelector (CLODSelector* value)
{
    LODSelector = value;
}

#endif
