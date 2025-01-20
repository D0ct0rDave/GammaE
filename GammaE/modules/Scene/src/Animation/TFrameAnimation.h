//## begin module%3AC4D1520316.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3AC4D1520316.cm

//## begin module%3AC4D1520316.cp preserve=no
//## end module%3AC4D1520316.cp

//## Module: TFrameAnimation%3AC4D1520316; Pseudo Package specification
//## Source file: i:\Projects\GammaE\Scene\Animation\TFrameAnimation.h

#ifndef TFrameAnimation_h
#define TFrameAnimation_h 1

//## begin module%3AC4D1520316.additionalIncludes preserve=no
//## end module%3AC4D1520316.additionalIncludes

//## begin module%3AC4D1520316.includes preserve=yes
//## end module%3AC4D1520316.includes

//## begin module%3AC4D1520316.additionalDeclarations preserve=yes
//## end module%3AC4D1520316.additionalDeclarations


//## begin TFrameAnimation%3AC4D1520316.preface preserve=yes
//## end TFrameAnimation%3AC4D1520316.preface

//## Class: TFrameAnimation%3AC4D1520316
//## Category: Scene::Animation%3BA297A00326
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class TFrameAnimation 
{
  //## begin TFrameAnimation%3AC4D1520316.initialDeclarations preserve=yes
  //## end TFrameAnimation%3AC4D1520316.initialDeclarations

  public:
    //## Constructors (generated)
      TFrameAnimation();

    //## Destructor (generated)
      ~TFrameAnimation();

    // Data Members for Class Attributes

      //## Attribute: InitialFrame%3AC4D1760302
      //## begin TFrameAnimation::InitialFrame%3AC4D1760302.attr preserve=no  public: int {UA} 
      int InitialFrame;
      //## end TFrameAnimation::InitialFrame%3AC4D1760302.attr

      //## Attribute: FinalFrame%3AC4D18200BE
      //## begin TFrameAnimation::FinalFrame%3AC4D18200BE.attr preserve=no  public: int {UA} 
      int FinalFrame;
      //## end TFrameAnimation::FinalFrame%3AC4D18200BE.attr

      //## Attribute: FrameTime%3AC4D1850334
      //## begin TFrameAnimation::FrameTime%3AC4D1850334.attr preserve=no  public: float {UA} 
      float FrameTime;
      //## end TFrameAnimation::FrameTime%3AC4D1850334.attr

      //## Attribute: TotalTime%3AC5E71503AC
      //## begin TFrameAnimation::TotalTime%3AC5E71503AC.attr preserve=no  public: float {UA} 
      float TotalTime;
      //## end TFrameAnimation::TotalTime%3AC5E71503AC.attr

      //## Attribute: bLoop%3BA51FAB0180
      //## begin TFrameAnimation::bLoop%3BA51FAB0180.attr preserve=no  public: bool {UA} 
      bool bLoop;
      //## end TFrameAnimation::bLoop%3BA51FAB0180.attr

    // Additional Public Declarations
      //## begin TFrameAnimation%3AC4D1520316.public preserve=yes
      //## end TFrameAnimation%3AC4D1520316.public

  protected:
    // Additional Protected Declarations
      //## begin TFrameAnimation%3AC4D1520316.protected preserve=yes
      //## end TFrameAnimation%3AC4D1520316.protected

  private:
    // Additional Private Declarations
      //## begin TFrameAnimation%3AC4D1520316.private preserve=yes
      //## end TFrameAnimation%3AC4D1520316.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin TFrameAnimation%3AC4D1520316.implementation preserve=yes
      //## end TFrameAnimation%3AC4D1520316.implementation

};

//## begin TFrameAnimation%3AC4D1520316.postscript preserve=yes
//## end TFrameAnimation%3AC4D1520316.postscript

// Class TFrameAnimation 

//## begin module%3AC4D1520316.epilog preserve=yes
//## end module%3AC4D1520316.epilog


#endif
