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
#include "CGSceneAnimNode.h"
#include "CGSceneAnimCfg.h"
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
	m_oAnimAction = m_poCfg->oGetFrameAnim(m_uiAnim);
	m_fTotalAnimTime = (m_oAnimAction.m_uiEndFrame - m_oAnimAction.m_uiIniFrame + 1) * m_oAnimAction.m_fFrameTime;
	
	m_fCurrentAnimTime = 0.0f;
}
// --------------------------------------------------------------------------------
void CGSceneAnimInstance::UpdateAnimState()
{
	if (CGRenderer::I()->oGetStats().m_uiCurrentFrame != iLastFrame)
	{
		iLastFrame = CGRenderer::I()->oGetStats().m_uiCurrentFrame;

		unsigned int		iCurrFrame;
		unsigned int		iNextFrame;
		unsigned int		iRealFrame;

		float				fFactor;
		float				fFrameAnimTime;
		float				fFrame;

		// Tiempo total desde la primera llamada a GetMesh
		m_fCurrentAnimTime += CGRenderer::I()->oGetStats().m_fDelta;

		// Tiempo transcurrido dentro de la actual animación
		fFrameAnimTime = Math::fMod(m_fCurrentAnimTime, m_fTotalAnimTime);

		// Frame que toca relativo al frame inicial de la animación
		fFrame = fFrameAnimTime / m_oAnimAction.m_fFrameTime;
		iCurrFrame = (int)fFrame;

		// Factor de cercanía hacia el siguiente frame: (->1 muy cerca de siguiente frame)
		fFactor = fFrame - iCurrFrame;

		// Frame real dentro de la tabla de frames	
		iRealFrame = m_oAnimAction.m_uiIniFrame + iCurrFrame;

		// Setup next frame
		if (iRealFrame >= m_oAnimAction.m_uiEndFrame)
		{
			if (m_oAnimAction.m_bLoop)
				iNextFrame = m_oAnimAction.m_uiIniFrame;
			else
			{
				iNextFrame = m_oAnimAction.m_uiEndFrame - 1;
				fFactor = 0.0f;
			}
		}
		else
			iNextFrame = iRealFrame + 1;

		m_poObj->SetAnimState(iRealFrame, iNextFrame, fFactor);
	}
}
// --------------------------------------------------------------------------------
