//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop


#include "MD2Convert.h"

#include <GammaE.h>
#include "Input/CommandBinder/CommandBinder.h"
#include "Input/CommandDispatcher/ClientCmdDispatcher.h"
#include "Game/GameInit/CGame_KeyBinder.h"
#include "WinEventTranslator.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;
//---------------------------------------------------------------------------
// Global variables
//---------------------------------------------------------------------------
unsigned int            uiScrWidth;
unsigned int            uiScrHeight;
CE3D_OGL_Win_Renderer   gRenderer;

CE3D_Viewport		    Viewport;
CE3D_Camera			    PerspCam;
CE3D_Projector		    PerspPrj;
char				    *szCmdLine;

CChrono                 oMainChrono;

CObject3D_AnimCfg       *poModel = NULL;
CObject3D_AnimMesh      *poAMesh = NULL;
CObject3D_Leaf          *poLeaf  = NULL;

float                   gDeltaT;
CE3D_Shader             *gpoShader= NULL;
CObject3D_Camera        gCamera;
bool                    bFinnishApplication = false;
// ----------------------------------------------------------------------------
// Interface
// ----------------------------------------------------------------------------
unsigned int CameraMovementFlags = 0;

bool		 bMouseDown = false;

int			 iOldX;
int			 iOldY;

float		 fOldPitch = 0;
float		 fPitch    = 0;
float		 fOldYaw   = 0;
float		 fYaw      = 0;
CVect3		 CamDir;
CVect3		 CamUp;
CVect3		 CamSide;

// ----------------------------------------------------------------------------
// Function prototypes
// ----------------------------------------------------------------------------
void AppLoop_OnCamForward  (unsigned int Enabled,unsigned int Par1,unsigned int Par2);
void AppLoop_OnCamBackward (unsigned int Enabled,unsigned int Par1,unsigned int Par2);
void AppLoop_OnCamUp       (unsigned int Enabled,unsigned int Par1,unsigned int Par2);
void AppLoop_OnCamDown     (unsigned int Enabled,unsigned int Par1,unsigned int Par2);
void AppLoop_OnCamLeft     (unsigned int Enabled,unsigned int Par1,unsigned int Par2);
void AppLoop_OnCamRight    (unsigned int Enabled,unsigned int Par1,unsigned int Par2);

void AppLoop_OnWalkForward (unsigned int Enabled,unsigned int Par1,unsigned int Par2);
void AppLoop_OnWalkBackward(unsigned int Enabled,unsigned int Par1,unsigned int Par2);
void AppLoop_OnWalkUp      (unsigned int Enabled,unsigned int Par1,unsigned int Par2);
void AppLoop_OnWalkDown    (unsigned int Enabled,unsigned int Par1,unsigned int Par2);
void AppLoop_OnWalkLeft    (unsigned int Enabled,unsigned int Par1,unsigned int Par2);
void AppLoop_OnWalkRight   (unsigned int Enabled,unsigned int Par1,unsigned int Par2);

void AppLoop_OnTurnUp      (unsigned int Enabled,unsigned int Par1,unsigned int Par2);
void AppLoop_OnTurnDown    (unsigned int Enabled,unsigned int Par1,unsigned int Par2);
void AppLoop_OnTurnLeft    (unsigned int Enabled,unsigned int Par1,unsigned int Par2);
void AppLoop_OnTurnRight   (unsigned int Enabled,unsigned int Par1,unsigned int Par2);

void AppLoop_OnExit	       (unsigned int Enabled,unsigned int Par1,unsigned int Par2);
void AppLoop_OnJump        (unsigned int Enabled,unsigned int Par1,unsigned int Par2);
void AppLoop_OnAttack      (unsigned int Enabled,unsigned int Par1,unsigned int Par2);
void AppLoop_OnAttack2     (unsigned int Enabled,unsigned int Par1,unsigned int Par2);
void AppLoop_OnMouseMove   (unsigned int Enabled,unsigned int Par1,unsigned int Par2);
void AppLoop_ToggleConsole (unsigned int Enabled,unsigned int Par1,unsigned int Par2);
void AppLoop_Screenshot    (unsigned int Enabled,unsigned int Par1,unsigned int Par2);
void AppLoop_OnShowNormals (unsigned int Enabled,unsigned int Par1,unsigned int Par2);
void AppLoop_OnShowBBoxes  (unsigned int Enabled,unsigned int Par1,unsigned int Par2);


