//## begin module%3C742B810173.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3C742B810173.cm

//## begin module%3C742B810173.cp preserve=no
//## end module%3C742B810173.cp

//## Module: CMapEnt_Monster%3C742B810173; Pseudo Package specification
//## Source file: i:\Projects\GammaE\Tools\GEMapCompiler\MapData\MapEntity\CMapEnt_Monster.h

#ifndef CMapEnt_Monster_h
#define CMapEnt_Monster_h 1

//## begin module%3C742B810173.additionalIncludes preserve=no
//## end module%3C742B810173.additionalIncludes

//## begin module%3C742B810173.includes preserve=yes
//## end module%3C742B810173.includes

// CMapEnt_Target
#include "Tools\GEMapCompiler\MapData\MapEntity\CMapEnt_Target.h"
//## begin module%3C742B810173.additionalDeclarations preserve=yes
//## end module%3C742B810173.additionalDeclarations


//## begin CMapEnt_Monster%3C742B810173.preface preserve=yes
//## end CMapEnt_Monster%3C742B810173.preface

//## Class: CMapEnt_Monster%3C742B810173
//## Category: Tools::GEMapCompiler::MapData::MapEntity%3C7428F80364
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CMapEnt_Monster : public CMapEnt_Target  //## Inherits: <unnamed>%3CDCDFFC0395
{
  //## begin CMapEnt_Monster%3C742B810173.initialDeclarations preserve=yes
  //## end CMapEnt_Monster%3C742B810173.initialDeclarations

  public:
    //## Constructors (generated)
      CMapEnt_Monster();

    //## Destructor (generated)
      ~CMapEnt_Monster();

    // Data Members for Class Attributes

      //## Attribute: oPos%3C742B8C02F5
      //## begin CMapEnt_Monster::oPos%3C742B8C02F5.attr preserve=no  public: CVect3 {UA} 
      CVect3 oPos;
      //## end CMapEnt_Monster::oPos%3C742B8C02F5.attr

      //## Attribute: iType%3C742B910112
      //## begin CMapEnt_Monster::iType%3C742B910112.attr preserve=no  public: int {UA} 
      int iType;
      //## end CMapEnt_Monster::iType%3C742B910112.attr

    // Additional Public Declarations
      //## begin CMapEnt_Monster%3C742B810173.public preserve=yes
      //## end CMapEnt_Monster%3C742B810173.public

  protected:
    // Additional Protected Declarations
      //## begin CMapEnt_Monster%3C742B810173.protected preserve=yes
      //## end CMapEnt_Monster%3C742B810173.protected

  private:
    // Additional Private Declarations
      //## begin CMapEnt_Monster%3C742B810173.private preserve=yes
      //## end CMapEnt_Monster%3C742B810173.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CMapEnt_Monster%3C742B810173.implementation preserve=yes
      //## end CMapEnt_Monster%3C742B810173.implementation

};

//## begin CMapEnt_Monster%3C742B810173.postscript preserve=yes
//## end CMapEnt_Monster%3C742B810173.postscript

// Class CMapEnt_Monster 

//## begin module%3C742B810173.epilog preserve=yes
//## end module%3C742B810173.epilog


#endif
