//## begin module%3BE9C5D6002E.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3BE9C5D6002E.cm

//## begin module%3BE9C5D6002E.cp preserve=no
//## end module%3BE9C5D6002E.cp

//## Module: CObject3D_BSPNode%3BE9C5D6002E; Pseudo Package specification
//## Source file: i:\Projects\GammaE\Scene\CObject3D_BSPNode.h

#ifndef CObject3D_BSPNode_h
#define CObject3D_BSPNode_h 1

//## begin module%3BE9C5D6002E.additionalIncludes preserve=no
//## end module%3BE9C5D6002E.additionalIncludes

//## begin module%3BE9C5D6002E.includes preserve=yes
//## end module%3BE9C5D6002E.includes

// CObject3D
#include "Scene\CObject3D.h"
//## begin module%3BE9C5D6002E.additionalDeclarations preserve=yes
//## end module%3BE9C5D6002E.additionalDeclarations


//## begin CObject3D_BSPNode%3BE9C5D6002E.preface preserve=yes
//## end CObject3D_BSPNode%3BE9C5D6002E.preface

//## Class: CObject3D_BSPNode%3BE9C5D6002E
//## Category: Scene%3AA2567D00C8
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CObject3D_BSPNode : public CObject3D  //## Inherits: <unnamed>%3BE9C64F024F
{
  //## begin CObject3D_BSPNode%3BE9C5D6002E.initialDeclarations preserve=yes
  //## end CObject3D_BSPNode%3BE9C5D6002E.initialDeclarations

  public:
    //## Constructors (generated)
      CObject3D_BSPNode();

    //## Destructor (generated)
      ~CObject3D_BSPNode();


    //## Other Operations (specified)
      //## Operation: Render%1005176633
      virtual void Render ();

      //## Operation: poGetBoundVol%1005176631
      virtual CGraphBV* poGetBoundVol ();

      //## Operation: ComputeBoundVol%1005176632
      virtual void ComputeBoundVol ();

      //## Operation: Setup%1005176628
      void Setup (CObject3D* _poBack, CObject3D *_poFront, CPlane& _roPlane);

      //## Operation: SetBackNode%1005176629
      void SetBackNode (CObject3D* _poBack);

      //## Operation: SetFrontNode%1005176630
      void SetFrontNode (CObject3D* _poFront);

      //## Operation: poGetBackNode%1011999907
      CObject3D* poGetBackNode ();

      //## Operation: poGetFrontNode%1011999908
      CObject3D* poGetFrontNode ();

      //## Operation: SetPartitionPlane%1005176634
      void SetPartitionPlane (CPlane &_roPlane);

      //## Operation: poGetPartitionPlane%1011999909
      CPlane * poGetPartitionPlane ();

    // Additional Public Declarations
      //## begin CObject3D_BSPNode%3BE9C5D6002E.public preserve=yes
      //## end CObject3D_BSPNode%3BE9C5D6002E.public

  protected:
    // Additional Protected Declarations
      //## begin CObject3D_BSPNode%3BE9C5D6002E.protected preserve=yes
      //## end CObject3D_BSPNode%3BE9C5D6002E.protected

  private:
    // Data Members for Class Attributes

      //## Attribute: poBackNode%3BE9C5E20375
      //## begin CObject3D_BSPNode::poBackNode%3BE9C5E20375.attr preserve=no  private: CObject3D * {UA} NULL
      CObject3D *poBackNode;
      //## end CObject3D_BSPNode::poBackNode%3BE9C5E20375.attr

      //## Attribute: poFrontNode%3BE9C5F402EF
      //## begin CObject3D_BSPNode::poFrontNode%3BE9C5F402EF.attr preserve=no  private: CObject3D * {UA} NULL
      CObject3D *poFrontNode;
      //## end CObject3D_BSPNode::poFrontNode%3BE9C5F402EF.attr

      //## Attribute: oPartitionPlane%3BE9C85301B1
      //## begin CObject3D_BSPNode::oPartitionPlane%3BE9C85301B1.attr preserve=no  private: CPlane {UA} 
      CPlane oPartitionPlane;
      //## end CObject3D_BSPNode::oPartitionPlane%3BE9C85301B1.attr

    // Additional Private Declarations
      //## begin CObject3D_BSPNode%3BE9C5D6002E.private preserve=yes
      //## end CObject3D_BSPNode%3BE9C5D6002E.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CObject3D_BSPNode%3BE9C5D6002E.implementation preserve=yes
      //## end CObject3D_BSPNode%3BE9C5D6002E.implementation

};

//## begin CObject3D_BSPNode%3BE9C5D6002E.postscript preserve=yes
//## end CObject3D_BSPNode%3BE9C5D6002E.postscript

// Class CObject3D_BSPNode 

//## begin module%3BE9C5D6002E.epilog preserve=yes
//## end module%3BE9C5D6002E.epilog


#endif
