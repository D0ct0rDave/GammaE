//	  %X% %Q% %Z% %W%



#ifndef CSkyDome_h
#define CSkyDome_h 1



// CObject3D_Leaf
#include "GammaE_Scene.h"




class CSkyDome : public CObject3D_Leaf  {
    
  public:
          CSkyDome();

          virtual ~CSkyDome();


                void SetRotation (float _fRot);

            void SetRadius (float _fRadius);

            void SetAxis (CVect3 _Axis);

            void SetPosition (CVect3 _Pos);

            void CreateDome (bool _bFogAffected, int _iNumVSlices, int _iNumHSlices, int _iStartVSlice, int _iEndVSlice, float _fUTiling, float _fVTiling);

            virtual void Render ();

    // Additional Public Declarations
            
  protected:
    // Additional Protected Declarations
            
  private:
    // Data Members for Class Attributes

                  float fRadius;
      
                  float fRot;
      
                  CVect3 Axis;
      
                  CVect3 Pos;
      
                  bool FogAffected;
      
    // Additional Private Declarations
            
  private:     // Additional Implementation Declarations
            
};


// Class CSkyDome 



#endif
