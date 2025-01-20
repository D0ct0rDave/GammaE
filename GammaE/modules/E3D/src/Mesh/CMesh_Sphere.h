//	  %X% %Q% %Z% %W%



#ifndef CMesh_Sphere_h
#define CMesh_Sphere_h 1



// CMesh
#include "Mesh\CMesh.h"




class CMesh_Sphere : public CMesh  {
    
  public:
          CMesh_Sphere();

                CMesh_Sphere (int _iNumSlices, float _fRadius);

          ~CMesh_Sphere();

    // Additional Public Declarations
            
  protected:

                void Init (int _iNumSlices, float _fRadius);

    // Additional Protected Declarations
            
  private:
    // Additional Private Declarations
            
  private:     // Additional Implementation Declarations
            
};


// Class CMesh_Sphere 



#endif
