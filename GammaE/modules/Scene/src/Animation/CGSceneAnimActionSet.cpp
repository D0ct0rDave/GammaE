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

	// Tiempo total desde la primera llamada a GetMesh
	m_fCurrentAnimTime += _fDeltaT;

	// Tiempo transcurrido dentro de la actual animación
	m_fCurrentAnimTime = Math::fMod(m_fCurrentAnimTime, m_fTotalAnimTime);

	// Frame que toca relativo al frame inicial de la animación
	float fFrame = m_fCurrentAnimTime / oCurrentAnimation.m_fFrameTime;
	uint iCurrFrame = (uint)fFrame;

	// Factor de cercanía hacia el siguiente frame: (->1 muy cerca de siguiente frame)
	float fFactor = fFrame - iCurrFrame;

	// Frame real dentro de la tabla de frames	
	uint uiRealFrame = oCurrentAnimation.m_uiIniFrame + iCurrFrame;

	// Setup next frame
	uint uiNextFrame;

	if (uiRealFrame >= oCurrentAnimation.m_uiEndFrame)
	{
		uiRealFrame = oCurrentAnimation.m_uiEndFrame;

		if (oCurrentAnimation.m_bLoop)
			uiNextFrame = oCurrentAnimation.m_uiIniFrame;
		else
		{
			uiNextFrame = oCurrentAnimation.m_uiEndFrame - 1;
			fFactor = 0.0f;
		}
	}
	else
		uiNextFrame = uiRealFrame + 1;

	m_poAnimObj->SetAnimState(uiRealFrame, uiNextFrame, fFactor);
}
// --------------------------------------------------------------------------------
CGGraphBV* CGSceneAnimActionSet::poGetBV()
{
	return m_poAnimObj->poGetBV();
}
// --------------------------------------------------------------------------------
