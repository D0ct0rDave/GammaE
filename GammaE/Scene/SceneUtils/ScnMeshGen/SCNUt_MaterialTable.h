//## begin module%3BFEE7220290.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3BFEE7220290.cm

//## begin module%3BFEE7220290.cp preserve=no
//## end module%3BFEE7220290.cp

//## Module: SCNUt_MaterialTable%3BFEE7220290; Pseudo Package specification
//## Source file: i:\Projects\GammaE\Scene\SceneUtils\ScnMeshGen\SCNUt_MaterialTable.h

#ifndef SCNUt_MaterialTable_h
#define SCNUt_MaterialTable_h 1

//## begin module%3BFEE7220290.additionalIncludes preserve=no
//## end module%3BFEE7220290.additionalIncludes

//## begin module%3BFEE7220290.includes preserve=yes
//## end module%3BFEE7220290.includes

// GammaE_E3D
#include "E3D\GammaE_E3D.h"
//## begin module%3BFEE7220290.additionalDeclarations preserve=yes
//## end module%3BFEE7220290.additionalDeclarations


//## begin SCNUt_MaterialTable%3BFEE7220290.preface preserve=yes
//## end SCNUt_MaterialTable%3BFEE7220290.preface

//## Class: SCNUt_MaterialTable%3BFEE7220290
//## Category: Scene::SceneUtils::ScnMeshGen%3C76D598034A
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3C1BF4C40230;GammaE_E3D { -> }

class SCNUt_MaterialTable 
{
  //## begin SCNUt_MaterialTable%3BFEE7220290.initialDeclarations preserve=yes
  //## end SCNUt_MaterialTable%3BFEE7220290.initialDeclarations

  public:
    //## Constructors (generated)
      SCNUt_MaterialTable();

      SCNUt_MaterialTable(const SCNUt_MaterialTable &right);

    //## Destructor (generated)
      ~SCNUt_MaterialTable();

    //## Assignment Operation (generated)
      const SCNUt_MaterialTable & operator=(const SCNUt_MaterialTable &right);


    //## Other Operations (specified)
      //## Operation: Init%1006556681
      void Init (int _iMaxShaders);

      //## Operation: SetShader%1006556682
      void SetShader (int _iShIdx, CE3D_Shader *_poSh);

      //## Operation: iAddShader%1009552694
      int iAddShader (CE3D_Shader *_poSh);

      //## Operation: poGetShader%1006556683
      CE3D_Shader * poGetShader (int _iShIdx);

    // Additional Public Declarations
      //## begin SCNUt_MaterialTable%3BFEE7220290.public preserve=yes
      //## end SCNUt_MaterialTable%3BFEE7220290.public

  protected:
    // Additional Protected Declarations
      //## begin SCNUt_MaterialTable%3BFEE7220290.protected preserve=yes
      //## end SCNUt_MaterialTable%3BFEE7220290.protected

  private:
    // Data Members for Class Attributes

      //## Attribute: iMaxShaders%3C2CA3CA0186
      //## begin SCNUt_MaterialTable::iMaxShaders%3C2CA3CA0186.attr preserve=no  private: int {UA} 0
      int iMaxShaders;
      //## end SCNUt_MaterialTable::iMaxShaders%3C2CA3CA0186.attr

      //## Attribute: poShaders%3BFEE73D039D
      //## begin SCNUt_MaterialTable::poShaders%3BFEE73D039D.attr preserve=no  private: CE3D_Shader* * {UA} NULL
      CE3D_Shader* *poShaders;
      //## end SCNUt_MaterialTable::poShaders%3BFEE73D039D.attr

    // Additional Private Declarations
      //## begin SCNUt_MaterialTable%3BFEE7220290.private preserve=yes
      //## end SCNUt_MaterialTable%3BFEE7220290.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin SCNUt_MaterialTable%3BFEE7220290.implementation preserve=yes
      //## end SCNUt_MaterialTable%3BFEE7220290.implementation

};

//## begin SCNUt_MaterialTable%3BFEE7220290.postscript preserve=yes
//## end SCNUt_MaterialTable%3BFEE7220290.postscript

// Class SCNUt_MaterialTable 

//## begin module%3BFEE7220290.epilog preserve=yes
//## end module%3BFEE7220290.epilog


#endif
