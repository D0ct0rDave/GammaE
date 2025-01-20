//## begin module%3B70757D03CA.cm preserve=no
//## end module%3B70757D03CA.cm

//## begin module%3B70757D03CA.cp preserve=no
//## end module%3B70757D03CA.cp

//## Module: CGraphBV_Manager%3B70757D03CA; Pseudo Package body
//## Source file: i:\Projects\GammaE\E3D\BoundingVolume\GraphBoundVol\CGraphBV_Manager.cpp

//## begin module%3B70757D03CA.additionalIncludes preserve=no
//## end module%3B70757D03CA.additionalIncludes

//## begin module%3B70757D03CA.includes preserve=yes
#include "Memory/GammaE_Mem.h"
//## end module%3B70757D03CA.includes

// CGraphBV_Sphere
#include "E3D\BoundingVolume\GraphBoundVol\CGraphBV_Sphere.h"
// CGraphBV_Point
#include "E3D\BoundingVolume\GraphBoundVol\CGraphBV_Point.h"
// CGraphBV_Manager
#include "E3D\BoundingVolume\GraphBoundVol\CGraphBV_Manager.h"
// CGraphBV_Cylinder
#include "E3D\BoundingVolume\GraphBoundVol\CGraphBV_Cylinder.h"
// CGraphBV_Box
#include "E3D\BoundingVolume\GraphBoundVol\CGraphBV_Box.h"
//## begin module%3B70757D03CA.additionalDeclarations preserve=yes
//## end module%3B70757D03CA.additionalDeclarations


// Class CGraphBV_Manager 

//## begin CGraphBV_Manager::eCreationMode%3B7075AD0398.attr preserve=no  private: static eGraphBV_TypeID {UA} eGraphBV_Sphere
eGraphBV_TypeID CGraphBV_Manager::eCreationMode = eGraphBV_Sphere;
//## end CGraphBV_Manager::eCreationMode%3B7075AD0398.attr

CGraphBV_Manager::CGraphBV_Manager()
  //## begin CGraphBV_Manager::CGraphBV_Manager%.hasinit preserve=no
  //## end CGraphBV_Manager::CGraphBV_Manager%.hasinit
  //## begin CGraphBV_Manager::CGraphBV_Manager%.initialization preserve=yes
  //## end CGraphBV_Manager::CGraphBV_Manager%.initialization
{
  //## begin CGraphBV_Manager::CGraphBV_Manager%.body preserve=yes
  //## end CGraphBV_Manager::CGraphBV_Manager%.body
}


CGraphBV_Manager::~CGraphBV_Manager()
{
  //## begin CGraphBV_Manager::~CGraphBV_Manager%.body preserve=yes
  //## end CGraphBV_Manager::~CGraphBV_Manager%.body
}



//## Other Operations (implementation)
CGraphBV * CGraphBV_Manager::poCreate ()
{
  //## begin CGraphBV_Manager::poCreate%997221311.body preserve=yes
	switch (eCreationMode)	
	{
		case eGraphBV_Sphere:	return(mNew CGraphBV_Sphere);
		case eGraphBV_Box:		return(mNew CGraphBV_Box);
		case eGraphBV_Cylinder:	return(mNew CGraphBV_Cylinder);				
		case eGraphBV_Point:	return(mNew CGraphBV_Point);
	}

	return (NULL);
  //## end CGraphBV_Manager::poCreate%997221311.body
}

// Additional Declarations
  //## begin CGraphBV_Manager%3B70757D03CA.declarations preserve=yes
  //## end CGraphBV_Manager%3B70757D03CA.declarations

//## begin module%3B70757D03CA.epilog preserve=yes
//---------------------------------------------------------------------------
// epilog: singleton initializer through static instantiation
//---------------------------------------------------------------------------
static CGraphBV_Manager oInstance;
//## end module%3B70757D03CA.epilog
