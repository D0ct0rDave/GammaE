//## begin module%3C4DE4F802B6.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3C4DE4F802B6.cm

//## begin module%3C4DE4F802B6.cp preserve=no
//## end module%3C4DE4F802B6.cp

//## Module: CCOL_ST_Point%3C4DE4F802B6; Pseudo Package body
//## Source file: i:\Projects\GammaE\Collision\COL_Testers\COL_StaticTest\CCOL_ST_Point.cpp

//## begin module%3C4DE4F802B6.additionalIncludes preserve=no
//## end module%3C4DE4F802B6.additionalIncludes

//## begin module%3C4DE4F802B6.includes preserve=yes
//## end module%3C4DE4F802B6.includes

// CCOL_ST_Point
#include "Collision\COL_Testers\COL_StaticTest\CCOL_ST_Point.h"
//## begin module%3C4DE4F802B6.additionalDeclarations preserve=yes
//## end module%3C4DE4F802B6.additionalDeclarations


// Class CCOL_ST_Point 

CCOL_ST_Point::CCOL_ST_Point()
  //## begin CCOL_ST_Point::CCOL_ST_Point%.hasinit preserve=no
  //## end CCOL_ST_Point::CCOL_ST_Point%.hasinit
  //## begin CCOL_ST_Point::CCOL_ST_Point%.initialization preserve=yes
  //## end CCOL_ST_Point::CCOL_ST_Point%.initialization
{
  //## begin CCOL_ST_Point::CCOL_ST_Point%.body preserve=yes
  //## end CCOL_ST_Point::CCOL_ST_Point%.body
}


CCOL_ST_Point::~CCOL_ST_Point()
{
  //## begin CCOL_ST_Point::~CCOL_ST_Point%.body preserve=yes
  //## end CCOL_ST_Point::~CCOL_ST_Point%.body
}



//## Other Operations (implementation)
int CCOL_ST_Point::iTestSphere (CVect3& _roSPoint, CVect3& _roDCenter, float _fDRadius)
{
  //## begin CCOL_ST_Point::iTestSphere%1011738050.body preserve=yes
	return ( _roSPoint.SqDistance(_roDCenter) < _SQ_(_fDRadius) );
  //## end CCOL_ST_Point::iTestSphere%1011738050.body
}

int CCOL_ST_Point::iTestBox (CVect3& _roSPoint, CVect3& _roDMaxs, CVect3& _roDMins)
{
  //## begin CCOL_ST_Point::iTestBox%1011738051.body preserve=yes
	return ( _roSPoint.Inside(_roDMaxs,_roDMins) );
  //## end CCOL_ST_Point::iTestBox%1011738051.body
}

int CCOL_ST_Point::iTestPoint (CVect3& _roSPoint, CVect3& _roDPoint)
{
  //## begin CCOL_ST_Point::iTestPoint%1011738052.body preserve=yes
	return ( _roSPoint.Equal(_roDPoint) );
  //## end CCOL_ST_Point::iTestPoint%1011738052.body
}

// Additional Declarations
  //## begin CCOL_ST_Point%3C4DE4F802B6.declarations preserve=yes
  //## end CCOL_ST_Point%3C4DE4F802B6.declarations

//## begin module%3C4DE4F802B6.epilog preserve=yes
//## end module%3C4DE4F802B6.epilog
