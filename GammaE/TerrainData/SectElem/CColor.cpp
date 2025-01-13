//## begin module%3AF5087A0014.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3AF5087A0014.cm

//## begin module%3AF5087A0014.cp preserve=no
//## end module%3AF5087A0014.cp

//## Module: CColor%3AF5087A0014; Pseudo Package body
//## Source file: E:\Projects\GammaE\TerrainData\SectElem\CColor.cpp

//## begin module%3AF5087A0014.additionalIncludes preserve=no
//## end module%3AF5087A0014.additionalIncludes

//## begin module%3AF5087A0014.includes preserve=yes
//## end module%3AF5087A0014.includes

// CColor
#include "TerrainData\SectElem\CColor.h"
//## begin module%3AF5087A0014.additionalDeclarations preserve=yes
float C_fCosFactor;
//## end module%3AF5087A0014.additionalDeclarations


// Class CColor 


CColor::CColor()
  //## begin CColor::CColor%.hasinit preserve=no
  //## end CColor::CColor%.hasinit
  //## begin CColor::CColor%.initialization preserve=yes
  //## end CColor::CColor%.initialization
{
  //## begin CColor::CColor%.body preserve=yes
  //## end CColor::CColor%.body
}


CColor::~CColor()
{
  //## begin CColor::~CColor%.body preserve=yes
  //## end CColor::~CColor%.body
}



//## Other Operations (implementation)
unsigned long CColor::ByteSize ()
{
  //## begin CColor::ByteSize%989139159.body preserve=yes
	return (4*sizeof(float));
  //## end CColor::ByteSize%989139159.body
}

CSectElem & CColor::Sum (CSectElem &a, CSectElem &b)
{
  //## begin CColor::Sum%989139169.body preserve=yes

	Value[0] = ((float *)a.Get())[0] + ((float *)b.Get())[0];
	Value[1] = ((float *)a.Get())[1] + ((float *)b.Get())[1];
	Value[2] = ((float *)a.Get())[2] + ((float *)b.Get())[2];
	Value[3] = ((float *)a.Get())[3] + ((float *)b.Get())[3];

	return (*this);
  //## end CColor::Sum%989139169.body
}

CSectElem & CColor::Mult (CSectElem &a, CSectElem &b)
{
  //## begin CColor::Mult%989139170.body preserve=yes
	Value[0] = ((float *)a.Get())[0] * ((float *)b.Get())[0];
	Value[1] = ((float *)a.Get())[1] * ((float *)b.Get())[1];
	Value[2] = ((float *)a.Get())[2] * ((float *)b.Get())[2];
	Value[3] = ((float *)a.Get())[3] * ((float *)b.Get())[3];

	return (*this);
  //## end CColor::Mult%989139170.body
}

CSectElem & CColor::LinInterpolate (CSectElem &a, CSectElem &b, float fFactor)
{
  //## begin CColor::LinInterpolate%989139171.body preserve=yes
	
	// Res = a*(1-f) + b*f = a - af + bf = a + (b-a)*f

	Value[0] = ((float *)a.Get())[0]  + ( ((float *)b.Get())[0] - ((float *)a.Get())[0]) *fFactor;
	Value[1] = ((float *)a.Get())[1]  + ( ((float *)b.Get())[1] - ((float *)a.Get())[1]) *fFactor;
	Value[2] = ((float *)a.Get())[2]  + ( ((float *)b.Get())[2] - ((float *)a.Get())[2]) *fFactor;
	Value[3] = ((float *)a.Get())[3]  + ( ((float *)b.Get())[3] - ((float *)a.Get())[3]) *fFactor;
	
	return (*this);
  //## end CColor::LinInterpolate%989139171.body
}

CSectElem & CColor::CosInterpolate (CSectElem &a, CSectElem &b, float fFactor)
{
  //## begin CColor::CosInterpolate%989139172.body preserve=yes

	// Res = a*( 1 - cos((1-f)*PI/2) ) + b * cos((1-f)*PI/2)
	// Res = a*( cos(f*PI/2) ) + b (1 - cos(f* PI/2);
	// Res = b  + (a -b)*cos(f*PI/2);

	C_fCosFactor = (float)cos(fFactor*_PI2_);

	Value[0] = ((float *)b.Get())[0] + ( ((float *)a.Get())[0] - ((float *)b.Get())[0]) *C_fCosFactor;
	Value[1] = ((float *)b.Get())[1] + ( ((float *)a.Get())[1] - ((float *)b.Get())[1]) *C_fCosFactor;
	Value[2] = ((float *)b.Get())[2] + ( ((float *)a.Get())[2] - ((float *)b.Get())[2]) *C_fCosFactor;
	Value[3] = ((float *)b.Get())[3] + ( ((float *)a.Get())[3] - ((float *)b.Get())[3]) *C_fCosFactor;

	return (*this);
  //## end CColor::CosInterpolate%989139172.body
}

CSectElem * CColor::CreateClass ()
{
  //## begin CColor::CreateClass%991155101.body preserve=yes
	return ( new CColor() );
  //## end CColor::CreateClass%991155101.body
}

CSectElem & CColor::Clear ()
{
  //## begin CColor::Clear%991155105.body preserve=yes
	Value[0] = 0;
	Value[1] = 0;
	Value[2] = 0;
	Value[3] = 0;

	return (*this);
  //## end CColor::Clear%991155105.body
}

CSectElem & CColor::Add (CSectElem &a)
{
  //## begin CColor::Add%991155111.body preserve=yes
	Value[0] += ((float *)a.Get())[0];
	Value[1] += ((float *)a.Get())[1];
	Value[2] += ((float *)a.Get())[2];
	Value[3] += ((float *)a.Get())[3];

	return (*this);
  //## end CColor::Add%991155111.body
}

CSectElem & CColor::Mult (CSectElem &a)
{
  //## begin CColor::Mult%991155112.body preserve=yes
	Value[0] *= ((float *)a.Get())[0];
	Value[1] *= ((float *)a.Get())[1];
	Value[2] *= ((float *)a.Get())[2];
	Value[3] *= ((float *)a.Get())[3];

	return (*this);
  //## end CColor::Mult%991155112.body
}

CSectElem & CColor::Scale (float a)
{
  //## begin CColor::Scale%991155113.body preserve=yes
	Value[0] *= a;
	Value[1] *= a;
	Value[2] *= a;
	Value[3] *= a;

	return (*this);
  //## end CColor::Scale%991155113.body
}

// Additional Declarations
  //## begin CColor%3AF5087A0014.declarations preserve=yes
  //## end CColor%3AF5087A0014.declarations

//## begin module%3AF5087A0014.epilog preserve=yes
//## end module%3AF5087A0014.epilog
