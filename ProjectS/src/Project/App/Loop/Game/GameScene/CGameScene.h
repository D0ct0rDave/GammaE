//## begin module%3B65CB11028A.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3B65CB11028A.cm

//## begin module%3B65CB11028A.cp preserve=no
//## end module%3B65CB11028A.cp

//## Module: CGameScene%3B65CB11028A; Pseudo Package specification
//## Source file: i:\Projects\GammaE\Game\GameScene\CGameScene.h

#ifndef CGameScene_h
#define CGameScene_h 1

//## begin module%3B65CB11028A.additionalIncludes preserve=no
//## end module%3B65CB11028A.additionalIncludes

//## begin module%3B65CB11028A.includes preserve=yes
#include "GammaE.h"
//## end module%3B65CB11028A.includes

//## begin module%3B65CB11028A.additionalDeclarations preserve=yes
//## end module%3B65CB11028A.additionalDeclarations


//## begin CGameScene%3B65CB11028A.preface preserve=yes
//## end CGameScene%3B65CB11028A.preface

//## Class: CGameScene%3B65CB11028A
//## Category: Game::GameScene%3B770ECD0030
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CGameScene 
{
  //## begin CGameScene%3B65CB11028A.initialDeclarations preserve=yes
  //## end CGameScene%3B65CB11028A.initialDeclarations

  public:
    //## Constructors (generated)
      CGameScene();

    //## Destructor (generated)
      virtual ~CGameScene();


    //## Other Operations (specified)
      //## Operation: Render%997655866
      static void Render ();

    // Data Members for Associations

      //## Association: Game::GameScene::<unnamed>%3CB33D3700BA
      //## Role: CGameScene::oPSysMgr%3CB33D370237
      //## begin CGameScene::oPSysMgr%3CB33D370237.role preserve=no  public: CParticleSystemMgr { -> VHAN}
      //## end CGameScene::oPSysMgr%3CB33D370237.role

      //## Association: Game::GameScene::<unnamed>%3CB33D5B003A
      //## Role: CGameScene::oBgrMgr%3CB33D5B0225
      //## begin CGameScene::oBgrMgr%3CB33D5B0225.role preserve=no  public: CBackgroundMgr { -> VHAN}
      //## end CGameScene::oBgrMgr%3CB33D5B0225.role

      //## Association: Game::GameScene::<unnamed>%3CB33E02021B
      //## Role: CGameScene::oHUDMgr%3CB33E0203B5
      //## begin CGameScene::oHUDMgr%3CB33E0203B5.role preserve=no  public: CHUDMgr { -> VHAN}
      static CGSceneGroup m_oList;
      //## end CGameScene::oHUDMgr%3CB33E0203B5.role

    // Additional Public Declarations
      //## begin CGameScene%3B65CB11028A.public preserve=yes
      //## end CGameScene%3B65CB11028A.public

  protected:
    // Additional Protected Declarations
      //## begin CGameScene%3B65CB11028A.protected preserve=yes
      //## end CGameScene%3B65CB11028A.protected

  private:
    // Additional Private Declarations
      //## begin CGameScene%3B65CB11028A.private preserve=yes
      //## end CGameScene%3B65CB11028A.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CGameScene%3B65CB11028A.implementation preserve=yes
      //## end CGameScene%3B65CB11028A.implementation

};

//## begin CGameScene%3B65CB11028A.postscript preserve=yes
//## end CGameScene%3B65CB11028A.postscript

// Class CGameScene 

//## begin module%3B65CB11028A.epilog preserve=yes
//## end module%3B65CB11028A.epilog


#endif
