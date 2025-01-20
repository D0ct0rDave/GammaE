//## begin module%3BA7B3200274.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3BA7B3200274.cm

//## begin module%3BA7B3200274.cp preserve=no
//## end module%3BA7B3200274.cp

//## Module: SCNUt_AnimMesh_NormalComputer%3BA7B3200274; Pseudo Package specification
//## Source file: i:\Projects\GammaE\Scene\SceneUtils\ScnNormalGen\SCNUt_AnimMesh_NormalComputer.h

#ifndef SCNUt_AnimMesh_NormalComputer_h
#define SCNUt_AnimMesh_NormalComputer_h 1

//## begin module%3BA7B3200274.additionalIncludes preserve=no
//## end module%3BA7B3200274.additionalIncludes

//## begin module%3BA7B3200274.includes preserve=yes
//## end module%3BA7B3200274.includes

// CObject3D_AnimMesh
#include "Scene\Animation\CObject3D_AnimMesh.h"
//## begin module%3BA7B3200274.additionalDeclarations preserve=yes
//## end module%3BA7B3200274.additionalDeclarations


//## begin SCNUt_AnimMesh_NormalComputer%3BA7B3200274.preface preserve=yes
//## end SCNUt_AnimMesh_NormalComputer%3BA7B3200274.preface

//## Class: SCNUt_AnimMesh_NormalComputer%3BA7B3200274
//## Category: Scene::SceneUtils::ScnNormalGen%3C76D58602F4
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3BA7B36C035A;CObject3D_AnimMesh { -> }

class SCNUt_AnimMesh_NormalComputer 
{
  //## begin SCNUt_AnimMesh_NormalComputer%3BA7B3200274.initialDeclarations preserve=yes
  //## end SCNUt_AnimMesh_NormalComputer%3BA7B3200274.initialDeclarations

  public:
    //## Constructors (generated)
      SCNUt_AnimMesh_NormalComputer();

    //## Destructor (generated)
      ~SCNUt_AnimMesh_NormalComputer();


    //## Other Operations (specified)
      //## Operation: Generate%1000845950
      void Generate (CObject3D_AnimMesh *_pObj);

    // Additional Public Declarations
      //## begin SCNUt_AnimMesh_NormalComputer%3BA7B3200274.public preserve=yes
      //## end SCNUt_AnimMesh_NormalComputer%3BA7B3200274.public

  protected:
    // Additional Protected Declarations
      //## begin SCNUt_AnimMesh_NormalComputer%3BA7B3200274.protected preserve=yes
      //## end SCNUt_AnimMesh_NormalComputer%3BA7B3200274.protected

  private:
    // Additional Private Declarations
      //## begin SCNUt_AnimMesh_NormalComputer%3BA7B3200274.private preserve=yes
      //## end SCNUt_AnimMesh_NormalComputer%3BA7B3200274.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin SCNUt_AnimMesh_NormalComputer%3BA7B3200274.implementation preserve=yes
      //## end SCNUt_AnimMesh_NormalComputer%3BA7B3200274.implementation

};

//## begin SCNUt_AnimMesh_NormalComputer%3BA7B3200274.postscript preserve=yes
//## end SCNUt_AnimMesh_NormalComputer%3BA7B3200274.postscript

// Class SCNUt_AnimMesh_NormalComputer 

//## begin module%3BA7B3200274.epilog preserve=yes
extern SCNUt_AnimMesh_NormalComputer	glbAnimMesh_NormalGenerator;
//## end module%3BA7B3200274.epilog


#endif
