//---------------------------------------------------------------------------
#ifndef EV_fBM_MonofractalH
#define EV_fBM_MonofractalH
//---------------------------------------------------------------------------
#include "EV_fBM.h"
//---------------------------------------------------------------------------
class TEv2D_fBM_Monofractal: public TEv2D_fBM
{
	public:
        TEv2D_fBM_Monofractal();
    	virtual float GetValue(float x,float y);
};
//---------------------------------------------------------------------------
#endif
 