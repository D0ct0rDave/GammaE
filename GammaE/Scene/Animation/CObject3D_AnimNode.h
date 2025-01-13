//## begin module%3BA534E1028D.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3BA534E1028D.cm

//## begin module%3BA534E1028D.cp preserve=no
//## end module%3BA534E1028D.cp

//## Module: CObject3D_AnimNode%3BA534E1028D; Pseudo Package specification
//## Source file: i:\Projects\GammaE\Scene\Animation\CObject3D_AnimNode.h

#ifndef CObject3D_AnimNode_h
#define CObject3D_AnimNode_h 1

//## begin module%3BA534E1028D.additionalIncludes preserve=no
//## end module%3BA534E1028D.additionalIncludes

//## begin module%3BA534E1028D.includes preserve=yes
//## end module%3BA534E1028D.includes

// CObject3D_AnimGen
#include "Scene\Animation\CObject3D_AnimGen.h"
//## begin module%3BA534E1028D.additionalDeclarations preserve=yes
//## end module%3BA534E1028D.additionalDeclarations


//## begin CObject3D_AnimNode%3BA534E1028D.preface preserve=yes
//## end CObject3D_AnimNode%3BA534E1028D.preface

//## Class: CObject3D_AnimNode%3BA534E1028D
//## Category: Scene::Animation%3BA297A00326
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CObject3D_AnimNode : public CObject3D_AnimGen  //## Inherits: <unnamed>%3BA5351C01C9
{
  //## begin CObject3D_AnimNode%3BA534E1028D.initialDeclarations preserve=yes
  //## end CObject3D_AnimNode%3BA534E1028D.initialDeclarations

  public:
    //## Constructors (generated)
      CObject3D_AnimNode();

    //## Destructor (generated)
      virtual ~CObject3D_AnimNode();


    //## Other Operations (specified)
      //## Operation: poGetBoundVol%1000676445
      virtual CGraphBV* poGetBoundVol ();

      //## Operation: ComputeBoundVol%1000676446
      virtual void ComputeBoundVol ();

      //## Operation: Render%1000676447
      virtual void Render ();

      //## Operation: SetAnimState%1000676448
      virtual void SetAnimState (int _iSrc, int _iDst, float _fFactor);

      //## Operation: poGetStateBVol%1000676449
      virtual CGraphBV * poGetStateBVol (int _iState);

      //## Operation: Init%1000676450
      void Init (int _iMaxObjs);

      //## Operation: AddObject%1000676451
      int AddObject (CObject3D_AnimGen* _poObj);

      //## Operation: CreateStates%1000676452
      void CreateStates (int _iNumStates);

      //## Operation: Clear%1000676453
      void Clear ();

      //## Operation: poGetObject%1000933006
      CObject3D* poGetObject (int _iObj);

    // Data Members for Class Attributes

      //## Attribute: poObjs%3BA53540013F
      //## begin CObject3D_AnimNode::poObjs%3BA53540013F.attr preserve=no  public: CObject3D* * {UA} NULL
      CObject3D* *poObjs;
      //## end CObject3D_AnimNode::poObjs%3BA53540013F.attr

      //## Attribute: iNumObjs%3BA5354F010E
      //## begin CObject3D_AnimNode::iNumObjs%3BA5354F010E.attr preserve=no  public: int {UA} 0
      int iNumObjs;
      //## end CObject3D_AnimNode::iNumObjs%3BA5354F010E.attr

      //## Attribute: iMaxObjs%3BA535530395
      //## begin CObject3D_AnimNode::iMaxObjs%3BA535530395.attr preserve=no  public: int {UA} 0
      int iMaxObjs;
      //## end CObject3D_AnimNode::iMaxObjs%3BA535530395.attr

      //## Attribute: poBVolStates%3BA535990332
      //## begin CObject3D_AnimNode::poBVolStates%3BA535990332.attr preserve=no  public: CGraphBV* * {UA} NULL
      CGraphBV* *poBVolStates;
      //## end CObject3D_AnimNode::poBVolStates%3BA535990332.attr

    // Additional Public Declarations
      //## begin CObject3D_AnimNode%3BA534E1028D.public preserve=yes
      //## end CObject3D_AnimNode%3BA534E1028D.public

  protected:
    // Additional Protected Declarations
      //## begin CObject3D_AnimNode%3BA534E1028D.protected preserve=yes
      //## end CObject3D_AnimNode%3BA534E1028D.protected

  private:
    // Additional Private Declarations
      //## begin CObject3D_AnimNode%3BA534E1028D.private preserve=yes
      //## end CObject3D_AnimNode%3BA534E1028D.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CObject3D_AnimNode%3BA534E1028D.implementation preserve=yes
      //## end CObject3D_AnimNode%3BA534E1028D.implementation

};

//## begin CObject3D_AnimNode%3BA534E1028D.postscript preserve=yes
//## end CObject3D_AnimNode%3BA534E1028D.postscript

// Class CObject3D_AnimNode 

//## begin module%3BA534E1028D.epilog preserve=yes
//## end module%3BA534E1028D.epilog


#endif
