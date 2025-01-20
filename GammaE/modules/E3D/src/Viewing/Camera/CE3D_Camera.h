//	  %X% %Q% %Z% %W%



#ifndef CE3D_Camera_h
#define CE3D_Camera_h 1



// GammaE_Math
#include "GammaE_Math.h"





class CE3D_Camera 
{
  	public:
		~CE3D_Camera() {};
  
  public:

                void SetPos (float _fcX, float _fcY, float _fcZ);

            void SetDir (float _fPitch, float _fYaw, float _fRoll);

            void SetVectors (CVect3& cDir, CVect3& cUp, CVect3& cSide);

            void LookAt (CVect3& Center);

    // Data Members for Class Attributes

                  CVect3 Pos;
      
                  CVect3 Dir;
      
                  CVect3 Side;
      
                  CVect3 Up;
      
    // Additional Public Declarations
            
  protected:
    // Additional Protected Declarations
            
  private:
    // Additional Private Declarations
            
  private:     // Additional Implementation Declarations
            
};


// Class CE3D_Camera 



#endif
