// ----------------------------------------------------------------------------
#ifndef TextureLibraryHeaderFile
#define TextureLibraryHeaderFile
// ----------------------------------------------------------------------------
#include <vector>
#include <stdio.h>
// ----------------------------------------------------------------------------
enum PixelFormat
{
    ARGB32,
    RGB24,
    GRAY8,
    PALETTE
};

struct Palette
{
    unsigned char* data;
    unsigned int numColors;
};

struct Texture
{
    unsigned char* data;
    unsigned int width;
    unsigned int height;
    unsigned int channels;
    PixelFormat pixelFormat;
    Palette* palette;
};

struct MipMap
{
    std::vector<Texture*> lods;
};
// ----------------------------------------------------------------------------

Texture* poCreateTexture(int width, int height, int numChannels);
Texture* poLoadTexture(char* _szFilename);
bool SaveTexture(char* _szFilename, Texture* texture);
Texture* poCreateTextureCopy(Texture* _poTex);
void DestroyTexture(Texture* _poTex);
void FlipTextureVertical(Texture* texture);

MipMap* poCreateMipMap(int width, int height, int numChannels);
MipMap* poLoadMipMap(FILE* fd);
MipMap* poLoadTextureAsMipmap(char* _szFilename);
MipMap* poCreateMipMapFromTexture(Texture* _poTex);
MipMap* poCreateMipMapCopy(MipMap* _poMipMap);
void DestroyMipMap(MipMap* _poMipMap);

// ----------------------------------------------------------------------------
#endif
// ----------------------------------------------------------------------------