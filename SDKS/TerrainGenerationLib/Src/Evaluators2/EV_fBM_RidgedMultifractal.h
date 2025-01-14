//---------------------------------------------------------------------------
#ifndef EV_fBM_RidgedMultifractalH
#define EV_fBM_RidgedMultifractalH
//---------------------------------------------------------------------------
#include "EV_fBM.h"
//---------------------------------------------------------------------------
class TEv2D_fBM_RidgedMultifractal: public TEv2D_fBM
{

public:
		TEv2D_fBM_RidgedMultifractal();
        virtual float GetValue(float x,float y);
		void SetGain(float NewGain);

private:
    	float fBMGain;
};
//---------------------------------------------------------------------------
#endif
 