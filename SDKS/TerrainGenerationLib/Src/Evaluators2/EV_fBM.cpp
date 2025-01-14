//---------------------------------------------------------------------------
#include "EV_fBM.h"

#include <math.h>
//---------------------------------------------------------------------------
TEv2D_fBM::TEv2D_fBM()
{
 	fBMLacunarity = 2;
    fBMOctaves    = 3;
    fBMOffset     = 0.5;
    fBMAmplitude  = 0.5;

    ComputeExponentArray();
}

void TEv2D_fBM::SetLacunarity(float NewLacunarity)
{
	fBMLacunarity = NewLacunarity;
    ComputeExponentArray();
}

void TEv2D_fBM::SetOctaves(float NewOctaves)
{
	fBMOctaves   = NewOctaves;
    fBMRemainder = fBMOctaves - (int)fBMOctaves;

    ComputeExponentArray();
}

void TEv2D_fBM::SetAmplitude (float NewAmplitude)
{
	fBMAmplitude = NewAmplitude;
	ComputeExponentArray();
}

void TEv2D_fBM::SetOffset(float NewOffset)
{
	fBMOffset = NewOffset;
}
//---------------------------------------------------------------------------
void TEv2D_fBM::ComputeExponentArray()
{
	float 	 	 fFreq;
    unsigned int cI;

    fFreq = 1.0f;
    for (cI=0;cI<(unsigned int)fBMOctaves+1;cI++)
    {
    	fBMExponentArray[cI] = pow(fFreq,-fBMAmplitude);
        fFreq *= fBMLacunarity;
    }
}
//---------------------------------------------------------------------------
