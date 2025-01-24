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
// CLensFlare
#include "LensFlare\CLensFlare.h"
#define _1_OVER_SQRT_2 0.70710678118654752440084436210485

#define LFST_Off        0
#define LFST_Showing    1
#define LFST_On         2
#define LFST_Hidding    3
#define CHST_SPEED      1.0f

float fCamDist;
float fCamSunAngle;

// -----------------------------------------------------------------------------
float fGetVisibilityFactor(CVect3 &_oPrjPos,float _fFlareCamZ)
{
#define         ZBUFFER_RECT_HSIZE          2
#define         ZBUFFER_RECT_VSIZE          2

    const float _1_OVER_65535_ = 1.0f / 65535.0f;

    unsigned int uiZBufferRect[ZBUFFER_RECT_HSIZE * ZBUFFER_RECT_VSIZE];
    int iIX,iIY;
    int iVisEntries = 0;
    float fZPos;
    float fZValue;
    float fZNear,fZFar;
    float fZRange;
    float fZMult;

    // Retrieve current viewport
    float m_fAspectRatio = CGRenderer::I()->fGetAspectRatio();

    // Retrieve the screen position
    iIX = ( (_oPrjPos.x + 1.0f) / 2.0f ) * CGRenderer::I()->iGetScrTX();
    iIY = ( (_oPrjPos.y + 1.0f) / 2.0f ) * CGRenderer::I()->iGetScrTY();

    // Read pixel z buffer
    CGRenderer::I()->ReadBuffer(iIX,
                                iIY,
                                ZBUFFER_RECT_HSIZE,
                                ZBUFFER_RECT_VSIZE,
                                E3D_RB_Z,
                                uiZBufferRect);

    // Compute the average of non occluded pixels
    fZFar = CGRenderer::I()->GetProjector()->fFar;
    fZNear = CGRenderer::I()->GetProjector()->fNear;
    fZRange = fZFar - fZNear;
    fZMult = fZFar * fZNear;

    for ( int iIdx = 0; iIdx < ZBUFFER_RECT_HSIZE * ZBUFFER_RECT_VSIZE; iIdx++ )
    {
        // <VKiller2k> Assume 24 bit ZBuffer
        fZValue = (float)(uiZBufferRect[iIdx] >> 16) * _1_OVER_65535_;
        fZPos = fZMult / (fZFar - fZValue * fZRange);

        if ( _fFlareCamZ < fZPos )
            iVisEntries++;
    }

    return ( (float)iVisEntries / ( (float)ZBUFFER_RECT_HSIZE * ZBUFFER_RECT_VSIZE ) );
}

// Class CLensFlare

CLensFlare::CLensFlare()
    : FlareElems(NULL), iNumElems(0), MeshArray(NULL), iLensFlareState(0), fVisFact(0.0f)
{
}

CLensFlare::~CLensFlare()
{
    if ( FlareElems ) mDel [] FlareElems;
    if ( MeshArray ) mDel [] MeshArray;
}

void CLensFlare::InitLensFlare (int _iNumElems, CVect3 _SunPos)
{
    // Setup lens flare properties
    oSunPos.Assign(_SunPos);
    iNumElems = _iNumElems;

    // -----------------------------------------------------
    // Create the flare elem array
    // -----------------------------------------------------
    FlareElems = mNew CLensFlare_Elem[iNumElems];

    // -----------------------------------------------------
    // Create the flare elem array
    // -----------------------------------------------------
    MeshArray = mNew CGMeshRect[iNumElems];
}

void CLensFlare::SetupFlareElem (int _iElem, float _fSize, float _fDist, CGColor _Color, CE3D_Shader* _pMat)
{
    assert (FlareElems && "NULL Lens flare elem array");
    assert ( (_iElem < iNumElems) && "Flare elem out of bounds" );

    FlareElems[_iElem].fSize = _fSize;
    FlareElems[_iElem].fDist = _fDist;
    FlareElems[_iElem].Color = _Color;
    FlareElems[_iElem].pMaterial = _pMat;
}

void CLensFlare::UpdateMesh ()
{
    int cElem;
    CVect3 NewPos;
    CVect3* pVX;
    CGColor* pVC;

    float fAlpha;
    CVect3 oSunScr;
    float fSize,fDist,fDistFact;

    // ---------------------------
    // Get the projected line eq
    // ---------------------------

    oPrjSun.y = 0.0f;

    // Get direction from projected sun position to the screen center
    // (Center - oPrjSun)

    oSunScr.V3(-oPrjSun.x,-oPrjSun.y,0.0f);

    // fDistFact = oPrjSun.Module() / sqrt(2);
    // fDistFact = oPrjSun.Module() * _1_OVER_SQRT_2
    // fDistFact = oPrjSun.SqModule()  / 2;
    fDistFact = MATH_fSqrt( oPrjSun.fSqModule() * 0.5f );

    // sqrt(x)/sqrt(2) si x (0,2) es +-=  x/2
    // fDistFact = oSunScr.SqModule()*0.5f;

    // Alpha decreases in squared proportion to Angle
    // fAlpha = fCamSunAngle*fCamSunAngle;
    // fAlpha = (1.0f - fDistFact)*1.025f*fVisFact;
    fAlpha = fVisFact;

    // Init lens flare elems
    float fInvRatio = 1.0f / CGRenderer::I()->fGetAspectRatio();

    for ( cElem = 0; cElem < iNumElems; cElem++ )
    {
        pVX = MeshArray[cElem].m_poVX;
        pVC = MeshArray[cElem].m_poVC;

        // Size decreases in angle
        fSize = FlareElems[cElem].fSize * fCamSunAngle;
        fDist = FlareElems[cElem].fDist * fDistFact / _1_OVER_SQRT_2;

        NewPos.LineEq(oPrjSun,oSunScr, fDist );

        // Set screen coordinates (normalized)
        pVX[3].V3(-fSize * fInvRatio,-fSize,0);
        pVX[3].Add(NewPos);
        pVX[2].V3(-fSize * fInvRatio, fSize,0);
        pVX[2].Add(NewPos);
        pVX[1].V3( fSize * fInvRatio, fSize,0);
        pVX[1].Add(NewPos);
        pVX[0].V3( fSize * fInvRatio,-fSize,0);
        pVX[0].Add(NewPos);

        // Set vertex color
        pVC[0] = FlareElems[cElem].Color;
        pVC[1] = FlareElems[cElem].Color;
        pVC[2] = FlareElems[cElem].Color;
        pVC[3] = FlareElems[cElem].Color;

        pVC[0].a *= fAlpha;
        pVC[1].a *= fAlpha;
        pVC[2].a *= fAlpha;
        pVC[3].a *= fAlpha;
    }
}

