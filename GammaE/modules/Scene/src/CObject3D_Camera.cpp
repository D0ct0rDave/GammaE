// ----------------------------------------------------------------------
#include "CObject3D_Camera.h"
// ----------------------------------------------------------------------
CObject3D_Camera::CObject3D_Camera() : poCam(NULL), poProj(NULL), poVpt(NULL), poOldCam(NULL), poOldProj(NULL), poOldVpt(NULL)
{
    bFrustumTest = false;
}
// ----------------------------------------------------------------------
CObject3D_Camera::~CObject3D_Camera()
{
}
// ----------------------------------------------------------------------
void CObject3D_Camera::PreRender ()
{

     // Get current state attributes
    poOldCam = CGRenderer::I()->GetCamera();
    poOldProj = CGRenderer::I()->GetProjector();
    poOldVpt = CGRenderer::I()->GetViewport();

    CGRenderer::I()->PushCameraMatrix();
    CGRenderer::I()->PushProjectorMatrix();

     // Send current attributes to render engine
    CGRenderer::I()->PushLocalFrustum();

    if (poVpt) CGRenderer::I()->SetViewport    (poVpt);

    if (poCam) CGRenderer::I()->SetCamera  (poCam);

    if (poProj) CGRenderer::I()->SetProjector(poProj);

    CGRenderer::I()->ComputeLocalFrustum();

}
// ----------------------------------------------------------------------
void CObject3D_Camera::Render ()
{
    PreRender();

     // Render
    CObject3D_Node::Render();

    PostRender();
}
// ----------------------------------------------------------------------
void CObject3D_Camera::PostRender ()
{
     // Restore previously defined attributes
    if (poCam) CGRenderer::I()->SetCamera  (poOldCam);

    if (poProj) CGRenderer::I()->SetProjector(poOldProj);

    if (poVpt) CGRenderer::I()->SetViewport    (poOldVpt);

    CGRenderer::I()->PopLocalFrustum();

    CGRenderer::I()->PopProjectorMatrix();
    CGRenderer::I()->PopCameraMatrix();
}
// ----------------------------------------------------------------------
