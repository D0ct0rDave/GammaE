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
#ifndef CGShaderInstructionH
#define CGShaderInstructionH
// ----------------------------------------------------------------------------
#include "Shaders\ShaderInstructions\EE3D_ShaderInstructionType.h"
// ----------------------------------------------------------------------------
class CGShaderInstruction
{
    public:

        CGShaderInstruction() : eInsType(E3D_SHI_NULL)
        {
        }
        CGShaderInstruction(E3D_ShaderInstructionType _eInsType)
        {
            eInsType = _eInsType;
        }

        E3D_ShaderInstructionType eGetInstructionType()
        {
            return(eInsType);
        }

    protected:
        E3D_ShaderInstructionType eInsType;
};
// ----------------------------------------------------------------------------
#endif
// ----------------------------------------------------------------------------
