//	  %X% %Q% %Z% %W%



#ifndef CCOL_Scn_TriListGen_h
#define CCOL_Scn_TriListGen_h 1


#include "GammaE_Scene.h"

// CCOL_TriListGen
#include "COL_TriList\CCOL_TriListGen.h"




class CCOL_Scn_TriListGen : public CCOL_TriListGen  {
    
  public:
          CCOL_Scn_TriListGen();

          ~CCOL_Scn_TriListGen();


                virtual int GetTriList (CCOL_TriList& _oTriList, CVect3& _oPos, float _fRadius);

            virtual int GetTrisFromMesh (CCOL_TriList& _oTriList, CMesh* _poMesh, int _iMat, CVect3& _oPos, float _fRadius);

    // Additional Public Declarations
            
  protected:
    // Additional Protected Declarations
            
  private:
    // Additional Private Declarations
            
  private:     // Additional Implementation Declarations
            
};


// Class CCOL_Scn_TriListGen 



#endif
