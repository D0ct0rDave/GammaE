//## begin module%3AFEFDB300B4.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3AFEFDB300B4.cm

//## begin module%3AFEFDB300B4.cp preserve=no
//## end module%3AFEFDB300B4.cp

//## Module: CTerrainCircuit%3AFEFDB300B4; Pseudo Package body
//## Source file: i:\Projects\GammaE\Terrain\TerrainScene\CTerrainCircuit.cpp

//## begin module%3AFEFDB300B4.additionalIncludes preserve=no
//## end module%3AFEFDB300B4.additionalIncludes

//## begin module%3AFEFDB300B4.includes preserve=yes
#include <string.h>
#include "Memory/GammaE_Mem.h"
#include "Misc/GammaE_Misc.h"
//## end module%3AFEFDB300B4.includes

// CTerrainCircuit
#include "Terrain\TerrainScene\CTerrainCircuit.h"
//## begin module%3AFEFDB300B4.additionalDeclarations preserve=yes

#ifdef _DEBUG	
	
	CChrono Chrono;
	double dAccumET  = 0.0;
	int	   iNumCalls = 0;

#endif

//## end module%3AFEFDB300B4.additionalDeclarations


// Class CTerrainCircuit 









CTerrainCircuit::CTerrainCircuit()
  //## begin CTerrainCircuit::CTerrainCircuit%.hasinit preserve=no
      : SecsPerRow(0), SecsPerCol(0), SectorSize(0), fLODMatrix(NULL), bVISMatrix(NULL)
  //## end CTerrainCircuit::CTerrainCircuit%.hasinit
  //## begin CTerrainCircuit::CTerrainCircuit%.initialization preserve=yes
  //## end CTerrainCircuit::CTerrainCircuit%.initialization
{
  //## begin CTerrainCircuit::CTerrainCircuit%.body preserve=yes
	bFrustumTest = false;
	CE3D_RenderVars::AddRenderVar("iLODs",iLODs);
	CE3D_RenderVars::AddRenderVar("fLODs",fLODs);
  //## end CTerrainCircuit::CTerrainCircuit%.body
}


CTerrainCircuit::~CTerrainCircuit()
{
  //## begin CTerrainCircuit::~CTerrainCircuit%.body preserve=yes
	if (fLODMatrix) mDel []fLODMatrix;
	if (bVISMatrix) mDel []bVISMatrix;
  //## end CTerrainCircuit::~CTerrainCircuit%.body
}



//## Other Operations (implementation)
void CTerrainCircuit::Init (int _SecsPerRow, int _SecsPerCol, float _SectorSize)
{
  //## begin CTerrainCircuit::Init%994715399.body preserve=yes
	SecsPerRow = _SecsPerRow;
	SecsPerCol = _SecsPerCol;
	SectorSize = _SectorSize;

	bVISMatrix = mNew bool [_SecsPerRow*_SecsPerCol];
	fLODMatrix = mNew float[_SecsPerRow*_SecsPerCol];
	
	CObject3D_Node::Init(SecsPerRow*SecsPerCol);
  //## end CTerrainCircuit::Init%994715399.body
}

void CTerrainCircuit::SetSector (int _iX, int _iY, CObject3D *_pSector)
{
  //## begin CTerrainCircuit::SetSector%990048933.body preserve=yes	
	iAddObject(_pSector);	
  //## end CTerrainCircuit::SetSector%990048933.body
}

