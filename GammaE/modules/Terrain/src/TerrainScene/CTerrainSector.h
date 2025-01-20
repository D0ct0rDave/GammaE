//	  %X% %Q% %Z% %W%



#ifndef CTerrainSector_h
#define CTerrainSector_h 1



// CTileBookmark
#include "TerrainMaterials\CTileBookmark.h"
// CTerrainTesselator
#include "TerrainTesselators\CTerrainTesselator.h"
// GammaE_TerrainData
#include "GammaE_TerrainData.h"
// CObject3D
#include "GammaE_Scene.h"





class CTerrainSector : public CObject3D
{
    
  public:
          CTerrainSector();

          virtual ~CTerrainSector();


                virtual void Render ();
			
			virtual CGraphBV* poCreateBoundVol();

            virtual void ComputeBoundVol ();

            virtual CGraphBV* poGetBoundVol ();

            void SetMaxsMins (CVect3& _Maxs, CVect3& _Mins);

    // Data Members for Class Attributes

                  CHFSector *HF;
      
                  CLMSector *LM;
      
                  CTMSector *TM;
      
                  CTileBookmark *TB;
      
                  CTerrainTesselator *Tess;
      
                  float fXYScale;
      
    // Additional Public Declarations
            
  protected:
    // Additional Protected Declarations
            
  private:
    
            float * GetfLODs ();

    // Data Members for Class Attributes

            float *fLODs;
      
                  int *iLODs;
      
                  CVect3 Mins;
      
                  CVect3 Maxs;
      
    // Additional Private Declarations
            
  private:     // Additional Implementation Declarations
            
};


// Class CTerrainSector 


inline float * CTerrainSector::GetfLODs ()
{
    return fLODs;
}



#endif
