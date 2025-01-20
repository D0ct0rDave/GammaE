//## begin module%3C2BCE35036E.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3C2BCE35036E.cm

//## begin module%3C2BCE35036E.cp preserve=no
//## end module%3C2BCE35036E.cp

//## Module: SCNUt_TriSceneAccumulator%3C2BCE35036E; Pseudo Package specification
//## Source file: i:\Projects\GammaE\Scene\SceneUtils\SCNUt_TriSceneAccumulator.h

#ifndef SCNUt_TriSceneAccumulator_h
#define SCNUt_TriSceneAccumulator_h 1

//## begin module%3C2BCE35036E.additionalIncludes preserve=no
//## end module%3C2BCE35036E.additionalIncludes

//## begin module%3C2BCE35036E.includes preserve=yes
//## end module%3C2BCE35036E.includes

// SCNUt_TriScene
#include "Scene\SceneUtils\SCNUt_TriScene.h"
//## begin module%3C2BCE35036E.additionalDeclarations preserve=yes
//## end module%3C2BCE35036E.additionalDeclarations


//## begin SCNUt_TriSceneAccumulator%3C2BCE35036E.preface preserve=yes
//## end SCNUt_TriSceneAccumulator%3C2BCE35036E.preface

//## Class: SCNUt_TriSceneAccumulator%3C2BCE35036E
//## Category: Scene::SceneUtils%3AC22916003C
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class SCNUt_TriSceneAccumulator : public SCNUt_TriScene  //## Inherits: <unnamed>%3C2BCE3F008E
{
  //## begin SCNUt_TriSceneAccumulator%3C2BCE35036E.initialDeclarations preserve=yes
  //## end SCNUt_TriSceneAccumulator%3C2BCE35036E.initialDeclarations

  public:
    //## Constructors (generated)
      SCNUt_TriSceneAccumulator();

    //## Destructor (generated)
      ~SCNUt_TriSceneAccumulator();


    //## Other Operations (specified)
      //## Operation: AddTriScene%1009496919
      void AddTriScene (SCNUt_TriScene* _poScn);

      //## Operation: Init%1012510459
      virtual void Init (int _iNumTris);

      //## Operation: Init%1012510460
      virtual void Init (int _iNumTris, int _iRealloc);

    // Additional Public Declarations
      //## begin SCNUt_TriSceneAccumulator%3C2BCE35036E.public preserve=yes
      //## end SCNUt_TriSceneAccumulator%3C2BCE35036E.public

  protected:
    // Additional Protected Declarations
      //## begin SCNUt_TriSceneAccumulator%3C2BCE35036E.protected preserve=yes
      //## end SCNUt_TriSceneAccumulator%3C2BCE35036E.protected

  private:
    // Data Members for Class Attributes

      //## Attribute: iMaxTris%3C59AEEE00D4
      //## begin SCNUt_TriSceneAccumulator::iMaxTris%3C59AEEE00D4.attr preserve=no  private: int {UA} 0
      int iMaxTris;
      //## end SCNUt_TriSceneAccumulator::iMaxTris%3C59AEEE00D4.attr

      //## Attribute: iRealloc%3C59AF2601F7
      //## begin SCNUt_TriSceneAccumulator::iRealloc%3C59AF2601F7.attr preserve=no  private: int {UA} 100
      int iRealloc;
      //## end SCNUt_TriSceneAccumulator::iRealloc%3C59AF2601F7.attr

    // Additional Private Declarations
      //## begin SCNUt_TriSceneAccumulator%3C2BCE35036E.private preserve=yes
      //## end SCNUt_TriSceneAccumulator%3C2BCE35036E.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin SCNUt_TriSceneAccumulator%3C2BCE35036E.implementation preserve=yes
      //## end SCNUt_TriSceneAccumulator%3C2BCE35036E.implementation

};

//## begin SCNUt_TriSceneAccumulator%3C2BCE35036E.postscript preserve=yes
//## end SCNUt_TriSceneAccumulator%3C2BCE35036E.postscript

// Class SCNUt_TriSceneAccumulator 

//## begin module%3C2BCE35036E.epilog preserve=yes
//## end module%3C2BCE35036E.epilog


#endif
