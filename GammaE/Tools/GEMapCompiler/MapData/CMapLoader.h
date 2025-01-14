//## begin module%3C74236B016C.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3C74236B016C.cm

//## begin module%3C74236B016C.cp preserve=no
//## end module%3C74236B016C.cp

//## Module: CMapLoader%3C74236B016C; Pseudo Package specification
//## Source file: i:\Projects\GammaE\Tools\GEMapCompiler\MapData\CMapLoader.h

#ifndef CMapLoader_h
#define CMapLoader_h 1

//## begin module%3C74236B016C.additionalIncludes preserve=no
//## end module%3C74236B016C.additionalIncludes

//## begin module%3C74236B016C.includes preserve=yes
//## end module%3C74236B016C.includes

// CMapScene
#include "Tools\GEMapCompiler\MapData\CMapScene.h"
//## begin module%3C74236B016C.additionalDeclarations preserve=yes
//## end module%3C74236B016C.additionalDeclarations


//## begin CMapLoader%3C74236B016C.preface preserve=yes
//## end CMapLoader%3C74236B016C.preface

//## Class: CMapLoader%3C74236B016C
//## Category: Tools::GEMapCompiler::MapData%3C741F390140
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3C7427860109;CMapScene { -> }

class CMapLoader 
{
  //## begin CMapLoader%3C74236B016C.initialDeclarations preserve=yes
  //## end CMapLoader%3C74236B016C.initialDeclarations

  public:
    //## Constructors (generated)
      CMapLoader();

    //## Destructor (generated)
      ~CMapLoader();


    //## Other Operations (specified)
      //## Operation: iLoad%1014246306
      static CMapScene * iLoad (char* _szFilename);

    // Additional Public Declarations
      //## begin CMapLoader%3C74236B016C.public preserve=yes
      //## end CMapLoader%3C74236B016C.public

  protected:

    //## Other Operations (specified)
      //## Operation: ParseWorldSpawn%1014246809
      static void ParseWorldSpawn (char*& _szMapStr, CMapScene& _roMap);

      //## Operation: poParseLightEntity%1014246810
      static CMapEntity * poParseLightEntity (char*& _szMapStr);

    // Additional Protected Declarations
      //## begin CMapLoader%3C74236B016C.protected preserve=yes
      //## end CMapLoader%3C74236B016C.protected

  private:
    // Additional Private Declarations
      //## begin CMapLoader%3C74236B016C.private preserve=yes
      //## end CMapLoader%3C74236B016C.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CMapLoader%3C74236B016C.implementation preserve=yes
      //## end CMapLoader%3C74236B016C.implementation

};

//## begin CMapLoader%3C74236B016C.postscript preserve=yes
//## end CMapLoader%3C74236B016C.postscript

// Class CMapLoader 

//## begin module%3C74236B016C.epilog preserve=yes
//## end module%3C74236B016C.epilog


#endif
