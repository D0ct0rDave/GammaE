//## begin module%3B76DDEF02D0.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3B76DDEF02D0.cm

//## begin module%3B76DDEF02D0.cp preserve=no
//## end module%3B76DDEF02D0.cp

//## Module: CSoundReceiver%3B76DDEF02D0; Pseudo Package specification
//## Source file: i:\Projects\GammaE\SoundSystem\SoundRender\CSoundReceiver.h

#ifndef CSoundReceiver_h
#define CSoundReceiver_h 1

//## begin module%3B76DDEF02D0.additionalIncludes preserve=no
//## end module%3B76DDEF02D0.additionalIncludes

//## begin module%3B76DDEF02D0.includes preserve=yes
//## end module%3B76DDEF02D0.includes

// CSoundEntity
#include "SoundSystem\SoundRender\CSoundEntity.h"
//## begin module%3B76DDEF02D0.additionalDeclarations preserve=yes
//## end module%3B76DDEF02D0.additionalDeclarations


//## begin CSoundReceiver%3B76DDEF02D0.preface preserve=yes
//## end CSoundReceiver%3B76DDEF02D0.preface

//## Class: CSoundReceiver%3B76DDEF02D0
//## Category: SoundSystem::SoundRender%3B76FFA20393
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CSoundReceiver : public CSoundEntity  //## Inherits: <unnamed>%3C7F8EC4031E
{
  //## begin CSoundReceiver%3B76DDEF02D0.initialDeclarations preserve=yes
  //## end CSoundReceiver%3B76DDEF02D0.initialDeclarations

  public:
    //## Constructors (generated)
      CSoundReceiver();

    //## Destructor (generated)
      ~CSoundReceiver();

    // Data Members for Class Attributes

      //## Attribute: Dir%3BB64C92030D
      //## begin CSoundReceiver::Dir%3BB64C92030D.attr preserve=no  public: CVect3 {UA} 
      CVect3 Dir;
      //## end CSoundReceiver::Dir%3BB64C92030D.attr

      //## Attribute: Up%3BBA2F6C005B
      //## begin CSoundReceiver::Up%3BBA2F6C005B.attr preserve=no  public: CVect3 {UA} 
      CVect3 Up;
      //## end CSoundReceiver::Up%3BBA2F6C005B.attr

      //## Attribute: Side%3C828B1900DE
      //## begin CSoundReceiver::Side%3C828B1900DE.attr preserve=no  public: CVect3 {UA} 
      CVect3 Side;
      //## end CSoundReceiver::Side%3C828B1900DE.attr

      //## Attribute: fSensitivity%3BB7102F00F2
      //## begin CSoundReceiver::fSensitivity%3BB7102F00F2.attr preserve=no  public: float {UA} 
      float fSensitivity;
      //## end CSoundReceiver::fSensitivity%3BB7102F00F2.attr

    // Additional Public Declarations
      //## begin CSoundReceiver%3B76DDEF02D0.public preserve=yes
      //## end CSoundReceiver%3B76DDEF02D0.public

  protected:
    // Additional Protected Declarations
      //## begin CSoundReceiver%3B76DDEF02D0.protected preserve=yes
      //## end CSoundReceiver%3B76DDEF02D0.protected

  private:
    // Additional Private Declarations
      //## begin CSoundReceiver%3B76DDEF02D0.private preserve=yes
      //## end CSoundReceiver%3B76DDEF02D0.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CSoundReceiver%3B76DDEF02D0.implementation preserve=yes
      //## end CSoundReceiver%3B76DDEF02D0.implementation

};

//## begin CSoundReceiver%3B76DDEF02D0.postscript preserve=yes
//## end CSoundReceiver%3B76DDEF02D0.postscript

// Class CSoundReceiver 

//## begin module%3B76DDEF02D0.epilog preserve=yes
//## end module%3B76DDEF02D0.epilog


#endif
