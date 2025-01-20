//	  %X% %Q% %Z% %W%



#ifndef SCNUt_AdjTriListBuilder_h
#define SCNUt_AdjTriListBuilder_h 1



// GammaE_E3D
#include "GammaE_E3D.h"
// SCNUt_Mesh2TriScene
#include "Mesh2TriScn\SCNUt_Mesh2TriScene.h"
// SCNUt_AdjTriList
#include "ScnStripifier\SCNUt_AdjTriList.h"
// SCNUt_MeshCompacter
#include "ScnMeshGen\SCNUt_MeshCompacter.h"





class SCNUt_AdjTriListBuilder 
{
    
  public:
          SCNUt_AdjTriListBuilder();

          ~SCNUt_AdjTriListBuilder();


                SCNUt_AdjTriList* poBuild (CMesh* _poMesh, CMesh *&_poOutMesh);

    // Additional Public Declarations
            
  protected:

                SCNUt_AdjTriList * poBuild_FromIndexedTriMesh (CMesh* _poMesh);

            void AddEdgeNeighs (CMesh* _poMesh, SCNUt_AdjTriList *_poATL, int _iTri, int _iA, int _iB);

    // Additional Protected Declarations
            
  private:
    // Additional Private Declarations
            
  private:     // Additional Implementation Declarations
            
};


// Class SCNUt_AdjTriListBuilder 



#endif