void AppLoop_ControlCommands();
// ----------------------------------------------------------------------------
// Command definitions
// ----------------------------------------------------------------------------
#define CMF_FORWARD		0x0001
#define CMF_BACKWARD	0x0002
#define CMF_UP			0x0004
#define CMF_DOWN		0x0008
#define CMF_LEFT		0x0010
#define CMF_RIGHT		0x0020
// ----------------------------------------------------------------------------
void AppLoop_SetupKeyBindings()
{
	CGame_KeyBinder KeyBinder;
	KeyBinder.Init("config.cfg");
}
// ----------------------------------------------------------------------------
void AppLoop_SetupCallbackFuncs()
{	
	// Camera commands
	ClientCmdDispatcher_SetDispatchCallback(KCMD_CAMFORWARD ,AppLoop_OnCamForward  );
	ClientCmdDispatcher_SetDispatchCallback(KCMD_CAMBACKWARD,AppLoop_OnCamBackward );
	ClientCmdDispatcher_SetDispatchCallback(KCMD_CAMUP      ,AppLoop_OnCamUp       );
	ClientCmdDispatcher_SetDispatchCallback(KCMD_CAMDOWN    ,AppLoop_OnCamDown     );
	ClientCmdDispatcher_SetDispatchCallback(KCMD_CAMLEFT    ,AppLoop_OnCamLeft     );
	ClientCmdDispatcher_SetDispatchCallback(KCMD_CAMRIGHT   ,AppLoop_OnCamRight    );

	// Player commands
	ClientCmdDispatcher_SetDispatchCallback(KCMD_FORWARD    ,AppLoop_OnWalkForward );
	ClientCmdDispatcher_SetDispatchCallback(KCMD_BACKWARD   ,AppLoop_OnWalkBackward);
	ClientCmdDispatcher_SetDispatchCallback(KCMD_UP         ,AppLoop_OnWalkUp      );
	ClientCmdDispatcher_SetDispatchCallback(KCMD_DOWN       ,AppLoop_OnWalkDown    );
	ClientCmdDispatcher_SetDispatchCallback(KCMD_LEFT       ,AppLoop_OnWalkLeft    );
	ClientCmdDispatcher_SetDispatchCallback(KCMD_RIGHT      ,AppLoop_OnWalkRight   );

	ClientCmdDispatcher_SetDispatchCallback(KCMD_TURNUP		,AppLoop_OnTurnUp      );
	ClientCmdDispatcher_SetDispatchCallback(KCMD_TURNDOWN	,AppLoop_OnTurnDown    );
	ClientCmdDispatcher_SetDispatchCallback(KCMD_TURNLEFT	,AppLoop_OnTurnLeft    );
	ClientCmdDispatcher_SetDispatchCallback(KCMD_TURNRIGHT	,AppLoop_OnTurnRight   );

	ClientCmdDispatcher_SetDispatchCallback(KCMD_BUTTON1	,AppLoop_OnAttack2     );

	ClientCmdDispatcher_SetDispatchCallback(KCMD_BUTTON0	,AppLoop_OnAttack      );
	ClientCmdDispatcher_SetDispatchCallback(KCMD_GENMOVE	,AppLoop_OnMouseMove   );	

	ClientCmdDispatcher_SetDispatchCallback(KCMD_JUMP		,AppLoop_OnJump        );
	ClientCmdDispatcher_SetDispatchCallback(KCMD_FUNC1		,AppLoop_OnShowNormals );
	ClientCmdDispatcher_SetDispatchCallback(KCMD_FUNC2		,AppLoop_OnShowBBoxes  );

	ClientCmdDispatcher_SetDispatchCallback(KCMD_EXIT		,AppLoop_OnExit        );
	ClientCmdDispatcher_SetDispatchCallback(KCMD_TOGGLECONSOLE,AppLoop_ToggleConsole);
	ClientCmdDispatcher_SetDispatchCallback(KCMD_SCREENSHOT	,AppLoop_Screenshot	   );
}
// ----------------------------------------------------------------------------
// Camera event handlers
// ----------------------------------------------------------------------------
void AppLoop_OnCamForward (unsigned int Enabled,unsigned int Par1,unsigned int Par2)
{
	if (Enabled)
		CameraMovementFlags |= CMF_FORWARD;
	else
		CameraMovementFlags &= ~CMF_FORWARD;
}
void AppLoop_OnCamBackward(unsigned int Enabled,unsigned int Par1,unsigned int Par2)
{
	if (Enabled)
		CameraMovementFlags |= CMF_BACKWARD;
	else
		CameraMovementFlags &= ~CMF_BACKWARD;
}

