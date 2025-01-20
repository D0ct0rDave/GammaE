//## begin module%3BA51C77000F.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3BA51C77000F.cm

//## begin module%3BA51C77000F.cp preserve=no
//## end module%3BA51C77000F.cp

//## Module: CObject3D_AnimCfgGen%3BA51C77000F; Pseudo Package specification
//## Source file: i:\Projects\GammaE\Scene\Animation\CObject3D_AnimCfgGen.h

#ifndef CObject3D_AnimCfgGen_h
#define CObject3D_AnimCfgGen_h 1

//## begin module%3BA51C77000F.additionalIncludes preserve=no
//## end module%3BA51C77000F.additionalIncludes

//## begin module%3BA51C77000F.includes preserve=yes
//## end module%3BA51C77000F.includes

// CObject3D
#include "Scene\CObject3D.h"
//## begin module%3BA51C77000F.additionalDeclarations preserve=yes
//## end module%3BA51C77000F.additionalDeclarations


//## begin CObject3D_AnimCfgGen%3BA51C77000F.preface preserve=yes
//## end CObject3D_AnimCfgGen%3BA51C77000F.preface

//## Class: CObject3D_AnimCfgGen%3BA51C77000F
//## Category: Scene::Animation%3BA297A00326
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CObject3D_AnimCfgGen : public CObject3D  //## Inherits: <unnamed>%3BA51C99014E
{
  //## begin CObject3D_AnimCfgGen%3BA51C77000F.initialDeclarations preserve=yes
  //## end CObject3D_AnimCfgGen%3BA51C77000F.initialDeclarations

  public:
    //## Constructors (generated)
      CObject3D_AnimCfgGen();

    //## Destructor (generated)
      virtual ~CObject3D_AnimCfgGen();


    //## Other Operations (specified)
      //## Operation: SetFrameAnim%1000676443
      virtual void SetFrameAnim (int iFrameAnim) = 0;

    // Additional Public Declarations
      //## begin CObject3D_AnimCfgGen%3BA51C77000F.public preserve=yes
      //## end CObject3D_AnimCfgGen%3BA51C77000F.public

  protected:
    // Additional Protected Declarations
      //## begin CObject3D_AnimCfgGen%3BA51C77000F.protected preserve=yes
      //## end CObject3D_AnimCfgGen%3BA51C77000F.protected

  private:
    // Additional Private Declarations
      //## begin CObject3D_AnimCfgGen%3BA51C77000F.private preserve=yes
      //## end CObject3D_AnimCfgGen%3BA51C77000F.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CObject3D_AnimCfgGen%3BA51C77000F.implementation preserve=yes
      //## end CObject3D_AnimCfgGen%3BA51C77000F.implementation

};

//## begin CObject3D_AnimCfgGen%3BA51C77000F.postscript preserve=yes
//## end CObject3D_AnimCfgGen%3BA51C77000F.postscript

// Class CObject3D_AnimCfgGen 

//## begin module%3BA51C77000F.epilog preserve=yes
//## end module%3BA51C77000F.epilog


#endif
