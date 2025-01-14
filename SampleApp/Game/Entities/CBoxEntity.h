//## begin module%3C06CBDC022D.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3C06CBDC022D.cm

//## begin module%3C06CBDC022D.cp preserve=no
//## end module%3C06CBDC022D.cp

//## Module: CBoxEntity%3C06CBDC022D; Pseudo Package specification
//## Source file: i:\Projects\GammaE\Game\Entities\CBoxEntity.h

#ifndef CBoxEntity_h
#define CBoxEntity_h 1

//## begin module%3C06CBDC022D.additionalIncludes preserve=no
//## end module%3C06CBDC022D.additionalIncludes

//## begin module%3C06CBDC022D.includes preserve=yes
//## end module%3C06CBDC022D.includes

// CGPhysicEntity
#include "Game\Entities\CGPhysicEntity.h"
//## begin module%3C06CBDC022D.additionalDeclarations preserve=yes
//## end module%3C06CBDC022D.additionalDeclarations


//## begin CBoxEntity%3C06CBDC022D.preface preserve=yes
//## end CBoxEntity%3C06CBDC022D.preface

//## Class: CBoxEntity%3C06CBDC022D
//## Category: Game::Entities%3B5DE99E0136
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CBoxEntity : public CGPhysicEntity  //## Inherits: <unnamed>%3CC096A800F6
{
  //## begin CBoxEntity%3C06CBDC022D.initialDeclarations preserve=yes
  //## end CBoxEntity%3C06CBDC022D.initialDeclarations

  public:
    //## Constructors (generated)
      CBoxEntity();

    //## Destructor (generated)
      ~CBoxEntity();


    //## Other Operations (specified)
      //## Operation: Think%1007074379
      virtual void Think (float _fDelta);

      //## Operation: Init%1019293386
      void Init (CVect3& _roPos, CVect3& _roSpeed);

      //## Operation: Respawn%1007604303
      void Respawn ();

    // Data Members for Class Attributes

      //## Attribute: iState%3C06CD0101AC
      //## begin CBoxEntity::iState%3C06CD0101AC.attr preserve=no  public: int {UA} 0
      int iState;
      //## end CBoxEntity::iState%3C06CD0101AC.attr

      //## Attribute: poGrObj%3CC1694802B3
      //## begin CBoxEntity::poGrObj%3CC1694802B3.attr preserve=no  public: CObject3D_Transf* {UA} NULL
      CObject3D_Transf* poGrObj;
      //## end CBoxEntity::poGrObj%3CC1694802B3.attr

    // Additional Public Declarations
      //## begin CBoxEntity%3C06CBDC022D.public preserve=yes
      //## end CBoxEntity%3C06CBDC022D.public

  protected:
    // Additional Protected Declarations
      //## begin CBoxEntity%3C06CBDC022D.protected preserve=yes
      //## end CBoxEntity%3C06CBDC022D.protected

  private:
    // Additional Private Declarations
      //## begin CBoxEntity%3C06CBDC022D.private preserve=yes
      //## end CBoxEntity%3C06CBDC022D.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CBoxEntity%3C06CBDC022D.implementation preserve=yes
      //## end CBoxEntity%3C06CBDC022D.implementation

};

//## begin CBoxEntity%3C06CBDC022D.postscript preserve=yes
//## end CBoxEntity%3C06CBDC022D.postscript

// Class CBoxEntity 

//## begin module%3C06CBDC022D.epilog preserve=yes
//## end module%3C06CBDC022D.epilog


#endif
