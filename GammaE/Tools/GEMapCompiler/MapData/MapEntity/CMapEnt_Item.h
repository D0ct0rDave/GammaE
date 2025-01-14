//## begin module%3C7EB6960108.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3C7EB6960108.cm

//## begin module%3C7EB6960108.cp preserve=no
//## end module%3C7EB6960108.cp

//## Module: CMapEnt_Item%3C7EB6960108; Pseudo Package specification
//## Source file: i:\Projects\GammaE\Tools\GEMapCompiler\MapData\MapEntity\CMapEnt_Item.h

#ifndef CMapEnt_Item_h
#define CMapEnt_Item_h 1

//## begin module%3C7EB6960108.additionalIncludes preserve=no
//## end module%3C7EB6960108.additionalIncludes

//## begin module%3C7EB6960108.includes preserve=yes
//## end module%3C7EB6960108.includes

// CMapEnt_Target
#include "Tools\GEMapCompiler\MapData\MapEntity\CMapEnt_Target.h"
//## begin module%3C7EB6960108.additionalDeclarations preserve=yes
//## end module%3C7EB6960108.additionalDeclarations


//## begin CMapEnt_Item%3C7EB6960108.preface preserve=yes
//## end CMapEnt_Item%3C7EB6960108.preface

//## Class: CMapEnt_Item%3C7EB6960108
//## Category: Tools::GEMapCompiler::MapData::MapEntity%3C7428F80364
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CMapEnt_Item : public CMapEnt_Target  //## Inherits: <unnamed>%3CDCE07501F4
{
  //## begin CMapEnt_Item%3C7EB6960108.initialDeclarations preserve=yes
  //## end CMapEnt_Item%3C7EB6960108.initialDeclarations

  public:
    //## Constructors (generated)
      CMapEnt_Item();

    //## Destructor (generated)
      ~CMapEnt_Item();

    // Data Members for Class Attributes

      //## Attribute: oPos%3C7EB6A30066
      //## begin CMapEnt_Item::oPos%3C7EB6A30066.attr preserve=no  public: CVect3 {UA} 
      CVect3 oPos;
      //## end CMapEnt_Item::oPos%3C7EB6A30066.attr

      //## Attribute: iType%3C7EB6A701E8
      //## begin CMapEnt_Item::iType%3C7EB6A701E8.attr preserve=no  public: int {UA} 
      int iType;
      //## end CMapEnt_Item::iType%3C7EB6A701E8.attr

    // Additional Public Declarations
      //## begin CMapEnt_Item%3C7EB6960108.public preserve=yes
      //## end CMapEnt_Item%3C7EB6960108.public

  protected:
    // Additional Protected Declarations
      //## begin CMapEnt_Item%3C7EB6960108.protected preserve=yes
      //## end CMapEnt_Item%3C7EB6960108.protected

  private:
    // Additional Private Declarations
      //## begin CMapEnt_Item%3C7EB6960108.private preserve=yes
      //## end CMapEnt_Item%3C7EB6960108.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CMapEnt_Item%3C7EB6960108.implementation preserve=yes
      //## end CMapEnt_Item%3C7EB6960108.implementation

};

//## begin CMapEnt_Item%3C7EB6960108.postscript preserve=yes
//## end CMapEnt_Item%3C7EB6960108.postscript

// Class CMapEnt_Item 

//## begin module%3C7EB6960108.epilog preserve=yes
//## end module%3C7EB6960108.epilog


#endif
