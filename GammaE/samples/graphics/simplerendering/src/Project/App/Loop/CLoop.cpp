// -----------------------------------------------------------------------------
/*! \class
 *  \brief
 *  \author David M&aacute;rquez de la Cruz
 *  \version 1.5
 *  \date 1999-2009
 *  \par Copyright (c) 1999 David M&aacute;rquez de la Cruz
 *  \par GammaE License
 */
// ----------------------------------------------------------------------------
#include <windows.h>
#include "CLoop.h"
#include "GammaE.h"
#include "CLoopGlobals.h"
// ----------------------------------------------------------------------------
// Init Game Related Stuff
// ----------------------------------------------------------------------------
CGMesh* m_poSphere = NULL;
CGShader* m_poShader = NULL;
float m_fTime = 0;
// ----------------------------------------------------------------------------
void CLoop::Init()
{
    CGShaderDefFileWH::I()->poLoad("shaders.txt");

    m_poSphere = mNew CGMeshSphere(32,5.0f);
    m_poShader = CGShaderWH::I()->poCreateShader("topitos.tga");

    // -------------------------------
    // Viewport Initialization
    // -------------------------------
    loopGlobals.m_oViewport.ScrCX = 0.0f;
    loopGlobals.m_oViewport.ScrCY = 0.0f;
    loopGlobals.m_oViewport.ScrTX = 1.0f;
    loopGlobals.m_oViewport.ScrTY = 1.0f;

    // -------------------------------
    // Perspective projection camera
    // -------------------------------
    loopGlobals.m_oPerspPrj.ePrjType = E3D_PT_Perspective;
    loopGlobals.m_oPerspPrj.fFOV = 45.0f;
    loopGlobals.m_oPerspPrj.fNear = 0.1f;
    loopGlobals.m_oPerspPrj.fFar = 500.0f;

    loopGlobals.m_oPerspCam.SetPos( 0, 0,  25);
    loopGlobals.m_oPerspCam.SetVectors( CGVect3(0,0,-1),CGVect3(0,1,0),CGVect3(1,0,0) );

    CGRenderer::I()->DisableFrustumCulling();
    CGRenderer::I()->SetZPars(E3D_ZTF_LEqual,E3D_ZW_Enable);
}
// ----------------------------------------------------------------------------
void CLoop::Finish()
{
}
// ----------------------------------------------------------------------------
bool CLoop::bLoop(float _fDeltaT)
{
    bool bRes = bUpdate(_fDeltaT);
    Render();

    return(bRes);
}
// ----------------------------------------------------------------------------
bool CLoop::bUpdate(float _fDeltaT)
{
    m_fTime += _fDeltaT;

    const float fRadius = 25;
    const float fFreq = 0.5f;

    CGVect3 oPos;
    oPos.x = fRadius * Math::fCos(m_fTime * fFreq * _2PI_);
    oPos.z = fRadius * Math::fSin(m_fTime * fFreq * _2PI_);

    loopGlobals.m_oPerspCam.SetPos( oPos.x, 0.0f, oPos.z);
    loopGlobals.m_oPerspCam.LookAt( CGVect3(0,0,0) );

    return(loopGlobals.m_bFinnishApplication);
}
// ----------------------------------------------------------------------------
void CLoop::Render()
{
    CGRenderer::I()->BeginRender();

    CGRenderer::I()->SetCamera(&loopGlobals.m_oPerspCam);
    CGRenderer::I()->SetProjector(&loopGlobals.m_oPerspPrj);
    CGRenderer::I()->SetViewport(&loopGlobals.m_oViewport);

    CGRenderer::I()->RenderMesh(m_poSphere,m_poShader);
    CGRenderer::I()->EndRender();
}
// ----------------------------------------------------------------------------
