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
void CGSCNVAnimUpdater::Update(CGSceneNode* _poNode, float _fDeltaT)
{
    m_fDeltaT = _fDeltaT;
    _poNode->Accept(this);
}
// ----------------------------------------------------------------------------
void CGSCNVAnimUpdater::Visit(CGSceneNode* _poNode)
{
    assert(false && "Unhandled node in anim updater");
}
// ----------------------------------------------------------------------------
void CGSCNVAnimUpdater::Visit(CGSceneBSPNode* _poNode)
{
    if (_poNode->poGetBackNode() != NULL)
    {
        _poNode->poGetBackNode()->Accept(this);
    }

    if (_poNode->poGetFrontNode() != NULL)
    {
        _poNode->poGetFrontNode()->Accept(this);
    }
}
// ----------------------------------------------------------------------------
void CGSCNVAnimUpdater::Visit(CGSceneCamera* _poNode)
{
    Visit((CGSceneGroup*)_poNode);
}
// ----------------------------------------------------------------------------
void CGSCNVAnimUpdater::Visit(CGSceneInstance* _poNode)
{
    if (_poNode->poGetObject() != NULL)
    {
        _poNode->poGetObject()->Accept(this);
    }
}
// ----------------------------------------------------------------------------
void CGSCNVAnimUpdater::Visit(CGSceneLeaf* _poNode)
{
}
// ----------------------------------------------------------------------------
void CGSCNVAnimUpdater::Visit(CGSceneMux* _poNode)
{
    for (uint i = 0;i < _poNode->uiNumSubObjs();i++)
    {
        if (_poNode->bIsSelected(i) && (_poNode->poGetObject(i) != NULL))
        {
            _poNode->poGetObject(i)->Accept(this);
        }
    }
}
// ----------------------------------------------------------------------------
void CGSCNVAnimUpdater::Visit(CGSceneGroup* _poNode)
{
    for (uint i = 0;i < _poNode->uiNumSubObjs();i++)
    {
        if (_poNode->poGetObject(i) != NULL)
        {
            _poNode->poGetObject(i)->Accept(this);
        }
    }
}
// ----------------------------------------------------------------------------
void CGSCNVAnimUpdater::Visit(CGSceneScreenRect* _poNode)
{
}
// ----------------------------------------------------------------------------
void CGSCNVAnimUpdater::Visit(CGSceneSwitch* _poNode)
{
    if (_poNode->poGetObject())
    {
        _poNode->poGetObject()->Accept(this);
    }
}
// ----------------------------------------------------------------------------
void CGSCNVAnimUpdater::Visit(CGSceneTransf* _poNode)
{
    if (_poNode->poGetObject())
    {
        _poNode->poGetObject()->Accept(this);
    }
}
// ----------------------------------------------------------------------------
void CGSCNVAnimUpdater::Visit(CGSceneAnimNode* _poNode)
{
    assert(false && "Expected update animation from a SceneAnimActionSet parent");
}
// ----------------------------------------------------------------------------
void CGSCNVAnimUpdater::Visit(CGSceneAnimMesh* _poNode)
{
    assert(false && "Expected update animation from a SceneAnimActionSet parent");
}
// ----------------------------------------------------------------------------
void CGSCNVAnimUpdater::Visit(CGSceneAnimGroup* _poNode)
{
    assert(false && "Expected update animation from a SceneAnimActionSet parent");
}
// ----------------------------------------------------------------------------
void CGSCNVAnimUpdater::Visit(CGSceneAnimTransf* _poNode)
{
    assert(false && "Expected update animation from a SceneAnimActionSet parent");
}
// ----------------------------------------------------------------------------
void CGSCNVAnimUpdater::Visit(CGSceneAnimActionSet* _poNode)
{
    _poNode->UpdateAnimState(m_fDeltaT);
}
// ----------------------------------------------------------------------------
