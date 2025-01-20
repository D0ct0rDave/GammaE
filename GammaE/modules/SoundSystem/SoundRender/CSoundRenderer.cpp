//## begin module%3B76FFB6017F.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3B76FFB6017F.cm

//## begin module%3B76FFB6017F.cp preserve=no
//## end module%3B76FFB6017F.cp

//## Module: CSoundRenderer%3B76FFB6017F; Pseudo Package body
//## Source file: i:\Projects\GammaE\SoundSystem\SoundRender\CSoundRenderer.cpp

//## begin module%3B76FFB6017F.additionalIncludes preserve=no
//## end module%3B76FFB6017F.additionalIncludes

//## begin module%3B76FFB6017F.includes preserve=yes
#include <assert.h>
//## end module%3B76FFB6017F.includes

// CSoundRenderer
#include "SoundSystem\SoundRender\CSoundRenderer.h"
//## begin module%3B76FFB6017F.additionalDeclarations preserve=yes
//## end module%3B76FFB6017F.additionalDeclarations


// Class CSoundRenderer 




CSoundRenderer::CSoundRenderer()
  //## begin CSoundRenderer::CSoundRenderer%.hasinit preserve=no
      : iMaxEmiters(0), poReceiver(NULL)
  //## end CSoundRenderer::CSoundRenderer%.hasinit
  //## begin CSoundRenderer::CSoundRenderer%.initialization preserve=yes
  //## end CSoundRenderer::CSoundRenderer%.initialization
{
  //## begin CSoundRenderer::CSoundRenderer%.body preserve=yes
  //## end CSoundRenderer::CSoundRenderer%.body
}


CSoundRenderer::~CSoundRenderer()
{
  //## begin CSoundRenderer::~CSoundRenderer%.body preserve=yes
  //## end CSoundRenderer::~CSoundRenderer%.body
}



//## Other Operations (implementation)
CSoundEmiter * CSoundRenderer::poAddEmiter (CSound* _poSound, CVect3& _roPos, float _fVol)
{
  //## begin CSoundRenderer::poAddEmiter%1001802592.body preserve=yes
	CSoundEmiter oSndEmiter;
	
	oSndEmiter.fVol			= _fVol;
	oSndEmiter.oSMP.poSound = _poSound;

	oSndEmiter.Speed.V3(0.0f,0.0f,0.0f);
	oSndEmiter.Dir.V3(1.0f,0.0f,0.0f);
	oSndEmiter.Pos.Assign(_roPos);
	oSndEmiter.fRadius      = 1e6f;

	oSndEmiter.iType		= 1;	
	oSndEmiter.oSMP.bEnd	= false;
	
	int iEmiter = oEmiters.iAdd( oSndEmiter );

	if (iEmiter == -1)	
		return(NULL);

	return( oEmiters.poElem(iEmiter) );
  //## end CSoundRenderer::poAddEmiter%1001802592.body
}

CSoundEmiter * CSoundRenderer::poAddOmniEmiter (CSound* _poSound, float _fVol)
{
  //## begin CSoundRenderer::poAddOmniEmiter%1024078849.body preserve=yes
  	CSoundEmiter oSndEmiter;
	
	oSndEmiter.fVol			= _fVol;
	oSndEmiter.oSMP.poSound = _poSound;	
	oSndEmiter.iType		= 0;
	oSndEmiter.oSMP.bEnd	= false;
	
	int iEmiter = oEmiters.iAdd( oSndEmiter );

	if (iEmiter == -1)	
		return(NULL);

	return( oEmiters.poElem(iEmiter) );
  //## end CSoundRenderer::poAddOmniEmiter%1024078849.body
}

void CSoundRenderer::SetReceiver (CSoundReceiver* _poReceiver)
{
  //## begin CSoundRenderer::SetReceiver%1001802594.body preserve=yes
	poReceiver = _poReceiver;
  //## end CSoundRenderer::SetReceiver%1001802594.body
}

CSoundReceiver * CSoundRenderer::poGetReceiver ()
{
  //## begin CSoundRenderer::poGetReceiver%1001802601.body preserve=yes
	return (poReceiver);
  //## end CSoundRenderer::poGetReceiver%1001802601.body
}

// Additional Declarations
  //## begin CSoundRenderer%3B76FFB6017F.declarations preserve=yes
  //## end CSoundRenderer%3B76FFB6017F.declarations

//## begin module%3B76FFB6017F.epilog preserve=yes
//## end module%3B76FFB6017F.epilog


// Detached code regions:
// WARNING: this code will be lost if code is regenerated.
#if 0
//## begin CSoundRenderer::RemoveEmiter%1001802595.body preserve=no
	assert (poEmiter && "NULL sound emiter table");
	assert ((_iIdx < iMaxEmiters )&& "Emiter index out of emiter table bounds");
	
	poEmiter[_iIdx] = NULL;
//## end CSoundRenderer::RemoveEmiter%1001802595.body

//## begin CSoundRenderer::UnlockEmiter%1001802593.body preserve=no
	assert (poEmiter && "NULL sound emiter table");
	assert ((_iIdx < iMaxEmiters )&& "Emiter index out of emiter table bounds");

	poEmiter[_iIdx]->oSMP.bLUnlock= true;
//## end CSoundRenderer::UnlockEmiter%1001802593.body

#endif
