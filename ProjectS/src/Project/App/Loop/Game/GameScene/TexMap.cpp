//---------------------------------------------------------------------------
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


#include "TexMap.h"
#include "File.h"

// -------------------------------------------------------------
TTexMap::TTexMap()
{
	TMap = NULL;
    Invalidate();
}

TTexMap::TTexMap(unsigned int TheLTileLevel,float TheSectorSize,unsigned int TheSecsPerRow,unsigned int TheSecsPerCol,char *TexMapName)
{
	TMap = NULL;
	Init(TheLTileLevel,TheSectorSize,TheSecsPerRow,TheSecsPerCol,TexMapName);
}

TTexMap::~TTexMap()
{
    Invalidate();
}

void TTexMap::Invalidate()
{
	if (TMap) delete TMap;

	TMap       = NULL;
	SecsPerRow = 0;
	SecsPerCol = 0;
	LTileLevel = 0;
	SectorRes  = 0;
}

void TTexMap::Init(unsigned int TheLTileLevel,
                   float		TheSectorSize,
                   unsigned int TheSecsPerRow,
                   unsigned int TheSecsPerCol,
                   char		   *TexMapName)
{
	Invalidate();
    
    if (TexMapName)
        strcpy(Name,TexMapName);
    else
        strcpy(Name,TM_DEFAULT_TEXMAP_NAME);

	TMap = new CTexMap();
	TMap->Init(TheSecsPerRow,TheSecsPerCol,1 << TheLTileLevel,0,false);
	
	UpdateLocalVariables();
}
// -------------------------------------------------------------
TTexMap& TTexMap::operator = (TTexMap& Src)
{
	Invalidate();

    TMap = new CTexMap();
	*TMap = *Src.TMap;

	UpdateLocalVariables();
    
    return *this;
}
// -------------------------------------------------------------
// Direct access functions. The coordinates are given relative to the texmap.
// -------------------------------------------------------------
// Set/Get Texture indexes

void TTexMap::SetTexIndex(unsigned int Sector,unsigned int cX,unsigned int cY,tdTexIndexType TexIndex)
{
	CTile *Tile = (CTile *)&TMap->GetValueFromSect(Sector,cX,cY);
	Tile->SetTileIdx (TexIndex);
	TMap->SetValueFromSect(Sector,cX,cY,*Tile);
}

void TTexMap::SetFlags(unsigned int Sector,unsigned int cX,unsigned int cY,tdRFlagType Flags)
{
	CTile *Tile = (CTile *)&TMap->GetValueFromSect(Sector,cX,cY);

	Tile->SetRotationType  ( (Flags & TM_RFLAGS_ROTATION_MASK     ) >> TM_RFLAGS_ROTATION_SHIFTBITS     );
	Tile->SetTransitionType( (Flags & TM_RFLAGS_TRANSITION_MASK   ) >> TM_RFLAGS_TRANSITION_SHIFTBITS   );
	Tile->SetTransTileIdx  ( (Flags & TM_RFLAGS_TRANSITIONTEX_MASK) >> TM_RFLAGS_TRANSITIONTEX_SHIFTBITS);
	Tile->SetInvisible     ( (Flags & TM_RFLAGS_INVISTILE_MASK    ) >> TM_RFLAGS_INVISTILE_SHIFTBITS    );
}

tdRFlagType TTexMap::GetFlags(unsigned int Sector,unsigned int cX,unsigned int cY)
{
	tdRFlagType Flag = 0;
	CTile *Tile = (CTile *)&TMap->GetValueFromSect(Sector,cX,cY);

	Flag = (Tile->GetRotationType()   << TM_RFLAGS_ROTATION_SHIFTBITS     ) |
		   (Tile->GetTransitionType() << TM_RFLAGS_TRANSITION_SHIFTBITS   ) |	
		   (Tile->GetTransTileIdx()   << TM_RFLAGS_TRANSITIONTEX_SHIFTBITS) |
		   (Tile->GetInvisible()      << TM_RFLAGS_INVISTILE_SHIFTBITS );

	return ( Flag );
}

tdTexIndexType TTexMap::GetTexIndex(unsigned int Sector,unsigned int cX,unsigned int cY)
{
	CTile *Tile = (CTile *)&TMap->GetValueFromSect(Sector,cX,cY);
	return (Tile->GetTileIdx() );	
}

