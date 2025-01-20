//	  %X% %Q% %Z% %W%



#ifndef CCOL_CollisionSystem_h
#define CCOL_CollisionSystem_h 1



// CCOL_Collider
#include "Collider\CCOL_Collider.h"
// CCOL_ColState
#include "CollisionSystem\CCOL_ColState.h"
// CCOL_DT_Tri
#include "COL_Testers\COL_DynamicTest\CCOL_DT_Tri.h"
// CCOL_DT_ColTester
#include "COL_Testers\COL_DynamicTest\CCOL_DT_ColTester.h"
// CCOL_MT_CommonMesh
#include "COL_Testers\COL_SceneTest\COL_MeshTest\CCOL_MT_CommonMesh.h"





class CCOL_CollisionSystem 
{
    
  public:
          CCOL_CollisionSystem();

          ~CCOL_CollisionSystem();


                void Init (int _iMaxColliders);

            void Reset ();

            int iAddObject (CCOL_Collider* _poColObj);

            void CheckCollisions (float _fDelta);

            bool bCheckCollision (CCOL_Collider& _Src, float _fDelta);

    // Data Members for Associations

                        CCOL_Collider** poColliders;
      
    // Additional Public Declarations
            
  protected:

                bool bTestBroadCD (CCOL_Collider& _Src, CCOL_Collider& _Dst);

            bool bTestNarrowCD (CCOL_Collider& _Src, CCOL_Collider& _Dst);

    // Data Members for Class Attributes

                  int iMaxColliders;
      
                  int iNumColliders;
      
    // Additional Protected Declarations
            
  private:
    // Additional Private Declarations
            
  private:     // Additional Implementation Declarations
            
};


// Class CCOL_CollisionSystem 



#endif
