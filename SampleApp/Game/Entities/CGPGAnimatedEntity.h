//## begin module%3CD6F1AF0109.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3CD6F1AF0109.cm

//## begin module%3CD6F1AF0109.cp preserve=no
//## end module%3CD6F1AF0109.cp

//## Module: CGPGAnimatedEntity%3CD6F1AF0109; Pseudo Package specification
//## Source file: i:\Projects\GammaE\Game\Entities\CGPGAnimatedEntity.h

#ifndef CGPGAnimatedEntity_h
#define CGPGAnimatedEntity_h 1

//## begin module%3CD6F1AF0109.additionalIncludes preserve=no
//## end module%3CD6F1AF0109.additionalIncludes

//## begin module%3CD6F1AF0109.includes preserve=yes
//## end module%3CD6F1AF0109.includes

// CGPGraphicEntity
#include "Game\Entities\CGPGraphicEntity.h"
//## begin module%3CD6F1AF0109.additionalDeclarations preserve=yes
//## end module%3CD6F1AF0109.additionalDeclarations


//## begin CGPGAnimatedEntity%3CD6F1AF0109.preface preserve=yes
//## end CGPGAnimatedEntity%3CD6F1AF0109.preface

//## Class: CGPGAnimatedEntity%3CD6F1AF0109
//## Category: Game::Entities%3B5DE99E0136
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CGPGAnimatedEntity : public CGPGraphicEntity  //## Inherits: <unnamed>%3CD6F5D702B7
{
  //## begin CGPGAnimatedEntity%3CD6F1AF0109.initialDeclarations preserve=yes
  //## end CGPGAnimatedEntity%3CD6F1AF0109.initialDeclarations

  public:
    //## Constructors (generated)
      CGPGAnimatedEntity();

    //## Destructor (generated)
      ~CGPGAnimatedEntity();

    // Additional Public Declarations
      //## begin CGPGAnimatedEntity%3CD6F1AF0109.public preserve=yes
      //## end CGPGAnimatedEntity%3CD6F1AF0109.public

  protected:
    // Data Members for Class Attributes

      //## Attribute: poMesh%3CD6F6530099
      //## begin CGPGAnimatedEntity::poMesh%3CD6F6530099.attr preserve=no  protected: CObject3D_AnimCfgGen * {UA} 
      CObject3D_AnimCfgGen *poMesh;
      //## end CGPGAnimatedEntity::poMesh%3CD6F6530099.attr

    // Additional Protected Declarations
      //## begin CGPGAnimatedEntity%3CD6F1AF0109.protected preserve=yes
      //## end CGPGAnimatedEntity%3CD6F1AF0109.protected

  private:
    // Additional Private Declarations
      //## begin CGPGAnimatedEntity%3CD6F1AF0109.private preserve=yes
      //## end CGPGAnimatedEntity%3CD6F1AF0109.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CGPGAnimatedEntity%3CD6F1AF0109.implementation preserve=yes
      //## end CGPGAnimatedEntity%3CD6F1AF0109.implementation

};

//## begin CGPGAnimatedEntity%3CD6F1AF0109.postscript preserve=yes
//## end CGPGAnimatedEntity%3CD6F1AF0109.postscript

// Class CGPGAnimatedEntity 

//## begin module%3CD6F1AF0109.epilog preserve=yes
//## end module%3CD6F1AF0109.epilog


#endif
