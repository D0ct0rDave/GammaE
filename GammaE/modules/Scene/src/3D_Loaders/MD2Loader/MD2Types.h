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

#ifndef MD2TypesH
#define MD2TypesH

#ifndef byte
    #define byte unsigned char
    #define undefbyte
#endif

// MD2 Header
typedef struct
{
    int magic;                          // 4
    int version;                        // 4
    int skinWidth;                      // 4
    int skinHeight;                     // 4

    int frameSize;                      // 4
    int numSkins;                       // 4
    int numVertices;                    // 4
    int numTexCoords;                    // 4

    int numTriangles;                    // 4
    int numGlCommands;                    // 4
    int numFrames;                      // 4
    int offsetSkins;                    // 4

    int offsetTexCoords;                    // 4
    int offsetTriangles;                    // 4
    int offsetFrames;                    // 4
    int offsetGlCommands;                    // 4

    int offsetEnd;                      // 4
} model_t;

typedef struct
{
    byte vertex[3];
    byte lightNormalIndex;
} triangleVertex_t;

typedef struct
{
    float scale[3];
    float translate[3];
    char name[16];
    triangleVertex_t* vertices;
} frame_t;

typedef struct
{
    short vertexIndices[3];
    short textureIndices[3];
} triangle_t;

typedef struct
{
    short s, t;
} textureCoordinate_t;

#ifdef undefbyte
    #undef byte
    #undef undefbyte
#endif

#endif