void AppLoop_OnCamUp      (unsigned int Enabled,unsigned int Par1,unsigned int Par2)
{	
	if (Enabled)
		CameraMovementFlags |= CMF_UP;
	else
		CameraMovementFlags &= ~CMF_UP;
}

void AppLoop_OnCamDown    (unsigned int Enabled,unsigned int Par1,unsigned int Par2)
{
	if (Enabled)
		CameraMovementFlags |= CMF_DOWN;
	else
		CameraMovementFlags &= ~CMF_DOWN;
}

void AppLoop_OnCamLeft    (unsigned int Enabled,unsigned int Par1,unsigned int Par2)
{
	if (Enabled)
		CameraMovementFlags |= CMF_LEFT;
	else
		CameraMovementFlags &= ~CMF_LEFT;
}

void AppLoop_OnCamRight   (unsigned int Enabled,unsigned int Par1,unsigned int Par2)
{	
	if (Enabled)
		CameraMovementFlags |= CMF_RIGHT;
	else
		CameraMovementFlags &= ~CMF_RIGHT;
}

// ----------------------------------------------------------------------------
// Player event handlers
// ----------------------------------------------------------------------------
void AppLoop_OnWalkForward (unsigned int Enabled,unsigned int Par1,unsigned int Par2)
{
	// gPlayer->ControlCmds(PC_Forward,Enabled,1.0f);
}

void AppLoop_OnWalkBackward(unsigned int Enabled,unsigned int Par1,unsigned int Par2)
{
	// gPlayer->ControlCmds(PC_Backward,Enabled,-1.0f);
}

void AppLoop_OnWalkUp      (unsigned int Enabled,unsigned int Par1,unsigned int Par2)
{
	// gPlayer->ControlCmds(PC_Up,Enabled,1.0f);
}

void AppLoop_OnWalkDown    (unsigned int Enabled,unsigned int Par1,unsigned int Par2)
{
	// gPlayer->ControlCmds(PC_Down,Enabled,-1.0f);
}

void AppLoop_OnWalkLeft    (unsigned int Enabled,unsigned int Par1,unsigned int Par2)
{
	// gPlayer->ControlCmds(PC_Left,Enabled,1.0f);
}

void AppLoop_OnWalkRight   (unsigned int Enabled,unsigned int Par1,unsigned int Par2)
{
	// gPlayer->ControlCmds(PC_Right,Enabled,-1.0f);
}

