//## begin module%3BE6F90101CB.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3BE6F90101CB.cm

//## begin module%3BE6F90101CB.cp preserve=no
//## end module%3BE6F90101CB.cp

//## Module: SCNUt_TriSceneLoader%3BE6F90101CB; Pseudo Package specification
//## Source file: i:\Projects\GammaE\Scene\SceneUtils\TriScnLoader\SCNUt_TriSceneLoader.h

#ifndef SCNUt_TriSceneLoader_h
#define SCNUt_TriSceneLoader_h 1

//## begin module%3BE6F90101CB.additionalIncludes preserve=no
//## end module%3BE6F90101CB.additionalIncludes

//## begin module%3BE6F90101CB.includes preserve=yes
//## end module%3BE6F90101CB.includes

// SCNUt_TriScene
#include "Scene\SceneUtils\SCNUt_TriScene.h"
//## begin module%3BE6F90101CB.additionalDeclarations preserve=yes
//## end module%3BE6F90101CB.additionalDeclarations


//## begin SCNUt_TriSceneLoader%3BE6F90101CB.preface preserve=yes
//## end SCNUt_TriSceneLoader%3BE6F90101CB.preface

//## Class: SCNUt_TriSceneLoader%3BE6F90101CB
//## Category: Scene::SceneUtils::TriScnLoader%3C76D6210116
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3BE6F93A0231;SCNUt_TriScene { -> }

class SCNUt_TriSceneLoader 
{
  //## begin SCNUt_TriSceneLoader%3BE6F90101CB.initialDeclarations preserve=yes
  //## end SCNUt_TriSceneLoader%3BE6F90101CB.initialDeclarations

  public:
    //## Constructors (generated)
      SCNUt_TriSceneLoader();

    //## Destructor (generated)
      ~SCNUt_TriSceneLoader();


    //## Other Operations (specified)
      //## Operation: poLoad%1004992830
      SCNUt_TriScene * poLoad (char* _szFilename);

    // Data Members for Class Attributes

      //## Attribute: pszMaterials%3BE865120258
      //## begin SCNUt_TriSceneLoader::pszMaterials%3BE865120258.attr preserve=no  public: char * * {UA} NULL
      char * *pszMaterials;
      //## end SCNUt_TriSceneLoader::pszMaterials%3BE865120258.attr

      //## Attribute: iNumMaterials%3BE865240394
      //## begin SCNUt_TriSceneLoader::iNumMaterials%3BE865240394.attr preserve=no  public: int {UA} 0
      int iNumMaterials;
      //## end SCNUt_TriSceneLoader::iNumMaterials%3BE865240394.attr

    // Additional Public Declarations
      //## begin SCNUt_TriSceneLoader%3BE6F90101CB.public preserve=yes
      //## end SCNUt_TriSceneLoader%3BE6F90101CB.public

  protected:
    // Additional Protected Declarations
      //## begin SCNUt_TriSceneLoader%3BE6F90101CB.protected preserve=yes
      //## end SCNUt_TriSceneLoader%3BE6F90101CB.protected

  private:
    // Additional Private Declarations
      //## begin SCNUt_TriSceneLoader%3BE6F90101CB.private preserve=yes
      //## end SCNUt_TriSceneLoader%3BE6F90101CB.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin SCNUt_TriSceneLoader%3BE6F90101CB.implementation preserve=yes
      //## end SCNUt_TriSceneLoader%3BE6F90101CB.implementation

};

//## begin SCNUt_TriSceneLoader%3BE6F90101CB.postscript preserve=yes
//## end SCNUt_TriSceneLoader%3BE6F90101CB.postscript

// Class SCNUt_TriSceneLoader 

//## begin module%3BE6F90101CB.epilog preserve=yes
//## end module%3BE6F90101CB.epilog


#endif
