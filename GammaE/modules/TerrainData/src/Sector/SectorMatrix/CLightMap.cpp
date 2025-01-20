



#include "GammaE_Mem.h"

// CLightMap
#include "Sector\SectorMatrix\CLightMap.h"


// Class CLightMap 

CLightMap::CLightMap()
        {
     	ulID = MAKE_RIFF_ID('L','M','A','P');
	poSectManager = mNew  CSLM_LMapSect();
}


CLightMap::~CLightMap()
{
  	mDel poSectManager;
}



unsigned long CLightMap::DataSize ()
{
  	return(0);
}

CSector * CLightMap::CreateClass ()
{
  	return (mNew CLightMap());
}

void CLightMap::Init (int _SecsPerRow, int _SecsPerCol, int _SectorRes, int _SectorType, bool _b21)
{
  	int cSect;

	CSectorMatrix::Init(_SecsPerRow,_SecsPerCol,_SectorRes,_SectorType,_b21);

	// Create sector
	switch (_SectorType)
	{
		case 0:	for (cSect=0;cSect<SecsPerCol*SecsPerRow;cSect++)
				{
					SectArray[cSect] = mNew CLMSector_RGB24();
					SectArray[cSect]->Init(_SectorRes,_b21);
				}
				break;
	}
}

// Additional Declarations
    
