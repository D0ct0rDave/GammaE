//## begin module%3CA6E1CA02EB.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3CA6E1CA02EB.cm

//## begin module%3CA6E1CA02EB.cp preserve=no
//## end module%3CA6E1CA02EB.cp

//## Module: CGEMapEntityFileIO%3CA6E1CA02EB; Pseudo Package specification
//## Source file: i:\Projects\GammaE\Game\GameScene\GameMap\GEMap\CGEMapEntityFileIO.h

#ifndef CGEMapEntityFileIO_h
#define CGEMapEntityFileIO_h 1

//## begin module%3CA6E1CA02EB.additionalIncludes preserve=no
//## end module%3CA6E1CA02EB.additionalIncludes

//## begin module%3CA6E1CA02EB.includes preserve=yes
//## end module%3CA6E1CA02EB.includes

// GammaE_FileSys
#include "FileSys\GammaE_FileSys.h"
// CMapEntities
#include "Tools\GEMapCompiler\MapData\MapEntity\CMapEntities.h"
//## begin module%3CA6E1CA02EB.additionalDeclarations preserve=yes
//## end module%3CA6E1CA02EB.additionalDeclarations


//## begin CGEMapEntityFileIO%3CA6E1CA02EB.preface preserve=yes
//## end CGEMapEntityFileIO%3CA6E1CA02EB.preface

//## Class: CGEMapEntityFileIO%3CA6E1CA02EB
//## Category: Game::GameScene::GameMap::GEMap%3CA0FEC20001
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3CA6E595008F;GammaE_FileSys { -> }
//## Uses: <unnamed>%3CA6E9F80153;CMapEntities { -> }

class CGEMapEntityFileIO 
{
  //## begin CGEMapEntityFileIO%3CA6E1CA02EB.initialDeclarations preserve=yes
  //## end CGEMapEntityFileIO%3CA6E1CA02EB.initialDeclarations

  public:
    //## Constructors (generated)
      CGEMapEntityFileIO();

    //## Destructor (generated)
      ~CGEMapEntityFileIO();


    //## Other Operations (specified)
      //## Operation: SaveEntity%1017566940
      static void SaveEntity (CMapEntity* _poEnt, CFile& _roFile);

      //## Operation: poLoadEntity%1017566941
      static CMapEntity* poLoadEntity (CFile& _roFile);

    // Additional Public Declarations
      //## begin CGEMapEntityFileIO%3CA6E1CA02EB.public preserve=yes
      //## end CGEMapEntityFileIO%3CA6E1CA02EB.public

  protected:
    // Additional Protected Declarations
      //## begin CGEMapEntityFileIO%3CA6E1CA02EB.protected preserve=yes
      //## end CGEMapEntityFileIO%3CA6E1CA02EB.protected

  private:
    // Additional Private Declarations
      //## begin CGEMapEntityFileIO%3CA6E1CA02EB.private preserve=yes
      //## end CGEMapEntityFileIO%3CA6E1CA02EB.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CGEMapEntityFileIO%3CA6E1CA02EB.implementation preserve=yes
      //## end CGEMapEntityFileIO%3CA6E1CA02EB.implementation

};

//## begin CGEMapEntityFileIO%3CA6E1CA02EB.postscript preserve=yes
//## end CGEMapEntityFileIO%3CA6E1CA02EB.postscript

// Class CGEMapEntityFileIO 

//## begin module%3CA6E1CA02EB.epilog preserve=yes
//## end module%3CA6E1CA02EB.epilog


#endif
