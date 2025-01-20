//	  %X% %Q% %Z% %W%



#ifndef CCompiledMesh_h
#define CCompiledMesh_h 1



// CGraphBV
#include "BoundingVolume\GraphBoundVol\CGraphBV.h"
// CMesh
#include "Mesh\CMesh.h"





class CCompiledMesh 
{
    
  public:
          CCompiledMesh();

          ~CCompiledMesh();


                CGraphBV * poGetBV ();

            void poCopyBV (CGraphBV *_poBV);

    // Data Members for Class Attributes

                  int iID;
      
                  unsigned short usNumVerts;
      
                  unsigned short usNumPrims;
      
                  EMeshType eMeshType;
      
    // Additional Public Declarations
            
  protected:
    // Additional Protected Declarations
            
  private:
    // Data Members for Class Attributes

                  CGraphBV *poBV;
      
    // Additional Private Declarations
            
  private:     // Additional Implementation Declarations
            
};


// Class CCompiledMesh 


inline CGraphBV * CCompiledMesh::poGetBV ()
{
  	return ( poBV);
}



#endif
