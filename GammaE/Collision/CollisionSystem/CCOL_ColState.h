//## begin module%3C2935B60274.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3C2935B60274.cm

//## begin module%3C2935B60274.cp preserve=no
//## end module%3C2935B60274.cp

//## Module: CCOL_ColState%3C2935B60274; Pseudo Package specification
//## Source file: i:\Projects\GammaE\Collision\CollisionSystem\CCOL_ColState.h

#ifndef CCOL_ColState_h
#define CCOL_ColState_h 1

//## begin module%3C2935B60274.additionalIncludes preserve=no
//## end module%3C2935B60274.additionalIncludes

//## begin module%3C2935B60274.includes preserve=yes
//## end module%3C2935B60274.includes

// GammaE_Math
#include "Math\GammaE_Math.h"
//## begin module%3C2935B60274.additionalDeclarations preserve=yes
//## end module%3C2935B60274.additionalDeclarations


//## begin CCOL_ColState%3C2935B60274.preface preserve=yes
//## end CCOL_ColState%3C2935B60274.preface

//## Class: CCOL_ColState%3C2935B60274
//## Category: Collision::CollisionSystem%3B6F1B480370
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3C293D3B03BC;GammaE_Math { -> }

class CCOL_ColState 
{
  //## begin CCOL_ColState%3C2935B60274.initialDeclarations preserve=yes
  //## end CCOL_ColState%3C2935B60274.initialDeclarations

  public:
    //## Constructors (generated)
      CCOL_ColState();

    //## Destructor (generated)
      ~CCOL_ColState();

    // Data Members for Class Attributes

      //## Attribute: SrcIPos%3C2935BC0088
      //## begin CCOL_ColState::SrcIPos%3C2935BC0088.attr preserve=no  public: static CVect3 {UA} 
      static CVect3 SrcIPos;
      //## end CCOL_ColState::SrcIPos%3C2935BC0088.attr

      //## Attribute: SrcFPos%3C2935C10388
      //## begin CCOL_ColState::SrcFPos%3C2935C10388.attr preserve=no  public: static CVect3 {UA} 
      static CVect3 SrcFPos;
      //## end CCOL_ColState::SrcFPos%3C2935C10388.attr

      //## Attribute: DstIPos%3C2935CD015E
      //## begin CCOL_ColState::DstIPos%3C2935CD015E.attr preserve=no  public: static CVect3 {UA} 
      static CVect3 DstIPos;
      //## end CCOL_ColState::DstIPos%3C2935CD015E.attr

      //## Attribute: DstFPos%3C2935D1034F
      //## begin CCOL_ColState::DstFPos%3C2935D1034F.attr preserve=no  public: static CVect3 {UA} 
      static CVect3 DstFPos;
      //## end CCOL_ColState::DstFPos%3C2935D1034F.attr

      //## Attribute: SrcSp%3C2935D60111
      //## begin CCOL_ColState::SrcSp%3C2935D60111.attr preserve=no  public: static CVect3 {UA} 
      static CVect3 SrcSp;
      //## end CCOL_ColState::SrcSp%3C2935D60111.attr

      //## Attribute: DstSp%3C2935DF01FA
      //## begin CCOL_ColState::DstSp%3C2935DF01FA.attr preserve=no  public: static CVect3 {UA} 
      static CVect3 DstSp;
      //## end CCOL_ColState::DstSp%3C2935DF01FA.attr

      //## Attribute: DSSp%3C2935E80167
      //## begin CCOL_ColState::DSSp%3C2935E80167.attr preserve=no  public: static CVect3 {UA} 
      static CVect3 DSSp;
      //## end CCOL_ColState::DSSp%3C2935E80167.attr

      //## Attribute: fDeltaT%3C4DEE3701F1
      //## begin CCOL_ColState::fDeltaT%3C4DEE3701F1.attr preserve=no  public: static float {UA} 
      static float fDeltaT;
      //## end CCOL_ColState::fDeltaT%3C4DEE3701F1.attr

      //## Attribute: fMinColTime%3CC715EF02FA
      //## begin CCOL_ColState::fMinColTime%3CC715EF02FA.attr preserve=no  public: static float {UA} 
      static float fMinColTime;
      //## end CCOL_ColState::fMinColTime%3CC715EF02FA.attr

    // Additional Public Declarations
      //## begin CCOL_ColState%3C2935B60274.public preserve=yes
      //## end CCOL_ColState%3C2935B60274.public

  protected:
    // Additional Protected Declarations
      //## begin CCOL_ColState%3C2935B60274.protected preserve=yes
      //## end CCOL_ColState%3C2935B60274.protected

  private:
    // Additional Private Declarations
      //## begin CCOL_ColState%3C2935B60274.private preserve=yes
      //## end CCOL_ColState%3C2935B60274.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CCOL_ColState%3C2935B60274.implementation preserve=yes
      //## end CCOL_ColState%3C2935B60274.implementation

};

//## begin CCOL_ColState%3C2935B60274.postscript preserve=yes
//## end CCOL_ColState%3C2935B60274.postscript

// Class CCOL_ColState 

//## begin module%3C2935B60274.epilog preserve=yes
//## end module%3C2935B60274.epilog


#endif
