//## begin module%3AAC0C32006E.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3AAC0C32006E.cm

//## begin module%3AAC0C32006E.cp preserve=no
//## end module%3AAC0C32006E.cp

//## Module: CObject3D_Node%3AAC0C32006E; Pseudo Package specification
//## Source file: i:\Projects\GammaE\Scene\CObject3D_Node.h

#ifndef CObject3D_Node_h
#define CObject3D_Node_h 1

//## begin module%3AAC0C32006E.additionalIncludes preserve=no
//## end module%3AAC0C32006E.additionalIncludes

//## begin module%3AAC0C32006E.includes preserve=yes
//## end module%3AAC0C32006E.includes

// CObject3D
#include "Scene\CObject3D.h"
//## begin module%3AAC0C32006E.additionalDeclarations preserve=yes
//## end module%3AAC0C32006E.additionalDeclarations


//## begin CObject3D_Node%3AAC0C32006E.preface preserve=yes
//## end CObject3D_Node%3AAC0C32006E.preface

//## Class: CObject3D_Node%3AAC0C32006E
//## Category: Scene%3AA2567D00C8
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CObject3D_Node : public CObject3D  //## Inherits: <unnamed>%3AAC0C4702EE
{
  //## begin CObject3D_Node%3AAC0C32006E.initialDeclarations preserve=yes
  //## end CObject3D_Node%3AAC0C32006E.initialDeclarations

  public:
    //## Constructors (generated)
      CObject3D_Node();

    //## Constructors (specified)
      //## Operation: CObject3D_Node%1019380666
      CObject3D_Node (int _iInitialSubObjs);

    //## Destructor (generated)
      virtual ~CObject3D_Node();


    //## Other Operations (specified)
      //## Operation: Init%984427108
      virtual void Init (int _iInitialSubObjs);

      //## Operation: Clear%986154962
      virtual void Clear ();

      //## Operation: poGetBoundVol%984427103
      virtual CGraphBV * poGetBoundVol ();

      //## Operation: ComputeBoundVol%984427104
      virtual void ComputeBoundVol ();

      //## Operation: DelObject%996702770
      void DelObject (int _iPos);

      //## Operation: iAddObject%996522678
      int iAddObject (CObject3D* _poObj);

      //## Operation: SetObject%984427106
      virtual void SetObject (CObject3D* _poObj, int _iPos);

      //## Operation: poGetObject%984427107
      CObject3D* poGetObject (int _iPos);

      //## Operation: Render%984427105
      virtual void Render ();

      //## Operation: iNumSubObjs%1010017301
      int iNumSubObjs ();

    // Additional Public Declarations
      //## begin CObject3D_Node%3AAC0C32006E.public preserve=yes
      //## end CObject3D_Node%3AAC0C32006E.public

  protected:
    // Data Members for Class Attributes

      //## Attribute: poSubObj%3AAC0CC4024E
      //## begin CObject3D_Node::poSubObj%3AAC0CC4024E.attr preserve=no  protected: CDynArray <CObject3D*> {UA} 
      CDynArray <CObject3D*> poSubObj;
      //## end CObject3D_Node::poSubObj%3AAC0CC4024E.attr

    // Additional Protected Declarations
      //## begin CObject3D_Node%3AAC0C32006E.protected preserve=yes
      //## end CObject3D_Node%3AAC0C32006E.protected

  private:
    // Additional Private Declarations
      //## begin CObject3D_Node%3AAC0C32006E.private preserve=yes
      //## end CObject3D_Node%3AAC0C32006E.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CObject3D_Node%3AAC0C32006E.implementation preserve=yes
      //## end CObject3D_Node%3AAC0C32006E.implementation

};

//## begin CObject3D_Node%3AAC0C32006E.postscript preserve=yes
//## end CObject3D_Node%3AAC0C32006E.postscript

// Class CObject3D_Node 

//## begin module%3AAC0C32006E.epilog preserve=yes
//## end module%3AAC0C32006E.epilog


#endif
