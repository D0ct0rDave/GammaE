



#include "GammaE_Mem.h"

// CTile
#include "SectElem\CTile.h"


// Class CTile 







CTile::CTile()
        : TileIdx(0), TransitionType(0), TransTileIdx(0), RotationType(0), Invisible(true), OldTransition(0)
      {
}


CTile::~CTile()
{
}



unsigned long CTile::ByteSize ()
{
  	return(4);
}

void * CTile::Get ()
{
  	return( &TileIdx);
}

void CTile::Set (void *_Value)
{
}

CSectElem * CTile::CreateClass ()
{
  	return (mNew CTile() );
}


int CTile::GetTileIdx ()
{
    return TileIdx;
}

void CTile::SetTileIdx (int value)
{
    TileIdx = value;
}

int CTile::GetTransitionType ()
{
    return TransitionType;
}

void CTile::SetTransitionType (int value)
{
    TransitionType = value;
}

void CTile::SetTransTileIdx (int value)
{
    TransTileIdx = value;
}

int CTile::GetRotationType ()
{
    return RotationType;
}

void CTile::SetRotationType (int value)
{
    RotationType = value;
}

bool CTile::GetInvisible ()
{
    return Invisible;
}

void CTile::SetInvisible (bool value)
{
    Invisible = value;
}

int CTile::GetOldTransition ()
{
    return OldTransition;
}

void CTile::SetOldTransition (int value)
{
    OldTransition = value;
}

// Additional Declarations
    
