//	  %X% %Q% %Z% %W%



#ifndef CCOL_CollidedMeshes_h
#define CCOL_CollidedMeshes_h 1



// GammaE_E3D
#include "GammaE_E3D.h"





class CCOL_CollidedMeshes 
{
    
  public:
          CCOL_CollidedMeshes();

          ~CCOL_CollidedMeshes();


                void Reset ();

            void AddMesh (CMesh* _pMesh);

            int iGetNumMeshes ();

            CMesh* pGetMesh (int _iMesh);

    // Additional Public Declarations
            
  protected:
    // Data Members for Class Attributes

                  int iNumMeshes;
      
                  CMesh *pMesh[10];
      
    // Additional Protected Declarations
            
  private:
    // Additional Private Declarations
            
  private:     // Additional Implementation Declarations
            
};


// Class CCOL_CollidedMeshes 



#endif
