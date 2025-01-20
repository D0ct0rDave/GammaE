//	  %X% %Q% %Z% %W%



#ifndef DEFSceneLoader_h
#define DEFSceneLoader_h 1



// CTileBookmark
#include "TerrainMaterials\CTileBookmark.h"
// CTerrainCircuit
#include "TerrainScene\CTerrainCircuit.h"
// CTerrainSector
#include "TerrainScene\CTerrainSector.h"
// CTerrainTesselatorGM
#include "TerrainTesselators\CTerrainTesselatorGM.h"
// CObject3D
#include "GammaE_Scene.h"





class DEFSceneLoader 
{
    
  public:
          DEFSceneLoader();

          ~DEFSceneLoader();


                CObject3D * Load (char *_Filename);

    // Additional Public Declarations
            
  protected:
    // Additional Protected Declarations
            
  private:
    // Additional Private Declarations
            
  private:     // Additional Implementation Declarations
            
};


// Class DEFSceneLoader 



#endif
