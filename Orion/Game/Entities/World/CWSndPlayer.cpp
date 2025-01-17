// -------------------------------------------------------
#include "CWSndPlayer.h"
#include "Game/GameGlobals/GameGlobals.h"
// -------------------------------------------------------
CSound *poCreateSound(char *_szSndFile)
{
	int iSmp = CSampleWH::iLoadSample(_szSndFile);
	if (iSmp == -1) return(NULL);
	
	CSound *poSnd = mNew CSound;
	if (! poSnd) return(NULL);

	poSnd->iAddLayer(false, CSampleWH::poGetSample(iSmp) );
	CSoundWH::iAddSound(poSnd,"_szSndFile");

	return(poSnd);
}
// -------------------------------------------------------
CWSndPlayer::CWSndPlayer()
{
}					

CWSndPlayer::~CWSndPlayer()
{
}
// -------------------------------------------------------
void CWSndPlayer::Setup(char *_szIniFile)
{
	oWSnds.Clear();
	char *szStream = ParseUtils_ReadFile(_szIniFile);
	
	if (! szStream) return;
	
	char *szStr = szStream;
	char *szLine;
	char szSndFile[256];

	TWSndEntry	oEntry;
	while (*szStr)
	{
		NextLine(szLine,szStr);

		sscanf(szLine,"%s %f %f %f",szSndFile,&oEntry.fProb,&oEntry.fVol,&oEntry.fITime);

		oEntry.poSnd = poCreateSound(szSndFile);
		oEntry.fTime = 0.0f;

		oWSnds.iAdd(oEntry);
	}
}
// -------------------------------------------------------
void CWSndPlayer::Think (float _fDelta)
{
	float	fProb;
	CSound	*poSnd;

	for (int cI=0;cI<oWSnds.iNumElems();cI++)
	{	
		if (oWSnds[cI].fTime > 0.0f)
		{
			oWSnds[cI].fTime -= _fDelta;
			if (oWSnds[cI].fTime <= 0.0f)
			{	
				oWSnds[cI].fTime = 0.0f;				
				oWSnds[cI].poSnd->poSLayer[0].bLoop = false;				
			}
		}
		else
		{
			// Launch probability
			fProb = MATH_Common::fRand() / _fDelta;

			if (fProb <= oWSnds[cI].fProb)
			{
				goSndRenderer.poAddOmniEmiter(oWSnds[cI].poSnd,oWSnds[cI].fVol);
				
				// Initilialize
				oWSnds[cI].fTime = oWSnds[cI].fITime;
				oWSnds[cI].poSnd->poSLayer[0].bLoop = true;
			}
		}
	}
}
// -------------------------------------------------------