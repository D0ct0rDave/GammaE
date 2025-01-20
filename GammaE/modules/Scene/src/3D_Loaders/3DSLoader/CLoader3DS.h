//	  %X% %Q% %Z% %W%

#ifndef CLoader3DS_h
#define CLoader3DS_h 1

#include "GammaE_E3D.h"

// CObject3D
#include "..\..\CObject3D.h"
// CObject3D_Node
#include "..\..\CObject3D_Node.h"
// CObject3D_Leaf
#include "..\..\CObject3D_Leaf.h"
// T3DS_Chunk
#include "T3DS_Chunk.h"
// C3DLoader
#include "..\C3DLoader.h"

//-----------------------------------------------------------------------------

#define     MAX_TRIMESHOBJS     4096    //	4 KMeshes

class CLoader3DS : public C3DLoader
{

public: CLoader3DS();

    ~CLoader3DS();

    void ReadChunk (char *Stream, T3DS_Chunk &Chunk);

    void ParseLocalAxis (char *Buffer, CMatrix4x4 &Matrix);

    CVect3 *ParseVertexCoordinates (char *Buffer, unsigned short &usNumVertexs);

    CVect2 *ParseTextureCoordinates (char *Buffer, unsigned short &usNumUVCoords);

    unsigned short *ParseFaces (char *Buffer, unsigned short & usNumFaces);

    CMesh *CreateMeshFromFields (int iNumFaces, int iNumVertexs, unsigned short *Idxs, CVect3 *VXs, CVect2 *UVs);

    int ParseChunks (CObject3D * *Node, char *Stream, unsigned int StreamSize);

    virtual CObject3D *pLoad (char *Filename);

    void ParseMaterial (char *pBuffer);

     // Additional Public Declarations
protected:
     // Additional Protected Declarations
private:
    // Data Members for Class Attributes

    CE3D_Shader *pMatTable[1024];

    int iMaxMats;

    int iCurMat;

     // Additional Private Declarations
private:
    // Additional Implementation Declarations
};

// Class CLoader3DS

#endif // ifndef CLoader3DS_h
