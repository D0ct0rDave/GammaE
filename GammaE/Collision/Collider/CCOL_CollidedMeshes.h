//## begin module%3C0ED68801F2.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3C0ED68801F2.cm

//## begin module%3C0ED68801F2.cp preserve=no
//## end module%3C0ED68801F2.cp

//## Module: CCOL_CollidedMeshes%3C0ED68801F2; Pseudo Package specification
//## Source file: i:\Projects\GammaE\Collision\Collider\CCOL_CollidedMeshes.h

#ifndef CCOL_CollidedMeshes_h
#define CCOL_CollidedMeshes_h 1

//## begin module%3C0ED68801F2.additionalIncludes preserve=no
//## end module%3C0ED68801F2.additionalIncludes

//## begin module%3C0ED68801F2.includes preserve=yes
//## end module%3C0ED68801F2.includes

// GammaE_E3D
#include "E3D\GammaE_E3D.h"
//## begin module%3C0ED68801F2.additionalDeclarations preserve=yes
//## end module%3C0ED68801F2.additionalDeclarations


//## begin CCOL_CollidedMeshes%3C0ED68801F2.preface preserve=yes
//## end CCOL_CollidedMeshes%3C0ED68801F2.preface

//## Class: CCOL_CollidedMeshes%3C0ED68801F2
//## Category: Collision::Collider%3B686E2401AE
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3C0ED7E400C4;GammaE_E3D { -> }

class CCOL_CollidedMeshes 
{
  //## begin CCOL_CollidedMeshes%3C0ED68801F2.initialDeclarations preserve=yes
  //## end CCOL_CollidedMeshes%3C0ED68801F2.initialDeclarations

  public:
    //## Constructors (generated)
      CCOL_CollidedMeshes();

    //## Destructor (generated)
      ~CCOL_CollidedMeshes();


    //## Other Operations (specified)
      //## Operation: Reset%1007604297
      void Reset ();

      //## Operation: AddMesh%1007604298
      void AddMesh (CMesh* _pMesh);

      //## Operation: iGetNumMeshes%1007604299
      int iGetNumMeshes ();

      //## Operation: pGetMesh%1007604300
      CMesh* pGetMesh (int _iMesh);

    // Additional Public Declarations
      //## begin CCOL_CollidedMeshes%3C0ED68801F2.public preserve=yes
      //## end CCOL_CollidedMeshes%3C0ED68801F2.public

  protected:
    // Data Members for Class Attributes

      //## Attribute: iNumMeshes%3C0ED6A90041
      //## begin CCOL_CollidedMeshes::iNumMeshes%3C0ED6A90041.attr preserve=no  protected: int {UA} 
      int iNumMeshes;
      //## end CCOL_CollidedMeshes::iNumMeshes%3C0ED6A90041.attr

      //## Attribute: pMesh%3C0ED6AD02FA
      //## begin CCOL_CollidedMeshes::pMesh%3C0ED6AD02FA.attr preserve=no  protected: CMesh *[10] {UA} 
      CMesh *pMesh[10];
      //## end CCOL_CollidedMeshes::pMesh%3C0ED6AD02FA.attr

    // Additional Protected Declarations
      //## begin CCOL_CollidedMeshes%3C0ED68801F2.protected preserve=yes
      //## end CCOL_CollidedMeshes%3C0ED68801F2.protected

  private:
    // Additional Private Declarations
      //## begin CCOL_CollidedMeshes%3C0ED68801F2.private preserve=yes
      //## end CCOL_CollidedMeshes%3C0ED68801F2.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CCOL_CollidedMeshes%3C0ED68801F2.implementation preserve=yes
      //## end CCOL_CollidedMeshes%3C0ED68801F2.implementation

};

//## begin CCOL_CollidedMeshes%3C0ED68801F2.postscript preserve=yes
//## end CCOL_CollidedMeshes%3C0ED68801F2.postscript

// Class CCOL_CollidedMeshes 

//## begin module%3C0ED68801F2.epilog preserve=yes
//## end module%3C0ED68801F2.epilog


#endif
