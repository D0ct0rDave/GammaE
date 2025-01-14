//## begin module%3CCD3E0403E4.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3CCD3E0403E4.cm

//## begin module%3CCD3E0403E4.cp preserve=no
//## end module%3CCD3E0403E4.cp

//## Module: CSphereEntity%3CCD3E0403E4; Pseudo Package specification
//## Source file: i:\Projects\GammaE\Game\Entities\CSphereEntity.h

#ifndef CSphereEntity_h
#define CSphereEntity_h 1

//## begin module%3CCD3E0403E4.additionalIncludes preserve=no
//## end module%3CCD3E0403E4.additionalIncludes

//## begin module%3CCD3E0403E4.includes preserve=yes
//## end module%3CCD3E0403E4.includes

// CGPhysicEntity
#include "Game\Entities\CGPhysicEntity.h"
//## begin module%3CCD3E0403E4.additionalDeclarations preserve=yes
//## end module%3CCD3E0403E4.additionalDeclarations


//## begin CSphereEntity%3CCD3E0403E4.preface preserve=yes
//## end CSphereEntity%3CCD3E0403E4.preface

//## Class: CSphereEntity%3CCD3E0403E4
//## Category: Game::Entities%3B5DE99E0136
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CSphereEntity : public CGPhysicEntity  //## Inherits: <unnamed>%3CCD3E0B01D1
{
  //## begin CSphereEntity%3CCD3E0403E4.initialDeclarations preserve=yes
  //## end CSphereEntity%3CCD3E0403E4.initialDeclarations

  public:
    //## Constructors (generated)
      CSphereEntity();

    //## Destructor (generated)
      ~CSphereEntity();


    //## Other Operations (specified)
      //## Operation: Think%1020082681
      virtual void Think (float _fDelta);

      //## Operation: Init%1020082682
      void Init (CVect3& _roPos, CVect3& _roSpeed);

      //## Operation: Respawn%1020082683
      void Respawn ();

    // Data Members for Class Attributes

      //## Attribute: poGrObj%3CCD3E150009
      //## begin CSphereEntity::poGrObj%3CCD3E150009.attr preserve=no  public: CObject3D_Transf* {UA} NULL
      CObject3D_Transf* poGrObj;
      //## end CSphereEntity::poGrObj%3CCD3E150009.attr

    // Additional Public Declarations
      //## begin CSphereEntity%3CCD3E0403E4.public preserve=yes
      //## end CSphereEntity%3CCD3E0403E4.public

  protected:
    // Additional Protected Declarations
      //## begin CSphereEntity%3CCD3E0403E4.protected preserve=yes
      //## end CSphereEntity%3CCD3E0403E4.protected

  private:
    // Additional Private Declarations
      //## begin CSphereEntity%3CCD3E0403E4.private preserve=yes
      //## end CSphereEntity%3CCD3E0403E4.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CSphereEntity%3CCD3E0403E4.implementation preserve=yes
      //## end CSphereEntity%3CCD3E0403E4.implementation

};

//## begin CSphereEntity%3CCD3E0403E4.postscript preserve=yes
//## end CSphereEntity%3CCD3E0403E4.postscript

// Class CSphereEntity 

//## begin module%3CCD3E0403E4.epilog preserve=yes
//## end module%3CCD3E0403E4.epilog


#endif
