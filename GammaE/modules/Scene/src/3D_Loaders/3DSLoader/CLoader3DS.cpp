#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "GammaE_Mem.h"

// CLoader3DS
#include "3D_Loaders\3DSLoader\CLoader3DS.h"

//-----------------------------------------------------------------------------
// 3DS Chunk types
//-----------------------------------------------------------------------------
 #define CHK_MAIN3DS            0x4D4D

//>------ Main Chunks
 #define CHK_EDIT3DS            0x3D3D  // this is the start of the editor config

//>------ sub defines of EDIT3DS
 #define CHK_EDIT_MATERIAL      0xAFFF
 #define CHK_EDIT_BACKGR        0x1200
 #define CHK_EDIT_AMBIENT       0x2100
 #define CHK_EDIT_OBJECT        0x4000

//>------ sub defines of EDIT_OBJECT
 #define CHK_OBJ_TRIMESH        0x4100

//>------ sub defines of OBJ_TRIMESH
 #define CHK_TRI_VERTEXL        0x4110
 #define CHK_TRI_FACEL2         0x4111
 #define CHK_TRI_FACEL1         0x4120
 #define CHK_TRI_FACEMAT        0x4130
 #define CHK_TRI_MAPPINGCOORDS  0x4140
 #define CHK_TRI_SMOOTH         0x4150
 #define CHK_TRI_LOCAL          0x4160
 #define CHK_TRI_VISIBLE        0x4165

//>>------  these define the different color chunk types
 #define CHK_COL_RGB            0x0010
 #define CHK_COL_TRU            0x0011
 #define CHK_COL_UNK            0x0013
//-----------------------------------------------------------------------------

// Class CLoader3DS

CLoader3DS::CLoader3DS()
    : iMaxMats(0), iCurMat(0)
{
}

CLoader3DS::~CLoader3DS()
{
}

void CLoader3DS::ReadChunk (char *Stream, T3DS_Chunk &Chunk)
{
     // Read chunk ID
    Chunk.ID   = *(unsigned short *)( Stream + 0 );
    Chunk.Len  = *(unsigned long  *)( Stream + 2 );
    Chunk.Data = Stream + 6;
}

void CLoader3DS::ParseLocalAxis (char *Buffer, CMatrix4x4 &Matrix)
{
   float *M = (float *)Buffer;

   Matrix.Set(0,0,M[ 0]);
   Matrix.Set(1,0,M[ 1]);
   Matrix.Set(2,0,M[ 2]);

   Matrix.Set(0,1,M[ 3]);
   Matrix.Set(1,1,M[ 4]);
   Matrix.Set(2,1,M[ 5]);

   Matrix.Set(0,2,M[ 6]);
   Matrix.Set(1,2,M[ 7]);
   Matrix.Set(2,2,M[ 8]);

   Matrix.Set(0,3,M[ 9]);
   Matrix.Set(1,3,M[10]);
   Matrix.Set(2,3,M[11]);
}

CVect3 *CLoader3DS::ParseVertexCoordinates (char *Buffer, unsigned short &usNumVertexs)
{
   CVect3  *VXCoords;
   unsigned int cVX;

     // Get the number of VX Coordinates
    usNumVertexs = *(unsigned short *)Buffer;

     // Create texture coordinate array
    VXCoords    =  mNew CVect3[usNumVertexs];

    Buffer += sizeof( unsigned short );

    for (cVX = 0; cVX < usNumVertexs; cVX++)
    {
        VXCoords[cVX].x = *( (float *)Buffer );
        Buffer += sizeof( float );
        VXCoords[cVX].y = *( (float *)Buffer );
        Buffer += sizeof( float );
        VXCoords[cVX].y = *( (float *)Buffer );
        Buffer += sizeof( float );
    }

    return( VXCoords );
}

