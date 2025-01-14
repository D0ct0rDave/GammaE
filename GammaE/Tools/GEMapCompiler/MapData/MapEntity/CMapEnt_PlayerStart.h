//## begin module%3CA6EB400208.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3CA6EB400208.cm

//## begin module%3CA6EB400208.cp preserve=no
//## end module%3CA6EB400208.cp

//## Module: CMapEnt_PlayerStart%3CA6EB400208; Pseudo Package specification
//## Source file: i:\Projects\GammaE\Tools\GEMapCompiler\MapData\MapEntity\CMapEnt_PlayerStart.h

#ifndef CMapEnt_PlayerStart_h
#define CMapEnt_PlayerStart_h 1

//## begin module%3CA6EB400208.additionalIncludes preserve=no
//## end module%3CA6EB400208.additionalIncludes

//## begin module%3CA6EB400208.includes preserve=yes
//## end module%3CA6EB400208.includes

// CMapEntity
#include "Tools\GEMapCompiler\MapData\MapEntity\CMapEntity.h"
//## begin module%3CA6EB400208.additionalDeclarations preserve=yes
//## end module%3CA6EB400208.additionalDeclarations


//## begin CMapEnt_PlayerStart%3CA6EB400208.preface preserve=yes
//## end CMapEnt_PlayerStart%3CA6EB400208.preface

//## Class: CMapEnt_PlayerStart%3CA6EB400208
//## Category: Tools::GEMapCompiler::MapData::MapEntity%3C7428F80364
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CMapEnt_PlayerStart : public CMapEntity  //## Inherits: <unnamed>%3CA6EB4F00E8
{
  //## begin CMapEnt_PlayerStart%3CA6EB400208.initialDeclarations preserve=yes
  //## end CMapEnt_PlayerStart%3CA6EB400208.initialDeclarations

  public:
    //## Constructors (generated)
      CMapEnt_PlayerStart();

    //## Destructor (generated)
      ~CMapEnt_PlayerStart();

    // Data Members for Class Attributes

      //## Attribute: oPos%3CA6EB5603E1
      //## begin CMapEnt_PlayerStart::oPos%3CA6EB5603E1.attr preserve=no  public: CVect3 {UA} 
      CVect3 oPos;
      //## end CMapEnt_PlayerStart::oPos%3CA6EB5603E1.attr

      //## Attribute: iType%3CA6EB5A022E
      //## begin CMapEnt_PlayerStart::iType%3CA6EB5A022E.attr preserve=no  public: int {UA} 
      int iType;
      //## end CMapEnt_PlayerStart::iType%3CA6EB5A022E.attr

    // Additional Public Declarations
      //## begin CMapEnt_PlayerStart%3CA6EB400208.public preserve=yes
      //## end CMapEnt_PlayerStart%3CA6EB400208.public

  protected:
    // Additional Protected Declarations
      //## begin CMapEnt_PlayerStart%3CA6EB400208.protected preserve=yes
      //## end CMapEnt_PlayerStart%3CA6EB400208.protected

  private:
    // Additional Private Declarations
      //## begin CMapEnt_PlayerStart%3CA6EB400208.private preserve=yes
      //## end CMapEnt_PlayerStart%3CA6EB400208.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CMapEnt_PlayerStart%3CA6EB400208.implementation preserve=yes
      //## end CMapEnt_PlayerStart%3CA6EB400208.implementation

};

//## begin CMapEnt_PlayerStart%3CA6EB400208.postscript preserve=yes
//## end CMapEnt_PlayerStart%3CA6EB400208.postscript

// Class CMapEnt_PlayerStart 

//## begin module%3CA6EB400208.epilog preserve=yes
//## end module%3CA6EB400208.epilog


#endif
