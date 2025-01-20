//## begin module%3C7F8EC1036A.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3C7F8EC1036A.cm

//## begin module%3C7F8EC1036A.cp preserve=no
//## end module%3C7F8EC1036A.cp

//## Module: CSoundEntity%3C7F8EC1036A; Pseudo Package specification
//## Source file: i:\Projects\GammaE\SoundSystem\SoundRender\CSoundEntity.h

#ifndef CSoundEntity_h
#define CSoundEntity_h 1

//## begin module%3C7F8EC1036A.additionalIncludes preserve=no
//## end module%3C7F8EC1036A.additionalIncludes

//## begin module%3C7F8EC1036A.includes preserve=yes
//## end module%3C7F8EC1036A.includes

// GammaE_Math
#include "Math\GammaE_Math.h"
//## begin module%3C7F8EC1036A.additionalDeclarations preserve=yes
//## end module%3C7F8EC1036A.additionalDeclarations


//## begin CSoundEntity%3C7F8EC1036A.preface preserve=yes
//## end CSoundEntity%3C7F8EC1036A.preface

//## Class: CSoundEntity%3C7F8EC1036A
//## Category: SoundSystem::SoundRender%3B76FFA20393
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3C7F9161035C;GammaE_Math { -> }

class CSoundEntity 
{
  //## begin CSoundEntity%3C7F8EC1036A.initialDeclarations preserve=yes
  //## end CSoundEntity%3C7F8EC1036A.initialDeclarations

  public:
    //## Constructors (generated)
      CSoundEntity();

    //## Destructor (generated)
      ~CSoundEntity();

    // Data Members for Class Attributes

      //## Attribute: Pos%3C7F8EC1036B
      //## begin CSoundEntity::Pos%3C7F8EC1036B.attr preserve=no  public: CVect3 {UA} 
      CVect3 Pos;
      //## end CSoundEntity::Pos%3C7F8EC1036B.attr

      //## Attribute: Speed%3C7F8EC1036C
      //## begin CSoundEntity::Speed%3C7F8EC1036C.attr preserve=no  public: CVect3 {UA} 
      CVect3 Speed;
      //## end CSoundEntity::Speed%3C7F8EC1036C.attr

    // Additional Public Declarations
      //## begin CSoundEntity%3C7F8EC1036A.public preserve=yes
      //## end CSoundEntity%3C7F8EC1036A.public

  protected:
    // Additional Protected Declarations
      //## begin CSoundEntity%3C7F8EC1036A.protected preserve=yes
      //## end CSoundEntity%3C7F8EC1036A.protected

  private:
    // Additional Private Declarations
      //## begin CSoundEntity%3C7F8EC1036A.private preserve=yes
      //## end CSoundEntity%3C7F8EC1036A.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CSoundEntity%3C7F8EC1036A.implementation preserve=yes
      //## end CSoundEntity%3C7F8EC1036A.implementation

};

//## begin CSoundEntity%3C7F8EC1036A.postscript preserve=yes
//## end CSoundEntity%3C7F8EC1036A.postscript

// Class CSoundEntity 

//## begin module%3C7F8EC1036A.epilog preserve=yes
//## end module%3C7F8EC1036A.epilog


#endif
