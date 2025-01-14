//---------------------------------------------------------------------------
#include "EV_fBM_Monofractal.h"
//---------------------------------------------------------------------------
TEv2D_fBM_Monofractal::TEv2D_fBM_Monofractal() : TEv2D_fBM(){ }
float TEv2D_fBM_Monofractal::GetValue(float x,float y)
{
	unsigned int cI;
	float Value = 0;

    // fBM process
    for (cI=0;cI<(unsigned int)fBMOctaves;cI++)
    {
    	Value += BaseFunc->GetValue(x,y) * fBMExponentArray[cI];

        x *= fBMLacunarity;
        y *= fBMLacunarity;
    }

    if (fBMRemainder)
		Value += fBMRemainder * BaseFunc->GetValue(x,y) * fBMExponentArray[cI];

    return(Value);
}
//---------------------------------------------------------------------------
