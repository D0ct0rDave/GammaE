//---------------------------------------------------------------------------
#include "EV_fBM_HeterogeneousMultifractal.h"
//---------------------------------------------------------------------------
TEv2D_fBM_Heterogeneous::TEv2D_fBM_Heterogeneous() : TEv2D_fBM(){ }
float TEv2D_fBM_Heterogeneous::GetValue(float x,float y)
{
	unsigned int cI;
    float Value;
    float Weight;
    float Signal;
    float Increment;

    Value = fBMOffset + BaseFunc->GetValue(x,y);

    x *= fBMLacunarity;
    y *= fBMLacunarity;

    // fBM process
    for (cI=1;cI<(unsigned int)fBMOctaves;cI++)
    {
    	// Cuidadin, que nos salimos de rango
        Increment = (fBMOffset + BaseFunc->GetValue(x,y)) * fBMExponentArray[cI] * Value;
        Value += Increment;

        x*=fBMLacunarity;
        y*=fBMLacunarity;
    }

    // This part is not in Texturing and Modelling ...
    if (fBMRemainder)
    {
    	Increment = (fBMOffset + BaseFunc->GetValue(x,y)) * fBMExponentArray[cI];
		Value    += Value * Increment * fBMRemainder;
    }

    return(Value);
};
//---------------------------------------------------------------------------
