//## begin module%3B9DFE320391.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3B9DFE320391.cm

//## begin module%3B9DFE320391.cp preserve=no
//## end module%3B9DFE320391.cp

//## Module: CObject3D_AnimCfg%3B9DFE320391; Pseudo Package body
//## Source file: i:\Projects\GammaE\Scene\Animation\CObject3D_AnimCfg.cpp

//## begin module%3B9DFE320391.additionalIncludes preserve=no
//## end module%3B9DFE320391.additionalIncludes

//## begin module%3B9DFE320391.includes preserve=yes
//## end module%3B9DFE320391.includes

// CObject3D_AnimCfg
#include "Scene\Animation\CObject3D_AnimCfg.h"
//## begin module%3B9DFE320391.additionalDeclarations preserve=yes
//## end module%3B9DFE320391.additionalDeclarations


// Class CObject3D_AnimCfg 







CObject3D_AnimCfg::CObject3D_AnimCfg()
  //## begin CObject3D_AnimCfg::CObject3D_AnimCfg%.hasinit preserve=no
      : iNumFrameAnims(0), iCurrentFrameAnim(0), fCurrentTime(0), iLastFrame(-1)
  //## end CObject3D_AnimCfg::CObject3D_AnimCfg%.hasinit
  //## begin CObject3D_AnimCfg::CObject3D_AnimCfg%.initialization preserve=yes
  //## end CObject3D_AnimCfg::CObject3D_AnimCfg%.initialization
{
  //## begin CObject3D_AnimCfg::CObject3D_AnimCfg%.body preserve=yes
	TypeID = e3DObj_AnimCfg;
  //## end CObject3D_AnimCfg::CObject3D_AnimCfg%.body
}


CObject3D_AnimCfg::~CObject3D_AnimCfg()
{
  //## begin CObject3D_AnimCfg::~CObject3D_AnimCfg%.body preserve=yes
  //## end CObject3D_AnimCfg::~CObject3D_AnimCfg%.body
}



//## Other Operations (implementation)
void CObject3D_AnimCfg::CreateFrameAnims (int _iNumFrameAnims)
{
  //## begin CObject3D_AnimCfg::CreateFrameAnims%1000205750.body preserve=yes
	iNumFrameAnims = _iNumFrameAnims;
	FrameAnim = new TFrameAnimation[_iNumFrameAnims];
  //## end CObject3D_AnimCfg::CreateFrameAnims%1000205750.body
}

void CObject3D_AnimCfg::SetupFrameAnim (int _iFrameAnim, int _iInitialFrame, int _iFinalFrame, float _fFrameAnimTime, bool _bLoop)
{
  //## begin CObject3D_AnimCfg::SetupFrameAnim%1000205751.body preserve=yes
	assert (FrameAnim && "NULL frame anim");
	assert ((_iFrameAnim <iNumFrameAnims) && "Object out of bounds");
	
	FrameAnim[_iFrameAnim].InitialFrame = _iInitialFrame;
	FrameAnim[_iFrameAnim].FinalFrame   = _iFinalFrame;
	FrameAnim[_iFrameAnim].TotalTime    = _fFrameAnimTime;
	FrameAnim[_iFrameAnim].bLoop		= _bLoop;

	if (_iFinalFrame > _iInitialFrame)
		FrameAnim[_iFrameAnim].FrameTime = _fFrameAnimTime / ( _iFinalFrame - _iInitialFrame + 1 );
	else
		FrameAnim[_iFrameAnim].FrameTime = 10000000.0f; // x/0	infinite

  //## end CObject3D_AnimCfg::SetupFrameAnim%1000205751.body
}

void CObject3D_AnimCfg::SetFrameAnim (int iFrameAnim)
{
  //## begin CObject3D_AnimCfg::SetFrameAnim%1000205752.body preserve=yes
  	iCurrentFrameAnim = iFrameAnim;
	fCurrentTime	  = 0;
  //## end CObject3D_AnimCfg::SetFrameAnim%1000205752.body
}

CGraphBV* CObject3D_AnimCfg::poGetBoundVol ()
{
  //## begin CObject3D_AnimCfg::poGetBoundVol%1000205753.body preserve=yes
	return(AnimObj->poGetBoundVol());
  //## end CObject3D_AnimCfg::poGetBoundVol%1000205753.body
}

void CObject3D_AnimCfg::ComputeBoundVol ()
{
  //## begin CObject3D_AnimCfg::ComputeBoundVol%1000205754.body preserve=yes
	AnimObj->ComputeBoundVol();
  //## end CObject3D_AnimCfg::ComputeBoundVol%1000205754.body
}

void CObject3D_AnimCfg::Render ()
{
  //## begin CObject3D_AnimCfg::Render%1000205755.body preserve=yes
	assert ( FrameAnim );

	if (gpoE3DRenderer->REStats.iCurrentFrame != iLastFrame)
	{
		iLastFrame = gpoE3DRenderer->REStats.iCurrentFrame;

		unsigned int		iCurrFrame;
		unsigned int		iNextFrame;
		unsigned int		iRealFrame;

		float				fFactor;
		float				fFrameAnimTime;
		float				fFrame;
		
		// Tiempo total desde la primera llamada a GetMesh
		fCurrentTime += gpoE3DRenderer->REStats.DTime;

		// Tiempo transcurrido dentro de la actual animación
 		fFrameAnimTime = fmod(fCurrentTime,FrameAnim[iCurrentFrameAnim].TotalTime);

		// Frame que toca relativo al frame inicial de la animación
		fFrame     = fFrameAnimTime / FrameAnim[iCurrentFrameAnim].FrameTime;
		iCurrFrame = (int) fFrame;
		
		// Factor de cercanía hacia el siguiente frame: (->1 muy cerca de siguiente frame)
		fFactor    = fFrame - iCurrFrame;

		// Frame real dentro de la tabla de frames	
		iRealFrame = FrameAnim[iCurrentFrameAnim].InitialFrame + iCurrFrame;

		// Setup next frame
		if (iRealFrame >= FrameAnim[iCurrentFrameAnim].FinalFrame)
		{
			if (FrameAnim[iCurrentFrameAnim ].bLoop)
				iNextFrame = FrameAnim[iCurrentFrameAnim ].InitialFrame;
			else
			{ 
				iNextFrame = FrameAnim[iCurrentFrameAnim].FinalFrame-1;
				fFactor = 0.0f;
			}
		}
		else
			iNextFrame = iRealFrame+1;

		AnimObj->SetAnimState(iRealFrame,iNextFrame,fFactor);
	}
	
	AnimObj->Render();	
  //## end CObject3D_AnimCfg::Render%1000205755.body
}

// Additional Declarations
  //## begin CObject3D_AnimCfg%3B9DFE320391.declarations preserve=yes
  //## end CObject3D_AnimCfg%3B9DFE320391.declarations

//## begin module%3B9DFE320391.epilog preserve=yes
//## end module%3B9DFE320391.epilog
