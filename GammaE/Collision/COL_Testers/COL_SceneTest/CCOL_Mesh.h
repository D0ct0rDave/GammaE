//## begin module%3C1FDD4C028B.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3C1FDD4C028B.cm

//## begin module%3C1FDD4C028B.cp preserve=no
//## end module%3C1FDD4C028B.cp

//## Module: CCOL_Mesh%3C1FDD4C028B; Pseudo Package specification
//## Source file: i:\Projects\GammaE\Collision\COL_Testers\COL_SceneTest\CCOL_Mesh.h

#ifndef CCOL_Mesh_h
#define CCOL_Mesh_h 1

//## begin module%3C1FDD4C028B.additionalIncludes preserve=no
//## end module%3C1FDD4C028B.additionalIncludes

//## begin module%3C1FDD4C028B.includes preserve=yes
//## end module%3C1FDD4C028B.includes

// GammaE_E3D
#include "E3D\GammaE_E3D.h"
// GammaE_Math
#include "Math\GammaE_Math.h"
//## begin module%3C1FDD4C028B.additionalDeclarations preserve=yes
//## end module%3C1FDD4C028B.additionalDeclarations


//## begin CCOL_Mesh%3C1FDD4C028B.preface preserve=yes
//## end CCOL_Mesh%3C1FDD4C028B.preface

//## Class: CCOL_Mesh%3C1FDD4C028B
//## Category: Collision::COL_Testers::COL_SceneTest%3C1FC2BD0368
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3C1FDE900350;GammaE_E3D { -> }
//## Uses: <unnamed>%3C1FDE7B02E1;GammaE_Math { -> }

class CCOL_Mesh 
{
  //## begin CCOL_Mesh%3C1FDD4C028B.initialDeclarations preserve=yes
  //## end CCOL_Mesh%3C1FDD4C028B.initialDeclarations

  public:
    //## Constructors (generated)
      CCOL_Mesh();

    //## Destructor (generated)
      ~CCOL_Mesh();


    //## Other Operations (specified)
      //## Operation: Set%1008711901
      void Set (CMesh* _poMesh, int _iMat, float _fFrameFact);

    // Data Members for Class Attributes

      //## Attribute: poMesh%3C1FDD59030C
      //## begin CCOL_Mesh::poMesh%3C1FDD59030C.attr preserve=no  public: CMesh * {UA} NULL
      CMesh *poMesh;
      //## end CCOL_Mesh::poMesh%3C1FDD59030C.attr

      //## Attribute: fFrameFact%3C1FDD6B01B4
      //## begin CCOL_Mesh::fFrameFact%3C1FDD6B01B4.attr preserve=no  public: float {UA} 
      float fFrameFact;
      //## end CCOL_Mesh::fFrameFact%3C1FDD6B01B4.attr

      //## Attribute: iMat%3CCA9B100183
      //## begin CCOL_Mesh::iMat%3CCA9B100183.attr preserve=no  public: int {UA} -1
      int iMat;
      //## end CCOL_Mesh::iMat%3CCA9B100183.attr

    // Additional Public Declarations
      //## begin CCOL_Mesh%3C1FDD4C028B.public preserve=yes
      //## end CCOL_Mesh%3C1FDD4C028B.public

  protected:
    // Additional Protected Declarations
      //## begin CCOL_Mesh%3C1FDD4C028B.protected preserve=yes
      //## end CCOL_Mesh%3C1FDD4C028B.protected

  private:
    // Additional Private Declarations
      //## begin CCOL_Mesh%3C1FDD4C028B.private preserve=yes
      //## end CCOL_Mesh%3C1FDD4C028B.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CCOL_Mesh%3C1FDD4C028B.implementation preserve=yes
      //## end CCOL_Mesh%3C1FDD4C028B.implementation

};

//## begin CCOL_Mesh%3C1FDD4C028B.postscript preserve=yes
//## end CCOL_Mesh%3C1FDD4C028B.postscript

// Class CCOL_Mesh 


//## Other Operations (inline)
inline void CCOL_Mesh::Set (CMesh* _poMesh, int _iMat, float _fFrameFact)
{
  //## begin CCOL_Mesh::Set%1008711901.body preserve=yes
	poMesh = _poMesh;	
	fFrameFact = _fFrameFact;
	iMat   = _iMat;
  //## end CCOL_Mesh::Set%1008711901.body
}

//## begin module%3C1FDD4C028B.epilog preserve=yes
//## end module%3C1FDD4C028B.epilog


#endif
