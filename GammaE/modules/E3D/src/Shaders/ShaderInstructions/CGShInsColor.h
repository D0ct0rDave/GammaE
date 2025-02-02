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
#ifndef CGShInsColorH
#define CGShInsColorH
// ----------------------------------------------------------------------------
#include "Materials/CGColor.h"
#include "Shaders\ShaderInstructions\CGShaderInstruction.h"
// -----------------------------------------------------------------------------
class CGShInsColor : public CGShaderInstruction
{
    public:

        CGShInsColor::CGShInsColor() : CGShaderInstruction(E3D_SHI_Color)
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
