//## begin module%3C7423D90034.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3C7423D90034.cm

//## begin module%3C7423D90034.cp preserve=no
//## end module%3C7423D90034.cp

//## Module: CMapBrushSide%3C7423D90034; Pseudo Package specification
//## Source file: i:\Projects\GammaE\Tools\GEMapCompiler\MapData\MapBrush\CMapBrushSide.h

#ifndef CMapBrushSide_h
#define CMapBrushSide_h 1

//## begin module%3C7423D90034.additionalIncludes preserve=no
//## end module%3C7423D90034.additionalIncludes

//## begin module%3C7423D90034.includes preserve=yes
//## end module%3C7423D90034.includes

// GammaE_Math
#include "Math\GammaE_Math.h"
//## begin module%3C7423D90034.additionalDeclarations preserve=yes
//## end module%3C7423D90034.additionalDeclarations


//## begin CMapBrushSide%3C7423D90034.preface preserve=yes
//## end CMapBrushSide%3C7423D90034.preface

//## Class: CMapBrushSide%3C7423D90034
//## Category: Tools::GEMapCompiler::MapData::MapBrush%3C7428C100BC
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3C742F0803CA;GammaE_Math { -> }

class CMapBrushSide 
{
  //## begin CMapBrushSide%3C7423D90034.initialDeclarations preserve=yes
  //## end CMapBrushSide%3C7423D90034.initialDeclarations

  public:
    //## Constructors (generated)
      CMapBrushSide();

    //## Destructor (generated)
      ~CMapBrushSide();

    // Data Members for Class Attributes

      //## Attribute: oVecs%3C74259F03E4
      //## begin CMapBrushSide::oVecs%3C74259F03E4.attr preserve=no  public: CVect3[3] {UA} 
      CVect3 oVecs[3];
      //## end CMapBrushSide::oVecs%3C74259F03E4.attr

      //## Attribute: oPlane%3C7425A502CA
      //## begin CMapBrushSide::oPlane%3C7425A502CA.attr preserve=no  public: CPlane {UA} 
      CPlane oPlane;
      //## end CMapBrushSide::oPlane%3C7425A502CA.attr

      //## Attribute: szTex%3C7425C80130
      //## begin CMapBrushSide::szTex%3C7425C80130.attr preserve=no  public: char [80] {UA} 
      char  szTex[80];
      //## end CMapBrushSide::szTex%3C7425C80130.attr

      //## Attribute: iTex%3C76E3190142
      //## begin CMapBrushSide::iTex%3C76E3190142.attr preserve=no  public: int {UA} 
      int iTex;
      //## end CMapBrushSide::iTex%3C76E3190142.attr

      //## Attribute: fAngle%3C7AA61D0049
      //## begin CMapBrushSide::fAngle%3C7AA61D0049.attr preserve=no  public: float {UA} 
      float fAngle;
      //## end CMapBrushSide::fAngle%3C7AA61D0049.attr

      //## Attribute: fUOfs%3C7AA65C03B1
      //## begin CMapBrushSide::fUOfs%3C7AA65C03B1.attr preserve=no  public: float {UA} 
      float fUOfs;
      //## end CMapBrushSide::fUOfs%3C7AA65C03B1.attr

      //## Attribute: fVOfs%3C7AA632022A
      //## begin CMapBrushSide::fVOfs%3C7AA632022A.attr preserve=no  public: float {UA} 
      float fVOfs;
      //## end CMapBrushSide::fVOfs%3C7AA632022A.attr

      //## Attribute: fUScale%3C7AA62302DC
      //## begin CMapBrushSide::fUScale%3C7AA62302DC.attr preserve=no  public: float {UA} 
      float fUScale;
      //## end CMapBrushSide::fUScale%3C7AA62302DC.attr

      //## Attribute: fVScale%3C7AA62A02F0
      //## begin CMapBrushSide::fVScale%3C7AA62A02F0.attr preserve=no  public: float {UA} 
      float fVScale;
      //## end CMapBrushSide::fVScale%3C7AA62A02F0.attr

      //## Attribute: iTexW%3C7CC13B009A
      //## begin CMapBrushSide::iTexW%3C7CC13B009A.attr preserve=no  public: int {UA} 
      int iTexW;
      //## end CMapBrushSide::iTexW%3C7CC13B009A.attr

      //## Attribute: iTexH%3C7CC141037D
      //## begin CMapBrushSide::iTexH%3C7CC141037D.attr preserve=no  public: int {UA} 
      int iTexH;
      //## end CMapBrushSide::iTexH%3C7CC141037D.attr

    // Additional Public Declarations
      //## begin CMapBrushSide%3C7423D90034.public preserve=yes
      //## end CMapBrushSide%3C7423D90034.public

  protected:
    // Additional Protected Declarations
      //## begin CMapBrushSide%3C7423D90034.protected preserve=yes
      //## end CMapBrushSide%3C7423D90034.protected

  private:
    // Additional Private Declarations
      //## begin CMapBrushSide%3C7423D90034.private preserve=yes
      //## end CMapBrushSide%3C7423D90034.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CMapBrushSide%3C7423D90034.implementation preserve=yes
      //## end CMapBrushSide%3C7423D90034.implementation

};

//## begin CMapBrushSide%3C7423D90034.postscript preserve=yes
//## end CMapBrushSide%3C7423D90034.postscript

// Class CMapBrushSide 

//## begin module%3C7423D90034.epilog preserve=yes
//## end module%3C7423D90034.epilog


#endif
