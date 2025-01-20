//## begin module%3A9EC352005A.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3A9EC352005A.cm

//## begin module%3A9EC352005A.cp preserve=no
//## end module%3A9EC352005A.cp

//## Module: CMesh%3A9EC352005A; Pseudo Package specification
//## Source file: i:\Projects\GammaE\E3D\Mesh\CMesh.h

#ifndef CMesh_h
#define CMesh_h 1

//## begin module%3A9EC352005A.additionalIncludes preserve=no
//## end module%3A9EC352005A.additionalIncludes

//## begin module%3A9EC352005A.includes preserve=yes
//## end module%3A9EC352005A.includes

// CGraphBV
#include "E3D\BoundingVolume\GraphBoundVol\CGraphBV.h"
// CBoundingBox
#include "E3D\BoundingVolume\CBoundingBox.h"
// CGraphBV_Manager
#include "E3D\BoundingVolume\GraphBoundVol\CGraphBV_Manager.h"
// CGraphBV_Box
#include "E3D\BoundingVolume\GraphBoundVol\CGraphBV_Box.h"
//## begin module%3A9EC352005A.additionalDeclarations preserve=yes

//---------------------------------------------------------------------------
typedef enum {

	E3D_MESH_NONE,

	E3D_MESH_TRIS,
	E3D_MESH_QUADS,

	E3D_MESH_TRIFANS,
	E3D_MESH_TRISTRIPS,
	E3D_MESH_QUADSTRIPS,

	// Non-indexed primitives
	E3D_MESH_NITRIS,
	E3D_MESH_NIQUADS,
	E3D_MESH_NITRISTRIP,

	E3D_MESH_NUM_MESHTYPES
}EMeshType;
//---------------------------------------------------------------------------
// Mesh creation flags
//---------------------------------------------------------------------------
#define MESH_FIELD_VERTEXS	0x00000001
#define MESH_FIELD_UVCOORDS	0x00000002
#define MESH_FIELD_VNORMALS	0x00000004
#define MESH_FIELD_COLORS 	0x00000010
#define MESH_FIELD_INDEXES	0x00000020
#define MESH_FIELD_TNORMALS	0x00000040
#define MESH_FIELD_UVCOORD2	0x00000080
#define MESH_FIELD_ALL		0x0000003f
#define MESH_FIELD_MULTITEX	0x000000bf
#define MESH_FIELD_COMPLETE	0x000000ff

//## end module%3A9EC352005A.additionalDeclarations


//## begin CMesh%3A9EC352005A.preface preserve=yes
//## end CMesh%3A9EC352005A.preface

//## Class: CMesh%3A9EC352005A
//## Category: E3D::Mesh%3A9EC33D0334
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3B5B466C0258;CBoundingBox { -> }
//## Uses: <unnamed>%3B7068D8000A;CGraphBV_Box { -> }
//## Uses: <unnamed>%3B706C8B035C;CGraphBV { -> }
//## Uses: <unnamed>%3B707B9D017C;CGraphBV_Manager { -> }

class CMesh 
{
  //## begin CMesh%3A9EC352005A.initialDeclarations preserve=yes
  //## end CMesh%3A9EC352005A.initialDeclarations

  public:
    //## Constructors (generated)
      CMesh();

    //## Destructor (generated)
      ~CMesh();


    //## Other Operations (specified)
      //## Operation: Init%995837635
      void Init (int NumVerts, int NumPrims, EMeshType MeshType, unsigned int uiFieldCreationMask);

      //## Operation: ComputeBoundVol%995837631
      void ComputeBoundVol ();

      //## Operation: GetBoundVol%995837632
      CGraphBV * GetBoundVol ();

      //## Operation: CenterMesh%995837633
      CVect3 CenterMesh ();

      //## Operation: GetCenter%995837634
      CVect3 GetCenter ();

      //## Operation: GetMeshType%995837636
      EMeshType GetMeshType ();

    // Data Members for Class Attributes

