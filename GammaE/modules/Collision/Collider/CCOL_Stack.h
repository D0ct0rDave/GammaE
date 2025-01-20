//## begin module%3B6F1B0E0226.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3B6F1B0E0226.cm

//## begin module%3B6F1B0E0226.cp preserve=no
//## end module%3B6F1B0E0226.cp

//## Module: CCOL_Stack%3B6F1B0E0226; Pseudo Package specification
//## Source file: i:\Projects\GammaE\Collision\Collider\CCOL_Stack.h

#ifndef CCOL_Stack_h
#define CCOL_Stack_h 1

//## begin module%3B6F1B0E0226.additionalIncludes preserve=no
//## end module%3B6F1B0E0226.additionalIncludes

//## begin module%3B6F1B0E0226.includes preserve=yes
//## end module%3B6F1B0E0226.includes

// CCOL_StackCollisionElem
#include "Collision\Collider\CCOL_StackCollisionElem.h"
//## begin module%3B6F1B0E0226.additionalDeclarations preserve=yes
//## end module%3B6F1B0E0226.additionalDeclarations


//## begin CCOL_Stack%3B6F1B0E0226.preface preserve=yes
//## end CCOL_Stack%3B6F1B0E0226.preface

//## Class: CCOL_Stack%3B6F1B0E0226
//## Category: Collision::Collider%3B686E2401AE
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CCOL_Stack 
{
  //## begin CCOL_Stack%3B6F1B0E0226.initialDeclarations preserve=yes
  //## end CCOL_Stack%3B6F1B0E0226.initialDeclarations

  public:
    //## Constructors (generated)
      CCOL_Stack();

    //## Destructor (generated)
      ~CCOL_Stack();


    //## Other Operations (specified)
      //## Operation: Init%999639509
      void Init (int _iMaxColisions);

      //## Operation: Reset%999639510
      void Reset ();

      //## Operation: AddCollision%999639511
      void AddCollision (void *_poCObj, float _fFrameFact);

      //## Operation: GetNumCollisions%1007074377
      int GetNumCollisions ();

    //## Get and Set Operations for Associations (generated)

      //## Association: Collision::Collider::<unnamed>%3C0C19BE0121
      //## Role: CCOL_Stack::Collided%3C0C19BE01EB
      CCOL_StackCollisionElem * GetCollided ();

    // Data Members for Associations

      //## Association: Collision::Collider::<unnamed>%3C0C19BE0121
      //## begin CCOL_Stack::Collided%3C0C19BE01EB.role preserve=no  public: CCOL_StackCollisionElem { -> RHAN}
      CCOL_StackCollisionElem *Collided;
      //## end CCOL_Stack::Collided%3C0C19BE01EB.role

    // Additional Public Declarations
      //## begin CCOL_Stack%3B6F1B0E0226.public preserve=yes
      //## end CCOL_Stack%3B6F1B0E0226.public

  protected:
    // Additional Protected Declarations
      //## begin CCOL_Stack%3B6F1B0E0226.protected preserve=yes
      //## end CCOL_Stack%3B6F1B0E0226.protected

  private:
    // Data Members for Class Attributes

      //## Attribute: iNumCollisions%3B6F1B1B030C
      //## begin CCOL_Stack::iNumCollisions%3B6F1B1B030C.attr preserve=no  private: int {UA} 0
      int iNumCollisions;
      //## end CCOL_Stack::iNumCollisions%3B6F1B1B030C.attr

      //## Attribute: iMaxCollisions%3B6F1B2B00A0
      //## begin CCOL_Stack::iMaxCollisions%3B6F1B2B00A0.attr preserve=no  private: int {UA} 0
      int iMaxCollisions;
      //## end CCOL_Stack::iMaxCollisions%3B6F1B2B00A0.attr

    // Additional Private Declarations
      //## begin CCOL_Stack%3B6F1B0E0226.private preserve=yes
      //## end CCOL_Stack%3B6F1B0E0226.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CCOL_Stack%3B6F1B0E0226.implementation preserve=yes
      //## end CCOL_Stack%3B6F1B0E0226.implementation

};

//## begin CCOL_Stack%3B6F1B0E0226.postscript preserve=yes
//## end CCOL_Stack%3B6F1B0E0226.postscript

// Class CCOL_Stack 


//## Other Operations (inline)
inline int CCOL_Stack::GetNumCollisions ()
{
  //## begin CCOL_Stack::GetNumCollisions%1007074377.body preserve=yes
  	return (iNumCollisions);
  //## end CCOL_Stack::GetNumCollisions%1007074377.body
}

//## Get and Set Operations for Associations (inline)

inline CCOL_StackCollisionElem * CCOL_Stack::GetCollided ()
{
  //## begin CCOL_Stack::GetCollided%3C0C19BE01EB.get preserve=no
  return Collided;
  //## end CCOL_Stack::GetCollided%3C0C19BE01EB.get
}

//## begin module%3B6F1B0E0226.epilog preserve=yes
//## end module%3B6F1B0E0226.epilog


#endif
