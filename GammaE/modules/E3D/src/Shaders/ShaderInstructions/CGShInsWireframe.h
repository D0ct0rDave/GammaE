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
#ifndef CGShInsWireframeH
#define CGShInsWireframeH
// ----------------------------------------------------------------------------
#include "Materials/CGColor.h"
#include "Shaders\ShaderInstructions\CGShaderInstruction.h"
// ----------------------------------------------------------------------------
class CGShInsWireframe : public CGShaderInstruction
{
    public:
        CGShInsWireframe() : CGShaderInstruction(E3D_SHI_Wireframe)
        {
        }

        void SetColor(const CGColor& _oColor)
        {
            m_oColor = _oColor;
        }
        const CGColor& oGetColor()
        {
            return(m_oColor);
        }

    protected:
        CGColor m_oColor;
};
// ----------------------------------------------------------------------------
#endif
// ----------------------------------------------------------------------------
