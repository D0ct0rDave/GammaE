//	  %X% %Q% %Z% %W%



#ifndef SCNUt_AdjTriList_h
#define SCNUt_AdjTriList_h 1



// SCNUt_AdjTri
#include "ScnStripifier\SCNUt_AdjTri.h"




class SCNUt_AdjTriList 
{
    
  public:
          SCNUt_AdjTriList();

          ~SCNUt_AdjTriList();


                void Init (int _iNumTris);

    // Data Members for Class Attributes

                  int iNumTris;
      
    // Data Members for Associations

                        SCNUt_AdjTri *Tri;
      
    // Additional Public Declarations
            
  protected:
    // Additional Protected Declarations
            
  private:
    // Additional Private Declarations
            
  private:     // Additional Implementation Declarations
            
};


// Class SCNUt_AdjTriList 



#endif
