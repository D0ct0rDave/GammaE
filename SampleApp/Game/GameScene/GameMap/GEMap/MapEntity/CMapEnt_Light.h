//## begin module%3C742A5E02F1.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3C742A5E02F1.cm

//## begin module%3C742A5E02F1.cp preserve=no
//## end module%3C742A5E02F1.cp

//## Module: CMapEnt_Light%3C742A5E02F1; Pseudo Package specification
//## Source file: i:\Projects\GammaE\Tools\GEMapCompiler\MapData\MapEntity\CMapEnt_Light.h

#ifndef CMapEnt_Light_h
#define CMapEnt_Light_h 1

//## begin module%3C742A5E02F1.additionalIncludes preserve=no
//## end module%3C742A5E02F1.additionalIncludes

//## begin module%3C742A5E02F1.includes preserve=yes
//## end module%3C742A5E02F1.includes

// GammaE_E3D
#include "E3D\GammaE_E3D.h"
// CMapEnt_Target
#include "Tools\GEMapCompiler\MapData\MapEntity\CMapEnt_Target.h"
//## begin module%3C742A5E02F1.additionalDeclarations preserve=yes
//## end module%3C742A5E02F1.additionalDeclarations


//## begin CMapEnt_Light%3C742A5E02F1.preface preserve=yes
//## end CMapEnt_Light%3C742A5E02F1.preface

//## Class: CMapEnt_Light%3C742A5E02F1
//## Category: Tools::GEMapCompiler::MapData::MapEntity%3C7428F80364
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3C83F2DE023B;GammaE_E3D { -> }

class CMapEnt_Light : public CMapEnt_Target  //## Inherits: <unnamed>%3CDCDFF8021D
{
  //## begin CMapEnt_Light%3C742A5E02F1.initialDeclarations preserve=yes
  //## end CMapEnt_Light%3C742A5E02F1.initialDeclarations

  public:
    //## Constructors (generated)
      CMapEnt_Light();

    //## Destructor (generated)
      ~CMapEnt_Light();

    // Data Members for Class Attributes

      //## Attribute: oPos%3C742AED0329
      //## begin CMapEnt_Light::oPos%3C742AED0329.attr preserve=no  public: CVect3 {UA} 
      CVect3 oPos;
      //## end CMapEnt_Light::oPos%3C742AED0329.attr

      //## Attribute: Color%3C83F11201D5
      //## begin CMapEnt_Light::Color%3C83F11201D5.attr preserve=no  public: TFColor {UA} 
      TFColor Color;
      //## end CMapEnt_Light::Color%3C83F11201D5.attr

      //## Attribute: iType%3C742AF4012A
      //## begin CMapEnt_Light::iType%3C742AF4012A.attr preserve=no  public: int {UA} 0
      int iType;
      //## end CMapEnt_Light::iType%3C742AF4012A.attr

      //## Attribute: fRadius%3C86646202CB
      //## begin CMapEnt_Light::fRadius%3C86646202CB.attr preserve=no  public: float {UA} 
      float fRadius;
      //## end CMapEnt_Light::fRadius%3C86646202CB.attr

      //## Attribute: oDir%3C8664670264
      //## begin CMapEnt_Light::oDir%3C8664670264.attr preserve=no  public: CVect3 {UA} 
      CVect3 oDir;
      //## end CMapEnt_Light::oDir%3C8664670264.attr

    // Additional Public Declarations
      //## begin CMapEnt_Light%3C742A5E02F1.public preserve=yes
      //## end CMapEnt_Light%3C742A5E02F1.public

  protected:
    // Additional Protected Declarations
      //## begin CMapEnt_Light%3C742A5E02F1.protected preserve=yes
      //## end CMapEnt_Light%3C742A5E02F1.protected

  private:
    // Additional Private Declarations
      //## begin CMapEnt_Light%3C742A5E02F1.private preserve=yes
      //## end CMapEnt_Light%3C742A5E02F1.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CMapEnt_Light%3C742A5E02F1.implementation preserve=yes
      //## end CMapEnt_Light%3C742A5E02F1.implementation

};

//## begin CMapEnt_Light%3C742A5E02F1.postscript preserve=yes
//## end CMapEnt_Light%3C742A5E02F1.postscript

// Class CMapEnt_Light 

//## begin module%3C742A5E02F1.epilog preserve=yes
//## end module%3C742A5E02F1.epilog


#endif
