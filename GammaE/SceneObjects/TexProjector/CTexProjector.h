//## begin module%3CB94617013A.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3CB94617013A.cm

//## begin module%3CB94617013A.cp preserve=no
//## end module%3CB94617013A.cp

//## Module: CTexProjector%3CB94617013A; Pseudo Package specification
//## Source file: i:\Projects\GammaE\SceneObjects\TexProjector\CTexProjector.h

#ifndef CTexProjector_h
#define CTexProjector_h 1

//## begin module%3CB94617013A.additionalIncludes preserve=no
//## end module%3CB94617013A.additionalIncludes

//## begin module%3CB94617013A.includes preserve=yes
//## end module%3CB94617013A.includes

// CObject3D_Leaf
#include "Scene\CObject3D_Leaf.h"
//## begin module%3CB94617013A.additionalDeclarations preserve=yes
//## end module%3CB94617013A.additionalDeclarations


//## begin CTexProjector%3CB94617013A.preface preserve=yes
//## end CTexProjector%3CB94617013A.preface

//## Class: CTexProjector%3CB94617013A
//## Category: SceneObjects::TexProjector%3CB945F403CF
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CTexProjector : public CObject3D_Leaf  //## Inherits: <unnamed>%3CB94726027B
{
  //## begin CTexProjector%3CB94617013A.initialDeclarations preserve=yes
  //## end CTexProjector%3CB94617013A.initialDeclarations

  public:
    //## Constructors (generated)
      CTexProjector();

    //## Destructor (generated)
      ~CTexProjector();


    //## Other Operations (specified)
      //## Operation: Setup%1018775600
      void Setup (CMesh* _roSrcMesh, CE3D_Shader* _poShader, CMatrix4x4& _roPrjMatrix);

      //## Operation: Setup%1019152544
      void Setup (CMesh* _roSrcMesh, CE3D_Shader* _poShader, CVect3& _roPos, CVect3& _roDir, float _fXSize, float _fYSize);

    // Additional Public Declarations
      //## begin CTexProjector%3CB94617013A.public preserve=yes
      //## end CTexProjector%3CB94617013A.public

  protected:
    // Data Members for Class Attributes

      //## Attribute: oAuxMesh%3CBCB0EC00BC
      //## begin CTexProjector::oAuxMesh%3CBCB0EC00BC.attr preserve=no  protected: CMesh {UA} 
      CMesh oAuxMesh;
      //## end CTexProjector::oAuxMesh%3CBCB0EC00BC.attr

    // Additional Protected Declarations
      //## begin CTexProjector%3CB94617013A.protected preserve=yes
      //## end CTexProjector%3CB94617013A.protected

  private:
    // Additional Private Declarations
      //## begin CTexProjector%3CB94617013A.private preserve=yes
      //## end CTexProjector%3CB94617013A.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CTexProjector%3CB94617013A.implementation preserve=yes
      //## end CTexProjector%3CB94617013A.implementation

};

//## begin CTexProjector%3CB94617013A.postscript preserve=yes
//## end CTexProjector%3CB94617013A.postscript

// Class CTexProjector 

//## begin module%3CB94617013A.epilog preserve=yes
//## end module%3CB94617013A.epilog


#endif
