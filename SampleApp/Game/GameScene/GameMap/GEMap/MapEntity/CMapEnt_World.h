//## begin module%3CDE328B016C.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3CDE328B016C.cm

//## begin module%3CDE328B016C.cp preserve=no
//## end module%3CDE328B016C.cp

//## Module: CMapEnt_World%3CDE328B016C; Pseudo Package specification
//## Source file: i:\Projects\GammaE\Tools\GEMapCompiler\MapData\MapEntity\CMapEnt_World.h

#ifndef CMapEnt_World_h
#define CMapEnt_World_h 1

//## begin module%3CDE328B016C.additionalIncludes preserve=no
//## end module%3CDE328B016C.additionalIncludes

//## begin module%3CDE328B016C.includes preserve=yes
//## end module%3CDE328B016C.includes

// CMapEntity
#include "Tools\GEMapCompiler\MapData\MapEntity\CMapEntity.h"
// GammaE_E3D
#include "E3D\GammaE_E3D.h"
//## begin module%3CDE328B016C.additionalDeclarations preserve=yes
//## end module%3CDE328B016C.additionalDeclarations


//## begin CMapEnt_World%3CDE328B016C.preface preserve=yes
//## end CMapEnt_World%3CDE328B016C.preface

//## Class: CMapEnt_World%3CDE328B016C
//## Category: Tools::GEMapCompiler::MapData::MapEntity%3C7428F80364
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3CF9D7AB01A2;GammaE_E3D { -> }

class CMapEnt_World : public CMapEntity  //## Inherits: <unnamed>%3CDE32950379
{
  //## begin CMapEnt_World%3CDE328B016C.initialDeclarations preserve=yes
  //## end CMapEnt_World%3CDE328B016C.initialDeclarations

  public:
    //## Constructors (generated)
      CMapEnt_World();

    //## Destructor (generated)
      ~CMapEnt_World();

    // Data Members for Class Attributes

      //## Attribute: szWorldFile%3CF9D1F703B5
      //## begin CMapEnt_World::szWorldFile%3CF9D1F703B5.attr preserve=no  public: char [32] {UA} 
      char  szWorldFile[32];
      //## end CMapEnt_World::szWorldFile%3CF9D1F703B5.attr

      //## Attribute: oAmbColor%3CF9D21401CC
      //## begin CMapEnt_World::oAmbColor%3CF9D21401CC.attr preserve=no  public: TFColor {UA} 
      TFColor oAmbColor;
      //## end CMapEnt_World::oAmbColor%3CF9D21401CC.attr

    // Additional Public Declarations
      //## begin CMapEnt_World%3CDE328B016C.public preserve=yes
      //## end CMapEnt_World%3CDE328B016C.public

  protected:
    // Additional Protected Declarations
      //## begin CMapEnt_World%3CDE328B016C.protected preserve=yes
      //## end CMapEnt_World%3CDE328B016C.protected

  private:
    // Additional Private Declarations
      //## begin CMapEnt_World%3CDE328B016C.private preserve=yes
      //## end CMapEnt_World%3CDE328B016C.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CMapEnt_World%3CDE328B016C.implementation preserve=yes
      //## end CMapEnt_World%3CDE328B016C.implementation

};

//## begin CMapEnt_World%3CDE328B016C.postscript preserve=yes
//## end CMapEnt_World%3CDE328B016C.postscript

// Class CMapEnt_World 

//## begin module%3CDE328B016C.epilog preserve=yes
//## end module%3CDE328B016C.epilog


#endif
