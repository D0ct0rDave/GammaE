//	  %X% %Q% %Z% %W%



#ifndef CCOL_TriListGen_h
#define CCOL_TriListGen_h 1



// GammaE_E3D
#include "GammaE_E3D.h"
// GammaE_Math
#include "GammaE_Math.h"
// CCOL_TriList
#include "COL_TriList\CCOL_TriList.h"





class CCOL_TriListGen 
{
    
  public:
          CCOL_TriListGen();

          ~CCOL_TriListGen();


                virtual int GetTriList (CCOL_TriList& _oTriList, CVect3& _oPos, float _fRadius);

            virtual void SetMeshes (CMesh** _poMeshes, int* _piMats, int _iNumMeshes);

            virtual int GetTrisFromMesh (CCOL_TriList& _oTriList, CMesh* _poMesh, int _iMat, CVect3& _oPos, float _fRadius);

    // Additional Public Declarations
            
  protected:
    // Data Members for Class Attributes

                  static CMesh* *poMeshes;
      
                  static int *piMats;
      
                  static int iNumMeshes;
      
    // Additional Protected Declarations
            
  private:
    // Additional Private Declarations
            
  private:     // Additional Implementation Declarations
            
};


// Class CCOL_TriListGen 



#endif
