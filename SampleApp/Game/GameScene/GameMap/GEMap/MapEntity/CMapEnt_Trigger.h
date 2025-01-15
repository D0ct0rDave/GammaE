//## begin module%3CDAFAA102B6.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3CDAFAA102B6.cm

//## begin module%3CDAFAA102B6.cp preserve=no
//## end module%3CDAFAA102B6.cp

//## Module: CMapEnt_Trigger%3CDAFAA102B6; Pseudo Package specification
//## Source file: i:\Projects\GammaE\Tools\GEMapCompiler\MapData\MapEntity\CMapEnt_Trigger.h

#ifndef CMapEnt_Trigger_h
#define CMapEnt_Trigger_h 1

//## begin module%3CDAFAA102B6.additionalIncludes preserve=no
//## end module%3CDAFAA102B6.additionalIncludes

//## begin module%3CDAFAA102B6.includes preserve=yes
//## end module%3CDAFAA102B6.includes

// CMapBrush
#include "Tools\GEMapCompiler\MapData\MapBrush\CMapBrush.h"
// CMapEnt_Target
#include "Tools\GEMapCompiler\MapData\MapEntity\CMapEnt_Target.h"
//## begin module%3CDAFAA102B6.additionalDeclarations preserve=yes
//## end module%3CDAFAA102B6.additionalDeclarations


//## begin CMapEnt_Trigger%3CDAFAA102B6.preface preserve=yes
//## end CMapEnt_Trigger%3CDAFAA102B6.preface

//## Class: CMapEnt_Trigger%3CDAFAA102B6
//## Category: Tools::GEMapCompiler::MapData::MapEntity%3C7428F80364
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3CDC09BB0309;CMapBrush { -> }

class CMapEnt_Trigger : public CMapEnt_Target  //## Inherits: <unnamed>%3CDCE014012D
{
  //## begin CMapEnt_Trigger%3CDAFAA102B6.initialDeclarations preserve=yes
  //## end CMapEnt_Trigger%3CDAFAA102B6.initialDeclarations

  public:
    //## Constructors (generated)
      CMapEnt_Trigger();

    //## Destructor (generated)
      ~CMapEnt_Trigger();

    // Data Members for Class Attributes

      //## Attribute: szTargetName%3CDAFAAE0391
      //## begin CMapEnt_Trigger::szTargetName%3CDAFAAE0391.attr preserve=no  public: char[32] {UA} 
      char szTargetName[32];
      //## end CMapEnt_Trigger::szTargetName%3CDAFAAE0391.attr

      //## Attribute: szSecTarget%3CDCDD28013B
      //## begin CMapEnt_Trigger::szSecTarget%3CDCDD28013B.attr preserve=no  public: char[32] {UA} 
      char szSecTarget[32];
      //## end CMapEnt_Trigger::szSecTarget%3CDCDD28013B.attr

      //## Attribute: iTargetIdx%3CDAFAD10305
      //## begin CMapEnt_Trigger::iTargetIdx%3CDAFAD10305.attr preserve=no  public: int {UA} -1
      int iTargetIdx;
      //## end CMapEnt_Trigger::iTargetIdx%3CDAFAD10305.attr

      //## Attribute: poBrush%3CDC050C01D9
      //## begin CMapEnt_Trigger::poBrush%3CDC050C01D9.attr preserve=no  public: CMapBrush * {UA} 
      CMapBrush *poBrush;
      //## end CMapEnt_Trigger::poBrush%3CDC050C01D9.attr

      //## Attribute: oMax%3CDD32F402FE
      //## begin CMapEnt_Trigger::oMax%3CDD32F402FE.attr preserve=no  public: CVect3 {UA} 
      CVect3 oMax;
      //## end CMapEnt_Trigger::oMax%3CDD32F402FE.attr

      //## Attribute: oMin%3CDD32FA00EA
      //## begin CMapEnt_Trigger::oMin%3CDD32FA00EA.attr preserve=no  public: CVect3 {UA} 
      CVect3 oMin;
      //## end CMapEnt_Trigger::oMin%3CDD32FA00EA.attr

    // Additional Public Declarations
      //## begin CMapEnt_Trigger%3CDAFAA102B6.public preserve=yes
      //## end CMapEnt_Trigger%3CDAFAA102B6.public

  protected:
    // Additional Protected Declarations
      //## begin CMapEnt_Trigger%3CDAFAA102B6.protected preserve=yes
      //## end CMapEnt_Trigger%3CDAFAA102B6.protected

  private:
    // Additional Private Declarations
      //## begin CMapEnt_Trigger%3CDAFAA102B6.private preserve=yes
      //## end CMapEnt_Trigger%3CDAFAA102B6.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CMapEnt_Trigger%3CDAFAA102B6.implementation preserve=yes
      //## end CMapEnt_Trigger%3CDAFAA102B6.implementation

};

//## begin CMapEnt_Trigger%3CDAFAA102B6.postscript preserve=yes
//## end CMapEnt_Trigger%3CDAFAA102B6.postscript

// Class CMapEnt_Trigger 

//## begin module%3CDAFAA102B6.epilog preserve=yes
//## end module%3CDAFAA102B6.epilog


#endif
