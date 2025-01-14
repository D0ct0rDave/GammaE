//---------------------------------------------------------------------------
#include "EV_fBM_HybridMultifractal.h"
#include "Math/MMath.h"
//---------------------------------------------------------------------------
TEv2D_fBM_HybridMultifractal::TEv2D_fBM_HybridMultifractal() : TEv2D_fBM(){ }
float TEv2D_fBM_HybridMultifractal::GetValue(float x,float y)
{
	unsigned int cI;
    float Result;
    float Weight;
    float Signal;

    Result = (fBMOffset + BaseFunc->GetValue(x,y))*fBMExponentArray[0];
    Weight = Result;

    x *= fBMLacunarity;
    y *= fBMLacunarity;

    // fBM process
    for (cI=1;cI<(unsigned int)fBMOctaves;cI++)
    {
    	// Cuidadin, que nos salimos de rango
        Weight = MMath_Min(Weight,1.0);
    	Signal = (fBMOffset + BaseFunc->GetValue(x,y))*fBMExponentArray[cI];
        Result += Weight * Signal;
        Weight *= Signal;

        x*=fBMLacunarity;
        y*=fBMLacunarity;
    }

    // This part is not in Texturing and Modelling ...
    if (fBMRemainder)
		Result += (fBMRemainder*BaseFunc->GetValue(x,y)*fBMExponentArray[cI]);

    return(Result);
};
//---------------------------------------------------------------------------

