//## begin module%3C2BB92601FA.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3C2BB92601FA.cm

//## begin module%3C2BB92601FA.cp preserve=no
//## end module%3C2BB92601FA.cp

//## Module: GammaE_Scene%3C2BB92601FA; Pseudo Package specification
//## Source file: i:\Projects\GammaE\Scene\GammaE_Scene.h

#ifndef GammaE_Scene_h
#define GammaE_Scene_h 1

//## begin module%3C2BB92601FA.additionalIncludes preserve=no
//## end module%3C2BB92601FA.additionalIncludes

//## begin module%3C2BB92601FA.includes preserve=yes
#include "Scene/CObject3D.h"
#include "Scene/CObject3D_Node.h"
#include "Scene/CObject3D_Transf.h"
#include "Scene/CObject3D_Camera.h"
#include "Scene/CObject3D_Leaf.h"
#include "Scene/CObject3D_CompiledLeaf.h"

#include "Scene/Animation/CObject3D_AnimCfgGen.h"
#include "Scene/Animation/CObject3D_AnimCfg.h"
#include "Scene/Animation/CObject3D_AnimCfgMgr.h"

#include "Scene/Animation/CObject3D_AnimGen.h"
#include "Scene/Animation/CObject3D_AnimTransf.h"
#include "Scene/Animation/CObject3D_AnimMesh.h"


#include "Scene/ParticleSystems/CParticleSystem.h"
#include "Scene/ParticleSystems/CParticleSystem_Sparks.h"
#include "Scene/ParticleSystems/CParticleSystem_Coolant.h"

#include "Scene/3D_Loaders/3DSLoader/CLoader3DS.h"
#include "Scene/3D_Loaders/MD2Loader/CLoaderMD2.h"
#include "Scene/3D_Loaders/MD3Loader/CLoaderMD3.h"
#include "Scene/3D_Loaders/BSP2Loader/CLoaderBSP2.h"

#include "Scene/3D_Loaders/GEMLoader/GEMFile.h"
#include "Scene/3D_Loaders/GEMLoader/CLoaderGEM.h"
#include "Scene/3D_Savers/GEMSaver/CSaverGEM.h"

#include "Scene/Billboard/CBillboard_AxisAlign.h"
#include "Scene/Billboard/CBillboard_ScrAlign.h"
#include "Scene/Billboard/CBillboard_WorldAlign.h"

#include "Scene/2D_Objects/CHeadUpDisplay.h"

#include "Scene/SceneUtils/SCNUt_TriScene.h"
#include "Scene/SceneUtils/SCNUt_TriSceneAccumulator.h"
#include "Scene/SceneUtils/SCNUt_Triangle.h"
#include "Scene/SceneUtils/TriScnLoader/SCNUt_TriSceneLoader.h"
#include "Scene/SceneUtils/SeparateTriScene/SCNUt_TriSceneSeparator.h"
#include "Scene/SceneUtils/SplitTriScene/SCNUt_TriSceneClassifier.h"
#include "Scene/SceneUtils/SplitTriScene/SCNUt_TriSceneSplitter.h"
#include "Scene/SceneUtils/ScnMeshGen/SCNUt_MeshGenerator.h"
#include "Scene/SceneUtils/ScnMeshGen/SCNUt_MeshCompacter.h"
#include "Scene/SceneUtils/ScnMeshGen/SCNUt_MaterialTable.h"
#include "Scene/SceneUtils/ScnNormalGen/SCNUt_AnimMesh_NormalComputer.h"
#include "Scene/SceneUtils/ScnShaderAssigner/ScnUt_ShaderAssigner.h"
#include "Scene/SceneUtils/ScnPlanarMapper/SCNUt_PlanarMapper.h"

#include "Scene/SceneUtils/BSPBuilder/SCNUt_BSPBuilder.h"
#include "Scene/SceneUtils/OctreeBuilder/SCNUt_OctreeBuilder.h"
#include "Scene/SceneUtils/SceneBuilder/SCNUt_SceneBuilder.h"

#include "Scene/SceneUtils/TransfTriScn/SCNUt_TransformTriScene.h"
#include "Scene/SceneUtils/Mesh2TriScn/SCNUt_Mesh2TriScene.h"
#include "Scene/SceneUtils/Scn2TriScnBuilder/SCNUt_Scn2TriScnBuilder.h"
#include "Scene/SceneUtils/ScnStripifier/SCNUt_Stripifier.h"
#include "Scene/SceneUtils/SceneCompiler/SCNUt_SceneCompiler.h"
#include "Scene/SceneUtils/ScnUtils/SCNUt_TriUtils.h"
#include "Scene/SceneUtils/ScnCoplanarRemover/SCNUt_CoplanarRemover.h"
#include "Scene/SceneUtils/ScnVisibilityTester/SCNUt_VisibilityTester.h"
//## end module%3C2BB92601FA.includes

//## begin module%3C2BB92601FA.additionalDeclarations preserve=yes
//## end module%3C2BB92601FA.additionalDeclarations


//## begin GammaE_Scene%3C2BB92601FA.preface preserve=yes
//## end GammaE_Scene%3C2BB92601FA.preface

//## Class: GammaE_Scene%3C2BB92601FA
//## Category: Scene%3AA2567D00C8
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class GammaE_Scene 
{
  //## begin GammaE_Scene%3C2BB92601FA.initialDeclarations preserve=yes
  //## end GammaE_Scene%3C2BB92601FA.initialDeclarations

  public:
    //## Constructors (generated)
      GammaE_Scene();

    //## Destructor (generated)
      ~GammaE_Scene();

    // Additional Public Declarations
      //## begin GammaE_Scene%3C2BB92601FA.public preserve=yes
      //## end GammaE_Scene%3C2BB92601FA.public

  protected:
    // Additional Protected Declarations
      //## begin GammaE_Scene%3C2BB92601FA.protected preserve=yes
      //## end GammaE_Scene%3C2BB92601FA.protected

  private:
    // Additional Private Declarations
      //## begin GammaE_Scene%3C2BB92601FA.private preserve=yes
      //## end GammaE_Scene%3C2BB92601FA.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin GammaE_Scene%3C2BB92601FA.implementation preserve=yes
      //## end GammaE_Scene%3C2BB92601FA.implementation

};

//## begin GammaE_Scene%3C2BB92601FA.postscript preserve=yes
//## end GammaE_Scene%3C2BB92601FA.postscript

// Class GammaE_Scene 

//## begin module%3C2BB92601FA.epilog preserve=yes
//## end module%3C2BB92601FA.epilog


#endif
