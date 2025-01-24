//	  %X% %Q% %Z% %W%



#ifndef SCNUt_TriUtils_h
#define SCNUt_TriUtils_h 1



// SCNUt_Triangle
#include "SCNUt_Triangle.h"





class SCNUt_TriUtils 
{
    
  public:
          SCNUt_TriUtils();

          ~SCNUt_TriUtils();


                static void MinimizeMappingOffset (SCNUt_Triangle& _oTri);

            static void ChangeWinding (SCNUt_Triangle& _oTri);

            static void GetQ2UVCoords (CVect3& _oPnt, CVect3& _oXAxis, CVect3& _oYAxis, float _fUOfs, float _fVOfs, float _fUScl, float _fVScl, float* _pfU, float* _pfV);

    // Additional Public Declarations
            
  protected:
    // Additional Protected Declarations
            
  private:
    // Additional Private Declarations
            
  private:     // Additional Implementation Declarations
            
};


// Class SCNUt_TriUtils 



#endif
