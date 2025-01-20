//## begin module%3C321D0D033F.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3C321D0D033F.cm

//## begin module%3C321D0D033F.cp preserve=no
//## end module%3C321D0D033F.cp

//## Module: SCNUt_AdjTriList%3C321D0D033F; Pseudo Package specification
//## Source file: i:\Projects\GammaE\Scene\SceneUtils\ScnStripifier\SCNUt_AdjTriList.h

#ifndef SCNUt_AdjTriList_h
#define SCNUt_AdjTriList_h 1

//## begin module%3C321D0D033F.additionalIncludes preserve=no
//## end module%3C321D0D033F.additionalIncludes

//## begin module%3C321D0D033F.includes preserve=yes
//## end module%3C321D0D033F.includes

// SCNUt_AdjTri
#include "Scene\SceneUtils\ScnStripifier\SCNUt_AdjTri.h"
//## begin module%3C321D0D033F.additionalDeclarations preserve=yes
//## end module%3C321D0D033F.additionalDeclarations


//## begin SCNUt_AdjTriList%3C321D0D033F.preface preserve=yes
//## end SCNUt_AdjTriList%3C321D0D033F.preface

//## Class: SCNUt_AdjTriList%3C321D0D033F
//## Category: Scene::SceneUtils::ScnStripifier%3C308123036F
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class SCNUt_AdjTriList 
{
  //## begin SCNUt_AdjTriList%3C321D0D033F.initialDeclarations preserve=yes
  //## end SCNUt_AdjTriList%3C321D0D033F.initialDeclarations

  public:
    //## Constructors (generated)
      SCNUt_AdjTriList();

    //## Destructor (generated)
      ~SCNUt_AdjTriList();


    //## Other Operations (specified)
      //## Operation: Init%1009917118
      void Init (int _iNumTris);

    // Data Members for Class Attributes

      //## Attribute: iNumTris%3C321D67035D
      //## begin SCNUt_AdjTriList::iNumTris%3C321D67035D.attr preserve=no  public: int {UA} 0
      int iNumTris;
      //## end SCNUt_AdjTriList::iNumTris%3C321D67035D.attr

    // Data Members for Associations

      //## Association: Scene::SceneUtils::ScnStripifier::<unnamed>%3C321D1701B3
      //## Role: SCNUt_AdjTriList::Tri%3C321D1801AC
      //## begin SCNUt_AdjTriList::Tri%3C321D1801AC.role preserve=no  public: SCNUt_AdjTri { -> RHAN}
      SCNUt_AdjTri *Tri;
      //## end SCNUt_AdjTriList::Tri%3C321D1801AC.role

    // Additional Public Declarations
      //## begin SCNUt_AdjTriList%3C321D0D033F.public preserve=yes
      //## end SCNUt_AdjTriList%3C321D0D033F.public

  protected:
    // Additional Protected Declarations
      //## begin SCNUt_AdjTriList%3C321D0D033F.protected preserve=yes
      //## end SCNUt_AdjTriList%3C321D0D033F.protected

  private:
    // Additional Private Declarations
      //## begin SCNUt_AdjTriList%3C321D0D033F.private preserve=yes
      //## end SCNUt_AdjTriList%3C321D0D033F.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin SCNUt_AdjTriList%3C321D0D033F.implementation preserve=yes
      //## end SCNUt_AdjTriList%3C321D0D033F.implementation

};

//## begin SCNUt_AdjTriList%3C321D0D033F.postscript preserve=yes
//## end SCNUt_AdjTriList%3C321D0D033F.postscript

// Class SCNUt_AdjTriList 

//## begin module%3C321D0D033F.epilog preserve=yes
//## end module%3C321D0D033F.epilog


#endif
