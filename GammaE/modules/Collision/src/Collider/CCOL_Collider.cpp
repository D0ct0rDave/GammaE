// ----------------------------------------------------------------------------
//	  %X% %Q% %Z% %W%

// CCOL_Collider
#include "Collider\CCOL_Collider.h"

// Class CCOL_Collider 
// ----------------------------------------------------------------------------
CCOL_Collider::CCOL_Collider() : UserID(-1), ColID(-1), GrObj(NULL), ColType(COL_CT_None), StTest(COL_TT_None), DynTest(COL_TT_None), TriListGen(NULL)
{
	Pos.V3(0.0f,0.0f,0.0f);
	OldPos.V3(0.0f,0.0f,0.0f);
	Speed.V3(0.0f,0.0f,0.0f);	
}
// ----------------------------------------------------------------------------
CCOL_Collider::~CCOL_Collider()
{
}
// ----------------------------------------------------------------------------
void CCOL_Collider::Init (int _iUserID, CCOL_TriListGen* _poTLGen, CCOL_MeshTester* _poMTester, ECOL_ColliderType _eCType, ECOL_TestType _eStTest, ECOL_TestType _eDynTest, CObject3D* _poGrObj, int _iMaxTris, int _iColStackSize)
{
  	UserID		= _iUserID;
	GrObj		= _poGrObj;

	ColType		= _eCType;
	StTest      = _eStTest;
	DynTest     = _eDynTest;

	TriListGen	= _poTLGen;
	MeshTester	= _poMTester;
	
	TriList.Init(_iMaxTris);
	ColStack.Init(_iColStackSize);
}
// ----------------------------------------------------------------------------
void CCOL_Collider::Reset ()
{
	ColStack.Reset();
	TriList.Reset();
}
// ----------------------------------------------------------------------------


