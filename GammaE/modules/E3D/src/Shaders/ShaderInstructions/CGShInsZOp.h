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
#ifndef CGShInsZOpH
#define CGShInsZOpH
// ----------------------------------------------------------------------------
#include "Shaders\ShaderInstructions\CGShaderInstruction.h"
#include "E3D_Enums.h"
// ----------------------------------------------------------------------------
class CGShInsZOp : public CGShaderInstruction
{
    public:
        CGShInsZOp() : CGShaderInstruction(E3D_SHI_ZOp), m_eZTF(E3D_ZTF_Current), m_eZW(E3D_ZW_Current)
        {
        }

        E3D_ZTestFunc eGetZTestFunc()
        {
            return(m_eZTF);
        }

        void SetZTestFunc(E3D_ZTestFunc value)
        {
            m_eZTF = value;
        }

        E3D_ZWrite eGetZWrite ()
        {
            return(m_eZW);
        }

        void SetZWrite(E3D_ZWrite value)
        {
            m_eZW = value;
        }

    protected:

        E3D_ZTestFunc m_eZTF;
        E3D_ZWrite m_eZW;
};
// ----------------------------------------------------------------------------
#endif
// ----------------------------------------------------------------------------
