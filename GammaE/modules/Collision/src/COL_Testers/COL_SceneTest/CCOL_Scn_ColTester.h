//	  %X% %Q% %Z% %W%



#ifndef CCOL_Scn_ColTester_h
#define CCOL_Scn_ColTester_h 1


#include "GammaE_Scene.h"

// CBoundingSphere
#include "GammaE_E3D.h"
// CCOL_ColState
#include "CollisionSystem\CCOL_ColState.h"
// CCOL_ST_ColTester
#include "COL_Testers\COL_StaticTest\CCOL_ST_ColTester.h"
// CCOL_DT_ColTester
#include "COL_Testers\COL_DynamicTest\CCOL_DT_ColTester.h"
// CCOL_Mesh
#include "COL_Testers\COL_SceneTest\CCOL_Mesh.h"





class CCOL_Scn_ColTester 
{
    
  public:
          ~CCOL_Scn_ColTester();


                static int iTestObjects ();

            static int iTest3DObj_Rec (CObject3D *_poObj);

            static int iTest3DObj (CObject3D* _poObj);

            static int iTest3DObj_Node (CObject3D_Node* _poObj);

            static int iTest3DObj_Transf (CObject3D_Transf* _poObj);

            static int iTest3DObj_CompiledLeaf (CObject3D_CompiledLeaf* _poObj);

            static int iTest3DObj_Leaf (CObject3D_Leaf* _poObj);

            static int iTest3DObj_BSPNode (CObject3D_BSPNode* _poObj);

    // Data Members for Class Attributes

                  static CObject3D *SGrObj;
      
                  static CObject3D *DGrObj;
      
                  static int iNumColMeshes;
      
    // Data Members for Associations

                        static CCOL_Mesh ColMeshes[64];
      
    // Additional Public Declarations
            
  protected:
    // Additional Protected Declarations
            
  private:
    // Additional Private Declarations
            
  private:     // Additional Implementation Declarations
            
};


// Class CCOL_Scn_ColTester 



#endif
