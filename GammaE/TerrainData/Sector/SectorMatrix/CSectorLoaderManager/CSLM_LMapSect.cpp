//## begin module%3B312EFC0136.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3B312EFC0136.cm

//## begin module%3B312EFC0136.cp preserve=no
//## end module%3B312EFC0136.cp

//## Module: CSLM_LMapSect%3B312EFC0136; Pseudo Package body
//## Source file: E:\Projects\GammaE\TerrainData\Sector\SectorMatrix\CSectorLoaderManager\CSLM_LMapSect.cpp

//## begin module%3B312EFC0136.additionalIncludes preserve=no
//## end module%3B312EFC0136.additionalIncludes

//## begin module%3B312EFC0136.includes preserve=yes
//## end module%3B312EFC0136.includes

// CSLM_LMapSect
#include "TerrainData\Sector\SectorMatrix\CSectorLoaderManager\CSLM_LMapSect.h"
//## begin module%3B312EFC0136.additionalDeclarations preserve=yes
//## end module%3B312EFC0136.additionalDeclarations


// Class CSLM_LMapSect 

CSLM_LMapSect::CSLM_LMapSect()
  //## begin CSLM_LMapSect::CSLM_LMapSect%.hasinit preserve=no
  //## end CSLM_LMapSect::CSLM_LMapSect%.hasinit
  //## begin CSLM_LMapSect::CSLM_LMapSect%.initialization preserve=yes
  //## end CSLM_LMapSect::CSLM_LMapSect%.initialization
{
  //## begin CSLM_LMapSect::CSLM_LMapSect%.body preserve=yes
  //## end CSLM_LMapSect::CSLM_LMapSect%.body
}


CSLM_LMapSect::~CSLM_LMapSect()
{
  //## begin CSLM_LMapSect::~CSLM_LMapSect%.body preserve=yes
  //## end CSLM_LMapSect::~CSLM_LMapSect%.body
}



//## Other Operations (implementation)
CSector * CSLM_LMapSect::poCreateClass (FILE *_FD)
{
  //## begin CSLM_LMapSect::poCreateClass%993079315.body preserve=yes
	if (! _FD) return(NULL);

	unsigned int uiID;
	unsigned int uiBlockLenght;

	fread(&uiID         ,4,1,_FD);
	fread(&uiBlockLenght,4,1,_FD);

	switch (uiID)
	{
		case MAKE_RIFF_ID('L','S','G','R'): return( new( CLMSector_Gray ) );
											break;
		case MAKE_RIFF_ID('L','S','P','L'): return( new( CLMSector_Pal ) );
											break;
		case MAKE_RIFF_ID('L','S','2','4'): return( new( CLMSector_RGB24 ) );
											break;
		default:
											return(NULL);
	}

	return(NULL);
  //## end CSLM_LMapSect::poCreateClass%993079315.body
}

// Additional Declarations
  //## begin CSLM_LMapSect%3B312EFC0136.declarations preserve=yes
  //## end CSLM_LMapSect%3B312EFC0136.declarations

//## begin module%3B312EFC0136.epilog preserve=yes
//## end module%3B312EFC0136.epilog
