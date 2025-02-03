// ----------------------------------------------------------------------------
#include <windows.h>
#include "CLoop.h"
#include "GammaE.h"

// ----------------------------------------------------------------------------
typedef struct TLoopGlobals
{
	HWND m_hWnd;
	uint m_uiScrWidth;
	uint m_uiScrHeight;
	float m_fTime;
	CGChrono m_oChrono;
}TLoopGlobals;

static TLoopGlobals globals;

CGViewport		    Viewport;
CGCamera			PerspCam;
CGProjector		    PerspPrj;
CGSceneCamera       gCamera;
CGSceneNode*		gpoScene = NULL;
// ----------------------------------------------------------------------------
void CLoop::Init(void* _hWnd)
{
	globals.m_hWnd = (HWND)_hWnd;
	RECT Rect;
	GetWindowRect(globals.m_hWnd,&Rect);

	// Initialize some objects in the system
	globals.m_uiScrWidth  = Rect.right - Rect.left;
	globals.m_uiScrHeight = Rect.bottom - Rect.top;

    CGRenderer::I()->bInit(globals.m_hWnd,E3D_RENDERER_OP_GDI | E3D_RENDERER_OP_DBUFFER,globals.m_uiScrWidth,globals.m_uiScrHeight,32);

	Viewport.ScrCX = 0.0f;
    Viewport.ScrCY = 0.0f;
    Viewport.ScrTX = 1.0f;
    Viewport.ScrTY = 1.0f;

    // La orientacion de la cámara se determina utilizando 3 vectores
    // que son los ejes locales de la cámara
	// PerspCam.Pos.V3 ( 4, 10,270);
	PerspCam.SetPos( 0.0f,-500.0f,0.0f);
	CGVect3 oDir(0, 1, 0);
	CGVect3 oUp(0, 0, 1);
	CGVect3 oSide(1,0,0);
	PerspCam.SetVectors(oDir, oUp, oSide);

	PerspPrj.ePrjType = E3D_PT_Perspective;
	PerspPrj.fFOV     = 45.0f;
    PerspPrj.fNear    = 1.0f;
    PerspPrj.fFar     = 2000.0f;

	// -------------------------------
	// Orthographic projection camnera
	// -------------------------------
    CGRenderer::I()->SetViewport (&Viewport);
    CGRenderer::I()->SetCamera   (&PerspCam);
	CGRenderer::I()->SetProjector(&PerspPrj);

    CGRenderer::I()->DisableFrustumCulling();
	CGRenderer::I()->SetZPars(E3D_ZTF_LEqual,E3D_ZW_Enable);

  	gCamera.Init	    (100);
	gCamera.SetCamera   (&PerspCam);
	gCamera.SetProjector(&PerspPrj);
	gCamera.SetViewport (&Viewport);

	CGShader* poShader = new CGShader;
	CGShInsWireframe* poInst = mNew CGShInsWireframe;
	poInst->SetColor(CGColor(1.0f, 1.0f, 0.0f, 1.0f));
	poShader->AddInstruction(poInst);
		
	CGSceneLeaf* poLeaf = mNew CGSceneLeaf();
	poLeaf->SetMesh(mNew CGMeshSphere());
	poLeaf->SetShader(poShader);

	gCamera.iAddObject(poLeaf);

	gpoScene = poLeaf;
    globals.m_fTime = 0.0f;
}
// ----------------------------------------------------------------------------
void CLoop::Loop()
{
	globals.m_oChrono.Stop();
	float fDeltaT  = globals.m_oChrono.dElapsedTime();
	globals.m_oChrono.Reset();
	globals.m_oChrono.Start();	

	Update(fDeltaT);
	Render();
}
// ----------------------------------------------------------------------------
void CLoop::Update(float _fDeltaT)
{
	globals.m_fTime += _fDeltaT;

	const float FREQ = 1.0f/4.0f;
	float fAngle = globals.m_fTime*FREQ;
		
	CGVect3 oCenter = CGVect3::oZero();
	CGVect3 oRange(1.0f,1.0f,1.0f);
	CGVect3 oPos;
		
	if (gpoScene->poGetBV() != NULL)
	{
		oCenter = gpoScene->poGetBV()->oGetCenter();
		oRange = gpoScene->poGetBV()->GetExtents();
		PerspCam.LookAt(oCenter);
	}
	float fAmplitude = oRange.fModule() * 2.0f;
		
	oPos.x = oCenter.x + fAmplitude * Math::fSin(fAngle);
	oPos.y = oCenter.y + fAmplitude * Math::fCos(fAngle);
	oPos.z = oCenter.z;

	PerspCam.SetPos(oPos.x,oPos.y,oPos.z);
	PerspCam.LookAt(oCenter);
}
// ----------------------------------------------------------------------------
void CLoop::Render()
{
	if (CGRenderer::I() == NULL) return;

	// World think entities
	CGRenderer::I()->BeginRender();

		// Render camera scene
		CGSCNVRenderer::I()->Render(&gCamera);

    CGRenderer::I()->EndRender();
}
// ----------------------------------------------------------------------------