CVect2 *CLoader3DS::ParseTextureCoordinates (char *Buffer, unsigned short &usNumUVCoords)
{
   CVect2  *UVCoords;
   unsigned int NumUVs,cUV;

     // Get the number of UV Coordinates
    NumUVs = *(unsigned short *)Buffer;

     // Create texture coordinate array
    UVCoords    =  mNew CVect2[NumUVs];

    Buffer += sizeof( unsigned short );

    for (cUV = 0; cUV < NumUVs; cUV++)
    {
        UVCoords[cUV].x = *(float *)Buffer;
        Buffer += sizeof( float );
        UVCoords[cUV].y = *(float *)Buffer;
        Buffer += sizeof( float );
    }

    return( UVCoords );
}

unsigned short *CLoader3DS::ParseFaces (char *Buffer, unsigned short & usNumFaces)
{
   unsigned short cFace;
   unsigned short *usFaces,*usFace;
   unsigned short *usBFaces = (unsigned short *)( Buffer + 2 );

    usNumFaces = *(unsigned short *)Buffer;
    usFaces    = mNew unsigned short[usNumFaces * 3];

    usFace   = usFaces;

    for (cFace = 0; cFace < usNumFaces; cFace++)
    {
        usFace[0] = usBFaces[0];
        usFace[1] = usBFaces[1];
        usFace[2] = usBFaces[2];

        usFace   += 3;
        usBFaces += 4;
    }

    return( usFaces );
}

CMesh *CLoader3DS::CreateMeshFromFields (int iNumFaces, int iNumVertexs, unsigned short *Idxs, CVect3 *VXs, CVect2 *UVs)
{
   CMesh *Mesh = mNew CMesh();
   unsigned int uiMask = 0;    // MESH_FIELD_VNORMALS | MESH_FIELD_COLORS;

    if (Idxs) uiMask |= MESH_FIELD_INDEXES;

    if (VXs ) uiMask |= MESH_FIELD_VERTEXS;

    if (UVs ) uiMask |= MESH_FIELD_UVCOORDS;

    Mesh->Init(iNumVertexs,iNumFaces,E3D_MESH_TRIS,uiMask);

    if (Idxs) memcpy(Mesh->Idxs,Idxs,3 * sizeof( unsigned short ) * iNumFaces);

    if (VXs ) memcpy(Mesh->VXs,VXs,  sizeof( CVect3 ) * iNumVertexs);

    if (UVs ) memcpy(Mesh->UVs,UVs,  sizeof( CVect2 ) * iNumVertexs);

     // Compute BBox, Normals, Etc ...
    Mesh->ComputeBoundVol();
    // NormalGen_ComputeVertexsNormals(*Mesh);

    return( Mesh );
}

