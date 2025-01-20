//## begin module%3B9E03DD0102.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3B9E03DD0102.cm

//## begin module%3B9E03DD0102.cp preserve=no
//## end module%3B9E03DD0102.cp

//## Module: CObject3D_AnimMesh%3B9E03DD0102; Pseudo Package specification
//## Source file: i:\Projects\GammaE\Scene\Animation\CObject3D_AnimMesh.h

#ifndef CObject3D_AnimMesh_h
#define CObject3D_AnimMesh_h 1

//## begin module%3B9E03DD0102.additionalIncludes preserve=no
//## end module%3B9E03DD0102.additionalIncludes

//## begin module%3B9E03DD0102.includes preserve=yes
//## end module%3B9E03DD0102.includes

// CObject3D_Leaf
#include "Scene\CObject3D_Leaf.h"
// CObject3D_AnimGen
#include "Scene\Animation\CObject3D_AnimGen.h"
//## begin module%3B9E03DD0102.additionalDeclarations preserve=yes
//## end module%3B9E03DD0102.additionalDeclarations


//## begin CObject3D_AnimMesh%3B9E03DD0102.preface preserve=yes
//## end CObject3D_AnimMesh%3B9E03DD0102.preface

//## Class: CObject3D_AnimMesh%3B9E03DD0102
//## Category: Scene::Animation%3BA297A00326
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CObject3D_AnimMesh : public CObject3D_AnimGen  //## Inherits: <unnamed>%3B9E0400008A
{
  //## begin CObject3D_AnimMesh%3B9E03DD0102.initialDeclarations preserve=yes
  //## end CObject3D_AnimMesh%3B9E03DD0102.initialDeclarations

  public:
    //## Constructors (generated)
      CObject3D_AnimMesh();

    //## Destructor (generated)
      virtual ~CObject3D_AnimMesh();


    //## Other Operations (specified)
      //## Operation: SetAnimState%1000205744
      virtual void SetAnimState (int _iSrc, int _iDst, float _fFactor);

      //## Operation: CreateStates%1000205745
      virtual void CreateStates (int _iNumStates, int _iNumStateVXs);

      //## Operation: Render%1000205746
      virtual void Render ();

      //## Operation: poGetBoundVol%1000205747
      virtual CGraphBV* poGetBoundVol ();

      //## Operation: ComputeBoundVol%1000205748
      virtual void ComputeBoundVol ();

      //## Operation: SetLeaf%1000239575
      void SetLeaf (CObject3D_Leaf *_pLeafMesh);

      //## Operation: poGetStateBVol%1000479979
      virtual CGraphBV * poGetStateBVol (int _iState);

      //## Operation: iGetNumStateVXs%1000933018
      int iGetNumStateVXs ();

    //## Get and Set Operations for Associations (generated)

      //## Association: Scene::<unnamed>%3B9E05D20135
      //## Role: CObject3D_AnimMesh::Leaf%3B9E05D4012E
      CObject3D_Leaf * GetLeaf ();

    // Data Members for Class Attributes

      //## Attribute: pMeshStates%3B9E04DC00EB
      //## begin CObject3D_AnimMesh::pMeshStates%3B9E04DC00EB.attr preserve=no  public: CVect3 * {UA} NULL
      CVect3 *pMeshStates;
      //## end CObject3D_AnimMesh::pMeshStates%3B9E04DC00EB.attr

      //## Attribute: pNMeshStates%3BA7B26901F9
      //## begin CObject3D_AnimMesh::pNMeshStates%3BA7B26901F9.attr preserve=no  public: CVect3 * {UA} NULL
      CVect3 *pNMeshStates;
      //## end CObject3D_AnimMesh::pNMeshStates%3BA7B26901F9.attr

      //## Attribute: iNumStateVXs%3B9E04F600FC
      //## begin CObject3D_AnimMesh::iNumStateVXs%3B9E04F600FC.attr preserve=no  public: int {UA} 0
      int iNumStateVXs;
      //## end CObject3D_AnimMesh::iNumStateVXs%3B9E04F600FC.attr

      //## Attribute: pBVolStates%3BA21CB80267
      //## begin CObject3D_AnimMesh::pBVolStates%3BA21CB80267.attr preserve=no  public: CGraphBV* * {UA} NULL
      CGraphBV* *pBVolStates;
      //## end CObject3D_AnimMesh::pBVolStates%3BA21CB80267.attr

    // Data Members for Associations

      //## Association: Scene::<unnamed>%3B9E05D20135
      //## begin CObject3D_AnimMesh::Leaf%3B9E05D4012E.role preserve=no  public: CObject3D_Leaf { -> RHAN}
      CObject3D_Leaf *Leaf;
      //## end CObject3D_AnimMesh::Leaf%3B9E05D4012E.role

    // Additional Public Declarations
      //## begin CObject3D_AnimMesh%3B9E03DD0102.public preserve=yes
      //## end CObject3D_AnimMesh%3B9E03DD0102.public

  protected:
    // Additional Protected Declarations
      //## begin CObject3D_AnimMesh%3B9E03DD0102.protected preserve=yes
      //## end CObject3D_AnimMesh%3B9E03DD0102.protected

  private:
    // Additional Private Declarations
      //## begin CObject3D_AnimMesh%3B9E03DD0102.private preserve=yes
      //## end CObject3D_AnimMesh%3B9E03DD0102.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CObject3D_AnimMesh%3B9E03DD0102.implementation preserve=yes
      //## end CObject3D_AnimMesh%3B9E03DD0102.implementation

};

//## begin CObject3D_AnimMesh%3B9E03DD0102.postscript preserve=yes
//## end CObject3D_AnimMesh%3B9E03DD0102.postscript

// Class CObject3D_AnimMesh 


//## Other Operations (inline)
inline int CObject3D_AnimMesh::iGetNumStateVXs ()
{
  //## begin CObject3D_AnimMesh::iGetNumStateVXs%1000933018.body preserve=yes
	return (iNumStateVXs);
  //## end CObject3D_AnimMesh::iGetNumStateVXs%1000933018.body
}

//## Get and Set Operations for Associations (inline)

inline CObject3D_Leaf * CObject3D_AnimMesh::GetLeaf ()
{
  //## begin CObject3D_AnimMesh::GetLeaf%3B9E05D4012E.get preserve=no
  return Leaf;
  //## end CObject3D_AnimMesh::GetLeaf%3B9E05D4012E.get
}

//## begin module%3B9E03DD0102.epilog preserve=yes
//## end module%3B9E03DD0102.epilog


#endif
