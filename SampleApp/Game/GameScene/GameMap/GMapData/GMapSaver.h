//## begin module%3C7E06EF02CA.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3C7E06EF02CA.cm

//## begin module%3C7E06EF02CA.cp preserve=no
//## end module%3C7E06EF02CA.cp

//## Module: GMapSaver%3C7E06EF02CA; Pseudo Package specification
//## Source file: i:\Projects\GammaE\Game\GameScene\GameMap\GMapData\GMapSaver.h

#ifndef GMapSaver_h
#define GMapSaver_h 1

//## begin module%3C7E06EF02CA.additionalIncludes preserve=no
//## end module%3C7E06EF02CA.additionalIncludes

//## begin module%3C7E06EF02CA.includes preserve=yes
//## end module%3C7E06EF02CA.includes

// GMapData
#include "Game\GameScene\GameMap\GMapData\GMapData.h"
// GammaE_FileSys
#include "FileSys\GammaE_FileSys.h"
//## begin module%3C7E06EF02CA.additionalDeclarations preserve=yes
//## end module%3C7E06EF02CA.additionalDeclarations


//## begin GMapSaver%3C7E06EF02CA.preface preserve=yes
//## end GMapSaver%3C7E06EF02CA.preface

//## Class: GMapSaver%3C7E06EF02CA
//## Category: Game::GameScene::GameMap::GMapData%3C7E06DC03D1
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3C7E075D00F2;GMapData { -> }
//## Uses: <unnamed>%3C7E57EE00EF;GammaE_FileSys { -> }

class GMapSaver 
{
  //## begin GMapSaver%3C7E06EF02CA.initialDeclarations preserve=yes
  //## end GMapSaver%3C7E06EF02CA.initialDeclarations

  public:
    //## Constructors (generated)
      GMapSaver();

    //## Destructor (generated)
      ~GMapSaver();


    //## Other Operations (specified)
      //## Operation: bSave%1014892584
      static bool bSave (char* _szFilename, GMapData* _poGMap);

      //## Operation: bSave%1014892586
      static bool bSave (CFile& _roFile, GMapData* _poGMap);

      //## Operation: bSaveEntity%1014912985
      static bool bSaveEntity (CFile& _roFile, CMapEntity* _poEntity);

      //## Operation: bSave_SoundEnt%1014933237
      static bool bSave_SoundEnt (CFile& _roFile, CMapEnt_Sound* _poEnt);

      //## Operation: bSave_LightEnt%1014933238
      static bool bSave_LightEnt (CFile& _roFile, CMapEnt_Light* _poEnt);

      //## Operation: bSave_MonsterEnt%1014933239
      static bool bSave_MonsterEnt (CFile& _roFile, CMapEnt_Monster* _poEnt);

      //## Operation: bSave_ItemEnt%1014933240
      static bool bSave_ItemEnt (CFile& _roFile, CMapEnt_Item* _poEnt);

      //## Operation: bSave_PowerUpEnt%1014933241
      static bool bSave_PowerUpEnt (CFile& _roFile, CMapEnt_PowerUp* _poEnt);

      //## Operation: bSave_TriggerEnt%1014933242
      static bool bSave_TriggerEnt (CFile& _roFile, CMapEnt_Trigger* _poEnt);

    // Additional Public Declarations
      //## begin GMapSaver%3C7E06EF02CA.public preserve=yes
      //## end GMapSaver%3C7E06EF02CA.public

  protected:
    // Additional Protected Declarations
      //## begin GMapSaver%3C7E06EF02CA.protected preserve=yes
      //## end GMapSaver%3C7E06EF02CA.protected

  private:
    // Additional Private Declarations
      //## begin GMapSaver%3C7E06EF02CA.private preserve=yes
      //## end GMapSaver%3C7E06EF02CA.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin GMapSaver%3C7E06EF02CA.implementation preserve=yes
      //## end GMapSaver%3C7E06EF02CA.implementation

};

//## begin GMapSaver%3C7E06EF02CA.postscript preserve=yes
//## end GMapSaver%3C7E06EF02CA.postscript

// Class GMapSaver 

//## begin module%3C7E06EF02CA.epilog preserve=yes
//## end module%3C7E06EF02CA.epilog


#endif
