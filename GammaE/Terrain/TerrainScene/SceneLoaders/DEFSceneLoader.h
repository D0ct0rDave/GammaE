//## begin module%3AFEFA4B0190.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3AFEFA4B0190.cm

//## begin module%3AFEFA4B0190.cp preserve=no
//## end module%3AFEFA4B0190.cp

//## Module: DEFSceneLoader%3AFEFA4B0190; Pseudo Package specification
//## Source file: i:\Projects\GammaE\Terrain\TerrainScene\SceneLoaders\DEFSceneLoader.h

#ifndef DEFSceneLoader_h
#define DEFSceneLoader_h 1

//## begin module%3AFEFA4B0190.additionalIncludes preserve=no
//## end module%3AFEFA4B0190.additionalIncludes

//## begin module%3AFEFA4B0190.includes preserve=yes
//## end module%3AFEFA4B0190.includes

// CTileBookmark
#include "Terrain\TerrainMaterials\CTileBookmark.h"
// CTerrainCircuit
#include "Terrain\TerrainScene\CTerrainCircuit.h"
// CTerrainSector
#include "Terrain\TerrainScene\CTerrainSector.h"
// CTerrainTesselatorGM
#include "Terrain\TerrainTesselators\CTerrainTesselatorGM.h"
// CObject3D
#include "Scene\CObject3D.h"
//## begin module%3AFEFA4B0190.additionalDeclarations preserve=yes
//## end module%3AFEFA4B0190.additionalDeclarations


//## begin DEFSceneLoader%3AFEFA4B0190.preface preserve=yes
//## end DEFSceneLoader%3AFEFA4B0190.preface

//## Class: DEFSceneLoader%3AFEFA4B0190
//## Category: Terrain::TerrainScene::SceneLoaders%3B0190A200C8
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3AFEFA700398;CObject3D { -> }
//## Uses: <unnamed>%3B0190EE03D4;CTerrainSector { -> }
//## Uses: <unnamed>%3B019112023A;CTileBookmark { -> }
//## Uses: <unnamed>%3B01912A00BE;CTerrainTesselatorGM { -> }
//## Uses: <unnamed>%3B0190EC03B6;CTerrainCircuit { -> }

class DEFSceneLoader 
{
  //## begin DEFSceneLoader%3AFEFA4B0190.initialDeclarations preserve=yes
  //## end DEFSceneLoader%3AFEFA4B0190.initialDeclarations

  public:
    //## Constructors (generated)
      DEFSceneLoader();

    //## Destructor (generated)
      ~DEFSceneLoader();


    //## Other Operations (specified)
      //## Operation: Load%989790243
      CObject3D * Load (char *_Filename);

    // Additional Public Declarations
      //## begin DEFSceneLoader%3AFEFA4B0190.public preserve=yes
      //## end DEFSceneLoader%3AFEFA4B0190.public

  protected:
    // Additional Protected Declarations
      //## begin DEFSceneLoader%3AFEFA4B0190.protected preserve=yes
      //## end DEFSceneLoader%3AFEFA4B0190.protected

  private:
    // Additional Private Declarations
      //## begin DEFSceneLoader%3AFEFA4B0190.private preserve=yes
      //## end DEFSceneLoader%3AFEFA4B0190.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin DEFSceneLoader%3AFEFA4B0190.implementation preserve=yes
      //## end DEFSceneLoader%3AFEFA4B0190.implementation

};

//## begin DEFSceneLoader%3AFEFA4B0190.postscript preserve=yes
//## end DEFSceneLoader%3AFEFA4B0190.postscript

// Class DEFSceneLoader 

//## begin module%3AFEFA4B0190.epilog preserve=yes
//## end module%3AFEFA4B0190.epilog


#endif
