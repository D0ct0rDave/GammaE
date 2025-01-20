//## begin module%3BFED7400167.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3BFED7400167.cm

//## begin module%3BFED7400167.cp preserve=no
//## end module%3BFED7400167.cp

//## Module: SCNUt_TriSceneClassifier%3BFED7400167; Pseudo Package specification
//## Source file: i:\Projects\GammaE\Scene\SceneUtils\SplitTriScene\SCNUt_TriSceneClassifier.h

#ifndef SCNUt_TriSceneClassifier_h
#define SCNUt_TriSceneClassifier_h 1

//## begin module%3BFED7400167.additionalIncludes preserve=no
//## end module%3BFED7400167.additionalIncludes

//## begin module%3BFED7400167.includes preserve=yes
//## end module%3BFED7400167.includes

// SCNUt_TriScene
#include "Scene\SceneUtils\SCNUt_TriScene.h"
//## begin module%3BFED7400167.additionalDeclarations preserve=yes
//## end module%3BFED7400167.additionalDeclarations


//## begin SCNUt_TriSceneClassifier%3BFED7400167.preface preserve=yes
//## end SCNUt_TriSceneClassifier%3BFED7400167.preface

//## Class: SCNUt_TriSceneClassifier%3BFED7400167
//## Category: Scene::SceneUtils::SplitTriScene%3C76D5FD022D
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3BFED89A02AF;SCNUt_TriScene { -> }

class SCNUt_TriSceneClassifier 
{
  //## begin SCNUt_TriSceneClassifier%3BFED7400167.initialDeclarations preserve=yes
  //## end SCNUt_TriSceneClassifier%3BFED7400167.initialDeclarations

  public:
    //## Constructors (generated)
      SCNUt_TriSceneClassifier();

    //## Destructor (generated)
      ~SCNUt_TriSceneClassifier();


    //## Other Operations (specified)
      //## Operation: ClassifyScene%1006556674
      void ClassifyScene (SCNUt_TriScene& _poScene, CPlane& _roPlane);

    // Data Members for Class Attributes

      //## Attribute: iFrontTris%3C02C6F500DC
      //## begin SCNUt_TriSceneClassifier::iFrontTris%3C02C6F500DC.attr preserve=no  public: int {UA} 0
      int iFrontTris;
      //## end SCNUt_TriSceneClassifier::iFrontTris%3C02C6F500DC.attr

      //## Attribute: iBackTris%3C02C6FA0256
      //## begin SCNUt_TriSceneClassifier::iBackTris%3C02C6FA0256.attr preserve=no  public: int {UA} 0
      int iBackTris;
      //## end SCNUt_TriSceneClassifier::iBackTris%3C02C6FA0256.attr

    // Additional Public Declarations
      //## begin SCNUt_TriSceneClassifier%3BFED7400167.public preserve=yes
      //## end SCNUt_TriSceneClassifier%3BFED7400167.public

  protected:

    //## Other Operations (specified)
      //## Operation: ClassifyTriangle%1006556675
      SCNUt_ePolyState ClassifyTriangle (SCNUt_Triangle& SrcTri, CPlane &Plane);

      //## Operation: ClassifyTriangleVertexs%1006556676
      void ClassifyTriangleVertexs (SCNUt_Triangle *SrcTri, CPlane &Plane);

      //## Operation: ClassifyVertex%1006556677
      SCNUt_ePolyState ClassifyVertex (SCNUt_Triangle *SrcTri, int iVertex);

    // Additional Protected Declarations
      //## begin SCNUt_TriSceneClassifier%3BFED7400167.protected preserve=yes
      //## end SCNUt_TriSceneClassifier%3BFED7400167.protected

  private:
    // Additional Private Declarations
      //## begin SCNUt_TriSceneClassifier%3BFED7400167.private preserve=yes
      //## end SCNUt_TriSceneClassifier%3BFED7400167.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin SCNUt_TriSceneClassifier%3BFED7400167.implementation preserve=yes
      //## end SCNUt_TriSceneClassifier%3BFED7400167.implementation

};

//## begin SCNUt_TriSceneClassifier%3BFED7400167.postscript preserve=yes
//## end SCNUt_TriSceneClassifier%3BFED7400167.postscript

// Class SCNUt_TriSceneClassifier 

//## begin module%3BFED7400167.epilog preserve=yes
//## end module%3BFED7400167.epilog


#endif
