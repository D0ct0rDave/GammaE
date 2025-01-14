//---------------------------------------------------------------------------
#include "EV_fBM_Multifractal.h"
//---------------------------------------------------------------------------
TEv2D_fBM_Multifractal::TEv2D_fBM_Multifractal() : TEv2D_fBM(){ }
float TEv2D_fBM_Multifractal::GetValue(float x,float y)
{
	unsigned int cI;
	float Value = 1;

    // fBM process
    for (cI=0;cI<(unsigned int)fBMOctaves;cI++)
    {
    	Value *= (fBMOffset + BaseFunc->GetValue(x,y) * fBMExponentArray[cI]);

        x*=fBMLacunarity;
        y*=fBMLacunarity;
    }

    // This part is not in Texturing and Modelling ...
    if (fBMRemainder)
		Value *= (fBMOffset + fBMRemainder*BaseFunc->GetValue(x,y)*fBMExponentArray[cI]);

    return(Value);
};
//---------------------------------------------------------------------------
