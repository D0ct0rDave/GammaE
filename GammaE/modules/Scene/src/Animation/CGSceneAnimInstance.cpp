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
#include "CGSceneAnimInstance.h"
// --------------------------------------------------------------------------------
CGSceneAnimInstance::CGSceneAnimInstance()
{
    m_eNodeType = ESceneNodeType::SNT_AnimInstance;
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
