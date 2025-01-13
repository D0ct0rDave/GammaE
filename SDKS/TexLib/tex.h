#ifndef TextureLibraryHeaderFile
#define TextureLibraryHeaderFile

#include <vector>

typedef struct TFColor
{
	float r,g,b,a;
}TFColor;

enum PixelFormat
{
    ARGB32,
    RGB24,
    GRAY8,
    PALETTE
};
typedef struct
{
    unsigned char* data;
    unsigned int numColors;
}
Palette;

typedef struct
{
    unsigned char* data;
    unsigned int width;
    unsigned int height;
    unsigned int channels;
    PixelFormat pixelFormat;
    Palette* palette;
}Texture;

typedef struct MipMap 
{
    std::vector<Texture*> lods;
};

Texture* poLoadTexture(char* _szFilename);
Texture* poCreateTextureCopy(Texture* _poTex);
void DestroyTexture(Texture* _poTex);

MipMap* poCreateMipMapFromTexture(Texture* _poTex);
MipMap* poCreateMipMapCopy(MipMap* _poMipMap);
void DestroyMipMap(MipMap* _poMipMap);

#endif

