//## begin module%3CA0F58F02C1.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3CA0F58F02C1.cm

//## begin module%3CA0F58F02C1.cp preserve=no
//## end module%3CA0F58F02C1.cp

//## Module: CQLEMapLoader%3CA0F58F02C1; Pseudo Package specification
//## Source file: i:\Projects\GammaE\Tools\GEMapCompiler\QLEMap\CQLEMapLoader.h

#ifndef CQLEMapLoader_h
#define CQLEMapLoader_h 1

//## begin module%3CA0F58F02C1.additionalIncludes preserve=no
//## end module%3CA0F58F02C1.additionalIncludes

//## begin module%3CA0F58F02C1.includes preserve=yes
//## end module%3CA0F58F02C1.includes

// CQLEMapScn
#include "Tools\GEMapCompiler\QLEMap\CQLEMapScn.h"
// CMapEntities
#include "Tools\GEMapCompiler\MapData\MapEntity\CMapEntities.h"
//## begin module%3CA0F58F02C1.additionalDeclarations preserve=yes
//## end module%3CA0F58F02C1.additionalDeclarations


//## begin CQLEMapLoader%3CA0F58F02C1.preface preserve=yes
//## end CQLEMapLoader%3CA0F58F02C1.preface

//## Class: CQLEMapLoader%3CA0F58F02C1
//## Category: Tools::GEMapCompiler::QLEMap%3CA0F45D0394
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3CA0F5D80258;CQLEMapScn { -> }
//## Uses: <unnamed>%3CA82B20014A;CMapEntities { -> }

class CQLEMapLoader 
{
  //## begin CQLEMapLoader%3CA0F58F02C1.initialDeclarations preserve=yes
  //## end CQLEMapLoader%3CA0F58F02C1.initialDeclarations

  public:
    //## Constructors (generated)
      CQLEMapLoader();

    //## Destructor (generated)
      ~CQLEMapLoader();


    //## Other Operations (specified)
      //## Operation: iLoad%1017265239
      CQLEMapScn * iLoad (char* _szFilename);

      //## Operation: ParseBrush%1017265240
      void ParseBrush (CQLEMapScn* _poQLEScn, char *&_szMapStr);

      //## Operation: ParseEntity%1017265243
      void ParseEntity (CQLEMapScn* _poQLEScn, char *&_szMapStr);

      //## Operation: ParseObject%1017265244
      void ParseObject (CQLEMapScn* _poQLEScn, char*& _szMapStr, char* _szObjName);

    // Additional Public Declarations
      //## begin CQLEMapLoader%3CA0F58F02C1.public preserve=yes
      //## end CQLEMapLoader%3CA0F58F02C1.public

  protected:
    // Additional Protected Declarations
      //## begin CQLEMapLoader%3CA0F58F02C1.protected preserve=yes
      //## end CQLEMapLoader%3CA0F58F02C1.protected

  private:
    // Additional Private Declarations
      //## begin CQLEMapLoader%3CA0F58F02C1.private preserve=yes
      //## end CQLEMapLoader%3CA0F58F02C1.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CQLEMapLoader%3CA0F58F02C1.implementation preserve=yes
      //## end CQLEMapLoader%3CA0F58F02C1.implementation

};

//## begin CQLEMapLoader%3CA0F58F02C1.postscript preserve=yes
//## end CQLEMapLoader%3CA0F58F02C1.postscript

// Class CQLEMapLoader 

//## begin module%3CA0F58F02C1.epilog preserve=yes
//## end module%3CA0F58F02C1.epilog


#endif
