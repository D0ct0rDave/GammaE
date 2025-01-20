












#include <assert.h>


//-----------------------------------------------------------------------------
#include "SoundRender\CSoundRenderer.h"




//-----------------------------------------------------------------------------





CSoundRenderer::CSoundRenderer()
  
      : iMaxEmiters(0), poReceiver(NULL), fGlbVol(1.0f)
  
  
  
{
  
  
}


CSoundRenderer::~CSoundRenderer()
{
  
  
}




CSoundEmiter * CSoundRenderer::poAddEmiter (CSound* _poSound, float _fVol, CVect3& _oPos, float _fRadius)
{
  
	CSoundEmiter* poSndEmiter = poAddOmniEmiter(_poSound,_fVol);
	if (!poSndEmiter) return (NULL);

	poSndEmiter->iType	      = 1;
	poSndEmiter->Pos.Assign(_oPos);
	poSndEmiter->fRadius      = _fRadius;

	return( poSndEmiter );
  
}

CSoundEmiter * CSoundRenderer::poAddOmniEmiter (CSound* _poSound, float _fVol)
{
  
	CSoundEmiter* poSndEmiter = poGetFreeEmiter();
	if (!poSndEmiter) return (NULL);

	poSndEmiter->fVol		  = _fVol;
	poSndEmiter->iType	      = 0;


	poSndEmiter->Speed = poReceiver->Speed;
	poSndEmiter->Pos  = poReceiver->Pos;
	poSndEmiter->Dir = poReceiver->Dir;
	poSndEmiter->fRadius      = 1e6f;

	poSndEmiter->poSound      = _poSound;
	
	return( poSndEmiter );
  
}

void CSoundRenderer::SetReceiver (CSoundReceiver* _poReceiver)
{
  
	poReceiver = _poReceiver;
  
}

CSoundReceiver * CSoundRenderer::poGetReceiver ()
{
  
	return (poReceiver);
  
}

//-----------------------------------------------------------------------------
  
CSoundEmiter * CSoundRenderer::poAddDirEmiter (CSound* _poSound, float _fVol, CVect3& _oPos, float _fRadius, CVect3& _oDir)
{
	CSoundEmiter* poSndEmiter = poAddEmiter(_poSound,_fVol,_oPos,_fRadius);
	if (!poSndEmiter) return (NULL);
	
	poSndEmiter->iType	      = 2;
	poSndEmiter->Dir.Assign ( _oDir );

	return(poSndEmiter);
}
  



