//	  %X% %Q% %Z% %W%



#ifndef CDetailer_h
#define CDetailer_h 1



// CObject3D_Leaf
#include "GammaE_Scene.h"




class CDetailer : public CObject3D_Leaf  {
    
  public:
          CDetailer();

          virtual ~CDetailer();


                void Init (int _iMaxTris);

            void SetCamPos (CVect3& _oCamPos);

            virtual void SetVertexTris (CVect3* _poVXs, int _iNumTris);

            void CreateTextureContents (CGMipMap *_pMipMap);

            CE3D_Shader * poCreateMaterial ();

            virtual void Render ();

    // Additional Public Declarations
            
  protected:
    // Data Members for Class Attributes

                  CVect3 oCamPos;
      
                  CGMipMap *poTex;
      
    // Additional Protected Declarations
            
  private:
    // Additional Private Declarations
            
  private:     // Additional Implementation Declarations
            
};


// Class CDetailer 



#endif
