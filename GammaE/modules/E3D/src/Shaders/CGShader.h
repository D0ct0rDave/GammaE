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
#ifndef CGShaderH
#define CGShaderH
// ----------------------------------------------------------------------------
#include <assert.h>

#include "GammaE_Misc.h"
#include "Shaders\ShaderInstructions\CGShaderInstruction.h"
// ----------------------------------------------------------------------------
#define SHFLAG_UNDEFINEDFLAGS   0x80000000
#define SHFLAG_TRANSPARENT      0x00000001
// ----------------------------------------------------------------------------
class CGShader : public CGResource
{
    public:
        CGShader();

        ~CGShader();

        void AddInstruction(CGShaderInstruction* _poInst);

        void PushInstruction(CGShaderInstruction* _poInst);

        CGShaderInstruction* pGetInstruction(uint _uiInstIdx);

        int iGetNumInstructions();

        virtual void Invalidate();

        void RefCopy(CGShader* _poShader);

        CGShaderInstruction* * poInsts;

        uint m_uiNumInsts;

        bool bIsTransparent();
        void SetupShaderFlags();

        uint m_uiShFlags;
    protected:
};
// ----------------------------------------------------------------------------
inline CGShaderInstruction* CGShader::pGetInstruction (uint _uiInstIdx)
{
    assert( (poInsts) && "NULL shader instruction array" );
    assert( (_uiInstIdx < m_uiNumInsts) && "Shader instruction out of bounds" );

    return(poInsts[_uiInstIdx]);
}
// ----------------------------------------------------------------------------
inline int CGShader::iGetNumInstructions ()
{
    return(m_uiNumInsts);
}
// ----------------------------------------------------------------------------
inline bool CGShader::bIsTransparent()
{
    if ( m_uiShFlags & SHFLAG_UNDEFINEDFLAGS )
        SetupShaderFlags();

    return (m_uiShFlags & SHFLAG_TRANSPARENT);
}
// ----------------------------------------------------------------------------
#endif
// ----------------------------------------------------------------------------
