//## begin module%3BD719670126.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3BD719670126.cm

//## begin module%3BD719670126.cp preserve=no
//## end module%3BD719670126.cp

//## Module: CE3D_Projector%3BD719670126; Pseudo Package specification
//## Source file: i:\Projects\GammaE\E3D\Viewing\Projector\CE3D_Projector.h

#ifndef CE3D_Projector_h
#define CE3D_Projector_h 1

//## begin module%3BD719670126.additionalIncludes preserve=no
//## end module%3BD719670126.additionalIncludes

//## begin module%3BD719670126.includes preserve=yes
//## end module%3BD719670126.includes

// eE3D_ProjectorType
#include "E3D\Viewing\Projector\eE3D_ProjectorType.h"
//## begin module%3BD719670126.additionalDeclarations preserve=yes
//## end module%3BD719670126.additionalDeclarations


//## begin CE3D_Projector%3BD719670126.preface preserve=yes
//## end CE3D_Projector%3BD719670126.preface

//## Class: CE3D_Projector%3BD719670126
//## Category: E3D::Viewing::Projector%3BD7195601D6
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CE3D_Projector 
{
  //## begin CE3D_Projector%3BD719670126.initialDeclarations preserve=yes
  //## end CE3D_Projector%3BD719670126.initialDeclarations

  public:
    //## Constructors (generated)
      CE3D_Projector();

    //## Destructor (generated)
      ~CE3D_Projector();

    // Data Members for Class Attributes

      //## Attribute: fFOV%3BD71A500239
      //## begin CE3D_Projector::fFOV%3BD71A500239.attr preserve=no  public: float {UA} 60.0f
      float fFOV;
      //## end CE3D_Projector::fFOV%3BD71A500239.attr

      //## Attribute: fNear%3BD71A5B0253
      //## begin CE3D_Projector::fNear%3BD71A5B0253.attr preserve=no  public: float {UA} 1.0f
      float fNear;
      //## end CE3D_Projector::fNear%3BD71A5B0253.attr

      //## Attribute: fFar%3BD71A6003CD
      //## begin CE3D_Projector::fFar%3BD71A6003CD.attr preserve=no  public: float {UA} 2000.0f
      float fFar;
      //## end CE3D_Projector::fFar%3BD71A6003CD.attr

    // Data Members for Associations

      //## Association: E3D::Viewing::Projector::<unnamed>%3BD71A120320
      //## Role: CE3D_Projector::ePrjType%3BD71A1300A2
      //## begin CE3D_Projector::ePrjType%3BD71A1300A2.role preserve=no  public: eE3D_ProjectorType { -> VHAN}
      eE3D_ProjectorType ePrjType;
      //## end CE3D_Projector::ePrjType%3BD71A1300A2.role

    // Additional Public Declarations
      //## begin CE3D_Projector%3BD719670126.public preserve=yes
      //## end CE3D_Projector%3BD719670126.public

  protected:
    // Additional Protected Declarations
      //## begin CE3D_Projector%3BD719670126.protected preserve=yes
      //## end CE3D_Projector%3BD719670126.protected

  private:
    // Additional Private Declarations
      //## begin CE3D_Projector%3BD719670126.private preserve=yes
      //## end CE3D_Projector%3BD719670126.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CE3D_Projector%3BD719670126.implementation preserve=yes
      //## end CE3D_Projector%3BD719670126.implementation

};

//## begin CE3D_Projector%3BD719670126.postscript preserve=yes
//## end CE3D_Projector%3BD719670126.postscript

// Class CE3D_Projector 

//## begin module%3BD719670126.epilog preserve=yes
//## end module%3BD719670126.epilog


#endif
