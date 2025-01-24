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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "GammaE_Mem.h"

// CLoader3DS
#include "3D_Loaders\3DSLoader\CLoader3DS.h"

// -----------------------------------------------------------------------------
// 3DS Chunk types
// -----------------------------------------------------------------------------
#define CHK_MAIN3DS            0x4D4D

// >------ Main Chunks
#define CHK_EDIT3DS            0x3D3D   // this is the start of the editor config

// >------ sub defines of EDIT3DS
#define CHK_EDIT_MATERIAL      0xAFFF
#define CHK_EDIT_BACKGR        0x1200
#define CHK_EDIT_AMBIENT       0x2100
#define CHK_EDIT_OBJECT        0x4000

// >------ sub defines of EDIT_OBJECT
#define CHK_OBJ_TRIMESH        0x4100

// >------ sub defines of OBJ_TRIMESH
#define CHK_TRI_VERTEXL        0x4110
#define CHK_TRI_FACEL2         0x4111
#define CHK_TRI_FACEL1         0x4120
#define CHK_TRI_FACEMAT        0x4130
#define CHK_TRI_MAPPINGCOORDS  0x4140
#define CHK_TRI_SMOOTH         0x4150
#define CHK_TRI_LOCAL          0x4160
#define CHK_TRI_VISIBLE        0x4165

// >>------  these define the different color chunk types
#define CHK_COL_RGB            0x0010
#define CHK_COL_TRU            0x0011
#define CHK_COL_UNK            0x0013
// -----------------------------------------------------------------------------

// Class CLoader3DS

