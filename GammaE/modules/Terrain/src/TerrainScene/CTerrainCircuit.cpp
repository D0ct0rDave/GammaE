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

#include <string.h>
#include "GammaE_Mem.h"
#include "GammaE_Misc.h"

// CTerrainCircuit
#include "TerrainScene\CTerrainCircuit.h"

#define TIMING
#ifdef TIMING

CGChrono Chrono;
double dAccumET = 0.0;
int iNumCalls = 0;

#endif

// Class CTerrainCircuit

CTerrainCircuit::CTerrainCircuit()
    : SecsPerRow(0), SecsPerCol(0), SectorSize(0), fLODMatrix(NULL), bVISMatrix(NULL)
{
    bFrustumTest = false;
    CE3D_RenderVars.AddVar("iLODs",iLODs);
    CE3D_RenderVars.AddVar("fLODs",fLODs);
}

CTerrainCircuit::~CTerrainCircuit()
{
    if ( fLODMatrix ) mDel [] fLODMatrix;
    if ( bVISMatrix ) mDel [] bVISMatrix;
}

void CTerrainCircuit::Init (int _SecsPerRow, int _SecsPerCol, float _SectorSize)
{
    SecsPerRow = _SecsPerRow;
    SecsPerCol = _SecsPerCol;
    SectorSize = _SectorSize;

    bVISMatrix = mNew bool [_SecsPerRow * _SecsPerCol];
    fLODMatrix = mNew float[_SecsPerRow * _SecsPerCol];

    CGSceneGroup::Init(SecsPerRow * SecsPerCol);
}

void CTerrainCircuit::SetSector (int _iX, int _iY, CGSceneNode* _pSector)
{
    iAddObject(_pSector);
}

void CTerrainCircuit::Render ()
{
    int cI,cJ,cSect;

    #ifdef TIMING
    Chrono.Reset();
    Chrono.Start();
    #endif

    ComputeVISLODMatrix();

    #ifdef TIMING
    Chrono.Stop();

    dAccumET += Chrono.dElapsedTime();
    iNumCalls++;
    #endif

    cSect = 0;
    for ( cJ = 0; cJ < SecsPerCol; cJ++ )
        for ( cI = 0; cI < SecsPerRow; cI++ )
        {
            if ( bVISMatrix[cSect] )
            {
                if ( poSubObj[cSect]->bVisible() )
                {
                    ComputeLODArrays (cI, cJ);

                    CGRenderer::I()->PushWorldMatrix();

                    // Translate the current sector
                    CGMatrix4x4 oM;
                    oM.LoadIdentity();
                    oM.Translate(cI * SectorSize,cJ * SectorSize,0);

                    CGRenderer::I()->MultiplyMatrix(&oM);

                    // Render the current sector
                    poSubObj[cSect]->Render();

                    CGRenderer::I()->PopWorldMatrix();
                }
            }

            cSect++;
        }
}

void CTerrainCircuit::ComputeVISLODMatrix ()
{
    int cI,cJ,cSect;
    CGVect3 SectorCenter;
    float fSectorDistance;
    CGMatrix4x4 M;

    // Get the current matrix
    CGRenderer::I()->GetWorldMatrix(&M);

    // traverse each terrain sector
    cSect = 0;
    for ( cJ = 0; cJ < SecsPerCol; cJ++ )
        for ( cI = 0; cI < SecsPerRow; cI++ )
        {
            // Get the middle height
            SectorCenter = poSubObj[cSect]->poGetBV()->GetCenter();

            // Set the sector center in camera coordinates
            M.TransformPoint( SectorCenter );

            // Compute the distance to the sector center
            fSectorDistance = SectorCenter.fModule();
            fLODMatrix[cSect] = LODSelector->GetLOD(fSectorDistance);

            if ( fLODMatrix[cSect] < 0.0f )
            {
                fLODMatrix[cSect] *= -1.0f;
                bVISMatrix[cSect] = false;
            }
            else
                bVISMatrix[cSect] = true;

            cSect++;
        }
}

void CTerrainCircuit::ComputeLODArrays (int iX, int iY)
{
    fLODs[0] = fLODMatrix[iY * SecsPerRow + iX];

    SetLOD(1,iX,iY - 1);                    // North
    SetLOD(2,iX + 1,iY  );                    // East
    SetLOD(3,iX,iY + 1);                    // South
    SetLOD(4,iX - 1,iY  );                    // West

    for ( int i = 0; i < 5; i++ ) iLODs[i] = (int)fLODs[i];
}

void CTerrainCircuit::SetLOD (int iBlockIdx, int iX, int iY)
{
    if ( BlockInRange(iX,iY) )
        fLODs[iBlockIdx] = fLODMatrix[iY * SecsPerRow + iX];
    else
        fLODs[iBlockIdx] = fLODs[0];

    // fLODs[iBlockIdx] = (BlockInRange(iX,iY)) ? fLODMatrix[iY*SecsPerRow+iX] :fLODs[0];
}

bool CTerrainCircuit::BlockInRange (int iX, int iY)
{
    return( (iX >= 0) && (iX < SecsPerRow) && (iY >= 0) && (iY < SecsPerCol) );
}

// Additional Declarations