int CLoader3DS::ParseChunks (CObject3D * *Node, char *Stream, unsigned int StreamSize)
{
   T3DS_Chunk Chunk;
   unsigned int StreamPos;

     // Current object and childs
    CObject3D_Node  *List       = NULL;
    CObject3D       *poChilds[MAX_TRIMESHOBJS];
    int NumChilds  = 0;
    int cChild;

     // For current mesh object: the first child
    bool bStartObject  = false;
    CObject3D_Leaf      *Leaf         = NULL;
    CMesh               *LeafMesh     = NULL;
    CVect3              *VXs          = NULL;
    CVect2              *UVs          = NULL;
    unsigned short      *Idxs         = NULL;
    unsigned short usNumVertexs  = 0;
    unsigned short usNumUVCoords = 0;
    unsigned short usNumFaces    = 0;

     // Parse the chunks
    StreamPos    = 0;

    while (StreamPos < StreamSize)
    {
        ReadChunk(Stream + StreamPos,Chunk);

        switch (Chunk.ID)
        {
            // Parse chunk data
            case CHK_MAIN3DS:
            case CHK_EDIT3DS:           StreamPos += 6;
                break;
            case CHK_EDIT_MATERIAL:     ParseMaterial(Chunk.Data);
                StreamPos += Chunk.Len;
                iCurMat    = 0;
                break;

            case CHK_EDIT_OBJECT:

                if (!List)
                {
                     // Skip object name
                    unsigned int StrLen = 0;

                    while (Chunk.Data[StrLen++]) ;
                    StreamPos += 6 + StrLen;
                }
                else
                {
                    StreamPos += ParseChunks(&poChilds[NumChilds++],Chunk.Data - 6,Chunk.Len);
                }
                break;

            case CHK_TRI_LOCAL:             // Matriz como Parseamos ???
                                            //ParseLocalAxis (Chunk.Data,List->Trans.M);
                StreamPos += Chunk.Len;
                break;
            case CHK_TRI_VERTEXL:       VXs = ParseVertexCoordinates(Chunk.Data,usNumVertexs);
                StreamPos += Chunk.Len;
                break;
            case CHK_TRI_FACEL1:        Idxs = ParseFaces(Chunk.Data,usNumFaces);
                StreamPos += Chunk.Len;
                break;
            case CHK_TRI_FACEMAT:       StreamPos += Chunk.Len;
                break;

            case CHK_TRI_MAPPINGCOORDS: UVs = ParseTextureCoordinates(Chunk.Data,usNumUVCoords);
                StreamPos += Chunk.Len;
                break;
            case CHK_OBJ_TRIMESH:           // Lo primero: Comprobar si hay un objeto en creación

                if ( ( bStartObject ) && ( NumChilds < MAX_TRIMESHOBJS ) )
                {
                    LeafMesh = CreateMeshFromFields(usNumFaces,usNumVertexs,Idxs,VXs,UVs);
                    Leaf = new CObject3D_Leaf();
                    Leaf->SetMesh  (LeafMesh);
                    Leaf->SetShader(pMatTable[iCurMat++]);

                    poChilds[NumChilds++] = Leaf;
                }

                bStartObject = true;
                StreamPos += 6;
                break;

            default:                    StreamPos += Chunk.Len;
                break;
        }
    }

     // Control there is no currently child creation
    if ( ( bStartObject ) && ( NumChilds < MAX_TRIMESHOBJS ) )
    {
        LeafMesh = CreateMeshFromFields(usNumFaces,usNumVertexs,Idxs,VXs,UVs);
        Leaf = mNew CObject3D_Leaf();
        Leaf->SetMesh(LeafMesh);
        Leaf->SetShader(pMatTable[iCurMat++]);

        poChilds[NumChilds++] = Leaf;
    }

     // Create the object
    List = mNew CObject3D_Node();
    List->Init(NumChilds);
    List->SetObject(Leaf,0);

    for (cChild = 0; cChild < NumChilds; cChild++)
        List->SetObject(poChilds[cChild],cChild);

    *Node = List;

    return( StreamSize );
} // ParseChunks

CObject3D *CLoader3DS::pLoad (char *Filename)
{
   CObject3D *poObj = NULL;

     //-----------------------------------------------------------------------------
     // Read file contents
     //-----------------------------------------------------------------------------
    FILE         *fd;
    char         *Stream;
    unsigned int StreamSize;

    fd = fopen(Filename,"rb");

    if (!fd) return( NULL );

    fseek(fd,0,SEEK_END);
    StreamSize = ftell(fd);

    fseek(fd,0,SEEK_SET);
    Stream = (char *)mAlloc(StreamSize);

    if (!Stream)
    {
        fclose(fd);
        return( NULL );
    }

    fread(Stream,StreamSize,1,fd);
    fclose(fd);

     //-----------------------------------------------------------------------------
    iMaxMats = 0;
    ParseChunks(&poObj,Stream,StreamSize);

    mFree(Stream);
    return( poObj );
}

void CLoader3DS::ParseMaterial (char *pBuffer)
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
            ( strnicmp(".tga",pBuffer,4) ) &&
            ( strnicmp(".jpg",pBuffer,4) ) &&
            ( strnicmp(".jpeg",pBuffer,5) )
           )
           &&
           ( i < 100000000 )
          )
    {
        pBuffer++;
        i++;
    }
    ;

    if (i == 100000000) return;

     // we found .tga Filename: go back to get the complete filename
    while (*pBuffer) pBuffer--;
     // skip 0 char
    pBuffer++;

    char *TexName = pBuffer;
    pMatTable[iMaxMats++] = CE3D_ShaderWH::I()->poCreateShader(TexName);
}

// Additional Declarations
