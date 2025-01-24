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
#include "CGSceneCompiledLeaf.h"
#include "CGSceneInstance.h"
#include "CGSceneLeaf.h"
#include "CGSceneMux.h"
#include "CGSceneNode.h"
#include "CGSceneScreenRect.h"
#include "CGSceneSwitch.h"
#include "CGSceneTransf.h"
#include "CGSceneScreenRect.h"

#include "Animation/CGSceneAnimObject.h"
#include "Animation/CGSceneAnimCfg.h"
#include "Animation/CGSceneAnimMesh.h"
#include "Animation/CGSceneAnimInstance.h"
#include "Animation/CGSceneAnimNode.h"
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
// ----------------------------------------------------------------------------Visitor for BSP Nodes
// ----------------------------------------------------------------------------
void CGSCNVRenderer::Visit(CGSceneBSPNode* _poNode)
{
    float fCamPlaneAngle;
    CE3D_Camera* poCam = CGRenderer::I()->GetCamera();
    float fFOV = CGRenderer::I()->GetProjector()->fFOV;
    CGPlane* poPartitionPlane = _poNode->poGetPartitionPlane();

    // Get the angle between the camera and the plane
    fCamPlaneAngle = poPartitionPlane->Normal().fDotProd( poCam->m_oDir );

    // Test the side of the plane the camera is
    if ( MATH_Utils::iTestPointPlane(poCam->m_oPos,*poPartitionPlane) >= 0 )
    {
        // The camera is in the front half space of the plane
        float fAngleLimit = cos( (90.0f - fFOV * 0.5f) * _PI_OVER_180_ );                    // cos(90 - Fov/2);

        // The camera could see part of the back space of the plane?
        // if (fCamPlaneAngle < fAngleLimit)
        if ( _poNode->poGetBackNode() )
            if ( _poNode->poGetBackNode()->bVisible() )
                _poNode->poGetBackNode()->Accept(this);

        if ( _poNode->poGetFrontNode() )
            _poNode->poGetFrontNode()->Accept(this);
    }
    else
    {
        // The camera is in the back half space of the plane
        float fAngleLimit = cos( (90.0f + fFOV * 0.5f) * _PI_OVER_180_ );

        // The camera could see part of the front space of the plane?
        // if (fCamPlaneAngle > fAngleLimit)
        if ( _poNode->poGetFrontNode() )
            if ( _poNode->poGetFrontNode()->bVisible() )
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
    CE3D_Camera* poOldCam = CGRenderer::I()->GetCamera();
    CE3D_Projector* poOldProj = CGRenderer::I()->GetProjector();
    CE3D_Viewport* poOldVpt = CGRenderer::I()->GetViewport();

    CGRenderer::I()->PushCameraMatrix();
    CGRenderer::I()->PushProjectorMatrix();

    // Send current attributes to render engine
    CGRenderer::I()->PushLocalFrustum();

    if ( _poNode->poGetViewport() != NULL ) CGRenderer::I()->SetViewport( _poNode->poGetViewport() );
    if ( _poNode->poGetCamera() != NULL ) CGRenderer::I()->SetCamera( _poNode->poGetCamera() );
    if ( _poNode->poGetProjector() != NULL ) CGRenderer::I()->SetProjector( _poNode->poGetProjector() );

    CGRenderer::I()->ComputeLocalFrustum();

    // RENDER
    Visit( (CGSceneGroup*) _poNode );

    // POSTRENDER
    // Restore previously defined attributes
    if ( _poNode->poGetViewport() != NULL ) CGRenderer::I()->SetViewport( poOldVpt );
    if ( _poNode->poGetCamera() != NULL ) CGRenderer::I()->SetCamera( poOldCam );
    if ( _poNode->poGetProjector() != NULL ) CGRenderer::I()->SetProjector( poOldProj );

    CGRenderer::I()->PopLocalFrustum();

    CGRenderer::I()->PopProjectorMatrix();
    CGRenderer::I()->PopCameraMatrix();
}
// ----------------------------------------------------------------------------
void CGSCNVRenderer::Visit(CGSceneCompiledLeaf* _poNode)
{
    // If NULL material process is still valid
    CGRenderer::I()->RenderCompiledMesh( _poNode->poGetCGMesh(),_poNode->poGetShader() );
}
// ----------------------------------------------------------------------------
void CGSCNVRenderer::Visit(CGSceneInstance* _poNode)
{
    Visit( (CGSceneTransf*)_poNode );
}
// ----------------------------------------------------------------------------
void CGSCNVRenderer::Visit(CGSceneLeaf* _poNode)
{
    CGRenderer::I()->RenderMesh( _poNode->poGetMesh(),_poNode->poGetShader() );
}
// ----------------------------------------------------------------------------
void CGSCNVRenderer::Visit(CGSceneMux* _poNode)
{
    if ( _poNode->bVisible() )
    {
        for ( uint i = 0; i < _poNode->uiNumSubObjs(); i++ )
            if ( (_poNode->poGetObject(i) != NULL) && ( _poNode->bIsSelected(i) ) )
                _poNode->poGetObject(i)->Accept(this);
    }
}
// ----------------------------------------------------------------------------
void CGSCNVRenderer::Visit(CGSceneGroup* _poNode)
{
    if ( _poNode->bVisible() )
    {
        for ( uint i = 0; i < _poNode->uiNumSubObjs(); i++ )
            if ( _poNode->poGetObject(i) )
                _poNode->poGetObject(i)->Accept(this);
    }
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
    CGRenderer::I()->SetWorldMatrix( (CGMatrix4x4*)&_poNode->oGetMatrix() );

    CGRenderer::I()->RenderMesh( _poNode->poGetMesh(),_poNode->poGetShader() );

    CGRenderer::I()->PopWorldMatrix();
    CGRenderer::I()->PopCameraMatrix();
    CGRenderer::I()->PopProjectorMatrix();
}
// ----------------------------------------------------------------------------
void CGSCNVRenderer::Visit(CGSceneSwitch* _poNode)
{
    if ( _poNode->bVisible() )
        if ( _poNode->poGetObject() != NULL )
            _poNode->poGetObject()->Accept(this);
}
// ----------------------------------------------------------------------------
void CGSCNVRenderer::Visit(CGSceneTransf* _poNode)
{
    CGRenderer::I()->PushLocalFrustum();
    CGRenderer::I()->PushWorldMatrix();

    // Setup new Ref system
    CGRenderer::I()->MultiplyMatrix( (CGMatrix4x4*)&_poNode->oTransf() );

    // Get the local frustum
    /*
       if ((poObj->eGetTypeID() != SNT_Leaf) &&
        (poObj->eGetTypeID() != SNT_CompiledLeaf))
     */
    CGRenderer::I()->ComputeLocalFrustum();

    // We only can test visibility after performing the camera transformation
    if ( _poNode->bVisible() )
        _poNode->poGetObject()->Accept(this);

    // Restore current state
    CGRenderer::I()->PopWorldMatrix();
    CGRenderer::I()->PopLocalFrustum();
}
// ----------------------------------------------------------------------------
void CGSCNVRenderer::Visit(CGSceneAnimCfg* _poNode)
{
}
// ----------------------------------------------------------------------------
void CGSCNVRenderer::Visit(CGSceneAnimObject* _poNode)
{
}
// ----------------------------------------------------------------------------
void CGSCNVRenderer::Visit(CGSceneAnimMesh* _poNode)
{
// assert (_poNode->pMeshStates && "NULL Mesh state array");
// assert (pBVolStates && "NULL Bounding Volume State array");
// assert (Leaf        && "NULL Leaf Mesh");
    if ( _poNode->uiGetNumKeyFrames() == 1 )
    {
        memcpy( _poNode->poGetMesh()->m_poVX,_poNode->poGetVertexs(),_poNode->uiGetNumFrameVXs() * sizeof(CGVect3) );
        memcpy( _poNode->poGetMesh()->m_poVN,_poNode->poGetNormals(),_poNode->uiGetNumFrameVXs() * sizeof(CGVect3) );
    }
    else
    {
        if ( m_uiIniFrame >= _poNode->uiGetNumKeyFrames() ) m_uiIniFrame = _poNode->uiGetNumKeyFrames() - 1;
        if ( m_uiEndFrame >= _poNode->uiGetNumKeyFrames() ) m_uiEndFrame = _poNode->uiGetNumKeyFrames() - 1;
        if ( m_fAnimFactor == 1.0f ) m_uiIniFrame = m_uiEndFrame;                     // Optimization

        if ( (m_uiIniFrame != m_uiEndFrame) && (m_fAnimFactor > 0.0f) )
        {
            int cVert;
            CGVect3* pSrcVX = _poNode->poGetVertexs() + _poNode->uiGetNumFrameVXs() * m_uiIniFrame;
            CGVect3* pDstVX = _poNode->poGetVertexs() + _poNode->uiGetNumFrameVXs() * m_uiEndFrame;
            CGVect3* pMeshVX = _poNode->poGetMesh()->m_poVX;

            for ( uint cVert = 0; cVert < _poNode->uiGetNumFrameVXs(); cVert++ )
            {
                pMeshVX->Interpolate(*pSrcVX,*pDstVX,m_fAnimFactor);

                pSrcVX++;
                pDstVX++;
                pMeshVX++;
            }

            /*
               // No se nota tanto la diferecia
               CGVect3			*pSrcVN  = pNMeshStates + iNumStateVXs*_iSrc;
               CGVect3			*pDstVN  = pNMeshStates + iNumStateVXs*_iDst;
               CGVect3			*pMeshVN = Leaf->poGetMesh()->VNs;
               for (cVert=0;cVert<iNumStateVXs;cVert++)
               {

                pMeshVN->Interpolate(*pSrcVN,*pDstVN,_fFactor);

                pSrcVN ++;
                pDstVN ++;
                pMeshVN++;
               }
             */
            memcpy( _poNode->poGetMesh()->m_poVN,_poNode->poGetNormals() + _poNode->uiGetNumFrameVXs() * m_uiIniFrame,_poNode->uiGetNumFrameVXs() * sizeof(CGVect3) );

            CGVect3 oSMax,oSMin,oDMax,oDMin,oMax,oMin;
            CGVect3 oSCen = _poNode->poGetKeyFrameBVol(m_uiIniFrame)->GetCenter();
            CGVect3 oDCen = _poNode->poGetKeyFrameBVol(m_uiEndFrame)->GetCenter();
            CGVect3 oSExt = _poNode->poGetKeyFrameBVol(m_uiIniFrame)->GetExtents();
            CGVect3 oDExt = _poNode->poGetKeyFrameBVol(m_uiEndFrame)->GetExtents();
            oSMax.Assign(oSCen);
            oSMax.Add(oSExt);
            oSMin.Assign(oSCen);
            oSMin.Sub(oSExt);
            oDMax.Assign(oDCen);
            oDMax.Add(oDExt);
            oDMin.Assign(oDCen);
            oDMin.Sub(oDExt);

            oMax.Interpolate(oSMax,oDMax,m_fAnimFactor);
            oMin.Interpolate(oSMin,oDMin,m_fAnimFactor);

            _poNode->poGetMesh()->poGetBoundVol()->Init(oMax,oMin);
        }
        else
        {
            // Src copy:
            _poNode->poGetMesh()->poGetBoundVol()->Copy( _poNode->poGetKeyFrameBVol(m_uiIniFrame) );

            // Copy of the vertexs
            memcpy( _poNode->poGetMesh()->m_poVX,_poNode->poGetVertexs() + _poNode->uiGetNumFrameVXs() * m_uiIniFrame,_poNode->uiGetNumFrameVXs() * sizeof(CGVect3) );

            // Copy of the normals
            memcpy( _poNode->poGetMesh()->m_poVN,_poNode->poGetNormals() + _poNode->uiGetNumFrameVXs() * m_uiIniFrame,_poNode->uiGetNumFrameVXs() * sizeof(CGVect3) );
        }
    }
}
// ----------------------------------------------------------------------------
void CGSCNVRenderer::Visit(CGSceneAnimInstance* _poNode)
{
    // CGSCNVAnimUpdater::SetAnimState(0,poNode->
}
// ----------------------------------------------------------------------------
void CGSCNVRenderer::Visit(CGSceneAnimNode* _poNode)
{
}
// ----------------------------------------------------------------------------
void CGSCNVRenderer::Visit(CGSceneAnimTransf* _poNode)
{
}
// ---------------------------------------------------------------------
