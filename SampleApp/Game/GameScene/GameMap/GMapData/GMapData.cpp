//## begin module%3C7E070B02A2.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3C7E070B02A2.cm

//## begin module%3C7E070B02A2.cp preserve=no
//## end module%3C7E070B02A2.cp

//## Module: GMapData%3C7E070B02A2; Pseudo Package body
//## Source file: i:\Projects\GammaE\Game\GameScene\GameMap\GMapData\GMapData.cpp

//## begin module%3C7E070B02A2.additionalIncludes preserve=no
//## end module%3C7E070B02A2.additionalIncludes

//## begin module%3C7E070B02A2.includes preserve=yes
//## end module%3C7E070B02A2.includes

// GMapData
#include "Game\GameScene\GameMap\GMapData\GMapData.h"
//## begin module%3C7E070B02A2.additionalDeclarations preserve=yes
//## end module%3C7E070B02A2.additionalDeclarations


// Class GMapData 




GMapData::GMapData()
  //## begin GMapData::GMapData%.hasinit preserve=no
      : poEntity(NULL), iNumEntities(0), poMap(NULL)
  //## end GMapData::GMapData%.hasinit
  //## begin GMapData::GMapData%.initialization preserve=yes
  //## end GMapData::GMapData%.initialization
{
  //## begin GMapData::GMapData%.body preserve=yes
  //## end GMapData::GMapData%.body
}


GMapData::~GMapData()
{
  //## begin GMapData::~GMapData%.body preserve=yes
  //## end GMapData::~GMapData%.body
}



//## Other Operations (implementation)
void GMapData::SetEntities (CMapEntity** _poEntities, int _iNumEntities)
{
  //## begin GMapData::SetEntities%1014892582.body preserve=yes
	poEntity     = _poEntities;
	iNumEntities = _iNumEntities;
  //## end GMapData::SetEntities%1014892582.body
}

void GMapData::SetMap (CObject3D_Gen *_poMap)
{
  //## begin GMapData::SetMap%1014892583.body preserve=yes
	poMap = _poMap;
  //## end GMapData::SetMap%1014892583.body
}

// Additional Declarations
  //## begin GMapData%3C7E070B02A2.declarations preserve=yes
  //## end GMapData%3C7E070B02A2.declarations

//## begin module%3C7E070B02A2.epilog preserve=yes
//## end module%3C7E070B02A2.epilog
