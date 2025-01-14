//---------------------------------------------------------------------------
#ifndef TexFiltersH
#define TexFiltersH
//---------------------------------------------------------------------------

struct Texture;

typedef struct{
	float Real;	// Parte real
    float Img;	// Parte imaginaria
}TComplex;

void TexFilter_ComputeDFT(Texture *Tex,TComplex *DFTMatrix);

//---------------------------------------------------------------------------
#endif
//---------------------------------------------------------------------------