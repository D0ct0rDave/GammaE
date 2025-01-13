//## begin module%3BE867D00383.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3BE867D00383.cm

//## begin module%3BE867D00383.cp preserve=no
//## end module%3BE867D00383.cp

//## Module: SCNUt_TriSceneSplitter%3BE867D00383; Pseudo Package specification
//## Source file: i:\Projects\GammaE\Scene\SceneUtils\SplitTriScene\SCNUt_TriSceneSplitter.h

#ifndef SCNUt_TriSceneSplitter_h
#define SCNUt_TriSceneSplitter_h 1

//## begin module%3BE867D00383.additionalIncludes preserve=no
//## end module%3BE867D00383.additionalIncludes

//## begin module%3BE867D00383.includes preserve=yes
//## end module%3BE867D00383.includes

// SCNUt_TriScene
#include "Scene\SceneUtils\SCNUt_TriScene.h"
// SCNUt_TriUtils
#include "Scene\SceneUtils\ScnUtils\SCNUt_TriUtils.h"
// SCNUt_TriSceneClassifier
#include "Scene\SceneUtils\SplitTriScene\SCNUt_TriSceneClassifier.h"
//## begin module%3BE867D00383.additionalDeclarations preserve=yes
//## end module%3BE867D00383.additionalDeclarations


//## begin SCNUt_TriSceneSplitter%3BE867D00383.preface preserve=yes
//## end SCNUt_TriSceneSplitter%3BE867D00383.preface

//## Class: SCNUt_TriSceneSplitter%3BE867D00383
//## Category: Scene::SceneUtils::SplitTriScene%3C76D5FD022D
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3BE87607017D;SCNUt_TriScene { -> }
//## Uses: <unnamed>%3BFED8A0011D;SCNUt_TriSceneClassifier { -> }
//## Uses: <unnamed>%3C85274901C3;SCNUt_TriUtils { -> }

class SCNUt_TriSceneSplitter 
{
  //## begin SCNUt_TriSceneSplitter%3BE867D00383.initialDeclarations preserve=yes
  //## end SCNUt_TriSceneSplitter%3BE867D00383.initialDeclarations

  public:
    //## Constructors (generated)
      SCNUt_TriSceneSplitter();

    //## Destructor (generated)
      ~SCNUt_TriSceneSplitter();


    //## Other Operations (specified)
      //## Operation: SplitScene%1005085983
      void SplitScene (SCNUt_TriScene& _poScene, CPlane& _roPlane, int _iBackTris, int _iFrontTris);

      //## Operation: ClassifyAndSplitScene%1006556673
      void ClassifyAndSplitScene (SCNUt_TriScene& _poScene, CPlane& _roPlane);

    // Data Members for Class Attributes

      //## Attribute: poFrontScene%3BE8682901D3
      //## begin SCNUt_TriSceneSplitter::poFrontScene%3BE8682901D3.attr preserve=no  public: SCNUt_TriScene * {UA} NULL
      SCNUt_TriScene *poFrontScene;
      //## end SCNUt_TriSceneSplitter::poFrontScene%3BE8682901D3.attr

      //## Attribute: poBackScene%3BE8684B031C
      //## begin SCNUt_TriSceneSplitter::poBackScene%3BE8684B031C.attr preserve=no  public: SCNUt_TriScene * {UA} NULL
      SCNUt_TriScene *poBackScene;
      //## end SCNUt_TriSceneSplitter::poBackScene%3BE8684B031C.attr

    // Additional Public Declarations
      //## begin SCNUt_TriSceneSplitter%3BE867D00383.public preserve=yes
      //## end SCNUt_TriSceneSplitter%3BE867D00383.public

  protected:

    //## Other Operations (specified)
      //## Operation: SplitIn3Triangles%1005085987
      void SplitIn3Triangles (SCNUt_Triangle &SrcTri, SCNUt_Triangle &A, SCNUt_Triangle &B, SCNUt_Triangle &C, CPlane &Plane);

      //## Operation: SplitIn2Triangles%1005085988
      void SplitIn2Triangles (SCNUt_Triangle &SrcTri, SCNUt_Triangle &A, SCNUt_Triangle &B, CPlane &Plane);

      //## Operation: GenerateTriangleFrom2Factors%1005085989
      void GenerateTriangleFrom2Factors (SCNUt_Triangle &SrcTri, int iIsolVX, int ipA, int ipB, int ipC, float fFactor1, float fFactor2, SCNUt_Triangle &DstTri);

      //## Operation: GenerateTriangleFromFactor%1005085990
      void GenerateTriangleFromFactor (SCNUt_Triangle &SrcTri, int ipA, int ipB, int ipC, float fFactor, SCNUt_Triangle &DstTri);

      //## Operation: GetSplitFactor%1005085991
      float GetSplitFactor (CVect3 &pA, CVect3 &pB, CPlane &Plane);

      //## Operation: GetSplitVertexs%1005085992
      void GetSplitVertexs (SCNUt_Triangle &SrcTri, int &C, int &A, int &B);

      //## Operation: CheckWinding%1006687670
      void CheckWinding (SCNUt_Triangle& _roRefTri, SCNUt_Triangle& _roTri);

    // Additional Protected Declarations
      //## begin SCNUt_TriSceneSplitter%3BE867D00383.protected preserve=yes
      //## end SCNUt_TriSceneSplitter%3BE867D00383.protected

  private:
    // Additional Private Declarations
      //## begin SCNUt_TriSceneSplitter%3BE867D00383.private preserve=yes
      //## end SCNUt_TriSceneSplitter%3BE867D00383.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin SCNUt_TriSceneSplitter%3BE867D00383.implementation preserve=yes
      //## end SCNUt_TriSceneSplitter%3BE867D00383.implementation

};

//## begin SCNUt_TriSceneSplitter%3BE867D00383.postscript preserve=yes
//## end SCNUt_TriSceneSplitter%3BE867D00383.postscript

// Class SCNUt_TriSceneSplitter 

//## begin module%3BE867D00383.epilog preserve=yes
//## end module%3BE867D00383.epilog


#endif