// Set/Get rotation values
void TTexMap::SetRotation(unsigned int Sector,unsigned int cX,unsigned int cY,tdRFlagType Rotation)
{
	CTile *Tile = (CTile *)&TMap->GetValueFromSect(Sector,cX,cY);
	Tile->SetRotationType(Rotation);
	TMap->SetValueFromSect(Sector,cX,cY,*Tile);
}

tdRFlagType TTexMap::GetRotation(unsigned int Sector,unsigned int cX,unsigned int cY)
{
	CTile *Tile = (CTile *)&TMap->GetValueFromSect(Sector,cX,cY);
	return (Tile->GetRotationType());
}

// Set/Get transition flags
void TTexMap::SetTransition(unsigned int Sector,unsigned int cX,unsigned int cY,tdRFlagType Transition)
{
	CTile *Tile = (CTile *)&TMap->GetValueFromSect(Sector,cX,cY);
	Tile->SetTransitionType(Transition);
	TMap->SetValueFromSect(Sector,cX,cY,*Tile);
}

tdRFlagType TTexMap::GetTransition(unsigned int Sector,unsigned int cX,unsigned int cY)
{
	CTile *Tile = (CTile *)&TMap->GetValueFromSect(Sector,cX,cY);
	return (Tile->GetTransitionType() );	
}

// Set/Get transition textures
void TTexMap::SetTransitionTex(unsigned int Sector,unsigned int cX,unsigned int cY,tdTexIndexType TexIndex)
{
	CTile *Tile = (CTile *)&TMap->GetValueFromSect(Sector,cX,cY);
	Tile->SetTransTileIdx(TexIndex);
	TMap->SetValueFromSect(Sector,cX,cY,*Tile);
}

tdTexIndexType TTexMap::GetTransitionTex(unsigned int Sector,unsigned int cX,unsigned int cY)
{
	CTile *Tile = (CTile *)&TMap->GetValueFromSect(Sector,cX,cY);
	return (Tile->GetTransTileIdx() );	
}

// Set/Get transition textures
void TTexMap::SetInvisibilityFlag(unsigned int Sector,unsigned int cX,unsigned int cY,bool Invis)
{
	CTile *Tile = (CTile *)&TMap->GetValueFromSect(Sector,cX,cY);
	Tile->SetInvisible(Invis);
	TMap->SetValueFromSect(Sector,cX,cY,*Tile);
}

