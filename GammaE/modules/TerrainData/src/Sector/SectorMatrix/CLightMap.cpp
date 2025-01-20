//## begin module%3AFC0CA80212.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3AFC0CA80212.cm

//## begin module%3AFC0CA80212.cp preserve=no
//## end module%3AFC0CA80212.cp

//## Module: CLightMap%3AFC0CA80212; Pseudo Package body
//## Source file: E:\Projects\GammaE\TerrainData\Sector\SectorMatrix\CLightMap.cpp

//## begin module%3AFC0CA80212.additionalIncludes preserve=no
//## end module%3AFC0CA80212.additionalIncludes

//## begin module%3AFC0CA80212.includes preserve=yes
//## end module%3AFC0CA80212.includes

// CLightMap
#include "TerrainData\Sector\SectorMatrix\CLightMap.h"
//## begin module%3AFC0CA80212.additionalDeclarations preserve=yes
//## end module%3AFC0CA80212.additionalDeclarations


// Class CLightMap 

CLightMap::CLightMap()
  //## begin CLightMap::CLightMap%.hasinit preserve=no
  //## end CLightMap::CLightMap%.hasinit
  //## begin CLightMap::CLightMap%.initialization preserve=yes
  //## end CLightMap::CLightMap%.initialization
{
  //## begin CLightMap::CLightMap%.body preserve=yes
   	ulID = MAKE_RIFF_ID('L','M','A','P');
	poSectManager = new  CSLM_LMapSect();
  //## end CLightMap::CLightMap%.body
}


CLightMap::~CLightMap()
{
  //## begin CLightMap::~CLightMap%.body preserve=yes
	delete poSectManager;
  //## end CLightMap::~CLightMap%.body
}



//## Other Operations (implementation)
unsigned long CLightMap::DataSize ()
{
  //## begin CLightMap::DataSize%989597155.body preserve=yes
	return(0);
  //## end CLightMap::DataSize%989597155.body
}

CSector * CLightMap::CreateClass ()
{
  //## begin CLightMap::CreateClass%989597156.body preserve=yes
	return (new CLightMap());
  //## end CLightMap::CreateClass%989597156.body
}

void CLightMap::Init (int _SecsPerRow, int _SecsPerCol, int _SectorRes, int _SectorType, bool _b21)
{
  //## begin CLightMap::Init%989597157.body preserve=yes
	int cSect;

	CSectorMatrix::Init(_SecsPerRow,_SecsPerCol,_SectorRes,_SectorType,_b21);

	// Create sector
	switch (_SectorType)
	{
		case 0:	for (cSect=0;cSect<SecsPerCol*SecsPerRow;cSect++)
				{
					SectArray[cSect] = new CLMSector_RGB24();
					SectArray[cSect]->Init(_SectorRes,_b21);
				}
				break;
	}
  //## end CLightMap::Init%989597157.body
}

// Additional Declarations
  //## begin CLightMap%3AFC0CA80212.declarations preserve=yes
  //## end CLightMap%3AFC0CA80212.declarations

//## begin module%3AFC0CA80212.epilog preserve=yes
//## end module%3AFC0CA80212.epilog
