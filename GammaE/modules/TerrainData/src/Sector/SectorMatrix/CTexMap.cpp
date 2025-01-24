



#include "GammaE_Mem.h"

// CTexMap
#include "Sector\SectorMatrix\CTexMap.h"


// Class CTexMap 

CTexMap::CTexMap()
        {
     	ulID = MAKE_RIFF_ID('T','M','A','P');
	poSectManager = mNew  CSLM_TMapSect();
}


CTexMap::~CTexMap()
{
  	mDel poSectManager;
}



CSector * CTexMap::CreateClass ()
{
  	return ( mNew CTexMap() );
}

void CTexMap::Init (int _SecsPerRow, int _SecsPerCol, int _SectorRes, int _SectorType, bool _b21)
{
  	int cSect;
	
	CSectorMatrix::Init(_SecsPerRow,_SecsPerCol,_SectorRes,_SectorType,_b21);

	// Create sector
	switch (_SectorType)
	{
		case 0:	for (cSect=0;cSect<SecsPerCol*SecsPerRow;cSect++)	
				{
					SectArray[cSect] = mNew CTMSector_8_16();
					SectArray[cSect]->Init(_SectorRes,_b21);
				}
				break;
	}
}

unsigned long CTexMap::DataSize ()
{
    	return(0);
}

// Additional Declarations
    
