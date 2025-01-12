//---------------------------------------------------------------------------
#include "TexObj.h"
#include <stdlib.h>

TTextureObj::TTextureObj()
{
	MipMapObj	= NULL;
	UWrap		= E3D_TEX_WRAP_CLAMP;
	VWrap		= E3D_TEX_WRAP_CLAMP;
	MinFilter	= E3D_TEX_MIN_FILTER_NEAREST;
	MaxFilter	= E3D_TEX_MAX_FILTER_NEAREST;
}

TTextureObj::~TTextureObj()
{
}

void TTextureObj::Think()
{
}
//---------------------------------------------------------------------------

