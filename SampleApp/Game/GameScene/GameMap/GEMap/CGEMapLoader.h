//## begin module%3CA0FD1D0254.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3CA0FD1D0254.cm

//## begin module%3CA0FD1D0254.cp preserve=no
//## end module%3CA0FD1D0254.cp

//## Module: CGEMapLoader%3CA0FD1D0254; Pseudo Package specification
//## Source file: i:\Projects\GammaE\Game\GameScene\GameMap\GEMap\CGEMapLoader.h

#ifndef CGEMapLoader_h
#define CGEMapLoader_h 1

//## begin module%3CA0FD1D0254.additionalIncludes preserve=no
//## end module%3CA0FD1D0254.additionalIncludes

//## begin module%3CA0FD1D0254.includes preserve=yes
//## end module%3CA0FD1D0254.includes

// CGEMapEntityFileIO
#include "Game\GameScene\GameMap\GEMap\CGEMapEntityFileIO.h"
// CGEMap
#include "Game\GameScene\GameMap\GEMap\CGEMap.h"
//## begin module%3CA0FD1D0254.additionalDeclarations preserve=yes
//## end module%3CA0FD1D0254.additionalDeclarations


//## begin CGEMapLoader%3CA0FD1D0254.preface preserve=yes
//## end CGEMapLoader%3CA0FD1D0254.preface

//## Class: CGEMapLoader%3CA0FD1D0254
//## Category: Game::GameScene::GameMap::GEMap%3CA0FEC20001
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3CA0FD7002AE;CGEMap { -> }
//## Uses: <unnamed>%3CA6E20801BE;CGEMapEntityFileIO { -> }

class CGEMapLoader 
{
  //## begin CGEMapLoader%3CA0FD1D0254.initialDeclarations preserve=yes
  //## end CGEMapLoader%3CA0FD1D0254.initialDeclarations

  public:
    //## Constructors (generated)
      CGEMapLoader();

    //## Destructor (generated)
      ~CGEMapLoader();


    //## Other Operations (specified)
      //## Operation: poLoad%1017327545
      static CGEMap * poLoad (char* _szFilename);

    // Additional Public Declarations
      //## begin CGEMapLoader%3CA0FD1D0254.public preserve=yes
      //## end CGEMapLoader%3CA0FD1D0254.public

  protected:
    // Additional Protected Declarations
      //## begin CGEMapLoader%3CA0FD1D0254.protected preserve=yes
      //## end CGEMapLoader%3CA0FD1D0254.protected

  private:
    // Additional Private Declarations
      //## begin CGEMapLoader%3CA0FD1D0254.private preserve=yes
      //## end CGEMapLoader%3CA0FD1D0254.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CGEMapLoader%3CA0FD1D0254.implementation preserve=yes
      //## end CGEMapLoader%3CA0FD1D0254.implementation

};

//## begin CGEMapLoader%3CA0FD1D0254.postscript preserve=yes
//## end CGEMapLoader%3CA0FD1D0254.postscript

// Class CGEMapLoader 

//## begin module%3CA0FD1D0254.epilog preserve=yes
//## end module%3CA0FD1D0254.epilog


#endif
