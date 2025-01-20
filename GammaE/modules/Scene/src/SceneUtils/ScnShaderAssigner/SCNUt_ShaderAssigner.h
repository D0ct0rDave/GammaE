//## begin module%3D02277501EE.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3D02277501EE.cm

//## begin module%3D02277501EE.cp preserve=no
//## end module%3D02277501EE.cp

//## Module: SCNUt_ShaderAssigner%3D02277501EE; Pseudo Package specification
//## Source file: i:\Projects\GammaE\Scene\SceneUtils\ScnShaderAssigner\SCNUt_ShaderAssigner.h

#ifndef SCNUt_ShaderAssigner_h
#define SCNUt_ShaderAssigner_h 1

//## begin module%3D02277501EE.additionalIncludes preserve=no
//## end module%3D02277501EE.additionalIncludes

//## begin module%3D02277501EE.includes preserve=yes
#include "Scene\CObject3D.h"
#include "Scene\CObject3D_Leaf.h"
#include "Scene\CObject3D_Node.h"
#include "Scene\CObject3D_Transf.h"
#include "Scene\CObject3D_BSPNode.h"
#include "Scene\CObject3D_CompiledLeaf.h"
//## end module%3D02277501EE.includes

// CObject3D
#include "Scene\CObject3D.h"
//## begin module%3D02277501EE.additionalDeclarations preserve=yes
//## end module%3D02277501EE.additionalDeclarations


//## begin SCNUt_ShaderAssigner%3D02277501EE.preface preserve=yes
//## end SCNUt_ShaderAssigner%3D02277501EE.preface

//## Class: SCNUt_ShaderAssigner%3D02277501EE
//## Category: Scene::SceneUtils::ScnShaderAssigner%3D0227600374
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3D02296D03D3;CObject3D { -> }

class SCNUt_ShaderAssigner 
{
  //## begin SCNUt_ShaderAssigner%3D02277501EE.initialDeclarations preserve=yes
  //## end SCNUt_ShaderAssigner%3D02277501EE.initialDeclarations

  public:
    //## Constructors (generated)
      SCNUt_ShaderAssigner();

    //## Destructor (generated)
      ~SCNUt_ShaderAssigner();


    //## Other Operations (specified)
      //## Operation: AssignShader%1023551463
      void AssignShader (CE3D_Shader* _poShader, CObject3D* _poObj);

    // Additional Public Declarations
      //## begin SCNUt_ShaderAssigner%3D02277501EE.public preserve=yes
      //## end SCNUt_ShaderAssigner%3D02277501EE.public

  protected:
    // Additional Protected Declarations
      //## begin SCNUt_ShaderAssigner%3D02277501EE.protected preserve=yes
      //## end SCNUt_ShaderAssigner%3D02277501EE.protected

  private:
    // Additional Private Declarations
      //## begin SCNUt_ShaderAssigner%3D02277501EE.private preserve=yes
      //## end SCNUt_ShaderAssigner%3D02277501EE.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin SCNUt_ShaderAssigner%3D02277501EE.implementation preserve=yes
      //## end SCNUt_ShaderAssigner%3D02277501EE.implementation

};

//## begin SCNUt_ShaderAssigner%3D02277501EE.postscript preserve=yes
//## end SCNUt_ShaderAssigner%3D02277501EE.postscript

// Class SCNUt_ShaderAssigner 

//## begin module%3D02277501EE.epilog preserve=yes
//## end module%3D02277501EE.epilog


#endif
