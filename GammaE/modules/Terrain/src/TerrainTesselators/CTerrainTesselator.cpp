//	  %X% %Q% %Z% %W%





// CTerrainTesselator
#include "TerrainTesselators\CTerrainTesselator.h"


// Class CTerrainTesselator 










CTerrainTesselator::CTerrainTesselator()
        : fLODs(NULL), iLODs(NULL), HF(NULL), LM(NULL), TM(NULL), TB(NULL), fXYScale(NULL)
      {
}


CTerrainTesselator::~CTerrainTesselator()
{
}



void CTerrainTesselator::Render ()
{
}

void CTerrainTesselator::SetData (CHFSector* _HF, CLMSector* _LM, CTMSector* _TM, CTileBookmark* _TB, float *_fLODs, int *_iLODs, float _fXYScale)
{
  	HF		= _HF;
	LM		= _LM;
	TM		= _TM;
	TB		= _TB;
	fLODs	= _fLODs;
	iLODs   = _iLODs;
	fXYScale = _fXYScale;
}

void CTerrainTesselator::SetCameraPos (CVect3 _Pos)
{
  	Cam = _Pos;
}

// Additional Declarations
    
