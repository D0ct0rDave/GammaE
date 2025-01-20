//-----------------------------------------------------------------------------
#include "Sound\CSoundWH.h"
#include "Sound\CSampleWH.h"
//-----------------------------------------------------------------------------
CSound* CSoundWH::poLoadResource(const CGString& _sFilename)
{
	int iSmp = CSampleWH::I()->iLoad(_sFilename);

	CSound* poSound = mNew CSound;
	poSound->iAddLayer(false,CSampleWH::I()->poGet(iSmp));

	return( poSound );
}
//-----------------------------------------------------------------------------
