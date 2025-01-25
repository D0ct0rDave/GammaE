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

#ifndef CTerrainSector_h
#define CTerrainSector_h 1

// CTileBookmark
#include "TerrainMaterials\CTileBookmark.h"
// CTerrainTesselator
#include "TerrainTesselators\CTerrainTesselator.h"
// GammaE_TerrainData
#include "GammaE_TerrainData.h"
// CGSceneNode
#include "GammaE_Scene.h"

class CTerrainSector : public CGSceneNode
{
    public:
        CTerrainSector();

        virtual ~CTerrainSector();

        virtual void Render();

        virtual CGraphBV* poCreateBoundVol();

        virtual void ComputeBoundVol();

        virtual CGraphBV* poGetBV();

        void SetMaxsMins(CGVect3& _Maxs, CGVect3& _Mins);

        // Data Members for Class Attributes

        CHFSector* HF;

        CLMSector* LM;

        CTMSector* TM;

        CTileBookmark* TB;

        CTerrainTesselator* Tess;

        float fXYScale;

        // Additional Public Declarations
        // General Processing Functionalities
        virtual void Accept(CGSceneVisitor* _poVisitor)
        {
            _poVisitor->Visit(this);
        }

    protected:
        // Additional Protected Declarations

    private:

        float* GetfLODs();

        // Data Members for Class Attributes

        float* fLODs;

        int* iLODs;

        CGVect3 Mins;

        CGVect3 Maxs;

        // Additional Private Declarations

    private:                    // Additional Implementation Declarations
};

// Class CTerrainSector

inline float* CTerrainSector::GetfLODs ()
{
    return(fLODs);
}

#endif
