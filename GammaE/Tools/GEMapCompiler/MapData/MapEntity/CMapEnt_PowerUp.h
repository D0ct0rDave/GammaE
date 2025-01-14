//## begin module%3C7EB7BA00E0.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3C7EB7BA00E0.cm

//## begin module%3C7EB7BA00E0.cp preserve=no
//## end module%3C7EB7BA00E0.cp

//## Module: CMapEnt_PowerUp%3C7EB7BA00E0; Pseudo Package specification
//## Source file: i:\Projects\GammaE\Tools\GEMapCompiler\MapData\MapEntity\CMapEnt_PowerUp.h

#ifndef CMapEnt_PowerUp_h
#define CMapEnt_PowerUp_h 1

//## begin module%3C7EB7BA00E0.additionalIncludes preserve=no
//## end module%3C7EB7BA00E0.additionalIncludes

//## begin module%3C7EB7BA00E0.includes preserve=yes
//## end module%3C7EB7BA00E0.includes

// CMapEnt_Target
#include "Tools\GEMapCompiler\MapData\MapEntity\CMapEnt_Target.h"
//## begin module%3C7EB7BA00E0.additionalDeclarations preserve=yes
//## end module%3C7EB7BA00E0.additionalDeclarations


//## begin CMapEnt_PowerUp%3C7EB7BA00E0.preface preserve=yes
//## end CMapEnt_PowerUp%3C7EB7BA00E0.preface

//## Class: CMapEnt_PowerUp%3C7EB7BA00E0
//## Category: Tools::GEMapCompiler::MapData::MapEntity%3C7428F80364
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CMapEnt_PowerUp : public CMapEnt_Target  //## Inherits: <unnamed>%3CDCE03802E7
{
  //## begin CMapEnt_PowerUp%3C7EB7BA00E0.initialDeclarations preserve=yes
  //## end CMapEnt_PowerUp%3C7EB7BA00E0.initialDeclarations

  public:
    //## Constructors (generated)
      CMapEnt_PowerUp();

    //## Destructor (generated)
      ~CMapEnt_PowerUp();

    // Data Members for Class Attributes

      //## Attribute: oPos%3C7EB7C7028D
      //## begin CMapEnt_PowerUp::oPos%3C7EB7C7028D.attr preserve=no  public: CVect3 {UA} 
      CVect3 oPos;
      //## end CMapEnt_PowerUp::oPos%3C7EB7C7028D.attr

      //## Attribute: iType%3C7EB7CC0045
      //## begin CMapEnt_PowerUp::iType%3C7EB7CC0045.attr preserve=no  public: int {UA} 
      int iType;
      //## end CMapEnt_PowerUp::iType%3C7EB7CC0045.attr

    // Additional Public Declarations
      //## begin CMapEnt_PowerUp%3C7EB7BA00E0.public preserve=yes
      //## end CMapEnt_PowerUp%3C7EB7BA00E0.public

  protected:
    // Additional Protected Declarations
      //## begin CMapEnt_PowerUp%3C7EB7BA00E0.protected preserve=yes
      //## end CMapEnt_PowerUp%3C7EB7BA00E0.protected

  private:
    // Additional Private Declarations
      //## begin CMapEnt_PowerUp%3C7EB7BA00E0.private preserve=yes
      //## end CMapEnt_PowerUp%3C7EB7BA00E0.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CMapEnt_PowerUp%3C7EB7BA00E0.implementation preserve=yes
      //## end CMapEnt_PowerUp%3C7EB7BA00E0.implementation

};

//## begin CMapEnt_PowerUp%3C7EB7BA00E0.postscript preserve=yes
//## end CMapEnt_PowerUp%3C7EB7BA00E0.postscript

// Class CMapEnt_PowerUp 

//## begin module%3C7EB7BA00E0.epilog preserve=yes
//## end module%3C7EB7BA00E0.epilog


#endif
