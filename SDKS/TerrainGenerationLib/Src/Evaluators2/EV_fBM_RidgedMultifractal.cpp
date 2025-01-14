//---------------------------------------------------------------------------
#include "EV_fBM_RidgedMultifractal.h"
#include "Math/MMath.h"
//---------------------------------------------------------------------------
TEv2D_fBM_RidgedMultifractal::TEv2D_fBM_RidgedMultifractal() : TEv2D_fBM(){ }

void TEv2D_fBM_RidgedMultifractal::SetGain(float NewGain)
{
	fBMGain = NewGain;
}
//---------------------------------------------------------------------------
float TEv2D_fBM_RidgedMultifractal::GetValue(float x,float y)
{
	unsigned int cI;
    float Result;
    float Weight;
    float Signal;

    Signal = fBMOffset - BaseFunc->GetValue(x,y);
    Signal*= Signal;
    Result = Signal;
    Weight = 1.0;

    Result = (fBMOffset + BaseFunc->GetValue(x,y))*fBMExponentArray[0];
    Weight = Result;

    /*
    Quitado por mi!

    x *= fBMLacunarity;
    y *= fBMLacunarity;
    */

    // fBM process
    for (cI=1;cI<(unsigned int)fBMOctaves;cI++)
    {
        x*=fBMLacunarity;
        y*=fBMLacunarity;

    	// Cuidadin, que nos salimos de rango
        Weight = Signal * fBMGain;
        MMath_Clamp(Weight,0,1);
    	Signal = fBMOffset - BaseFunc->GetValue(x,y);
        Signal *= Signal;
        Signal *= Weight;

        Result += Signal * fBMExponentArray[cI];
    }

    // This part is not in Texturing and Modelling ...
    if (fBMRemainder)
    {
	    Weight = Signal * fBMGain;
        MMath_Clamp(Weight,0,1);

    	Signal  = fBMOffset - BaseFunc->GetValue(x,y);
        Signal *= Signal;
        Signal *= Weight;

        Result += fBMRemainder * Signal * fBMExponentArray[cI];
    }

    return(Result);
};
//---------------------------------------------------------------------------


