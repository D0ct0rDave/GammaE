// ----------------------------------------------------------------------------
/*! \class CGShInsExtension
 *  \brief
 *  \author David M&aacute;rquez de la Cruz
 *  \version 1.5
 *  \date 1999-2009
 *  \par Copyright (c) 1999 David M&aacute;rquez de la Cruz
 *  \par GammaE License
 */
// ----------------------------------------------------------------------------
#ifndef CGShInsExtensionH
#define CGShInsExtensionH
// ----------------------------------------------------------------------------
#include "Shaders\ShaderInstructions\CGShaderInstruction.h"
// ----------------------------------------------------------------------------
typedef void (*TExtensionFunction)(void* p1);
// ----------------------------------------------------------------------------
class CGShInsExtension : public CGShaderInstruction
{
    public:
        CGShInsExtension() : CGShaderInstruction(E3D_SHI_Extension), m_pFunction(NULL)
        {
        }

        TExtensionFunction pFunction()
        {
            return(m_pFunction);
        }
        void SetFunction(TExtensionFunction _pFunction)
        {
            m_pFunction = _pFunction;
        }

    protected:
        TExtensionFunction m_pFunction;
};
// ----------------------------------------------------------------------------
#endif
// ----------------------------------------------------------------------------
