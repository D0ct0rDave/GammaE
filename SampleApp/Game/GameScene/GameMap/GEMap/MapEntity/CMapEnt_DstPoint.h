//## begin module%3CDAFCAC007D.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3CDAFCAC007D.cm

//## begin module%3CDAFCAC007D.cp preserve=no
//## end module%3CDAFCAC007D.cp

//## Module: CMapEnt_DstPoint%3CDAFCAC007D; Pseudo Package specification
//## Source file: i:\Projects\GammaE\Tools\GEMapCompiler\MapData\MapEntity\CMapEnt_DstPoint.h

#ifndef CMapEnt_DstPoint_h
#define CMapEnt_DstPoint_h 1

//## begin module%3CDAFCAC007D.additionalIncludes preserve=no
//## end module%3CDAFCAC007D.additionalIncludes

//## begin module%3CDAFCAC007D.includes preserve=yes
//## end module%3CDAFCAC007D.includes

// CMapEntity
#include "Tools\GEMapCompiler\MapData\MapEntity\CMapEntity.h"
//## begin module%3CDAFCAC007D.additionalDeclarations preserve=yes
//## end module%3CDAFCAC007D.additionalDeclarations


//## begin CMapEnt_DstPoint%3CDAFCAC007D.preface preserve=yes
//## end CMapEnt_DstPoint%3CDAFCAC007D.preface

//## Class: CMapEnt_DstPoint%3CDAFCAC007D
//## Category: Tools::GEMapCompiler::MapData::MapEntity%3C7428F80364
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CMapEnt_DstPoint : public CMapEntity  //## Inherits: <unnamed>%3CDAFCCC0051
{
  //## begin CMapEnt_DstPoint%3CDAFCAC007D.initialDeclarations preserve=yes
  //## end CMapEnt_DstPoint%3CDAFCAC007D.initialDeclarations

  public:
    //## Constructors (generated)
      CMapEnt_DstPoint();

    //## Destructor (generated)
      ~CMapEnt_DstPoint();

    // Data Members for Class Attributes

      //## Attribute: oPos%3CDAFCB30308
      //## begin CMapEnt_DstPoint::oPos%3CDAFCB30308.attr preserve=no  public: CVect3 {UA} 
      CVect3 oPos;
      //## end CMapEnt_DstPoint::oPos%3CDAFCB30308.attr

      //## Attribute: szName%3CDAFCB90090
      //## begin CMapEnt_DstPoint::szName%3CDAFCB90090.attr preserve=no  public: char[64] {UA} 
      char szName[64];
      //## end CMapEnt_DstPoint::szName%3CDAFCB90090.attr

    // Additional Public Declarations
      //## begin CMapEnt_DstPoint%3CDAFCAC007D.public preserve=yes
      //## end CMapEnt_DstPoint%3CDAFCAC007D.public

  protected:
    // Additional Protected Declarations
      //## begin CMapEnt_DstPoint%3CDAFCAC007D.protected preserve=yes
      //## end CMapEnt_DstPoint%3CDAFCAC007D.protected

  private:
    // Additional Private Declarations
      //## begin CMapEnt_DstPoint%3CDAFCAC007D.private preserve=yes
      //## end CMapEnt_DstPoint%3CDAFCAC007D.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CMapEnt_DstPoint%3CDAFCAC007D.implementation preserve=yes
      //## end CMapEnt_DstPoint%3CDAFCAC007D.implementation

};

//## begin CMapEnt_DstPoint%3CDAFCAC007D.postscript preserve=yes
//## end CMapEnt_DstPoint%3CDAFCAC007D.postscript

// Class CMapEnt_DstPoint 

//## begin module%3CDAFCAC007D.epilog preserve=yes
//## end module%3CDAFCAC007D.epilog


#endif
