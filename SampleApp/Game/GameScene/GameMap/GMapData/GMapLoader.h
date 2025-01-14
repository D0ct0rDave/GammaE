//## begin module%3C7E06E900AF.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3C7E06E900AF.cm

//## begin module%3C7E06E900AF.cp preserve=no
//## end module%3C7E06E900AF.cp

//## Module: GMapLoader%3C7E06E900AF; Pseudo Package specification
//## Source file: i:\Projects\GammaE\Game\GameScene\GameMap\GMapData\GMapLoader.h

#ifndef GMapLoader_h
#define GMapLoader_h 1

//## begin module%3C7E06E900AF.additionalIncludes preserve=no
//## end module%3C7E06E900AF.additionalIncludes

//## begin module%3C7E06E900AF.includes preserve=yes
//## end module%3C7E06E900AF.includes

// GMapData
#include "Game\GameScene\GameMap\GMapData\GMapData.h"
// GammaE_FileSys
#include "FileSys\GammaE_FileSys.h"
//## begin module%3C7E06E900AF.additionalDeclarations preserve=yes
//## end module%3C7E06E900AF.additionalDeclarations


//## begin GMapLoader%3C7E06E900AF.preface preserve=yes
//## end GMapLoader%3C7E06E900AF.preface

//## Class: GMapLoader%3C7E06E900AF
//## Category: Game::GameScene::GameMap::GMapData%3C7E06DC03D1
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3C7E075A0378;GMapData { -> }
//## Uses: <unnamed>%3C7E57E90048;GammaE_FileSys { -> }

class GMapLoader 
{
  //## begin GMapLoader%3C7E06E900AF.initialDeclarations preserve=yes
  //## end GMapLoader%3C7E06E900AF.initialDeclarations

  public:
    //## Constructors (generated)
      GMapLoader();

    //## Destructor (generated)
      ~GMapLoader();


    //## Other Operations (specified)
      //## Operation: poLoad%1014892585
      static GMapData* poLoad (char* _szFilename);

      //## Operation: poLoad%1014892587
      static GMapData* poLoad (CFile& _roFile);

      //## Operation: poLoadEntity%1014912984
      static CMapEntity* poLoadEntity (CFile& _roFile);

      //## Operation: poLoad_SoundEnt%1014933243
      static CMapEnt_Sound* poLoad_SoundEnt (CFile& _roFile);

      //## Operation: poLoad_LightEnt%1014933244
      static CMapEnt_Light* poLoad_LightEnt (CFile& _roFile);

      //## Operation: poLoad_MonsterEnt%1014933245
      static CMapEnt_Monster* poLoad_MonsterEnt (CFile& _roFile);

      //## Operation: poLoad_ItemEnt%1014933246
      static CMapEnt_Item* poLoad_ItemEnt (CFile& _roFile);

      //## Operation: poLoad_PowerUpEnt%1014933247
      static CMapEnt_PowerUp* poLoad_PowerUpEnt (CFile& _roFile);

      //## Operation: poLoad_TriggerEnt%1014933248
      static CMapEnt_Trigger* poLoad_TriggerEnt (CFile& _roFile);

    // Additional Public Declarations
      //## begin GMapLoader%3C7E06E900AF.public preserve=yes
      //## end GMapLoader%3C7E06E900AF.public

  protected:
    // Additional Protected Declarations
      //## begin GMapLoader%3C7E06E900AF.protected preserve=yes
      //## end GMapLoader%3C7E06E900AF.protected

  private:
    // Additional Private Declarations
      //## begin GMapLoader%3C7E06E900AF.private preserve=yes
      //## end GMapLoader%3C7E06E900AF.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin GMapLoader%3C7E06E900AF.implementation preserve=yes
      //## end GMapLoader%3C7E06E900AF.implementation

};

//## begin GMapLoader%3C7E06E900AF.postscript preserve=yes
//## end GMapLoader%3C7E06E900AF.postscript

// Class GMapLoader 

//## begin module%3C7E06E900AF.epilog preserve=yes
//## end module%3C7E06E900AF.epilog


#endif
