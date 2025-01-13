//---------------------------------------------------------------------------
#ifndef TexSetH
#define TexSetH
// -------------------------------------------------------------
struct Texture;
struct MipMap;
// ------------------------------------------------------------
#define     TEXSET_MAJOR_VERSION    1
#define     TEXSET_MINOR_VERSION    0

#define     TEXSET_OBJ_IDENTIFIER   MAKE_RIFF_ID('T','S','E','T')
//---------------------------------------------------------------------------
#define     TEXSET_MAX_TEXTURES         256

#ifndef MAX_CARS
#define MAX_CARS 256
#endif

#define MAX_CARS_TEXSET_NAME            80
#define TEXSET_DEFAULT_TEXSET_NAME      "Unnamed TexSet"
//---------------------------------------------------------------------------
typedef struct{
    bool Used;
    char Filename[MAX_CARS];
    MipMap* tex;
}TTextureEntry;
//---------------------------------------------------------------------------
class TTexSet
{
public:
         TTexSet();
        ~TTexSet();

        int  LoadTexture(char *Filename,unsigned int MipMapID);

        MipMap  *GetMipMap(unsigned int MipMapID);
        int      SetMipMap(unsigned int MipMapID,MipMap *mipMap);

        Texture *GetMipMapLOD(unsigned int TexID,unsigned int LOD);

        Texture *GetTexture(unsigned int TexID);
        int      SetTexture(unsigned int TexID,Texture *Tex);

        char *   GetTextureName(unsigned int TexID);

        int Load(char *Filename);
        int Save(char *Filename);
        int LoadWithHandler(FILE *fd);
        int SaveWithHandler(FILE *fd);
        int LoadTexSetList(char *Filename);
        int SaveTexSetList(char *Filename);

        void Invalidate();

        char         Name[MAX_CARS_TEXSET_NAME];

        unsigned int  GetNumMipMaps();
		unsigned int  GetMaxMipMaps();
        unsigned char GetMaxLODS();

private:

        TTextureEntry TextureArray[TEXSET_MAX_TEXTURES];
};
//---------------------------------------------------------------------------
#endif