bool TTexMap::GetInvisibilityFlag(unsigned int Sector,unsigned int cX,unsigned int cY)
{
	CTile *Tile = (CTile *)&TMap->GetValueFromSect(Sector,cX,cY);
	return ( Tile->GetInvisible() );	
}
// -------------------------------------------------------------
// Absolute functions: The coordinates are givzn relative to the whole texture map
// -------------------------------------------------------------
// Set/Get Texture indexes
#undef  GetSectorIdx
#define GetSectorIdx(cX,cY) ((cY / SectorRes) * SecsPerRow + (cX / SectorRes))
// -------------------------------------------------------------
void TTexMap::SetTexIndexAbs(unsigned int cX,unsigned int cY,tdTexIndexType TexIndex)
{
    unsigned int Sector;
    Sector =  GetSectorIdx(cX,cY);
    SetTexIndex(Sector,cX % SectorRes, cY % SectorRes,TexIndex);
}
// -------------------------------------------------------------
tdTexIndexType TTexMap::GetTexIndexAbs(unsigned int cX,unsigned int cY)
{
    unsigned int Sector;
    Sector =  GetSectorIdx(cX,cY);
    return(GetTexIndex(Sector,cX % SectorRes, cY % SectorRes));
}
// -------------------------------------------------------------
// Set/Get rotation values
void TTexMap::SetRotationAbs(unsigned int cX,unsigned int cY,tdRFlagType Rotation)
{
    unsigned int Sector;
    Sector =  GetSectorIdx(cX,cY);
    SetRotation(Sector,cX % SectorRes, cY % SectorRes,Rotation);
}
// -------------------------------------------------------------
tdRFlagType TTexMap::GetRotationAbs(unsigned int cX,unsigned int cY)
{
    unsigned int Sector;
    Sector =  GetSectorIdx(cX,cY);

    return(GetRotation(Sector,cX % SectorRes, cY % SectorRes));
}
// -------------------------------------------------------------
// Set/Get transition flags
void TTexMap::SetTransitionAbs(unsigned int cX,unsigned int cY,tdRFlagType Transition)
{
    unsigned int Sector;
    Sector =  GetSectorIdx(cX,cY);
    SetTransition(Sector,cX % SectorRes, cY % SectorRes,Transition);
}
// -------------------------------------------------------------
tdRFlagType TTexMap::GetTransitionAbs(unsigned int cX,unsigned int cY)
{
    unsigned int Sector;
    Sector =  GetSectorIdx(cX,cY);
    return(GetTransition(Sector,cX % SectorRes, cY % SectorRes));
}
// -------------------------------------------------------------
// Set/Get transition textures
void TTexMap::SetTransitionTexAbs(unsigned int cX,unsigned int cY,tdTexIndexType TexIndex)
{
    unsigned int Sector;
    Sector =  GetSectorIdx(cX,cY);
    SetTransitionTex(Sector,cX % SectorRes, cY % SectorRes,TexIndex);
}
// -------------------------------------------------------------
tdTexIndexType TTexMap::GetTransitionTexAbs(unsigned int cX,unsigned int cY)
{
    unsigned int Sector;
    Sector = GetSectorIdx(cX,cY);
	return(GetTransitionTex(Sector,cX % SectorRes, cY % SectorRes));
}
// -------------------------------------------------------------
// Set/Get drawable flag
void TTexMap::SetInvisibilityFlagAbs(unsigned int cX,unsigned int cY,bool Invis)
{
    unsigned int Sector;
    Sector = GetSectorIdx(cX,cY);
	SetInvisibilityFlag(Sector,cX % SectorRes, cY % SectorRes,Invis);
}
// -------------------------------------------------------------
bool TTexMap::GetInvisibilityFlagAbs(unsigned int cX,unsigned int cY)
{
    unsigned int Sector;
    Sector = GetSectorIdx(cX,cY);
	return(GetInvisibilityFlag(Sector,cX % SectorRes, cY % SectorRes));
}
//---------------------------------------------------------------------------
void TTexMap::SetFlagsAbs(unsigned int cX,unsigned int cY,tdRFlagType Flags)
{
    unsigned int Sector;
    Sector = GetSectorIdx(cX,cY);
	SetFlags(Sector,cX % SectorRes, cY % SectorRes,Flags);
}

tdRFlagType TTexMap::GetFlagsAbs(unsigned int cX,unsigned int cY)
{
    unsigned int Sector;
    Sector = GetSectorIdx(cX,cY);

	return( GetFlags(Sector,cX % SectorRes, cY % SectorRes) );
}

//---------------------------------------------------------------------------
// Disk functions
//---------------------------------------------------------------------------
int TTexMap::Load(char *Filename)
{
	if (! Filename) return(0);

    if (! TMap) TMap = new CTexMap();
	int iRes = TMap->iLoad(Filename);
	UpdateLocalVariables();

	return ( iRes );
}
//---------------------------------------------------------------------------
int TTexMap::Save(char *Filename)
{
    if (! Filename) return(0);
    if (!     TMap) return(0);    
	return ( TMap->iSave(Filename) );
}
//---------------------------------------------------------------------------
int TTexMap::SaveWithHandler(FILE *fd)
{
	if (! fd  ) return(0);
    if (! TMap) return(0);
	return (TMap->iSaveWithHandler(fd) );
}
//---------------------------------------------------------------------------
int TTexMap::LoadWithHandler(FILE *fd)
{
	if (! fd) return(0);

    if (! TMap) TMap = new CTexMap();
	int iRes = TMap->iLoadWithHandler(fd);
	UpdateLocalVariables();

	return ( iRes );
}
//---------------------------------------------------------------------------
void TTexMap::UpdateLocalVariables()
{
	SecsPerRow = TMap->iGetSecsPerRow();
	SecsPerCol = TMap->iGetSecsPerCol();

	SectorRes = TMap->GetSector(0)->GetResolution();
    LTileLevel = log(SectorRes)/log(2);
}
//---------------------------------------------------------------------------