//---------------------------------------------------------------------------
#ifndef TexObjH
#define TexObjH
//---------------------------------------------------------------------------
#include "MipMapObj.h"
//---------------------------------------------------------------------------
// wrap of textures (clamp or repeat)
#define         E3D_TEX_WRAP_CLAMP                     0x00
#define         E3D_TEX_WRAP_REPEAT                    0x01

// filtering of textures
#define         E3D_TEX_MIN_FILTER_NEAREST                0x01
#define         E3D_TEX_MIN_FILTER_LINEAR                 0x02
#define         E3D_TEX_MIN_FILTER_NEAREST_MIPMAP_NEAREST 0x03
#define         E3D_TEX_MIN_FILTER_NEAREST_MIPMAP_LINEAR  0x03
#define         E3D_TEX_MIN_FILTER_LINEAR_MIPMAP_NEAREST  0x04
#define         E3D_TEX_MIN_FILTER_LINEAR_MIPMAP_LINEAR   0x05

#define         E3D_TEX_MAX_FILTER_NEAREST                0x01
#define         E3D_TEX_MAX_FILTER_LINEAR                 0x02
//---------------------------------------------------------------------------
class TTextureObj
{
    public:
             TTextureObj();
            ~TTextureObj();

            virtual void Think();

            TMipMapObj *MipMapObj;

            // Texture flags
            unsigned int UWrap;
            unsigned int VWrap;

            unsigned int MinFilter;
            unsigned int MaxFilter;
private:
};
//---------------------------------------------------------------------------
#endif
