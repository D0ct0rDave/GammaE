//## begin module%3C06B92E0385.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3C06B92E0385.cm

//## begin module%3C06B92E0385.cp preserve=no
//## end module%3C06B92E0385.cp

//## Module: CCOL_Collider%3C06B92E0385; Pseudo Package body
//## Source file: i:\Projects\GammaE\Collision\Collider\CCOL_Collider.cpp

//## begin module%3C06B92E0385.additionalIncludes preserve=no
//## end module%3C06B92E0385.additionalIncludes

//## begin module%3C06B92E0385.includes preserve=yes
//## end module%3C06B92E0385.includes

// CCOL_Collider
#include "Collision\Collider\CCOL_Collider.h"
//## begin module%3C06B92E0385.additionalDeclarations preserve=yes
//## end module%3C06B92E0385.additionalDeclarations


// Class CCOL_Collider 


















CCOL_Collider::CCOL_Collider()
  //## begin CCOL_Collider::CCOL_Collider%.hasinit preserve=no
      : UserID(-1), ColID(-1), GrObj(NULL), ColType(eCOL_CT_None), StTest(eCOL_TT_None), DynTest(eCOL_TT_None), TriListGen(NULL)
  //## end CCOL_Collider::CCOL_Collider%.hasinit
  //## begin CCOL_Collider::CCOL_Collider%.initialization preserve=yes
  //## end CCOL_Collider::CCOL_Collider%.initialization
{
  //## begin CCOL_Collider::CCOL_Collider%.body preserve=yes
  	   Pos.V3(0.0f,0.0f,0.0f);
	OldPos.V3(0.0f,0.0f,0.0f);
	 Speed.V3(0.0f,0.0f,0.0f);	
  //## end CCOL_Collider::CCOL_Collider%.body
}


CCOL_Collider::~CCOL_Collider()
{
  //## begin CCOL_Collider::~CCOL_Collider%.body preserve=yes
  //## end CCOL_Collider::~CCOL_Collider%.body
}



//## Other Operations (implementation)
void CCOL_Collider::Init (int _iUserID, CCOL_TriListGen* _poTLGen, CCOL_MeshTester* _poMTester, eCOL_ColliderType _eCType, eCOL_TestType _eStTest, eCOL_TestType _eDynTest, CObject3D* _poGrObj, int _iMaxTris, int _iColStackSize)
{
  //## begin CCOL_Collider::Init%1008463031.body preserve=yes
	UserID		= _iUserID;
	GrObj		= _poGrObj;

	ColType		= _eCType;
	StTest      = _eStTest;
	DynTest     = _eDynTest;

	TriListGen	= _poTLGen;
	MeshTester	= _poMTester;
	
	TriList.Init(_iMaxTris);
	ColStack.Init(_iColStackSize);
  //## end CCOL_Collider::Init%1008463031.body
}

void CCOL_Collider::Reset ()
{
  //## begin CCOL_Collider::Reset%1008534192.body preserve=yes
  ColStack.Reset();
  TriList.Reset();
  //## end CCOL_Collider::Reset%1008534192.body
}

// Additional Declarations
  //## begin CCOL_Collider%3C06B92E0385.declarations preserve=yes
  //## end CCOL_Collider%3C06B92E0385.declarations

//## begin module%3C06B92E0385.epilog preserve=yes
//## end module%3C06B92E0385.epilog
