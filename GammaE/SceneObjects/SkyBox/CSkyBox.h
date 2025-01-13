//## begin module%3B59802101A4.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3B59802101A4.cm

//## begin module%3B59802101A4.cp preserve=no
//## end module%3B59802101A4.cp

//## Module: CSkyBox%3B59802101A4; Pseudo Package specification
//## Source file: i:\Projects\GammaE\SceneObjects\SkyBox\CSkyBox.h

#ifndef CSkyBox_h
#define CSkyBox_h 1

//## begin module%3B59802101A4.additionalIncludes preserve=no
//## end module%3B59802101A4.additionalIncludes

//## begin module%3B59802101A4.includes preserve=yes
//## end module%3B59802101A4.includes

// CObject3D_Transf
#include "Scene\CObject3D_Transf.h"
// CObject3D_Node
#include "Scene\CObject3D_Node.h"
// CObject3D_Leaf
#include "Scene\CObject3D_Leaf.h"
//## begin module%3B59802101A4.additionalDeclarations preserve=yes
//## end module%3B59802101A4.additionalDeclarations


//## begin CSkyBox%3B59802101A4.preface preserve=yes
//## end CSkyBox%3B59802101A4.preface

//## Class: CSkyBox%3B59802101A4
//## Category: SceneObjects::SkyBox%3B5980040280
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3B59997A02EE;CObject3D_Leaf { -> }
//## Uses: <unnamed>%3CC2942403B4;CObject3D_Node { -> }

class CSkyBox : public CObject3D_Transf  //## Inherits: <unnamed>%3CC2942F0355
{
  //## begin CSkyBox%3B59802101A4.initialDeclarations preserve=yes
  //## end CSkyBox%3B59802101A4.initialDeclarations

  public:
    //## Constructors (generated)
      CSkyBox();

    //## Destructor (generated)
      virtual ~CSkyBox();


    //## Other Operations (specified)
      //## Operation: InitSkyBox%995721543
      void InitSkyBox (float fSize, CVect3& Center, float fRoll, CE3D_Shader* *Materials);

    // Additional Public Declarations
      //## begin CSkyBox%3B59802101A4.public preserve=yes
      //## end CSkyBox%3B59802101A4.public

  protected:
    // Additional Protected Declarations
      //## begin CSkyBox%3B59802101A4.protected preserve=yes
      //## end CSkyBox%3B59802101A4.protected

  private:
    // Data Members for Class Attributes

      //## Attribute: MeshSides%3B5981A1026C
      //## begin CSkyBox::MeshSides%3B5981A1026C.attr preserve=no  private: CMesh*[6] {UA} 
      CMesh* MeshSides[6];
      //## end CSkyBox::MeshSides%3B5981A1026C.attr

      //## Attribute: ObjSides%3B5984180302
      //## begin CSkyBox::ObjSides%3B5984180302.attr preserve=no  private: CObject3D_Leaf *[6] {UA} 
      CObject3D_Leaf *ObjSides[6];
      //## end CSkyBox::ObjSides%3B5984180302.attr

      //## Attribute: MatsSides%3B5981AB037A
      //## begin CSkyBox::MatsSides%3B5981AB037A.attr preserve=no  private: CE3D_Shader *[6] {UA} 
      CE3D_Shader *MatsSides[6];
      //## end CSkyBox::MatsSides%3B5981AB037A.attr

      //## Attribute: poNode%3CC294680195
      //## begin CSkyBox::poNode%3CC294680195.attr preserve=no  private: CObject3D_Node* {UA} NULL
      CObject3D_Node* poNode;
      //## end CSkyBox::poNode%3CC294680195.attr

    // Additional Private Declarations
      //## begin CSkyBox%3B59802101A4.private preserve=yes
      //## end CSkyBox%3B59802101A4.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CSkyBox%3B59802101A4.implementation preserve=yes
      //## end CSkyBox%3B59802101A4.implementation

};

//## begin CSkyBox%3B59802101A4.postscript preserve=yes
//## end CSkyBox%3B59802101A4.postscript

// Class CSkyBox 

//## begin module%3B59802101A4.epilog preserve=yes
//## end module%3B59802101A4.epilog


#endif