void CTerrainCircuit::Render ()
{
  //## begin CTerrainCircuit::Render%989790242.body preserve=yes
	int		cI,cJ,cSect;	

#ifdef _DEBUG	 
	Chrono.Reset();
	Chrono.Start();
#endif

	ComputeVISLODMatrix();	

	cSect = 0;
	for (cJ=0;cJ<SecsPerCol;cJ++)		
		for (cI=0;cI<SecsPerRow;cI++)
		{			
			if (bVISMatrix[cSect])
			{
				if (poSubObj[cSect]->bVisible())
				{
					ComputeLODArrays (cI, cJ);
					
					gpoE3DRenderer->PushMatrix();

						// Translate the current sector
						gpoE3DRenderer->Translate(cI*SectorSize,cJ*SectorSize,0);

						// Render the current sector
						poSubObj[cSect]->Render();
			
					gpoE3DRenderer->PopMatrix();
				}
			}

			cSect++;
		}

#ifdef _DEBUG
	Chrono.Stop();
	
	dAccumET  += Chrono.ElapsedTime();
	iNumCalls ++;
#endif
  //## end CTerrainCircuit::Render%989790242.body
}

void CTerrainCircuit::ComputeVISLODMatrix ()
{
  //## begin CTerrainCircuit::ComputeVISLODMatrix%995406154.body preserve=yes
	int				cI,cJ,cSect;
	CVect3			SectorCenter;
	float			fSectorDistance;	
	CMatrix4x4		M;
	
	// Get the current matrix
	gpoE3DRenderer->GetCurrentMatrix(&M);

	// traverse each terrain sector
	cSect = 0;
	for (cJ=0;cJ<SecsPerCol;cJ++)
		for (cI=0;cI<SecsPerRow;cI++)
		{	
			// Get the middle height
			SectorCenter = poSubObj[cSect]->poGetBoundVol()->GetCenter();

			// Set the sector center in camera coordinates
			M.TransformPoint( SectorCenter );

			// Compute the distance to the sector center
			fSectorDistance   = SectorCenter.Module();

			fLODMatrix[cSect] = LODSelector->GetLOD(fSectorDistance);

			if (fLODMatrix[cSect] < 0.0f)
			{
				fLODMatrix[cSect]*=-1.0f;
				bVISMatrix[cSect] = false;
			}
			else
				bVISMatrix[cSect] = true;
			
			cSect++;
		}
  //## end CTerrainCircuit::ComputeVISLODMatrix%995406154.body
}

void CTerrainCircuit::ComputeLODArrays (int iX, int iY)
{
  //## begin CTerrainCircuit::ComputeLODArrays%995488540.body preserve=yes
	fLODs[0] = fLODMatrix[iY*SecsPerRow+iX];

	SetLOD(1,iX  ,iY-1);	// North
	SetLOD(2,iX+1,iY  );	// East
	SetLOD(3,iX  ,iY+1);	// South
	SetLOD(4,iX-1,iY  );	// West

	for (int i=0;i<5;i++) iLODs[i] = (int)fLODs[i];
  //## end CTerrainCircuit::ComputeLODArrays%995488540.body
}

void CTerrainCircuit::SetLOD (int iBlockIdx, int iX, int iY)
{
  //## begin CTerrainCircuit::SetLOD%995639486.body preserve=yes
	if ( BlockInRange(iX,iY) )
		fLODs[iBlockIdx] = fLODMatrix[iY*SecsPerRow+iX];
	else 
		fLODs[iBlockIdx] = fLODs[0]; 

	// fLODs[iBlockIdx] = (BlockInRange(iX,iY)) ? fLODMatrix[iY*SecsPerRow+iX] :fLODs[0];
  //## end CTerrainCircuit::SetLOD%995639486.body
}

bool CTerrainCircuit::BlockInRange (int iX, int iY)
{
  //## begin CTerrainCircuit::BlockInRange%995639485.body preserve=yes
	return( (iX >=0) && (iX<SecsPerRow) && (iY >=0) && (iY<SecsPerCol) );
  //## end CTerrainCircuit::BlockInRange%995639485.body
}

// Additional Declarations
  //## begin CTerrainCircuit%3AFEFDB300B4.declarations preserve=yes
  //## end CTerrainCircuit%3AFEFDB300B4.declarations

//## begin module%3AFEFDB300B4.epilog preserve=yes
//## end module%3AFEFDB300B4.epilog
