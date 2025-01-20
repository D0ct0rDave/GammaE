//	  %X% %Q% %Z% %W%



#ifndef SCNUt_EdgeList_h
#define SCNUt_EdgeList_h 1



// SCNUt_Edge
#include "ScnStripifier\SCNUt_Edge.h"




class SCNUt_EdgeList 
{
    
  public:
          SCNUt_EdgeList();

          ~SCNUt_EdgeList();


                int iAdd (SCNUt_Edge& _oEdge);

            void Clear ();

    // Data Members for Class Attributes

                  int iNumEdges;
      
    // Data Members for Associations

                        SCNUt_Edge *Edge;
      
    // Additional Public Declarations
            
  protected:
    // Additional Protected Declarations
            
  private:
    // Data Members for Class Attributes

                  int iMaxEdges;
      
    // Additional Private Declarations
            
  private:     // Additional Implementation Declarations
            
};


// Class SCNUt_EdgeList 



#endif
