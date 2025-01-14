//## begin module%3CA0FD3800F5.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3CA0FD3800F5.cm

//## begin module%3CA0FD3800F5.cp preserve=no
//## end module%3CA0FD3800F5.cp

//## Module: CGEMapSaver%3CA0FD3800F5; Pseudo Package specification
//## Source file: i:\Projects\GammaE\Game\GameScene\GameMap\GEMap\CGEMapSaver.h

#ifndef CGEMapSaver_h
#define CGEMapSaver_h 1

//## begin module%3CA0FD3800F5.additionalIncludes preserve=no
//## end module%3CA0FD3800F5.additionalIncludes

//## begin module%3CA0FD3800F5.includes preserve=yes
//## end module%3CA0FD3800F5.includes

// CGEMapEntityFileIO
#include "Game\GameScene\GameMap\GEMap\CGEMapEntityFileIO.h"
// CGEMap
#include "Game\GameScene\GameMap\GEMap\CGEMap.h"
//## begin module%3CA0FD3800F5.additionalDeclarations preserve=yes
//## end module%3CA0FD3800F5.additionalDeclarations


//## begin CGEMapSaver%3CA0FD3800F5.preface preserve=yes
//## end CGEMapSaver%3CA0FD3800F5.preface

//## Class: CGEMapSaver%3CA0FD3800F5
//## Category: Game::GameScene::GameMap::GEMap%3CA0FEC20001
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3CA0FD680180;CGEMap { -> }
//## Uses: <unnamed>%3CA6E2090328;CGEMapEntityFileIO { -> }

class CGEMapSaver 
{
  //## begin CGEMapSaver%3CA0FD3800F5.initialDeclarations preserve=yes
  //## end CGEMapSaver%3CA0FD3800F5.initialDeclarations

  public:
    //## Constructors (generated)
      CGEMapSaver();

    //## Destructor (generated)
      ~CGEMapSaver();


    //## Other Operations (specified)
      //## Operation: Save%1017327544
      static void Save (char* _szFilename, CGEMap *_poGEMap);

    // Additional Public Declarations
      //## begin CGEMapSaver%3CA0FD3800F5.public preserve=yes
      //## end CGEMapSaver%3CA0FD3800F5.public

  protected:
    // Additional Protected Declarations
      //## begin CGEMapSaver%3CA0FD3800F5.protected preserve=yes
      //## end CGEMapSaver%3CA0FD3800F5.protected

  private:
    // Additional Private Declarations
      //## begin CGEMapSaver%3CA0FD3800F5.private preserve=yes
      //## end CGEMapSaver%3CA0FD3800F5.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CGEMapSaver%3CA0FD3800F5.implementation preserve=yes
      //## end CGEMapSaver%3CA0FD3800F5.implementation

};

//## begin CGEMapSaver%3CA0FD3800F5.postscript preserve=yes
//## end CGEMapSaver%3CA0FD3800F5.postscript

// Class CGEMapSaver 

//## begin module%3CA0FD3800F5.epilog preserve=yes
//## end module%3CA0FD3800F5.epilog


#endif
