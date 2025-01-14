//## begin module%3CAA12EF010B.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3CAA12EF010B.cm

//## begin module%3CAA12EF010B.cp preserve=no
//## end module%3CAA12EF010B.cp

//## Module: CGEMapInterpreter%3CAA12EF010B; Pseudo Package specification
//## Source file: i:\Projects\GammaE\Game\GameScene\GameMap\GEMap\GEMapInterpreter\CGEMapInterpreter.h

#ifndef CGEMapInterpreter_h
#define CGEMapInterpreter_h 1

//## begin module%3CAA12EF010B.additionalIncludes preserve=no
//## end module%3CAA12EF010B.additionalIncludes

//## begin module%3CAA12EF010B.includes preserve=yes
//## end module%3CAA12EF010B.includes

// CRTMapEntities
#include "Game\Entities\RTMapEntities\CRTMapEntities.h"
// CParticleSystemMgr
#include "Game\GameScene\CParticleSystemMgr.h"
// CGameScene
#include "Game\GameScene\CGameScene.h"
// CGEMap
#include "Game\GameScene\GameMap\GEMap\CGEMap.h"
//## begin module%3CAA12EF010B.additionalDeclarations preserve=yes
//## end module%3CAA12EF010B.additionalDeclarations


//## begin CGEMapInterpreter%3CAA12EF010B.preface preserve=yes
//## end CGEMapInterpreter%3CAA12EF010B.preface

//## Class: CGEMapInterpreter%3CAA12EF010B
//## Category: Game::GameScene::GameMap::GEMap::GEMapInterpreter%3CAA139E0301
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3CAA1313031F;CGEMap { -> }
//## Uses: <unnamed>%3CAA13DA00CD;CGameScene { -> }
//## Uses: <unnamed>%3CAA1482033B;CParticleSystemMgr { -> }
//## Uses: <unnamed>%3CAB7EAD03D2;CMapEntities { -> }
//## Uses: <unnamed>%3CDE4AFA010C;CRTMapEntities { -> }

class CGEMapInterpreter 
{
  //## begin CGEMapInterpreter%3CAA12EF010B.initialDeclarations preserve=yes
  //## end CGEMapInterpreter%3CAA12EF010B.initialDeclarations

  public:
    //## Constructors (generated)
      CGEMapInterpreter();

    //## Destructor (generated)
      ~CGEMapInterpreter();


    //## Other Operations (specified)
      //## Operation: Interpret%1017778984
      static void Interpret (CGEMap& _roMap);

      //## Operation: LinkTriggeredTargets%1021237868
      static void LinkTriggeredTargets (CGEMap& _roMap);

      //## Operation: poFindTarget%1021237869
      static CRTME_Target* poFindTarget (char* _szTargetName, CGEMap& _roMap);

    // Additional Public Declarations
      //## begin CGEMapInterpreter%3CAA12EF010B.public preserve=yes
      //## end CGEMapInterpreter%3CAA12EF010B.public

  protected:
    // Additional Protected Declarations
      //## begin CGEMapInterpreter%3CAA12EF010B.protected preserve=yes
      //## end CGEMapInterpreter%3CAA12EF010B.protected

  private:
    // Additional Private Declarations
      //## begin CGEMapInterpreter%3CAA12EF010B.private preserve=yes
      //## end CGEMapInterpreter%3CAA12EF010B.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CGEMapInterpreter%3CAA12EF010B.implementation preserve=yes
      //## end CGEMapInterpreter%3CAA12EF010B.implementation

};

//## begin CGEMapInterpreter%3CAA12EF010B.postscript preserve=yes
//## end CGEMapInterpreter%3CAA12EF010B.postscript

// Class CGEMapInterpreter 

//## begin module%3CAA12EF010B.epilog preserve=yes
//## end module%3CAA12EF010B.epilog


#endif
