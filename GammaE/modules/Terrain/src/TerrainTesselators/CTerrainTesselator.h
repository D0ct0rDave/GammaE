//	  %X% %Q% %Z% %W%



#ifndef CTerrainTesselator_h
#define CTerrainTesselator_h 1



// CTileBookmark
#include "TerrainMaterials\CTileBookmark.h"
// CLODSelector
#include "TerrainMath\CLODSelector.h"
// GammaE_TerrainData
#include "GammaE_TerrainData.h"





class CTerrainTesselator 
{
    
  public:
          CTerrainTesselator();

          ~CTerrainTesselator();


                virtual void Render ();

            virtual void SetData (CHFSector* _HF, CLMSector* _LM, CTMSector* _TM, CTileBookmark* _TB, float *_fLODs, int *_iLODs, float _fXYScale);

            void SetCameraPos (CVect3 _Pos);

    
                  CLODSelector * GetTileLODSel ();
      void SetTileLODSel (CLODSelector * value);

    // Data Members for Associations

                  CLODSelector *TileLODSel;
      
    // Additional Public Declarations
            
  protected:
    // Data Members for Class Attributes

                  float *fLODs;
      
                  int *iLODs;
      
                  CHFSector *HF;
      
                  CLMSector *LM;
      
                  CTMSector *TM;
      
                  CTileBookmark *TB;
      
                  CVect3 Cam;
      
                  float fXYScale;
      
    // Additional Protected Declarations
            
  private:
    // Additional Private Declarations
            
  private:     // Additional Implementation Declarations
            
};


// Class CTerrainTesselator 


inline CLODSelector * CTerrainTesselator::GetTileLODSel ()
{
    return TileLODSel;
}

inline void CTerrainTesselator::SetTileLODSel (CLODSelector * value)
{
    TileLODSel = value;
}



#endif
