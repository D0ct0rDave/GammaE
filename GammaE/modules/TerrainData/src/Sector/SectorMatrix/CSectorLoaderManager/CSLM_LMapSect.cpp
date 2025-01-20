



#include "GammaE_Mem.h"

// CSLM_LMapSect
#include "Sector\SectorMatrix\CSectorLoaderManager\CSLM_LMapSect.h"


// Class CSLM_LMapSect 

CSLM_LMapSect::CSLM_LMapSect()
        {
}


CSLM_LMapSect::~CSLM_LMapSect()
{
}



CSector * CSLM_LMapSect::poCreateClass (FILE *_FD)
{
  	if (! _FD) return(NULL);

	unsigned int uiID;
	unsigned int uiBlockLenght;

	fread(&uiID         ,4,1,_FD);
	fread(&uiBlockLenght,4,1,_FD);

	switch (uiID)
	{
		case MAKE_RIFF_ID('L','S','G','R'): return( mNew ( CLMSector_Gray ) );
											break;
		case MAKE_RIFF_ID('L','S','P','L'): return( mNew ( CLMSector_Pal ) );
											break;
		case MAKE_RIFF_ID('L','S','2','4'): return( mNew ( CLMSector_RGB24 ) );
											break;
		default:
											return(NULL);
	}

	return(NULL);
}

// Additional Declarations
    
