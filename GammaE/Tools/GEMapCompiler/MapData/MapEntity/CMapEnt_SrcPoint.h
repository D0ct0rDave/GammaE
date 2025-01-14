//## begin module%3CDAFC410282.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3CDAFC410282.cm

//## begin module%3CDAFC410282.cp preserve=no
//## end module%3CDAFC410282.cp

//## Module: CMapEnt_SrcPoint%3CDAFC410282; Pseudo Package specification
//## Source file: i:\Projects\GammaE\Tools\GEMapCompiler\MapData\MapEntity\CMapEnt_SrcPoint.h

#ifndef CMapEnt_SrcPoint_h
#define CMapEnt_SrcPoint_h 1

//## begin module%3CDAFC410282.additionalIncludes preserve=no
//## end module%3CDAFC410282.additionalIncludes

//## begin module%3CDAFC410282.includes preserve=yes
//## end module%3CDAFC410282.includes

// CMapEntity
#include "Tools\GEMapCompiler\MapData\MapEntity\CMapEntity.h"
//## begin module%3CDAFC410282.additionalDeclarations preserve=yes
//## end module%3CDAFC410282.additionalDeclarations


//## begin CMapEnt_SrcPoint%3CDAFC410282.preface preserve=yes
//## end CMapEnt_SrcPoint%3CDAFC410282.preface

//## Class: CMapEnt_SrcPoint%3CDAFC410282
//## Category: Tools::GEMapCompiler::MapData::MapEntity%3C7428F80364
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CMapEnt_SrcPoint : public CMapEntity  //## Inherits: <unnamed>%3CDAFCC8033A
{
  //## begin CMapEnt_SrcPoint%3CDAFC410282.initialDeclarations preserve=yes
  //## end CMapEnt_SrcPoint%3CDAFC410282.initialDeclarations

  public:
    //## Constructors (generated)
      CMapEnt_SrcPoint();

    //## Destructor (generated)
      ~CMapEnt_SrcPoint();

    // Data Members for Class Attributes

      //## Attribute: oPos%3CDAFC4C0179
      //## begin CMapEnt_SrcPoint::oPos%3CDAFC4C0179.attr preserve=no  public: CVect3 {UA} 
      CVect3 oPos;
      //## end CMapEnt_SrcPoint::oPos%3CDAFC4C0179.attr

      //## Attribute: szName%3CDAFC5202E0
      //## begin CMapEnt_SrcPoint::szName%3CDAFC5202E0.attr preserve=no  public: char[64] {UA} 
      char szName[64];
      //## end CMapEnt_SrcPoint::szName%3CDAFC5202E0.attr

    // Additional Public Declarations
      //## begin CMapEnt_SrcPoint%3CDAFC410282.public preserve=yes
      //## end CMapEnt_SrcPoint%3CDAFC410282.public

  protected:
    // Additional Protected Declarations
      //## begin CMapEnt_SrcPoint%3CDAFC410282.protected preserve=yes
      //## end CMapEnt_SrcPoint%3CDAFC410282.protected

  private:
    // Additional Private Declarations
      //## begin CMapEnt_SrcPoint%3CDAFC410282.private preserve=yes
      //## end CMapEnt_SrcPoint%3CDAFC410282.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CMapEnt_SrcPoint%3CDAFC410282.implementation preserve=yes
      //## end CMapEnt_SrcPoint%3CDAFC410282.implementation

};

//## begin CMapEnt_SrcPoint%3CDAFC410282.postscript preserve=yes
//## end CMapEnt_SrcPoint%3CDAFC410282.postscript

// Class CMapEnt_SrcPoint 

//## begin module%3CDAFC410282.epilog preserve=yes
//## end module%3CDAFC410282.epilog


#endif