CLoader3DS::CLoader3DS()
    : m_uiCurMat(0)
{
}
// ----------------------------------------------------------------------------
CLoader3DS::~CLoader3DS()
{
}
// ----------------------------------------------------------------------------
void CLoader3DS::ReadChunk (pointer _pStream, T3DS_Chunk* _poChunk)
{
    // Read chunk ID
    _poChunk->m_usID = *(unsigned short*)(_pStream + 0);
    _poChunk->m_uiLen = *(unsigned long*)(_pStream + 2);
    _poChunk->m_pData = _pStream + 6;
}
// ----------------------------------------------------------------------------
void CLoader3DS::ParseLocalAxis (pointer _pStream, CGMatrix4x4* _poMatrix)
{
    float* M = (float*)_pStream;

    _poMatrix->Set(0,0,M[ 0]);
    _poMatrix->Set(1,0,M[ 1]);
    _poMatrix->Set(2,0,M[ 2]);

    _poMatrix->Set(0,1,M[ 3]);
    _poMatrix->Set(1,1,M[ 4]);
    _poMatrix->Set(2,1,M[ 5]);

    _poMatrix->Set(0,2,M[ 6]);
    _poMatrix->Set(1,2,M[ 7]);
    _poMatrix->Set(2,2,M[ 8]);

    _poMatrix->Set(0,3,M[ 9]);
    _poMatrix->Set(1,3,M[10]);
    _poMatrix->Set(2,3,M[11]);
}
// ----------------------------------------------------------------------------
CGVect3* CLoader3DS::poParseVertexCoordinates (pointer _pStream, unsigned short* _pusNumVertexs)
{
    CGVect3* VXCoords;

    // Get the number of VX Coordinates
    *_pusNumVertexs = *(unsigned short*)_pStream;

    // Create texture coordinate array
    VXCoords = mNew CGVect3[ *_pusNumVertexs ];

    //
    _pStream += sizeof(unsigned short);

    for ( uint cVX = 0; cVX < *_pusNumVertexs; cVX++ )
    {
        VXCoords[cVX].x = *( (float*)_pStream );
        _pStream += sizeof(float);
        VXCoords[cVX].y = *( (float*)_pStream );
        _pStream += sizeof(float);
        VXCoords[cVX].y = *( (float*)_pStream );
        _pStream += sizeof(float);
    }

    return(VXCoords);
}
// ----------------------------------------------------------------------------
CGVect2* CLoader3DS::poParseTextureCoordinates (pointer _pStream, unsigned short* _pusNumUVCoords)
{
    CGVect2* UVCoords;
    uint NumUVs,cUV;

    // Get the number of UV Coordinates
    NumUVs = *(unsigned short*)_pStream;

    // Create texture coordinate array
    UVCoords = mNew CGVect2[NumUVs];

    _pStream += sizeof(unsigned short);

    for ( cUV = 0; cUV < NumUVs; cUV++ )
    {
        UVCoords[cUV].x = *(float*)_pStream;
        _pStream += sizeof(float);

        UVCoords[cUV].y = *(float*)_pStream;
        _pStream += sizeof(float);
    }

    return(UVCoords);
}
// ----------------------------------------------------------------------------
unsigned short* CLoader3DS::pusParseFaces (pointer _pStream, unsigned short* _pusNumFaces)
{
    unsigned short* usFaces, * usFace;
    unsigned short* usBFaces = (unsigned short*)(_pStream + 2);

    *_pusNumFaces = *(unsigned short*)_pStream;
    usFaces = mNew unsigned short[*_pusNumFaces * 3];

    usFace = usFaces;
    for ( uint cFace = 0; cFace < *_pusNumFaces; cFace++ )
    {
        usFace[0] = usBFaces[0];
        usFace[1] = usBFaces[1];
        usFace[2] = usBFaces[2];

        usFace += 3;
        usBFaces += 4;
    }

    return(usFaces);
}
// ----------------------------------------------------------------------------
CGMesh* CLoader3DS::poCreateMeshFromFields (uint _uiNumFaces, uint _uiNumVertexs, unsigned short* _pusIdxs, CGVect3* _poVXs, CGVect2* _poUVs)
{
    CGMesh* poMesh = mNew CGMesh();
    uint uiMask = 0;                    // MESH_FIELD_VNORMALS | MESH_FIELD_COLORS;

    if ( _pusIdxs ) uiMask |= MESH_FIELD_INDEXES;
    if ( _poVXs ) uiMask |= MESH_FIELD_VERTEXS;
    if ( _poUVs ) uiMask |= MESH_FIELD_UVCOORDS;

    poMesh->Init(_uiNumVertexs,_uiNumFaces,E3D_PT_TRIS,uiMask);

    if ( _pusIdxs ) memcpy(poMesh->m_pusIdx,_pusIdxs, 3 * sizeof(unsigned short) * _uiNumFaces);
    if ( _poVXs ) memcpy(poMesh->m_poVX,_poVXs,  sizeof(CGVect3) * _uiNumVertexs);
    if ( _poUVs ) memcpy(poMesh->m_poUV,_poUVs,  sizeof(CGVect2) * _uiNumVertexs);

    // Compute BBox, Normals, Etc ...
    poMesh->SetBV( MeshUtils::poComputeBV( *poMesh ) );

    // NormalGen_ComputeVertexsNormals(*Mesh);

    return(poMesh);
}
// ----------------------------------------------------------------------------
uint CLoader3DS::uiParseChunks (CGSceneNode* * _poNode, pointer _pStream, uint _uiStreamSize)
{
    T3DS_Chunk Chunk;

    // Current object and childs
    CGSceneGroup* List = NULL;
    CGSceneNode* poChilds[MAX_TRIMESHOBJS];
    uint uiNumChilds = 0;

    // For current mesh object: the first child
    bool bStartObject = false;
    CGSceneLeaf* Leaf = NULL;
    CGMesh* LeafMesh = NULL;
    CGVect3* VXs = NULL;
    CGVect2* UVs = NULL;
    unsigned short* Idxs = NULL;
    unsigned short usNumVertexs = 0;
    unsigned short usNumUVCoords = 0;
    unsigned short usNumFaces = 0;

    // Parse the chunks
    uint uiStreamPos = 0;
    while ( uiStreamPos < _uiStreamSize )
    {
        ReadChunk(_pStream + uiStreamPos,&Chunk);

        switch ( Chunk.m_usID )
        {
            // Parse chunk data
            case CHK_MAIN3DS:
            case CHK_EDIT3DS:
            uiStreamPos += 6;
            break;

            case CHK_EDIT_MATERIAL:
            ParseMaterial(Chunk.m_pData);
            uiStreamPos += Chunk.m_uiLen;
            m_uiCurMat = 0;
            break;

            case CHK_EDIT_OBJECT:
            {
                if ( !List )
                {
                    // Skip object name
                    uint StrLen = 0;
                    while ( Chunk.m_pData[StrLen++] ) ;
                    uiStreamPos += 6 + StrLen;
                }
                else
                {
                    uiStreamPos += uiParseChunks(&poChilds[uiNumChilds++],Chunk.m_pData - 6,Chunk.m_uiLen);
                }
            }
            break;

            case CHK_TRI_LOCAL:                    // Matriz como Parseamos ???
                                                   // ParseLocalAxis (Chunk.Data,List->Trans.M);
            uiStreamPos += Chunk.m_uiLen;
            break;

            case CHK_TRI_VERTEXL:
            VXs = poParseVertexCoordinates(Chunk.m_pData,&usNumVertexs);
            uiStreamPos += Chunk.m_uiLen;
            break;

            case CHK_TRI_FACEL1:
            Idxs = pusParseFaces(Chunk.m_pData,&usNumFaces);
            uiStreamPos += Chunk.m_uiLen;
            break;

            case CHK_TRI_FACEMAT:
            uiStreamPos += Chunk.m_uiLen;
            break;

            case CHK_TRI_MAPPINGCOORDS:
            UVs = poParseTextureCoordinates(Chunk.m_pData,&usNumUVCoords);
            uiStreamPos += Chunk.m_uiLen;
            break;

            case CHK_OBJ_TRIMESH:                    // Lo primero: Comprobar si hay un objeto en creación
            {
                if ( (bStartObject) && (uiNumChilds < MAX_TRIMESHOBJS) )
                {
                    LeafMesh = poCreateMeshFromFields(usNumFaces,usNumVertexs,Idxs,VXs,UVs);
                    Leaf = new CGSceneLeaf();
                    Leaf->SetMesh  (LeafMesh);
                    Leaf->SetShader(m_oMatTable[m_uiCurMat++]);

                    poChilds[uiNumChilds++] = Leaf;
                }

                bStartObject = true;
                uiStreamPos += 6;
            }
            break;

            default:
            uiStreamPos += Chunk.m_uiLen;
            break;
        }
    }

    // Control there is no currently child creation
    if ( (bStartObject) && (uiNumChilds < MAX_TRIMESHOBJS) )
    {
        LeafMesh = poCreateMeshFromFields(usNumFaces,usNumVertexs,Idxs,VXs,UVs);
        Leaf = mNew CGSceneLeaf();
        Leaf->SetMesh(LeafMesh);
        Leaf->SetShader(m_oMatTable[m_uiCurMat++]);

        poChilds[uiNumChilds++] = Leaf;
    }

    // Create the object
    List = mNew CGSceneGroup(uiNumChilds);
    List->SetObject(Leaf,0);

    for ( uint cChild = 0; cChild < uiNumChilds; cChild++ )
        List->SetObject(poChilds[cChild],cChild);

    *_poNode = List;

    return(_uiStreamSize);
}
// ----------------------------------------------------------------------------
CGSceneNode* CLoader3DS::poLoad(const CGString& _sFilename)
{
    CGSceneNode* poObj = NULL;

    // ----------------------------------------------------------------------------
    // Read file contents
    // ----------------------------------------------------------------------------
    FILE* fd;
    pointer Stream;
    uint StreamSize;

    fd = fopen(_sFilename.szString(),"rb");
    if ( !fd ) return(NULL);

    fseek(fd,0,SEEK_END);
    StreamSize = ftell(fd);

    fseek(fd,0,SEEK_SET);
    Stream = (pointer)MEMAlloc(StreamSize);
    if ( !Stream )
    {
        fclose(fd);
        return(NULL);
    }

    fread(Stream,StreamSize,1,fd);
    fclose(fd);

    // ----------------------------------------------------------------------------
    uiParseChunks(&poObj,Stream,StreamSize);

    MEMFree(Stream);
    return(poObj);
}
// ----------------------------------------------------------------------------
void CLoader3DS::ParseMaterial (pointer _pStream)
{
    // hardcoded: material name is at offset 6 from the begining
    /*
       if (iMaxMats == 1024) return;

       pBuffer += 6;
       while(*pBuffer) pBuffer++;

       // skip 0 char
       pBuffer++;

       // hardcoded: texture name is at offset 157, starting from
       // the end of the material name
       pBuffer += 157;
     */

    // Safer code:
    int i = 0;
    while (
        (
            ( strnicmp(".tga",(const char*)_pStream,4) ) &&
            ( strnicmp(".jpg",(const char*)_pStream,4) ) &&
            ( strnicmp(".jpeg",(const char*)_pStream,5) )
        )
        &&
        (i < 100000000)
        )
    {
        _pStream++;
        i++;
    }

    if ( i == 100000000 ) return;

    // we found .tga Filename: go back to get the complete filename
    while ( *_pStream ) _pStream--;

    // skip 0 char
    _pStream++;

    m_oMatTable.uiAdd( CGShaderWH::I()->poCreateShader( (char*)_pStream ) );
}
// ----------------------------------------------------------------------------