void AppLoop_OnJump        (unsigned int Enabled,unsigned int Par1,unsigned int Par2)
{
	// gPlayer->ControlCmds(PC_Jump,Enabled,1.0f);
}
// ----------------------------------------------------------------------------
void AppLoop_OnTurnUp      (unsigned int Enabled,unsigned int Par1,unsigned int Par2)
{
	// gPlayer->ControlCmds(PC_Yaw,Enabled, 5.0f);
}
void AppLoop_OnTurnDown    (unsigned int Enabled,unsigned int Par1,unsigned int Par2)
{
	// gPlayer->ControlCmds(PC_Yaw,Enabled,-5.0f);
}
void AppLoop_OnTurnLeft    (unsigned int Enabled,unsigned int Par1,unsigned int Par2)
{
	// gPlayer->ControlCmds(PC_Roll,Enabled,5.0f);
}
void AppLoop_OnTurnRight   (unsigned int Enabled,unsigned int Par1,unsigned int Par2)
{
	// gPlayer->ControlCmds(PC_Roll,Enabled,-5.0f);
}
void AppLoop_ToggleConsole(unsigned int Enabled,unsigned int Par1,unsigned int Par2)
{
	// if (Enabled) GHUD.Toggle();
}
// ----------------------------------------------------------------------------
void AppLoop_Screenshot    (unsigned int Enabled,unsigned int Par1,unsigned int Par2)
{
	if (Enabled)
	{
		/*
		if (! gpoE3DRenderer->UsingFlatRendering())
			gpoE3DRenderer->EnableFlatRendering();
		else
			gpoE3DRenderer->DisableFlatRendering();
		*/	
		Texture* texture = poCreateTexture(uiScrWidth, uiScrHeight, 4);
		gpoE3DRenderer->ReadBuffer(0,0,uiScrWidth,uiScrHeight,eE3D_RB_Front,(void *)texture->data);

		// gpoE3DRenderer->ReadBuffer(0,0,uiScrWidth,uiScrHeight,eE3D_RB_Z,(void *)Tex.data);		
		// FlipTexture(&Tex,TEX_FF_FLIPVERTICAL);
		// SaveTGAFile("Screenshot.tga",&texture);

		DestroyTexture(texture);
	}
}
// ----------------------------------------------------------------------------
void AppLoop_OnShowNormals (unsigned int Enabled,unsigned int Par1,unsigned int Par2)
{
	if (Enabled)
	{
		if(gRenderer.UsingNormalRender())
			gRenderer.DisableNormalRender();
		else
			gRenderer.EnableNormalRender();
	}
}
// ----------------------------------------------------------------------------
void AppLoop_OnShowBBoxes  (unsigned int Enabled,unsigned int Par1,unsigned int Par2)
{
	if (Enabled)
	{
		if(gRenderer.UsingBBoxRender())
			gRenderer.DisableBBoxRender();
		else
			gRenderer.EnableBBoxRender();
	}
}
// ----------------------------------------------------------------------------
void AppLoop_OnAttack       (unsigned int Enabled,unsigned int Par1,unsigned int Par2)
{
	bMouseDown = Enabled;

	if (Enabled)
	{
		bMouseDown = true;

		iOldX     = Par1;
		iOldY     = Par2;

		fOldPitch = fPitch;
		fOldYaw	  = fYaw;
		
		CamUp.  Assign( PerspCam.Up  );
		CamSide.Assign( PerspCam.Side);
		CamDir.Assign ( PerspCam.Dir );
	}
	else
		bMouseDown = false;
}
void AppLoop_OnAttack2(unsigned int Enabled,unsigned int Par1,unsigned int Par2)
{
	// gPlayer->ControlCmds(PC_Shot,Enabled,5.0f);
}
// ----------------------------------------------------------------------------
void AppLoop_OnMouseMove    (unsigned int Enabled,unsigned int Par1,unsigned int Par2)
{
	#define CAM_ANGLE_SCALE	2.0f

	int		   iXDiff;
	int		   iYDiff;
	float	   dPitch;
	float      dYaw;
	CMatrix4x4 R;

	if ( bMouseDown )
	{
		iXDiff = iOldX - (int)Par1;
		iYDiff = (int)Par2 - iOldY;

		iOldX = Par1;
		iOldY = Par2;

		dPitch = ((float)iYDiff/(float)uiScrHeight) * _PI_ / CAM_ANGLE_SCALE;		
		dYaw   = ((float)iXDiff/(float)uiScrWidth ) * _PI_ / CAM_ANGLE_SCALE;

		fPitch =  fOldPitch + dPitch;
		fYaw   =  fOldYaw   + dYaw;
		
		// Setup previous camera vector
	    // Establecer los nuevos ejes: Transformarlos con los nuevos ángulos incrementados		
		R.LoadIdentity();
		R.RotateFromArbitraryAxis( dPitch,PerspCam.Side.X(),PerspCam.Side.Y(),PerspCam.Side.Z() );
		R.TransformVector(PerspCam.Up  );
		R.TransformVector(PerspCam.Dir );
		PerspCam.Side.CrossProd(PerspCam.Dir,PerspCam.Up);

		R.LoadIdentity();
        R.RotateFromArbitraryAxis( dYaw,PerspCam.Up.X() ,PerspCam.Up.Y() ,PerspCam.Up.Z() );
		R.TransformVector(PerspCam.Side);
        R.TransformVector(PerspCam.Dir );
	}
}
// ----------------------------------------------------------------------------
bool AppLoop_bFinnishApp()
{
	return(bFinnishApplication);
}

