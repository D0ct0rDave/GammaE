//## begin module%3AFE96C5000A.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3AFE96C5000A.cm

//## begin module%3AFE96C5000A.cp preserve=no
//## end module%3AFE96C5000A.cp

//## Module: CTile%3AFE96C5000A; Pseudo Package body
//## Source file: E:\Projects\GammaE\TerrainData\SectElem\CTile.cpp

//## begin module%3AFE96C5000A.additionalIncludes preserve=no
//## end module%3AFE96C5000A.additionalIncludes

//## begin module%3AFE96C5000A.includes preserve=yes
//## end module%3AFE96C5000A.includes

// CTile
#include "TerrainData\SectElem\CTile.h"
//## begin module%3AFE96C5000A.additionalDeclarations preserve=yes
//## end module%3AFE96C5000A.additionalDeclarations


// Class CTile 







CTile::CTile()
  //## begin CTile::CTile%.hasinit preserve=no
      : TileIdx(0), TransitionType(0), TransTileIdx(0), RotationType(0), Invisible(true), OldTransition(0)
  //## end CTile::CTile%.hasinit
  //## begin CTile::CTile%.initialization preserve=yes
  //## end CTile::CTile%.initialization
{
  //## begin CTile::CTile%.body preserve=yes
  //## end CTile::CTile%.body
}


CTile::~CTile()
{
  //## begin CTile::~CTile%.body preserve=yes
  //## end CTile::~CTile%.body
}



//## Other Operations (implementation)
unsigned long CTile::ByteSize ()
{
  //## begin CTile::ByteSize%989763979.body preserve=yes
	return(4);
  //## end CTile::ByteSize%989763979.body
}

void * CTile::Get ()
{
  //## begin CTile::Get%989763984.body preserve=yes
	return( &TileIdx);
  //## end CTile::Get%989763984.body
}

void CTile::Set (void *_Value)
{
  //## begin CTile::Set%989763985.body preserve=yes
  //## end CTile::Set%989763985.body
}

CSectElem * CTile::CreateClass ()
{
  //## begin CTile::CreateClass%991155102.body preserve=yes
	return (new CTile() );
  //## end CTile::CreateClass%991155102.body
}

//## Get and Set Operations for Class Attributes (implementation)

int CTile::GetTileIdx ()
{
  //## begin CTile::GetTileIdx%3AFE96DE0370.get preserve=no
  return TileIdx;
  //## end CTile::GetTileIdx%3AFE96DE0370.get
}

void CTile::SetTileIdx (int value)
{
  //## begin CTile::SetTileIdx%3AFE96DE0370.set preserve=no
  TileIdx = value;
  //## end CTile::SetTileIdx%3AFE96DE0370.set
}

int CTile::GetTransitionType ()
{
  //## begin CTile::GetTransitionType%3AFE97330352.get preserve=no
  return TransitionType;
  //## end CTile::GetTransitionType%3AFE97330352.get
}

void CTile::SetTransitionType (int value)
{
  //## begin CTile::SetTransitionType%3AFE97330352.set preserve=no
  TransitionType = value;
  //## end CTile::SetTransitionType%3AFE97330352.set
}

void CTile::SetTransTileIdx (int value)
{
  //## begin CTile::SetTransTileIdx%3AFE9753021C.set preserve=no
  TransTileIdx = value;
  //## end CTile::SetTransTileIdx%3AFE9753021C.set
}

int CTile::GetRotationType ()
{
  //## begin CTile::GetRotationType%3AFE974902F8.get preserve=no
  return RotationType;
  //## end CTile::GetRotationType%3AFE974902F8.get
}

void CTile::SetRotationType (int value)
{
  //## begin CTile::SetRotationType%3AFE974902F8.set preserve=no
  RotationType = value;
  //## end CTile::SetRotationType%3AFE974902F8.set
}

bool CTile::GetInvisible ()
{
  //## begin CTile::GetInvisible%3AFE97610334.get preserve=no
  return Invisible;
  //## end CTile::GetInvisible%3AFE97610334.get
}

void CTile::SetInvisible (bool value)
{
  //## begin CTile::SetInvisible%3AFE97610334.set preserve=no
  Invisible = value;
  //## end CTile::SetInvisible%3AFE97610334.set
}

int CTile::GetOldTransition ()
{
  //## begin CTile::GetOldTransition%3AFE97AF03D4.get preserve=no
  return OldTransition;
  //## end CTile::GetOldTransition%3AFE97AF03D4.get
}

void CTile::SetOldTransition (int value)
{
  //## begin CTile::SetOldTransition%3AFE97AF03D4.set preserve=no
  OldTransition = value;
  //## end CTile::SetOldTransition%3AFE97AF03D4.set
}

// Additional Declarations
  //## begin CTile%3AFE96C5000A.declarations preserve=yes
  //## end CTile%3AFE96C5000A.declarations

//## begin module%3AFE96C5000A.epilog preserve=yes
//## end module%3AFE96C5000A.epilog
