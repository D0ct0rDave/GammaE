//	  %X% %Q% %Z% %W%



#ifndef SCNUt_Stripifier_h
#define SCNUt_Stripifier_h 1



// GammaE_E3D
#include "GammaE_E3D.h"
// SCNUt_TriScene
#include "SCNUt_TriScene.h"
// SCNUt_AdjTriListBuilder
#include "ScnStripifier\SCNUt_AdjTriListBuilder.h"
// SCNUt_EdgeBuilder
#include "ScnStripifier\SCNUt_EdgeBuilder.h"
// SCNUt_MeshGenerator
#include "ScnMeshGen\SCNUt_MeshGenerator.h"





class SCNUt_Stripifier 
{
    
  public:
          SCNUt_Stripifier();

          ~SCNUt_Stripifier();


                CMesh * poStripifyMesh (CMesh *_poMesh);

            CMesh * poStripifyTriScene (SCNUt_TriScene *_poTS);

            int iGetNonCommonVertex (CMesh* _SrcMesh, int _iSrcTri, int _iDstTri);

    // Additional Public Declarations
            
  protected:

                CMesh * poStripify (CMesh* _poMesh, SCNUt_AdjTriList* _poATL);

            int iSelectStartingTri (SCNUt_AdjTriList *_poATL);

            int iSelectBestNeigh (SCNUt_AdjTriList *_poATL, int _iSrcTri);

    // Additional Protected Declarations
            
  private:
    // Additional Private Declarations
            
  private:     // Additional Implementation Declarations
            
};


// Class SCNUt_Stripifier 



#endif
