//## begin module%3B62DC8C03CA.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3B62DC8C03CA.cm

//## begin module%3B62DC8C03CA.cp preserve=no
//## end module%3B62DC8C03CA.cp

//## Module: CGameHUD%3B62DC8C03CA; Pseudo Package body
//## Source file: i:\Projects\GammaE\Game\Entities\GameHUD\CGameHUD.cpp

//## begin module%3B62DC8C03CA.additionalIncludes preserve=no
//## end module%3B62DC8C03CA.additionalIncludes

//## begin module%3B62DC8C03CA.includes preserve=yes
//## end module%3B62DC8C03CA.includes

// CGameHUD
#include "CGameHUD.h"
//## begin module%3B62DC8C03CA.additionalDeclarations preserve=yes
#include "Game\GameGlobals\GameGlobals.h"
//## end module%3B62DC8C03CA.additionalDeclarations


// Class CGameHUD 






CGameHUD::CGameHUD()
  //## begin CGameHUD::CGameHUD%.hasinit preserve=no
      : Cam(NULL), fSize(0.0f), fSecs(1.0f)
  //## end CGameHUD::CGameHUD%.hasinit
  //## begin CGameHUD::CGameHUD%.initialization preserve=yes
  //## end CGameHUD::CGameHUD%.initialization
{
  //## begin CGameHUD::CGameHUD%.body preserve=yes
	eState = eGHUDSt_Closed;
	fSize  = 0.0f;	
	fSecs  = 0.5f;
  //## end CGameHUD::CGameHUD%.body
}


CGameHUD::~CGameHUD()
{
  //## begin CGameHUD::~CGameHUD%.body preserve=yes
  //## end CGameHUD::~CGameHUD%.body
}



//## Other Operations (implementation)
void CGameHUD::Think (float fDelta)
{
  //## begin CGameHUD::Think%996334235.body preserve=yes
  	if (! Cam) return;
	if (! Console) return;

	if (eState == eGHUDSt_Closed) return;

	
	// Show console state vars
	switch (eState)
	{
		case eGHUDSt_Opening:	fSize += (gpoE3DRenderer->REStats.DTime / fSecs);
								if (fSize >= 1.0f) 
								{
									fSize  = 1.0f;
									eState = eGHUDSt_Open;
								}
								break;
		case eGHUDSt_Closing:	fSize -= (gpoE3DRenderer->REStats.DTime / fSecs);
								if (fSize <= 0.0f) 
								{
									fSize  = 0.0f;
									eState = eGHUDSt_Closed;
								}
								break;
	}
	
	#define  OFSX	0
	#define  OFSY	10

	Console->Resize(1.0f,0.5f*fSize);
	
	char pszStrBuff[256];

	sprintf(pszStrBuff,"%cgFPS: %c%.2f ",4,1,1.0f/gfDeltaT);
	Console->WriteXY(OFSX+0,OFSY+1,pszStrBuff);

	sprintf(pszStrBuff,"%crFPS: %c%.3f PRIMS: %d VXs: %d  ",3,1,
				gpoE3DRenderer->REStats.FPS,
				gpoE3DRenderer->REStats.NumRenderedTris,
				gpoE3DRenderer->REStats.NumRenderedVerts);
	
	Console->WriteXY(OFSX+0,OFSY+2,pszStrBuff);

	sprintf(pszStrBuff,"%cCam: %.2f %.2f %.2f   ",1,Cam->Pos.X(),Cam->Pos.Y(),Cam->Pos.Z());
	Console->WriteXY(OFSX+0,OFSY+3,pszStrBuff);

	sprintf(pszStrBuff,"%cPlayer: %.2f %.2f %.2f   ",1,
				gpoPlayer->oCol.oPos.X(),
				gpoPlayer->oCol.oPos.Y(),
				gpoPlayer->oCol.oPos.Z());
	Console->WriteXY(OFSX+0,OFSY+4,pszStrBuff);

	Console->Write(CONGetBuffer());
	/*
	sprintf(pszStrBuff,"Player Pos: %.2f %.2f %.2f   ",Player->Pos.X(),Player->Pos.Y(),Player->Pos.Z());
	Console->WriteXY(0,5,pszStrBuff);
	sprintf(pszStrBuff,"Player Speed: %.2f %.2f %.2f   ",Player->Speed.X(),Player->Speed.Y(),Player->Speed.Z());
	Console->WriteXY(0,6,pszStrBuff);	
	*/

  //## end CGameHUD::Think%996334235.body
}

void CGameHUD::SetCamera (CE3D_Camera *_Cam)
{
  //## begin CGameHUD::SetCamera%1004042075.body preserve=yes
	Cam = _Cam;
  //## end CGameHUD::SetCamera%1004042075.body
}

void CGameHUD::Toggle ()
{
  //## begin CGameHUD::Toggle%1004309120.body preserve=yes
	if ((eState == eGHUDSt_Opening) || (eState == eGHUDSt_Open))
		eState = eGHUDSt_Closing;
	else
		eState = eGHUDSt_Opening;
  //## end CGameHUD::Toggle%1004309120.body
}

// Additional Declarations
  //## begin CGameHUD%3B62DC8C03CA.declarations preserve=yes
  //## end CGameHUD%3B62DC8C03CA.declarations

//## begin module%3B62DC8C03CA.epilog preserve=yes
//## end module%3B62DC8C03CA.epilog
