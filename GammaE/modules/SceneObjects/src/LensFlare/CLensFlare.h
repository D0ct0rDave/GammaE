//	  %X% %Q% %Z% %W%



#ifndef CLensFlare_h
#define CLensFlare_h 1



// CLensFlare_Elem
#include "LensFlare\CLensFlare_Elem.h"
// CObject3D
#include "GammaE_Scene.h"





class CLensFlare : public CObject3D  {
    
  public:
          CLensFlare();

          virtual ~CLensFlare();


                void InitLensFlare (int _iNumElems, CVect3 _SunPos);

            void SetupFlareElem (int _iElem, float _fSize, float _fDist, CGColor _Color, CE3D_Shader *_pMat);

            void UpdateMesh ();

            virtual void Render ();

            virtual CGraphBV* poGetBoundVol ();

            virtual void ComputeBoundVol ();

            bool bVisible ();

            void UpdateState ();

    // Additional Public Declarations
            
  protected:
    // Additional Protected Declarations
            
  private:
    // Data Members for Class Attributes

                  CLensFlare_Elem* FlareElems;
      
                  int iNumElems;
      
                  CMesh_Rect *MeshArray;
      
                  int iLensFlareState;
      
                  float fVisFact;
      
                  CVect3 oPrjSun;
      
                  CVect3 oSunPos;
      
                  CVect3 oScrPos;
      
                  CMatrix4x4 oViewMat;
      
                  CMatrix4x4 oPrjMat;
      
    // Additional Private Declarations
            
  private:     // Additional Implementation Declarations
            
};


// Class CLensFlare 



#endif
