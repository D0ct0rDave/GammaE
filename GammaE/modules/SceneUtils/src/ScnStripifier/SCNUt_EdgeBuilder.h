//	  %X% %Q% %Z% %W%



#ifndef SCNUt_EdgeBuilder_h
#define SCNUt_EdgeBuilder_h 1



// GammaE_E3D
#include "GammaE_E3D.h"
// SCNUt_Mesh2TriScene
#include "Mesh2TriScn\SCNUt_Mesh2TriScene.h"
// SCNUt_EdgeList
#include "ScnStripifier\SCNUt_EdgeList.h"
// SCNUt_MeshCompacter
#include "ScnMeshGen\SCNUt_MeshCompacter.h"





class SCNUt_EdgeBuilder 
{
    
  public:
          SCNUt_EdgeBuilder();

          ~SCNUt_EdgeBuilder();


                SCNUt_EdgeList* poBuild (CMesh* _poMesh, CMesh *&_poOutMesh);

            SCNUt_EdgeList* poBuild_FromIndexedTriMesh (CMesh* _poMesh);

    // Additional Public Declarations
            
  protected:
    // Additional Protected Declarations
            
  private:
    // Additional Private Declarations
            
  private:     // Additional Implementation Declarations
            
};


// Class SCNUt_EdgeBuilder 



#endif