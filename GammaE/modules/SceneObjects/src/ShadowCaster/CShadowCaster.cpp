// -----------------------------------------------------------------------------
/*! \class
 *  \brief
 *  \author David M&aacute;rquez de la Cruz
 *  \version 1.5
 *  \date 1999-2009
 *  \par Copyright (c) 1999 David M&aacute;rquez de la Cruz
 *  \par GammaE License
 */
// -----------------------------------------------------------------------------
// CShadowCaster
#include "ShadowCaster\CShadowCaster.h"

// #define _SMOOTH_SHADOW2_

// Class CShadowCaster

CShadowCaster::CShadowCaster()
    : poBlockerObj(NULL), poRecObjs(NULL), iNumRecObjs(0), poTexObj(NULL), pucAuxTexData(NULL)
{
}

CShadowCaster::~CShadowCaster()
{
}

void CShadowCaster::Init (int _iRes)
{
    iRes = _iRes;

    // Create texture
    #ifdef _SMOOTH_SHADOW_

    CGMipMap* poMipMap = mNew CGMipMap(iRes >> 1,iRes >> 1,1,IF_PALETTE);
    // MipMap_fn_iAllocateMipMap(&oMipMap,iRes>>1,iRes>>1,TEX_PF_PALETTE,1);
    for ( int i = 0; i < 256; i++ )
    {
        oMipMap.Palette->data[i].r = i;
        oMipMap.Palette->data[i].g = i;
        oMipMap.Palette->data[i].b = i;
    }
    pucAuxTexData = mNew unsigned char[iRes * iRes * 4];

    #else

    CGMipMap* poMipMap = mNew CGMipMap(iRes,iRes,1,IF_RGBA);

    #endif

    // Create shader from texture
    CE3D_ShaderUtils::SetupTilingFlags(0,0);
    poShader = CE3D_ShaderUtils::poGenerateShaderFromMipMap(poMipMap,"::ShadowMap::");

    // Get a Ref to texture object
    poTexObj = ( (CE3D_ShIns_Texture*)poShader->pGetInstruction(0) )->m_poTex;

    // Add blending op before texture operation
    CE3D_ShIns_BlendOp* poBop = mNew CE3D_ShIns_BlendOp;
    poBop->SetBlendMode(E3D_BM_Mult);
    poShader->PushInstruction(poBop);

    // Add matrix texture operation
    CE3D_ShIns_TexOp* poTop = mNew CE3D_ShIns_TexOp;
    poTop->SetTOpType(eSITexOp_Matrix);
    poTop->m_poMat = &oPrjTexMat;
    poShader->PushInstruction(poTop);
}

void CShadowCaster::Setup (CGVect3& _oLightPos, CGSceneNode* _poBlockerObj, CGMesh* * _poRecObjs, int _iNumRecObjs)
{
    oLPos.Assign(_oLightPos);
    poBlockerObj = _poBlockerObj;

    poRecObjs = _poRecObjs;
    iNumRecObjs = _iNumRecObjs;

    RenderShadowMap();

    ComputeTextureProjection();
}

CGraphBV* CShadowCaster::poGetBV ()
{
    return (NULL);
}

void CShadowCaster::ComputeBoundVol ()
{
}

