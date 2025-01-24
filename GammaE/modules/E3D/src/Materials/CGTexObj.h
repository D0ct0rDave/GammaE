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
#ifndef CGTexObjH
#define CGTexObjH
// ----------------------------------------------------------------------------
#include "CGMipMap.h"
#include "GammaE_Misc.h"
// ----------------------------------------------------------------------------
// wrap of textures (clamp or repeat)
// ----------------------------------------------------------------------------
#define         E3D_TEX_WRAP_CLAMP                        0x00
#define         E3D_TEX_WRAP_REPEAT                       0x01

// filtering of textures
#define         E3D_TEX_MIN_FILTER_NEAREST                0x01
#define         E3D_TEX_MIN_FILTER_LINEAR                 0x02
#define         E3D_TEX_MIN_FILTER_NEAREST_MIPMAP_NEAREST 0x03
#define         E3D_TEX_MIN_FILTER_NEAREST_MIPMAP_LINEAR  0x04
#define         E3D_TEX_MIN_FILTER_LINEAR_MIPMAP_NEAREST  0x05
#define         E3D_TEX_MIN_FILTER_LINEAR_MIPMAP_LINEAR   0x06

#define         E3D_TEX_MAX_FILTER_NEAREST                0x01
#define         E3D_TEX_MAX_FILTER_LINEAR                 0x02
// ----------------------------------------------------------------------------
class CGTextureObj : public CGResource
{
    public:
        CGTextureObj() : m_poMipMap(NULL), m_uiUWrap(E3D_TEX_WRAP_CLAMP), m_uiVWrap (E3D_TEX_WRAP_CLAMP), m_uiMinFilter (E3D_TEX_MIN_FILTER_NEAREST), m_uiMaxFilter(E3D_TEX_MAX_FILTER_NEAREST), m_uiHandler(0)
        {
        }
        virtual void Think()
        {
        }

        // Image data
        CGMipMap* m_poMipMap;

        // Texture flags
        uint m_uiUWrap;
        uint m_uiVWrap;
        uint m_uiMinFilter;
        uint m_uiMaxFilter;

        // Texture handler for the driver
        uint m_uiHandler;

        virtual bool bValid()
        {
            return( CGResource::bValid() && m_poMipMap->bValid() );
        }
    private:
};
// ----------------------------------------------------------------------------
#endif
// ----------------------------------------------------------------------------
