//	  %X% %Q% %Z% %W%



#ifndef CBoundingSphere_h
#define CBoundingSphere_h 1



// CBoundingVolume
#include "BoundingVolume\CBoundingVolume.h"

//			y
//			|
//          |
//			|
//     Center----- x
//		   /
//        /
//	     z
//-----------------------------------------------------------------------------





class CBoundingSphere : public CBoundingVolume  {
    
  public:
          CBoundingSphere();

          ~CBoundingSphere();


                void Init (CVect3 _Center, float _fRadius);

            virtual void Init (CVect3& Max, CVect3& Min);

    // Data Members for Class Attributes

                  CVect3 Center;
      
                  float Radius;
      
    // Additional Public Declarations
            
  protected:
    // Additional Protected Declarations
            
  private:
    // Additional Private Declarations
            
  private:     // Additional Implementation Declarations
            
};


// Class CBoundingSphere 



#endif
