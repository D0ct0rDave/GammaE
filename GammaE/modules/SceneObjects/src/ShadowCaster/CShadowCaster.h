//	  %X% %Q% %Z% %W%



#ifndef CShadowCaster_h
#define CShadowCaster_h 1



// CTexProjector
#include "TexProjector\CTexProjector.h"
// CE3D_Shader
#include "GammaE_E3D.h"
// CObject3D
#include "GammaE_Scene.h"




class CShadowCaster : public CObject3D  {
    
  public:
          CShadowCaster();

          virtual ~CShadowCaster();


                void Init (int _iRes);

            void Setup (CVect3& _oLightPos, CObject3D* _poBlockerObj, CMesh** _poRecObjs, int _iNumRecObjs);

            virtual CGraphBV* poGetBoundVol ();

            virtual void ComputeBoundVol ();

            void ComputeLightCamera ();

            void ComputeLightViewport (CE3D_Viewport& _oVpt);

            void ComputeLightProjection ();

            void ComputeTextureProjection ();

            void UploadShadowMap ();

            void RenderShadowMap ();

            virtual void Render ();

    // Data Members for Class Attributes

                  CMatrix4x4 oCamMat;
      
    // Data Members for Associations

                        CTexProjector oTexProj;
      
                        CE3D_Shader *poShader;
      
    // Additional Public Declarations
            
  protected:
    // Data Members for Class Attributes

                  CObject3D* poBlockerObj;
      
                  CVect3 oLPos;
      
                  CMesh* *poRecObjs;
      
                  int iNumRecObjs;
      
                  int iRes;
      
                  CGTextureObj *poTexObj;
      
                  CMatrix4x4 oPrjMat;
      
                  CMatrix4x4 oPrjTexMat;
      
                  unsigned char *pucAuxTexData;
      
    // Additional Protected Declarations
            
  private:
    // Additional Private Declarations
            
  private:     // Additional Implementation Declarations
            
};


// Class CShadowCaster 



#endif