void AppLoop_OnExit	       (unsigned int Enabled,unsigned int Par1,unsigned int Par2)
{
	bFinnishApplication = true;
}
// ----------------------------------------------------------------------------
void AppLoop_ControlCommands()
{
    // Computo del vector de incremento
	static float	fInc = 64.0f;
	CVect3	Inc;

    Inc.V3(0,0,0);

    if (CameraMovementFlags & CMF_FORWARD ) Inc.Add(PerspCam.Dir );
    if (CameraMovementFlags & CMF_BACKWARD) Inc.Sub(PerspCam.Dir );
    if (CameraMovementFlags & CMF_UP      ) Inc.Add(PerspCam.Up  );
    if (CameraMovementFlags & CMF_DOWN    ) Inc.Sub(PerspCam.Up  );
    if (CameraMovementFlags & CMF_LEFT    ) Inc.Sub(PerspCam.Side);
    if (CameraMovementFlags & CMF_RIGHT   ) Inc.Add(PerspCam.Side);

    Inc.Scale(fInc*gDeltaT);

	if(Inc.Module()>0)
	{
		// Incremento de la posicion de la cámara
		PerspCam.Pos.Add(Inc);
	}
}
// ----------------------------------------------------------------------------
void AppLoop_OnDestroy(void *uiWinHandler)
{
	gpoE3DRenderer->Finish();
}
// ----------------------------------------------------------------------------
void AppLoop_OnResize (unsigned int uiWndWidth,unsigned int uiWndHeight)
{
	uiScrWidth  = uiWndWidth;
	uiScrHeight = uiWndHeight;

	gpoE3DRenderer->SetScreenSize(uiWndWidth,uiWndHeight);
}
//---------------------------------------------------------------------------
// INPUT
//---------------------------------------------------------------------------
void __fastcall TForm2::FormKeyDown(TObject *Sender, WORD &Key,TShiftState Shift)
{
    WinEvent_KeyDown  (Key & 0x000000ff);
}
//---------------------------------------------------------------------------
void __fastcall TForm2::FormKeyUp(TObject *Sender, WORD &Key,TShiftState Shift)
{
    WinEvent_KeyUp    (Key & 0x000000ff);
}
//---------------------------------------------------------------------------
int lButton = 0,rButton = 0,mButton = 0;

