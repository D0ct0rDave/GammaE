//## begin module%3C509C7D0320.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3C509C7D0320.cm

//## begin module%3C509C7D0320.cp preserve=no
//## end module%3C509C7D0320.cp

//## Module: TDefferredMeshEntry%3C509C7D0320; Pseudo Package specification
//## Source file: i:\Projects\GammaE\E3D\MeshDB\TDefferredMeshEntry.h

#ifndef TDefferredMeshEntry_h
#define TDefferredMeshEntry_h 1

//## begin module%3C509C7D0320.additionalIncludes preserve=no
//## end module%3C509C7D0320.additionalIncludes

//## begin module%3C509C7D0320.includes preserve=yes
//## end module%3C509C7D0320.includes

// eE3D_MeshType
#include "E3D\MeshDB\eE3D_MeshType.h"
// CE3D_Shader
#include "E3D\Shaders\CE3D_Shader.h"
// GammaE_Math
#include "Math\GammaE_Math.h"
//## begin module%3C509C7D0320.additionalDeclarations preserve=yes
//## end module%3C509C7D0320.additionalDeclarations


//## begin TDefferredMeshEntry%3C509C7D0320.preface preserve=yes
//## end TDefferredMeshEntry%3C509C7D0320.preface

//## Class: TDefferredMeshEntry%3C509C7D0320
//## Category: E3D::MeshDB%3C509C55008D
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3C509CA60025;eE3D_MeshType { -> }
//## Uses: <unnamed>%3C69A3CB024B;CE3D_Shader { -> }
//## Uses: <unnamed>%3C509E7D016D;GammaE_Math { -> }

struct TDefferredMeshEntry 
{
  //## begin TDefferredMeshEntry%3C509C7D0320.initialDeclarations preserve=yes
  //## end TDefferredMeshEntry%3C509C7D0320.initialDeclarations

    // Data Members for Class Attributes

      //## Attribute: poMesh%3C509C8A0292
      //## begin TDefferredMeshEntry::poMesh%3C509C8A0292.attr preserve=no  public: void * {UA} NULL
      void *poMesh;
      //## end TDefferredMeshEntry::poMesh%3C509C8A0292.attr

      //## Attribute: eMeshType%3C509CA80277
      //## begin TDefferredMeshEntry::eMeshType%3C509CA80277.attr preserve=no  public: eE3D_MeshType {UA} 
      eE3D_MeshType eMeshType;
      //## end TDefferredMeshEntry::eMeshType%3C509CA80277.attr

      //## Attribute: oMatrix%3C509CB300C4
      //## begin TDefferredMeshEntry::oMatrix%3C509CB300C4.attr preserve=no  public: CMatrix4x4 {UA} 
      CMatrix4x4 oMatrix;
      //## end TDefferredMeshEntry::oMatrix%3C509CB300C4.attr

      //## Attribute: poShader%3C509CC60234
      //## begin TDefferredMeshEntry::poShader%3C509CC60234.attr preserve=no  public: CE3D_Shader * {UA} 
      CE3D_Shader *poShader;
      //## end TDefferredMeshEntry::poShader%3C509CC60234.attr

      //## Attribute: uiLights%3D837ACE02EF
      //## begin TDefferredMeshEntry::uiLights%3D837ACE02EF.attr preserve=no  public: unsigned int {UA} 
      unsigned int uiLights;
      //## end TDefferredMeshEntry::uiLights%3D837ACE02EF.attr

  public:
    // Additional Public Declarations
      //## begin TDefferredMeshEntry%3C509C7D0320.public preserve=yes
      //## end TDefferredMeshEntry%3C509C7D0320.public

  protected:
    // Additional Protected Declarations
      //## begin TDefferredMeshEntry%3C509C7D0320.protected preserve=yes
      //## end TDefferredMeshEntry%3C509C7D0320.protected

  private:
    // Additional Private Declarations
      //## begin TDefferredMeshEntry%3C509C7D0320.private preserve=yes
      //## end TDefferredMeshEntry%3C509C7D0320.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin TDefferredMeshEntry%3C509C7D0320.implementation preserve=yes
      //## end TDefferredMeshEntry%3C509C7D0320.implementation

};

//## begin TDefferredMeshEntry%3C509C7D0320.postscript preserve=yes
//## end TDefferredMeshEntry%3C509C7D0320.postscript

// Class TDefferredMeshEntry 

//## begin module%3C509C7D0320.epilog preserve=yes
//## end module%3C509C7D0320.epilog


#endif
