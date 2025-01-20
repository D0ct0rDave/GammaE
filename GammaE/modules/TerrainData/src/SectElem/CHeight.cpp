//## begin module%3AF508690258.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3AF508690258.cm

//## begin module%3AF508690258.cp preserve=no
//## end module%3AF508690258.cp

//## Module: CHeight%3AF508690258; Pseudo Package body
//## Source file: E:\Projects\GammaE\TerrainData\SectElem\CHeight.cpp

//## begin module%3AF508690258.additionalIncludes preserve=no
//## end module%3AF508690258.additionalIncludes

//## begin module%3AF508690258.includes preserve=yes
//## end module%3AF508690258.includes

// CHeight
#include "TerrainData\SectElem\CHeight.h"
//## begin module%3AF508690258.additionalDeclarations preserve=yes
float H_fCosFactor;
//## end module%3AF508690258.additionalDeclarations


// Class CHeight 


CHeight::CHeight()
  //## begin CHeight::CHeight%.hasinit preserve=no
  //## end CHeight::CHeight%.hasinit
  //## begin CHeight::CHeight%.initialization preserve=yes
  //## end CHeight::CHeight%.initialization
{
  //## begin CHeight::CHeight%.body preserve=yes
  //## end CHeight::CHeight%.body
}


CHeight::~CHeight()
{
  //## begin CHeight::~CHeight%.body preserve=yes
  //## end CHeight::~CHeight%.body
}



//## Other Operations (implementation)
unsigned long CHeight::ByteSize ()
{
  //## begin CHeight::ByteSize%989139158.body preserve=yes
	return(sizeof(float));
  //## end CHeight::ByteSize%989139158.body
}

CSectElem & CHeight::Sum (CSectElem &a, CSectElem &b)
{
  //## begin CHeight::Sum%989139165.body preserve=yes
	Value = ((float *)a.Get())[0] + ((float *)b.Get())[0];
	return (*this);
  //## end CHeight::Sum%989139165.body
}

CSectElem & CHeight::Mult (CSectElem &a, CSectElem &b)
{
  //## begin CHeight::Mult%989139166.body preserve=yes
	Value = ((float *)a.Get())[0] * ((float *)b.Get())[0];
	return (*this);
  //## end CHeight::Mult%989139166.body
}

CSectElem & CHeight::LinInterpolate (CSectElem &a, CSectElem &b, float fFactor)
{
  //## begin CHeight::LinInterpolate%989139167.body preserve=yes
	Value = ((float *)a.Get())[0]  + ( ((float *)b.Get())[0] - ((float *)a.Get())[0]) *fFactor;
	return (*this);
  //## end CHeight::LinInterpolate%989139167.body
}

CSectElem & CHeight::CosInterpolate (CSectElem &a, CSectElem &b, float fFactor)
{
  //## begin CHeight::CosInterpolate%989139168.body preserve=yes
	H_fCosFactor = (float)cos(fFactor*_PI2_);

	Value = ((float *)b.Get())[0] + ( ((float *)a.Get())[0] - ((float *)b.Get())[0]) *H_fCosFactor;
	return (*this);
  //## end CHeight::CosInterpolate%989139168.body
}

CSectElem * CHeight::CreateClass ()
{
  //## begin CHeight::CreateClass%991155098.body preserve=yes
	return ( new CHeight() );
  //## end CHeight::CreateClass%991155098.body
}

CSectElem & CHeight::Clear ()
{
  //## begin CHeight::Clear%991155107.body preserve=yes
	Value = 0;
	return (*this);
  //## end CHeight::Clear%991155107.body
}

CSectElem & CHeight::Add (CSectElem &a)
{
  //## begin CHeight::Add%991155117.body preserve=yes
	Value += *( (float *)a.Get() );
	return (*this);
  //## end CHeight::Add%991155117.body
}

CSectElem & CHeight::Mult (CSectElem &a)
{
  //## begin CHeight::Mult%991155118.body preserve=yes
	Value *= *( (float *)a.Get() );
	return (*this);
  //## end CHeight::Mult%991155118.body
}

CSectElem & CHeight::Scale (float a)
{
  //## begin CHeight::Scale%991155119.body preserve=yes
	Value *= a;
	return (*this);
  //## end CHeight::Scale%991155119.body
}

// Additional Declarations
  //## begin CHeight%3AF508690258.declarations preserve=yes
  //## end CHeight%3AF508690258.declarations

//## begin module%3AF508690258.epilog preserve=yes
//## end module%3AF508690258.epilog
