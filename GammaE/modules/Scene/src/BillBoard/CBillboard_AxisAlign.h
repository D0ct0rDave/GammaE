//## begin module%3AC8FC760122.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3AC8FC760122.cm

//## begin module%3AC8FC760122.cp preserve=no
//## end module%3AC8FC760122.cp

//## Module: CBillboard_AxisAlign%3AC8FC760122; Pseudo Package specification
//## Source file: i:\Projects\GammaE\Scene\Billboard\CBillboard_AxisAlign.h

#ifndef CBillboard_AxisAlign_h
#define CBillboard_AxisAlign_h 1

//## begin module%3AC8FC760122.additionalIncludes preserve=no
//## end module%3AC8FC760122.additionalIncludes

//## begin module%3AC8FC760122.includes preserve=yes
//## end module%3AC8FC760122.includes

// CBillboard
#include "Scene\Billboard\CBillboard.h"
//## begin module%3AC8FC760122.additionalDeclarations preserve=yes
//## end module%3AC8FC760122.additionalDeclarations


//## begin CBillboard_AxisAlign%3AC8FC760122.preface preserve=yes
//## end CBillboard_AxisAlign%3AC8FC760122.preface

//## Class: CBillboard_AxisAlign%3AC8FC760122
//## Category: Scene::Billboard%3AC8FD16033E
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CBillboard_AxisAlign : public CBillboard  //## Inherits: <unnamed>%3AC8FC84023A
{
  //## begin CBillboard_AxisAlign%3AC8FC760122.initialDeclarations preserve=yes
  //## end CBillboard_AxisAlign%3AC8FC760122.initialDeclarations

  public:
    //## Constructors (generated)
      CBillboard_AxisAlign();

    //## Destructor (generated)
      ~CBillboard_AxisAlign();


    //## Other Operations (specified)
      //## Operation: SetAxis%986249628
      void SetAxis (bool x, bool y, bool z);

      //## Operation: Render%986249627
      virtual void Render ();

    // Additional Public Declarations
      //## begin CBillboard_AxisAlign%3AC8FC760122.public preserve=yes
      //## end CBillboard_AxisAlign%3AC8FC760122.public

  protected:
    // Additional Protected Declarations
      //## begin CBillboard_AxisAlign%3AC8FC760122.protected preserve=yes
      //## end CBillboard_AxisAlign%3AC8FC760122.protected

  private:
    // Data Members for Class Attributes

      //## Attribute: Flags%3AC8FF630168
      //## begin CBillboard_AxisAlign::Flags%3AC8FF630168.attr preserve=no  private: int {UA} 
      int Flags;
      //## end CBillboard_AxisAlign::Flags%3AC8FF630168.attr

    // Additional Private Declarations
      //## begin CBillboard_AxisAlign%3AC8FC760122.private preserve=yes
      //## end CBillboard_AxisAlign%3AC8FC760122.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CBillboard_AxisAlign%3AC8FC760122.implementation preserve=yes
      //## end CBillboard_AxisAlign%3AC8FC760122.implementation

};

//## begin CBillboard_AxisAlign%3AC8FC760122.postscript preserve=yes
//## end CBillboard_AxisAlign%3AC8FC760122.postscript

// Class CBillboard_AxisAlign 

//## begin module%3AC8FC760122.epilog preserve=yes
//## end module%3AC8FC760122.epilog


#endif
