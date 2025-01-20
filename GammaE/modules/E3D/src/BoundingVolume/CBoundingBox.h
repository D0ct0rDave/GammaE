//	  %X% %Q% %Z% %W%



#ifndef CBoundingBox_h
#define CBoundingBox_h 1



// CBoundingVolume
#include "BoundingVolume\CBoundingVolume.h"

//-----------------------------------------------------------------------------
//			  e---f
//           /|  /|
//			a-g-b h
//          |/  |/
//          c---d
//-----------------------------------------------------------------------------





class CBoundingBox : public CBoundingVolume  {
    
  public:
          CBoundingBox();

          ~CBoundingBox();


                void Init (CVect3& Max, CVect3& Min);

    // Data Members for Class Attributes

                  CVect3 Maxs;
      
                  CVect3 Mins;
      
                  CVect3 Points[8];
      
    // Additional Public Declarations
            
  protected:
    // Additional Protected Declarations
            
  private:
    // Additional Private Declarations
            
  private:     // Additional Implementation Declarations
            
};


// Class CBoundingBox 



#endif
