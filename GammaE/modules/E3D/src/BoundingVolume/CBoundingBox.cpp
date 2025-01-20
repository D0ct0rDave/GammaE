//## begin module%3B55F43401AE.cm preserve=no
//## end module%3B55F43401AE.cm

//## begin module%3B55F43401AE.cp preserve=no
//## end module%3B55F43401AE.cp

//## Module: CBoundingBox%3B55F43401AE; Pseudo Package body
//## Source file: i:\Projects\GammaE\E3D\BoundingVolume\CBoundingBox.cpp

//## begin module%3B55F43401AE.additionalIncludes preserve=no
//## end module%3B55F43401AE.additionalIncludes

//## begin module%3B55F43401AE.includes preserve=yes
//## end module%3B55F43401AE.includes

// CBoundingBox
#include "E3D\BoundingVolume\CBoundingBox.h"
//## begin module%3B55F43401AE.additionalDeclarations preserve=yes
//## end module%3B55F43401AE.additionalDeclarations


// Class CBoundingBox 





CBoundingBox::CBoundingBox()
  //## begin CBoundingBox::CBoundingBox%.hasinit preserve=no
  //## end CBoundingBox::CBoundingBox%.hasinit
  //## begin CBoundingBox::CBoundingBox%.initialization preserve=yes
  //## end CBoundingBox::CBoundingBox%.initialization
{
  //## begin CBoundingBox::CBoundingBox%.body preserve=yes
  //## end CBoundingBox::CBoundingBox%.body
}


CBoundingBox::~CBoundingBox()
{
  //## begin CBoundingBox::~CBoundingBox%.body preserve=yes
  //## end CBoundingBox::~CBoundingBox%.body
}



//## Other Operations (implementation)
void CBoundingBox::Init (CVect3& Max, CVect3& Min)
{
  //## begin CBoundingBox::Init%995837647.body preserve=yes
  	Mins.Assign(Min);
    Maxs.Assign(Max);

    // Look up table
    Points[0].V3( Maxs.X(),Maxs.Y(),Maxs.Z() );		// 000
    Points[1].V3( Maxs.X(),Maxs.Y(),Mins.Z() );		// 001
    Points[2].V3( Maxs.X(),Mins.Y(),Maxs.Z() );		// 010
    Points[3].V3( Maxs.X(),Mins.Y(),Mins.Z() );		// 011
    Points[4].V3( Mins.X(),Maxs.Y(),Maxs.Z() );		// 100
    Points[5].V3( Mins.X(),Maxs.Y(),Mins.Z() );		// 101
    Points[6].V3( Mins.X(),Mins.Y(),Maxs.Z() );		// 110
    Points[7].V3( Mins.X(),Mins.Y(),Mins.Z() );		// 111
  //## end CBoundingBox::Init%995837647.body
}

// Additional Declarations
  //## begin CBoundingBox%3B55F43401AE.declarations preserve=yes
  //## end CBoundingBox%3B55F43401AE.declarations

//## begin module%3B55F43401AE.epilog preserve=yes
//## end module%3B55F43401AE.epilog
