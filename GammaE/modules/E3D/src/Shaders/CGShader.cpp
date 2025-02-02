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
#include <string.h>
#include "GammaE_Mem.h"
// ----------------------------------------------------------------------------
#include "Shaders\CGShader.h"
// ----------------------------------------------------------------------------
CGShader::CGShader() :
    poInsts(NULL),
    m_uiNumInsts(0),
    m_uiShFlags(SHFLAG_UNDEFINEDFLAGS)
{
}
// ----------------------------------------------------------------------------
CGShader::~CGShader()
{
    Invalidate();
}
// ----------------------------------------------------------------------------
void CGShader::AddInstruction(CGShaderInstruction* _poInst)
{
    CGShaderInstruction* * poNewInsts;

    // Allocate space for old + new instructions
    poNewInsts = mNew CGShaderInstruction *[m_uiNumInsts + 1];

    // Copy old data
    if ( poInsts )
        memcpy( poNewInsts,poInsts,m_uiNumInsts * sizeof(CGShaderInstruction*) );

    // Add new instruction
    poNewInsts[m_uiNumInsts] = _poInst;

    // delete old data
    if ( poInsts ) mDel [] poInsts;

    // Update object
    poInsts = poNewInsts;

    m_uiNumInsts++;
}
// ----------------------------------------------------------------------------
void CGShader::PushInstruction(CGShaderInstruction* _poInst)
{
    CGShaderInstruction* * poNewInsts;

    // Allocate space for old + new instructions
    poNewInsts = mNew CGShaderInstruction *[m_uiNumInsts + 1];

    // Copy old data
    memcpy( poNewInsts + 1,poInsts,m_uiNumInsts * sizeof(CGShaderInstruction*) );

    // Add new instruction
    poNewInsts[0] = _poInst;

    // delete old data
    mDel [] poInsts;

    // Update object
    poInsts = poNewInsts;

    m_uiNumInsts++;
}
// ----------------------------------------------------------------------------
void CGShader::SetupShaderFlags()
{
    m_uiShFlags = 0;
    for ( uint i = 0; i < m_uiNumInsts; i++ )
    {
        if ( poInsts[i]->eGetInstructionType() == E3D_SHI_BlendOp )
        {
            m_uiShFlags |= SHFLAG_TRANSPARENT;
            return; // De momento solo necesitamos este flag
        }
    }
}
// ----------------------------------------------------------------------------
void CGShader::Invalidate()
{
    if ( poInsts )
    {
        // Delete instructions
        for ( uint i = 0; i < m_uiNumInsts; i++ )
        {
            mDel poInsts[i];
        }

        // Delete instruction array
        mDel [] poInsts;
        poInsts = NULL;
    }

    CGResource::Invalidate();
}
// ----------------------------------------------------------------------------
void CGShader::RefCopy(CGShader* _poShader)
{
    poInsts = _poShader->poInsts;
    m_uiNumInsts = _poShader->m_uiNumInsts;
    m_uiShFlags = _poShader->m_uiShFlags;
}
// ----------------------------------------------------------------------------
