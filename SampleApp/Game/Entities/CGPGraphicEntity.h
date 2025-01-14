//## begin module%3CD6F5C002C8.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3CD6F5C002C8.cm

//## begin module%3CD6F5C002C8.cp preserve=no
//## end module%3CD6F5C002C8.cp

//## Module: CGPGraphicEntity%3CD6F5C002C8; Pseudo Package specification
//## Source file: i:\Projects\GammaE\Game\Entities\CGPGraphicEntity.h

#ifndef CGPGraphicEntity_h
#define CGPGraphicEntity_h 1

//## begin module%3CD6F5C002C8.additionalIncludes preserve=no
//## end module%3CD6F5C002C8.additionalIncludes

//## begin module%3CD6F5C002C8.includes preserve=yes
//## end module%3CD6F5C002C8.includes

// CGPhysicEntity
#include "Game\Entities\CGPhysicEntity.h"
//## begin module%3CD6F5C002C8.additionalDeclarations preserve=yes
//## end module%3CD6F5C002C8.additionalDeclarations


//## begin CGPGraphicEntity%3CD6F5C002C8.preface preserve=yes
//## end CGPGraphicEntity%3CD6F5C002C8.preface

//## Class: CGPGraphicEntity%3CD6F5C002C8
//## Category: Game::Entities%3B5DE99E0136
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CGPGraphicEntity : public CGPhysicEntity  //## Inherits: <unnamed>%3CD6F5D5034B
{
  //## begin CGPGraphicEntity%3CD6F5C002C8.initialDeclarations preserve=yes
  //## end CGPGraphicEntity%3CD6F5C002C8.initialDeclarations

  public:
    //## Constructors (generated)
      CGPGraphicEntity();

    //## Destructor (generated)
      ~CGPGraphicEntity();


    //## Other Operations (specified)
      //## Operation: SetAngles%1020720914
      void SetAngles (float _fRoll, float _fYaw, float _fPitch);

    // Additional Public Declarations
      //## begin CGPGraphicEntity%3CD6F5C002C8.public preserve=yes
      //## end CGPGraphicEntity%3CD6F5C002C8.public

  protected:
    // Data Members for Class Attributes

      //## Attribute: oDir%3CD6F5EB0162
      //## begin CGPGraphicEntity::oDir%3CD6F5EB0162.attr preserve=no  protected: CVect3 {UA} 
      CVect3 oDir;
      //## end CGPGraphicEntity::oDir%3CD6F5EB0162.attr

      //## Attribute: oUp%3CD6F5F303D0
      //## begin CGPGraphicEntity::oUp%3CD6F5F303D0.attr preserve=no  protected: CVect3 {UA} 
      CVect3 oUp;
      //## end CGPGraphicEntity::oUp%3CD6F5F303D0.attr

      //## Attribute: oSide%3CD6F5FB016F
      //## begin CGPGraphicEntity::oSide%3CD6F5FB016F.attr preserve=no  protected: CVect3 {UA} 
      CVect3 oSide;
      //## end CGPGraphicEntity::oSide%3CD6F5FB016F.attr

      //## Attribute: oPos%3CD6F60202E1
      //## begin CGPGraphicEntity::oPos%3CD6F60202E1.attr preserve=no  protected: CVect3 {UA} 
      CVect3 oPos;
      //## end CGPGraphicEntity::oPos%3CD6F60202E1.attr

      //## Attribute: poModel%3CD6F6080023
      //## begin CGPGraphicEntity::poModel%3CD6F6080023.attr preserve=no  protected: CObject3D_Transf * {UA} 
      CObject3D_Transf *poModel;
      //## end CGPGraphicEntity::poModel%3CD6F6080023.attr

    // Additional Protected Declarations
      //## begin CGPGraphicEntity%3CD6F5C002C8.protected preserve=yes
      //## end CGPGraphicEntity%3CD6F5C002C8.protected

  private:
    // Additional Private Declarations
      //## begin CGPGraphicEntity%3CD6F5C002C8.private preserve=yes
      //## end CGPGraphicEntity%3CD6F5C002C8.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CGPGraphicEntity%3CD6F5C002C8.implementation preserve=yes
      //## end CGPGraphicEntity%3CD6F5C002C8.implementation

};

//## begin CGPGraphicEntity%3CD6F5C002C8.postscript preserve=yes
//## end CGPGraphicEntity%3CD6F5C002C8.postscript

// Class CGPGraphicEntity 

//## begin module%3CD6F5C002C8.epilog preserve=yes
//## end module%3CD6F5C002C8.epilog


#endif
