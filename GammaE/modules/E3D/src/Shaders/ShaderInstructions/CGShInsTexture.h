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
#ifndef CGShInsTextureH
#define CGShInsTextureH
// ----------------------------------------------------------------------------
#include "Materials/CGTexObj.h"
#include "Shaders\ShaderInstructions\CGShaderInstruction.h"
// ----------------------------------------------------------------------------
class CGShInsTexture : public CGShaderInstruction
{
    public:
        CGShInsTexture() : CGShaderInstruction(E3D_SHI_Texture), m_poTex(NULL)
        {
        }
        CGTextureObj* m_poTex;
};
// ----------------------------------------------------------------------------
#endif
// ----------------------------------------------------------------------------
