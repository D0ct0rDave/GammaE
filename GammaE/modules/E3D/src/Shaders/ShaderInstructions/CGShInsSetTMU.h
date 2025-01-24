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
#ifndef CGShInsSetTMUH
#define CGShInsSetTMUH
// ----------------------------------------------------------------------------
#include "Shaders\ShaderInstructions\CGShaderInstruction.h"
#include "GammaE_Misc.h"
// ----------------------------------------------------------------------------
class CGShInsSetTMU : public CGShaderInstruction
{
    public:
        CGShInsSetTMU() : CGShaderInstruction(E3D_SHI_SetTMU)
        {
        }
        uint uiGetTMU()
        {
            return(m_uiTMU);
        }
        void SetTMU(uint _uiTMU)
        {
            m_uiTMU = _uiTMU;
        }

    protected:
        uint m_uiTMU;
};
// ----------------------------------------------------------------------------
#endif
// ----------------------------------------------------------------------------
