



#include "GammaE_Mem.h"

// CLightElem
#include "SectElem\CLightElem.h"
float L_fCosFactor;


// Class CLightElem 


CLightElem::CLightElem()
        {
}


CLightElem::~CLightElem()
{
}



unsigned long CLightElem::ByteSize ()
{
  	return(3*sizeof(float));
}

CSectElem & CLightElem::Sum (CSectElem &a, CSectElem &b)
{
    	
	Value[0] = ((float *)a.Get())[0] + ((float *)b.Get())[0];
	Value[1] = ((float *)a.Get())[1] + ((float *)b.Get())[1];
	Value[2] = ((float *)a.Get())[2] + ((float *)b.Get())[2];
	return (*this);
}

CSectElem & CLightElem::Mult (CSectElem &a, CSectElem &b)
{
  	Value[0] = ((float *)a.Get())[0] * ((float *)b.Get())[0];
	Value[1] = ((float *)a.Get())[1] * ((float *)b.Get())[1];
	Value[2] = ((float *)a.Get())[2] * ((float *)b.Get())[2];
	return (*this);
}

CSectElem & CLightElem::LinInterpolate (CSectElem &a, CSectElem &b, float fFactor)
{
  
	Value[0] = ((float *)a.Get())[0]  + ( ((float *)b.Get())[0] - ((float *)a.Get())[0]) *fFactor;
	Value[1] = ((float *)a.Get())[1]  + ( ((float *)b.Get())[1] - ((float *)a.Get())[1]) *fFactor;
	Value[2] = ((float *)a.Get())[2]  + ( ((float *)b.Get())[2] - ((float *)a.Get())[2]) *fFactor;
	return (*this);
}

CSectElem & CLightElem::CosInterpolate (CSectElem &a, CSectElem &b, float fFactor)
{
  	float L_fCosFactor = (float)cos(fFactor*_PI2_);

	Value[0] = ((float *)b.Get())[0] + ( ((float *)a.Get())[0] - ((float *)b.Get())[0]) *L_fCosFactor;
	Value[1] = ((float *)b.Get())[1] + ( ((float *)a.Get())[1] - ((float *)b.Get())[1]) *L_fCosFactor;
	Value[2] = ((float *)b.Get())[2] + ( ((float *)a.Get())[2] - ((float *)b.Get())[2]) *L_fCosFactor;
	return (*this);
}

CSectElem * CLightElem::CreateClass ()
{
  	return ( mNew CLightElem() );
}

CSectElem & CLightElem::Clear ()
{
  	Value[0] = 0;
	Value[1] = 0;
	Value[2] = 0;
	return (*this);
}

CSectElem & CLightElem::Add (CSectElem &a)
{
  	Value[0] += ((float *)a.Get())[0];
	Value[1] += ((float *)a.Get())[1];
	Value[2] += ((float *)a.Get())[2];
	return(*this);   
}

CSectElem & CLightElem::Mult (CSectElem &a)
{
  	Value[0] *= ((float *)a.Get())[0];
	Value[1] *= ((float *)a.Get())[1];
	Value[2] *= ((float *)a.Get())[2];
	return(*this);
}

CSectElem & CLightElem::Scale (float a)
{
  	Value[0] *= a;
	Value[1] *= a;
	Value[2] *= a;
	return(*this);
}

// Additional Declarations
    
