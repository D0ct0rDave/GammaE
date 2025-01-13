//## begin module%3AC229AA038E.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3AC229AA038E.cm

//## begin module%3AC229AA038E.cp preserve=no
//## end module%3AC229AA038E.cp

//## Module: SCNUt_TriScene%3AC229AA038E; Pseudo Package specification
//## Source file: i:\Projects\GammaE\Scene\SceneUtils\SCNUt_TriScene.h

#ifndef SCNUt_TriScene_h
#define SCNUt_TriScene_h 1

//## begin module%3AC229AA038E.additionalIncludes preserve=no
//## end module%3AC229AA038E.additionalIncludes

//## begin module%3AC229AA038E.includes preserve=yes
//## end module%3AC229AA038E.includes

// SCNUt_Triangle
#include "Scene\SceneUtils\SCNUt_Triangle.h"
//## begin module%3AC229AA038E.additionalDeclarations preserve=yes
//## end module%3AC229AA038E.additionalDeclarations


//## begin SCNUt_TriScene%3AC229AA038E.preface preserve=yes
//## end SCNUt_TriScene%3AC229AA038E.preface

//## Class: SCNUt_TriScene%3AC229AA038E
//## Category: Scene::SceneUtils%3AC22916003C
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3AC22AB703DE;SCNUt_Triangle { -> }

class SCNUt_TriScene 
{
  //## begin SCNUt_TriScene%3AC229AA038E.initialDeclarations preserve=yes
  //## end SCNUt_TriScene%3AC229AA038E.initialDeclarations

  public:
    //## Constructors (generated)
      SCNUt_TriScene();

    //## Destructor (generated)
      ~SCNUt_TriScene();

    //## Assignment Operation (generated)
      const SCNUt_TriScene & operator=(const SCNUt_TriScene &right);


    //## Other Operations (specified)
      //## Operation: Init%985803487
      virtual void Init (int _iNumTris);

    // Data Members for Class Attributes

      //## Attribute: Tris%3AC22AA101D6
      //## begin SCNUt_TriScene::Tris%3AC22AA101D6.attr preserve=no  public: SCNUt_Triangle * {UA} 0
      SCNUt_Triangle *Tris;
      //## end SCNUt_TriScene::Tris%3AC22AA101D6.attr

      //## Attribute: NumTris%3AC22AA90258
      //## begin SCNUt_TriScene::NumTris%3AC22AA90258.attr preserve=no  public: int {UA} 0
      int NumTris;
      //## end SCNUt_TriScene::NumTris%3AC22AA90258.attr

    // Additional Public Declarations
      //## begin SCNUt_TriScene%3AC229AA038E.public preserve=yes
      //## end SCNUt_TriScene%3AC229AA038E.public

  protected:
    // Additional Protected Declarations
      //## begin SCNUt_TriScene%3AC229AA038E.protected preserve=yes
      //## end SCNUt_TriScene%3AC229AA038E.protected

  private:
    // Additional Private Declarations
      //## begin SCNUt_TriScene%3AC229AA038E.private preserve=yes
      //## end SCNUt_TriScene%3AC229AA038E.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin SCNUt_TriScene%3AC229AA038E.implementation preserve=yes
      //## end SCNUt_TriScene%3AC229AA038E.implementation

};

//## begin SCNUt_TriScene%3AC229AA038E.postscript preserve=yes
//## end SCNUt_TriScene%3AC229AA038E.postscript

// Class SCNUt_TriScene 

//## begin module%3AC229AA038E.epilog preserve=yes
//## end module%3AC229AA038E.epilog


#endif
