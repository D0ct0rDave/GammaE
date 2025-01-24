// ----------------------------------------------------------------------------
/*! \class
 *  \brief
 *  \author David M&aacute;rquez de la Cruz
 *  \version 1.5
 *  \date 1999-2009
 *  \par Copyright (c) 1999 David M&aacute;rquez de la Cruz
 *  \par GammaE License
 */
// ----------------------------------------------------------------------------
#ifndef CLoader3DSH
#define CLoader3DSH
// ----------------------------------------------------------------------------
#include "GammaE_E3D.h"
#include "GammaE_Misc.h"

#include "CGSceneNode.h"
#include "CGSceneGroup.h"
#include "CGSceneLeaf.h"
#include "3D_Loaders\C3DLoader.h"

// ----------------------------------------------------------------------------
typedef struct T3DS_Chunk
{
    unsigned short m_usID;
    uint m_uiLen;
    pointer m_pData;
}T3DS_Chunk;
// ----------------------------------------------------------------------------

#define     MAX_TRIMESHOBJS     4096     // 4 KMeshes

// ----------------------------------------------------------------------------
class CLoader3DS : public C3DLoader
{
    public:
        CLoader3DS();

        ~CLoader3DS();

        // / Load a 3DS file and returns the scene contained in the file.
        virtual CGSceneNode* poLoad(const CGString& _sFilename);

    protected:

        // / Reads a chunk of data from the given stream.
        void ReadChunk(pointer _pStream, T3DS_Chunk* _poChunk);

        // / Reads a matrix from the given stream.
        void ParseLocalAxis(pointer _pStream, CGMatrix4x4* _poMatrix);

        // / Retrieves an array of vertex coords from the given stream.
        CGVect3* poParseVertexCoordinates(pointer _pStream, unsigned short* _pusNumVertexs);

        // / Retrieves an array of texture coords from the given stream.
        CGVect2* poParseTextureCoordinates(pointer _pStream, unsigned short* _pusNumUVCoords);

        // / Retrieves an array of faces from the given stream.
        unsigned short* pusParseFaces(pointer _pStream, unsigned short* _usNumFaces);

        // / Creates a mesh from the input fields.
        CGMesh* poCreateMeshFromFields(uint _uiNumFaces, uint _uiNumVertexs, unsigned short* _pusIdxs, CGVect3* _poVXs, CGVect2* _poUVs);

        // /
        uint uiParseChunks(CGSceneNode* * _poNode, pointer _pStream, uint _uiStreamSize);

        void ParseMaterial(pointer _pStream);

    protected:

        CGDynArray <CGShader*> m_oMatTable;
        uint m_uiCurMat;
};
// ----------------------------------------------------------------------------
#endif
// ----------------------------------------------------------------------------
