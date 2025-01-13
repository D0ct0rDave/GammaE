//## begin module%3AB910BA0028.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3AB910BA0028.cm

//## begin module%3AB910BA0028.cp preserve=no
//## end module%3AB910BA0028.cp

//## Module: CLoader3DS%3AB910BA0028; Pseudo Package specification
//## Source file: i:\Projects\GammaE\Scene\3D_Loaders\3DSLoader\CLoader3DS.h

#ifndef CLoader3DS_h
#define CLoader3DS_h 1

//## begin module%3AB910BA0028.additionalIncludes preserve=no
//## end module%3AB910BA0028.additionalIncludes

//## begin module%3AB910BA0028.includes preserve=yes
#include "E3D/GammaE_E3D.h"
//## end module%3AB910BA0028.includes

// CObject3D
#include "Scene\CObject3D.h"
// CObject3D_Node
#include "Scene\CObject3D_Node.h"
// CObject3D_Leaf
#include "Scene\CObject3D_Leaf.h"
// T3DS_Chunk
#include "Scene\3D_Loaders\3DSLoader\T3DS_Chunk.h"
// C3DLoader
#include "Scene\3D_Loaders\C3DLoader.h"
//## begin module%3AB910BA0028.additionalDeclarations preserve=yes

//---------------------------------------------------------------------------
//## end module%3AB910BA0028.additionalDeclarations


//## begin CLoader3DS%3AB910BA0028.preface preserve=yes

#define		MAX_TRIMESHOBJS		4096	//	4 KMeshes

//## end CLoader3DS%3AB910BA0028.preface

//## Class: CLoader3DS%3AB910BA0028
//## Category: Scene::3D_Loaders::3DSLoader%3AB910B101E0
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3AB9112D0000;CObject3D { -> }
//## Uses: <unnamed>%3AB9124A03B6;T3DS_Chunk { -> }
//## Uses: <unnamed>%3AB940B501A4;CObject3D_Leaf { -> }
//## Uses: <unnamed>%3AB940B70046;CObject3D_Node { -> }

class CLoader3DS : public C3DLoader  //## Inherits: <unnamed>%3AC0F8C8023A
{
  //## begin CLoader3DS%3AB910BA0028.initialDeclarations preserve=yes
  //## end CLoader3DS%3AB910BA0028.initialDeclarations

  public:
    //## Constructors (generated)
      CLoader3DS();

    //## Destructor (generated)
      ~CLoader3DS();


    //## Other Operations (specified)
      //## Operation: ReadChunk%985207003
      void ReadChunk (char *Stream, T3DS_Chunk &Chunk);

      //## Operation: ParseLocalAxis%985214440
      void ParseLocalAxis (char *Buffer, CMatrix4x4 &Matrix);

      //## Operation: ParseVertexCoordinates%985214441
      CVect3 * ParseVertexCoordinates (char *Buffer, unsigned short &usNumVertexs);

      //## Operation: ParseTextureCoordinates%985214442
      CVect2 * ParseTextureCoordinates (char* Buffer, unsigned short &usNumUVCoords);

      //## Operation: ParseFaces%985298868
      unsigned short * ParseFaces (char *Buffer, unsigned short& usNumFaces);

      //## Operation: CreateMeshFromFields%985298867
      CMesh * CreateMeshFromFields (int iNumFaces, int iNumVertexs, unsigned short *Idxs, CVect3 *VXs, CVect2* UVs);

      //## Operation: ParseChunks%985207004
      int ParseChunks (CObject3D* *Node, char *Stream, unsigned int StreamSize);

      //## Operation: pLoad%985903376
      virtual CObject3D * pLoad (char* Filename);

      //## Operation: ParseMaterial%1001203802
      void ParseMaterial (char *pBuffer);

    // Additional Public Declarations
      //## begin CLoader3DS%3AB910BA0028.public preserve=yes
      //## end CLoader3DS%3AB910BA0028.public

  protected:
    // Additional Protected Declarations
      //## begin CLoader3DS%3AB910BA0028.protected preserve=yes
      //## end CLoader3DS%3AB910BA0028.protected

  private:
    // Data Members for Class Attributes

      //## Attribute: pMatTable%3BAE06020063
      //## begin CLoader3DS::pMatTable%3BAE06020063.attr preserve=no  private: CE3D_Shader *[1024] {UA} 
      CE3D_Shader *pMatTable[1024];
      //## end CLoader3DS::pMatTable%3BAE06020063.attr

      //## Attribute: iMaxMats%3BAE060D0217
      //## begin CLoader3DS::iMaxMats%3BAE060D0217.attr preserve=no  private: int {UA} 0
      int iMaxMats;
      //## end CLoader3DS::iMaxMats%3BAE060D0217.attr

      //## Attribute: iCurMat%3BAE06110191
      //## begin CLoader3DS::iCurMat%3BAE06110191.attr preserve=no  private: int {UA} 0
      int iCurMat;
      //## end CLoader3DS::iCurMat%3BAE06110191.attr

    // Additional Private Declarations
      //## begin CLoader3DS%3AB910BA0028.private preserve=yes
      //## end CLoader3DS%3AB910BA0028.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CLoader3DS%3AB910BA0028.implementation preserve=yes
      //## end CLoader3DS%3AB910BA0028.implementation

};

//## begin CLoader3DS%3AB910BA0028.postscript preserve=yes
//## end CLoader3DS%3AB910BA0028.postscript

// Class CLoader3DS 

//## begin module%3AB910BA0028.epilog preserve=yes
//## end module%3AB910BA0028.epilog


#endif
