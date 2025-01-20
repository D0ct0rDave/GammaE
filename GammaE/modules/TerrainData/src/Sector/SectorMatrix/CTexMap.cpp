//## begin module%3AFE944E02A8.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3AFE944E02A8.cm

//## begin module%3AFE944E02A8.cp preserve=no
//## end module%3AFE944E02A8.cp

//## Module: CTexMap%3AFE944E02A8; Pseudo Package body
//## Source file: E:\Projects\GammaE\TerrainData\Sector\SectorMatrix\CTexMap.cpp

//## begin module%3AFE944E02A8.additionalIncludes preserve=no
//## end module%3AFE944E02A8.additionalIncludes

//## begin module%3AFE944E02A8.includes preserve=yes
//## end module%3AFE944E02A8.includes

// CTexMap
#include "TerrainData\Sector\SectorMatrix\CTexMap.h"
//## begin module%3AFE944E02A8.additionalDeclarations preserve=yes
//## end module%3AFE944E02A8.additionalDeclarations


// Class CTexMap 

CTexMap::CTexMap()
  //## begin CTexMap::CTexMap%.hasinit preserve=no
  //## end CTexMap::CTexMap%.hasinit
  //## begin CTexMap::CTexMap%.initialization preserve=yes
  //## end CTexMap::CTexMap%.initialization
{
  //## begin CTexMap::CTexMap%.body preserve=yes
   	ulID = MAKE_RIFF_ID('T','M','A','P');
	poSectManager = new  CSLM_TMapSect();
  //## end CTexMap::CTexMap%.body
}


CTexMap::~CTexMap()
{
  //## begin CTexMap::~CTexMap%.body preserve=yes
	delete poSectManager;
  //## end CTexMap::~CTexMap%.body
}



//## Other Operations (implementation)
CSector * CTexMap::CreateClass ()
{
  //## begin CTexMap::CreateClass%990392863.body preserve=yes
	return ( new CTexMap() );
  //## end CTexMap::CreateClass%990392863.body
}

void CTexMap::Init (int _SecsPerRow, int _SecsPerCol, int _SectorRes, int _SectorType, bool _b21)
{
  //## begin CTexMap::Init%991049054.body preserve=yes
	int cSect;
	
	CSectorMatrix::Init(_SecsPerRow,_SecsPerCol,_SectorRes,_SectorType,_b21);

	// Create sector
	switch (_SectorType)
	{
		case 0:	for (cSect=0;cSect<SecsPerCol*SecsPerRow;cSect++)	
				{
					SectArray[cSect] = new CTMSector_8_16();
					SectArray[cSect]->Init(_SectorRes,_b21);
				}
				break;
	}
  //## end CTexMap::Init%991049054.body
}

unsigned long CTexMap::DataSize ()
{
  //## begin CTexMap::DataSize%991155096.body preserve=yes
  	return(0);
  //## end CTexMap::DataSize%991155096.body
}

// Additional Declarations
  //## begin CTexMap%3AFE944E02A8.declarations preserve=yes
  //## end CTexMap%3AFE944E02A8.declarations

//## begin module%3AFE944E02A8.epilog preserve=yes
//## end module%3AFE944E02A8.epilog
