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

// CGSceneReflector
#include "Reflector\CGSceneReflector.h"

// Class CGSceneReflector

CGSceneReflector::CGSceneReflector()
    : Mirror(NULL)
{
    Mirror = mNew CGMeshRect();
}

CGSceneReflector::~CGSceneReflector()
{
    mDel Mirror;
}

void CGSceneReflector::Render ()
{
    CMatrix4x4 M;
    CMatrix4x4 PrjMatrix;
    CMatrix4x4 FPrjMat;

    // Enable stenciling
    CGRenderer::I()->SetStencilPars(E3D_SF_Always,1,~0,E3D_SA_Keep,E3D_SA_Keep,E3D_SA_Replace);

    // Render the reflector object first with stencil on
    CGRenderer::I()->ClearBuffer(E3D_RB_Stencil);

    CGRenderer::I()->SetZPars(E3D_ZTF_None, E3D_ZW_Disable);
    CGRenderer::I()->RenderMesh(Mirror);
    CGRenderer::I()->SetZPars(E3D_ZTF_Last, E3D_ZW_Last);

    // Disable Stenciling
    CGRenderer::I()->SetStencilPars(E3D_SF_None,0,0,E3D_SA_None,E3D_SA_None,E3D_SA_None);

    /*
       CGRenderer::I()->GetGetProjectorMatrix(&M);
       // Setup reflection matrix
       SetupReflectionMatrix(PrjMatrix);

       // La reflexión tambien debe aparecer projectada en pantalla (por supuesto)
       FPrjMat.Multiply(PrjMatrix,M);

       // Setup reflection matrix
       CGRenderer::I()->SetProjectorMatrix(&FPrjMat);

       // Normal Rendering
       CGSceneNode::Render();

       // Restore previous matrix
       CGRenderer::I()->SetProjectorMatrix(&M);
     */

    CGRenderer::I()->PushWorldMatrix();

    // Setup reflection matrix
    SetupReflectionMatrix(PrjMatrix);

    CGRenderer::I()->MultiplyMatrix(&PrjMatrix);

    // Normal Rendering
    CGSceneGroup::Render();

    // Restore previous matrix
    CGRenderer::I()->PopWorldMatrix();

    glDisable(GL_STENCIL_TEST);
}

void CGSceneReflector::SetupReflectionMatrix (CMatrix4x4 &_oMat)
{
    CPlane Plane;
    CGVect3 Normal;
    float D;

    Plane.GenerateFromPoints(Mirror->m_poVX[0],Mirror->m_poVX[1],Mirror->m_poVX[2]);
    Normal.Assign( Plane.Normal() );
    // Normal.Set(0,0,1);
    D = -1.0f * Plane.D();

    _oMat.Set(0,0,1.0f - 2.0f * Normal.x * Normal.x);
    _oMat.Set(0,1,     -2.0f * Normal.x * Normal.y);
    _oMat.Set(0,2,     -2.0f * Normal.x * Normal.z);
    _oMat.Set(0,3,       2.0f * Normal.x * D);

    _oMat.Set(1,0,     -2.0f * Normal.y * Normal.x);
    _oMat.Set(1,1,1.0f - 2.0f * Normal.y * Normal.y);
    _oMat.Set(1,2,     -2.0f * Normal.y * Normal.z);
    _oMat.Set(1,3,       2.0f * Normal.y * D);

    _oMat.Set(2,0,     -2.0f * Normal.z * Normal.x);
    _oMat.Set(2,1,     -2.0f * Normal.z * Normal.y);
    _oMat.Set(2,2,1.0f - 2.0f * Normal.z * Normal.z);
    _oMat.Set(2,3,       2.0f * Normal.z * D);

    _oMat.Set(3,0,0.0f);
    _oMat.Set(3,1,0.0f);
    _oMat.Set(3,2,0.0f);
    _oMat.Set(3,3,1.0f);
}

// Additional Declarations
