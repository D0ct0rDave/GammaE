//## begin module%3C4DB0B60195.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3C4DB0B60195.cm

//## begin module%3C4DB0B60195.cp preserve=no
//## end module%3C4DB0B60195.cp

//## Module: CCOL_DT_Point%3C4DB0B60195; Pseudo Package body
//## Source file: i:\Projects\GammaE\Collision\COL_Testers\COL_DynamicTest\CCOL_DT_Point.cpp

//## begin module%3C4DB0B60195.additionalIncludes preserve=no
//## end module%3C4DB0B60195.additionalIncludes

//## begin module%3C4DB0B60195.includes preserve=yes
//## end module%3C4DB0B60195.includes

// CCOL_DT_Point
#include "Collision\COL_Testers\COL_DynamicTest\CCOL_DT_Point.h"
//## begin module%3C4DB0B60195.additionalDeclarations preserve=yes
CVect3 SrcIP,SrcFP,SrcSp;
CVect3 DstIP,DstFP,DstSp;
CVect3 DSSpeed;

inline void SaveStateVars()
{
	// Backup variables
//	SrcIP  .Assign(CCOL_ColState::SrcIPos);
//	SrcFP  .Assign(CCOL_ColState::SrcFPos);
	SrcSp  .Assign(CCOL_ColState::SrcSp  );

//	DstIP  .Assign(CCOL_ColState::DstIPos);
//	DstFP  .Assign(CCOL_ColState::DstFPos);
	DstSp  .Assign(CCOL_ColState::DstSp  );
	
	DSSpeed.Assign(CCOL_ColState::DSSp   );
}

inline void RestoreStateVars()
{
	// Backup variables
//	CCOL_ColState::SrcIPos.Assign(SrcIP);
//	CCOL_ColState::SrcFPos.Assign(SrcFP);
	CCOL_ColState::SrcSp  .Assign(SrcSp);

//	CCOL_ColState::DstIPos.Assign(DstIP);
//	CCOL_ColState::DstFPos.Assign(DstFP);
	CCOL_ColState::DstSp  .Assign(DstSp);
	
	CCOL_ColState::DSSp   .Assign(DSSpeed);
}

inline void SwapStateVars()
{
	// Backup variables
//	CCOL_ColState::SrcIPos.Assign(DstIP);
//	CCOL_ColState::SrcFPos.Assign(DstFP);
	CCOL_ColState::SrcSp  .Assign(DstSp);

//	CCOL_ColState::DstIPos.Assign(SrcIP);
//	CCOL_ColState::DstFPos.Assign(SrcFP);
	CCOL_ColState::DstSp  .Assign(SrcSp);

	CCOL_ColState::DSSp.Scale(-1.0f);
}
//## end module%3C4DB0B60195.additionalDeclarations


// Class CCOL_DT_Point 

CCOL_DT_Point::CCOL_DT_Point()
  //## begin CCOL_DT_Point::CCOL_DT_Point%.hasinit preserve=no
  //## end CCOL_DT_Point::CCOL_DT_Point%.hasinit
  //## begin CCOL_DT_Point::CCOL_DT_Point%.initialization preserve=yes
  //## end CCOL_DT_Point::CCOL_DT_Point%.initialization
{
  //## begin CCOL_DT_Point::CCOL_DT_Point%.body preserve=yes
  //## end CCOL_DT_Point::CCOL_DT_Point%.body
}


CCOL_DT_Point::~CCOL_DT_Point()
{
  //## begin CCOL_DT_Point::~CCOL_DT_Point%.body preserve=yes
  //## end CCOL_DT_Point::~CCOL_DT_Point%.body
}



//## Other Operations (implementation)
float CCOL_DT_Point::fTestSphere (CVect3& _roSPoint, CVect3& _roDCenter, float _fDRadius)
{
  //## begin CCOL_DT_Point::fTestSphere%1011722644.body preserve=yes
	float fRes;
	SaveStateVars();
	SwapStateVars();

	// Setup vars
	fRes = CCOL_DT_Sphere::fTestPoint(_roDCenter,_fDRadius,_roSPoint);

	RestoreStateVars();

	return(fRes);
  //## end CCOL_DT_Point::fTestSphere%1011722644.body
}

float CCOL_DT_Point::fTestBox (CVect3& _roSPoint, CVect3& _roDMaxs, CVect3& _roDMins)
{
  //## begin CCOL_DT_Point::fTestBox%1011722645.body preserve=yes
	float fRes;
	SaveStateVars();
	SwapStateVars();

	// Setup vars
	fRes = CCOL_DT_Box::fTestPoint(_roDMaxs,_roDMins,_roSPoint);

	RestoreStateVars();

	return(fRes);
  //## end CCOL_DT_Point::fTestBox%1011722645.body
}

float CCOL_DT_Point::fTestPoint (CVect3& _roSPoint, float _fDRadius, CVect3& _roDCenter)
{
  //## begin CCOL_DT_Point::fTestPoint%1011722646.body preserve=yes
	return(-1.0f);
  //## end CCOL_DT_Point::fTestPoint%1011722646.body
}

// Additional Declarations
  //## begin CCOL_DT_Point%3C4DB0B60195.declarations preserve=yes
  //## end CCOL_DT_Point%3C4DB0B60195.declarations

//## begin module%3C4DB0B60195.epilog preserve=yes
//## end module%3C4DB0B60195.epilog
