// -------------------------------------------------------
#ifndef CWSndPlayerH
#define CWSndPlayerH
// -------------------------------------------------------
#include "GammaE.h"
#include "Game/Entities/CGameEntity.h"

typedef struct{

	float	fProb;				// Sound probability
	float	fVol;				// Sound volume
	float	fITime;				// Sound time
	
	// Runtime fields
	CSound *poSnd;
	float	fTime;				

}TWSndEntry;

class CWSndPlayer : CGameEntity
{
	public:		CWSndPlayer();
				~CWSndPlayer();

				virtual void Think (float _fDelta);				
					
				void Setup(char *_szIniFile);
				CDynArray <TWSndEntry> oWSnds;
};

// -------------------------------------------------------
#endif
// -------------------------------------------------------