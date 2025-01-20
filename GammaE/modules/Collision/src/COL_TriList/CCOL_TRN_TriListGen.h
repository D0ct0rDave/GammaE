//	  %X% %Q% %Z% %W%



#ifndef CCOL_TRN_TriListGen_h
#define CCOL_TRN_TriListGen_h 1



// GammaE_TerrainData
#include "GammaE_TerrainData.h"
// GammaE_Math
#include "GammaE_Math.h"
// CCOL_TriListGen
#include "COL_TriList\CCOL_TriListGen.h"





class CCOL_TRN_TriListGen : public CCOL_TriListGen  {
    
  public:
          CCOL_TRN_TriListGen();

          ~CCOL_TRN_TriListGen();


                static float GetHeight (float fX, float fY);

            static float GetHeight (int iX, int iY);

            static void Init (int _iSecsPerRow, int _iSecsPerCol, int _iSectorRes, float _fSectorSize);

            static void SetSector (int iSect, CHFSector *HFSect);

            virtual int GetTriList (CCOL_TriList& _oTriList, CVect3& _oPos, float _fRadius);

            virtual int GetTrisFromMesh (CCOL_TriList& _oTriList, CMesh* _poMesh, int _iMat, CVect3& _oPos, float _fRadius);

    // Additional Public Declarations
            
  protected:
    // Additional Protected Declarations
            
  private:
    // Data Members for Class Attributes

                  static float fSectorSize;
      
                  static CHFSector* *HFs;
      
                  static int iSecsPerRow;
      
                  static int iSecsPerCol;
      
                  static int iSectorRes;
      
                  static float fRatio;
      
                  static int iTWidth;
      
                  static int iTHeight;
      
                  static float fInvRatio;
      
    // Additional Private Declarations
            
  private:     // Additional Implementation Declarations
            
};


// Class CCOL_TRN_TriListGen 



#endif
