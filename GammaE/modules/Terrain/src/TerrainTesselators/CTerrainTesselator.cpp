//## begin module%3AFEFF600212.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3AFEFF600212.cm

//## begin module%3AFEFF600212.cp preserve=no
//## end module%3AFEFF600212.cp

//## Module: CTerrainTesselator%3AFEFF600212; Pseudo Package body
//## Source file: i:\Projects\GammaE\Terrain\TerrainTesselators\CTerrainTesselator.cpp

//## begin module%3AFEFF600212.additionalIncludes preserve=no
//## end module%3AFEFF600212.additionalIncludes

//## begin module%3AFEFF600212.includes preserve=yes
//## end module%3AFEFF600212.includes

// CTerrainTesselator
#include "Terrain\TerrainTesselators\CTerrainTesselator.h"
//## begin module%3AFEFF600212.additionalDeclarations preserve=yes
//## end module%3AFEFF600212.additionalDeclarations


// Class CTerrainTesselator 










CTerrainTesselator::CTerrainTesselator()
  //## begin CTerrainTesselator::CTerrainTesselator%.hasinit preserve=no
      : fLODs(NULL), iLODs(NULL), HF(NULL), LM(NULL), TM(NULL), TB(NULL), fXYScale(NULL)
  //## end CTerrainTesselator::CTerrainTesselator%.hasinit
  //## begin CTerrainTesselator::CTerrainTesselator%.initialization preserve=yes
  //## end CTerrainTesselator::CTerrainTesselator%.initialization
{
  //## begin CTerrainTesselator::CTerrainTesselator%.body preserve=yes
  //## end CTerrainTesselator::CTerrainTesselator%.body
}


CTerrainTesselator::~CTerrainTesselator()
{
  //## begin CTerrainTesselator::~CTerrainTesselator%.body preserve=yes
  //## end CTerrainTesselator::~CTerrainTesselator%.body
}



//## Other Operations (implementation)
void CTerrainTesselator::Render ()
{
  //## begin CTerrainTesselator::Render%989790246.body preserve=yes
  //## end CTerrainTesselator::Render%989790246.body
}

void CTerrainTesselator::SetData (CHFSector* _HF, CLMSector* _LM, CTMSector* _TM, CTileBookmark* _TB, float *_fLODs, int *_iLODs, float _fXYScale)
{
  //## begin CTerrainTesselator::SetData%989962904.body preserve=yes
	HF		= _HF;
	LM		= _LM;
	TM		= _TM;
	TB		= _TB;
	fLODs	= _fLODs;
	iLODs   = _iLODs;
	fXYScale = _fXYScale;
  //## end CTerrainTesselator::SetData%989962904.body
}

void CTerrainTesselator::SetCameraPos (CVect3 _Pos)
{
  //## begin CTerrainTesselator::SetCameraPos%990132098.body preserve=yes
	Cam = _Pos;
  //## end CTerrainTesselator::SetCameraPos%990132098.body
}

// Additional Declarations
  //## begin CTerrainTesselator%3AFEFF600212.declarations preserve=yes
  //## end CTerrainTesselator%3AFEFF600212.declarations

//## begin module%3AFEFF600212.epilog preserve=yes
//## end module%3AFEFF600212.epilog
