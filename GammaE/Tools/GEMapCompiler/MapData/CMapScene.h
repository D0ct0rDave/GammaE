//## begin module%3C7423860247.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3C7423860247.cm

//## begin module%3C7423860247.cp preserve=no
//## end module%3C7423860247.cp

//## Module: CMapScene%3C7423860247; Pseudo Package specification
//## Source file: i:\Projects\GammaE\Tools\GEMapCompiler\MapData\CMapScene.h

#ifndef CMapScene_h
#define CMapScene_h 1

//## begin module%3C7423860247.additionalIncludes preserve=no
//## end module%3C7423860247.additionalIncludes

//## begin module%3C7423860247.includes preserve=yes
//## end module%3C7423860247.includes

// CMapEntity
#include "Tools\GEMapCompiler\MapData\MapEntity\CMapEntity.h"
// CMapBrush
#include "Tools\GEMapCompiler\MapData\MapBrush\CMapBrush.h"
//## begin module%3C7423860247.additionalDeclarations preserve=yes
//## end module%3C7423860247.additionalDeclarations


//## begin CMapScene%3C7423860247.preface preserve=yes
//## end CMapScene%3C7423860247.preface

//## Class: CMapScene%3C7423860247
//## Category: Tools::GEMapCompiler::MapData%3C741F390140
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CMapScene 
{
  //## begin CMapScene%3C7423860247.initialDeclarations preserve=yes
  //## end CMapScene%3C7423860247.initialDeclarations

  public:
    //## Constructors (generated)
      CMapScene();

    //## Destructor (generated)
      ~CMapScene();


    //## Other Operations (specified)
      //## Operation: AddEntity%1014246304
      void AddEntity (CMapEntity* _poMapEntity);

      //## Operation: AddBrush%1014246305
      void AddBrush (CMapBrush *_poBrush);

    // Data Members for Class Attributes

      //## Attribute: iNumBrushes%3C7427B402D2
      //## begin CMapScene::iNumBrushes%3C7427B402D2.attr preserve=no  public: int {UA} 0
      int iNumBrushes;
      //## end CMapScene::iNumBrushes%3C7427B402D2.attr

      //## Attribute: iNumEntities%3C7427B9010D
      //## begin CMapScene::iNumEntities%3C7427B9010D.attr preserve=no  public: int {UA} 0
      int iNumEntities;
      //## end CMapScene::iNumEntities%3C7427B9010D.attr

    // Data Members for Associations

      //## Association: Tools::GEMapCompiler::MapData::<unnamed>%3C74271B0106
      //## Role: CMapScene::poBrush%3C74271B0247
      //## begin CMapScene::poBrush%3C74271B0247.role preserve=no  public: CMapBrush { -> RHAN}
      CMapBrush **poBrush;
      //## end CMapScene::poBrush%3C74271B0247.role

      //## Association: Tools::GEMapCompiler::MapData::<unnamed>%3C74272D00A7
      //## Role: CMapScene::poEntity%3C74272D0243
      //## begin CMapScene::poEntity%3C74272D0243.role preserve=no  public: CMapEntity { -> RHAN}
      CMapEntity **poEntity;
      //## end CMapScene::poEntity%3C74272D0243.role

    // Additional Public Declarations
      //## begin CMapScene%3C7423860247.public preserve=yes
      //## end CMapScene%3C7423860247.public

  protected:
    // Additional Protected Declarations
      //## begin CMapScene%3C7423860247.protected preserve=yes
      //## end CMapScene%3C7423860247.protected

  private:
    // Additional Private Declarations
      //## begin CMapScene%3C7423860247.private preserve=yes
      //## end CMapScene%3C7423860247.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CMapScene%3C7423860247.implementation preserve=yes
      //## end CMapScene%3C7423860247.implementation

};

//## begin CMapScene%3C7423860247.postscript preserve=yes
//## end CMapScene%3C7423860247.postscript

// Class CMapScene 

//## begin module%3C7423860247.epilog preserve=yes
//## end module%3C7423860247.epilog


#endif
