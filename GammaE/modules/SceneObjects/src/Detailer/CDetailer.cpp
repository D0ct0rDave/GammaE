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
#include <string.h>
#include "GammaE_Mem.h"

#ifdef _MBCS
    #include <windows.h>
    #include <wingdi.h>

    #define TPixelFormatDescriptor  PIXELFORMATDESCRIPTOR
    #define TLogPalette             LOGPALETTE
    #define TPaletteEntry           PALETTEENTRY
#else
    #ifdef _BCB_
        #include <vcl\vcl.h>
    #endif
#endif

#include <gl/gl.h>

// CDetailer
#include "Detailer\CDetailer.h"
#define TEX_SIZE            128

#define TEX_NOISE_AMPLITUDE 255
#define TEX_NOISE_OFFSET    0

// Class CDetailer

CDetailer::CDetailer()
    : poTex(NULL)
{
}

CDetailer::~CDetailer()
{
    if ( poTex )
    {
        mDel(poTex);
    }
}

void CDetailer::Init (int _iMaxTris)
{
    poMesh = mNew CGMesh();
    poMesh->Init(   _iMaxTris * 3,_iMaxTris,
                    E3D_MESH_NITRIS,
                    MESH_FIELD_VERTEXS |
                    MESH_FIELD_UVCOORDS |
                    MESH_FIELD_COLORS);

    poShader = poCreateMaterial();

    poMesh->m_uiNumIdxs = 0;
    poMesh->m_uiNumPrims = 0;
    poMesh->m_usNumVXs = 0;
}

void CDetailer::SetCamPos (CVect3& _oCamPos)
{
    oCamPos.Assign( _oCamPos);
}

void CDetailer::SetVertexTris (CVect3* _poVXs, int _iNumTris)
{
    poMesh->m_uiNumIdxs = 0;
    poMesh->m_uiNumPrims = _iNumTris;
    poMesh->m_usNumVXs = _iNumTris * 3;

    if ( !_iNumTris ) return;

    static float fThresholdDist = 50.0f;
    static float fUVMultiplier = 0.125f;
    static float fColorAmp = 0.3f;

    int cI;
    float fDist;
    CVect3* poVX = poMesh->m_poVX;
    CVect2* poUV = poMesh->m_poUV;
    CGColor* poVC = poMesh->m_poVC;

    // Compute
    poVX = poMesh->m_poVX;
    for ( cI = 0; cI < _iNumTris * 3; cI++ )
    {
        // Increase height
        poVX->Assign(*_poVXs);
        poVX->z += 0.05f;

        // Compute UV
        poUV->x = poVX->x * fUVMultiplier;
        poUV->y = poVX->y * fUVMultiplier;

        // Compute color
        fDist = oCamPos.fSqDistance(*poVX);
        fDist /= fThresholdDist;
        if ( fDist > 1.0f ) fDist = 1.0f;
        fDist = 1.0f - fDist;

        poVC->Set(1.0f,1.0f,1.0f,fDist * fColorAmp);

        _poVXs++;
        poVX++;
        poUV++;
        poVC++;
    }
}

void CDetailer::CreateTextureContents (CGMipMap* _pMipMap)
{
    int cI,cJ;
    int iValue;
    char* pData = (char*)_pMipMap->m_pLOD[0];

    for ( cJ = 0; cJ < TEX_SIZE; cJ++ )
        for ( cI = 0; cI < TEX_SIZE; cI++ )
        {
            iValue = TEX_NOISE_OFFSET + TEX_NOISE_AMPLITUDE* MATH_fRand();

            /*
               if (iValue > 128)
                if (MATH_fRand() < 0.9f)
                {
                    iValue = MATH_fRand()*128;
                }
             */

            pData[0] = 16;
            pData[1] = 16;
            pData[2] = 16;
            pData[3] = iValue;

            pData += 4;
        }
}

CE3D_Shader* CDetailer::poCreateMaterial ()
{
    poTex = mNew CGMipMap(TEX_SIZE,TEX_SIZE,1,IF_RGBA);
    CreateTextureContents(poTex);

    CE3D_Shader* poSh = CE3D_ShaderUtils::poGenerateShaderFromMipMap(poTex,"DetailMap.tex");

    // Setup blending op instruction
    CE3D_ShIns_BlendOp* poBO = mNew CE3D_ShIns_BlendOp;
    poBO->SetBlendMode(E3D_BM_Alpha);

    poSh->PushInstruction(poBO);

    return (poSh);
}

void CDetailer::Render ()
{
    CGSceneLeaf::Render();
}

// Additional Declarations
