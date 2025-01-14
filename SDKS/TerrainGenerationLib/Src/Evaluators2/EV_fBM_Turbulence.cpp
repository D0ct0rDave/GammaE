//---------------------------------------------------------------------------
#include "EV_fBM_Turbulence.h"
#include "Math/MMath.h"
//---------------------------------------------------------------------------
TEv2D_fBM_Turbulence::TEv2D_fBM_Turbulence() : TEv2D_fBM(){ }

float TEv2D_fBM_Turbulence::GetValue(float x,float y)
{
    // Turbulence function
    float f,MaxFreq;
    float Value;

    unsigned int cI;

    Value = 1.0f;
    for (cI=1;cI<(unsigned int)fBMOctaves;cI++)
    {
     	Value *= fBMOffset + MMath_Abs(BaseFunc->GetValue(x,y)*fBMExponentArray[cI]);

        x*=fBMLacunarity;
        y*=fBMLacunarity;
    }

    if (fBMRemainder)
		Value *= fBMOffset + MMath_Abs(fBMRemainder*BaseFunc->GetValue(x,y)*fBMExponentArray[cI]);

    return(Value);
}
//---------------------------------------------------------------------------
