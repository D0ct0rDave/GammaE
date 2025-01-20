//## begin module%3AC2295A0226.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3AC2295A0226.cm

//## begin module%3AC2295A0226.cp preserve=no
//## end module%3AC2295A0226.cp

//## Module: SCNUt_TriSceneSeparator%3AC2295A0226; Pseudo Package specification
//## Source file: i:\Projects\GammaE\Scene\SceneUtils\SeparateTriScene\SCNUt_TriSceneSeparator.h

#ifndef SCNUt_TriSceneSeparator_h
#define SCNUt_TriSceneSeparator_h 1

//## begin module%3AC2295A0226.additionalIncludes preserve=no
//## end module%3AC2295A0226.additionalIncludes

//## begin module%3AC2295A0226.includes preserve=yes
//## end module%3AC2295A0226.includes

// SCNUt_TriScene
#include "Scene\SceneUtils\SCNUt_TriScene.h"
// SCNUt_MeshCompacter
#include "Scene\SceneUtils\ScnMeshGen\SCNUt_MeshCompacter.h"
//## begin module%3AC2295A0226.additionalDeclarations preserve=yes
//## end module%3AC2295A0226.additionalDeclarations


//## begin SCNUt_TriSceneSeparator%3AC2295A0226.preface preserve=yes
//## end SCNUt_TriSceneSeparator%3AC2295A0226.preface

//## Class: SCNUt_TriSceneSeparator%3AC2295A0226
//## Category: Scene::SceneUtils::SeparateTriScene%3C76D5DA00B0
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3C76D6DB03B3;SCNUt_TriScene { -> }
//## Uses: <unnamed>%3C76D70C00E2;SCNUt_MeshCompacter { -> }

class SCNUt_TriSceneSeparator 
{
  //## begin SCNUt_TriSceneSeparator%3AC2295A0226.initialDeclarations preserve=yes
  //## end SCNUt_TriSceneSeparator%3AC2295A0226.initialDeclarations

  public:
    //## Constructors (generated)
      SCNUt_TriSceneSeparator();

    //## Destructor (generated)
      ~SCNUt_TriSceneSeparator();


    //## Other Operations (specified)
      //## Operation: SeparateScene%985807907
      int SeparateScene (SCNUt_TriScene &Scene);

      //## Operation: iProcessTriScene%1004401294
      int iProcessTriScene (SCNUt_TriScene &Scene);

      //## Operation: iGetTrisWithMat%1004401295
      int iGetTrisWithMat (int _iMat);

    // Data Members for Class Attributes

      //## Attribute: NumMeshes%3AC243C90172
      //## begin SCNUt_TriSceneSeparator::NumMeshes%3AC243C90172.attr preserve=no  public: int {UA} 0
      int NumMeshes;
      //## end SCNUt_TriSceneSeparator::NumMeshes%3AC243C90172.attr

      //## Attribute: Meshes%3AC243D40168
      //## begin SCNUt_TriSceneSeparator::Meshes%3AC243D40168.attr preserve=no  public: SCNUt_TriScene * {UA} NULL
      SCNUt_TriScene *Meshes;
      //## end SCNUt_TriSceneSeparator::Meshes%3AC243D40168.attr

      //## Attribute: piTriMat%3BDDF279012D
      //## begin SCNUt_TriSceneSeparator::piTriMat%3BDDF279012D.attr preserve=no  public: int * {UA} NULL
      int *piTriMat;
      //## end SCNUt_TriSceneSeparator::piTriMat%3BDDF279012D.attr

      //## Attribute: piMatIdx%3BDDF80A037B
      //## begin SCNUt_TriSceneSeparator::piMatIdx%3BDDF80A037B.attr preserve=no  public: int * {UA} NULL
      int *piMatIdx;
      //## end SCNUt_TriSceneSeparator::piMatIdx%3BDDF80A037B.attr

      //## Attribute: iMaxMats%3BDDF3D700EA
      //## begin SCNUt_TriSceneSeparator::iMaxMats%3BDDF3D700EA.attr preserve=no  public: int {UA} 0
      int iMaxMats;
      //## end SCNUt_TriSceneSeparator::iMaxMats%3BDDF3D700EA.attr

    // Additional Public Declarations
      //## begin SCNUt_TriSceneSeparator%3AC2295A0226.public preserve=yes
      //## end SCNUt_TriSceneSeparator%3AC2295A0226.public

  protected:
    // Additional Protected Declarations
      //## begin SCNUt_TriSceneSeparator%3AC2295A0226.protected preserve=yes
      //## end SCNUt_TriSceneSeparator%3AC2295A0226.protected

  private:
    // Additional Private Declarations
      //## begin SCNUt_TriSceneSeparator%3AC2295A0226.private preserve=yes
      //## end SCNUt_TriSceneSeparator%3AC2295A0226.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin SCNUt_TriSceneSeparator%3AC2295A0226.implementation preserve=yes
      //## end SCNUt_TriSceneSeparator%3AC2295A0226.implementation

};

//## begin SCNUt_TriSceneSeparator%3AC2295A0226.postscript preserve=yes
//## end SCNUt_TriSceneSeparator%3AC2295A0226.postscript

// Class SCNUt_TriSceneSeparator 

//## begin module%3AC2295A0226.epilog preserve=yes
//## end module%3AC2295A0226.epilog


#endif
