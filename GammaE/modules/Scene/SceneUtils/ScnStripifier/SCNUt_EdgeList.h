//## begin module%3C3082000041.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3C3082000041.cm

//## begin module%3C3082000041.cp preserve=no
//## end module%3C3082000041.cp

//## Module: SCNUt_EdgeList%3C3082000041; Pseudo Package specification
//## Source file: i:\Projects\GammaE\Scene\SceneUtils\ScnStripifier\SCNUt_EdgeList.h

#ifndef SCNUt_EdgeList_h
#define SCNUt_EdgeList_h 1

//## begin module%3C3082000041.additionalIncludes preserve=no
//## end module%3C3082000041.additionalIncludes

//## begin module%3C3082000041.includes preserve=yes
//## end module%3C3082000041.includes

// SCNUt_Edge
#include "Scene\SceneUtils\ScnStripifier\SCNUt_Edge.h"
//## begin module%3C3082000041.additionalDeclarations preserve=yes
//## end module%3C3082000041.additionalDeclarations


//## begin SCNUt_EdgeList%3C3082000041.preface preserve=yes
//## end SCNUt_EdgeList%3C3082000041.preface

//## Class: SCNUt_EdgeList%3C3082000041
//## Category: Scene::SceneUtils::ScnStripifier%3C308123036F
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class SCNUt_EdgeList 
{
  //## begin SCNUt_EdgeList%3C3082000041.initialDeclarations preserve=yes
  //## end SCNUt_EdgeList%3C3082000041.initialDeclarations

  public:
    //## Constructors (generated)
      SCNUt_EdgeList();

    //## Destructor (generated)
      ~SCNUt_EdgeList();


    //## Other Operations (specified)
      //## Operation: iAdd%1009811894
      int iAdd (SCNUt_Edge& _roEdge);

      //## Operation: Clear%1009811895
      void Clear ();

    // Data Members for Class Attributes

      //## Attribute: iNumEdges%3C308225032A
      //## begin SCNUt_EdgeList::iNumEdges%3C308225032A.attr preserve=no  public: int {UA} 0
      int iNumEdges;
      //## end SCNUt_EdgeList::iNumEdges%3C308225032A.attr

    // Data Members for Associations

      //## Association: Scene::SceneUtils::ScnStripifier::<unnamed>%3C30820C01BB
      //## Role: SCNUt_EdgeList::Edge%3C30820D00A5
      //## begin SCNUt_EdgeList::Edge%3C30820D00A5.role preserve=no  public: SCNUt_Edge { -> RHAN}
      SCNUt_Edge *Edge;
      //## end SCNUt_EdgeList::Edge%3C30820D00A5.role

    // Additional Public Declarations
      //## begin SCNUt_EdgeList%3C3082000041.public preserve=yes
      //## end SCNUt_EdgeList%3C3082000041.public

  protected:
    // Additional Protected Declarations
      //## begin SCNUt_EdgeList%3C3082000041.protected preserve=yes
      //## end SCNUt_EdgeList%3C3082000041.protected

  private:
    // Data Members for Class Attributes

      //## Attribute: iMaxEdges%3C30837D013A
      //## begin SCNUt_EdgeList::iMaxEdges%3C30837D013A.attr preserve=no  private: int {UA} 0
      int iMaxEdges;
      //## end SCNUt_EdgeList::iMaxEdges%3C30837D013A.attr

    // Additional Private Declarations
      //## begin SCNUt_EdgeList%3C3082000041.private preserve=yes
      //## end SCNUt_EdgeList%3C3082000041.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin SCNUt_EdgeList%3C3082000041.implementation preserve=yes
      //## end SCNUt_EdgeList%3C3082000041.implementation

};

//## begin SCNUt_EdgeList%3C3082000041.postscript preserve=yes
//## end SCNUt_EdgeList%3C3082000041.postscript

// Class SCNUt_EdgeList 

//## begin module%3C3082000041.epilog preserve=yes
//## end module%3C3082000041.epilog


#endif
