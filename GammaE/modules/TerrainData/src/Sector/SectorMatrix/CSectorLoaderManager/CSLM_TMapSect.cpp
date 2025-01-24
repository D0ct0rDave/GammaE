



#include "GammaE_Mem.h"

// CSLM_TMapSect
#include "Sector\SectorMatrix\CSectorLoaderManager\CSLM_TMapSect.h"


// Class CSLM_TMapSect 

CSLM_TMapSect::CSLM_TMapSect()
        {
}


CSLM_TMapSect::~CSLM_TMapSect()
{
}



CSector * CSLM_TMapSect::poCreateClass (FILE *_FD)
{
  	if (! _FD) return(NULL);

	unsigned int uiID;
	unsigned int uiBlockLenght;

	fread(&uiID         ,4,1,_FD);
	fread(&uiBlockLenght,4,1,_FD);

	switch (uiID)
	{
		case MAKE_RIFF_ID('T','M','C','S'): return( mNew ( CTMSector_8_16 ) );
											break;
		default:
											return(NULL);
	}

	return(NULL);

}

// Additional Declarations
    
