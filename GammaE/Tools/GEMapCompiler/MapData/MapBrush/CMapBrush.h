//## begin module%3C7423B10131.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3C7423B10131.cm

//## begin module%3C7423B10131.cp preserve=no
//## end module%3C7423B10131.cp

//## Module: CMapBrush%3C7423B10131; Pseudo Package specification
//## Source file: i:\Projects\GammaE\Tools\GEMapCompiler\MapData\MapBrush\CMapBrush.h

#ifndef CMapBrush_h
#define CMapBrush_h 1

//## begin module%3C7423B10131.additionalIncludes preserve=no
//## end module%3C7423B10131.additionalIncludes

//## begin module%3C7423B10131.includes preserve=yes
//## end module%3C7423B10131.includes

// CMapBrushSide
#include "Tools\GEMapCompiler\MapData\MapBrush\CMapBrushSide.h"
//## begin module%3C7423B10131.additionalDeclarations preserve=yes
//## end module%3C7423B10131.additionalDeclarations


//## begin CMapBrush%3C7423B10131.preface preserve=yes
//## end CMapBrush%3C7423B10131.preface

//## Class: CMapBrush%3C7423B10131
//## Category: Tools::GEMapCompiler::MapData::MapBrush%3C7428C100BC
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CMapBrush 
{
  //## begin CMapBrush%3C7423B10131.initialDeclarations preserve=yes
  //## end CMapBrush%3C7423B10131.initialDeclarations

  public:
    //## Constructors (generated)
      CMapBrush();

    //## Destructor (generated)
      ~CMapBrush();


    //## Other Operations (specified)
      //## Operation: AddBrushSide%1014246303
      void AddBrushSide (CMapBrushSide &_roBrushSide);

    // Data Members for Class Attributes

      //## Attribute: iNumBSides%3C7427AB012B
      //## begin CMapBrush::iNumBSides%3C7427AB012B.attr preserve=no  public: int {UA} 0
      int iNumBSides;
      //## end CMapBrush::iNumBSides%3C7427AB012B.attr

    // Data Members for Associations

      //## Association: Tools::GEMapCompiler::MapData::<unnamed>%3C74266C02E5
      //## Role: CMapBrush::poBSides%3C74266C032C
      //## begin CMapBrush::poBSides%3C74266C032C.role preserve=no  public: CMapBrushSide { -> RHAN}
      CMapBrushSide *poBSides;
      //## end CMapBrush::poBSides%3C74266C032C.role

    // Additional Public Declarations
      //## begin CMapBrush%3C7423B10131.public preserve=yes
      //## end CMapBrush%3C7423B10131.public

  protected:
    // Additional Protected Declarations
      //## begin CMapBrush%3C7423B10131.protected preserve=yes
      //## end CMapBrush%3C7423B10131.protected

  private:
    // Additional Private Declarations
      //## begin CMapBrush%3C7423B10131.private preserve=yes
      //## end CMapBrush%3C7423B10131.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CMapBrush%3C7423B10131.implementation preserve=yes
      //## end CMapBrush%3C7423B10131.implementation

};

//## begin CMapBrush%3C7423B10131.postscript preserve=yes
//## end CMapBrush%3C7423B10131.postscript

// Class CMapBrush 

//## begin module%3C7423B10131.epilog preserve=yes
//## end module%3C7423B10131.epilog


#endif
