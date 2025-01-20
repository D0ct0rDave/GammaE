//	  %X% %Q% %Z% %W%



#ifndef CSkyBox_h
#define CSkyBox_h 1



// CObject3D_Transf
#include "GammaE_Scene.h"





class CSkyBox : public CObject3D_Transf  {
    
  public:
          CSkyBox();

          virtual ~CSkyBox();


                void InitSkyBox (float fSize, CVect3& Center, float fRoll, CE3D_Shader* *Materials);

    // Additional Public Declarations
            
  protected:
    // Additional Protected Declarations
            
  private:
    // Data Members for Class Attributes

                  CMesh* MeshSides[6];
      
                  CObject3D_Leaf *ObjSides[6];
      
                  CE3D_Shader *MatsSides[6];
      
                  CObject3D_Node* poNode;
      
    // Additional Private Declarations
            
  private:     // Additional Implementation Declarations
            
};


// Class CSkyBox 



#endif
