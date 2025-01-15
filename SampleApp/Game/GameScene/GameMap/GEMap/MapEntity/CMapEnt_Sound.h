//## begin module%3C742B0501F7.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3C742B0501F7.cm

//## begin module%3C742B0501F7.cp preserve=no
//## end module%3C742B0501F7.cp

//## Module: CMapEnt_Sound%3C742B0501F7; Pseudo Package specification
//## Source file: i:\Projects\GammaE\Tools\GEMapCompiler\MapData\MapEntity\CMapEnt_Sound.h

#ifndef CMapEnt_Sound_h
#define CMapEnt_Sound_h 1

//## begin module%3C742B0501F7.additionalIncludes preserve=no
//## end module%3C742B0501F7.additionalIncludes

//## begin module%3C742B0501F7.includes preserve=yes
//## end module%3C742B0501F7.includes

// CMapEnt_Target
#include "Tools\GEMapCompiler\MapData\MapEntity\CMapEnt_Target.h"
//## begin module%3C742B0501F7.additionalDeclarations preserve=yes
//## end module%3C742B0501F7.additionalDeclarations


//## begin CMapEnt_Sound%3C742B0501F7.preface preserve=yes
//## end CMapEnt_Sound%3C742B0501F7.preface

//## Class: CMapEnt_Sound%3C742B0501F7
//## Category: Tools::GEMapCompiler::MapData::MapEntity%3C7428F80364
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CMapEnt_Sound : public CMapEnt_Target  //## Inherits: <unnamed>%3CDCDFFA0248
{
  //## begin CMapEnt_Sound%3C742B0501F7.initialDeclarations preserve=yes
  //## end CMapEnt_Sound%3C742B0501F7.initialDeclarations

  public:
    //## Constructors (generated)
      CMapEnt_Sound();

    //## Destructor (generated)
      ~CMapEnt_Sound();

    // Data Members for Class Attributes

      //## Attribute: oPos%3C742B13011B
      //## begin CMapEnt_Sound::oPos%3C742B13011B.attr preserve=no  public: CVect3 {UA} 
      CVect3 oPos;
      //## end CMapEnt_Sound::oPos%3C742B13011B.attr

      //## Attribute: szFileName%3C742B170275
      //## begin CMapEnt_Sound::szFileName%3C742B170275.attr preserve=no  public: char[64] {UA} 
      char szFileName[64];
      //## end CMapEnt_Sound::szFileName%3C742B170275.attr

      //## Attribute: iType%3C742B2F0125
      //## begin CMapEnt_Sound::iType%3C742B2F0125.attr preserve=no  public: int {UA} 0
      int iType;
      //## end CMapEnt_Sound::iType%3C742B2F0125.attr

    // Additional Public Declarations
      //## begin CMapEnt_Sound%3C742B0501F7.public preserve=yes
      //## end CMapEnt_Sound%3C742B0501F7.public

  protected:
    // Additional Protected Declarations
      //## begin CMapEnt_Sound%3C742B0501F7.protected preserve=yes
      //## end CMapEnt_Sound%3C742B0501F7.protected

  private:
    // Additional Private Declarations
      //## begin CMapEnt_Sound%3C742B0501F7.private preserve=yes
      //## end CMapEnt_Sound%3C742B0501F7.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CMapEnt_Sound%3C742B0501F7.implementation preserve=yes
      //## end CMapEnt_Sound%3C742B0501F7.implementation

};

//## begin CMapEnt_Sound%3C742B0501F7.postscript preserve=yes
//## end CMapEnt_Sound%3C742B0501F7.postscript

// Class CMapEnt_Sound 

//## begin module%3C742B0501F7.epilog preserve=yes
//## end module%3C742B0501F7.epilog


#endif
