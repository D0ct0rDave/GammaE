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
#include "Animation\CGSceneAnimInstance.h"
// --------------------------------------------------------------------------------
CGSceneAnimInstance::CGSceneAnimInstance()
{
    TypeID = OBJ3D_AnimCfg;
}
// --------------------------------------------------------------------------------
CGSceneAnimInstance::~CGSceneAnimInstance()
{
}
// --------------------------------------------------------------------------------
void CGSceneAnimInstance::SetAnim(uint _uiAnim)
{
    m_uiAnim = _uiAnim;
    m_fTime = 0.0f;
}
// --------------------------------------------------------------------------------
void CGSceneAnimInstance::Render()
{
    if ( m_bEnabled )
    {
        // m_poCfg
    }
}
// --------------------------------------------------------------------------------
