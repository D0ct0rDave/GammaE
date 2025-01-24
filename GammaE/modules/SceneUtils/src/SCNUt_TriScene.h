//	  %X% %Q% %Z% %W%



#ifndef SCNUt_TriScene_h
#define SCNUt_TriScene_h 1



// SCNUt_Triangle
#include "SCNUt_Triangle.h"





class SCNUt_TriScene 
{
    
  public:
          SCNUt_TriScene();

          ~SCNUt_TriScene();

          const SCNUt_TriScene & operator=(const SCNUt_TriScene &right);


                virtual void Init (uint _uiNumTris);

    // Data Members for Class Attributes

                  SCNUt_Triangle *Tris;
      
                  uint NumTris;
      
    // Additional Public Declarations
            
  protected:
    // Additional Protected Declarations
            
  private:
    // Additional Private Declarations
            
  private:     // Additional Implementation Declarations
            
};


// Class SCNUt_TriScene 



#endif