void CShadowCaster::ComputeLightCamera ()
{
    CE3D_Camera oCam;

    oCam.m_oDir.Assign( poBlockerObj->poGetBV()->GetCenter() );
    oCam.m_oDir.Sub   (oLPos);
    oCam.m_oDir.Normalize();

    // _oCam.Side = Orthogonal();
    oCam.m_oSide.Orthogonal(oCam.m_oDir);
    oCam.m_oSide.Normalize ();

    oCam.m_oUp.CrossProd(oCam.m_oDir,oCam.m_oSide);
    oCam.m_oPos.Assign   (oLPos);

    /*
       // Compute camera viewing matrix
       CGVect3 oDir,oSide,oUp;

       oDir.Assign(poBlockerObj->poGetBoundVol()->GetCenter());
       oDir.Sub   (oLPos);
       oDir.Normalize();

       // Side = Orthogonal();
       oSide.Orthogonal(oDir);
       oSide.Normalize ();

       oUp.CrossProd(oDir,oSide);

       oCamMat.SetColVector(0,oSide.x,oSide.y,oSide.z,0.0f);
       oCamMat.SetColVector(1,oDir .x,oDir .y,oDir .z,0.0f);
       oCamMat.SetColVector(2,oUp  .x,oUp  .y,oUp  .z,0.0f);
       oCamMat.SetColVector(3,oLPos.x,oLPos.y,oLPos.z,1.0f);

       _oCam.Dir.Assign	(oDir);
       _oCam.Side.Assign	(oSide);
       _oCam.Up.Assign	(oUp);
       _oCam.Pos.Assign   (oLPos);
     */

    // <OPTIMIZABLE> Via own camera computation.
    CGRenderer::I()->SetCamera(&oCam);
    CGRenderer::I()->GetCameraMatrix(&oCamMat);
}

void CShadowCaster::ComputeLightViewport (CE3D_Viewport& _oVpt)
{
    float fTX = (float)iRes / (float)CGRenderer::I()->iGetScrTX();
    float fTY = (float)iRes / (float)CGRenderer::I()->iGetScrTY();

    _oVpt.SetViewport(0.0f,0.0f,fTX,fTY);
}

void CShadowCaster::ComputeLightProjection ()
{
    CGraphBV_Box oBox;
    CGVect3* poPnt = oBox.Vol.m_oPoints;
    oBox.Copy( poBlockerObj->poGetBV() );

    // Transform bounding volume points
    float fXAbs,fYAbs;
    float fXMax,fYMax;

    fXMax = -1e6f;
    fYMax = -1e6f;
    for ( int iPnt = 0; iPnt < 8; iPnt++ )
    {
        oCamMat.TransformPoint(poPnt[iPnt]);

        fXAbs = MATH_fAbs(poPnt[iPnt].x / poPnt[iPnt].z);
        fYAbs = MATH_fAbs(poPnt[iPnt].y / poPnt[iPnt].z);

        if ( fXMax < fXAbs ) fXMax = fXAbs;
        if ( fYMax < fYAbs ) fYMax = fYAbs;
    }

    const float fLFar = 1000.0f;
    const float fLNear = 0.1f;
    float A = 1.0f - 2.0f / (float)iRes;
    const float B = (fLFar + fLNear) / (fLNear - fLFar);
    const float C = 2 * (fLFar * fLNear) / (fLNear - fLFar);

    oPrjMat.LoadIdentity();
    oPrjMat.Set(0,0,A / fXMax);
    oPrjMat.Set(1,1,A / fYMax);
    oPrjMat.Set(2,2,B);
    oPrjMat.Set(2,3,C);                    // Este es el orden correcto !
    oPrjMat.Set(3,2,-1);                    // Este es el orden correcto !
    oPrjMat.Set(3,3,0);
}

void CShadowCaster::ComputeTextureProjection ()
{
    CMatrix4x4 oAuxMat;

    oAuxMat = oPrjMat;

    /*
       oAuxMat.Set(0,0,oAuxMat.Get(0,0)*0.5f);
       oAuxMat.Set(1,1,oAuxMat.Get(1,1)*0.5f);
       oAuxMat.Set(0,2,-0.5f);
       oAuxMat.Set(1,2,-0.5f);
     */

    CMatrix4x4 oScaleMat;
    oScaleMat.LoadIdentity();
    oScaleMat.Scale(0.5f,0.5f,1.0f);

    CMatrix4x4 oTransMat;
    oTransMat.LoadIdentity();
    oTransMat.Translate(0.5f,0.5f,0.0f);

    oAuxMat = oPrjMat;
    oAuxMat.MultiplyBy(oScaleMat);

    oPrjTexMat = oCamMat;
    oPrjTexMat.MultiplyBy(oPrjMat);
    oPrjTexMat.MultiplyBy(oScaleMat);
    oPrjTexMat.MultiplyBy(oTransMat);

    oPrjTexMat = oTransMat;
    oPrjTexMat.MultiplyBy(oScaleMat);
    oPrjTexMat.MultiplyBy(oPrjMat);
    oPrjTexMat.MultiplyBy(oCamMat);

    // oPrjTexMat.Multiply(oAuxMat,oCamMat);
}

