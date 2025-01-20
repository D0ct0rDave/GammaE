//	  %X% %Q% %Z% %W%



#ifndef CCOL_MT_TerrainMesh_h
#define CCOL_MT_TerrainMesh_h 1



// GammaE_TerrainData
#include "GammaE_TerrainData.h"
// CCOL_DT_ColTester
#include "COL_Testers\COL_DynamicTest\CCOL_DT_ColTester.h"
// CCOL_MeshTester
#include "COL_Testers\COL_SceneTest\COL_MeshTest\CCOL_MeshTester.h"





class CCOL_MT_TerrainMesh : public CCOL_MeshTester  {
    
  public:
          CCOL_MT_TerrainMesh();

          ~CCOL_MT_TerrainMesh();


                virtual int iTestCollision (CMesh* _poMesh, int _iMat, CGraphBV* _poBVol, CCOL_TriList& _oTriList);

            int iGetTriangles (int _iX, int _iY, int _iRad, CVect3* _pVXs);

            void GetTriangle (int _iX, int _iY, CVect3* _pa6VXs);

            float GetHeight (int iX, int iY);

            void Init (CHeightField* _pHF, int _iSectorRes, float _fSectorSize);

    // Additional Public Declarations
            
  protected:
    // Additional Protected Declarations
            
  private:
    // Data Members for Class Attributes

                  CHeightField *HF;
      
                  int iSectorRes;
      
                  float fRatio;
      
                  int iTWidth;
      
                  int iTHeight;
      
                  float fInvRatio;
      
    // Additional Private Declarations
            
  private:     // Additional Implementation Declarations
            
};


// Class CCOL_MT_TerrainMesh 



#endif
