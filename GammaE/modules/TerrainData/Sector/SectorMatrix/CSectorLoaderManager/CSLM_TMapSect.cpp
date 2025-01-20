//## begin module%3B312EED01E0.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3B312EED01E0.cm

//## begin module%3B312EED01E0.cp preserve=no
//## end module%3B312EED01E0.cp

//## Module: CSLM_TMapSect%3B312EED01E0; Pseudo Package body
//## Source file: E:\Projects\GammaE\TerrainData\Sector\SectorMatrix\CSectorLoaderManager\CSLM_TMapSect.cpp

//## begin module%3B312EED01E0.additionalIncludes preserve=no
//## end module%3B312EED01E0.additionalIncludes

//## begin module%3B312EED01E0.includes preserve=yes
//## end module%3B312EED01E0.includes

// CSLM_TMapSect
#include "TerrainData\Sector\SectorMatrix\CSectorLoaderManager\CSLM_TMapSect.h"
//## begin module%3B312EED01E0.additionalDeclarations preserve=yes
//## end module%3B312EED01E0.additionalDeclarations


// Class CSLM_TMapSect 

CSLM_TMapSect::CSLM_TMapSect()
  //## begin CSLM_TMapSect::CSLM_TMapSect%.hasinit preserve=no
  //## end CSLM_TMapSect::CSLM_TMapSect%.hasinit
  //## begin CSLM_TMapSect::CSLM_TMapSect%.initialization preserve=yes
  //## end CSLM_TMapSect::CSLM_TMapSect%.initialization
{
  //## begin CSLM_TMapSect::CSLM_TMapSect%.body preserve=yes
  //## end CSLM_TMapSect::CSLM_TMapSect%.body
}


CSLM_TMapSect::~CSLM_TMapSect()
{
  //## begin CSLM_TMapSect::~CSLM_TMapSect%.body preserve=yes
  //## end CSLM_TMapSect::~CSLM_TMapSect%.body
}



//## Other Operations (implementation)
CSector * CSLM_TMapSect::poCreateClass (FILE *_FD)
{
  //## begin CSLM_TMapSect::poCreateClass%993079316.body preserve=yes
	if (! _FD) return(NULL);

	unsigned int uiID;
	unsigned int uiBlockLenght;

	fread(&uiID         ,4,1,_FD);
	fread(&uiBlockLenght,4,1,_FD);

	switch (uiID)
	{
		case MAKE_RIFF_ID('T','M','C','S'): return( new( CTMSector_8_16 ) );
											break;
		default:
											return(NULL);
	}

	return(NULL);

  //## end CSLM_TMapSect::poCreateClass%993079316.body
}

// Additional Declarations
  //## begin CSLM_TMapSect%3B312EED01E0.declarations preserve=yes
  //## end CSLM_TMapSect%3B312EED01E0.declarations

//## begin module%3B312EED01E0.epilog preserve=yes
//## end module%3B312EED01E0.epilog
