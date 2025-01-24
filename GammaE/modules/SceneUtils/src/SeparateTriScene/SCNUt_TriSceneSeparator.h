//	  %X% %Q% %Z% %W%



#ifndef SCNUt_TriSceneSeparator_h
#define SCNUt_TriSceneSeparator_h 1



// SCNUt_TriScene
#include "SCNUt_TriScene.h"
// SCNUt_MeshCompacter
#include "ScnMeshGen\SCNUt_MeshCompacter.h"





class SCNUt_TriSceneSeparator 
{
    
  public:
          SCNUt_TriSceneSeparator();

          ~SCNUt_TriSceneSeparator();


                int SeparateScene (SCNUt_TriScene &Scene);

            int iProcessTriScene (SCNUt_TriScene &Scene);

            int iGetTrisWithMat (int _iMat);

    // Data Members for Class Attributes

                  int NumMeshes;
      
                  SCNUt_TriScene *Meshes;
      
                  int *piTriMat;
      
                  int *piMatIdx;
      
                  int iMaxMats;
      
    // Additional Public Declarations
            
  protected:
    // Additional Protected Declarations
            
  private:
    // Additional Private Declarations
            
  private:     // Additional Implementation Declarations
            
};


// Class SCNUt_TriSceneSeparator 



#endif
