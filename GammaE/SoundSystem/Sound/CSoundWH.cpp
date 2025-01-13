//## begin module%3B76DEFB00B8.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3B76DEFB00B8.cm

//## begin module%3B76DEFB00B8.cp preserve=no
//## end module%3B76DEFB00B8.cp

//## Module: CSoundWH%3B76DEFB00B8; Pseudo Package body
//## Source file: i:\Projects\GammaE\SoundSystem\Sound\CSoundWH.cpp

//## begin module%3B76DEFB00B8.additionalIncludes preserve=no
//## end module%3B76DEFB00B8.additionalIncludes

//## begin module%3B76DEFB00B8.includes preserve=yes
#include <assert.h>
#include <string.h>
#include "memory/GammaE_mem.h"
//## end module%3B76DEFB00B8.includes

// CSoundWH
#include "SoundSystem\Sound\CSoundWH.h"
//## begin module%3B76DEFB00B8.additionalDeclarations preserve=yes
//## end module%3B76DEFB00B8.additionalDeclarations


// Class CSoundWH 

//## begin CSoundWH::iNumSounds%3BB645250115.attr preserve=no  private: static int {UA} 0
int CSoundWH::iNumSounds = 0;
//## end CSoundWH::iNumSounds%3BB645250115.attr

//## begin CSoundWH::iMaxSounds%3BB6452A0036.attr preserve=no  private: static int {UA} 0
int CSoundWH::iMaxSounds = 0;
//## end CSoundWH::iMaxSounds%3BB6452A0036.attr

//## begin CSoundWH::poSndElem%3BB646E10145.role preserve=no  public: static CSoundWH_Elem { -> RHAN}
CSoundWH_Elem *CSoundWH::poSndElem;
//## end CSoundWH::poSndElem%3BB646E10145.role

CSoundWH::CSoundWH()
  //## begin CSoundWH::CSoundWH%.hasinit preserve=no
  //## end CSoundWH::CSoundWH%.hasinit
  //## begin CSoundWH::CSoundWH%.initialization preserve=yes
  //## end CSoundWH::CSoundWH%.initialization
{
  //## begin CSoundWH::CSoundWH%.body preserve=yes
  //## end CSoundWH::CSoundWH%.body
}


CSoundWH::~CSoundWH()
{
  //## begin CSoundWH::~CSoundWH%.body preserve=yes
  //## end CSoundWH::~CSoundWH%.body
}



//## Other Operations (implementation)
void CSoundWH::Init (int _iMaxSounds)
{
  //## begin CSoundWH::Init%1001802585.body preserve=yes
  	iMaxSounds = _iMaxSounds;
	iNumSounds = 0;
	poSndElem  = mNew CSoundWH_Elem[iMaxSounds];
	memset(poSndElem,0,iMaxSounds*sizeof(CSound*));
  //## end CSoundWH::Init%1001802585.body
}

void CSoundWH::Invalidate ()
{
  //## begin CSoundWH::Invalidate%1001802586.body preserve=yes
	if ( ! poSndElem) return;
	mDel []poSndElem;
	iNumSounds = 0;
  //## end CSoundWH::Invalidate%1001802586.body
}

int CSoundWH::iAddSound (CSound *_poSound, char *_szSndName)
{
  //## begin CSoundWH::iAddSound%1001802587.body preserve=yes
	assert( (poSndElem) && ("NULL Sound Warehouse"));
	assert( (iNumSounds<iMaxSounds) && ("Sound Warehouse full"));	

	strncpy(poSndElem[iNumSounds].szSoundName,_szSndName,256);
	poSndElem[iNumSounds].szSoundName[255] = 0;
	poSndElem[iNumSounds].poSound          = _poSound;
	
	iNumSounds++;

	return ( iNumSounds-1 );
  //## end CSoundWH::iAddSound%1001802587.body
}

CSound * CSoundWH::poGetSound (char* _szName)
{
  //## begin CSoundWH::poGetSound%1001802588.body preserve=yes
	assert( (poSndElem) && ("NULL Sound Warehouse") );
	
	for (int cSound=0;cSound<iNumSounds;cSound++)
		if (! strcmp(_szName,poSndElem[cSound].szSoundName))
			return( poSndElem[cSound].poSound );

	return(NULL);
  //## end CSoundWH::poGetSound%1001802588.body
}

CSound * CSoundWH::poGetSound (int _iIdx)
{
  //## begin CSoundWH::poGetSound%1001802589.body preserve=yes
	assert( (poSndElem) && ("NULL Sound Warehouse") );
	assert( (_iIdx<iNumSounds) && ("Sound idx out of Warehousebounds"));	

	return( poSndElem[_iIdx].poSound );
  //## end CSoundWH::poGetSound%1001802589.body
}

int CSoundWH::iLoadSound (char *_szFilename)
{
  //## begin CSoundWH::iLoadSound%1001802596.body preserve=yes
	
	// WARNING: Empty code!!!!!!!!!

	return (0);

  //## end CSoundWH::iLoadSound%1001802596.body
}

// Additional Declarations
  //## begin CSoundWH%3B76DEFB00B8.declarations preserve=yes
//---------------------------------------------------------------------------
// epilog: singleton initializer through static instantiation
//---------------------------------------------------------------------------
static CSoundWH oInstance;

  //## end CSoundWH%3B76DEFB00B8.declarations
//## begin module%3B76DEFB00B8.epilog preserve=yes
//## end module%3B76DEFB00B8.epilog
