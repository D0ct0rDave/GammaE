//## begin module%3C0824C801D4.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3C0824C801D4.cm

//## begin module%3C0824C801D4.cp preserve=no
//## end module%3C0824C801D4.cp

//## Module: CCOL_ST_Box%3C0824C801D4; Pseudo Package body
//## Source file: i:\Projects\GammaE\Collision\COL_Testers\COL_StaticTest\CCOL_ST_Box.cpp

//## begin module%3C0824C801D4.additionalIncludes preserve=no
//## end module%3C0824C801D4.additionalIncludes

//## begin module%3C0824C801D4.includes preserve=yes
//## end module%3C0824C801D4.includes

// CCOL_ST_Box
#include "Collision\COL_Testers\COL_StaticTest\CCOL_ST_Box.h"
//## begin module%3C0824C801D4.additionalDeclarations preserve=yes
//## end module%3C0824C801D4.additionalDeclarations


// Class CCOL_ST_Box 

CCOL_ST_Box::CCOL_ST_Box()
  //## begin CCOL_ST_Box::CCOL_ST_Box%.hasinit preserve=no
  //## end CCOL_ST_Box::CCOL_ST_Box%.hasinit
  //## begin CCOL_ST_Box::CCOL_ST_Box%.initialization preserve=yes
  //## end CCOL_ST_Box::CCOL_ST_Box%.initialization
{
  //## begin CCOL_ST_Box::CCOL_ST_Box%.body preserve=yes
  //## end CCOL_ST_Box::CCOL_ST_Box%.body
}


CCOL_ST_Box::~CCOL_ST_Box()
{
  //## begin CCOL_ST_Box::~CCOL_ST_Box%.body preserve=yes
  //## end CCOL_ST_Box::~CCOL_ST_Box%.body
}



//## Other Operations (implementation)
int CCOL_ST_Box::iTestSphere (CVect3& _roSMaxs, CVect3& _roSMins, CVect3& _roDCenter, float _fDRadius)
{
  //## begin CCOL_ST_Box::iTestSphere%1007160421.body preserve=yes

	// OPTIMIZABLE!!!
	
	// Perfoming separating axis test
	float	fSqRad = _SQ_(_fDRadius);
	float	fDiff;

	for (int i=0;i<3;i++)
	{
		if (_roDCenter.v[i] < _roSMins.v[i])
		{
			fDiff = _roSMins.v[i] - _roDCenter.v[i];
			if (_SQ_(fDiff) > fSqRad) return(0);
		}
		else
		{
			if (_roDCenter.v[i] > _roSMaxs.v[i])
			{
				fDiff = _roDCenter.v[i] - _roSMaxs.v[i];				
				if (_SQ_(fDiff) > fSqRad) return(0);
			}
		}
	}

	return(1);
  //## end CCOL_ST_Box::iTestSphere%1007160421.body
}

int CCOL_ST_Box::iTestBox (CVect3& _roSMaxs, CVect3& _roSMins, CVect3& _roDMaxs, CVect3& _roDMins)
{
  //## begin CCOL_ST_Box::iTestBox%1007160422.body preserve=yes

	// OPTIMIZABLE!!!
	for (int i=0;i<3;i++)
		if ((_roSMins.v[i] > _roDMaxs.v[i]) || (_roSMaxs.v[i] < _roDMins.v[i]))
			return(0);
	
	return(1);
  //## end CCOL_ST_Box::iTestBox%1007160422.body
}

int CCOL_ST_Box::iTestPoint (CVect3& _roSMaxs, CVect3& _roSMins, CVect3& _roDPoint)
{
  //## begin CCOL_ST_Box::iTestPoint%1007160423.body preserve=yes
	return ( _roDPoint.Inside(_roSMaxs,_roSMins) );
  //## end CCOL_ST_Box::iTestPoint%1007160423.body
}

// Additional Declarations
  //## begin CCOL_ST_Box%3C0824C801D4.declarations preserve=yes
  //## end CCOL_ST_Box%3C0824C801D4.declarations

//## begin module%3C0824C801D4.epilog preserve=yes
//## end module%3C0824C801D4.epilog
