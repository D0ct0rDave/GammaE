//## begin module%3AF508750276.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3AF508750276.cm

//## begin module%3AF508750276.cp preserve=no
//## end module%3AF508750276.cp

//## Module: CLightElem%3AF508750276; Pseudo Package body
//## Source file: E:\Projects\GammaE\TerrainData\SectElem\CLightElem.cpp

//## begin module%3AF508750276.additionalIncludes preserve=no
//## end module%3AF508750276.additionalIncludes

//## begin module%3AF508750276.includes preserve=yes
//## end module%3AF508750276.includes

// CLightElem
#include "TerrainData\SectElem\CLightElem.h"
//## begin module%3AF508750276.additionalDeclarations preserve=yes
float L_fCosFactor;
//## end module%3AF508750276.additionalDeclarations


// Class CLightElem


CLightElem::CLightElem()
  //## begin CLightElem::CLightElem%.hasinit preserve=no
  //## end CLightElem::CLightElem%.hasinit
  //## begin CLightElem::CLightElem%.initialization preserve=yes
  //## end CLightElem::CLightElem%.initialization
{
  //## begin CLightElem::CLightElem%.body preserve=yes
  //## end CLightElem::CLightElem%.body
}


CLightElem::~CLightElem()
{
  //## begin CLightElem::~CLightElem%.body preserve=yes
  //## end CLightElem::~CLightElem%.body
}



//## Other Operations (implementation)
unsigned long CLightElem::ByteSize ()
{
  //## begin CLightElem::ByteSize%989139160.body preserve=yes
	return(3*sizeof(float));
  //## end CLightElem::ByteSize%989139160.body
}

CSectElem & CLightElem::Sum (CSectElem &a, CSectElem &b)
{
  //## begin CLightElem::Sum%989139173.body preserve=yes
  	
	Value[0] = ((float *)a.Get())[0] + ((float *)b.Get())[0];
	Value[1] = ((float *)a.Get())[1] + ((float *)b.Get())[1];
	Value[2] = ((float *)a.Get())[2] + ((float *)b.Get())[2];
	return (*this);
  //## end CLightElem::Sum%989139173.body
}

CSectElem & CLightElem::Mult (CSectElem &a, CSectElem &b)
{
  //## begin CLightElem::Mult%989139174.body preserve=yes
	Value[0] = ((float *)a.Get())[0] * ((float *)b.Get())[0];
	Value[1] = ((float *)a.Get())[1] * ((float *)b.Get())[1];
	Value[2] = ((float *)a.Get())[2] * ((float *)b.Get())[2];
	return (*this);
  //## end CLightElem::Mult%989139174.body
}

CSectElem & CLightElem::LinInterpolate (CSectElem &a, CSectElem &b, float fFactor)
{
  //## begin CLightElem::LinInterpolate%989139175.body preserve=yes

	Value[0] = ((float *)a.Get())[0]  + ( ((float *)b.Get())[0] - ((float *)a.Get())[0]) *fFactor;
	Value[1] = ((float *)a.Get())[1]  + ( ((float *)b.Get())[1] - ((float *)a.Get())[1]) *fFactor;
	Value[2] = ((float *)a.Get())[2]  + ( ((float *)b.Get())[2] - ((float *)a.Get())[2]) *fFactor;
	return (*this);
  //## end CLightElem::LinInterpolate%989139175.body
}

CSectElem & CLightElem::CosInterpolate (CSectElem &a, CSectElem &b, float fFactor)
{
  //## begin CLightElem::CosInterpolate%989139176.body preserve=yes
	float L_fCosFactor = (float)cos(fFactor*_PI2_);

	Value[0] = ((float *)b.Get())[0] + ( ((float *)a.Get())[0] - ((float *)b.Get())[0]) *L_fCosFactor;
	Value[1] = ((float *)b.Get())[1] + ( ((float *)a.Get())[1] - ((float *)b.Get())[1]) *L_fCosFactor;
	Value[2] = ((float *)b.Get())[2] + ( ((float *)a.Get())[2] - ((float *)b.Get())[2]) *L_fCosFactor;
	return (*this);
  //## end CLightElem::CosInterpolate%989139176.body
}

CSectElem * CLightElem::CreateClass ()
{
  //## begin CLightElem::CreateClass%991155100.body preserve=yes
	return ( new CLightElem() );
  //## end CLightElem::CreateClass%991155100.body
}

CSectElem & CLightElem::Clear ()
{
  //## begin CLightElem::Clear%991155106.body preserve=yes
	Value[0] = 0;
	Value[1] = 0;
	Value[2] = 0;
	return (*this);
  //## end CLightElem::Clear%991155106.body
}

CSectElem & CLightElem::Add (CSectElem &a)
{
  //## begin CLightElem::Add%991155114.body preserve=yes
	Value[0] += ((float *)a.Get())[0];
	Value[1] += ((float *)a.Get())[1];
	Value[2] += ((float *)a.Get())[2];
	return(*this);   
	//## end CLightElem::Add%991155114.body
}

CSectElem & CLightElem::Mult (CSectElem &a)
{
  //## begin CLightElem::Mult%991155115.body preserve=yes
	Value[0] *= ((float *)a.Get())[0];
	Value[1] *= ((float *)a.Get())[1];
	Value[2] *= ((float *)a.Get())[2];
	return(*this);
  //## end CLightElem::Mult%991155115.body
}

CSectElem & CLightElem::Scale (float a)
{
  //## begin CLightElem::Scale%991155116.body preserve=yes
	Value[0] *= a;
	Value[1] *= a;
	Value[2] *= a;
	return(*this);
  //## end CLightElem::Scale%991155116.body
}

// Additional Declarations
  //## begin CLightElem%3AF508750276.declarations preserve=yes
  //## end CLightElem%3AF508750276.declarations

//## begin module%3AF508750276.epilog preserve=yes
//## end module%3AF508750276.epilog
