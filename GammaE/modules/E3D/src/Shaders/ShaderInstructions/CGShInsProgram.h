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
#ifndef CGShInsProgramH
#define CGShInsProgramH
// ----------------------------------------------------------------------------
#include "Materials/CGProgram.h"
#include "Shaders\ShaderInstructions\CGShaderInstruction.h"
// ----------------------------------------------------------------------------
class CGShInsProgram : public CGShaderInstruction
{
    public:
        CGShInsProgram() : CGShaderInstruction(E3D_SHI_Program), m_poProgram(NULL)
        {
        }

        void SetProgram(CGProgram* _poProgram)
        {
            m_poProgram = _poProgram;
        }
        CGProgram* poGetProgram()
        {
            return(m_poProgram);
        }

    protected:
        CGProgram* m_poProgram;
};
// ----------------------------------------------------------------------------
#endif
// ----------------------------------------------------------------------------
