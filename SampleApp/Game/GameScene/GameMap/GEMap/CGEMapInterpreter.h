//## begin module%3CAA12EF010B.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3CAA12EF010B.cm

//## begin module%3CAA12EF010B.cp preserve=no
//## end module%3CAA12EF010B.cp

//## Module: CGEMapInterpreter%3CAA12EF010B; Pseudo Package specification
//## Source file: i:\Projects\GammaE\Game\GameScene\GameMap\GEMap\CGEMapInterpreter.h

#ifndef CGEMapInterpreter_h
#define CGEMapInterpreter_h 1

//## begin module%3CAA12EF010B.additionalIncludes preserve=no
//## end module%3CAA12EF010B.additionalIncludes

//## begin module%3CAA12EF010B.includes preserve=yes
//## end module%3CAA12EF010B.includes

// CGEMap
#include "Game\GameScene\GameMap\GEMap\CGEMap.h"
//## begin module%3CAA12EF010B.additionalDeclarations preserve=yes
//## end module%3CAA12EF010B.additionalDeclarations


//## begin CGEMapInterpreter%3CAA12EF010B.preface preserve=yes
//## end CGEMapInterpreter%3CAA12EF010B.preface

//## Class: CGEMapInterpreter%3CAA12EF010B
//## Category: Game::GameScene::GameMap::GEMap%3CA0FEC20001
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3CAA1313031F;CGEMap { -> }

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
