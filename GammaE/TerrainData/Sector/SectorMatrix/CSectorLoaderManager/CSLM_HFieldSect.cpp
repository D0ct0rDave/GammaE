//## begin module%3B312EE00050.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3B312EE00050.cm

//## begin module%3B312EE00050.cp preserve=no
//## end module%3B312EE00050.cp

//## Module: CSLM_HFieldSect%3B312EE00050; Pseudo Package body
//## Source file: E:\Projects\GammaE\TerrainData\Sector\SectorMatrix\CSectorLoaderManager\CSLM_HFieldSect.cpp

//## begin module%3B312EE00050.additionalIncludes preserve=no
//## end module%3B312EE00050.additionalIncludes

//## begin module%3B312EE00050.includes preserve=yes
//## end module%3B312EE00050.includes

// CSLM_HFieldSect
#include "TerrainData\Sector\SectorMatrix\CSectorLoaderManager\CSLM_HFieldSect.h"
//## begin module%3B312EE00050.additionalDeclarations preserve=yes
//## end module%3B312EE00050.additionalDeclarations


// Class CSLM_HFieldSect 

CSLM_HFieldSect::CSLM_HFieldSect()
  //## begin CSLM_HFieldSect::CSLM_HFieldSect%.hasinit preserve=no
  //## end CSLM_HFieldSect::CSLM_HFieldSect%.hasinit
  //## begin CSLM_HFieldSect::CSLM_HFieldSect%.initialization preserve=yes
  //## end CSLM_HFieldSect::CSLM_HFieldSect%.initialization
{
  //## begin CSLM_HFieldSect::CSLM_HFieldSect%.body preserve=yes
  //## end CSLM_HFieldSect::CSLM_HFieldSect%.body
}


CSLM_HFieldSect::~CSLM_HFieldSect()
{
  //## begin CSLM_HFieldSect::~CSLM_HFieldSect%.body preserve=yes
  //## end CSLM_HFieldSect::~CSLM_HFieldSect%.body
}



//## Other Operations (implementation)
CSector * CSLM_HFieldSect::poCreateClass (FILE *_FD)
{
  //## begin CSLM_HFieldSect::poCreateClass%993079317.body preserve=yes
	if (! _FD) return(NULL);

	unsigned int uiID;
	unsigned int uiBlockLenght;

	fread(&uiID         ,4,1,_FD);
	fread(&uiBlockLenght,4,1,_FD);

	switch (uiID)
	{
		case MAKE_RIFF_ID('H','S','F','N'): return( new( CHFSector_FN ) );
											break;
		default:
											return(NULL);
	}

	return(NULL);
  //## end CSLM_HFieldSect::poCreateClass%993079317.body
}

// Additional Declarations
  //## begin CSLM_HFieldSect%3B312EE00050.declarations preserve=yes
  //## end CSLM_HFieldSect%3B312EE00050.declarations

//## begin module%3B312EE00050.epilog preserve=yes
//## end module%3B312EE00050.epilog

