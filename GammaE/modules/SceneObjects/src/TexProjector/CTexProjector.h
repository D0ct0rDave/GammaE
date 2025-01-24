//	  %X% %Q% %Z% %W%



#ifndef CTexProjector_h
#define CTexProjector_h 1



// CObject3D_Leaf
#include "GammaE_Scene.h"




class CTexProjector : public CObject3D_Leaf  {
    
  public:
          CTexProjector();

          virtual ~CTexProjector();


                void Setup (CMesh* _oSrcMesh, CE3D_Shader* _poShader, CMatrix4x4& _oPrjMatrix);

            void Setup (CMesh* _oSrcMesh, CE3D_Shader* _poShader, CVect3& _oPos, CVect3& _oDir, float _fXSize, float _fYSize);

    // Additional Public Declarations
            
  protected:
    // Data Members for Class Attributes

                  CMesh oAuxMesh;
      
    // Additional Protected Declarations
            
  private:
    // Additional Private Declarations
            
  private:     // Additional Implementation Declarations
            
};


// Class CTexProjector 



#endif
