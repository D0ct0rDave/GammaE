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
#include "GammaE_Mem.h"
#include "Animation\CGSceneAnimActionSet.h"
// --------------------------------------------------------------------------------
CGSceneAnimActionSet::CGSceneAnimActionSet()
{
	m_eNodeType = SNT_AnimActionSet;
}
// --------------------------------------------------------------------------------
CGSceneAnimActionSet::~CGSceneAnimActionSet()
{
    m_oActions.Clear();
}
// --------------------------------------------------------------------------------
void CGSceneAnimActionSet::SetAction(uint _uiAction)
{
	m_uiAction = _uiAction;
	const CAnimAction& oCurrentAnimation = oGetAnimAction(_uiAction);
	m_fTotalAnimTime = (oCurrentAnimation.m_uiEndFrame - oCurrentAnimation.m_uiIniFrame + 1) * oCurrentAnimation.m_fFrameTime;

	m_fCurrentAnimTime = 0.0f;
}
// --------------------------------------------------------------------------------
void CGSceneAnimActionSet::UpdateAnimState(float _fDeltaT)
{
	const CAnimAction& oCurrentAnimation = oGetAnimAction(m_uiAction);
	iLastFrame = CGRenderer::I()->oGetStats().m_uiCurrentFrame;

	unsigned int		iCurrFrame;
	unsigned int		iNextFrame;
	unsigned int		iRealFrame;

	float				fFactor;
	float				fFrameAnimTime;
	float				fFrame;

	// Tiempo total desde la primera llamada a GetMesh
	m_fCurrentAnimTime += _fDeltaT;

	// Tiempo transcurrido dentro de la actual animación
	fFrameAnimTime = Math::fMod(m_fCurrentAnimTime, m_fTotalAnimTime);

	// Frame que toca relativo al frame inicial de la animación
	fFrame = fFrameAnimTime / oCurrentAnimation.m_fFrameTime;
	iCurrFrame = (int)fFrame;

	// Factor de cercanía hacia el siguiente frame: (->1 muy cerca de siguiente frame)
	fFactor = fFrame - iCurrFrame;

	// Frame real dentro de la tabla de frames	
	iRealFrame = oCurrentAnimation.m_uiIniFrame + iCurrFrame;

	// Setup next frame
	if (iRealFrame >= oCurrentAnimation.m_uiEndFrame)
	{
		if (oCurrentAnimation.m_bLoop)
			iNextFrame = oCurrentAnimation.m_uiIniFrame;
		else
		{
			iNextFrame = oCurrentAnimation.m_uiEndFrame - 1;
			fFactor = 0.0f;
		}
	}
	else
		iNextFrame = iRealFrame + 1;

	m_poAnimObj->SetAnimState(iRealFrame, iNextFrame, fFactor);
}
// --------------------------------------------------------------------------------
CGGraphBV* CGSceneAnimActionSet::poGetBV()
{
	return m_poAnimObj->poGetBV();
}
// --------------------------------------------------------------------------------
