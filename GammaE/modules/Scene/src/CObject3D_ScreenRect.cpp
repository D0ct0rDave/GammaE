// ----------------------------------------------------------------------
#include "GammaE_Mem.h"
#include "CObject3D_ScreenRect.h"
// ----------------------------------------------------------------------
// Class CObject3D_ScreenRect
// ----------------------------------------------------------------------
CObject3D_ScreenRect::CObject3D_ScreenRect() : poShader(NULL)
{
    TypeID   = e3DObj_ScreenRect;

    poMesh   = mNew CMesh_Rect;

    oMat.LoadIdentity();
    oMat.Set(1,1,-1.0f);

    BVol = poCreateBoundVol();
    ComputeBoundVol();
}
// ----------------------------------------------------------------------
CObject3D_ScreenRect::~CObject3D_ScreenRect()
{
    Clear();
}
// ----------------------------------------------------------------------
void CObject3D_ScreenRect::Clear()
{
   mDel poMesh;

    poMesh = NULL;
}
// ----------------------------------------------------------------------
CGraphBV *CObject3D_ScreenRect::poCreateBoundVol()
{
   eGraphBV_TypeID eOldType = CGraphBV_Manager::eGetBVMode();

   CGraphBV_Manager::SetBVMode(eGraphBV_Box);

   CGraphBV *poBVol = CGraphBV_Manager::poCreate();

   CGraphBV_Manager::SetBVMode(eOldType);

    return( poBVol );
}
// ----------------------------------------------------------------------
CGraphBV *CObject3D_ScreenRect::poGetBoundVol()
{
    return( BVol );
}
// ----------------------------------------------------------------------
void CObject3D_ScreenRect::ComputeBoundVol()
{
   poMesh->ComputeBoundVol();

     // Recompute Bounding Volume
    BVol->Copy( poMesh->BVol );
    BVol->Transform(oMat);
}
// ----------------------------------------------------------------------
void CObject3D_ScreenRect::SetRect(float _fX,float _fY,float _fTX,float _fTY)
{
/*
    oMat.LoadIdentity();
    oMat.Translate(-1.0f,1.0f,0.0f);
    oMat.Translate(_fX/0.5f,-_fY/0.5f,0.0f);
    oMat.Scale(_fTX,_fTY,1);
    oMat.Translate(1.0f,-1.0f,0.0f);
    oMat.Scale(2.0f,2.0f,1);
    oMat.Scale(1.0f/_fTX,-1.0f/_fTY,1.0f);
    oMat.Translate(_fX,_fY,0.0f);
 */
    // oMat.LoadIdentity();
    // oMat.Scale(_fTX,-_fTY,1.0f);
    // oMat.Translate(_fX - 2.0f*_fTX,_fY - 2.0f*_fTY,0.0f);

    // ComputeBoundVol();
}
// ----------------------------------------------------------------------
void CObject3D_ScreenRect::Render()
{
     // Setup our Render State
    CGRenderer::I()->PushProjectorMatrix();
    CGRenderer::I()->ClearProjectorMatrix();
    CGRenderer::I()->PushCameraMatrix();
    CGRenderer::I()->ClearCameraMatrix();
    CGRenderer::I()->PushWorldMatrix();
    CGRenderer::I()->SetWorldMatrix( &oMat );

    CGRenderer::I()->RenderMesh( poMesh,poGetShader() );

    CGRenderer::I()->PopWorldMatrix();
    CGRenderer::I()->PopCameraMatrix();
    CGRenderer::I()->PopProjectorMatrix();
}
// ----------------------------------------------------------------------
