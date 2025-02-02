// -----------------------------------------------------------------------------
/*! \class
 *  \brief
 *  \author David M&aacute;rquez de la Cruz
 *  \version 1.5
 *  \date 1999-2009
 *  \par Copyright (c) 1999 David M&aacute;rquez de la Cruz
 *  \par GammaE License
 */
// ----------------------------------------------------------------------------
// %X% %Q% %Z% %W%

// CCOL_Collider
#include "Collider\CCOL_Collider.h"

// Class CCOL_Collider
// -----------------------------------------------------------------------------
// ----------------------------------------------------------------------------
CCOL_Collider::CCOL_Collider() : UserID(-1), ColID(-1), GrObj(NULL), ColType(COL_CT_None), StTest(COL_TT_None), DynTest(COL_TT_None), TriListGen(NULL)
{
    Pos.Set(0.0f,0.0f,0.0f);
    OldPos.Set(0.0f,0.0f,0.0f);
    Speed.Set(0.0f,0.0f,0.0f);
}
// ----------------------------------------------------------------------------
CCOL_Collider::~CCOL_Collider()
{
}
// ----------------------------------------------------------------------------
void CCOL_Collider::Init (int _iUserID, CCOL_TriListGen* _poTLGen, CCOL_MeshTester* _poMTester, ECOL_ColliderType _eCType, ECOL_TestType _eStTest, ECOL_TestType _eDynTest, CGSceneNode* _poGrObj, int _iMaxTris, int _iColStackSize)
{
    UserID = _iUserID;
    GrObj = _poGrObj;

    ColType = _eCType;
    StTest = _eStTest;
    DynTest = _eDynTest;

    TriListGen = _poTLGen;
    MeshTester = _poMTester;

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
