//---------------------------------------------------------------------------
#include <stdlib.h>
#include "HeightField/PT_HeightField_Matrix.h"
//---------------------------------------------------------------------------
// Class PT_HeightField_Matrix
//---------------------------------------------------------------------------
PT_HeightField_Matrix::PT_HeightField_Matrix (): Data(NULL), Min(0), Max(0)
{

}
//---------------------------------------------------------------------------
PT_HeightField_Matrix::~PT_HeightField_Matrix()
{
  	if (Data) free(Data);
}
//---------------------------------------------------------------------------
void PT_HeightField_Matrix::Init(unsigned int TheTX, unsigned int TheTY)
{
    if (Data) free(Data);

  	Data = (float *)malloc(TheTX*TheTY * sizeof(float));

	TX = TheTX;
    TY = TheTY;
}
//---------------------------------------------------------------------------
float PT_HeightField_Matrix::GetHeight(unsigned int x, unsigned int y)
{
  	return ( Data[y*TX + x] );
}
//---------------------------------------------------------------------------
void PT_HeightField_Matrix::SetHeight(unsigned int x, unsigned int y, float Height)
{
	Height *= HeightMultiplier;
    Height += HeightDisplacement;

	if (Height > Max) Max = Height;
	if (Height < Min) Min = Height;

	Data[y*TX + x] = Height;
}
//---------------------------------------------------------------------------
