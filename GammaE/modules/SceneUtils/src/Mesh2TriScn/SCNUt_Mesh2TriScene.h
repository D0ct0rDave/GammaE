//	  %X% %Q% %Z% %W%



#ifndef SCNUt_Mesh2TriScene_h
#define SCNUt_Mesh2TriScene_h 1



// GammaE_E3D
#include "GammaE_E3D.h"
// SCNUt_TriScene
#include "SCNUt_TriScene.h"





class SCNUt_Mesh2TriScene 
{
    
  public:
          SCNUt_Mesh2TriScene();

          ~SCNUt_Mesh2TriScene();


                SCNUt_TriScene* Generate (CMesh& _oMesh, int _iMat);

            SCNUt_TriScene* Generate_FromIndexedTriFanMesh (CMesh& _oMesh, int _iMat);

            SCNUt_TriScene* Generate_FromIndexedQuadStripMesh (CMesh& _oMesh, int _iMat);

    // Additional Public Declarations
            
  protected:

                SCNUt_TriScene* Generate_FromIndexedTriMesh (CMesh& _oMesh, int _iMat);

            SCNUt_TriScene* Generate_FromIndexedQuadMesh (CMesh& _oMesh, int _iMat);

            SCNUt_TriScene* Generate_FromIndexedTriStripMesh (CMesh& _oMesh, int _iMat);

            SCNUt_TriScene* Generate_FromNonIndexedTriMesh (CMesh& _oMesh, int _iMat);

            SCNUt_TriScene* Generate_FromNonIndexedQuadMesh (CMesh& _oMesh, int _iMat);

            SCNUt_TriScene* Generate_FromNonIndexedTriStripMesh (CMesh& _oMesh, int _iMat);

    // Additional Protected Declarations
            
  private:
    // Additional Private Declarations
            
  private:     // Additional Implementation Declarations
            
};


// Class SCNUt_Mesh2TriScene 



#endif
