//## begin module%3B76DF3D0334.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3B76DF3D0334.cm

//## begin module%3B76DF3D0334.cp preserve=no
//## end module%3B76DF3D0334.cp

//## Module: CSound%3B76DF3D0334; Pseudo Package body
//## Source file: i:\Projects\GammaE\SoundSystem\Sound\CSound.cpp

//## begin module%3B76DF3D0334.additionalIncludes preserve=no
//## end module%3B76DF3D0334.additionalIncludes

//## begin module%3B76DF3D0334.includes preserve=yes
//## end module%3B76DF3D0334.includes

// CSound
#include "SoundSystem\Sound\CSound.h"
//## begin module%3B76DF3D0334.additionalDeclarations preserve=yes
#include <assert.h>
#include <string.h>
#include "memory/GammaE_mem.h"
//## end module%3B76DF3D0334.additionalDeclarations


// Class CSound 





CSound::CSound()
  //## begin CSound::CSound%.hasinit preserve=no
      : iNumLayers(0), poSLayer(NULL)
  //## end CSound::CSound%.hasinit
  //## begin CSound::CSound%.initialization preserve=yes
  //## end CSound::CSound%.initialization
{
  //## begin CSound::CSound%.body preserve=yes
  //## end CSound::CSound%.body
}


CSound::~CSound()
{
  //## begin CSound::~CSound%.body preserve=yes
	mDel []poSLayer;
  //## end CSound::~CSound%.body
}



//## Other Operations (implementation)
int CSound::iAddLayer (CSoundLayer& _roSLayer)
{
  //## begin CSound::iAddLayer%1001802578.body preserve=yes
	return(iAddLayer(_roSLayer.bLoop,_roSLayer.poSample));
  //## end CSound::iAddLayer%1001802578.body
}

int CSound::iAddLayer (bool _bLoop, CSample* _poSample)
{
  //## begin CSound::iAddLayer%1014992647.body preserve=yes
	CSoundLayer	*poNewSLayer;
	poNewSLayer = mNew CSoundLayer[iNumLayers+1];
	
	if (poSLayer)
	{
		memcpy(poNewSLayer,poSLayer,iNumLayers*sizeof(CSoundLayer));
		mDel []poSLayer;
	}

	// Add new sound layer
	poNewSLayer[iNumLayers].bLoop    = _bLoop;
	poNewSLayer[iNumLayers].poSample = _poSample;

	// Update sound layer array pointer
	poSLayer = poNewSLayer;	
	
	// Update number of sound layers
	iNumLayers++;

	return(iNumLayers-1);
   //## end CSound::iAddLayer%1014992647.body
}

// Additional Declarations
  //## begin CSound%3B76DF3D0334.declarations preserve=yes
  //## end CSound%3B76DF3D0334.declarations

//## begin module%3B76DF3D0334.epilog preserve=yes
//## end module%3B76DF3D0334.epilog