void CLensFlare::Render ()
{
    assert (FlareElems && "NULL Lens flare elem array");

    CGRenderer::I()->GetCameraMatrix     (&oViewMat);
    CGRenderer::I()->GetProjectorMatrix(&oPrjMat);
    UpdateState();

    if ( iLensFlareState == LFST_Off ) return;

    // ---------------------------
    // Update Lens flare meshes
    // ---------------------------
    UpdateMesh();

    // ---------------------------
    // Flare Rendering
    // ---------------------------
    CGRenderer::I()->SetFogPars(E3D_FM_None,0.0f,0.0f,0.0f,NULL);
    CGRenderer::I()->ClearProjectorMatrix();
    CGRenderer::I()->ClearCameraMatrix();

    for ( int cElem = 0; cElem < iNumElems; cElem++ )
        CGRenderer::I()->RenderMesh(&MeshArray[cElem],FlareElems[cElem].pMaterial);

    CGRenderer::I()->SetCameraMatrix   (&oViewMat);
    CGRenderer::I()->SetProjectorMatrix(&oPrjMat);
    CGRenderer::I()->SetFogPars(E3D_FM_Last,0.0f,0.0f,0.0f,NULL);
}

CGraphBV* CLensFlare::poGetBV ()
{
    return (NULL);
}

void CLensFlare::ComputeBoundVol ()
{
}

bool CLensFlare::bVisible ()
{
    // ---------------------------
    // Get the projected sun point
    // ---------------------------
    oPrjSun.Assign(oSunPos);
    oViewMat.TransformPoint(oPrjSun);
    oPrjMat.TransformPoint(oPrjSun);

    oPrjSun.x = oPrjSun.x / oPrjSun.z;
    oPrjSun.y = oPrjSun.y / oPrjSun.z;

    if ( (oPrjSun.x < -1.0f) || (oPrjSun.x > 1.0f) ||
        (oPrjSun.y < -1.0f) || (oPrjSun.y > 1.0f) ||
        (oPrjSun.z < 0.0f) )
        return(false);

    // ------------------------------------------------------
    // Get camera-sun distance
    // ------------------------------------------------------
    CE3D_Camera* pCam = CGRenderer::I()->GetCamera();
    CVect3 oSunCam;

    oSunCam.Assign( pCam->m_oPos );
    oSunCam.Sub(oSunPos);
    fCamDist = oSunCam.fModule();

    // Safe exit
    if ( fCamDist == 0.0f ) return(false);
    oSunCam.Scale(1.0f / fCamDist);

    // ------------------------------------------------------
    // Get the angle between camera dir vector and sun-camera vector
    // ------------------------------------------------------
    fCamSunAngle = -1.0f * pCam->m_oDir.fDotProd(oSunCam);

    // <WARNING: DEBUG CODE>
    // return(true);

    // Get occlussion factor
    float fVFact = fGetVisibilityFactor(oPrjSun,500.0f);
    return(fVFact > 0.0f);
}

void CLensFlare::UpdateState ()
{
    bool bLFVisible = bVisible();

    // Update flare state
    switch ( iLensFlareState )
    {
        case LFST_Off:
        {
            if ( bLFVisible )
            {
                iLensFlareState = LFST_Showing;
                fVisFact = 0.0f;
            }
        }
        break;

        case LFST_Showing:
        {
            if ( bLFVisible )
            {
                fVisFact += CHST_SPEED * CGRenderer::I()->REStats.DTime;

                if ( fVisFact >= 1.0f )
                {
                    fVisFact = 1.0f;
                    iLensFlareState = LFST_On;
                }
            }
            else
                iLensFlareState = LFST_Hidding;
        }
        break;

        case LFST_On:
        {
            if ( !bLFVisible )
            {
                iLensFlareState = LFST_Hidding;
                fVisFact = 1.0f;
            }
        }
        break;

        case LFST_Hidding:
        {
            if ( !bLFVisible )
            {
                fVisFact -= CHST_SPEED * CGRenderer::I()->REStats.DTime;

                if ( fVisFact <= 0.0f )
                {
                    fVisFact = 0.0f;
                    iLensFlareState = LFST_Off;
                }
            }
            else
                iLensFlareState = LFST_Showing;
        }
        break;
    }
}

// Additional Declarations