void CShadowCaster::UploadShadowMap ()
{
    // Retrieve texture from frame buffer
    CGRenderer::I()->ReadBuffer(0,0,iRes,iRes,E3D_RB_Back,poTexObj->m_poMipMap->m_pLOD[0]);

    #ifdef _SMOOTH_SHADOW2_
    int cI,cJ;
    char* pucPixelA = poTexObj->Tex->MipMap.LOD[0].data;
    char* pucPixelB;
    unsigned short usValue;
    for ( cJ = 0; cJ < iRes; cJ++ )
    {
        pucPixelB = pucPixelA + 4;
        for ( cI = 1; cI < iRes; cI++ )
        {
            if ( *pucPixelB != *pucPixelA )
            {
                usValue = (pucPixelB[0] + pucPixelA[0]) >> 1;

                pucPixelA[0] = usValue;
                pucPixelA[1] = usValue;
                pucPixelA[2] = usValue;
                pucPixelA[3] = usValue;
            }

            pucPixelA += 4;
            pucPixelB += 4;
        }

        pucPixelA = pucPixelB;
    }
    #endif

    // Force update
    poTexObj->m_poMipMap->Invalidate();
}

void CShadowCaster::RenderShadowMap ()
{
    CE3D_Viewport oVpt;
    CE3D_Viewport* poOldVpt;
    CMatrix4x4 oOldPrjMat;
    CMatrix4x4 oOldCamMat;

    // Save current state
    CGRenderer::I()->GetProjectorMatrix(&oOldPrjMat);
    CGRenderer::I()->GetCameraMatrix   (&oOldCamMat);
    poOldVpt = CGRenderer::I()->GetViewport();

    // Set current point of view
    ComputeLightViewport    (oVpt);
    CGRenderer::I()->SetViewport(&oVpt);

    ComputeLightCamera();
    ComputeLightProjection();

    CGRenderer::I()->SetCameraMatrix(&oCamMat);
    CGRenderer::I()->SetProjectorMatrix(&oPrjMat);

    // Rendering

    // El objeto es visible completamente porque el frustum de la luz
    // es adaptativo
    CGRenderer::I()->DisableFrustumCulling();
    CGRenderer::I()->EnableFlatRendering();
    CGRenderer::I()->SetZPars(E3D_ZTF_None, E3D_ZW_Disable);

    // Clear buffer
    CGRenderer::I()->ClearBuffer(E3D_RB_Back);

    // Render blocking object
    poBlockerObj->Render();

    // Get ShadowMap texture
    UploadShadowMap ();

    CGRenderer::I()->SetZPars(E3D_ZTF_Last, E3D_ZW_Last);
    CGRenderer::I()->DisableFlatRendering();

    // Restore state
    CGRenderer::I()->SetViewport     (poOldVpt);
    CGRenderer::I()->SetProjectorMatrix(&oOldPrjMat);
    CGRenderer::I()->SetCameraMatrix   (&oOldCamMat);
}

void CShadowCaster::Render ()
{
    for ( int iObj = 0; iObj < iNumRecObjs; iObj++ )
    {
        oTexProj.Setup(poRecObjs[iObj],poShader,oPrjTexMat);
        oTexProj.Render();
    }
}

// Additional Declarations
