//	  %X% %Q% %Z% %W%



#ifndef CBoundingCylinder_h
#define CBoundingCylinder_h 1



// CBoundingVolume
#include "BoundingVolume\CBoundingVolume.h"




class CBoundingCylinder : public CBoundingVolume  {
    
  public:
          CBoundingCylinder();

          ~CBoundingCylinder();


                void Init (CVect3 &_Center, float _adius, float _Height);

            virtual void Init (CVect3& Max, CVect3& Min);

    // Data Members for Class Attributes

                  CVect3 Center;
      
                  float Radius;
      
                  float Height;
      
    // Additional Public Declarations
            
  protected:
    // Additional Protected Declarations
            
  private:
    // Additional Private Declarations
            
  private:     // Additional Implementation Declarations
            
};


// Class CBoundingCylinder 



#endif
