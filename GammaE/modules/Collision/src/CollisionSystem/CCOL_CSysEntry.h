//## begin module%3C0C1B8A014B.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3C0C1B8A014B.cm

//## begin module%3C0C1B8A014B.cp preserve=no
//## end module%3C0C1B8A014B.cp

//## Module: CCOL_CSysEntry%3C0C1B8A014B; Pseudo Package specification
//## Source file: i:\Projects\GammaE\Collision\CollisionSystem\CCOL_CSysEntry.h

#ifndef CCOL_CSysEntry_h
#define CCOL_CSysEntry_h 1

//## begin module%3C0C1B8A014B.additionalIncludes preserve=no
//## end module%3C0C1B8A014B.additionalIncludes

//## begin module%3C0C1B8A014B.includes preserve=yes
//## end module%3C0C1B8A014B.includes

// CCOL_Collider
#include "Collision\Collider\CCOL_Collider.h"
//## begin module%3C0C1B8A014B.additionalDeclarations preserve=yes
//## end module%3C0C1B8A014B.additionalDeclarations


//## begin CCOL_CSysEntry%3C0C1B8A014B.preface preserve=yes
//## end CCOL_CSysEntry%3C0C1B8A014B.preface

//## Class: CCOL_CSysEntry%3C0C1B8A014B
//## Category: Collision::CollisionSystem%3B6F1B480370
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CCOL_CSysEntry 
{
  //## begin CCOL_CSysEntry%3C0C1B8A014B.initialDeclarations preserve=yes
  //## end CCOL_CSysEntry%3C0C1B8A014B.initialDeclarations

  public:
    //## Constructors (generated)
      CCOL_CSysEntry();

    //## Destructor (generated)
      ~CCOL_CSysEntry();


    //## Other Operations (specified)
      //## Operation: Tested%1007421149
      void Tested (int _iIdx);

      //## Operation: bTested%1007421150
      bool bTested (int _iIdx);

      //## Operation: Init%1007421151
      void Init (int _iNumTests);

      //## Operation: Reset%1007421152
      void Reset ();

    // Data Members for Associations

      //## Association: Collision::CollisionSystem::<unnamed>%3C0C1B96026B
      //## Role: CCOL_CSysEntry::ColObj%3C0C1B97023B
      //## begin CCOL_CSysEntry::ColObj%3C0C1B97023B.role preserve=no  public: CCOL_Collider { -> RHAN}
      CCOL_Collider *ColObj;
      //## end CCOL_CSysEntry::ColObj%3C0C1B97023B.role

    // Additional Public Declarations
      //## begin CCOL_CSysEntry%3C0C1B8A014B.public preserve=yes
      //## end CCOL_CSysEntry%3C0C1B8A014B.public

  protected:
    // Additional Protected Declarations
      //## begin CCOL_CSysEntry%3C0C1B8A014B.protected preserve=yes
      //## end CCOL_CSysEntry%3C0C1B8A014B.protected

  private:
    // Data Members for Class Attributes

      //## Attribute: pbTested%3C0C1BA80270
      //## begin CCOL_CSysEntry::pbTested%3C0C1BA80270.attr preserve=no  private: bool * {UA} NULL
      bool *pbTested;
      //## end CCOL_CSysEntry::pbTested%3C0C1BA80270.attr

      //## Attribute: iNumTests%3C0C1C830261
      //## begin CCOL_CSysEntry::iNumTests%3C0C1C830261.attr preserve=no  private: int {UA} 0
      int iNumTests;
      //## end CCOL_CSysEntry::iNumTests%3C0C1C830261.attr

    // Additional Private Declarations
      //## begin CCOL_CSysEntry%3C0C1B8A014B.private preserve=yes
      //## end CCOL_CSysEntry%3C0C1B8A014B.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CCOL_CSysEntry%3C0C1B8A014B.implementation preserve=yes
      //## end CCOL_CSysEntry%3C0C1B8A014B.implementation

};

//## begin CCOL_CSysEntry%3C0C1B8A014B.postscript preserve=yes
//## end CCOL_CSysEntry%3C0C1B8A014B.postscript

// Class CCOL_CSysEntry 

//## begin module%3C0C1B8A014B.epilog preserve=yes
//## end module%3C0C1B8A014B.epilog


#endif
