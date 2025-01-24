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
#ifndef CGShInsBlendOpH
#define CGShInsBlendOpH
// ----------------------------------------------------------------------------
#include "Shaders\ShaderInstructions\CGShaderInstruction.h"
#include "E3D_Enums.h"
// -----------------------------------------------------------------------------
class CGShInsBlendOp : public CGShaderInstruction
{
    public:

        CGShInsBlendOp() : CGShaderInstruction(E3D_SHI_BlendOp), m_eBlendMode(E3D_BM_Copy)
        {
        }

        E3D_BlendMode eGetBlendMode()
        {
            return (m_eBlendMode);
        }

        void SetBlendMode(E3D_BlendMode value)
        {
            m_eBlendMode = value;
        }

    protected:

        E3D_BlendMode m_eBlendMode;
};
// ----------------------------------------------------------------------------
#endif
// ----------------------------------------------------------------------------
