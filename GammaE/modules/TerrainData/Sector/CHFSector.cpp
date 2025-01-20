//## begin module%3AF50E5C0082.cm preserve=no
//## end module%3AF50E5C0082.cm

//## begin module%3AF50E5C0082.cp preserve=no
//## end module%3AF50E5C0082.cp

//## Module: CHFSector%3AF50E5C0082; Pseudo Package body
//## Source file: i:\Projects\GammaE\TerrainData\Sector\CHFSector.cpp

//## begin module%3AF50E5C0082.additionalIncludes preserve=no
//## end module%3AF50E5C0082.additionalIncludes

//## begin module%3AF50E5C0082.includes preserve=yes
//## end module%3AF50E5C0082.includes

// CHFSector
#include "TerrainData\Sector\CHFSector.h"
//## begin module%3AF50E5C0082.additionalDeclarations preserve=yes
//## end module%3AF50E5C0082.additionalDeclarations


// Class CHFSector 




CHFSector::CHFSector()
  //## begin CHFSector::CHFSector%.hasinit preserve=no
      : MaxHeight(0), MinHeight(0)
  //## end CHFSector::CHFSector%.hasinit
  //## begin CHFSector::CHFSector%.initialization preserve=yes
  //## end CHFSector::CHFSector%.initialization
{
  //## begin CHFSector::CHFSector%.body preserve=yes
  //## end CHFSector::CHFSector%.body
}


CHFSector::~CHFSector()
{
  //## begin CHFSector::~CHFSector%.body preserve=yes
  //## end CHFSector::~CHFSector%.body
}



//## Other Operations (implementation)
float CHFSector::GetMaxHeight ()
{
  //## begin CHFSector::GetMaxHeight%990479653.body preserve=yes
	if (bRecomputeMaxMins) RecomputeMaxMins();
	return (MaxHeight);
  //## end CHFSector::GetMaxHeight%990479653.body
}

float CHFSector::GetMinHeight ()
{
  //## begin CHFSector::GetMinHeight%990479654.body preserve=yes
	if (bRecomputeMaxMins) RecomputeMaxMins();
	return (MinHeight);
  //## end CHFSector::GetMinHeight%990479654.body
}

void CHFSector::RecomputeMaxMins ()
{
  //## begin CHFSector::RecomputeMaxMins%990479655.body preserve=yes
	int		cI,cJ;
	float	fHeight;

	MaxHeight = -1.0E09f;
	MinHeight =  1.0E09f;
	for (cJ=0;cJ<Resolution;cJ++)
		for (cI=0;cI<Resolution;cI++)
		{	
			fHeight = *(float *)GetValue(cI,cJ).Get();
			
			if (fHeight > MaxHeight) MaxHeight = fHeight;
			if (fHeight < MinHeight) MinHeight = fHeight;
		}

	bRecomputeMaxMins = false;
  //## end CHFSector::RecomputeMaxMins%990479655.body
}

void CHFSector::SetValue (int _X, int _Y, CSectElem &_Value)
{
  //## begin CHFSector::SetValue%990479656.body preserve=yes
	bRecomputeMaxMins = true;
  //## end CHFSector::SetValue%990479656.body
}

// Additional Declarations
  //## begin CHFSector%3AF50E5C0082.declarations preserve=yes
  //## end CHFSector%3AF50E5C0082.declarations

//## begin module%3AF50E5C0082.epilog preserve=yes
//## end module%3AF50E5C0082.epilog
