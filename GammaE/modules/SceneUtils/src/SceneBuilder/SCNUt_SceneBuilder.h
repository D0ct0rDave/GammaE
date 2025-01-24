//	  %X% %Q% %Z% %W%



#ifndef SCNUt_SceneBuilder_h
#define SCNUt_SceneBuilder_h 1



// CObject3D_Node
#include "GammaE_Scene.h"
// SCNUt_TriScene
#include "SCNUt_TriScene.h"
// SCNUt_MaterialTable
#include "SCNUt_MaterialTable.h"
// SCNUt_MeshCompacter
#include "ScnMeshGen\SCNUt_MeshCompacter.h"
// SCNUt_TriSceneSeparator
#include "SeparateTriScene\SCNUt_TriSceneSeparator.h"





class SCNUt_SceneBuilder 
{
    
  public:
          SCNUt_SceneBuilder();

          ~SCNUt_SceneBuilder();


                CObject3D * poBuildScene (SCNUt_TriScene& _oScene, SCNUt_MaterialTable &_oMatTable);

    // Additional Public Declarations
            
  protected:
    // Additional Protected Declarations
            
  private:
    // Additional Private Declarations
            
  private:     // Additional Implementation Declarations
            
};


// Class SCNUt_SceneBuilder 



#endif
