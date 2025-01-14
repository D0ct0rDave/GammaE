//---------------------------------------------------------------------------
#ifndef EV_fBM_HeterogeneousMultifractalH
#define EV_fBM_HeterogeneousMultifractalH
//---------------------------------------------------------------------------
#include "EV_fBM.h"
//---------------------------------------------------------------------------
class TEv2D_fBM_Heterogeneous: public TEv2D_fBM
{
	public:
	    TEv2D_fBM_Heterogeneous();
    	virtual float GetValue(float x,float y);
};
//---------------------------------------------------------------------------
#endif
//---------------------------------------------------------------------------
