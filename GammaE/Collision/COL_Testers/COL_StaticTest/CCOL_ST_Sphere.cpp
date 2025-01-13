//## begin module%3C0822A10055.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3C0822A10055.cm

//## begin module%3C0822A10055.cp preserve=no
//## end module%3C0822A10055.cp

//## Module: CCOL_ST_Sphere%3C0822A10055; Pseudo Package body
//## Source file: i:\Projects\GammaE\Collision\COL_Testers\COL_StaticTest\CCOL_ST_Sphere.cpp

//## begin module%3C0822A10055.additionalIncludes preserve=no
//## end module%3C0822A10055.additionalIncludes

//## begin module%3C0822A10055.includes preserve=yes
//## end module%3C0822A10055.includes

// CCOL_ST_Sphere
#include "Collision\COL_Testers\COL_StaticTest\CCOL_ST_Sphere.h"
//## begin module%3C0822A10055.additionalDeclarations preserve=yes
//## end module%3C0822A10055.additionalDeclarations


// Class CCOL_ST_Sphere 

CCOL_ST_Sphere::CCOL_ST_Sphere()
  //## begin CCOL_ST_Sphere::CCOL_ST_Sphere%.hasinit preserve=no
  //## end CCOL_ST_Sphere::CCOL_ST_Sphere%.hasinit
  //## begin CCOL_ST_Sphere::CCOL_ST_Sphere%.initialization preserve=yes
  //## end CCOL_ST_Sphere::CCOL_ST_Sphere%.initialization
{
  //## begin CCOL_ST_Sphere::CCOL_ST_Sphere%.body preserve=yes
  //## end CCOL_ST_Sphere::CCOL_ST_Sphere%.body
}


CCOL_ST_Sphere::~CCOL_ST_Sphere()
{
  //## begin CCOL_ST_Sphere::~CCOL_ST_Sphere%.body preserve=yes
  //## end CCOL_ST_Sphere::~CCOL_ST_Sphere%.body
}



//## Other Operations (implementation)
int CCOL_ST_Sphere::iTestSphere (CVect3& _roSCenter, float _fSRadius, CVect3& _roDCenter, float _fDRadius)
{
  //## begin CCOL_ST_Sphere::iTestSphere%1007160418.body preserve=yes
	if (_roSCenter.SqDistance(_roDCenter) < _SQ_(_fSRadius + _fDRadius) )
		return(1);
	else
		return(0);
  //## end CCOL_ST_Sphere::iTestSphere%1007160418.body
}

int CCOL_ST_Sphere::iTestBox (CVect3& _roSCenter, float _fSRadius, CVect3& _roDMaxs, CVect3& _roDMins)
{
  //## begin CCOL_ST_Sphere::iTestBox%1007160419.body preserve=yes
	return ( CCOL_ST_Box::iTestSphere(_roDMaxs,_roDMins,_roSCenter,_fSRadius));
  //## end CCOL_ST_Sphere::iTestBox%1007160419.body
}

int CCOL_ST_Sphere::iTestPoint (CVect3& _roSCenter, float _fSRadius, CVect3& _roDPoint)
{
  //## begin CCOL_ST_Sphere::iTestPoint%1007160420.body preserve=yes
	return ( _roDPoint.SqDistance(_roSCenter) < _SQ_(_fSRadius) );
  //## end CCOL_ST_Sphere::iTestPoint%1007160420.body
}

// Additional Declarations
  //## begin CCOL_ST_Sphere%3C0822A10055.declarations preserve=yes
  //## end CCOL_ST_Sphere%3C0822A10055.declarations

//## begin module%3C0822A10055.epilog preserve=yes
//## end module%3C0822A10055.epilog
