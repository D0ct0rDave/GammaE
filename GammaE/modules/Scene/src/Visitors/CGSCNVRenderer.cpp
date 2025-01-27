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
#include "GammaE_E3D.h"
#include "CGSCNVRenderer.h"

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
#include "Animation/CGSceneAnimCfg.h"
#include "Animation/CGSceneAnimMesh.h"
#include "Animation/CGSceneAnimInstance.h"
#include "Animation/CGSceneAnimGroup.h"
#include "Animation/CGSceneAnimTransf.h"
// ----------------------------------------------------------------------------
void CGSCNVRenderer::Render(CGSceneNode* _poNode)
{
    _poNode->Accept(this);
}
// ----------------------------------------------------------------------------
void CGSCNVRenderer::Visit(CGSceneNode* _poNode)
{
}
// ----------------------------------------------------------------------------
void CGSCNVRenderer::Visit(CGSceneBSPNode* _poNode)
{
    if (!_poNode->bIsVisible())
    {
        return;
    }

    float fCamPlaneAngle;
    CGCamera* poCam = CGRenderer::I()->poGetCamera();
    float fFOV = CGRenderer::I()->poGetProjector()->fFOV;
    const CGPlane& oPartitionPlane = _poNode->oGetPartitionPlane();

    // Get the angle between the camera and the plane
    fCamPlaneAngle = oPartitionPlane.oGetNormal().fDotProd(poCam->oGetDir());

    // Test the side of the plane the camera is
    if ( Math::iTestPointPlane(poCam->oGetPos(), oPartitionPlane) >= 0)
    {
        // The camera is in the front half space of the plane
        float fAngleLimit = Math::fCos( (90.0f - fFOV * 0.5f) * _PI_OVER_180_ );                    // cos(90 - Fov/2);

        // The camera could see part of the back space of the plane?
        // if (fCamPlaneAngle < fAngleLimit)
        if ( _poNode->poGetBackNode() )
            if (_poNode->poGetBackNode()->bIsVisible())
                _poNode->poGetBackNode()->Accept(this);

        if ( _poNode->poGetFrontNode() )
            _poNode->poGetFrontNode()->Accept(this);
    }
    else
    {
        // The camera is in the back half space of the plane
        float fAngleLimit = Math::fCos( (90.0f + fFOV * 0.5f) * _PI_OVER_180_ );

        // The camera could see part of the front space of the plane?
        // if (fCamPlaneAngle > fAngleLimit)
        if ( _poNode->poGetFrontNode() )
            if ( _poNode->poGetFrontNode()->bIsVisible() )
                _poNode->poGetFrontNode()->Accept(this);                     // farthest area in rendering

        if ( _poNode->poGetBackNode() )
            _poNode->poGetBackNode()->Accept(this);
    }
}
// ----------------------------------------------------------------------------
void CGSCNVRenderer::Visit(CGSceneCamera* _poNode)
{
    // PRERENDER:
    // Get current state attributes
    CGCamera* poOldCam = CGRenderer::I()->poGetCamera();
    CGProjector* poOldProj = CGRenderer::I()->poGetProjector();
    CGViewport* poOldVpt = CGRenderer::I()->poGetViewport();
    
    CGRenderer::I()->PushCameraMatrix();
    CGRenderer::I()->PushProjectorMatrix();

    // Send current attributes to render engine
    if ( _poNode->poGetViewport() != NULL ) CGRenderer::I()->SetViewport( _poNode->poGetViewport() );
    if ( _poNode->poGetCamera() != NULL ) CGRenderer::I()->SetCamera( _poNode->poGetCamera() );
    if ( _poNode->poGetProjector() != NULL ) CGRenderer::I()->SetProjector( _poNode->poGetProjector() );

    // RENDER
    Visit( (CGSceneGroup*) _poNode );

    // POSTRENDER
    // Restore previously defined attributes
    if ( _poNode->poGetViewport() != NULL ) CGRenderer::I()->SetViewport( poOldVpt );
    if ( _poNode->poGetCamera() != NULL ) CGRenderer::I()->SetCamera( poOldCam );
    if ( _poNode->poGetProjector() != NULL ) CGRenderer::I()->SetProjector( poOldProj );

    CGRenderer::I()->PopProjectorMatrix();
    CGRenderer::I()->PopCameraMatrix();
}
// ----------------------------------------------------------------------------
void CGSCNVRenderer::Visit(CGSceneInstance* _poNode)
{
    if (!_poNode->bIsVisible())
    {
        return;
    }

    Visit( (CGSceneTransf*)_poNode );
}
// ----------------------------------------------------------------------------
void CGSCNVRenderer::Visit(CGSceneLeaf* _poNode)
{
    if (!_poNode->bIsVisible())
    {
        return;
    }

    CGRenderer::I()->RenderMesh( _poNode->poGetMesh(),_poNode->poGetShader() );
}
// ----------------------------------------------------------------------------
void CGSCNVRenderer::Visit(CGSceneMux* _poNode)
{
    if (!_poNode->bIsVisible())
    {
        return;
    }
    
    for ( uint i = 0; i < _poNode->uiNumSubObjs(); i++ )
        if ( (_poNode->poGetObject(i) != NULL) && ( _poNode->bIsSelected(i) ) )
            _poNode->poGetObject(i)->Accept(this);
}
// ----------------------------------------------------------------------------
void CGSCNVRenderer::Visit(CGSceneGroup* _poNode)
{
    if (!_poNode->bIsVisible())
    {
        return;
    }
    
    for ( uint i = 0; i < _poNode->uiNumSubObjs(); i++ )
        if ( _poNode->poGetObject(i) )
            _poNode->poGetObject(i)->Accept(this);
}
// ----------------------------------------------------------------------------
void CGSCNVRenderer::Visit(CGSceneScreenRect* _poNode)
{
    // Setup our Render State
    CGRenderer::I()->PushProjectorMatrix();
    CGRenderer::I()->ClearProjectorMatrix();
    CGRenderer::I()->PushCameraMatrix();
    CGRenderer::I()->ClearCameraMatrix();
    CGRenderer::I()->PushWorldMatrix();
    CGRenderer::I()->SetWorldMatrix( _poNode->oGetMatrix() );

    CGRenderer::I()->RenderMesh( _poNode->poGetMesh(),_poNode->poGetShader() );

    CGRenderer::I()->PopWorldMatrix();
    CGRenderer::I()->PopCameraMatrix();
    CGRenderer::I()->PopProjectorMatrix();
}
// ----------------------------------------------------------------------------
void CGSCNVRenderer::Visit(CGSceneSwitch* _poNode)
{
    if (!_poNode->bEnabled())
    {
        return;
    }

    if (!_poNode->bIsVisible())
    {
        return;
    }

    if ( _poNode->poGetObject() != NULL )
        _poNode->poGetObject()->Accept(this);
}
// ----------------------------------------------------------------------------
void CGSCNVRenderer::Visit(CGSceneTransf* _poNode)
{
    if (!_poNode->bIsVisible())
    {
        return;
    }

    CGRenderer::I()->PushWorldMatrix();

    // Setup new Ref system
    CGRenderer::I()->MultiplyMatrix( _poNode->oTransf() );

    // We only can test visibility after performing the camera transformation
    _poNode->poGetObject()->Accept(this);

    // Restore current state
    CGRenderer::I()->PopWorldMatrix();
}
// ----------------------------------------------------------------------------
void CGSCNVRenderer::Visit(CGSceneAnimCfg* _poNode)
{
}
// ----------------------------------------------------------------------------
void CGSCNVRenderer::Visit(CGSceneAnimNode* _poNode)
{
}
// ----------------------------------------------------------------------------
void CGSCNVRenderer::Visit(CGSceneAnimMesh* _poNode)
{
    if (!_poNode->bIsVisible())
    {
        return;
    }

    CGRenderer::I()->RenderMesh(_poNode->poGetMesh(), _poNode->poGetShader());
}
// ----------------------------------------------------------------------------
void CGSCNVRenderer::Visit(CGSceneAnimInstance* _poNode)
{
    _poNode->poGetAnimatedObject()->Accept(this);
}
// ----------------------------------------------------------------------------
void CGSCNVRenderer::Visit(CGSceneAnimGroup* _poNode)
{
    for (uint i = 0; i < _poNode->uiNumAnimObjects(); i++)
        if (_poNode->poGetAnimObject(i) != NULL)
            _poNode->poGetAnimObject(i)->Accept(this);
}
// ----------------------------------------------------------------------------
void CGSCNVRenderer::Visit(CGSceneAnimTransf* _poNode)
{
    if (!_poNode->bIsVisible())
    {
        return;
    }

    CGRenderer::I()->PushWorldMatrix();

    // Setup new Ref system
    CGRenderer::I()->MultiplyMatrix( _poNode->GetCurrentTranform());

    _poNode->poGetObject()->Accept(this);

    // Restore current state
    CGRenderer::I()->PopWorldMatrix();
}
// ---------------------------------------------------------------------
