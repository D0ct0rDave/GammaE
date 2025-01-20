//	  %X% %Q% %Z% %W%



#ifndef CMesh_h
#define CMesh_h 1


#include "Materials/CGColor.h"
// CGraphBV
#include "BoundingVolume\GraphBoundVol\CGraphBV.h"
// CBoundingBox
#include "BoundingVolume\CBoundingBox.h"
// CGraphBV_Manager
#include "BoundingVolume\GraphBoundVol\CGraphBV_Manager.h"
// CGraphBV_Box
#include "BoundingVolume\GraphBoundVol\CGraphBV_Box.h"

//-----------------------------------------------------------------------------
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
//-----------------------------------------------------------------------------
// Mesh creation flags
//-----------------------------------------------------------------------------
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






class CMesh 
{
    
  public:
          CMesh();

          ~CMesh();


                void Init (int NumVerts, int NumPrims, EMeshType MeshType, unsigned int uiFieldCreationMask);

            void ComputeBoundVol ();

            CGraphBV * GetBoundVol ();

            CVect3 CenterMesh ();

            CVect3 GetCenter ();

            EMeshType GetMeshType ();

    // Data Members for Class Attributes

                  CVect3 *VXs;
      
                  CVect2 *UVs;
      
                  CVect3 *VNs;
      
                  CGColor *VCs;
      
                  CVect3 *TNs;
      
                  CVect2 *UVs2;
      
                  unsigned short *Idxs;
      
                  unsigned short usNumVerts;
      
                  unsigned short usNumIdxs;
      
                  unsigned short usNumPrims;
      
                  EMeshType eMeshType;
      
                  CGraphBV *BVol;
      
    // Additional Public Declarations
            
  protected:
    // Additional Protected Declarations
            
  private:
    // Additional Private Declarations
            
  private:     // Additional Implementation Declarations
            
};


// Class CMesh 



#endif
