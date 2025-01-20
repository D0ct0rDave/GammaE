//## begin module%3B55F49C00F0.cm preserve=no
//## end module%3B55F49C00F0.cm

//## begin module%3B55F49C00F0.cp preserve=no
//## end module%3B55F49C00F0.cp

//## Module: CBoundingSphere%3B55F49C00F0; Pseudo Package body
//## Source file: i:\Projects\GammaE\E3D\BoundingVolume\CBoundingSphere.cpp

//## begin module%3B55F49C00F0.additionalIncludes preserve=no
//## end module%3B55F49C00F0.additionalIncludes

//## begin module%3B55F49C00F0.includes preserve=yes
//## end module%3B55F49C00F0.includes

// CBoundingSphere
#include "E3D\BoundingVolume\CBoundingSphere.h"
//## begin module%3B55F49C00F0.additionalDeclarations preserve=yes
//## end module%3B55F49C00F0.additionalDeclarations


// Class CBoundingSphere 




CBoundingSphere::CBoundingSphere()
  //## begin CBoundingSphere::CBoundingSphere%.hasinit preserve=no
  //## end CBoundingSphere::CBoundingSphere%.hasinit
  //## begin CBoundingSphere::CBoundingSphere%.initialization preserve=yes
  //## end CBoundingSphere::CBoundingSphere%.initialization
{
  //## begin CBoundingSphere::CBoundingSphere%.body preserve=yes
  //## end CBoundingSphere::CBoundingSphere%.body
}


CBoundingSphere::~CBoundingSphere()
{
  //## begin CBoundingSphere::~CBoundingSphere%.body preserve=yes
  //## end CBoundingSphere::~CBoundingSphere%.body
}



//## Other Operations (implementation)
void CBoundingSphere::Init (CVect3 _Center, float _fRadius)
{
  //## begin CBoundingSphere::Init%997221286.body preserve=yes
	Center.Assign(_Center);
	Radius = _fRadius;
  //## end CBoundingSphere::Init%997221286.body
}

void CBoundingSphere::Init (CVect3& Max, CVect3& Min)
{
  //## begin CBoundingSphere::Init%997221303.body preserve=yes

	// Get radius
	Center.Assign(Max);
	Center.Sub(Min);
	Radius = Center.Module() * 0.5;

	// Get center pos
	Center.Interpolate(Max,Min,0.5f);

  //## end CBoundingSphere::Init%997221303.body
}

// Additional Declarations
  //## begin CBoundingSphere%3B55F49C00F0.declarations preserve=yes
  //## end CBoundingSphere%3B55F49C00F0.declarations

//## begin module%3B55F49C00F0.epilog preserve=yes
//## end module%3B55F49C00F0.epilog
