//## begin module%3C50A9EA01AF.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3C50A9EA01AF.cm

//## begin module%3C50A9EA01AF.cp preserve=no
//## end module%3C50A9EA01AF.cp

//## Module: CObject3D_CompiledLeaf%3C50A9EA01AF; Pseudo Package specification
//## Source file: i:\Projects\GammaE\Scene\CObject3D_CompiledLeaf.h

#ifndef CObject3D_CompiledLeaf_h
#define CObject3D_CompiledLeaf_h 1

//## begin module%3C50A9EA01AF.additionalIncludes preserve=no
//## end module%3C50A9EA01AF.additionalIncludes

//## begin module%3C50A9EA01AF.includes preserve=yes
//## end module%3C50A9EA01AF.includes

// CObject3D
#include "Scene\CObject3D.h"
//## begin module%3C50A9EA01AF.additionalDeclarations preserve=yes
//## end module%3C50A9EA01AF.additionalDeclarations


//## begin CObject3D_CompiledLeaf%3C50A9EA01AF.preface preserve=yes
//## end CObject3D_CompiledLeaf%3C50A9EA01AF.preface

//## Class: CObject3D_CompiledLeaf%3C50A9EA01AF
//## Category: Scene%3AA2567D00C8
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CObject3D_CompiledLeaf : public CObject3D  //## Inherits: <unnamed>%3C50AAA40347
{
  //## begin CObject3D_CompiledLeaf%3C50A9EA01AF.initialDeclarations preserve=yes
  //## end CObject3D_CompiledLeaf%3C50A9EA01AF.initialDeclarations

  public:
    //## Constructors (generated)
      CObject3D_CompiledLeaf();

    //## Destructor (generated)
      ~CObject3D_CompiledLeaf();


    //## Other Operations (specified)
      //## Operation: Render%1011911202
      virtual void Render ();

      //## Operation: SetCMesh%1011911203
      void SetCMesh (CCompiledMesh *_poCMesh);

      //## Operation: poGetCMesh%1011911205
      CCompiledMesh * poGetCMesh ();

      //## Operation: poGetBoundVol%1011911206
      virtual CGraphBV* poGetBoundVol ();

      //## Operation: ComputeBoundVol%1011911207
      virtual void ComputeBoundVol ();

      //## Operation: SetShader%1011999904
      void SetShader (CE3D_Shader* _poShader);

      //## Operation: poGetShader%1011999905
      CE3D_Shader* poGetShader ();

    // Additional Public Declarations
      //## begin CObject3D_CompiledLeaf%3C50A9EA01AF.public preserve=yes
      //## end CObject3D_CompiledLeaf%3C50A9EA01AF.public

  protected:
    // Additional Protected Declarations
      //## begin CObject3D_CompiledLeaf%3C50A9EA01AF.protected preserve=yes
      //## end CObject3D_CompiledLeaf%3C50A9EA01AF.protected

  private:
    // Data Members for Class Attributes

      //## Attribute: poCMesh%3C50AA020286
      //## begin CObject3D_CompiledLeaf::poCMesh%3C50AA020286.attr preserve=no  private: CCompiledMesh * {UA} NULL
      CCompiledMesh *poCMesh;
      //## end CObject3D_CompiledLeaf::poCMesh%3C50AA020286.attr

      //## Attribute: poShader%3C51EFFF0133
      //## begin CObject3D_CompiledLeaf::poShader%3C51EFFF0133.attr preserve=no  private: CE3D_Shader * {UA} NULL
      CE3D_Shader *poShader;
      //## end CObject3D_CompiledLeaf::poShader%3C51EFFF0133.attr

    // Additional Private Declarations
      //## begin CObject3D_CompiledLeaf%3C50A9EA01AF.private preserve=yes
      //## end CObject3D_CompiledLeaf%3C50A9EA01AF.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CObject3D_CompiledLeaf%3C50A9EA01AF.implementation preserve=yes
      //## end CObject3D_CompiledLeaf%3C50A9EA01AF.implementation

};

//## begin CObject3D_CompiledLeaf%3C50A9EA01AF.postscript preserve=yes
//## end CObject3D_CompiledLeaf%3C50A9EA01AF.postscript

// Class CObject3D_CompiledLeaf 

//## begin module%3C50A9EA01AF.epilog preserve=yes
//## end module%3C50A9EA01AF.epilog


#endif
