//## begin module%3CDCDF9603A2.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3CDCDF9603A2.cm

//## begin module%3CDCDF9603A2.cp preserve=no
//## end module%3CDCDF9603A2.cp

//## Module: CMapEnt_Target%3CDCDF9603A2; Pseudo Package specification
//## Source file: i:\Projects\GammaE\Tools\GEMapCompiler\MapData\MapEntity\CMapEnt_Target.h

#ifndef CMapEnt_Target_h
#define CMapEnt_Target_h 1

//## begin module%3CDCDF9603A2.additionalIncludes preserve=no
//## end module%3CDCDF9603A2.additionalIncludes

//## begin module%3CDCDF9603A2.includes preserve=yes
//## end module%3CDCDF9603A2.includes

// CMapEnt_TriggerMode
#include "Tools\GEMapCompiler\MapData\MapEntity\CMapEnt_TriggerMode.h"
// CMapEntity
#include "Tools\GEMapCompiler\MapData\MapEntity\CMapEntity.h"
// CMapEnt_TargetType
#include "Tools\GEMapCompiler\MapData\MapEntity\CMapEnt_TargetType.h"
//## begin module%3CDCDF9603A2.additionalDeclarations preserve=yes
//## end module%3CDCDF9603A2.additionalDeclarations


//## begin CMapEnt_Target%3CDCDF9603A2.preface preserve=yes
//## end CMapEnt_Target%3CDCDF9603A2.preface

//## Class: CMapEnt_Target%3CDCDF9603A2
//## Category: Tools::GEMapCompiler::MapData::MapEntity%3C7428F80364
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CMapEnt_Target : public CMapEntity  //## Inherits: <unnamed>%3CDCE02B02A2
{
  //## begin CMapEnt_Target%3CDCDF9603A2.initialDeclarations preserve=yes
  //## end CMapEnt_Target%3CDCDF9603A2.initialDeclarations

  public:
    //## Constructors (generated)
      CMapEnt_Target();

    //## Destructor (generated)
      ~CMapEnt_Target();

    // Data Members for Class Attributes

      //## Attribute: szName%3CDCE08C0067
      //## begin CMapEnt_Target::szName%3CDCE08C0067.attr preserve=no  public: char[32] {UA} 
      char szName[32];
      //## end CMapEnt_Target::szName%3CDCE08C0067.attr

    // Data Members for Associations

      //## Association: Tools::GEMapCompiler::MapData::MapEntity::<unnamed>%3CDC0E8F00E0
      //## Role: CMapEnt_Target::eType%3CDC0E8F01C6
      //## begin CMapEnt_Target::eType%3CDC0E8F01C6.role preserve=no  public: CMapEnt_TargetType { -> UHAN}
      CMapEnt_TargetType eType;
      //## end CMapEnt_Target::eType%3CDC0E8F01C6.role

      //## Association: Tools::GEMapCompiler::MapData::MapEntity::<unnamed>%3CDAFCFF0357
      //## Role: CMapEnt_Target::eTriggerMode%3CDAFD00010A
      //## begin CMapEnt_Target::eTriggerMode%3CDAFD00010A.role preserve=no  public: CMapEnt_TriggerMode { -> UHAN}
      CMapEnt_TriggerMode eTriggerMode;
      //## end CMapEnt_Target::eTriggerMode%3CDAFD00010A.role

    // Additional Public Declarations
      //## begin CMapEnt_Target%3CDCDF9603A2.public preserve=yes
      //## end CMapEnt_Target%3CDCDF9603A2.public

  protected:
    // Additional Protected Declarations
      //## begin CMapEnt_Target%3CDCDF9603A2.protected preserve=yes
      //## end CMapEnt_Target%3CDCDF9603A2.protected

  private:
    // Additional Private Declarations
      //## begin CMapEnt_Target%3CDCDF9603A2.private preserve=yes
      //## end CMapEnt_Target%3CDCDF9603A2.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CMapEnt_Target%3CDCDF9603A2.implementation preserve=yes
      //## end CMapEnt_Target%3CDCDF9603A2.implementation

};

//## begin CMapEnt_Target%3CDCDF9603A2.postscript preserve=yes
//## end CMapEnt_Target%3CDCDF9603A2.postscript

// Class CMapEnt_Target 

//## begin module%3CDCDF9603A2.epilog preserve=yes
//## end module%3CDCDF9603A2.epilog


#endif
