//	  %X% %Q% %Z% %W%



#ifndef CCOL_MT_CommonMesh_h
#define CCOL_MT_CommonMesh_h 1



// CCOL_DT_ColTester
#include "COL_Testers\COL_DynamicTest\CCOL_DT_ColTester.h"
// CCOL_MeshTester
#include "COL_Testers\COL_SceneTest\COL_MeshTest\CCOL_MeshTester.h"





class CCOL_MT_CommonMesh : public CCOL_MeshTester  {
    
  public:
          CCOL_MT_CommonMesh();

          ~CCOL_MT_CommonMesh();


                virtual int iTestCollision (CMesh* _poMesh, int _iMat, CGraphBV* _poBVol, CCOL_TriList& _oTriList);

    // Additional Public Declarations
            
  protected:
    // Additional Protected Declarations
            
  private:
    // Additional Private Declarations
            
  private:     // Additional Implementation Declarations
            
};


// Class CCOL_MT_CommonMesh 



#endif
