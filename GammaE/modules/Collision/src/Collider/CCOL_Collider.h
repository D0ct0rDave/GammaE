// -----------------------------------------------------------------------------
#ifndef CCOL_Collider_h
#define CCOL_Collider_h 1
// -----------------------------------------------------------------------------
#include "GammaE_Scene.h"

// GammaE_Math
#include "GammaE_Math.h"

// eCOL_TestType
#include "Collider\eCOL_TestType.h"
// CCOL_Stack
#include "Collider\CCOL_Stack.h"
// eCOL_ColliderType
#include "Collider\eCOL_ColliderType.h"
// CCOL_TriListGen
#include "COL_TriList\CCOL_TriListGen.h"
// CCOL_TriList
#include "COL_TriList\CCOL_TriList.h"
// CCOL_MeshTester
#include "COL_Testers\COL_SceneTest\COL_MeshTest\CCOL_MeshTester.h"
// ----------------------------------------------------------------------------
class CCOL_Collider 
{
	public:
		CCOL_Collider();
		~CCOL_Collider();

		void Init (int _iUserID, CCOL_TriListGen* _poTLGen, CCOL_MeshTester* _poMTester, ECOL_ColliderType _eCType, ECOL_TestType _eStTest, ECOL_TestType _eDynTest, CObject3D* _poGrObj, int _iMaxTris, int _iColStackSize);

		void Reset ();

		CCOL_Stack* poGetColStack();

		ECOL_ColliderType eGetColType();
		ECOL_TestType eGetStTest();
		ECOL_TestType eGetDynTest();

		CCOL_MeshTester * GetMeshTester();
		CCOL_TriList& GetTriList();

		CCOL_TriListGen * GetTriListGen();

		CVect3 OldPos;

		CVect3 Pos;

		CVect3 Speed;

		int UserID;

		int ColID;

		CObject3D *GrObj;

		// Data Members for Associations

		CCOL_Stack ColStack;

		ECOL_ColliderType ColType;

		ECOL_TestType StTest;

		CCOL_MeshTester *MeshTester;

		ECOL_TestType DynTest;

		CCOL_TriList TriList;

		CCOL_TriListGen *TriListGen;

		uint m_uiTestFlags;
		uint m_uiColliderType;
		// Additional Public Declarations

		protected:
		// Additional Protected Declarations

		private:
		// Additional Private Declarations

		private:     // Additional Implementation Declarations

};
// ----------------------------------------------------------------------------
inline CCOL_Stack* CCOL_Collider::poGetColStack ()
{
    return &ColStack;
}
// ----------------------------------------------------------------------------
inline ECOL_ColliderType CCOL_Collider::eGetColType ()
{
    return ColType;
}
// ----------------------------------------------------------------------------
inline ECOL_TestType CCOL_Collider::eGetStTest ()
{
    return StTest;
}
// ----------------------------------------------------------------------------
inline CCOL_MeshTester * CCOL_Collider::GetMeshTester ()
{
    return MeshTester;
}
// ----------------------------------------------------------------------------
inline ECOL_TestType CCOL_Collider::eGetDynTest ()
{
    return DynTest;
}
// ----------------------------------------------------------------------------
inline CCOL_TriList& CCOL_Collider::GetTriList ()
{
    return TriList;
}
// ----------------------------------------------------------------------------
inline CCOL_TriListGen * CCOL_Collider::GetTriListGen ()
{
    return TriListGen;
}
// ----------------------------------------------------------------------------
#endif
// ----------------------------------------------------------------------------
