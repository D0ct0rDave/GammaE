//	  %X% %Q% %Z% %W%



#ifndef SCNUt_Scn2TriScnBuilder_h
#define SCNUt_Scn2TriScnBuilder_h 1



// CObject3D
#include "CObject3D.h"
// CObject3D_Transf
#include "CObject3D_Transf.h"
// SCNUt_TriScene
#include "SCNUt_TriScene.h"
// SCNUt_MaterialTable
#include "SCNUt_MaterialTable.h"





class SCNUt_Scn2TriScnBuilder 
{
    
  public:
          SCNUt_Scn2TriScnBuilder();

          ~SCNUt_Scn2TriScnBuilder();


                SCNUt_TriScene * poBuild (CObject3D* _poScene, SCNUt_MaterialTable& _oMTable);

            SCNUt_TriScene* poBuildRec (CObject3D* _poScene, CMatrix4x4 *_poMStack, int _iMPos, SCNUt_MaterialTable& _poMTab);

            SCNUt_TriScene* poBuildMesh (CMesh& _oMesh, int _iMat, CMatrix4x4& _oMat);

    // Additional Public Declarations
            
  protected:
    // Additional Protected Declarations
            
  private:
    // Additional Private Declarations
            
  private:     // Additional Implementation Declarations
            
};


// Class SCNUt_Scn2TriScnBuilder 



#endif
