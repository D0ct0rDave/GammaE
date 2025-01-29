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
#include "CGSCNVAnimUpdater.h"

#include "CGSceneBSPNode.h"
#include "CGSceneCamera.h"
#include "CGSceneInstance.h"
#include "CGSceneLeaf.h"
#include "CGSceneMux.h"
#include "CGSceneNode.h"
#include "CGSceneScreenRect.h"
#include "CGSceneSwitch.h"
#include "CGSceneTransf.h"
#include "CGSceneScreenRect.h"

#include "Animation/CGSceneAnimNode.h"
#include "Animation/CGSceneAnimActionSet.h"
#include "Animation/CGSceneAnimMesh.h"
#include "Animation/CGSceneAnimGroup.h"
#include "Animation/CGSceneAnimTransf.h"

// ----------------------------------------------------------------------------
void CGSCNVAnimUpdater::SetAnimState(CGSceneAnimActionSet* _poInst,uint _uiIFrame,uint _uiEFrame,float _fFact)
{
    m_uiIFrame = _uiIFrame;
    m_uiEFrame = _uiEFrame;
    m_fFact = _fFact;

    _poInst->poGetAnimObj()->Accept(this);
}
// ----------------------------------------------------------------------------
void CGSCNVAnimUpdater::Visit(CGSceneAnimNode* _poNode)
{
}
// ----------------------------------------------------------------------------
void CGSCNVAnimUpdater::Visit(CGSceneAnimMesh* _poNode)
{
    _poNode->SetAnimState(m_uiIFrame, m_uiEFrame, m_fFact);
}
// ----------------------------------------------------------------------------
void CGSCNVAnimUpdater::Visit(CGSceneAnimGroup* _poNode)
{
}
// ----------------------------------------------------------------------------
void CGSCNVAnimUpdater::Visit(CGSceneAnimTransf* _poNode)
{
    _poNode->SetAnimState(m_uiIFrame, m_uiEFrame, m_fFact);
}
// ----------------------------------------------------------------------------