      //## Attribute: VXs%3B5B43D0028A
      //## begin CMesh::VXs%3B5B43D0028A.attr preserve=no  public: CVect3 * {UA} NULL
      CVect3 *VXs;
      //## end CMesh::VXs%3B5B43D0028A.attr

      //## Attribute: UVs%3B5B43ED017C
      //## begin CMesh::UVs%3B5B43ED017C.attr preserve=no  public: CVect2 * {UA} NULL
      CVect2 *UVs;
      //## end CMesh::UVs%3B5B43ED017C.attr

      //## Attribute: VNs%3B5B43FD005A
      //## begin CMesh::VNs%3B5B43FD005A.attr preserve=no  public: CVect3 * {UA} NULL
      CVect3 *VNs;
      //## end CMesh::VNs%3B5B43FD005A.attr

      //## Attribute: VCs%3B5B44070208
      //## begin CMesh::VCs%3B5B44070208.attr preserve=no  public: CVect4 * {UA} NULL
      CVect4 *VCs;
      //## end CMesh::VCs%3B5B44070208.attr

      //## Attribute: TNs%3C1E6C5900EC
      //## begin CMesh::TNs%3C1E6C5900EC.attr preserve=no  public: CVect3 * {UA} NULL
      CVect3 *TNs;
      //## end CMesh::TNs%3C1E6C5900EC.attr

      //## Attribute: UVs2%3C5ED7C90138
      //## begin CMesh::UVs2%3C5ED7C90138.attr preserve=no  public: CVect2 * {UA} NULL
      CVect2 *UVs2;
      //## end CMesh::UVs2%3C5ED7C90138.attr

      //## Attribute: Idxs%3B5B442802BC
      //## begin CMesh::Idxs%3B5B442802BC.attr preserve=no  public: unsigned short * {UA} NULL
      unsigned short *Idxs;
      //## end CMesh::Idxs%3B5B442802BC.attr

      //## Attribute: usNumVerts%3B5B4FA5012C
      //## begin CMesh::usNumVerts%3B5B4FA5012C.attr preserve=no  public: unsigned short {UA} 0
      unsigned short usNumVerts;
      //## end CMesh::usNumVerts%3B5B4FA5012C.attr

      //## Attribute: usNumIdxs%3B5B443D019A
      //## begin CMesh::usNumIdxs%3B5B443D019A.attr preserve=no  public: unsigned short {UA} 0
      unsigned short usNumIdxs;
      //## end CMesh::usNumIdxs%3B5B443D019A.attr

      //## Attribute: usNumPrims%3B5B4446038E
      //## begin CMesh::usNumPrims%3B5B4446038E.attr preserve=no  public: unsigned short {UA} 0
      unsigned short usNumPrims;
      //## end CMesh::usNumPrims%3B5B4446038E.attr

      //## Attribute: eMeshType%3B5B45210046
      //## begin CMesh::eMeshType%3B5B45210046.attr preserve=no  public: EMeshType {UA} E3D_MESH_NONE
      EMeshType eMeshType;
      //## end CMesh::eMeshType%3B5B45210046.attr

      //## Attribute: BVol%3B5B4E610384
      //## begin CMesh::BVol%3B5B4E610384.attr preserve=no  public: CGraphBV * {UA} 
      CGraphBV *BVol;
      //## end CMesh::BVol%3B5B4E610384.attr

    // Additional Public Declarations
      //## begin CMesh%3A9EC352005A.public preserve=yes
      //## end CMesh%3A9EC352005A.public

  protected:
    // Additional Protected Declarations
      //## begin CMesh%3A9EC352005A.protected preserve=yes
      //## end CMesh%3A9EC352005A.protected

  private:
    // Additional Private Declarations
      //## begin CMesh%3A9EC352005A.private preserve=yes
      //## end CMesh%3A9EC352005A.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CMesh%3A9EC352005A.implementation preserve=yes
      //## end CMesh%3A9EC352005A.implementation

};

//## begin CMesh%3A9EC352005A.postscript preserve=yes
//## end CMesh%3A9EC352005A.postscript

// Class CMesh 

//## begin module%3A9EC352005A.epilog preserve=yes
//## end module%3A9EC352005A.epilog


#endif
