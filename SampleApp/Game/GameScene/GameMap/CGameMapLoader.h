//## begin module%3CB4A85F029E.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3CB4A85F029E.cm

//## begin module%3CB4A85F029E.cp preserve=no
//## end module%3CB4A85F029E.cp

//## Module: CGameMapLoader%3CB4A85F029E; Pseudo Package specification
//## Source file: i:\Projects\GammaE\Game\GameScene\GameMap\CGameMapLoader.h

#ifndef CGameMapLoader_h
#define CGameMapLoader_h 1

//## begin module%3CB4A85F029E.additionalIncludes preserve=no
//## end module%3CB4A85F029E.additionalIncludes

//## begin module%3CB4A85F029E.includes preserve=yes
//## end module%3CB4A85F029E.includes

// CGMRoomCOLInfo
#include "Game\GameScene\GameMap\CGMRoomCOLInfo.h"
//## begin module%3CB4A85F029E.additionalDeclarations preserve=yes
//## end module%3CB4A85F029E.additionalDeclarations


//## begin CGameMapLoader%3CB4A85F029E.preface preserve=yes
//## end CGameMapLoader%3CB4A85F029E.preface

//## Class: CGameMapLoader%3CB4A85F029E
//	This class is reponsible of loading all data regarding
//	to a level map.
//	It also initilizes other global structures in the game.
//## Category: Game::GameScene::GameMap%3C2B3ADF02B0
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3CB4A8B80255;CGEMap { -> }
//## Uses: <unnamed>%3CB4A8BA019A;CGEMapLoader { -> }
//## Uses: <unnamed>%3CB4AEE300CF;CGEMapInterpreter { -> }

class CGameMapLoader 
{
  //## begin CGameMapLoader%3CB4A85F029E.initialDeclarations preserve=yes
  //## end CGameMapLoader%3CB4A85F029E.initialDeclarations

  public:
    //## Constructors (generated)
      CGameMapLoader();

    //## Destructor (generated)
      ~CGameMapLoader();


    //## Other Operations (specified)
      //## Operation: iLoad%1018461830
      static void iLoad (char *_szMap);

      //## Operation: SetupRoomColliders%1018461831
      static void SetupRoomColliders ();

      //## Operation: poLoadWorldScene%1023005985
      static CObject3D* poLoadWorldScene (char* _szWFilename);

      //## Operation: poLoadTerrainScene%1023005986
      static CObject3D * poLoadTerrainScene (char* _szTrnFile);

      //## Operation: LinkWorldRooms%1023005984
      static void LinkWorldRooms (CObject3D *_poWorldScn);

    // Data Members for Associations

      //## Association: Game::GameScene::GameMap::<unnamed>%3CB4AC3F0178
      //## Role: CGameMapLoader::aoRoomColliders%3CB4AC3F0269
      //## begin CGameMapLoader::aoRoomColliders%3CB4AC3F0269.role preserve=no  public: static CGMRoomCOLInfo { -> VHAN}
      static CDynArray <CGMRoomCOLInfo*> aoRoomColliders;
      //## end CGameMapLoader::aoRoomColliders%3CB4AC3F0269.role

    // Additional Public Declarations
      //## begin CGameMapLoader%3CB4A85F029E.public preserve=yes
      //## end CGameMapLoader%3CB4A85F029E.public

  protected:
    // Additional Protected Declarations
      //## begin CGameMapLoader%3CB4A85F029E.protected preserve=yes
      //## end CGameMapLoader%3CB4A85F029E.protected

  private:
    // Additional Private Declarations
      //## begin CGameMapLoader%3CB4A85F029E.private preserve=yes
      //## end CGameMapLoader%3CB4A85F029E.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CGameMapLoader%3CB4A85F029E.implementation preserve=yes
      //## end CGameMapLoader%3CB4A85F029E.implementation

};

//## begin CGameMapLoader%3CB4A85F029E.postscript preserve=yes
//## end CGameMapLoader%3CB4A85F029E.postscript

// Class CGameMapLoader 

//## begin module%3CB4A85F029E.epilog preserve=yes
//## end module%3CB4A85F029E.epilog


#endif