void __fastcall TForm2::FormMouseMove(TObject *Sender, TShiftState Shift,int X, int Y)
{
    // MK_LBUTTON | MK_MBUTTON | MK_RBUTTON)
    WinEvent_MouseMove( X,Y, lButton | rButton | mButton);
}
//---------------------------------------------------------------------------
void __fastcall TForm2::FormMouseDown(TObject *Sender, TMouseButton Button,TShiftState Shift, int X, int Y)
{
    switch (Button)
    {
        case mbLeft:  WinEvent_MouseDown( X, Y,0); lButton = 0;break;
		case mbRight: WinEvent_MouseDown( X, Y,1); rButton = 0;break;
		case mbMiddle:WinEvent_MouseDown( X, Y,2); mButton = 0;break;
    }
}
//---------------------------------------------------------------------------
void __fastcall TForm2::FormMouseUp(TObject *Sender, TMouseButton Button,TShiftState Shift, int X, int Y)
{
    switch (Button)
    {
        case mbLeft:  WinEvent_MouseUp( X, Y,0); lButton = MK_LBUTTON;break;
		case mbRight: WinEvent_MouseUp( X, Y,1); rButton = MK_RBUTTON;break;
		case mbMiddle:WinEvent_MouseUp( X, Y,2); mButton = MK_MBUTTON;break;
    }
}
//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)   : TForm(Owner)
{
	CE3D_ShaderWH::Init(1024);

	uiScrWidth  = ClientWidth;
	uiScrHeight = ClientHeight;

	gpoE3DRenderer = &gRenderer;
    gpoE3DRenderer->Init(Handle,E3D_RENDERER_OP_DBUFFER,uiScrWidth,uiScrHeight,32);

	Viewport.ScrCX = 0.0f;
    Viewport.ScrCY = 0.0f;
    Viewport.ScrTX = 1.0f;
    Viewport.ScrTY = 1.0f;

    // La orientacion de la cámara se determina utilizando 3 vectores
    // que son los ejes locales de la cámara
	// PerspCam.Pos.V3 ( 4, 10,270);
	PerspCam.Pos.V3 ( 0.0f,-20.0f,0.0f);

    PerspCam.Up.V3  ( 0, 0,   1);
	PerspCam.Dir.V3 ( 0, 1,   0);	PerspCam.Dir.Normalize();
	PerspCam.Side.CrossProd(PerspCam.Dir,PerspCam.Up);

	PerspPrj.ePrjType = eE3DPrjType_Perspective;
	PerspPrj.fFOV     = 45.0f;
    PerspPrj.fNear    = 1.0f;
    PerspPrj.fFar     = 2000.0f;

	// -------------------------------
	// Orthographic projection camnera
	// -------------------------------
    gpoE3DRenderer->SetViewport (&Viewport);
    gpoE3DRenderer->SetCamera   (&PerspCam);
	gpoE3DRenderer->SetProjector(&PerspPrj);

    gpoE3DRenderer->DisableFrustumCulling();
    gpoE3DRenderer->DisableLighting();
	gpoE3DRenderer->SetZPars(eE3D_ZTF_LEqual,eE3D_ZW_Enable);

  	gCamera.Init	    (100);
	gCamera.SetCamera   (&PerspCam);
	gCamera.SetProjector(&PerspPrj);
	gCamera.SetViewport (&Viewport);

    gCamera.iAddObject(NULL);

	AppLoop_SetupKeyBindings();
	AppLoop_SetupCallbackFuncs();


    RTimer->Enabled = true;
}
//---------------------------------------------------------------------------
void __fastcall TForm2::pb_DspPaint(TObject *Sender)
{
    // Similar to AppLoop_OnIdle()
    AppLoop_ControlCommands();

	// World think entities
	oMainChrono.Reset();
 	oMainChrono.Start();



    gpoE3DRenderer->BeginRender();

        // Camera viewpoint
    	gCamera.PreRender();

		// Render camera scene
		gCamera.Render();
        // Camera viewpoint
    	gCamera.PostRender();

    gpoE3DRenderer->EndRender();

	oMainChrono.Stop();
	gDeltaT  = oMainChrono.ElapsedTime();
}
//---------------------------------------------------------------------------
void PivotAnimMesh()
{
    // Compute object Bounding Volume
    poModel->ComputeBoundVol();

	int			iState;
	int			iVert;
	float		fZMin;
	CMatrix4x4	oMat;
	CVect3		*poVXs = poAMesh->pMeshStates;
	CVect3		oBottom;

	for (iState=0;iState<poModel->AnimObj->iGetNumStates();iState++)
	{
		oBottom.Assign( poAMesh->pBVolStates[iState]->GetCenter());
		oBottom.Sub( 0.0f,0.0f,poAMesh->pBVolStates[iState]->GetExtents().Z());

		oMat.LoadIdentity();
        // XY Centered Z at bottom
		//oMat.Translate3f(-oBottom.X(),-oBottom.Y(),-oBottom.Z());
        oMat.Translate3f(0.0f,0.0f,-oBottom.Z());

		for (iVert=0;iVert<poAMesh->iGetNumStateVXs();iVert++)
		{
			oMat.TransformPoint(*poVXs);
			poVXs++;
		}

		poAMesh->pBVolStates[iState]->Transform(oMat);
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm2::LoadMD2model1Click(TObject *Sender)
{
    if (dlg_Load->Execute())
    {
        CGraphBV_Manager::SetBVMode(eGraphBV_Box);

        CLoaderMD2          oMD2Loader;
        if (poModel) mDel poModel;
        poModel = (CObject3D_AnimCfg *)oMD2Loader.pLoad(dlg_Load->FileName.c_str());
        poAMesh = (CObject3D_AnimMesh *)poModel;
        poLeaf  = poAMesh->Leaf;

        PivotAnimMesh();

        poLeaf->SetShader(gpoShader);
        gCamera.SetObject(poModel,0);
    }
}
//---------------------------------------------------------------------------
void __fastcall TForm2::LoadMD2Player1Click(TObject *Sender)
{
    if (dlg_Load->Execute())
    {
        CGraphBV_Manager::SetBVMode(eGraphBV_Box);

        CLoaderMD2              oMD2Loader;
        if (poModel) mDel poModel;
        poModel = (CObject3D_AnimCfg *)oMD2Loader.pLoadQ2Player(dlg_Load->FileName.c_str());
        poAMesh = (CObject3D_AnimMesh *)poModel->AnimObj;
        poLeaf  = poAMesh->Leaf;

        PivotAnimMesh();
        
        poLeaf->SetShader(gpoShader);
        gCamera.SetObject(poModel,0);
    }
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Loadtexture1Click(TObject *Sender)
{
    dlg_LoadTex->InitialDir = dlg_Load->InitialDir;
    if (dlg_LoadTex->Execute())
    {
        CE3D_ShaderWH::Invalidate();
        gpoShader = CE3D_ShaderWH::poCreateShader( dlg_LoadTex->FileName.c_str() );

        if (poLeaf)
            poLeaf->SetShader(gpoShader);
    }
}
//---------------------------------------------------------------------------
void __fastcall TForm2::FormResize(TObject *Sender)
{
    AppLoop_OnResize(ClientWidth,ClientHeight);
}
//---------------------------------------------------------------------------

void __fastcall TForm2::SaveGEMmodel1Click(TObject *Sender)
{
    if (dlg_Save->Execute())
    {
        CSaverGEM oGEMSaver;
        oGEMSaver.iSave(dlg_Save->FileName.c_str(),poModel);
    }
}
//---------------------------------------------------------------------------


