//---------------------------------------------------------------------------
#ifndef EV_fBMH
#define EV_fBMH
//---------------------------------------------------------------------------
#include "EV_Composite.h"
//---------------------------------------------------------------------------
// Generic fBM evaluator
//---------------------------------------------------------------------------
class TEv2D_fBM: public TEvaluator2D_Composite
{
public:
	TEv2D_fBM();        	
	virtual float GetValue(float x,float y) = 0;

    void SetLacunarity(float NewLacunarity);
    void SetOctaves   (float NewOctaves);
    void SetAmplitude (float NewAmplitude);
    void SetOffset	  (float NewOffset);

protected:
	void  ComputeExponentArray();

	float fBMLacunarity;
    float fBMOctaves;
    float fBMRemainder;
    float fBMAmplitude;
    float fBMOffset;

    float fBMExponentArray[32]; // up to 16 octaves -> resolution 2^32 pixels
};
//---------------------------------------------------------------------------
#endif
 