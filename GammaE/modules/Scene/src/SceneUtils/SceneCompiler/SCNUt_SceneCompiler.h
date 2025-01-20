//## begin module%3C51E67003B5.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3C51E67003B5.cm

//## begin module%3C51E67003B5.cp preserve=no
//## end module%3C51E67003B5.cp

//## Module: SCNUt_SceneCompiler%3C51E67003B5; Pseudo Package specification
//## Source file: i:\Projects\GammaE\Scene\SceneUtils\SceneCompiler\SCNUt_SceneCompiler.h

#ifndef SCNUt_SceneCompiler_h
#define SCNUt_SceneCompiler_h 1

//## begin module%3C51E67003B5.additionalIncludes preserve=no
//## end module%3C51E67003B5.additionalIncludes

//## begin module%3C51E67003B5.includes preserve=yes
//## end module%3C51E67003B5.includes

// CObject3D
#include "Scene\CObject3D.h"
// CObject3D_Transf
#include "Scene\CObject3D_Transf.h"
// CObject3D_CompiledLeaf
#include "Scene\CObject3D_CompiledLeaf.h"
// CObject3D_BSPNode
#include "Scene\CObject3D_BSPNode.h"
// CObject3D_Node
#include "Scene\CObject3D_Node.h"
// CObject3D_Leaf
#include "Scene\CObject3D_Leaf.h"
//## begin module%3C51E67003B5.additionalDeclarations preserve=yes
//## end module%3C51E67003B5.additionalDeclarations


//## begin SCNUt_SceneCompiler%3C51E67003B5.preface preserve=yes
//## end SCNUt_SceneCompiler%3C51E67003B5.preface

//## Class: SCNUt_SceneCompiler%3C51E67003B5
//## Category: Scene::SceneUtils::SceneCompiler%3C51E4D7019B
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3C51E7BD0075;CObject3D { -> }
//## Uses: <unnamed>%3C51E7BE01D5;CObject3D_Node { -> }
//## Uses: <unnamed>%3C51E7C00386;CObject3D_BSPNode { -> }
//## Uses: <unnamed>%3C51E7C20375;CObject3D_Leaf { -> }
//## Uses: <unnamed>%3C51E7C50081;CObject3D_CompiledLeaf { -> }
//## Uses: <unnamed>%3CC293460101;CObject3D_Transf { -> }

class SCNUt_SceneCompiler 
{
  //## begin SCNUt_SceneCompiler%3C51E67003B5.initialDeclarations preserve=yes
  //## end SCNUt_SceneCompiler%3C51E67003B5.initialDeclarations

  public:
    //## Constructors (generated)
      SCNUt_SceneCompiler();

    //## Destructor (generated)
      ~SCNUt_SceneCompiler();


    //## Other Operations (specified)
      //## Operation: CompileScene%1011999903
      void CompileScene (CObject3D* _poScn);

      //## Operation: SetNULLMaterials%1012851956
      void SetNULLMaterials (bool _bNULL);

    // Additional Public Declarations
      //## begin SCNUt_SceneCompiler%3C51E67003B5.public preserve=yes
      //## end SCNUt_SceneCompiler%3C51E67003B5.public

  protected:
    // Additional Protected Declarations
      //## begin SCNUt_SceneCompiler%3C51E67003B5.protected preserve=yes
      //## end SCNUt_SceneCompiler%3C51E67003B5.protected

  private:
    // Data Members for Class Attributes

      //## Attribute: bNULLMaterials%3C5EF8820282
      //## begin SCNUt_SceneCompiler::bNULLMaterials%3C5EF8820282.attr preserve=no  private: bool {UA} true
      bool bNULLMaterials;
      //## end SCNUt_SceneCompiler::bNULLMaterials%3C5EF8820282.attr

    // Additional Private Declarations
      //## begin SCNUt_SceneCompiler%3C51E67003B5.private preserve=yes
      //## end SCNUt_SceneCompiler%3C51E67003B5.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin SCNUt_SceneCompiler%3C51E67003B5.implementation preserve=yes
      //## end SCNUt_SceneCompiler%3C51E67003B5.implementation

};

//## begin SCNUt_SceneCompiler%3C51E67003B5.postscript preserve=yes
//## end SCNUt_SceneCompiler%3C51E67003B5.postscript

// Class SCNUt_SceneCompiler 


//## Other Operations (inline)
inline void SCNUt_SceneCompiler::SetNULLMaterials (bool _bNULL)
{
  //## begin SCNUt_SceneCompiler::SetNULLMaterials%1012851956.body preserve=yes
	bNULLMaterials = _bNULL;
  //## end SCNUt_SceneCompiler::SetNULLMaterials%1012851956.body
}

//## begin module%3C51E67003B5.epilog preserve=yes
//## end module%3C51E67003B5.epilog


#endif
