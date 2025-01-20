



#include "GammaE_Mem.h"

// CHeight
#include "SectElem\CHeight.h"
float H_fCosFactor;


// Class CHeight 


CHeight::CHeight()
        {
}


CHeight::~CHeight()
{
}



unsigned long CHeight::ByteSize ()
{
  	return(sizeof(float));
}

CSectElem & CHeight::Sum (CSectElem &a, CSectElem &b)
{
  	Value = ((float *)a.Get())[0] + ((float *)b.Get())[0];
	return (*this);
}

CSectElem & CHeight::Mult (CSectElem &a, CSectElem &b)
{
  	Value = ((float *)a.Get())[0] * ((float *)b.Get())[0];
	return (*this);
}

CSectElem & CHeight::LinInterpolate (CSectElem &a, CSectElem &b, float fFactor)
{
  	Value = ((float *)a.Get())[0]  + ( ((float *)b.Get())[0] - ((float *)a.Get())[0]) *fFactor;
	return (*this);
}

CSectElem & CHeight::CosInterpolate (CSectElem &a, CSectElem &b, float fFactor)
{
  	H_fCosFactor = (float)cos(fFactor*_PI2_);

	Value = ((float *)b.Get())[0] + ( ((float *)a.Get())[0] - ((float *)b.Get())[0]) *H_fCosFactor;
	return (*this);
}

CSectElem * CHeight::CreateClass ()
{
  	return ( mNew CHeight() );
}

CSectElem & CHeight::Clear ()
{
  	Value = 0;
	return (*this);
}

CSectElem & CHeight::Add (CSectElem &a)
{
  	Value += *( (float *)a.Get() );
	return (*this);
}

CSectElem & CHeight::Mult (CSectElem &a)
{
  	Value *= *( (float *)a.Get() );
	return (*this);
}

CSectElem & CHeight::Scale (float a)
{
  	Value *= a;
	return (*this);
}

// Additional Declarations
    
