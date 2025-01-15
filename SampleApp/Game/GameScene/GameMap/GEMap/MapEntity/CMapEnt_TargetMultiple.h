//## begin module%3CDD23D4024C.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3CDD23D4024C.cm

//## begin module%3CDD23D4024C.cp preserve=no
//## end module%3CDD23D4024C.cp

//## Module: CMapEnt_TargetMultiple%3CDD23D4024C; Pseudo Package specification
//## Source file: i:\Projects\GammaE\Tools\GEMapCompiler\MapData\MapEntity\CMapEnt_TargetMultiple.h

#ifndef CMapEnt_TargetMultiple_h
#define CMapEnt_TargetMultiple_h 1

//## begin module%3CDD23D4024C.additionalIncludes preserve=no
//## end module%3CDD23D4024C.additionalIncludes

//## begin module%3CDD23D4024C.includes preserve=yes
#include "Misc/GammaE_Misc.h"
//## end module%3CDD23D4024C.includes

// CMapEnt_Target
#include "Tools\GEMapCompiler\MapData\MapEntity\CMapEnt_Target.h"
//## begin module%3CDD23D4024C.additionalDeclarations preserve=yes
//## end module%3CDD23D4024C.additionalDeclarations


//## begin CMapEnt_TargetMultiple%3CDD23D4024C.preface preserve=yes
//## end CMapEnt_TargetMultiple%3CDD23D4024C.preface

//## Class: CMapEnt_TargetMultiple%3CDD23D4024C
//## Category: Tools::GEMapCompiler::MapData::MapEntity%3C7428F80364
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CMapEnt_TargetMultiple : public CMapEnt_Target  //## Inherits: <unnamed>%3CDD23E203E7
{
  //## begin CMapEnt_TargetMultiple%3CDD23D4024C.initialDeclarations preserve=yes
  //## end CMapEnt_TargetMultiple%3CDD23D4024C.initialDeclarations

  public:
    //## Constructors (generated)
      CMapEnt_TargetMultiple();

    //## Destructor (generated)
      ~CMapEnt_TargetMultiple();

    // Data Members for Associations

      //## Association: Tools::GEMapCompiler::MapData::MapEntity::<unnamed>%3CDD23E90383
      //## Role: CMapEnt_TargetMultiple::aoTargets%3CDD23EB03B9
      //## begin CMapEnt_TargetMultiple::aoTargets%3CDD23EB03B9.role preserve=no  public: CMapEnt_Target { -> UHAN}
      CDynArray <CMapEnt_Target*> aoTargets;
      //## end CMapEnt_TargetMultiple::aoTargets%3CDD23EB03B9.role

    // Additional Public Declarations
      //## begin CMapEnt_TargetMultiple%3CDD23D4024C.public preserve=yes
      //## end CMapEnt_TargetMultiple%3CDD23D4024C.public

  protected:
    // Additional Protected Declarations
      //## begin CMapEnt_TargetMultiple%3CDD23D4024C.protected preserve=yes
      //## end CMapEnt_TargetMultiple%3CDD23D4024C.protected

  private:
    // Additional Private Declarations
      //## begin CMapEnt_TargetMultiple%3CDD23D4024C.private preserve=yes
      //## end CMapEnt_TargetMultiple%3CDD23D4024C.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CMapEnt_TargetMultiple%3CDD23D4024C.implementation preserve=yes
      //## end CMapEnt_TargetMultiple%3CDD23D4024C.implementation

};

//## begin CMapEnt_TargetMultiple%3CDD23D4024C.postscript preserve=yes
//## end CMapEnt_TargetMultiple%3CDD23D4024C.postscript

// Class CMapEnt_TargetMultiple 

//## begin module%3CDD23D4024C.epilog preserve=yes
//## end module%3CDD23D4024C.epilog


#endif
