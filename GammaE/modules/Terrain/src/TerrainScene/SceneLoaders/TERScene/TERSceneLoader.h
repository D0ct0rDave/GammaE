//	  %X% %Q% %Z% %W%



#ifndef TERSceneLoader_h
#define TERSceneLoader_h 1


#include "TerrainScene\SceneLoaders\EnvPars\EnvPars.h"
#include "GammaE_SceneObjects.h"
// CTileBookmark
#include "TerrainMaterials\CTileBookmark.h"
// CTerrainCircuit
#include "TerrainScene\CTerrainCircuit.h"
// CTerrainSector
#include "TerrainScene\CTerrainSector.h"
// CLODSelector_Array
#include "TerrainMath\CLODSelector_Array.h"
// CTerrainTesselatorGM
#include "TerrainTesselators\CTerrainTesselatorGM.h"





class TERSceneLoader 
{
    
  public:
          TERSceneLoader();

          ~TERSceneLoader();


                CObject3D * poLoad (char *_Filename);

            void LoadData (FILE *fd);

            void CreateSharedObjects ();

            CTileBookmark * poCreateTileBookmark ();

            CLODSelector * poCreateLODSelector ();

            CSkyBox * poCreateSkyBox ();

            CSkyDome * poCreateSkyDome ();

            CObject3D * poGenerateScene ();

    // Data Members for Class Attributes

                  CHeightField *HF;
      
                  CTexMap *TM;
      
                  CLightMap *LM;
      
                  TTexSet *TS;
      
                  TTexSet *ATS;
      
                  int iSectorRes;
      
                  float fSectorSize;
      
                  float fXYScale;
      
                  float fIScale;
      
                  int iCircXRes;
      
                  int iCircYRes;
      
                  int fCircXSize;
      
                  int fCircYSize;
      
                  CTileBookmark *poTB;
      
                  CTerrainTesselatorGM *poTT;
      
                  CLODSelector *poLS;
      
                  TEnvironmentPars EnvPars;
      
    // Additional Public Declarations
            
  protected:
    // Additional Protected Declarations
            
  private:
    // Additional Private Declarations
            
  private:     // Additional Implementation Declarations
            
};


// Class TERSceneLoader 



#endif
